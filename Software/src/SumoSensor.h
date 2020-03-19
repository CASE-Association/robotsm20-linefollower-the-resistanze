#ifndef SumoSensor_h
#define SumoSensor_h

#include <Arduino.h>

class SumoSensor{
    public:
        SumoSensor(int pinD1, int pinD2, int pinD3, int pinD4, int pinA);
        int getValue(int nr);
        long getWeightedAvg();

    private:
        int pinD1;
        int pinD2;
        int pinD3;
        int pinD4;
        int pinA;
        int weights[16] = {35, 30, 25, 20, 15, 10, 5, 0, 0, -5, -10, -15, -20, -25, -30, -35};
    
};


#endif