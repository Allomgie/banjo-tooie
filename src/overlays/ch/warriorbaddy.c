#include "common.h"

extern int D_80800128_chwarriorbaddy;
typedef struct { u8 pad_0[0x78]; u32 pad_1 : 26; u32 local_0 : 1; u32 pad_2 : 5; } WarriorCoasterFlags;
extern s32 _sucoaster_entrypoint_0(Actor *, s32);
extern void func_80102FDC(Actor *, f32);
extern void func_8010A3E8(Actor *, f32);

int *chwarriorbaddy_entrypoint_0()
{
    return &D_80800128_chwarriorbaddy;
}

void func_8080000C_chwarriorbaddy(Actor *param_0)
{
    if (_sucoaster_entrypoint_0(param_0, 0)) {
        func_80102FDC(param_0, param_0->scale * 1.5f);
        func_8010A3E8(param_0, 0.4f);
        if (!((WarriorCoasterFlags *)param_0)->local_0) _sucoaster_entrypoint_10(param_0, 2);
    }
}
