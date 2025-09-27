#include <Servo.h>
#include "NewPing.h"
#include "SR04.h"

const int TRIG_PIN = 7;
const int ECHO_PIN = 6;

NewPing sonar(TRIG_PIN, ECHO_PIN); 

boolean goesForward=false;
long duration;
int distance = 100;

int enA = 5;
int DIRA = 4;
int DIRB = 3;

Servo myservo;

void setup(){

  Serial.begin(9600);
  myservo.attach(9);  
  myservo.write(90); 
  pinMode(TRIG_PIN,OUTPUT);
  pinMode(ECHO_PIN,INPUT);
  pinMode(enA, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){
int distanceR = 0;
int distanceL =  0;
delay(40);
 
 if(distance<=35)
 {
  moveStop();
  delay(100);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    delay(500);

    moveStop();
    delay(500);

    turnLeft();
    delay(770);

    moveStop();
    delay(500);

    turnRight();
    delay(500);

    moveForward();
    delay(500);

  }
  else
  {
    turnLeft();
    delay(500);

    moveStop();
    delay(500);
    
    turnRight();
    delay(770);
    
    
    moveStop();
    delay(500);
    
    turnLeft();
    delay(500);

    moveForward();
    delay(500);
    
  }
 
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    myservo.write(45); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
}

int lookLeft()
{
    myservo.write(135); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(90); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  analogWrite(enA, 0);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
  } 
  
void moveForward() {
  myservo.write(90);
  analogWrite(enA, 130);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
}


void turnRight() {
     myservo.write(45);
    analogWrite(enA, 255);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);    
} 
 
void turnLeft() {
  myservo.write(135);
    analogWrite(enA, 255);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
} 
