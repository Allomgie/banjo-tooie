#include "common.h"

// TU-NOTE: D_80079FA0 holds 6 slots of 0x274 bytes; D_8007AE58 follows it (also used as the loop end and as the
// player config). D_80079FA2, D_8007A198, D_8007A1AC, D_8007A1B0 and D_8007A20C are addresses inside the slots
// (+2, +0x1F8, +0x20C, +0x210, +0x26C).
// TU-NOTE: func_80016ED0_unproto is a weak alias of func_80016ED0, used for a call without a prototype.

typedef struct {
    u8 pad_0[2];
    u8 pending;
    u8 unk_3;
    u8 timer;
    u8 unk_5;
    u8 pad_6[0x1DA];
    u8 player[0x8E];
    s16 pending_track;
    u8 pad_270[4];
} Struct_9FA0;
typedef struct {
    s32 max_voices;
    s32 max_events;
    u8 max_channels;
    u8 pad_9[3];
    s32 heap;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
} Struct_AE58;
typedef struct {
    u8 pad_0[0x26C];
    s16 track;
    u8 pad_26E[6];
} Struct80016DF8;
typedef struct {
    s16 volume;
    u8 pending;
    u8 unk_3;
    u8 timer;
    u8 unk_5;
    u8 pad_6[0x206];
    s32 player_state;
    u8 pad_210[0x5C];
    s16 track;
    u8 pad_26E[6];
} Struct80016ED0;
extern s32 func_80017D74(s32, s32, f32);
extern s32 func_800178C4(s32, u32, f32);
extern u8 D_8007A198[];
extern u32 D_8007A1B0[];
extern short D_8007A20C[];
typedef struct {
    u8 pad_0[0x1F8];
    s32 unk_1F8;
    u8 pad_1FC[0x10];
    s32 player_state;
    u8 pad_210[0x5C];
    s16 track;
    u8 pad_26E[6];
} Struct1713C;
extern s32 D_8007A1AC[];
typedef struct {
    s16 volume;
    u8 pending;
    u8 unk_3;
    u8 timer;
    u8 unk_5;
    u8 pad_6[0x266];
    s16 track;
    s16 pending_track;
    u8 pad_270[4];
} Struct17330;
typedef union {
    Struct_9FA0 base;
    Struct80016ED0 start_view;
    Struct1713C switch_view;
    u8 raw[0x274];
} Union80079FA0;
Union80079FA0 D_80079FA0[6];
u8 D_8007AE58[0x20];
u16 D_8007AE78[4];
extern void func_80025ED0(void *, s16);
extern u8 D_80079FA2[];
typedef struct {
    u8 pad_0[8];
    u8 unk_8[0x26C];
} Struct800175A0;
extern u16 D_8003F600[];

void func_80017244();
volatile unsigned int func_80017778();
#pragma weak func_80016ED0_unproto = func_80016ED0
extern void func_80016ED0_unproto();

// Counts the music assets, sets up the six sequence players and stops them.
void func_80016C00(void)
{
    s32 i;

    func_800E9574();
    i = 0x1ED7;
    if (func_800D738C(0x1ED7) == 4) {
        do {
            i--;
            if (i < 0x1DDE) {
                break;
            }
        } while (func_800D738C(i) == 4);
    }
    *(s16 *) D_8007AE78 = i - 0x1DDC;
    (*(Struct_AE58 *) D_8007AE58).max_voices = 0x18;
    (*(Struct_AE58 *) D_8007AE58).max_events = 0x78;
    (*(Struct_AE58 *) D_8007AE58).max_channels = 0x20;
    (*(Struct_AE58 *) D_8007AE58).heap = func_80012EDC();
    (*(Struct_AE58 *) D_8007AE58).unk_10 = 0;
    (*(Struct_AE58 *) D_8007AE58).unk_14 = 0;
    (*(Struct_AE58 *) D_8007AE58).unk_18 = 0;
    func_80022084((Struct_AE58 *) D_8007AE58, 0x30);
    for (i = 0; i < 6; i++) {
        func_800221B0(D_80079FA0[i].base.player, (Struct_AE58 *) D_8007AE58);
    }
    for (i = 0; i < 6; i++) {
        D_80079FA0[i].base.pending = 0;
        D_80079FA0[i].base.unk_3 = 0;
        D_80079FA0[i].base.pending_track = 0;
        D_80079FA0[i].base.timer = 0;
        D_80079FA0[i].base.unk_5 = 0;
    }
    func_80017244();
}

// Music asset id of a track is 0x1DDD + track.
void func_80016DA0(s32 track, s32 unk_1)
{
    s32 asset_id;
    asset_id = track + 0x1DDD;
    if (func_800D73CC(asset_id) == 0) {
        if (unk_1 != 0) {
            func_800D5B24();
        }
        func_800D674C(asset_id);
        func_800D70D0(1);
        func_800D71F4(1);
    }
}

// Unloads the music asset of track unless a slot is using it.
void func_80016DF8(s32 track)
{
    if (func_800D73CC(track + 0x1DDD, track)) {
        Struct80016DF8 *slot;
        Struct80016DF8 *slots_end;

        slot = (Struct80016DF8 *) D_80079FA0, slots_end = (Struct80016DF8 *) D_8007AE58;
        do {
            if (track == slot->track) {
                return;
            }
            slot++;
        } while (slot != slots_end);
        func_800D721C(track + 0x1DDD, 0);
        func_800D70F8(track + 0x1DDD, 0);
        func_800D6CEC(track + 0x1DDD);
    }
}

// Unloads all music assets that are not in use.
void func_80016E7C()
{
    s32 track;
    for (track = 0; track < D_8007AE78[0]; track++) {
        func_80016DF8(track);
    }
}

// Starts track on slot; track -1 stops the slot.
void func_80016ED0(u8 slot, s32 track)
{
    // Matching: write-only volatile local, needed for the match.
    volatile u64 time;

    if ((track == -1)) {
        if (D_80079FA0[slot].start_view.track != track) {
            func_80024E90(&D_80079FA0[slot].start_view.pad_6[0x1DA]);
        }
        D_80079FA0[slot].start_view.track = track;
        return;
    }

    if (D_80079FA0[slot].start_view.track != -1) {
        func_80016ED0(slot, -1);
    }
    time = osGetTime();
    while (D_80079FA0[slot].start_view.player_state != 0) {
        osGetTime();
    }

    D_80079FA0[slot].start_view.pending = 0;
    D_80079FA0[slot].start_view.unk_3 = 0;
    D_80079FA0[slot].start_view.track = track;
    D_80079FA0[slot].start_view.unk_5 = 0;
    func_80016DA0(D_80079FA0[slot].start_view.track, 1);
    func_80024EE0(&D_80079FA0[slot].start_view.pad_6[2],
                  func_800D674C(D_80079FA0[slot].start_view.track + 0x1DDD));
    func_80025E80(&D_80079FA0[slot].start_view.pad_6[0x1DA],
                  &D_80079FA0[slot].start_view.pad_6[2]);
    func_80017850(slot);
    if (D_80079FA0[slot].start_view.track != -1) {
        func_800178C4(slot, func_800FCDB4(D_80079FA0[slot].start_view.track), 0.0f);
    }
    func_80017D74(slot, -1, 0.0f);
    func_80025ED0(&D_80079FA0[slot].start_view.pad_6[0x1DA],
                  D_80079FA0[slot].start_view.volume);
    func_80025F20(&D_80079FA0[slot].start_view.pad_6[0x1DA]);
    D_80079FA0[slot].start_view.timer = 2;
}

u32 func_80017070(slot)
u8 slot;
{
    u8 **ptr;
    u32 bits_dup;
    u32 bits;
    s32 shift;
    u32 shifted;
    u32 mask;
    ptr = *(u8 ***) &D_8007A198[slot * 0x274];
    if (ptr == 0) {
        return 0xFFFFFFFFU;
    }
    bits = ((u32 *) *ptr)[1];
    // Matching: duplicate load, needed for the match.
    bits_dup = ((u32 *) *ptr)[1];
    shift = 0x20 - bits;
    shifted = 0xFFFFFFFF;
    shifted = shifted << shift;
    mask = shifted >> shift;
    return mask;
}

int func_800170D4(slot)
u8 slot;
{
    return *(s32 *) ((char *) D_8007A1B0 + slot * 628);
}

// Returns the current track of slot.
short func_80017108(slot)
u8 slot;
{
    return *(s16 *) ((char *) D_8007A20C + slot * 628);
}

// Switches slot to track: stops the current one, waits for the player to idle, then starts the new one.
void func_8001713C(u8 slot, s32 track)
{
    s32 old_track;
    // Matching: write-only volatile local, needed for the match.
    volatile long long time;
    Struct1713C *entry;
    u8 slot_copy;
    s32 track_copy;
    entry = &D_80079FA0[slot].switch_view;
    old_track = entry->track;
    if ((track == old_track) || (old_track == -1)) {
        func_80016ED0(slot, track);
        return;
    }
    // Matching: copies of the arguments are needed for the match.
    slot_copy = slot;
    track_copy = track;
    func_80016ED0(slot, -1);
    time = osGetTime();
    while (D_80079FA0[slot].switch_view.player_state != 0) {
        osGetTime();
    }

    entry->unk_1F8 = 0;
    func_80016DF8(old_track);
    func_80016ED0(slot_copy, track_copy);
}

// Returns the player state of slot.
s32 func_80017210(slot)
u8 slot;
{
    return *(s32 *) ((char *) D_8007A1AC + slot * 628);
}

// Stops all slots and waits until every player is idle.
void func_80017244(void)
{
    s32 i;
    s32 busy_count;
    // Matching: write-only volatile local, needed for the match.
    volatile u64 time;

    for (i = 0; i < 6; i++) {
        func_80016ED0_unproto(i & 0xFF, -1);
    }
    time = osGetTime();
    do {
        busy_count = 0;
        for (i = 0; i < 6; i++) {
            if (func_80017210(i & 0xFF) != 0) {
                busy_count++;
            }
        }
        osGetTime();
    } while (busy_count != 0);
}

// Queues track on slot with its default volume from D_8003F600.
void func_800172D4(slot, track) u8 slot;
u32 track;
{
    s32 table_offset;
    u8 *base;

    base = (u8 *) D_80079FA0 + (slot * 0x274);
    *(s16 *) (base + 0x26E) = track;
    base[2] = 1;
    base[5] = 1;
    table_offset = track * 2;
    base[3] = 0;
    *(u16 *) base = *(u16 *) ((u8 *) D_8003F600 + table_offset);
}

void func_80017330(u8 slot)
{
    unsigned long cur_track = (&((Struct17330 *) D_80079FA0)[(u8) slot])->track;
    if (((&((Struct17330 *) D_80079FA0)[(u8) slot])->track == 0x10) || (cur_track == 0x18)) {
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->pending = 1;
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->unk_3 = 0;
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->pending_track =
            (&((Struct17330 *) D_80079FA0)[(u8) slot])->track;
    } else {
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->pending_track = -1;
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->unk_3 = 1;
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->pending = 1;
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->unk_5 = 1;
        (&((Struct17330 *) D_80079FA0)[(u8) slot])->volume = 0;
    }
}

void func_800173B0(u8 slot, s16 volume)
{
    s32 offset = slot * 0x274;
    u8 *base = &((u8 *) D_80079FA0)[offset];
    s16 *cur_track = (s16 *) (base + 0x26C);
    *(u8 *) (base + 3) = 1;
    *(u8 *) (base + 2) = 1;
    *(u8 *) (base + 5) = 1;
    *(s16 *) base = volume;
    *(s16 *) (base + 0x26E) = *cur_track;
}

// Sets the volume of slot.
void func_80017404(u8 slot, s16 volume)
{
    *(s16 *) D_80079FA0[slot].raw = volume;
    func_80025ED0(D_80079FA0[slot].raw + 0x1E0, volume);
    if (D_80079FA0[slot].raw[3] != 0 && volume != 0) {
        func_800173B0(slot, volume);
        return;
    }
    if (D_80079FA0[slot].raw[3] == 0 && volume == 0 && func_80017778(slot) == 0) {
        func_80017330(slot);
    }
}

void func_800174C0(volatile u8 slot, s32 unk_1)
{
    u32 slot_copy;

    slot_copy = slot;
    if (func_80017778(slot_copy) == 0) {
        if (D_80079FA2[slot * 0x274] == 0) {
            func_80017D74(slot_copy, unk_1, 0.0f);
        }
    }
}

void func_80017534(char slot, s32 unk_1, s32 unk_2)
{
    u8 *player;
    u32 slot_copy;

    if (func_80017778(slot) == 0) {
        slot_copy = slot;
        player = (u8 *) (u8 *) D_80079FA0 + (slot_copy * 0x274) + 0x1E0;
        func_80025FE0(player, unk_1, unk_2);
    }
}

void func_800175A0(slot) u8 slot;
{
    func_80025668(&((Struct800175A0 *) D_80079FA0)[slot].unk_8, slot);
}

// Per-frame update of all slots: handles queued starts, stops and timers.
void func_800175F0(void)
{
    s8 *slot;
    s32 state;
    s32 i;
    u8 timer;
    u8 timer2;

    func_800E96B0(0);
    slot = (s8 *) D_80079FA0;
    i = 0;
    do {
        state = *(s32 *) (slot + 0x20C);
        switch (state) {
            case 2:
                break;
            case 1:
                if (*(u8 *) (slot + 2) != 0 && *(u8 *) (slot + 5) == 0 &&
                    *(u8 *) (slot + 4) == 0) {
                    func_80024E90(slot + 0x1E0);
                    if (*(u8 *) (slot + 3) != 0) {
                        *(u8 *) (slot + 2) = 0U;
                    }
                } else {
                    *(u8 *) (slot + 5) = 0U;
                }
                timer = *(u8 *) (slot + 4);
                if ((s32) timer > 0) {
                    *(u8 *) (slot + 4) = (u8) (timer - 1);
                }
                break;
            case 0:
                if (*(u8 *) (slot + 2) != 0 && *(u8 *) (slot + 4) == 0 &&
                    *(s32 *) (slot + 0x238) == 0) {
                    if (*(u8 *) (slot + 3) != 0) {
                        func_80025F20(slot + 0x1E0);
                        *(u8 *) (slot + 4) = 2U;
                    } else {
                        func_8001713C((u8) i, *(s16 *) (slot + 0x26E));
                    }
                    *(u8 *) (slot + 3) = 0U;
                    *(u8 *) (slot + 2) = 0U;
                    *(u8 *) (slot + 5) = 0U;
                    func_80017404((u8) i, *(s16 *) (slot + 0));
                }
                timer2 = *(u8 *) (slot + 4);
                if ((s32) timer2 > 0) {
                    // Matching: u16 temporary needed for the match.
                    u16 new_timer = timer2 - 1;
                    *(u8 *) (slot + 4) = (u8) new_timer;
                }
        }
        i += 1;
        slot += 0x274;
    } while (i != 6);
}

// Returns the default volume of track.
u16 func_80017764(s32 track)
{
    return D_8003F600[track];
}

volatile unsigned int func_80017778(slot)
s32 slot;
{
    s32 offset;
    u8 *base;
    int idle;

    offset = slot * 0x274;
    base = &((u8 *) D_80079FA0)[offset];
    idle = *(s32 *) (base + 0x20C) == 0;

if (idle) {
    return base[3] == 0;
}

}

volatile unsigned int func_800177C4(s32 slot)
{
    s32 offset;
    u8 *base;
    int idle;
    offset = slot * 0x274;
    base = &((u8 *) D_80079FA0)[offset];
    idle = *(s32 *) (base + 0x20C) == 0;

if (idle) {
    return base[3] != 0;
}

}

// Returns the CSP player of slot.
s16 *func_80017810(s32 slot)
{
    return (s16 *) ((char *) ((s16 *) D_80079FA0) + slot * 628 + 480);
}

// TU-NOTE: the .data of this file (formerly asm/data/core1/1E2E730.data.s) is defined here in C; values are from the ROM.
u16 D_8003F600[168] = {
    0x3A98, 0x61A8, 0x3A98, 0x61A8, 0x61A8, 0x6D60, 0x6D60, 0x3A98, 0x6D60, 0x3A98, 0x55F0, 0x4E20,
    0x4E20, 0x6D60, 0x6D60, 0x7D00, 0x7D00, 0x3A98, 0x3A98, 0x3A98, 0x3A98, 0x3A98, 0x4E20, 0x4E20,
    0x3A98, 0x3A98, 0x4A38, 0x61A8, 0x3A98, 0x3A98, 0x3A98, 0x6D60, 0x6D60, 0x3A98, 0x3A98, 0x61A8,
    0x3A98, 0x7D00, 0x7D00, 0x7D00, 0x4E20, 0x61A8, 0x3A98, 0x6D60, 0x61A8, 0x4E20, 0x6D60, 0x4E20,
    0x4E20, 0x4E20, 0x3A98, 0x3A98, 0x3A98, 0x3A98, 0x3A98, 0x3A98, 0x4650, 0x4E20, 0x3A98, 0x4E20,
    0x3A98, 0x3A98, 0x4E20, 0x4E20, 0x4E20, 0x5DC0, 0x4A38, 0x3A98, 0x4E20, 0x4E20, 0x4E20, 0x3A98,
    0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x6590, 0x3A98, 0x3A98, 0x4E20, 0x55F0, 0x59D8,
    0x7D00, 0x59D8, 0x61A8, 0x55F0, 0x5DC0, 0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x61A8, 0x4650,
    0x6D60, 0x4E20, 0x55F0, 0x4A38, 0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x4E20, 0x61A8, 0x61A8, 0x61A8,
    0x61A8, 0x61A8, 0x61A8, 0x61A8, 0x61A8, 0x61A8, 0x55F0, 0x55F0, 0x4E20, 0x4E20, 0x55F0, 0x4E20,
    0x61A8, 0x61A8, 0x55F0, 0x6978, 0x6978, 0x55F0, 0x55F0, 0x4E20, 0x6D60, 0x6D60, 0x55F0, 0x55F0,
    0x3A98, 0x4A38, 0x4A38, 0x5208, 0x5208, 0x5208, 0x5208, 0x5208, 0x5208, 0x7D00, 0x5208, 0x5208,
    0x5208, 0x5208, 0x6D60, 0x5208, 0x5208, 0x5208, 0x5208, 0x5208, 0x59D8, 0x5DC0, 0x5208, 0x61A8,
    0x61A8, 0x61A8, 0x61A8, 0x61A8, 0x61A8, 0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x0};
