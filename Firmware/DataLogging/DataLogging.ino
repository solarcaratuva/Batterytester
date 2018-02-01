#include <SPI.h>
#include <SD.h>
/*

  Note: for viewing console output, open serial monitor and set baud rate to 9600

  SD card read/write

  Wiring for arduino nano:
  SD card attached to SPI bus as follows:
  ** CS - pin D10
  ** SCK - pin D13
  ** MOSI - pin D11
  ** MISO - pin D12

  Powering SD Card reader:
  **Vcc - 5V
  **GND - GND

*/

File myFile;
String FILENAME = "data.csv";

int SD_CSPIN = 10;

//function prototypes
void initializeSD(); //sets up SD
void saveData(String aFilename, String dataString); //writes a string (with a concatenated comma) to the given file
bool createFile(String aFilename);


void setup() {
  initializeSD();
  createFile(FILENAME);

  // the part where we write to the SD card

  while (millis() <= 300) {
    if (millis() % 20 == 0)
      saveData(FILENAME, String(millis()));
  }

  Serial.print("Done");
}

void loop() {
}

void initializeSD() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Initializing SD card...");

  if (!SD.begin(SD_CSPIN)) {
    Serial.println("Initialization failed! Press reset button to try again.");
    while (1); //ininite loop
  }
  Serial.println("Initialization done.");
}

bool createFile(String aFilename) {
  //if file 'filename' doesn't exist yet, create it
  if (!SD.exists(aFilename)) {
    myFile = SD.open(aFilename, FILE_WRITE);
    myFile.close(); // close the newly created empty file
    Serial.println("Created file: " + aFilename);

    return true;
  }

  else
    return false;
}

void saveData(String aFilename, String dataString) {
  //append comma to dataString for CSV file
  dataString.concat(",");

  if (SD.exists(aFilename)) { //if file 'filename' is found
    // now append new data file
    myFile = SD.open(aFilename, FILE_WRITE);
    if (myFile) {
      Serial.println("Writing: \"" + dataString + "\" to " + aFilename + "...");
      myFile.print(dataString);
      myFile.close(); // close the file
      Serial.println(aFilename + " closed.");
    }
  }
  else {
    Serial.println("Error writing to file !");
  }
}
