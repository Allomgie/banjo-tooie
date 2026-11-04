// Builder for mesh-group instances (see gl/id): creates the per-model group structure from the
// model's id section, and computes a group's bounding box, centre and vertex count.
#include "common.h"

extern void *func_800D674C(s32);
extern void *func_800B274C(void *);
extern u8 *_dbid_entrypoint_2(void *, s32);
extern u8 *func_800B2190(s32);
extern void *heap_alloc(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24();
extern void aligned4_memcpy(void *, void *, s32);
void glidmake_entrypoint_2();

// Returns the instance transform at +8, or 0 for none.
int func_80800000_glidmake(s32 inst[3])
{
    s32 mtx;
    if (func_800EEEA8(inst + 2)) {
        // Matching: the `0 | 0` is needed for the match.
        mtx = 0 | 0;
    } else {
        mtx = inst + 2;
    }
    return mtx;
}

// Centre of the group's bounding box.
int glidmake_entrypoint_0(s16 inst[3], s16 group_id[3], s16 *center)
{
    s16 lo[3];
    s16 hi[3];
    glidmake_entrypoint_2(inst, group_id, lo, hi);
    center[0] = (lo[0] + hi[0]) / 2;
    center[1] = (lo[1] + hi[1]) / 2;
    center[2] = (lo[2] + hi[2]) / 2;
}

// Resolves the instance's model to its header sections.
int glidmake_entrypoint_1(s32 inst[3])
{
    s32 model;
    model = func_800D674C(inst[0]);
    func_800B274C(model | 0);
}

// Bounding box of the group's vertices, transformed when the instance has a transform.
void glidmake_entrypoint_2(inst, group_id, bbox_min, bbox_max) u8 *inst;
s32 group_id;
s16 *bbox_min;
s16 *bbox_max;
{
    s16 *idx;
    s16 *idx_end;
    u8 *id_group;
    u8 *verts;
    s16 *vtx;
    s32 axis;
    void *mtx;

    func_800EFD4C(bbox_min);
    func_800EFD4C(bbox_max);
    id_group = _dbid_entrypoint_2(func_800B274C(func_800D674C(*(s32 *) inst)), group_id);
    if (id_group != NULL) {
        verts = func_800B2190(*(s32 *) (inst + 0x14));
        idx = (s16 *) (id_group + 4);
        idx_end = (s16 *) (id_group + 4 + *(s16 *) (id_group + 2) * 2);
        while ((u32) idx < (u32) idx_end) {
            vtx = (s16 *) (verts + *idx * 16);
            for (axis = 0; axis < 3; axis++) {
                if (idx == (s16 *) (id_group + 4)) {
                    bbox_min[axis] = bbox_max[axis] = vtx[axis];
                } else {
                    bbox_min[axis] =
                        vtx[axis] < bbox_min[axis] ? vtx[axis] : bbox_min[axis];
                    bbox_max[axis] =
                        bbox_max[axis] < vtx[axis] ? vtx[axis] : bbox_max[axis];
                }
            }
            idx++;
        }
        mtx = func_80800000_glidmake(inst);
        if (mtx) {
            func_800EF0B4(bbox_min, mtx);
            func_800EF0B4(bbox_max, mtx);
        }
    }
}

// Vertex count of the group.
s16 glidmake_entrypoint_3(s32 *inst, s32 group_id)
{
    s16 count;
    u8 *id_group;

    id_group = _dbid_entrypoint_2(func_800B274C(func_800D674C(*inst)), group_id);
    if (id_group != NULL) {
        count = *(s16 *) ((char *) id_group + 2);
    } else {
        count = 0;
    }
    return count;
}

void glidmake_entrypoint_4(void *inst)
{
    heap_free(inst);
}

// Builds the mesh-group instance (see gl/id.c for the layout) from the model's 'id' section.
u8 *glidmake_entrypoint_5(s32 model_id, f32 *transform)
{
    s16 *section;
    u8 *vtx_list;
    u8 *inst;
    s16 *ids;
    s16 *group;
    s16 *run;
    s32 run_len;
    s32 i;
    s32 j;
    s32 run_start;
    s32 model;
    s32 size;
    u8 *chunk;
    u8 *copy;
    model = func_800D674C(model_id);
    section = (s16 *) func_800B274C(model);
    if (!section) {
        return NULL;
    }
    vtx_list = (u8 *) func_800B2840(model);
    size = *section * 8 + _dbid_entrypoint_1(section) * 0x10 + 0x1C;
    ids = section + 1;
    group = ids;
    for (i = 0; i < *section; i++) {
        size += _dbid_entrypoint_0(section, group[0]) * 4;
        group += group[1];
        group += 2;
    }
    group = ids;
    i = 0;
    inst = heap_alloc(size);
    *(s32 *) inst = model_id;
    *(s32 *) (inst + 4) = *section;
    if (transform) {
        func_800EE7F8((f32 *) (inst + 8), transform);
    } else {
        func_800EFD24((f32 *) (inst + 8));
    }
    *(u8 **) (inst + 0x14) = vtx_list;
    *(s32 *) (inst + 0x18) = 0;
    chunk = inst + 0x1C;
    for (; i < *section; i++) {
        ((s16 *) chunk)[0] = group[0];
        ((s16 *) chunk)[1] = _dbid_entrypoint_0(section, group[0]);
        run_len = 1;
        j = 1;
        run_start = group[2];
        run = (s16 *) (chunk + 8);
        copy = chunk + ((s16 *) chunk)[1] * 4 + 8;
        aligned4_memcpy(copy, vtx_list + run_start * 0x10 + 0x18, 0x10);
        copy += 0x10;
        ids = group + 1;
        for (; j < group[1]; j++) {
            if (ids[2] != ids[1] + 1) {
                run[0] = run_start;
                run[1] = run_len;
                run_len = 0;
                run += 2;
                run_start = ids[2];
            }
            aligned4_memcpy(copy, vtx_list + ids[2] * 0x10 + 0x18, 0x10);
            ids++;
            copy += 0x10;
            run_len++;
        }
        run[0] = run_start;
        run[1] = run_len;
        *(s32 *) (chunk + 4) = copy - chunk;
        group += group[1];
        group += 2;
        chunk = copy;
    }
    return inst;
}
