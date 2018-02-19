// SQW/OUT pin mode using a DS1307 RTC connected via I2C.
//
// According to the data sheet (http://datasheets.maxim-ic.com/en/ds/DS1307.pdf), the
// DS1307's SQW/OUT pin can be set to low, high, 1Hz, 4.096kHz, 8.192kHz, or 32.768kHz.
//
// This sketch reads the state of the pin, then iterates through the possible values at
// 5 second intervals.
//

// NOTE:
// You must connect a pull up resistor (~10kohm) from the SQW pin up to VCC.  Without
// this pull up the wave output will not work!

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;


void setup () {
  rtc.begin();
}

void loop () {
  rtc.writeSqwPinMode(SquareWave1HZ);
}
