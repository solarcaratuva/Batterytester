#ifndef MISC_H
#define MISC_H


/******** USER DEFINABLE CONSTANTS: ********/


#define FILENAME "batchA.csv"
#define BATCH_SIZE 30              // batch size represents the number of cells we are currently testing
#define SD_CS_PIN 10              // Chip Select Pin for SD Card Reader
#define RTC_INTERRUPT_PIN 2       // RTC Will be connected to pin D2 to trigger interrupt every 1 second
#define THRESHOLD_TEMP 700
#define DISCHARGE_CURRENT 3000    // This is the discharge rate we plan to test the boards with


#endif
