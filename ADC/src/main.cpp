#include <Arduino.h>

#define POT_PIN 4

int adcValue = 0;
float voltage = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  adcValue = analogRead(POT_PIN);
  String printData = "Nilai ADC yang terbaca: " + String(adcValue);
  Serial.println(printData);
  voltage = ((float)adcValue / 4095) * 3.3;
  printData = "Nilai tegangan yang terbaca: " + String(voltage) + " v";
  Serial.println(printData);
  delay(1000);
}