#include <hcsr04.h> 

#define TRIG_PIN 12 
#define ECHO_PIN 13 

const int LEngEn = 3; 
const int LEngDir = 2; 
const int REngEn = 5; 
const int REngDir = 4; 
//const int button1 = 6; 

const int VelR = 150; 
const int VelL = 150; 
int tOfSet; 
int t1; 
//int tIndif = 600; 
bool fl; 

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000); 

void setup() { 

pinMode(REngEn, OUTPUT); 
pinMode(REngDir, OUTPUT); 
//digitalWrite(REngDir, HIGH); 

pinMode(LEngEn, OUTPUT); 
pinMode(LEngDir, OUTPUT); 
//digitalWrite(LEngDir, LOW); 
} 

void loop() {  
 setMiddle(VelR,VelL); 
 delay(3000); 
} 

bool seeCan(){ 
 bool res = (hcsr04.distanceInMillimeters()<450)&&hcsr04.distanceInMillimeters()>10; 
 return res; 
} 

/*
задает направления колес, т.к. выносить скорость в отдельную
функцию счел нецелесообразным
p.s. потом при вызове функции пришлось химичить с
!(значение), т.к. на роботе перепутана полярность
одного мотора
*/
void setWheelsRL(bool dirR,bool dirL){ 
 digitalWrite(LEngDir, dirL); 
 digitalWrite(REngDir, dirR); 
//analogWrite(PinRv,vright); 
//analogWrite(PinLv, vleft); 
} 

void setMiddle(int vr, int vl){ 
 analogWrite(REngEn, vr); 
 analogWrite(LEngEn, vl); 
 
 while(seeCan()==false){ //рис(1)
  setWheelsRL(!HIGH,LOW); 
 } 
 fl=false; 
 tOfSet = millis(); 

 while((seeCan()==false)||(fl==false)){ //рис(2)
  /*
  будет крутиться обратно пока видит 1ое перепятсвие, 
  а затем - просвет, на 2ом препятствии должно остановиться
  */
  setWheelsRL(!LOW,HIGH); 
  if(seeCan()==false){ 
   fl=true; 
  } 
 } 
 t1 = millis() - tOfSet; 
 t1 = round(t1 / 2); 
 //половина времени на поворот между препятствий
 setWheelsRL(!HIGH,LOW); //рис(3)
 delay(t1); 
 analogWrite(REngEn,0); 
 analogWrite(LEngEn,0); 
}
