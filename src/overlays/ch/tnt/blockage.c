#include "common.h"

extern int D_80800240_chtntblockage[];
extern f32 func_800D8FF8(void);
extern u8 D_80800288_chtntblockage[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_8080029C_chtntblockage[];
int func_80800184_chtntblockage();

void *chtntblockage_entrypoint_0()
{
    return &D_80800240_chtntblockage;
}

void func_8080000C_chtntblockage(Actor *actor)
{
    if (actor->unk70_10 == 2) {
        actor->unk58 += func_800D8FF8();
        if (actor->unk58 > 0.5f) {
            func_800C4AF0(actor->position, D_80800288_chtntblockage, actor);
            func_800FFAB0(actor);
        }
    }
}

void func_80800088_chtntblockage()
{
    _subaddiefade_entrypoint_14();
}

// Game flag for this variant (0x7E for the Canary Cave entrance).
s32 func_808000A8_chtntblockage(u8 *actor)
{
    return ((u32) *(u16 *) (actor + 0x76) >> 7) + 0x4C;
}

// Message 5: the detonator fired.
s32 func_808000B8_chtntblockage(Actor *actor, s32 msg, s32 param_2)
{
    f32 pos[3];

    switch (msg) {
        case 5:
            // Explode 300 units behind and 110 lower
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, actor->rotation[1], -300.0f);
            pos[1] -= 110.0f;
            _chexploder_entrypoint_3(actor, pos, 0);
            break;
        case 0x90:
            func_80800184_chtntblockage(actor);
            break;
        // 0x95 (on load): link to the nearest detonator
        case 0x95:
            _chtntdetonator_entrypoint_1(actor, func_808000A8_chtntblockage(actor));
            break;
        default:
            return 0;
    }
    return 1;
}

// Message 0x90: debris, set the flag and disappear.
int func_80800184_chtntblockage(actor)
Actor *actor;
{
    s32 exploder;
    u8 *debris_data;
    exploder = func_80106790(func_80101080());
    _chexploder_entrypoint_12(exploder, 0x32);
    _chexploder_entrypoint_6(exploder, 0x44960000, 0x44AF0000);
    _chexploder_entrypoint_13(exploder, 4);
    _chexploder_entrypoint_15(exploder, 1, 0x3F99999A);
    debris_data = &D_8080029C_chtntblockage;
    func_800BABB8(0, (u8 *) actor + 4, exploder + 0x18, *(s32 *) ((char *) actor + 0x38),
                  debris_data);
    func_800DA544(func_808000A8_chtntblockage(actor));
    func_80101FDC(actor, 2);
    func_80103110(actor, 1);
}

// TU-NOTE: the overlay .data is defined here in C because its tables point to functions of this file;
// IDO schedules some of them differently otherwise. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800240_chtntblockage[18] = {0x1580145,
                                    0x6920001,
                                    0x0,
                                    (u32) func_8080000C_chtntblockage,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x804,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800088_chtntblockage,
                                    (u32) func_80107C2C,
                                    -0x7FF7D3FE,
                                    (u32) func_808000B8_chtntblockage,
                                    0x0};
u8 D_80800288_chtntblockage[20] = {0x0,  0x13, 0x4, 0x3F, 0x0, 0xA,  0x0, 0xE6, 0x0, 0x16,
                                   0x6D, 0x60, 0x0, 0x1,  0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0};
u8 D_8080029C_chtntblockage[116] = {
    0x5,  0x10, 0x0,  0x1D, 0x9,  0xDD, 0x0,  0x2B, 0x8,  0x0,  0xA,  0x0,  0x0,  0x22, 0x1,
    0x80, 0x2,  0x0,  0x4,  0x80, 0x6,  0x0,  0x0,  0x15, 0x0,  0x0,  0x0,  0x26, 0x0,  0x19,
    0x0,  0x0,  0x0,  0x7,  0x0,  0x2D, 0x0,  0x32, 0x0,  0x4B, 0x0,  0x20, 0xDE, 0xA7, 0x71,
    0xC0, 0x0,  0xA,  0xFF, 0x9C, 0x0,  0x19, 0xFF, 0x9C, 0x0,  0x64, 0x0,  0x4B, 0x0,  0x64,
    0x5,  0x1A, 0xF,  0x10, 0x0,  0x16, 0x0,  0x2,  0x0,  0x1D, 0x6,  0x88, 0x0,  0x14, 0x0,
    0x2D, 0x2,  0x58, 0x3,  0x20, 0x0,  0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0,  0x22, 0x3,  0x80,
    0x6,  0x0,  0x2,  0x0,  0x3,  0x0,  0x0,  0x1E, 0x0,  0x64, 0x0,  0x64, 0x0,  0xD,  0x0,
    0x64, 0xF,  0x1A, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
