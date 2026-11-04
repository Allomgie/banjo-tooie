// Cube-grid set-up for a map: sizes and allocates the grid from the map bounds, reads node and
// actor props from the setup file, frees the grid, and runs per-cube passes (zones, counts).
#include "common.h"

typedef struct CubeListView {
    u64 *entries;
    u8 pad_4[0x20];
    s32 count;
} CubeListView;
extern void _gspropsDll_entrypoint_0(u64 *, u32 *, s32 *);
extern void _gspropsDll_entrypoint_1(u32 *, s32);
extern void *heap_alloc(s32);
extern void heap_free();
// The cube grid: 8 bytes per cube, indexed x + y * stride1 + z * stride2
typedef struct {
    void *data;
    s32 min[3];
    s32 max[3];
    u32 stride1;
    u32 stride2;
    u32 total;
    s32 size[3];
    u8 pad_34[8];
    s16 cube_size;
    s16 pad_3E;
    f32 inv_cube_size;
    void *aux;
} GCCube;
extern void func_800CD230(f32);
extern void func_800E9C44();
typedef struct {
    s32 unk_0, unk_4;
} CubeEnt;
typedef struct {
    CubeEnt *cubes;
    u8 pad_4[0x20];
    s32 count;
} CubeS;
extern void _gccollectDll_entrypoint_8(CubeEnt *);
extern void _gspropsDll_entrypoint_2(void *param_0, int param_1);
extern void func_800CB9FC(void);
extern void func_800CBA20(void);
extern void func_800CBA44(void);
int func_80800868_gccubeDll();

void gccubeDll_entrypoint_0(CubeListView *list)
{
    u64 *entry;
    s32 i;
    u32 table[499];
    s32 pad;
    s32 total;

    for (i = 0; i < 500; i++) {
        table[i] = 0;
    }
    total = 0;
    for (entry = list->entries; entry < list->count + list->entries; entry++) {
        _gspropsDll_entrypoint_0(entry, table, &total);
    }
    _gspropsDll_entrypoint_1(table, total);
}

// Read node props (0x14 bytes) and actor props (0xC bytes) of a cube from the setup stream
void func_808000B8_gccubeDll(void *reader, s32 skip)
{
    u8 count;
    s32 size;
    u8 *node_props;
    u8 *actor_props;
    s32 i;
    if (_gsmaker_entrypoint_17(reader, 0xA, &count)) {
        size = count * 0x14;
        node_props = heap_alloc(size);
        _gsmaker_entrypoint_18(reader, 0xB, node_props, count * 0x14);
        for (i = 0; i < count && skip == 0; i++)
            _gspropsDll_entrypoint_3(node_props + i * 0x14);
        heap_free(node_props);
    }
    if (_gsmaker_entrypoint_17(reader, 8, &count)) {
        i = 0;
        size = count * 0xC;
        actor_props = heap_alloc(size);
        _gsmaker_entrypoint_18(reader, 9, actor_props, count * 0xC);
        for (; i < count && skip == 0; i++)
            _gspropsDll_entrypoint_4(actor_props + i * 0xC);
        heap_free(actor_props);
    }
}

void func_80800230_gccubeDll(void *reader, s32 skip)
{
    s32 count;
    s32 i;
    u8 *node_props;
    u8 *actor_props;

    if (_gsmaker_entrypoint_21(reader, 0xA, &count)) {
        node_props = heap_alloc(count * 0x14);
        _gsmaker_entrypoint_8(reader, node_props, count * 0x14);
        for (i = 0; i < count && skip == 0; i++) {
            _gspropsDll_entrypoint_3(node_props + i * 0x14);
        }
        heap_free(node_props);
    }
    if (_gsmaker_entrypoint_21(reader, 8, &count)) {
        actor_props = heap_alloc(count * 0xC);
        _gsmaker_entrypoint_8(reader, actor_props, count * 0xC);
        for (i = 0; i < count && skip == 0; i++) {
            _gspropsDll_entrypoint_4(actor_props + i * 0xC);
        }
        heap_free(actor_props);
    }
}

void func_808003A0_gccubeDll(s32 reader, s32 skip)
{
    s8 pad[8];
    s32 unk_0;

    if (_gsmaker_entrypoint_16(reader, 1) == 0) {
        do {
            if (_gsmaker_entrypoint_22(reader, 0, &unk_0, 3) != 0) {
                _gsmaker_entrypoint_12(reader, &unk_0, 3);
            } else if ((_gsmaker_entrypoint_22(reader, 2, &unk_0, 3) == 0) &&
                       (_gsmaker_entrypoint_16(reader, 3) != 0)) {
                func_808000B8_gccubeDll(reader, skip);
            }
        } while (_gsmaker_entrypoint_16(reader, 1) == 0);
    }
}

// Size the grid from the map bounds and allocate it
void gccubeDll_entrypoint_1(GCCube *grid)
{
    extern void func_800CD23C();
    extern void func_800CD3A8();
    extern void func_800CD544();

    s32 cell[3];
    s32 rel[3];
    s32 i;
    GCCube *unused;

    grid->cube_size = _gcmapDll_entrypoint_5();
    grid->inv_cube_size = 1.0f / (f32) grid->cube_size;
    func_800BEC4C(grid->min, grid->max, grid->cube_size);
    // Matching: always-true wrapper needed for the match.
    if (1) {
        for (i = 0; i < 3; i++) {
            grid->size[i] = grid->max[i] - grid->min[i] + 1;
        }
    }
    grid->stride1 = grid->size[0];
    grid->stride2 = grid->size[1] * grid->stride1;
    grid->total = grid->size[2] * grid->stride2;
    grid->data = heap_alloc(grid->total << 3);
    grid->aux = heap_alloc(grid->total);
    for (cell[0] = grid->min[0]; cell[0] <= grid->max[0]; cell[0]++) {
        for (cell[1] = grid->min[1]; cell[1] <= grid->max[1]; cell[1]++) {
            for (cell[2] = grid->min[2]; cell[2] <= grid->max[2]; cell[2]++) {
                func_800EFB58(rel, cell, grid->min);
                // Matching: grid[0].stride2 spelling needed for the match.
                func_800E9E4C((u64 *) grid->data + rel[0] + rel[1] * grid->stride1 +
                                  rel[2] * grid[0].stride2,
                              cell);
            }
        }
    }
    func_800E9E4C(grid->pad_34, 0);
    func_800CD230(func_800EA05C() == 0xD7 ? 1000.0f : 200.0f);
    func_800C6A08(func_800CD23C, func_800CD3A8, func_800CD544);
    func_800CE2DC();
    func_800E9708();
}

// Free the grid cubes and the aux array
void gccubeDll_entrypoint_2(void *grid)
{
    u32 cube = *(u32 *) grid;
    if (cube < (u32) (cube + (((s32 *) ((char *) grid + 0x24))[0] * 8))) {
        do {
            func_800E9C44((void *) cube);
            cube += 8;
        } while (cube <
                 (u32) ((u32) ((u32 *) grid)[0] + (((s32 *) ((char *) grid + 0x24))[0] * 8)));
    }
    func_800E9C44((void *) ((char *) grid + 0x34));
    heap_free((void *) ((u32 *) grid)[0]);
    ((u32 *) grid)[0] = 0;
    heap_free((void *) ((u32 *) grid)[0x11]);
    ((u32 *) grid)[0x11] = 0;
}

void gccubeDll_entrypoint_3(void *arg0, void *reader)
{
    s32 cell[3];
    s32 min[3];
    s32 max[3];

    _gsmaker_entrypoint_22(reader, 1, min, 3);
    _gsmaker_entrypoint_12(reader, max, 3);
    for (cell[0] = min[0]; cell[0] <= max[0]; cell[0]++) {
        for (cell[1] = min[1]; cell[1] <= max[1]; cell[1]++) {
            for (cell[2] = min[2]; cell[2] <= max[2]; cell[2]++) {
                func_808003A0_gccubeDll(reader, 0);
            }
        }
    }
    _gsmaker_entrypoint_16(reader, 0);
    func_80800868_gccubeDll(arg0, reader);
}

s32 gccubeDll_entrypoint_4(s32 arg0, s32 reader)
{
    s32 reader_copy;
    s32 reader_copy2;
    // Matching: the temp assigned inside the expression and copied again is needed for the match.
    func_80800230_gccubeDll(reader_copy | (reader_copy = reader), 0);
    reader_copy2 = reader_copy;
    _gsmaker_entrypoint_16(reader, 1);
    func_80800868_gccubeDll(arg0, reader_copy2);
}

int func_80800868_gccubeDll(arg0, unused)
s32 arg0;
s32 unused;
{
    // Matching: xor with 0 needed for the match.
    func_800CE308(arg0 ^ 0);
}

void gccubeDll_entrypoint_5(CubeS *grid)
{
    s32 i;
    for (i = 0; i < grid->count; i++) {
        _gccollectDll_entrypoint_8(&grid->cubes[i]);
    }
}

void gccubeDll_entrypoint_6(void *grid)
{
    s32 i;

    i = 0;
    if (*(s32 *) ((char *) grid + 0x24) > 0) {
        do {
            _gspropsDll_entrypoint_2(*(s32 *) ((char *) grid + 0) + (i << 3), 0);
            i += 1;
        } while (i < *(s32 *) ((char *) grid + 0x24));
        i = 0;
    }
    func_800CBA20();
    if (*(s32 *) ((char *) grid + 0x24) > 0) {
        do {
            _gspropsDll_entrypoint_2(*(s32 *) ((char *) grid + 0) + (i << 3), 1);
            i += 1;
        } while (i < *(s32 *) ((char *) grid + 0x24));
    }
    func_800CB9FC();
    func_800CBA44();
}

u32 gccubeDll_entrypoint_7(void)
{
    u32 prop_end;
    u32 cube;
    u32 cube_end;
    u32 max_val;
    u32 prop;

    max_val = 0;
    func_800BE52C(&cube, &cube_end);
    while (cube < cube_end) {
        prop = func_800E9D68(cube);
        prop_end = func_800E9D90(cube);
        while (prop < prop_end) {
            if (max_val < (*(u32 *) (prop + 0x10) >> 21)) {
                max_val = *(u32 *) (prop + 0x10) >> 21;
            }
            prop += 0x14;
        }
        cube += 8;
    }
    return max_val;
}
