/**
 * Motor Class for Motor Driver TB6612FNG
 */

#ifndef Motor_h
#define Motor_h

#include <Arduino.h>

const int FORWARD = 0;
const int BACKWARD = 1;

class Motor {
    public:
        Motor(); // Solely to allow the initiation of arrays
        Motor(int pwm, int in1, int in2);

        void setSpeed(int speed);

        void forward(int speed);
        void backward(int speed);

        void shortBreak();
        void stop();
    private:
        int pwm;
        int in1;
        int in2;
};

#endif
