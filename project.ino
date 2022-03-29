/*
 *          BELABO PILOT MODERN GOVT. MODEL HIGH SCHOOL
 *          PROJECT NAME : TIME MONITORING MOBILE PHONE HOLDER
 *          CREATED BY : MAHDEE MOHAMMAD         
 */
#define buzzpin 8
#define trigpin 11
#define echopin 13
unsigned int total_time = 0, start;
unsigned short int time, distance, i, tmp, prev;
bool con = true;


void setup() {
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin, HIGH);
  distance = (time * 0.034)/2;

  //the following lines are for debugging purpose
  //Serial.print("distance : ");
  //Serial.println(distance);

  if(distance >= 0 && distance <= 10){
    noTone(buzzpin);
    if(!con){
      con = true;
      tmp = 0;
      Serial.println("Phone has been detected. Timer has stopped.");
      for(i=0; i <=3; i++){
        tone(buzzpin, 1300);
        delay(100);
        noTone(buzzpin);
      }
    } 
    Serial.print("Phone is not being used, ");
    Serial.print(total_time);
    Serial.print(" seconds total ");
    Serial.print((30 - total_time));
    Serial.println(" seconds remaining ");
    delay(1000);
  }
  else if(distance > 10){
    if(total_time > 30){
      tone(buzzpin, 1300);
      delay(200);
    }
    else if(con){
      start = millis();
      con = false;
      Serial.println("Phone is being used. Timer has started.");
      for(i=0; i <=3; i++){
        tone(buzzpin, 1300);
        delay(100);
        noTone(buzzpin);
      }
    }
    else{
      Serial.println("phone is being used.");
      prev = tmp;
      tmp = floor((millis() - start)/1000);
      total_time = total_time + (tmp-prev);

      // the following lines are for debugging purpose
      //Serial.print("tmp = ");
      //Serial.println(tmp);
      //Serial.print("prev = ");
      //Serial.println(prev);
      
      Serial.print(total_time);
      Serial.print(" seconds total ");
      Serial.print((30 - total_time));
      Serial.println(" seconds remaining");
    }
    delay(600);
  }
}
