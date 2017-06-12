//
// Created by Michal Sabo on 10.6.2017.
//

#ifndef ARDUINOEXAMPLE_ALGORITHM_H
#define ARDUINOEXAMPLE_ALGORITHM_H

#include "MovingStrategy.h"
#include "CarBot.h"

class AutonomousStrategy : public MovingStrategy {
public:
    void move(CarBot& carBot) override;

private:
    unsigned long positionToDelay(int position) const;
};


#endif //ARDUINOEXAMPLE_ALGORITHM_H
