#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 _badata_entrypoint_18(PlayerState *);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);

void bsdronefired_entrypoint_0()
{
    _babounce_entrypoint_3();
}

void bsdronefired_entrypoint_1(PlayerState *param_0)
{
    f32 local_1;
    s32 local_0;
    s32 local_2;

    _badata_entrypoint_7(param_0, &local_0, &local_1);
    baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
    _babounce_entrypoint_4(param_0, 2);
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + 180.0f);
    yaw_applyIdeal(param_0);
    switch (func_800A3274(param_0)) {
        case 1:
        case 10:
            local_2 = 0x420;
            break;
        case 11:
            local_2 = 0x598;
            break;
        case 13:
            local_2 = 0x5A3;
            break;
        default:
            return;
    }
    func_8009DF18(param_0, local_2, _badata_entrypoint_18(param_0) + 1.0f, 0x6D60);
}

void bsdronefired_entrypoint_2()
{
    func_80099AA8();
}

s32 bsdronefired_entrypoint_3(Actor *this){
    if(_babounce_entrypoint_10(this) != 0){
        bs_setState(this, _badata_entrypoint_24(this));
    }
}
