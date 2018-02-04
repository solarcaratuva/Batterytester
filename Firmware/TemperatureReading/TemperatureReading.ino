/*
 * Voltage across pins should be 250mV at 25 degrees Celsius
 */

const int sensorPin = A0;

void setup() {
  // Set up serial connection speed
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value
  int sensorVal = analogRead(sensorPin);
  
  // Convert reading to millivolts
  float millivoltage = map(sensorVal, 0, 1023, 0, 5000);
  
  // At 250 mV the temperature is 25 C and it scales at 0.1 mV/C
  Serial.println(temperature*1.8 + 32); //print temp in F
  delay(10);
}
