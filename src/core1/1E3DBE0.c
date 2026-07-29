#include "common.h"

typedef struct { u8 pad0[8]; f32 unk8; } TTInner;
typedef struct { u8 pad0[0x18]; TTInner *unk18; u8 pad1C[8]; s32 unk24; } TTOuter;

s32 func_800260B0(TTOuter *param_0)
{
    if (!param_0->unk18)
        return 0;
    return (s32)((f32)param_0->unk24 / param_0->unk18->unk8);
}
