#include "common.h"

extern int D_808000E0_chcoderoomdoor[];
extern u8 D_80800128_chcoderoomdoor[];
extern u8 D_80800170_chcoderoomdoor[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);

int chcoderoomdoor_entrypoint_0()
{
    return (int) &D_808000E0_chcoderoomdoor;
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

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000E0_chcoderoomdoor[18] = {0x1990110,
                                     0x6510001,
                                     0x0,
                                     (u32) func_80102EC0,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x3660000,
                                     0x800,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFD800,
                                     (u32) func_8080000C_chcoderoomdoor,
                                     0x0};
u8 D_80800128_chcoderoomdoor[72] = {
    0x5,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x3,  0x0,  0x4,  0x0,  0x0,  0x22, 0x2,
    0x0,  0x2,  0x80, 0x6,  0x0,  0x8,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x99, 0x0,  0x19,
    0x0,  0x0,  0x0,  0x7,  0x0,  0x2C, 0xFF, 0xEC, 0x0,  0x14, 0xFF, 0xEC, 0x0,  0x14, 0x0,
    0x28, 0x0,  0x14, 0x0,  0x20, 0xB4, 0xB4, 0xB4, 0xA0, 0x0,  0xA,  0xFF, 0x38, 0x0,  0x19,
    0xFF, 0x38, 0x0,  0xC8, 0x0,  0x4B, 0x0,  0xC8, 0x5,  0x1A, 0x0,  0x0};
u8 D_80800170_chcoderoomdoor[16] = {0x0, 0x13, 0x4, 0xF4, 0x0, 0x18, 0x0, 0x0,
                                    0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
