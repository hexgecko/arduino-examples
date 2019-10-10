#pragma once

#include <Arduino.h>
#include <Protothread.h>

#include "AlarmLed.h"

#define FLAME_DETECTOR_PIN A0

class FlameDetector: public Protothread {
public:
    FlameDetector(AlarmLed &alarmLed): mAlarmLed(alarmLed) { }
    bool resume();

private:
    AlarmLed &mAlarmLed;
};
