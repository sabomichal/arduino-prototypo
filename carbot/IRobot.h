//
// Created by Michal Sabo on 4.6.2017.
//
#ifndef ARDUINOEXAMPLE_IROBOT_H
#define ARDUINOEXAMPLE_IROBOT_H

#include <stdint.h>

struct IRobot {
    /**
     * Turn left
     */
    virtual void turnLeft()= 0;

    /**
     * Turn right
     */
    virtual void turnRight()= 0;

    /**
     * Move forward
     */
    virtual void goForward()= 0;

    /**
     * Move backward
     */
    virtual void goBackward()= 0;

    /**
     * Turn servo to the specified position <0,180>
     * @param position
     */
    virtual void lookAt(uint8_t position)= 0;

    /**
     * Read the distance
     * @return distance in centimeters
     */
    virtual int readDistance()= 0;
};

#endif //ARDUINOEXAMPLE_IROBOT_H
