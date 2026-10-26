#include "common.h"

typedef struct { s32 local_0[3]; } HealingParticleColor;
extern HealingParticleColor D_808008DC_chmumbohealspell;
extern HealingParticleColor D_808008E8_chmumbohealspell;
extern HealingParticleColor D_808008F4_chmumbohealspell;
extern void *func_80100094(Actor *, u32);
extern void _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, HealingParticleColor *, HealingParticleColor *, HealingParticleColor *);
extern int D_80800900_chmumbohealspell;
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_80103EAC(Actor *);
extern void _sumumbofx_entrypoint_14(void *);
extern f32 _sumumbofx_entrypoint_21(void *);
extern s32 _sumumbofx_entrypoint_5(void *, f32);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, f32 *, s32);
extern int _sumumbofx_entrypoint_24(void *, f32);
extern int _sumumbofx_entrypoint_15(void *, f32);
extern int _sumumbofx_entrypoint_18(void *, f32);
extern int _sumumbofx_entrypoint_17(void *, f32);
extern int _sumumbofx_entrypoint_16(void *, f32);
extern int _sumumbofx_entrypoint_3(void *, f32);
extern u32 D_808008D0_chmumbohealspell[3];
void func_80800450_chmumbohealspell();

void func_80800000_chmumbohealspell(Actor *param_0)
{
    if (func_800DA298(0x15E) && func_800EA05C() == 0x155) {
        func_800FFA88(param_0->unk0);
    } else if (!func_800DA298(0x189)) {
        func_800FFA88(param_0->unk0);
    }
    func_80103110(param_0, 0);
}

void func_80800740_chmumbohealspell();

void func_80800074_chmumbohealspell(Actor *param_0)
{
    Actor *local_1;
    Actor *local_2;
    void *local_0;

    switch (param_0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_800DA298(0x9DE)) {
            func_80800450_chmumbohealspell(param_0, 3);
        }
        break;
    case 3:
        func_80800740_chmumbohealspell(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(param_0, 4);
        }
        break;
    case 4:
        func_80800740_chmumbohealspell(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 0));
        _sumumbofx_entrypoint_5(func_80100094(param_0, 0), 4.0f);
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(param_0, 5);
        }
        break;
    case 5:
        func_80800740_chmumbohealspell(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(param_0, 6);
        }
        break;
    case 6:
        func_80800740_chmumbohealspell(param_0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(param_0, 8);
        }
        break;
    case 7:
        func_800FFA88(param_0->unk0);
        break;
    case 8:
        break;
    case 9:
        local_1 = _subaddiefind_entrypoint_2(0x52D, 0);
        if (local_1) {
            local_0 = func_80100094(param_0, 0);
            _sumumbofx_entrypoint_7(local_0, func_80103EAC(local_1), 0, 60,
                                  local_1->position, NULL, 0);
        }
        _sumumbofx_entrypoint_14(func_80100094(param_0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(param_0, 10);
        }
        break;
    case 10:
        local_2 = _subaddiefind_entrypoint_2(0x52D, 0);
        local_0 = func_80100094(param_0, 0);
        _sumumbofx_entrypoint_7(local_0, func_80103EAC(local_2), 0, 60,
                              local_2->position, NULL, 0);
        _sumumbofx_entrypoint_14(func_80100094(param_0, 0));
        if (_sumumbofx_entrypoint_21(func_80100094(param_0, 0)) <= 0.0f) {
            func_80800450_chmumbohealspell(param_0, 11);
        }
        break;
    case 11:
        break;
    }
}

s32 func_808003A8_chmumbohealspell(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x4B:
            func_80800450_chmumbohealspell(param_0, 2);
            func_80103110(param_0, 1);
            return 1;
        case 0xB:
            if (param_2 == 0x10) {
                _capod_entrypoint_14();
                func_80800450_chmumbohealspell(param_0, 7);
                return 4;
            }
            return 3;
        case 0x49:
            if (param_2 == 0x71) {
                func_80800450_chmumbohealspell(param_0, 9);
                return 1;
            }
            return 0;
    }
    return 0;
}

void func_80800450_chmumbohealspell(param_0, param_1) Actor *param_0; s32 param_1;
{
    u32 local_0[3];
    s32 local_1;

    switch (param_1) {
    case 1:
        break;
    case 2:
        func_80103110(param_0, 1);
        break;
    case 3:
        local_0[0] = 0;
        local_0[1] = 0;
        local_0[2] = 0;
        _sumumbofx_entrypoint_0(param_0, 0, 0x3C, (s16)_chmumbopad_entrypoint_0(0x10));
        _sumumbofx_entrypoint_2(func_80100094(param_0, 0));
        _sumumbofx_entrypoint_25(func_80100094(param_0, 0), 0x7D, local_0);
        _sumumbofx_entrypoint_24(func_80100094(param_0, 0), 0.65f);
        _sumumbofx_entrypoint_15(func_80100094(param_0, 0), 3.0f);
        _capod_entrypoint_13(param_0->unk0, param_0->unk0, 0x10, 0x800);
        func_8010A800(param_0, 2);
        break;
    case 4:
        _sumumbofx_entrypoint_18(func_80100094(param_0, 0), 4.0f);
        _chglowbo_entrypoint_6();
        break;
    case 5:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 0), 3.0f);
        break;
    case 6:
        _sumumbofx_entrypoint_16(func_80100094(param_0, 0), 3.0f);
        break;
    case 7:
        _glcutDll_entrypoint_6(0x121, 0x71);
        break;
    case 8:
        _sumumbofx_entrypoint_1(param_0, 0);
        break;
    case 9:
        func_80103110(param_0, 1);
        _sumumbofx_entrypoint_0(param_0, 0, 0x3C, (s16)_chmumbopad_entrypoint_0(0x10));
        _sumumbofx_entrypoint_2(func_80100094(param_0, 0));
        _sumumbofx_entrypoint_25(func_80100094(param_0, 0), 0x7D, D_808008D0_chmumbohealspell);
        _sumumbofx_entrypoint_24(func_80100094(param_0, 0), 0.65f);
        _sumumbofx_entrypoint_17(func_80100094(param_0, 0), 3.0f);
        _sumumbofx_entrypoint_3(func_80100094(param_0, 0), 375.0f);
        _sumumbofx_entrypoint_4(func_80100094(param_0, 0));
        _capod_entrypoint_13(param_0->unk0, param_0->unk0, 0, 0x2900);
        break;
    case 10:
        _sumumbofx_entrypoint_16(func_80100094(param_0, 0), 3.0f);
        func_80101180(0x52D, 0x33, 0);
        break;
    case 11:
        _sumumbofx_entrypoint_1(param_0, 0);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x15E);
        break;
    }
    func_80102424(param_0, param_1);
}

void func_80800740_chmumbohealspell(Actor *param_0)
{
    HealingParticleColor local_0 = D_808008DC_chmumbohealspell;
    HealingParticleColor local_1 = D_808008E8_chmumbohealspell;
    HealingParticleColor local_2 = D_808008F4_chmumbohealspell;

    _sumumbofx_entrypoint_6(func_80100094(param_0, 0), 1400.0f, 500.0f, 0, 60,
                          &local_1, &local_2, &local_0);
}

s32 func_80800800_chmumbohealspell(Actor *this, f32 param_1[3]){
    if(func_80100094(this, 0) != 0){
        _sumumbofx_entrypoint_9(func_80100094(this, 0), param_1);
        _sumumbofx_entrypoint_8(func_80100094(this, 0), param_1);
    }
}

int chmumbohealspell_entrypoint_0()
{
    return (int)&D_80800900_chmumbohealspell;
}
