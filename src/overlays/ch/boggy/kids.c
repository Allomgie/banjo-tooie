// Shared helper for Boggy's three lost kids: randomly picks one of three hiding spots per kid
// on first call, then tells a kid actor whether it is the instance at the chosen spot.
#include "common.h"

extern u16 D_808000E0_chboggykids[];

// Returns 1 if this actor is the instance placed at the randomly chosen hiding spot of its kid.
// First call picks a spot (1..3) for each kid.
s32 chboggykids_entrypoint_0(Actor *actor)
{
    s32 spot;
    s32 kid;

    if (!func_800DA564(0x59D, 2)) {
        func_800DA7A8(0x59D, func_800DC128(0, 3) + 1, 2);
        func_800DA7A8(0x59F, func_800DC128(0, 3) + 1, 2);
        func_800DA7A8(0x5A1, func_800DC128(0, 3) + 1, 2);
    }
    spot = actor->unk74_7 - 0x32;
    kid = (actor->unk0->unk24 >> 22) - 0x192;
    if (func_800DA564(D_808000E0_chboggykids[kid], 2) != spot + 1)
        return 0;
    return 1;
}

u16 D_808000E0_chboggykids[8] = {0x59D, 0x59F, 0x5A1, 0x0, 0x0, 0x0, 0x0, 0x0};
