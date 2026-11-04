#include "common.h"

extern f32 func_800DC0C0(void);
extern f32 func_800DC178(f32, f32);
extern f32 func_800EFC7C(f32 *, f32 *);

void *B_80800300_sudeathmatch[40];
u8 B_808003A0_sudeathmatch[40];
s32 B_808003C8_sudeathmatch;

// Picks a spawn prop (id 0x2B7) at least 400 units from other players and not the last one used.
s32 sudeathmatch_entrypoint_0(s32 player, f32 *out_pos, f32 *out_rot)
{
    s32 i;
    s32 other_count;
    Vec3f other_pos[8];
    s32 spawn_count;
    s32 pick;
    s32 spawn_idx;
    Vec3f spawn_pos;
    s32 alive;
    s32 yaw;
    void *prop;
    s32 radius;
    Vec3f offset;

    i = 0;
    other_count = 0;
    for (; i < func_800F5898(); i++) {
        if (i != player && (alive = func_800F6438(i))) {
            func_800F5A00(i, other_pos[other_count++].f);
        }
    }
    spawn_count = _gccubesearch_entrypoint_9(0x2B7, B_80800300_sudeathmatch, 40);
    if (spawn_count == 0) {
        return 0;
    }
    for (i = 0; i < spawn_count; i++) {
        B_808003A0_sudeathmatch[i] = i;
    }
    spawn_count--;
    B_808003A0_sudeathmatch[B_808003C8_sudeathmatch] = B_808003A0_sudeathmatch[spawn_count];
    while (spawn_count > 0) {
        pick = func_800DC0C0() * (spawn_count - 0.5f);
        spawn_idx = B_808003A0_sudeathmatch[pick];
        prop = B_80800300_sudeathmatch[spawn_idx];
        _gspropctrl_entrypoint_11(prop, spawn_pos.f);
        for (i = 0; i < other_count; i++) {
            if (func_800EFC7C(spawn_pos.f, other_pos[i].f) < 160000.0f) {
                if (spawn_count >= 2) {
                    B_808003A0_sudeathmatch[pick] = B_808003A0_sudeathmatch[--spawn_count];
                } else {
                    i = other_count;
                }
                break;
            }
        }
        if (i == other_count) {
            radius = _gspropctrl_entrypoint_8(prop);
            yaw = _gspropctrl_entrypoint_12(prop);
            offset.pos.x = func_800DC178(-1.0f, 1.0f) * radius;
            offset.pos.y = 0.0f;
            offset.pos.z = func_800DC178(-1.0f, 1.0f) * radius;
            func_800EE780(out_pos, spawn_pos.f, offset.f);
            out_rot[0] = out_rot[2] = 0.0f;
            out_rot[1] = yaw;
            B_808003C8_sudeathmatch = spawn_idx;
            return 1;
        }
    }
    return 0;
}
