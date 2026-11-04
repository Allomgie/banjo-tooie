// Probably Kazooie's fire-breath (flamethrower) state: a wind-up, then a hold phase that keeps
// emitting flames from a mouth position until the button is released, then a wind-down.
#include "common.h"
#include "overlays/bs/kaz/flamethrower.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern s32 D_808003B0_bskazflamethrower[];

// Emitter callback: mouth position is the player position 17 units forward along pitch/yaw, 57 up.
void bskazflamethrower_entrypoint_0(PlayerState *self, f32 pos[3], f32 dir[3])
{
    f32 offset[3];
    s32 unk_0;
    f32 pitch;

    pitch = func_8009BFCC(self);
    func_800EEC30(dir, -pitch, yaw_get(self), 1);
    func_8009C128(self, pos);
    func_800EFA98(offset, dir, 17);
    func_800EF04C(pos, offset);
    pos[1] += 57.0f;
}

// Enters a phase: 1 wind-up, 2 hold, 3 release, 4 wind-down, 0 stops the emitter.
void func_80800094_bskazflamethrower(PlayerState *self, s32 phase)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    self->unk15C.word = phase;
    switch (phase) {
        case 1:
            baanim_playForDuration_onceSmooth(self, 0xE1, 1.0f);
            func_8009FFD8(self, 1, 3, 8, 2);
            yaw_setVelocityBounded(self, 300.0f, 1.6f);
            baphysics_set_target_horizontal_velocity(self, 0);
            _baflamethrower_entrypoint_2(self, &_bskazflamethrower_entrypoint_0);
            break;
        case 2:
            anctrl_setSubrange(anim_ctrl, 0.375f, 0.5625f);
            anctrl_setPlaybackType(anim_ctrl, 4);
            _batimer_set(self, 2, 0.14f);
            _baflamethrower_entrypoint_3(self);
            break;
        case 3:
            _baflamethrower_entrypoint_4(self);
            _batimer_set(self, 1, 0.05f);
            break;
        case 4:
            anctrl_setPlaybackType(anim_ctrl, 1);
            baanim_setEnd(self, 1.0f);
            break;
        case 0:
            _baflamethrower_entrypoint_1(self);
    }
}

void bskazflamethrower_entrypoint_1(PlayerState *self)
{
    func_80800094_bskazflamethrower(self, 0);
}

void bskazflamethrower_entrypoint_2(PlayerState *self)
{
    self->unk15C.word = 0;
    func_80800094_bskazflamethrower(self, 1);
}

void bskazflamethrower_entrypoint_3(PlayerState *self)
{
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
            // Stops on button release, but only after a 0.14 s minimum.
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
    }
    _baflamethrower_entrypoint_5(self);
    bs_setState(self, next_state);
}

s32 bskazflamethrower_entrypoint_4(s32 idx)
{
    return D_808003B0_bskazflamethrower[idx];
}

// TU-NOTE: the overlay .data (formerly flamethrower.data.s) is defined here in C. The table holds
// function pointers from this file; IDO's assembler schedules these functions differently
// unless the table is in the same unit. Values are taken from the ROM.
extern void func_80099B94();
s32 D_808003B0_bskazflamethrower[4] = {(u32) _bskazflamethrower_entrypoint_1,
                                       (u32) _bskazflamethrower_entrypoint_2,
                                       (u32) _bskazflamethrower_entrypoint_3, (u32) func_80099B94};
