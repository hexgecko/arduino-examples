#include <Arduino.h>

#include "Timer.h"

static byte nextIndex = 0;
static unsigned long counter[5];

Timer::Timer() {
    if(nextIndex == 0) {
        noInterrupts();
        TIMSK2 = (TIMSK2 & B11111110) | 0x01;
        TCCR2B = (TCCR2B & B11111000) | 0b00000100;
        interrupts();
    }

    mIndex = nextIndex;
    counter[mIndex] = 0;
    nextIndex++;
}

void Timer::start(uint16_t delayMs) {
    //counter[mIndex] = millis() + delayMs;
    counter[mIndex] = delayMs;
}

bool Timer::expire() {
    // return millis() >= counter[mIndex];
    return (counter[mIndex] == 0);
}

ISR(TIMER2_OVF_vect){
   for(byte i=0; i<nextIndex; i++) {
       if(counter[i] > 0) counter[i]--;
   }
}
