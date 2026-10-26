#include "common.h"

typedef struct { u8 pad_0[0x30]; f32 unk30; u8 pad_34[5]; u8 flags : 1; u8 pad_39 : 7; } EggUpdateLocal;
extern void *func_80100094(Actor *, u32);
extern s32 func_800EEEA8(void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _suegg_entrypoint_8(Actor *);
extern void _suegg_entrypoint_16(Actor *);
extern s32 _suegg_entrypoint_14(Actor *);
extern s32 _sueggmove_entrypoint_3(Actor *);
extern void _suegg_entrypoint_23(Actor *);
extern s32 _suegg_entrypoint_13(Actor *);
extern s32 _suegg_entrypoint_12(Actor *);
extern void _sueggmisc_entrypoint_1(Actor *);
extern void _suegg_entrypoint_3(Actor *);
extern int D_808003E0_cheggice;
extern Actor *_suegg_entrypoint_11(s32, s32, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _sueggmove_entrypoint_7(Actor *, s32);
extern void _sueggmove_entrypoint_10();
extern f32 func_800D8FF8(void);
extern f32 func_800DC0C0(void);
extern void _fxegg_entrypoint_2(f32 *, f32);
extern void _fxegg_entrypoint_1(f32 *, f32);
void func_80800000_cheggice();

void func_80800000_cheggice(param_0) Actor *param_0;
{
    f32 *local_1;
    f32 local_2;
    f32 local_0[3];
    local_1 = (f32 *)func_80100094(param_0, 0);
    local_1[10] -= func_800D8FF8();
    local_2 = func_800F10B4(local_1[12], 0, 2.0f, 0.0333f, 0.1f);
    while (local_1[10] <= 0.0f) {
        local_1[10] += local_2;
        func_800EE7F8(local_0, param_0->position);
        if (func_800DC0C0() < 0.5f) _fxegg_entrypoint_2(local_0, param_0->scale);
        else _fxegg_entrypoint_1(local_0, param_0->scale);
    }
}

void func_80800114_cheggice(Actor *param_0)
{
    EggUpdateLocal *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        if (!_suegg_entrypoint_8(param_0)) {
            if (func_800EEEA8(&param_0->actorData[4])) {
                local_0->flags = 1;
            } else {
                func_80800000_cheggice(param_0);
                _suegg_entrypoint_16(param_0);
                if (_suegg_entrypoint_14(param_0)) {
                    local_0->flags = 1;
                }
            }
        }
        break;
    case 2:
        if (!_suegg_entrypoint_8(param_0)) {
            param_0->scale = func_800F10B4(local_0->unk30, 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(param_0)) {
                _suegg_entrypoint_23(param_0);
            }
            if (_suegg_entrypoint_13(param_0)) {
                local_0->flags = 1;
            } else if (_suegg_entrypoint_12(param_0)) {
                _sueggmisc_entrypoint_1(param_0);
            } else {
                func_80800000_cheggice(param_0);
                _suegg_entrypoint_16(param_0);
            }
        }
        break;
    }
    if (local_0->flags) {
        _suegg_entrypoint_3(param_0);
    }
}

void *cheggice_entrypoint_0()
{
    return &D_808003E0_cheggice;
}

u8 *cheggice_entrypoint_1(Actor *param_0, s32 param_1, f32 param_2[3], s32 param_3) {
    Actor *local_0;

    _sueggmove_entrypoint_10(param_0);
    local_0 = _suegg_entrypoint_11(0x15c, param_1, param_3);
    *(f32 *)((char *)local_0 + 0x38) = 0.134f;
    _suegg_entrypoint_1(local_0, 3e+01f);
    _sueggmove_entrypoint_5(local_0, 1);
    _sueggmove_entrypoint_6(local_0, -2.2e+03f, -22000.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    *(u8 *)((char *)local_0 + 0x72) = (*(u8 *)((char *)local_0 + 0x72) & 0xFF03) | 8;
    return local_0;
}

Actor *cheggice_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;

    _sueggmove_entrypoint_10(param_0, param_1);
    local_0 = _suegg_entrypoint_11(0x15C, param_1, param_3);
    local_0->scale = 0.25f;
    _sueggmove_entrypoint_5(local_0, 0);
    _sueggmove_entrypoint_6(local_0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(local_0, 30.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    local_0->unk70_10 = 1;
    return local_0;
}
