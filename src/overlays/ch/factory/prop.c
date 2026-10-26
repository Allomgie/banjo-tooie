#include "common.h"
#include "types.h"
#include "macros.h"

extern int D_80800C20_chfactoryprop;
extern void *D_80800C68_chfactoryprop;
extern int D_80800CB0_chfactoryprop;
extern void _subaddiefade_entrypoint_14(void);
extern void func_8010A63C(void *param_0);
typedef struct { s32 unk0; int unk4; int unk8; int unkC; int unk10; int unk14; int unk18; int unk1C; int unk20; int unk24; f32 unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C; int unk40; f32 unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C; int unk60; int unk64; int unk68; s32 unk6C; s16 unk70; u16 unk72; } ChFactoryProp;
extern void _glid_entrypoint_0(void *param_0, int param_1, f32 *param_2, void *param_3);
extern void _subaddieaudioloop_entrypoint_2(ChFactoryProp *param_0);
extern f32 func_800136E4(f32 param_0);
extern f32 func_800D8FF8(void);
extern void func_80101FDC(ChFactoryProp *param_0, int param_1);
extern s32 func_801065A4(ChFactoryProp *param_0);
extern void _chfactoryprop_entrypoint_3(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern u8 D_80800D24_chfactoryprop[];
extern s32 func_800DB9B0(void);
extern void func_8008FE68(f32 *);
extern void func_800E3980(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800C4350();
extern s32 func_800EA05C(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C3058();
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_800907C0(f32 *);
extern u8 D_80800CF8_chfactoryprop[];
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800D08_chfactoryprop[];
extern u8 D_80800D14_chfactoryprop[];
extern f32 func_800DC178(f32, f32);
extern void func_800C31DC(s32, f32);
extern void func_800C4B64(f32);
extern s32 func_800D9154(f32 *, f32);
void func_80800988_chfactoryprop();
void func_80800324_chfactoryprop();
void func_80800674_chfactoryprop();

int chfactoryprop_entrypoint_0()
{
  return (int)&D_80800C20_chfactoryprop;
}

int chfactoryprop_entrypoint_1()
{
  return &D_80800C68_chfactoryprop;
}

int *chfactoryprop_entrypoint_2()
{
    return &D_80800CB0_chfactoryprop;
}

void func_80800024_chfactoryprop(void *param_0)
{
  char *new_var;
  *((float *) (((char *) param_0) + 0x34)) = 1.0f;
  new_var = (char *) param_0;
  *((float *) (new_var - (-(0x24 & 0xFFFFFFFFFFFFFFFFu)))) = 1.0f;
  _subaddiefade_entrypoint_14();
  func_8010A63C(param_0);
  *((float *) (new_var + 0x44)) = 30.0f;
  if (!param_0)
  {
  }
}

void func_80800070_chfactoryprop(ChFactoryProp *param_0)
{
  f32 sp24;
  f32 temp_f0;
  u32 temp_t9;
  sp24 = func_800D8FF8();
  if (param_0->unk28 > 0.0f)
  {
    if ((((u32) (param_0->unk6C << 0xB)) >> 0x14) == 0x3B2)
    {
      func_80800674_chfactoryprop(param_0);
    }
    else
    {
      func_80800988_chfactoryprop(param_0);
    }
  }
  else
  {
    _subaddieaudioloop_entrypoint_2(param_0);
  }
  temp_t9 = (u16) param_0->unk72;
  temp_t9 = temp_t9 >> 0xA;
  switch (temp_t9)
  {
    case 1:
      param_0->unk44 = func_800136E4((param_0->unk28 * sp24) + param_0->unk44);
      func_80800324_chfactoryprop(param_0);
      break;

    case 2:
      temp_f0 = func_800F15F8(param_0->unk28, 0, 40.0f * sp24);
      param_0->unk28 = temp_f0;
      param_0->unk44 = func_800136E4((temp_f0 * sp24) + param_0->unk44);
      if (param_0->unk28 == 0.0f)
    {
      func_80101FDC(param_0, 3);
    }
      break;

  }

  temp_t9 = func_801065A4(param_0);
  if (temp_t9 != 0)
  {
    _glid_entrypoint_0(func_801065A4(param_0), 1, &_chfactoryprop_entrypoint_3, param_0->unk0);
  }
}

void func_808001D8_chfactoryprop(u8 *param_0)
{
    *(u8 *)((char *)param_0 + 0x18) = _subaddieaudioloop_entrypoint_3(*(u8 *)((char *)param_0 + 0x18));
    *(u8 *)((char *)param_0 + 0x1C) = _subaddieaudioloop_entrypoint_3(*(u8 *)((char *)param_0 + 0x1C));
}

s32 func_80800214_chfactoryprop(u8 *param_0, s32 param_1, s32 param_2) {
    switch (param_1) {                                 
    case 0x49:
        if (_glcutDll_entrypoint_19(0x45) == 0) {
            return 0;
        } else {
            func_80101FDC(param_0, 2);
            if (((u32) ((*(s32 *)((s8 *)(param_0) + (0x6C))) << 0xB) >> 0x14) == 0x3B2) {
                _capod_entrypoint_13((*(s32 *)((s8 *)(param_0) + (0))), 0, 3, 0x2910);
            }
        }
        break;
    case 0x4F:
        func_80101FDC(param_0, 2);
        break;
    case 0x95:
        (*(s8 *)((s8 *)(param_0) + (0x1C))) = 0;
        (*(s8 *)((s8 *)(param_0) + (0x18))) = 0;
        if ((func_800DA298(0x18C) != 0) && (_glcutDll_entrypoint_19(0x45) == 0) && (_glcutDll_entrypoint_20() == 0)) {
            func_80101FDC(param_0, 3);
            (*(f32 *)((s8 *)(param_0) + (0x28))) = 0.0f;
        } else {
            (*(f32 *)((s8 *)(param_0) + (0x28))) = 400.0f;
            (*(f32 *)((s8 *)(param_0) + (0x2C))) = 0.0f;
        }
        break;
    }
    return 0;
}

void func_80800324_chfactoryprop(param_0) Actor *param_0;
{
    f32 local_1[3];
    f32 local_0[3];
    f32 local_4;
    f32 local_2;
    f32 local_3;
    s32 local_5;
    s32 local_6;
    if (param_0->unk6C_9 != 0x3B2) return;
    func_8008FE68(local_0);
    if (local_0[2] > 1700.0f || local_0[2] < -1700.0f) return;
    local_4 = local_0[0] - param_0->position[0];
    if (local_4 <= -100.0f) local_2 = func_800F10B4(local_4, -500.0f, -100.0f, 0.0f, 800.0f);
    else local_2 = func_800F10B4(local_4, -100.0f, 4000.0f, 800.0f, 0.0f);
    local_3 = func_800D8FF8();
    *(f32 *)&param_0->actorData[5] = func_800F15F8(*(f32 *)&param_0->actorData[5], 0.0f, local_3 * 400.0f);
    if (local_0[0] < 1300.0f && local_0[0] > 0.0f && local_0[1] < param_0->position[1]) *(f32 *)&param_0->actorData[5] = 600.0f;
    func_80090794(local_1);
    func_800EF1B8(local_1, 90.0f, (*(f32 *)&param_0->actorData[5] + local_2) * local_3);
    func_800907C0(local_1);
    local_5 = *(f32 *)&param_0->actorData[5] + local_2 > 240.0000153f;
    if (local_5 || (!local_5 && *((u8 *)param_0 + 0x1C))) {
        local_6 = func_800F10B4(*(f32 *)&param_0->actorData[5] + local_2, 0.0f, 800.0f, 8000.0f, 22000.0f);
        *((u8 *)param_0 + 0x1C) = _subaddieaudioloop_entrypoint_7(*((u8 *)param_0 + 0x1C), local_0, local_5, D_80800CF8_chfactoryprop, *(u32 *)((u8 *)param_0 + 0x70) & 1);
        if (*((u8 *)param_0 + 0x1C) != 0) func_800C3058(*((u8 *)param_0 + 0x1C), local_6);
    }
}

void chfactoryprop_entrypoint_3(void *param_0, void *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    f32 local_0;
    Vtx *local_1;
    u8 local_2;

    local_0 = func_800F12D4(*(f32 *)&func_80106790(param_4)->actorData[4], 0.0f, 160.0f, 0, 64.0f);
    local_1 = param_2 + param_3;
    if (param_2 < local_1) {
        local_2 = local_0;
        do {
            param_2->v.cn[3] = local_2;
            param_2++;
        } while (param_2 < local_1);
    }
}

void func_80800674_chfactoryprop(param_0) Actor *param_0;
{
    f32 local_0;
    Vec3f local_1;
    f32 local_4;
    f32 *local_5;
    s32 local_2;
    s32 local_3;

    if (!func_800DB9B0()) {
        local_3 = func_800F55FC(func_800F54E4());
        func_8008FE68(local_1.f);
        if (local_3 & 0x08000000) {
            ((f32 *)param_0->actorData)[7] = 0.3f;
        } else if (local_3 & 0x30000000) {
            ((f32 *)param_0->actorData)[7] = func_800F10B4(local_1.pos.z, -1200.0f, -2400.0f, 1.0f, 0.3f);
        } else {
            ((f32 *)param_0->actorData)[7] = 1.0f;
        }
    } else {
        ((f32 *)param_0->actorData)[7] = 1.0f;
        func_800E3980(local_1.f);
    }
    ((f32 *)param_0->actorData)[3] = func_800F15F8(((f32 *)param_0->actorData)[3],
        ((f32 *)param_0->actorData)[7], func_800D8FF8());
    local_4 = param_0->position[0] - local_1.pos.x;
    if (local_4 < 0.0f) {
        local_2 = func_800F10B4(local_4, 0.0f, -8000.0f, 32767.0f, 14000.0f);
    } else {
        local_2 = func_800F10B4(local_4, 0.0f, 2000.0f, 32767.0f, 0);
    }
    if (param_0->unk5F == 0) {
        param_0->unk5F = func_800C4350(0, param_0->position, D_80800D08_chfactoryprop);
    }
    local_5 = param_0->position;
    local_0 = func_800F12D4(((f32 *)param_0->actorData)[4], 0.0f, 400.0f, 0.4f, 1.0f);
    local_2 *= ((f32 *)param_0->actorData)[3] *
        func_800F12D4(((f32 *)param_0->actorData)[4], 0.0f, 400.0f, 0.4f, 1.0f);
    func_800C31DC(param_0->unk5F, local_0);
    func_800C3058(param_0->unk5F, local_2);
    func_800C4350(param_0->unk5F, local_5, NULL);
    if (func_800D9154((f32 *)&param_0->actorData[6],
        func_800F10B4(((f32 *)param_0->actorData)[4], 0.0f, 400.0f, 0.8f, 0.3f)) &&
        ((f32 *)param_0->actorData)[4] > 80.0f && local_2 != 0) {
        if (*(u8 *)param_0->actorData == 0) {
            *(u8 *)param_0->actorData = _subaddieaudioquick_entrypoint_1(param_0, local_5);
        }
        local_0 = func_800F12D4(((f32 *)param_0->actorData)[4], 0.0f, 400.0f, 0.2f, 0.5f) + func_800DC178(-0.05f, 0.05f);
        func_800C4B70((s32)(((f32 *)param_0->actorData)[3] * local_2));
        func_800C4B64(local_0);
        func_800C4350(*(u8 *)param_0->actorData, local_5, D_80800D14_chfactoryprop);
    }
}

void func_80800988_chfactoryprop(param_0) Actor *param_0;
{
#define P (*(Actor **)&param_0)
    f32 local_0[3];
    f32 local_1[3];
    f32 local_3;
    s32 local_2;

    if (!func_800DB9B0()) {
        func_8008FE68(local_1);
    } else {
        func_800E3980(local_1);
    }
    func_800EE7F8(local_0, P->position);
    local_0[0] = local_1[0];
    if (P->unk5F == 0) {
        P->unk5F = func_800C4350(0, local_0, D_80800D24_chfactoryprop);
    }
    switch (func_800EA05C()) {
    case 0x10F:
        local_3 = -1200.0f - local_1[0];
        if (local_3 < 0) {
            local_2 = func_800F10B4(local_3, 0.0f, -800.0f, 20000.0f, 0.0f);
        } else {
            local_2 = 20000;
        }
        break;
    case 0x110:
        local_3 = P->position[1] - local_1[1];
        if (0 < local_3) {
            local_2 = func_800F10B4(local_3, 0.0f, 4000.0f, 20000.0f, 0.0f);
        } else {
            local_2 = 20000;
        }
        break;
    }
    local_2 *= func_800F12D4(((f32 *)P->actorData)[4], 0.0f, 400.0f, 0.4f, 1.0f);
    func_800C3058(P->unk5F, local_2);
    func_800C4350(P->unk5F, local_0, NULL);
}

void func_80800B44_chfactoryprop(Actor *param_0)
{
    func_8010A63C(param_0);
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 200.0f, 0x20, 0x18C)) {
        _chdoormake_entrypoint_6(param_0, 2.25f);
        _chdoormake_entrypoint_12(param_0, 0, 0x45);
        _chdoormake_entrypoint_8(param_0, 0xC);
    }
    if (func_800DA298(0x18C) && !_glcutDll_entrypoint_19(0x45)) func_800FFAB0(param_0);
}
