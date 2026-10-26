#include "common.h"

extern f32 func_8010CD28(Actor *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_80013728(f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_8008F990(f32 *, f32);
extern void func_8010D5DC();
typedef struct { u8 pad_0[0x70]; u32 pad_1 : 16; u32 local_0 : 6; u32 pad_2 : 10; } MolehillMode;
extern void _chmolehill_entrypoint_0(void);
extern Actor *func_80106790();
extern int D_80800B70_chmolehill;
typedef struct { f32 local_0[5]; } MoleHillTimes401;
extern u8 D_80800AC0_chmolehill[];
extern u8 D_80800ACC_chmolehill[];
extern u8 D_80800ADC_chmolehill[];
extern MoleHillTimes401 D_80800B5C_chmolehill;
extern s32 func_80101E14(Actor *, f32);
typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest:10; } MoleState;
extern u8 func_800D731C(s32);
extern f32 func_800D8FF8(void);
extern void func_800DBE60(u8, s32, s32);
void func_80800884_chmolehill();

int func_80800000_chmolehill(Actor *param_0)
{
    if (func_8010CAC0(param_0->position, 0x87)) return 0;
    if (mlAbsF(func_800F1DCC(func_8010CD28(param_0), param_0->rotation[1] + 15.0f)) > 5.0f) return 0;
    return 1;
}

void func_80800088_chmolehill(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;

    if (param_0->unk64_20) {
        func_8010D254(local_1);
        local_2 = func_800F1DF4(param_0->position, local_1);
        local_3 = func_80013728(func_800F1DCC(local_2, param_0->rotation[1] + 15.0f));
        if (local_3 < -15.0f) local_3 = -15.0f;
        if (local_3 > 15.0f) local_3 = 15.0f;
        local_2 -= local_3;
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, local_2, 150.0f);
        func_8008F964(local_0);
    }
}

void chmolehill_entrypoint_2();

void chmolehill_entrypoint_1();

void func_80800160_chmolehill(Actor *param_0)
{
  s32 local_0;
  u32 new_var;
  local_0 = 0;
  param_0->unk64_19 = 0;
  switch (param_0->unk79_4)
  {
    case 0:

    case 2:

    case 5:

    case 6:
      break;

    case 7:
      chmolehill_entrypoint_1(param_0, 0);
      chmolehill_entrypoint_2(param_0, 0xD);
      break;

    case 1:
      func_80800088_chmolehill(param_0);
      if (param_0->unk3C && func_80800000_chmolehill(param_0))
    {
      func_8008F8B0();
      chmolehill_entrypoint_1(param_0, 0);
      chmolehill_entrypoint_2(param_0, 2);
    }
      break;

    case 3:
      func_80800088_chmolehill(param_0);
      if (param_0->unk3C && func_80800000_chmolehill(param_0))
    {
      func_8008F8B0();
      chmolehill_entrypoint_1(param_0, 0);
      chmolehill_entrypoint_2(param_0, 7);
    }
      break;

    case 4:
      chmolehill_entrypoint_1(param_0, 0);
      chmolehill_entrypoint_2(param_0, 8);
      break;

  }

  new_var = param_0->unk70_10;
  if ((new_var != 2) && (new_var != 7))
  {
    if (new_var != 9)
    {
      if (new_var == 10)
      {
        param_0->unk64_19 = 1;
      }
    }
    else
    {
      param_0->unk64_19 = 1;
    }
  }
  if ((*((s16 *) (((u8 *) param_0) + 0x8C))) && (anctrl_getPlaybackType(func_80104248(param_0)) != 3))
  {
    switch (func_801022E4(param_0))
    {
      case 0x229:
        if (func_80101E14(param_0, 0.288f))
      {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AC0_chmolehill);
      }
      else
        if (func_80101E14(param_0, 0.69f) || func_80101E14(param_0, 0.76f))
      {
        local_0 = 1;
      }
        break;

      case 0x22A:
        if (func_80101E14(param_0, 0.16f))
      {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AC0_chmolehill);
      }
      else
        if (func_80101E14(param_0, 0.86f) || func_80101E14(param_0, 0.98f))
      {
        local_0 = 1;
      }
        break;

      case 0x22B:
        if (func_80101E14(param_0, 0.2f))
      {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800ACC_chmolehill);
      }
        break;

      case 0x22C:
        if (func_80101E14(param_0, 0.48f))
      {
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AC0_chmolehill);
      }
      else
        if (func_80101E14(param_0, 0.7136f) || func_80101E14(param_0, 0.9336f))
      {
        local_0 = 1;
      }
        break;

      case 0x22E:
      {
        const MoleHillTimes401 local_1 = D_80800B5C_chmolehill;
        if (func_80101E14(param_0, 0.04f))
        {
          _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800AC0_chmolehill);
        }
        else
          if (func_80101E4C(param_0, local_1.local_0))
        {
          local_0 = 1;
        }
        break;
      }

    }

  }
  if (local_0)
  {
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800ADC_chmolehill);
  }
}

int chmolehill_entrypoint_0(Actor *param_0)
{
  Actor *local_0;
  s32 *local_1;
  s32 pad[2];
  local_0 = func_80106790();
  local_1 = func_801084B0(0x18F, &local_0);
  (*(s32 *)((char *)(local_0) + 0x3C)) = (*(s32 *)((char *)(local_1) + 0));
  (*(s32 *)((char *)(local_1) + 0x3C)) = (*(s32 *)((char *)(local_0) + 0));
  func_80108944(local_1, local_0);
  _chmoley_entrypoint_1(local_1, (u32)(*(u16 *)((char *)(local_0) + 0x72)) >> 10 | 0);
}

void func_8080058C_chmolehill(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;
    f32 local_3;

    if (!func_80800000_chmolehill(param_0)) {
        func_8010D254(local_1);
        local_2 = func_800F1DF4(param_0->position, local_1);
        local_3 = func_80013728(func_800F1DCC(local_2, param_0->rotation[1] + 15.0f));
        if (local_3 < -15.0f) local_3 = -15.0f;
        if (local_3 > 15.0f) local_3 = 15.0f;
        local_2 -= local_3;
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, local_2, 150.0f);
        func_8008F8B0();
        func_8008F8D8(1);
        func_8008F938(1);
        func_8008F904(func_8010D5DC, param_0->unk0);
        func_8008F990(local_0, 300.0f);
        param_0->unk64_20 = 1;
    }
}

void chmolehill_entrypoint_1(Actor *param_0, s32 param_1)
{
    param_0->unk79_4 = param_1;
    switch (param_0->unk79_4) {
    case 1:
    case 3:
        _chbaddiesetup_entrypoint_1(_chmolehill_entrypoint_0, param_0->unk0);
        func_8080058C_chmolehill(param_0);
        break;
    case 7:
        ((MolehillMode *)param_0)->local_0 = 0xD;
        _chbaddiesetup_entrypoint_1(_chmolehill_entrypoint_0, param_0->unk0);
        break;
    }
    if (param_0->unk3C) _chmoley_entrypoint_0(func_80106790(param_0->unk3C), param_1);
}

void chmolehill_entrypoint_2(Actor *param_0, s32 param_1)
{
    if (param_1 != param_0->unk70_10) {
        func_80102424(param_0, param_1);
        if (param_0->unk70_10 == 1 && param_0->unk3C) {
            func_800FFA88(param_0->unk3C);
            param_0->unk3C = 0;
        }
        if (param_0->unk3C) _chmoley_entrypoint_1(func_80106790(param_0->unk3C), param_1);
    }
}

s32 chmolehill_entrypoint_3(MoleState *param_0) {
    switch (param_0->f72) {
    case 0:
    case 1:
    case 3:
    case 11:
        return 0;
    case 7:
    case 8:
    case 9:
        return 0;
    case 2:
    case 4:
    case 5:
    case 6:
    case 10:
        return 1;
    }
    return 0;
}

int chmolehill_entrypoint_4(s32 param_0, s32 param_1)
{
  *(s32 *)func_80100094(param_0, 0) = param_1;
}

int chmolehill_entrypoint_5(s32 param_0)
{
    s32 ret = func_80100094(param_0, 0);
    return *(s32*)(ret);
}

void func_80800884_chmolehill(param_0) Actor *param_0;
{
    u8 local_0;

    local_0 = func_800D731C(param_0->unk0->unk14);
    if (param_0->unk74_30) {
        *(f32 *)((u8 *)param_0 + 0x28) += 15.0f * func_800D8FF8();
        if (8.49f <= *(f32 *)((u8 *)param_0 + 0x28)) {
            *(f32 *)((u8 *)param_0 + 0x28) = 8.49f;
            param_0->unk74_30 = 0;
        }
    } else {
        *(f32 *)((u8 *)param_0 + 0x28) -= 15.0f * func_800D8FF8();
        if (*(f32 *)((u8 *)param_0 + 0x28) <= 0.0f) {
            *(f32 *)((u8 *)param_0 + 0x28) = 0.0f;
            param_0->unk74_30 = 1;
        }
    }
    if (local_0 != 0) {
        func_800DBE60(local_0, 0, *(f32 *)((u8 *)param_0 + 0x28));
        func_800DBE60(local_0, 1, *(f32 *)((u8 *)param_0 + 0x28));
    }
}

s32 func_808009A0_chmolehill(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x32:
        func_8080058C_chmolehill(param_0);
        break;
    case 0x1F:
        func_801015D0(param_0);
        func_80800884_chmolehill(param_0);
        local_0 = param_0->unk74_29 || _glcutDll_entrypoint_20() ? 2 : 1;
        func_800DF744(3, local_0);
        break;
    default:
        return 0;
    }
    return 1;
}

int *chmolehill_entrypoint_6()
{
    return &D_80800B70_chmolehill;
}
