#ifndef MCP3208_H
#define MCP3208_H
#include <Arduino.h>
#include <SPI.h>


class MCP3208 {
  public:
  //TODO: there should be a static init() function definition somewhere here. Problem is, is that all it does is configure SPI, but so many of the libraries already do that.

  
  // TODO: Figure out what type of datatype auto is. It's a lambda but the original function pointer definition was giving me problems.
  static uint16_t read(auto pinSelectMethod, int channel){
    pinSelectMethod(LOW);
    SPI.transfer(0b01100000 | ((channel) << 2));
    uint16_t adcvalue =  (SPI.transfer(0xff) << 4) | (SPI.transfer(0xff) >> 4);
    pinSelectMethod(HIGH);
    return adcvalue;
  }
};

#endif
