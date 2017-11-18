//Link to LiquidCrystal_I2C Library: https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads/
#include<Wire.h>
#include<RTClib.h>
#include <SPI.h>
#include <SD.h>
#include<LiquidCrystal_I2C.h>

 /* SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

 */

RTC_DS1307 RTC;
File myFile;
//Define LCD Display (parameters are LCD display address, and pinouts to i2c card, backlight setting)
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup()
{
  //Initialize LCD display
  lcd.begin(16, 2);
  lcd.clear();

  Serial.begin(9600);
  while(!Serial){
    //do nothing if SD Card isn't in
  }

 if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");



  //Initialize Wire and RTC
  Wire.begin();
  RTC.begin();
  
}

void loop()
{
  //Read value from RTC
  DateTime now = RTC.now();
  int hourvar = (now.hour(), DEC);
  int minutevar = (now.minute(), DEC);
  int secondvar = (now.second(), DEC);
  
  //Display time data from RTC to LCD --> Test
  //lcd.print(now.hour(), DEC); lcd.print(':'); lcd.print(now.minute(), DEC); lcd.print(':'); lcd.print(now.second(), DEC); lcd.setCursor(0, 1);
  //lcd.print(now.month(), DEC); lcd.print('/'); lcd.print(now.day(), DEC); lcd.print('/'); lcd.print(now.year(), DEC);

  int pinBATTERY = 0; //TO DO: Need to update with the method to be able to retrieve the unique ID of every battery 
  int uniqueADC = 0; //TO DO: Need to update with the method to be able to retrieve the unique ID of every ADC
  int batchNUM = 0; //TO DO: Need to update with the method to be able to retrieve the unique ID of every batch
  String filename = String(batchNUM) + String(uniqueADC) + String(pinBATTERY);
  myFile = SD.open(filename, FILE_WRITE);
  if(myFile){
   String builder = String(hourvar) + ":" + String(minutevar) + ":" + String(secondvar);
   myFile.print(builder);
   myFile.close();
  }
  else{
  //We fucked up, file didn't open.
  }
  
  delay(1000);
  lcd.clear();
}

