#include "StepMotor.h"

void StepMotor::setup() {
    pinMode(mPinA, OUTPUT);
    pinMode(mPinB, OUTPUT);
    pinMode(mPinC, OUTPUT);
    pinMode(mPinD, OUTPUT);
}

bool StepMotor::resume() {
    PT_BEGIN();
    
    for(;;) {
        if(mSetpoint > mPosition) {
            step((mPosition++) % 4);
            PT_SLEEP(mStepDelay);
        } else if(mSetpoint < mPosition) {
            step((mPosition--) % 4);
            PT_SLEEP(mStepDelay);
        } else {
            digitalWrite(mPinA, LOW);
            digitalWrite(mPinB, LOW);
            digitalWrite(mPinC, LOW);
            digitalWrite(mPinD, LOW);
            PT_SLEEP(mStepDelay);
        }
    }

    PT_END();
}

void StepMotor::step(byte nextStep) {
    switch(nextStep) {
        case 0:  // 1010
            digitalWrite(mPinA, HIGH);
            digitalWrite(mPinB, LOW);
            digitalWrite(mPinC, HIGH);
            digitalWrite(mPinD, LOW);
            break;

        case 1:  // 0110
            digitalWrite(mPinA, LOW);
            digitalWrite(mPinB, HIGH);
            digitalWrite(mPinC, HIGH);
            digitalWrite(mPinD, LOW);
            break;
    
        case 2:  //0101
            digitalWrite(mPinA, LOW);
            digitalWrite(mPinB, HIGH);
            digitalWrite(mPinC, LOW);
            digitalWrite(mPinD, HIGH);
            break;
    
        case 3:  //1001
            digitalWrite(mPinA, HIGH);
            digitalWrite(mPinB, LOW);
            digitalWrite(mPinC, LOW);
            digitalWrite(mPinD, HIGH);
            break;
    }
}
