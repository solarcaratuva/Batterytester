#include "CSVWriter.h"


CSVWriter::CSVWriter() {}


void CSVWriter::writeToCSV(File & thisfile, BatteryCell values[], uint32_t timestamp) {
  thisfile.print(String(timestamp) + ",");

  for (int i = 0; i < BATCH_SIZE;  i++) {
    // Print the 90 data values to the csv file
    thisfile.print(values[i].present_voltage);
    thisfile.print(",");
    thisfile.print(values[i].present_current);
    thisfile.print(",");
    thisfile.print(values[i].present_temp);
  }
  thisfile.println();
}

void CSVWriter::setFile(File & newFile) {
  file = newFile;
}
