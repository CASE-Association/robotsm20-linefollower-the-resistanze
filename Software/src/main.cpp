#include <math.h>
#include <Arduino.h>
#include "MotorDriver.h"

//int STBY = -1;

int PWMA = 11;
int AIN1 = 2;
int AIN2 = 3;

int PWMB = 10;
int BIN1 = 4;
int BIN2 = 5;

int LEFT = A_MOTOR;
int RIGHT = B_MOTOR;
MotorDriver driver;

void setup() {
    // Motor
    driver = MotorDriver();
    driver.initMotorA(PWMA, AIN1, AIN2);
    driver.initMotorB(PWMB, BIN1, BIN2);
}

void loop() {
    int leftSpeed = 255 * sin( millis() * 2 * PI / 8000 );
    int rightSpeed = 255 * cos( millis() * 2 * PI / 8000 );

    driver.setSpeed(LEFT, leftSpeed);
    driver.setSpeed(RIGHT, rightSpeed);

    delay(100);
}
