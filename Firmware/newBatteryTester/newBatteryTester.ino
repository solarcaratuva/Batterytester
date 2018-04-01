#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "CSVWriter.h"
#include "misc.h"
#include "discharger.h"
#include "MCPDAC.h"
#include "RTClib.h"
#include "mcp3208.h"
RTC_DS1307 rtc;
// constants located in misc.h


/*
  Arduino SPI (SD card, DAC, ADC):
  ** CS - pin CSPIN (any digital pin)
  ** SCK - pin D13
  ** MOSI - pin D11
  ** MISO - pin D12
  * 
  * NOTE: Due to poor hardware implementation, the SD breakout card requires a 100 ohm resistor in series with MISO.
  * This is because for some unknown reason, the PCB designer of the SD card has tied 3OE pin to ground, so it remains 
  * in a low impedance state regardless of the CS pin. This goes against the SPI standard and causes problems when 
  * attempting to read other chips.
*/


int cell[3] = {0,0,0}; // {voltage,current,tempurature}
volatile uint32_t time_flag = 0; // this gets incremented by the interrupt when it's triggered. Should be reset to zero when it's handled.
uint32_t timestamp = 0; // Counts the number of seconds that have passed (it is never reset unless arduino is reset)
File myFile;
uint32_t I_set = 0; // discharge current

bool loggingState = false;
bool tempThresholdExceeded = false;


/* Function declarations (prototypes)
 * Arduino should do this automatically but it's good practice.
 */
boolean tempExceeded();
void readWrite();

void setup() {
  Serial.begin(115200);
  SPI.begin();
  SPI.setClockDivider(0);
  rtc.begin();
  pinMode(A0, INPUT);
  decoder::init(); // set pinmodes for decoder (this is hardcoded for performance)
  MCPDAC.begin(9);
  MCPDAC.setGain(CHANNEL_A,GAIN_HIGH);
  MCPDAC.setGain(CHANNEL_B,GAIN_HIGH);
  MCPDAC.shutdown(CHANNEL_A,false);
  MCPDAC.shutdown(CHANNEL_B,false);
  MCPDAC.setVoltage(CHANNEL_B, 2500); // 2.5V gets multiplied by the x2 amp
  rtc.writeSqwPinMode(SquareWave1HZ); // make sure RTC is configured properly
  while (!Serial){}
  


  // initialize the SD and write the header to the CSV as nessesary:
  Serial.println(F("Initializing SD card..."));
  while(!SD.begin(SD_CS_PIN)) {
    Serial.println(F("Initialization failed: Reset or wait."));
    delay(1000);
  }
  Serial.println(F("Initialization done"));

  // if file exists yet, just open it:
  if (SD.exists(FILENAME)) {
    myFile = SD.open(FILENAME, FILE_WRITE);
    
  }
  else {
    //create labels for batteries
    myFile = SD.open(FILENAME, FILE_WRITE);
    myFile.print("time,");
    for (int x = 1; x <= BATCH_SIZE; x++) {
      myFile.print("Cell " + String(x) + " Voltage(V),");
      myFile.print("Cell " + String(x) + " Current(A),");
      myFile.print("Cell " + String(x) + " Temperature(" + (char(0xB0)) + "C),"); //176 is degree symbol in ASCII
    }
    myFile.println(); // go down to next row
    myFile.close(); // close the newly created empty file
    Serial.print(F("Created file: "));
    Serial.println(F(FILENAME));
  }
   /* ISR is attached to RTC_INTERUPT_PIN, which is
   *  connected to SQR output on RTC. time_flag
   *  is incremented every second and decremented once
   *  things are taken care of.
   */
  pinMode(RTC_INTERRUPT_PIN, INPUT); // configure this pin as an INPUT
  attachInterrupt(
    digitalPinToInterrupt(RTC_INTERRUPT_PIN),
    [](void){time_flag++;},
    RISING
  );
}
void loop(){
  if(time_flag > 0){
    if(PINC&1/*A0==true*/){
      MCPDAC.setVoltage(CHANNEL_A, DISCHARGE_CURRENT/2); // discharge_current (Amps) = 2*I_SET.
      myFile = SD.open(FILENAME, FILE_WRITE);
      myFile.print(millis()); myFile.print(',');
      for (int i = 0; i < BATCH_SIZE; i++) {
        cell[0] = Discharger::read_voltage(i);
        cell[1] = Discharger::read_current(i);
        cell[2] = Discharger::read_temp(i);
        myFile.print(cell[0]); myFile.print(',');
        myFile.print(cell[1]); myFile.print(',');
        myFile.print(cell[2]); myFile.print(',');
        
          Serial.print(cell[0]);
        if(cell[0] < VOLTAGE_CUTOFF){
          Serial.print(cell[0]);
          Serial.println(" cutout reached");
          I_set = 0;
        }
      }
      myFile.println();
      myFile.close();
      Serial.println(F("wrote stuff to SD card"));
    }
    else{
      MCPDAC.setVoltage(CHANNEL_A, 0);
      Serial.println(F("BatteryTester off"));
    }
    time_flag--;
  }
}

