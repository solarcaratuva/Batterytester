#include <SPI.h>
#include <Wire.h>
#include <RTClib.h>
#include <MCP3208.h>
#include "misc.h"
#include "Discharger.h"
#include "CSVWriter.h"


void setup() {
  pinMode(RTC_INTERUPT_PIN, INPUT);
  Serial.begin(9600);
  while(!Serial);
  Discharger dis(10, 11, 12, 13);
  CSVWriter sd(SD_CS_PIN);
  dis.initialize();

  attachInterrupt(
    digitalPinToInterrupt(RTC_INTERUPT_PIN),
    time_flag++,
    CHANGE
  );
}

void loop() {

  if(time_flag > 0){
    Serial.println("Current time is");
        
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

