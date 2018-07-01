int LedGalben = 13;
void setup() {
  pinMode(LedGalben, OUTPUT);

}

void loop() {
  digitalWrite(LedGalben, HIGH);

  delay(500);

  digitalWrite(LedGalben, LOW);

  delay(500);

}
