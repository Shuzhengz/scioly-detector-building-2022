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

int resistance; // Resistance calculated
int rawRead; // Raw Readings
float voltage; // Voltage after calculation

float resistanceCalc(float v){
  // V = 5 R / (R + 10000)
  // R = 10000 V / (5 - v)
  return -(10000 * v)/(5-v);
}

void updateLCD(float v, float ohmn) {
 lcd.setCursor(0,0);
 lcd.print("Vol:");
 lcd.print(v);
 lcd.print(" V");

 lcd.setCursor(0,1);
 lcd.print("Res: ");
 lcd.print(ohmn);
  
}

void setup() {
  pinMode(led, OUTPUT);
  
}

void loop() {
  rawRead = analogRead(A0);
  
  if (rawRead != 0) {digitalWrite(led, HIGH);}
  else {digitalWrite(led, LOW);}

  voltage = rawRead*(5.0/1023.0);
  resistance = resistanceCalc(voltage);
  
  updateLCD(voltage, resistance);
  delay(1000);
}
