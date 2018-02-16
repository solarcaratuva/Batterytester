#include "CSVWriter.h"

CSVWriter::CSVWriter(int CSpin){
	//Open serial comunications and wait for port ot open:
	Serial.begin(9600);

	while(!Serial); //wait for serial port to connect (only needed when connected to a computer)

	Serial.println("Initializing SD card...");

// check if card reader initialization failed
	if(!SD.begin(CSpin)){
		Serial.println("Initialization failed: Press reset button to try again.");
		while(1); // infinite loop
	}

	Serial.println("Initialization done");
}

void CSVWriter::writeToCSV(String aFilename, String dataString){
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

bool CSVWriter::createFile(String aFilename, int numBatteries){
	//if file 'aFilename' doesn't exist yet, create it
  if (!SD.exists(aFilename)) {
    myFile = SD.open(aFilename, FILE_WRITE);
    Serial.println("Writing table headers...");
    // header names
    myFile.print("Time Stamp"); // write timeStamp

    //create labels for batteries
    for(int x = 1; x <= numBatteries; x++){
      myFile.print("Cell " + (String)x + " Voltage(V),");
      myFile.print("Cell " + (String)x + " Current(A),");
      myFile.print("Cell " + (String)x + " Temperature(" + (char(176)) + "C),"); //char(176) is degree symbol
    }

    myFile.println(); // go down to next row
    
    myFile.close(); // close the newly created empty file
    Serial.println("Created file: " + aFilename);

    return true;
  }

  else
    return false;
}
