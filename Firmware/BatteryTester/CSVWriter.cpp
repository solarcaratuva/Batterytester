#include "CSVWriter.h"
/*
 * TODO: what exactly is the purpose of this class?
 * 
 * IMHO,
 * This class should:
 *     prepare a CSV file with the header in constructor
 *     take in the cell type and do stuff with the file object
 * 
 * It should not:
 *    do anything SD card (do this more abstractly by passing in the file object by reference. SD stuff is done in setup.)
 *    do any calculations/conversions
 * 
 */
CSVWriter::CSVWriter(int CSpin){
//  // attempt to open file:
//  SD.begin(CSpin);
//	if(!SD.begin()){
//		Serial.println("ERROR: SD init failed");
//    for(;;);
//	}
//	Serial.println("Initialization done");
//
//  // NOTE: array size important. Do NOT write more than sizeof(fileName) characters to this string.
//  char fileName[16] = "Batch_";
//  
//  for(uint8_t fileNum = 1; fileNum < 99; ++fileNum){
//    if(!SD.exists( strcat(fileName,int2str(fileNum)))){
//      file = SD.open(fileName, FILE_WRITE); // open new file
//      file.print("Time Stamp, Voltage A (V), Current A (A), Temperature A (deg F), Voltage B (V), Current B (A), Temperature B (deg F)");
//      break; // we do not want to create a lot of files, once we make one then break.
//    }
//  }
}

void CSVWriter::writeCSV(){
	// append comma to dataString for CSV file
  //dataString.concat(",");
  //file.print(*dataString);
}


