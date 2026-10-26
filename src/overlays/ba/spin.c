#include "common.h"
#include "playerstate.h"

extern f32 func_80092BE8();
typedef struct { u8 local_0; u8 local_1; u8 local_2[2]; f32 local_3; } Broad42SpinState;
extern void baroll_setIdeal(PlayerState *, f32);
extern void func_8009BF5C(PlayerState *, f32);
extern f32 yaw_get(PlayerState *);
extern f32 _bareact_entrypoint_4(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void yaw_setIdeal(PlayerState *, f32);
extern void func_8009328C(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_80013970(f32);
extern s32 baanim_isAt(PlayerState *, f32);

s32 baspin_entrypoint_0() 
{
    return 0x8;
}

void baspin_entrypoint_1(u8 *param_0) {
    if (((*(u8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x118)))) + (1))) == 1) && (_bafpctrl_entrypoint_4() == 3)) {
        _ncba1p_entrypoint_4(func_800A4CA8(param_0), 1);
    }
    func_8009BD88(param_0);
    func_8008E95C(param_0);
    func_800951B4(param_0);
    yaw_setIdeal(param_0, func_80092BE8(param_0));
    yaw_applyIdeal(param_0);
    func_800931AC(param_0, 1);
}

void baspin_entrypoint_2(PlayerState *param_0, s32 param_1, f32 param_2, s32 param_3, s32 param_4)
{
    f32 local_0;
    f32 local_1[3];
    f32 local_2[3];

    ((Broad42SpinState *)*(void **)((u8 *)param_0 + 0x118))->local_1 = param_4;
    ((Broad42SpinState *)*(void **)((u8 *)param_0 + 0x118))->local_0 = param_3;
    _bareact_entrypoint_1(param_0, func_80099A58());
    baanim_playForDuration_once(param_0, param_1, param_2);
    if (func_800A32EC(param_0) != 3) {
        func_8009D9D4(param_0);
    }
    func_8009C128(param_0, local_1);
    func_800A32C4(param_0, local_2);
    func_800F1E6C(local_2, local_1, &local_0);
    yaw_setIdeal(param_0, local_0);
    yaw_applyIdeal(param_0);
    baroll_setIdeal(param_0, 0.0f);
    func_8009BF5C(param_0, 0.0f);
    ((Broad42SpinState *)*(void **)((u8 *)param_0 + 0x118))->local_3 = yaw_get(param_0);
    func_800931AC(param_0, 3);
    func_8009328C(param_0, ((Broad42SpinState *)*(void **)((u8 *)param_0 + 0x118))->local_3);
    baphysics_set_target_horizontal_velocity(param_0, _bareact_entrypoint_4(param_0));
    baphysics_set_target_yaw(param_0, local_0);
    baphysics_set_horizontal_velocity(param_0, local_0, baphysics_get_target_horizontal_velocity(param_0));
    func_8009FFD8(param_0, 1, 1, 2, 3);
    func_8008E944(param_0);
    func_8009514C(param_0);
    _batimer_set(param_0, 0xB, 1.5f);
    if (((Broad42SpinState *)*(void **)((u8 *)param_0 + 0x118))->local_1 == 1
        && _bafpctrl_entrypoint_4(param_0) == 3) {
        _ncba1p_entrypoint_4(func_800A4CA8(param_0), 0);
    }
}

s32 baspin_entrypoint_3(PlayerState *param_0)
{
    u8 *local_0 = *(u8 **)((u8 *)param_0 + 0x118);
    f32 local_1 = 360.0f * (f32)(u32)local_0[0] + *(f32 *)(local_0 + 4) + 180.0f;
    f32 local_2;
    f32 local_3;

    local_3 = func_800F10B4(_batimer_get(param_0, 11), 0.0f, 1.5f, 1.0f, 0) * 90.0f;
    local_2 = func_80013970(local_3) * local_1;
    func_8009328C(param_0, local_2);
    if ((*(u8 **)((u8 *)param_0 + 0x118))[1] == 1 && _bafpctrl_entrypoint_4(param_0) == 3) {
        yaw_setIdeal(param_0, local_2);
        yaw_applyIdeal(param_0);
    }
    _batimer_decrement(param_0, 11);
    if (baanim_isAt(param_0, 0.5f)) func_800951B4(param_0);
    if (_batimer_get(param_0, 11) == 0.0f && baanim_isStopped(param_0)) return 2;
    return 1;
}
