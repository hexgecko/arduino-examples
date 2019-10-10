#include <Arduino.h>

#include "StartIndicator.h"
#include "CounterSegment.h"

StartIndicator startIndicator(13);
CounterSegment counterSegment(4, 5, 2);

void setup() {
  startIndicator.setup();
  counterSegment.setup();
}

void loop() {
  startIndicator.resume();
  counterSegment.resume();
}
