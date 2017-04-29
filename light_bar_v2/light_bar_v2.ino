
unsigned long raw = 0;
const int CH3 = 3;
const int PATNUM = 4;

void setup() {
  Serial.begin(9600);
  pinMode(CH3, INPUT);
}

void loop() {
  // read value from pin
  // print debug statement
  debug("pulseIn", readSmooth());
//  delay(100);
}

void debug(String msg, unsigned long value) {
  Serial.print(msg);
  Serial.print(": ");
  Serial.print(value);
  Serial.println();
}

unsigned long readCH3() {
  return pulseIn(CH3, HIGH);
}

unsigned long readSmooth() {
  return (readCH3() / 20)%PATNUM;
}

