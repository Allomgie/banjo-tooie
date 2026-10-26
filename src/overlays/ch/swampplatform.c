#include "common.h"

typedef struct { u8 pad_0[0x6C]; u32 local_0 : 11; u32 pad_1 : 21; } SwampPlatformKind;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_80103EF4(Actor *);
extern void func_800DF500(f32, f32, f32);
extern f32 func_80103EAC(Actor *);
extern s32 _subaddiefind_entrypoint_4(s32, Actor **, s32);
extern void func_80103DFC(Actor *, f32 *);
extern void *func_80100094(Actor *, s32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, f32 *);
extern int D_808009F8_chswampplatform;
extern f32 D_808009D0_chswampplatform[];
extern f32 D_808009E4_chswampplatform[];
extern void func_80103110(Actor *, s32);
extern s32 func_800DA298(s32);
extern s32 _chmumbopad_entrypoint_0(s32);
extern void _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
extern void _sumumbofx_entrypoint_2(s32);
extern void _sumumbofx_entrypoint_25(s32, s32, s32 *);
extern void _sumumbofx_entrypoint_24(s32, f32);
extern void _sumumbofx_entrypoint_15(s32, f32);
extern void _capod_entrypoint_13(Unk80132ED0 *, s32, s32, s32);
extern void func_80101FDC(Actor *, s32);
extern void func_8010A800(Actor *, s32);
extern void _sumumbofx_entrypoint_14(s32);
extern s32 _sumumbofx_entrypoint_27(s32);
extern void _sumumbofx_entrypoint_18(s32, f32);
extern void _sumumbofx_entrypoint_5(s32, f32);
extern void _sumumbofx_entrypoint_17(s32, f32);
extern f32 _sumumbofx_entrypoint_21(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, f32 *);
extern f32 func_800138D0(f32);
extern f32 mlAbsF(f32);
extern void _chglowbo_entrypoint_6(void);
extern void _sumumbofx_entrypoint_16(s32, f32);
extern void _sumumbofx_entrypoint_1(Actor *, s32);
extern void func_800DA524(s32);
extern void func_800DA544(s32);

void func_80800000_chswampplatform(Actor *param_0)
{
    if (!func_800DA298(0x160)) {
        if (!_gccubesearch_entrypoint_10(0x28E, ((SwampPlatformKind *)param_0)->local_0)) func_80101FDC(param_0, 0);
        param_0->scale = 2.0f;
    } else param_0->scale = 7.0f;
    func_800EE7F8((f32 *)&param_0->actorData[0], param_0->position);
    func_800EFA4C((f32 *)&param_0->actorData[4], 1.0f, 1.0f, 1.0f);
    param_0->unk64_20 = 0;
    param_0->unk64_19 = 0;
    *(f32 *)&param_0->actorData[7] = 0.0f;
}

void func_80800804_chswampplatform();

void func_808000BC_chswampplatform(Actor *param_0)
{
    s32 local_0[3];
    f32 local_1;
    f32 local_2;

    switch (param_0->unk70_10) {
    case 0:
        func_80103110(param_0, 0);
        break;
    case 1:
        if (func_800DA298(0x9DE)) {
            local_0[0] = 0;
            local_0[1] = 0;
            local_0[2] = 0;
            _sumumbofx_entrypoint_0(param_0, 1, 0x32, _chmumbopad_entrypoint_0(8));
            _sumumbofx_entrypoint_2(func_80100094(param_0, 1));
            _sumumbofx_entrypoint_25(func_80100094(param_0, 1), 0x7D, local_0);
            _sumumbofx_entrypoint_24(func_80100094(param_0, 1), 0.65f);
            _sumumbofx_entrypoint_15(func_80100094(param_0, 1), 3.0f);
            _capod_entrypoint_13(param_0->unk0, 0, 10, 0x210);
            func_80101FDC(param_0, 2);
            func_8010A800(param_0, 2);
        }
        break;
    case 2:
        func_80800804_chswampplatform(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            _sumumbofx_entrypoint_18(func_80100094(param_0, 1), 4.0f);
            func_80101FDC(param_0, 3);
        }
        break;
    case 3:
        func_80800804_chswampplatform(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        _sumumbofx_entrypoint_5(func_80100094(param_0, 1), 2.0f);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 4.0f);
            func_80101FDC(param_0, 4);
        }
        break;
    case 4:
        if (2.0f < _sumumbofx_entrypoint_21(func_80100094(param_0, 1))) {
            if (!param_0->unk64_20) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009D0_chswampplatform);
                param_0->unk64_20 = 1;
            }
            local_1 = func_800138D0((_sumumbofx_entrypoint_21(func_80100094(param_0, 1)) - 2.0f) * 0.5f * 90.0f);
            param_0->unk58 = local_1;
            param_0->scale = param_0->unk58 * 5.0f * 0.5f + 2.0f;
            ((f32 *)param_0->actorData)[4] = param_0->unk58 * 2.0f + 1.0f;
            ((f32 *)param_0->actorData)[5] = param_0->unk58 * 2.0f + 1.0f;
            ((f32 *)param_0->actorData)[6] = param_0->unk58 * 2.0f + 1.0f;
        } else {
            if (!param_0->unk64_19) {
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808009E4_chswampplatform);
                param_0->unk64_19 = 1;
            }
            local_2 = 1.0f - func_800138D0(_sumumbofx_entrypoint_21(func_80100094(param_0, 1)) * 0.5f * 90.0f);
            param_0->unk58 = local_2;
            param_0->scale = (1.0f - param_0->unk58) * 5.0f * 0.5f + 2.0f + 2.5f;
            ((f32 *)param_0->actorData)[4] = mlAbsF(func_800138D0(param_0->unk58 * 1.5f * 360.0f)) * (param_0->unk58 * 2.0f) + 1.0f;
            ((f32 *)param_0->actorData)[5] = mlAbsF(func_800138D0(param_0->unk58 * 2.5f * 360.0f)) * (param_0->unk58 * 2.0f) + 1.0f;
            ((f32 *)param_0->actorData)[6] = mlAbsF(func_800138D0(param_0->unk58 * 2.0f * 360.0f)) * (param_0->unk58 * 2.0f) + 1.0f;
        }
        func_80800804_chswampplatform(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            _chglowbo_entrypoint_6();
            func_80101FDC(param_0, 5);
            _sumumbofx_entrypoint_16(func_80100094(param_0, 1), 3.0f);
        }
        break;
    case 5:
        func_80800804_chswampplatform(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80101FDC(param_0, 6);
        }
        break;
    case 6:
        _sumumbofx_entrypoint_1(param_0, 1);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_8010A800(param_0, 0);
        func_800DA544(0x160);
        func_80101FDC(param_0, 7);
        break;
    case 7:
        func_80103110(param_0, 0);
        break;
    }
}

void func_8080061C_chswampplatform(Actor *param_0, s32 param_1)
{
    Actor *local_0[5];
    s32 local_1;
    s32 local_2;
    if (func_800DA298(0x9DE)) {
        if (func_80100094(param_0, 1)) {
            local_1 = _subaddiefind_entrypoint_4(0x28E, local_0, 5);
            _sumumbofx_entrypoint_9(func_80100094(param_0, 1), param_1);
            for (local_2 = 0; local_2 < local_1; local_2++) {
                local_0[local_2]->position[1] = *(f32 *)((u8 *)local_0[local_2] + 0x1C) - func_80103EF4(local_0[local_2]) * 0.5f;
                if (*(f32 *)((u8 *)param_0 + 0x28) != 0.0f
                    && *(f32 *)((u8 *)param_0 + 0x2C) != 0.0f
                    && *(f32 *)((u8 *)param_0 + 0x30) != 0.0f)
                    func_800DF500(*(f32 *)((u8 *)param_0 + 0x28), *(f32 *)((u8 *)param_0 + 0x2C), *(f32 *)((u8 *)param_0 + 0x30));
                local_0[local_2]->scale = param_0->scale;
                func_80101870(local_0[local_2], param_1);
            }
            _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
        }
    } else {
        param_0->position[1] = *(f32 *)((u8 *)param_0 + 0x1C) - func_80103EF4(param_0) * 0.5f;
        func_80101870(param_0, param_1);
    }
}

s32 func_808007A4_chswampplatform(Actor *param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x4B) {
        if (param_2 == 8 && param_0->unk70_10 == 0) {
            func_80101FDC(param_0, 1);
            func_80103110(param_0, 1);
        }
        return 1;
    }
    return 0;
}

void func_80800804_chswampplatform(Actor *param_0)
{
    Actor *local_0[5];
    f32 local_2;
    f32 local_3;
    s32 local_4;
    s32 local_5;
    f32 local_1[3];
    s32 i;

    local_2 = func_80103EAC(param_0);
    local_3 = ((((((f32 *)param_0->actorData)[4] > ((f32 *)param_0->actorData)[5]) ? ((f32 *)param_0->actorData)[4] : ((f32 *)param_0->actorData)[5]) > ((f32 *)param_0->actorData)[6]) ? ((((f32 *)param_0->actorData)[4] > ((f32 *)param_0->actorData)[5]) ? ((f32 *)param_0->actorData)[4] : ((f32 *)param_0->actorData)[5]) : ((f32 *)param_0->actorData)[6]) * local_2;
    local_4 = _subaddiefind_entrypoint_4(0x28E, local_0, 5);
    local_5 = 50 / local_4;
    if (((f32 *)param_0->actorData)[7] < local_3) {
        ((f32 *)param_0->actorData)[7] = local_3;
    } else {
        local_3 = ((f32 *)param_0->actorData)[7];
    }
    for (i = 0; i < local_4; i++) {
        func_80103DFC(local_0[i], local_1);
        _sumumbofx_entrypoint_7(func_80100094(param_0, 1), local_3, i * local_5, (i + 1) * local_5, local_1, NULL, NULL);
    }
}

int chswampplatform_entrypoint_0()
{
    return (int)&D_808009F8_chswampplatform;
}
