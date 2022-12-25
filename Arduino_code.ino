int led = 3;        //led 
int outPin1 = 12;     //motor1 
int outPin2 = 11;    //motor1 
int outPin4 = 10;   //motor2 
int outPin3 = 9;   //motor2 
char bt = 0;       //BT  

void setup() 
{ 
Serial.begin(9600); 
pinMode(outPin1,OUTPUT); 
pinMode(outPin2,OUTPUT); 
pinMode(outPin3,OUTPUT); 
pinMode(outPin4,OUTPUT); 
pinMode(led,OUTPUT); 
} 
void loop() 
{ 
if (Serial.available() > 0) 
{ 
 bt = Serial.read(); 
 digitalWrite(led, 1); 
  
 if(bt == 'B')        //move back
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,HIGH); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW);
   
    
 } 
 else if (bt == 'F')       //move forward 
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,HIGH);
 } 
 else if (bt == 'S')     //stop!! 
 {    
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,LOW); 
 } 
 else if (bt == 'L')    // move left
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,HIGH); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,HIGH);
 } 
 else if (bt == 'R')     //move right
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW);
 } 
 else if (bt == 'G')    //forward right 
 { 
   digitalWrite(outPin1,HIGH); 
   digitalWrite(outPin2,LOW); 
   digitalWrite(outPin3,LOW); 
   digitalWrite(outPin4,HIGH);
 } 
 else if (bt == 'I')    //forward left 
 { 
   digitalWrite(outPin1,LOW); 
   digitalWrite(outPin2,HIGH); 
   digitalWrite(outPin3,HIGH); 
   digitalWrite(outPin4,LOW); 
 } 
 } 
}
