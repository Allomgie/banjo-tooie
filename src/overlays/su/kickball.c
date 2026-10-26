#include "common.h"

extern Vec3f D_80801200_sukickball;
extern s32 func_801039E4(Actor *);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern Vec3f D_8080120C_sukickball;
extern void func_801015D0(void);
extern void func_800DF47C(void (*)(void), Actor *);
extern f32 func_800138D0(f32);
extern void *func_80100094(Actor *, u32);
extern s32 D_80801218_sukickball[];
extern void *func_80104248(Actor *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_start(void *);
extern void func_80101CDC(Actor *, f32);
extern int func_80101E14(Actor *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int func_800DC298(f32);
typedef struct { f32 local_0[2]; u8 pad_0[0x18]; s32 local_1[4]; u8 pad_1[9]; u8 local_2; } Broad51KickballData;
extern f32 func_80102D78(Actor *, void *);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern f32 D_80801234_sukickball[];
typedef struct { u8 pad_0[0x20]; s32 local_0[4]; u8 local_1[8]; u8 local_2; } KickballScores;
extern f32 func_800DC178(f32, f32);
extern s32 func_800BF340(f32 *, f32 *, f32 *, u32, f32);
extern s32 func_800EFA98(f32 *, f32 *, f32);
typedef struct { f32 value[3]; } KickBallVector;
extern u8 D_80801228_sukickball[];
extern s32 func_800F0064(f32 *, f32, f32 *);
extern void func_800EF368(f32 *, f32);
float sukickball_entrypoint_15();

void func_80800000_sukickball(Actor *param_0, void *param_1, f32 *param_2, f32 param_3)
{
    Vec3f local_0 = D_80801200_sukickball;
    func_800DF830(3);
    func_800DE448(param_2, local_0.f, param_3, NULL, func_801039E4(param_0));
}

void sukickball_entrypoint_0(Actor *param_0, void *param_1)
{
    u8 *local_0;
    Vec3f local_1;
    s32 local_2;
    f32 local_3[3];

    local_0 = func_80100094(param_0, 0);
    do {} while (0);
    local_1 = D_8080120C_sukickball;
    local_1.f[0] = param_0->rotation[0];
    local_1.f[1] = 0.0f;
    local_1.f[2] = param_0->rotation[2];
    func_800DF47C(func_801015D0, param_0);
    local_2 = (s32)(func_800138D0(*(f32 *)(local_0 + 0x14)) * (u32)*((u8 *)param_0 + 0x9B));
    if (local_2 < 0) { local_2 = -local_2; }
    if (local_2 >= 97) {
        func_800DF744(3, 1);
        func_800DF410(local_2);
        func_800DE448(param_0->position, local_1.f, param_0->scale, NULL, func_8010347C(param_0->unk0));
        if (func_800DF350()) {
            func_800DBEFC(func_80104130(), 4, local_0 + 8);
        }
    }
    if (local_2 < 160) {
        func_800DF744(3, 2);
        func_800DF410(*((u8 *)param_0 + 0x9B) - local_2);
        func_800DE448(param_0->position, local_1.f, param_0->scale, NULL, func_8010347C(param_0->unk0));
        if (func_800DF350()) {
            func_800DBEFC(func_80104130(), 5, local_0 + 8);
        }
    }
    if (func_800DF350()) {
        local_3[0] = param_0->position[0];
        local_3[1] = param_0->position[1] - 30.0f;
        local_3[2] = param_0->position[2];
        func_80800000_sukickball((Actor *)param_0->unk3C, param_1, local_3, 0.4f);
    }
}

void sukickball_entrypoint_1(Actor *param_0, void *param_1)
{
    func_800DF744(1, D_80801218_sukickball[param_0->unk6C_0]);
    func_80101870(param_0, param_1);
    if (param_0->unk7C_12) {
        func_80800000_sukickball((Actor *)param_0->unk3C, param_1, param_0->position, 0.5f);
    }
}

void sukickball_entrypoint_2(Actor *param_0, f32 param_1, f32 param_2)
{
    f32 *local_0;

    local_0 = func_80100094(param_0, 0);
    if (*(f32 *)&param_0->actorData[3] > 0.5f) {
        if (func_801022E4(param_0) == 0x63) {
            anctrl_setIndex(func_80104248(param_0), 0x1D7);
            anctrl_start(func_80104248(param_0));
        }
        func_80101CDC(param_0, func_800F10B4(*(f32 *)&param_0->actorData[3], param_1, param_2, 1.0f, 0.5f));
    } else if (func_801022E4(param_0) != 0x63) {
        anctrl_setIndex(func_80104248(param_0), 0x63);
        func_80101CDC(param_0, 8.0f);
        anctrl_start(func_80104248(param_0));
    }
    if (local_0[1] <= 0.0f && (func_80101E14(param_0, 0.5f) || func_80101E14(param_0, 0.0f))) {
        func_800C4140(0xE627D4AE, param_0->position, 0x3E800640);
        local_0[1] = 1.0f;
    }
}

s32 sukickball_entrypoint_3(void)
{
    switch (func_800EA05C()) {
        case 0xC6:
        case 0x12E: return 0;
        case 0xC8:
        case 0x12F: return 1;
        case 0xC9:
        case 0x130: return 2;
        case 0x17F:
        case 0x180: return 4;
        case 0xBB: return 3;
    }
    return 0;
}

void sukickball_entrypoint_4(s32 param_0, f32 *param_1)
{
    param_1[1] = 0.0f;
    switch (param_0) {
    case 0:
        param_1[0] = 846.0f;
        if (param_1[2] < -108.0f || param_1[2] > 108.0f) param_1[2] = func_800DC178(-108.0f, 108.0f);
        break;
    case 2:
        if (param_1[0] < -108.0f || param_1[0] > 108.0f) param_1[0] = func_800DC178(-108.0f, 108.0f);
        param_1[2] = 846.0f;
        break;
    case 1:
        param_1[0] = -846.0f;
        if (param_1[2] < -108.0f || param_1[2] > 108.0f) param_1[2] = func_800DC178(-108.0f, 108.0f);
        break;
    case 3:
        if (param_1[0] < -108.0f || param_1[0] > 108.0f) param_1[0] = func_800DC178(-108.0f, 108.0f);
        param_1[2] = -846.0f;
        break;
    }
}

s32 sukickball_entrypoint_5(Actor *param_0, f32 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3 = 0;
    f32 local_5;
    f32 local_4[3];

    func_800EFB24(local_1, param_0->position, param_1);
    func_800EE7F8(local_2, param_0->position);
    if (func_800BF340(param_1, local_2, local_0, 0x20020, 30.0f)) {
        func_800EFDE8(local_4, local_1, local_0);
        local_4[1] = 0.0f;
        func_800EFA98(local_4, local_4, 5.0f);
        func_800EE780(param_0->position, local_2, local_4);
        func_800EE7F8(param_1, param_0->position);
        return 1;
    }
    if (param_0->position[2] > 690.0f) {
        if (param_0->position[0] > -159.0f && param_0->position[0] < 159.0f) {
            if (param_0->position[2] > 822.0f) {
                local_3 = 1;
                param_0->position[2] = 816.0f;
            }
        } else {
            param_0->position[2] = 690.0f;
            local_3 = 1;
        }
    }
    if (param_0->position[2] < -696.0f) {
        if (param_0->position[0] > -159.0f && param_0->position[0] < 159.0f) {
            if (param_0->position[2] < -822.0f) {
                local_3 = 1;
                param_0->position[2] = -816.0f;
            }
        } else {
            local_3 = 1;
            param_0->position[2] = -690.0f;
        }
    }
    if (param_0->position[0] < -696.0f) {
        if (param_0->position[2] < 159.0f && param_0->position[2] > -159.0f) {
            if (param_0->position[0] < -822.0f) {
                local_3 = 1;
                param_0->position[0] = -816.0f;
            }
        } else {
            local_3 = 1;
            param_0->position[0] = -690.0f;
        }
    }
    if (param_0->position[0] > 696.0f) {
        if (param_0->position[2] > -159.0f && param_0->position[2] < 159.0f) {
            if (param_0->position[0] > 822.0f) {
                local_3 = 1;
                param_0->position[0] = 816.0f;
            }
        } else {
            param_0->position[0] = 690.0f;
            local_3 = 1;
        }
    }
    if (local_3) {
        func_800EE7F8(param_0->position, param_1);
    }
    return local_3;
}

s32 sukickball_entrypoint_6(s32 unused, s32 param_1)
{
    return (*(u8 *)(((s32)func_80100094(unused, 0) + param_1) + 0xA)) == 2;
}

s32 sukickball_entrypoint_7(s32 unused, s32 param_1) {
    return (*(u8 *)((s8 *)(((s32)func_80100094(unused, 0) + param_1)) + (0xA))) == 1;
}

int sukickball_entrypoint_8(s32 param_0, s32 param_1)
{
  s32 new_var;
  s32 new_var2;
  s32 *local_0 = func_80100094(param_0, 0);
  local_0++;
  new_var = (new_var2 = local_0[param_1 + 3]);
  local_0--;
  return new_var2;
}

void sukickball_entrypoint_9(Actor *param_0, s32 param_1, s32 param_2)
{
    Broad51KickballData *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if (4 == (s32)param_0->unk70_10) {
        switch (param_2) {
        case 1:
            local_0->local_1[param_1] += 2;
            if ((!param_1 && local_0->local_2 != 4) || (local_0->local_2 == 4 && func_800DC298(0.5f))) {
                local_1 = 2;
            } else {
                local_1 = 1;
            }
            break;
        case 5:
            local_0->local_1[param_1] += 4;
            if ((!param_1 && local_0->local_2 != 4) || (local_0->local_2 == 4 && func_800DC298(0.5f))) {
                local_1 = 2;
            } else {
                local_1 = 1;
            }
            break;
        case 2:
            local_0->local_1[param_1]--;
            if (local_0->local_1[param_1] < 0) {
                local_0->local_1[param_1] = 0;
            }
            if ((!param_1 && local_0->local_2 != 4) || (local_0->local_2 == 4 && func_800DC298(0.5f))) {
                local_1 = 1;
            } else {
                local_1 = 2;
            }
            break;
        case 4:
            local_0->local_1[param_1] -= 2;
            if (local_0->local_1[param_1] < 0) {
                local_0->local_1[param_1] = 0;
            }
            if ((!param_1 && local_0->local_2 != 4) || (local_0->local_2 == 4 && func_800DC298(0.5f))) {
                local_1 = 1;
            } else {
                local_1 = 2;
            }
            break;
        }
        switch (local_1) {
        case 1:
            if (local_0->local_0[0] <= 0.0f) {
                func_800C4140(0x7FFF453A, param_0->position, 0x3E800640);
                local_0->local_0[0] = 1.0f;
            }
            break;
        case 2:
            if (local_0->local_0[1] <= 0.0f) {
                func_800C4140(0x7FFF453B, param_0->position, 0x3E800640);
                local_0->local_0[1] = 1.0f;
            }
            break;
        }
    }
}

void sukickball_entrypoint_10(s32 unused, s32 param_1, s32 param_2) {
    s32 local_0;
    local_0 = func_80100094(unused, 0);
    *(s8 *)((s8 *)(local_0 + param_1) + 0x34) = (s8) param_2;
}

void sukickball_entrypoint_11(s32 unused, s32 param_1) {
    (*(s8 *)((s8 *)(((s32)func_80100094(unused, 0) + param_1)) + (0x34))) = 0;
}

int sukickball_entrypoint_12(s32 param_0, s32 param_1)
{
  u8 *local_0;
  local_0 = (s32)func_80100094(param_0, 0) + param_1;
  return local_0[0x34];
}

int sukickball_entrypoint_13(f32 *param_0, f32 *param_1, f32 param_2)
{
    KickBallVector local_0;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    if (func_800F0064(param_0, param_2, param_1)) {
        local_0 = *(KickBallVector *)D_80801228_sukickball;
        local_3 = param_1[1];
        local_4 = param_0[1];
        func_800EE7F8(local_1, param_0);
        func_800EE7F8(local_2, param_1);
        if (param_1[0] == param_0[0] && param_1[2] == param_0[2]) {
            param_1[0] += func_800DC178(-5.0f, 5.0f);
            param_1[2] += func_800DC178(-5.0f, 5.0f);
        }
        local_0.value[0] = param_0[0] - param_1[0];
        local_0.value[1] = param_0[1] - param_1[1];
        local_0.value[2] = param_0[2] - param_1[2];
        func_800EF368(local_0.value, param_2 * 1.1f);
        func_800EFB24(param_1, local_1, local_0.value);
        func_800EE780(param_0, local_2, local_0.value);
        param_1[1] = local_3;
        param_0[1] = local_4;
        return 1;
    }
    return 0;
}

void sukickball_entrypoint_14(Actor *param_0)
{
    param_0->unk54 = func_80102D78(param_0, param_0->actorData);
    if (param_0->unk70_10 == 3) {
        param_0->unk54 = sukickball_entrypoint_15(param_0->unk6C_0);
    }
    if (!func_80102CF4(param_0, 8.0f)) {
        func_80102B2C(param_0, 8.0f);
    }
}

float sukickball_entrypoint_15(param_0) s32 param_0;
{
  return D_80801234_sukickball[param_0];
}

void sukickball_entrypoint_16(s32 param_0, u8 *param_1) {
    switch (param_0) {
    case 0:
        (*(f32 *)((s8 *)(param_1) + (4))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (8))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (0))) = 720.0f;
        return;
    case 2:
        (*(f32 *)((s8 *)(param_1) + (0))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (4))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (8))) = 720.0f;
        return;
    case 1:
        (*(f32 *)((s8 *)(param_1) + (4))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (8))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (0))) = -720.0f;
        return;
    case 3:
        (*(f32 *)((s8 *)(param_1) + (0))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (4))) = 0.0f;
        (*(f32 *)((s8 *)(param_1) + (8))) = -720.0f;
        return;
    }
}

s32 sukickball_entrypoint_17(s32 param_0)
{
    s32 local_0;
    s32 local_1;
    f32 local_2[3];
    s32 *local_3;
    local_3 = func_80100094(param_0, 0);
    if ((u8) (*(u8 *)((char *)(local_3) + 0x39)) != 3)
    {
        for (local_0 = 0; local_0 < 4; local_0++)
        {
            if (sukickball_entrypoint_6(param_0, local_0))
            {
                sukickball_entrypoint_16(local_0, &local_2);
                func_800F8294(local_0, &local_2);
            }
        }
    }
}

void sukickball_entrypoint_18(Actor *param_0)
{
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (local_0[0x39]) {
    case 0:
    case 1:
    case 2:
        func_800D2748(0xC3, 0x2D);
        break;
    case 4:
        func_800D2748(0xC3, 0x1F);
        break;
    }
    func_800D2748(0xC4, 0x20);
    func_800D2748(0xC5, 0x21);
    func_800D2748(0xC6, 0x22);
}

void sukickball_entrypoint_19(Actor *param_0, s32 param_1, s32 param_2)
{
    KickballScores *local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_80100094(param_0, 0);
    local_1 = 0;
    if (param_2 > 0) {
        do {
            local_2 = local_1 + 0xC3;
            if (local_0->local_2 == 0) {
                local_2 = local_1 + 0xC3;
                func_800D2770(local_2, 0);
            } else {
                func_800D24E8(local_2, local_0->local_0[local_1], 0);
            }
            if (param_1 && local_0->local_1[local_1]) func_800D28A0(local_2);
            local_1++;
        } while (local_1 != param_2);
    }
    local_0->local_2 = 1;
}
