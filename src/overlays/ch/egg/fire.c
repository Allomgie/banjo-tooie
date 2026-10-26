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
extern void _suegg_entrypoint_5(void);
extern void _suegg_entrypoint_21(Actor *param_0, void *param_1);
extern u8 D_808003B0_cheggfire[];
extern int D_808003BC_cheggfire;
extern Actor *_suegg_entrypoint_11(s32, s32, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _sueggmove_entrypoint_7(Actor *, s32);
extern void _sueggmove_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_3(f32 *, f32);
void func_80800000_cheggfire();

void func_80800000_cheggfire(param_0) Actor *param_0;
{
    u8 *local_0;
    f32 local_1;

    local_0 = func_80100094(param_0, 0);
    *(f32 *)(local_0 + 0x28) -= func_800D8FF8();
    local_1 = func_800F10B4(*(f32 *)(local_0 + 0x30), 0, 2.0f, 0.0333f, 0.1f);
    while (*(f32 *)(local_0 + 0x28) <= 0.0f) {
        *(f32 *)(local_0 + 0x28) += local_1;
    }
    if (!func_8001210C(1)) {
        _fxegg_entrypoint_3(param_0->position, param_0->scale);
    }
}

void func_808000B8_cheggfire(Actor *param_0)
{
    EggUpdateLocal *local_0;

    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        if (!_suegg_entrypoint_8(param_0)) {
            if (func_800EEEA8(&param_0->actorData[4])) {
                local_0->flags = 1;
            } else {
                func_80800000_cheggfire(param_0);
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
                func_80800000_cheggfire(param_0);
                _suegg_entrypoint_16(param_0);
            }
        }
        break;
    }
    if (local_0->flags) {
        _suegg_entrypoint_3(param_0);
    }
}

void func_80800228_cheggfire(Actor *param_0)
{
    _suegg_entrypoint_5();
    _suegg_entrypoint_21(param_0, &D_808003B0_cheggfire);
}

int cheggfire_entrypoint_0()
{
    return (int)&D_808003BC_cheggfire;
}

u8 *cheggfire_entrypoint_1(Actor *param_0, s32 param_1, f32 param_2[3], s32 param_3) {
    Actor *local_0;

    _sueggmove_entrypoint_10(param_0);
    local_0 = _suegg_entrypoint_11(0x15B, param_1, param_3);
    *(f32 *)((char *)local_0 + 0x38) = 0.134f;
    _suegg_entrypoint_1(local_0, 3e+01f);
    _sueggmove_entrypoint_5(local_0, 1);
    _sueggmove_entrypoint_6(local_0, -2.2e+03f, -22000.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    *(u8 *)((char *)local_0 + 0x72) = (*(u8 *)((char *)local_0 + 0x72) & 0xFF03) | 8;
    return local_0;
}

Actor *cheggfire_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;

    _sueggmove_entrypoint_10(param_0, param_1);
    local_0 = _suegg_entrypoint_11(0x15B, param_1, param_3);
    local_0->scale = 0.25f;
    _sueggmove_entrypoint_5(local_0, 0);
    _sueggmove_entrypoint_6(local_0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(local_0, 30.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    local_0->unk70_10 = 1;
    return local_0;
}
