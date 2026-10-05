#include "core2/1E82660.h"

typedef struct { s16 mode, count; u8 flags[4]; s16 ids[8]; s32 slots[8]; s32 handles[8]; } LocalState;
extern s32 D_801276D0[];
extern s32 D_801276F0[];
extern void func_8010FC38(s32);
typedef struct { s16 local_0; s16 local_1; } Struct800A8FDC;
extern s16 D_801276D2;
extern u8 D_801276D4;
extern u8 D_801276D5;
extern u8 D_801276D6;
extern u8 D_801276D7[];
typedef struct { s16 local_0, local_1; u8 local_2[4]; s16 local_3[8]; s32 local_4[8]; void *local_5[8]; s32 local_6[8]; } StateA907C;
extern void *func_800CA334(void);
extern s32 func_8010FB34(void *, s32);
extern void func_80110164();
extern s32 D_80127728[];
extern s32 D_80127708[];
extern s32 D_801276E8[];
extern f32 func_800EEB40(s32 *param_0, s32 param_1);
extern s32 func_800A88C4();
extern s32 func_800A8984(s32 param_0);
extern s32 func_800CA384(s32 param_0);
extern s32 func_80110068(s32 param_0, s32 param_1);
extern s32 D_801276EC[];
extern s32 D_801276F4[];
extern s32 D_80127754;
extern s16 D_80127750;
extern s16 D_80127752;
void func_800A91F4();
int func_800A9420();
void func_800A9828();

void func_800A8D70(s32 param_0, s32 param_1)
{
    s32 local_0;
    _gcstatusDll_entrypoint_1();
    if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(param_0), 0x20)) (*((LocalState *) D_801276D0)).count = _gcstatusDll_entrypoint_11();
    else (*((LocalState *) D_801276D0)).count = 1;
    for (local_0 = 0; local_0 < (*((LocalState *) D_801276D0)).count; local_0++) func_800A877C(local_0);
    for (local_0 = 0; local_0 < 8; local_0++) (*((LocalState *) D_801276D0)).ids[local_0] = -1;
    for (local_0 = 0; local_0 < 4; local_0++) (*((LocalState *) D_801276D0)).flags[local_0] = 0;
    for (local_0 = 0; local_0 < 8; local_0++) (*((LocalState *) D_801276D0)).handles[local_0] = 0;
    for (local_0 = 0; local_0 < 8; local_0 += 4) {
        (*((LocalState *) D_801276D0)).slots[local_0 + 1] = 0;
        (*((LocalState *) D_801276D0)).slots[local_0 + 2] = 0;
        (*((LocalState *) D_801276D0)).slots[local_0 + 3] = 0;
        (*((LocalState *) D_801276D0)).slots[local_0] = 0;
    }
    (*((LocalState *) D_801276D0)).mode = 0;
}

void func_800A8E9C()
{
  s32 *local_0;
  s32 *local_1;
 do { local_0 = D_801276D0; local_1 = D_801276F0; } while (0);
  do
  {
    if (local_0[0x16] != 0)
    {
      func_8010FC38(local_0[0x16]);
    }
    local_0++;
  }
  while (local_0 != local_1);
}

void func_800A8EF0(s32 param_0, s32 param_1)
{
  s32 *local_0;
  s32 local_1;
 local_0 = (s32 *) ((u8 *) D_801276D0); do { local_1 = *((s32 *) (((char *) local_0) + 0x58)); if ((local_1 != 0) && (param_1 == (*((s32 *) (((char *) local_0) + 0x18))))) {
      func_8010FAEC(param_0, local_1);
    }
    local_0 += 1;
  }
  while (local_0 != ((s32 *) ((u8 *) D_801276F0)));
}

int func_800A8F68()
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    func_800A91F4(local_0);
  }

  while (((s16 *) D_801276D0)[1] != 0)
  {
    func_800A87FC(((s16 *) D_801276D0)[1] - 1);
    ((s16 *) D_801276D0)[1]--;
  }

}

s32 func_800A8FDC(void)
{
    Struct800A8FDC *local_2;

    func_800A877C(D_801276D2);
    local_2 = ((Struct800A8FDC *) D_801276D0);
    return local_2->local_1++;
}

int func_800A9010()
{
  if (D_801276D4 == 0)
  {
    return 0;
  }
  if (D_801276D5 == 0)
  {
    return 1;
 do { } while (0);
  }
  if (D_801276D6 == 0)
  {
    return 2;
  }
  if (!(D_801276D7[0] != 0))
  {
    return 3;
  }
  return -1;
}

s32 func_800A907C(s32 param_0, s32 param_1, s32 param_2) {
    param_1 = param_1 == -1 ? func_800A9010() : param_1;
    if (param_1 == -1) return -1;
    if ((*((StateA907C *) D_801276D0)).local_5[param_0]) return (*((StateA907C *) D_801276D0)).local_3[param_0];
    if (param_2 == -1) param_2 = param_1;
    if (param_2 >= (*((StateA907C *) D_801276D0)).local_1) param_2 = (*((StateA907C *) D_801276D0)).local_1 - 1;
    (*((StateA907C *) D_801276D0)).local_0++;
    (*((StateA907C *) D_801276D0)).local_3[param_0] = param_1;
    (*((StateA907C *) D_801276D0)).local_2[param_1]++;
    (*((StateA907C *) D_801276D0)).local_5[param_0] = func_800CA334();
    (*((StateA907C *) D_801276D0)).local_6[param_0] = func_8010FB34((*((StateA907C *) D_801276D0)).local_5[param_0], param_0);
    (*((StateA907C *) D_801276D0)).local_4[param_0] = param_2;
    if ((*((StateA907C *) D_801276D0)).local_2[param_1] == 1) func_800A88C4(param_2, (*((StateA907C *) D_801276D0)).local_5[param_0]);
    return param_1;
}

void func_800A91A8(s32 param_0)
{
  if (param_0 >= 0)
  {
    s32 idx = param_0;
    if (((s16 *) D_801276D0)[idx + 4] != (-1))
    {
      func_800A88C4(((s16 *) D_801276D0)[idx + 4], ((s32 *)((s16 *) D_801276D0))[idx + 0xE]);
    }
  }
}

void func_800A91F4(param_0) s32 param_0;
{
  s16 *temp_s0;
  u8 *temp_s1;
  u8 *temp_v0;
  if (param_0 >= 0)
  {
    temp_s0 = &((s16 *) D_801276D0)[param_0];
    temp_s1 = ((u8 *) (((s16 *) D_801276D0))) + (param_0 * 4);
    if ((*((s16 *) (((s8 *) temp_s0) + 8))) != (-1))
    {
      func_8010FBD4(*((s32 *) (((s8 *) temp_s1) + 0x58)));
      *((s32 *) (((s8 *) temp_s1) + 0x58)) = 0;
      if (func_800A8984(*((s16 *) (((s8 *) temp_s0) + 8))) == (*((s32 *) (((s8 *) temp_s1) + 0x38))))
      {
 if (1) { }
        func_800A8948(*((s16 *) (((s8 *) temp_s0) + 8)));
      }
      func_800CA364(*((s32 *) (((s8 *) temp_s1) + 0x38)));
 do { } while (0);
      *((s32 *) (((s8 *) temp_s1) + 0x38)) = 0;
      temp_v0 = (u8 *) (((s16 *) D_801276D0));
      temp_v0 += *((s16 *) (((s8 *) temp_s0) + 8));
      *((u8 *) (((s8 *) temp_v0) + 4)) = (u8) ((*((u8 *) (((s8 *) temp_v0) + 4))) - 1);
      *((s16 *) (((s8 *) temp_s0) + 8)) = -1;
      ((s16 *) D_801276D0)[0] -= 1;
    }
  }
}

void func_800A92A8(s32 param_0, s32 param_1)
{
  s32 *p;
 p = ((s32 *) D_801276D0); do { if (p[(0x58 / 4) & 0xFFFFFFFFFFFFFFFFu] != 0) {
      func_8010FE00(p[0x58 / 4], param_0, param_1);
      param_0 += 0;
    }
    p++;
  }
  while (p != (((s32 *) D_801276F0)));
}

void func_800A9318(s32 param_0)
{
  s32 local_0;
  s32* arr = (s32*)((int *) D_801276D0);
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (arr[local_0 + 0x58/4] != 0)
    {
      func_8010FE34(arr[local_0 + 0x58/4], param_0);
    }
  }
}

void func_800A9378(void) {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (((s32 *) D_801276D0)[i + 0x16]) {
            if (func_800A9420(i) != 0) {
                func_80110164(((s32 *) D_801276D0)[i + 0x16]);
            }
        }
    }
}

int func_800A93E4(s32 param_0)
{
  return D_80127728[param_0];
}

int func_800A93F8(s32 param_0)
{
  return D_80127708[param_0];
}

int func_800A940C(s32 param_0)
{
  return D_801276E8[param_0];
}

int func_800A9420(param_0) s32 param_0;
{
  return D_801276D0[param_0 + 0x38/4] == func_800A8984(D_801276D0[param_0 + 6]);
}

s16 func_800A9460()
{
  return ((s16 *) D_801276D0)[0];
}

s32 func_800A946C(void)
{
  return D_801276D2;
}

int func_800A9478(s32 param_0)
{
  s32 local_0;
  s32 local_2;
  s32 local_1;
  local_2 = -1;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (func_800F6438(local_0) && (D_801276D0[local_0 + 6] == param_0))
    {
      if (func_800A9420(local_0))
      {
        return local_0;
      }
      else
      {
        local_2 = local_0;
      }
    }
  }

  return local_2;
}

void func_800A9514(s32 param_0, s32 param_1) {
  s8 _sfpad[8];
    s32 sp4C;
    u8 *var_s0;
    f32 temp_f0;
    f32 var_f20;
    s32 temp_a0;

    var_f20 = 3.4028235e+38f;
    var_s0 = (u8 *)&D_801276D0; do {
        temp_a0 = *(s32 *)(var_s0 + 0x38);
        if (temp_a0 != 0) {
            func_800CA7E4(temp_a0, &sp4C);
            temp_f0 = func_800EEB40(&sp4C, param_1);
            if (temp_f0 < var_f20) {
                var_f20 = temp_f0;
                func_800EE7F8(param_0, &sp4C);
            }
        }
        var_s0 += 4;
    } while (var_s0 != (u8 *)&D_801276F0);
}

void func_800A95C4(void)
{
  s8 *var_s0;
  s8 *var_s2;
  s32 temp_v0;
  s32 temp_v0_2;
  s32 temp_a0;
 var_s2 = (s8 *) (&D_801276F0); var_s0 = (s8 *) (&D_801276D0); do { if ((*((s32 *) (var_s0 + 0x38))) != 0) { temp_v0 = *((s32 *) (var_s0 + 0x38));
      temp_v0_2 = func_800CA384(temp_v0);
      *((s32 *) (var_s0 + 0x38)) = temp_v0_2;
      if ((temp_v0_2 != temp_v0) && (func_800A8984(*((s32 *) (var_s0 + 0x18))) == temp_v0))
      {
        func_800A88C4(*((s32 *) (var_s0 + 0x18)), *((s32 *) (var_s0 + 0x38)));
      }
    }
    temp_a0 = *((s32 *) (var_s0 + 0x58));
    if (temp_a0 != 0)
    {
      *((s32 *) (var_s0 + ((0, 0x58)))) = func_80110068(temp_a0, *((s32 *) (var_s0 + 0x38)));
    }
    var_s0 = var_s0 + 4;
  }
  while (var_s0 != var_s2);
}

int func_800A965C()
{
  return 4 - D_801276D2;
}

s32 func_800A9670(s32 *param_0)
{
  s32 idx = 0;
 do { if (D_801276D4 == 0) { param_0[idx++] = 0; } if (D_801276D5 == 0) { param_0[idx++] = 1; } if (D_801276D6 == 0) { param_0[idx++] = 2; } if ((*((u8 *) D_801276D7)) == 0) { param_0[idx++] = 3; } } while (0);
  return idx;
}

s32 func_800A96F0(s32 param_0)
{
  s32 local_0;
  for (local_0 = 0; local_0 < 8; local_0++)
  {
    if (param_0 == ((s16 *) D_801276D0)[local_0 + 4])
    {
      return local_0;
    }
  }

  return -1;
}

s32 func_800A9768(s32 param_0) {
    u8 *var_v0;
    s32 var_v1;

    var_v0 = (u8 *)((u8 *) D_801276D0);
    var_v1 = 0;
loop_1:
    if (param_0 == (*(s16 *)(var_v0 + 8))) {
        return *(s32 *)((u8 *)&D_801276E8 + (var_v1 * 4));
    }
    if (param_0 == (*(s16 *)(var_v0 + 0xA))) {
        return *(s32 *)((u8 *)&D_801276EC + (var_v1 * 4));
    }
    if (param_0 == (*(s16 *)(var_v0 + 0xC))) {
        return *(s32 *)((u8 *)&D_801276F0 + (var_v1 * 4));
    }
    if (param_0 == (*(s16 *)(var_v0 + 0xE))) {
        return *(s32 *)((u8 *)&D_801276F4 + (var_v1 * 4));
    }
    var_v1 += 4;
    var_v0 += 8;
    if (var_v1 == 8) {
        return -1;
    }
    goto loop_1;
}

int func_800A9800()
{
  func_800A9828(0, 0, 0);
}

void func_800A9828(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    D_80127754 = param_0;
    if (param_1 != 0) {
        D_80127750 = param_1;
    } else {
        D_80127750 = 0x130;
    }
    if (param_2 != 0) {
        D_80127752 = param_2;
    } else {
        D_80127752 = 0xE4;
    }
    func_800E7F60();
    func_800A8D00(D_80127750, D_80127752);
}

int func_800A989C(void)
{
    return ((int) D_80127754) ? ((int) D_80127754) : func_80014F00();
}
