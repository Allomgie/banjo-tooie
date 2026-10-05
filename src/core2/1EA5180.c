#include "common.h"

extern void func_800B42A0(void *, void *);
extern s32 D_8012AF60;
extern u8 D_8012AE98[];
extern struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; } *D_8012AE8C;
extern s32 D_8012AE94;
typedef struct { f32 local_0[3]; s16 pad; s16 local_1; f32 local_2; s32 pad2; } EntryCBC3C;
extern f32 func_800EFC7C(f32 *, f32 *);
typedef struct { f32 local_0[3]; s16 local_1, local_2; f32 local_3; u32 pad:12; u32 local_4:3; u32 pad2:17; } VolumeCB;
typedef struct { u8 pad[2]; u8 local_0; u8 pad3; f32 local_1[3]; f32 local_2; s32 local_3; s32 pad18; } GroupCB;
typedef struct { s32 count0; GroupCB *group0; s32 local_0; GroupCB *local_1; s32 local_2; GroupCB *local_3; u8 local_4[1]; } StateCB;
extern s32 D_8012AE84;
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
s32 func_800CC4D4();

extern StateCB D_8012AE80;

int func_800CB890(param_0) s32 param_0;
{
    s32 local_0;
    local_0 = param_0;
    func_800B42A0((void *)D_8012AF60, (void *)(local_0 + 0x18));
}

int func_800CB8BC(param_0) s32 param_0[3];
{
  s32 local_0;
  s32 *new_var;
  char *new_var2;
  ;
  new_var = param_0;
  new_var2 = (char *) new_var;
  return ((*((s16 *) (new_var2 + 0x1A))) * 0x18) + func_800CB890();
}

int func_800CB8F0()
{
    func_800CB890();
}

u32 func_800CB910(param_0) u32 *param_0;
{
    return ((param_0[0] >> 9) * 0x18) + func_800CB8F0();
}

int func_800CB948()
{
    func_800CB910();
}

int func_800CB968()
{
    func_800CB8BC();
}

void func_800CB988()
{
    _gcboundDll_entrypoint_0(&D_8012AE80);
}

void func_800CB9AC(void) {
}

void func_800CB9B4()
{
    _gcboundDll_entrypoint_1(&D_8012AE80);
}

void func_800CB9D8()
{
    _gcboundDll_entrypoint_2(&D_8012AE80);
}

void func_800CB9FC()
{
    _gcboundDll_entrypoint_6(&D_8012AE80);
}

void func_800CBA20()
{
    _gcboundDll_entrypoint_7(&D_8012AE80);
}

void func_800CBA44()
{
    _gcboundDll_entrypoint_8(&D_8012AE80);
}

void func_800CBA68(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6)
{
  _gcboundDll_entrypoint_3(((s32 *) &D_8012AE80), param_0, param_1, param_2, param_3, param_4, param_5, param_6);
}

void func_800CBAC8(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  _gcboundDll_entrypoint_4(((s32 *) &D_8012AE80), param_0, param_1, param_2, param_3, param_4);
}

int func_800CBB18(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5)
{
  _gcboundDll_entrypoint_5(((s32 *) &D_8012AE80), param_0, param_1, param_2, param_3, param_4, param_5);
}

void func_800CBB70(s32 param_0, s32 param_1)
{
  D_8012AE98[param_0] = param_1;
}

void func_800CBB80(s32 param_0, s32 param_1)
{
  u8 *temp_v0;
  temp_v0 = (param_0 * 0x1C) + ((u8 *) D_8012AE8C);
  if (param_1 != 0)
  {
    *((u8 *) (((s8 *) temp_v0) + 2)) = (u8) (((*((u8 *) (((s8 *) temp_v0) + 2))) & 0xFFFFu) | 1);
    return;
  }
  *((u8 *) (((s8 *) temp_v0) + 2)) = (u8) ((*((u8 *) (((s8 *) temp_v0) + 2))) & 0xFFFE);
}

int func_800CBBC0(s32 param_0)
{
  struct 
  {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
  } *new_var;
  new_var = &D_8012AE8C[param_0];
  return (*new_var).unk14;
}

s32 func_800CBBE0(s32 param_0)
{
  int new_var;
  new_var = (param_0 * 0x1C) + D_8012AE94;
  return *((s32 *) (((s8 *) new_var) + 0x14));
}

s32 func_800CBC00(s32 param_0) {
    return (*(u16 *)((s8 *)(func_800CB8F0((param_0 * 0x1C) + D_8012AE94)) + (0x14))) & 1;
}

s32 func_800CBC3C(param_0) f32 * param_0; {
    GroupCB *local_0;
    EntryCBC3C *local_1, *local_2;
    for (local_0 = D_8012AE80.group0; local_0 < D_8012AE80.count0 + D_8012AE80.group0; local_0++) {
        local_2 = func_800CB910(local_0);
        for (local_1 = func_800CB8F0(local_0); local_1 < local_2; local_1++) {
            if (local_1->local_0[1] - local_1->local_1 < param_0[1] &&
                param_0[1] < local_1->local_0[1] + local_1->local_1 &&
                func_800EFC7C(local_1->local_0, param_0) < local_1->local_2) return local_0 - D_8012AE80.group0;
        }
    }
    return -1;
}

int func_800CBD84(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    local_0 = func_800CBC3C();
    if (local_0 != -1)
    {
        local_1 = func_800CC4D4(param_0, local_0);
        if (local_1 != -1)
        {
            return -1;
        }
    }
    return local_0;
}

s32 func_800CBDD4(f32 *param_0, s32 param_1, s32 param_2)
{
    GroupCB *local_0;
    VolumeCB *local_1;
    VolumeCB *local_2;
    f32 local_3;
    f32 local_4;
    GroupCB *local_5;
    local_3 = param_0[1] + param_1 * 0.5f;
    local_4 = param_0[1] - param_1 * 0.5f;
    for (local_0 = D_8012AE80.local_1; local_0 < (local_5 = D_8012AE80.local_1 + D_8012AE80.local_0); local_0++) {
        if (!(local_0->local_0 & 1)) continue;
        {
            if (func_800EFC7C(local_0->local_1, param_0) < local_0->local_2) {
                local_2 = func_800CB910(local_0);
                if (!D_8012AE80.local_4[local_0->local_3]) continue;
                if (param_2 & 1) {
                    for (local_1 = func_800CB8F0(local_0); local_1 < local_2; local_1++) {
                        if ((local_1->local_4 & param_2) && local_1->local_0[1] <= local_3 && local_4 < local_1->local_0[1] && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) {
                            return local_0 - D_8012AE80.local_1;
                        }
                    }
                } else {
                    for (local_1 = func_800CB8F0(local_0); local_1 < local_2; local_1++) {
                        if ((local_1->local_4 & param_2) && ((local_1->local_4 & 2) || (local_1->local_0[1] - local_1->local_2 <= param_0[1] && param_0[1] < local_1->local_0[1] + local_1->local_2)) && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) {
                            return local_0 - D_8012AE80.local_1;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

s32 func_800CC078(f32 *param_0)
{
    GroupCB *local_0;
    VolumeCB *local_1;
    VolumeCB *local_2;
    for (local_0 = D_8012AE80.local_3; local_0 < D_8012AE80.local_3 + D_8012AE80.local_2; local_0++) {
        if (func_800EFC7C(local_0->local_1, param_0) < local_0->local_2) {
            local_2 = func_800CB910(local_0);
            for (local_1 = func_800CB8F0(local_0); local_1 < local_2; local_1++) {
                switch (local_1->local_4) {
                case 0:
                    if (func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return local_0 - D_8012AE80.local_3;
                    break;
                case 1:
                    if (local_1->local_0[1] - local_1->local_2 < param_0[1] && param_0[1] < local_1->local_0[1] + local_1->local_2 && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return local_0 - D_8012AE80.local_3;
                    break;
                case 2:
                    if (local_1->local_0[1] - local_1->local_2 < param_0[1] && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return local_0 - D_8012AE80.local_3;
                    break;
                case 3:
                    if (param_0[1] < local_1->local_0[1] + local_1->local_2 && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return local_0 - D_8012AE80.local_3;
                    break;
                }
            }
        }
    }
    return -1;
}

s32 func_800CC338(f32 *param_0, s32 param_1, s32 param_2) {
    s32 local_4[1];
    GroupCB *local_0;
    EntryCBC3C *local_1, *local_2, *local_3;
    local_0 = &D_8012AE80.group0[param_1];
    if (func_800CC4D4(param_0) != -1) return -1;
    local_1 = func_800CB8F0(local_0);
    local_2 = &local_1[param_2];
    if (local_2->local_0[1] - local_2->local_1 < param_0[1] &&
        param_0[1] < local_2->local_0[1] + local_2->local_1 &&
        func_800EFC7C(local_2->local_0, param_0) < local_2->local_2) return param_2;
    local_3 = func_800CB910(local_0);
    for (local_2 = local_1; local_2 < local_3; local_2++) {
        if (local_2->local_0[1] - local_2->local_1 < param_0[1] &&
            param_0[1] < local_2->local_0[1] + local_2->local_1 &&
            func_800EFC7C(local_2->local_0, param_0) < local_2->local_2) return local_2 - local_1;
    }
    return -1;
}

s32 func_800CC4D4(param_0, param_1) u8 * param_0; s32 param_1;
{
  f32 local_1;
  f32 local_2;
  int new_var;
  u32 local_0;
  f32 local_3;
  u32 local_4;
  u32 local_5;
  u8 *local_6;
  local_6 = (param_1 * 0x1C) + D_8012AE84;
  new_var = -1;
  if ((*((u8 *) (((s8 *) local_6) + 3))) == 0)
  {
    return new_var;
  }
  local_0 = func_800CB948(local_6);
  local_4 = func_800CB968(local_6);
  local_5 = local_0;
  while (local_5 < local_4)
  {
    local_1 = *((f32 *) (((s8 *) local_5) + 4));
    local_3 = (f32) (*((s16 *) (((s8 *) local_5) + 0xE)));
    local_2 = *((f32 *) (((s8 *) param_0) + 4));
    if ((((local_1 - local_3) < local_2) && (local_2 < (local_1 + local_3))) && (func_800EFC7C((u8 *) local_5, param_0) < (*((f32 *) (((s8 *) local_5) + 0x10)))))
    {
      return ((s32) (local_5 - local_0)) / 24;
    }
    local_5 += 0x18;
  }

  return new_var;
}

s32 func_800CC5E8()
{
    return *(s32 *) &D_8012AE80;
}

u32 func_800CC5F4(s32 param_0)
{
    return *(u32 *)((param_0 * 28) + (u8 *) D_8012AE84) >> 9;
}

u8 func_800CC61C(s32 param_0) {
    return (*(u8 *)((s8 *)(((param_0 * 0x1C) + D_8012AE84)) + (3)));
}

s32 func_800CC63C(param_0, param_1) s32 param_0; s32 param_1; {
    return func_800CB8F0((param_0 * 0x1C) + D_8012AE84) + (param_1 * 0x18);
}

s32 func_800CC684(s32 param_0, s32 param_1)
{
    return func_800CB948((param_0 * 0x1C) + D_8012AE84) + (param_1 * 0x18);
}

s32 func_800CC6CC(void)
{
  s32 local_2;
  u16 *new_var;
  new_var = (u16 *) (((char *) func_800CC63C()) + 0x14);
  ;
  return (*new_var) & 1;
}

s32 func_800CC6F4(f32 *param_0, s32 param_1, s32 param_2)
{
    GroupCB *local_0;
    s32 local_1;
    VolumeCB *local_2;
    VolumeCB *local_3;
    VolumeCB *local_4;
    local_0 = &D_8012AE80.local_3[param_1];
    local_2 = func_800CB8F0(local_0);
    local_4 = &local_2[param_2];
    switch (local_4->local_4) {
        case 0:
            if (func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return param_2;
            break;
        case 1:
            if (local_4->local_0[1] - local_4->local_2 < param_0[1] && param_0[1] < local_4->local_0[1] + local_4->local_2 && func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return param_2;
            break;
        case 2:
            if (local_4->local_0[1] - local_4->local_2 < param_0[1] && func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return param_2;
            break;
        case 3:
            if (param_0[1] < local_4->local_0[1] + local_4->local_2 && func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return param_2;
            break;
    }
    local_3 = func_800CB910(local_0);
    for (local_4 = local_2; local_4 < local_3; local_4++) {
        switch (local_4->local_4) {
        case 0:
            if (func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return local_4 - local_2;
            break;
        case 1:
            if (local_4->local_0[1] - local_4->local_2 < param_0[1] && param_0[1] < local_4->local_0[1] + local_4->local_2 && func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return local_4 - local_2;
            break;
        case 2:
            if (local_4->local_0[1] - local_4->local_2 < param_0[1] && func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return local_4 - local_2;
            break;
        case 3:
            if (param_0[1] < local_4->local_0[1] + local_4->local_2 && func_800EFC7C(local_4->local_0, param_0) < local_4->local_3) return local_4 - local_2;
            break;
    }
    }
    return -1;
}

s32 func_800CCAB0(f32 *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    GroupCB *local_0;
    VolumeCB *local_1;
    VolumeCB *local_2;
    VolumeCB *local_3;
    f32 local_4;
    f32 local_5;
    local_0 = &D_8012AE80.local_1[param_1];
    if (!(local_0->local_0 & 1)) return -1;
    if (!D_8012AE80.local_4[local_0->local_3]) return -1;
    local_2 = func_800CB8F0(local_0);
    local_1 = &local_2[param_2];
    local_4 = param_0[1] + param_3 * 0.5f;
    local_5 = param_0[1] - param_3 * 0.5f;
    if (param_4 & 1) {
        if ((local_1->local_4 & param_4) && local_1->local_0[1] <= local_4 && local_5 < local_1->local_0[1] && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return param_2;
    } else {
        if ((local_1->local_4 & param_4) && ((local_1->local_4 & 2) || (local_1->local_0[1] - local_1->local_2 <= param_0[1] && param_0[1] < local_1->local_0[1] + local_1->local_2)) && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return param_2;
    }
    local_3 = func_800CB910(local_0);
    if (param_4 & 1) {
        for (local_1 = local_2; local_1 < local_3; local_1++) {
            if ((local_1->local_4 & param_4) && local_1->local_0[1] <= local_4 && local_5 < local_1->local_0[1] && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return local_1 - local_2;
        }
    } else {
        for (local_1 = local_2; local_1 < local_3; local_1++) {
            if ((local_1->local_4 & param_4) && ((local_1->local_4 & 2) || (local_1->local_0[1] - local_1->local_2 <= param_0[1] && param_0[1] < local_1->local_0[1] + local_1->local_2)) && func_800EFC7C(local_1->local_0, param_0) < local_1->local_3) return local_1 - local_2;
        }
    }
    return -1;
}

s32 func_800CCDF4(s32 param_0, s32 *param_1, s32 *param_2, s32 param_3, s32 param_4) {
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_a2;

    if (-1 == *param_1) {
        temp_v0 = func_800CBDD4(param_0, param_3, param_4);
        *param_1 = temp_v0;
        if (temp_v0 == -1) {
            *param_2 = -1;
            return 0;
        }
    }
    if (-1 == *param_2) {
        var_a2 = 0;
    } else {
        var_a2 = *param_2;
    }
    temp_v0_3 = func_800CCAB0(param_0, *param_1, var_a2, param_3, param_4);
    *param_2 = temp_v0_3;
    if (temp_v0_3 >= 0) {
        return 1;
    }
    temp_v0_4 = func_800CBDD4(param_0, param_3, param_4);
    *param_1 = temp_v0_4;
    if (temp_v0_4 == -1) {
        *param_2 = -1;
        return 0;
    }
    temp_v0_5 = func_800CCAB0(param_0, *param_1, 0, param_3, param_4);
    *param_2 = temp_v0_5;
    if (temp_v0_5 >= 0) {
        return 1;
    }
    *param_1 = -1;
    return 0;
}

int func_800CCEF4(void *param_0, s32 *param_1, s32 *param_2, s32 param_3) {
    if (*param_1 == -1) {
        *param_1 = func_800CC078(param_0);
        if (*param_1 == -1) {
            *param_2 = -1;
            return 0;
        }
    }
    *param_2 = func_800CC6F4(param_0, *param_1, *param_2 == -1 ? 0 : *param_2);
    if (*param_2 >= 0) return 1;
    *param_1 = func_800CC078(param_0);
    if (*param_1 == -1) {
        *param_2 = -1;
        return 0;
    }
    *param_2 = func_800CC6F4(param_0, *param_1, 0);
    if (*param_2 >= 0) return 1;
    *param_1 = -1;
    return 0;
}

int func_800CCFEC()
{
  if (((int *) &D_8012AE80)[1])
  {
    ((int *) &D_8012AE80)[1] = defrag(((int *) &D_8012AE80)[1]);
  }
  if (((int *) &D_8012AE80)[3])
  {
    ((int *) &D_8012AE80)[3] = defrag(((int *) &D_8012AE80)[3]);
  }
  if (((int *) &D_8012AE80)[5])
  {
    ((int *) &D_8012AE80)[5] = defrag(((int *) &D_8012AE80)[5]);
  }
  if (((int *) &D_8012AE80)[56])
  {
    ((int *) &D_8012AE80)[56] = defrag(((int *) &D_8012AE80)[56]);
  }
}

void func_800CD08C(param_0, param_1) s32 param_0; u8 * param_1; {
    f32 local_0;
    f32 local_1;
    s16 local_2;
    s32 local_3;
    u32 *local_4;
    u32 local_5;
    u8 *local_6;

    local_4 = (param_0 * 0x1C) + D_8012AE84;
    local_5 = (u32) *local_4 >> 9;
    local_3 = func_800CB8F0(local_4);
    local_1 = 359.0f;
    do {
        local_6 = (func_800DC128(0, local_5) * 0x18) + local_3;
        func_800EE7F8(param_1, local_6);
        local_0 = func_800DC178(0.0f, local_1);
        func_800EF1B8(param_1, local_0, func_800DC178(0.0f, (f32) (*(s16 *)((char *)local_6 + 0xC) - 5)));
        local_2 = *(s16 *)((char *)local_6 + 0xE);
        *(f32 *)((char *)param_1 + 4) = (f32) (func_800DC178((f32) (5 - local_2), (f32) (local_2 - 5)) + *(f32 *)((char *)param_1 + 4));
    } while (func_800CC4D4(param_1, param_0) != -1);
}

void func_800CD1E0(s32 param_0, f32 *param_1, f32 param_2)
{
  func_800CD08C(param_0);
  if (param_1[1] < param_2)
  {
    param_1[1] = param_2;
  }
  if (!param_1)
  {
  }
}
