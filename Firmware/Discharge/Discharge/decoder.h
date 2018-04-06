#ifndef DECODER_H
#define DECODER_H
#include <Arduino.h>

// decoder class is a bit crap right now. It assumes that it will stay connected to PORTC pins 0 through 8 (A0 - A7)
class decoder {
  public:
  static void init(){
    PORTD |= 0b10000000; // ensure that the ENABLE is HIGH (active low -> disabled)
    DDRD  |= 0b11111000; // set port direction for D3 -- D7 to OUTPUT
  }
  
  static void select(uint8_t channel){
    /*  | D7 | D6 | D5 | D4 | D3 |
     *  | EN |  D |  C |  B |  A | 
     */
    channel = (channel & 0x0F) << 3; 
    PORTD &=  0x07;
    PORTD |= channel;
  }
  
  static void enable(bool en){
     en ? (PORTD |=  0b10000000) : (PORTD &= ~0b10000000);
  }
};

#endif
