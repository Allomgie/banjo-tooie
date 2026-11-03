#include "ch/ghostdoor.h"

extern int D_80800220_chghostdoor[];
extern int D_80800268_chghostdoor[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);

int *chghostdoor_entrypoint_0()
{
    return &D_80800220_chghostdoor;
}

int chghostdoor_entrypoint_1()
{
  return (int)&D_80800268_chghostdoor;
}

void func_80800018_chghostdoor(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    local_0 = param_0->rotation[1];
    local_1 = 0;
    if (((u32)*(u16 *)((u8 *)param_0 + 0x76) >> 7) == 50) {
        local_1 = 1;
        local_0 += 180.0f;
    }
    func_800EFD24(param_0->position);
    func_80103014(param_0);
    if (_chdoormake_entrypoint_3(param_0, local_0, 0.0f, 650.0f, 0x20, 0x96)) {
        _chdoormake_entrypoint_5(param_0, 3.5f);
        _chdoormake_entrypoint_6(param_0, 2.0f);
        if (local_1) _chdoormake_entrypoint_8(param_0, 15);
    }
    if (func_800DA298(0x96)) func_800FFAB0(param_0);
}

s32 func_808000F4_chghostdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x95:
        local_0 = param_0->unk74_7 == 0x32 ? 0x782 : 0x783;
        func_80103140(param_0, local_0, *(u16 *)((u8 *)param_0->unk0 + 0x16));
        break;
    case 0x9D:
        func_800FFAB0(param_0);
        return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

void func_80800190_chghostdoor(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_096_STATION_UNLOCKED_WW);
    _chswitch_entrypoint_9(arg0);
}

s32 func_808001BC_chghostdoor(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 7:
        _capod_entrypoint_13(param_0->unk0, NULL, 5, 0x10);
        func_80101180(0x344, 7, 0);
        break;
    default:
        return _chswitch_entrypoint_10(param_0, param_1, param_2);
    }
    return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/ghostdoor.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800220_chghostdoor -> int[], D_80800268_chghostdoor -> int[] */
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
int D_80800220_chghostdoor[18] = { 0xAC0344, -0xFFFF, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_80800018_chghostdoor, (u32)func_80107C2C, -0x7FF7D3FE, (u32)func_808000F4_chghostdoor, 0x0 };
int D_80800268_chghostdoor[18] = { 0x3430348, 0x86D0001, (u32)&D_8011A248, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x4000080C, 0x0, 0x0, 0x0, (u32)func_80800190_chghostdoor, (u32)func_80107C2C, -0x7FF7D3EE, (u32)func_808001BC_chghostdoor, 0x0 };
