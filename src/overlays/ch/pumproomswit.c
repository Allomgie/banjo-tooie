#include "common.h"

extern void *D_80800380_chpumproomswitch;
extern int D_808003C8_chpumproomswitch[];
extern void func_801032B0(Actor *, u16, u16);
extern void func_80103110(Actor *, s32);
extern void _chswitch_entrypoint_10(Actor *, s32, s32);
extern s16 D_80800410_chpumproomswitch[];
extern s16 D_80800424_chpumproomswitch[];
extern s32 func_800C4350();
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800C31DC(u8, f32);
int func_8080016C_chpumproomswitch();

int chpumproomswitch_entrypoint_0()
{
  return (int)&D_80800380_chpumproomswitch;
}

int chpumproomswitch_entrypoint_1()
{
  return (int)&D_808003C8_chpumproomswitch;
}

int func_80800018_chpumproomswitch(s32 param_0)
{
  if (func_800DA298(0xB2))
  {
    func_800DA544(func_8080016C_chpumproomswitch(param_0));
  }
  _chswitch_entrypoint_7(param_0, func_8080016C_chpumproomswitch(param_0));
  _chswitch_entrypoint_8(param_0, ((u32)(*(u16 *)((char *)(param_0) + 0x76)) >> 7) == 0x32 ? 0x400 : 0x200);
  if (func_800DA298(0xB2))
  {
    _chswitch_entrypoint_9(param_0);
    func_80103110(param_0, 0);
  }
}

void func_808000BC_chpumproomswitch(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        func_801032B0(param_0, param_0->unk74_7 == 0x32 ? 0x7B9 : 0x7B8, param_0->unk0->unk16);
        if (func_800DA298(0xB2)) func_80103110(param_0, 0);
        break;
    case 7:
        func_80101180(0x3D2, 10, 0);
        break;
    }
    _chswitch_entrypoint_10(param_0, param_1, param_2);
}

func_8080016C_chpumproomswitch(param_0){
    return (((u32)((u16)(*(u16 *)((char *)(param_0) + 0x76))) >> 7) == 0x32) ? 0x9E6 : 0x9E7;
}

int func_80800194_chpumproomswitch(Actor *param_0)
{
  param_0->unk58 = 0.0f;
  if (func_800DA298(0xB2) != 0 || _glcutDll_entrypoint_19(0x20) != 0) {
    func_80101FDC(param_0, 2);
  }
}

void func_808001E4_chpumproomswitch(Actor *param_0)
{
    s16 *local_0;
    if (param_0->unk70_10 == 2) {
        if (!param_0->unk5F) {
            if (func_800EA05C() == 0xE3) local_0 = D_80800410_chpumproomswitch;
            else local_0 = D_80800424_chpumproomswitch;
            param_0->unk5F = func_800C4350(0, param_0->position, local_0);
        }
        func_800D9078(&param_0->unk58);
        func_800C31DC(param_0->unk5F, func_800F12D4(param_0->unk58, 0.0f, 3.5f, 1.0f, 0.3f));
        func_800C4350(param_0->unk5F, 0, 0);
    }
}

s32 func_808002A0_chpumproomswitch(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 10:
        if (param_0->unk70_10 == 1 && func_800DA298(0x9E6) && func_800DA298(0x9E7)) {
            param_0->unk58 = 3.5f;
            func_80101FDC(param_0, 2);
            _capod_entrypoint_13(param_0->unk0, 0, 0, 0x10);
        }
        break;
    case 11:
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0xE1, 0x20);
        return 4;
    default:
        return 0;
    }
    return 1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/pumproomswit.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808003C8_chpumproomswitch -> int[] */
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_8010A730();
void *D_80800380_chpumproomswitch = (void *)0x0343034B;
static u32 D_80800380_chpumproomswitch_rest[17] = { 0x7B80001, 0x8011A220, (u32)_chswitch_entrypoint_6, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0x4000080C, 0x0, 0x0, 0x0, (u32)func_80800018_chpumproomswitch, (u32)func_80107C2C, 0x80082C12, (u32)func_808000BC_chpumproomswitch, 0x0 };
int D_808003C8_chpumproomswitch[18] = { 0x33003D2, 0x1, 0x0, (u32)func_808001E4_chpumproomswitch, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, (u32)func_80800194_chpumproomswitch, (u32)func_80107C2C, -0x7FFFF9FE, (u32)func_808002A0_chpumproomswitch, 0x0 };
s16 D_80800410_chpumproomswitch[10] = { 0x206, 0x13, 0x4B4, 0x16, 0x2EE0, 0x1, 0x1F4, 0xDAC, 0x0, 0x0 };
s16 D_80800424_chpumproomswitch[14] = { 0x206, 0x13, 0x4B4, 0x16, 0x1F40, 0x1, 0x320, 0x1194, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
