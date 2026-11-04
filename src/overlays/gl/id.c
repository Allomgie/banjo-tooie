// Vertex-group iteration for model meshes: calls a per-vertex callback for every vertex of a
// group, optionally with the original vertex copy, normals, or all groups; plus header setters.
#include "common.h"

// Instance layout (built by glidmake): +0 model, +4 chunk count, +0x14/+0x18 vertex lists,
// +0x1C chunks. Each chunk: group id, run count, size, runs of {first vertex, count},
// then a copy of the original vertices.
typedef struct GlIdChunk_glid_entrypoint_0 {
    s16 group_id;
    s16 item_count;
    s32 size;
} GlIdChunk_glid_entrypoint_0;
typedef struct GlIdItem_glid_entrypoint_0 {
    s16 first;
    s16 count;
} GlIdItem_glid_entrypoint_0;
extern void *func_800B2190(s32);

typedef struct {
    s16 group_id;
    s16 item_count;
    s32 size;
} GlIdChunk_glid_entrypoint_1;
typedef struct {
    s16 first;
    s16 count;
} GlIdItem_glid_entrypoint_1;
typedef struct {
    s16 position[3];
    u16 flags;
    s16 uv[2];
    u8 color[4];
} GlIdVertex;

// Calls callback for each vertex run of the group (with the original-vertex copy).
void glid_entrypoint_0(inst, group_id, callback, arg) u8 *inst;
s32 group_id;
void (*callback)(s32, void *, void *, s32, s32);
s32 arg;
{
    u8 *verts;
    GlIdChunk_glid_entrypoint_0 *chunk;
    GlIdItem_glid_entrypoint_0 *item;
    GlIdItem_glid_entrypoint_0 *item_end;
    u8 *orig;
    s32 i;

    verts = func_800B2190(*(s32 *) (inst + 0x14));
    chunk = (GlIdChunk_glid_entrypoint_0 *) (inst + 0x1C);
    for (i = 0; i < *(s32 *) (inst + 4); i++) {
        if (group_id == chunk->group_id) {
            item = (GlIdItem_glid_entrypoint_0 *) (chunk + 1);
            item_end = item + chunk->item_count;
            orig = (u8 *) item_end;
            for (; item < item_end; item++) {
                callback(chunk->group_id, orig, verts + item->first * 16,
                        item->count, arg);
                orig += item->count * 16;
            }
            break;
        }
        chunk = (GlIdChunk_glid_entrypoint_0 *) ((u8 *) chunk + chunk->size);
    }
}

// Like entrypoint_0, but passes the matching runs of both vertex lists.
void glid_entrypoint_1(inst, group_id, callback, arg) u8 *inst;
s32 group_id;
void (*callback)(void *, void *, void *, s32, s32);
s32 arg;
{
    GlIdChunk_glid_entrypoint_1 *chunk;
    GlIdItem_glid_entrypoint_1 *item;
    GlIdItem_glid_entrypoint_1 *item_end;
    u8 *verts;
    u8 *other_verts;
    u8 *orig;
    s32 i;
    s32 offset;

    verts = func_800B2190(*(s32 *) (inst + 0x14));
    other_verts = func_800B2190(*(s32 *) (inst + 0x18));
    chunk = (GlIdChunk_glid_entrypoint_1 *) (inst + 0x1C);
    for (i = 0; i < *(s32 *) (inst + 4); i++) {
        if (group_id == chunk->group_id) {
            item = (GlIdItem_glid_entrypoint_1 *) (chunk + 1);
            item_end = item + chunk->item_count;
            orig = (u8 *) item_end;
            for (; item < item_end; item++) {
                offset = item->first * 16;
                callback(orig, offset + verts, offset + other_verts, item->count, arg);
                orig += item->count * 16;
            }
            break;
        }
        chunk = (GlIdChunk_glid_entrypoint_1 *) ((u8 *) chunk + chunk->size);
    }
}

// Calls callback once per vertex of the group.
void glid_entrypoint_2(inst, group_id, callback, arg) u8 *inst;
s32 group_id;
s32 (*callback)(s16, u8 *, u8 *, s32);
s32 arg;
{
    u8 *verts;
    u8 *chunk;
    u8 *orig;
    u8 *vtx;
    u8 *vtx_end;
    s16 *run;
    s16 *run_end;
    s32 i;

    verts = func_800B2190(*(s32 *) (inst + 0x14));
    chunk = inst + 0x1C;
    for (i = 0; i < *(s32 *) (inst + 4); i++) {
        if (group_id == *(s16 *) chunk) {
            run = (s16 *) (chunk + 8);
            run_end = (s16 *) (chunk + *(s16 *) (chunk + 2) * 4 + 8);
            orig = (u8 *) run_end;
            for (; run < run_end; run += 2) {
                vtx = verts + run[0] * 16;
                vtx_end = vtx + run[1] * 16;
                for (; vtx < vtx_end; vtx += 16) {
                    callback(*(s16 *) chunk, orig, vtx, arg);
                    orig += 16;
                }
            }
            break;
        }
        chunk += *(s32 *) (chunk + 4);
    }
}

// Per-vertex callback for the group, also passing the vertex normals.
void glid_entrypoint_3(inst, group_id, callback, arg) u8 *inst;
s32 group_id;
void (*callback)(void *, void *, s32, void *);
s32 arg;
{
    u8 *verts;
    u8 *normal_src;
    u8 *chunk;
    u8 *run;
    u8 *run_end;
    u8 *orig;
    u8 *vtx;
    u8 *vtx_end;
    s32 i;
    u8 *normals;
    verts = (u8 *) func_800B2190(*(s32 *) (inst + 0x14));
    normal_src = (u8 *) func_800B27A0(func_800D674C(*(s32 *) inst));
    chunk = inst + 0x1C;
    for (i = 0; i < *(s32 *) (inst + 4); i++) {
        if (*(s16 *) chunk == group_id) {
            run = chunk + 8;
            run_end = chunk + 8 + *(s16 *) (chunk + 2) * 4;
            orig = run_end;
            while (run < run_end) {
                vtx = verts + *(s16 *) run * 16;
                vtx_end = vtx + *(s16 *) (run + 2) * 16;
                normals = (u8 *) _dbvtxnormal_entrypoint_0(normal_src, *(s16 *) run);
                while (vtx < vtx_end) {
                    callback(orig, vtx, arg, normals);
                    vtx += 16;
                    orig += 16;
                    normals += 4;
                }
                run += 4;
            }
            break;
        }
        chunk += *(s32 *) (chunk + 4);
    }
}

// Per-vertex callback over all groups.
void glid_entrypoint_4(inst, callback, arg) u8 *inst;
void (*callback)(s16, GlIdVertex *, GlIdVertex *, s32);
s32 arg;
{
    GlIdVertex *verts;
    u8 *chunk;
    GlIdVertex *orig;
    GlIdVertex *vtx;
    s32 i;
    GlIdVertex *vtx_end;
    s16 *run;
    s16 *run_end;

    verts = func_800B2190(*(s32 *) (inst + 0x14));
    chunk = inst + 0x1C;
    for (i = 0; i < *(s32 *) (inst + 4); i++) {
        run = (s16 *) (chunk + 8);
        run_end = (s16 *) (chunk + *(s16 *) (chunk + 2) * 4 + 8);
        orig = (GlIdVertex *) run_end;
        for (; run < run_end; run += 2) {
            vtx = verts + run[0];
            vtx_end = vtx + run[1];
            for (; vtx < vtx_end; vtx++) {
                callback(*(s16 *) chunk, orig, vtx, arg);
                orig++;
            }
        }
        chunk += *(s32 *) (chunk + 4);
    }
}

void glid_entrypoint_5(s32 *inst, s32 value)
{
    inst[5] = value;
}

void glid_entrypoint_6(void *inst, s32 value)
{
    // Matching: extra temporaries and the empty xor test are needed for the match.
    unsigned int slot_copy;
    unsigned int slot;
    slot = 6;
    slot_copy = slot;
    ((s32 *) inst)[slot_copy] = value;
    if (slot ^ 0) {
    }
}
