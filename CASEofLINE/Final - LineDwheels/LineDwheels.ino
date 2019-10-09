const int REngEn = 3;
const int REngDir = 2;
const int LEngEn = 5;
const int LEngDir = 4;
const int SenRight = 13;
const int SenLeft = 12;
const int velR = 103;
const int velL = 155;
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
  if(SenRV == HIGH){
    if(SenLV == HIGH){
      analogWrite(REngEn, velR);
      analogWrite(LEngEn, velL);
      }
    else{
      analogWrite(REngEn, velR);
      analogWrite(LEngEn, 0);     
      }
  }
    else{
    if(SenLV == HIGH){
      analogWrite(REngEn, 0);
      analogWrite(LEngEn, velL);
      }
    else{
      analogWrite(REngEn, 0);
      analogWrite(LEngEn, 0);     
      }
    }
  //analogWrite(REngEn, 200);
  //analogWrite(LEngEn, 200);
}
