#include "CSVWriter.h"

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

const int CSPIN = 10;
String FILENAME = "data.csv";

void setup() {
  CSVWriter sd(CSPIN); // initialize CSVWriter

  sd.createFile(FILENAME);

  // write to the SD card

  while (millis() <= 300) {
    if (millis() % 20 == 0)
      sd.writeToCSV(FILENAME, String(millis()));
  }

  Serial.println("done");
}

void loop() {
  // put your main code here, to run repeatedly:
}
