#define pir 2
#define led 3
short int val;

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  delay(7000);
  digitalWrite(led, LOW);
}

void loop() {
  val = digitalRead(pir);
  if(val == HIGH){
    digitalWrite(led, HIGH);
    delay(5000);
  }
  else{
    analogWrite(led, 29);
  }
}
