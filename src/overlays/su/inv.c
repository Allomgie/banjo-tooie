#include "su/inv.h"

// Spends amount_to_remove of item_type and sets the success state; otherwise plays the
// "not enough" jingle, flashes the counter and sets the failure state (-1 = leave unchanged).
void suinv_entrypoint_0(s32 *state, s32 failure, s32 success, s32 item_type, s32 amount_to_remove)
{
    // Not enough of the item (negative count or amount too large)
    if ((func_800D1C38(item_type) != 0) || ((func_800D1A04(item_type) - amount_to_remove) < 0)) {
        func_800D1824(item_type);
        func_800FC63C(0xF, 0x55F0);
        if (failure != -1) {
            *state = failure;
        }
    } else {
        if (amount_to_remove != 0) {
            func_800D175C(item_type, -amount_to_remove);
        }
        if (success != -1) {
            *state = success;
        }
    }
}
