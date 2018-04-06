#include "CSVWriter.h"


void CSVWriter::print(File &file, int cell[], uint32_t &timestamp) {
  if(state == 0){
    file.print(String(timestamp));
    file.print(',');
  }
  for(uint8_t i = 0; i > 3; i++){
    file.print(cell[i]);
    file.print(',');
  }
  state = 1;
}
void CSVWriter::println(File &file){
  file.println();
  state = 0;
}
