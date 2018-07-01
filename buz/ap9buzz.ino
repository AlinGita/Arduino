#define butonAPin 14
#define butonCPin 17
#define buzzerPin 6
#include "pitches.h"

int statusButonA;
int statusButonC;
int melodie[]={
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
  };
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
void setup() {
  Serial.begin(9600);
  pinMode(butonAPin, INPUT);
  pinMode(butonCPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  statusButonA=digitalRead(butonAPin);

  if(statusButonA == 0){
    Serial.print("Buton A actionat ");
    tone(buzzerPin, NOTE_A3, 500);
    delay(500);
    noTone(buzzerPin);
  }
  
  statusButonC=digitalRead(butonCPin);
  
  if(statusButonC == 0){
    Serial.print("\nButon C actionat ");
    Serial.println("\n Melodia");
    for(int thisNote = 0;thisNote < 8; thisNote++){
    int noteDuration = 1000/ noteDurations[thisNote];
    tone(buzzerPin, melodie[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(buzzerPin);
    }
  }
}
