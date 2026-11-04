// Returns an anti-tamper value, used as data by other overlays and copied into game flags by gldb.
#include "common.h"

extern s32 D_8007DB54;

// Anti-tamper value; 0x01C003FE on a clean ROM (D_8007DB54 == 0xAD090010).
s32 glreflight_entrypoint_0(void)
{
    return D_8007DB54 ^ 0xACC903EE;
}

// TU-NOTE: .data is defined here in C; values are taken from the ROM.
