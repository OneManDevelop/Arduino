#include <hcsr04.h>

#define TRIG_PIN A0
#define ECHO_PIN A1

const int REngEn = 3;
const int REngDir = 2;
const int LEngEn = 5;
const int LEngDir = 4;

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
 // digitalWrite(REngEn, HIGH);
 // digitalWrite(LEngEn, HIGH);
    // Output the distance in mm
  Serial.println(hcsr04.distanceInMillimeters());

    // Output information about the device, driver, and distance in Bifrost JSON format
    Serial.println(hcsr04.ToString());
if(hcsr04.distanceInMillimeters()>150){
  analogWrite(REngEn, 150);
  analogWrite(LEngEn, 150);
  }
else{
  digitalWrite(REngEn, LOW);
  digitalWrite(LEngEn, LOW);
  }
    delay(250);
}
