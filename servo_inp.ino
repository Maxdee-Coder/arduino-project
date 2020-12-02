int angle, i, j;
int inp;
#include <Servo.h>
#include <stdlib.h>
Servo motor;

void setup(){
  Serial.begin(9600);
  motor.attach(9);
  motor.write(0);
}

void loop(){
  inp = Serial.parseInt();
  if(inp >= 0 && inp <= 260){
    motor.write(inp);
    for(i=0; i<=inp;++i){
      motor.write(i);
      delay(10);
    }
  }
  else if(inp < 0 && inp >= -260){
    inp = abs(inp);
    motor.write(inp);
    for(j=inp;j>=0;--j){
      motor.write(j);
      delay(10);
    }
  }
  else{
    Serial.println("Wrong input is entered!");
  }
}
  
