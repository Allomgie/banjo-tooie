#include "common.h"

extern void *D_80800380_chpumproomswitch;
extern int D_808003C8_chpumproomswitch;
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
