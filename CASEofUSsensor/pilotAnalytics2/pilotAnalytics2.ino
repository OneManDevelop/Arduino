const int lg = 80;
int DefVal[lg];
int MidVal[lg];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  fillArr(10, 5);
  glitch(2,2);
  //outp();
  buildGraph(5);
  delay(3000);
  GetMidVals(4);
  buildGraph2(5);
  while (true) {
    Serial.println("5c wasted");
    delay(5000);
  }
}

void outp() {
  for (int i = 0; i < lg; i++) {
    Serial.print(DefVal[i]);
    Serial.print(',');
  }
}

void fillArr(float k1, int k2) {
  float arg;
  float res;
  for (int i = 0; i < lg; i++) {
    arg = (i / k1) * PI;
    res = (cos(arg) * k2);
    DefVal[i] = (int)res;
  }
}

void glitch(int k3, int k4) {
  int k41;
  for (int i = 0; i < lg; i = i + random(k3)) {
    k41 = (int)(k4 / 2);
    DefVal[i] = DefVal[i] - k41 + random(k4);
  }
}

//k5 == k2
void buildGraph(int k5) {
  for (int g = k5; (g > -k5 - 1); g--) {
    Serial.println("N");
    for (int i = 0; i < lg; i++) {
      if (DefVal[i] == g) {
        Serial.print("+");
      }
      else {
        Serial.print(" ");
      }
    }
  }
}

void buildGraph2(int k5) {
  Serial.println(" ");
  for (int i = 0; i < lg; i++) {
    Serial.print("X");
  }
  Serial.println(" ");
  
  for (int g = k5; (g > -k5 - 1); g--) {
    Serial.println("N");
    for (int i = 0; i < lg; i++) {
      if (MidVal[i] == g) {
        Serial.print("+");
      }
      else {
        Serial.print(" ");
      }
    }
  }
}

void GetMidVals(int k6) {
  int s;
  for (int i = 0; i < k6; i++) {
    MidVal[i] = 0;
    // mb change later
  }
  for (int i = k6; i < lg; i++) {
    s = 0;
    for (int g = i - k6; g < i; g++) {
      s = s + DefVal[g];
    }
    MidVal[i] = (int)(s / k6);
  }
}
