#include <Arduino.h>


int tempArray[3];
int tempLen;
int tempAverage;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tempLen = sizeof(tempArray) / sizeof(tempArray[0]);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < tempLen; i++) {
    tempArray[i] = random(20, 30);
  }

  tempAverage = (tempArray[0] + tempArray[1] + tempArray[2]) / tempLen;
  Serial.print("Rata-rata nilai suhu: ");
  Serial.println(tempAverage);
  delay(3000);
}