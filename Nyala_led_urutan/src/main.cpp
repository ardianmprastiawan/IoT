#include <Arduino.h>

#define LED1 18
#define LED2 19
#define LED3 22
#define LED4 23

void initLed(int ledNumber){
  pinMode(ledNumber, OUTPUT);
}

void ledOn(int ledNumber){
  digitalWrite(ledNumber, HIGH);
}

void ledOff(int ledNumber){
  digitalWrite(ledNumber, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initLed(LED1);
  initLed(LED2);
  initLed(LED3);
  initLed(LED4);
}

void loop() {
  // put your main code here, to run repeatedly:

  ledOn(LED1);
  delay(1000);
  ledOff(LED1);

  ledOn(LED2);
  delay(1000);
  ledOff(LED2);

  ledOn(LED3);
  delay(1000);
  ledOff(LED3);

  ledOn(LED4);
  delay(1000);
  ledOff(LED4);



}