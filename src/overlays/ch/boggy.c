#include "common.h"

extern s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
extern void func_80101FDC(s32, s32);
extern void func_800DA544(s32);
extern void func_800F82D4(s32, s32);
extern s32 func_800F54E4(void);
typedef union { s32 word; s16 half[2]; } BoggyMessage32;
extern s32 D_80800820_chboggy[];
extern Actor *func_80106790();
extern s32 _chbounce_entrypoint_9(s32);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern void func_800902E4(f32 *, f32, s32, Actor **);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_80800740_chboggy[];
extern u8 D_80800704_chboggy[];
extern u8 D_808006A0_chboggy[];
extern u8 D_80800710_chboggy[];
extern u8 D_808006F8_chboggy[];
extern u8 D_808006C8_chboggy[];
extern u8 D_8080074C_chboggy[];
extern u8 D_80800800_chboggy[];
extern u8 D_80800790_chboggy[];
extern u8 D_808006B0_chboggy[];
extern u8 D_808006E8_chboggy[];
extern u8 D_80800760_chboggy[];
extern u8 D_808006B8_chboggy[];
extern u8 D_80800730_chboggy[];
extern u8 D_808006D8_chboggy[];
extern u8 D_80800720_chboggy[];
extern u8 D_80800810_chboggy[];
extern u8 D_808007C8_chboggy[];
typedef struct { u8 pad[0x7C]; u32 pad7C:19; u32 flag:1; u32 rest:12; } BoggyS;
extern s32 func_80104130(void);
extern void func_800DBEFC();
extern void *_idworld_entrypoint_0(s32);
extern f32 _idglowa_entrypoint_1(void *);
extern s16 D_80800830_chboggy[];
extern s32 func_800C4350();
extern void func_800C3A40(u8, f32, f32, f32);
extern int D_80800840_chboggy;
typedef struct { u8 pad[0x38]; f32 f38; u8 pad3C[8]; f32 f44; u8 pad48[4]; f32 f4C; u8 pad50[0x26]; u16 f76:9; u16 pad76:7; } BoggyState;
extern int D_80800888_chboggy;
void func_80800554_chboggy();

void func_80800000_chboggy(s32 param_0)
{
  *((f32 *) (((u8 *) param_0) + 0x38)) = 0.18f;
  if (func_800DA298(0x439) != 0 || _glcutDll_entrypoint_20() != 0)
  {
    func_80101FDC(param_0, 3);
  }
  return;
}

void func_80800054_chboggy(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  s32 local_1;
  local_0 = _subaddiedialog_entrypoint_9(param_0, param_1, ((s32 *) D_80800790_chboggy), 7);
  local_1 = _subaddiedialog_entrypoint_9(param_0, param_1, ((s32 *) D_808007C8_chboggy), 7);
  if (local_0 == 1)
  {
    func_80101FDC(param_0, 1);
    func_800DA544(0x447);
  }
  else
    if (local_1 == 1)
  {
    func_800F82D4(func_800F54E4() | 0, 0 | 0);
  }
}

s32 func_808000EC_chboggy(Actor *param_0, s32 param_1, BoggyMessage32 param_2)
{
    s32 local_0;

    switch (param_1) {
        case 0x2E:
            func_80800054_chboggy(param_0, param_2.half[0], param_2.half[1]);
            break;
        case 0x1F:
            func_800DF3E0();
            func_801015D0(param_0);
            local_0 = param_0->unk70_10 == 1 ? 1 : 2;
            func_800DF744(3, local_0);
            break;
        case 0x7D:
            func_80101FDC(param_0, 2);
            break;
        case 0x3D:
            if (param_2.word == 0x22B) {
                _subaddieaudioquick_entrypoint_2(param_0, &param_0->actorData[4], D_80800820_chboggy);
                *(f32 *)&param_0->actorData[1] -= 60.0f;
                ((f32 *)_chbounce_entrypoint_9((s32)func_80106790(
                    func_800D10D4(0x40, 1, param_0->actorData, 0, 0))))[1] = 0.0f;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800220_chboggy(Actor *param_0)
{
  u32 local_0;
  _sudeflect_entrypoint_0(param_0->position, 175.0f, 175.0f, 0xE);
  func_80800554_chboggy(param_0);
  local_0 = param_0->unk70_10;
  switch (local_0)
  {
    case 1:
      _subaddieaudioquick_entrypoint_3(param_0, (f32 *)&param_0->actorData[4], &D_808006A0_chboggy, 0.1298000067f);
      _subaddieaudioquick_entrypoint_4(param_0, (f32 *)&param_0->actorData[4], &D_80800704_chboggy, &D_80800740_chboggy);
      _subaddieaudioquick_entrypoint_3(param_0, (f32 *)&param_0->actorData[4], &D_80800710_chboggy, 0.4199999869f);
      _subaddieaudioquick_entrypoint_3(param_0, (f32 *)&param_0->actorData[4], &D_808006F8_chboggy, 0.5799999833f);
      _subaddieaudioquick_entrypoint_4(param_0, (f32 *)&param_0->actorData[4], &D_808006C8_chboggy, &D_8080074C_chboggy);
      if (((func_800DA298(0x447) != 0) && (((func_800902E4(param_0->position, 400.0f, 0x4D7, &param_0), func_800F640C(func_800F54E4(), 0x4D7) != 0)) || (func_8008FE14() == 0x4D7))) && (func_80090818() != 0))
    {
      func_80090768((f32 *)param_0->actorData);
      func_800D1824(0x51);
      func_800F8300(func_800F54E4(), 2, param_0->position);
    }
      if (func_800DA298(0x439) != 0)
    {
      func_800DA544(0x437);
    }
      _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_80800800_chboggy, &D_80800790_chboggy, 7);
      return;

    case 2:
      _subaddieaudioquick_entrypoint_3(param_0, (f32 *)&param_0->actorData[4], &D_808006B0_chboggy, 0.05000000075f);
      _subaddieaudioquick_entrypoint_4(param_0, (f32 *)&param_0->actorData[4], &D_808006E8_chboggy, &D_80800760_chboggy);
      _subaddieaudioquick_entrypoint_4(param_0, (f32 *)&param_0->actorData[4], &D_808006B8_chboggy, &D_80800730_chboggy);
      if (((func_80101E14(param_0, 0.6000000238f) != 0) && (func_800D0B68(0x40, 1) == 0)) && (func_800D0A9C(0x40, 1) == 0))
    {
      func_80108B04(param_0, 0x22B);
    }
      if (func_80101E14(param_0, 0.9900000095f) != 0)
    {
      func_80101FDC(param_0, 3);
      return;
    }
      return;

    case 3:
      _subaddieaudioquick_entrypoint_3(param_0, (f32 *)&param_0->actorData[4], &D_808006D8_chboggy, 0.2199999988f);
      _subaddieaudioquick_entrypoint_4(param_0, (f32 *)&param_0->actorData[4], &D_808006B8_chboggy, &D_80800720_chboggy);
      _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_80800810_chboggy, &D_808007C8_chboggy, 7);
      break;

  }

}

void func_80800504_chboggy(BoggyS *param_0) {
    func_801018A4(param_0);
    if (param_0->flag) {
        func_800DBEFC(func_80104130(), 4, (u8 *)param_0 + 0x18);
    }
}

void func_80800554_chboggy(param_0) s32 param_0;
{
    s32 local_0;
  s32 pad0;
    u8 local_1;
    void *local_2;

    local_2 = _idworld_entrypoint_0(0x35C);
    if (local_2 != NULL) {
        local_0 = (s32)(_idglowa_entrypoint_1(local_2) * 32.0f);
        if (local_0 == 0x13) func_800DA544(0xA2E);
        if (local_0 == 0x12 && func_800DA298(0xA2E)) {
            local_1 = func_800C4350(0, NULL, D_80800830_chboggy);
            func_800C36F4(local_1, 1);
            func_800C3A40(local_1, 1.0f, 1.4f, 1.0f);
            func_800C3BDC(local_1);
            func_800DA524(0xA2E);
        }
    }
}

int chboggy_entrypoint_0()
{
    return (int)&D_80800840_chboggy;
}

void func_80800634_chboggy(BoggyState *param_0) {
    param_0->f44 = param_0->f76;
    param_0->f4C = param_0->f38 * 100.0f;
    param_0->f38 = 2.0f;
}

int chboggy_entrypoint_1()
{
    return (int)&D_80800888_chboggy;
}
