#include "common.h"
// TU-NOTE: the .data of this overlay is defined here in C; values come from the ROM.

extern void _subaddielink_entrypoint_0();
extern void func_80090658();
extern f32 func_800D8FF8(void);
extern s32 func_800902E4(f32 *, f32, s32, Actor **);
typedef struct {
    u8 pad0[0x64];
    u32 padH : 9;
    u32 f : 1;
    u32 padL : 22;
} ShiftBf64_22_0;
typedef struct {
    u8 pad0[0x65];
    u8 f : 1;
    u8 pad : 7;
} SignBf65_0;
void func_80800224_subaddieitem();

// Initializes the exchange state: item id, radius and flags (2 = play jingle, 1 = delete the item).
void subaddieitem_entrypoint_0(void *state, long item_id, int radius, unsigned int flags)
{
    *(u8 *) ((char *) state + 0x0) = 0;
    *(s16 *) ((char *) state + 0x4) = item_id;
    *(s16 *) ((char *) state + 0x6) = radius;
    *(u8 *) ((char *) state + 0x1) = flags;
    *(u8 *) ((char *) state + 0x2) = 0;
    *(u8 *) ((char *) state + 0x3) = 0;
    *(f32 *) ((char *) state + 0x10) = 0.0f;
    _subaddielink_entrypoint_0((char *) state + 0x8);
}

// Sets how many items are removed from the inventory.
s32 subaddieitem_entrypoint_1(u8 *state, s32 count)
{
    state[2] = count;
}

// Starts waiting for the player to hold out the item.
void subaddieitem_entrypoint_2(u8 *state)
{
    func_80090658(1, state);
    *(s8 *) ((s8 *) state + 3) = 1;
    *(s8 *) ((s8 *) state + 0) = 1;
    *(f32 *) ((s8 *) state + 0x10) = 0.0f;
    _subaddielink_entrypoint_0(state + 8, state);
}

// Per-frame update. State 1 waits for the item, 2 waits for the handover, 3 finishes.
// Returns 1 when finished.
int subaddieitem_entrypoint_3(Actor *npc, f32 *pos, u8 *state)
{
    s32 done;
    s32 pad0;
    Actor *item;
    f32 pos_buf[1];

    done = 0;
    *(f32 *) (state + 0x10) += func_800D8FF8();
    switch (state[0]) {
        case 1:
            if (func_800902E4(npc->position, (f32) *(s16 *) (state + 6),
                              *(s16 *) (state + 4), &npc) &&
                func_8008FE14() == *(s16 *) (state + 4) && func_80090818()) {
                if (!pos) {
                    pos = pos_buf;
                    func_80103DFC(npc, pos);
                }
                _subaddielink_entrypoint_1(state + 8, func_8008FDEC());
                func_80090768(pos);
                state[0] = 2;
            }
            break;
        case 2:
            if (!_subaddielink_entrypoint_2(state + 8)) {
                func_80800224_subaddieitem(npc, state, 0);
            } else {
                item = (Actor *) _subaddielink_entrypoint_4(state + 8);
                if (!((ShiftBf64_22_0 *) item)->f && !((SignBf65_0 *) item)->f) {
                    func_80800224_subaddieitem(npc, state, item);
                }
            }
            break;
        case 3:
            if (state[3]) {
                func_80090658(0);
                state[3] = 0;
            }
            _subaddielink_entrypoint_0(state + 8);
            state[0] = 0;
            done = 1;
    }
    return done;
}

// Completes the handover: jingle, delete item, remove from inventory, notify the NPC.
void func_80800224_subaddieitem(npc, state, item) s32 npc;
u8 *state;
s32 item;
{
    unsigned long flags;
    flags = *(u8 *) ((s8 *) state + 1);
    if (flags & 2) {
        func_800FC660(0xE);
        // Matching: the always-true if is needed for the match.
        if (1) {
            flags = *(u8 *) ((s8 *) state + 1);
        }
    }
    if ((flags & 1) && (item != 0)) {
        func_800FFAB0(item);
    }
    _subaddielink_entrypoint_0(state + 8);
    // Matching: the * 0 is needed for the match.
    if (*(u8 *) ((s8 *) state + 2) != (1 * 0)) {
        func_800D175C(func_800D1B34(*(s16 *) ((s8 *) state + 4)),
                      -(s32) *(u8 *) ((s8 *) state + 2));
    }
    func_8010108C(npc, 0x2D, *(s16 *) ((s8 *) state + 4));
    *(s8 *) ((s8 *) state + 0) = 3;
}
