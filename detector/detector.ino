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

// Set up LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Dimensions of the probe
// In mm
const int radius = 5;
const int heihgt = 5;

int resistance; // Resistance calculated
int rawRead; // Raw Readings
float voltage; // Voltage after calculation

float resistanceCalc(float v){
  // V = 5 R / (R + 10000)
  // R = 10000 V / (5 - v)
  return -(10000 * v)/(5-v);
}

// Updates the LCD
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

  // Turns on LED if has a reading
  if (rawRead != 0) {digitalWrite(led, HIGH);}
  else {digitalWrite(led, LOW);}

  // Caculate voltage read
  voltage = rawRead*(5.0/1023.0);
  resistance = resistanceCalc(voltage);

  // Prints out the stuff
  updateLCD(voltage, resistance);

  // Wait for 1 second so the screen doesn't freak out
  delay(1000);
}
