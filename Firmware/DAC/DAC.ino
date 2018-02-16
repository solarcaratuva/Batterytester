/*
 * Library acquired from https://github.com/MajenkoLibraries/MCPDAC
 */
#include <SPI.h>
#include "MCPDAC.h"

/*
 * Pin 2 = CSPin = 10
 * Pin 3 = SCK = 13
 * Pin4 = SDI = 11
 * Pin 8 = VoutA
 * Pin 6 = VoutB
 */

void setup() {
  // put your setup code here, to run once:
  MCPDAC.begin();

  MCPDAC.setGain(CHANNEL_A,GAIN_HIGH);

  // Do not shut down channel A, but shut down channel B.
  MCPDAC.shutdown(CHANNEL_A,false);
  //MCPDAC.shutdown(CHANNEL_B,true);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int mv = 1000;
  MCPDAC.setVoltage(CHANNEL_A, mv&0x0FFF);
}
