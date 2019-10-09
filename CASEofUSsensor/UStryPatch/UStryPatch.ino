#include <hcsr04.h> 

#define TRIG_PIN 12 
#define ECHO_PIN 13 

const int LEngEn = 3; 
const int LEngDir = 2; 
const int REngEn = 5; 
const int REngDir = 4; 
//const int button1 = 6; 

const int VelR = 200; 
const int VelL = 200; 
int tOfSet; 
int t1; 
//int tIndif = 600; 
bool fl; 

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000); 

int seeCan()
{ 
  int res=0;
  Serial.println("Serial 301");
 if((hcsr04.distanceInMillimeters()<450)&&(hcsr04.distanceInMillimeters()>10))
 {
    Serial.println("Serial 302");
    res=1; 
 }
 Serial.println("Serial 303");
 Serial.println("ress");
 Serial.println(1);

 return res; 
} 

void setup() 
{ 
  
  pinMode(REngEn, OUTPUT); 
  pinMode(REngDir, OUTPUT); 
  //digitalWrite(REngDir, HIGH); 
  
  pinMode(LEngEn, OUTPUT); 
  pinMode(LEngDir, OUTPUT); 
  //digitalWrite(LEngDir, LOW);
  Serial.begin(9600); 
  //digitalWrite(LEngDir, 1); 
  //digitalWrite(REngDir, 1);
  analogWrite(LEngEn, 0);
  analogWrite(LEngEn, 0);
  Serial.println("Serial 201");
  seeCan();
  Serial.println("Serial 202");
} 

void loop()
{  
  setMiddle(VelR,VelL); 
  delay(100); 
} 


/*
задает направления колес, т.к. выносить скорость в отдельную
функцию счел нецелесообразным
p.s. потом при вызове функции пришлось химичить с
!(значение), т.к. на роботе перепутана полярность
одного мотора
*/
void setWheelsRL(int dirR,int dirL)
{ 
 digitalWrite(LEngDir, dirL); 
 digitalWrite(REngDir, dirR); 
} 

void setMiddle(int vr, int vl)
{  
 analogWrite(REngEn, vr); 
 analogWrite(LEngEn, vl); 
 
 Serial.println("Serial 101");
 //Serial.println(seeCan());
 Serial.println("Serial 102");
 
 while(seeCan()==false)
 { //рис(1)
    setWheelsRL(0,1); 
 }
 
 fl=false; 
 tOfSet = millis(); 
 Serial.println("Serial2");
 Serial.println(seeCan());

 /*while((seeCan()==false)||(fl==false)){ //рис(2)
  /*
  будет крутиться обратно пока видит 1ое перепятсвие, 
  а затем - просвет, на 2ом препятствии должно остановиться
  */
 /* setWheelsRL(0,1); 
  if(seeCan()==false){ 
   fl=true; 
  } 
 } 
 */
 
  do{setWheelsRL(1,1);}
  while((seeCan()==false)||(fl==false));

 setWheelsRL(0,0);
 
 t1 = millis() - tOfSet; 
 t1 = round(t1 / 2); 
 //половина времени на поворот между препятствий
 setWheelsRL(0,0); //рис(3)
 delay(t1); 
 analogWrite(REngEn,0); 
 analogWrite(LEngEn,0); 
}
