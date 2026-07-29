#include "core2/1E2F380.h"
#include "common.h"
#define MIN(a, b) ((b) < (a) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

u8 D_8007AE80[0x20];
u8 _ido_bss_gap_AEA0_AEE8[0x48];
u8 D_8007AEE8[6];
u8 _ido_bss_gap_AEF0_B4E0[0x5F0];
typedef struct { u32 unk0; u32 count; } Header178C4;
typedef struct { Header178C4 *header; } Wrapper178C4;
typedef struct { u8 pad0[0x18]; Wrapper178C4 *wrapper; u8 pad1C[0x44]; u8 *channels; } Obj178C4;
extern f32 D_80041720;
extern u32 D_8007AED0[];
extern s32 D_8007AEA0[];
typedef struct { u8 pad0[0x18]; s32 unk18; } Struct17810;
extern s32 D_8007AEB8[];
extern s32 func_800260B0(Struct17810 *);
extern s16 *func_80017810();
extern u32 func_80017778(s32 param_0);
extern void func_80026330(s32 *param_0, s32 param_1);
typedef struct { s32 local_0[33]; } Struct80017FC0;
extern OSMesgQueue *D_8007AF0C;
typedef struct { s32 unk0; s32 unk4; s32 unk8; f32 unkC; f32 unk10; f32 unk14; f32 unk18; u8 pad1C[0x68]; } Struct8001817C;
extern s32 func_800A9CAC(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern OSMesgQueue D_8007AEF0;
typedef struct { s32 local_0; u8 pad4[8]; f32 local_C; f32 local_10; u8 pad14[0x70]; } Struct80018444Sub;
typedef struct { Struct80018444Sub local_0; Struct80018444Sub local_84; } Struct80018444;
extern Struct80018444 D_8007B4E0[];
extern f32 func_800D8FF8(void);
extern u8 D_8007B0C0[];
extern u8 D_8007AF08[];
extern u8 D_8007B2EC[];
extern u8 D_8007AF10[];
typedef struct { s32 unk0; s32 unk4; u8 pad8[0x14]; OSPfs unk1C; } Struct_8007B2D0_18634;
typedef struct { s32 unk0; s32 unk4; u8 pad8[4]; f32 unkC; f32 unk10; f32 unk14; f32 unk18; OSPfs unk1C; } Struct8007B2D0;
typedef union {
    Struct80017FC0 local_17FC0;
    Struct8001817C local_1817C;
    Struct_8007B2D0_18634 local_18634;
    Struct8007B2D0 local_other;
} Union8007B2D0;
extern Union8007B2D0 D_8007B2D0[];
extern f32 D_80041730;
typedef struct { s32 local_0; u8 pad_4[0x80]; } Struct80018854;
extern void func_800C9EAC(f32, void *, s32, s32, s32, s32);

/* Forward declarations for this translation unit. */
void func_800187B4(s32 param_0, f32 param_1, f32 param_2, f32 param_3);

#pragma GLOBAL_ASM("src/core1/1E2F380_head.inc")

void func_80017850(s32 param_0)
{
  ((u8 *) D_8007AEE8)[param_0] = 1;
}

void func_80017864(void) {
    s32 i;

    for (i = 0; i < 0x20; i++) {
        D_8007AE80[i] = 0xFF;
    }
    for (i = 0; i < 6; i++) {
        D_8007AEE8[i] = 1;
    }
}

s32 func_800178C4(s32 param_0, s32 param_1, f32 param_2)
{
  Obj178C4 *local_0;
  u32 local_2;
  u32 local_3;
  long local_4;
  long local_10;
  u8 local_5;
  u8 *local_6;
  u8 *local_7;
  u32 *local_8;
  s32 pad_a;
  s32 pad_b;
  s32 pad_c;
  s32 pad_d;
  local_0 = func_80017810(param_0);
  if (local_0 == 0)
  {
    return 0;
  }
  if (local_0->wrapper != 0)
  {
    local_2 = func_800260B0(local_0);
    local_3 = (u32) (((param_2 * D_80041720) * ((f32) local_0->wrapper->header->unk0)) / ((f32) local_2));
    local_6 = D_8007AE80;
    if (0)
    {
    }
    local_7 = &D_8007AEE8[param_0];
    local_8 = D_8007AED0;
    if (local_3 == 0)
    {
      for (local_10 = 0; local_10 < local_0->wrapper->header->count; local_10++)
      {
        if ((*local_7) || ((param_1 & (1U << local_10)) != (local_8[param_0] & (1U << local_10))))
        {
          if (param_1 & (1U << local_10))
          {
            func_800262DC(local_0, local_10, local_6[local_10]);
          }
          else
          {
            func_800262DC(local_0, local_10, 0);
          }
        }
      }

      local_8[param_0] = param_1;
    }
    else
    {
      local_4 = param_1 * 0;
      if (local_0->wrapper->header->count != 0)
      {
        do
        {
        if ((*local_7) || ((param_1 & (1U << local_4)) != (local_8[param_0] & (1U << local_4))))
        {
          if (param_1 & (1U << local_4))
          {
            local_5 = local_6[local_4];
          }
          else
          {
            local_5 = 0;
          }
          local_0->channels[(local_4 * 0x38) + 0xB] = (u8) (param_2 * 10.0f);
          func_80026238(local_0, local_4, local_5 & 0xFFu, 0);
        }
        local_4++;
        } while (local_4 < local_0->wrapper->header->count);
      }

      local_8[param_0] = param_1;
    }
    for (local_4 = 0; local_4 < local_0->wrapper->header->count; local_4++)
    {
      D_8007AE80[local_4] = 0xFF;
    }

    return 1;
  }
  for (local_4 = 0; local_4 < 0x20; local_4++)
  {
    {
      if (D_8007AEE8[param_0] || ((param_1 & (1U << local_4)) != (D_8007AED0[param_0] & (1U << local_4))))
      {
        if (param_1 & (1U << local_4))
        {
          func_800262DC(local_0, local_4, D_8007AE80[local_4]);
        }
        else
        {
          func_800262DC(local_0, local_4, 0);
        }
      }
    }
  }

  D_8007AED0[param_0] = param_1;
  for (local_4 = 0; local_4 < 0x20; local_4++)
  {
    D_8007AE80[local_4] = 0xFF;
  }

  return 0;
}

s32 func_80017D74(u32 param_0, s32 param_1, f32 param_2)
{
  Struct17810 *local_0;
  s32 local_1;
  s32 local_2;
  local_0 = func_80017810();
  if (local_0->unk18 != 0)
  {
    if (param_1 == (-1))
    {
      D_8007AEA0[param_0] = -1;
      D_8007AEB8[param_0] = 0;
 if (1) { }
      return 1;
    }
    if (param_1 != D_8007AEA0[param_0])
    {
      local_1 = func_800260B0(local_0);
      if (param_2 == 0.0f)
      {
        func_80026330(local_0, param_1);
        D_8007AEA0[param_0] = param_1;
        return 1;
      }
      if (local_1 < param_1)
      {
        local_2 = param_1 - local_1;
      }
      else
      {
        local_2 = local_1 - param_1;
      }
      D_8007AEA0[param_0] = param_1;
      D_8007AEB8[param_0] = (s32) (((f32) local_2) / (param_2 * 30.0f));
    }
    return 1;
  }
  D_8007AEA0[param_0] = -1;
  D_8007AEB8[param_0] = 0;
  if (param_0)
  {
  }
  return 0;
}

void func_80017EC0(s32 param_0)
{
  s32 *local_0;
  s32 local_8;
  local_0 = (s32 *) func_80017810(param_0);
  if ((local_0 != 0) && (local_0[6] != 0) && (D_8007AEB8[param_0] != 0) &&
      (func_80017778(param_0) == 0))
  {
    local_8 = func_800260B0(local_0);
    if (local_8 == D_8007AEA0[param_0])
    {
      D_8007AEB8[param_0] = 0;
      return;
    }
    if ((D_8007AEB8[param_0] + local_8) < D_8007AEA0[param_0])
    {
      local_8 = MIN(D_8007AEB8[param_0] + local_8, D_8007AEA0[param_0]);
    }
    else if (D_8007AEA0[param_0] < (local_8 - D_8007AEB8[param_0]))
    {
      local_8 = MAX(local_8 - D_8007AEB8[param_0], D_8007AEA0[param_0]);
    }
    else
    {
      local_8 = D_8007AEA0[param_0];
      D_8007AEB8[param_0] = 0;
    }
    func_80026330(local_0, local_8);
  }
}

void func_80017FC0(s32 param_0)
{
    if (D_8007B2D0[param_0].local_17FC0.local_0[1]) {
        func_80016934(4);
        D_8007B2D0[param_0].local_17FC0.local_0[1] =
            !__osMotorAccess(&D_8007B2D0[param_0].local_17FC0.local_0[7], 1);
        func_80016934(0);
    }
}

void func_80018028(s32 param_0)
{
    if (D_8007B2D0[param_0].local_17FC0.local_0[1]) {
        func_80016934(4);
        D_8007B2D0[param_0].local_17FC0.local_0[1] =
            !__osMotorAccess(&D_8007B2D0[param_0].local_17FC0.local_0[7], 0);
        func_80016934(0);
    }
}

void func_80018090(s32 param_0) {
    Struct80017FC0 *local_0;

    local_0 = &D_8007B2D0[param_0].local_17FC0;
    if (local_0->local_0[1] != 0) {
        return;
    }
    func_80016934(4);
    local_0->local_0[1] = osMotorInit(D_8007AF0C, &local_0->local_0[7], param_0) == 0;
    func_80016934(0);
}

void func_80018108(s32 param_0) {
    Struct80017FC0 *local_0;

    if (func_80016800() != 0) {
        func_80016934(4);
        local_0 = &D_8007B2D0[param_0].local_17FC0;
        local_0->local_0[0] = osMotorInit(D_8007AF0C, &local_0->local_0[7], param_0) == 0;
        func_80016934(0);
    }
}

s32 func_8001817C(OSMesg param_0)
{
  static s32 D_8007B4E0;
  s32 local_0;
  Struct8001817C *local_1;
  s32 local_2;
  f32 local_3;
  int new_var3;
  s32 local_4;
  while (1)
  {
    new_var3 = 4;
    osRecvMesg(&D_8007AEF0, 0, 1);
    D_8007B4E0++;
    if ((D_8007B4E0 & 0xF) == 0)
    {
      func_80018108((D_8007B4E0 >> new_var3) & 3);
    }
    for (local_0 = 0; local_0 < new_var3; local_0++)
    {
      local_1 = &D_8007B2D0[local_0].local_1817C;
      if ((&D_8007B2D0[local_0].local_1817C)->unk0 != 0)
      {
        if (((&D_8007B2D0[local_0].local_1817C)->unk4 == 0) && ((D_8007B4E0 % 60) == 0))
        {
          func_80018090(local_0);
        }
        local_2 = local_1->unk8;
        if ((&D_8007B2D0[local_0].local_1817C)->unk10 != (&D_8007B2D0[local_0].local_1817C)->unkC)
        {
          local_3 = func_800F10B4(local_1->unk10, 0.0f, local_1->unkC, local_1->unk14, local_1->unk18);
          local_4 = (s32) (((1.0f - local_3) * 8.0f) + 1.f);
          if (local_4 < 2)
          {
            (&D_8007B2D0[local_0].local_1817C)->unk8 = (local_4 != 0) || (0.0f < local_3);
          }
          else
          {
            (&D_8007B2D0[local_0].local_1817C)->unk8 = (D_8007B4E0 % local_4) == 0;
          }
        }
        else
        {
          local_1->unk8 = 0;
        }
        if ((local_2 != local_1->unk8) && (func_800A9CAC() == 0))
        {
          if (local_1->unk8 != 0)
          {
            func_80017FC0(local_0);
          }
          else
          {
            func_80018028(local_0);
          }
        }
      }
    }

  }

}

void func_800183D4(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    f32 local_0;
    f32 local_1;
    f32 local_2;

    local_0 = (f32)param_1 / 524288.0f;
    local_1 = (f32)param_2 / 524288.0f;
    local_2 = (f32)param_3 / 524288.0f;
    func_800187B4(param_0, local_0, local_1, local_2);
}

void func_80018444(void)
{
  f32 local_0;
  f32 local_1;
  f32 local_3;
  Struct80018444 *local_2;
  Struct80018444 *local_4;
  local_0 = func_800D8FF8();
  local_4 = D_8007B4E0;
 local_2 = ((Struct80018444 *) D_8007B2D0); local_loop: { if (local_2->local_0.local_0 != 0) {
      local_1 = local_2->local_0.local_C;
      local_3 = local_2->local_0.local_10 + local_0;
      if (local_1 < local_3)
      {
        local_2->local_0.local_10 = local_1;
      }
      else
      {
        local_2->local_0.local_10 = local_3;
      }
    }
    if (local_2->local_84.local_0 != 0)
    {
      local_1 = local_2->local_84.local_C;
      local_3 = local_2->local_84.local_10 + local_0;
      if (local_1 < local_3)
      {
        local_2->local_84.local_10 = local_1;
      }
      else
      {
        local_2->local_84.local_10 = local_3;
      }
    }
    local_2++;
  }

  if (local_2 != local_4)
  {
    goto local_loop;
  }
}

void func_800184E8(void) {
    u8 *local_1;
    u8 *local_0;
    s32 local_2;
    s32 local_3;
    s32 local_4;

    func_80016934(4);
    D_8007AF0C = func_80016928();
    local_0 = ((u8 *) D_8007B2D0), local_1 = &D_8007B2EC;
    local_3 = 0;
    do {
        local_4 = osPfsInit(D_8007AF0C, (OSPfs *)local_1, local_3);
        if ((local_4 == 0xA) || (local_4 == 0xB)) {
            local_4 = osMotorInit(D_8007AF0C, (OSPfs *)local_1, local_3);
        }
        local_3 += 1;
        local_2 = local_4 == 0;
        local_0 += 0x84;
        local_1 += 0x84;
        *(s32 *)(local_0 - 0x84) = local_2;
        *(s32 *)(local_0 - 0x80) = local_2;
    } while (local_3 != 4);
    func_80016934(0);
    osCreateMesgQueue(((u8 *) &D_8007AEF0), &D_8007AF08, 1);
    func_8001DCB0(&D_8007AF10, &D_8007B0C0, 8, &func_8001817C, 0, ((u8 *) D_8007B2D0), 0x19);
    osStartThread(&D_8007AF10);
    func_80014F64(((u8 *) &D_8007AEF0), 0);
}

void func_8001862C(void) {
}

void func_80018634(void)
{
  s32 new_var; short new_var3; s32 local_0; OSMesgQueue *new_var2;
  s32 local_1; u32 local_2;
  for (local_0 = 0; local_0 < 4; local_0++) {
    if (D_8007B2D0[local_0].local_18634.unk4) {
      new_var = local_0; new_var3 = 4;
      func_80016934(new_var3);
      new_var2 = D_8007AF0C;
      local_2 = osMotorInit(new_var2, &D_8007B2D0[local_0].local_18634.unk1C, new_var);
      D_8007B2D0[local_0].local_18634.unk4 = local_2 == 0;
      for (local_1 = 0; (local_1 < 3) && D_8007B2D0[local_0].local_18634.unk4; local_1++) {
        local_2 = __osMotorAccess(&D_8007B2D0[local_0].local_18634.unk1C, 0);
        if (local_1) { }
        D_8007B2D0[local_0].local_18634.unk4 = local_2 == 0;
      }
      func_80016934(0);
    }
  }
}

void func_80018704(s32 param_0, f32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  f32 local_2;
  if (param_3 != .0f)
  {
    if ((((Struct8007B2D0 *) D_8007B2D0)[param_0].unk0 != 0)
        && (((param_4 != 0) || (!(D_80041730 < (((Struct8007B2D0 *) D_8007B2D0)[param_0].unkC - ((Struct8007B2D0 *) D_8007B2D0)[param_0].unk10))))
            || (!((param_1 + param_2) < (((Struct8007B2D0 *) D_8007B2D0)[param_0].unk14 + ((Struct8007B2D0 *) D_8007B2D0)[param_0].unk18)))))
    {
      ((Struct8007B2D0 *) D_8007B2D0)[param_0].unk10 = (local_2 = 0.0f);
      local_2 = ((Struct8007B2D0 *) D_8007B2D0)[param_0].unkC - ((Struct8007B2D0 *) D_8007B2D0)[param_0].unk10;
      ((Struct8007B2D0 *) D_8007B2D0)[param_0].unkC = param_3;
      ((Struct8007B2D0 *) D_8007B2D0)[param_0].unk14 = param_1;
      ((Struct8007B2D0 *) D_8007B2D0)[param_0].unk18 = param_2;
    }
  }
}

void func_800187B4(s32 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    func_80018704(param_0, param_1, param_2, param_3, 0);
}

void func_800187E8(s32 param_0, f32 param_1, f32 param_2, f32 param_3)
{
    func_80018704(param_0, param_1, param_2, param_3, 1);
}

void func_80018820(s32 param_0, f32 param_1, f32 param_2)
{
    func_800187B4(param_0, param_1, param_1, param_2);
}

void func_80018854(s32 param_0, f32 param_1, f32 param_2, f32 param_3,
                   f32 param_4, f32 param_5, f32 param_6)
{
    if (((Struct80018854 *) D_8007B2D0)[param_0].local_0 != 0) {
        func_800C9EAC(0.0f, &func_800183D4, param_0, 0,
                      (s32)(param_1 * 524288.0f),
                      (s32)(param_3 * 524288.0f));

        func_800C9EAC(param_3, &func_800183D4, param_0,
                      (s32)(param_1 * 524288.0f),
                      (s32)(param_2 * 524288.0f),
                      (s32)(param_4 * 524288.0f));

        func_800C9EAC(param_3 + param_4, &func_800183D4, param_0,
                      (s32)(param_2 * 524288.0f),
                      (s32)(param_2 * 524288.0f),
                      (s32)(param_5 * 524288.0f));
        func_800C9EAC(param_3 + param_4 + param_5, &func_800183D4, param_0,
                      (s32)(param_2 * 524288.0f),
                      0, (s32)(param_6 * 524288.0f));
    }
}

void func_800189A8(s32 param_0, f32 *param_1, s16 param_2, f32 param_3, f32 param_4)
{
  s32 local_0;
  s32 local_1;
  f32 *local_2;
  f32 local_3;
  f32 local_4;
  f32 new_var2;
  f32 new_var;
  if (((Struct80018854 *) D_8007B2D0)[param_0].local_0 != 0)
  {
    local_0 = param_2 - 1;
    local_1 = 0;
    if (local_0 > 0)
    {
 local_2 = param_1; do {
        local_3 = local_2[0] * param_3;
        local_4 = local_2[2] * param_3;
        new_var2 = local_2[1] * param_4;
        new_var = local_2[3] * param_4;
        func_800C9EAC(local_3, &func_800183D4, param_0, (s32) (new_var2 * 524288.0f), (s32) (new_var * 524288.0f), (s32) ((local_4 - local_3) * 524288.0f));
        local_1++;
        local_2 += 2;
      }
      while ((local_1 + 0) != (param_2 - 1));
    }
  }
}
