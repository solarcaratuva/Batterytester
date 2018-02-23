#ifndef BATTERYCELL_H
#define BATTERYCELL_H

#include "Arduino.h"

using namespace std;

//class BatteryCell;

class BatteryCell {
  public:
    BatteryCell(); //Default constructor: initializes all values to 0
    int  present_voltage;
    int  present_current;
    int  present_temp;
  private:
};

#endif

