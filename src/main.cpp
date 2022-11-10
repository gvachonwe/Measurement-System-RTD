#include <Arduino.h>

// Define global variables
int Vo;
int ResistPin = 0;
float R1 = 10000;
float R2, T, Tc;

void setup() {
  // Start serial monitor + set speed
  Serial.begin(9600);
}

void loop() {
   // Read pin output
  Vo = analogRead(ResistPin);

  // Find resistance with voltage divider equation
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  
}