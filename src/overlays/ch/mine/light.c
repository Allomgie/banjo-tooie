#include "common.h"

typedef union { s32 word; void *pointer; } MineLightMessage29;
extern void *_idworld_entrypoint_3(s32);
extern void *func_800BEA88(s32);
extern void func_800EDDDC(void *, f32 *, f32 *, f32);
extern s32 D_80800688_chminelight[];
extern s32 D_808006AC_chminelight;
typedef struct { u8 pad_0[0x72]; u16 st : 6; u16 rest : 10; } MineLightState;
extern u8 D_80800660_chminelight[];
extern u8 D_80800674_chminelight[];
extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern void func_800C8800(s32, u32 *);
extern void func_800C8E84(s32, s32 *);
void func_8080011C_chminelight();

s32 func_80800000_chminelight(Actor *param_0, s32 param_1, MineLightMessage29 param_2)
{
    void *local_0;
    f32 local_1[4];
    void *local_2;
    switch (param_1) {
    case 0x95:
        local_0 = _idworld_entrypoint_3(0x1AA);
        if (local_0) {
            local_1[0] = *(f32 *)((u8 *)param_0 + 0x30);
            local_1[1] = *(f32 *)((u8 *)param_0 + 0x30);
            local_1[2] = *(f32 *)((u8 *)param_0 + 0x30);
            local_1[3] = *(f32 *)((u8 *)param_0 + 0x30);
            local_2 = func_800BEA88(0);
            if (local_2) _idworldmake_entrypoint_1(local_2, 0x69, 0x1AA, 1);
            local_2 = func_800BEA88(1);
            if (local_2) _idworldmake_entrypoint_1(local_2, 0x69, 0x1AA, 1);
            func_800EDDDC(local_0, local_1, local_1, 0.0f);
        }
        if (_glcutDll_entrypoint_19(0x15)) {
            if (func_800DA298(0x9E0)) _capod_entrypoint_13(param_0->unk0, 0, 0, 0x6910);
            else _capod_entrypoint_13(param_0->unk0, 0, 2, 0x6910);
            param_0->unk64_20 = 1;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080011C_chminelight(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;
    s32 local_3[3];
    s32 local_5;
    s32 local_2;
    f32 local_4[4];

    local_0 = func_80100094(param_0, 0);
    switch (((MineLightState *)param_0)->st) {
    case 2:
        if (*(f32 *)&param_0->actorData[6] <= 0.975f) {
            if (func_8001210C(3)) {
                *(f32 *)&param_0->actorData[6] += 0.025f;
            }
        } else {
            param_0->unk70_10 = 3;
        }
        break;
    case 4:
        if (0.02f <= *(f32 *)&param_0->actorData[6]) {
            if (func_8001210C(3)) {
                *(f32 *)&param_0->actorData[6] -= 0.02f;
            }
        } else {
            param_0->unk70_10 = 1;
        }
        break;
    }
    if (param_0->unk54 != *(f32 *)&param_0->actorData[6]) {
        local_1 = *(f32 *)&param_0->actorData[6];
        if (local_1 < 0.9f && func_800DC0C0() < 0.8f) {
            local_1 *= func_800DC178(0.25f, 0.5f);
            func_800C8800(D_80800688_chminelight[param_0->unk6C_0], param_0->actorData);
            if (((MineLightState *)param_0)->st == 2) {
                if (func_800DC0C0() < 0.3f) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800660_chminelight);
                }
            } else {
                if (func_800DC0C0() < 0.15f) {
                    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800674_chminelight);
                }
            }
        }
        for (local_5 = 0; local_5 != 2; local_5++) {
            local_3[0] = (u32)*(u8 *)((s32)local_0 + param_0->unk6C_0 * 3) * local_1;
            local_3[1] = (u32)*(u8 *)((s32)local_0 + param_0->unk6C_0 * 3 + 1) * local_1;
            local_3[2] = (u32)*(u8 *)((s32)local_0 + param_0->unk6C_0 * 3 + 2) * local_1;
            func_800C8E84(D_80800688_chminelight[param_0->unk6C_0], local_3);
            if (param_0->unk6C_0 >= 8) {
                param_0->unk6C_0 = 0;
                param_0->unk54 = *(f32 *)&param_0->actorData[6];
            } else {
                param_0->unk6C_0++;
            }
        }
    }
    local_2 = _idworld_entrypoint_3(0x1AA);
    if (local_2) {
        local_4[0] = *(f32 *)&param_0->actorData[6];
        local_4[1] = *(f32 *)&param_0->actorData[6];
        local_4[2] = *(f32 *)&param_0->actorData[6];
        local_4[3] = *(f32 *)&param_0->actorData[6];
        func_800EDDDC(local_2, local_4, local_4, 0.0f);
    }
}

void func_808004CC_chminelight(s32 arg0) 
{
}
void func_808004D4_chminelight(Actor *param_0)
{
    u8 (*local_0)[3];
    s32 local_2[4];
    s32 local_1;

    local_0 = func_80100094(param_0, 0);

    for (local_1 = 0; local_1 < 9; local_1++) {
        func_800C8900(D_80800688_chminelight[local_1], local_2);
        local_0[local_1][0] = local_2[0];
        local_0[local_1][1] = local_2[1];
        local_0[local_1][2] = local_2[2];
    }
    if (func_800DA298(0x9E0)) {
        if (param_0->unk70_10 != 3) {
            ((u8 *)param_0)[0x72] = (((u8 *)param_0)[0x72] & ~0xFC) | 8;
            param_0->unk54 = -1.0f;
            *(f32 *)&param_0->actorData[6] = !_glcutDll_entrypoint_19(0x15) ? 1.0f : 0.0f;
        }
    } else {
        if (param_0->unk70_10 != 1) {
            ((u8 *)param_0)[0x72] = (((u8 *)param_0)[0x72] & ~0xFC) | 0x10;
            param_0->unk54 = -1.0f;
            *(f32 *)&param_0->actorData[6] = !_glcutDll_entrypoint_19(0x15) ? 0.0f : 1.0f;
        }
    }
    func_8080011C_chminelight(param_0);
}

int *chminelight_entrypoint_0()
{
    return ((int *) &D_808006AC_chminelight);
}
