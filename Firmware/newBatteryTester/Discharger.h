#ifndef Discharger_h
#define Discharger_h
#include <Arduino.h>
#include "decoder.h"
#include "mcp3208.h"
#include <SPI.h>

class discharger{
  public:
  
  static uint16_t read_adc(uint8_t board, uint8_t channel){
    // it's very ugly... but it WORKS! :)
    // the first argument of read is a lambda (a function pointer).
    return MCP3208::read( [=](bool b){ decoder::select(board); decoder::enable(b); } , channel );
  }
  
  private:
  
};

#endif
