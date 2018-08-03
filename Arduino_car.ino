#include<Servo.h>
// create servo class
Servo base;
Servo top;

// variables for servo
int i = 0;
char receivedchar;
int basedeg = 90;
int* basepos = &basedeg; // making a pointer allows different functions to access the same value via dereferencing
int topdeg = 90;
int* toppos = &topdeg;

// variables for motor driver
// variable names correspond to the pins on the TB6612FNG motor driver
int STBY = A4;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 9;
int BIN2 = 4;
int PWMA = 11;
int PWMB = 3;

int PWMSPD = 80;

void setup() {
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);

  base.attach(6);
  top.attach(10);
  base.write(basedeg);
  top.write(topdeg);
  Serial.begin(9600);

}

void forward() // move forward
{
  digitalWrite(STBY, HIGH);
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void reverse() // move backward
{
  digitalWrite(STBY, HIGH);
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void brake() // active brakes
{
  digitalWrite(STBY, HIGH);
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
}

void left() // turn left, on the spot
{
  digitalWrite(STBY, HIGH);
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void right() // turn right on the spot
{
  digitalWrite(STBY, HIGH);
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void receiver(){ // receiver function
  if (Serial.available() > 0){
    receivedchar = Serial.read();
  }
}

void loop() {
  receiver();

  // for wheel movement
    if(receivedchar == 'w'){
    forward();
  }
  else if (receivedchar == 's'){
    brake();
  }
    else if (receivedchar == 'd'){
    left();
  }
    else if (receivedchar == 'a'){
    right();
  }
    else if (receivedchar == 'x'){
    reverse();
  }

  // for servo controlled camera
  if (receivedchar == ','){
    while(*toppos < 180){
      *toppos += 1;
      top.write(*toppos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }

    if (receivedchar == 'i'){
    while(*toppos >= 10){
      *toppos -= 1;
      top.write(*toppos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }

    if (receivedchar == 'l'){
    while(*basepos >= 10){
      *basepos -= 1;
      base.write(*basepos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }
  if (receivedchar == 'j'){
    while(*basepos < 180){
      *basepos += 1;
      base.write(*basepos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }

    if (receivedchar == 'o'){ // function to center servos to 90 degrees on the base and top servos
      top.write(90);
      base.write(90);
      *basepos = 90;
      *toppos = 90;
  }
  
}
