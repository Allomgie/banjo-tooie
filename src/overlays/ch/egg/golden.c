#include "common.h"

extern void _suegg_entrypoint_16();
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C4140(s32, f32 *, u32);
typedef struct { u8 pad_0[0x38]; u32 pad_1 : 8; u32 local_0 : 1; u32 pad_2 : 23; } GoldenEggPendingFlags1041;
extern int D_808003F0_chegggolden;
extern Actor *_suegg_entrypoint_11(s32, s32, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _sueggmove_entrypoint_7(Actor *, s32);
extern void _sueggmove_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void _fxegg_entrypoint_6(f32 *, f32, f32 *);
void func_80800000_chegggolden();

void func_80800000_chegggolden(param_0) Actor *param_0;
{
    f32 *local_2;
    f32 local_3;
    f32 local_0[3];
    f32 local_1[3];

    local_2 = (f32 *)func_80100094(param_0, 0);
    if (func_800A946C() < 3) {
        func_800EFA20(local_0, &((f32 *)param_0->actorData)[4], 0.5f);
        local_2[10] -= func_800D8FF8();
        local_3 = func_800F10B4(local_2[12], 0, 1.8f, 0.0333f, 0.1f);
        while (local_2[10] <= 0.0f) {
            local_2[10] += local_3;
            func_800EE7F8(local_1, param_0->position);
            _fxegg_entrypoint_6(param_0->position, param_0->scale, local_0);
        }
    }
}

void func_80800110_chegggolden(Actor *param_0)
{
    u8 *local_0;
    local_0 = (u8 *)func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        if (!_suegg_entrypoint_8(param_0)) {
            if (func_800EEEA8((u8 *)param_0 + 0x28)) ((GoldenEggPendingFlags1041 *)local_0)->local_0 = 1;
            else {
                func_80800000_chegggolden(param_0);
                _suegg_entrypoint_16(param_0);
                if (_suegg_entrypoint_14(param_0)) ((GoldenEggPendingFlags1041 *)local_0)->local_0 = 1;
            }
        }
        break;
    case 2:
        if (!_suegg_entrypoint_8(param_0)) {
            param_0->scale = func_800F10B4(*(f32 *)(local_0 + 0x30), 0.0f, 0.134f, 0.1f, 0.25f);
            if (_sueggmove_entrypoint_3(param_0)) func_800C4140(0x7FEBBC18, param_0->position, 0x04B000FA);
            if (_suegg_entrypoint_13(param_0)) ((GoldenEggPendingFlags1041 *)local_0)->local_0 = 1;
            else if (_suegg_entrypoint_12(param_0)) _sueggmisc_entrypoint_1(param_0);
            else {
                func_80800000_chegggolden(param_0);
                _suegg_entrypoint_16(param_0);
            }
        }
        break;
    }
    if (((GoldenEggPendingFlags1041 *)local_0)->local_0) _suegg_entrypoint_3(param_0);
}

int *chegggolden_entrypoint_0()
{
    return &D_808003F0_chegggolden;
}

u8 *chegggolden_entrypoint_1(Actor *param_0, s32 param_1, f32 param_2[3], s32 param_3) {
    Actor *local_0;

    _sueggmove_entrypoint_10(param_0);
    local_0 = _suegg_entrypoint_11(0x15f, param_1, param_3);
    *(f32 *)((char *)local_0 + 0x38) = 0.134f;
    _suegg_entrypoint_1(local_0, 3e+01f);
    _sueggmove_entrypoint_5(local_0, 1);
    _sueggmove_entrypoint_6(local_0, -2.2e+03f, -22000.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    *(u8 *)((char *)local_0 + 0x72) = (*(u8 *)((char *)local_0 + 0x72) & 0xFF03) | 8;
    return local_0;
}

Actor *chegggolden_entrypoint_2(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
    Actor *local_0;

    _sueggmove_entrypoint_10(param_0, param_1);
    local_0 = _suegg_entrypoint_11(0x15F, param_1, param_3);
    local_0->scale = 0.25f;
    _sueggmove_entrypoint_5(local_0, 0);
    _sueggmove_entrypoint_6(local_0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(local_0, 30.0f);
    _sueggmove_entrypoint_7(local_0, param_2);
    local_0->unk70_10 = 1;
    return local_0;
}
