/**
 * Motor Class for Motor Driver TB6612FNG
 */

#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
    public:
        Motor(int pwm, int in1, int in2);

        void setSpeed(int speed);
        void setDirection(int direction);
        void drive(int direction, int speed);

        void forward();
        void forward(int speed);

        void backward();
        void backward(int speed);

        void shortBreak();
        void stop();
    private:
        int pwm;
        int in1;
        int in2;
};

#endif
