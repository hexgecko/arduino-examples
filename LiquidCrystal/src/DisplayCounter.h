#include <Arduino.h>
#include <Protothread.h>
#include <LiquidCrystal.h>

class DisplayCounter: public Protothread {
public:
    DisplayCounter(): mLCD(12, 11, 5, 4, 3, 2), mCount(0) { }

    void setup();

    bool resume();

private:
    LiquidCrystal mLCD;
    unsigned long mCount;
};
