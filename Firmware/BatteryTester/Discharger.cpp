#include "Discharger.h"


/*
 * TODO: This class needs to be rewritten to use the preeixinting library for the DAC.
 * Additional functionality that should be implemented is a 'setDischargeCurrent.' Use
 * the DAC class to implement reading data regarding cell 1 and 2. (returning a cell 
 * stuct defined in misc.)
 * 
 * Future OPTIONAL changes: The code could pontentially be optimized by rewriting the code for the
 * DAC. The ones I found do not appear to read all ADC channels with one SPI frame. Doing it with a 
 * single SPI read as shown below will greatly reduce time between reading all the channels.
 * (However I am not sure if the DAC supports it due to a crummy datasheet.) (note: the timing diagram
 * below, the blocks of SPI transfers are 16 bits in size, in arduino that means you do 2 8 bit transfers.
 * 
 *  SS pin: [low]                                                                                                                          [high]
 *  clock:      [16]         [16]            [16]            [16]            [16]            [16]            [16]            [16]
 *  Master:     [read ch. 0] [0x0000       ] [0x0000       ] [0x0000       ] [0x0000       ] [0x0000       ] [0x0000       ] [0x0000       ]
 *  Slave:      [          ] [ch0 (16 bits)] [ch1 (16 bits)] [ch2 (16 bits)] [ch3 (16 bits)] [ch4 (16 bits)] [ch5 (16 bits)] [ch6 (16 bits)]
 *  
 *  This sequential read approch, if supported by the DAC, should allow a near doubling in read speed, 
 *  since you do not need to constantly specify which channel your reading and you can keep the SS pin 
 *  low for the whole duration.
 */
 
Discharger::Discharger(int SELPIN,int DATAOUT,int DATAIN,int SPICLOCK){
	SELPIN = SELPIN;
	DATAOUT = DATAOUT;
	DATAIN = DATAIN;
	SPICLOCK = SPICLOCK;	
}

int Discharger::read_adc(int channel){
	int adcvalue = 0;
  byte commandbits = B11000000; //command bits - start, mode, chn (3), dont care (3)

  //allow channel selection
  commandbits|=((channel-1)<<3);

  digitalWrite(SELPIN,LOW); //Select adc
  // setup bits to be written
  for (int i=7; i>=3; i--){
    digitalWrite(DATAOUT,commandbits&1<<i);
    //cycle clock
    digitalWrite(SPICLOCK,HIGH);
    digitalWrite(SPICLOCK,LOW);    
  }

  digitalWrite(SPICLOCK,HIGH);    //ignores 2 null bits
  digitalWrite(SPICLOCK,LOW);
  digitalWrite(SPICLOCK,HIGH);  
  digitalWrite(SPICLOCK,LOW);

  //read bits from adc
  for (int i=11; i>=0; i--){
    adcvalue+=digitalRead(DATAIN)<<i;
    //cycle clock
    digitalWrite(SPICLOCK,HIGH);
    digitalWrite(SPICLOCK,LOW);
  }
  digitalWrite(SELPIN, HIGH); //turn off device
  return adcvalue;
}

void Discharger::initialize(){ 
 //disable device to start with 
 digitalWrite(SELPIN,HIGH); 
 digitalWrite(DATAOUT,LOW); 
 digitalWrite(SPICLOCK,LOW); 
 // now configure the pins
 pinMode(SELPIN, OUTPUT); 
 pinMode(DATAOUT, OUTPUT); 
 pinMode(DATAIN, INPUT); 
 pinMode(SPICLOCK, OUTPUT);
}
