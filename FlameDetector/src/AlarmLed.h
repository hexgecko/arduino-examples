#pragma once

#include <Arduino.h>
#include <Protothread.h>

#define ALARM_LED_PIN     13
#define ALARM_LED_DELAY  200

class AlarmLed: public Protothread {
public:
    void setup();
    void stop();
    bool resume();
};
