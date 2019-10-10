#include "BeatingHeart.h"


static const byte heartBitmap[2][8] = {
    {   0b00100100,
        0b01111110,
        0b11111111,
        0b11111111,
        0b01111110,
        0b01111110,
        0b00111100,
        0b00011000
    },
    {   0b00000000,
        0b00100100,
        0b01111110,
        0b01111110,
        0b00111100,
        0b00111100,
        0b00011000,
        0b00000000
    },
};

bool BeatingHeart::resume() {
    PT_BEGIN();

    for(;;) {
        for(mI=0; mI<2; mI++) {
            mDotMatrix.memCpy(heartBitmap[mI]);
            PT_SLEEP(300);
        }
    }

    PT_END();
}