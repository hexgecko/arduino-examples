#pragma once

#include <Arduino.h>

class Timer {
public:
    Timer();
    void start(uint16_t delayMs);
    bool expire();
private:
    byte mIndex;
};
