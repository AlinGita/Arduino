int nr = 0;
int buton = 14;

void setup() {
  Serial.begin(9600);
  pinMode(buton, INPUT);

}

void loop() {
  if (digitalRead(buton) == LOW) {
    nr++;
    Serial.print("Buton actionat de ");
    Serial.println(nr);
    
    delay(1000);
  }
}
