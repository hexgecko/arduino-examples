#include <Arduino.h>
#include <Protothread.h>

#include "FourEightTube.h"

static const byte segmentPin[7] = { 1, 2, 3, 4, 5, 6, 7 };
static const byte selectPin[4] = { 9, 10, 11, 12 };

static const byte numberData[10] {
    0b01111110, // 0
    0b00110000, // 1
    0b01101101, // 2
    0b01111001, // 3
    0b00110011, // 4
    0b01011011, // 5
    0b00011111, // 6
    0b01110000, // 7
    0b01111111, // 8
    0b01110011  // 9
};

void FourEightTube::setup() {
    // Set the segemnt pin as ouputs.
    for(byte i=0; i<7; i++) {
        pinMode(segmentPin[i], OUTPUT);
    }

    // Set the select pin as output
    for(byte i=0; i<4; i++) {
        pinMode(selectPin[i], OUTPUT);
    }
}

bool FourEightTube::resume() {
    byte mask, segment;
    PT_BEGIN();

    for(;;) {
        mTemp = mOutput;
        if(mTemp < 0) { mTemp = -mOutput; }

        for(mI=0; mI<3; mI++) {
            digitalWrite(selectPin[mI], HIGH);

            mask = 0b01000000;
            segment = numberData[mTemp % 10];
            for(mJ=0; mJ<7; mJ++) {
                if(mTemp > 0 || (mI == 0 && mOutput == 0)) {
                    byte highOrLow = HIGH;
                    if((segment & (mask >> mJ)) > 0) highOrLow = LOW;

                    digitalWrite(segmentPin[mJ], highOrLow);
                } else {
                    digitalWrite(segmentPin[mJ], HIGH);
                }
            }

            mTemp /= 10;

            mTimer.start(1);
            PT_WAIT_UNTIL(mTimer.expire());

            for(mJ=0; mJ<7; mJ++) { digitalWrite(segmentPin[mJ], HIGH); }
            digitalWrite(selectPin[mI], LOW);
        }
        
        if(mOutput < 0) {
            if(mOutput < -99) mSelector = 3;
            else if(mOutput < -9) mSelector = 2;
            else mSelector = 1;

            digitalWrite(selectPin[mSelector], HIGH);
            digitalWrite(segmentPin[6], LOW);

            mTimer.start(1);
            PT_WAIT_UNTIL(mTimer.expire());
            
            digitalWrite(segmentPin[6], HIGH);
            digitalWrite(selectPin[mSelector], LOW);
        }
    }

    PT_END();
}

void FourEightTube::setOutput(int16_t output) {
    if(output > 999) {
        mOutput = 999;
    } else if(output < -999) {
        mOutput = -999;
    } else {
        mOutput = output;
    }
}
