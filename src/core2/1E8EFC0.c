#include "common.h"

typedef struct { f32 local_0; s32 local_1; unsigned local_2:1; unsigned local_3:10; unsigned local_4:21; } local_type_800B56D0;
typedef struct {s32 local_0, local_1; u32 local_2:1; u32 local_3:10; u32 local_4:21;} local_type_800B5758;
extern local_type_800B5758 D_80127F28[45];
typedef struct { int unk0; int unk4; int unk8; } Struct800B5824;
extern Struct800B5824 D_80127F34[528];
typedef struct { u8 pad0[8]; u8 unk8; u8 pad9[3]; } Sub_B5884;
typedef struct { Sub_B5884 sub[4]; } E_B5884;
typedef struct { u8 pad0[4]; void *unk4; u8 unk8; u8 pad9[3]; } S_B58D4;
extern void func_800B5450();
extern u32 D_80128144[];
extern f32 func_800D8FF8(void);
extern int func_800BA28C(u32);
extern u8 D_80127F20[];
extern s32 func_800B5548(s32);
void func_800B58D4();

s32 func_800B56D0(param_0) u8 param_0; {
    if (((local_type_800B56D0 *) D_80127F28)[param_0].local_1 == 0) {
        (*((u8 *) D_80127F20)) = param_0;
        ((local_type_800B56D0 *) D_80127F28)[param_0].local_1 = func_800B53A4(((local_type_800B56D0 *) D_80127F28)[param_0].local_3);
        func_800B5534(((local_type_800B56D0 *) D_80127F28)[param_0].local_1);
        (*((u8 *) D_80127F20)) = 0;
    }
    ((local_type_800B56D0 *) D_80127F28)[param_0].local_0 = 1.0f;
    return ((local_type_800B56D0 *) D_80127F28)[param_0].local_1;
}

u8 func_800B5758(s32 param_0) {
    s32 local_0;
    for (local_0 = 1; local_0 < 45; local_0++) {
        if (!D_80127F28[local_0].local_2) {
            D_80127F28[local_0].local_2++;
            D_80127F28[local_0].local_1 = 0;
            D_80127F28[local_0].local_3 = param_0;
            return local_0;
        }
    }
    return 0;
}

void func_800B5824()
{
  int local_0;
  Struct800B5824 *local_1;
  local_1 = D_80127F34;
  for (local_0 = 1; local_0 < 0x2D; local_0++)
  {
    if ((u32) local_1->unk8 >> 31)
    {
      func_800B58D4(local_0 & 0xFF);
    }
    local_1++;
  }
}

void func_800B5884(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 11; i++) {
        for (j = 0; j < 4; j++) {
            ((E_B5884 *) D_80127F34)[i].sub[j].unk8 &= 0xFF7F;
        }
    }
}

void func_800B58D4(param_0) u8 param_0; {
    if (((S_B58D4 *) D_80127F28)[param_0].unk4 != 0) { func_800B5450(((S_B58D4 *) D_80127F28)[param_0].unk4); }
    ((S_B58D4 *) D_80127F28)[param_0].unk8 &= ~0x80;
}

void func_800B592C(void)
{
  u32 *local_0;
  u32 *local_1;
  f32 delta = func_800D8FF8();
  local_0 = &((u32 *) D_80127F34)[0]; local_1 = &D_80128144[0];
  do {
    if ((local_0[2] >> 31) && local_0[1]) {
      if (func_800BA28C(local_0[1])) {
        *(f32 *)local_0 -= delta;
        if (*(f32 *)local_0 <= 0.0f) {
          func_800B5450(local_0[1]);
          local_0[1] = 0;
        }
      }
    }
    local_0 += 3;
  } while (local_0 != local_1);
}

void func_800B59E0(void)
{
  u32 *local_0;
  s32 local_1;
  char *new_var;
 do { local_0 = (u32 *) (((u8 *) D_80127F34)); local_1 = 1; do { new_var = ((char *) local_0) + 0x8; if (((*((u32 *) new_var)) >> 0x1F) != 0) { if (((*((u32 *) (((char *) local_0) + 0x4))) != 0) && (local_1 != (*((u8 *) D_80127F20)))) { if (local_0) { } do { } while (0); func_800B5450(*((u32 *) (((char *) local_0) + 0x4))); *((u32 *) ((0, ((char *) local_0) + 0x4))) = 0; } } local_1 += 1; local_0 += 3; } while (local_1 != 0x2D); } while (0);
}

void func_800B5A6C()
{
  s32 *s0;
  s32 *s1;
  s32 temp_a0;
 s0 = ((s32 *) D_80127F34); do {
    ;
    if ((((u32) s0[2]) >> 0x1F) != 0)
    {
      ;
      if (s0[1] != 0)
      {
        s0[1] = func_800B5548(s0[1]);
      }
    }
    s0 += 3;
  }
  while (s0 != (((s32 *) D_80128144)));
}

int func_800B5AD4()
{
  _fxsparkle_entrypoint_2();
  func_800B4428();
  func_800B5B40();
}

int func_800B5B04()
{
  func_800B5B88();
  _fxsparkle_entrypoint_3();
  func_800B43E0();
}
