#include "common.h"

extern void func_8010D5DC(void);
extern void func_800F4AC0(s32, f32 *, f32);
extern int D_80800558_chlagoonufoext;
extern u8 D_80800500_chlagoonufoext[];
extern u8 D_80800510_chlagoonufoext[];
extern u8 D_80800524_chlagoonufoext[];
extern u8 D_808005A0_chlagoonufoext[];
extern void func_800DF428(f32);
extern void func_801015D0(Actor *, void *);
void func_808002A4_chlagoonufoext();

int func_80800000_chlagoonufoext(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    switch (param_1) {
    case 0xB:
        if (param_2 == 0x32) {
            func_800DA544(0xB6);
            _susubgame_entrypoint_4(param_0, func_80100094(param_0, 0));
            if (_gclevel_entrypoint_3(0x17)) _glcutDll_entrypoint_6(0x128, 0x4A);
            return 4;
        }
        return 3;
    case 0x32:
        func_808002A4_chlagoonufoext(param_0);
        return 1;
    case 0x95:
        if (func_800DA298(0x9F0) && func_80090178(1) && func_800EA090() == 9) {
            local_0 = func_800F54E4();
            func_800F608C(local_0, 1);
            func_800F497C(local_0);
            func_800F49D4(local_0, func_8010D5DC, param_0->unk0);
            func_800F4AC0(local_0, (f32 *)((u8 *)param_0 + 0x28), 300.0f);
            _susubgame_entrypoint_6(param_0, func_80100094(param_0, 0), 0x42, 0x60, 0);
            func_80102424(param_0, 2);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800168_chlagoonufoext(u8 *param_0) {
    param_0[0x34] = _subaddieaudioloop_entrypoint_3(param_0[0x34]);
    if (_susubgame_entrypoint_2(param_0, func_80100094(param_0, 0)) != 0) {
        _susubgame_entrypoint_4(param_0, func_80100094(param_0, 0));
    }
}

int chlagoonufoext_entrypoint_0()
{
    return (int)&D_80800558_chlagoonufoext;
}

void func_808001D8_chlagoonufoext(u8 *param_0)
{
  s8 _sfpad[16];
  u8 *new_var;
  s32 local_0;
  s32 local_1;

  *(s32 *)(param_0 + 0x24) = func_800CBDD4(param_0 + 4, 0x64, 6);
  if (func_800DA298(0xB6) != 0) {
    local_1 = *(s32 *)(param_0 + 0x24);
    if (local_1 != -1) {
      func_800CBB80(local_1, 0);
    }
    func_800FFAB0(param_0);
  } else {
    ((Actor *)param_0)->unk6C_0 = _subaddiesect_entrypoint_1(param_0);
  }
  if (_subaddiemarker_entrypoint_0(param_0, 0x1C0, &local_0, 1) != 0) {
    func_800EE7F8(param_0 + 0x28, &local_0);
  }
  _susubgame_entrypoint_0(param_0, func_80100094(param_0, 0), 0);
}

void func_808002A4_chlagoonufoext(param_0) s32 *param_0; {
    func_80101FDC(param_0, 3);
    func_80101D4C(param_0);
    func_800D1000(0x28, 1, 0, 3, 0);
    _susubgame_entrypoint_6(param_0, func_80100094(param_0, 0), 0x32, 0x30, 0);
    _subaddiedialog_entrypoint_11(*param_0, 0x1047, 0x40, param_0 + 1, 0);
}

void func_8080032C_chlagoonufoext(u8 *param_0)
{
    s32 sp34;
    switch ((u32)(*(u16 *)(param_0 + 0x72)) >> 0xA) {
    case 1:
        if (_subaddiesect_entrypoint_0(param_0, *(s32 *)(param_0 + 0x6C) & 0x1FF, 4) == 0) {
            return;
        }
        return;
    case 3:
        sp34 = 0;
        if (func_80101E14(param_0, 0x3EFAE148) != 0) {
            param_0[0x73] &= 0xFFFE;
        }
        if (func_80102320(param_0, 0x3F07AE14, 0x3F333333) != 0) {
            sp34 = 1;
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0 + 0x18, 1, D_80800510_chlagoonufoext);
        }
        param_0[0x34] = _subaddieaudioloop_entrypoint_7(param_0[0x34], param_0 + 0x18, sp34, D_80800500_chlagoonufoext, *(s32 *)(param_0 + 0x70) & 1);
        _subaddieaudioquick_entrypoint_4(param_0, param_0 + 0x18, D_80800524_chlagoonufoext, D_808005A0_chlagoonufoext);
        if (func_800DA298(0xB6) != 0) {
            if (*(s32 *)(param_0 + 0x24) != -1) {
                func_800CBB80(*(s32 *)(param_0 + 0x24), 0);
            }
            func_800FFAB0(param_0);
        }
        break;
    }
}

void func_8080047C_chlagoonufoext(Actor *param_0, void *param_1)
{
    if (param_0->unk70_10 != 3) {
        func_800DF428(9000.0f);
    } else {
        func_800DF440(0);
    }
    func_80101808(param_0, func_801015D0);
    _subaddieskeleton_entrypoint_3(param_0->unk0, 4, param_0->actorData);
}
