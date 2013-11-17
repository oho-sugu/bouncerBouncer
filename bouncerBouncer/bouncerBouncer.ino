int FIN = 5;
int RIN = 6;
int count = 0;
int OFFSET = 40;
int MAX = 256;

void setup() {
  pinMode(FIN, OUTPUT);
  pinMode(RIN, OUTPUT);
}

void loop() {
  delay(100);
  count += 1;
  count %= MAX - OFFSET;
  analogWrite(FIN, count + OFFSET);
  digitalWrite(RIN, LOW);
}

