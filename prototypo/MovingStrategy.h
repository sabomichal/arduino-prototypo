//
// Created by miso on 10.6.2017.
//

#ifndef ARDUINOEXAMPLE_IALGORITHM_H
#define ARDUINOEXAMPLE_IALGORITHM_H

#include "CarBot.h"

struct MovingStrategy {
    virtual void move(CarBot&)= 0;
};

#endif //ARDUINOEXAMPLE_IALGORITHM_H
