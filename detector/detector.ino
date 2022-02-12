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

// Dimensions of the probe
// In mm
const int radius = 5;
const int heihgt = 5;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int cond; // Conductivity value
int rawRead; // Raw Readings
float voltage; // Voltage after calculation

int condCalc(int v){
  
  
}

double consCalc(int cond){

}

void updateLCD(int cond, double cons) {
 lcd.setCursor(0,0);
 lcd.print("Conductivity: ");
 lcd.print(cond);

 lcd.setCursor(0,1);
 lcd.print("Consentration: ");
 lcd.print(cons);
 lcd.print(" ppm");
  
}

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  rawRead = analogRead(A0);
  
  if (rawRead != 0) {digitalWrite(led, HIGH);}
  else {digitalWrite(led, LOW);}

  voltage = rawRead*(5.0/1023.0);

}
