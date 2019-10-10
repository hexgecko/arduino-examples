#pragma once

#include <Arduino.h>
#include <Protothread.h>

#include "DotMatrix.h"

class BeatingHeart: public Protothread {
public:
    BeatingHeart(DotMatrix &dotMatrix): mDotMatrix(dotMatrix) { }

    bool resume();

private:
    DotMatrix &mDotMatrix;
    byte mI;
};
