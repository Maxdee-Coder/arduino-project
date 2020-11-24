int trig_pin = 10;
int echo_pin = 8;
int power_pin = 12, buzzPin = 13;
int time, distance;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(power_pin, OUTPUT);
  digitalWrite(power_pin, HIGH);
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delay(10);
  digitalWrite(trig_pin, LOW);
  time = pulseIn(echo_pin, HIGH);
  distance = (time * 0.034)/2;
  
  if(distance>=0 && distance <= 90){
     Serial.println(distance);
     tone(buzzPin, 1300);
     delay(100);
  }
  else{
    Serial.println("not in range");
    delay(100);
    noTone(buzzPin);
    }
}
