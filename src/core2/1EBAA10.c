#include "common.h"
#include "types.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern float D_8012CFB8[12];
extern u8 D_8012D004[1124];
extern float D_8012CFAC[16];
extern float D_8012CFA4[16];
typedef struct { u8 pad[0x74]; u8 state, type, distance, phase; u8 tail[4]; } LocalEffect;
typedef union { u8 raw[1]; LocalEffect fx[1]; } Union_D_8012CF90;
extern Union_D_8012CF90 D_8012CF90;
extern s32 func_800DC128(s32, s32);
typedef struct { u8 pad0[0x18]; f32 unk18; u8 pad1C[4]; f32 unk20; u8 pad24[8]; f32 unk2C; f32 unk30; u8 pad34[0x40]; u8 unk74; u8 pad75[7]; } S8012CF90;
typedef struct { u8 pad0[0x74]; u8 unk74; u8 pad75; u8 unk76; u8 pad77[5]; } E124_E1720;
typedef struct { f32 local_0[3], local_1[3]; f32 local_2, local_3, local_4, local_5, local_6, local_7, local_8; f32 local_9[16]; u8 local_10, local_11, local_12, local_13, local_14, pad[3]; } EffectE1804;
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F3780(f32, f32 *, s32);
typedef struct { f32 local_0[3], local_1, local_2, local_3; u8 pad0[16]; f32 local_4, local_5; u8 pad1[0x44]; u8 local_6, local_7, local_8, pad2[5]; } EntryE1A58;
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
void func_800E13F0(s32 param_0, f32 param_1);
void func_800E144C(s32 param_0, f32 param_1);
void func_800E146C(s32 param_0, f32 param_1);
void func_800E148C(s32 param_0, f32 param_1, f32 param_2);

void func_800E1120(f32 *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0[3];
    func_800EFA4C(local_0, 0.0f, param_2, 0.0f);
    func_800EF8BC(local_0, local_0, param_1[0]);
    func_800EF934(local_0, local_0, param_1[1]);
    func_800EF04C(param_0, local_0);
}

void func_800E119C(f32 *param_0, f32 *param_1, f32 param_2) {
    f32 sp24[3];
    func_800EFA4C(sp24, 0.0f, 0.0f, param_2);
    func_800EF8BC(sp24, sp24, param_1[0]);
    func_800EF934(sp24, sp24, param_1[1]);
    func_800EF04C(param_0, sp24);
}

void func_800E1218(f32 *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0[3];
    func_800EFA4C(local_0, param_2, 0.0f, 0.0f);
    func_800EF8BC(local_0, local_0, param_1[0]);
    func_800EF934(local_0, local_0, param_1[1]);
    func_800EF04C(param_0, local_0);
}

void func_800E1294(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3) {
    switch (param_0) {
        case 1:
            func_800E1218(param_1, param_2, param_3);
            break;
        case 0:
            func_800E1120(param_1, param_2, param_3);
            break;
        case 2:
            func_800E119C(param_1, param_2, param_3);
            break;
        case 3:
            param_1[1] += param_3;
            break;
    }
}

f32 func_800E1338(s32 param_0)
{
  return *(f32 *)((u8 *)D_8012CFB8 + param_0 * 124);
}

int func_800E1354(s32 param_0)
{
  return D_8012D004[param_0 * 124] != 1;
}

void func_800E1378(s32 param_0)
{
  func_800E13F0(param_0, 30.0f);
  func_800E144C(param_0, 0.65f);
  func_800E148C(param_0, 1000.0f, 2000.0f);
  if (func_800EA068(0x20) != 0)
  {
    func_800E146C(param_0, 0.0f);
    return;
  }
  func_800E146C(param_0, 0.5f);
}

void func_800E13F0(s32 param_0, f32 param_1)
{
  *(f32 *)((u8 *)D_8012CFB8 + param_0 * 124) = param_1;
}

void func_800E1410(s32 param_0, f32 param_1, f32 param_2)
{
  float new_var2;
  f32 local_0;
  u8 *local_1;
  f32 *new_var;
  local_1 = (u8 *) ((param_0 * 0x7C) + D_8012CF90.raw);
  new_var = (f32 *) (local_1 + 0x28);
  local_0 = *new_var;
  new_var2 = local_0 + param_1;
  *((f32 *) (local_1 + 0x24)) = local_0;
  *((f32 *) (local_1 + 0x30)) = param_2;
  *((f32 *) (local_1 + 0x20)) = new_var2;
  *((f32 *) (local_1 + 0x18)) = param_2;
}

void func_800E144C(s32 param_0, f32 param_1)
{
  *(f32 *)((u8 *)D_8012CFAC + param_0 * 124) = param_1;
}

void func_800E146C(s32 param_0, f32 param_1)
{
  *(f32 *)((u8 *)D_8012CFA4 + param_0 * 124) = param_1;
}

void func_800E148C(s32 param_0, f32 param_1, f32 param_2)
{
  f32 *local_0 = (f32 *)((char *)((f32 *) D_8012CF90.raw) + param_0 * 124);
  local_0[3] = param_1;
  local_0[4] = param_2;
}

void func_800E14B8(s32 param_0, f32 *param_1)
{
    func_800EE7F8((f32 *) &D_8012CF90.raw[param_0 * 124], param_1);
    D_8012CF90.raw[param_0 * 124 + 0x76] = 1;
}

void func_800E14F8(s32 param_0, u8 *param_1, s16 param_2)
{
  u8 *new_var;
  u8 *local_0 = (u8 *) (((int *) D_8012CF90.raw));
  local_0 += param_0 * 124;
  new_var = local_0;
  new_var = local_0;
  local_0[120] = param_2;
  rare_memcpy(local_0 + 52, param_1, ((u32) param_2) << 3);
}

s32 func_800E1540(s32 param_0) {
    s32 local_0;
    LocalEffect *local_1;
    for (local_0 = 0; local_0 < 10; local_0++) {
        if (D_8012CF90.fx[local_0].state == 1) break;
    }
    if (local_0 == 10) {
        local_0 = func_800DC128(0, 10);
    }
    local_1 = &D_8012CF90.fx[local_0];
    local_1->type = param_0;
    local_1->state = 2;
    local_1->phase = 0;
    return local_0;
}

s32 func_800E15CC(s32 param_0, f32 param_1, f32 param_2)
{
  s32 local_0;

  local_0 = func_800E1540(param_0);
  func_800E13F0(local_0, param_1);
  func_800E144C(local_0, param_2);
  return local_0;
}

s32 func_800E1610(s32 param_0, f32 param_1, f32 param_2, f32 *param_3)
{
  s32 local_0;
  local_0 = func_800E1540(param_0);
  func_800E13F0(local_0, param_1);
  func_800E144C(local_0, param_2);
  func_800E14B8(local_0, param_3);
  return local_0;
}

s32 func_800E1664(s32 param_0, f32 param_1, f32 param_2, s32 param_3, s32 param_4, s16 param_5) {
    s32 idx;
    S8012CF90 *e;
    idx = func_800E1540(param_0);
    func_800E14F8(idx, param_4, param_5);
    e = &((S8012CF90 *) D_8012CF90.raw)[idx];
    e->unk74 = 4;
    e->unk20 = param_1;
    e->unk30 = 0.0f;
    e->unk18 = param_2;
    if (param_1 >= 0.0f) {
        e->unk2C = 1.0f;
    } else {
        e->unk2C = -1.0f;
    }
    if (param_3 != 0) {
        func_800E14B8(idx, param_3);
    }
    return idx;
}

void func_800E1720(s32 param_0) {
    ((E124_E1720 *) D_8012CF90.raw)[param_0].unk74 = 1;
    ((E124_E1720 *) D_8012CF90.raw)[param_0].unk76 = 0;
}

int func_800E1748()
{
  s32 local_0;
  for (local_0 = 0; local_0 < 10; local_0++)
  {
    func_800E1720(local_0);
  }

}

void func_800E1788(void) {
    s8 *local_0;
    s32 local_1;

    local_0 = ((s32 *) D_8012CF90.raw);
    local_1 = 0;
    do {
        (*(s8 *)((s8 *)(local_0) + (0x74))) = 1;
        (*(f32 *)((s8 *)(local_0) + (0x30))) = 0.0f;
        (*(s8 *)((s8 *)(local_0) + (0x76))) = 0;
        func_800EFD24(local_0);
        func_800E1378(local_1);
        local_1 += 1;
        local_0 += 0x7C;
    } while (local_1 != 0xA);
}

void func_800E1804(void) {
    EffectE1804 *local_0;
    s32 local_1;
    f32 local_2;
    local_2 = func_800D8FF8();
    for (local_1 = 0; local_1 < 10; local_1++) {
        local_0 = &((EffectE1804 *) D_8012CF90.raw)[local_1];
        switch (local_0->local_10) {
        case 2:
            if (local_0->local_6 >= 0.0f) local_0->local_7 = 1.0f;
            else local_0->local_7 = -1.0f;
            local_0->local_10 = 3;
            local_0->local_13 = 0;
            break;
        case 3:
            if (local_0->local_8 != 0.0f) {
                local_0->local_8 = func_800F0E00(0.0f, local_0->local_8 - local_2);
                if (local_0->local_13) local_0->local_6 = func_800F10B4(local_0->local_8, local_0->local_2, 0.0f, local_0->local_5, local_0->local_4);
            } else if (local_0->local_13) {
                local_0->local_6 *= local_0->local_3 * local_0->local_3;
            }
            local_0->local_13 ^= 1;
            local_0->local_7 = -local_0->local_7;
            if (local_0->local_3 != 1 && mlAbsF(local_0->local_6) < 0.001f) func_800E1720(local_1);
            break;
        case 4:
            if (local_0->local_8 < local_0->local_2) {
                local_0->local_8 = func_800F13F0(local_0->local_2, local_0->local_8 + local_2);
                local_0->local_6 = func_800F3780(local_0->local_8 / local_0->local_2, local_0->local_9, local_0->local_14) * local_0->local_4;
                local_0->local_7 = -local_0->local_7;
            } else func_800E1720(local_1);
            break;
        }
    }
}

void func_800E1A58(f32 *param_0, f32 *param_1) {
    f32 local_1;
    f32 local_0[3];
    s32 local_3;
    func_800EE7F8(local_0, param_0);
    for (local_3 = 0; local_3 < 10; local_3++) {
        local_1 = 1;
        if (((EntryE1A58 *) D_8012CF90.raw)[local_3].local_6 == 1) continue;
        if (((EntryE1A58 *) D_8012CF90.raw)[local_3].local_8) {
            local_1 = func_800F0E00(func_800F10B4(func_800EEAD4(local_0, ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_0), ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_1, ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_2, 1.0f, 0.0f), ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_3);
            if (local_1 == 0) continue;
        }
        switch (((EntryE1A58 *) D_8012CF90.raw)[local_3].local_6) {
        case 2:
            func_800E1294(((EntryE1A58 *) D_8012CF90.raw)[local_3].local_7, param_0, param_1, ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_4 * local_1);
            break;
        case 3:
        case 4:
            func_800E1294(((EntryE1A58 *) D_8012CF90.raw)[local_3].local_7, param_0, param_1, ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_5 * ((EntryE1A58 *) D_8012CF90.raw)[local_3].local_4 * local_1);
            break;
        }
    }
}
