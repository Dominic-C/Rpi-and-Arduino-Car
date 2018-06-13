#include<Servo.h>

Servo base;
Servo top;

int i = 0;
char receivedchar;
int basepos = 90;
int toppos = 90;

int STBY = A4;
int AIN1 = 7;
int AIN2 = 8;
int BIN1 = 9;
int BIN2 = 10;
int PWMA = 11;
int PWMB = 3;
int PWMSPD = 80;

void setup() {
  // put your setup code here, to run once:
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);

  base.attach(6);
  top.attach(5);
  base.write(basepos);
  top.write(toppos);
  Serial.begin(9600);

}

void forward()
{
  digitalWrite(STBY, HIGH);
  // control speed between 0 and 255
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void reverse()
{
  digitalWrite(STBY, HIGH);
  //digitalWrite(PWMA, HIGH);
  //digitalWrite(PWMB, HIGH);
  // control speed between 0 and 255
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void brake()
{
  digitalWrite(STBY, HIGH);
  //digitalWrite(PWMA, HIGH);
  //digitalWrite(PWMB, HIGH);
  // control speed between 0 and 255
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, HIGH);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, HIGH);
}

void left()
{
  digitalWrite(STBY, HIGH);
  //digitalWrite(PWMA, HIGH);
  //digitalWrite(PWMB, HIGH);
  // control speed between 0 and 255
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}

void right()
{
  digitalWrite(STBY, HIGH);
  //digitalWrite(PWMA, HIGH);
  //digitalWrite(PWMB, HIGH);
  // control speed between 0 and 255
  analogWrite(PWMA, PWMSPD);
  analogWrite(PWMB, PWMSPD);
  
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}

void receiver(){
  if (Serial.available() > 0){
    receivedchar = Serial.read();
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  receiver();

    if(receivedchar == 'w'){
    forward();
    Serial.println("moving forward");
  }
  else if (receivedchar == 's'){
    brake();
    Serial.println("braking");
  }
    else if (receivedchar == 'd'){
    left();
    Serial.println("turning left");
  }
    else if (receivedchar == 'a'){
    right();
    Serial.println("turning right");
  }
    else if (receivedchar == 'x'){
    reverse();
    Serial.println("reversing");
  }
    if (receivedchar == 'i'){
    while(toppos < 180){
      toppos ++;
      top.write(toppos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }

    if (receivedchar == ','){
    while(toppos >= 10){
      toppos --;
      top.write(toppos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }
  if (receivedchar == 'j'){
    while(basepos < 180){
      basepos ++;
      base.write(basepos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }

    if (receivedchar == 'l'){
    while(basepos >= 10){
      basepos --;
      base.write(basepos);
      delay(10);
      receiver();
      if(receivedchar == 'k'){
        break;
      }
    }
  }
    if (receivedchar == 'o'){
      top.write(90);
      base.write(90);
  }
  
}
