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

void Prototypo::lookAt(uint8_t position) {
    servo.write(position);
}

int Prototypo::readDistance() {
    return ultrasonic.distanceRead(CM);
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
    movingStrategy.move(*this);
}

Prototypo::Prototypo(Config &config) : ultrasonic{config.hcsr04Pinout.trigPin,
                                                        config.hcsr04Pinout.echoPin} {
    this->config = config;
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
