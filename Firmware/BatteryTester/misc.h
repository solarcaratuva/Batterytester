#ifndef MISC_H
#define MISC_H


/******** USER DEFINABLE CONSTANTS: ********/


#define FILENAME "batchA.csv"
#define BATCH_SIZE 2              // batch size represents the number of cells we are currently testing
#define SD_CS_PIN 10              // Chip Select Pin for SD Card Reader
#define RTC_INTERRUPT_PIN 2       // RTC Will be connected to pin D2 to trigger interrupt every 1 second
#define THRESHOLD_TEMP 600
#define VOLTAGE_CUTOFF 2457      // defines the voltage cutoff for cells (2457 = 3V)
#define DISCHARGE_CURRENT 2000    // This is the discharge rate we plan to test the boards with


#endif
