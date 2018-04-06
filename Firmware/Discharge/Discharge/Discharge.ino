#include "decoder.h"

void setup(){
  Serial.begin(9600);
  
  decoder::init();
  decoder::enable(false);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}
void loop(){
  
  for(uint8_t i = 0; i < 4; i++){
    decoder::select(3);
    delay(250);
    Serial.print(digitalRead(2));
  }
} 

