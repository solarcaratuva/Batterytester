#include "Discharger.h"
#include "CSVWriter.h"

double voltage;
double current;
double temperature;
Discharger dis(10, 11, 12, 13);

String FILENAME = "PCB_1.csv";
CSVWriter sd(10);

void setup() {
  dis.initialize();
  sd.createFile(FILENAME);

  Serial.begin(9600);
}

void loop() {
  //Read all Data from PCB and Write it to SD card
  ReadWrite();
  
  //Create new line in SD Card
  sd.writeToCSV(FILENAME, "\n");
}

void ReadWrite()
{
  //Insert Code for reading time from an RTC, and writing it to the SD Card
  
  //Reading Data from Battery A
  voltage = dis.read_adc(0);
  current = dis.read_adc(1); //Don't know if value returns a voltage
  temperature = ((dis.read_adc(2)/4096.0) * 5000.0 - 250)*0.1 + 25; ////map(dis.read-adc(2), 0, 4095, 0, 5)?

  //Writing Data from Battery A to SD Card
  sd.writeToCSV(FILENAME, String(voltage));
  sd.writeToCSV(FILENAME, String(current));
  sd.writeToCSV(FILENAME, String(temperature));

  //Reading Data from Battery B
  voltage = dis.read_adc(3);
  current = dis.read_adc(4); //Don't know if value returns a voltage
  temperature = ((dis.read_adc(5)/4096.0) * 5000.0 - 250)*0.1 + 25; ////map(dis.read-adc(2), 0, 4095, 0, 5)?  

  //Writing Data from Battery B to SD Card
  sd.writeToCSV(FILENAME, String(voltage));
  sd.writeToCSV(FILENAME, String(current));
  sd.writeToCSV(FILENAME, String(temperature));
}

