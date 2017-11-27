#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include <MCP3208.h>
#include <SPI.h>

MCP3208 adc(10);

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
int tempPin1_1 = 0;             // Package 1: Temp reading pin
int tempPin1_2 = 1;             // Package 1: Temp reading pin
int tempPin1_3 = 2;             // Package 1: Temp reading pin for battery
int volPin1    = 3;             // Package 1: Voltage pin for battery

int tempPin2_1 = 4;             // Package 2: Temp reading pin
int tempPin2_2 = 5;             // Package 2: Temp reading pin
int tempPin2_3 = 6;             // Package 2: Temp reading pin for battery
int volPin2    = 7;             // Package 2: Voltage pin for battery

int MIN_TEMP = -20;           // Min temperature limit
int MAX_TEMP = 50;            // Max temperature limit
int VOL      = 3.9;           // Voltage upperlimit


void setup() {
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
}

double readVoltage(int pin){
  double reading = adc.analogRead(pin);
  double Voltage = map(reading, 0, 4095, 0, 5000)/1000.0;
  return Voltage;
}

void loop() {
  double Voltage1_1 = readVoltage(tempPin1_1);
  double Voltage1_2 = readVoltage(tempPin1_2);
  double Voltage1_3 = readVoltage(tempPin1_3);
  double Voltage1_4 = readVoltage(volPin1);
  double Voltage2_1 = readVoltage(tempPin2_1);
  double Voltage2_2 = readVoltage(tempPin2_2);
  double Voltage2_3 = readVoltage(tempPin2_3);
  double Voltage2_4 = readVoltage(volPin2);
  
  double tempC1_1 = 100.0 * (Voltage1_1) - 50.0;
  double tempC1_2 = 100.0 * (Voltage1_2) - 50.0;
  double tempC1_3 = 100.0 * (Voltage1_3) - 50.0;
  double tempC2_1 = 100.0 * (Voltage2_1) - 50.0;
  double tempC2_2 = 100.0 * (Voltage2_2) - 50.0;
  double tempC2_3 = 100.0 * (Voltage2_3) - 50.0;
  
  
  if(tempC1_1>MAX_TEMP||tempC1_2>MAX_TEMP||tempC1_3>MAX_TEMP||tempC2_1>MAX_TEMP||tempC2_2>MAX_TEMP||tempC2_3>MAX_TEMP){
    Serial.println("The temperature passes the upper limit.");
  }
  if(tempC1_1<MIN_TEMP||tempC1_2<MIN_TEMP||tempC1_3<MIN_TEMP||tempC2_1<MIN_TEMP||tempC2_2<MIN_TEMP||tempC2_3<MIN_TEMP){
    Serial.println("The temperature passes the lower limit.");
  }
  if(Voltage1_4>3.9||Voltage2_4>3.9){
    Serial.println("The Battery passes the nominal limit");
  }
  
  //lcd.print(tempC1); lcd.print(" Degree Celcius");
  delay(1000);
}
//Serial.print("Volatge for Package 1 is ");Serial.print(Voltage1);
//Serial.print("Volatge for Package 2 is ");Serial.print(Voltage2);
/**double tempF1 = (tempC1 * 9.0 / 5.0) + 32.0;
  double tempF2 = (tempC2 * 9.0 / 5.0) + 32.0;
  double tempF3 = (tempC2 * 9.0 / 5.0) + 32.0;**/

