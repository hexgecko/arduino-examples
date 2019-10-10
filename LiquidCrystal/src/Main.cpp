#include <Arduino.h>
#include <Protothread.h>
#include <StartIndicator.h>

#include "DisplayCounter.h"

StartIndicator startIndicator(13);
DisplayCounter displayCounter;

void setup() {
  startIndicator.setup();
  displayCounter.setup();
}

void loop() {
  startIndicator.resume();
  displayCounter.resume();
}