#include "SumoSensor.h"

SumoSensor::SumoSensor(int pinD1, int pinD2, int pinD3, int pinD4, int pinA) {
    this->pinD1 = pinD1;
    this->pinD2 = pinD2;
    this->pinD3 = pinD3;
    this->pinD4 = pinD4;
    this->pinA = pinA;
    
    pinMode(pinD1, OUTPUT);
    pinMode(pinD2, OUTPUT);
    pinMode(pinD3, OUTPUT);
    pinMode(pinD4, OUTPUT);

}


int SumoSensor::getValue(int nr) {
    digitalWrite(this->pinD1, (nr & 1) > 0 ? HIGH : LOW);
    digitalWrite(this->pinD2, (nr & 2) > 0 ? HIGH : LOW);
    digitalWrite(this->pinD3, (nr & 4) > 0 ? HIGH : LOW);
    digitalWrite(this->pinD4, (nr & 8) > 0 ? HIGH : LOW);
    delay(1);

    return analogRead(this->pinA);
}


long SumoSensor::getWeightedAvg() {
    long val = 0;

    for(int i = 0; i < 16; i++) {
        int vall = getValue(i);
        val += vall * weights[i];
    }

    return val;
}
