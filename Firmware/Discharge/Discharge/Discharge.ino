#include "Discharger.h"
int readvalue; 
Discharger dis(10,11,12,13); //declares global Discharger class

void setup(){
  Serial.begin(9600); 
  dis.initialize(); //initalizes the Discharger class (sets pins to low/high and output/input
}

void loop() { 
 /**Serial.println(dis.read_adc(1),DEC); //calls read_adc method from Discharger class, parameter is channel on the adc  
 //Serial.println(dis.read_adc(2),DEC); 
 Serial.println(" "); 
 delay(250); **/
 
  readvalue = dis.read_adc(1); 
  Serial.println(readvalue,DEC); 
  Serial.println(" "); 
  delay(50);
} 


