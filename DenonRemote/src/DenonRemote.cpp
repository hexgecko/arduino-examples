#include <Arduino.h>
#include <IRRemote.h>

#include "DenonRemote.h"

void DenonRemote::setup() {
    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    mIRRecv.enableIRIn();
}

bool DenonRemote::resume() {
    PT_BEGIN();

    for(;;) {
        if(mIRRecv.decode(&mDecodeResult)) {
            if(mDecodeResult.value == mLastDecodeValue) {
                if((millis() - mLastRecvTimestamp) > 300) {
                    handleRecv();
                }

            } else {
                handleRecv();
                mLastDecodeValue = mDecodeResult.value;
            }

            mLastRecvTimestamp = millis();
            mIRRecv.resume();
        }
        PT_SLEEP(100);
    }

    PT_END();
}

void DenonRemote::handleRecv() {
    switch(mDecodeResult.value) {
        case 0xFEDBC2BE:
            mRedPinOn = !mRedPinOn;
            digitalWrite(redPin, mRedPinOn);
            break;
        
        case 0x5EAA77B4:
            mGreenPinOn = !mGreenPinOn;
            digitalWrite(greenPin, mGreenPinOn);
            break;
    }
}
