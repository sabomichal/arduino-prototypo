#if ARDUINO >= 100

#include <Servo/src/Servo.h>
#include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include "blink_lib.h"

void blink_setup(uint8_t pin) {
  pinMode(pin, OUTPUT);
  Servo servo;
}


void blink(unsigned long duration, uint8_t pin) {
  digitalWrite(pin, HIGH);   // set the LED on
  delay(duration);           // wait for a second
  digitalWrite(pin, LOW);    // set the LED off
  delay(duration);           // wait for a second
}
