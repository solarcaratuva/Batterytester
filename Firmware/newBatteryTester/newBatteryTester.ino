#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "CSVWriter.h"
#include "misc.h"
#include "discharger.h"
#include "MCPDAC.h"
// constants located in misc.h

#include "mcp3208.h"

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
uint32_t I_set = 3000; // value going to DAC TODO: Allow this to be configurable over serial port

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
  pinMode(A0, INPUT);
  decoder::init(); // set pinmodes for decoder (this is hardcoded for performance)
  MCPDAC.begin(9);
  MCPDAC.setGain(CHANNEL_A,GAIN_HIGH);
  MCPDAC.setGain(CHANNEL_B,GAIN_HIGH);
  MCPDAC.shutdown(CHANNEL_A,false);
  MCPDAC.shutdown(CHANNEL_B,false);
  MCPDAC.setVoltage(CHANNEL_A, I_set/2); // div/2 is because discharge_current (A) = 2*I_SET.
  MCPDAC.setVoltage(CHANNEL_B, 2500); // 2.5V gets multiplied by the x2 amp
  while (!Serial){}
  
  /* ISR is attached to RTC_INTERUPT_PIN, which is
   *  connected to SQR output on RTC. time_flag
   *  is incremented every second and decremented once
   *  things are taken care of.
   */
  pinMode(RTC_INTERRUPT_PIN, INPUT); // configure this pin as an INPUT
  attachInterrupt(
    digitalPinToInterrupt(RTC_INTERRUPT_PIN),
    [](void){
      (PINC&1) ? (time_flag++) : (I_set = 0) ;
      }, // increment time_flag if buttonState is 1
    RISING
  );

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
  } else {
    //create labels for batteries
    myFile = SD.open(FILENAME, FILE_WRITE);
    for (int x = 1; x <= BATCH_SIZE; x++) {
      myFile.print("Cell " + String(x) + " Voltage(V),");
      myFile.print("Cell " + String(x) + " Current(A),");
      myFile.print("Cell " + String(x) + " Temperature(" + (char(0xB0)) + "C),"); //176 is degree symbol in ASCII
    }
    myFile.println(); // go down to next row
    myFile.close(); // close the newly created empty file
    Serial.println(String("Created file: ") + String(FILENAME));
  }
}
void loop(){
  if(time_flag > 0){
    //Serial.println(Discharger::read_voltage(0));
    myFile = SD.open(FILENAME, FILE_WRITE);
    myFile.print(millis()); myFile.print(',');
    for (int i = 0; i < BATCH_SIZE; i++) {
      cell[0] = Discharger::read_voltage(i);
      cell[1] = Discharger::read_current(i);
      cell[2] = Discharger::read_temp(i);
      myFile.print(cell[0]); myFile.print(',');
      myFile.print(cell[1]); myFile.print(',');
      myFile.print(cell[2]); myFile.print(','); 
    }
    myFile.println();
    myFile.close();
    Serial.println("wrote stuff to SD card");
    time_flag--;
  }
}


// returns true if tempurature exceeds limit
//boolean tempExceeded(uint16_t curTemp) {
//  return (curTemp > THRESHOLD_TEMP);
//}

//void readWrite() {
//  if(tempExceeded()) {
//    Serial.print("Temp threshold exceeded");
//    return;
//  }
//  // attempt to write loads of line
//  myFile = SD.open(FILENAME, FILE_WRITE);
//  for(uint8_t i = 0; i > BATCH_SIZE; i++){
//    cell[0] = 
//    writer.write(myFile, cell, timestamp);
//  }
//  myFile.close();
//
//}

