#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>

#define DHT_PIN 5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN,DHT_TYPE);

float readTemp();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  float temp = readTemp();
  Serial.print("Suhu saat ini dalam celcius: ");
  Serial.println(temp);
  delay(5000);
}

float readTemp() {
  return dht.readTemperature();
}