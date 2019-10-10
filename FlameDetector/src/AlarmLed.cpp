#include <Arduino.h>
#include <Protothread.h>

#include "AlarmLed.h"

void AlarmLed::setup() {
    pinMode(ALARM_LED_PIN, OUTPUT);

    // Alarm is not active by default
    stop();
}

void AlarmLed::stop() {
    digitalWrite(ALARM_LED_PIN, LOW);
    Protothread::stop();
}

bool AlarmLed::resume() {

    PT_BEGIN();

    // An never ending loop that just blink the alarm
    for(;;) {
        digitalWrite(ALARM_LED_PIN, HIGH);
        PT_SLEEP(ALARM_LED_DELAY);

        digitalWrite(ALARM_LED_PIN, LOW);
        PT_SLEEP(ALARM_LED_DELAY);
    }

    PT_END();
}

