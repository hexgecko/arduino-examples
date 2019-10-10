#include <Arduino.h>

#include "StepMotor.h"
#include "PushButton.h"

StepMotor stepMotor(8,9,10,11);
PushButton forwardButton(stepMotor, 200, 7);
PushButton backwardButton(stepMotor, -200, 6);

void setup() {
  stepMotor.setup();
  forwardButton.setup();
  backwardButton.setup();
}

void loop() {
  stepMotor.resume();
  backwardButton.resume();
  forwardButton.resume();
}
