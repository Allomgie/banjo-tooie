#include "common.h"
#ifndef M2C_MACROS_H
#endif

extern s32 *D_800411F4;

f32 func_80027170(s32 cents)
{
    f32 x;
    f32 ratio = 1.0f;

    if (cents >= 0) {
        x = 1.0005778f;
    } else {
        x = 0.99942255f;
        cents = -cents;
    }

    while (cents) {
        if (cents & 1)
            ratio *= x;
        x *= x;
        cents = cents >> 1;
    }

    return ratio;
}

void func_80027200(void)
{
    *D_800411F4 = 0;
}
