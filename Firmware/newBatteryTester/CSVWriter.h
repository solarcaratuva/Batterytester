/*
	UVASD.h - Library for interfacing with SPI SD card readers
*/
#ifndef CSVwriter_h
#define CSVwriter_h

#include "Arduino.h"
#include "BatteryCell.h"
#include "misc.h"
#include <SD.h>

class CSVWriter {
  public:
    File file;

    /**
      Creates a new CSVWriter with uninitialized file
     */
    CSVWriter();
    
    /**
      Writes a string (with a concatenated comma) to a the file given
      by aFileName. Note: all data will be saved to a single column.
    */
    void writeToCSV(File & thisfile, BatteryCell values[], uint32_t timestamp);

    /**
    	Checks to see if the file given by the parameter exists
      if it does not exist, it is created. If it does already
      exist, nothing is modified.
    	@param aFileName The name (or directory) to the csv file to be written to
      @paran numBatteries
      @return True if the file previously did not exist and was created,
      False if the file already existed and no new file was created
    */
    //bool createFile(String aFilename, int numBatteries);

    /**
      Set value of file
     */
    void setFile(File & newFile);

  private:
};

#endif
