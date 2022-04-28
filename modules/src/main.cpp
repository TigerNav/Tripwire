#include <Arduino.h>
#include <SPI.h>

#define PORT 5000

const int trigPin = 9;
const int echopin = 10;
const int LED = 13;

long duration;
int disctance;

int calibrated_length = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(LED, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {

   // clears pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echopin, HIGH);
  // distance calculation
  disctance = (duration / 2) * 0.0343;
  
  switch (Serial.read())
  {
  // calibration case   Letter C
  case 99:
    calibrated_length = disctance;
    break;
    
  // exit case    Letter E
  case 101:
    calibrated_length = 0;
    break;

  case 114:
    calibrated_length = 0;
    break;
  }

  
  if(disctance + 1 < calibrated_length) {
    Serial.write("i");
    
    digitalWrite(LED, HIGH);
    delay(100);
    digitalWrite(LED, LOW);
    delay(100);
  } 

  

}