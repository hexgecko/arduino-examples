#pragma once

#include <Arduino.h>
#include <Protothread.h>

#include "AlarmLed.h"

#define RESET_BUTTON_PIN 2

class ResetButton: public Protothread {
public:
    ResetButton(AlarmLed &alarmLed): mAlarmLed(alarmLed) { }

    void setup();

    bool resume();

private:
    AlarmLed &mAlarmLed;
};
