#include "common.h"

extern f32 D_80800998_chfantasysafe[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800DB9B0(void);
extern void func_80101FDC(Actor *, s32);
extern s32 func_800DA298(s32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_801015D0(Actor *);
extern s32 _glcutDll_entrypoint_20(void);
extern void func_800DF744(s32, s32);
extern int D_80800AA0_chfantasysafe;
extern int D_80800AE8_chfantasysafe;
typedef struct { f32 unk0; f32 unk4; u8 unk8; } SafeKey;
extern u8 D_808009AC_chfantasysafe[];
extern u8 D_808009D4_chfantasysafe[];
extern u8 D_808009DC_chfantasysafe[];
extern u8 D_808009F4_chfantasysafe[];
extern u8 D_808009FC_chfantasysafe[];
extern SafeKey D_80800A08_chfantasysafe[];
extern u8 D_80800A98_chfantasysafe[];
extern void _subaddiedialog_entrypoint_8();
extern s32 func_800D90A4(f32 *);
extern void _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
extern void _subaddieaudioloop_entrypoint_2(Actor *);
extern void func_800FC6B0(s32);
extern void _subaddieaudioloop_entrypoint_4();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddieaudioquick_entrypoint_2();
extern void func_80103110(Actor *, s32);
extern void func_800D91B8(f32 *);
extern void func_800C3F48(s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 func_8010262C(Unk80132ED0 *, s32);
extern void func_800E0AFC(s32, s32, f32, f32, f32, f32);
void func_808001A0_chfantasysafe();
extern void func_801018A4(), func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chfantasysafe(), func_808001A0_chfantasysafe();
extern u8 D_80800960_chfantasysafe[];

void func_80800000_chfantasysafe(param_0) Actor *param_0;
{
    s32 pad[2];
    s32 local_3;
    s32 local_2;
    s32 local_1;
    s32 local_0;

    func_800EFA4C(param_0->position, 4539.4f, -748.6f, 2277.6f);
    if (_glcutDll_entrypoint_20()) {
        param_0->actorData[4] = 0;
        param_0->unk79_4 = 0;
        param_0->unk58 = param_0->unk54 = param_0->unk50 =
            ((f32 *)param_0->actorData)[3] = ((f32 *)param_0->actorData)[7] = 0.0f;
        param_0->rotation[1] = 228.0f;
        func_80101FDC(param_0, 6);
        return;
    }
    if (func_800DA298(0x38D)) {
        param_0->rotation[1] = 360.0f;
        param_0->unk50 = 0.0f;
        param_0->unk54 = 110.0f;
        func_80101FDC(param_0, 5);
        return;
    }
    local_0 = func_800DA298(0x38B) ? 1 : 0;
    local_1 = func_800DA298(0x38A) ? 1 : 0;
    local_2 = func_800DA298(0x389) ? 1 : 0;
    local_3 = func_800DA298(0x38C) ? 1 : 0;
    param_0->unk50 = ((f32 *)param_0->actorData)[3] = ((f32 *)param_0->actorData)[7] = D_80800998_chfantasysafe[local_3 + local_2 + local_1 + local_0];
    param_0->unk54 = 0.0f;
    param_0->rotation[1] = 228.0f;
}

void func_808001A0_chfantasysafe(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_1;
    f32 local_2;
    SafeKey *local_3; /* unused: the target's frame has this slot */
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_7;
    f32 local_8;

    switch (param_0->unk70_10) {
    case 1:
        _subaddiedialog_entrypoint_8(param_0, param_0->position, D_808009DC_chfantasysafe, D_808009AC_chfantasysafe, 5);
        break;
    case 2:
        if (func_800D90A4(&param_0->unk58)) {
            local_6 = func_800DA298(0x38B) ? 1 : 0;
            local_5 = func_800DA298(0x38A) ? 1 : 0;
            local_4 = func_800DA298(0x389) ? 1 : 0;
            local_7 = func_800DA298(0x38C) ? 1 : 0;
            if (local_7 + local_4 + local_5 + local_6 >= 3) {
                param_0->unk58 = 1.0f;
                func_80101FDC(param_0, 3);
                local_1 = 0x10;
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x13DD, 0, param_0->position, 0);
            } else {
                func_80101FDC(param_0, 1);
                local_1 = 0xE;
            }
            func_800DA544(param_0->unk6C_0 + 0x389);
            _subaddieaudioloop_entrypoint_2(param_0);
            func_800FC6B0(local_1);
            param_0->unk50 = ((f32 *)param_0->actorData)[7] = ((f32 *)param_0->actorData)[3];
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808009F4_chfantasysafe);
            param_0->unk50 = func_800F10B4(param_0->unk58, 2.0f, 0, ((f32 *)param_0->actorData)[7], ((f32 *)param_0->actorData)[3]);
        }
        break;
    case 3:
        param_0->unk54 = func_800F10B4(param_0->unk58, 1.0f, 0, 0, 110.0f);
        if (func_800D90A4(&param_0->unk58)) {
            param_0->unk54 = 110.0f;
            param_0->unk58 = 3.0f;
            func_80101FDC(param_0, 4);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009D4_chfantasysafe);
        }
        break;
    case 4:
        if (func_800D90A4(&param_0->unk58)) {
            func_80101FDC(param_0, 5);
            func_800DA544(0x38D);
            _subaddieaudioloop_entrypoint_2(param_0);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009D4_chfantasysafe);
        } else {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_808009FC_chfantasysafe);
        }
        param_0->rotation[1] = func_800F10B4(param_0->unk58, 3.0f, 0, 228.0f, 360.0f);
        break;
    case 5:
        func_80103110(param_0, 0);
        break;
    case 6:
        func_800D91B8(&param_0->unk58);
        local_8 = D_80800A08_chfantasysafe[param_0->actorData[4] + 1].unk0;
        if (local_8 < param_0->unk58) {
            param_0->actorData[4]++;
            if (D_80800A08_chfantasysafe[param_0->actorData[4]].unk4 == 0.0f) {
                func_800C3F48(0x66538CA0);
                func_800C3F48(0x4CB38CA1);
            } else {
                func_800C3F48(0x66538CA1);
            }
            param_0->unk79_4 = D_80800A08_chfantasysafe[param_0->actorData[4]].unk8;
        }
        local_2 = func_800F12D4(param_0->unk58, D_80800A08_chfantasysafe[param_0->actorData[4]].unk0, D_80800A08_chfantasysafe[param_0->actorData[4] + 1].unk0, D_80800A08_chfantasysafe[param_0->actorData[4]].unk4, D_80800A08_chfantasysafe[param_0->actorData[4] + 1].unk4);
        param_0->rotation[1] = func_800F1214(local_2, 228.0f, 360.0f);
        param_0->unk54 = func_800F1214(local_2, 0.0f, 110.0f);
        param_0->unk50 = func_800F1214(local_2, 0.0f, 360.0f);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800A98_chfantasysafe);
        break;
    }
    local_0 = func_8010262C(param_0->unk0, 2);
    if (local_0) {
        func_800E0AFC(local_0, 0x2A, 1.0f, 0, 0.0f, param_0->unk54);
        func_800E0AFC(local_0, 0x2B, 1.0f, 0, 0.0f, param_0->unk50);
    }
}

s32 func_80800630_chfantasysafe(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    s32 local_0;
    s32 local_1[1];
    f32 *local_2;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    s32 local_3;
    switch (param_1) {
        case 0x49:
            local_0 = param_2 - 0x51;
            if (func_800DB9B0()) {
                param_1 = 0x100;
            } else {
                param_1 = 0;
            }
            local_1[0] = param_1 | 0x810;
            if (local_0 < 4 && local_0 >= 0) {
                param_0->unk58 = 2.0f;
                func_80101FDC(param_0, 2);
                param_0->unk6C_0 = local_0;
                local_2 = &D_80800998_chfantasysafe[local_0];
                ((f32 *)param_0->actorData)[7] = param_0->unk50 = local_2[0];
                ((f32 *)param_0->actorData)[3] = local_2[1];
                local_3 = func_800DA298(0x38B) ? 1 : 0;
                local_6 = func_800DA298(0x38A) ? 1 : 0;
                local_5 = func_800DA298(0x389) ? 1 : 0;
                param_1 = func_800DA298(0x38C) ? 1 : 0;
                if (param_1 + local_5 + local_6 + local_3 >= 3) {
                    _capod_entrypoint_13(param_0->unk0, 0, 0, local_1[0]);
                    return 1;
                }
                _capod_entrypoint_13(param_0->unk0, 0, 2, local_1[0]);
                return 1;
            }
            return 0;
        case 0x1F:
            func_801015D0(param_0);
            if (_glcutDll_entrypoint_20()) {
                func_800DF744(1, (param_0->unk79_4 & 1) ? 1 : 0);
                func_800DF744(2, (param_0->unk79_4 & 2) ? 1 : 0);
                func_800DF744(3, (param_0->unk79_4 & 4) ? 1 : 0);
                func_800DF744(4, (param_0->unk79_4 & 8) ? 1 : 0);
            } else {
                func_800DF744(1, func_800DA298(0x389) ? 1 : 0);
                func_800DF744(2, func_800DA298(0x38A) ? 1 : 0);
                func_800DF744(3, func_800DA298(0x38B) ? 1 : 0);
                func_800DF744(4, func_800DA298(0x38C) ? 1 : 0);
            }
            return 1;
        default:
            return 0;
    }
}

int chfantasysafe_entrypoint_0()
{
    return (int)&D_80800AA0_chfantasysafe;
}

int chfantasysafe_entrypoint_1()
{
    return (int)&D_80800AE8_chfantasysafe;
}
