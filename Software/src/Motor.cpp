/**
 * Motor Class for Motor Driver TB6612FNG
 */

#include "Arduino.h"
#include "Motor.h"

const int FORWARD = 0;
const int BACKWARD = 1;

Motor::Motor(int pwm, int in1, int in2) {
    this->pwm = pwm;
    this->in1 = in1;
    this->in2 = in2;

    // Initiate pins
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
}

void Motor::drive(int direction, int speed) {
    setDirection(direction);
    setSpeed(speed);
}

void Motor::setDirection(int direction) {
    if (direction == FORWARD) {
        forward();
    }
    else if (direction == BACKWARD) {
        backward();
    }
    else {
        //throw NoSuchDirectionException();
    }
}

void Motor::forward(int speed) {
    forward();
    setSpeed(speed);
}

void Motor::forward() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
}

void Motor::backward(int speed) {
    backward();
    setSpeed(speed);
}

void Motor::backward() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
}

void Motor::shortBreak() {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
}

void Motor::stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
}
