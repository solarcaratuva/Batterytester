// SQW/OUT pin mode using a DS1307 RTC connected via I2C.

/*
 * SQ (Square Wave Output): Connect pullup resistor (~10k) to Vcc
 * SCL: A5
 * SDA: A4
 */

#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  rtc.begin();
}

void loop () {
  rtc.writeSqwPinMode(SquareWave1HZ);
}
