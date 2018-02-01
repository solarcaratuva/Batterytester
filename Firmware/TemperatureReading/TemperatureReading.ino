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
  float millivoltage = (sensorVal/1024.0) * 5000.0;
  // At 250 mV the temperature is 25 C and it scales at 0.1 mV/C
  // Millivoltage equals its difference from 250mV 
  millivoltage -= 250;
  // temperature equals its displacement from 25 C
  float temperature = millivoltage * 0.1;
  // fixed displacement
  temperature += 25;
  Serial.print(temperature);
  Serial.print(",");
  delay(1000);
}
