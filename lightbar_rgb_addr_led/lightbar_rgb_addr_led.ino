
#include <Adafruit_NeoPixel.h>

int x;
int y;

// use 

int rcRead;
int rcValue;

unsigned long raw = 0;
const int RECEIVER_PIN = 9;
const int LIGHTBAR_PIN = 10;
const int LIGHTBAR_COUNT = 5;
const int PATTERN_COUNT = 6;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LIGHTBAR_COUNT, LIGHTBAR_PIN, NEO_RGB + NEO_KHZ800);
////
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  off();
  strip.show();

  pinMode(RECEIVER_PIN, INPUT);

  Serial.begin(9600);
}
////
void loop() {
  rcValue = readSmooth();
  debug("rcValue", rcValue);

  if (2 == rcValue) {
    debug("off", rcValue);
    off();
  }
  if (1 == rcValue) {
    debug("on", rcValue);
    on();
  }
  if (0 == rcValue){
    debug("police", rcValue);
    police();
  }
  if (5 == rcValue) {
    debug("strobe", rcValue);
    strobe();
  }
  if (4 == rcValue) {
    debug("strobe2", rcValue);
    strobe2();
  }
  if (3  == rcValue) {
    debug("RainbowTwo", rcValue);
    rainbowTwo();
  }
}
////
unsigned long readRECEIVER_PIN() {
  return pulseIn(RECEIVER_PIN, HIGH);
}
////
unsigned long readSmooth() {
  return (readRECEIVER_PIN() / 20)%PATTERN_COUNT;
}
////
void debug(String msg, unsigned long value) {
  Serial.print(msg);
  Serial.print(": ");
  Serial.print(value);
  Serial.println();
}
////

/***PPPP***AAA**TTTTT*TTTTT*EEEEE*RRRR**NN****N**SSSS********************************************************************************/
/***P***P*A***A***T*****T***E*****R***R*N*N***N*S************************************************************************************/
/***PPPP**AAAAA***T*****T***EEEE**RRRR**N**N**N**SSS*********************************************************************************/
/***P****A*****A**T*****T***E*****R*R***N***N*N*****S********************************************************************************/
/***P****A*****A**T*****T***EEEEE*R**R**N****NN*SSSS*********************************************************************************/

void off() {
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.show();
}
////
void on() {
  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(1, 255, 255, 255);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 255, 255, 255);
  strip.show();
  delay(1);
}
////
void rainbow() {
  
  for(x=255; x>=0; x -= 5) {
    strip.setPixelColor(0, x, (-x+255), 0);
    strip.setPixelColor(1, 0, x, (-x+255));
    strip.setPixelColor(2, (-x+255), 0, x);
    strip.setPixelColor(3, x, (-x+255), 0);
    strip.setPixelColor(4, 0, x, (-x+255));
    strip.show();
    delay(100);
  }

  for(x=255; x>=0; x -= 5) {
    strip.setPixelColor(0, 0, x, (-x+255));
    strip.setPixelColor(1, (-x+255), 0, x);
    strip.setPixelColor(2, x, (-x+255), 0);
    strip.setPixelColor(3, 0, x, (-x+255));
    strip.setPixelColor(4, (-x+255), 0, x);
    strip.show();
    delay(100);
  }

  for(x=255; x>=0; x -= 5) {
    strip.setPixelColor(0, (-x+255), 0, x);
    strip.setPixelColor(1, x, (-x+255), 0);
    strip.setPixelColor(2, 0, x, (-x+255));
    strip.setPixelColor(3, (-x+255), 0, x);
    strip.setPixelColor(4, x, (-x+255), 0);
    strip.show();
    delay(100);
  }
  
}
////
void rainbowTwo() {

  for(y=0; y<=4; y++) {
    for(x=0; x<=255; x++) {
      strip.setPixelColor((y+4)%5, 255, x, 0);
      strip.setPixelColor((y+3)%5, 255-x, 255, 0);
      strip.setPixelColor((y+2)%5, 0, 255-x, x);
      strip.setPixelColor((y+1)%5, 0.5*x, 0, 255-(0.5*x));
      strip.setPixelColor((y+0)%5, 128+(0.5*x), 0, 128-(0.5*x));
      strip.show();
      delay(3);
    }
  }
}
////
void police() {

  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.show();
  delay(100);
  off();
  delay(100);
  strip.setPixelColor(0, 255, 0, 0);
  strip.setPixelColor(1, 255, 0, 0);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.show();
  delay(100);
  off();
  delay(200);

  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 0, 0, 255);
  strip.setPixelColor(4, 0, 0, 255);
  strip.show();
  delay(100);
  off();
  delay(100);
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 0, 0, 255);
  strip.setPixelColor(4, 0, 0, 255);
  strip.show();
  delay(100);
  off();
  delay(200);
}
////
void strobe() {
  strip.setPixelColor(0, 255, 255, 255);
  strip.setPixelColor(1, 255, 255, 255);
  strip.setPixelColor(2, 255, 255, 255);
  strip.setPixelColor(3, 255, 255, 255);
  strip.setPixelColor(4, 255, 255, 255);
  strip.show();
  delay(50);
  strip.setPixelColor(0, 0, 0, 0);
  strip.setPixelColor(1, 0, 0, 0);
  strip.setPixelColor(2, 0, 0, 0);
  strip.setPixelColor(3, 0, 0, 0);
  strip.setPixelColor(4, 0, 0, 0);
  strip.show();
  delay(50);
}
////
void strobe2() {

  for(y=0; y<=3; y++) {
  strip.setPixelColor((y+4)%5, 255, 255, 255);
  strip.setPixelColor((y+3)%5, 255, 255, 255);
  strip.setPixelColor((y+2)%5, 255, 255, 255);
  strip.setPixelColor((y+1)%5, 255, 255, 255);
  strip.setPixelColor(y%5, 0, 0, 0);
  strip.show();
  delay(50);
  off();
  delay(50);
  }

  for(y=4; y>=1; y--) {
  strip.setPixelColor((y+4)%5, 255, 255, 255);
  strip.setPixelColor((y+3)%5, 255, 255, 255);
  strip.setPixelColor((y+2)%5, 255, 255, 255);
  strip.setPixelColor((y+1)%5, 255, 255, 255);
  strip.setPixelColor(y%5, 0, 0, 0);
  strip.show();
  delay(50);
  off();
  delay(50);
  }
}


