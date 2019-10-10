#include <Arduino.h>
#include "DotMatrix.h"
#include "BeatingHeart.h"

DotMatrix dotMatrix;
BeatingHeart beatingHeart(dotMatrix);

void setup() {
  dotMatrix.setup();
}

void loop() {
  dotMatrix.resume();
  beatingHeart.resume();
}
