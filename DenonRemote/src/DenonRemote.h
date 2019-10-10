#pragma once

#include <Protothread.h>
#include <IRremote.h>

class DenonRemote: public Protothread {
public:
    static const byte recvPin;
    static const byte redPin;
    static const byte greenPin;

    DenonRemote():
        mRedPinOn(false),
        mGreenPinOn(false),
        mIRRecv(recvPin),
        mLastDecodeValue(false),
        mLastRecvTimestamp(false) {}

    void setup();
    bool resume();

private:
    void handleRecv();

    bool mRedPinOn;
    bool mGreenPinOn;

    IRrecv mIRRecv;
    decode_results mDecodeResult;
    unsigned long mLastDecodeValue;
    unsigned long mLastRecvTimestamp;
};
