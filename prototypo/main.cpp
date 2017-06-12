//
// Created by Michal Sabo on 4.6.2017.
//

#include "Prototypo.h"

Config robotConfig{{7, 8, 9, 10},
                   {4, 5},
                   {6}};
Prototypo bot(robotConfig);

void setup() {
    bot.setup();
}

void loop() {
    bot.move();
}
