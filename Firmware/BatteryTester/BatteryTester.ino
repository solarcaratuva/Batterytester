#include <SPI.h>
#include <Wire.h>
#include "RTClib.h"
//#include <MCP3208.h>
#include "misc.h"
#include "Discharger.h"
#include "CSVWriter.h"

//cur_temps needs to be a global array of size numBatteries
//threshold temp needs to be defined

#define thresholdTemp 737 //90 degrees C -> 0.9 V (coming out of the map function) -> 900mV on a 0-5000 scale -> 737 on a 0-4095 scale

boolean checkTemp();
int numBatteries = 30; //placeholder
int curTemps[30]; //placeholder
int I_set = 3.75; //value going to DAC

void setup() {
  pinMode(RTC_INTERUPT_PIN, INPUT);
  Serial.begin(9600);
  while (!Serial);
  Discharger dis(10, 11, 12, 13);
  CSVWriter sd(SD_CS_PIN);
  dis.initialize();

  attachInterrupt(
    digitalPinToInterrupt(RTC_INTERUPT_PIN),
    time_flag++, //will change to an ISR
    RISING //every sec 
  );
}

void loop() {
  if (checkTemp()) {
    return; //if temp above the threshold, return to the top of loop
  }


  // will not need with ISR functioning
  //  if(time_flag > 0){
  //      Serial.println("Current time is");
  //
  //      //sd.writeToCSV(&filename, "\n"); // Create new line in SD Card
  //      time_flag = 0;
  //    }
  //  }
}

boolean checkTemp() {
  for (int i = 0; i < numBatteries; i++) {
    if (curTemps[i] > thresholdTemp) { //cur_temps comes from readings compiled in the interrupt
      I_set = 0; //set the DAC to 0
      return true; //TOO HOT
    }
    return false;
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
//  temperature = ((dis.read_adc(5)/4096.0) * 5000.0 - 250)*0.1 + 25; //old formula

//probably right
// Convert reading to millivolts
// float millivoltage = map(sensorVal, 0, 4095, 0, 5000);
// At 250 mV the temperature is 25 C and it scales at 0.1 mV/C
//  Serial.println(millivoltage/10); //print temp in C

//  //Writing Data from Battery B to SD Card
//  sd.writeToCSV(filename, String(voltage));
//  sd.writeToCSV(filename, String(current));
//  sd.writeToCSV(filename, String(temperature));

