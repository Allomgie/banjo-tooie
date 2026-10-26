#include "common.h"

#define OD(n) (((f32 *)param_0->actorData)[n])
extern int D_80800920_chpotogoldbits;
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern void func_80101FDC(Actor *, s32);
extern int D_80800988_chpotogoldbits;
extern int _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_7(Actor *, f32);
extern s32 D_808009D0_chpotogoldbits[];
extern u8 D_80800968_chpotogoldbits[];
extern u8 D_80800978_chpotogoldbits[];
extern void func_80103110(Actor *, s32);
extern void _subaddieaudioquick_entrypoint_2();
extern s32 func_800D90A4(f32 *);
extern void _subaddieaudioloop_entrypoint_4();
extern s32 func_800D91EC(f32 *, f32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void func_800FFA88(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_80013970(f32);
extern void _chpotogoldbits_entrypoint_1();
extern void func_800CE8D8(void *, f32, s32);
s32 func_80800618_chpotogoldbits();
extern void func_80101870(), func_80105834(), func_80107C2C(), func_8080007C_chpotogoldbits();

s32 func_80800000_chpotogoldbits(Actor *this) {
    _chswitch_entrypoint_7(this, 0xA2D);
    _chswitch_entrypoint_8(this, 0x601);
}

s32 func_80800030_chpotogoldbits(void *this, s32 next_state)
{
  if (next_state == 7)
  {
    func_80101180(0x408, 7, 0);
    return 1;
  }
  _chswitch_entrypoint_10(this, next_state);
}

int chpotogoldbits_entrypoint_0()
{
    return (int)&D_80800920_chpotogoldbits;
}

void func_8080007C_chpotogoldbits(param_0) Actor *param_0;
{
    f32 local_0[3];

    func_800EE7F8((f32 *)&param_0->actorData[4], param_0->position);
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    if (func_800EA05C() == 0x136) {
        ((f32 *)param_0->actorData)[1] -= 500.0f;
        ((f32 *)param_0->actorData)[3] = 0.0f;
        param_0->unk54 = 3.0f;
        return;
    }
    func_800F5A00(func_800F54E4(), local_0);
    if (func_800EA090() == 1 && param_0->position[1] <= local_0[1]) {
        ((f32 *)param_0->actorData)[1] -= 2000.0f;
        ((f32 *)param_0->actorData)[3] = 0.0f;
        param_0->unk54 = 3.0f;
        func_80101FDC(param_0, 9);
        func_800CE88C(0, 0);
        return;
    }
    func_800FFA88(param_0->unk0);
}

void func_80800188_chpotogoldbits(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        func_80103110(param_0, 0);
        break;
    case 2:
        if (!param_0->unk74_30) {
            param_0->unk74_30 = 1;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(&OD(7))) {
            if (1) {}
            func_80101FDC(param_0, 3);
        }
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800968_chpotogoldbits);
        break;
    case 3:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800968_chpotogoldbits);
        if (func_800D91EC(&OD(3), param_0->unk54)) {
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
            func_80101FDC(param_0, 4);
        }
        break;
    case 4:
        func_80103110(param_0, 0);
        break;
    case 5:
        if (!param_0->unk74_30) {
            param_0->unk74_30 = 1;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(&OD(7))) {
            if (1) {}
            func_80101FDC(param_0, 6);
        }
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800968_chpotogoldbits);
        break;
    case 6:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800968_chpotogoldbits);
        if (func_800D90A4(&OD(3))) {
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
            func_80101FDC(param_0, 1);
        }
        break;
    case 7:
        break;
    case 8:
        if (!param_0->unk74_30) {
            param_0->unk74_30 = 1;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(&OD(7))) {
            func_80101FDC(param_0, 9);
        }
        break;
    case 9:
        if (func_800D91EC(&OD(3), param_0->unk54)) {
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
            param_0->unk74_30 = 0;
            func_80101FDC(param_0, 10);
        }
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800968_chpotogoldbits);
        break;
    case 10:
        if (!param_0->unk74_30) {
            param_0->unk74_30 = 1;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(&OD(7))) {
            param_0->unk50 = 0.5f;
            func_80101FDC(param_0, 11);
        }
        break;
    case 11:
        if (func_800D90A4(&param_0->unk50)) {
            func_800FFA88(param_0->unk0);
        }
        param_0->alpha = func_800F10B4(param_0->unk50, 0.5f, 0.0f, 255.0f, 0.0f);
        break;
    }
    param_0->unk58 = func_800F12D4(OD(3), 0.0f, param_0->unk54, 0.0f, 1.0f);
    func_800EFE50(param_0->position, &OD(4), &OD(0), param_0->unk58);
    if (OD(7) != 0) {
        param_0->position[1] += func_80013970(func_800F10B4(OD(7), 0.3f, 0.0f, 0.0f, 1.0f) * 180.0f) * 20.0f;
    }
}

s32 func_80800618_chpotogoldbits(param_0, param_1, param_2) u8 *param_0; s32 param_1; s32 param_2;
{
  switch (param_1)
  {
    case 0x7:
      if ((((u32) ((u16) (*((u16 *) (((s8 *) param_0) + 0x72))))) >> 0xA) != 4)
    {
      *((u8 *) (((s8 *) param_0) + 0x74)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x74))) & 0xFFBF);
      _capod_entrypoint_13(*((s32 *) (((s8 *) param_0) + 0)), 0, 3, 0x810);
      func_80103110(param_0, 1);
      *((f32 *) (((s8 *) param_0) + 0x34)) = 0.3f;
      func_80101FDC(param_0, 2);
    }
      return 1;

    case 0x8:
      if ((((u32) ((u16) (*((u16 *) (((s8 *) param_0) + 0x72))))) >> 0xA) == 4)
    {
      *((u8 *) (((s8 *) param_0) + 0x74)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x74))) & 0xFFBF);
      _capod_entrypoint_13(*((s32 *) (((s8 *) param_0) + 0)), 0, 5, 0x810);
      func_80103110(param_0, 1);
      *((f32 *) (((s8 *) param_0) + 0x34)) = 0.3f;
      func_80101FDC(param_0, 5);
    }
      return 1;

    case 0x91:
      if ((s32)((Actor *)param_0)->unk70_10 == 7)
    {
      func_80103110(param_0, 1);
      *((u8 *) (((s8 *) param_0) + 0x74)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x74))) & 0xFFBF);
      *((f32 *) (((s8 *) param_0) + 0x34)) = 0.3f;
      func_80101FDC(param_0, 8);
    }
      return 1;

    case 0xB:
      if (param_2 == 3)
    {
      func_800CE8D8(0, ((Actor *)param_0)->unk74_7, ((Actor *)param_0)->unk74_7);
      func_800CE928(0, _chpotogoldbits_entrypoint_1, 0);
      func_800CE88C(0, 1);
    }
      return 3;

    default:
      return 0;

  }

}

int chpotogoldbits_entrypoint_1(s32 param_0, s32 param_1)
{
  func_80101180(0x408, 8, 0);
}

int chpotogoldbits_entrypoint_2(void)
{
    return (int)&D_80800988_chpotogoldbits;
}

void func_80800810_chpotogoldbits(Actor *param_0)
{
    if (func_800EA090() == 0xD) {
        func_80101FDC(param_0, 4);
    }
    _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 212.0f, 2, -1);
    _chdoormake_entrypoint_5(param_0, 1.0f);
    _chdoormake_entrypoint_7(param_0, 0.5f);
    _chdoormake_entrypoint_8(param_0, 2);
    if (param_0->unk70_10 == 4) {
        func_8010108C(param_0, 8, 0);
    }
}

s32 chpotogoldbits_entrypoint_3()
{
  return (s32)D_808009D0_chpotogoldbits;
}
