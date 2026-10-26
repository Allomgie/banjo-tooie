#include "common.h"

#define M2C_MACROS_H
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;
typedef struct { u8 pad_0[0x70]; u32 route : 7; u32 pad_1 : 15; u32 node : 6; u32 pad_2 : 4; } SubaddieRoute;
typedef struct { u8 pad_0[0x70]; u32 local_0 : 7; u32 : 15; u32 local_1 : 6; u32 : 4; } SubaddieSelectors1269;
extern int func_800CC338(f32 *, s32, s32);
extern s32 func_8001210C(s32);
extern void _gccubesearch_entrypoint_7();
extern void func_800EF1B8(f32 *, f32, f32);
s32 subaddieDll_entrypoint_2();

void subaddieDll_entrypoint_0(u8 **arg0)
{
  s32 sp1C;
  u8 *temp_v1;
  if (!((*((s32 *) (((s8 *) (*arg0)) + 0x10))) & 1))
  {
    sp1C = func_8010A698();
    temp_v1 = *arg0;
    *((u8 *) (((s8 *) temp_v1) + 0x13)) = (u8) (((*((u8 *) (((s8 *) temp_v1) + 0x13))) & 0xFFFFu) | 1);
    func_80103014(arg0);
    func_8010A654(arg0, sp1C);
  }
}

s32 subaddieDll_entrypoint_1(Actor *this){
    Actor *other = (Actor*)((s32)this + 4);
    subaddieDll_entrypoint_2(this, other);
}

s32 subaddieDll_entrypoint_2(param_0, param_1) SubaddieRoute *param_0; f32 *param_1;
{
    param_0->route = func_800CBC3C(param_1) + 1;
    if (param_0->route == 0) return 0;
    param_0->node = func_800CC338(param_1, param_0->route - 1, 0) + 1;
    return 1;
}

s32 subaddieDll_entrypoint_3(Actor *param_0)
{
    u32 local_0;
    u32 local_1;
    u32 local_2;
    int local_3;

    local_0 = *(u32 *)((u8 *)param_0 + 0x70);
    local_1 = local_0 >> 25;
    if (local_1 == 0 || (local_2 = (local_0 << 22) >> 26) == 0) return 0;
    local_3 = func_800CC338(param_0->position, local_1 - 1, local_2 - 1);
    if (local_3 != -1) {
        ((SubaddieSelectors1269 *)param_0)->local_1 = local_3 + 1;
        return 1;
    }
    return 0;
}

void subaddieDll_entrypoint_4(u8 *param_0, s32 param_1) {
    if (param_1 != 0) {
        *(u16 *)((char *)param_0 + 0x7C) = 0;
        return;
    }
    *(u16 *)((char *)param_0 + 0x7C) = *(u16 *)((char *)func_80100368() + 0x18);
}

s32 subaddieDll_entrypoint_5(s32 *param_0, u8 *param_1) {
    u32 temp_t8;
    u32 sp1C;

    if (((u32) (*(u32 *)((s8 *)(param_1) + 0x24)) >> 0x16) != 0) {
        return 0;
    }
    temp_t8 = ((u32) ((u16) (*(u16 *)((s8 *)(param_1) + 0x1A)))) >> 5;
    sp1C = temp_t8;
    if (func_800F52B8(temp_t8, *param_0, param_1) != 0xB) {
        return 0;
    }
    if (func_800F55D0(sp1C) != *param_0) {
        return 0;
    }
    return 1;
}

void func_80800260_subaddieDll(param_0, param_1)
f32 *param_0;
s32 param_1;
{
    s32 local_0;
    f32 local_1;

    if (func_8001210C(1)) {
        local_0 = param_1;
    } else {
        local_0 = -param_1;
    }
    local_1 = (f32)local_0;
    param_0[1] += local_1;
    param_0[3] += local_1;
}

int subaddieDll_entrypoint_6(s32 param_0[3], s32 param_1)
{
  s32 local_0;
  local_0 = func_800F54E4();
  if (func_800F52B8(local_0 | 0, param_0[0]) != 0xB)
  {
    return 1;
  }
  else
  {
    func_80800260_subaddieDll(param_0, param_1);
    return 0;
  }
}

void subaddieDll_entrypoint_7()
{
    func_80800260_subaddieDll();
}

s32 subaddieDll_entrypoint_8() {
    s32 local_0;

    local_0 = func_80106790();
    func_8010A570(local_0 | 0);
    return local_0;
}

s32 subaddieDll_entrypoint_9(Actor *this, s32 param_1) {
    func_800DA544(param_1);
    subaddieDll_entrypoint_8(this);
}

void subaddieDll_entrypoint_10(s32 param_0, s16 *param_1)
{
    s32 local_0[2];
  s32 pad0;
    s16 *local_1[2];
    s32 local_2;
    s16 local_3;
    s16 local_4;
    s32 local_5;

    local_0[0] = param_0;
    local_0[1] = -1;
    _gccubesearch_entrypoint_7(local_0, local_1, 2);
    for (local_2 = 0; local_2 < 2; local_2++) {
        local_3 = local_1[0][local_2 * 2];
        local_4 = local_1[1][local_2 * 2];
        param_1[local_2] = local_3 < local_4 ? local_3 : local_4;
        param_1[local_2 + 2] = local_4 < local_3 ? local_3 : local_4;
    }
}

int subaddieDll_entrypoint_11(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    u32 local_1;

    if ((*(u32 *)((u8 *)param_0 + 0x70) >> 25) == 0) return 1;
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, (f32)param_1, (f32)param_2);
    local_1 = *(u32 *)((u8 *)param_0 + 0x70);
    if (func_800CC338(local_0, (local_1 >> 25) - 1, ((local_1 << 22) >> 26) - 1) == -1) return 0;
    return 1;
}

int subaddieDll_entrypoint_12(s16 param_0[3], s16 *param_1)
{
  param_1[0] = func_800DC128(param_0[0], param_0[2]);
  param_1[1] = func_800DC128(param_0[1], param_0[3]);
}
