#include "CSVWriter.h"


// this scary function converts a number into a string. Source: https://stackoverflow.com/questions/7910339/how-to-convert-int-to-string-on-arduino
char _int2str[7];
char* int2str( register int i ) {
  register unsigned char L = 1;
  register char c;
  register boolean m = false;
  register char b;  // lower-byte of i
  // negative
  if ( i < 0 ) {
    _int2str[ 0 ] = '-';
    i = -i;
  }
  else L = 0;
  // ten-thousands
  if( i > 9999 ) {
    c = i < 20000 ? 1
      : i < 30000 ? 2
      : 3;
    _int2str[ L++ ] = c + 48;
    i -= c * 10000;
    m = true;
  }
  // thousands
  if( i > 999 ) {
    c = i < 5000
      ? ( i < 3000
          ? ( i < 2000 ? 1 : 2 )
          :   i < 4000 ? 3 : 4
        )
      : i < 8000
        ? ( i < 6000
            ? 5
            : i < 7000 ? 6 : 7
          )
        : i < 9000 ? 8 : 9;
    _int2str[ L++ ] = c + 48;
    i -= c * 1000;
    m = true;
  }
  else if( m ) _int2str[ L++ ] = '0';
  // hundreds
  if( i > 99 ) {
    c = i < 500
      ? ( i < 300
          ? ( i < 200 ? 1 : 2 )
          :   i < 400 ? 3 : 4
        )
      : i < 800
        ? ( i < 600
            ? 5
            : i < 700 ? 6 : 7
          )
        : i < 900 ? 8 : 9;
    _int2str[ L++ ] = c + 48;
    i -= c * 100;
    m = true;
  }
  else if( m ) _int2str[ L++ ] = '0';
  // decades (check on lower byte to optimize code)
  b = char( i );
  if( b > 9 ) {
    c = b < 50
      ? ( b < 30
          ? ( b < 20 ? 1 : 2 )
          :   b < 40 ? 3 : 4
        )
      : b < 80
        ? ( i < 60
            ? 5
            : i < 70 ? 6 : 7
          )
        : i < 90 ? 8 : 9;
    _int2str[ L++ ] = c + 48;
    b -= c * 10;
    m = true;
  }
  else if( m ) _int2str[ L++ ] = '0';
  // last digit
  _int2str[ L++ ] = b + 48;
  // null terminator
  _int2str[ L ] = 0;  
  return _int2str;
}

CSVWriter::CSVWriter(int CSpin){
  // attempt to open file:
  SD.begin(CSpin);
	if(!SD.begin()){
		Serial.println("ERROR: SD init failed");
    for(;;);
	}
	Serial.println("Initialization done");

  // NOTE: array size important. Do NOT write more than sizeof(fileName) characters to this string.
  char fileName[16] = "Batch_";
  
  for(uint8_t fileNum = 1; fileNum < 99; ++fileNum){
    if(!SD.exists( strcat(fileName,int2str(fileNum)))){
      file = SD.open(fileName, FILE_WRITE); // open new file
      file.print("Time Stamp, Voltage A (V), Current A (A), Temperature A (deg F), Voltage B (V), Current B (A), Temperature B (deg F)");
      break; // we do not want to create a lot of files, once we make one then break.
    }
  }
}

void CSVWriter::writeCSV(){
  //TODO: This function needs to be rewritten. It should take the data in 

  
	// append comma to dataString for CSV file
  //dataString.concat(",");
  //file.print(*dataString);
}


