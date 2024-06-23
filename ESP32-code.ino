#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

int IN1 = 15;     //motor1 
int IN2 = 2;    //motor1
int ENA = 0;

int IN3 = 4;   //motor2 
int IN4 = 16;   //motor2  
int ENB = 17;

char bt = 0;

void My_Motor(bool a, bool b,bool c, bool d){

    digitalWrite(IN1,a);
    digitalWrite(IN2,b);
    digitalWrite(IN3,c);
    digitalWrite(IN4,d);
}

void motorForward(){
  My_Motor(1,0,0,1);
}

void motorBackward(){
  My_Motor(0,1,1,0);
}

void motorStop(){
  My_Motor(0,0,0,0);
}

void motorRight(){
  My_Motor(1,0,1,0);
}

void motorLeft(){
  My_Motor(0,1,1,0);
}

void motorSetSpeed(char motor, int speed){
  if(motor == 'L'){
    analogWrite(ENB, speed);
  }
  else if(motor == 'R'){
    analogWrite(ENA, speed);
  }
  else if(motor == 'B'){
    analogWrite(ENA, speed);
    analogWrite(ENB, speed);
  }
}

void setup() 
{ 
    Serial.begin(115200); 
    SerialBT.begin("Robot"); 

    pinMode(IN1,OUTPUT); 
    pinMode(IN2,OUTPUT); 
    pinMode(IN3,OUTPUT); 
    pinMode(IN4,OUTPUT); 

    motorSetSpeed('B', 255);
} 


void loop() 
{ 
    run();
}


void run(){
if (SerialBT.available() > 0) 
{ 
 bt = SerialBT.read();

 Serial.print(bt);
  
 if(bt == 'B')        //move back
 { 
    motorBackward();
 } 
 
 else if (bt == 'F')    //move forward 
 { 
    motorForward();
 } 

 else if (bt == 'L')    // move left
 { 
    motorLeft();
 } 
 else if (bt == 'R')     //move right
 { 
    motorRight();
 } 

 else if (bt == 'S')    //forward right 
 { 
    motorStop();
 } 
 } 
}