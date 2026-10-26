#include "common.h"

#include "overlays/bs/kaz/flamethrower.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void baanim_playForDuration_onceSmooth(PlayerState *, AssetId, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void _batimer_set(PlayerState *, s32, f32);

extern s32 D_808003B0_bskazflamethrower[];

void bskazflamethrower_entrypoint_0(PlayerState *self, f32 arg1[3], f32 arg2[3]) {
    f32 unk0[3];
    s32 pad2;
    f32 unk1;

    unk1 = func_8009BFCC(self);
    func_800EEC30(arg2, -unk1, yaw_get(self), 1);
    func_8009C128(self, arg1);
    func_800EFA98(unk0, arg2, 17);
    func_800EF04C(arg1, unk0);
    arg1[1] += 57.0f;
}

void func_80800094_bskazflamethrower(PlayerState *param_0, s32 param_1)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    param_0->unk15C.word = param_1;
    switch (param_1) {
        case 1:
            baanim_playForDuration_onceSmooth(param_0, 0xE1, 1.0f);
            func_8009FFD8(param_0, 1, 3, 8, 2);
            yaw_setVelocityBounded(param_0, 300.0f, 1.6f);
            baphysics_set_target_horizontal_velocity(param_0, 0);
            _baflamethrower_entrypoint_2(param_0, &_bskazflamethrower_entrypoint_0);
            break;
        case 2:
            anctrl_setSubrange(local_0, 0.375f, 0.5625f);
            anctrl_setPlaybackType(local_0, 4);
            _batimer_set(param_0, 2, 0.14f);
            _baflamethrower_entrypoint_3(param_0);
            break;
        case 3:
            _baflamethrower_entrypoint_4(param_0);
            _batimer_set(param_0, 1, 0.05f);
            break;
        case 4:
            anctrl_setPlaybackType(local_0, 1);
            baanim_setEnd(param_0, 1.0f);
            break;
        case 0:
            _baflamethrower_entrypoint_1(param_0);
            break;
    }
}

void bskazflamethrower_entrypoint_1(PlayerState *self) {
    func_80800094_bskazflamethrower(self, 0);
}

void bskazflamethrower_entrypoint_2(PlayerState *self) {
    self->unk15C.word = 0;
    func_80800094_bskazflamethrower(self, 1);
}

void bskazflamethrower_entrypoint_3(PlayerState *self) {
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    switch (self->unk15C.word) {
        case 1:
            if (baanim_isAt(self, 0.2) != 0) {
                func_8009DF18(self, 0x459F, 1, 0x6590);
            }
            if (baanim_isAt(self, 0.375) != 0) {
                func_80800094_bskazflamethrower(self, 2);
            }
            break;
        case 2:
            _batimer_decrement(self, 2);
            if ((_batimer_isZero(self, 2) != 0) && (bakey_released(self, 9) != 0)) {
                func_80800094_bskazflamethrower(self, 3);
            }
            break;
        case 3:
            if (_batimer_decrement(self, 1) != 0) {
                func_80800094_bskazflamethrower(self, 4);
            }
            break;
        case 4:
            if (baanim_isStopped(self) != 0) {
                next_state = BS_STATE_BB;
            }
            if (baanim_getTimer(self) > 0.7f) {
                next_state = _bskazstill_entrypoint_4(self, next_state);
            }
            break;
    }
    _baflamethrower_entrypoint_5(self);
    bs_setState(self, next_state);
}

s32 bskazflamethrower_entrypoint_4(s32 idx) {
    return D_808003B0_bskazflamethrower[idx];
}