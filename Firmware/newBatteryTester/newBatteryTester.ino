#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "CSVWriter.h"
#include "misc.h"
#include "BatteryCell.h"
#include "discharger.h"

// constants located in misc.h

#include "mcp3208.h"

/*
  Arduino SPI (SD card, DAC, ADC):
  ** CS - pin CSPIN (any digital pin)
  ** SCK - pin D13
  ** MOSI - pin D11
  ** MISO - pin D12
*/

BatteryCell BatteryArray[BATCH_SIZE];
uint32_t time_flag = 0; // this gets incremented by the interrupt when it's triggered. Should be reset to zero when it's handled.
uint32_t timestamp = 0; // Counts the number of seconds that have passed (it is never reset unless arduino is reset)
File myFile;
CSVWriter writer;
int I_set = 3.75; // value going to DAC TODO: Allow this to be configurable over serial port
bool tempThresholdExceeded = false;


/*
 * Function declarations (prototypes)
 * Arduino should do this automatically but it's good practice.
 */
boolean tempExceeded();
void readWrite();

void setup() {
  Serial.begin(115200);
  SPI.begin();
  while (!Serial)

  

  /* ISR is attached to RTC_INTERUPT_PIN, which is
   *  connected to SQR output on RTC. time_flag
   *  is incremented every second and decremented once
   *  things are taken care of.
   */
  pinMode(RTC_INTERRUPT_PIN, INPUT); // configure this pin as an INPUT
  attachInterrupt(
    digitalPinToInterrupt(RTC_INTERRUPT_PIN),
    time_flag++,
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
  }
  else {
    //create labels for batteries
    myFile = SD.open(FILENAME, FILE_WRITE);
    for (int x = 1; x <= BATCH_SIZE; x++) {
      myFile.print("Cell " + (String)x + " Voltage(V),");
      myFile.print("Cell " + (String)x + " Current(A),");
      myFile.print("Cell " + (String)x + " Temperature(" + (char(176)) + "C),"); //char(176) is degree symbol
    }
    myFile.println(); // go down to next row
    myFile.close(); // close the newly created empty file
    Serial.println(String("Created file: ") + String(FILENAME));
  }
}
void loop(){

// TODO: implement DAC
  
  if(time_flag > 0){
    time_flag--;
    // somthing that may be preferable: you may wish to create
    // a intermediate class that abstracts reading the ADC.
    // this is what the Discharger class should be for.
    // BATCH_SIZE may be regarding the number of batteries,
    // but a new constant may be desirable to describe the 
    // number of "discharger" boards.
    for (int i = 0; i < BATCH_SIZE; i++) {
  //    BatteryArray[i].present_voltage = 15;
  //    BatteryArray[i].present_current = 18;
  //    BatteryArray[i].present_temp    =  2;
    }
    //writer.setFile(myFile);
  }
}


// returns true if tempurature exceeds limit
boolean tempExceeded(uint16_t curTemp) {
  return (curTemp > THRESHOLD_TEMP);
}

void readWrite() {
  if(tempExceeded()) {
    Serial.print("Temp threshold exceeded");
    return;
  }
  // attempt to write loads of line
  myFile = SD.open(FILENAME, FILE_WRITE);
  writer.writeToCSV(myFile, BatteryArray, timestamp);
  myFile.close();

}

