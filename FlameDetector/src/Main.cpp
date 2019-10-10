// ----------------------------------------------------------------------------
// Flame Detector
//
// If the Flame Sensor detects a flame a Led start to blink.
// The user can reset the dector by pressing a button
// ----------------------------------------------------------------------------

#include <Arduino.h>

#include "AlarmLed.h"
#include "ResetButton.h"
#include "FlameDetector.h"

AlarmLed alarmLed;
ResetButton resetButton(alarmLed);
FlameDetector flameDetector(alarmLed);

void setup() {
  alarmLed.setup();
  resetButton.setup();
}

void loop() {
  alarmLed.resume();
  resetButton.resume();
  flameDetector.resume();
}
