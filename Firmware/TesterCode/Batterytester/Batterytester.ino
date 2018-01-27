#include <Wire.h>
// dummy load: Constant Current and Constant Power


// configure TIMER2 PWM REG to output higher frequency PWM:
//#define CONFIGURE_FAST_PWM \
//  DDRD |= 0x10; \// equivilant to pinMode(11, OUTPUT);
//  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);\
//  //TCCR2B = _BV(CS22);\
//  OCR2A = 180;\
//  //OCR2B = 50;\
  


/*TODO:
 * Figure out how to use the internal voltage reference for the A0-A3 pins
 * interface the RTC
 * 
 */

void setup() {
  DDRD  |= 0x08; // equivilant to pinMode(3, OUTPUT) ;
  TCNT2  = 0;    // initialize counter value to 0
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS20);
  //OCR2A = 0;
  OCR2B = 128;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
