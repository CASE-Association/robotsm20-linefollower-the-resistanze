#include <Arduino.h>

int frequency = 4;
int ledPin = LED_BUILTIN;

void setup() {
    pinMode(ledPin, OUTPUT);

    // Motor
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);

    // pinMode(11, ANALOG);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
}

void loop() {
    if (0) {
        digitalWrite(ledPin, HIGH);
        delay(500 / frequency);
        digitalWrite(ledPin, LOW);
        delay(500 / frequency);
    }

    // Motor
    int numberOfSteps = 20;
    int stepTime = 100;

    for (int i = 0; i <= numberOfSteps; i++) {
        analogWrite(11, (double) i/numberOfSteps * 255);
        delay(stepTime);
    }


    for (int i = 0; i <= numberOfSteps; i++) {
        analogWrite(11, (double) (numberOfSteps - i)/numberOfSteps * 255);
        delay(stepTime);
    }

    delay(1000);
}

