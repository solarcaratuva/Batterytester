#ifndef DECODER_H
#define DECODER_H
#include <Arduino.h>

// decoder class is a bit crap right now. It assumes that it will stay connected to PORTC pins 0 through 8 (A0 - A7)
class decoder {
  public:
  static void init(){
    DDRC |= 0b00011111; // set port direction to OUTPUT for A0,A1,A2,A3,and  A4. (TODO: Change A4 to A6. (I tried this but some reason DDRC has no effect on A6 ot A7.)
  }
  
  static void select(uint8_t channel){
    channel &= 0x0F; // prevents channel inputs from overflowing. 
    (PORTC &= ~channel) |= channel;
  }
  
  static void enable(bool en){
     en ? (PORTC |=  0b00010000) : (PORTC &= ~0b00010000); // ternary operator
  }
};

#endif
