#include <Arduino.h>
#include <LiquidCrystal.h>

// Define global variables
int Vo;
float V = 0.0;

// Initialize LCD
LiquidCrystal lcd(0, 1, 8, 9, 10, 11);

void setup() {
  // Start serial monitor + set speed
  //Serial.begin(9600);

  // Start LCD
  delay(1000);
  lcd.begin(16, 2);
  lcd.clear();
  //lcd.print("hello, world!");
}

void loop() {
   // Read pin output
  Vo = analogRead(A0);

  // Convert analog signal to voltage
  V = Vo*(5.0/1023);

  // Convert voltage to temp

  // Print to serial monitor
  //Serial.print("Voltage: "); 
  //Serial.print(V);
  //Serial.println(" V");

  lcd.setCursor(0,1);
  lcd.print("Voltage: ");
  lcd.print(V);
  lcd.print(" V");

  delay(1000);
}