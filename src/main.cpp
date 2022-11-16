#include <Arduino.h>
#include <LiquidCrystal.h>

// Define global variables
int Vo;
float V = 0.0;
float T = 0.0;

// Initialize LCD
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

void setup() {
  // Start LCD
  delay(1000);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop() {
   // Read pin output
  Vo = analogRead(A0);

  // Convert analog signal to voltage
  V = Vo*(5.0/1023);

  // Convert voltage to temp
  //T = (131.5*V) - 333.78;
  T = (109.63*V) - 300.27;

  lcd.setCursor(0,0);
  lcd.print("Voltage: ");
  lcd.print(V);
  lcd.print(" V");

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.print(T);
  lcd.print(" C");

  delay(500);

  lcd.clear();
}