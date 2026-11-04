#include "common.h"

typedef struct {
    u8 pad_0[0x10];
    u16 cell_count;
    u8 pad_12[2];
    s32 group_count;
    u8 pad_18[4];
    s32 record_offset;
} LightGridDefinition;
typedef struct {
    u16 id;
    u16 enabled;
} LightGridSourceState;
typedef struct {
    u8 pad_0[0x14];
    LightGridSourceState groups[1];
} LightGridSource;
typedef struct {
    u8 pad_0[0x10];
    s32 cell;
} LightGridRecord;
typedef struct {
    u8 used;
    u8 n;
    u8 pad_2[14];
} LightGridState;
typedef struct {
    s16 grid_min[3];
    s16 grid_max[3];
    u8 pad_C[12];
    f32 scale;
} LightGridBounds;
typedef struct {
    u8 used;
    u8 n;
    u8 h[14];
} VpCell;
typedef struct {
    u8 pad_0[3];
    u8 dirty;
    u8 pad_4[16];
} VpCellOut;
typedef struct {
    u8 pad_0[0xC];
    u16 width;
    u16 plane;
    u8 pad_10[4];
    s32 count;
    u8 pad_18[4];
    s32 out_offset;
} VpGrid;
extern s32 func_800C8760(s32, s32);
extern s32 func_800C89D8(s32);
extern s32 func_800C8800(s32, f32 *);
extern void func_800C883C(s32, f32 *);
extern s32 func_800C878C(s32, s32, s32);
extern void func_800C8898(s32, f32[3]);
typedef struct {
    u8 used;
    u8 n;
    u8 h[14];
} VpLightGroup62;
extern void func_800C8900(s32, s32 *);

// Create: allocates the per-group light state and the grid cell -> group table (-1 = none).
void *vplight_entrypoint_0(LightGridDefinition *def, LightGridSource *src)
{
    LightGridState *states;
    LightGridState *state;
    LightGridRecord *record;
    LightGridSourceState *src_group;
    LightGridSourceState *src_end;
    s16 *cell_table;
    s16 *entry;
    s16 *table_end;
    LightGridSourceState *src_first;
    s32 size;

    size = def->cell_count * sizeof(s16) + def->group_count * sizeof(LightGridState);
    states = heap_alloc(size);
    rare_memset(states, 0, size);
    // Matching: empty block steers IDO's register allocation.
    if (1) {
    }
    cell_table = (s16 *) ((u8 *) states + def->group_count * sizeof(LightGridState));
    table_end = cell_table + def->cell_count;
    for (entry = cell_table; entry < table_end;) {
        *entry++ = -1;
    }
    src_end = def->group_count + src->groups;
    record = (LightGridRecord *) ((u8 *) def + def->record_offset);
    src_first = src->groups;
    state = states;
    src_group = src_first;
    for (; src_group < src_end; src_group++, state++) {
        if (src_group->enabled) {
            state->used = 1;
            state->n = 0;
            cell_table[((src_group - src_first) + record)->cell] = src_group - src_first;
        }
    }
    return states;
}

void vplight_entrypoint_1(void *state)
{
    heap_free(state);
}

// Converts a sphere (pos, radius) into the min/max grid cell range per axis, clamped to the grid.
void func_80800134_vplight(LightGridBounds *grid, f32 pos[3], f32 radius, s32 cell_lo[3],
                           s32 cell_hi[3])
{
    s32 axis;
    s32 lo;
    s32 hi;
    f32 pos_lo;
    f32 pos_hi;
    s32 grid_lo;
    s32 grid_hi;

    for (axis = 0; axis < 3; axis++) {
        pos_lo = pos[axis] - radius;
        pos_hi = pos[axis] + radius;
        lo = grid->scale * pos_lo;
        hi = grid->scale * pos_hi;
        if (pos_lo < 0.0f) {
            lo--;
        }
        if (pos_hi < 0.0f) {
            hi--;
        }
        grid_lo = grid->grid_min[axis];
        grid_hi = grid->grid_max[axis];
        if (lo < grid_lo) {
            lo = grid_lo;
        }
        if (lo > grid_hi) {
            lo = grid_hi;
        }
        if (hi < grid_lo) {
            hi = grid_lo;
        }
        if (hi > grid_hi) {
            hi = grid_hi;
        }
        cell_lo[axis] = lo - grid_lo;
        cell_hi[axis] = hi - grid_lo;
    }
}

// Update: re-bins changed lights into the groups their outer radius overlaps and marks those
// groups dirty.
void vplight_entrypoint_2(VpCell *list, VpGrid *grid)
{
    VpCellOut *out;
    VpCell *group;
    VpCell *end;
    s16 *cell_table;
    s32 handle;
    s32 changed;
    f32 pos[3];
    f32 range[2];
    s32 lo[3];
    s32 hi[3];
    VpCell *target;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    s32 group_idx;
    s32 cell_idx;
    s32 j;
    VpCell *groups;

    groups = list;
    end = groups + grid->count;
    cell_table = (s16 *) (groups + grid->count);
    out = (VpCellOut *) ((u8 *) grid + grid->out_offset);
    handle = func_800C8760(2, 2);
    if (handle == 0) {
        return;
    }
    do {
        changed = func_800C89D8(handle);
        // Marks groups holding the light dirty; drops the light from them if it changed.
        for (group = groups; group < end; group++) {
            if (group->used != 0 && group->n != 0) {
                for (k = 0; k != 14; k++) {
                    if (group->h[k] == handle) {
                        if (changed) {
                            group->h[k] = 0;
                            group->n--;
                        }
                        out[group - groups].dirty = 1;
                        break;
                    }
                }
            }
        }
        if (changed) {
            func_800C8800(handle, pos);
            func_800C883C(handle, range);
            func_80800134_vplight(grid, pos, range[1], lo, hi);
            for (z = lo[2]; z <= hi[2]; z++) {
                for (y = lo[1]; y <= hi[1]; y++) {
                    for (x = lo[0]; x <= hi[0]; x++) {
                        cell_idx = grid->plane * z + x + y * grid->width;
                        group_idx = cell_table[cell_idx];
                        if (group_idx >= 0) {
                            target = groups + group_idx;
                            if (target->used != 0) {
                                for (j = 0; j != 14; j++) {
                                    if (target->h[j] == 0) {
                                        target->h[j] = handle;
                                        target->n++;
                                        ((VpCellOut *) (group_idx * 20 + (s32) out))->dirty = 1;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        handle = func_800C878C(handle, 2, 2);
    } while (handle != 0);
}

// Writes the integer light position to out.
s32 func_808004B0_vplight(s32 light, s32 *out)
{
    f32 pos[3];

    func_800C8800(light, pos);
    out[0] = (s32) pos[0];
    out[1] = (s32) pos[1];
    out[2] = (s32) pos[2];
}

// Writes inner radius * 256, outer radius squared and the 16384 inverse-range fixed point.
void func_80800518_vplight(s32 light, s32 *out)
{
    f32 radii[3];

    func_800C8898(light, radii);
    out[0] = (s32) (radii[0] * 256.0f);
    out[1] = (s32) (radii[1] * radii[1]);
    out[2] = (s32) (radii[2] * 16384.0f);
}

// Apply: adds the colour of each light in the group to the vertex colours, with a linear
// falloff between the inner and outer radius.
void vplight_entrypoint_3(VpLightGroup62 *groups, s32 group_idx, Vtx *vtx, s32 count)
{
    VpLightGroup62 *group;
    s32 pos[5];
    s32 radii[3];
    s32 color[3];
    Vtx *v;
    Vtx *end;
    s32 slot;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dist;
    // Matching: unused local, needed for the frame layout.
    s32 unk_0;
    s32 channel;

    // Matching: the `+ 0` is needed for the match.
    group = &(groups + 0)[group_idx];
    if (group->n) {
        end = vtx + count;
        slot = 0;
        do {
            if (group->h[slot])
                break;
            slot++;
        } while (slot < 14);
        // Matching: empty test steers IDO's register allocation.
        if (vtx) {
        }
        for (; slot < 14; slot++) {
            if (group->h[slot]) {
                func_808004B0_vplight(group->h[slot], pos);
                func_80800518_vplight(group->h[slot], radii);
                func_800C8900(group->h[slot], color);
                // Matching: empty test steers IDO's register allocation.
                if (end) {
                }
                for (v = vtx; v < end; v++) {
                    dx = pos[0] - v->v.ob[0];
                    dy = pos[1] - v->v.ob[1];
                    dz = pos[2] - v->v.ob[2];
                    dist = dx * dx + dy * dy + dz * dz;
                    if (dist < radii[1]) {
                        if (dist != 0)
                            dist = sqrtf((f32) dist) * 256.0f;
                        // dz, dx and dy are reused for the falloff (0x10000 = full strength).
                        dz = radii[0];
                        if (dz < dist) {
                            dx = 0x4000 - (((dist - dz) * radii[2]) >> 8);
                            dy = dx << 2;
                        } else {
                            dy = 0x10000;
                        }
                        channel = v->v.cn[0] + ((color[0] * dy) >> 16);
                        if (channel >= 256)
                            channel = 255;
                        v->v.cn[0] = channel;
                        channel = v->v.cn[1] + ((color[1] * dy) >> 16);
                        if (channel >= 256)
                            channel = 255;
                        v->v.cn[1] = channel;
                        channel = v->v.cn[2] + ((color[2] * dy) >> 16);
                        if (channel >= 256)
                            channel = 255;
                        v->v.cn[2] = channel;
                    }
                }
            }
        }
    }
}

// Init: bakes the static lights into the base vertex colours.
void vplight_entrypoint_4(Vtx *vtx, s32 count)
{
    Vtx *end;
    s32 green;
    s32 blue;
    s32 handle;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 dist_sq;
    s32 dist;
    s32 falloff;
    s32 pos[3];
    s32 radii[3];
    s32 color[3];
    s32 red;
    // Matching: extra temporary splits the live ranges of dz.
    s32 dz_tmp;
    end = vtx + count;
    for (; vtx < end; vtx++) {
        red = vtx->v.cn[0];
        green = vtx->v.cn[1];
        blue = vtx->v.cn[2];
        handle = func_800C8760(0, 4);
        while (handle) {
            func_808004B0_vplight(handle, pos);
            func_80800518_vplight(handle, radii);
            func_800C8900(handle, color);
            dx = pos[0] - vtx->v.ob[0];
            dy = pos[1] - vtx->v.ob[1];
            dz_tmp = pos[2] - vtx->v.ob[2];
            dz = dz_tmp;
            dist_sq = dx * dx + dy * dy + dz * dz;
            dist = dist_sq;
            if (dist_sq < radii[1]) {
                // Matching: the repeated expression instead of dist_sq is needed for the match.
                if (dx * dx + dy * dy + dz * dz)
                    dist = sqrtf((f32) dist_sq) * 256.0f;
                // dz and dy are reused for the falloff (0x10000 = full strength).
                dz = radii[0];
                if (dz < dist) {
                    dy = 0x4000 - (((dist - dz) * radii[2]) >> 8);
                    falloff = dy << 2;
                } else {
                    falloff = 0x10000;
                }
                red += (color[0] * falloff) >> 16;
                green += (color[1] * falloff) >> 16;
                blue += (color[2] * falloff) >> 16;
            }
            handle = func_800C878C(handle, 0, 4);
        }
        if (red >= 256)
            red = 255;
        if (green >= 256)
            green = 255;
        if (blue >= 256)
            blue = 255;
        vtx->v.cn[0] = red;
        vtx->v.cn[1] = green;
        vtx->v.cn[2] = blue;
    }
}
