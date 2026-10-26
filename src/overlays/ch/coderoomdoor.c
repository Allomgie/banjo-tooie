#include "common.h"

extern int D_808000E0_chcoderoomdoor;
extern u8 D_80800128_chcoderoomdoor[];
extern u8 D_80800170_chcoderoomdoor[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);

int chcoderoomdoor_entrypoint_0()
{
    return (int)&D_808000E0_chcoderoomdoor;
}

s32 func_8080000C_chcoderoomdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 0x40:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], -100.0f);
        _chexploder_entrypoint_3(param_0, local_0, 0xF);
        break;
    case 0x90:
        func_800BABB8(0, param_0->position, param_0->position, 1.0f, D_80800128_chcoderoomdoor);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800170_chcoderoomdoor);
        func_800DA544(0x366);
        break;
    default:
        return 0;
    }
    return 1;
}
