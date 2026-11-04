// Shared helpers for all solo-Kazooie player states: common enter/exit with shoe hooks, a shoes
// callback, and two next-state selectors (jump type and air state).
#include "overlays/bs/kaz.h"

void bskaz_entrypoint_0(PlayerState *self, s32 arg1, s32 arg2)
{
    if (arg1 != arg2) {
        if (arg1 == 3) {
            func_800962B0(self, 0);
        }
    }
}

// Common enter for solo Kazooie states.
void bskaz_entrypoint_1(PlayerState *self)
{
    _bashoes_entrypoint_15();
    _bashoes_entrypoint_7(self, &_bskaz_entrypoint_0);
    _bashoes_entrypoint_8(self, &_bskazmove_entrypoint_11);
    bastick_func_8009F258(self);
    baflag_set(self, BA_FLAG_3);
    func_80092864(self, 0.8999939);
}

// Common exit for solo Kazooie states.
void bskaz_entrypoint_2(PlayerState *self)
{
    baflag_clear(self, 3);
    _bashoes_entrypoint_14(self);
    func_80092864(self, 1);
}

// Next state for a jump: 0x186, 0x161, 0xC6 (Z held) or 0xBD.
BanjoStateId bskaz_entrypoint_3(PlayerState *self)
{
    if (func_8008E430() != 0) {
        return BS_STATE_186;
    }

    if (func_8008D3B0(self) != 0) {
        return BS_STATE_161;
    }

    if ((bakey_held(self, BUTTON_Z) != 0) && (func_800C6E38(0x24) != 0)) {
        return BS_STATE_C6;
    }

    return BS_STATE_BD;
}

// Air state: 0x18B or 0xC2.
BanjoStateId bskaz_entrypoint_4(PlayerState *self)
{
    if (func_8009EA2C() != 0) {
        return BS_STATE_18B;
    }

    return BS_STATE_C2;
}
