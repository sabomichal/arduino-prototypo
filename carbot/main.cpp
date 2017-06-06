//
// Created by Michal Sabo on 4.6.2017.
//

#if ARDUINO >= 100

#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "CarBot.h"

RobotConfig robotConfig{{7, 8, 9, 10},
                        {4, 5},
                        {6}};
CarBot robot(robotConfig);

void setup() {
    robot.setup();
}

void loop() {
    robot.goForward();
    delay(5000);
    robot.goBackward();
    delay(5000);
    robot.turnLeft();
    delay(5000);
    robot.turnRight();
    delay(5000);
}
