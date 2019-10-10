#pragma once

#include <Arduino.h>
#include <Protothread.h>

#include "Timer.h"

class FourEightTube: public Protothread {
public:
    FourEightTube(): mOutput(0) { }
    void setup();
    bool resume();

    void setOutput(int16_t output);
    int16_t getOutput() { return mOutput; }

private:
    int16_t mOutput, mTemp;
    byte mI, mJ, mSelector;
    Timer mTimer;
};
