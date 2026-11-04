// Probably map-section awareness for actors: hides, disables or restores an actor depending on
// whether its map section is loaded, and snaps an actor onto the section mesh below it.
#include "common.h"

typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 28;
    u32 flag_3 : 1;
    u32 pad_2 : 3;
} SectFlags30;
extern void *func_800BF704(void);
extern void *_gcmapsects_entrypoint_25(void *, s32, f32 *, f32 *, f32 *, s32);
extern s32 func_800F1B78(f32 *, f32 *, f32, f32);

// If the actor's map section is not loaded, apply the hide/disable options in flags; otherwise undo them.
// Returns whether the section is loaded.
s32 subaddiesect_entrypoint_0(Actor *actor, s32 section, u32 flags)
{
    if (!_gcmapsects_entrypoint_5(section)) {
        if ((flags & 1) && ((SectFlags30 *) actor)->flag_3)
            func_8010381C(actor);
        if (flags & 2)
            func_8010A570(actor);
        if (flags & 4)
            func_8010A624(actor);
        if (flags & 8)
            actor->unk64_16 = 0;
        return 0;
    } else {
        if (flags & 2)
            func_8010A590(actor);
        if (flags & 4)
            func_8010A63C(actor);
        if (flags & 8) {
            if ((flags & 0x10) && !(*(u16 *) ((u8 *) actor + 0x64) & 1))
                _subaddiefade_entrypoint_2(actor);
            actor->unk64_16 = 1;
        }
        return 1;
    }
}

// Matching: the missing return and the temporary are needed for the match.
s32 subaddiesect_entrypoint_1(s32 actor)
{
    s32 unk_0 = actor + 4;
    _gcmapsects_entrypoint_4(unk_0);
}

// Probe the section mesh below the actor (+/-100); with snap, move onto it and align pitch/roll.
s32 subaddiesect_entrypoint_2(Actor *actor, s32 section, s32 snap)
{
    f32 from[3];
    f32 to[3];
    f32 normal[3];
    void *surface;
    f32 tilt[3];

    func_800EE7F8(from, actor->position);
    func_800EE7F8(to, actor->position);
    from[1] += 100.0f;
    to[1] -= 100.0f;
    surface = _gcmapsects_entrypoint_25(func_800BF704(), section, from, to, normal,
                                        actor->unk14);
    if (surface != NULL) {
        if (snap) {
            actor->position[1] = to[1];
            if (func_800F1B78(tilt, normal, actor->rotation[1], 1.0f)) {
                actor->rotation[0] = tilt[0];
                actor->rotation[2] = tilt[2];
            }
        }
        func_801045AC(actor, normal, to, *(s32 *) ((u8 *) surface + 8));
        return 1;
    }
    return 0;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
