#include <TimerOne.h>

const int tempPin = A0; //LM35 pin 
const int ledPin = 13;  //LED pin

int blinkInterval = 250000;

void setup() {
  pinMode(ledPin, OUTPUT);
  Timer1.initialize(blinkInterval);
  Timer1.attachInterrupt(blinkLED);
}

void loop() {

}

void blinkLED() {
  float temperature = analogRead(tempPin) * 0.48828125;

  if (temperature < 30) {
    blinkInterval = 250000; //below 30 C
  } else {
    blinkInterval = 500000; //above 30 C
  }

  Timer1.setPeriod(blinkInterval);
  digitalWrite(ledPin, !digitalRead(ledPin)); 
}