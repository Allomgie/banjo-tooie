#include "common.h"

extern void *func_800B2190(s32);
extern void *func_80100480(s32, s32);
extern void *func_800ADE2C(void *, s32);

typedef struct {
    s16 pos[3];
    u8 unk_6[10];
} Mass47DBAnimVertex;

// Poses the skinned vertices: transforms each group's positions by its bone matrix and
// scatters them into the vertex list by index (-1 in the index list advances to the next point).
void dbanim_entrypoint_0(s16 *section, s32 model, void *anim)
{
    s16 *cursor;
    s32 i;
    s16 *group;
    s16 *points;
    s16 *src;
    u8 *verts;
    s16 *vtx;

    verts = func_800B2190(model);
    group = section + 2;
    for (i = 0; i < section[1]; i++) {
        points = func_80100480(4, group[1]);
        src = group + 3;
        func_80116568(func_800ADE2C(anim, group[0]), src, points, group[1]);
        cursor = src;
        cursor += group[1] * 3;
        if (section[0])
            cursor += group[2] * 2;
        while (*cursor >= -1) {
            if (*cursor == -1)
                points += 3;
            else {
                vtx = (s16 *) (verts + *cursor * 0x10);
                vtx[0] = points[0];
                vtx[1] = points[1];
                vtx[2] = points[2];
            }
            cursor++;
        }
        group = cursor + 1;
    }
    // Flush the modified vertices to RDRAM.
    osWritebackDCache(verts, func_800B2344(model) * 0x10);
}

// Like entrypoint_0, but also transforms the normals and writes them as signed 8-bit values.
void dbanim_entrypoint_1(s16 *section, s32 model, void *anim, u8 *normals)
{
    s16 *group;
    s16 *points;
    s16 *cursor;
    f32 *norms;
    Mass47DBAnimVertex *verts;
    Mass47DBAnimVertex *vtx;
    u8 *out;
    s32 i;
    s32 count;

    verts = func_800B2190(model);
    i = 0;
    group = section + 2;
    while (i < section[1]) {
        points = func_80100480(4, group[1]);
        cursor = group + 3;
        func_80116568(func_800ADE2C(anim, group[0]), cursor, points, group[1]);
        cursor += group[1] * 3;
        norms = func_80100480(2, group[2]);
        func_801163B0(cursor, func_800ADE2C(anim, group[0]), norms, group[2]);
        cursor += group[2] * 2;
        while (*cursor >= -1) {
            if (*cursor == -1) {
                points += 3;
            } else {
                vtx = verts + *cursor;
                vtx->pos[0] = points[0];
                vtx->pos[1] = points[1];
                vtx->pos[2] = points[2];
                norms += 3;
                out = normals + *cursor * 4;
                out[0] = (s32) (norms[-3] * 127.0f);
                out[1] = (s32) (norms[-2] * 127.0f);
                out[2] = (s32) (norms[-1] * 127.0f);
            }
            cursor++;
        }
        i++;
        group = cursor + 1;
    }
    count = func_800B2344(model);
    osWritebackDCache(verts, count * 16);
    osWritebackDCache(normals, count * 4);
}
