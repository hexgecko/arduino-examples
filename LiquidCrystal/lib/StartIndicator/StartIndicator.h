#include <Arduino.h>
#include <Protothread.h>

class StartIndicator: public Protothread {
public:
    StartIndicator(byte ledPin): mLedPin(ledPin) { }

    void setup();

    bool resume();

private:
    byte mLedPin;
    byte mI;
};
