#include <SPI.h>
#include "Discharger.h"
#include "CSVWriter.h"

// USER DEFINABLE CONSTANTS:
String filename = "PCB_1.csv"; // TODO Strings are bad because they are dynamic (not static in size) and can lead to memory fragmentation. We cannot tolerate much of that.
#define BATCH_SIZE 32 // batch size represents the number of cells we can test at a time
#define SD_CS_PIN 10  // TODO figure out which CS pin the SD card will be connected to

// think of this like an object with values (but no methods since C does not support the notion of objects)
typedef struct cell{
  byte cell_id;
  int  current_voltage;
  int  current_current; // the current current at the current moment currently
  int  current_temp;
};
struct cell BatteryData[15]; // an array of structures.
int time_flag = 0; // this gets incremented every time the interrupt is triggered (every second)


// memory-safe way to append character to string
byte append(char * s, char c, int s_len){
  int len = strlen(s);
  if(len >= s_len){
    return -1;
  }
  s[len] = c;
  s[len+1] = '\0';
  return 0;
}




void setup() {
  Serial.begin(9600);
  while(!Serial);
  Discharger dis(10, 11, 12, 13);
  CSVWriter sd(SD_CS_PIN);
  
  dis.initialize();

  attachInterrupt(
    digitalPinToInterrupt(BATCH_SIZE),
    time_flag++,
    CHANGE
  );
}

void loop() {


  if(time_flag > 0){
    // TODO insert 
    
    //sd.writeToCSV(&filename, "\n"); // Create new line in SD Card
    time_flag = 0;
  }
}


  


  //Writing Data from Battery A to SD Card
//  sd.writeToCSV(filename, String(voltage));
//  sd.writeToCSV(filename, String(current));
//  sd.writeToCSV(filename, String(temperature));
//
//  //Reading Data from Battery B
//  voltage = dis.read_adc(3);
//  current = dis.read_adc(4); //Don't know if value returns a voltage
//  temperature = ((dis.read_adc(5)/4096.0) * 5000.0 - 250)*0.1 + 25; ////map(dis.read-adc(2), 0, 4095, 0, 5)?  
//
//  //Writing Data from Battery B to SD Card
//  sd.writeToCSV(filename, String(voltage));
//  sd.writeToCSV(filename, String(current));
//  sd.writeToCSV(filename, String(temperature));

