/**
 * Motor Class for Motor Driver TB6612FNG
 */

#include <Arduino.h>
#include "MotorDriver.h"

MotorDriver::MotorDriver(int standby, boolean enable) {
    this->standby = standby;

    if (standby != -1) pinMode(standby, OUTPUT);
    if (enable) this->enable();
}

void MotorDriver::enable() {
    //if (standby == -1) throw NoStandbyPinInitiated();
    digitalWrite(standby, HIGH);
}

void MotorDriver::disable() {
    //if (standby == -1) throw NoStandbyPinInitiated();
    digitalWrite(standby, LOW);
}

void MotorDriver::initMotorA(int pwm, int in1, int in2) { initMotor(A_MOTOR, pwm, in1, in2); }
void MotorDriver::initMotorB(int pwm, int in1, int in2) { initMotor(B_MOTOR, pwm, in1, in2); }

void MotorDriver::initMotor(int motor, int pwm, int in1, int in2) {
    //if (motor < 0 || motor >= NUM_OF_MOTORS) throw NoSuchMotorException();
    motors[motor] = Motor(pwm, in1, in2);
}



void MotorDriver::setSpeedA(int speed) { setSpeed(A_MOTOR, speed); }
void MotorDriver::setSpeedB(int speed) { setSpeed(B_MOTOR, speed); }

void MotorDriver::setSpeed(int motor, int speed) {
    //if (motor < 0 || motor >= NUM_OF_MOTORS) throw NoSuchMotorException();
    motors[motor].setSpeed(speed);
}
