#pragma once

#include <Arduino.h>
#include <Protothread.h>

#include "FourEightTube.h"
#include "Timer.h"

class EchoSensor: public Protothread {
public:
    EchoSensor(FourEightTube &fourEightTube): mFourEightTube(fourEightTube) { }
    void setup();
    bool resume();
private:
    FourEightTube &mFourEightTube;
    Timer mTimer;
};
