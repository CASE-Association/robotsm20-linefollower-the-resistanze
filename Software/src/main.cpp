#include <Arduino.h>
#include "Motor.h"

int frequency = 4;
int ledPin = LED_BUILTIN;

int PWMA = 11;
int AIN1 = 2;
int AIN2 = 3;
Motor motorA;

void setup() {
    //Serial.begin(9600);
    pinMode(ledPin, OUTPUT);

    // Motor
    motorA = Motor(PWMA, AIN1, AIN2);
}

void loop() {

    // Motor
    int numberOfSteps = 20;
    int stepTime = 100;

    for (int i = 0; i <= numberOfSteps; i++) {
        int speed = (double) i/numberOfSteps * 255;

        motorA.forward(speed);
        delay(stepTime);
    }


    for (int i = 0; i <= numberOfSteps; i++) {
        int speed = (double) (numberOfSteps - i)/numberOfSteps * 255;

        motorA.forward(speed);
        delay(stepTime);
    }

    delay(1000);
}
