#ifndef Discharger_h
#define Discharger_h
#include <Arduino.h>
class Discharger {
  public:
    /* @param SELPIN: SELPIN pin number. (Selection Pin)
        @param DATAOUT: DATAOUT pin number. (MOSI)
        @param DATAIN: DATAIN pin number. (MISO)
        @param SPICLOCK: SPICLOCK pin number. (Clock)
    */
    Discharger(int MYSELPIN, int MYDATAOUT, int MYDATAIN, int MYSPICLOCK);
    /* @param channel number to read voltage data from
       @return returns the digital voltage
    */
    int read_adc(int channel);
    /*
       @ Defines the pins as input and outputs, sets HIGH and LOW responses
    */
    void initialize();
  private:
    /*
       The four pins needed for Discharger class.
    */
    int SELPIN, DATAOUT, DATAIN, SPICLOCK;
};

#endif
