#include "common.h"
#ifndef M2C_MACROS_H
#endif

extern s32 *D_800411F4;

// alCents2Ratio: pitch ratio from cents via exponentiation by squaring.
f32 func_80027170(s32 cents)
{
    f32 base;
    f32 ratio = 1.0f;

    if (cents >= 0) {
        base = 1.0005778f; // 2^(1/1200)
    } else {
        base = 0.99942255f; // 2^(-1/1200)
        cents = -cents;
    }

    while (cents) {
        if (cents & 1)
            ratio *= base;
        base *= base;
        cents = cents >> 1;
    }

    return ratio;
}

// n_alSynDelete: clears the synth client list.
void func_80027200(void)
{
    *D_800411F4 = 0;
}
