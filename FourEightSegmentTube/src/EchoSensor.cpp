#include <Arduino.h>

#include "EchoSensor.h"

static const byte trigPin = A1;
static const byte echoPin = A0;

void EchoSensor::setup() {
    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT);
}

bool EchoSensor::resume() {
    float distance;

    PT_BEGIN();

    for(;;) {
        mTimer.start(100);

        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2); 
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        distance = pulseIn(echoPin, HIGH, 3000) / 5.8f;
        mFourEightTube.setOutput(distance);

        PT_WAIT_UNTIL(mTimer.expire());
    }

    PT_END();
}
