/**
 * Motor Class for Motor Driver TB6612FNG
 */

#include <Arduino.h>
#include "Motor.h"

Motor::Motor() {}
Motor::Motor(int pwm, int in1, int in2) {
    this->pwm = pwm;
    this->in1 = in1;
    this->in2 = in2;

    // Initiate pins
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
}

void Motor::setSpeed(int speed) {
    (speed > 0) ? forward(speed) : backward(-speed);
}

void Motor::forward(int speed) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(pwm, speed);
}

void Motor::backward(int speed) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(pwm, speed);
}

void Motor::shortBreak() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
}

void Motor::stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}
