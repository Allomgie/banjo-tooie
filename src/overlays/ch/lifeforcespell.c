#include "common.h"

extern Vec3f D_808004A8_chlifeforcespell;
extern void _sumumbofx_entrypoint_24(void *, f32);
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_20(void *, f32);
extern u8 D_808004C0_chlifeforcespell[];
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F3214(f32 *, f32 *, void *, f32);
extern f32 _sumumbofx_entrypoint_22(void *);
extern void _subaddiefade_entrypoint_9();
extern s32 D_808004B4_chlifeforcespell;
extern int func_80100094();
extern void func_800EFD24(f32 *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_7();
extern Actor *func_80108528(s32, f32 *, s32, Actor **);

int chlifeforcespell_entrypoint_0()
{
    extern int D_80800460_chlifeforcespell;
    return (int)&D_80800460_chlifeforcespell;
}

void func_8080000C_chlifeforcespell(Actor *param_0)
{
    Vec3f local_0 = D_808004A8_chlifeforcespell;
    void *local_1;
    _sumumbofx_entrypoint_0(param_0, 1, 0x14, (s16)_chmumbopad_entrypoint_0(0xD));
    local_1 = func_80100094(param_0, 1);
    _sumumbofx_entrypoint_2(local_1);
    _sumumbofx_entrypoint_25(local_1, 150, local_0.f);
    _sumumbofx_entrypoint_24(local_1, 0.7f);
    _sumumbofx_entrypoint_15(local_1, 2.0f);
    _sumumbofx_entrypoint_20(local_1, 3.0f);
}

void func_808000C8_chlifeforcespell(Actor *param_0)
{
    f32 local_0[3];
    void *local_1;
    Actor *local_2;
    local_1 = (void *)func_80100094(param_0, 1);
    local_2 = func_80106790(param_0->unk3C);
    func_800EFD24(local_0);
    if (func_800DA298(0x9DE)) {
        _subaddieskeleton_entrypoint_0(local_2, param_0->unk6C_0, param_0->position);
        _sumumbofx_entrypoint_7(local_1, param_0->actorData[3], 0, 20, local_0, param_0->position, &D_808004B4_chlifeforcespell);
        switch (param_0->unk70_10) {
        case 1:
            if (_sumumbofx_entrypoint_21(local_1) == 0.0f) {
                func_800D9078(&param_0->unk58);
                if (_sumumbofx_entrypoint_5(local_1, 1.85f)) {
                    _sumumbofx_entrypoint_17(local_1, ((f32 *)param_0->actorData)[4]);
                    func_80101FDC(param_0, 2);
                    param_0->unk58 = ((f32 *)param_0->actorData)[4];
                }
            }
            break;
        case 2:
            if (func_800D9078(&param_0->unk58)) {
                _chglowbo_entrypoint_6();
                _sumumbofx_entrypoint_16(local_1, 1.5f);
                func_80101FDC(param_0, 3);
            }
            break;
        case 3:
            if (_sumumbofx_entrypoint_22(local_1) < 0.05f) {
                _sumumbofx_entrypoint_1(param_0, 1);
                func_8010114C(param_0->unk3C, 0x4C, 0);
                func_800FFA88(param_0->unk0);
                func_800DA544(0x9DF);
                func_800DA524(0x9DE);
                return;
            }
            break;
        }
        _sumumbofx_entrypoint_14(local_1);
    }
}

s32 func_8080028C_chlifeforcespell(s32 param_0, s32 param_1) {
    _sumumbofx_entrypoint_9(func_80100094(param_0, 1), param_1);
    _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
}

Unk80132ED0 *chlifeforcespell_entrypoint_1(Actor **param_0, f32 *param_1,
    s32 param_2, f32 param_3, s32 param_4)
{
    Actor *local_0;

    local_0 = func_80108528(0x45C, param_1, 0, param_0);
    *(f32 *)&local_0->actorData[3] = param_2;
    local_0->unk6C_0 = param_4;
    *(f32 *)&local_0->actorData[4] = param_3;
    local_0->unk58 = 1.85f;
    local_0->unk3C = (*param_0)->unk0;
    return local_0->unk0;
}

int chlifeforcespell_entrypoint_2(void *param_0, Unk80132ED0 *param_1, f32 *param_2)
{
    Actor *local_0;
    void *local_1;
    f32 local_2[3];
    f32 local_3;

    local_0 = func_80106790(param_1);
    local_1 = (void *)func_80100094(local_0, 1);
    if (func_800DA298(0x9DE) && local_1) {
        _subaddiefade_entrypoint_9(param_0, local_2);
        if (local_0->unk70_10 == 1) {
            local_3 = func_800F10B4(local_0->unk58, 0.0f, 1.85f, 1.0f, 0.0f);
            func_800F3214(param_2, local_2, D_808004C0_chlifeforcespell, local_3);
            return 1;
        }
        func_800F3214(param_2, local_2, D_808004C0_chlifeforcespell, _sumumbofx_entrypoint_22(local_1));
        return 1;
    }
    _subaddiefade_entrypoint_9(param_0, param_2);
    return 0;
}
