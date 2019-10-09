#include <hcsr04.h> 

#define TRIG_PIN 12
#define ECHO_PIN 13

const int LEngEn = 3; 
const int LEngDir = 2; 
const int REngEn = 5; 
const int REngDir = 4; 
const int button1 = 6;

const int VelR = 125;
const int VelL = 105;
int tOfSet;
int t1;
int tIndif = 600;

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);

void setup() {
  // put your setup code here, to run once:
pinMode(REngEn, OUTPUT); 
pinMode(REngDir, OUTPUT); 
digitalWrite(REngDir, HIGH); 

pinMode(LEngEn, OUTPUT); 
pinMode(LEngDir, OUTPUT); 
digitalWrite(LEngDir, LOW); 
}

void loop() {
  // put your main code here, to run repeatedly:
setMiddle(VelR,VelL);
delay(3000);
}

bool seeCan(){
  bool res = (hcsr04.distanceInMillimeters()<250);
  return res;
}

void setWheelsRL(int dirR,int dirL){
  digitalWrite(LEngDir, dirL);
  digitalWrite(REngDir, dirR);
  //analogWrite(PinRv,vright);
  //analogWrite(PinLv, vleft);  
}

void setMiddle(int vr, int vl){
    analogWrite(REngEn, vr); 
    analogWrite(LEngEn, vl);
    while(seeCan()==false){
    setWheelsRL(!HIGH,LOW);
  }
  setWheelsRL(!LOW,HIGH);
  delay(tIndif);
  tOfSet = millis();
  while(seeCan()==false){
    setWheelsRL(!HIGH,LOW);
  }
  t1 = millis() - tOfSet;
  t1 = round(t1 / 2);
  analogWrite(REngEn, 0); 
  analogWrite(LEngEn, vl);
  delay(t1 + tIndif);
  analogWrite(REngEn, 0); 
  analogWrite(LEngEn, 0);
  }

