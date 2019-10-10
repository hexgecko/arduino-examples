#include <Arduino.h>

#include "FourEightTube.h"
#include "EchoSensor.h"

FourEightTube fourEightTube;
EchoSensor echoSensor(fourEightTube);

void setup() {
  fourEightTube.setup();
  echoSensor.setup();
}

void loop() {
  fourEightTube.resume();
  echoSensor.resume();
}