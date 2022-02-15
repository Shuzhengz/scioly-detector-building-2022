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

// Change this to the actual specific resistivity
// based on the concentration during comp
const float p = 0.60;

// Set up LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Dimensions of the probe
// In mm
const int radius = 5;
const int heihgt = 5;

float resistance; // Resistance calculated
int rawRead; // Raw Readings
float voltage; // Voltage after calculation
double resOffset; // The error we have to offset
double cond; // Conductivity
double cons; // Consentration

// Calculates Resistance based on delta Voltage
float resistanceCalc(float v){
  // V = 5 R / (R + 10000)
  // R = 10000 V / (5 - v)
  return -(10000 * v)/(5-v);
}

// Calculates concentration (ppm, which is m/L)
float concentrationCalc(float conductivity){
  return 4.6 * cond * 1000; // g/dm^3 -> mg/L
}

// Updates the LCD
void updateLCD(float res, float cons) {
 lcd.setCursor(0,0);
 lcd.print("Res:");
 lcd.print(res);
 lcd.print(" ohmn");

 lcd.setCursor(0,1);
 lcd.print("Cons: ");
 lcd.print( "ppm");
  
}

// Set up pin mode
void setup() {
  pinMode(led, OUTPUT);
  
}

// Loop code
void loop() {
  // Read from A0 analog port
  rawRead = analogRead(A0);

  // Turns on LED if has a reading
  if (rawRead != 0) {digitalWrite(led, HIGH);}
  else {digitalWrite(led, LOW);}

  // Caculate voltage read
  voltage = rawRead*(5.0/1023.0); // Converts from raw into actual
  resistance = resistanceCalc(voltage);

  // Calculates conductivity (S/m)
  cond = 1/resistance;

  // calculates concentration (ppm, which is m/L)
  cons = concentrationCalc(cond);

  // Prints out the stuff
  updateLCD(resistance, cons);

  // Wait for 1 second so the screen doesn't freak out
  delay(1000);
}
