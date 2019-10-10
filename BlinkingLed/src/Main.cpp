#include <Arduino.h>
#include "FlashLed.h"
#include "PushButton.h"

FlashLed led(11);
PushButton pushButton(8, led);

void setup()
{
  led.setup();
  pushButton.setup();
}

void loop()
{
  pushButton.resume();
}
