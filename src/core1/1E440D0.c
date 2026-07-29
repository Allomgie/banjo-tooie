#include "common.h"

typedef struct { u8 pad0[0x16]; s16 unk16; } TTHdl;

void func_8002C5A0(TTHdl *param_0, s16 param_1)
{
    param_0->unk16 = param_1;
}
