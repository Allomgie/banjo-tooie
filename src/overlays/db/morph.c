// Probably the model morph-target section: finds morph records by id, transforms flagged
// vertices with a bone matrix and applies weighted blend shapes (position, UV, colour).
#include "common.h"

typedef struct {
    u8 pad_0[0x16];
    u16 pad_1 : 15;
    u16 dirty : 1;
} DBMorphModel;
extern Vtx *func_800B2190(void *);
extern void *func_80100480(s32, s32);
extern void *func_800ADE2C(void *, s32);

// Finds the morph record with the given id, or returns 0.
u8 *func_80800000_dbmorph(section, id)
s16 *section;
s32 id;
{
    s32 i;
    u8 *record = (u8 *) (section + 2);
    for (i = 0; i < *section; i++) {

if (record[2] == id) {
    return record;
}

record += *(s32 *) (record + 8);
}
return 0;
}

s32 dbmorph_entrypoint_0(s32 section)
{
    return *(s16 *) (section + 0x2);
}

int dbmorph_entrypoint_1(s16 *section)
{
    return section[0];
}

u8 dbmorph_entrypoint_2(void)
{
    return *(u8 *) ((u8 *) func_80800000_dbmorph() + 3);
}

// Applies weighted morph targets to the flagged (0x4000) vertices. When dirty, the vertices
// are first reset from the base list.
void dbmorph_entrypoint_3(void *section, DBMorphModel *model, void *base_model, s32 morph_id,
                          f32 *weights)
{
    s16 du;
    f32 weight;
    s16 *vert_ids;
    s32 vert_id;
    u8 *target;
    Vtx *cur_verts;
    Vtx *delta;
    Vtx *cur;
    u8 *record;
    Vtx *base_verts;
    s32 cb;
    s16 dv;
    s32 cg;
    s32 cr;
    s32 i;
    s16 dx;
    s32 dirty;
    s16 dz;
    s16 dy;
    Vtx *base;
    s32 ca;
    s32 k = -1;

    dirty = model->dirty;

    record = func_80800000_dbmorph(section, morph_id);

    base_verts = func_800B2190(base_model);
    cur_verts = func_800B2190(model);

    base = *(s16 *) (record + 4) + base_verts;
    cur = *(s16 *) (record + 4) + cur_verts;

    if (dirty != 0) {
        i = *(s16 *) (record + 6);

if (i != 0) {
    do {
        if (base->v.flag & 0x4000) {
            aligned4_memcpy(cur, base, sizeof(Vtx));
            i--;
        }

        cur++;
        base++;
    } while (i != 0);
}

dirty = 0;
}

target = record + 0xC;

for (i = 0; i < record[3]; i++) {
    weight = *weights++;

if (weight != 0.0f) {
    delta = (Vtx *) (target + 4);
    vert_ids = (s16 *) (target + *(s16 *) target * 0x10 + 4);
    vert_id = *vert_ids;
    dx = (s16) (delta->v.ob[0] * weight);
    dy = (s16) (delta->v.ob[1] * weight);
    dz = (s16) (delta->v.ob[2] * weight);
    cr = delta->v.cn[0];
    cg = delta->v.cn[1];
    cb = delta->v.cn[2];
    ca = delta->v.cn[3];
    du = (s16) (delta->v.tc[0] * weight);
    dv = (s16) (delta->v.tc[1] * weight);

    dirty = 1;

    while (vert_id >= -1) {
        if (k == vert_id) {
            delta++;

            dx = (s16) (delta->v.ob[0] * weight);
            dy = (s16) (delta->v.ob[1] * weight);
            dz = (s16) (delta->v.ob[2] * weight);
            du = (s16) (delta->v.tc[0] * weight);
            dv = (s16) (delta->v.tc[1] * weight);

            cr = delta->v.cn[0];
            cg = delta->v.cn[1];
            cb = delta->v.cn[2];
            ca = delta->v.cn[3];
        } else {
            cur = cur_verts + vert_id;
            base = base_verts + vert_id;
            // Matching: the no-op multiply is needed for the match.
            vert_id *= 1;

            cur->v.ob[0] += dx;
            cur->v.ob[1] += dy;
            cur->v.ob[2] += dz;
            cur->v.tc[0] += du;
            cur->v.tc[1] += dv;

            cur->v.cn[0] += (cr - base->v.cn[0]) * weight;
            cur->v.cn[1] += (cg - base->v.cn[1]) * weight;
            cur->v.cn[2] += (cb - base->v.cn[2]) * weight;
            cur->v.cn[3] += (ca - base->v.cn[3]) * weight;
        }

        vert_id = *++vert_ids;
    }

    vert_ids++;
} else {

// Matching: the comma expression (0, target) is needed for the match.
vert_ids = (s16 *) (*(s16 *) target * 0x10 + (0, target) + 4);

while (-2 != *vert_ids++) {
}

}

if ((u32) vert_ids & 3) {
    vert_ids++;

}

target = (u8 *) vert_ids;
}

model->dirty = dirty;
}

// Transforms the flagged (0x4000) vertices of a morph record by its bone matrix.
void dbmorph_entrypoint_4(void *section, u8 *model, void *base_model, u32 morph_id, void *anim)
{
    s32 remaining;
    s16 *cursor;
    s16 *points;
    s32 count;
    Vtx *verts;
    Vtx *vtx;
    s16 *record;

    record = func_80800000_dbmorph(section, morph_id);
    count = record[3];
    verts = func_800B2190(model);

    if (*(u16 *) (model + 0x16) & 1)
        vtx = verts + record[2];
    else
        vtx = record[2] + func_800B2190(base_model);
    points = func_80100480(4, count);
    cursor = points;
    remaining = count;
    if (count) {
        do {
            if (vtx->v.flag & 0x4000) {
                *cursor++ = vtx->v.ob[0];
                *cursor++ = vtx->v.ob[1];
                *cursor++ = vtx->v.ob[2];
                remaining--;
            }

vtx++;

}
while (remaining)
    ;
}
remaining = count;
func_80116568(func_800ADE2C(anim, record[0]), points, points, count);
vtx = verts + record[2];
cursor = points;
if (count) {
    do {
        if (vtx->v.flag & 0x4000) {
            vtx->v.ob[0] = *cursor++;
            vtx->v.ob[1] = *cursor++;
            vtx->v.ob[2] = *cursor++;
            remaining--;
        }

vtx++;
}
while (remaining)
    ;
}
}
