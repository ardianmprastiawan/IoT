#include <Arduino.h>

#define POT_PIN 4
#define LED1 18
#define LED2 19
#define LED3 22
#define LED4 23

int adcValue = 0;
float voltage = 0;
float degree = 0;

void initLed(int ledNumber){
  pinMode(ledNumber, OUTPUT);
}

void ledOn(int ledNumber, String ledName){
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(ledNumber, HIGH);
  Serial.println("Nyala " + ledName + "\n");
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

  adcValue = analogRead(POT_PIN);
  String printData = "Nilai ADC: " + String(adcValue);
  Serial.println(printData);

  voltage = ((float)adcValue / 4095) * 3.3;
  printData = "Nilai tegangan: " + String(voltage) + " V";
  Serial.println(printData);

  degree = ((float)voltage / 3.3) * 100;
  printData = "Nilai Suhu: " + String(degree) + " C";
  Serial.println(printData);

  if ( degree < 10 ) {
   // Serial.println("Nyala LED 1");
    ledOn(LED1,"LED 1");
  } else if ( degree >= 10 && degree < 20 ) {
    //Serial.println("Nyala LED 2");
    ledOn(LED2,"LED 2");
  } else if ( degree >= 20 && degree < 30 ) {
    //Serial.println("Nyala LED 3");
    ledOn(LED3,"LED 3");
  } else if ( degree >= 30 ) {
    //Serial.println("Nyala LED 4");
    ledOn(LED4,"LED 4");
  } else {
    Serial.println("Error....");
  }
  delay(2000);

}