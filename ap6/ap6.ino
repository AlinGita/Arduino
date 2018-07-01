#define A 14
#define Galben 13
#define Rosu 17
#define Verde PD5
int n = 0;
boolean StatusA = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(A, INPUT);
  pinMode(Galben, OUTPUT);
  pinMode(Rosu, OUTPUT);
  pinMode(Verde, OUTPUT);
}

void loop() {
  int a, i = 0;
  int statusA = 0;
  statusA = digitalRead(A);
  delay(250);
  if (digitalRead(A) == LOW) {
    Serial.print("Pt led galben  tasta G \n");
    Serial.print("Pt led verde  tasta V \n");
    n = 1;
  }
  if (n == 1) {
    a = Serial.read();
  }
  i = a;
  if (a == 103) {
    digitalWrite(Galben, StatusA = 1 - StatusA);
    delay(1000);
  }
  if (a == 118) {
    digitalWrite(Rosu, StatusA = 1 - StatusA);
  }
  if (a == 114) {
    digitalWrite(Verde, StatusA = 1 - StatusA);
  }
}
