#include "core2/1E7B250.h"

extern s32 func_80091E80(PlayerState *, s32);
extern void func_8009C128(PlayerState *, f32 *);
extern f32 func_80096364(PlayerState *);
extern s32 func_80096628(PlayerState *);
extern void func_80096604(PlayerState *, f32 (*)[3]);
extern void func_800965E0();
extern s32 func_800F36D4(s32 *, s32 *);
extern void func_800EE84C(f32 *, s32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_800962D4(PlayerState *);
extern Unk80132ED0 *func_800965D4(PlayerState *);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _subaddiefade_entrypoint_9(Actor *, s32 *);
extern s32 func_800F40EC(PlayerState *);
extern const f32 D_801254A0, D_801254A4, D_801254A8, D_801254AC, D_801254B0;
extern s16 D_80119260[];
typedef struct { u8 state; u8 prev; u8 pad[2]; f32 r; f32 g; f32 b; } Sub1F78;
typedef struct { u8 pad[0x108]; Sub1F78 *sub; } Obj1F78;
typedef struct { u8 local_0; u8 pad[3]; f32 local_1[3]; } StateA2060;
typedef struct { u8 pad[0x108]; StateA2060 *local_0; } ActorA2060;
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800965C8(ActorA2060 *);

s32 func_800A1960() 
{
    return 0x10;
}

void func_800A1968(PlayerState *param_0, f32 *param_1)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    f32 local_4;
    f32 local_15;
    u32 local_5;
    f32 local_6;
    f32 local_7[3];
    f32 local_8[3];
    f32 local_9[3];
    u8 local_10[3][4];
    s32 local_11[3][3];
    s32 local_12;
    s32 local_13;
    s32 local_14;
    f32 local_16[3][3];
    Unk80132ED0 *local_17;
    s32 local_18[3];

    param_1[0] = param_1[1] = param_1[2] = 255.0f;
    if (!func_80091E80(param_0, 4)) return;
    func_8009C128(param_0, local_0);
    if (local_0[1] - func_80096364(param_0) > 1000.0f) return;
    local_5 = func_80096628(param_0);
    if (local_5 & 0x200000) return;
    func_80096604(param_0, local_16);
    func_800965E0(param_0, local_10);
    for (local_13 = 0; local_13 < 3; local_13++) {
        local_16[local_13][1] = 0.0f;
        for (local_14 = 0; local_14 < 3; local_14++) {
            local_11[local_13][local_14] = local_10[local_13][local_14];
        }
    }
    if (func_800F36D4(local_11[0], local_11[1]) && func_800F36D4(local_11[0], local_11[2])) {
        func_800EE84C(param_1, local_11[0]);
    } else {
        local_0[1] = 0.0f;
        func_800EFB24(local_1, local_0, local_16[0]);
        local_1[1] = 0.0f;
        func_800EFB24(local_8, local_16[0], local_16[1]);
        local_8[1] = 0.0f;
        func_800EFB24(local_7, local_16[2], local_16[1]);
        local_7[1] = 0.0f;
        local_15 = local_7[0];
        local_7[0] = -local_7[2];
        local_7[2] = local_15;
        local_3 = func_800EEAA4(local_1, local_7);
        if (local_3 == 0.0f) local_3 = D_801254A0;
        local_4 = -func_800EEAA4(local_8, local_7) / local_3;
        func_800EFA4C(local_9, local_16[0][0] + local_1[0] * local_4, 0,
            local_16[0][2] + local_1[2] * local_4);
        func_800EFB24(local_2, local_9, local_16[1]);
        local_6 = func_800EEF94(local_2) / (func_800EEF94(local_7) + D_801254A4);
        for (local_13 = 0; local_13 < 3; local_13++) {
            param_1[local_13] = local_11[1][local_13] + (local_11[2][local_13] - local_11[1][local_13]) * local_6;
        }
        func_800EFB24(local_2, local_9, local_16[0]);
        local_6 = 1.0f - func_800EEF94(local_1) / (func_800EEF94(local_2) + D_801254A8);
        for (local_13 = 0; local_13 < 3; local_13++) {
            param_1[local_13] = param_1[local_13] + (local_11[0][local_13] - param_1[local_13]) * local_6;
        }
    }
    local_6 = func_800962D4(param_0) / 1000.0f;
    for (local_13 = 0; local_13 < 3; local_13++) {
        param_1[local_13] = param_1[local_13] + (255.0f - param_1[local_13]) * local_6;
    }
    for (local_13 = 0; local_13 < 3; local_13++) {
        if (param_1[local_13] > 255.0f) param_1[local_13] = 255.0f;
        if (param_1[local_13] < 0.0f) param_1[local_13] = 0.0f;
    }
    if (func_80091E80(param_0, 4)) {
        local_17 = func_800965D4(param_0);
        if (local_17) {
            _subaddiefade_entrypoint_9(func_80106790(local_17), local_18);
            for (local_13 = 0; local_13 < 3; local_13++) {
                param_1[local_13] = ((s32)param_1[local_13] * local_18[local_13]) >> 8;
            }
        }
    }
    if (**(u8 **)((u8 *)param_0 + 0x108) == 1) local_12 = 50;
    else {
        switch (func_800F40EC(param_0)) {
            case 0: local_12 = 200; break;
            default: local_12 = 250; break;
        }
    }
    if (local_5 & 0x4000000) {
        param_1[0] = (param_1[0] + param_1[1] + param_1[2]) * (255.0f - local_12) * D_801254AC + local_12;
        param_1[1] = param_1[0];
        param_1[2] = param_1[0];
    } else {
        local_3 = D_801254B0;
        param_1[0] = param_1[0] * (255.0f - local_12) * local_3 + local_12;
        param_1[1] = param_1[1] * (255.0f - local_12) * local_3 + local_12;
        param_1[2] = param_1[2] * (255.0f - local_12) * local_3 + local_12;
    }
}

void func_800A1F0C(u8 *param_0, s32 param_1)
{
  u8 *temp_v0;
  temp_v0 = *((u8 **) (((s8 *) param_0) + 0x108));
  func_800EFA88(param_1, (s32) ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x108)))) + 4))) + 0.5f), (s32) ((*((f32 *) (((s8 *) temp_v0) + 8))) + 0.5f), (s32) ((*((f32 *) (((s8 *) (*((u8 **) (((s8 *) param_0) + 0x108)))) + 0xC))) + 0.5f));
}

void func_800A1F78(Obj1F78 *param_0) {
    s32 i;
    s32 map;

    map = func_800EA05C();
    param_0->sub->r = 255.0f;
    param_0->sub->g = 255.0f;
    param_0->sub->b = 255.0f;
    param_0->sub->state = 1;
    for (i = 0; D_80119260[i] != 0; i++) {
        if (map == D_80119260[i]) {
            param_0->sub->state = 2;
            break;
        }
    }
    param_0->sub->prev = param_0->sub->state;
}

void func_800A2018(PlayerState *param_0, s32 param_1) {
    u8 *local_0;
    u8 local_1;
    u8 *local_2;

    if (param_1 == -1) {
        local_0 = *(u8 ***)((char*)param_0 + 0x108);
        *(u8 *)(local_0) = *(u8 *)(local_0 + 1);
        return;
    }
    local_2 = *(u8 ***)((char*)param_0 + 0x108);
    local_1 = *(u8 *)(local_2);
    if (param_1 != local_1) {
        *(u8 *)(local_2 + 1) = local_1;
        *(u8 *)(*(u8 ***)((char*)param_0 + 0x108)) = param_1;
    }
}

void func_800A2058(s32 arg0) 
{
}
void func_800A2060(ActorA2060 *param_0) {
    s32 local_1;
    f32 local_0[3];
    switch (param_0->local_0->local_0) {
        case 0: func_800EFA4C(local_0, 255.0f, 255.0f, 255.0f); break;
        case 3: func_800EE7F8(local_0, param_0->local_0->local_1); break;
        default:
            if (func_800965C8(param_0)) func_800A1968(param_0, local_0);
            else func_800EE7F8(local_0, param_0->local_0->local_1);
            break;
    }
    for (local_1 = 0; local_1 < 3; local_1++) {
        if (param_0->local_0->local_1[local_1] < local_0[local_1]) {
            param_0->local_0->local_1[local_1] += 40.0f;
            if (local_0[local_1] < param_0->local_0->local_1[local_1]) param_0->local_0->local_1[local_1] = local_0[local_1];
        } else if (local_0[local_1] < param_0->local_0->local_1[local_1]) {
            param_0->local_0->local_1[local_1] -= 40.0f;
            if (param_0->local_0->local_1[local_1] < local_0[local_1]) param_0->local_0->local_1[local_1] = local_0[local_1];
        }
    }
}
