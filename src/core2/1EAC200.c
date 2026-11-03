#include "common.h"

// Fog setup: per-map fog ranges, then per-layer prop counts of the cube grid.

// Per-map fog table entry; flags bit 0/1 enable fog range 0/1.
typedef struct {
    s16 map;
    u8 flags;
    u8 pad_3[13];
} LocalEntry;
typedef struct {
    u8 enabled, pad_1;
    s16 color[4];
    s16 pad_A;
    f32 near, far;
} LocalRange;
typedef struct {
    u8 enabled, status, pad_2[2];
    LocalRange range[2];
    s16 color[4];
} LocalState;
extern LocalState D_8012B320;
extern LocalEntry D_8011B530[];
extern s32 func_800EA05C(void);
typedef struct {
    u32 word0, word1;
} LocalGfx;
extern void *func_800A89F8(void);
extern void *func_800A9478(void *);
extern void *func_800A93E4(void *);
extern s32 func_800F6BE4(void *);
extern s32 func_8010FFD8(void *);
extern s32 func_800F0D90(s32, s32, s32);
extern void func_800E3CB8(f32 *, f32 *);
// Overlay of LocalState: status flag and the fog color at +0x2C.
typedef struct {
    u8 enabled;
    u8 status;
    u8 pad_2[42];
    s16 color[4];
} local_type;
extern u8 D_8012B321;
typedef struct {
    s32 pad[2];
} EntryD2CD0;
typedef struct {
    s16 *counts;
    s32 layer_count;
} StateD2CD0;
extern StateD2CD0 D_8012B360;
extern void func_800BE58C(s32 *, s32 *);
extern void *heap_alloc(s32);
extern void func_800BE52C(EntryD2CD0 **, s32 *);
extern s32 func_800E9D68(EntryD2CD0 *);
extern s32 func_800E9DC4(EntryD2CD0 *);
s32 defrag();
int func_800D2CC4();

// Enable fog range range_idx from a table entry.
void func_800D2910(s32 range_idx, u8 *entry)
{
    s32 idx = range_idx * 0x14;
    u8 *ptr = &((u8 *) &D_8012B320)[idx];

    ptr[4] = 1;
    *(s16 *) (ptr + 6) = *(u8 *) (entry + 0xC);
    *(s16 *) (ptr + 8) = entry[0xD];
    *(s16 *) (ptr + 0xA) = entry[0xE];
    *(s16 *) (ptr + 0xC) = entry[0xF];
    *(f32 *) &ptr[0x10] = *(f32 *) &entry[4];
    *(f32 *) &ptr[0x14] = *(f32 *) &entry[8];
    ((u8 *) &D_8012B320)[0]++;
}

void func_800D2970(void)
{
    D_8012B320.range[0].enabled = D_8012B320.range[1].enabled = 0;
    D_8012B320.status = 0;
    D_8012B320.enabled = 0;
}

void func_800D298C(void)
{
    LocalEntry *entry;
    s32 map_id;
    entry = D_8011B530;
    map_id = func_800EA05C();
    D_8012B320.range[1].enabled = D_8012B320.status = D_8012B320.enabled = 0;
    D_8012B320.range[0].enabled = 0;
    while (entry->map != -1) {
        if (entry->map == map_id) {
            if (entry->flags & 1)
                func_800D2910(0, entry);
            if (entry->flags & 2)
                func_800D2910(1, entry);
        }
        entry++;
    }
}

// Emit the RSP fog factor (multiplier/offset) for the active fog range.
void func_800D2A44(LocalGfx **gfx)
{
    f32 cam_near;
    f32 cam_far;
    f32 near_z;
    f32 far_z;
    s32 range_idx;
    void *env;
    s32 fog_mul;
    f32 fog_at_near;
    f32 fog_at_far;
    s32 fog_offset;
    f32 fog_near;
    f32 fog_far;
    LocalGfx *cmd;
    s32 fog_mul_clamped;
    f32 depth_range[1];
    if (D_8012B320.enabled) {
        env = func_800A9478(func_800A89F8());
        if (func_800F6BE4(env)) {
            range_idx = func_8010FFD8(func_800A93E4(env));
        } else {
            range_idx = 1;
        }
        if (D_8012B320.range[1].enabled && range_idx) {
            range_idx = 1;
        } else if (D_8012B320.range[0].enabled && !range_idx) {
            range_idx = 0;
        } else {
            return;
        }
        func_800E3CB8(&cam_near, &cam_far);
        near_z = cam_near;
        far_z = cam_far;
        depth_range[0] = far_z - near_z;
        if (far_z != near_z) {
            D_8012B320.color[0] = D_8012B320.range[range_idx].color[0];
            D_8012B320.color[1] = D_8012B320.range[range_idx].color[1];
            D_8012B320.color[2] = D_8012B320.range[range_idx].color[2];
            D_8012B320.color[3] = D_8012B320.range[range_idx].color[3];
            fog_near = D_8012B320.range[range_idx].near;
            fog_far = D_8012B320.range[range_idx].far;
            fog_offset = 0;
            if (far_z < fog_near) {
                fog_mul = 0;
            } else {
                far_z = (2.0f * far_z) / depth_range[0];
                fog_at_near = (1.0f - near_z / fog_near) * far_z - 1.0f;
                fog_at_far = (1.0f - near_z / fog_far) * far_z - 1.0f;
                far_z = 1.0f / (fog_at_far - fog_at_near);
                fog_mul = (s32) (256.0f * far_z);
                fog_offset = (s32) (-256.0f * fog_at_near * far_z);
            }
            cmd = (*gfx)++;
            cmd->word0 = 0xDB080000;
            fog_mul_clamped = func_800F0D90(fog_mul, -0x7FFF, 0x7FFF);
            cmd->word1 =
                (func_800F0D90(fog_offset, -0x7FFF, 0x7FFF) & 0xFFFF) | ((fog_mul_clamped & 0xFFFF) << 16);
            func_800D2CC4();
        }
    }
}

// Emit the fog color once until the status flag is cleared again.
void func_800D2C54(Gfx **gfx)
{
    if (!(*(local_type *) &D_8012B320).status) {
        gDPSetFogColor((*gfx)++, (*(local_type *) &D_8012B320).color[0],
                       (*(local_type *) &D_8012B320).color[1],
                       (*(local_type *) &D_8012B320).color[2],
                       (*(local_type *) &D_8012B320).color[3]);
        (*(local_type *) &D_8012B320).status = 1;
    }
}

int func_800D2CC4()
{
    D_8012B321 = 0;
}

// Count the props in each Y layer of the cube grid.
void func_800D2CD0(void)
{
    s32 cell[3];
    s32 dims[3];
    s32 strides[3];
    EntryD2CD0 *base;
    s32 unk_0;
    EntryD2CD0 *cube;
    s32 count;
    func_800BE58C(dims, strides);
    D_8012B360.layer_count = dims[1];
    D_8012B360.counts = heap_alloc(D_8012B360.layer_count * 2);
    for (count = 0; count < D_8012B360.layer_count; count++)
        *(s16 *) ((u8 *) D_8012B360.counts + (count << 1)) = 0;
    func_800BE52C(&base, &unk_0);
    for (cell[1] = 0; cell[1] < dims[1]; cell[1]++) {
        for (cell[0] = 0; cell[0] < dims[0]; cell[0]++) {
            for (cell[2] = 0; cell[2] < dims[2]; cell[2]++) {
                cube =
                    (cell[1] * strides[0]) + (cell[0] + (base + cell[2] * strides[1]));
                if (func_800E9D68(cube)) {
                    count = func_800E9DC4(cube);
                    *(s16 *) ((cell[1] << 1) + (u8 *) D_8012B360.counts) += count;
                }
            }
        }
    }
}

int func_800D2E4C()
{
    if (((void **) &D_8012B360)[0] != 0) {
        heap_free(((void **) &D_8012B360)[0]);
        ((void **) &D_8012B360)[0] = 0;
    }
    ((void **) &D_8012B360)[1] = 0;
}

// Whether the given Y layer contains any props.
u32 func_800D2E90(int layer)
{
    int has_props;

    if (layer < 0 || layer >= ((int *) &D_8012B360)[1]) {
        return 0;
    }
    if (*(s16 *) (((int *) &D_8012B360)[0] + layer * 2) != 0) {
        has_props = 1;
    } else {
        has_props = 0;
    }
    return has_props;
}

void func_800D2EE4()
{
    if (*(s32 *) &D_8012B360 != 0) {
        *(s32 *) &D_8012B360 = defrag(*(s32 *) &D_8012B360);
    }
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EAC200.data.s) is defined here in C.
// Values are taken from the ROM.
LocalEntry D_8011B530[3] = {0x181, 0x3,  0x0,  0x45, 0xCB, 0x20, 0x0,  0x46, 0x84, 0xD0, 0x0,  0x40,
                            0x40,  0x80, 0xC0, 0xFC, 0x3,  0x0,  0x45, 0x7A, 0x0,  0x0,  0x46, 0x8C,
                            0xA0,  0x0,  0xF,  0x3F, 0x53, 0x7F, -0x1, 0x0,  0x0,  0x0,  0x0,  0x0,
                            0x0,   0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
