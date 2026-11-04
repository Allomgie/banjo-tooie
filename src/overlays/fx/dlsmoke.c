// Dust/smoke puff preset (shared emitter slot 8); used by player dust, Bill Drill, torpedo, fx/egg.
#include "common.h"

extern int D_80800050_fxdlsmoke[];

// Spawns one dust/smoke puff at pos from shared emitter slot 8.
s32 fxdlsmoke_entrypoint_0(s32 pos)
{
    return func_800BABB8(func_800B5BE4(8), pos, 0, 0x3F800000, &D_80800050_fxdlsmoke);
}

// TU-NOTE: .data of this overlay is defined here in C; values are taken from the ROM.
// D_80800050_fxdlsmoke is declared as int[] to match the object.
int D_80800050_fxdlsmoke[20] = {0x1D09DC,  0x2CFF6A,   0x64FF6A,  0x96012C, 0x96001B,
                                -0x630096, 0x150000,   0x660020,  -0x1B0,   0x220033,
                                0x660100,  0x166002B,  0x1330166, 0x180000, 0x130CAA,
                                0xCAA0016, 0x10000000, 0x0,       0x0,      0x0};
