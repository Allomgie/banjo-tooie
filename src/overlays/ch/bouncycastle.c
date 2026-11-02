#include "common.h"

extern int D_80800930_chbouncycastle;
extern int D_80800978_chbouncycastle;
extern int D_808009C0_chbouncycastle;
extern s32 D_80800A08_chbouncycastle[];
typedef struct { u8 pad_0[0x70]; u32 pad_5 : 7; u32 active : 1; u32 pad_6 : 2; u32 triggered : 1; u32 pad_7 : 21; u32 pad_8; u32 pad_1 : 8; u32 kind : 4; u32 pad_2 : 20; u32 pad_3 : 19; u32 done : 1; u32 pad_4 : 12; } BounceCastleFlags29;
extern void *func_801039E4(Unk80132ED0 *);
extern void *func_80104248(Actor *, void *);
extern void *func_80100094(Actor *, u32);
typedef struct { s32 local_0; } BounceTransform;
typedef struct { u8 pad_0[0x28]; s32 local_0; } BounceRenderTransform;
extern void _chbouncycastle_entrypoint_4(void);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern void *func_80103AA0(Unk80132ED0 *);
extern void func_80102424();
typedef struct { u8 pad_0[0x74]; u32 pad_1 : 9; u32 local_0 : 1; u32 pad_2 : 22; } BounceCastleUpdateFlags;
typedef struct { u8 pad[0x76]; u16 hi : 9; u16 lo : 7; } BccBits;
extern void func_80101EE4(Actor *, f32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
typedef struct { u8 pad_0[4]; f32 local_0[3]; s32 local_1; s32 local_2; } BounceCastleCheckpoint;
extern s32 func_800BF744(s32, s32);
extern s32 func_8010D278(s32);
extern s32 D_80800A5C_chbouncycastle[];
extern u8 D_80800A50_chbouncycastle[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C3868(u8, f32, f32, f32, f32);
void func_8080051C_chbouncycastle();

int chbouncycastle_entrypoint_0()
{
    return (int)&D_80800930_chbouncycastle;
}

int chbouncycastle_entrypoint_1()
{
    return (int)&D_80800978_chbouncycastle;
}

int chbouncycastle_entrypoint_2(void)
{
    return (int)&D_808009C0_chbouncycastle;
}

int chbouncycastle_entrypoint_3()
{
  return (int)D_80800A08_chbouncycastle;
}

void chbouncycastle_entrypoint_4(Actor *param_0)
{
  s32 pad0;
    u8 *local_0;
    s32 *local_1;
    void *local_2;
    local_0 = func_801039E4(param_0->unk0);
    local_1 = func_80100094(param_0, 0);
    func_80103D48(param_0);
    *local_1 = *(s32 *)(local_0 + 0x28);
    if (*(s16 *)((u8 *)param_0 + 0x8C) && (param_0->unk70_10 == 2 || ((BounceCastleFlags29 *)param_0)->kind)) {
        local_2 = func_80104248(param_0, local_0);
        func_8008B304(local_2);
        func_800DF41C(func_8008B4D4(local_2));
    } else {
        *(s32 *)(local_0 + 0x28) = 0;
    }
    if (((BounceCastleFlags29 *)param_0)->kind != 1 && (((BounceCastleFlags29 *)param_0)->active || ((BounceCastleFlags29 *)param_0)->triggered)) func_800DF818(func_80103CDC(param_0, local_0));
    func_800DF830(1);
    func_80103D70(param_0);
    ((BounceCastleFlags29 *)param_0)->done = 1;
}

void func_80800148_chbouncycastle(u8 **param_0) {
    s32 local_0;

    local_0 = func_801065A4();
    if (local_0 != 0) {
        _glidmake_entrypoint_4(local_0);
    }
    func_8010647C(param_0, _glidmake_entrypoint_5(*(u16 *)((char *)*param_0 + 0x14), 0));
}

void func_80800198_chbouncycastle(Actor *param_0, s32 param_1)
{
    BounceTransform *local_0;
    local_0 = func_80100094(param_0, 0);
    func_800DF47C(_chbouncycastle_entrypoint_4, param_0);
    func_800DE448(0, 0, param_0->scale, 0, func_8010347C(param_0->unk0));
    if (param_0->unk7C_12) {
        ((BounceRenderTransform *)func_80103AA0(param_0->unk0))->local_0 = local_0->local_0;
        if (param_0->unk79_4) {
            param_0->unk79_4--;
            if (!param_0->unk79_4) func_80800148_chbouncycastle(param_0);
        }
    }
}

void func_80800254_chbouncycastle(Actor *param_0)
{
    s32 local_0;

    local_0 = param_0->unk70_10;
    if (local_0 == 2) {
        func_8080051C_chbouncycastle();
        if (func_80101DDC(param_0)) {
            func_80102424(param_0, 3);
            func_800DA544(0xB2);
            param_0->unk79_4 = 3;
        }
        local_0 = param_0->unk70_10;
    }
    if (local_0 == 2 || param_0->unk79_4) {
        ((BounceCastleUpdateFlags *)param_0)->local_0 = 1;
    } else {
        ((BounceCastleUpdateFlags *)param_0)->local_0 = 0;
    }
}

s32 func_80800308_chbouncycastle(Actor *param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    Actor *local_2;

    switch (param_1) {
    case 0xB:
        if (param_2 == 1) {
            _capod_entrypoint_14();
            _capod_entrypoint_13(param_0->unk0, 0, 0xA, 0x2910);
            func_80108B04(param_0, 0x210);
            return 4;
        }
        return 3;
    case 0x49:
        if (param_2 == 0x20) {
            func_80102424(param_0, 2);
            func_80101EE4(param_0, 0.21590909f);
            param_0->unk79_4 = 0;
            _capod_entrypoint_13(param_0->unk0, 0, 1, 0x2830);
            break;
        }
        return 0;
    case 0x3D:
        local_0 = func_80100094(param_0, 0);
        local_2 = func_80108528(0x210, (f32 *)(local_0 + 4), (s32)*(f32 *)(local_0 + 0x14), &param_0);
        ((BccBits *)local_2)->hi = *(s32 *)(local_0 + 0x10);
        _chappearfx_entrypoint_1(local_2, 0x22, 1, 1.0f);
        return 1;
    default:
        return 0;
    }
    return 1;
}

void func_8080045C_chbouncycastle(Actor *param_0)
{
    BounceCastleCheckpoint *local_0;

    local_0 = (BounceCastleCheckpoint *)func_80100094(param_0, 0);
    _subaddiemarker_entrypoint_0(param_0, 0x154, local_0->local_0, 1);
    if (!func_800DA298(0xB2)) {
        func_80102424(param_0, 1);
        func_80101EE4(param_0, 0.2159091f);
    } else {
        func_80108A30(0x210, local_0->local_0, local_0->local_2, local_0->local_1);
        func_80102424(param_0, 3);
    }
    param_0->unk79_4 = 3;
    if (func_800EA05C() != 0xE1) func_8010A624(param_0);
}

void func_8080051C_chbouncycastle(Actor *param_0)
{
    s32 local_0;
    s32 *local_1;
    f32 local_2;
    u8 local_3;
    s32 local_4 = 4;
    for (local_0 = 0, local_1 = D_80800A5C_chbouncycastle; local_0 < local_4; local_0++, local_1++) {
        if (func_80101E14(param_0, *local_1)) {
            local_2 = func_800F10B4((f32)local_0, 0.0f, (f32)(local_4 - 1), 0.3f, 0.5f);
            local_3 = _subaddieaudioquick_entrypoint_1(param_0, param_0->position);
            func_800C3868(local_3, 0.15f, 0.25f, local_2, local_2 + 0.12f);
            func_800C4350((u8)(s32)local_3, param_0->position, D_80800A50_chbouncycastle);
        }
    }
}

void func_80800670_chbouncycastle(s32 param_0[3])
{
  s32 local_0;
  local_0 = func_800CBDD4(&param_0[1], 0x64, 1);
  param_0[10] = local_0;
  if (local_0 != (-1))
  {
    func_800CBB80(param_0[10], func_800DA298(0xB2) | 0);
  }
}

int func_808006C4_chbouncycastle(Actor *param_0)
{
  u16 local_0;
  local_0 = *((u16 *) (((char *) param_0) + 0x72));
  switch ((local_0 & 0xFFFFu) >> 10)
  {
    case 2:
      if (func_800D9078((void *) (((char *) param_0) + 0x58)))
    {
      func_800D1000(0x19, 1, 0, 1, 0);
      func_80101FDC(param_0, 1);
    }
      break;

    case 3:
      if (func_800D9078((void *) (((char *) param_0) + 0x58)))
    {
      func_800D1000(0x15, 1, 0, 1, 0);
      func_80101FDC(param_0, 1);
    }
      break;

  }

}

int func_80800774_chbouncycastle(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  Actor *local_1 = param_0;
  if (param_1 == 0x49)
  {
    if (_glcutDll_entrypoint_19(0x22))
    {
      _capod_entrypoint_13(local_1->unk0, 0, 0xF, 0x2910);
      func_80101FDC(local_1, 2);
      local_1->unk58 = 0.15f;
      return 1;
    }
    if (_glcutDll_entrypoint_19(0x21))
    {
      _capod_entrypoint_13(local_1->unk0, 0, 0xC, 0x2910);
      func_80101FDC(local_1, 3);
      local_1->unk58 = 0.15f;
      return 1;
    }
  }
  return 0;
}

void func_80800828_chbouncycastle(s32 arg0) 
{
}
s32 func_80800830_chbouncycastle(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    if (param_1 == 0x95) {
        local_0 = param_0->unk6C_9 == 0x3C7 ? 1 : 0xB;
        local_1 = param_0->unk6C_9 == 0x3C7 ? 2 : 1;
        if (func_8010D278(local_1) == local_0) {
            func_800BF744(local_1, 0);
            func_8010A624(param_0);
            param_0->unk64_16 = 0;
            return 1;
        }
        func_800BF744(local_1, 1);
        return 1;
    }
    return 0;
}
