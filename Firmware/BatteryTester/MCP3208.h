#ifndef MCP3208_H
#define MCP3208_H
#include <Arduino.h>
#include <SPI.h>


class MCP3208 {
  
  public:
      // TODO: Figure out what type of datatype auto is
    static uint16_t read(auto pinSelectMethod, int channel){
      pinSelectMethod(LOW);
      SPI.transfer(0b01100000 | ((channel) << 2));
      uint16_t adcvalue =  (SPI.transfer(0xff) << 4) | (SPI.transfer(0xff) >> 4);
      pinSelectMethod(HIGH);
      return adcvalue;
    }
    
};

#endif
