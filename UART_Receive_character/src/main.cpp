#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char data = Serial.read();
    Serial.println();
    Serial.print("Karacter yang dikirim: ");
    Serial.println(data);
  }
}