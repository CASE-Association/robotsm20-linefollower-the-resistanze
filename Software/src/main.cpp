#include <math.h>
#include <Arduino.h>
#include "MotorDriver.h"
#include "SumoSensor.h"

SumoSensor sensor = SumoSensor(8, 9, 10, 11, A0);

void setup() {
    Serial.begin(115200);
    

}

void loop() {
    Serial.println(sensor.getWeightedAvg());
    
    delay(50);
}
