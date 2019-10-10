#include <Arduino.h>
#include <Protothread.h>
#include <LiquidCrystal.h>

#include "DisplayCounter.h"

void DisplayCounter::setup() {
    mLCD.begin(16,2);
    mLCD.print("Count:");
}

bool DisplayCounter::resume() {
    PT_BEGIN();

    for(;;) {
        mLCD.setCursor(7,0);
        mLCD.print(mCount++);
        PT_SLEEP(100);
    }

    PT_END();
}
