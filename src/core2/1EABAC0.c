#include "core2/1EABAC0.h"

#define MAX_D2574(a, b) ((a) < (b) ? (b) : (a))
#define MIN_D2574(a, b) ((a) < (b) ? (a) : (b))
typedef struct { s32 unk0; u8 *unk4; } E_D21F0;
extern E_D21F0 D_8011B45C[];
extern s16 D_8012B2C0[];
extern u8 *D_8011B460[];
typedef struct { u8 pad0[4]; s16 unk4; s16 unk6; f32 unk8; } A_D2438;
typedef struct { u8 local_0, local_1; s16 pad, local_2, pad2; f32 local_3; } EntryD2574;
extern EntryD2574 D_8011AFB0[];
extern f32 func_800D8FF8(void);
extern s32 func_800FA8E8(s32, s32);
extern s32 func_800FA874(s32, s32);
extern s32 func_800FA818(s32, s32);

s32 *func_800D21D0(param_0) s32 param_0;
{
  s32 t6;
  s32 t8;
  s32 t7;
  t6 = 3;
  t6 = t6 << 2;
  t6 = param_0 * t6;
  t8 = &((s32 *) D_8011AFB0)[0];
  t7 = t6;
  t7 = t7 - 2304;
  return t7 + t8;
}

s32 func_800D21F0(s32 param_0, s32 param_1) {
    u8 *p;
    u8 *end;
    s32 c;
    p = D_8011B45C[param_1].unk4;
    end = p + D_8011B45C[param_1].unk0;
    while (p < end) {
        c = *p;
        p++;
        if (param_0 == D_8012B2C0[c]) {
            return c;
        }
    }
    return -1;
}

int func_800D225C(param_0) s32 param_0;
{
  u32 local_0;
  u8 local_2;
  u32 local_1;
  u8 *local_3;
  local_2 = *((u8 *) local_1);
  local_3 = (param_0 * 8) + ((u8 *) D_8011B45C);
  local_1 = *((u32 *) (local_3 + 4));
  local_0 = (*((u32 *) local_3)) + local_1;
  if (local_1 < local_0)
  {
    loop_1:
    local_2 = *((u8 *) local_1);

    local_1 += 1;
    if (D_8012B2C0[local_2] == (-1))
    {
      return local_2;
    }
    if (local_1 < local_0)
    {
      goto loop_1;
    }
  }
  return -1;
}

s32 func_800D22C8(param_0) s32 param_0;
{
  u8 *ptr;
  ;
  return *(*((u8 **) (((char *) (&D_8011B460)) + (param_0 * 8))));
}

s32 func_800D22E0(u8 *param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;

    local_0 = 0;
    local_3 = func_800D21F0(param_1, (*(u8 *)((s8 *)(param_0) + (0))));
    local_2 = local_3;
    if (local_3 < 0) {
        local_3 = func_800D225C((*(u8 *)((s8 *)(param_0) + (0))));
        local_2 = local_3;
    }
    if (local_3 < 0) {
        local_3 = func_800D22C8((*(u8 *)((s8 *)(param_0) + (0))));
        local_2 = local_3;
    }
    if (local_3 >= 0) {
        local_1 = func_800FA708((s32) (*(f32 *)((s8 *)(param_0) + (8))), local_2, (*(u8 *)((s8 *)(param_0) + (1))), (*(u8 *)((s8 *)(param_0) + (2))));
        local_0 = local_1;
        if (local_1 != 0) {
            func_800FA9B4(local_2, (*(s16 *)((s8 *)(param_0) + (6))));
            D_8012B2C0[local_2] = (s16) param_1;
        }
    }
    return local_0;
}

int func_800D2398(u8 *param_0, int param_1) {
    int local_0 = func_800D21F0(param_1, param_0[0]);
    return (local_0 >= 0) && (func_800FA8E8(local_0, param_0[1]) == 1);
}

int func_800D23E8(u8 *param_0, int param_1) {
    int local_0 = func_800D21F0(param_1, param_0[0]);
    return (local_0 >= 0) && (func_800FA874(local_0, param_0[1]) == 1);
}

void func_800D2438(void) {
    s32 i;
    for (i = 0; i < 91; i++) {
        ((A_D2438 *) D_8011AFB0)[i].unk4 = -1;
        ((A_D2438 *) D_8011AFB0)[i].unk6 = 0;
        ((A_D2438 *) D_8011AFB0)[i].unk8 = 0.0f;
    }
    for (i = 0; i < 48; i++) {
        ((s16 *) D_8012B2C0)[i] = -1;
    }
}

void func_800D2498(u32 param_0, u32 param_1, u32 param_2) {
    u32 *local_0 = func_800D21D0();
    *(u16 *)((u8 *)local_0 + 4) = param_1;
    *(float *)((u8 *)local_0 + 8) = (s32)param_1;
    *(u16 *)((u8 *)local_0 + 6) = param_2;
    func_800D22E0(local_0, param_0);
}

s32 func_800D24E8(Gtexture *param_0, s32 param_1, s32 param_2)
{
  s32 local_1;
  s16 *local_0;
  local_0 = func_800D21D0(param_0);
  if (local_0[2] < 0)
  {
    func_800D2498((u32)param_0, param_1, param_2);
  }
  else
  {
    local_0[2] = param_1;
    local_0[3] = param_2;
    local_1 = func_800D22E0(local_0, param_0);
    if (local_1 == 0)
    {
      *(f32 *)&local_0[4] = local_0[2];
    }
    return local_1;
  }
}

void func_800D2574(void) {
    s32 local_0;
    s32 local_1;
    s32 local_5;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    local_2 = func_800D8FF8();
    for (local_0 = 0; local_0 < 91; local_0++) {
        local_5 = local_0 + 0xC0;
        local_1 = func_800D21F0(local_5, D_8011AFB0[local_0].local_0);
        if (local_1 < 0) continue;
        if (func_800FA8E8(local_1, D_8011AFB0[local_0].local_1) != 1) {
            D_8012B2C0[local_1] = -1;
            continue;
        }
        if (func_800FA874(local_1, D_8011AFB0[local_0].local_1)) {
                if (D_8011AFB0[local_0].local_2 != (s32)D_8011AFB0[local_0].local_3) {
                    local_3 = D_8011AFB0[local_0].local_2 - D_8011AFB0[local_0].local_3;
                    local_4 = local_3 >= 0.0f ? 1.0f : -1.0f;
                    D_8011AFB0[local_0].local_3 += local_4 * MIN_D2574(1.0f, MAX_D2574(local_3, 8.0f) * local_2);
                    func_800D22E0(&D_8011AFB0[local_0], local_5);
                }
        }
    }
}

int func_800D2748(s32 param_0, s32 param_1)
{
  u8 *local_0;
  local_0 = func_800D21D0(param_0);
  local_0++;
  *local_0 = param_1;
  local_0--;
}

void func_800D2770(s32 param_0, s32 param_1)
{
  void *local_0;
  local_0 = func_800D21D0(param_0);
  {
    float f4;
    f4 = (float)param_1;
    *(float *)((char *)local_0 + 8) = f4;
  }
  *(s16 *)((char *)local_0 + 4) = param_1;
}

s32 func_800D27A4(s32 param_0)
{
  u8 *local_0 = func_800D21D0(param_0);
  return local_0[1];
}

int func_800D27C8(u8 *param_0)
{
  u8 *local_0;
  local_0 = func_800D21D0();
  func_800D21F0(param_0, *local_0);
}

void func_800D27F4(s32 arg0)
{
    func_800D23E8(func_800D21D0(),arg0);
}

void func_800D2820(s32 arg0)
{
    func_800D2398(func_800D21D0(),arg0);
}

int func_800D284C(u32 param_0) {
    u8 *local_0 = func_800D21D0(param_0);
    int local_1 = func_800D21F0(param_0, local_0[0]);
    return (local_1 >= 0) && (func_800FA818(local_1, local_0[1]) == 1);
}

int func_800D28A0(u8 *param_0)
{
  u8 *local_0;
  int local_1;
  local_0 = func_800D21D0();
  local_1 = func_800D21F0(param_0, *local_0);
  if (local_1 >= 0) {
    func_800FAA74(local_1);
    return 1;
  }
  return 0;
}

u32 func_800D28E8(s32 param_0)
{
  u8 *local_0 = func_800D21D0(param_0);
  return local_0[2];
}
