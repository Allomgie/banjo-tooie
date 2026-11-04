// Banjo-Kazooie rebound: the stronger knock-back from bouncing off something.
#include "overlays/bs/rebound.h"

// Rebound: stronger knock-back from bouncing off something (anim 0xF).
void func_80800000_bsrebound(PlayerState *self)
{
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0xF, 0.5823f);
}

void func_80800038_bsrebound(PlayerState *self)
{
    enum bs_state_e next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (_babounce_entrypoint_2(self) != 0) {
        _bswalk_entrypoint_1(self);
    }

    if (_babounce_entrypoint_9(self) != 0) {
        next_state = BS_STATE_1_IDLE;
    }

    if (_babounce_entrypoint_1(self) == 2) {
        if (func_8008E260(self) != 0) {
            next_state = BS_STATE_3D_FALL_TUMBLING;
        }
        if ((anctrl_isStopped(anim_ctrl) != 0) && (func_8008DD04(self) != 0)) {
            next_state = BS_STATE_2F_FALL;
        }
    }

    bs_setState(self, next_state);
}

void func_808000EC_bsrebound(PlayerState *self)
{
    _babounce_entrypoint_3(self);
}

s32 bsrebound_entrypoint_0(s32 idx)
{
    return D_80800120_bsrebound[idx];
}

// TU-NOTE: the overlay's .data is defined here in C. The table holds pointers to functions of
// this file, and IDO's assembler schedules some of them differently unless it is in the same
// unit. Values are taken from the ROM.
extern void func_80099AA8();
s32 D_80800120_bsrebound[4] = {(u32) func_808000EC_bsrebound, (u32) func_80800000_bsrebound,
                               (u32) func_80800038_bsrebound, (u32) func_80099AA8};
