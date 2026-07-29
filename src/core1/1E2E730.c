#include "common.h"

typedef struct { u8 pad0[2]; u8 unk2; u8 unk3; u8 unk4; u8 unk5; u8 pad6[0x1DA]; u8 unk1E0[0x8E]; s16 unk26E; u8 pad270[4]; } Struct_9FA0;
typedef struct { s32 unk0; s32 unk4; u8 unk8; u8 pad9[3]; s32 unkC; s32 unk10; s32 unk14; s32 unk18; } Struct_AE58;
typedef struct { u8 pad_0[0x26C]; s16 local_0; u8 pad_26E[6]; } Struct80016DF8;
typedef struct { s16 local_0; u8 local_1; u8 local_2; u8 local_3; u8 local_4; u8 pad_6[0x206]; s32 local_5; u8 pad_210[0x5C]; s16 local_6; u8 pad_26e[6]; } Struct80016ED0;
extern s32 func_80017D74(s32, s32, f32);
extern s32 func_800178C4(s32, u32, f32);
extern u64 osGetTime(void);
extern u8 D_8007A198[];
extern u32 D_8007A1B0[];
extern short D_8007A20C[];
typedef struct { u8 pad0[0x1F8]; s32 unk1F8; u8 pad1FC[0x10]; s32 unk20C; u8 pad210[0x5C]; s16 unk26C; u8 pad26E[6]; } Struct1713C;
extern s32 D_8007A1AC[];
typedef struct { s16 unk0; u8 unk2; u8 unk3; u8 unk4; u8 unk5; u8 pad6[0x266]; s16 unk26C; s16 unk26E; u8 pad270[4]; } Struct17330;
typedef union {
    Struct_9FA0 base;
    Struct80016ED0 local_16ED0;
    Struct1713C local_1713C;
    u8 raw[0x274];
} Union80079FA0;
Union80079FA0 D_80079FA0[6];
u8 D_8007AE58[0x20];
u16 D_8007AE78[4];
extern void func_80025ED0(void *, s16);
extern u8 D_80079FA2[];
typedef struct { u8 local_0[8]; u8 local_1[0x26C]; } Struct800175A0;
extern u16 D_8003F600[];

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
void func_80017244();
void func_80017330(u8);
void func_800173B0(u8, s16);
volatile unsigned int func_80017778();
#pragma weak func_80016ED0_unproto = func_80016ED0
extern void func_80016ED0_unproto();

void func_80016C00(void) {
    s32 i;

    func_800E9574();
    i = 0x1ED7;
    if (func_800D738C(0x1ED7) == 4) {
        do {
            i--;
            if (i < 0x1DDE) {
                break;
            }
        } while (func_800D738C(i) == 4);
    }
    (*((s16 *) D_8007AE78)) = i - 0x1DDC;
    (*((Struct_AE58 *) D_8007AE58)).unk0 = 0x18;
    (*((Struct_AE58 *) D_8007AE58)).unk4 = 0x78;
    (*((Struct_AE58 *) D_8007AE58)).unk8 = 0x20;
    (*((Struct_AE58 *) D_8007AE58)).unkC = func_80012EDC();
    (*((Struct_AE58 *) D_8007AE58)).unk10 = 0;
    (*((Struct_AE58 *) D_8007AE58)).unk14 = 0;
    (*((Struct_AE58 *) D_8007AE58)).unk18 = 0;
    func_80022084(((Struct_AE58 *) D_8007AE58), 0x30);
    for (i = 0; i < 6; i++) {
        func_800221B0(D_80079FA0[i].base.unk1E0, ((Struct_AE58 *) D_8007AE58));
    }
    for (i = 0; i < 6; i++) {
        D_80079FA0[i].base.unk2 = 0;
        D_80079FA0[i].base.unk3 = 0;
        D_80079FA0[i].base.unk26E = 0;
        D_80079FA0[i].base.unk4 = 0;
        D_80079FA0[i].base.unk5 = 0;
    }
    func_80017244();
}

void func_80016DA0(s32 param_0, s32 param_1)
{
  s32 var;
  var = param_0 + 0x1DDD;
  if (func_800D73CC(var) == 0)
  {
    if (param_1 != 0)
    {
      func_800D5B24();
    }
    func_800D674C(var);
    func_800D70D0(1);
    func_800D71F4(1);
  }
}

void func_80016DF8(s32 param_0) {
    if (func_800D73CC(param_0 + 0x1DDD, param_0)) {
        Struct80016DF8 *local_0;
        Struct80016DF8 *local_1;

        local_0 = ((Struct80016DF8 *) D_80079FA0), local_1 = (Struct80016DF8 *) D_8007AE58;
        do {
            if (param_0 == local_0->local_0) {
                return;
            }
            local_0++;
        } while (local_0 != local_1);
        func_800D721C(param_0 + 0x1DDD, 0);
        func_800D70F8(param_0 + 0x1DDD, 0);
        func_800D6CEC(param_0 + 0x1DDD);
    }
}

void func_80016E7C()
{
  s32 local_0;
  for (local_0 = 0; local_0 < D_8007AE78[0]; local_0++)
  {
    func_80016DF8(local_0);
  }

}

void func_80016ED0(u8 param_0, s32 param_1)
{
  volatile u64 tt;

  if ((param_1 == -1))
  {
    if (D_80079FA0[param_0].local_16ED0.local_6 != param_1)
    {
      func_80024E90(&D_80079FA0[param_0].local_16ED0.pad_6[0x1DA]);
    }
    D_80079FA0[param_0].local_16ED0.local_6 = param_1;
    return;
  }

  if (D_80079FA0[param_0].local_16ED0.local_6 != (-1))
  {
    func_80016ED0(param_0, -1);
  }
  tt = osGetTime();
  while (D_80079FA0[param_0].local_16ED0.local_5 != 0)
  {
    osGetTime();
  }

  D_80079FA0[param_0].local_16ED0.local_1 = 0;
  D_80079FA0[param_0].local_16ED0.local_2 = 0;
  D_80079FA0[param_0].local_16ED0.local_6 = param_1;
  D_80079FA0[param_0].local_16ED0.local_4 = 0;
  func_80016DA0(D_80079FA0[param_0].local_16ED0.local_6, 1);
  func_80024EE0(&D_80079FA0[param_0].local_16ED0.pad_6[2], func_800D674C(D_80079FA0[param_0].local_16ED0.local_6 + 0x1DDD));
  func_80025E80(&D_80079FA0[param_0].local_16ED0.pad_6[0x1DA], &D_80079FA0[param_0].local_16ED0.pad_6[2]);
  func_80017850(param_0);
  if (D_80079FA0[param_0].local_16ED0.local_6 != -1)
  {
    func_800178C4(param_0, func_800FCDB4(D_80079FA0[param_0].local_16ED0.local_6), 0.0f);
  }
  func_80017D74(param_0, -1, 0.0f);
  func_80025ED0(&D_80079FA0[param_0].local_16ED0.pad_6[0x1DA], D_80079FA0[param_0].local_16ED0.local_0);
  func_80025F20(&D_80079FA0[param_0].local_16ED0.pad_6[0x1DA]);
  D_80079FA0[param_0].local_16ED0.local_3 = 2;
}

u32 func_80017070(param_0) u8 param_0;
{
  u8 **ptr;
  u32 new_var;
  u32 local_0;
  s32 local_1;
  u32 local_2;
  u32 local_3;
  ptr = *((u8 ***) (&D_8007A198[param_0 * 0x274]));
  if (ptr == 0)
  {
    return 0xFFFFFFFFU;
  }
  local_0 = ((u32 *) (*ptr))[1];
  new_var = ((u32 *) (*ptr))[1];
  local_0 = new_var;
  local_1 = 0x20 - local_0;
  local_2 = 0xFFFFFFFF;
  local_2 = local_2 << local_1;
  local_3 = local_2 >> local_1;
  return local_3;
}

int func_800170D4(param_0) u8 param_0;
{
  return *(s32 *)((char *)D_8007A1B0 + param_0 * 628);
}

short func_80017108(param_0) u8 param_0;
{
  return *(s16 *)((char *)D_8007A20C + param_0 * 628);
}

void func_8001713C(u8 param_0, s32 param_1)
{
  s32 local_1;
  volatile long long local_2;
  Struct1713C *local_0;
  u8 local_3;
  s32 local_4;
  local_0 = &D_80079FA0[param_0].local_1713C;
  local_1 = local_0->unk26C;
  if ((param_1 == local_1) || (local_1 == (-1)))
  {
    func_80016ED0(param_0, param_1);
    return;
  }
  local_3 = param_0;
  local_4 = param_1;
  func_80016ED0(param_0, -1);
  local_2 = osGetTime();
  while (D_80079FA0[param_0].local_1713C.unk20C != 0)
  {
    osGetTime();
  }

  local_0->unk1F8 = 0;
  func_80016DF8(local_1);
  func_80016ED0(local_3, local_4);
}

s32 func_80017210(param_0) u8 param_0;
{
  return *(s32 *)((char *)D_8007A1AC + param_0 * 628);
}

void func_80017244(void) {
    s32 local_0;
    s32 local_1;
    volatile u64 local_2;

    for (local_0 = 0; local_0 < 6; local_0++) {
        func_80016ED0_unproto(local_0 & 0xFF, -1);
    }
    local_2 = osGetTime();
    do {
        local_1 = 0;
        for (local_0 = 0; local_0 < 6; local_0++) {
            if (func_80017210(local_0 & 0xFF) != 0) {
                local_1++;
            }
        }
        osGetTime();
    } while (local_1 != 0);
}

void func_800172D4(param_0, param_1) u8 param_0; u32 param_1;
{
    s32 local_0;
    u8 *local_1;

    local_1 = ((u8 *) D_80079FA0) + (param_0 * 0x274);
    *(s16 *)(local_1 + 0x26E) = param_1;
    local_1[2] = 1;
    local_1[5] = 1;
    local_0 = param_1 * 2;
    local_1[3] = 0;
    *(u16 *)local_1 = *(u16 *)(((u8 *) D_8003F600) + local_0);
}

void func_80017330(u8 param_0)
{
  Struct17330 *local_0;
  s32 *local_1 = &param_0;
  s16 local_2;
  unsigned long local_3 = (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk26C;
  if (((&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk26C == 0x10) || (local_3 == 0x18))
  {
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk2 = 1;
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk3 = 0;
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk26E = (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk26C;
  }
  else
  {
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk26E = -1;
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk3 = 1;
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk2 = 1;
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk5 = 1;
    (&((Struct17330 *) D_80079FA0)[(u8) param_0])->unk0 = 0;
    local_0 += 0;
    local_1 += 0;
  }
}

void func_800173B0(u8 param_0, s16 param_1)
{
    s32 idx = param_0 * 0x274;
    u8 *base = &((u8 *) D_80079FA0)[idx];
    s16 *ptr = (s16 *) (base + 0x26C);
    *((u8 *) (base + 3)) = 1;
    *((u8 *) (base + 2)) = 1;
    *((u8 *) (base + 5)) = 1;
    *((s16 *) base) = param_1;
    *((s16 *) (base + 0x26E)) = *ptr;
}

void func_80017404(u8 param_0, s16 param_1)
{
    *(s16 *)D_80079FA0[param_0].raw = param_1;
    func_80025ED0(D_80079FA0[param_0].raw + 0x1E0, param_1);
    if (D_80079FA0[param_0].raw[3] != 0 && param_1 != 0) {
        func_800173B0(param_0, param_1);
        return;
    }
    if (D_80079FA0[param_0].raw[3] == 0 && param_1 == 0 &&
        func_80017778(param_0) == 0) {
        func_80017330(param_0);
    }
}

void func_800174C0(volatile u8 param_0, s32 param_1)
{
    u32 local_0;

    local_0 = param_0;
    if (func_80017778(local_0) == 0) {
        if (D_80079FA2[param_0 * 0x274] == 0) {
            func_80017D74(local_0, param_1, 0.0f);
        }
    }
}

void func_80017534(char param_0, s32 param_1, s32 param_2)
{
    u8 *local_0;
    u32 local_1;

    if (func_80017778(param_0) == 0) {
        local_1 = param_0;
        local_0 = (u8 *)((u8 *) D_80079FA0) + (local_1 * 0x274) + 0x1E0;
        func_80025FE0(local_0, param_1, param_2);
        param_0 = param_0;
    }
}

void func_800175A0(param_0) u8 param_0; {
    func_80025668(&((Struct800175A0 *) D_80079FA0)[param_0].local_1, param_0);
}

void func_800175F0(void) {
    s8 *local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    u8 local_4;
    u8 local_5;

    func_800E96B0(0);
    local_0 = (s8 *)D_80079FA0;
    local_3 = 0;
    do {
        local_1 = *(s32 *)(local_0 + 0x20C);
        switch (local_1) {
        case 2:
            break;
        case 1:
            if (*(u8 *)(local_0 + 2) != 0 && *(u8 *)(local_0 + 5) == 0 && *(u8 *)(local_0 + 4) == 0) {
                func_80024E90(local_0 + 0x1E0);
                if (*(u8 *)(local_0 + 3) != 0) {
                    *(u8 *)(local_0 + 2) = 0U;
                }
            } else {
                *(u8 *)(local_0 + 5) = 0U;
            }
            local_4 = *(u8 *)(local_0 + 4);
            if ((s32)local_4 > 0) {
                *(u8 *)(local_0 + 4) = (u8)(local_4 - 1);
            }
            break;
        case 0:
            if (*(u8 *)(local_0 + 2) != 0 && *(u8 *)(local_0 + 4) == 0 && *(s32 *)(local_0 + 0x238) == 0) {
                if (*(u8 *)(local_0 + 3) != 0) {
                    func_80025F20(local_0 + 0x1E0);
                    *(u8 *)(local_0 + 4) = 2U;
                } else {
                    func_8001713C((u8)local_3, *(s16 *)(local_0 + 0x26E));
                }
                *(u8 *)(local_0 + 3) = 0U;
                *(u8 *)(local_0 + 2) = 0U;
                *(u8 *)(local_0 + 5) = 0U;
                func_80017404((u8)local_3, *(s16 *)(local_0 + 0));
            }
            local_5 = *(u8 *)(local_0 + 4);
            if ((s32)local_5 > 0) {
                u16 local_6 = local_5 - 1;
                *(u8 *)(local_0 + 4) = (u8)local_6;
            }
            break;
        }
        local_3 += 1;
        local_0 += 0x274;
    } while (local_3 != 6);
}

u16 func_80017764(s32 param_0)
{
    return D_8003F600[param_0];
}

volatile unsigned int func_80017778(param_0) s32 param_0;
{
    s32 local_0;
    u8 *local_1;
    int local_2;

    local_0 = param_0 * 0x274;
    local_1 = &((u8 *) D_80079FA0)[local_0];
    local_2 = *(s32 *)(local_1 + 0x20C) == 0;
    if (local_2) {
        return local_1[3] == 0;
    }
}

volatile unsigned int func_800177C4(s32 param_0)
{
    s32 idx;
    u8 *ptr;
    int new_var;
    idx = param_0 * 0x274;
    ptr = &((u8 *) D_80079FA0)[idx];
    new_var = *(s32 *)(ptr + 0x20C) == 0;
    if (new_var)
    {
        return ptr[3] != 0;
    }
}

s16 *func_80017810(s32 param_0)
{
  return (s16 *)((char *)((s16 *) D_80079FA0) + param_0 * 628 + 480);
}

