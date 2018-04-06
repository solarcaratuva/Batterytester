/*
	UVASD.h - Library for interfacing with SPI SD card readers
*/
#ifndef CSVwriter_h
#define CSVwriter_h

#include "Arduino.h"
#include "misc.h"
#include <SD.h>

class CSVWriter {
  public:
    void print(File &file, int cell[], uint32_t &timestamp); // takes cell array and appends it to the csv. (handles the csv part)
    void println(File &file); // goes to new line. (also resets the state so that print will read latest timestamp.)

  private:
    int state = 0; // 0: print timestamp, else: don't.
};

#endif
