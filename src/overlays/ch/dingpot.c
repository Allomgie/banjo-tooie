#include "common.h"

extern int D_80800500_chdingpot;
extern void func_80102FDC(u8 *, f32);
extern int func_80101DDC(void *param_0);
extern void func_80102424(void *param_0, int param_1);
extern int func_80101E14(void *param_0, int param_1);
extern void func_800C3F48(int param_0);
extern void func_800EE7F8(void *param_0, void *param_1);
extern void func_800EF1B8(void *param_0, void *param_1, int param_2);
extern void func_800F4CC0(int param_0);
extern int func_800F54E4(void);
extern void func_800F82D4(int param_0, int param_1);
extern void func_800F7844(int param_0, void *param_1, int param_2, int param_3);
extern void func_800D175C(int param_0, int param_1);
extern void _subaddieDll_entrypoint_4(void *param_0, int param_1);
extern s32 D_80800548_chdingpot[4];
extern s32 D_80800568_chdingpot[4];
extern u8 D_808005A4_chdingpot[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
typedef union { s16 local_0[2]; s32 local_1; } DingpotNotes1559;
extern DingpotNotes1559 D_808005B4_chdingpot;
extern s32 D_808005B8_chdingpot;
extern int func_80101E4C(Actor *, f32 *);
extern int _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
extern int func_800DC128(s32, s32);
extern void func_800C301C(s32, s32);
extern void func_800C4350(s32, f32 *, void *);
extern void func_800C3BDC(s32);
extern s32 D_808005C8_chdingpot;
extern s32 D_808004B0_chdingpot;
extern int D_808005D8_chdingpot;
extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800C9C04(f32, s32, s32);
void func_808002B4_chdingpot();
int func_80800350_chdingpot();
void func_80800388_chdingpot();

int chdingpot_entrypoint_0()
{
  return (int)&D_80800500_chdingpot;
}

void func_8080000C_chdingpot(u8 *param_0) {
    func_80102FDC(param_0, *(f32 *)(param_0 + 0x38) * 0.5f);
}

void func_80800040_chdingpot(void *param_0)
{
  s8 _sfpad[8];
  int new_var;
  switch ((u32)(((u16 *) param_0)[0x39]) >> 10)
  {
    case 1:
      func_808002B4_chdingpot(param_0, &D_80800548_chdingpot);
      if (func_80800350_chdingpot(param_0) == 0)
      {
        func_80800388_chdingpot(param_0);
        return;
      }
      return;

    case 2:
      func_808002B4_chdingpot(param_0, &D_80800548_chdingpot);
      break;

    case 3:
      func_808002B4_chdingpot(param_0, &D_80800568_chdingpot);
      if (func_80101DDC(param_0) != 0)
      {
        func_80102424(param_0, 4);
        return;
      }
      break;

    case 4:
      if (func_80101E14(param_0, 0x3F189375))
      {
        func_800C3F48(0x6CBF441E);
      }
      if (func_80101E14(param_0, 0x3F2147AE))
      {
        func_800EE7F8(&new_var, (void *)((char *)param_0 + 4));
        func_800EF1B8(&new_var, *(s32 *)((char *)param_0 + 0x48), 0x43C80000);
        func_800F4CC0(func_800F54E4());
        func_800F82D4(func_800F54E4(), 0);
        func_800F7844(func_800F54E4(), &new_var, 0x44CA8000, 0xC5802000);
        func_800D175C(0x40, 0x270F);
        func_800D175C(0x41, 0x270F);
        func_800D175C(0x42, 0x270F);
        func_800D175C(0x43, 0x270F);
        func_800D175C(0x44, 0x270F);
        func_800D175C(0x46, 0x270F);
        func_800D175C(0x47, 0x270F);
      }
      if (func_80101DDC(param_0) != 0)
      {
        func_80102424(param_0, 1);
        _subaddieDll_entrypoint_4(param_0, 0);
      }
      break;
  }
}

s32 func_8080021C_chdingpot(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x2E:
        func_80102424(param_0, 1);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808005A4_chdingpot, param_0->scale);
        break;
    case 0xB:
        func_800F7F98(func_800F54E4(), 0);
        return 3;
    default:
        return 0;
    }
    return 1;
}

void func_808002B4_chdingpot(param_0, param_1) Actor *param_0; f32 *param_1;
{
    DingpotNotes1559 local_0;

    local_0 = D_808005B4_chdingpot;
    if (func_80101E4C(param_0, param_1)) {
        if (!param_0->unk5F) param_0->unk5F = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
        func_800C301C(param_0->unk5F, local_0.local_0[func_800DC128(0, 2)]);
        func_800C4350(param_0->unk5F, param_0->position, &D_808005B8_chdingpot);
        func_800C3BDC(param_0->unk5F);
    }
}

int func_80800350_chdingpot(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = 5;
  _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_808005C8_chdingpot, &D_808004B0_chdingpot, local_0);
}

void func_80800388_chdingpot(param_0) s32 *param_0;
{
    s32 local_0;
    f32 local_1[3];
    f32 *local_2;

    if (&param_0) {}
    if (func_800DA298(0x1AC)) {
        local_0 = _plsu_entrypoint_3(param_0[0]);
        if (func_800F54E4() == local_0 && local_0 != -1) {
            if (func_800F64A4(local_0, 0xB)) {
                func_800F5A00(local_0, local_1);
                local_2 = (f32 *)&param_0[1];
                if (local_0 && local_0 && local_0) {}
                if (func_800EEB40(local_2, local_1) < 10000.0f) {
                    if (local_2) {}
                    _subaddieaudioquick_entrypoint_2(param_0, local_2, &D_808005D8_chdingpot);
                    _subaddieDll_entrypoint_4(param_0, 1);
                    func_80102424(param_0, 3);
                    func_800F82D4(local_0, 2);
                    func_800F7F98(local_0, 1);
                    _capod_entrypoint_13(param_0[0], 0, 2, 0x10);
                    func_800F4CEC(local_0, 0x60);
                    func_800C9C04(0.5f, 0x15, 22000);
                }
            }
        }
    }
}
