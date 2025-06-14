#include "core.h"
#include <Arduino.h>


led::led(int rPin, int gPin, int bPin) {
  redPin = rPin;
  greenPin = gPin;
  bluePin = bPin;

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void led::setColor(struct rgbColor color) {
  analogWrite(redPin, color.r);
  analogWrite(greenPin, color.g);
  analogWrite(bluePin, color.b);
}
