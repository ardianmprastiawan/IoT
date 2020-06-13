#include <Arduino.h>


int tempArray[3];
int tempLen, tempAverage;
int *pointerTemp1, *pointerTemp2, *pointerTemp3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  tempLen = sizeof(tempArray) / sizeof(tempArray[0]);

  pointerTemp1 = &tempArray[0];
  pointerTemp2 = &tempArray[1];
  pointerTemp3 = &tempArray[3];

  Serial.print("Alamat data pertama: ");
  Serial.println((unsigned int)pointerTemp1);
  Serial.print("Alamat data kedua: ");
  Serial.println((unsigned int)pointerTemp2);
  Serial.print("Alamat data ketiga: ");
  Serial.println((unsigned int)pointerTemp3);


}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < tempLen; i++) {
    tempArray[i] = random(20, 30);
  }

  tempAverage = (*pointerTemp1 + *pointerTemp1 + *pointerTemp1) / tempLen;
  Serial.print("Rata-rata nilai suhu: ");
  Serial.println(tempAverage);
  delay(3000);
}