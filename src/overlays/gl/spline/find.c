// Spline lookups: find the spline path through a point, two consecutive points, or the nearest
// spline node of a position or actor.
#include "common.h"

typedef struct {
    u8 pad_0[0x184];
    s16 spline_list;
    u16 pad_1;
    s32 count;
} SplineFindList;
typedef struct {
    u8 pad_0[2];
    u8 count;
    u8 pad_1[0x11];
    f32 positions[1][3];
} SplineFindPath;
extern void *func_800D7400(void);
extern void *func_8001B798();
typedef struct {
    u8 pad_0[0x184];
    s16 spline_list;
    s16 pad_1;
    s32 count;
} SplineLevelData;
typedef struct {
    u8 pad_0[2];
    u8 count;
    u8 pad_1[0x11];
    f32 positions[1][3];
} SplinePointList;
s32 glsplinefind_entrypoint_2();
s32 glsplinefind_entrypoint_3();

// Find the spline through the spline node nearest to a position; also returns that node position.
s32 glsplinefind_entrypoint_0(f32 pos[3], f32 node_pos_out[3])
{
    f32 node_pos[3];
    s32 found;

    found = _gccubesearch_entrypoint_2(pos, node_pos);
    if (found == 0) {
        return -1;
    }
    func_800EE84C(node_pos_out, node_pos);
    return glsplinefind_entrypoint_2(node_pos);
}

int glsplinefind_entrypoint_1(s32 pos)
{
    s32 node_pos[3];
    if (!_gccubesearch_entrypoint_2(pos, node_pos)) {
        return -1;
    }
    return glsplinefind_entrypoint_2(node_pos);
}

s32 glsplinefind_entrypoint_2(actor) Actor *actor;
{
    f32 pos[3];
    func_800EE84C(pos, actor);
    return glsplinefind_entrypoint_3(pos);
}

// Find the spline with a node exactly at pos.
s32 glsplinefind_entrypoint_3(pos)
f32 pos[3];
{
    SplineFindList *level;
    SplineFindPath *path;
    f32(*point)[3];
    s32 i;
    s32 offset;
    s32 j;
    s32 point_count;
    s16 *spline_ids;

    level = func_800D7400();
    for (i = 0, offset = 0; i < level->count; i++, offset += 2) {
        spline_ids = func_8001B798(level->spline_list);
        j = 0;
        path = func_8001B798(*(s16 *) ((u8 *) spline_ids + offset));
        point_count = path->count;
        point = path->positions;

if (point_count > 0) {
    do {
        if (func_800EECE0(pos, *point))
            return i;
        j++;
        point++;
    } while (j != point_count);
}

}
return -1;
}

// Find the spline with two consecutive nodes at from and to.
s32 glsplinefind_entrypoint_4(f32 *from, f32 *to)
{
    s32 i;
    s32 point_count;
    s32 j;
    f32 from_pos[3];
    f32 to_pos[3];
    SplineLevelData *level;
    SplinePointList *path;
    f32 *point;
    level = func_800D7400();
    func_800EE84C(from_pos, from);
    func_800EE84C(to_pos, to);
    for (i = 0; i < level->count; i++) {
        path = func_8001B798(((s16 *) func_8001B798(level->spline_list))[i]);
        point_count = path->count;
        point = path->positions[0];
        for (j = 0; j < point_count; j++, point += 3) {
            if (func_800EECE0(from_pos, point) && func_800EECE0(to_pos, point + 3))
                return i;
        }
    }
    return -1;
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/gl/spline/find.data.s) is defined here in C.
// Values are taken from the ROM.
