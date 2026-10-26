#include "common.h"

extern int D_80800918_chbosskogsdoor;
typedef struct { u8 pad0[0x74]; u8 unk74_7 : 1; u8 unk74_6 : 1; u8 unk74_0 : 6; } BossKogsDoor;
extern int D_808009EC_chbosskogsdoor;
extern s32 D_808008B0_chbosskogsdoor;
extern u8 D_8080090C_chbosskogsdoor[];
extern u8 D_80800904_chbosskogsdoor[];
extern u8 D_808008F8_chbosskogsdoor[];
extern u8 D_808008E8_chbosskogsdoor[];
extern f32 func_800D8FF8(void);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern s32 func_800D91EC(f32 *, f32);
extern f32 func_80103EF4(Actor *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 D_80800988_chbosskogsdoor;
extern s32 D_80800994_chbosskogsdoor;
extern s32 D_808009A0_chbosskogsdoor;
extern s32 D_808009B0_chbosskogsdoor;
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void func_800EFA4C(f32 *, f32, f32, f32);

void func_80800000_chbosskogsdoor(Actor *param_0)
{
    if (func_800DA298(0x1B8)) {
        param_0->unk58 = param_0->unk74_7 / 10.0f;
        func_80101FDC(param_0, 9);
    } else param_0->unk58 = 0.0f;
    ((f32 *)param_0->actorData)[7] = param_0->position[1];
}

void func_80800090_chbosskogsdoor(Actor *param_0)
{

    switch (param_0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_800D90A4(&param_0->actorData[5])) {
            func_80101FDC(param_0, 3);
            func_800DA544(0x1B8);
        }
        break;
    case 3:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080090C_chbosskogsdoor);
        ((f32 *)param_0->actorData)[2] += 1200.0f * func_800D8FF8();
        if (((f32 *)param_0->actorData)[2] > -220.0f) {
            ((f32 *)param_0->actorData)[2] = -220.0f;
            func_80101FDC(param_0, 4);
        }
        func_800BBCB8((f32 *)param_0->actorData, (f32 *)param_0->actorData, 1.0f, 1, &D_808008B0_chbosskogsdoor);
        break;
    case 4:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080090C_chbosskogsdoor);
        ((f32 *)param_0->actorData)[1] += 1200.0f * func_800D8FF8();
        if (((f32 *)param_0->actorData)[1] > 2480.0f) {
            ((f32 *)param_0->actorData)[1] = 2480.0f;
            func_80101FDC(param_0, 5);
        }
        func_800BBCB8((f32 *)param_0->actorData, (f32 *)param_0->actorData, 1.0f, 1, &D_808008B0_chbosskogsdoor);
        break;
    case 5:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080090C_chbosskogsdoor);
        ((f32 *)param_0->actorData)[2] += 1200.0f * func_800D8FF8();
        if (((f32 *)param_0->actorData)[2] > 0.0f) {
            ((f32 *)param_0->actorData)[2] = 0.0f;
            func_80101FDC(param_0, 6);
        }
        func_800BBCB8((f32 *)param_0->actorData, (f32 *)param_0->actorData, 1.0f, 1, &D_808008B0_chbosskogsdoor);
        break;
    case 6:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_8080090C_chbosskogsdoor);
        ((f32 *)param_0->actorData)[1] -= 1200.0f * func_800D8FF8();
        if (((f32 *)param_0->actorData)[1] < 2204.0f) {
            func_80101FDC(param_0, 7);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800904_chbosskogsdoor);
            _subaddieaudioloop_entrypoint_2(param_0);
        }
        func_800BBCB8((f32 *)param_0->actorData, (f32 *)param_0->actorData, 1.0f, 4, &D_808008B0_chbosskogsdoor);
        break;
    case 7:
        if (func_800D91EC(&param_0->unk58, (f32)param_0->unk74_7 / 10.0f)) {
            func_80101FDC(param_0, 8);
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808008F8_chbosskogsdoor);
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808008E8_chbosskogsdoor);
        }
        break;
    case 9:
        func_80103110(param_0, 0);
        break;
    }
    param_0->position[1] = ((f32 *)param_0->actorData)[7] + func_800F10B4(param_0->unk58, 0.0f,
        (f32)param_0->unk74_7 / 10.0f, 0.0f, func_80103EF4(param_0));
}

s32 func_80800458_chbosskogsdoor(u8 *param_0, s32 param_1, s32 param_2) {
    if (param_1 == 0x49) {
        if (param_2 == 0x40) {
            _capod_entrypoint_13(*(s32 *)param_0, 0, 1, 0x930);
            func_80101FDC(param_0, 2);
            func_800EFA4C(param_0 + 0x18, -7472.0f, 2405.0f, -1.24e+03f);
            *(f32 *)(param_0 + 0x2C) = 5.0f;
            return 1;
        }
        return 0;
    }
    return 0;
}

int *chbosskogsdoor_entrypoint_0()
{
    return &D_80800918_chbosskogsdoor;
}

void func_808004F4_chbosskogsdoor(BossKogsDoor *param_0)
{
  if (func_800DA298(0x1B8))
  {
    func_80102424(param_0, 4);
    param_0->unk74_6 = 1;
  }
  else
  {
    func_80102424(param_0, 1);
  }
}

void func_80800544_chbosskogsdoor(Actor *param_0)
{
    f32 local_0[3];

    switch (param_0->unk70_10) {
    case 1:
        if (param_0->unk64_20) {
            func_80102424(param_0, 2);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800994_chbosskogsdoor);
            *(f32 *)&param_0->actorData[4] = 0.0f;
        } else {
            func_80103110(param_0, 0);
        }
        break;
    case 2:
        if (func_80101E14(param_0, 0.35f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800988_chbosskogsdoor);
        } else if (func_80101E14(param_0, 0.4f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808009A0_chbosskogsdoor);
            func_800BBCB8(param_0->position, NULL, param_0->scale, 4, &D_808009B0_chbosskogsdoor);
        }
        if (func_80101F24(param_0) > 0.4f) {
            func_800EFA4C(local_0, -247.0f, *(f32 *)&param_0->actorData[4] + 150.0f, 1720.0f);
            *(f32 *)&param_0->actorData[4] += 1200.0f * func_800D8FF8();
            func_800BBCB8(local_0, local_0, 1.0f, 2, &D_808008B0_chbosskogsdoor);
        }
        if (func_80101DDC(param_0)) {
            param_0->unk58 = 2.0f;
            func_80102424(param_0, 3);
        }
        break;
    case 3:
    case 4:
        break;
    }
}

s32 func_80800714_chbosskogsdoor(Actor *param_0, s32 param_1, s32 param_2)
{
  switch (param_1) {
    case 0x91:
      if (func_800F64A4(func_800F54E4(), 0x40) != 0) {
        if ((func_800DA298(0xA06) != 0) && (param_0->unk70_10 == 1)) {
          param_0->unk64_20 = 1;
          func_80103110(param_0, 1);
          _capod_entrypoint_13(param_0->unk0, 0, 0x18, 0x810);
          return 1;
        }
      } else if (!param_0->unk74_30) {
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1354, 6, (u8 *)param_0 + 4, 0);
        param_0->unk74_30 = 1;
      }
      return 1;
    case 0x95:
      func_80102424(param_0, param_0->unk70_10);
      func_80102204(param_0);
      return 1;
    case 0xB:
      if (param_2 == 0x18) {
        _capod_entrypoint_14();
        func_80102424(param_0, 4);
        _glcutDll_entrypoint_6(0x10F, 0x40);
        return 4;
      }
      return 3;
    default:
      return 0;
  }
}

int chbosskogsdoor_entrypoint_1()
{
  return &D_808009EC_chbosskogsdoor;
}
