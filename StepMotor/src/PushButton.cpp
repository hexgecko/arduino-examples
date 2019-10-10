#include "PushButton.h"

void PushButton::setup() {
    pinMode(mPin, INPUT);
}

bool PushButton::resume() {
    PT_BEGIN();

    for(;;) {
        // Wait for the button to be pressed and the button bounce.
        PT_WAIT_UNTIL(!digitalRead(mPin));
        PT_SLEEP(20);

        // Update the setpoint for the step motor
        mStepMotor.setSetpoint(mSetpoint);

        // Wait for the button to be released and the button bounce.
        PT_WAIT_WHILE(!digitalRead(mPin));
        PT_SLEEP(20);
    }

    PT_END();
}
