#include "common.h"

// Vertical probe against floor/solid collision (mask 0x20020); returns 1 and the hit height on hit.
int subaddie3d_entrypoint_0(f32 pos[3], f32 up, f32 down, f32 *hit_y)
{
    f32 hit[3];
    f32 from[3];
    f32 to[3];

    func_800EE7F8(from, pos);
    from[1] += up;
    func_800EE7F8(to, pos);
    to[1] += down;
    if (func_800BEF00(from, to, hit, 0x20020)) {
        *hit_y = to[1];
        return 1;
    }
    return 0;
}

// Vertical probe against water/material collision (mask 0x1F00); returns 1 and the hit height on hit.
int subaddie3d_entrypoint_1(f32 pos[3], f32 up, f32 down, f32 *hit_y)
{
    f32 hit[3];
    f32 from[3];
    f32 to[3];

    func_800EE7F8(from, pos);
    from[1] += up;
    func_800EE7F8(to, pos);
    to[1] += down;
    if (func_800BEF00(from, to, hit, 0x1F00)) {
        *hit_y = to[1];
        return 1;
    }
    return 0;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
