#include "common.h"

extern int D_80800930_chhotwaterpoolbits;
extern int D_80800978_chhotwaterpoolbits;
extern int D_808009C0_chhotwaterpoolbits;
extern s32 D_80800A08_chhotwaterpoolbits[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern u8 D_80800A5C_chhotwaterpoolbits[];
extern u8 D_80800A50_chhotwaterpoolbits[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800F3214(f32 *, void *, void *, f32);
extern u8 D_80800A68_chhotwaterpoolbits[];
extern u8 _chhotwaterpoolbits_entrypoint_4[];
typedef struct { s16 position[3]; u16 flags; s16 uv[2]; u8 color[4]; } HotWaterVertex1805;
extern Actor *func_80106790();
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } PoolS;
extern void func_800FFAB0(PoolS *);
extern void func_800EE7F8();
extern s32 D_80800A88_chhotwaterpoolbits;
extern s32 D_80800AC0_chhotwaterpoolbits;
extern s32 D_80800AD8_chhotwaterpoolbits;
extern f32 func_800F5628(s32);
int func_808003E0_chhotwaterpoolbits();
void func_80800528_chhotwaterpoolbits();
extern void func_80102EC0(), func_80107C2C(), func_8010A730(), func_80800204_chhotwaterpoolbits();

int chhotwaterpoolbits_entrypoint_0()
{
    return (int)&D_80800930_chhotwaterpoolbits;
}

int chhotwaterpoolbits_entrypoint_1()
{
    return (int)&D_80800978_chhotwaterpoolbits;
}

int *chhotwaterpoolbits_entrypoint_2()
{
    return &D_808009C0_chhotwaterpoolbits;
}

s32 chhotwaterpoolbits_entrypoint_3()
{
    return D_80800A08_chhotwaterpoolbits;
}

s32 func_80800030_chhotwaterpoolbits(Actor *this) {
    s32 local_0 = _chswitch_entrypoint_7(this, 0x167);
    _chswitch_entrypoint_8(this, 0x200);
    if(local_0)
        _chswitch_entrypoint_9(this);
}

s32 func_80800078_chhotwaterpoolbits(Actor *param_0, s32 param_1)
{
    if (param_1 == 7) {
        if (!func_800DA298(0x31B)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x12B0, 15, param_0->position, 0);
        } else {
            func_80101180(0x428, param_1, 0);
            func_80101180(0x439, 10, 0x427);
            func_80103110(param_0, 0);
            _chswitch_entrypoint_9(param_0);
        }
    } else {
        return _chswitch_entrypoint_10(param_0);
    }
    return 1;
}

void func_80800124_chhotwaterpoolbits(Actor *param_0)
{
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 300.0f, 0x60, 0x167)) {
        _chdoormake_entrypoint_5(param_0, 2.0f);
        _chdoormake_entrypoint_6(param_0, 0.15f);
        _chdoormake_entrypoint_9(param_0, 0, 0xD, 0x10);
        _chdoormake_entrypoint_8(param_0, 0xD);
    }
}

s32 func_808001A8_chhotwaterpoolbits(s32 param_0, s32 param_1, s32 param_2) {
    if ((param_1 == 0xb) && (param_2 == 0xd)) {
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0x1a7, 0x29);
        func_800FFAB0(param_0);
        return 4;
    }
    return _chdoor_entrypoint_1(param_0);
}

void func_80800204_chhotwaterpoolbits(param_0) s32 param_0;
{
    func_800F2E60(param_0 + 0x28, ((int *) D_80800A50_chhotwaterpoolbits), param_0);
    *(f32 *)((char *)param_0 + 0x1C) = 0.0f;
    *(f32 *)((char *)param_0 + 0x18) = 127.0f;
}

void func_8080024C_chhotwaterpoolbits(Actor *param_0)
{
    switch (param_0->unk70_10) {
        case 2:
            if (func_800D9078(&param_0->unk58)) {
                func_80101FDC(param_0, 3);
                func_80103110(param_0, 0);
            }
            func_800F3214((f32 *)((u8 *)param_0 + 0x28), D_80800A50_chhotwaterpoolbits, D_80800A5C_chhotwaterpoolbits,
                func_800F10B4(param_0->unk58, 0.0f, 4.0f, 1.0f, 0.0f));
            ((f32 *)param_0->actorData)[1] = 0.0;
            break;
        case 3:
            func_800F2E60((u8 *)param_0 + 0x28, D_80800A5C_chhotwaterpoolbits);
            ((f32 *)param_0->actorData)[1] = 0.0;
            ((f32 *)param_0->actorData)[0] = 100.0f;
            break;
        case 4:
            if (func_800D9078(&param_0->unk58)) {
                func_80101FDC(param_0, 3);
                func_80103110(param_0, 0);
            }
            ((f32 *)param_0->actorData)[1] = func_800F12D4(param_0->unk58, 0.0f, 10.0f, -800.0f, 0.0f);
            ((f32 *)param_0->actorData)[0] = func_800F12D4(param_0->unk58, 0.0f, 10.0f, 100.0f, 127.0f);
            func_800F2E60((u8 *)param_0 + 0x28, D_80800A5C_chhotwaterpoolbits);
            break;
        case 5:
            func_800F2E60((u8 *)param_0 + 0x28, D_80800A5C_chhotwaterpoolbits);
            ((f32 *)param_0->actorData)[0] = 100.0f;
            ((f32 *)param_0->actorData)[1] = -800.0f;
            func_800FFAB0(param_0);
            break;
    }
    func_80800528_chhotwaterpoolbits(param_0);
}

int func_808003E0_chhotwaterpoolbits(param_0, param_1, param_2) s32 param_0; s32 param_1; u32 param_2;
{
  switch (param_1)
  {
    case 0xA :
      if (param_2 == 0x3E7)
    {
      func_80101FDC(param_0, 2);
      func_80103110(param_0, 1);
      (*(f32 *)((char *)(param_0) + 0x58)) = 4.0f;
    }
    else
    {
      _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, D_80800A68_chhotwaterpoolbits);
      func_80101FDC(param_0, 4);
      func_80103110(param_0, 1);
      (*(f32 *)((char *)(param_0) + 0x58)) = 10.0f;
    }

      break;

    case 0x95 :
      if (func_800DA298(0x167))
    {
      func_800F2E60(param_0 + 0x28, D_80800A5C_chhotwaterpoolbits);
      (*(f32 *)((char *)(param_0) + 0x18)) = 100.0f;
      (*(f32 *)((char *)(param_0) + 0x1C)) = -800.0f;
      func_800FFAB0(param_0);
    }
    else
    {
      if (func_800DA298(0x31B))
      {
        func_800F2E60(param_0 + 0x28, D_80800A5C_chhotwaterpoolbits);
        (*(f32 *)((char *)(param_0) + 0x1C)) = 0.0f;
        (*(f32 *)((char *)(param_0) + 0x18)) = 100.0f;
        func_80101FDC(param_0, 3);
      }
    }
    func_80800528_chhotwaterpoolbits(param_0);
    return 1;

    default :
      return 0;

  }


  return 1;
}

void func_80800528_chhotwaterpoolbits(param_0) s32 *param_0; {
    s32 local_0;

    local_0 = func_800BEA88(1);
    if (local_0 != 0) {
        _glid_entrypoint_0(local_0, 0xA, &_chhotwaterpoolbits_entrypoint_4, *param_0);
    }
}

void chhotwaterpoolbits_entrypoint_4(void *param_0, HotWaterVertex1805 *param_1, HotWaterVertex1805 *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    Actor *local_0;
    u8 local_1;
    s16 local_2;
    s32 local_3;
    HotWaterVertex1805 *local_7;
    local_0 = func_80106790(param_4);
    local_1 = (u8)*(f32 *)((u8 *)local_0 + 0x18);
    local_2 = *(f32 *)((u8 *)local_0 + 0x1C);
    local_7 = param_2 + param_3;
    for (; param_2 < local_7; param_1++, param_2++) {
        for (local_3 = 0; local_3 != 3; local_3++) {
            param_2->color[local_3] = param_1->color[local_3] * ((s32 *)((u8 *)local_0 + 0x28))[local_3] >> 8;
        }
        param_2->color[3] = local_1;
        param_2->position[1] = param_1->position[1] + local_2;
    }
}

void func_808006BC_chhotwaterpoolbits(PoolS *param_0) {
    if (param_0->f76 == 0x33 && func_800DA298(0x31B)) {
        func_800FFAB0(param_0);
    } else {
        func_800EE7F8((u8 *)param_0 + 0x18, (u8 *)param_0 + 4);
    }
}

void chhotwaterpoolbits_entrypoint_5();

void func_80800718_chhotwaterpoolbits(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_4;
    f32 local_3[3];
    switch (param_0->unk70_10) {
    case 1:
        local_0 = func_800F54E4();
        if (func_800F6A38(local_0)) {
            local_1 = func_800F5C94(local_0);
            local_2 = func_800F5D18(local_0);
            local_4 = func_800F64A4(local_0, 2);
            if (local_1 != 0xC && local_1 != 0xE && (local_2 || local_4) && func_800D9078((u8 *)param_0 + 0x58)) {
                func_800F7D90(local_0, 0x52, param_0->actorData, 1);
                func_80101FDC(param_0, 2);
                chhotwaterpoolbits_entrypoint_5(param_0, 0x3F800000);
                *(f32 *)((u8 *)param_0 + 0x58) = 1.0f;
            }
        } else {
            func_800F5A00(local_0, local_3);
            local_3[1] = func_800F5628(local_0);
            if (func_800F55FC(local_0) & 0x08000000) func_800EE7F8(param_0->actorData, local_3);
            *(f32 *)((u8 *)param_0 + 0x58) = 0.04f;
        }
        return;
    case 2:
        if (func_800D9078((u8 *)param_0 + 0x58) && func_800F5578(func_800F54E4()) > 0) {
            func_80101FDC(param_0, 1);
            *(f32 *)((u8 *)param_0 + 0x58) = 0.04f;
        }
        break;
    }
}

void chhotwaterpoolbits_entrypoint_5(s32 param_0, s32 param_1) {
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;

    sp24 = func_800F54E4();
    func_800F7620(sp24, 0x3F800000, 0x3F000000, 0x3ECCCCCD);
    func_800F5A00(sp24, sp28);
    func_800EE780(sp34, sp28, &D_80800AD8_chhotwaterpoolbits);
    func_800BABB8(0, sp28, sp34, param_1, &D_80800A88_chhotwaterpoolbits);
    _subaddieaudioquick_entrypoint_2(param_0, sp28, &D_80800AC0_chhotwaterpoolbits);
}
