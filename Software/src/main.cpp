#include <Arduino.h>

int frequency = 4;
int ledPin = LED_BUILTIN;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH);
    delay(500 / frequency);
    digitalWrite(ledPin, LOW);
    delay(500 / frequency);
}