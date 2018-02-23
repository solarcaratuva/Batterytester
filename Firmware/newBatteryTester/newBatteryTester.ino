#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "CSVWriter.h"
#include "misc.h"
#include "BatteryCell.h"
#include "discharger.h"

// TODO:
//update writecsv function to write all cell values to csv
//get adc values using function from * library

/*
  Note: for viewing console output, open serial monitor and set baud rate to 9600
  SD card read/write
  Wiring for arduino nano:
  SD card attached to SPI bus as follows:
  ** CS - pin CSPIN (any digital pin)
  ** SCK - pin D13
  ** MOSI - pin D11
  ** MISO - pin D12

  Powering SD Card reader:
  **Vcc - 5V
  **GND - GND
*/

uint32_t time_flag = 0; // this gets incremented by the interrupt when it's triggered. Should be reset to zero when it's handled.
uint32_t timestamp = 0; // Counts the number of seconds that have passed (it is never reset unless arduino is reset)
File myFile;
BatteryCell BatteryArray[BATCH_SIZE];
//CSVWriter writer;

//Discharger dis(10,11,12,13); //declares global Discharger class

void setup() {
  timestamp = 0;
  pinMode(RTC_INTERUPT_PIN, INPUT); // configure this pin as an INPUT
  Serial.begin(115200); // initialize Serial:
  while (!Serial)

  // initialize the SD and write the header to the CSV as nessesary:
  Serial.println(F("Initializing SD card..."));
  if (!SD.begin(SD_CS_PIN)){
    Serial.println(F("Initialization failed: Press reset button to try again."));
    while (1); // infinite loop
  }
  Serial.println("Initialization done");

  
  // if file exists yet, just open it:
  if(SD.exists(FILENAME)) {
    myFile = SD.open(FILENAME, FILE_WRITE);
  }
  else{
    //create labels for batteries
    myFile = SD.open(FILENAME, FILE_WRITE);
    for(int x = 1; x <= BATCH_SIZE; x++){
      myFile.print("Cell " + (String)x + " Voltage(V),");
      myFile.print("Cell " + (String)x + " Current(A),");
      myFile.print("Cell " + (String)x + " Temperature(" + (char(176)) + "C),"); //char(176) is degree symbol
    }
    myFile.println(); // go down to next row  
    myFile.close(); // close the newly created empty file
    Serial.println(String("Created file: ") + String(FILENAME));
  }
  //writer.createFile(FILENAME, BATCH_SIZE);
  //dis.initialize();   // initalizes the Discharger class (sets pins to low/high and output/input

  for (int i = 0; i < BATCH_SIZE; i++) {
    BatteryArray[i].cell_id = i + 1;
  }
  for (int i = 0; i < BATCH_SIZE; i++){// sizeof may return bytes
    BatteryArray[i].present_voltage = 15; // TODO implement ADC
    BatteryArray[i].present_current = 18; // TODO implement ADC
    BatteryArray[i].present_temp     = 2; // TODO implement ADC
  }
  CSVWriter writer(myFile);

  while(1){
    // attempt to write loads of line
    Serial.println("HELLO");
    myFile = SD.open(FILENAME, FILE_WRITE);
    writer.writeToCSV(myFile, BatteryArray, timestamp);
    myFile.close();
  }
}




