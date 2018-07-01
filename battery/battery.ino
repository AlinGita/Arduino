#include <LiquidCrystal.h>
#include "pitches.h"
#define butonAPin 14
#define butonCPin 17
#define buzzerPin 6

int batteryVoltagePin = A1;

int rs = 0, e = 1, db4 = 14, db5 = 17, db6 = 13, db7 = 30;
int i, cont = 0;
int statusButonA;
int statusButonC;

LiquidCrystal lcd(rs, e, db4, db5, db6, db7);

void setup() {
  lcd.begin(8, 2);
  lcd.clear();
  Serial.begin(9600);
  pinMode(butonAPin, INPUT);
  pinMode(butonAPin, OUTPUT);
  pinMode(butonCPin, INPUT);
  pinMode(butonCPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}
void loop() {
  float ma1 = 0;
  float ma2 = 0;

  for (i = 0; i < 10; i++) {

    int voltageValue = analogRead(batteryVoltagePin);
    float batteryVoltage = (float) voltageValue;
    batteryVoltage = 2 * batteryVoltage;
    batteryVoltage = batteryVoltage * 4.9;
    ma1 = (float)ma1 + batteryVoltage;
    ma2 = (float)ma2 + voltageValue;
    pinMode(butonAPin, OUTPUT);
    pinMode(butonCPin, OUTPUT);
    lcd.clear();
  }
  ma1 = ma1 / i;
  ma2 = ma2 / i;
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("ADC= ");
  lcd.setCursor(4, 0); lcd.print(ma1);
  lcd.setCursor(0, 1); lcd.print("B= ");
  lcd.setCursor(2, 1); lcd.print(ma2);

  delay(500);

  pinMode(butonAPin, INPUT);
  pinMode(butonCPin, INPUT);
  statusButonA = digitalRead(butonAPin);
  if (statusButonA == 0) {
    cont = cont + 1;
    Serial.print("Buton apasat");
    Serial.print(cont);
  }
  statusButonC = digitalRead(butonCPin);
  if (statusButonC == 0) {
    cont = cont - 1;
    Serial.print("Buton apasat");
    Serial.print(cont);
  }
  if (ma1 < cont * 1000 * 1.0) {
    tone(buzzerPin, NOTE_A3, 500);
    delay(500);
    noTone(buzzerPin);
  }
}
