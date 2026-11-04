// Player roster queries over the 8 slots: nearest player to a point, find by character id,
// check that both Banjo and Kazooie exist (split-up), find by controlled marker.

#include "common.h"

extern f32 func_800EEB40(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);

// Returns the index of the live player nearest to point; copies its position to out_pos.
s32 plsu_entrypoint_0(f32 *out_pos, f32 *point)
{
    f32 player_pos[3];
    f32 dist_sq;
    f32 min_dist_sq;
    s32 i;
    s32 nearest;

    min_dist_sq = 3.402823466e38f;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6BE4(i)) {
            func_800F5A00(i, player_pos);
            dist_sq = func_800EEB40(player_pos, point);
            if (dist_sq < min_dist_sq) {
                min_dist_sq = dist_sq;
                nearest = i;
                func_800EE7F8(out_pos, player_pos);
            }
        }
    }
    return nearest;
}

// Returns the slot of the live player whose character id equals char_id, or -1.
int plsu_entrypoint_1(s32 char_id)
{
    s32 i;
    s32 id;
    id = char_id | 0; // Matching: needed for the match.
    i = 0;
    while (i < func_800F5898()) {
        if (func_800F6BE4(i) && func_800F5410(i) == id) {
            return i;
        }
        i++;
    }

    return -1;
}

// Nonzero when both Banjo (0xA) and Kazooie (0xB) exist (split-up).
s32 plsu_entrypoint_2(void)
{
    if ((plsu_entrypoint_1(0xA) == -1)) {
        return 0;
    }
    if ((plsu_entrypoint_1(0xB) == -1)) {
        return 0;
    }
    return 1;
}

// Returns the slot of the live, stable player controlling the given marker, or -1.
int plsu_entrypoint_3(s32 marker)
{
    s32 i;
    s32 target;
    target = marker | 0; // Matching: needed for the match.
    i = 0;
    while (i < func_800F5898()) {
        if (func_800F6BE4(i) && func_800F6C5C(i) && func_800F55D0(i) == target) {
            return i;
        }
        i++;
    }

    return -1;
}
