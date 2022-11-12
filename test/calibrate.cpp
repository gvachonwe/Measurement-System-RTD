#include <Arduino.h>
#include <LiquidCrystal.h>

// Define global variables
int ThermPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tcel;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

// Initialize LCD
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

void setup() {
  // Start serial monitor + set speed
  //Serial.begin(9600);

  // Start LCD
  delay(1000);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
  // Read pin output
  Vo = analogRead(ThermPin);

  // Find resistance with voltage divider equation
  R2 = R1 * (1023.0 / (float)Vo - 1.0);

  // Find T (k) using Stein-Hart equation
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));

  // Covert to celcius degrees
  Tcel = T - 273.15;

  // Print to serial monitor
  //Serial.print("Temperature: "); 
  //Serial.print(Tcel);
  //Serial.println(" C");   

  // Output to LCD
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(Tcel);
  lcd.print(" C");

  delay(500);
}