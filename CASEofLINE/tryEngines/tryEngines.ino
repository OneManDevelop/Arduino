const int REngEn = 3;
const int REngDir = 2;
const int SenRight = 13;
int SenRV;

void setup() 
{
  //  Serial.begin(9600);
  pinMode(REngEn, OUTPUT);
  pinMode(REngDir, OUTPUT);
  pinMode(SenRight, INPUT);
  digitalWrite(REngDir, LOW);
  //pinMode(10, OUTPUT);
}

void loop() 
{ SenRV = digitalRead(SenRight);
//Serial.write(SenRight);
if(SenRV == HIGH){
  digitalWrite(REngEn, HIGH);
}
else{
  digitalWrite(REngEn, LOW);
}
}
