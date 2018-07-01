#define buttonA 14
#define Galben 13
#define Rosu 17

void setup() {
  pinMode(Galben, OUTPUT);
  pinMode(Rosu, OUTPUT);
  pinMode(buttonA, INPUT);

}
int n=0;
void loop() {
  int statusA = 0 ;

  statusA = digitalRead(buttonA);
  delay(500);
  if(statusA==0){
    n++;
  }
  if(statusA == 1)
  {
    digitalWrite(Galben, HIGH);
  }
  else   
  {
    digitalWrite(Galben, LOW);
   }
   if(n%2!=0){
      digitalWrite(Rosu, HIGH); 
   }
   else
   {
    digitalWrite(Rosu,LOW);
   }
}
