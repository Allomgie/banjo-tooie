#include "common.h"
#include "overlays/ba/playerstate.h"

void bsdronewaitbabykaz_entrypoint_0(s32 player)
{
}

// Init: idle animation while Clockwork Kazooie is controlled.
int bsdronewaitbabykaz_entrypoint_1(Actor *player)
{
    s32 duration;
    s32 anim_id;
    _badata_entrypoint_3(player, &anim_id, &duration);
    baanim_playForDuration_loopSmooth(player, anim_id, duration);
    func_8009FFD8(player, 1, 1, 3, 2);
}

// Interrupt handler: damage hits are forwarded to the clockwork slot as message 0x87.
void bsdronewaitbabykaz_entrypoint_2(PlayerState *player)
{
    s32 clockwork_slot;

    switch (func_8009E6EC(player)) {
        case 0x20:
        case 0x21:
        case 0x24:
        case 0x2D:
        case 0x2E:
        case 0x2F:
        case 0x4E:
        case 0x51:
        case 0x52:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
            func_80099B94(player);
            clockwork_slot = _plsu_entrypoint_1(0x11);
            if (clockwork_slot != -1)
                func_800F7B9C(clockwork_slot, 0x87);
            func_8009E830(player, 2);
            return;
        case 0x6B:
            func_80099B94(player);
        case 0x15:
        case 0x1C:
        case 0x1D:
        case 0x1E:
            break;
        default:
            func_80099B94(player);
    }
}

// Update: leaves the state once no clockwork slot (transformation 0x11) exists.
s32 bsdronewaitbabykaz_entrypoint_3(void *player)
{
    s32 next_state = 0;
    if (_plsu_entrypoint_1(0x11) == -1) {
        next_state = _badata_entrypoint_34(player);
    }
    bs_setState(player, next_state);
}
