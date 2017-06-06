//
// Created by Michal Sabo on 4.6.2017.
//

#include <Arduino.h>
#include "CarBot.h"

void CarBot::turnLeft() {
    // motor A clockwise
    digitalWrite(robotConfig.l293Pinout.in1, HIGH);
    digitalWrite(robotConfig.l293Pinout.in2, LOW);
    // motor B
    digitalWrite(robotConfig.l293Pinout.in3, LOW);
    digitalWrite(robotConfig.l293Pinout.in4, HIGH);
}

void CarBot::turnRight() {
    // motor A counter clockwise
    digitalWrite(robotConfig.l293Pinout.in1, LOW);
    digitalWrite(robotConfig.l293Pinout.in2, HIGH);
    // motor B clockwise
    digitalWrite(robotConfig.l293Pinout.in3, HIGH);
    digitalWrite(robotConfig.l293Pinout.in4, LOW);
}

void CarBot::goForward() {
    // motor A clockwise
    digitalWrite(robotConfig.l293Pinout.in1, HIGH);
    digitalWrite(robotConfig.l293Pinout.in2, LOW);
    // motor B clockwise
    digitalWrite(robotConfig.l293Pinout.in3, HIGH);
    digitalWrite(robotConfig.l293Pinout.in4, LOW);
}

void CarBot::goBackward() {
    // motor A counter clockwise
    digitalWrite(robotConfig.l293Pinout.in1, LOW);
    digitalWrite(robotConfig.l293Pinout.in2, HIGH);
    // motor B counter clockwise
    digitalWrite(robotConfig.l293Pinout.in3, LOW);
    digitalWrite(robotConfig.l293Pinout.in4, HIGH);
}

void CarBot::lookAt(uint8_t position) {
    servo.write(position);
}

int CarBot::readDistance() {
    //return ultrasonic.distanceRead();
    return 0;
}

void CarBot::setup() {
    // ultrasonic - nothing to set up

    // servo
    servo.attach(robotConfig.sg90Pinout.pwm);
    // look forward
    servo.write(90);

    // motor
    pinMode(robotConfig.l293Pinout.in1, OUTPUT);
    pinMode(robotConfig.l293Pinout.in2, OUTPUT);
    pinMode(robotConfig.l293Pinout.in3, OUTPUT);
    pinMode(robotConfig.l293Pinout.in4, OUTPUT);
}

CarBot::CarBot(RobotConfig &robotConfig) : ultrasonic{robotConfig.hcsr04Pinout.trigPin,
                                                    robotConfig.hcsr04Pinout.echoPin} {
    this->robotConfig = robotConfig;
    setup();
}

CarBot::~CarBot() {
}
