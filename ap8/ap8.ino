#include <LiquidCrystal.h>
#define butonA 14

int rs=0,e=1,db4=14,db5=17,db6=13,db7=30;

LiquidCrystal lcd(rs,e,db4,db5,db6,db7);
 byte loading[8] = {
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
    B10000,
 };

void setup() {
   lcd.begin(8,2);
   lcd.createChar(0, loading);
   lcd.clear();
}

void loop() {
  pinMode(butonA, INPUT);
  int statusButonA=0;
  statusButonA = digitalRead(butonA);
  delay(250);
  pinMode(butonA, OUTPUT);
  if(statusButonA == LOW){
   for(int i=0;i<8;i++){
      lcd.setCursor(i,0);
      lcd.write(byte(0));
      delay(1000);
   }
  }
}
