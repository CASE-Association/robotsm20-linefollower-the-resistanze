#include <math.h>
#include <Arduino.h>
#include "MotorDriver.h"

//int STBY = -1;

int PWMA = 11;
int AIN1 = 2;
int AIN2 = 3;

/*
int PWMB = 0;
int BIN1 = 0;
int BIN2 = 0;
*/

int LEFT = A_MOTOR;
int RIGHT = B_MOTOR;
MotorDriver driver;

void setup() {
    Serial.begin(9600);

    // Motor
    driver = MotorDriver();
    driver.initMotorA(PWMA, AIN1, AIN2);
    //driver.initMotorB(PWMB, BIN1, BIN2);
}

void loop() {
    int speed = 255 * sin( millis() * 2 * PI / 8000 );
    driver.setSpeedA(speed);

    Serial.println(speed);
    delay(100);
}
