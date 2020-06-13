#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <DHT.h>

#define DHT_PIN 5
#define DHT_TYPE DHT11

DHT dht(DHT_PIN,DHT_TYPE);
float temp, humid;
String printData;
String tempSentence = "Suhu saat ini: ";
String humidSentence = "Humidity saat ini: ";

void updateData();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  updateData();
  printData = tempSentence + String(temp) + " C";
  Serial.println(printData);
  printData = humidSentence + String(humid) + " %";
  Serial.println(printData);
  delay(5000);
}

void updateData() {
  temp = dht.readTemperature();
  humid = dht.readHumidity();
}