#include <Arduino.h>
#include <Protothread.h>

class CounterSegment: public Protothread {
public:
    CounterSegment(byte latchPin, byte clockPin, byte dataPin) :
        mLatchPin(latchPin), mClockPin(clockPin), mDataPin(dataPin) { }
    
    void setup();

    bool resume();

private:
    byte mLatchPin;
    byte mClockPin;
    byte mDataPin;
    byte mI;
};
