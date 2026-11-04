// Prop search over the cube grid: finds node props (markers) by type id near a point or anywhere,
// returns the nearest one, its position and counts; used by actors and cameras.
#include "common.h"

extern void func_800EE84C();
extern void **func_800BDD24(s32 *);
extern s32 func_800EEB40;
extern s32 func_800EFC7C;
void func_800BE554();
void func_800BD64C(s32 *, f32 *);
extern void *func_800BDAD4(s32 *);
extern void *func_800E9D68(void *);
extern void *func_800E9D90(void *);
typedef struct Mass46CubeCoords {
    s32 x;
    s32 y;
    s32 z;
} Mass46CubeCoords;
extern void *func_800E9BF4(void *, s32);
extern void func_800EFD24(f32 *);
extern void func_800EE7F8(f32 *, f32 *);
s32 gccubesearch_entrypoint_7();
s32 gccubesearch_entrypoint_8();
s32 gccubesearch_entrypoint_14();

int gccubesearch_entrypoint_0(s32 id, f32 *pos)
{
    s32 cell_pos[3];
    if (pos != 0) {
        cell_pos[0] = pos[1];
        cell_pos[1] = pos[2];
        cell_pos[2] = pos[3];
    }
    gccubesearch_entrypoint_14(id, (pos == 0) ? 0 : cell_pos);
}

s32 gccubesearch_entrypoint_1(s32 id, f32 pos[3])
{
    s32 cell_pos[3];

    cell_pos[0] = (s32) pos[0];
    cell_pos[1] = (s32) pos[1];
    cell_pos[2] = (s32) pos[2];
    return gccubesearch_entrypoint_14(id, cell_pos);
}

// Finds the first prop with this id anywhere and copies its position (as s32) to out.
int gccubesearch_entrypoint_2(OSIoMesg *id, OSIoMesg *out)
{
    int prop;
    if ((prop = gccubesearch_entrypoint_14(id, 0)) != 0) {
        *(s32 *) ((char *) out + 0x0) = *(s16 *) ((char *) prop + 0x0);
        *(s32 *) ((char *) out + 0x4) = *(s16 *) ((char *) prop + 0x2);
        *(s32 *) ((char *) out + 0x8) = *(s16 *) ((char *) prop + 0x4);
        return 1;
    }
    return 0;
}

s32 gccubesearch_entrypoint_3(s32 id, f32 out[3])
{
    f32 pos[3];

    if (!gccubesearch_entrypoint_2(id, pos)) {
        return 0;
    }
    func_800EE84C(out, pos);
    return 1;
}

// Squared length.
s32 func_80800160_gccubesearch(s32 dx, s32 dy, s32 dz)
{
    return dx * dx + dy * dy + dz * dz;
}

// Nearest prop with this id to pos (squared distance); nearby = only the cubes around pos.
s16 *gccubesearch_entrypoint_4(s32 id, f32 *pos, s32 nearby)
{
    s32 i;
    s16 *props[40];
    s32 best_dist = 0x7FFFFFFF;
    s16 *best = NULL;
    s32 count;
    s32 dist;
    s16 ipos[3];
    ipos[0] = (s32) pos[0];
    ipos[1] = (s32) pos[1];
    ipos[2] = (s32) pos[2];
    if (!nearby)
        count = gccubesearch_entrypoint_7(id, props, 40, pos);
    else
        count = gccubesearch_entrypoint_8(id, props, 40, pos);
    if (!count)
        return NULL;
    for (i = 0; i < count; i++) {
        dist = func_80800160_gccubesearch(ipos[0] - props[i][0],
                                          ipos[1] - props[i][1],
                                          ipos[2] - props[i][2]);
        if (dist < best_dist) {
            best_dist = dist;
            best = props[i];
        }
    }
    return best;
}

void gccubesearch_entrypoint_5(s32 id, s32 pos)
{
    gccubesearch_entrypoint_4(id, pos, 0);
}

void gccubesearch_entrypoint_6(s32 id, s32 pos)
{
    gccubesearch_entrypoint_4(id, pos, 0x1);
}

// Collects props with the ids in the -1 terminated list over all cubes; returns the count.
s32 gccubesearch_entrypoint_7(ids, out, max)
s32 ids;
s32 out;
s32 max;
{
    s32 count;
    u32 cube;
    u32 cube_end;

    count = 0;
    func_800BE52C(&cube, &cube_end);

if (cube < cube_end) {
    do {
        count +=
            _gspropmarker_entrypoint_1(cube, ids, (count * 4) + out, max - count);
        cube += 8;
    } while (cube < cube_end);
}

return count;
}

// Same as above, but only over the cubes around pos.
s32 gccubesearch_entrypoint_8(ids, out, max, pos) void *ids;
void **out;
s32 max;
f32 *pos;
{
    void **cube_ptr;
    s32 count;
    s32 cell_pos[3];

    count = 0;
    func_800EE904(cell_pos, pos);
    cube_ptr = func_800BDD24(cell_pos);
    for (; *cube_ptr; cube_ptr++) {
        count +=
            _gspropmarker_entrypoint_1(*cube_ptr, ids, out + count, max - count);

}
return count;
}

int gccubesearch_entrypoint_9(id)
s32 id;
{
    s32 ids[2];
    ids[0] = id;
    ids[1] = -1;
    gccubesearch_entrypoint_7(ids);
}

// TU-NOTE: this .bss object is defined before its first use; IDO puts .bss objects used before
// their definition first, the rest in definition order.
int B_80800EB0_gccubesearch[40];

// Counts props with this id whose value (word at 0x10, top 11 bits) is below limit.
int gccubesearch_entrypoint_10(int id, int limit)
{
    int count;
    int matches;
    int i;
    int limit_copy;
    count = gccubesearch_entrypoint_9(id, &B_80800EB0_gccubesearch, 0x28);
    limit_copy = limit;
    matches = 0;
    for (i = count - 1; i >= 0; i--) {
        if (((u32) *(s32 *) ((char *) B_80800EB0_gccubesearch[i] + 0x10) >> 21) < limit_copy) {
            matches++;
        }

}

return matches;
}

s32 gccubesearch_entrypoint_11(s32 id, Vec3f *out, s32 max)
{
    s32 count = 0;
    u8 *cube;
    u8 *cube_end;

    func_800BE52C(&cube, &cube_end);
    for (; cube < cube_end; cube += 8) {
        count +=
            _gspropmarker_entrypoint_2(cube, id, out + count, max - count);
    }
    return count;
}

// Finds the prop position with the smallest dist_fn(ref, pos) and stores it in out.
s32 func_80800590_gccubesearch(out, id, ref, dist_fn)
f32 *out;
void *id;
void *ref;
f32 (*dist_fn)(void *, f32 *);
{
    f32 positions[40][3];
    s32 i;
    f32 best_dist;
    f32 dist;
    s32 count;

    func_800EFD24(out);
    best_dist = 3.402823466e+38f;
    count = gccubesearch_entrypoint_11(id, positions, 40);
    if (count == 0) {
        return 0;
    }
    for (i = 0; i < count; i++) {
        dist = dist_fn(ref, positions[i]);

if (dist < best_dist) {
    best_dist = dist;
    func_800EE7F8(out, positions[i]);
}

}
if (best_dist == 3.402823466e+38f) {
    return 0;
}
return 1;
}

void gccubesearch_entrypoint_12(s32 out, s32 id, s32 ref)
{
    func_80800590_gccubesearch(out, id, ref, &func_800EEB40);
}

int gccubesearch_entrypoint_13(s32 out, s32 id, s32 ref)
{
    func_80800590_gccubesearch(out, id, ref, &func_800EFC7C);
}

// Finds the first prop with this id: first in the cubes around pos (if given), then in all cubes.
s32 gccubesearch_entrypoint_14(id, pos)
s32 id;
s32 *pos;
{
    s32 cell[3];
    s32 prop;
    s32 min[3];
    s32 max[3];
    f32 fpos[3];
    s32 lo[3];
    s32 hi[3];
    s32 i;

    func_800BE554(min, max, pos);
    if (pos) {
        fpos[0] = (f32) pos[0];
        fpos[1] = (f32) pos[1];
        fpos[2] = (f32) pos[2];
        func_800BD64C(cell, fpos);
        for (i = 0; i < 3; i++) {
            lo[i] = cell[i] - 1;
            hi[i] = cell[i] + 1;
            if (lo[i] < min[i])
                lo[i] = min[i];
            if (max[i] < hi[i])
                hi[i] = max[i];
        }
        for (cell[0] = lo[0]; cell[0] <= hi[0]; cell[0]++) {
            for (cell[1] = lo[1]; cell[1] <= hi[1]; cell[1]++) {
                for (cell[2] = lo[2]; cell[2] <= hi[2]; cell[2]++) {
                    prop = _gspropmarker_entrypoint_0(func_800BDAD4(cell), id);
                    if (prop)
                        return prop;
                }
            }
        }
    }
    for (cell[1] = min[1]; cell[1] <= max[1]; cell[1]++) {
        if (func_800D2E90(cell[1] - min[1])) {
            for (cell[0] = min[0]; cell[0] <= max[0]; cell[0]++) {
                for (cell[2] = min[2]; cell[2] <= max[2]; cell[2]++) {
                    prop = _gspropmarker_entrypoint_0(func_800BDAD4(cell), id);
                    if (prop)
                        return prop;
                }
            }
        }
    }
    return 0;
}

// Finds a prop with this id in the cubes around pos; unk_0 != 0 also requires it to match the value
// in the top 11 bits of the word at 0x10.
void *gccubesearch_entrypoint_15(s32 id, s32 unk_0, f32 *pos)
{
    s32 cell[3];
    s32 i;
    s32 lo[3];
    s32 hi[3];
    s32 min[3];
    s32 max[3];
    u8 *prop;
    func_800BE554(min, max);
    func_800BD64C(cell, pos);
    for (i = 0; i < 3; i++) {
        lo[i] = cell[i] - 1;
        hi[i] = cell[i] + 1;
        if (lo[i] < min[i])
            lo[i] = min[i];
        if (max[i] < hi[i])
            hi[i] = max[i];
    }
    for (cell[0] = lo[0]; cell[0] <= hi[0]; cell[0]++)
        for (cell[1] = lo[1]; cell[1] <= hi[1]; cell[1]++)
            for (cell[2] = lo[2]; cell[2] <= hi[2]; cell[2]++) {
                prop = (u8 *) _gspropmarker_entrypoint_0(func_800BDAD4(cell), id);
                if (prop && (!unk_0 || unk_0 == (*(u32 *) (prop + 0x10) >> 21)))
                    return prop;
            }
    return 0;
}

void gccubesearch_entrypoint_16(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
    u64 *cube;
    u64 *cube_end;
    func_800EB880(param_0, param_3, param_4);
    func_800BE52C(&cube, &cube_end);
    while (cube < cube_end) {
        func_800EB8C0(cube);
        cube++;
    }
    func_800EBB30(param_1, param_2);
}

// Finds the first prop whose value (top 11 bits of the word at 0x10) equals key; the cube
// holding it is returned through out_cube.
void *gccubesearch_entrypoint_17(s32 key, void **out_cube)
{
    s32 cell[3];
    u8 *prop;
    s32 min[3];
    s32 max[3];
    u8 *prop_end;
    void *cube;
    func_800BE554(min, max);
    for (cell[1] = min[1]; cell[1] <= max[1]; cell[1]++) {
        if (func_800D2E90(cell[1] - min[1])) {
            for (cell[0] = min[0]; cell[0] <= max[0]; cell[0]++) {
                for (cell[2] = min[2]; cell[2] <= max[2]; cell[2]++) {
                    cube = func_800BDAD4(cell);

if (cube) {
    prop = func_800E9D68(cube);
    prop_end = func_800E9D90(cube);
    for (; prop < prop_end; prop += 0x14) {
        if (key == *(u32 *) (prop + 0x10) >> 21) {
            if (out_cube)
                *out_cube = cube;
            return prop;
        }
    }
}

}
}
}
}
if (out_cube)
    *out_cube = NULL;
return NULL;
}

// Iterator over all props in all cubes; next == 0 resets cell/index. Returns the value of the
// prop found, 0 at the start, -1 at the end.
s32 gccubesearch_entrypoint_18(s32 next, s32 *pos, s32 *param_2, s32 *flag, s32 *cell,
                               s32 *index, u8 **prop)
{
    s32 value;
    void *cube;
    Mass46CubeCoords min;
    Mass46CubeCoords max;
    u32 word;

    value = 0;
    func_800BE554(&min, &max);
    if (!next) {
        cell[0] = min.x;
        cell[1] = min.y;
        cell[2] = min.z;
        *index = 0;
        return 0;
    }
    do {
        if (max.x < cell[0]) {
            return -1;
        }
        cube = (void *) func_800BDAD4(cell);
        if (cube && func_800E9DC4(cube)) {
            *prop = func_800E9BF4(cube, *index);
            word = *(u32 *) (*prop + 0x10);
            *param_2 = (word << 11) >> 21;
            value = word >> 21;
            *flag = *(u32 *) (*prop + 4) & 1;
            pos[0] = *(s16 *) (*prop);
            pos[1] = *(s16 *) (*prop + 2);
            pos[2] = *(s16 *) (*prop + 4);
            (*index)++;
        }
        if (!cube || *index >= func_800E9DC4(cube)) {
            *index = 0;
            cell[2]++;
            if (max.z < cell[2]) {
                cell[2] = min.z;
                cell[1]++;
                if (max.y < cell[1]) {
                    cell[1] = min.y;
                    cell[0]++;

if (max.x < cell[0]) {
    return value ? value : -1;
}

}
}
}
}
while (value == 0)
    ;
return value;
}
