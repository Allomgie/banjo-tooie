#include "overlays/bs/rebound.h"

void func_80800000_bsrebound(PlayerState *self) {
    _babounce_entrypoint_4(self, 2);
    _babounce_entrypoint_5(self, 0xF, 0.5823f);
}

void func_80800038_bsrebound(PlayerState *self) {
    enum bs_state_e next_state;
    AnimCtrl *animCtrl;

    next_state = BS_STATE_0_INVALID;
    animCtrl = baanim_getAnimCtrlPtr(self);
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
        if ((anctrl_isStopped(animCtrl) != 0) && (func_8008DD04(self) != 0)) {
            next_state = BS_STATE_2F_FALL;
        }
    }

    bs_setState(self, next_state);
}

void func_808000EC_bsrebound(PlayerState *self) {
    _babounce_entrypoint_3(self);
}

s32 bsrebound_entrypoint_0(s32 idx) {
    return D_80800120_bsrebound[idx];
}
/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/bs/rebound.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM. */
extern void func_80099AA8();
s32 D_80800120_bsrebound[4] = { (u32)func_808000EC_bsrebound, (u32)func_80800000_bsrebound, (u32)func_80800038_bsrebound, (u32)func_80099AA8 };
