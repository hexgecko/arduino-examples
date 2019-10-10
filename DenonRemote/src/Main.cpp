#include <Arduino.h>

#include "DenonRemote.h"

const byte DenonRemote::redPin = 2;
const byte DenonRemote::greenPin = 3;
const byte DenonRemote::recvPin = 11;

DenonRemote denonRemote;

void setup() {
  denonRemote.setup();
}

void loop() {
  denonRemote.resume();
}