#ifndef Discharger_h
#define Discharger_h
#include <Arduino.h>
#include "decoder.h"
#include "mcp3208.h"
#include <SPI.h>

class Discharger{
  public:
  static uint16_t read_adc(uint8_t board, uint8_t channel){
    // it's very ugly... but it WORKS! :)
    // the first argument of read is a lambda (a function pointer).
    return MCP3208::read( [=](bool b){ decoder::select(board); decoder::enable(b); } , channel );
  }
  static uint16_t read_voltage(uint8_t cellNum){
    // tell me what cell voltage you want to read. (don't worry about which board. I handle that.)
    //only 2 cells per board, hence cell/2. turninary operator selects which battery to read
    return read_adc( cellNum/2 , (cellNum&1) ? 0 : 3);
  }
  static uint16_t read_current(uint16_t cellNum){
    // tell me what cell current you wanna read. (don't worry about which board. I handle that.)
    return read_adc( cellNum/2 , (cellNum&1) ? 1 : 4);
  }

  static uint16_t read_temp(uint16_t cellNum){
    // tell me what cell temp you wanna read. (don't worry about which board. I handle that.)
    return read_adc( cellNum/2 , (cellNum&1) ? 2 : 6);
  }
  private:
  
};

#endif
