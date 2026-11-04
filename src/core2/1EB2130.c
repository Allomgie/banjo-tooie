// Most likely per-actor surface attachments: barycentric points on triangles of a deforming mesh,
// so a player standing on it can be repositioned next frame. Also a small static table lookup.
#include "common.h"

// TU-NOTE: the .data of this file is defined at the end in C, values taken from the ROM.
// D_8011B961 is a linker symbol (undefined_syms.us.txt) at D_8011B960 + 0x1.
// Surface attachments: freelist D_8012C020 of 0x70-byte blocks, each holding 4 records of 0x1C bytes.
extern float D_8011B964[];
extern u8 D_8011B961[3];
extern s32 D_8012C020;
extern void freelist_next();
typedef struct {
    s16 x;
    s16 y;
} pair16;
typedef union {
    s32 val;
    pair16 pair;
} local_1_type;
typedef struct {
    f32 weight_0, weight_1, point[3];
    s16 indices[3];
    u8 active;
} StateD89C8;
typedef struct {
    s16 xyz[3];
    u8 pad[10];
} VertexD89C8;
typedef struct {
    u8 pad[24];
    VertexD89C8 vertices[1];
} MeshD89C8;
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80019CD4(void);
extern void func_80019750(f32 *, f32 *, f32, f32 *);
extern void func_80019224(f32 *, f32 *);
typedef struct {
    f32 weights[2], point[3];
    s16 indices[3];
    u8 active, pad;
} LocalAttachment;
typedef struct {
    s16 xyz[3];
    u8 pad6[10];
} LocalVertex;
typedef struct {
    u8 pad0[0x18];
    LocalVertex vertices[1];
} LocalVertexList;
extern void func_8001980C(f32 *, f32 *, f32, f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 mlAbsF(f32);
extern f32 func_800EEF94(f32 *);
extern s32 D_8012C030;
s32 func_800D8988();

// Static per-index default float / flag table lookup.
// Accessors into a static table with an 8-byte stride.
float func_800D8840(s32 index)
{
    return *(f32 *) ((char *) D_8011B964 + index * 8);
}

int func_800D8854(s32 index)
{
    return D_8011B961[index * 8] & 1;
}

// Attachment block pool and barycentric recording / reconstruction of positions on mesh triangles.
void func_800D8870()
{
    D_8012C020 = freelist_new(0x70, 0);
}

s32 func_800D8898(void)
{
    freelist_free(D_8012C020);
    D_8012C020 = 0;
}

int func_800D88C0()
{
    if (D_8012C020 != 0) {
        D_8012C020 = freelist_defrag(D_8012C020);
    }
}

// Allocates a block of 4 attachment records, all inactive; returns its freelist index.
int func_800D88F8()
{
    local_1_type slot;
    s32 i;
    slot.val = 0;
    // freelist_next stores the new index into the union; pair.y is read back below.
    freelist_next((u8 *) &D_8012C020, &slot);
    for (i = 0; i < 4; i++) {
        u8 *record = func_800D8988(slot.pair.y, i);
        record[0x1a] = 0;
    }
    return slot.pair.y;
}

s32 func_800D8954(index)
s16 index;
{
    s32 block = index;
    freelist_erase(D_8012C020, block);
}

// Returns record `slot` (0x1C bytes each) of the block with the given freelist index.
s32 func_800D8988(index, slot)
s16 index;
s32 slot;
{
    return freelist_at(((u8 *) D_8012C020), index) + (slot * 0x1C);
}

// Rebuilds the attached point from the current triangle vertices into `point` (world space).
// Returns 0 if the record is inactive or the old point does not match cur_point.
s32 func_800D89C8(s16 block, s32 slot, f32 *pos, f32 *rot, f32 scale, f32 *param_5,
                  MeshD89C8 *mesh, f32 *cur_point, f32 *point)
{
    f32 edge1[3];
    f32 edge2[3];
    s32 i;
    s32 j;
    f32 tri[3][3];
    VertexD89C8 *vertex;
    StateD89C8 *attach;
    attach = func_800D8988(block, slot);
    if (!attach->active)
        return 0;
    attach->active = 0;
    if (func_800EEAD4(cur_point, attach->point) > 0.1f)
        return 0;
    for (i = 0; i < 3; i++) {
        vertex = attach->indices[i] + mesh->vertices;
        for (j = 0; j < 3; j++) {
            tri[i][j] = vertex->xyz[j];
        }
    }
    func_800EFB24(edge1, tri[1], tri[0]);
    func_800EFB24(edge2, tri[2], tri[0]);
    func_800EFA4C(point,
                  tri[0][0] + attach->weight_0 * edge1[0] + edge2[0] * attach->weight_1,
                  tri[0][1] + attach->weight_0 * edge1[1] + edge2[1] * attach->weight_1,
                  tri[0][2] + attach->weight_0 * edge1[2] + edge2[2] * attach->weight_1);
    func_80019CD4();
    func_80019750(pos, rot, scale, param_5);
    func_80019224(point, point);
    return 1;
}

// Stores `point` as barycentric weights on the triangle given by the vertex indices `tri_indices`.
void func_800D8B80(s16 block, s32 slot, f32 *pos, f32 *rot, f32 scale, f32 *param_5,
                   u16 *tri_indices, LocalVertexList *vertex_list, f32 *point)
{
    f32 edge1[3];
    f32 edge2[3];
    f32 local_point[3];
    f32 row_u[3];
    f32 row_v[3];
    s32 i;
    s32 j;
    LocalVertex *vertex;
    s32 axis;
    s32 axis_u;
    s32 axis_v;
    f32 normal[3];
    f32 tri[3][3];
    f32 scratch;
    LocalAttachment *attach;
    f32 abs_val;
    attach = func_800D8988(block, slot);
    func_800EE7F8(attach->point, point);
    func_80019CD4();
    func_8001980C(pos, rot, scale, param_5);
    func_80019224(local_point, point);
    for (i = 0; i < 3; i++)
        attach->indices[i] = tri_indices[i];
    for (i = 0; i < 3; i++) {
        vertex = vertex_list->vertices + attach->indices[i];
        for (j = 0; j < 3; j++)
            tri[i][j] = vertex->xyz[j];
    }
    func_800EFB24(edge1, tri[1], tri[0]);
    func_800EFB24(edge2, tri[2], tri[0]);
    func_800EE97C(normal, edge1, edge2);
    if (100000.0f < normal[0] || 100000.0f < normal[1] || 100000.0f < normal[2] ||
        normal[0] < (-100000.0f) || normal[1] < (-100000.0f) || normal[2] < (-100000.0f)) {
        normal[0] *= 0.00001f;
        normal[1] *= 0.00001f;
        normal[2] *= 0.00001f;
    }
    if (func_800EEF94(normal) < 0.001f) {
        attach->active = 0;
        return;
    }
    // Pick the dominant axis of the normal; the weights are solved in the other two.
    abs_val = mlAbsF(normal[0]);
    scratch = mlAbsF(normal[1]);
    axis = scratch < abs_val ? 0 : 1;
    abs_val = mlAbsF(normal[2]);
    scratch = mlAbsF(normal[axis]);
    if (scratch < abs_val)
        axis = 2;
    axis_u = (axis + 1) % 3;
    func_800EFA4C(row_u, local_point[axis_u] - tri[0][axis_u], edge1[axis_u],
                  edge2[axis_u]);
    axis_v = (axis + 2) % 3;
    func_800EFA4C(row_v, local_point[axis_v] - tri[0][axis_v], edge1[axis_v],
                  edge2[axis_v]);
    scratch = row_u[1] * row_v[2] - row_v[1] * row_u[2];
    attach->weights[0] = (row_u[0] * row_v[2] - row_v[0] * row_u[2]) / scratch;
    attach->weights[1] = (row_u[1] * row_v[0] - row_v[1] * row_u[0]) / scratch;
    attach->active = 1;
}

int func_800D8F40()
{
    return (int) &D_8012C030;
}

u32 D_8011B960[1] = {0x0};
float D_8011B964[11] = {0.0f,  2.3509887e-38f, 0.07f, 9.477423e-38f, 0.29f, 3.8203566e-37f,
                        0.15f, 1.5163877e-36f, 0.05f, 0.0f,          0.0f};
