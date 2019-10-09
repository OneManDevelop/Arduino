#include <hcsr04.h> 

#define TRIG_PIN 12
#define ECHO_PIN 13

const int LEngEn = 3; 
const int REngDir = 2; 
const int REngEn = 5; 
const int LEngDir = 4; 
const int button1 = 6;
int flag = 0; 
int t = 250;

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000); 

void setup(){ 
Serial.begin(9600); 
pinMode(REngEn, OUTPUT); 
pinMode(REngDir, OUTPUT); 
digitalWrite(REngDir, HIGH); 

pinMode(LEngEn, OUTPUT); 
pinMode(LEngDir, OUTPUT); 
digitalWrite(LEngDir, LOW); 
} 

void loop() { 
//analogWrite(REngEn, 0); 
//analogWrite(LEngEn, 100); 
flag = 0;
// analogWrite(REngEn, 150);
// analogWrite(LEngEn, 150);
digitalWrite(REngEn, LOW); 
digitalWrite(LEngEn, LOW); 
Serial.println(hcsr04.distanceInMillimeters()); 
if(flag == 0){
// Output the distance in mm 
// Output information about the device, driver, and distance in Bifrost JSON format 
Serial.println(hcsr04.ToString()); 
if(hcsr04.distanceInMillimeters()>150){ 
if(analogRead(button1)>120){
analogWrite(REngEn, 150); 
analogWrite(LEngEn, 150); 
}
} 
else{ 
flag = 1; 
digitalWrite(REngEn, LOW); 
digitalWrite(LEngEn, LOW); 
} 
}
delay(250);
// analogReadSerial?
if((flag == 1) && (analogRead(button1)>120)){ 
digitalWrite(REngEn, LOW); 
analogWrite(LEngEn, 150); 
delay(t*2); 
analogWrite(REngEn, 150); 
analogWrite(LEngEn, 150); 
delay(t*2); 
analogWrite(REngEn, 200); 
digitalWrite(LEngEn, LOW); 
delay(t*5); 
analogWrite(REngEn, 150); 
analogWrite(LEngEn, 150); 
delay(t*2); 
digitalWrite(REngEn, LOW); 
analogWrite(LEngEn, 150); 
delay(t*2); 
} 
}


