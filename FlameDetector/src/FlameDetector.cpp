#include <Arduino.h>
#include <Protothread.h>

#include "FlameDetector.h"

bool FlameDetector::resume() {

    PT_BEGIN();

    for(;;) {
        if(analogRead(FLAME_DETECTOR_PIN) > 500) {
            if(!mAlarmLed.isRunning()) {
                mAlarmLed.restart();
            }
        }

        PT_SLEEP(100);
    }

    PT_END();

}
