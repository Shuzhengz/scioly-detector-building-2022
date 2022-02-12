// Libraries
#include<LiquidCrystal.h>

// Pin Constants
const int rs = 12;
const int en = 11;
const int d4 = 5;
const int d5 = 4;
const int d6 = 3;
const int d7 = 2;

const int led = 6;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int cond; // Conductivity value

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  
}
