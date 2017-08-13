//
// Created by Michal Sabo on 4.6.2017.
//

#ifndef ARDUINOEXAMPLE_ROBOT_H
#define ARDUINOEXAMPLE_ROBOT_H

#include "CarBot.h"
#include "Ultrasonic.h"
#include "VarSpeedServo.h"
#include "MovingStrategy.h"
#include "AutonomousStrategy.h"

struct Config {
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

class Prototypo : public CarBot {
private:
    static const uint8_t POSITION_MIN = 0;
    static const uint8_t POSITION_MAX = 180;
    static const uint8_t SAFE_DISTANCE = 10;

    VarSpeedServo servo;
    Ultrasonic ultrasonic;
    Config config;
    MovingStrategy *movingStrategy;

public:
    Prototypo(Config&, MovingStrategy&);

    virtual ~Prototypo();

    void setup();

    void turnLeft() override;

    void turnRight() override;

    void goForward() override;

    void goBackward() override;

    void stop() override;

    void writeServoPosition(uint8_t) override;

    void writeServoPosition(uint8_t, uint8_t, bool) override;

    uint8_t readServoPosition() override;

    int readDistance() override;

    uint8_t getPositionMin() override;

    uint8_t getPositionMax() override;

    uint8_t getSafeDistance() override;

    void move();
};

#endif //ARDUINOEXAMPLE_ROBOT_H
