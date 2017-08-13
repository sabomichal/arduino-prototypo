//
// Created by Michal Sabo on 10.6.2017.
//

#ifndef ARDUINOEXAMPLE_ALGORITHM_H
#define ARDUINOEXAMPLE_ALGORITHM_H

static const double DEGREE_TO_DELAY_CONSTANT = 4.45;

#include "MovingStrategy.h"
#include "CarBot.h"

class AutonomousStrategy : public MovingStrategy {
public:
    void move(CarBot&) override;

private:
    uint8_t getMaxDistancePosition(CarBot&) const;

    void turnToPosition(CarBot&, uint8_t);
};


#endif //ARDUINOEXAMPLE_ALGORITHM_H
