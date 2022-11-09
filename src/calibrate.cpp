#include <Arduino.h>

// Define global variables
int ThermPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tcel;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
  // Start serial monitor + set speed
  Serial.begin(9600);
}

void loop() {
  // Read pin output
  Vo = analogRead(ThermPin);

  // Find resistance with voltage divider equation
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);

  // Find T (k) using Stein-Hart equation
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));

  // Covert to celcius degrees
  Tcel = T - 273.15;

  // Print to serial monitor
  Serial.print("Temperature: "); 
  Serial.print(Tcel);
  Serial.println(" C");   

  delay(500);
}