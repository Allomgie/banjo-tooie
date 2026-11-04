// Real-time point lighting of the map mesh: builds a cell grid over the map vertices at load,
// then each frame adds light colour * falloff to baked vertex colours of cells lights touch.
#include "common.h"

// Map light grid: header followed by cells (32 bytes each, 15 light slots, an AABB padded by 20
// units, a range of vertex records) and then the vertex records (baked colour per vertex).
// dirty: -1 = cell has no vertices, > 0 = vertex colours need rewriting.
typedef struct {
    s16 origin[3];
    u16 pad_6[3];
    u16 stride_y;
    u16 stride_z;
} RtLightGrid32_80800000_rtlight;
typedef struct {
    u8 pad_0[0x10];
    u16 cell_count;
    s16 cell_size;
    s32 vertex_count;
    u16 cells[1][2];
} RtSrc;
typedef struct {
    u8 slots[15];
    s8 dirty;
    s16 min[3];
    s16 max[3];
    u16 first;
    u16 count;
} RtCell_rtlight_entrypoint_1;
typedef struct {
    u8 pad_0[6];
    s16 vertex_idx;
    u8 baked_col[3];
    u8 pad_B;
} RtLight_rtlight_entrypoint_1;
typedef struct {
    u8 pad_0[0xC];
    u8 col[3];
    u8 pad_F;
} RtTblEntry_rtlight_entrypoint_1;
typedef struct {
    RtSrc *src;
    s16 cell_size;
    u16 cell_count;
    f32 inv_cell_size;
    RtCell_rtlight_entrypoint_1 cells[1];
} RtOut_rtlight_entrypoint_1;
extern void *heap_alloc(s32);
extern RtTblEntry_rtlight_entrypoint_1 *func_800B2190(s32);
typedef struct {
    s16 origin[3];
    s16 max[3];
    u16 stride_y;
    u16 stride_z;
} RtLightGrid32_8080036C_rtlight;
typedef struct {
    u8 slots[15];
    s8 dirty;
    s16 min[3];
    s16 max[3];
    u16 first;
    u16 count;
} RtCell_8080036C_rtlight;
typedef struct {
    RtLightGrid32_8080036C_rtlight *src;
    s16 cell_size;
    u16 cell_count;
    f32 inv_cell_size;
    RtCell_8080036C_rtlight cells[1];
} RtOut_8080036C_rtlight;
typedef struct {
    RtCell_8080036C_rtlight *list[150];
    RtCell_8080036C_rtlight **cur;
} RtCellList;
extern RtCellList D_80135550;
extern void func_800C8898(s32, f32[3]);
typedef struct {
    u8 slots[15];
    s8 dirty;
    s16 min[3];
    s16 max[3];
    s16 first;
    s16 count;
} RtCell_rtlight_entrypoint_2;
typedef struct {
    s16 sum[3];
    s16 vertex_idx;
    u8 baked_col[3];
    u8 pad_B;
} RtLight_rtlight_entrypoint_2;
typedef struct {
    s16 pos[3];
    u8 pad_6[6];
    u8 col[3];
    u8 pad_F;
} RtTblEntry_rtlight_entrypoint_2;
typedef struct {
    void *src;
    s16 cell_size;
    s16 cell_count;
    f32 inv_cell_size;
    RtCell_rtlight_entrypoint_2 cells[1];
} RtOut_rtlight_entrypoint_2;
extern s32 func_800C8760(s32, s32);
extern s32 func_800C878C(s32, s32, s32);
extern void func_800C8800(s32, f32 *);
extern void func_800C883C(s32, f32 *);
extern s32 func_800E3DC0();
extern void func_800C8900(s32, s32 *);

// Cell index to grid coordinates.
void func_80800000_rtlight(RtLightGrid32_80800000_rtlight *grid, s32 cell_idx, s32 coords[3])
{
    coords[2] = cell_idx / grid->stride_z;
    coords[1] = (cell_idx % grid->stride_z) / grid->stride_y;
    coords[0] = (cell_idx % grid->stride_z) % grid->stride_y;
    coords[0] += grid->origin[0];
    coords[1] += grid->origin[1];
    coords[2] += grid->origin[2];
}

void rtlight_entrypoint_0(void *grid)
{
    heap_free(grid);
}

// Builds the cell grid over the map's vertex list; copies baked colours from the model.
RtOut_rtlight_entrypoint_1 *rtlight_entrypoint_1(RtSrc *src, s32 model, s32 unused)
{
    RtOut_rtlight_entrypoint_1 *grid;
    RtCell_rtlight_entrypoint_1 *cell;
    RtLight_rtlight_entrypoint_1 *rec_end;
    RtCell_rtlight_entrypoint_1 *cell_end;
    RtCell_rtlight_entrypoint_1 *first_cell;
    u16 *src_cell;
    RtLight_rtlight_entrypoint_1 *rec;
    RtTblEntry_rtlight_entrypoint_1 *verts;
    s32 i;
    s32 cell_count;
    s16 *src_idx;
    RtTblEntry_rtlight_entrypoint_1 *vert;
    s32 pos[3];

    cell_count = src->cell_count;
    grid = heap_alloc(cell_count * 32 + src->vertex_count * 12 + 12);
    grid->src = src;
    grid->cell_size = src->cell_size;
    grid->cell_count = cell_count;
    grid->inv_cell_size = 1.0f / src->cell_size;
    src_cell = src->cells[0];
    first_cell = grid->cells;
    cell_end = (RtCell_rtlight_entrypoint_1 *) ((cell_count << 5) + (u8 *) grid + 12);
    for (cell = first_cell; cell < cell_end; cell++, src_cell += 2) {
        if (src_cell[1] == 0) {
            cell->dirty = -1;
            continue;
        }
        for (i = 0; i < 15; i++) {
            cell->slots[i] = 0;
        }
        func_80800000_rtlight(grid->src, cell - first_cell, pos);
        for (i = 0; i < 3; i++) {
            cell->min[i] = pos[i] * src->cell_size - 20;
            cell->max[i] = (pos[i] + 1) * src->cell_size + 20;
        }
        cell->first = src_cell[0];
        cell->count = src_cell[1];
        cell->dirty = 0;
    }
    rec = (RtLight_rtlight_entrypoint_1 *) cell;
    rec_end = rec + src->vertex_count;
    src_idx = (s16 *) src_cell;
    verts = func_800B2190(model);
    for (; rec < rec_end; rec++, src_idx++) {
        rec->vertex_idx = *src_idx;
        vert = &verts[*src_idx];
        for (i = 0; i < 3; i++) {
            rec->baked_col[i] = vert->col[i];
        }
    }
    return grid;
}

// Collects the cells overlapping the sphere (pos, radius) into D_80135550 (max 150).
void func_8080036C_rtlight(RtOut_8080036C_rtlight *grid, f32 *pos, f32 radius,
                           RtCell_8080036C_rtlight ***out_list, RtCell_8080036C_rtlight ***out_end)
{
    s32 lo[3];
    s32 hi[3];
    RtLightGrid32_8080036C_rtlight *src;
    RtCell_8080036C_rtlight *cell;
    f32 p; // Matching: unused local needed for the match.
    f32 min_f;
    f32 max_f;
    s32 min_cell;
    s32 max_cell;
    s32 i;
    s32 x;
    s32 y;
    s32 z;
    s32 cell_origin;
    s32 cell_max;

    src = grid->src;
    for (i = 0; i < 3; i++) {
        min_f = pos[i] - radius;
        max_f = pos[i] + radius;
        min_cell = grid->inv_cell_size * min_f;
        max_cell = grid->inv_cell_size * max_f;
        if (min_f < 0.0f) {
            min_cell--;
        }
        if (max_f < 0.0f) {
            max_cell--;
        }
        cell_origin = src->origin[i];
        cell_max = src->max[i];
        if (min_cell < cell_origin) {
            min_cell = cell_origin;
        }
        if (cell_max < min_cell) {
            min_cell = cell_max;
        }
        if (max_cell < cell_origin) {
            max_cell = cell_origin;
        }
        if (cell_max < max_cell) {
            max_cell = cell_max;
        }
        lo[i] = min_cell - cell_origin;
        hi[i] = max_cell - cell_origin;
    }
    D_80135550.cur = D_80135550.list;
    for (z = lo[2]; z <= hi[2]; z++) {
        for (y = lo[1]; y <= hi[1]; y++) {
            for (x = lo[0]; x <= hi[0]; x++) {
                cell = (RtCell_8080036C_rtlight *) (((src->stride_z * z) << 5) + (u8 *) grid +
                                                    (x << 5) + ((y * src->stride_y) << 5) + 12);
                if (cell->dirty >= 0 && D_80135550.cur < &D_80135550.list[150]) {
                    *D_80135550.cur = cell;
                    D_80135550.cur++;
                }
            }
        }
    }
    *out_list = D_80135550.list;
    *out_end = D_80135550.cur;
}

void func_80800544_rtlight(s32 light, s32 *out_pos)
{
    f32 pos[3];
    func_800C8800(light, pos);
    out_pos[0] = pos[0];
    out_pos[1] = pos[1];
    out_pos[2] = pos[2];
}

// Light radii in fixed point for the falloff: inner * 256, outer squared, inverse range * 0x4000.
void func_808005AC_rtlight(s32 light, s32 *out)
{
    f32 radii[3];

    func_800C8898(light, radii);
    out[0] = (s32) (radii[0] * 256.0f);
    out[1] = (s32) (radii[1] * radii[1]);
    out[2] = (s32) (radii[2] * 16384.0f);
}

// Per-frame update: assigns the active lights to the cells they overlap, then for visible dirty
// cells rewrites the vertex colours (baked colour + light colour * falloff, clamped to 255).
void rtlight_entrypoint_2(RtOut_rtlight_entrypoint_2 *grid, s32 model, s32 unused, s32 flag)
{
    s32 light;
    s32 slot;
    RtCell_rtlight_entrypoint_2 *cell;
    RtCell_rtlight_entrypoint_2 *cell_end;
    s32 pad[2]; // Matching: unused local needed for the match.
    f32 pos[3];
    f32 radii[2];
    RtCell_rtlight_entrypoint_2 **list;
    RtCell_rtlight_entrypoint_2 **list_end;
    s32 dx;
    s32 dy;
    s32 dz;
    RtTblEntry_rtlight_entrypoint_2 *vert_restore;
    RtTblEntry_rtlight_entrypoint_2 *vert_sum;
    RtTblEntry_rtlight_entrypoint_2 *vert_out;
    s32 falloff;
    s32 light_pos[3];
    s32 radius[3];
    s32 light_col[3];
    s32 j;
    RtTblEntry_rtlight_entrypoint_2 *verts;
    RtLight_rtlight_entrypoint_2 *rec;
    RtLight_rtlight_entrypoint_2 *rec_end;
    RtLight_rtlight_entrypoint_2 *cur;
    u8 *slot_ptr;
    s32 tmp;
    s32 dist;
    s32 scale;
    s32 val;

    cell_end = (RtCell_rtlight_entrypoint_2 *) ((grid->cell_count << 5) + (u8 *) grid + 12);
    for (light = func_800C8760(2, 2); light != 0; light = func_800C878C(light, 2, 2)) {
        for (cell = grid->cells; cell < cell_end; cell++) {
            if (cell->dirty < 0) {
                continue;
            }
            for (j = 0; j < 15; j++) {
                if (cell->slots[j] == light) {
                    cell->slots[j] = 0;
                    cell->dirty = flag;
                    break;
                }
            }
        }
        func_800C8800(light, pos);
        func_800C883C(light, radii);
        func_8080036C_rtlight(grid, pos, radii[1], &list, &list_end);
        for (; list < list_end; list++) {
            for (tmp = 0; tmp < 15; tmp++) {
                if ((*list)->slots[tmp] == 0) {
                    (*list)->slots[tmp] = light;
                    (*list)->dirty = flag;
                    break;
                }
            }
        }
    }
    cell = grid->cells;
    verts = func_800B2190(model);
    for (; cell < cell_end; cell++) {
        if (cell->dirty <= 0) {
            continue;
        }
        if (!func_800E3DC0(cell->min, cell->max)) {
            continue;
        }
        slot = 0;
        slot_ptr = cell->slots;
        for (; slot < 15; slot++, slot_ptr++) {
            if (*slot_ptr != 0) {
                break;
            }
        }
        rec = cell->first + (RtLight_rtlight_entrypoint_2 *) cell_end;
        rec_end = rec + cell->count;
        if (slot == 15) {
            for (; rec < rec_end; rec++) {
                vert_restore = &verts[rec->vertex_idx];
                vert_restore->col[0] = rec->baked_col[0];
                vert_restore->col[1] = rec->baked_col[1];
                vert_restore->col[2] = rec->baked_col[2];
            }
        } else {
            for (cur = rec; cur < rec_end; cur++) {
                cur->sum[0] = cur->baked_col[0];
                cur->sum[1] = cur->baked_col[1];
                cur->sum[2] = cur->baked_col[2];
            }
            for (; slot < 15; slot++, slot_ptr++) {
                if (!*slot_ptr) {
                    continue;
                }
                func_80800544_rtlight(*slot_ptr, light_pos);
                func_808005AC_rtlight(*slot_ptr, radius);
                func_800C8900(*slot_ptr, light_col);
                for (cur = rec; cur < rec_end; cur++) {
                    vert_sum = &verts[cur->vertex_idx];
                    dx = light_pos[0] - vert_sum->pos[0];
                    dy = light_pos[1] - vert_sum->pos[1];
                    dz = light_pos[2] - vert_sum->pos[2];
                    tmp = dx * dx + dy * dy + dz * dz;
                    dist = tmp;
                    if (tmp < radius[1]) {
                        if (tmp != 0) {
                            dist = sqrtf(tmp) * 256.0f;
                        }
                        if (radius[0] < dist) {
                            falloff = 0x4000 - (((dist - radius[0]) * radius[2]) >> 8);
                            scale = falloff << 2;
                        } else {
                            scale = 0x10000;
                        }
                        cur->sum[0] += (light_col[0] * scale) >> 16;
                        cur->sum[1] += (light_col[1] * scale) >> 16;
                        cur->sum[2] += (light_col[2] * scale) >> 16;
                    }
                }
            }
            for (; rec < rec_end; rec++) {
                vert_out = &verts[rec->vertex_idx];
                val = rec->sum[0];
                if (val >= 0x100) {
                    val = 0xFF;
                }
                vert_out->col[0] = val;
                val = rec->sum[1];
                if (val >= 0x100) {
                    val = 0xFF;
                }
                vert_out->col[1] = val;
                val = rec->sum[2];
                if (val >= 0x100) {
                    val = 0xFF;
                }
                vert_out->col[2] = val;
            }
        }
        cell->dirty--;
    }
}
