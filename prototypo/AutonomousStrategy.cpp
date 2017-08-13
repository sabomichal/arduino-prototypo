//
// Created by miso on 10.6.2017.
//

#if ARDUINO >= 100

#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "AutonomousStrategy.h"

void AutonomousStrategy::move(CarBot& carBot) {
    // get max distance position
    auto position = getMaxDistancePosition(carBot);
    Serial.print("Max distance position: ");
    Serial.println(position);

    // turn to this position
    turnToPosition(carBot, position);
    // look forward
    carBot.writeServoPosition(carBot.getPositionMax() / 2, 255, false);

    // go forward
    carBot.goForward();
    delay(500);

    // until the distance is safe
    auto distance = 0;
    do {
        distance = carBot.readDistance();
        Serial.print("Distance in front: ");
        Serial.println(distance);
        delay(200);
    } while (distance > carBot.getSafeDistance());
    carBot.stop();
}

uint8_t AutonomousStrategy::getMaxDistancePosition(CarBot &carBot) const {
    auto maxDistancePosition = 0;
    // auto currentPosition = carBot.readServoPosition();
    auto maxDistance = 0;
    for (auto i = carBot.getPositionMin(); i <= carBot.getPositionMax(); i+=10) {
        carBot.writeServoPosition(i);
        auto distance = carBot.readDistance();
        Serial.print("Max distance candidate: ");
        Serial.println(distance);
        if (distance > maxDistance) {
            maxDistance = distance;
            maxDistancePosition = i;
        }
    }
    return (uint8_t) maxDistancePosition;
}

void AutonomousStrategy::turnToPosition(CarBot& carBot, uint8_t position) {
    if (position < (carBot.getPositionMax() / 2)) {
        auto actualDelay = (unsigned long) ((carBot.getPositionMax() / 2 - position) * DEGREE_TO_DELAY_CONSTANT);
        Serial.print("Turning right with delay: ");
        Serial.println(actualDelay);
        carBot.turnRight();
        delay(actualDelay);
    } else if (position > (carBot.getPositionMax() / 2)) {
        auto actualDelay = (unsigned long) ((position - carBot.getPositionMax() / 2) * DEGREE_TO_DELAY_CONSTANT);
        Serial.print("Turning left with delay: ");
        Serial.println(actualDelay);
        carBot.turnLeft();
        delay(actualDelay);
    } else {
        // do nothing
        Serial.print("Not turning");
    }
    carBot.stop();
}
