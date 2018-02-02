const int sensorPin = A0;

void setup() {
  // Set up serial connection speed
  Serial.begin(9600);
}

void loop() {
  // Read the sensor value
  int sensorVal = analogRead(sensorPin);
  // Convert reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  //convert milivolts into temperature
  float temperature = (voltage - 0.5) * 100;
  Serial.print(temperature);
  Serial.print(",");
  delay(1000);
}
