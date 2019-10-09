const int REngEn = 3;
const int REngDir = 2;
const int LEngEn = 5;
const int LEngDir = 4;
const int SenRight = 13;
const int SenLeft = 12;
int SenRV;
int SenLV;

void setup(){
  pinMode(REngEn, OUTPUT);
  pinMode(REngDir, OUTPUT);
  pinMode(SenRight, INPUT);
  digitalWrite(REngDir, HIGH);

  pinMode(LEngEn, OUTPUT);
  pinMode(LEngDir, OUTPUT);
  pinMode(SenLeft, INPUT);
  digitalWrite(LEngDir, HIGH);
}

void loop(){
  SenRV = digitalRead(SenRight);
  SenLV = digitalRead(SenLeft);
  digitalWrite(REngEn, SenRV);
  digitalWrite(LEngEn, SenLV);
}
