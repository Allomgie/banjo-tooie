#include "common.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef union { s32 word; void *pointer; } DinoMessage30;
extern u8 D_80800F10_chdinofamilysmall[];
extern u16 D_80800E94_chdinofamilysmall[][4];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 _capod_entrypoint_14(void);
extern f32 B_80800F70_chdinofamilysmall[];
extern f32 B_80800F94_chdinofamilysmall[];
extern f32 B_80800FA0_chdinofamilysmall[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800DF500(f32, f32, f32);
extern void func_800DE498(s32, f32 *, f32 *, f32, s32, void *);
extern void *func_800D674C(s32);
extern void *D_80800F20_chdinofamilysmall;
extern f32 func_80103EAC(Actor *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern f32 _sumumbofx_entrypoint_26(void *);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, s32, s32);
extern void _sumumbofx_entrypoint_5(void *, f32);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800138D0(f32);
extern f32 func_80013970(f32);
extern void func_800C4244(s32, f32, s32, f32 *, f32, f32);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern void _sumumbofx_entrypoint_24(void *, f32);
void func_808008B4_chdinofamilysmall();

void func_80800000_chdinofamilysmall(Actor *param_0)
{
    if (_glcutDll_entrypoint_20()) func_808008B4_chdinofamilysmall(param_0, 10);
    else if (!func_800DA298(0x15F)) func_808008B4_chdinofamilysmall(param_0, 1);
    else func_808008B4_chdinofamilysmall(param_0, 9);
    ((f32 *)param_0->actorData)[7] = param_0->position[1];
    func_800EFA4C((f32 *)&param_0->actorData[4], 1.0f, 1.0f, 1.0f);
}

void func_80800090_chdinofamilysmall(Actor *param_0)
{
    extern u8 D_80800EE8_chdinofamilysmall[];
    extern u8 D_80800EFC_chdinofamilysmall[];
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    f32 local_5[3];
    f32 local_6;

    switch (param_0->unk70_10) {
    case 1:
        if (_subaddiedialog_entrypoint_4(param_0->position, 0x258, 0)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17CB, 0xF, param_0->position, 0x39);
        }
        _sudeflect_entrypoint_1(param_0->position, param_0->scale * 235.0f, 0, param_0->scale * 179.0f, 0x1E);
        _chdinofamilyfx_entrypoint_0(param_0);
        break;
    case 2:
        if (func_800DA298(0x9DE)) {
            func_808008B4_chdinofamilysmall(param_0, 3);
        }
        _chdinofamilyfx_entrypoint_0(param_0);
        break;
    case 3:
        func_80103DFC(param_0, local_0);
        _sumumbofx_entrypoint_7(func_80100094(param_0, 1), func_80103EAC(param_0), 0, 0x28, local_0, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_808008B4_chdinofamilysmall(param_0, 4);
        }
        _chdinofamilyfx_entrypoint_0(param_0);
        break;
    case 4:
        func_80103DFC(param_0, local_1);
        _sumumbofx_entrypoint_7(func_80100094(param_0, 1), func_80103EAC(param_0), 0, 0x28, local_1, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        _sumumbofx_entrypoint_5(func_80100094(param_0, 1), 2.0f);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_808008B4_chdinofamilysmall(param_0, 5);
        }
        break;
    case 5:
        func_80103DFC(param_0, local_2);
        _sumumbofx_entrypoint_7(func_80100094(param_0, 1), func_80103EAC(param_0), 0, 0x28, local_2, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        param_0->position[1] = func_800F12D4(_sumumbofx_entrypoint_26(func_80100094(param_0, 1)),
            0.0f, 1.0f, 0.0f, 800.0f);
        param_0->position[1] += *(f32 *)((u8 *)param_0 + 0x34);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_808008B4_chdinofamilysmall(param_0, 6);
        }
        break;
    case 6:
        func_80103DFC(param_0, local_3);
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 1)) > 2.0f) {
            if (!param_0->unk64_20) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800EE8_chdinofamilysmall);
                param_0->unk64_20 = 1;
            }
            param_0->scale = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                4.0f, 2.0f, 0.5f, 0.50f);
            *(f32 *)((u8 *)param_0 + 0x30) =
            *(f32 *)((u8 *)param_0 + 0x2C) =
            *(f32 *)((u8 *)param_0 + 0x28) = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                4.0f, 2.0f, 1.0f, 2.0f);
        } else {
            local_4 = func_800F10B4(_sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                2.0f, 0.0f, 1.0f, 0.0f);
            if (!param_0->unk64_19) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800EFC_chdinofamilysmall);
                param_0->unk64_19 = 1;
            }
            param_0->scale = func_800F12D4(_sumumbofx_entrypoint_21(func_80100094(param_0, 1)),
                2.0f, 0.0f, 0.50f, 1.0f);
            *(f32 *)((u8 *)param_0 + 0x28) = func_800138D0(local_4 * 3.0f * 360.0f) * local_4 + 1.0f;
            *(f32 *)((u8 *)param_0 + 0x2C) = func_800138D0(local_4 * 5.0f * 360.0f) * local_4 + 1.0f;
            *(f32 *)((u8 *)param_0 + 0x30) = func_800138D0(local_4 * 4.0f * 360.0f) * local_4 + 1.0f;
        }
        _sumumbofx_entrypoint_7(func_80100094(param_0, 1), func_80103EAC(param_0) *
            (func_80013970(_sumumbofx_entrypoint_26(func_80100094(param_0, 1)) * 180.0f) * 2.0f + 1.0f),
            0, 0x28, local_3, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_808008B4_chdinofamilysmall(param_0, 7);
        }
        break;
    case 7:
        func_80103DFC(param_0, local_5);
        _sumumbofx_entrypoint_7(func_80100094(param_0, 1), func_80103EAC(param_0), 0, 0x28, local_5, 0, 0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        local_6 = _sumumbofx_entrypoint_21(func_80100094(param_0, 1));
        if (local_6 <= (0.55f * 3.0f) && local_6 >= 1.05f) {
            param_0->position[1] = func_800138D0(func_800F10B4(local_6, (0.55f * 3.0f), 1.05f, 0.0f, 90.0f)) * 800.0f;
            param_0->position[1] += *(f32 *)((u8 *)param_0 + 0x34);
        } else if (local_6 < 1.05f) {
            if (!param_0->unk74_30) {
                func_800C4244(0x416, 0.9f, 0x55F0, param_0->position, 100.0f, 2500.0f);
                param_0->unk74_30 = 1;
                func_800E1610(3, 100.0f, 0.6f, param_0->position);
                param_0->position[1] = *(f32 *)((u8 *)param_0 + 0x34);
            }
        }
        if (local_6 <= 0.0f) {
            func_808008B4_chdinofamilysmall(param_0, 8);
        }
        break;
    case 8:
        func_808008B4_chdinofamilysmall(param_0, 9);
        break;
    case 9:
        if (_subaddiedialog_entrypoint_4(param_0->position, 0x258, 0)) {
            _subaddiedialog_entrypoint_11(param_0->unk0, 0x17CC, 0xF, param_0->position, 0x39);
        }
        _sudeflect_entrypoint_1(param_0->position, param_0->scale * 235.0f, 0, param_0->scale * 179.0f, 0x1E);
        _chdinofamilyfx_entrypoint_0(param_0);
        break;
    case 10:
        _chdinofamilyfx_entrypoint_0(param_0);
        break;
    }
}

void func_808008B4_chdinofamilysmall(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[4];
    switch (param_1) {
    case 1:
        param_0->scale = 0.5f;
        break;
    case 3:
        *(s32 *)&local_0[1] = 0;
        *(s32 *)&local_0[2] = 0;
        *(s32 *)&local_0[3] = 0;
        _sumumbofx_entrypoint_0(param_0, 1, 0x28, _chmumbopad_entrypoint_0(7));
        _sumumbofx_entrypoint_2(func_80100094(param_0, 1));
        _sumumbofx_entrypoint_25(func_80100094(param_0, 1), 0x7D, &local_0[1]);
        _sumumbofx_entrypoint_24(func_80100094(param_0, 1), 0.2f);
        _sumumbofx_entrypoint_15(func_80100094(param_0, 1), 3.0f);
        _capod_entrypoint_13(param_0->unk0, 0, 0x15, 0x210);
        func_8010A800(param_0, 2);
        break;
    case 4:
        _sumumbofx_entrypoint_18(func_80100094(param_0, 1), 2.0f);
        _chglowbo_entrypoint_6();
        break;
    case 5:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 3.0f);
        break;
    case 6:
        param_0->unk64_19 = 0;
        param_0->unk64_20 = 0;
        _sumumbofx_entrypoint_20(func_80100094(param_0, 1), 4.0f);
        param_0->position[1] = *(f32 *)&param_0->actorData[7] + 800.0f;
        break;
    case 7:
        param_0->unk74_30 = 0;
        _sumumbofx_entrypoint_16(func_80100094(param_0, 1), 3.0f);
        *((u8 *)param_0 + 0x77) &= ~0xF;
        param_0->scale = 1.0f;
        break;
    case 8:
        _sumumbofx_entrypoint_1(param_0, 1);
        func_8010A800(param_0, 0);
        param_0->position[1] = *(f32 *)&param_0->actorData[7];
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x15F);
        break;
    case 9:
    case 10:
        param_0->scale = 1.0f;
        break;
    }
    func_80102424(param_0, param_1);
}

s32 func_80800AF4_chdinofamilysmall(Actor *param_0, s32 param_1, DinoMessage30 param_2)
{
    switch (param_1) {
    case 0xB:
        _capod_entrypoint_14();
        func_80101180(0x290, 0x33, 1);
        return 4;
    case 0x4B:
        func_80101FDC(param_0, 2);
        return 1;
    case 0x52:
        _gcdialogcamera_entrypoint_4(param_0->position);
        _gcdialogcamera_entrypoint_3(D_80800F10_chdinofamilysmall, param_0->scale);
        return 3;
    case 0x1F:
        func_801015D0(param_0);
        if (D_80800E94_chdinofamilysmall[param_0->unk70_10][0] == 0x14D) func_800DF744(3, 1);
        else {
            func_800DF744(1, 0);
            func_800DF744(2, 1);
            func_800DF744(3, 2);
        }
        return 1;
    default:
        return 0;
    }
}

void func_80800C10_chdinofamilysmall(Actor *param_0, s32 param_1)
{
    f32 *local_0;
    f32 *local_1;
    s32 local_2;

    if (func_80100094(param_0, 1)) {
        _sumumbofx_entrypoint_9(func_80100094(param_0, 1), param_1);
    }
    if (param_0->unk70_10 == 6) {
        func_801015D0(param_0);
        for (local_2 = 4, local_0 = B_80800FA0_chdinofamilysmall, local_1 = B_80800F94_chdinofamilysmall;
             local_2 != 0; local_2--, local_0 -= 3, local_1 -= 3) {
            func_800EE7F8(local_0, local_1);
            if (local_0[0] != 0.0f && local_0[1] != 0.0f && local_0[2] != 0.0f) {
                func_800DF744(3, 1);
                func_800DF500(local_0[0], local_0[1], local_0[2]);
                func_800DF410(160 - local_2 * 30);
                func_800DF830(2);
                func_800DE498(param_1, param_0->position, param_0->rotation, param_0->scale, 0,
                    func_800D674C(param_0->unk0->unk14));
            }
        }
        func_800EE7F8(B_80800F70_chdinofamilysmall, (f32 *)&param_0->actorData[4]);
        if (((f32 *)param_0->actorData)[4] != 0.0f && ((f32 *)param_0->actorData)[5] != 0.0f &&
            ((f32 *)param_0->actorData)[6] != 0.0f) {
            func_800DF500(((f32 *)param_0->actorData)[4], ((f32 *)param_0->actorData)[5],
                ((f32 *)param_0->actorData)[6]);
        }
    }
    func_801018A4(param_0, param_1);
    if (func_80100094(param_0, 1)) {
        _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
    }
}

int chdinofamilysmall_entrypoint_0()
{
  return &D_80800F20_chdinofamilysmall;
}
