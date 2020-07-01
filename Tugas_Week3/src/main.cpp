#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <w25q64.hpp>

#define CS_PIN 5
#define SCK_PIN 18
#define MISO_PIN 19
#define MOSI_PIN 23

#define GET_CHIP_ID 0x9F

#define LEN_ID 4

#define BH1750_ADDRESS 0x23
#define BH1750_DATALEN 2

#define LED1 2
#define LED2 4
#define LED3 16
#define LED4 17

#define BUTTON_PIN 15

#define BOOL_STR(ot) (ot?"1":"0")
#define STR_BOOL(dt) (dt=="1"? 1 : 0)

unsigned char writePage[256] = "";
unsigned char readPage[256] = "";

byte chipId[4];

w25q64 spiChip;

void bh1750Request(int address);
int bh1750GetData(int address);

void bacaMem();
bool otomatis;
String data_mem;

byte buff[2];
unsigned short lux = 0;

void initLed(int ledNumber){
  pinMode(ledNumber, OUTPUT);
}

//fungsi untuk menyalakan LED 1-4 
void led(bool led1, bool led2, bool led3,bool led4){
  if(led1 == 1) {
      digitalWrite(LED1, HIGH);
  }else{
      digitalWrite(LED1, LOW);
  }
    if(led2 == 1) {
      digitalWrite(LED2, HIGH);
  }else{
      digitalWrite(LED2, LOW);
  }
    if(led3 == 1) {
      digitalWrite(LED3, HIGH);
  }else{
      digitalWrite(LED3, LOW);
  }
    if(led4 == 1) {
      digitalWrite(LED4, HIGH);
  }else{
      digitalWrite(LED4, LOW);
  }
}

//Fungsi membaca data di Mem
void bacaMem(){
    // Read Data
    data_mem = "";
    spiChip.readPages(readPage,  0xFFFF, 1);
    for(int i = 0; i < 256; i++) {
        if (readPage[i] > 8 && readPage[i] < 127) 
          data_mem += (char)readPage[i];
    }
}

void setup() {
    // put your setup code here, to run once:       
    
    Serial.begin(9600);
    Serial.println("Tugas Week III a.n Ardian Maretta Prastiawan");
    
    Wire.begin();
    initLed(LED1);
    initLed(LED2);
    initLed(LED3);
    initLed(LED4);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    spiChip.begin();

    bacaMem();
    otomatis = STR_BOOL(data_mem);  
    Serial.println("Reading Mem: " + String(otomatis));
}

void loop() {
    // put your main code here, to run repeatedly:
    //jika button di klik
    if (digitalRead(BUTTON_PIN) == LOW) {
      otomatis = !otomatis;
      Serial.println("Status Otomatis: " + String(otomatis));
      led(1,1,1,1);

      //Tulis di Mem
      memcpy(writePage, BOOL_STR(otomatis), 1);
      spiChip.erasePageSector(0xFFFF);
      spiChip.pageWrite(writePage, 0xFFFF);
      Serial.println("Writing is done");
      
      bacaMem();
      
      Serial.println("Reading Mem: " + data_mem);
      otomatis = STR_BOOL(data_mem);
      Serial.println("Status Otomatis Baru: " + String(otomatis));
      delay(1000);
    }

    
    //bacaMem();

    if(otomatis == 1){
        bh1750Request(BH1750_ADDRESS);
        delay(200);

        if (bh1750GetData(BH1750_ADDRESS) == BH1750_DATALEN) {
            lux = (((unsigned short)buff[0] << 8) | (unsigned short)buff[1]) / 1.2;
            String sentence = "Nilai intensitas cahaya: " + String(lux) + " lux";
            Serial.println(sentence);
            if (lux >= 0 && lux <= 250) {
                led(1,1,1,1);
            } else if (lux > 250 && lux <= 500){
                led(1,1,1,0);
            } else if (lux > 500 && lux <= 750){
                led(1,1,0,0);
            } else if (lux > 750 && lux <= 1000){
                led(1,0,0,0);
            } else {
                led(0,0,0,0);
            }
        }
    }
    delay(1000);
}

void bh1750Request(int address) {
  Wire.beginTransmission(address);
  Wire.write(0x10);
  Wire.endTransmission();
}


int bh1750GetData(int address) {
  int i = 0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while (Wire.available()) {
    buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();
  return i;
}