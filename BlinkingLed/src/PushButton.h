#pragma once

#include <Protothread.h>
#include "FlashLed.h"

class PushButton: public Protothread {
public:
    PushButton(byte pin, FlashLed &led): mPin(pin), mLed(led) { }

    void setup() {
        pinMode(mPin, INPUT);
    }

    bool resume() {
        PT_BEGIN();

        for(;;) {
            PT_WAIT_UNTIL(digitalRead(mPin));
            PT_SPAWN(mLed);

            PT_WAIT_WHILE(digitalRead(mPin));
            PT_SLEEP(10);
        }

        PT_END();
    }

private:
    byte mPin;
    FlashLed &mLed;
};