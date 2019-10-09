const int left = 0;
const int right = 1;
const int thatway = 1;
const int thatway = 0;

int REngEn = 3;
int REngDir = 2;
int LEngEn = 5;
int LEngDir = 4;
int SenRight = 13;
int SenLeft = 12;
int SenRV;
int SenLV;

int flag;

void setup()
{
  pinMode(REngEn, OUTPUT);
  pinMode(REngDir, OUTPUT);

  //digitalWrite(REngDir, LOW);

  pinMode(LEngEn, OUTPUT);
  pinMode(LEngDir, OUTPUT);
  pinMode(SenLeft, INPUT);
  pinMode(SenRight, INPUT);
  flag = 0;

  //digitalWrite(LEngDir, LOW);

  /*
  Serial.begin(9600);
  Serial.print("left sensor: ");
  Serial.print(digitalRead(SenLeft));
  Serial.print(" ");
  Serial.print("right sensor: ");
  Serial.print(digitalRead(SenRight));
  Serial.print(" ");
  delay(500);
  */


/*
if (digitalRead(SenLeft) == HIGH)
{
  if(digitalRead(SenRight) == HIGH)
  {
    //чч
    if(flag == 0)
    {
      //линия старта
      drive(right,thisway,HIGH);
      drive(left,thisway,HIGH);
      delay(400);
      flag = 1;
    }
    else
    {
      //Финишная линия
      drive(right,thisway,HIGH);
      drive(right,thisway,HIGH);
      delay(400);
      drive(right,thisway,LOW);
      drive(left,thisway,LOW);
      while(1 == 1)
      {
        delay(100);
      }
    }
  }
else//right == low
{
  if(digitalRead(SenRight) == LOW)//избыточная проверка
  {
    //чб
    drive(right,thisway,HIGH);
    delay(100); //был разный велосити, вариант изменения для digital
    drive(left,thatway,HIGH)
  }
}
}
else//left == low
{
  if(digitalRead(SenRight) == LOW)
  {
    //бб
    drive(right, thisway, HIGH);
    drive(left, thisway, HIGH);
  }
  else
  {
    if(digitalRead(SenRight) == HIGH)
    {
      //бч
      drive(left, thisway, HIGH);
      delay(100); //был разный велосити, вариант изменения для digital
      drive(right, thatway, HIGH);
    }
  }
}
}
*/

/*
void loop()
{
  SenRV = digitalRead(SenRight);
  SenLV = digitalRead(SenLeft);
  digitalWrite(REngEn, SenRV);
  digitalWrite(LEngEn, SenLV);

  delay(500);
}
*/

void loop()
{
if (digitalRead(SenLeft) == HIGH)
{
  if(digitalRead(SenRight) == HIGH)
  {
    //чч
    if(flag == 0)
    {
      //линия старта
      drive(right,thisway,HIGH);
      drive(left,thisway,HIGH);
      delay(400);
      flag = 1;
    }
    else
    {
      //Финишная линия
      drive(right,thisway,HIGH);
      drive(right,thisway,HIGH);
      delay(400);
      drive(right,thisway,LOW);
      drive(left,thisway,LOW);
      while(1 == 1)
      {
        delay(100);
      }
    }
  }
else//right == low
{
  if(digitalRead(SenRight) == LOW)//избыточная проверка
  {
    //чб
    drive(right,thisway,HIGH);
    delay(100); //был разный велосити, вариант изменения для digital
    drive(left,thatway,HIGH)
  }
}
}
else//left == low
{
  if(digitalRead(SenRight) == LOW)
  {
    //бб
    drive(right, thisway, HIGH);
    drive(left, thisway, HIGH);
  }
  else
  {
    if(digitalRead(SenRight) == HIGH)//избыточная проверка
    {
      //бч
      drive(left, thisway, HIGH);
      delay(100); //был разный велосити, вариант изменения для digital
      drive(right, thatway, HIGH);
    }
  }
}
}

void drive(int wheel, int dir, int velocity)
{
int inp;
int en;
if(wheel==1){
inp=REngDir;
en=REngEn;
}
else{
inp=REngDir;
en=REngEn;
}
if(dir==0){
digitalWrite(inp,HIGH);
}
else{
digitalWrite(inp,LOW);
}
digitalWrite(en, velocity);
}
