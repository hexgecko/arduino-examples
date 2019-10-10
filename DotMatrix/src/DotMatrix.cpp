:q
#include <Arduino.h>

#include "DotMatrix.h"

static const byte colPin[8] = {6,7,8,9,10,11,12,13};
static const byte rowPin[8] = {2,3,4,5,17,16,15,14};

void DotMatrix::setup() {
    for(byte i=0; i<8; i++) {
        pinMode(colPin[i], OUTPUT);
        pinMode(rowPin[i], OUTPUT);
    }

    for(byte i=0; i<8; i++) {
        digitalWrite(colPin[i], HIGH);
        digitalWrite(rowPin[i], LOW);
    }
}

bool DotMatrix::resume() {
    PT_BEGIN();

    for(;;) {
        for(mI=0; mI<8; mI++) {
            // Write the bits for the row
            digitalWrite(rowPin[mI], HIGH);
            for(mJ=0; mJ<8; mJ++) {
                byte highOrLow = HIGH;
                if(mDotMemory[mI] & (1<<mJ)) {
                    highOrLow = LOW;
                }
                digitalWrite(colPin[mJ], highOrLow);
            }
            for(mJ=0; mJ<100; mJ++) { PT_YIELD(); }

            // Clear all bits for the row
            for(mJ=0; mJ<8; mJ++) {
                digitalWrite(colPin[mJ], HIGH);
            }
            digitalWrite(rowPin[mI], LOW);
        }
    }

    PT_END();
}

void DotMatrix::memCpy(const byte *src) {
    for(byte i=0; i<8; i++) {
        mDotMemory[i] = mReverseByteBitOrder(src[i]);
    }
}

byte DotMatrix::mReverseByteBitOrder(byte b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}
