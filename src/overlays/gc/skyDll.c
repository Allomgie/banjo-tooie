#include "common.h"

extern u8 D_80800510_gcskyDll[];
typedef struct { s32 unk0; s16 model; s16 pad6; f32 unk8; f32 unkC; } SkyDef;
typedef struct { s32 a; s32 b; } SkyPair;
typedef struct { s32 v[4]; } SkyQuad;
typedef struct { s32 unk0[2]; s32 unk8[2]; s32 unk10[2]; s32 unk18[2]; SkyPair pair20[2]; SkyQuad quad30[16]; u8 pad130_[0]; } SkyStateHead;
typedef struct { s32 unk0[2]; s32 unk8[2]; s32 unk10[2]; s32 unk18[2]; SkyPair pair20[2]; u8 pad30[0xF0]; f32 unk120[2]; f32 unk128[2]; f32 unk130; f32 unk134; s32 unk138[2]; } SkyState;
extern s32 func_800EA05C(void);
extern void func_800EFD24(f32 *);
extern void func_800D70D0(s32);
extern void func_800D71F4(s32);
extern s32 func_800B274C(s32);
extern s32 _glidmake_entrypoint_5(s32, s32);
extern void _idworldmake_entrypoint_0(s32, s32);
extern s32 func_800DBFF8(void);
extern s32 func_800B2840(s32);
extern void func_800B2198(s32, s32 *, s32 *);
extern f32 mlAbsF(f32);
extern void func_800D5B24(void);
extern s32 func_800B2400(s32, s32);
extern void func_800BFCD0(s32, s32);
extern f32 func_800EEF94(f32 *);
typedef struct { u8 pad_0[4]; s16 local_0; u8 pad_1[10]; } SkyLayerRecord;
typedef struct { u8 pad_0[0x18]; void *local_0[2]; } SkyTextureState;
extern void *func_800D674C(s32);
extern void *func_800B27FC(void *);
extern void * _dbtex_entrypoint_0(void *);

int func_80800000_gcskyDll(s32 param_0)
{
    s32 local_0;
    u8 *local_1 = &D_80800510_gcskyDll[0];
    while ((*(s16 *)((char *)(local_1) + 0x0)) != 0)
    {
        if (param_0 == (*(s16 *)((char *)(local_1) + 0x0)))
        {
            return local_1;
        }
        local_1 += 0x24;
    }

    return local_1;
}

void gcskyDll_entrypoint_0(u8 *param_0)
{
  s32 local_0;
  s32 local_2;
  s32 local_4;
  s32 local_5;
  s32 local_6;
  unsigned int local_7;
  u8 *local_8;
  u8 *local_1;
  u8 *local_3;
  local_6 = func_80800000_gcskyDll(func_800EA05C());
  local_7 = 0;
  local_1 = param_0;
  local_3 = param_0;
  do
  {
    local_0 = *((s32 *) (local_1 + 0x0));
    if (local_0 != 0)
    {
      func_800DBFD8(local_0);
      *((s32 *) (local_1 + 0x0)) = 0;
    }
    local_2 = *((s32 *) (local_1 + 0x8));
    if (local_2 != 0)
    {
      _glidmake_entrypoint_4(local_2);
      *((s32 *) (local_1 + 0x8)) = 0;
    }
    local_4 = *((s32 *) (local_1 + 0x18));
    if (local_4 != 0)
    {
      _dbtex_entrypoint_1(local_4);
      *((s32 *) (local_1 + 0x18)) = 0;
    }
    local_5 = *((s32 *) (local_3 + 0x24));
    if (local_5 != 0)
    {
      func_800B23E0(local_5);
      *((s32 *) (local_3 + 0x24)) = 0;
    }
    *((s32 *) (local_3 + 0x20)) = 0;
    local_8 = local_6 + (local_7 * 0x10);
    if ((*((s32 *) (local_1 + 0x10))) != 0)
    {
      func_800D70F8(*((s16 *) (local_8 + 0x4)), 0);
      func_800D721C(*((s16 *) (local_8 + 0x4)), 0);
      func_800D6CEC(*((s16 *) (local_8 + 0x4)));
      *((s32 *) (local_1 + 0x10)) = 0;
    }
    local_7 += 1;
    local_1 += 4;
    local_3 += 8;
  }
  while (local_7 != 2);
}

void gcskyDll_entrypoint_1(SkyState *param_0)
{
    SkyDef *local_3;
    f32 local_0[3];
    s32 local_4;
    s32 local_5;
    s32 local_1[3];
    s32 local_2[3];

    local_3 = func_80800000_gcskyDll(func_800EA05C());
    func_800EFD24(local_0);
    for (local_4 = 0; local_4 < 2; local_4++) {
        param_0->unk8[local_4] = 0;
        param_0->unk10[local_4] = 0;
        param_0->unk0[local_4] = 0;
        param_0->pair20[local_4].a = 0;
        param_0->pair20[local_4].b = 0;
        param_0->unk138[local_4] = 0;
        if (local_3[local_4].model == 0) {
            continue;
        }
        param_0->unk10[local_4] = func_800D674C(local_3[local_4].model);
        if (param_0->unk18[local_4] == 0) {
            param_0->unk18[local_4] = _dbtex_entrypoint_0(func_800B27FC(param_0->unk10[local_4]));
        }
        func_800D70D0(1);
        func_800D71F4(1);
        if (func_800B274C(param_0->unk10[local_4])) {
            param_0->unk8[local_4] = _glidmake_entrypoint_5(local_3[local_4].model, 0);
            _idworldmake_entrypoint_0(param_0->unk8[local_4], 3);
        }
        param_0->unk0[local_4] = func_800DBFF8();
        param_0->pair20[local_4].a = func_800B2840(param_0->unk10[local_4]);
        func_800B2198(param_0->pair20[local_4].a, local_1, local_2);
        local_1[0] = mlAbsF(local_1[0]);
        local_1[1] = mlAbsF(local_1[1]);
        local_1[2] = mlAbsF(local_1[2]);
        local_2[0] = mlAbsF(local_2[0]);
        local_2[1] = mlAbsF(local_2[1]);
        local_2[2] = mlAbsF(local_2[2]);
        for (local_5 = 0; local_5 < 3; local_5++) {
            if (local_0[local_5] < local_1[local_5]) {
                local_0[local_5] = local_1[local_5];
            }
            if (local_0[local_5] < local_2[local_5]) {
                local_0[local_5] = local_2[local_5];
            }
        }
        param_0->unk128[local_4] = local_3[local_4].unk8;
        param_0->unk120[local_4] = local_3[local_4].unkC;
        if (local_3[local_4 + 1].unk0) {
            func_800D5B24();
            param_0->pair20[local_4].b = func_800B2400(param_0->pair20[local_4].a, 1);
        }
    }
    for (local_4 = 0; local_4 < 60; local_4++) {
        ((s32 *)((u8 *)param_0 + 0x30))[local_4] = 1;
    }
    func_800BFCD0(1, 1);
    param_0->unk130 = (s32)func_800EEF94(local_0) + 100;
    param_0->unk134 = 0.0f;
}

void gcskyDll_entrypoint_2(SkyTextureState *param_0, s32 param_1)
{
    SkyLayerRecord *local_0;
    s32 local_1;
    local_0 = func_80800000_gcskyDll(param_1);
    for (local_1 = 0; local_1 < 2; local_1++) {
        if (local_0[local_1].local_0) {
            func_800D5B24();
            param_0->local_0[local_1] = _dbtex_entrypoint_0(func_800B27FC(func_800D674C(local_0[local_1].local_0)));
        }
    }
}

int gcskyDll_entrypoint_3()
{
  s32 local_0;
 do { local_0 = func_800EA05C(); } while (0);
  return func_80800000_gcskyDll(local_0) != 0;
}
