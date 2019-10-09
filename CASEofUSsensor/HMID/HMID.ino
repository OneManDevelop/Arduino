const int trigPin = 12;
const int echoPin = 13;
int LEn=3;
int REn=5;
int LDir=2;
int RDir=4;
int QClose = 25;
int TClose = 5;
int myt;
int t1;

void setup()  {
  pinMode(trigPin, OUTPUT); // триггер - выходной пин
  pinMode(echoPin, INPUT); // эхо - входной
  digitalWrite(trigPin, LOW);
  Serial.begin(9600); // инициализация послед. порта

  pinMode(LEn, OUTPUT);
  pinMode(REn, OUTPUT);
  pinMode(LDir, OUTPUT);
  pinMode(RDir, OUTPUT);

 // Serial.begin(9600);

  analogWrite(LEn, 0);
  analogWrite(REn, 0);
  
}

void loop()  { 
  //long distance = getDistance(); // получаем дистанцию с датчика
 // Serial.println(distance); // выводим в последовательный порт
 // delay(100);
 Serial.print("p1:");
Serial.println(getDistance());
analogWrite(REn, 200);
analogWrite(LEn, 200);
//delay(300);

 if(getDistance()>QClose)
 {
  Serial.print("p2:");
  Serial.println(getDistance());
  digitalWrite(LDir,LOW);
  digitalWrite(RDir,LOW);
  analogWrite(LEn, 200);
  analogWrite(REn, 200);
  delay(50);
 }

if((getDistance()<QClose)&&(getDistance()>TClose))
 {
  myt=millis();
Serial.print("p3:");
Serial.println(getDistance());
  //компенсация инерции:
  digitalWrite(LDir,HIGH);
  digitalWrite(RDir,HIGH);
  analogWrite(LEn, 200);
  analogWrite(REn, 200);
  //delay(250);

        do{
          Serial.print("p4:");
          Serial.println(getDistance());
          analogWrite(LEn, 200);
          analogWrite(REn, 200);
          delay(10);
          }
        while(getDistance>QClose);

   Serial.print("p5:");
   Serial.println(getDistance());

   t1 = millis() - myt;
   t1 = round(t1 / 2);

   Serial.println("p5");

  digitalWrite(LDir,LOW);
  digitalWrite(RDir,LOW);
  analogWrite(LEn, 200);
  analogWrite(REn, 200);

  delay(t1);

  analogWrite(LEn, 0);
  analogWrite(REn, 0);
  //delay(5000);

 }
} 

// Определение дистанции до объекта в см
long getDistance() {
  long distacne_cm = getEchoTiming() * 1.7 * 0.01;
  return distacne_cm;
}

// Определение времени задержки
long getEchoTiming() {
  digitalWrite(trigPin, HIGH); // генерируем 10 мкс импульс запуска
  delayMicroseconds(10);  
  digitalWrite(trigPin, LOW);
  // определение на пине echoPin длительности уровня HIGH, мкс:
  long duration = pulseIn(echoPin, HIGH); 
  return duration;
}
