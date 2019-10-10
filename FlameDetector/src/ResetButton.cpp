#include <Arduino.h>
#include <Protothread.h>

#include "ResetButton.h"

void ResetButton::setup() {
    pinMode(RESET_BUTTON_PIN, INPUT);
}

bool ResetButton::resume() {
    PT_BEGIN();

    for(;;) {
        // Wait for the button to be pressed and the button bounce.
        PT_WAIT_UNTIL(digitalRead(RESET_BUTTON_PIN));
        PT_SLEEP(50);

        // Stop the alarm if the user have pressed the button
        if(mAlarmLed.isRunning()) {
            mAlarmLed.stop();
        }

        // Wait for the button to be released and the button bounce.
        PT_WAIT_WHILE(digitalRead(RESET_BUTTON_PIN));
        PT_SLEEP(50);
    }

    PT_END();
}
