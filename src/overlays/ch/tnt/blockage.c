#include "common.h"

extern int D_80800240_chtntblockage[];
extern f32 func_800D8FF8(void);
extern u8 D_80800288_chtntblockage[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 local_1;
extern u8 D_8080029C_chtntblockage[];
extern u8 marker[];
extern u8 ActorMarker[];
int func_80800184_chtntblockage();

void *chtntblockage_entrypoint_0()
{
    return &D_80800240_chtntblockage;
}

void func_8080000C_chtntblockage(Actor *param_0)
{
    if (param_0->unk70_10 == 2) {
        param_0->unk58 += func_800D8FF8();
        if (param_0->unk58 > 0.5f) {
            func_800C4AF0(param_0->position, D_80800288_chtntblockage, param_0);
            func_800FFAB0(param_0);
        }
    }
}

void func_80800088_chtntblockage()
{
    _subaddiefade_entrypoint_14();
}

s32 func_808000A8_chtntblockage(u8 *param_0)
{
  return ((u32)*(u16 *)(param_0 + 0x76) >> 7) + 0x4C;
}

s32 func_808000B8_chtntblockage(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
    case 5:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], -300.0f);
        local_0[1] -= 110.0f;
        _chexploder_entrypoint_3(param_0, local_0, 0);
        break;
    case 0x90:
        func_80800184_chtntblockage(param_0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(param_0, func_808000A8_chtntblockage(param_0));
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800184_chtntblockage(param_0) Actor *param_0;
{
    s32 local_0;
    u8 *local_1;
    local_0 = func_80106790(func_80101080());
    _chexploder_entrypoint_12(local_0, 0x32);
    _chexploder_entrypoint_6(local_0, 0x44960000, 0x44AF0000);
    _chexploder_entrypoint_13(local_0, 4);
    _chexploder_entrypoint_15(local_0, 1, 0x3F99999A);
    local_1 = &D_8080029C_chtntblockage;
    func_800BABB8(0, (u8*)param_0 + 4, local_0 + 0x18, *(s32*)((char*)param_0 + 0x38), local_1);
    func_800DA544(func_808000A8_chtntblockage(param_0));
    func_80101FDC(param_0, 2);
    func_80103110(param_0, 1);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/tnt/blockage.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800240_chtntblockage -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800240_chtntblockage[18] = { 0x1580145, 0x6920001, 0x0, (u32)func_8080000C_chtntblockage, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x804, 0x0, 0x0, 0x0, (u32)func_80800088_chtntblockage, (u32)func_80107C2C, -0x7FF7D3FE, (u32)func_808000B8_chtntblockage, 0x0 };
u8 D_80800288_chtntblockage[20] = { 0x0, 0x13, 0x4, 0x3F, 0x0, 0xA, 0x0, 0xE6, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xE2, 0x9, 0xC4, 0x0, 0x0 };
u8 D_8080029C_chtntblockage[116] = { 0x5, 0x10, 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2B, 0x8, 0x0, 0xA, 0x0, 0x0, 0x22, 0x1, 0x80, 0x2, 0x0, 0x4, 0x80, 0x6, 0x0, 0x0, 0x15, 0x0, 0x0, 0x0, 0x26, 0x0, 0x19, 0x0, 0x0, 0x0, 0x7, 0x0, 0x2D, 0x0, 0x32, 0x0, 0x4B, 0x0, 0x20, 0xDE, 0xA7, 0x71, 0xC0, 0x0, 0xA, 0xFF, 0x9C, 0x0, 0x19, 0xFF, 0x9C, 0x0, 0x64, 0x0, 0x4B, 0x0, 0x64, 0x5, 0x1A, 0xF, 0x10, 0x0, 0x16, 0x0, 0x2, 0x0, 0x1D, 0x6, 0x88, 0x0, 0x14, 0x0, 0x2D, 0x2, 0x58, 0x3, 0x20, 0x0, 0x1B, 0xFC, 0xE0, 0xFD, 0xA8, 0x0, 0x22, 0x3, 0x80, 0x6, 0x0, 0x2, 0x0, 0x3, 0x0, 0x0, 0x1E, 0x0, 0x64, 0x0, 0x64, 0x0, 0xD, 0x0, 0x64, 0xF, 0x1A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
