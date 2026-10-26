#include "common.h"

typedef struct { s16 local_0; u16 pad_0; f32 local_1; u32 pad_1; s16 local_2; u8 local_3; u8 pad_2; u32 pad_3; f32 local_4; } PowerHutState;
typedef struct { u16 local_0; u8 pad_0[6]; f32 local_1; } PowerHutSetup;
extern void *func_80100094(Actor *, u32);
extern void func_800EE88C();
extern s32 func_800D9058(f32);
extern u8 D_80800970_chpowerhut[];
extern f32 D_80800988_chpowerhut[3];
extern void *func_800D674C(s32);
extern void func_800DE448(f32 *, f32 *, f32, s32, void *);
extern u8 D_80800950_chpowerhut[];
extern u8 D_80800964_chpowerhut[];
extern u8 D_80800958_chpowerhut[];
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s32);
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern u8 D_80800994_chpowerhut[];
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, f32 *, f32 *, void *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern int D_808009C0_chpowerhut;
extern f32 _sumumbofx_entrypoint_22(void *);
extern u8 D_808009A0_chpowerhut[];
extern u8 D_808009B4_chpowerhut[];
extern int func_800D9078();
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC298(f32);
extern void func_80018820(s32, f32, f32);
extern void func_800E15CC(s32, f32, f32);
void func_80800400_chpowerhut();
int func_8080047C_chpowerhut();
s32 func_808005F4_chpowerhut();
int func_80800698_chpowerhut();

s32 chpowerhut_entrypoint_0(Actor *param_0, PowerHutSetup *param_1)
{
    PowerHutState *local_0;

    local_0 = func_80100094(param_0, 0);
    func_800EE88C((f32 *)&param_0->actorData[0], _gccubesearch_entrypoint_0(0x154, param_0));
    local_0->local_1 = param_1->local_1;
    local_0->local_0 = func_800D9058(1.5f);
    local_0->local_2 = 1;
    local_0->local_3 = 0;
    local_0->local_4 = 0.0f;
    if (func_800DA298(param_1->local_0) || _glcutDll_entrypoint_20()) {
        func_80101FDC(param_0, 5);
        local_0->local_2 = 4;
        local_0->local_4 = 1.0f;
        return 1;
    }
    return 0;
}

s32 chpowerhut_entrypoint_1(Actor *param_0, u16 *param_1)
{
    _subaddieaudioloop_entrypoint_5(param_0, param_0->position, func_800DA298(param_1[0]) != 0 || _glcutDll_entrypoint_20() != 0, 0x708, D_80800970_chpowerhut);
    switch (param_0->unk70_10) {
        case 2:
            func_8080047C_chpowerhut(param_0, param_1);
            break;
        case 3:
            func_8080047C_chpowerhut(param_0, param_1);
            func_80800698_chpowerhut(param_0, param_1);
            break;
        case 4:
            func_8080047C_chpowerhut(param_0, param_1);
            if (func_808005F4_chpowerhut(param_0)) {
                _subaddieDll_entrypoint_4(param_0, 0);
                return 1;
            }
            break;
    }
    return 0;
}

void chpowerhut_entrypoint_2(Actor *param_0, s32 param_1)
{
    u8 *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    if (func_80100094(param_0, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
    }
    if (*(s16 *)(local_0 + 0xC) == 3) {
        local_1 = func_800DC128(0, 4);
        for (local_2 = 0; local_2 < 4; local_2++) {
            func_800DF744(local_2 + 1, local_1 == local_2 ? 1 : 0);
        }
        func_800DF830(2);
        func_800DE448((f32 *)((u8 *)param_0 + 0x18), D_80800988_chpowerhut, 2.5f, 0, func_800D674C(0x742));
    }
}

int chpowerhut_entrypoint_3(Image *param_0, s32 param_1, u8 param_2, OSIoMesgHdr *param_3)
{
  Image *local_0;
  s32 local_1;
  u8 *local_2;

  local_0 = param_0;
  switch (param_1)
  {
    case 0xA :
      if ((func_800DA298((*(u16 *)((char *)(param_3) + 0x0))) != 0) || (_glcutDll_entrypoint_20() != 0))
      {
        return 0;
      }
      func_80101FDC(local_0, 2);
      _subaddieDll_entrypoint_4(local_0, 1);
      func_80103110(local_0, 1);
      func_80800400_chpowerhut(local_0);
      _capod_entrypoint_13(*(u8 **)((char *)local_0 + 0x0), 0, (*(u16 *)((char *)(param_3) + 0x2)), (*(u16 *)((char *)(param_3) + 0x4)));
      goto block_13;
    case 0x95 :
      (*(u8 *)((char *)(func_80100094(local_0, 0)) + 0xE)) = 0;
      local_1 = func_800C8A98();
      (*(s32 *)((char *)(local_0) + 0x28)) = local_1;
      func_800C8D4C(local_1, D_80800950_chpowerhut);
      func_800C8CB8((*(s32 *)((char *)(local_0) + 0x28)), (u8 *)local_0 + 0x18);
      if ((func_800DA298((*(u16 *)((char *)(param_3) + 0x0))) != 0) || (_glcutDll_entrypoint_20() != 0))
      {
        local_2 = D_80800964_chpowerhut;
      }
      else
      {
        local_2 = D_80800958_chpowerhut;
      }
      func_800C8E84((*(s32 *)((char *)(local_0) + 0x28)), local_2);
      func_80103110(local_0, func_800DA298((*(u16 *)((char *)(param_3) + 0x0))));
      goto block_13;
    default:
      return 0;
  }
block_13:
  return 1;
}

void func_80800400_chpowerhut(param_0) Actor *param_0;
{
    void *local_0;
    _sumumbofx_entrypoint_0(param_0, 1, 20, (s16)_chmumbopad_entrypoint_0(3));
    local_0 = func_80100094(param_0, 1);
    _sumumbofx_entrypoint_2(local_0);
    _sumumbofx_entrypoint_24(local_0, 2.25f);
    _sumumbofx_entrypoint_15(local_0, 3.0f);
    _sumumbofx_entrypoint_20(local_0, 3.0f);
}

int func_8080047C_chpowerhut(param_0, param_1) Actor *param_0; u8 *param_1;
{
    f32 local_0[3];
    void *local_1;
    u8 *local_2;
    local_1 = func_80100094(param_0, 1);
    local_2 = func_80100094(param_0, 0);
    func_800EFD24(local_0);
    if (func_800DA298(0x9DE)) {
        _sumumbofx_entrypoint_6(local_1, 500.0f, (f32)(u32)*(u16 *)(param_1 + 6), 0, 20, local_0, param_0->position, &D_80800994_chpowerhut);
        switch (param_0->unk70_10) {
        case 2:
            if (_sumumbofx_entrypoint_21(local_1) == 0.0f && _sumumbofx_entrypoint_5(local_1, 1.85f)) {
                _sumumbofx_entrypoint_17(local_1, *(f32 *)(param_1 + 8));
                func_80101FDC(param_0, 3);
            }
            break;
        case 3:
            *(f32 *)(local_2 + 8) = *(f32 *)(param_1 + 8) - *(f32 *)(local_2 + 4);
            if (func_800D9078(local_2 + 4)) {
                _chglowbo_entrypoint_6();
                _sumumbofx_entrypoint_16(local_1, 1.5f);
                func_80101FDC(param_0, 4);
            }
            break;
        }
        _sumumbofx_entrypoint_14(local_1);
    }
}

s32 func_808005F4_chpowerhut(param_0) Actor *param_0;
{
    u16 *local_0;
    if (_sumumbofx_entrypoint_22(func_80100094(param_0, 1)) < 0.05f) {
        local_0 = func_80100094(param_0, 0);
        if (*local_0) {
            *local_0 = *local_0 - 1;
            return 0;
        } else {
            _sumumbofx_entrypoint_1(param_0, 1);
            func_80101FDC(param_0, 5);
            func_800DA524(0x9DE);
            func_800DA544(0x9DF);
            return 1;
        }
    }
    return 0;
}

int func_80800698_chpowerhut(param_0, param_1) Actor *param_0; u8 *param_1;
{
    u8 *local_2;
    s32 local_0;

    local_2 = func_80100094(param_0, 0);
    local_2[0xE] = _subaddieaudioloop_entrypoint_7(local_2[0xE], ((f32 *)param_0->actorData),
        *((s16 *)(local_2 + 0xC)) == 3, D_808009A0_chpowerhut,
        *((u32 *)((u8 *)param_0 + 0x70)) & 1);
    switch (*((s16 *)(local_2 + 0xC))) {
    case 1:
        if (*((f32 *)(param_1 + 0xC)) < *((f32 *)(param_1 + 8)) - *((f32 *)(local_2 + 4))) {
            *((s16 *)(local_2 + 0xC)) = 2;
        }
        break;
    case 2:
        _subaddieaudioquick_entrypoint_2(param_0, ((f32 *)param_0->actorData), D_808009B4_chpowerhut);
        *((s16 *)(local_2 + 0xC)) = 3;
        *((f32 *)(local_2 + 0x10)) = *((f32 *)(param_1 + 0x10));
        func_800C8E84(param_0->actorData[4], D_80800964_chpowerhut);
        func_80018820(0, 2.0f, 1.0f);
        func_800E15CC(0, 20.0f, 0.9f);
        func_800DA544(*((u16 *)param_1));
        func_80101180(0x33D, 0xA, 0);
        break;
    case 3:
        local_0 = func_800D9078((f32 *)(local_2 + 0x10));
        *((f32 *)(local_2 + 0x14)) = 1.0f;
        if (func_800DC298(0.8f) && *((f32 *)(local_2 + 0x10)) > 0.15f) {
            *((f32 *)(local_2 + 0x14)) *= func_800DC178(0.25f, 0.5f);
        }
        if (local_0) {
            *((s16 *)(local_2 + 0xC)) = 4;
            *((f32 *)(local_2 + 0x14)) = 1.0f;
        }
        func_80800870_chpowerhut(param_0);
        break;
    }
}

int func_80800870_chpowerhut(s32 param_0)
{
  int new_var2;
  int new_var3;
  new_var2 = 0;
  if (!func_8001210C(3 ^ new_var2))
  {
    int new_var;
    new_var2 = (new_var = param_0 | ((param_0 + 0x18) * new_var2));
    new_var2 = param_0 + 0x18;
    new_var3 = new_var2;
    func_800BBCB8(new_var2, new_var3, 0x3F800000, 2, &D_808009C0_chpowerhut);
  }
}

int chpowerhut_entrypoint_4(Actor *param_0, f32 param_1, f32 *param_2)
{
    f32 *local_0;
    f32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = param_2[2] - local_0[1];
    return param_1 < local_1 && local_0[2] <= param_1;
}
