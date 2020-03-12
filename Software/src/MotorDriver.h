/**
 * MotorDriver Class for TB6612FNG
 */

#ifndef MotorDriver_h
#define MotorDriver_h

#include "Arduino.h"
#include "Motor.h"

const int A_MOTOR = 0;
const int B_MOTOR = 1;

const int NUM_OF_MOTORS = 2;

class MotorDriver {
    public:
        MotorDriver(int standby, boolean enable);

        void enable();
        void disable();

        void initMotorA(int pwm, int in1, int in2);
        void initMotorB(int pwm, int in1, int in2);
        void initMotor(int motor, int pwm, int in1, int in2);
    private:
        int standby;
        Motor motors [NUM_OF_MOTORS];
};

#endif
