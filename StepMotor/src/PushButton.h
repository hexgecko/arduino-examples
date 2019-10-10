#pragma once

#include <Arduino.h>
#include <Protothread.h>

#include "StepMotor.h"

class PushButton: public Protothread {
public:
    PushButton(StepMotor &stepMotor, int setpoint, byte pin):
        mStepMotor(stepMotor), mSetpoint(setpoint), mPin(pin) { ; }
    
    void setup();
    bool resume();

private:
    StepMotor &mStepMotor;
    const int mSetpoint;
    byte mPin;
};
 