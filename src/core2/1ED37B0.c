// Most likely the per-player-slot health table used in the alternative health mode: current/max
// pairs with clamped add, get and set. Damage triggers the hurt jingle.
#include "common.h"

extern s16 D_80135530[];
extern s16 D_80135532[];
s16 func_800F9F04();
void func_800F9F2C();

// Adds delta to current health with clamping; damage plays jingle 0x74.
int func_800F9EC0(s32 slot, s32 delta)
{
    if (delta < 0) {
        func_800FC660(0x74);
    }
    func_800F9F2C(slot, func_800F9F04(slot) + delta);
}

// Current health.
s16 func_800F9F04(slot)
s32 slot;
{
    unsigned int *offset_ptr;
    int offset;
    unsigned int raw_offset;
    // Matching: the round trip through a pointer to the local is needed for the match.
    raw_offset = (slot ^ 0) * 2;
    offset_ptr = &raw_offset;
    offset = *offset_ptr;
    return D_80135530[offset];
}

// Max health.
s16 func_800F9F18(s32 slot)
{
    int offset;
    offset = slot * 2;
    // Matching: empty test steers IDO's register allocation.
    if (offset) {
    }
    return D_80135532[offset];
}

// Sets current health, clamped to 0..max.
void func_800F9F2C(slot, value) s32 slot;
s32 value;
{
    s32 *entry;
    entry = &((s32 *) D_80135530)[slot];
    if (value < 0) {
        value = 0;
    } else if (*(s16 *) ((u8 *) entry + 2) < value) {
        value = *(s16 *) ((u8 *) entry + 2);
    }
    *(s16 *) entry = value;
}

// Sets max health.
int func_800F9F74(s32 slot, int max_value)
{
    *(short *) &((int *) D_80135532)[slot] = max_value;
}
