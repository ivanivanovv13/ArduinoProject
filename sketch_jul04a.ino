#include <SoftwareSerial.h>
SoftwareSerial Blue(10,9);
int const Backlights=12,Frontlights=13;
int const Motor1A=7;
int const Motor1B=6;
int const Motor2A=3;
int const Motor2B=2;
void setup() {
  Blue.begin(9600);
  // put your setup code here, to run once:
  pinMode(Frontlights,OUTPUT);
  pinMode(Backlights,OUTPUT);
  pinMode(Motor1A,OUTPUT);
  pinMode(Motor1B,OUTPUT);
  pinMode(Motor2A,OUTPUT);
  pinMode(Motor2B,OUTPUT);
}

bool emergencyOnOff=false;
int emergencyHighLow=HIGH;
int skorost;
unsigned long previousMillisOn = 0; 
unsigned long previousMillisOff = 500; 
const long interval = 500; 

void loop() {
  char msg;
  
  
  // put your main code here, to run repeatedly:
 if(Blue.available()>0)
 {
  msg=Blue.read();
  switch(msg)
   {
    case 'F': MoveForward(); break;
    case 'B': MoveBackward(); break;
    case 'L': RotateLeft(); break;
    case 'R': RotateRight(); break;
    case 'S': Stop(); break;
    
    case'W':digitalWrite(Frontlights,HIGH);break;
    case'w':digitalWrite(Frontlights,LOW);break;
    case'U':digitalWrite(Backlights,HIGH);break;
    case'u':digitalWrite(Backlights,LOW);break;
    
    case 'X': emergencyOnOff=true; break;
    case 'x': emergencyOnOff=false; digitalWrite(Frontlights,LOW);
    digitalWrite(Backlights,LOW); break;
   }
 }
 unsigned long currentMillis = millis();
 if(emergencyOnOff== true)
 {
   if(currentMillis-previousMillisOn>interval)
   {
      previousMillisOn=currentMillis;
      if(emergencyHighLow==LOW)
      {
        emergencyHighLow=HIGH;
      }
      else
      {
        emergencyHighLow=LOW;
      }
      digitalWrite(Frontlights,emergencyHighLow);
      digitalWrite(Backlights,emergencyHighLow);
   }
 }
 delay(1);
}

void MoveForward()
{
  digitalWrite(Motor1A, HIGH);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,HIGH);
  digitalWrite(Motor2B,LOW);
}

void MoveBackward()
{
  digitalWrite(Motor1A,LOW);
  digitalWrite(Motor1B,HIGH);
  digitalWrite(Motor2A,LOW);
  digitalWrite(Motor2B,HIGH);
}

void RotateLeft()
{
  digitalWrite(Motor1A,LOW);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,HIGH);
  digitalWrite(Motor2B,LOW);
}
void RotateRight()
{
  digitalWrite(Motor1A,HIGH);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,LOW);
  digitalWrite(Motor2B,LOW);
}
void Stop()
{
  digitalWrite(Motor1A,LOW);
  digitalWrite(Motor1B,LOW);
  digitalWrite(Motor2A,LOW);
  digitalWrite(Motor2B,LOW);
}




  
