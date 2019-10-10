#pragma once

#include <Protothread.h>

class FlashLed: public Protothread {
public:
    FlashLed(byte pin): mPin(pin) { }

    void setup() {
        pinMode(mPin, OUTPUT);
    }

    bool resume() {
        PT_BEGIN();

        for(mI=0; mI<3; mI++) {
            digitalWrite(mPin, HIGH);
            PT_SLEEP(300);

            digitalWrite(mPin, LOW);
            PT_SLEEP(300);
        }

        PT_END();
    }

private:
    byte mPin;
    int mI;
};