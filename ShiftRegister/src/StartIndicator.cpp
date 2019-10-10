#include <Arduino.h>
#include <Protothread.h>

#include "StartIndicator.h"

void StartIndicator::setup() {
    pinMode(mLedPin, OUTPUT);
}

bool StartIndicator::resume() {
    PT_BEGIN();

    for(mI=0; mI<3; mI++) {
        digitalWrite(mLedPin, HIGH);
        PT_SLEEP(300);

        digitalWrite(mLedPin, LOW);
        PT_SLEEP(300);
    }

    PT_END();
}
