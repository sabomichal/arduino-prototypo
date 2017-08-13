//
// Created by Michal Sabo on 4.6.2017.
//

#include "Prototypo.h"

Config robotConfig{{7, 8, 9, 10},
                   {4, 5},
                   {6}};
AutonomousStrategy autonomousStrategy;
Prototypo bot(robotConfig, autonomousStrategy);

void setup() {
    bot.setup();
    bot.writeServoPosition(0);
}

void loop() {
    bot.move();
}
