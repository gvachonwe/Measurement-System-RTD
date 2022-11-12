#include <Arduino.h>

// Define global variables
int Vo;
float V = 0.0;
int ResistPin = 0;
float R1 = 10000;
float R2, T, Tc;

void setup() {
  // Start serial monitor + set speed
  Serial.begin(9600);
}

void loop() {
   // Read pin output
  Vo = analogRead(A0);

  // Convert analog signal to voltage
  V = Vo*(5.0/1023);

  // Print to serial monitor
  Serial.print("Voltage: "); 
  Serial.print(V);
  Serial.println(" V");

  delay(1000);
}