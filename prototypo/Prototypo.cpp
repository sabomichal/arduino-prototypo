//
// Created by Michal Sabo on 4.6.2017.
//

#include <Arduino.h>
#include "Prototypo.h"

void Prototypo::turnLeft() {
    // motor A clockwise
    digitalWrite(config.l293Pinout.in1, HIGH);
    digitalWrite(config.l293Pinout.in2, LOW);
    // motor B
    digitalWrite(config.l293Pinout.in3, LOW);
    digitalWrite(config.l293Pinout.in4, HIGH);
}

void Prototypo::turnRight() {
    // motor A counter clockwise
    digitalWrite(config.l293Pinout.in1, LOW);
    digitalWrite(config.l293Pinout.in2, HIGH);
    // motor B clockwise
    digitalWrite(config.l293Pinout.in3, HIGH);
    digitalWrite(config.l293Pinout.in4, LOW);
}

void Prototypo::goForward() {
    // motor A counter clockwise
    digitalWrite(config.l293Pinout.in1, LOW);
    digitalWrite(config.l293Pinout.in2, HIGH);
    // motor B counter clockwise
    digitalWrite(config.l293Pinout.in3, LOW);
    digitalWrite(config.l293Pinout.in4, HIGH);
}

void Prototypo::goBackward() {
    // motor A clockwise
    digitalWrite(config.l293Pinout.in1, HIGH);
    digitalWrite(config.l293Pinout.in2, LOW);
    // motor B clockwise
    digitalWrite(config.l293Pinout.in3, HIGH);
    digitalWrite(config.l293Pinout.in4, LOW);
}

void Prototypo::stop() {
    // motor A stop
    digitalWrite(config.l293Pinout.in1, LOW);
    digitalWrite(config.l293Pinout.in2, LOW);
    // motor B stop
    digitalWrite(config.l293Pinout.in3, LOW);
    digitalWrite(config.l293Pinout.in4, LOW);
}

void Prototypo::writeServoPosition(uint8_t position) {
    // move to position degrees, use a speed of 30, wait until move is complete
    servo.write(position, 30, true);
}

void Prototypo::writeServoPosition(uint8_t position, uint8_t speed, bool wait) {
    // move to position degrees, use a speed of 30, wait until move is complete
    servo.write(position, speed, wait);
}

uint8_t Prototypo::readServoPosition() {
    return (uint8_t) servo.read();
}

int Prototypo::readDistance() {
    auto d1 = ultrasonic.distanceRead(CM);
    auto d2 = ultrasonic.distanceRead(CM);
    return (d1 + d2) / 2;
}

void Prototypo::setup() {
    // ultrasonic - nothing to set up

    // servo
    servo.attach(config.sg90Pinout.pwm);

    // motor
    pinMode(config.l293Pinout.in1, OUTPUT);
    pinMode(config.l293Pinout.in2, OUTPUT);
    pinMode(config.l293Pinout.in3, OUTPUT);
    pinMode(config.l293Pinout.in4, OUTPUT);
}

void Prototypo::move() {
    movingStrategy->move(*this);
}

Prototypo::Prototypo(Config &config, MovingStrategy &movingStrategy) : ultrasonic{config.hcsr04Pinout.trigPin,
                                                  config.hcsr04Pinout.echoPin} {
    this->config = config;
    this->movingStrategy = &movingStrategy;
}

Prototypo::~Prototypo() {
    servo.detach();
}

uint8_t Prototypo::getPositionMin() {
    return POSITION_MIN;
}

uint8_t Prototypo::getPositionMax() {
    return POSITION_MAX;
}

uint8_t Prototypo::getSafeDistance() {
    return SAFE_DISTANCE;
}
