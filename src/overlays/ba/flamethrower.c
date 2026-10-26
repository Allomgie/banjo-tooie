#include "common.h"

typedef struct { void (*local_0)(void *, f32 *, f32 *); f32 local_1; f32 local_2; } FlameThrowerData;
extern void _baflameline_entrypoint_6(void *, f32);
extern f32 func_800F15F8(f32, f32, f32);
typedef struct { s32 pad_0; f32 local_0; f32 local_1; u8 local_2; } FlamethrowerState;
typedef struct { u8 pad_0[0x88]; FlamethrowerState *local_0; } FlamethrowerPlayer;

s32 baflamethrower_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_baflamethrower(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    (*(FlameThrowerData **)(param_0 + 0x88))->local_0(param_0, local_0, local_1);
    _baflameline_entrypoint_4(param_0, local_0);
    _baflameline_entrypoint_5(param_0, local_1);
    _baflameline_entrypoint_6(param_0, (*(FlameThrowerData **)(param_0 + 0x88))->local_1);
    (*(FlameThrowerData **)(param_0 + 0x88))->local_1 =
        func_800F15F8((*(FlameThrowerData **)(param_0 + 0x88))->local_1,
            (*(FlameThrowerData **)(param_0 + 0x88))->local_2, 20.0f);
}

void func_80800088_baflamethrower(FlamethrowerPlayer *param_0, s32 param_1)
{
    s32 local_0;

    local_0 = param_0->local_0->local_2;
    if ((local_0 == 1 || local_0 == 3) && param_1 == 3) return;
    param_0->local_0->local_2 = param_1;
    switch (param_1) {
    case 0:
        break;
    case 1:
        param_0->local_0->local_1 = 0.0f;
        param_0->local_0->local_0 = param_0->local_0->local_1;
        func_80800008_baflamethrower(param_0);
        break;
    case 2:
        param_0->local_0->local_0 = 150.0f;
        param_0->local_0->local_1 = 300.0f;
        func_80800008_baflamethrower(param_0);
        break;
    case 3:
        param_0->local_0->local_1 = 150.0f;
        _baflameline_entrypoint_1(param_0);
        break;
    }
}

void baflamethrower_entrypoint_1(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0);
    _baflameline_entrypoint_2(arg0);
}

void baflamethrower_entrypoint_2(u8 *param_0, s32 param_1) {
    _baflameline_entrypoint_3();
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x88)))) + (0))) = param_1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x88)))) + (0xC))) = 0;
    func_80800088_baflamethrower(param_0, 1);
}

void baflamethrower_entrypoint_3(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0x2);
}

void baflamethrower_entrypoint_4(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0x3);
}

void baflamethrower_entrypoint_5(u8 *param_0) {
    u8 local_0;
    u8 *local_1;

    local_0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x88)))) + (0xC)));
    switch (local_0) {                              
    case 1:
        break;
    case 2:
        func_80800008_baflamethrower(param_0);
        break;
    case 3:
        func_80800008_baflamethrower(param_0);
        local_1 = (*(u8 **)((s8 *)(param_0) + (0x88)));
        if ((*(f32 *)((s8 *)(local_1) + (8))) == (*(f32 *)((s8 *)(local_1) + (4)))) {
            func_80800088_baflamethrower(param_0, 1);
        }
        break;
    }
    _baflameline_entrypoint_7(param_0);
}
