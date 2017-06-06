//
// Created by Michal Sabo on 4.6.2017.
//

#ifndef ARDUINOEXAMPLE_ROBOT_H
#define ARDUINOEXAMPLE_ROBOT_H

#include "IRobot.h"
#include "Ultrasonic.h"
#include "Servo.h"

struct RobotConfig {
public:
    struct L293Pinout {
        uint8_t in1;
        uint8_t in2;
        uint8_t in3;
        uint8_t in4;
    } l293Pinout;

    struct HCSR04Pinout {
        uint8_t trigPin;
        uint8_t echoPin;
    } hcsr04Pinout;

    struct SG90Pinout {
        uint8_t pwm;
    } sg90Pinout;
};

class CarBot : IRobot {

private:
    Servo servo;
    Ultrasonic ultrasonic;
    RobotConfig robotConfig;

public:
    CarBot(RobotConfig &robotConfig);

    virtual ~CarBot();

    void setup();

    void turnLeft() override;

    void turnRight() override;

    void goForward() override;

    void goBackward() override;

    void lookAt(uint8_t position) override;

    int readDistance() override;
};

#endif //ARDUINOEXAMPLE_ROBOT_H
