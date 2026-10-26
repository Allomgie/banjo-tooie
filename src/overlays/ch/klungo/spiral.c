#include "common.h"

extern void *D_80800620_chklungospiral;
extern void _subaddiemarker_entrypoint_1();
extern void _subaddieDll_entrypoint_2();
extern void func_80105A9C(u8 *, f32);
extern void func_80105BAC();
extern f32 D_80800668_chklungospiral[];
extern void *func_80100094(Actor *, s32);
extern u8 unk6C[];
extern u8 D_808005F0_chklungospiral[];
extern u8 unk6A[];
typedef struct { u8 pad[0x6C]; u32 pad6C:23; u32 f:9; } KlungoS;
extern void _capod_entrypoint_3(s32, KlungoS *);
extern s32 D_80800688_chklungospiral;
extern s32 D_80800674_chklungospiral;
extern s32 func_80101E4C(Actor *, void *);
extern s32 func_80101E14(Actor *, f32);
extern void func_80018820(s32, f32, f32);
extern void func_800E15CC(s32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
void func_808002FC_chklungospiral();
int func_808003AC_chklungospiral();
s32 func_80800430_chklungospiral();
void func_80800480_chklungospiral();

int chklungospiral_entrypoint_0()
{
  return &D_80800620_chklungospiral;
}

void func_8080000C_chklungospiral(u8 *param_0) {
    s32 local_0[6];
    _subaddiemarker_entrypoint_1(param_0, 0x154, 0x33, local_0, 1);
    _subaddieDll_entrypoint_2(param_0, local_0);
    func_80105A9C(param_0, 300.0f);
    func_80105BAC(param_0);
}

void func_80800060_chklungospiral(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 1:
            if (func_8010C500(param_0)) {
                func_80102424(param_0, 2);
                func_808003AC_chklungospiral(param_0, 15, 48);
            }
            break;
        case 2:
            func_80800480_chklungospiral(param_0);
            break;
        case 3:
            func_80105834(param_0);
            func_80105230(param_0, D_80800668_chklungospiral);
            if (func_80105A5C(param_0)) {
                func_80800430_chklungospiral(param_0);
                func_800FFAB0(param_0);
                func_800DA544(0x3C);
            }
            break;
    }
    if (func_80100094(param_0, 1)) {
        _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    }
}

s32 func_8080015C_chklungospiral(Actor *param_0, s32 param_1, u32 param_2)
{
    switch (param_1) {
        case 11:
            if (param_2 == 15) {
                func_808002FC_chklungospiral(param_0, 3, 1);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x1638, 0xE, 0, 0xAB);
                return 4;
            }
            return 3;
        case 46:
            func_808003AC_chklungospiral(param_0, 22, 48);
            func_80102424(param_0, 3);
            break;
        case 0x57:
            return func_808002A0_chklungospiral(param_0, param_2 & 0xFFFF, (param_2 & 0xFFFF0000) >> 16);
        case 41:
            _suexpression_entrypoint_7(param_0, 1, 0xAB);
            break;
        case 42:
            _suexpression_entrypoint_8(param_0, 1);
            break;
        case 31:
            func_801015D0(param_0);
            func_800DF744(3, 0);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_808002A0_chklungospiral(Actor *param_0, s32 param_1, s32 param_2)
{
  if (_gcdialogcamera_entrypoint_0(param_1 | 0, param_2 | 0))
  {
    if (((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF) != 2)
    {
      func_808002FC_chklungospiral(param_0, 2, 1);
    }
    return 2;
  }
  return 1;
}

void func_808002FC_chklungospiral(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;

    local_0 = (*(s32 *)((s8 *)(param_0) + (0x6C))) & 0x1FF;
    switch (local_0) {                              
    case 0:
        _capod_entrypoint_2((*(s32 *)((s8 *)(param_0) + (0))), 0xc, 0);
        
    case 1:
        _capod_entrypoint_8(1);
        (*(u16 *)((s8 *)(param_0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(param_0) + (0x6E))) & 0xFE00) | 2);
        _gcdialogcamera_entrypoint_3(&D_808005F0_chklungospiral, (*(s32 *)((s8 *)(param_0) + (0x38))));
        _gcdialogcamera_entrypoint_4(param_0 + 4);
        _gcdialogcamera_entrypoint_5(param_0 + 0x44);
        _gcdialogcamera_entrypoint_8();
        
    case 2:
        _capod_entrypoint_7(param_1, param_2);
        return;
    }
}

int func_808003AC_chklungospiral(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
  s32 new_var;
  s32 temp_t6;
  new_var = *((s32 *) (((char *) param_0) + 0x6C));
  temp_t6 = new_var & 0x1FF;
  switch (temp_t6 & 0xFFFF)
  {
    case 0:
      _capod_entrypoint_2(*((s32 *) (((char *) param_0) + 0x0)), 0xC, param_2, param_0);

    case 2:
      *((u16 *) (((char *) param_0) + 0x6E)) = (u16) (((*((u16 *) (((char *) param_0) + 0x6E))) & 0xFE00) | 1);

    case 1:
      _capod_entrypoint_6(*((s32 *) (((char *) param_0) + 0x0)), param_1, param_2, param_0);
      return;
      if (!param_0)
    {
    }

  }

}

s32 func_80800430_chklungospiral(param_0) KlungoS *param_0; {
    if (param_0->f) {
        _capod_entrypoint_3(0, param_0);
        param_0->f = 0;
        return 1;
    }
    return 0;
}

void func_80800480_chklungospiral(param_0) Actor *param_0;
{
    if (!param_0->unk7C_12) {
        return;
    }
    if (func_80101E4C(param_0, &D_80800688_chklungospiral)) {
        func_80018820(0, 0.8f, 0.3f);
        func_800E15CC(0, 5.0f, 0.7f);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800674_chklungospiral);
        return;
    }
    if (func_80101E14(param_0, 0.7f)) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 10.0f, 0.8f);
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800674_chklungospiral);
    }
}
