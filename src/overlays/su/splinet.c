#include "common.h"

#define SUSPLINET_SPLINE_S_VIEW
#define SPLINE_LAYOUT_1446
typedef struct { u8 pad[0x32]; s16 off; } SplineFlagsView;
typedef struct { u8 pad[0x30]; s16 off30; s16 off32; u8 pad34[0x10]; f32 f44; f32 f48; u8 pad4C[2]; s16 cnt; u8 bits[1]; } SplineS;
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct { u8 pad_0[0x44]; f32 local_0; u8 pad_1[0xC]; u32 local_1; } SplineTimeState;
typedef struct { u8 pad_0[0x30]; s16 offsets[3]; s16 vector_offsets[4]; s16 pair_offsets[7]; s16 index, count; u8 pad_1, vector_count, pair_count; } SplineLayout1446;
typedef struct { u8 pad[0x30]; s16 off0; } SplineHdr30_80800384_susplinet;
typedef struct { u8 pad[0x30]; s16 off0; s16 off1; } SplineHdr30_susplinet_entrypoint_16;
extern s32 func_800DA9E4(s32, s32);
extern void func_800F0EF0(s32, f32 *);
extern void _mlspline_entrypoint_8(f32, s32, f32 *, u8 *);
extern void _mlspline_entrypoint_9(f32, s32, f32 *, u8 *);
typedef struct { u8 pad[0x30]; s16 k; s16 pad32; s16 l; } SplHdr;
typedef struct { u8 pad[0x32]; s16 unk32; s16 unk34; } SplinetHdr;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct { u8 pad[0x30]; s16 off30; } SplineHdr30b;
extern s32 func_800EEDE8(void *, void *, f32);
extern f32 func_800EEAD4(void *, void *);
extern void _mlspline_entrypoint_4(f32, s32, void *, void *);
void susplinet_entrypoint_17();
void func_80800D3C_susplinet_2arg();
f32 func_80800620_susplinet(u8 *param_0, s16 *param_1, f32 param_2);
f32 func_808007D0_susplinet(u8 *param_0, f32 param_1, s16 *param_2, u8 *param_3);

void susplinet_entrypoint_0(SplineFlagsView *param_0, s32 param_1, s32 param_2, s32 param_3) {
    s16 *local_0 = (s16 *)((u8 *)param_0 + param_0->off);
    if (param_3) {
        local_0[param_1] |= param_2;
    } else if (local_0[param_1] & param_2) {
        local_0[param_1] -= param_2;
    }
}

s32 func_80800048_susplinet(SplineS *param_0, s32 param_1) {
    s16 *local_0 = (s16 *)((u8 *)param_0 + param_0->off32);
    return local_0[param_1] & 4;
}

s32 func_80800068_susplinet(SplineS *param_0, s32 param_1) {
    s16 *local_0 = (s16 *)((u8 *)param_0 + param_0->off32);
    return local_0[param_1] & 2;
}

void susplinet_entrypoint_1(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_2) {
        *(u8 *)(param_0 + 0x50 + (param_1 / 8)) |= 1 << (param_1 & 7);
    } else {
        *(u8 *)(param_0 + 0x50 + (param_1 / 8)) &= ~(1 << (param_1 & 7));
    }
}

s32 func_808000FC_susplinet(s32 param_0, s32 param_1) {
  return (((u8 *)((s32)param_0 + (param_1 / 8)))[80] & (1 << (param_1 & 7))) ? 1 : 0;
}

s32 susplinet_entrypoint_2(SplineS *param_0) {
    s16 *local_0 = (s16 *)((u8 *)param_0 + param_0->off30);
    return local_0[param_0->cnt - 1] <= param_0->f44;
}

s32 susplinet_entrypoint_3(SplineS *param_0) {
    s16 *local_0 = (s16 *)((u8 *)param_0 + param_0->off30);
    return local_0[param_0->cnt - 1];
}

s32 susplinet_entrypoint_4(SplineS *param_0, f32 param_1) {
    if (param_0->f48 <= param_1 && param_1 < func_800D8FF8() * 100.0f + param_0->f44) {
        return 1;
    }
    return 0;
}

int susplinet_entrypoint_5(f32 param_0[9], f32 param_1)
{
  if (param_0[18] <= param_1 && param_1 < param_0[17])
    return 1;
  return 0;
}

susplinet_entrypoint_6(u8 *param_0) {
    return param_0[0x53];
}

void susplinet_entrypoint_7(f32 (*param_0)[3], s32 param_1, f32 *param_2) {
    func_800EE7F8(param_2, param_0[param_1]);
}

float susplinet_entrypoint_8(float *param_0, int param_1) {
    return param_0[param_1 + 9];
}

f32 susplinet_entrypoint_9(void *arg)
{
    return ((f32 *)arg)[17];
}

void susplinet_entrypoint_10(SplineTimeState *param_0, f32 param_1)
{
    s32 local_0;
    local_0 = susplinet_entrypoint_3((SplineS *)param_0);
    if (param_1 < 0.0f) param_1 = 0.0f;
    if (param_0->local_1 & 2) {
        while ((f32)local_0 < param_1) param_1 -= (f32)local_0;
    }
    param_0->local_0 = param_1;
}

void susplinet_entrypoint_11(Actor *param_0, f32 param_1)
{
    *(f32*)((u8*)param_0 + 0x48) = param_1;
}

int susplinet_entrypoint_12(s32 param_0)
{
  s16 *new_var;
  new_var = (s16 *) (((int) param_0) + 0x30);
  return (*new_var) + ((0, param_0));
}

int susplinet_entrypoint_13(s32 param_0)
{
  s16 *new_var;
  new_var = (s16 *) (((int) param_0) + 0x34);
  return (*new_var) + ((0, param_0));
}

s32 susplinet_entrypoint_14(s32 param_0, s32 param_1)
{
  unsigned long new_var3;
  s32 new_var;
  s8 *new_var2;
  new_var3 = param_1 * 2;
  new_var = param_0;
  new_var2 = ((s8 *) (new_var + new_var3)) + 0x36;
  return (*((s16 *) new_var2)) + param_0;
}

s32 susplinet_entrypoint_15(s32 param_0, s32 param_1)
{
  return (*((s16 *) (((s8 *) ((param_0 ^ 0) + (param_1 * 2))) + 0x3E))) + param_0;
}

s16 func_80800384_susplinet(SplineLayout1446 *param_0, s16 param_1)
{
    s16 *local_0;
    s16 *local_1;
    s16 local_2;
    s32 local_3;

    local_0 = (s16 *)((s32)param_0 + ((SplineHdr30_80800384_susplinet *)param_0)->off0);
    local_2 = param_0->index;
    local_1 = (s16 *)((u32)local_0 + local_2 * sizeof(s16));
    if (param_1 < *local_1 && local_2 > 0) {
        do {
            local_2--;
            local_1 = (s16 *)((u32)local_0 + local_2 * sizeof(s16));
        } while (param_1 < *local_1 && local_2 > 0);
    }
    if (local_1[1] < param_1) {
        local_3 = param_0->count - 1;
        if (local_2 < local_3) {
            do {
                local_2++;
            } while (local_0[local_2 + 1] < param_1 && local_2 < local_3);
        }
    }
    param_0->index = local_2;
    return local_2;
}

void susplinet_entrypoint_16(SplineLayout1446 *this, f32 arg1, f32 arg2)
{
    s16 *a;
    s16 *b;
    s16 k;
    s16 i;
    s16 j;

    a = (s16 *)((s32)this + ((SplineHdr30_susplinet_entrypoint_16 *)this)->off0);
    b = (s16 *)((s32)this + ((SplineHdr30_susplinet_entrypoint_16 *)this)->off1);
    k = func_80800384_susplinet(this, arg1);
    i = k + 1;
    j = i + 1;
    if (j >= this->count) {
        susplinet_entrypoint_10(this, arg2);
        return;
    }
    if (a[i] != a[j]) {
        susplinet_entrypoint_10(this, arg2);
        return;
    }
    if (arg2 < a[i]) {
        susplinet_entrypoint_10(this, arg2);
        return;
    }
    if (b[i] & 1) {
        if (func_800DA9E4(0x644, 0) == 0) {
            susplinet_entrypoint_10(this, a[i]);
        } else {
            susplinet_entrypoint_10(this, a[j] + 1);
        }
        return;
    }
    susplinet_entrypoint_10(this, arg2);
}

f32 func_80800620_susplinet(u8 *param_0, s16 *param_1, f32 param_2)
{
    f32 local_1;
    s16 *local_0;
    local_0 = (s16 *)((s32)param_0 + ((SplineHdr30b *)param_0)->off30);
    local_1 = param_2;
    param_1[1] = func_80800384_susplinet(param_0, (s16)(s32)local_1);
    param_1[0] = param_1[1] - 1;
    param_1[2] = param_1[1] + 1;
    if (!(*(u32 *)(param_0 + 0x54) & 2)) {
        if (param_1[2] >= *(s16 *)(param_0 + 0x4E)) param_1[2] = *(s16 *)(param_0 + 0x4E) - 1;
        param_1[3] = param_1[2] + 1;
        if (param_1[3] >= *(s16 *)(param_0 + 0x4E)) param_1[3] = *(s16 *)(param_0 + 0x4E) - 1;
        if (param_1[0] < 0) param_1[0] = 0;
    } else {
        if (param_1[2] >= *(s16 *)(param_0 + 0x4E)) param_1[2] = param_1[2] - *(s16 *)(param_0 + 0x4E) + 1;
        param_1[3] = param_1[2] + 1;
        if (param_1[3] >= *(s16 *)(param_0 + 0x4E)) param_1[3] = param_1[3] - *(s16 *)(param_0 + 0x4E) + 1;
        if (param_1[0] < 0) param_1[0] = *(s16 *)(param_0 + 0x4E) + param_1[0] - 1;
    }
    if (func_80800048_susplinet(param_0, param_1[1])) param_1[0] = param_1[1];
    if (func_80800068_susplinet(param_0, param_1[2])) param_1[3] = param_1[2];
    return func_800F10B4(param_2, local_0[param_1[1]], local_0[param_1[2]], 0.333f, 0.666f);
}

f32 func_808007D0_susplinet(u8 *param_0, f32 param_1, s16 *param_2, u8 *param_3)
{
    s16 *knots;
    s16 *lens;
    s32 pad1;
    f32 spB4[30];
    s32 pad2;
    f32 spA4[3];
    f32 sp98[3];
    s32 i;
    f32 sp90;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 pad80;
    f32 sp7C;
    f32 sp78;
    f32 x;
    f32 b;
    f32 r;
    s32 k;

    knots = (s16 *)((s32)param_0 + ((SplHdr *)param_0)->k);
    lens = (s16 *)((s32)param_0 + ((SplHdr *)param_0)->l);
    if ((f32) knots[param_2[2]] <= param_1) {
        return 0.666f;
    }
    if (param_1 <= (f32) knots[param_2[1]]) {
        return 0.333f;
    }
    if (func_800EEDE8(param_3 + 0xC, param_3 + 0x18, 25.0f) != 0) {
        return func_800F10B4(param_1, (f32) knots[param_2[1]], (f32) knots[param_2[2]], 0.333f, 0.666f);
    }
    for (i = 0; i != 30; i++) {
        _mlspline_entrypoint_4(func_800F10B4((f32) i, 0.0f, 29.0f, 0.333f, 0.666f), 4, param_3, spA4);
        if (i > 0) {
            spB4[i] = spB4[i - 1] + func_800EEAD4(sp98, spA4);
        } else {
            spB4[i] = 0.0f;
        }
        func_800EE7F8(sp98, spA4);
    }
    sp88 = (f32) lens[param_2[1]] * 0.01f;
    sp8C = (f32) lens[param_2[2]] * 0.01f;
    sp84 = (f32) knots[param_2[2]] - (f32) knots[param_2[1]];
    sp90 = ((((spB4[29] * 4.0f) / sp84) - sp88) - sp8C) * 0.5f;
    sp7C = func_800F10B4(param_1, (f32) knots[param_2[1]], (f32) knots[param_2[2]], 0.0f, 1.0f);
    if (sp7C < 0.5f) {
        sp78 = func_800F10B4(param_1, (f32) knots[param_2[1]], (f32) knots[param_2[1]] + (0.5f * sp84), sp88, sp90);
        b = func_800F10B4(param_1, (f32) knots[param_2[1]], (f32) knots[param_2[1]] + (0.5f * sp84), 0.0f, 1.0f);
        x = sp88;
    } else {
        sp78 = func_800F10B4(param_1, (f32) knots[param_2[1]] + (0.5f * sp84), (f32) knots[param_2[2]], sp90, sp8C);
        b = func_800F10B4(param_1, (f32) knots[param_2[1]] + (0.5f * sp84), (f32) knots[param_2[2]], 0.0f, 1.0f);
        x = sp90;
    }

    if (sp78 < x) {
        r = (x + sp78) * 0.25f * sp84 * b;
    } else {
        r = (sp78 + x) * 0.25f * sp84 * b;
    }
    if (0.5f <= sp7C) {
        r += (0.25f * sp84) * (sp88 + sp90);
    }
    k = 0;
    while (k < 28 && spB4[k + 1] < r) {
        k++;
    }
    r = func_800F10B4(r, spB4[k], spB4[k + 1], (f32) k * 0.03448275849f, (f32) (k + 1) * 0.03448275849f);
    return func_800F10B4(r, 0.0f, 1.0f, 0.333f, 0.666f);
}

/* s1 is a third parameter that is only written, never read on entry: it gives the value a register without
 * a stack slot, as in the target. susplinet_entrypoint_17 calls this function with two arguments (a2 is not
 * set), through the second name func_80800D3C_susplinet_2arg from undefined_syms.us.txt; without a prototype the
 * f32 argument is passed as its bit pattern. */
void func_80800D3C_susplinet(u8 *param_0, f32 param_1, s16 *s1)
{
    s16 *local_0;
    u8 *local_A4[5];
    u8 *local_94[3];
    s32 i;
    s16 local_84[4];
    f32 f20;
    f32 local_74[4];
    f32 local_68[3];
    f32 local_5C[3];
    f32 local_50[3];
    f32 local_44[3];
    s32 a;
    s32 b;
    s32 c;
    s32 d;

    local_0 = (s16 *)((s32)param_0 + ((SplHdr *)param_0)->l);
    s1 = (s16 *)((s32)param_0 + ((SplHdr *)param_0)->k);
    if ((f32)s1[*(s16 *)(param_0 + 0x4E) - 1] < param_1) {
        param_1 = s1[*(s16 *)(param_0 + 0x4E) - 1];
    } else if (param_1 < (f32)s1[0]) {
        param_1 = s1[0];
    }
    for (i = 0; i < param_0[0x51]; i++) {
        local_A4[i] = param_0 + *(s16 *)(param_0 + 0x36 + i * 2);
    }
    for (i = 0; i < param_0[0x52]; i++) {
        local_94[i] = param_0 + *(s16 *)(param_0 + 0x3E + i * 2);
    }
    if (*(s16 *)(param_0 + 0x4E) >= 4) {
        f20 = func_80800620_susplinet(param_0, local_84, param_1);
        if (local_84[0] != local_84[1] && s1[local_84[0]] == s1[local_84[1]] && susplinet_entrypoint_5(param_0, s1[local_84[1]])) {
            param_0[0x53] = 1;
        } else {
            param_0[0x53] = 0;
        }
        a = local_84[0] * 3;
        b = local_84[1] * 3;
        c = local_84[2] * 3;
        d = local_84[3] * 3;
        for (i = 0; i < param_0[0x51]; i++) {
            func_800EE7F8(local_44, (f32 *)local_A4[i] + a);
            func_800EE7F8(local_50, (f32 *)local_A4[i] + b);
            func_800EE7F8(local_5C, (f32 *)local_A4[i] + c);
            func_800EE7F8(local_68, (f32 *)local_A4[i] + d);
            if (i == 0 && *local_0 != -1) {
                f20 = func_808007D0_susplinet(param_0, param_1, local_84, local_44);
            }
            if (func_808000FC_susplinet(param_0, i)) {
                func_800F0EF0(4, local_44);
            }
            _mlspline_entrypoint_4(f20, 4, local_44, param_0 + i * 12);
            if (i == 0) {
                _mlspline_entrypoint_8(f20, 4, local_44, param_0 + i * 12 + 0x18);
            }
        }
        for (i = 0; i < param_0[0x52]; i++) {
            local_74[0] = ((f32 *)local_94[i])[local_84[0]];
            local_74[1] = ((f32 *)local_94[i])[local_84[1]];
            local_74[2] = ((f32 *)local_94[i])[local_84[2]];
            local_74[3] = ((f32 *)local_94[i])[local_84[3]];
            _mlspline_entrypoint_9(f20, 4, local_74, param_0 + 0x24 + i * 4);
        }
    }
}

void susplinet_entrypoint_17(param_0) u8 *param_0; {
    param_0[0x58] = 1;
    func_80800D3C_susplinet_2arg(param_0, *(s32 *)(param_0 + 0x44));
    param_0[0x58] = 0;
}

void func_8080111C_susplinet(SplineLayout1446 *param_0)
{
    s32 local_0;
    s32 local_1;

    param_0->offsets[0] = 0x5C;
    local_0 = 0x5C + param_0->count * 2;
    param_0->offsets[1] = local_0;
    local_0 += param_0->count * 2;
    for (local_1 = 0; local_1 < param_0->vector_count; local_1++) {
        param_0->vector_offsets[local_1] = local_0;
        local_0 += param_0->count * 12;
    }
    for (local_1 = 0; local_1 < param_0->pair_count; local_1++) {
        param_0->pair_offsets[local_1] = local_0;
        local_0 += param_0->count * 4;
    }
    param_0->offsets[2] = local_0;
}

s32 func_808011B8_susplinet(s32 param_0, s32 param_1) {
    return (param_0 * 0xC) + (param_1 * 4) + 6;
}

s32 susplinet_entrypoint_18(s32 param_0, s32 param_1, s32 param_2)
{
  int new_var;
  s32 local_0;
  local_0 = func_808011B8_susplinet(param_1 | 0, param_2 | 0);
  new_var = param_0 * local_0;
  if (1)
  {
    return new_var + 0x5C;
  }
}

void susplinet_entrypoint_19(u8 *param_0, s32 param_1, s32 param_2, s32 param_3)
{
    s16 *local_0;
    s16 *local_1;
    s32 local_2;

    *(s16 *)(param_0 + 0x4E) = param_1;
    param_0[0x51] = param_2;
    param_0[0x52] = param_3;
    param_0[0x50] = 0;
    *(s16 *)(param_0 + 0x4C) = 0;
    param_0[0x58] = 0;
    *(f32 *)(param_0 + 0x44) = 0.0f;
    *(f32 *)(param_0 + 0x48) = 0.0f;
    func_8080111C_susplinet(param_0);
    local_0 = (s16 *)((s32)param_0 + ((SplinetHdr *)param_0)->unk32);
    local_1 = (s16 *)((s32)param_0 + ((SplinetHdr *)param_0)->unk34);
    for (local_2 = 0; local_2 < param_1; local_2++) {
        local_0[local_2] = 0;
        local_1[local_2] = -1;
    }
    func_800DA524(0x644);
}
