#include "core2/1E93440.h"

typedef struct { /* 0x00 */ u16 flags; /* 0x02 */ u8 pad02[2]; /* 0x04 */ u8 unk4; /* 0x05 */ u8 unk5; /* 0x06 */ u8 pad06[0x0C]; /* 0x12 */ s16 unk12[3]; /* 0x18 */ f32 unk18; /* 0x1C */ u8 pad1C[0x0C]; /* 0x28 */ s16 unk28[3]; /* 0x2E */ s16 unk2E[3]; /* 0x34 */ s16 unk34[3]; /* 0x3A */ s16 unk3A[3]; /* 0x40 */ s16 unk40[3]; /* 0x46 */ s16 unk46[3]; /* 0x4C */ s16 unk4C[3]; /* 0x52 */ u8 unk52; /* 0x53 */ u8 unk53; /* 0x54 */ u8 pad54[0x24]; /* 0x78 */ f32 unk78; /* 0x7C */ f32 unk7C; /* 0x80 */ u8 pad80[4]; /* 0x84 */ s16 unk84; /* 0x86 */ s16 unk86; /* 0x88 */ u8 pad88[0x12]; /* 0x9A */ s16 unk9A; /* 0x9C */ s16 unk9C; /* 0x9E */ s16 unk9E; /* 0xA0 */ s16 unkA0; /* 0xA2 */ s16 unkA2; /* 0xA4 */ s16 unkA4; /* 0xA6 */ u8 padA6[2]; /* 0xA8 */ u16 unkA8; /* 0xAA */ u8 padAA[0x1A]; /* 0xC4 */ s16 unkC4[3]; /* 0xCA */ s16 unkCA[3]; } Quelle;
typedef struct { /* 0x00 */ s16 unk0[3]; /* 0x06 */ s16 unk6[3]; /* 0x0C */ f32 unkC; /* 0x10 */ f32 unk10[3]; /* 0x1C */ f32 unk1C; /* 0x20 */ s16 unk20[3]; /* 0x26 */ s16 unk26[3]; /* 0x2C */ s16 unk2C; /* 0x2E */ s16 unk2E; /* 0x30 */ s16 unk30; /* 0x32 */ s16 unk32; /* 0x34 */ s16 unk34; /* 0x36 */ s16 unk36; /* 0x38 */ u8 unk38; /* 0x39 */ unsigned char active:1; unsigned char low:7; } Ziel;
s32 func_800DC128(s32, s32);
f32 func_800DC0C0(void);
s32 func_800F0E44(s32);
s32 func_800EEDA0();
void func_800EE88C();
void func_800EFE50(f32 *, f32 *, f32 *, f32);
void func_800EF214(f32 *, f32, f32, f32);
void func_800EF1B8(f32 *, f32, f32);
void func_800EF368(f32 *, f32);
void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
typedef struct { u8 b[60]; } Eintrag;
typedef struct { u8 pad00[7]; u8 unk7; u8 pad08[0x14]; f32 unk1C; u8 pad20[0x32]; u8 unk52; u8 unk53; u8 pad54[0x2C]; u8 unk80; u8 unk81; u8 unk82; u8 unk83; u8 pad84[8]; Eintrag *unk8C; Eintrag *unk90; Eintrag *unk94; u8 pad98[0x3C]; Eintrag unkD4[1]; } Obj;
void *heap_alloc(s32);
void rare_memset(void *, s32, s32);
int func_800EFA6C(s32, s16, s16, s16);
extern f32 func_800DC178(f32, f32);
void func_800EFA4C(s32 a, f32 b, f32 c, f32 d);
extern void func_800EE940();
extern int func_800DC298(f32);
s32 func_800B53A4(s32);
void func_800BA22C();
void func_800BA4C4(f32 *param_0, f32 param_1);
void func_800BA4D0();
int func_800BA54C();
int func_800BA554(f32 *param_0, f32 param_1, f32 param_2);
void func_800BA568();
void func_800BA7C4(s32 param_0, f32 param_1, f32 param_2);
void func_800BA894(f32 param_0[3], f32 param_1, f32 param_2);
void func_800BA8F8(s32 param_0, f32 param_1, f32 param_2);

void func_800B9B50(Quelle *param_0, Ziel *param_1)
{
  s32 local_0;
  f32 local_1[3];
  f32 local_2[3];
  f32 local_3[3];
  f32 local_4[3];
  f32 local_5[3];
  f32 local_6[3];
  f32 local_7[3];
  s32 local_8;
  f32 local_9;
  f32 local_10;
  s32 local_11;
  for (local_11 = 0; local_11 < 3; local_11++)
  {
    param_1->unk0[local_11] = func_800DC128(param_0->unk34[local_11], param_0->unk3A[local_11]);
  }

  param_1->unk38 = param_0->unkA8;
  if (param_0->unk18 == 0)
  {
    param_1->unkC = 1.0f;
  }
  else
  {
    param_1->unkC = 0.0f;
  }
  param_1->unk2C = func_800DC178((f32) param_0->unk84, (f32) param_0->unk86) * 256.0f;
  param_1->unk2E = func_800DC178(param_0->unk78, param_0->unk7C) * 256.0f;
  switch (param_0->unk5)
  {
    case 0:
      if (param_0->flags & 0x40)
    {
      func_800EE88C(local_1, param_0->unk28);
      func_800EE88C(local_2, param_0->unk2E);
      func_800EFE50(local_3, local_1, local_2, func_800DC0C0());
      func_800EE940(param_1->unk6, local_3);
    }
    else
    {
      for (local_11 = 0; local_11 < 3; local_11++)
      {
        param_1->unk6[local_11] = param_0->unk12[local_11] + func_800DC128(param_0->unk28[local_11], param_0->unk2E[local_11]);
      }

    }
      break;
 case 1: func_800EE88C(local_4, param_0->unk12); local_10 = func_800DC178(0.0f, 359.0f); local_9 = func_800DC178(0.0f, 359.0f); func_800EF214(local_4, local_10, local_9, (f32) func_800DC128(param_0->unk28[0], param_0->unk28[1])); func_800EE940(param_1->unk6, local_4); break; case 2: func_800EE88C(local_5, param_0->unk12); local_9 = func_800DC178(0.0f, 359.9f); func_800EF1B8(local_5, local_9, (f32) func_800DC128(param_0->unk28[0], param_0->unk28[1])); func_800EE940(param_1->unk6, local_5); param_1->unk6[1] = func_800DC128(param_0->unk2E[0], param_0->unk28[2]) + param_1->unk6[1]; break;

  }

  param_1->unk30 = func_800DC128(param_0->unk9A, param_0->unk9C);
  param_1->unk32 = param_1->unk30;
  if ((param_0->unk9E == 0) && (param_0->unkA0 == 0))
  {
    param_1->unk34 = 0;
  }
  else
  {
    param_1->unk34 = func_800DC128(param_0->unk9E, param_0->unkA0) - param_1->unk32;
  }
  if (param_0->flags & 0x400)
  {
    for (local_11 = 0; local_11 < 3; local_11++)
    {
      param_1->unk10[local_11] = func_800DC178(0.0, 360.0f);
    }

  }
  else
  {
    func_800EFA4C(param_1->unk10, (f32) param_0->unk4C[0], (f32) param_0->unk4C[1], (f32) param_0->unk4C[2]);
  }
  for (local_11 = 0; local_11 < 3; local_11++)
  {
    param_1->unk20[local_11] = func_800DC128(param_0->unk40[local_11], param_0->unk46[local_11]);
  }

  param_1->unk1C = 0.0f;
  param_1->unk36 = func_800DC128(param_0->unkA2, param_0->unkA4) + 1;
  switch (param_0->unk4)
  {
    case 0:
      for (local_11 = 0; local_11 < 3; local_11++)
    {
      param_1->unk26[local_11] = func_800DC128(param_0->unkC4[local_11], param_0->unkCA[local_11]);
    }

      break;

    case 1:
    {
      s32 local_12;
      s32 local_13;
      local_12 = func_800F0E44(param_0->unkC4[2] + func_800DC128(0, func_800F0E44(param_0->unkCA[0] - param_0->unkC4[2])));
      local_13 = func_800F0E44(param_0->unkC4[0] + func_800DC128(0, func_800F0E44(param_0->unkC4[1] - param_0->unkC4[0])));
      func_800EF4E4(local_6, (f32) local_12, (f32) local_13, 0.0f, 0.0f, (f32) func_800DC128(param_0->unkCA[1], param_0->unkCA[2]));
      func_800EE940(param_1->unk26, local_6);
    }
      break;

    case 2:
      if (func_800EEDA0(param_1->unk6, param_0->unkC4 + 2) == 0)
    {
      if (param_0->flags & 0x8000)
      {
        local_7[0] = (f32) (param_0->unkC4[2] - param_1->unk6[0]);
        local_7[1] = (f32) (param_0->unkCA[0] - param_1->unk6[1]);
        local_7[2] = (f32) (param_0->unkCA[1] - param_1->unk6[2]);
      }
      else
      {
        local_7[0] = (f32) (param_1->unk6[0] - param_0->unkC4[2]);
        local_7[1] = (f32) (param_1->unk6[1] - param_0->unkCA[0]);
        local_7[2] = (f32) (param_1->unk6[2] - param_0->unkCA[1]);
      }
      func_800EF368(local_7, func_800DC178((f32) param_0->unkC4[0], (f32) param_0->unkC4[1]));
      func_800EE940(param_1->unk26, local_7);
    }
    else
    {
      param_1->unk26[2] = 0;
      param_1->unk26[0] = param_1->unk26[2];
      param_1->unk26[1] = func_800DC128(param_0->unkC4[0], param_0->unkC4[1]);
    }
      break;

  }

  param_1->active = 1;
  if (param_0->flags & 8)
  {
    param_0->unk52 = 0;
  }
  if (param_0->flags & 0x10)
  {
    param_0->unk53 = 0;
  }
}

int func_800BA198(void *param_0)
{
  s32 local_0;
  int new_var;
  new_var = 0x8C;
  if ((param_0 != 0) && ((*((s32 *) (((char *) param_0) + 0x90))) != 0))
  {
    ;
    return ((*((s32 *) (((char *) param_0) + 0x90))) - (*((s32 *) (((char *) param_0) + new_var)))) / 0x3C;
  }
  return 0;
}

void func_800BA1D0(u8 *param_0, s32 param_1, u32 param_2, u32 param_3)
{
    *(u16 *)param_0 |= 0x40;
    func_800EE940(param_0 + 0x28, param_1);
    func_800EE940(param_0 + 0x2E, param_2);
    param_0[5] = 0;
    func_800BA22C(param_0, param_3);
}

void func_800BA22C(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 *local_0;
  local_0 = (s32 *) param_0;
  while (param_1 > 0)
  {
    s32 val = local_0[36];
    if ((u32)val < (u32)local_0[37])
    {
      local_0[36] = val + 0x3C;
      func_800B9B50(local_0, val);
    }
    param_1--;
  }
}

s32 func_800BA28C(u8 *param_0)
{
  s32 var_v0;
  var_v0 = (((s32) ((*((s32 *) (((u8 *) param_0) + 0x90))) - (*((s32 *) (((u8 *) param_0) + 0x8C))))) / 60) == 0;
  if (var_v0 != 0)
  {
    var_v0 = (*((u8 *) (((u8 *) param_0) + 7))) == 2;
    return (*((u8 *) (((u8 *) param_0) + 7))) == 2;
    var_v0 = (*((u8 *) (((u8 *) param_0) - -7))) == 2;
  }
}

int func_800BA2C4()
{
  heap_free();

  return 0;
}

Obj *func_800BA2E8(s32 param_0)
{
    Obj *p;

    p = heap_alloc(param_0 * 60 + 0xD4);
    rare_memset(p, 0, param_0 * 60 + 0xD4);
    p->unk7 = 2;
    p->unk80 = p->unk81 = p->unk82 = p->unk83 = 0xFF;
    p->unk1C = 1.0f;
    func_800BA4D0(p, -0x8000);
    func_800BA568(p, 0x7FFF);
    func_800BA894(p, 0.0f, 5.0f);
    func_800BA8F8(p, 0.0f, 5.0f);
    func_800BA4C4(p, 0.9f);
    func_800BA554(p, 1.0f, 1.0f);
    func_800BA7C4(p, 1.0f, 1.0f);
    p->unk8C = p->unkD4;
    p->unk90 = p->unkD4;
    p->unk94 = p->unk8C + param_0;
    p->unk52 = 1;
    p->unk53 = 1;
    return p;
}

void func_800BA3FC(s32 param_0, s32 param_1) {
    u8 *s0 = (u8 *) param_0;
    if (((u16 *)param_0)[1] != param_1) {
        *(u16 *)(param_0 + 2) = param_1;
        s0[0xA] = func_800D738C((u16)param_1);
        s0[0xB] = func_800AF5A0(func_800D674C(((u16 *)s0)[1]));
    }
}

void func_800BA450(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6; {
    func_800EFA6C(param_0 + 0x34, param_1, param_2, param_3);
    func_800EFA6C(param_0 + 0x3A, param_4, param_5, param_6);
}

int func_800BA4B0(u8 *param_0, unsigned int param_1)
{
  param_0[0x83] = param_1;
  if (param_1)
  {
  }
}

void func_800BA4B8(u8 *param_0, unsigned long param_1, s32 param_2)
{
  *((s16 *) (((u8 *) param_0) + 0xAA)) = param_1;
  *((s32 *) (((u8 *) param_0) + 0xBC)) = param_2;
}

void func_800BA4C4(f32 *param_0, f32 param_1)
{
  param_0[44] = param_1;
}

void func_800BA4D0(param_0, param_1) void * param_0; s16 param_1; {
    s16 sp1E;
    if (func_800B5698(&sp1E) != 0) {
        if (param_1 < sp1E) {
            param_1 = sp1E;
        }
        if (*(s16 *)((s8 *)param_0 + 0xA8) == 0) {
            func_800BA54C(param_0, 2);
        }
    }
    *(s16 *)((s8 *)param_0 + 0xAC) = param_1;
}

func_800BA544(void *param_0, s32 param_1){
    s32 local_0;
    local_0 = param_1;
    *(s32 *)((char *)param_0 + 0xC0) = local_0;
}

int func_800BA54C(param_0, param_1) s32 param_0; unsigned int param_1;
{
  *((s16 *) (param_0 + 0xA8)) = param_1;
}

int func_800BA554(f32 *param_0, f32 param_1, f32 param_2)
{
  unsigned int new_var;
  param_0[new_var = 45] = param_1;
  param_0[46] = param_2;
}

void func_800BA568(param_0, param_1) s32 param_0; s16 param_1; {
    *(s16 *)(param_0 + 0xae) = param_1;
}

int func_800BA574(s32 param_0)
{
  func_800EE814(param_0 + 0xC);
}

void func_800BA594(u8 *arg0, f32 arg1, f32 arg2) {
    *(f32 *)(arg0 + 0x18) = arg1;
    *(f32 *)(arg0 + 0x1C) = arg2;
}

int func_800BA5A8(s16 *param_0, unsigned int param_1)
{
  *param_0 = param_1;
}

void func_800BA5B0(s32 param_0, int param_1, int param_2)
{
  *((s16 *) (((char *) param_0) + 0x84)) = param_1;
  *((s16 *) (((char *) param_0) + 0x86)) = param_2;
}

int func_800BA5BC(f32 *param_0, f32 param_1, f32 param_2)
{
  int new_var;
  new_var = (0xFFFFFFFF & 0xFFFFFFFF) & 0xFFFFFFFF;
  param_0[30] = param_1 * 1.0f;
  param_0[31] = param_2;
}

void func_800BA5D0(u8 *arg0, s16 arg1)
{
  u32 var_v0;
 var_v0 = *((u32 *) (arg0 + 0x8C)); *((s16 *) (arg0 + 0x14)) = arg1; if (var_v0 < (*((u32 *) (arg0 + 0x90)))) {
    do
    {
      *((s16 *) (var_v0 + 8)) = arg1;
      var_v0 += 0x3C;
    }
    while (var_v0 < (*((u32 *) (arg0 + 0x90))));
  }
}

int func_800BA610(param_0, param_1, param_2) s32 param_0; s16 param_1; s16 param_2;
{
  func_800EFA6C(param_0 + 0x34, 0, param_1, 0);
  func_800EFA6C(param_0 + 0x3A, 0, param_2, 0);
}

func_800BA660(s32 param_0[2], s32 param_1, s16 param_2){
    param_0[0x22] = param_1;
    ((s16*)param_0)[0x4C] = param_2;
}

void func_800BA670(s32 param_0, s32 param_1)
{
    u16 *ptr = (u16 *)param_0;
    if (ptr[1] != param_1) {
        ptr[1] = param_1;
        *(u8 *)(ptr + 5) = func_800D738C((u16)param_1);
    }
    return;
}

int func_800BA6B0(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6;
{
  char new_var;
  *((u8 *) (param_0 + 5)) = 0;
  func_800EFA6C(param_0 + 0x28, param_1, param_2, param_3);
  ;
  func_800EFA6C(param_0 + (0x2e ^ 0), param_4, param_5, param_6);
}

func_800BA714(u8 volatile *param_0, s16 param_1, s16 param_2) {
    u8 local_0 = 1;
    param_0[5] = local_0;
    *(s16 *)(param_0 + 0x28) = param_1;
    *(s16 *)(param_0 + 0x2A) = param_2;
}

void func_800BA730(void *param_0, s16 param_1, s16 param_2, s16 param_3, s16 param_4) {
    *(u8 *)((char *)param_0 + 5) = 2;
    *(s16 *)((char *)param_0 + 0x28) = param_1;
    *(s16 *)((char *)param_0 + 0x2A) = param_2;
    *(s16 *)((char *)param_0 + 0x2C) = param_3;
    *(s16 *)((char *)param_0 + 0x2E) = param_4;
}

int func_800BA75C(s32 param_0)
{
  func_800EE940(param_0 + 0x12);
}

void func_800BA77C(param_0, param_1, param_2, param_3) s32 param_0; s16 param_1; s16 param_2; s16 param_3;
{
    func_800EFA6C(param_0 + 0x4C, param_1, param_2, param_3);
}

void func_800BA7C4(s32 param_0, f32 param_1, f32 param_2) {
    s16 local_0;
    s16 local_1;

    local_0 = param_1 * 256.0f;
    local_1 = param_2 * 256.0f;
    *(s16 *)(param_0 + 0x9A) = local_0;
    *(s16 *)(param_0 + 0x9C) = local_1;
}

void func_800BA7FC(s32 param_0, f32 param_1, f32 param_2)
{
  s32 local_0;
  s32 local_1;
  local_0 = param_1 * 256.0f;
  local_1 = param_2 * 256.0f;
  *((s16 *) (param_0 + 0x9E)) = local_0;
  *((s16 *) (param_0 - -0xA0)) = local_1;
}

int func_800BA834(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6;
{
  func_800EFA6C(param_0 + 0x40, param_1, param_2, param_3);
  func_800EFA6C(param_0 + 0x46, param_4, param_5, param_6);
}

void func_800BA894(f32 param_0[3], f32 param_1, f32 param_2)
{
  f32 local_0;
  ;
  param_0[21] = param_1;
  param_0[22] = param_2;
  if ((0.0f == param_0[8]) || (param_2 < param_0[8]))
  {
    local_0 = func_800DC178(param_0[21], param_0[22]);
    param_0[8] = local_0;
  }
}

void func_800BA8F8(s32 param_0, f32 param_1, f32 param_2) {
    s16 local_0;
    s16 local_1;

    local_0 = param_1 * 256.0f;
    local_1 = param_2 * 256.0f;
    *(s16 *)(param_0 + 0xA2) = local_0;
    *(s16 *)(param_0 + 0xA4) = local_1;
}

void func_800BA930(param_0, param_1, param_2, param_3, param_4, param_5, param_6) s32 param_0; s16 param_1; s16 param_2; s16 param_3; s16 param_4; s16 param_5; s16 param_6;
{
  *((s8 *) (((s8 *) param_0) + 4)) = 0;
  func_800EFA6C(param_0 + 0xC4, param_1, param_2, param_3);
  func_800EFA6C(param_0 + 0xCA, param_4, param_5, param_6);
}

void func_800BA994(u8 *param_0, s16 param_1, s16 param_2, s16 param_3, s16 param_4, s16 param_5, s16 param_6) {
    f32 func_800136E4(f32);
    (*(s8 *)((s8 *)(param_0) + (4))) = 1;
    (*(s16 *)((s8 *)(param_0) + (0xC4))) = (s16)(s32)func_800136E4((f32)param_2);
    (*(s16 *)((s8 *)(param_0) + (0xC6))) = (s16)(s32)func_800136E4((f32)param_5);
    (*(s16 *)((s8 *)(param_0) + (0xC8))) = (s16)(s32)func_800136E4((f32)param_1);
    (*(s16 *)((s8 *)(param_0) + (0xCA))) = (s16)(s32)func_800136E4((f32)param_4);
    (*(s16 *)((s8 *)(param_0) + (0xCC))) = param_3;
    (*(s16 *)((s8 *)(param_0) + (0xCE))) = param_6;
}

void func_800BAA60(s16 *param_0, s32 param_1, s16 param_2, s16 param_3)
{
  *(s8 *)(param_0 + 2) = 2;
  *(s16 *)(param_0 + 0x62) = param_2;
  *(s16 *)(param_0 + 0x63) = param_3;
  func_800EE940((s32 *)(param_0 + 0x64), param_1);
}

void func_800BAA9C(s32 param_0, f32 param_1)
{
    func_800BA7C4(param_0, param_1, param_1);
    func_800BA7FC(param_0, param_1, param_1);
}

void func_800BAAE4(s32 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    func_800EFA4C(param_0 + 0x6C, param_1, param_2, param_3);
}

void func_800BAB1C(s32 param_0, f32 param_1, f32 param_2, f32 param_3) {
    func_800EFA4C(param_0 + 0x60, param_1, param_2, param_3);
}

void func_800BAB54(f32 *param_0, f32 param_1)
{
  param_0[23] = param_1;
}

int func_800BAB60(s32 param_0)
{
  func_800F2EA0(param_0 + 0x80);
}

int func_800BAB80(s32 param_0)
{
  func_800F2EBC(param_0 + 0x80);
}

func_800BABA0(s32 param_0, f32 param_1) {
    ((f32*)((s8*)param_0 + 36))[0] = param_1;
    ((s8*)param_0)[7] = 0;
}

void func_800BABB0(s32 arg0) 
{
}
s32 func_800BABB8(s32 param_0, f32 *param_1, f32 *param_2, f32 param_3, s32 *param_4)
{
    /* Keep declaration order and types: IDO's stack layout depends on them.
     * local_78 is the command word; local_85 is its opcode.
     * local_22 is the scale selected by command 0x13.
     * local_0 defers the func_800BA22C call until the stream has finished.
     */
    f32 local_1;
    f32 local_2;
    s32 local_0;
    f32 local_3;
    f32 local_7;
    f32 local_10;
    f32 local_12;
    f32 local_13;
    f32 local_14;
    f32 local_16;
    f32 local_18;
    f32 local_9;
    f32 local_19;
    f32 local_20;
    f32 local_21;
    f32 local_22;
    s16 local_24;
    s16 local_25;
    s16 local_26;
    s16 local_27;
    s16 local_28;
    s16 local_29;
    s16 local_30;
    s16 local_31;
    s16 local_32;
    s16 local_33;
    s16 local_34;
    s16 local_35;
    s16 local_36;
    s16 local_37;
    s16 local_38;
    s16 local_39;
    s16 local_40;
    s16 local_41;
    f32 local_42;
    f32 local_43;
    s16 local_44;
    s16 local_45;
    s16 local_46;
    f32 local_47;
    s16 local_48;
    s16 local_49;
    f32 local_50;
    s16 local_51;
    s16 local_52;
    s16 local_53;
    f32 local_54;
    f32 local_55;
    s16 local_56;
    f32 local_57;
    f32 local_58;
    s16 local_59;
    f32 local_60;
    s16 local_61;
    f32 local_62;
    f32 local_63;
    f32 local_64;
    s16 local_65;
    s16 local_66;
    s16 local_67;
    s16 local_68;
    s16 local_69;
    s16 local_70;
    s16 local_71;
    s16 local_72;
    s16 local_73;
    s16 local_74;
    s16 local_75;
    s16 local_76;
    s16 local_77;
    s16 local_78;
    s32 local_79;
    s32 local_80;
    f32 local_17;
    f32 local_15;
    s32 local_81;
    s32 local_82;
    s32 local_83;
    s32 local_84;
    s32 local_85;
    f32 local_4;
    f32 local_5;
    f32 local_6;
    f32 local_11;
    s32 local_86;
    s32 local_87;
    u8 local_88;
    u8 *local_89;
    u8 *local_90;
    u8 *local_8;
    u8 *local_91;
    u8 *local_92;
    u8 *local_93;
    u8 *local_94;
    u8 *local_95;
    u8 *local_97;
    u8 *local_98;
    local_22 = 1.0f;
    local_0 = 0;
    if ((param_0 != 0) && (param_1 != 0))
    {
        func_800EE940(param_0 + 0x12, param_1);
    }
    if (param_4 == 0)
    {
        return (s32)param_0;
    }
    {
        local_78 = *(s16 *)param_4;
        param_4 = (s32 *)((u8 *)param_4 + 2);
        if (local_78 != 0)
        {
            do
            {
                local_85 = local_78 & 0xFF;
                switch (local_85)
                {
                case 0x1:
                    /* Read two scaled three-component bounds at 0x34 and 0x3A. */
                    local_86 = 0;
                    local_89 = (u8 *)param_0;
                    for (; local_86 < 3; local_86++)
                    {
                        *(s16 *)(local_89 + 52) = (s16)(s32)((f32)*(s16 *)param_4 * local_22);
                        *(s16 *)(local_89 + 58) = (s16)(s32)((f32)*(s16 *)((u8 *)param_4 + 6) * local_22);
                        local_89 += 2;
                        param_4 = (s32 *)((u8 *)param_4 + 2);
                    }
                    param_4 = (s32 *)((u8 *)param_4 + 6);
                    break;

                case 0x2:
                    /* Set the fourth color byte from the command immediate. */
                    *(u8 *)(param_0 + 0x83) = (s8)(((s32)(local_78 & 0xFF00)) >> 8);
                    break;

                case 0x3:
                    *(s16 *)(param_0 + 0xAA) = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s32 *)(param_0 + 0xBC) = *(s16 *)((u8 *)param_4 - 2);
                    break;

                case 0x4:
                    local_62 = (f32)*(s16 *)param_4 * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(f32 *)(param_0 + 176) = local_62;
                    break;

                case 0x5:
                    local_68 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(s16 *)(param_0 + 0xAC) = local_68;
                    break;

                case 0x6:
                    local_69 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(s16 *)(param_0 + 0xAC) =
                        (s16)((s32)((*((f32 *)(((s8 *)param_1) + 4))) + ((f32)local_69)));
                    break;

                case 0x7:
                    *(s16 *)(param_0 + 0xA8) = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    break;

                case 0x8:
                    local_42 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_47 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(f32 *)(param_0 + 180) = local_42;
                    *(f32 *)(param_0 + 184) = local_47;
                    break;

                case 0x9:
                    local_70 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(s16 *)(param_0 + 0xAE) = local_70;
                    break;

                case 0xA:
                    /* Read two vectors scaled by the caller, selecting mode 0. */
                    local_87 = 0;
                    local_89 = (u8 *)param_0;
                    for (; local_87 < 3; local_87++)
                    {
                        *(s16 *)(local_89 + 40) = (s16)(s32)((f32)*(s16 *)param_4 * param_3);
                        *(s16 *)(local_89 + 46) = (s16)(s32)((f32)*(s16 *)((u8 *)param_4 + 6) * param_3);
                        local_89 += 2;
                        param_4 = (s32 *)((u8 *)param_4 + 2);
                    }
                    *(s8 *)(param_0 + 5) = 0;
                    param_4 = (s32 *)((u8 *)param_4 + 6);
                    break;

                case 0xB:
                    *(s8 *)(param_0 + 5) = 2;
                    *(s16 *)(param_0 + 0x28) = (s16)((f32)*(s16 *)param_4 * param_3);
                    param_4 = (s32 *)((u8 *)param_4 + 8);
                    *(s16 *)(param_0 + 42) = (s16)((f32)*(s16 *)((u8 *)param_4 - 6) * param_3);
                    *(s16 *)(param_0 + 44) = (s16)((f32)*(s16 *)((u8 *)param_4 - 4) * param_3);
                    *(s16 *)(param_0 + 46) = (s16)((f32)*(s16 *)((u8 *)param_4 - 2) * param_3);
                    break;

                case 0xC:
                    /* Construct symmetric bounds from one scaled magnitude. */
                    local_9 = (f32)*(s16 *)param_4;
                    *(s8 *)(param_0 + 5) = 0;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    local_9 *= param_3;
                    local_81 = (s32)-local_9;
                    func_800EFA6C(param_0 + 0x28, (s16)local_81, (s16)local_81, (s16)local_81);
                    local_79 = (s32)local_9;
                    func_800EFA6C(param_0 + 0x2E, (s16)local_79, (s16)local_79, (s16)local_79);
                    break;

                case 0xD:
                    local_35 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(s8 *)(param_0 + 5) = 0;
                    local_35 = (s32)(((f32)local_35) * param_3);
                    local_24 = -((s16)local_35);
                    func_800EFA6C(param_0 + 0x28, local_24, 0, local_24);
                    func_800EFA6C(param_0 + 0x2E, (s16)local_35, (s16)local_35, (s16)local_35);
                    break;

                case 0xE:
                    *(s8 *)(param_0 + 5) = 1;
                    *(s16 *)(param_0 + 0x28) = (s16)((f32)*(s16 *)param_4 * param_3);
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 42) = (s16)((f32)*(s16 *)((u8 *)param_4 - 2) * param_3);
                    break;

                case 0xF:
                    *(s8 *)(param_0 + 7) = 1;
                    *(f32 *)(param_0 + 0x20) =
                        func_800DC178(*(f32 *)(param_0 + 0x54), *(f32 *)(param_0 + 0x58));
                    break;

                case 0x10:
                    /* Allocate/replace the current object and apply the optional position. */
                    local_94 = func_800B53A4(((s32)(local_78 & 0xFF00)) >> 8);
                    param_0 = local_94;
                    if (param_1 != 0)
                    {
                        func_800EE940(local_94 + 0x12, param_1);
                    }
                    break;

                case 0x11:
                    /* As above, also retain the immediate for the final func_800BA22C call. */
                    local_84 = ((s32)(local_78 & 0xFF00)) >> 8;
                    local_0 = local_84;
                    local_95 = func_800B53A4(local_84);
                    param_0 = local_95;
                    if (param_1 != 0)
                    {
                        func_800EE940(local_95 + 0x12, param_1);
                    }
                    break;

                case 0x12:
                    /* Copy three halfwords, then skip three more payload halfwords. */
                    local_25 = *(s16 *)(((u8 *)param_4) + 0);
                    local_26 = *(s16 *)(((u8 *)param_4) + 2);
                    local_27 = *(s16 *)(((u8 *)param_4) + 4);
                    param_4 = (s32 *)((u8 *)param_4 + 6);
                    func_800EFA6C(param_0 + 0xC, local_25, local_26, local_27);
                    param_4 = (s32 *)((u8 *)param_4 + 6);
                    break;

                case 0x13:
                    /* Enable or disable caller scaling for subsequent selected commands. */
                    if ((((s32)(local_78 & 0xFF00)) >> 8) != 0)
                    {
                        local_22 = param_3;
                    }
                    else
                    {
                        local_22 = 1.0f;
                    }
                    break;

                case 0x14:
                    /* Install a preset; field meanings beyond the offsets remain unconfirmed. */
                    *(s16 *)(param_0 + 0) = 0x586;
                    *(f32 *)(param_0 + 0xB0) = 0.4f;
                    *(f32 *)(param_0 + 0x18) = 0.0f;
                    *(s16 *)(param_0 + 0xA8) = 4;
                    *(s16 *)(param_0 + 0xA2) = 0x300;
                    *(s16 *)(param_0 + 0xA4) = 0x400;
                    *(f32 *)(param_0 + 0x1C) = 0.8f;
                    local_8 = param_0 + 0x34;
                    func_800EFA6C(param_0 + 0x40, 0xC8, 0, 0xC8);
                    func_800EFA6C(param_0 + 0x46, 0x190, 0, 0x190);
                    func_800EFA6C(local_8, 0, -0x3E8, 0);
                    func_800EFA6C(param_0 + 0x3A, 0, -0x320, 0);
                    break;

                case 0x15:
                    local_63 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_64 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(f32 *)(param_0 + 24) = local_63;
                    *(f32 *)(param_0 + 28) = local_64;
                    break;

                case 0x16:
                    *(s16 *)param_0 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    break;

                case 0x17:
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    if (func_800DC298((f32)*(s16 *)((u8 *)param_4 - 2) * 0.00390625f) != 0)
                    {
                        *(s16 *)param_0 = (u16) * (s16 *)param_0 | 0x800;
                    }
                    break;

                case 0x18:
                    local_16 = (f32)*(s16 *)((u8 *)param_4 + 4) * 0.00390625f;
                    local_18 = (f32)*(s16 *)((u8 *)param_4 + 6) * 0.00390625f;
                    local_72 = *(s16 *)param_4;
                    local_73 = *(s16 *)((u8 *)param_4 + 2);
                    *(s16 *)(param_0 + 0x86) = local_73;
                    param_4 = (s32 *)((u8 *)param_4 + 8);
                    *(s16 *)(param_0 + 0x84) = local_72;
                    *(f32 *)(param_0 + 0x78) = local_16;
                    *(f32 *)(param_0 + 0x7C) = local_18;
                    break;

                case 0x19:
                    local_72 = *(s16 *)param_4;
                    local_73 = *(s16 *)((u8 *)param_4 + 2);
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 0x86) = local_73;
                    *(s16 *)(param_0 + 0x84) = local_72;
                    break;

                case 0x1A:
                    func_800BA22C(param_0, ((s32)(local_78 & 0xFF00)) >> 8);
                    break;

                case 0x1B:
                    func_800EFA6C(param_0 + 0x34, 0, (s16)((s32)(((f32)(*(s16 *)param_4)) * local_22)), 0);
                    func_800EFA6C(param_0 + 0x3A, 0,
                                  (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 + 2))) * local_22)), 0);
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    break;

                case 0x1C:
                    local_92 = func_800BA2E8(((s32)(local_78 & 0xFF00)) >> 8);
                    param_0 = local_92;
                    if (param_1 != 0)
                    {
                        func_800EE940(local_92 + 0x12, param_1);
                    }
                    break;

                case 0x1D:
                    /* Only refresh resource metadata when the resource ID changes. */
                    local_65 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    /* Keep the early exit: its branch shape is match-sensitive. */
                    if (local_65 == *(u16 *)(param_0 + 2))
                    {
                        break;
                    }
                    {
                        *(u16 *)(param_0 + 2) = (u16)local_65;
                        *(u8 *)(param_0 + 0xA) = func_800D738C(local_65 & 0xFFFF);
                        if (*(u8 *)(param_0 + 0xA) == 7)
                        {
                            *(s8 *)(param_0 + 0xB) = func_800AF5A0(func_800D674C(*(u16 *)(param_0 + 2)));
                        }
                    }
                    break;

                case 0x1E:
                    *(s16 *)(param_0 + 0x14) +=
                        (s16)(param_3 *
                              func_800DC178((f32)*(s16 *)param_4, (f32)*(s16 *)((u8 *)param_4 + 2)));
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    break;

                case 0x1F:
                    /* Unpack three color bytes from two payload halfwords. */
                    local_66 = *(s16 *)param_4;
                    local_74 = *(s16 *)((u8 *)param_4 + 2);
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    func_800F31EC(param_0 + 0x80, ((u32)(local_66 & 0xFF00)) >> 8, local_66 & 0xFF,
                                  ((u32)(local_74 & 0xFF00)) >> 8);
                    break;

                case 0x20:
                    /* Unpack all four color bytes from two payload halfwords. */
                    local_67 = *(s16 *)param_4;
                    local_75 = *(s16 *)((u8 *)param_4 + 2);
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    func_800F31FC(param_0 + 0x80, ((u32)(local_67 & 0xFF00)) >> 8, local_67 & 0xFF,
                                  ((u32)(local_75 & 0xFF00)) >> 8, local_75 & 0xFF);
                    break;

                case 0x21:
                    local_25 = *(s16 *)param_4;
                    local_26 = *(s16 *)((u8 *)param_4 + 2);
                    local_27 = *(s16 *)((u8 *)param_4 + 4);
                    param_4 = (s32 *)((u8 *)param_4 + 6);
                    func_800EFA6C(param_0 + 0x4C, local_25, local_26, local_27);
                    break;

                case 0x22:
                    /* Decode, scale, then re-encode four fixed-point values in order. */
                    local_1 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_2 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    local_3 = (f32)*(s16 *)((u8 *)param_4 + 4) * 0.00390625f;
                    local_7 = (f32)*(s16 *)((u8 *)param_4 + 6) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 8);
                    *(s16 *)(param_0 + 0x9a) = (s16)(s32)((local_1 * param_3) * 256.0f);
                    *(s16 *)(param_0 + 0x9c) = (s16)(s32)((local_2 * param_3) * 256.0f);
                    *(s16 *)(param_0 + 0x9e) = (s16)(s32)((local_3 * param_3) * 256.0f);
                    *(s16 *)(param_0 + 0xa0) = (s16)(s32)((local_7 * param_3) * 256.0f);
                    break;

                case 0x23:
                    local_1 = (f32)*(s16 *)param_4 * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    local_1 = (local_1 * param_3) * 256.0f;
                    local_83 = (s32)local_1;
                    *(s16 *)(param_0 + 0x9a) = (s16)local_83;
                    *(s16 *)(param_0 + 0x9c) = (s16)local_83;
                    *(s16 *)(param_0 + 0x9e) = (s16)local_83;
                    *(s16 *)(param_0 + 0xa0) = (s16)local_83;
                    break;

                case 0x24:
                    local_1 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_2 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 0x9a) = (s16)(s32)((local_1 * param_3) * 256.0f);
                    *(s16 *)(param_0 + 0x9c) = (s16)(s32)((local_2 * param_3) * 256.0f);
                    break;

                case 0x25:
                    local_1 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_2 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 0x9e) = (s16)(s32)((local_1 * param_3) * 256.0f);
                    *(s16 *)(param_0 + 0xa0) = (s16)(s32)((local_2 * param_3) * 256.0f);
                    break;

                case 0x26:
                    func_800EFA6C(param_0 + 0x40, *(s16 *)param_4, *(s16 *)((u8 *)param_4 + 2),
                                  *(s16 *)((u8 *)param_4 + 4));
                    func_800EFA6C(param_0 + 0x46, *(s16 *)((u8 *)param_4 + 6), *(s16 *)((u8 *)param_4 + 8),
                                  *(s16 *)((u8 *)param_4 + 0xA));
                    param_4 = (s32 *)((u8 *)param_4 + 0xC);
                    break;

                case 0x27:
                    func_800EFA6C(param_0 + 0x40, *(s16 *)param_4, 0, *(s16 *)((u8 *)param_4 + 2));
                    func_800EFA6C(param_0 + 0x46, *(s16 *)((u8 *)param_4 + 4), 0,
                                  *(s16 *)((u8 *)param_4 + 6));
                    param_4 = (s32 *)((u8 *)param_4 + 8);
                    break;

                case 0x28:
                    local_1 = (f32)*(s16 *)param_4 * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    func_800BABA0(param_0, local_1);
                    break;

                case 0x29:
                    func_800B5534(param_0);
                    break;

                case 0x2A:
                    /* Replace the range and resample if the current value is zero or too large. */
                    local_12 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_14 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    local_17 = (f32)*(s16 *)((u8 *)param_4 + 4) * 0.00390625f;
                    local_15 = (f32)*(s16 *)((u8 *)param_4 + 6) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 8);
                    *(f32 *)(param_0 + 0x54) = local_12;
                    *(f32 *)(param_0 + 0x58) = local_14;
                    if (*(f32 *)(param_0 + 0x20) == 0.0f || local_14 < *(f32 *)(param_0 + 0x20))
                    {
                        local_2 = local_17;
                        local_3 = local_15;
                        *(f32 *)(param_0 + 0x20) = func_800DC178(local_12, local_14);
                    }
                    *(s16 *)(param_0 + 0xA2) = (s16)(s32)(local_17 * 256.0f);
                    *(s16 *)(param_0 + 0xA4) = (s16)(s32)(local_15 * 256.0f);
                    break;

                case 0x2B:
                    local_58 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_60 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 0xA2) = (s16)(s32)(local_58 * 256.0f);
                    *(s16 *)(param_0 + 0xA4) = (s16)(s32)(local_60 * 256.0f);
                    break;

                case 0x2C:
                    *(s8 *)(param_0 + 4) = 0;
                    *(s16 *)(param_0 + 0xC4) = (s16)(s32)((f32)*(s16 *)param_4 * local_22);
                    param_4 = (s32 *)((u8 *)param_4 + 12);
                    *(s16 *)(param_0 + 0xC6) =
                        (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 0xA))) * local_22));
                    *(s16 *)(param_0 + 0xC8) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 8))) * local_22));
                    *(s16 *)(param_0 + 0xCA) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 6))) * local_22));
                    *(s16 *)(param_0 + 0xCC) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 4))) * local_22));
                    *(s16 *)(param_0 + 0xCE) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 2))) * local_22));
                    break;

                case 0x2D:
                    /* Select mode 2 and copy the caller vector into the field at 0xC8. */
                    *(s8 *)(param_0 + 4) = 2;
                    *(s16 *)(param_0 + 0xC4) = (s16)(s32)((f32)*(s16 *)param_4 * local_22);
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 0xC6) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 2))) * local_22));
                    func_800EE940(param_0 + 0xC8, param_2);
                    break;

                case 0x2E:
                    *(s8 *)(param_0 + 4) = 1;
                    *(s16 *)(param_0 + 0xC8) = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 12);
                    *(s16 *)(param_0 + 0xC4) = (s16)(*(s16 *)((u8 *)param_4 - 0xA));
                    *(s16 *)(param_0 + 0xCC) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 8))) * local_22));
                    *(s16 *)(param_0 + 0xCA) = (s16)(*(s16 *)((u8 *)param_4 - 6));
                    *(s16 *)(param_0 + 0xC6) = (s16)(*(s16 *)((u8 *)param_4 - 4));
                    *(s16 *)(param_0 + 0xCE) = (s16)((s32)(((f32)(*(s16 *)((u8 *)param_4 - 2))) * local_22));
                    break;

                case 0x2F:
                    /* Read two scaled float vectors and a separate unscaled scalar. */
                    local_1 = (f32)*(s16 *)param_4 * 0.00390625f;
                    local_2 = (f32)*(s16 *)((u8 *)param_4 + 2) * 0.00390625f;
                    local_3 = (f32)*(s16 *)((u8 *)param_4 + 4) * 0.00390625f;
                    local_4 = (f32)*(s16 *)((u8 *)param_4 + 6) * 0.00390625f;
                    local_5 = (f32)*(s16 *)((u8 *)param_4 + 8) * 0.00390625f;
                    local_6 = (f32)*(s16 *)((u8 *)param_4 + 10) * 0.00390625f;
                    local_11 = (f32)*(s16 *)((u8 *)param_4 + 12) * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 14);
                    func_800EFA4C((f32 *)(param_0 + 0x6C), local_1 * param_3, local_2 * param_3,
                                  local_3 * param_3);
                    func_800EFA4C((f32 *)(param_0 + 0x60), local_4 * param_3, local_5 * param_3,
                                  local_6 * param_3);
                    *(f32 *)(param_0 + 0x5C) = local_11;
                    break;

                case 0x30:
                    local_54 = (f32)*(s16 *)param_4 * 0.00390625f;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(f32 *)(param_0 + 208) = local_54;
                    break;

                case 0x31:
                    local_80 = func_800DC128(*(s16 *)param_4, *(s16 *)((u8 *)param_4 + 2));
                    param_4 = (s32 *)((u8 *)param_4 + 4);
                    *(s16 *)(param_0 + 0xCA) += (s16)(param_3 * (f32)local_80);
                    break;

                case 0x32:
                    /* Keep the explicit low-byte mask before narrowing: it affects IDO codegen. */
                    local_46 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(s8 *)(param_0 + 0x52) = (s8)(local_46 & 0xFF);
                    break;

                case 0x33:
                    /* The same low-byte conversion for the adjacent field. */
                    local_52 = *(s16 *)param_4;
                    param_4 = (s32 *)((u8 *)param_4 + 2);
                    *(s8 *)(param_0 + 0x53) = (s8)(local_52 & 0xFF);
                    break;

                case 0x34:
                    /* Reset color and three vector ranges. Keep this loop: IDO unrolls it
                     * with the register allocation and store order required by the target. */
                    for (local_86 = 0; local_86 < 4; local_86++)
                    {
                        ((u8 *)param_0)[0x80 + local_86] = 255;
                    }
                    func_800BA930(param_0, 0, 0, 0, 0, 0, 0);
                    func_800BA450(param_0, 0, 0, 0, 0, 0, 0);
                    func_800BA834(param_0, 0, 0, 0, 0, 0, 0);
                    break;
                }

                local_78 = *(s16 *)((u8 *)param_4);
                param_4 = (s32 *)((u8 *)param_4 + 2);
            } while (local_78 != 0);
        }
        if (local_0 != 0)
        {
            func_800BA22C(param_0, local_0);
        }
    }
    return param_0;
}

s32 func_800BBCB8(f32 param_0[3], s32 param_1, f32 param_2, s32 param_3,
                  s32 *param_4)
{
    s32 local_0;

    local_0 = func_800B53A4(param_3);
    func_800BABB8(local_0, param_0, param_1, param_2, param_4);
    func_800BA22C(local_0, param_3);
    return local_0;
}

int func_800BBD18(s32 param_0, s32 param_1, s32 param_2, f32 param_3, s32 param_4)
{
  if (param_0 != 0)
  {
    func_800BABB8(param_0, param_1, param_2, param_3, param_4);
    func_800B4790(param_0);
  }
}
