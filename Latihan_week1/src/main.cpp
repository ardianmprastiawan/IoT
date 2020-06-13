#include <Arduino.h>

#define LED1 BUILTIN_LED
#define LED2 4
#define LED3 19
#define LED4 21

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
  delay(1000);
  initLed(LED1);
  initLed(LED2);
  initLed(LED3);
  initLed(LED4);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    char data = Serial.read();
    Serial.println();
    Serial.print("Karakter yang dikirim: ");
    Serial.println(data);

    if (data == '1') {
      Serial.println("Nyala LED 1");
      ledOn(LED1);
      delay(2000);
      ledOff(LED1);
    }
        
    else if (data == '2') {
      Serial.println("Nyala LED 2");
      ledOn(LED2);
      delay(2000);
      ledOff(LED2);
    }

    else if (data == '3') {
      Serial.println("Nyala LED 3");
      ledOn(LED3);
      delay(2000);
      ledOff(LED3);
    }

    else if (data == '4') {
      Serial.println("Nyala LED 4");
      ledOn(LED4);
      delay(2000);
      ledOff(LED4);
    }
    else
    {
      Serial.println("Karakter yang boleh : 1,2,3,4");
    }
    
  }
  
}