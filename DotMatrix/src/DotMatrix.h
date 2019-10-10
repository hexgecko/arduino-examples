#pragma once

#include <Arduino.h>
#include <Protothread.h>

class DotMatrix: public Protothread {
public:
    // Constructor, clear the dot memroy
    DotMatrix() {
        for(byte i=0; i<8; i++) {
            mDotMemory[i] = 0;
        }
    }
    
    // Setup the pin, call this in the setup function.
    void setup();
    
    // Write the dot memory to the dot matrix.
    bool resume();

    // Set a dot to at the x,y coordinate.
    void setDot(byte x, byte y) { mDotMemory[y] |= 1 << x; }

    // Clear the dot at the x,y coordinate.
    void clearDot(byte x, byte y) { mDotMemory[y] &= 1 << x; }

    // Copy a 8 byte array to the dot memmory.
    void memCpy(const byte *src);
    
private:
    byte mReverseByteBitOrder(byte b);
    byte mDotMemory[8];
    byte mI, mJ;
};
