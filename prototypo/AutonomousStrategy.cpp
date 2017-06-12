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
    //carBot.lookAt(90);
    //delay(1000);

    /*auto position = 0;
    auto maxDistance = 0;
    for (uint8_t i = carBot.getPositionMin(); i < carBot.getPositionMax(); i++) {
        carBot.lookAt(i);
        delay(10);
        auto distance = carBot.readDistance();
        if (distance > maxDistance) {
            maxDistance = distance;
            position = i;
        }
    }*/

    /*if (position < 90) {
        carBot.turnLeft();
        delay(positionToDelay(90 - position));
    } else if (position > 90) {
        carBot.turnRight();
        delay(positionToDelay(position - 90));
    } else {
        carBot.goForward();
    }
    delay(1000);*/
    //carBot.goForward();
    /*auto distance = carBot.readDistance();
    Serial.println(distance);
    if (distance < 10) {
        carBot.turnLeft();
        delay(1000);
    //    Serial.print("Distance: ");
        Serial.println("turn left");
    //    Serial.println("cm");
    } else {
        carBot.goForward();
        Serial.println("go forward");
    }*/

    auto distance = carBot.readDistance();
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println("cm");
    delay(10);
}

unsigned long AutonomousStrategy::positionToDelay(int position) const { return (unsigned long) (position * 100); }
