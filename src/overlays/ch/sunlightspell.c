#include "common.h"

extern f32 D_808008B0_chsunlightspell;
extern void *func_80100094(Actor *, u32);
typedef union { s32 word; void *pointer; } SunlightSpellEventPayload;
extern void *D_808008BC_chsunlightspell;
extern u8 D_80800890_chsunlightspell[];
extern s32 func_800DA298(s32);
extern s32 _sumumbofx_entrypoint_27(s32);
extern void _sumumbofx_entrypoint_5(s32, f32);
extern f32 _sumumbofx_entrypoint_26(s32);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void _subaddieaudioloop_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_1(Actor *, s32);
typedef struct { f32 local_0[3]; } SunlightVector;
extern u8 D_808008A4_chsunlightspell[];
extern void _sumumbofx_entrypoint_15(void *, f32);
extern void _sumumbofx_entrypoint_16(void *, f32);
extern void _sumumbofx_entrypoint_17(void *, f32);
extern void _sumumbofx_entrypoint_18(void *, f32);
extern void _sumumbofx_entrypoint_24(void *, f32);
void func_80800404_chsunlightspell();

void func_80800000_chsunlightspell(s32 *param_0) {
    if (func_800DA298(0xE9) != 0) {
        func_800FFA88(*param_0);
        return;
    }
    func_80800404_chsunlightspell(param_0, 1);
}

s32 func_80800704_chsunlightspell(s32 param_0, f32 param_1);
extern void _sumumbofx_entrypoint_7(void *, f32, s32, s32, f32 *, s32, s32);

void func_80800668_chsunlightspell();

void func_80800048_chsunlightspell(Actor *param_0)
{
    f32 local_0;
    f32 local_1;
    f32 local_2;

    switch (param_0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_800DA298(0x9DE)) {
            func_80800404_chsunlightspell(param_0, 3);
        }
        break;
    case 3:
        func_80800668_chsunlightspell(param_0);
        func_80800704_chsunlightspell(param_0, 1e+02f);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80800404_chsunlightspell(param_0, 4);
        }
        break;
    case 4:
        func_80800668_chsunlightspell(param_0);
        func_80800704_chsunlightspell(param_0, 1e+02f);
        _sumumbofx_entrypoint_5(func_80100094(param_0, 1), 4.5f);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80800404_chsunlightspell(param_0, 5);
        }
        break;
    case 5:
        local_0 = _sumumbofx_entrypoint_26(func_80100094(param_0, 1));
        func_80800668_chsunlightspell(param_0);
        func_80800704_chsunlightspell(param_0, func_800F12D4(local_0, 0.0f, 1.0f, 100.0f, 10.0f));
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80800404_chsunlightspell(param_0, 6);
        }
        break;
    case 6:
        local_1 = _sumumbofx_entrypoint_26(func_80100094(param_0, 1));
        func_80800668_chsunlightspell(param_0);
        func_80800704_chsunlightspell(param_0, func_800F12D4(local_1, 0.0f, 1.0f, 10.0f, 100.0f));
        param_0->scale = func_800F12D4(local_1, 0.0f, 1.0f, 0.01f, 1.0f);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800890_chsunlightspell);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80800404_chsunlightspell(param_0, 7);
        }
        break;
    case 7:
        func_80800668_chsunlightspell(param_0);
        func_80800704_chsunlightspell(param_0, 1e+02f);
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800890_chsunlightspell);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80800404_chsunlightspell(param_0, 8);
        }
        break;
    case 8:
        func_80800668_chsunlightspell(param_0);
        func_80800704_chsunlightspell(param_0, 1e+02f);
        local_2 = 1.0f - _sumumbofx_entrypoint_26(func_80100094(param_0, 1));
        param_0->alpha = local_2 * 255.0f;
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, D_80800890_chsunlightspell);
        _subaddieaudioloop_entrypoint_1(param_0, local_2 * 20000.0f);
        if (_sumumbofx_entrypoint_27(func_80100094(param_0, 1))) {
            func_80800404_chsunlightspell(param_0, 9);
        }
        break;
    case 9:
        break;
    }
}

void func_80800404_chsunlightspell(Actor *param_0, s32 param_1)
{
    switch (param_1) {
    case 1:
        param_0->unk64_19 = 0;
        break;
    case 2:
        func_80103110(param_0, 1);
        *((u8 *)param_0 + 0x7A) = (*((u8 *)param_0 + 0x7A) & ~0xC0) | 0x80;
        break;
    case 3: {
        SunlightVector local_0 = *(SunlightVector *)D_808008A4_chsunlightspell;
        s16 local_1;
        local_1 = _chmumbopad_entrypoint_0(6);
        _sumumbofx_entrypoint_0(param_0, 1, 0x2E, local_1);
        _sumumbofx_entrypoint_2(func_80100094(param_0, 1));
        _sumumbofx_entrypoint_15(func_80100094(param_0, 1), 3.0f);
        _sumumbofx_entrypoint_24(func_80100094(param_0, 1), 0.5f);
        _sumumbofx_entrypoint_25(func_80100094(param_0, 1), 0, &local_0);
        _capod_entrypoint_13(param_0->unk0, 0, 0x12, 0x10);
        break;
    }
    case 4:
        _sumumbofx_entrypoint_18(func_80100094(param_0, 1), 6.0f);
        break;
    case 5:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 2.0f);
        break;
    case 6:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 6.0f);
        param_0->unk64_19 = 1;
        param_0->scale = 0.01f;
        break;
    case 7:
        _sumumbofx_entrypoint_17(func_80100094(param_0, 1), 1.5f);
        param_0->scale = 1.0f;
        break;
    case 8:
        _sumumbofx_entrypoint_16(func_80100094(param_0, 1), 3.0f);
        break;
    case 9:
        _sumumbofx_entrypoint_1(param_0, 1);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0xE9);
        _subaddiedialog_entrypoint_11(param_0->unk0, 0x1035, 7, param_0->position, 0x10);
        param_0->unk64_16 = 0;
        _subaddieaudioloop_entrypoint_2(param_0);
        func_800FFAB0(param_0);
        break;
    }
    func_80102424(param_0, param_1);
}

void func_80800668_chsunlightspell(u8 *param_0) {
    f32 sp34[3];
    f32 sp28[3];
    f32 sp20[2];

    if (func_800BFFB4(0, 4, sp34) != 0) {
        func_800E3980(sp28);
        func_800F18FC(sp28, sp34, sp20);
        func_800EEBF0(sp34, sp20, 0x447A0000);
        func_800EE780(param_0 + 4, sp28, sp34);
        func_800F18FC(param_0 + 4, &D_808008B0_chsunlightspell, sp20);
        (*(f32 *)((s8 *)(param_0) + (0x48))) = sp20[1];
        (*(f32 *)((s8 *)(param_0) + (0x44))) = sp20[0];
    }
}

s32 func_80800704_chsunlightspell(s32 param_0, f32 param_1)
{
    _sumumbofx_entrypoint_7(func_80100094(param_0, 1), param_1, 0, 0x2E, param_0 + 4, 0, 0);
    _sumumbofx_entrypoint_14(func_80100094(param_0, 1));
}

void func_80800768_chsunlightspell(Actor *param_0, s32 param_1)
{
    if (func_80100094(param_0, 1) != NULL) {
        _sumumbofx_entrypoint_8(func_80100094(param_0, 1), param_1);
    }
    if (param_0->unk64_19) {
        func_80101870(param_0, param_1);
    }
}

s32 func_808007CC_chsunlightspell(Actor *param_0, s32 param_1, SunlightSpellEventPayload param_2)
{
    switch (param_1) {
    case 0x4B:
        _subaddieDll_entrypoint_0(param_0);
        func_80800404_chsunlightspell(param_0, 2);
        return 1;
    case 0x2E:
        func_800FFA88(param_0->unk0);
        return 1;
    }
    return 0;
}

void *chsunlightspell_entrypoint_0(void)
{
    return &D_808008BC_chsunlightspell;
}
