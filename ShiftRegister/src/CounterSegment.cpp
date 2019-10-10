#include <Arduino.h>
#include <Protothread.h>

#include "CounterSegment.h"

static byte segmentNumberData[10] {
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

void CounterSegment::setup() {
    pinMode(mLatchPin, OUTPUT);
    pinMode(mClockPin, OUTPUT);
    pinMode(mDataPin, OUTPUT);
}

bool CounterSegment::resume() {
    PT_BEGIN();

    for(;;) {
        for(mI=0; mI<10; mI++) {
            // Shift out the number to the 74HC595
            digitalWrite(mLatchPin,LOW); 
            shiftOut(mDataPin, mClockPin, LSBFIRST, segmentNumberData[mI]);
            digitalWrite(mLatchPin, HIGH); 
            PT_SLEEP(500);

            // Shift out the number to the 74HC595 plus a dot
            digitalWrite(mLatchPin,LOW); 
            shiftOut(mDataPin, mClockPin, LSBFIRST, segmentNumberData[mI] | 0b10000000);
            digitalWrite(mLatchPin, HIGH); 
            PT_SLEEP(500);
        }
    }

    PT_END();
}