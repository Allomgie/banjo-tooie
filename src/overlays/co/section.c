// Constant getters for the fixed start maps: Spiral Mountain (0xAF) and the boot intro (0x18B).
#include "common.h"

// Start map for a new game: Spiral Mountain.
s32 cosection_entrypoint_0()
{
    return 0xAF;
}

// Start map of the boot intro cutscene.
s32 cosection_entrypoint_1()
{
    return 0x18B;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
