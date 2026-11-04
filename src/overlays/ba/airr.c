// Player air-meter trigger: shows or starts draining the air meter when a swimming state begins
// or ends, unless the water is oxygenated, the player cannot drown, or party mode is 3.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "gameflags.h"

// Air meter trigger: mode 1 shows the meter, mode 2 starts draining it.
void baairbar_entrypoint_0(PlayerState *self, s32 mode)
{
    // Oxygenated water: no air meter needed.
    if (func_800DA298(FLAG_0E9_MAGIC_SUNLIGHT_OXYGENATED_WATER) && _gclevel_entrypoint_4(0x10)) {
        return;
    }

    if (!func_8008DAA8(self)) {
        return;
    }

    if (func_800F8B88() == 3) {
        return;
    }

    switch (mode) {
        case 1:
            func_800CF494();
            break;

        case 2:
            func_800CF2D4(1);
    }
}
