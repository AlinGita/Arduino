#include <LiquidCrystal.h>
#include "pitches.h"
#define butonAPin 14
#define butonCPin 17
#define buzzerPin 6

int statusButonA;
int statusButonC;

int yellowLedPin = 13;
int dutyCycle = 0;
int dutyCycleStep = 5;

int rs = 0, e = 1, db4 = 14, db5 = 17, db6 = 13, db7 = 30;
LiquidCrystal lcd(rs, e, db4, db5, db6, db7);

void setup() {
  Serial.begin(9600);
  // pinMode(yellowLedPin, OUTPUT);
  lcd.begin(8, 2);
  lcd.clear();
  //  pinMode(butonAPin, INPUT);
  //  pinMode(butonCPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  lcd.setCursor(0, 0); lcd.print("Buton A");
  lcd.setCursor(0, 1); lcd.print("Buton C");
  pinMode(butonAPin, INPUT);
  pinMode(butonCPin, INPUT);
}

void loop() {
  statusButonA = digitalRead(butonAPin);
  if (statusButonA == 0) {
    Serial.print("Buton apasat");
    analogWrite(yellowLedPin, dutyCycle);
    dutyCycle = dutyCycle + dutyCycleStep;

    if (dutyCycle <= 0 || dutyCycle >= 255)
    {
      dutyCycleStep = - dutyCycleStep;
    }
    delay(30);
  }

  statusButonC = digitalRead(butonCPin);
  if (statusButonC == 0) {
    tone(buzzerPin, NOTE_A3, 500);
    delay(500);
  }
}

