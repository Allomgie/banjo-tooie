#include "common.h"

extern f32 func_800EEAD4();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u8 pad[0x70]; s16 offsets[4]; s16 count; s16 pad7A; s16 current; } SuSplineOffsetView;
extern f32 func_800D8FF8(void);
extern void _mlspline_entrypoint_6(void);
extern void _mlspline_entrypoint_7(void);
extern void _mlspline_entrypoint_8(void);
extern f32 _mlspline_entrypoint_13(s32, void *, f32, f32, f32, void (*)());
typedef struct { u8 pad0[0x58]; f32 progress; u8 pad5C[12]; s16 offsets[8]; s16 count; s16 index; u8 pad7C[14]; u8 flags; } SplineAdvance32;
typedef struct SplineAdvanceState { u8 pad_0[0x58]; f32 local_0; u8 pad_1[12]; s16 local_1[8]; s16 local_2; s16 local_3; u8 pad_2[14]; u8 local_4; } SplineAdvanceState;
extern void func_800EE7F8(void *, void *);
extern void func_800F0EF0(s32, void *);
extern void _mlspline_entrypoint_0(f32, s32, void *, void *);
extern void _mlspline_entrypoint_1(f32, s32, void *, void *);
extern void _mlspline_entrypoint_2(f32, s32, void *, void *);
extern void _mlspline_entrypoint_3(f32, s32, void *, void *);
extern void _mlspline_entrypoint_4(f32, s32, void *, void *);
extern void _mlspline_entrypoint_9(f32, s32, void *, void *);
extern void func_800EFD24();
s32 suspline_entrypoint_1();
void suspline_entrypoint_19();

void suspline_entrypoint_0(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_2) {
        *(u8 *)(param_0 + 0x7E + (param_1 / 8)) |= 1 << (param_1 & 7);
    } else {
        *(u8 *)(param_0 + 0x7E + (param_1 / 8)) &= ~(1 << (param_1 & 7));
    }
}

int func_80800074_suspline(u8 *param_0, s32 param_1)
{
  return (((u8 *)((s32)param_0 + (param_1 / 8)))[126] & (1 << (param_1 & 7))) ? 1 : 0;
}

int func_808000B4_suspline(u8 *param_0, s32 param_1)
{
  return (((u8*)param_0 + param_1 / 8)[0x87] & (1 << (param_1 & 7))) ? 1 : 0;
}

s32 suspline_entrypoint_1(param_0) Actor *param_0;
{
    return param_0->unk58 >= 0.99f;
}

int suspline_entrypoint_2(f32 param_0[4], f32 param_1)
{
  if (param_0[23] <= param_1 && param_1 < param_0[22])
    return 1;
  return 0;
}

void suspline_entrypoint_3(f32 (*param_0)[3], s32 param_1, f32 *param_2) {
    func_800EE7F8(param_2, param_0[param_1]);
}

float suspline_entrypoint_4(float *param_0, int param_1)
{
    return ((float *)(((char *)param_0) + (param_1 * 4)))[0x30 / 4];
}

s32 suspline_entrypoint_5(s32 param_0, f32 *param_1){
    func_800EE7F8(param_0 + 0x3C, param_1);
}

f32 suspline_entrypoint_6(void *arg)
{
    return ((f32 *)arg)[22];
}

suspline_entrypoint_7(u8 *param_0) {
    return param_0[0x8B];
}

s32 suspline_entrypoint_8(Actor *this, f32 param_1){
    this->unk58 = param_1;
}

int suspline_entrypoint_9(f32 *param_0, f32 param_1)
{
  int new_var;
  f32 new_var2;
  new_var = 0xFFFFFFFFFFFFFFFFu;
  param_0[23] = (new_var2 = param_1);
 do { } while (0);
}

s32 suspline_entrypoint_10(s32 param_0, s32 param_1)
{
  return (*((s16 *) (((s8 *) ((param_0 ^ 0) + (param_1 * 2))) + 0x68))) + param_0;
}

s32 suspline_entrypoint_11(s32 param_0, s32 param_1)
{
  return (*((s16 *) (((s8 *) (param_0 + ((((((((((((param_1 * 2) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu))) + 0x70))) + param_0;
}

void suspline_entrypoint_12(s32 param_0, s32 param_1)
{
  s32 new_var;
  s32 *new_var2;
  new_var2 = &param_1;
  ((u8 *) param_0)[0x8A] = (new_var = *new_var2);
}

f32 func_80800224_suspline(u8 *param_0, f32 *param_1, s16 *param_2)
{
    if (*(s16 *)(param_0 + 0x78) >= 4) {
        if (param_0[0x8A] & 2) {
            param_2[1] = (f32)*(s16 *)(param_0 + 0x78) * *param_1;
        } else {
            param_2[1] = (f32)(*(s16 *)(param_0 + 0x78) - 1) * *param_1;
        }
        param_2[0] = param_2[1] - 1;
        param_2[2] = param_2[1] + 1;
        if (param_2[2] >= *(s16 *)(param_0 + 0x78)) {
            if (param_0[0x8A] & 2) {
                param_2[2] -= *(s16 *)(param_0 + 0x78);
            } else {
                param_2[2] = *(s16 *)(param_0 + 0x78) - 1;
            }
        }
        param_2[3] = param_2[2] + 1;
        if (param_2[3] >= *(s16 *)(param_0 + 0x78)) {
            if (param_0[0x8A] & 2) {
                param_2[3] -= *(s16 *)(param_0 + 0x78);
            } else {
                param_2[3] = *(s16 *)(param_0 + 0x78) - 1;
            }
        }
        if (param_2[0] < 0) {
            if (param_0[0x8A] & 2) {
                param_2[0] += *(s16 *)(param_0 + 0x78);
            } else {
                param_2[0] = 0;
            }
        }
        if (func_80800074_suspline(param_0, param_2[1])) {
            if (param_0[0x8A] & 2) {
                *param_1 = (param_2[1] + 1) / (f32)*(s16 *)(param_0 + 0x78);
            } else {
                *param_1 = (param_2[1] + 1) / (f32)(*(s16 *)(param_0 + 0x78) - 1);
            }
            param_0[0x8B] = 1;
        } else {
            param_0[0x8B] = 0;
        }
        if (func_80800074_suspline(param_0, param_2[2])) {
            param_2[3] = param_2[2];
        }
        if (func_80800074_suspline(param_0, param_2[0])) {
            param_2[0] = param_2[1];
        }
        if (param_0[0x8A] & 2) {
            return func_800F10B4(*param_1,
                param_2[1] / (f32)*(s16 *)(param_0 + 0x78),
                (param_2[1] + 1) / (f32)*(s16 *)(param_0 + 0x78), 0.333f, 0.666f);
        }
        return func_800F10B4(*param_1,
            param_2[1] / (f32)(*(s16 *)(param_0 + 0x78) - 1),
            param_2[2] / (f32)(*(s16 *)(param_0 + 0x78) - 1), 0.333f, 0.666f);
    }
    return 0.0f;
}

void suspline_entrypoint_13(u8 *param_0)
{
    f32 local_3;
    s16 local_0[4];
    f32 local_1[4];
    f32 *local_2;

    if (!(param_0[0x8A] & 1)) {
        local_2 = (f32 *)(param_0 + ((SuSplineOffsetView *)param_0)->offsets[((SuSplineOffsetView *)param_0)->current]);
        if (*(s16 *)(param_0 + 0x78) >= 4) {
            local_3 = func_80800224_suspline(param_0, (f32 *)(param_0 + 0x58), local_0);
            local_1[0] = local_2[local_0[0]];
            local_1[1] = local_2[local_0[1]];
            local_1[2] = local_2[local_0[2]];
            local_1[3] = local_2[local_0[3]];
            _mlspline_entrypoint_9(local_3, 4, local_1, (f32 *)(param_0 + 0x60));
        } else if (*(s16 *)(param_0 + 0x78) == 3) {
            _mlspline_entrypoint_3(*(f32 *)(param_0 + 0x58), *(s16 *)(param_0 + 0x78), local_2, (f32 *)(param_0 + 0x60));
        } else {
            _mlspline_entrypoint_1(*(f32 *)(param_0 + 0x58), *(s16 *)(param_0 + 0x78), local_2, (f32 *)(param_0 + 0x60));
        }
        if (*(f32 *)(param_0 + 0x54) < 0.05f) {
            *(f32 *)(param_0 + 0x54) = 0.05f;
        }
        *(f32 *)(param_0 + 0x64) = *(f32 *)(param_0 + 0x60) * func_800D8FF8();
    }
}

void suspline_entrypoint_14(SplineAdvance32 *param_0)
{
    f32 local_0;
    s32 local_1;
    u8 *local_2;

    if ((local_0 = param_0->progress) < 0.9999f && !(param_0->flags & 1)) {
        local_2 = (u8 *)param_0 + param_0->offsets[param_0->index];
        local_1 = param_0->count;
        if (local_1 >= 4) {
            param_0->progress = _mlspline_entrypoint_13(local_1, local_2, local_0,
                *(f32 *)((u8 *)param_0 + 0x54) * *(f32 *)((u8 *)param_0 + 0x64), 1.0f, _mlspline_entrypoint_8);
        } else if (local_1 >= 3) {
            param_0->progress = _mlspline_entrypoint_13(local_1, local_2, local_0,
                *(f32 *)((u8 *)param_0 + 0x54) * *(f32 *)((u8 *)param_0 + 0x64), 1.0f, _mlspline_entrypoint_7);
        } else {
            param_0->progress = _mlspline_entrypoint_13(local_1, local_2, local_0,
                *(f32 *)((u8 *)param_0 + 0x54) * *(f32 *)((u8 *)param_0 + 0x64), 1.0f, _mlspline_entrypoint_6);
        }
    }
}

void suspline_entrypoint_15(SplineAdvanceState *param_0, f32 param_1)
{
    s32 local_0;
    void *local_1;

    if (param_0->local_0 < 0.9999f && !(param_0->local_4 & 1)) {
        local_1 = (u8 *)param_0 + param_0->local_1[param_0->local_3];
        local_0 = param_0->local_2;
        if (local_0 >= 4) {
            param_0->local_0 = _mlspline_entrypoint_13(local_0, local_1, param_0->local_0, param_1, 1.0f, _mlspline_entrypoint_8);
        } else if (local_0 >= 3) {
            param_0->local_0 = _mlspline_entrypoint_13(local_0, local_1, param_0->local_0, param_1, 1.0f, _mlspline_entrypoint_7);
        } else {
            param_0->local_0 = _mlspline_entrypoint_13(local_0, local_1, param_0->local_0, param_1, 1.0f, _mlspline_entrypoint_6);
        }
    }
}

void suspline_entrypoint_16(u8 *param_0)
{
    if (!suspline_entrypoint_1(param_0) && 0.0f != *(f32 *)(param_0 + 0x64)
        && !func_800EECE0((f32 *)(param_0 + 0x48), (f32 *)(param_0 + 0x3C))) {
        *(f32 *)(param_0 + 0x54) *= *(f32 *)(param_0 + 0x64)
            / func_800EEAD4((f32 *)(param_0 + 0x48), (f32 *)(param_0 + 0x3C));
    }
}

void suspline_entrypoint_17(u8 *param_0)
{
    f32 local_0;
    u8 *local_A4[4];
    u8 *local_94[4];
    s32 i;
    f32 f20;
    s16 local_84[4];
    f32 local_74[4];
    f32 local_68[3];
    f32 local_5C[3];
    f32 local_50[3];
    f32 local_44[3];
    local_0 = *((f32 *) (param_0 + 0x58));
    func_800EE7F8(param_0 + 0x48, param_0 + 0x3C);
    for (i = 0; i < param_0[0x88]; i++) {
        local_A4[i] = param_0 + *((s16 *) (param_0 + 0x68 + i * 2));
    }
    for (i = 0; i < param_0[0x89]; i++) {
        local_94[i] = param_0 + *((s16 *) (param_0 + 0x70 + i * 2));
    }
    if (*((s16 *) (param_0 + 0x78)) >= 4) {
        f20 = func_80800224_suspline(param_0, &local_0, local_84);
        for (i = 0; i < param_0[0x88]; i++) {
            func_800EE7F8(local_44, (f32 *) local_A4[i] + 3 * local_84[0]);
            func_800EE7F8(local_50, (f32 *) local_A4[i] + 3 * local_84[1]);
            func_800EE7F8(local_5C, (f32 *) local_A4[i] + 3 * local_84[2]);
            func_800EE7F8(local_68, (f32 *) local_A4[i] + 3 * local_84[3]);
            if (func_808000B4_suspline(param_0, i)) {
                func_800F0EF0(4, local_44);
            }
            _mlspline_entrypoint_4(f20, 4, local_44, param_0 + 0xC * i);
        }
        for (i = 0; i < param_0[0x89]; i++) {
            local_74[0] = ((f32 *) local_94[i])[local_84[0]];
            local_74[1] = ((f32 *) local_94[i])[local_84[1]];
            local_74[2] = ((f32 *) local_94[i])[local_84[2]];
            local_74[3] = ((f32 *) local_94[i])[local_84[3]];
            _mlspline_entrypoint_9(f20, 4, local_74, param_0 + 0x30 + i * 4);
        }
    } else {
        if (*((s16 *) (param_0 + 0x78)) == 3) {
            for (i = 0; i < param_0[0x88]; i++) {
                _mlspline_entrypoint_2(local_0, *((s16 *) (param_0 + 0x78)), local_A4[i], param_0 + 0xC * i);
            }
            for (i = 0; i < param_0[0x89]; i++) {
                _mlspline_entrypoint_3(local_0, *((s16 *) (param_0 + 0x78)), local_94[i], param_0 + 0x30 + i * 4);
            }
        } else {
            for (i = 0; i < param_0[0x88]; i++) {
                _mlspline_entrypoint_0(local_0, *((s16 *) (param_0 + 0x78)), local_A4[i], param_0 + 0xC * i);
            }
            for (i = 0; i < param_0[0x89]; i++) {
                _mlspline_entrypoint_1(local_0, *((s16 *) (param_0 + 0x78)), local_94[i], param_0 + 0x30 + i * 4);
            }
        }
    }
    if (local_0 > 0.9998999834f) {
        local_0 = 0.9998999834f;
    }
    *((f32 *) (param_0 + 0x58)) = local_0;
}

void func_80800C8C_suspline(u8 *param_0)
{
  s32 var_v0;
  s32 var_v1;
  u8 *var_a1;
  u8 *var_a1_2;
  var_v0 = 0x8C;
  var_v1 = 0;
  var_a1 = param_0;
  if (((s32) (*((u8 *) (param_0 + 0x88)))) > 0)
  {
    do
    {
      *((s16 *) (var_a1 + 0x68)) = var_v0;
      var_v1++;
      var_a1 += 2;
      var_v0 += (*((s16 *) (param_0 + 0x78))) * 0xC;
    }
    while (var_v1 < ((s32) (*((u8 *) (param_0 + 0x88)))));
    var_v1 = 0;
  }
  var_a1_2 = param_0;
  if (((s32) (*((u8 *) (param_0 + 0x89)))) > 0)
  {
    do
    {
      *((s16 *) (var_a1_2 + 0x70)) = var_v0;
      var_v1++;
      var_a1_2 += 2;
      var_v0 += (*((s16 *) (param_0 + 0x78))) * 4;
    }
    while (var_v1 < ((s32) (*((u8 *) (param_0 + 0x89)))));
  }
}

s32 suspline_entrypoint_18(unsigned int param_0, s32 param_1, s32 param_2)
{
  return (param_0 * ((param_1 * 0xC) + (param_2 * 4))) + 0x8C;
}

void suspline_entrypoint_19(param_0, param_1, param_2, param_3, param_4, param_5) u8 *param_0; s32 param_1; s32 param_2; s32 param_3; s32 param_4; s32 param_5;
{
    s32 local_0;

    func_800EFD24((f32 *)(param_0 + 0x3C));
    func_800EFD24((f32 *)(param_0 + 0x48));
    param_0[0x7E] = 0;
    *(f32 *)(param_0 + 0x60) = 0.0f;
    *(f32 *)(param_0 + 0x64) = 0.0f;
    for (local_0 = 1; local_0 < 9; local_0++) {
        param_0[0x7E + local_0] = 0;
    }
    *(s16 *)(param_0 + 0x7A) = param_4;
    *(s16 *)(param_0 + 0x7C) = param_5;
    *(s16 *)(param_0 + 0x78) = param_1;
    param_0[0x88] = param_2;
    param_0[0x89] = param_3;
    param_0[0x87] = 0;
    *(f32 *)(param_0 + 0x54) = 1.0f;
    func_800EFD24((f32 *)(param_0 + 0x48));
    *(f32 *)(param_0 + 0x58) = 0.0f;
    *(f32 *)(param_0 + 0x5C) = -0.01f;
    param_0[0x8B] = 0;
    param_0[0x8A] = 0;
    func_80800C8C_suspline(param_0);
}

int suspline_entrypoint_20(s32 param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4[3], f32 param_5[3])
{
    s32 local_0;
    s32 local_1;
    local_1 = param_3;
    local_0 = suspline_entrypoint_18(param_1, param_2, local_1);
    func_80100074(param_0, 1, local_0);
    suspline_entrypoint_19(func_80100094(param_0, 1), param_1, param_2, param_3, param_4, param_5);
}
