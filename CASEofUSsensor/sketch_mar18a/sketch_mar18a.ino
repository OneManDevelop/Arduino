const int lg = 80;
int DefVal[lg];
int MidVal[lg];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void fillArr(int k1, int k2) {
  float arg;
  for (int i = 0; i < lg; i++) {
    arg = (i / k1) * PI;
    DefVal[i] = (int)(sin(arg) * k2);
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
  for (int g = -k5; (g < k5 + 1); g++) {
    Serial.println('T');
    for (int i = 0; i < lg; i++) {
      if (DefVal[i] == g) {
        Serial.print('X');
      }
      else {
        Serial.print('O');
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
