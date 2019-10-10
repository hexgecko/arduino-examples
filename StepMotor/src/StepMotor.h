#pragma once

#include <Arduino.h>
#include <Protothread.h>

class StepMotor: public Protothread {
public:

    StepMotor(byte pinA, byte pinB, byte pinC, byte pinD):
        mPinA(pinA), mPinB(pinB), mPinC(pinC), mPinD(pinD),
        mPosition(32767), mSetpoint(32767), mStepDelay(2) { ; }
    
    void setup();
    bool resume();

    void setSetpoint(int setpoint) { mSetpoint = 32767 + setpoint; }

private:

    void step(byte nextStep);

    byte mPinA, mPinB, mPinC, mPinD;
    unsigned int mPosition, mSetpoint;
    byte mStepDelay;
};
