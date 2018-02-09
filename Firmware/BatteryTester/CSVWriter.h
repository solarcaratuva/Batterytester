/*
	UVASD.h - Library for interfacing with SPI SD card readers
*/
#ifndef CSVwriter_h
#define CSVwriter_h
#include "Arduino.h"
#include <SD.h>

class CSVWriter{
  
  File file; /* current working file: */
  public:
  	/*
  	*	Constructor. 
    * Creates new  with the CS pin initialized to a specific CSpin
  	* @param CSpin the digital pin to be connected to the Chip Select
  	* (or slave select) port of the SD card reader then opens file
  	*/
  	CSVWriter(int CSpin);
  
  	/**
  	* Writes a string (with a concatenated comma) to a the file given
  	* by aFileName. Note: all data will be saved to a single column.
  	* @param aFileName The name (or directory) to the csv file to be written to
  	* @param dataString The data to be recorded into the CSV file
  	*/
  	void writeCSV();
};

#endif
