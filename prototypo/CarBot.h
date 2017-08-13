//
// Created by Michal Sabo on 4.6.2017.
//
#ifndef ARDUINOEXAMPLE_IROBOT_H
#define ARDUINOEXAMPLE_IROBOT_H

#include <stdint.h>

struct CarBot {
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
     * Stop moving
     */
    virtual void stop()= 0;

    /**
     * Turn servo to the specified position <getPositionMin(),getPositionMax>
     * @param position
     */
    virtual void writeServoPosition(uint8_t)= 0;

    virtual void writeServoPosition(uint8_t position, uint8_t speed, bool wait)= 0;

    /**
     * Get servo position
     */
    virtual uint8_t readServoPosition()= 0;

    virtual uint8_t getPositionMin()= 0;

    virtual uint8_t getPositionMax()= 0;

    virtual uint8_t getSafeDistance()= 0;

    /**
     * Read the distance
     * @return distance in centimeters
     */
    virtual int readDistance()= 0;
};

#endif //ARDUINOEXAMPLE_IROBOT_H
