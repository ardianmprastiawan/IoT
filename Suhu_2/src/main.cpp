#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>

#define DHT_PIN 5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN,DHT_TYPE);
float temp, humid;

void updateData();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  Serial.print("Suhu saat ini dalam celcius: ");
  Serial.println(temp);
  Serial.print("Humiditydalam persen: ");
  Serial.println(humid);
  delay(5000);
}

void updateData() {
  temp = dht.readTemperature();
  humid = dht.readHumidity();
}