#include <hcsr04.h>
#define TRIG_PIN 12
#define ECHO_PIN 13

int LEn=3;
int REn=5;
int LDir=2;
int RDir=4;
int myt;
int t1;

HCSR04 hcsr04(TRIG_PIN, ECHO_PIN, 20, 4000);
void setup() {
  pinMode(LEn, OUTPUT);
  pinMode(REn, OUTPUT);
  pinMode(LDir, OUTPUT);
  pinMode(RDir, OUTPUT);

  Serial.begin(9600);

  //analogWrite(LEn, 200);
  //analogWrite(REn, 200);
  digitalWrite(LDir,HIGH);
  digitalWrite(RDir,LOW);

}

void loop() {
analogWrite(LEn, 200);
analogWrite(REn, 200);
 if(hcsr04.distanceInMillimeters()>450)
 {
  digitalWrite(LDir,HIGH);
  digitalWrite(RDir,LOW);
  delay(50);
 }

if((hcsr04.distanceInMillimeters()<450)&&(hcsr04.distanceInMillimeters()>10))
 {
  myt=millis();

  //компенсация инерции:
  digitalWrite(LDir,LOW);
  digitalWrite(RDir,HIGH);
  delay(500);

        do{
          digitalWrite(LDir,LOW);
          digitalWrite(RDir,HIGH);
          delay(100);
          }
        while(hcsr04.distanceInMillimeters()>450);

    t1 = millis() - myt;
    t1 = round(t1 / 2);

  digitalWrite(LDir,HIGH);
  digitalWrite(RDir,LOW);

  delay(t1);

  analogWrite(LEn, 0);
  analogWrite(REn, 0);
  delay(5000);

 }
}
