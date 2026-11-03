#include "common.h"

extern void func_80112E50(void *param_0, int param_1, int param_2);

s32 func_80114D90()
{
    return 0x8;
}

// Counts a frame of held C-button rotate input (0 = left, 1 = right).
void func_80114D98(u8 *camera, s32 dir)
{
    s16 *counter;
    s32 offset;

    if ((dir == 0) || (dir == 1)) {
        offset = dir * 2;
        *(s16 *) ((s8 *) (*(s32 *) ((s8 *) camera + 8) + offset) + 4) = 1;
        counter = *(s32 *) ((s8 *) camera + 8) + offset;
        *counter += 1;
    }
}

// On release after at least 5 frames, nudges the yaw rotation by -/+5 degrees.
void func_80114DD8(void *camera)
{
    s16 *slot_final;
    s16 *slot;
    slot = *(s16 **) ((s8 *) camera + 8);
    if (*(s16 *) ((s8 *) slot + 4) == 0) {
        if (*(s16 *) ((s8 *) slot + 0) >= 5) {
            func_80112E50(camera, 0xC0A00000, 2);
            slot = *(s16 **) ((s8 *) camera + 8);
        }
        *slot = 0;
        slot = *(s16 **) ((s8 *) camera + 8);
    }
    if (*(s16 *) ((s8 *) slot + 6) == 0) {
        if (*(s16 *) ((s8 *) slot + 2) >= 5) {
            func_80112E50(camera, 0x40A00000, 2);
            slot = *(s16 **) ((s8 *) camera + 8);
        }
        *(s16 *) ((s8 *) slot + 2) = 0;
        slot = *(s16 **) ((s8 *) camera + 8);
    }
    *(s16 *) ((s8 *) slot + 6) = 0;
    // Matching: empty block needed for the match.
    if (slot) {
    }
    slot_final = *(s16 **) ((s8 *) camera + 8);
    *(s16 *) ((s8 *) slot_final + 4) = (s16) *(s16 *) ((s8 *) slot_final + 6);
}
