#include "common.h"
#include "playerstate.h"
#include "yaw.h"

#define INVISIBLE_PLAYER_VIEW_DEFINED
typedef struct { u8 pad0[0x30]; } InvisiblePart;
typedef struct { u8 pad0[0x1C]; InvisiblePart unk1C[2]; } InvisibleState;
typedef struct { u8 pad0[0xA8]; InvisibleState *unkA8; } InvisiblePlayerView;




































void bainvisible_entrypoint_1(void *param_0, f32 param_1, f32 param_2);

extern void bastatetimer_clear(InvisiblePlayerView *, s32);
extern void bastatetimer_set(InvisiblePlayerView *, s32, f32);
extern f32 func_800D8FF8(void);
extern void func_8009BC08(PlayerState *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 mlAbsF(f32);
extern f32 func_800F214C(f32, f32);
void func_80800000_bainvisible();
void func_808001BC_bainvisible();
s32 func_808003AC_bainvisible();

void func_80800000_bainvisible(param_0, param_1, param_2) PlayerState *param_0; u8 *param_1; s32 param_2;
{
    u8 *local_1;
    u8 *local_0;
    param_1[0] = param_2;
    local_0 = *(u8 **)((u8 *)param_0 + 0xA8) + 0x4C;
    local_1 = *(u8 **)((u8 *)param_0 + 0xA8) + 0x1C;
    switch (param_2) {
    case 0:
        if (!local_1[0] && !local_0[0]) func_8009ADF0(param_0, 0xC, 0);
        break;
    case 2:
        if (!func_8009AD78(param_0, 0xC)) {
            func_8009ADF0(param_0, 0xC, 1);
            bainvisible_entrypoint_1(param_0, 750.0f, 135.0f);
            func_8009BC08(param_0, *(f32 **)((u8 *)param_0 + 0xA8));
            *(f32 *)(*(u8 **)((u8 *)param_0 + 0xA8) + 0xC) = yaw_get(param_0);
            local_0[0x1C] = 0;
            *(f32 *)(local_0 + 0xC) = 1.0f;
            *(f32 *)(local_0 + 4) = 0.67f;
            local_1[0x1C] = 0;
            *(f32 *)(local_1 + 0xC) = 1.0f;
            *(f32 *)(local_1 + 4) = 0.67f;
            *(f32 *)(*(u8 **)((u8 *)param_0 + 0xA8) + 0x10) = 0.0f;
            func_808001BC_bainvisible(param_0);
        }
        break;
    case 3:
        if (param_1 == local_1) func_8009DBF0(param_0, 0x65E, 1.0f);
        break;
    case 4:
        if (!func_8009AD78(param_0, 0xC)) {
            func_8009ADF0(param_0, 0xC, 1);
            *(f32 *)(local_0 + 0xC) = 1.0f;
            *(f32 *)(local_1 + 0xC) = 1.0f;
        }
        *(f32 *)(param_1 + 0x24) = *(f32 *)(param_1 + 0xC);
        *(f32 *)(param_1 + 0x28) = 0.0f;
        break;
    case 1:
        param_1[0x1C] = 0;
        *(f32 *)(param_1 + 8) = 1.0f;
        break;
    }
}

void func_808001BC_bainvisible(param_0) u8 *param_0;
{
    u8 *local_0;
    f32 local_1;
    f32 local_5;
    f32 local_2;
    f32 local_3[3];
    f32 local_4;
    f32 local_6;
    f32 local_7;
    s32 local_8;
    u8 *local_9;

    local_0 = *(u8 **)(param_0 + 0xA8) + 0x1C;
    local_2 = 1.0f / func_800D8FF8();
    func_8009BC08(param_0, &local_3);
    local_1 = func_800EFB8C(&local_3, *(f32 **)(param_0 + 0xA8)) * local_2;
    func_800EE7F8(*(f32 **)(param_0 + 0xA8), &local_3);
    local_5 = *(f32 *)(*(u8 **)(param_0 + 0xA8) + 0x14);
    if (local_5 < local_1) {
        local_1 = 1.0f;
    } else {
        local_1 /= local_5;
    }
    local_4 = yaw_get(param_0);
    local_5 = mlAbsF(func_80013728(local_4 - *(f32 *)(*(u8 **)(param_0 + 0xA8) + 0xC)));
    *(f32 *)(*(u8 **)(param_0 + 0xA8) + 0xC) = local_4;
    local_6 = local_5 * local_2;
    local_7 = *(f32 *)(*(u8 **)(param_0 + 0xA8) + 0x18);
    local_5 = local_7 < local_6 ? 1.0f : local_6 / local_7;
    *(f32 *)(*(u8 **)(param_0 + 0xA8) + 0x10) = local_5 < local_1 ? local_1 : local_5;
    local_6 = local_5 < local_1 ? local_1 : local_5;
    if (local_0[0] == 3) {
        *(f32 *)(local_0 + 8) = 0.255f * local_6 + 0.07499999553f;
    }
    if (local_0[0x30] == 3) {
        *(f32 *)(local_0 + 0x38) = 0.1999999881f * local_6 + 0.3999999762f;
    }
    local_9 = local_0;
    local_8 = 0;
    do {
        if (local_9[0x1C]) {
            if (*(f32 *)(local_9 + 8) < *(f32 *)(local_9 + 0x10)) {
                *(f32 *)(local_9 + 8) = *(f32 *)(local_9 + 0x10);
            }
            if (*(f32 *)(local_9 + 0x14) < *(f32 *)(local_9 + 8)) {
                *(f32 *)(local_9 + 8) = *(f32 *)(local_9 + 0x14);
            }
        }
        local_8 += 0x30;
        local_9 += 0x30;
    } while (local_8 != 0x60);
    if (local_0) {}
}

s32 func_808003AC_bainvisible(param_0) f32 *param_0;
{
    f32 local_0;

    local_0 = param_0[2] - param_0[3];
    param_0[3] += local_0 * 0.25f;
    return func_800F214C(local_0, 0.01f) == 0.0f;
}

s32 bainvisible_entrypoint_0() 
{
    return 0x7C;
}

void bainvisible_entrypoint_1(void *param_0, f32 param_1, f32 param_2)
{
  f32 *ptr;
  ptr = *((void **) (((u8 *) param_0) + 0xA8));
  *((f32 *) (((u8 *) (*((void **) (((u8 *) param_0) + 0xA8)))) + 0x14)) = param_1;
  ;
  *((f32 *) (((u8 *) (*((void **) (((u8 *) param_0) + 0xA8)))) + 0x18)) = param_2;
}

f32 bainvisible_entrypoint_2(u8 *param_0, s32 param_1) {
    return (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(param_0) + (0xA8))) + (param_1 * 0x30))) + (0x28)));
}

void bainvisible_entrypoint_3(InvisiblePlayerView *param_0)
{
    InvisiblePart *local_0;

    local_0 = &param_0->unkA8->unk1C[0];
    func_80800000_bainvisible(param_0, local_0, 1);
    func_80800000_bainvisible(param_0, ++local_0, 1);
    bastatetimer_clear(param_0, 9);
}

void bainvisible_entrypoint_4(InvisiblePlayerView *param_0)
{
    InvisiblePart *local_0;

    local_0 = &param_0->unkA8->unk1C[0];
    func_80800000_bainvisible(param_0, local_0, 0);
    func_80800000_bainvisible(param_0, ++local_0, 0);
    bastatetimer_clear(param_0, 9);
}

void bainvisible_entrypoint_5(InvisiblePlayerView *param_0, f32 param_1)
{
    InvisiblePart *local_0;

    local_0 = &param_0->unkA8->unk1C[0];
    func_80800000_bainvisible(param_0, local_0, 2);
    func_80800000_bainvisible(param_0, ++local_0, 2);
    bastatetimer_set(param_0, 9, param_1);
}

void bainvisible_entrypoint_6(void *param_0)
{
    s32 local_0;
    u8 *local_1;
    f32 local_2;

    if (*(*(u8 **)((u8 *)param_0 + 0xA8) + 0x1C) == 3) {
        func_808001BC_bainvisible();
    }
    for (local_0 = 0; local_0 != 0x60; local_0 += 0x30) {
        local_1 = *(u8 **)((u8 *)param_0 + 0xA8) + local_0 + 0x1C;
        switch (*local_1) {
        case 2:
            *(f32 *)(local_1 + 4) -= func_800D8FF8();
            if (*(f32 *)(local_1 + 4) < 0.0f) {
                func_80800000_bainvisible(param_0, local_1, 3);
            }
            break;
        case 3:
            func_808003AC_bainvisible(local_1);
            if (bastatetimer_isDone(param_0, 9)) {
                func_80800000_bainvisible(param_0, local_1, 1);
                func_8009DBF0(param_0, 0x65D, 1.0f);
            }
            if (local_1[0x1C]) {
                *(f32 *)(local_1 + 0x18) -= func_800D8FF8();
                if (*(f32 *)(local_1 + 0x18) <= 0.0f) {
                    local_1[0x1C] = 0;
                }
            }
            break;
        case 4:
            *(f32 *)(local_1 + 0x28) += func_800D8FF8();
            local_2 = *(f32 *)(local_1 + 0x28) < *(f32 *)(local_1 + 0x2C) ?
                *(f32 *)(local_1 + 0x28) / *(f32 *)(local_1 + 0x2C) : 1.0f;
            *(f32 *)(local_1 + 0xC) =
                (*(f32 *)(local_1 + 0x20) - *(f32 *)(local_1 + 0x24)) * local_2 +
                *(f32 *)(local_1 + 0x24);
            break;
        case 1:
            if (func_808003AC_bainvisible(local_1)) {
                func_80800000_bainvisible(param_0, local_1, 0);
            }
            break;
        }
    }
}

void bainvisible_entrypoint_7(u8 *param_0, s32 param_1, f32 param_2, f32 param_3, f32 param_4)
{
    int local_0;
    u8 *local_1;
    if (param_4 != 0.0f) {
        local_0 = 1;
    } else {
        local_0 = 0;
    }
    if (param_1 & 1) {
        local_1 = *(u8 **)(param_0 + 0xA8);
        local_1[0x38] = local_0;
        *(f32 *)(local_1 + 0x34) = param_4;
        *(f32 *)(local_1 + 0x2C) = param_2;
        local_1 += 0x1C;
        *(f32 *)(local_1 + 0x14) = param_3;
    }
    if (param_1 & 2) {
        local_1 = *(u8 **)(param_0 + 0xA8);
        local_1[0x68] = local_0;
        *(f32 *)(local_1 + 0x64) = param_4;
        *(f32 *)(local_1 + 0x5C) = param_2;
        local_1 += 0x4C;
        *(f32 *)(local_1 + 0x14) = param_3;
    }
}

int func_808007CC_bainvisible(f32 param_0[3], f32 param_1[3], f32 param_2, f32 param_3)
{
  func_80800000_bainvisible(param_0, param_1, 4);
  param_1[8] = param_2;
  param_1[11] = param_3;
}

int bainvisible_entrypoint_8(Actor *param_0, s32 param_1, f32 param_2, f32 param_3)
{
  if (param_1 & 1)
  {
    func_808007CC_bainvisible(param_0, *(s32 *)((char *)param_0 + 0xA8) + 0x1C, param_2, param_3);
  }
  if (param_1 & 2)
  {
    func_808007CC_bainvisible(param_0, *(s32 *)((char *)param_0 + 0xA8) + 0x4C, param_2, param_3);
  }
}

void bainvisible_entrypoint_9(PlayerState **param_0, s32 param_1, f32 *param_2)
{
    f32 local_0[3];
    f32 local_1[8];
    f32 local_2;
    PlayerState *local_3;
    s32 local_4;
    s32 local_5;
    for (local_4 = 0; local_4 < param_1; local_4++) {
        func_8009BC08(param_0[local_4], local_0);
        local_2 = func_800EFC7C(local_0, param_2);
        local_3 = param_0[local_4];
        for (local_5 = local_4; local_5 > 0 && local_1[local_5 - 1] < local_2; local_5--) {
            param_0[local_5] = param_0[local_5 - 1];
            local_1[local_5] = local_1[local_5 - 1];
        }
        param_0[local_5] = local_3;
        local_1[local_5] = local_2;
    }
}
