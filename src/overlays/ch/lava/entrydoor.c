#include "ch/lavaentrydoor.h"

extern s32 D_80800150_chlavaentrydoor[];
extern s32 D_80800190_chlavaentrydoor[];
extern u32 D_808001A4_chlavaentrydoor[];

s32 func_80800000_chlavaentrydoor(Actor* arg0, s32 arg1, s32 arg2)
{
    Actor* temp_v0;

    switch (arg1)
    {
    case 0x7:
        _chexploder_entrypoint_3(arg0, arg0->position, 8U);
        break;
    case 0x90:
        temp_v0 = func_80106790(func_80101080());
        _chexploder_entrypoint_13(temp_v0, 6U);
        _chexploder_entrypoint_15(temp_v0, 2U, 1.0f);
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800150_chlavaentrydoor);
        func_800C4AF0(arg0->position, &D_80800190_chlavaentrydoor);
        func_800DA544(FLAG_398_PROGRESS_OPENED_WORLD_HFP);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_808000CC_chlavaentrydoor(Actor* arg0)
{
    if (_sujiggy_entrypoint_20(6U) != 0)
    {
        func_800DA544(FLAG_398_PROGRESS_OPENED_WORLD_HFP);
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800D3E40(0xBU) != 0) && (_glcutDll_entrypoint_19(0x80U) == 0))
    {
        func_800FFAB0(arg0);
    }
}

void* chlavaentrydoor_entrypoint_0(void) {
    return &D_808001A4_chlavaentrydoor;
}
/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lava/entrydoor.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800150_chlavaentrydoor -> s32[], D_80800190_chlavaentrydoor -> s32[], D_808001A4_chlavaentrydoor -> u32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800150_chlavaentrydoor[16] = { 0x610001D, 0x9DD002B, 0x2000300, 0x220180, 0x2000480, 0x6000015, 0x26, 0x190000, 0x7002D, 0x320064, 0x20DEA7, 0x71C0000A, -0x63FFE7, -0x63FF9C, 0x4B0064, 0x61A0000 };
s32 D_80800190_chlavaentrydoor[5] = { 0x130413, 0xA00E6, 0x166D60, 0x11964, 0x19640000 };
u32 D_808001A4_chlavaentrydoor[19] = { 0xAC0394, 0x96F0001, 0x0, 0x0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x3980000, 0x20C00, 0x0, 0x0, 0x0, (u32)func_808000CC_chlavaentrydoor, (u32)func_80107C2C, 0x80002802, (u32)func_80800000_chlavaentrydoor, 0x0, 0x0 };
