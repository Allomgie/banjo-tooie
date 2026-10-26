#include "common.h"

extern u8 D_808000F0_chcrackarchwall[];
extern u8 D_80800130_chcrackarchwall[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef union { s32 local_0; s16 local_1[2]; } CrackWallEventValue;
extern int D_80800144_chcrackarchwall;

s32 func_80800000_chcrackarchwall(Actor *param_0, s32 param_1, CrackWallEventValue param_2)
{
    switch (param_1) {
        case 0x95:
            if (func_800DA298((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7)) func_800FFAB0(param_0);
            break;
        case 0x40:
            func_800DA544((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7);
            _chexploder_entrypoint_3(param_0, param_0->position, 12);
            break;
        case 0x90:
            func_800BABB8(0, param_0->position, param_0->position, param_0->scale, D_808000F0_chcrackarchwall);
            func_800C4AF0(param_0->position, D_80800130_chcrackarchwall);
            break;
        default: return 0;
    }
    return 1;
}

int chcrackarchwall_entrypoint_0()
{
  return (int)&D_80800144_chcrackarchwall;
}
