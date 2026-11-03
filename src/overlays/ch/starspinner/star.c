#include "common.h"

extern int D_808006B0_chstarspinnerstar[];
extern Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
extern s32 _chstarspinnerctrl_entrypoint_3(Actor *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef union {
    s32 word;
    Unk80132ED0 *marker;
} StarSpinnerEventPayload;
typedef struct {
    f32 f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, f10, f11, f12, f13, f14, f15;
} ADF_;
extern u8 D_808006F8_chstarspinnerstar[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4B64(f32);
extern void _subaddieaudioloop_entrypoint_0(Actor *, f32);
extern void func_80101FDC();
extern f32 mlAbsF(f32);
void func_808005F8_chstarspinnerstar();
f32 *func_80800660_chstarspinnerstar();
int func_80800454_chstarspinnerstar(Actor *param_0, f32 param_1);
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80800320_chstarspinnerstar();

int chstarspinnerstar_entrypoint_0()
{
    return (int) &D_808006B0_chstarspinnerstar;
}

void func_8080000C_chstarspinnerstar(Actor *param_0)
{
    f32 local_0;
    s32 local_1;
    s32 local_2;
    f32 local_3;

    local_0 = func_800D8FF8();
    local_1 = func_800DA298(0xEA) || _glcutDll_entrypoint_20();
    param_0->actorData[6] = _chstarspinnerctrl_entrypoint_4(
        param_0, func_80800660_chstarspinnerstar(param_0), param_0->actorData[6]);
    switch (param_0->unk70_10) {
        case 1:
            if (local_1 && param_0->unk64_20) {
                func_80101FDC(param_0, 2);
                param_0->unk58 = 1.5f;
            }
            break;
        case 2:
            ((ADF_ *) param_0->actorData)->f7 =
                (func_800DA298(0x679) ? 30 : 80) * ((ADF_ *) param_0->actorData)->f4;
            param_0->rotation[1] =
                func_800136E4(param_0->rotation[1] + local_0 * ((ADF_ *) param_0->actorData)->f7);
            func_80800454_chstarspinnerstar(param_0, local_0);
            if (!param_0->unk64_20 || !local_1) {
                param_0->unk58 -= local_0;
                if (param_0->unk58 < 0.0f || !local_1) {
                    if (((ADF_ *) param_0->actorData)->f5 > 0) {
                        ((ADF_ *) param_0->actorData)->f5 = -((ADF_ *) param_0->actorData)->f5;
                    }
                    func_80101FDC(param_0, 3);
                }
            } else {
                param_0->unk58 = 1.5f;
            }
            break;
        case 3:
            ((ADF_ *) param_0->actorData)->f7 =
                (func_800DA298(0x679) ? 30 : 80) * ((ADF_ *) param_0->actorData)->f4;
            param_0->rotation[1] =
                func_800136E4(param_0->rotation[1] + local_0 * ((ADF_ *) param_0->actorData)->f7);
            if (func_80800454_chstarspinnerstar(param_0, local_0)) {
                param_0->position[1] = ((ADF_ *) param_0->actorData)->f1;
                func_80101FDC(param_0, 1);
            }
            if (param_0->unk64_20 && local_1) {
                func_80101FDC(param_0, 2);
                param_0->unk58 = 1.5f;
            }
            break;
    }
    param_0->unk64_20 = 0;
    local_2 = local_1 && (s32) param_0->unk70_10 >= 2;
    if (local_2 || (!local_2 && param_0->unk5F)) {
        local_3 = func_800F10B4(param_0->position[1] - ((ADF_ *) param_0->actorData)->f1, 0,
                                1900.0f, 0.8f, 1.2f);
        func_800C4B64(local_3);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_2,
                                        D_808006F8_chstarspinnerstar);
        _subaddieaudioloop_entrypoint_0(param_0, local_3);
    }
}

void func_80800320_chstarspinnerstar(param_0) Actor *param_0;
{
    param_0->unk3C = _subaddiefind_entrypoint_0(param_0->position, 0x337, -1, 0)->unk0;
    param_0->actorData[6] =
        _chstarspinnerctrl_entrypoint_3(param_0, func_80800660_chstarspinnerstar(param_0));
    param_0->unk54 = param_0->rotation[1];
    func_800EE7F8((f32 *) param_0->actorData, param_0->position);
    if (param_0->rotation[1] == 1.0f) {
        *(f32 *) ((u8 *) param_0 + 0x28) = -1.0f;
    } else {
        *(f32 *) ((u8 *) param_0 + 0x28) = 1.0;
    }
    param_0->rotation[1] = 0.0f;
    *(f32 *) ((u8 *) param_0 + 0x2C) = 1.0;
    if (func_800EA05C() != 0xE6) {
        func_8010A624(param_0);
    }
}

s32 func_808003F8_chstarspinnerstar(Actor *param_0, s32 param_1, StarSpinnerEventPayload param_2)
{
    switch (param_1) {
        case 0x91:
            param_0->unk64_20 = 1;
            break;
        case 0x1F:
            func_808005F8_chstarspinnerstar(param_0, param_2.word);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800454_chstarspinnerstar(Actor *param_0, f32 param_1)
{
    s32 local_3;
    f32 local_0;
    f32 local_1;
    f32 local_2;
    local_0 =
        ((((f32 *) param_0->actorData)[5] < 0.0f ? ((f32 *) param_0->actorData)[1]
                                                 : ((f32 *) param_0->actorData)[1] + 1900.0f) -
         param_0->position[1]) *
        0.05f;
    local_1 = mlAbsF(local_0);
    local_3 = func_800DA298(0x679);
    local_2 = ((f32 *) param_0->actorData)[5] * (local_3 ? 400 : 1000) * param_1;
    if (local_1 < 4.0f) {
        local_0 = local_0 < 0.0f ? -4.0f : 4.0f;
    } else if (local_1 > mlAbsF(local_2)) {
        local_0 = local_2;
    }
    param_0->position[1] += local_0;
    if (((f32 *) param_0->actorData)[5] < 0.0f) {
        if (param_0->position[1] < ((f32 *) param_0->actorData)[1]) {
            ((f32 *) param_0->actorData)[5] = -((f32 *) param_0->actorData)[5];
            return 1;
        }
    } else if (((f32 *) param_0->actorData)[1] + 1900.0f < param_0->position[1]) {
        ((f32 *) param_0->actorData)[5] = -((f32 *) param_0->actorData)[5];
        return 1;
    }
    return 0;
}

void func_808005F8_chstarspinnerstar(param_0, param_1) u8 **param_0;
s32 param_1;
{
    u8 sp1F;
    int temp_v0;
    func_801015D0();
    temp_v0 = func_800D731C(*(u16 *) ((s8 *) *param_0 + 0x14));
    sp1F = temp_v0;
    if (((temp_v0 != 0) && (func_800DA298(0xEA) == 0)) && (_glcutDll_entrypoint_20() == 0)) {
        func_800DBE60(sp1F, 0, 0);
    }
}

u8 B_80800710_chstarspinnerstar[16];

f32 *func_80800660_chstarspinnerstar(param_0)
s32 param_0;
{
    func_800EE7F8(B_80800710_chstarspinnerstar, (f32 *) (param_0 + 4));
    ((f32 *) B_80800710_chstarspinnerstar)[1] = ((f32 *) B_80800710_chstarspinnerstar)[1];
    return (f32 *) B_80800710_chstarspinnerstar;
}

int D_808006B0_chstarspinnerstar[18] = {0x1BF0336,
                                        0x7790001,
                                        0x0,
                                        (u32) func_8080000C_chstarspinnerstar,
                                        (u32) func_80105834,
                                        (u32) func_801018A4,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x4C00,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800320_chstarspinnerstar,
                                        (u32) func_80107C2C,
                                        -0x7FFFFBEE,
                                        (u32) func_808003F8_chstarspinnerstar,
                                        0x0};
u8 D_808006F8_chstarspinnerstar[24] = {0x0, 0x13, 0x4,  0xE0, 0x0, 0xA, 0x0, 0xCC,
                                       0x0, 0x16, 0x1B, 0x58, 0x0, 0x0, 0x0, 0x0,
                                       0x0, 0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0};
