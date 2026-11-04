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

s32 func_8080000C_chcoderoomdoor(Actor *actor, s32 msg, s32 data)
{
    f32 pos[3];

    switch (msg) {
        case 0x40:
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, actor->rotation[1], -100.0f);
            _chexploder_entrypoint_3(actor, pos, 0xF);
            break;
        case 0x90:
            func_800BABB8(0, actor->position, actor->position, 1.0f, D_80800128_chcoderoomdoor);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800170_chcoderoomdoor);
            func_800DA544(0x366);
            break;
        default:
            return 0;
    }
    return 1;
}

// TU-NOTE: the overlay .data is defined in this file. Its tables point to functions here, and
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
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
