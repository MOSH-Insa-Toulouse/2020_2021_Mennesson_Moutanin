
#include "Morse.h"

Morse pinMorse(2);


void setup() {
  Serial.begin(9600);
}

void loop() {
  pinMorse.dot();pinMorse.dot();pinMorse.dot();
  pinMorse.dash();pinMorse.dash();pinMorse.dash();
  pinMorse.dot();pinMorse.dot();pinMorse.dot();
}
