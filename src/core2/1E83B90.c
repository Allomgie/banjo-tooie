// Collision queries against a model's collision list: segment raycast, sphere sweep,
// sphere overlap. The last hit triangle's vertices and colors are cached in D_80127938.
// Wrappers transform the query into the local space of a rotated/scaled model.
#include "common.h"
#include "core2/1EC8070.h"
#include "core2/1ECB9F0.h"

typedef struct {
    s16 local_0[3];
    u8 pad[6];
    u8 local_1[4];
} VertexAA3B4;
typedef struct {
    f32 local_0[3][3];
    f32 local_1[3][4];
} BufferAA3B4;
typedef struct {
    s16 local_0[3], local_1[3];
    u16 local_2, local_3;
    s16 pad10, local_4;
    s32 pad14;
    u32 local_5[1];
} GridAA;
typedef struct {
    u32 *local_0[100];
    u32 **local_1;
} ListAA;
extern ListAA D_801277A0;
extern u32 *D_80127930[];
typedef struct {
    u8 pad[0x24];
    f32 local_0[3][4];
} ColorAAAE0;
extern void func_800EFB24(f32 *, f32 *, f32 *);
typedef struct {
    u16 start, count;
} ABGeo;
typedef struct {
    u16 vertex[3];
    u16 pad;
    u32 flags;
} ABTri;
typedef struct {
    s16 pos[3];
    u8 pad[10];
} ABVertex;
extern void *D_8012798C;
extern void *heap_alloc();
extern void heap_free(void *ptr);
typedef struct NodeABA20 {
    struct NodeABA20 *local_0;
    struct NodeABA20 *local_1;
} NodeABA20;
extern NodeABA20 *defrag(NodeABA20 *);
typedef struct {
    u16 start, count;
} LocalGeo;
typedef struct {
    u16 vertex[3], pad;
    u32 flags;
} LocalTri_800ABCE0;
typedef struct {
    f32 edge0[3], edge1[3], normal[3];
    LocalTri_800ABCE0 *tri;
    f32 points[3][3];
} LocalEntry;
typedef struct {
    u8 pad[0x10];
    LocalEntry entries[1];
} LocalBlock;
typedef struct {
    f32 edgeAB[3];
    f32 edgeAC[3];
    f32 normal[3];
    void *triangle;
    f32 vertices[3][3];
} LocalTriangle;
typedef struct LocalTriangleBlock {
    s32 first;
    struct LocalTriangleBlock *next;
    s32 capacity;
    s32 count;
    LocalTriangle triangles[1];
} LocalTriangleBlock;
typedef struct {
    u8 pad[0x24];
    void *local_0;
} HitAC638;
extern f32 D_80127938[][3];
extern f32 D_8012795C[];
extern void func_80019CD4(void);
extern void func_8001980C(f32 *, f32 *, f32, f32 *);
extern void func_80019750(f32 *, f32 *, f32, f32 *);
extern void func_80019224(f32 *, f32 *);
extern void func_800EF410(f32 *, f32 *);
typedef struct {
    u8 pad00[0x10];
    u16 groupCount;
} LocalModel;
typedef struct {
    u16 first, count;
} LocalGroup;
typedef struct {
    u16 index[3];
    u16 pad06;
    u32 flags;
} LocalTri_800AD2C8;
typedef struct {
    s16 position[3];
    u8 pad06[10];
} LocalVertex;
typedef struct {
    s16 position[3][3];
    s16 pad12;
} LocalCachedTri;
typedef struct {
    s16 position[3][3];
} LocalOutput;
extern struct {
    LocalCachedTri triangles[64];
    LocalCachedTri *end;
} D_80127990;
extern LocalVertex *func_800B2190(void *);
extern void func_800EFB58(s32 *, s32 *, s32 *);
typedef struct {
    u8 pad[0x10];
    u16 local_0;
} ModelAD894;
typedef struct {
    u16 local_0, local_1;
} GroupAD894;
typedef struct {
    u16 local_0[3];
    u8 pad[6];
} TriAD894;
typedef struct {
    s16 local_0[3];
    u8 pad[10];
} VertexAD894;
extern s32 func_800EED58(s32 *, s32 *);

// Group: grid cell lookup, triangle ray/sphere/sweep/ground queries, local wrappers, hit cache.
// Converts a position to clamped grid cell coordinates.
void func_800AA2A0(s16 *grid, s32 *cell, f32 *pos)
{
    s32 i;
    f32 coord;
    s16 *hdr;
    s32 whole;
    if (!grid[9]) {
        cell[2] = 0;
        cell[1] = 0;
        cell[0] = 0;
        return;
    }
    for (i = 0; i < 3; i++) {
        coord = pos[i];
        if (coord >= 0.0f) {
            whole = (s32) coord;
            cell[i] = whole / grid[9];
        } else {
            whole = (s32) coord;
            cell[i] = (whole / grid[9]) - 1;
        }
        // Matching: the extra copy of the grid pointer is needed for the match.
        hdr = grid;
        if (cell[i] < hdr[i]) {
            cell[i] = hdr[i];
        }
        if (cell[i] > hdr[i + 3]) {
            cell[i] = hdr[i + 3];
        }
    }
}

// Caches the triangle's vertex positions and colors in D_80127938.
void func_800AA3B4(u16 *tri, u8 *vtx_list)
{
    s32 i;
    s32 j;
    VertexAA3B4 *vertex;
    VertexAA3B4 *vertices;
    if (tri != 0) {
        vertices = (VertexAA3B4 *) (vtx_list + 0x18);
        for (i = 0; i < 3; i++) {
            vertex = vertices + tri[i];
            func_800EE88C((*(BufferAA3B4 *) D_80127938).local_0[i], vertex->local_0);
            for (j = 0; j < 4; j++) {
                (*(BufferAA3B4 *) D_80127938).local_1[i][j] =
                    (u32) vertex->local_1[j];
            }
        }
    }
}

// Lists the grid cells covered by a float bounding box (cell pointers go to D_801277A0).
void func_800AA4D4(GridAA *grid, f32 *min_pos, f32 *max_pos, u32 ***out_begin, u32 ***out_end)
{
    s32 cell_min[3];
    s32 cell_max[3];
    s32 axis;
    s32 z;
    s32 y;
    s32 x;
    s32 unk_0;
    if (!grid->local_4) {
        D_801277A0.local_1 = D_801277A0.local_0;
        *D_801277A0.local_1++ = grid->local_5;
        *out_begin = D_801277A0.local_0;
        *out_end = D_801277A0.local_1;
        return;
    }
    for (axis = 0; axis < 3; axis++) {
        if (min_pos[axis] >= 0.0f)
            cell_min[axis] = (s32) min_pos[axis] / grid->local_4;
        else
            cell_min[axis] = (s32) min_pos[axis] / grid->local_4 - 1;
        if (max_pos[axis] >= 0.0f)
            cell_max[axis] = (s32) max_pos[axis] / grid->local_4;
        else
            cell_max[axis] = (s32) max_pos[axis] / grid->local_4 - 1;
        if (cell_min[axis] < grid->local_0[axis])
            cell_min[axis] = grid->local_0[axis];
        if (cell_min[axis] > grid->local_1[axis])
            cell_min[axis] = grid->local_1[axis];
        if (cell_max[axis] < grid->local_0[axis])
            cell_max[axis] = grid->local_0[axis];
        if (cell_max[axis] > grid->local_1[axis])
            cell_max[axis] = grid->local_1[axis];
        cell_min[axis] -= grid->local_0[axis];
        cell_max[axis] -= grid->local_0[axis];
    }
    D_801277A0.local_1 = D_801277A0.local_0;
    for (z = cell_min[2]; z <= cell_max[2]; z++) {
        for (y = cell_min[1]; y <= cell_max[1]; y++) {
            for (x = cell_min[0]; x <= cell_max[0]; x++) {
                if (D_801277A0.local_1 < D_80127930) {
                    *D_801277A0.local_1 = (grid->local_3 * z + grid->local_5) +
                                          x + y * grid->local_2;
                    D_801277A0.local_1++;
                }
            }
        }
    }
    *out_begin = D_801277A0.local_0;
    *out_end = D_801277A0.local_1;
}

// Same as func_800AA4D4 for an integer bounding box.
void func_800AA7FC(GridAA *grid, s32 *min_pos, s32 *max_pos, u32 ***out_begin, u32 ***out_end)
{
    s32 cell_min[3];
    s32 cell_max[3];
    s32 axis;
    s32 z;
    s32 y;
    s32 x;
    s32 unk_0;
    if (!grid->local_4) {
        D_801277A0.local_1 = D_801277A0.local_0;
        *D_801277A0.local_1++ = grid->local_5;
        *out_begin = D_801277A0.local_0;
        *out_end = D_801277A0.local_1;
        return;
    }
    for (axis = 0; axis < 3; axis++) {
        if (min_pos[axis] >= 0)
            cell_min[axis] = (s32) min_pos[axis] / grid->local_4;
        else
            cell_min[axis] = (s32) min_pos[axis] / grid->local_4 - 1;
        if (max_pos[axis] >= 0)
            cell_max[axis] = (s32) max_pos[axis] / grid->local_4;
        else
            cell_max[axis] = (s32) max_pos[axis] / grid->local_4 - 1;
        if (cell_min[axis] < grid->local_0[axis])
            cell_min[axis] = grid->local_0[axis];
        if (cell_min[axis] > grid->local_1[axis])
            cell_min[axis] = grid->local_1[axis];
        if (cell_max[axis] < grid->local_0[axis])
            cell_max[axis] = grid->local_0[axis];
        if (cell_max[axis] > grid->local_1[axis])
            cell_max[axis] = grid->local_1[axis];
        cell_min[axis] -= grid->local_0[axis];
        cell_max[axis] -= grid->local_0[axis];
    }
    D_801277A0.local_1 = D_801277A0.local_0;
    for (z = cell_min[2]; z <= cell_max[2]; z++) {
        for (y = cell_min[1]; y <= cell_max[1]; y++) {
            for (x = cell_min[0]; x <= cell_max[0]; x++) {
                if (D_801277A0.local_1 < D_80127930) {
                    *D_801277A0.local_1 = (grid->local_3 * z + grid->local_5) +
                                          x + y * grid->local_2;
                    D_801277A0.local_1++;
                }
            }
        }
    }
    *out_begin = D_801277A0.local_0;
    *out_end = D_801277A0.local_1;
}

// Copies the cached vertex colors of the last hit triangle.
void func_800AAAE0(u8 colors[3][4])
{
    s32 i;
    s32 j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            colors[i][j] =
                (u32) (*(ColorAAAE0 *) D_80127938).local_0[i][j];
        }
    }
}

// Copies the cached vertex positions of the last hit triangle.
// Matching: the line breaks in this function are needed for the match.
void func_800AAD28(s32 out)
{
    u8 *src;
    u8 *src_end;
    s32 dst;
    src = (u8 *) D_80127938; src_end = (u8 *) D_8012795C;
    dst = out;
    do
    {
        func_800EE7F8(dst, src);
        src += 0xC;
        dst += 0xC;
    }
    while (src != src_end);
}

// Counts the triangles whose flags include 0x20020.
int func_800AAD80(u16 *list)
{
    s32 count;
    u32 tris;
    u32 tris_end;
    u32 *tri;
    count = 0;
    tris = ((u32) list + (list[8] * 4)) + 0x18;
    tris_end = tris + (list[10] * 0xC);
    tri = (u32 *) tris;
    while (tri < (u32 *) tris_end) {
        if (tri[2] & 0x20020) {
            count++;
        }
        tri = (u32 *) ((u32) tri + 12);
    }
    return count;
}

// Returns the triangle count of a collision list.
u16 func_800AADE4(u16 *list)
{
    return list[10];
}

// Group: pure geometry (point-to-line distance test, sphere-vs-segment test).
// Tests whether a point is closer to a segment than sqrt(radius_sq).
int func_800AADEC(f32 *seg_start, f32 *seg_end, f32 *point, f32 radius_sq)
{
    f32 dir[3];
    f32 to_point[3];
    f32 cross[3];
    f32 len_sq;
    f32 inv_len;
    func_800EFB24(dir, seg_end, seg_start);
    len_sq = func_800EEFD4(dir);
    if (len_sq < 0.01f)
        return func_800EEB40(seg_start, point) < radius_sq;
    inv_len = 1.0f / sqrtf(len_sq);
    dir[0] *= inv_len;
    dir[1] *= inv_len;
    dir[2] *= inv_len;
    func_800EFB24(to_point, point, seg_start);
    func_800EE97C(cross, to_point, dir);
    return func_800EEFD4(cross) < radius_sq;
}

int func_800AAEF4(f32 *point, f32 radius, f32 *seg_start, f32 *seg_end)
{
    f32 mid[3];
    f32 half_len_sq;
    f32 dist_sq;
    f32 radius_sq;
    radius_sq = radius * radius;
    if (!func_800AADEC(seg_start, seg_end, point, radius_sq))
        return 0;
    func_800EFA4C(mid, (seg_start[0] + seg_end[0]) * 0.5f, (seg_start[1] + seg_end[1]) * 0.5f,
                  (seg_start[2] + seg_end[2]) * 0.5f);
    dist_sq = func_800EEB40(mid, point);
    half_len_sq = func_800EEB40(mid, seg_start);
    if (half_len_sq + radius_sq + (2.0f * radius_sq) * half_len_sq <= dist_sq)
        return 0;
    return 1;
}

// Integer bounding box of a segment (padded by 1) and the segment's delta.
int func_800AAFEC(f32 start[3], f32 end[3], s32 *bbox_min, s32 *bbox_max, f32 *delta)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (start[i] < end[i]) {
            bbox_min[i] = start[i];
            bbox_max[i] = end[i];
        } else {
            bbox_min[i] = end[i];
            bbox_max[i] = start[i];
        }
        bbox_min[i]--;
        bbox_max[i]++;
    }

    func_800EFB24(delta, end, start);
}

// Segment raycast: returns the nearest hit triangle, moves end to the hit point and writes
// the unit hit normal to out_normal. Triangles with a flag in skip_mask are ignored.
ABTri *func_800AB0BC(u8 *coll, u8 *vtx_list, f32 *start, f32 *end, f32 *out_normal,
                     u32 skip_mask)
{
    s32 i;
    ABGeo **cell_begin;
    ABGeo **cell;
    ABGeo **cell_end;
    s32 drop_axis;
    s32 bbox_min[3];
    s32 bbox_max[3];
    f32 delta[3];
    s32 unk_0;
    ABTri *hit;
    ABTri *tri_begin;
    ABTri *tri;
    ABTri *tri_end;
    f32 edge1[3];
    f32 edge2[3];
    f32 rel_start[3];
    f32 rel_end[3];
    s32 unk_1;
    f32 hit_pos[3];
    f32 proj_a[3];
    f32 proj_b[3];
    f32 t;
    f32 plane_d;
    f32 inv_det;
    f32 u;
    f32 v;
    s32 unk_2;
    s32 unk_3;
    f32 normal[3];
    s32 unk_4;
    s32 unk_5;
    f32 verts[3][3];
    ABVertex *vertices;
    ABVertex *vtx0;
    ABVertex *vtx1;
    ABVertex *vtx2;
    s32 c0;
    s32 c1;
    s32 c2;

    hit = 0;
    // Reject segments outside the vertex-list extent before visiting cells.
    t = (f32) (u32) *(u16 *) (vtx_list + 0x14);
    func_800AAFEC(start, end, bbox_min, bbox_max, delta);
    for (i = 0; i < 3; i++) {
        if (bbox_max[i] <= -t || t <= bbox_min[i])
            return 0;
    }
    func_800AA7FC(coll, bbox_min, bbox_max, &cell_begin, &cell_end);
    for (cell = cell_begin; cell < cell_end; cell++) {
        tri_begin = (ABTri *) (coll + 0x18 + *(u16 *) (coll + 0x10) * 4) + (*cell)->start;
        tri_end = tri_begin + (*cell)->count;
        for (tri = tri_begin; tri < tri_end; tri++) {
            vertices = (ABVertex *) (vtx_list + 0x18);
            if (tri->flags & skip_mask)
                continue;
            vtx0 = &vertices[tri->vertex[0]];
            vtx1 = &vertices[tri->vertex[1]];
            vtx2 = &vertices[tri->vertex[2]];
            // Reject on each axis before converting that axis to float.
            c0 = vtx0->pos[0];
            c1 = vtx1->pos[0];
            c2 = vtx2->pos[0];
            if (c0 < bbox_min[0] && c1 < bbox_min[0] && c2 < bbox_min[0])
                continue;
            if (bbox_max[0] < c0 && bbox_max[0] < c1 && bbox_max[0] < c2)
                continue;
            verts[0][0] = c0;
            verts[1][0] = c1;
            verts[2][0] = c2;
            c0 = vtx0->pos[1];
            c1 = vtx1->pos[1];
            c2 = vtx2->pos[1];
            if (c0 < bbox_min[1] && c1 < bbox_min[1] && c2 < bbox_min[1])
                continue;
            if (bbox_max[1] < c0 && bbox_max[1] < c1 && bbox_max[1] < c2)
                continue;
            verts[0][1] = c0;
            verts[1][1] = c1;
            verts[2][1] = c2;
            c0 = vtx0->pos[2];
            c1 = vtx1->pos[2];
            c2 = vtx2->pos[2];
            if (c0 < bbox_min[2] && c1 < bbox_min[2] && c2 < bbox_min[2])
                continue;
            if (bbox_max[2] < c0 && bbox_max[2] < c1 && bbox_max[2] < c2)
                continue;
            verts[0][2] = c0;
            verts[1][2] = c1;
            verts[2][2] = c2;
            func_800EFB24(edge1, verts[1], verts[0]);
            func_800EFB24(edge2, verts[2], verts[0]);
            func_800EE97C(normal, edge1, edge2);
            // Rescaling a huge normal limits intermediate magnitudes.
            if (mlAbsF(normal[0]) > 100000.0f || mlAbsF(normal[1]) > 100000.0f ||
                mlAbsF(normal[2]) > 100000.0f) {
                normal[0] *= 0.00001f;
                normal[1] *= 0.00001f;
                normal[2] *= 0.00001f;
            }
            func_800EFB24(rel_start, start, verts[0]);
            func_800EFB24(rel_end, end, verts[0]);
            t = func_800EEAA4(rel_start, normal);
            plane_d = func_800EEAA4(rel_end, normal);
            if (t >= 0.0f && plane_d >= 0.0f)
                continue;
            if (t <= 0.0f && plane_d <= 0.0f)
                continue;
            // Flag 0x10000 (two-sided) flips the normal toward the start point.
            if ((tri->flags & 0x10000) && t < 0.0f) {
                normal[0] = -normal[0];
                normal[1] = -normal[1];
                normal[2] = -normal[2];
            }
            plane_d = -func_800EEAA4(verts[0], normal);
            t = func_800EEAA4(normal, delta);
            if (t >= 0.0f)
                continue;
            t = -(func_800EEAA4(normal, start) + plane_d) / t;
            if (t <= 0.0f || 1.0f <= t)
                continue;
            func_800EFA4C(hit_pos, start[0] + delta[0] * t,
                          start[1] + delta[1] * t, start[2] + delta[2] * t);
            // Drop the dominant normal axis and solve the 2D barycentric test.
            drop_axis = mlAbsF(normal[0]) > mlAbsF(normal[1]) ? 0 : 1;
            if (mlAbsF(normal[2]) > mlAbsF(normal[drop_axis]))
                drop_axis = 2;
            i = (drop_axis + 1) % 3;
            func_800EFA4C(proj_a, hit_pos[i] - verts[0][i], edge1[i],
                          edge2[i]);
            i = (drop_axis + 2) % 3;
            func_800EFA4C(proj_b, hit_pos[i] - verts[0][i], edge1[i],
                          edge2[i]);
            inv_det = 1.0f / (proj_a[1] * proj_b[2] - proj_b[1] * proj_a[2]);
            u = (proj_a[0] * proj_b[2] - proj_b[0] * proj_a[2]) * inv_det;
            if (u < 0.0f || 1.0f < u)
                continue;
            v = (proj_a[1] * proj_b[0] - proj_b[1] * proj_a[0]) * inv_det;
            if (v < 0.0f || 1.0f < v || 1.0f < u + v)
                continue;
            // Shortening the segment makes later accepted hits nearer.
            hit = tri;
            func_800EE7F8(end, hit_pos);
            func_800EE7F8(out_normal, normal);
            func_800AAFEC(start, end, bbox_min, bbox_max, delta);
        }
    }
    if (hit)
        func_800EF2A0(out_normal);
    func_800AA3B4(hit, vtx_list);
    return hit;
}

// Raycast against a model placed with pos/rot/scale; works in the model's local space.
// Matching: the line breaks in this function are needed for the match.
s32 func_800AB868(s32 coll, s32 vtx_list, f32 *pos, f32 *rot, f32 scale, s32 *start, s32 *end, s32 *out_normal, s32 skip_mask)
{
    f32 local_start[3];
    f32 local_end[3];
    s32 hit;
    s32 pad[2];
    s32 *vec;

    func_80019CD4();
    func_8001980C(pos, rot, scale, 0);
    func_800193C4(local_start, start);
    func_800193C4(local_end, end);
    hit = func_800AB0BC(coll, vtx_list, local_start, local_end, out_normal, skip_mask);
    if (hit == 0) {
        return 0;
    }
    func_80019CD4();
    func_80019750(pos, rot, scale, 0);
    func_800193C4(end, local_end);
    vec = (s32 *) D_80127938; do {
        func_80019224(vec, vec);
        vec += 3;
    } while (vec != (s32 *) D_8012795C);
    func_80019CD4();
    func_80019750(0, rot, 1.0f, 0);
    func_80019224(out_normal, out_normal);
    return hit;
}

// Group: chunked candidate-triangle scratch list used by the sweep query.
// Allocates the first block of the triangle scratch list.
void func_800AB980()
{
    D_8012798C = heap_alloc(0x484);
    ((struct {
        int unk0;
        int unk1;
        int unk3;
        int unk2;
    } *) D_8012798C)
        ->unk0 = 0;
    ((struct {
        int unk0;
        int unk1;
        int unk3;
        int unk2;
    } *) D_8012798C)
        ->unk1 = 0;
    ((struct {
        int unk0;
        int unk1;
        int unk3;
        int unk2;
    } *) D_8012798C)
        ->unk2 = 0xf;
    ((struct {
        int unk0;
        int unk1;
        int unk3;
        int unk2;
    } *) D_8012798C)
        ->unk3 = 0x40000000;
}

// Frees every block of the scratch list.
void func_800AB9D0()
{
    void *block = D_8012798C;
    while (block) {
        void *next = *((void **) block + 1);
        heap_free(block);
        block = next;
    }
    D_8012798C = 0;
}

// Group: defrag of the scratch chunk list and freeing chunks unused for 40 frames.
// Defragments the scratch blocks and relinks their neighbours.
void func_800ABA20(void)
{
    NodeABA20 *block;
    NodeABA20 *old_block;
    block = (NodeABA20 *) D_8012798C;
    while (block != 0) {
        old_block = block;
        block = defrag(block);
        if (block != old_block) {
            if (block->local_0 != 0)
                block->local_0->local_1 = block;
            else
                D_8012798C = block;
            if (block->local_1 != 0)
                block->local_1->local_0 = block;
        }
        block = block->local_1;
    }
}

// Frees trailing blocks whose stamp is older than 0x28 frames.
void func_800ABA9C()
{
    void *block;
    void *next;
    s32 cutoff;
    s32 cutoff_copy;
    next = func_8001211C();
    cutoff = (s32) next - 0x28;
    // Matching: the second copy of the cutoff is needed for the match.
    cutoff_copy = cutoff;
    block = *(void **) ((char *) D_8012798C + 4);
    if ((block != 0) && (cutoff < *(s32 *) ((char *) block + 8))) {
        do {
            block = *(void **) ((char *) block + 4);
            if (block == 0) {
                break;
            }
        } while (cutoff_copy < *(s32 *) ((char *) block + 8));
    }
    if (block != 0) {
        *(s32 *) ((char *) *(void **) ((char *) block + 0) + 4) = 0;
        if (block != 0) {
            do {
                next = *(void **) ((char *) block + 4);
                heap_free(block);
                block = next;
            } while (next != 0);
        }
    }
}

// Advances the entry cursor; moves to the next block (allocating it) when the block is full.
void func_800ABB34(s32 **cursor, s32 **block)
{
    s32 *next_block;

    *cursor = (s32 *) ((s8 *) *cursor + 0x4C);
    if (((s32) *cursor - (s32) *block - 0x10) / 0x4C >= *(s32 *) ((s8 *) *block + 0xC)) {
        next_block = *(s32 **) ((s8 *) *block + 4);
        if (next_block == NULL) {
            *(s32 **) ((s8 *) *block + 4) = heap_alloc(0xEE8, block);
            *(s32 **) (s8 *) *(s32 **) ((s8 *) *block + 4) = *block;
            *(s32 *) ((s8 *) *(s32 **) ((s8 *) *block + 4) + 4) = 0;
            *(s32 *) ((s8 *) *(s32 **) ((s8 *) *block + 4) + 0xC) = 0x32;
            next_block = *(s32 **) ((s8 *) *block + 4);
        }
        *block = next_block;
        *(s32 *) ((s8 *) *block + 8) = func_8001211C(next_block, block, cursor);
        *cursor = *block + 4;
    }
}

// Advances the entry cursor; moves to the next existing block when the block is exhausted.
void func_800ABC0C(s32 *cursor, s32 **block)
{
    *cursor = *cursor + 0x4C;
    if ((((*cursor - (s32) *block) - 0x10) / 0x4C) >= (*block)[3]) {
        *block = (*block)[1];
        *cursor = (s32) *block + 0x10;
    }
}

// Bounding box of a segment inflated by radius.
func_800ABC58(f32 *start, f32 *end, f32 radius, f32 *bbox_min, f32 *bbox_max)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        if (start[i] < end[i]) {
            bbox_min[i] = start[i];
            bbox_max[i] = end[i];
        } else {
            bbox_min[i] = end[i];
            bbox_max[i] = start[i];
        }
        bbox_min[i] -= radius;
        bbox_max[i] += radius;
    }
}

// Sphere sweep broad phase: collects the triangles near the swept segment that face against dir
// into the scratch list. out_end receives the end of the collected entries.
s32 func_800ABCE0(u8 *coll, u8 *vtx_list, f32 *start, f32 *end, f32 *dir, f32 radius,
                  u32 skip_mask, LocalEntry **out_end)
{
    LocalGeo **cell_begin;
    LocalGeo **cell;
    LocalGeo **cell_end;
    f32 rel[3];
    s32 i;
    s16 *vtx;
    f32 bbox_min[3];
    f32 bbox_max[3];
    s32 j;
    LocalTri_800ABCE0 *tri_begin;
    LocalTri_800ABCE0 *tri_end;
    LocalTri_800ABCE0 *tri;
    u8 *vertices;
    f32 tri_min[3];
    f32 tri_max[3];
    f32 extent;
    LocalBlock *block;
    LocalEntry *entry;
    func_800ABC58(start, end, radius, bbox_min, bbox_max);
    extent = *(u16 *) (vtx_list + 0x14);
    for (i = 0; i < 3; i++) {
        if (bbox_max[i] <= -extent || extent <= bbox_min[i])
            return 0;
    }
    func_800AA4D4(coll, bbox_min, bbox_max, &cell_begin, &cell_end);
    block = (LocalBlock *) D_8012798C;
    entry = block->entries;
    for (cell = cell_begin; cell < cell_end; cell++) {
        tri_begin = (LocalTri_800ABCE0 *) (coll + *(u16 *) (coll + 0x10) * 4 + 0x18) +
                  (*cell)->start;
        tri_end = tri_begin + (*cell)->count;
        for (tri = tri_begin; tri < tri_end; tri++) {
            vertices = vtx_list + 0x18;
            if (tri->flags & skip_mask)
                continue;
            for (i = 0; i < 3; i++) {
                vtx = (s16 *) (vertices + tri->vertex[i] * 0x10);
                func_800EE88C(entry->points[i], vtx);
            }
            func_800EE7F8(tri_min, entry->points[0]);
            func_800EE7F8(tri_max, entry->points[0]);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (entry->points[i][j] < tri_min[j])
                        tri_min[j] = entry->points[i][j];
                    if (tri_max[j] < entry->points[i][j])
                        tri_max[j] = entry->points[i][j];
                }
            }
            if (bbox_max[0] < tri_min[0] || tri_max[0] < bbox_min[0])
                continue;
            if (bbox_max[1] < tri_min[1] || tri_max[1] < bbox_min[1])
                continue;
            if (bbox_max[2] < tri_min[2] || tri_max[2] < bbox_min[2])
                continue;
            func_800EFB24(entry->edge0, entry->points[1], entry->points[0]);
            func_800EFB24(entry->edge1, entry->points[2], entry->points[0]);
            func_800EE97C(entry->normal, entry->edge0, entry->edge1);
            func_800EF2A0(entry->normal);
            if (tri->flags & 0x10000) {
                func_800EFB24(rel, start, entry->points[0]);
                if (func_800EEAA4(rel, entry->normal) < 0.0f) {
                    entry->normal[0] = -entry->normal[0];
                    entry->normal[1] = -entry->normal[1];
                    entry->normal[2] = -entry->normal[2];
                }
            }
            if (func_800EEAA4(entry->normal, dir) > 0.0f)
                continue;
            entry->tri = tri;
            func_800ABB34(&entry, &block);
        }
    }
    *out_end = entry;
    return entry != ((LocalBlock *) D_8012798C)->entries;
}

// Tests a sphere against the collected triangles. Returns the last one touched and sums the
// normals of all touched triangles into out_normal. `end` marks the end of the entries.
LocalTriangle *func_800AC100(LocalTriangle *end, f32 *center, f32 radius, f32 *out_normal)
{
    s32 i;
    LocalTriangleBlock *block;
    LocalTriangle *entry;
    f32 edges[3][3];
    f32 to_vert[3][3];
    f32 radius_sq;
    f32 along;
    f32 v;
    f32 u;
    f32 plane_dist;
    f32 edge_len_sq;
    f32 proj_a[3];
    f32 proj_b[3];
    u32 unk_0;
    s32 unk_1;
    s32 drop_axis;
    f32 proj_pt[3];
    LocalTriangle *hit;
    f32 inv_det;

    hit = NULL;
    radius_sq = radius * radius;
    func_800EFD24(out_normal);
    block = (LocalTriangleBlock *) D_8012798C;
    for (entry = block->triangles; entry != end; func_800ABC0C(&entry, &block)) {
        func_800EFB24(to_vert[0], center, entry->vertices[0]);
        plane_dist = func_800EEAA4(to_vert[0], entry->normal);
        if (radius - 0.5f <= mlAbsF(plane_dist))
            continue;

        proj_pt[0] = center[0] - entry->normal[0] * plane_dist;
        proj_pt[1] = center[1] - entry->normal[1] * plane_dist;
        proj_pt[2] = center[2] - entry->normal[2] * plane_dist;
        drop_axis = mlAbsF(entry->normal[0]) > mlAbsF(entry->normal[1]) ? 0 : 1;
        if (mlAbsF(entry->normal[2]) > mlAbsF(entry->normal[drop_axis]))
            drop_axis = 2;

        func_800EFA4C(proj_a,
                      proj_pt[(drop_axis + 1) % 3] - entry->vertices[0][(drop_axis + 1) % 3],
                      entry->edgeAB[(drop_axis + 1) % 3], entry->edgeAC[(drop_axis + 1) % 3]);
        func_800EFA4C(proj_b,
                      proj_pt[(drop_axis + 2) % 3] - entry->vertices[0][(drop_axis + 2) % 3],
                      entry->edgeAB[(drop_axis + 2) % 3], entry->edgeAC[(drop_axis + 2) % 3]);
        inv_det = proj_a[1] * proj_b[2] - proj_b[1] * proj_a[2];
        if (inv_det == 0.0f)
            continue;
        inv_det = 1.0f / inv_det;
        u = (proj_a[0] * proj_b[2] - proj_b[0] * proj_a[2]) * inv_det;
        v = (proj_a[1] * proj_b[0] - proj_b[1] * proj_a[0]) * inv_det;
        if (0.0f <= u && u <= 1.0f && 0.0f <= v && v <= 1.0f)
            if (u + v <= 1.0f) {
                hit = entry;
                func_800EF04C(out_normal, entry->normal);
                continue;
            }
        for (i = 0; i < 3; i++) {
            func_800EFB24(to_vert[i], center, entry->vertices[i]);
            if (func_800EEFD4(to_vert[i]) < radius_sq) {
                hit = entry;
                func_800EF04C(out_normal, entry->normal);
                break;
            }
        }
        if (i < 3)
            continue;
        for (i = 0; i < 3; i++) {
            func_800EFB24(edges[i], entry->vertices[(i + 1) % 3],
                          entry->vertices[i]);
            edge_len_sq = func_800EEFD4(edges[i]);
            func_800EF2A0(edges[i]);
            along = func_800EEAA4(edges[i], to_vert[i]);
            if (0 <= along && along * along <= edge_len_sq) {
                proj_pt[0] = to_vert[i][0] - edges[i][0] * along;
                proj_pt[1] = to_vert[i][1] - edges[i][1] * along;
                proj_pt[2] = to_vert[i][2] - edges[i][2] * along;
                if (func_800EEFD4(proj_pt) < radius_sq) {
                    hit = entry;
                    func_800EF04C(out_normal, entry->normal);
                    break;
                }
            }
        }
    }
    return hit;
}

// Sphere sweep from start to end: bisects the segment `steps` times to find the last free
// position (written to end) and the touched triangle's normal (out_normal).
void *func_800AC638(void *coll, void *vtx_list, f32 *start, f32 *end, f32 radius,
                    f32 *out_normal, s32 steps, u32 skip_mask)
{
    void *entries_end;
    f32 delta[3];
    f32 lo, hi, mid;
    s32 i;
    f32 mid_pos[3];
    f32 normal[3];
    HitAC638 *hit;
    HitAC638 *mid_hit;
    f32 dir[3];
    func_800EFB24(dir, end, start);
    if (!func_800ABCE0(coll, vtx_list, start, end, dir, radius + 0.5f, skip_mask,
                       &entries_end))
        return 0;
    hit = func_800AC100(entries_end, end, radius, normal);
    if (!hit)
        return 0;
    func_800EE7F8(out_normal, normal);
    func_800EFB24(delta, end, start);
    func_800EE7F8(end, start);
    lo = 0.0f;
    hi = 1.0f;
    for (i = 0; i < steps; i++) {
        mid = (lo + hi) * 0.5f;
        mid_pos[0] = start[0] + delta[0] * mid;
        mid_pos[1] = start[1] + delta[1] * mid;
        mid_pos[2] = start[2] + delta[2] * mid;
        mid_hit = func_800AC100(entries_end, mid_pos, radius, normal);
        if (mid_hit) {
            hi = mid;
            hit = mid_hit;
            func_800EE7F8(out_normal, normal);
        } else {
            lo = mid;
            func_800EE7F8(end, mid_pos);
        }
    }
    if (!hit)
        return 0;
    func_800EF2A0(out_normal);
    func_800AA3B4(hit->local_0, vtx_list);
    return hit->local_0;
}

// Sphere sweep against a model placed with pos/rot/scale; works in the model's local space.
s32 func_800AC848(s32 coll, s32 vtx_list, f32 *pos, f32 *rot, f32 scale, f32 *start,
                  f32 *end, f32 radius, f32 *out_normal, s32 steps, s32 skip_mask)
{
    f32 local_start[3];
    f32 local_end[3];
    s32 i;
    s32 hit;
    func_80019CD4();
    func_8001980C(pos, rot, scale, 0);
    func_80019224(local_start, start);
    func_80019224(local_end, end);
    hit = func_800AC638(coll, vtx_list, local_start, local_end, radius / scale, out_normal, steps,
                            skip_mask);
    if (!hit)
        return 0;
    func_80019CD4();
    func_80019750(pos, rot, scale, 0);
    func_80019224(end, local_end);
    for (i = 0; i < 3; i++)
        func_80019224(D_80127938[i], D_80127938[i]);
    func_80019CD4();
    func_80019750(0, rot, 1.0f, 0);
    func_80019224(out_normal, out_normal);
    return hit;
}

// Sphere overlap: returns the last touched triangle and sums the touched normals into
// out_normal.
ABTri *func_800AC978(u8 *coll, u8 *vtx_list, f32 *center, f32 radius, f32 *out_normal, s32 skip_mask)
{
    ABGeo **cell_begin;
    ABGeo **cell;
    ABGeo **cell_end;
    s32 i;
    f32 bbox_min[3];
    f32 bbox_max[3];
    s32 j;
    f32 normal_sum[3];
    ABTri *hit;
    ABTri *tri_begin;
    u8 *vertices;
    u16 *vtx;
    ABTri *tri;
    ABTri *tri_end;
    f32(*unk_0)[3];
    f32 v;
    f32 plane_dist;
    f32 edges[3][3];
    f32 to_vert[3][3];
    f32 inv_det;
    f32 u;
    f32 unk_1;
    f32 normal[3];
    f32 proj_a[3];
    f32 proj_b[3];
    f32 edge_len_sq;
    f32 along;
    s32 drop_axis;
    f32 tri_min[3];
    f32 tri_max[3];
    f32 proj_pt[3];
    f32 verts[3][3];
    f32 radius_sq;

    // Broad phase: expand the sphere bounds, then reject the entire model.
    for (i = 0; i < 3; i++) {
        bbox_min[i] = center[i] - (radius + 0.5f);
        bbox_max[i] = center[i] + (radius + 0.5f);
    }
    v = *(u16 *) (vtx_list + 0x14);
    for (i = 0; i < 3; i++) {
        if (bbox_max[i] <= -v || v <= bbox_min[i])
            return 0;
    }
    hit = 0;
    func_800EFD24(normal_sum);
    func_800AA4D4(coll, bbox_min, bbox_max, &cell_begin, &cell_end);
    for (cell = cell_begin; cell < cell_end; cell++) {
        tri_begin = (ABTri *) (coll + 0x18 + *(u16 *) (coll + 0x10) * 4) + (*cell)->start;
        tri_end = tri_begin + (*cell)->count;
        for (tri = tri_begin; tri < tri_end; tri++) {
            if (tri->flags & skip_mask)
                continue;
            vertices = vtx_list + 0x18;
            for (i = 0; i < 3; i++) {
                vtx = (u16 *) (vertices + tri->vertex[i] * 0x10);
                func_800EE88C(verts[i], (s16 *) vtx);
            }
            func_800EE7F8(tri_min, verts[0]);
            func_800EE7F8(tri_max, verts[0]);
            for (i = 1; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (verts[i][j] < tri_min[j])
                        tri_min[j] = verts[i][j];
                    if (tri_max[j] < verts[i][j])
                        tri_max[j] = verts[i][j];
                }
            }
            if (bbox_max[0] < tri_min[0] || tri_max[0] < bbox_min[0])
                continue;
            if (bbox_max[1] < tri_min[1] || tri_max[1] < bbox_min[1])
                continue;
            if (bbox_max[2] < tri_min[2] || tri_max[2] < bbox_min[2])
                continue;
            func_800EFB24(edges[0], verts[1], verts[0]);
            func_800EFB24(edges[1], verts[2], verts[0]);
            func_800EE97C(normal, edges[0], edges[1]);
            func_800EF2A0(normal);
            // Reject degenerate triangles; orient two-sided faces toward the center.
            if (normal[0] == 0.0f && normal[1] == 0.0f && normal[2] == 0.0f)
                continue;
            func_800EFB24(to_vert[0], center, verts[0]);
            if ((tri->flags & 0x10000) && func_800EEAA4(to_vert[0], normal) < 0) {
                normal[0] = -normal[0];
                normal[1] = -normal[1];
                normal[2] = -normal[2];
            }
            plane_dist = func_800EEAA4(to_vert[0], normal);
            if (radius - 0.5f <= mlAbsF(plane_dist))
                continue;
            proj_pt[0] = center[0] - normal[0] * plane_dist;
            proj_pt[1] = center[1] - normal[1] * plane_dist;
            proj_pt[2] = center[2] - normal[2] * plane_dist;
            drop_axis = mlAbsF(normal[0]) > mlAbsF(normal[1]) ? 0 : 1;
            if (mlAbsF(normal[2]) > mlAbsF(normal[drop_axis]))
                drop_axis = 2;
            i = (drop_axis + 1) % 3;
            func_800EFA4C(proj_a, proj_pt[i] - verts[0][i], edges[0][i],
                          edges[1][i]);
            i = (drop_axis + 2) % 3;
            func_800EFA4C(proj_b, proj_pt[i] - verts[0][i], edges[0][i],
                          edges[1][i]);
            inv_det = 1.0f / (proj_a[1] * proj_b[2] - proj_b[1] * proj_a[2]);
            u = (proj_a[0] * proj_b[2] - proj_b[0] * proj_a[2]) * inv_det;
            if (u >= 0 && u <= 1.0f) {
                // Matching: the copy through v is needed for the match.
                v = proj_b[0];
                v = (proj_a[1] * v - proj_b[1] * proj_a[0]) * inv_det;
                if (v >= 0 && v <= 1.0f && u + v <= 1.0f) {
                    hit = tri;
                    func_800EF04C(normal_sum, normal);
                    continue;
                }
            }
            // Outside the face: test the three vertices, then the edge segments.
            radius_sq = radius * radius;
            for (i = 0; i < 3; i++) {
                func_800EFB24(to_vert[i], center, verts[i]);
                if (func_800EEFD4(to_vert[i]) < radius_sq) {
                    hit = tri;
                    func_800EF04C(normal_sum, normal);
                    break;
                }
            }
            if (i < 3)
                continue;
            for (i = 0; i < 3; i++) {
                func_800EFB24(edges[i], verts[(i + 1) % 3], verts[i]);
                edge_len_sq = func_800EEFD4(edges[i]);
                func_800EF2A0(edges[i]);
                along = func_800EEAA4(edges[i], to_vert[i]);
                if (along >= 0.0f && along * along <= edge_len_sq) {
                    proj_pt[0] = to_vert[i][0] - edges[i][0] * along;
                    proj_pt[1] = to_vert[i][1] - edges[i][1] * along;
                    proj_pt[2] = to_vert[i][2] - edges[i][2] * along;
                    if (func_800EEFD4(proj_pt) < radius_sq) {
                        hit = tri;
                        func_800EF04C(normal_sum, normal);
                        break;
                    }
                }
            }
        }
    }
    if (hit != 0)
        func_800EF410(out_normal, normal_sum);
    func_800AA3B4(hit, vtx_list);
    return hit;
}

// Sphere overlap against a model placed with pos/rot/scale; works in the model's local space.
s32 func_800AD1AC(s32 coll, s32 vtx_list, f32 *pos, f32 *rot, f32 scale, f32 *center,
                  f32 radius, f32 *out_normal, s32 skip_mask)
{
    f32 local_center[3];
    s32 i;
    s32 hit;
    s32 unk_0;
    func_80019CD4();
    func_8001980C(pos, rot, scale, 0);
    func_80019224(local_center, center);
    hit = func_800AC978(coll, vtx_list, local_center, radius / scale, out_normal, skip_mask);
    if (!hit)
        return 0;
    func_80019CD4();
    func_80019750(pos, rot, scale, 0);
    func_80019224(center, local_center);
    for (i = 0; i < 3; i++)
        func_80019224(D_80127938[i], D_80127938[i]);
    func_80019CD4();
    func_80019750(0, rot, 1.0f, 0);
    func_80019224(out_normal, out_normal);
    return hit;
}

// Collects up-facing triangles inside the segment's bounds into out; returns how many were written.
s32 func_800AD2C8(LocalModel *col_list, void *model, f32 *seg_start, f32 *seg_end, f32 *origin,
                  LocalOutput **out, s32 max_count, f32 min_normal_y)
{
    s32 i;
    s32 j;
    s32 num_out = 0;
    LocalGroup **group_begin;
    LocalGroup **group_end;
    LocalGroup **group_it;
    LocalVertex *vertices;
    LocalTri_800AD2C8 *tri_end;
    LocalTri_800AD2C8 *tri;
    s32 box_min[3];
    s32 box_max[3];
    s32 origin_i[3];
    s32 tri_min[3];
    s32 tri_max[3];
    s32 tri_pos[3][3];
    s32 edge_ab[3];
    s32 edge_ac[3];
    LocalCachedTri *cached;
    LocalVertex *vtx;
    LocalTri_800AD2C8 *tri_start;
    f32 normal[3];

    for (i = 0; i < 3; i++) {
        box_min[i] = seg_start[i] - origin[i];
        box_max[i] = seg_end[i] - origin[i];
        origin_i[i] = origin[i];
    }
    func_800AA7FC(col_list, box_min, box_max, &group_begin, &group_end);
    vertices = func_800B2190(model);
    D_80127990.end = D_80127990.triangles;
    for (group_it = group_begin; group_it < group_end; group_it++) {
        tri_start = (LocalTri_800AD2C8 *) ((u8 *) col_list + col_list->groupCount * 4 + 0x18) +
                   (*group_it)->first;
        tri_end = tri_start + (*group_it)->count;
        for (tri = tri_start; num_out < max_count && tri < tri_end; tri++) {
            if (tri->flags & 0x20020) // flags 0x20020 are skipped
                continue;
            vtx = vertices + tri->index[0];
            tri_min[0] = tri_max[0] = vtx->position[0];
            tri_min[1] = tri_max[1] = vtx->position[1];
            tri_min[2] = tri_max[2] = vtx->position[2];
            func_800EE8CC(tri_pos[0], vtx->position);
            for (i = 1; i < 3; i++) {
                vtx = vertices + tri->index[i];
                for (j = 0; j < 3; j++) {
                    if (vtx->position[j] < tri_min[j])
                        tri_min[j] = vtx->position[j];
                    if (tri_max[j] < vtx->position[j])
                        tri_max[j] = vtx->position[j];
                }
                func_800EE8CC(tri_pos[i], vtx->position);
            }
            if (tri_max[0] < box_min[0] || box_max[0] < tri_min[0])
                continue;
            if (tri_max[1] < box_min[1] || box_max[1] < tri_min[1])
                continue;
            if (tri_max[2] < box_min[2] || box_max[2] < tri_min[2])
                continue;
            // Skip triangles already in the shared cache.
            for (cached = D_80127990.triangles; cached < D_80127990.end; cached++) {
                if (tri_pos[0][0] == cached->position[0][0] &&
                    tri_pos[0][1] == cached->position[0][1] &&
                    tri_pos[0][2] == cached->position[0][2] &&
                    tri_pos[1][0] == cached->position[1][0] &&
                    tri_pos[1][1] == cached->position[1][1] &&
                    tri_pos[1][2] == cached->position[1][2] &&
                    tri_pos[2][0] == cached->position[2][0] &&
                    tri_pos[2][1] == cached->position[2][1] &&
                    tri_pos[2][2] == cached->position[2][2])
                    break;
            }
            if (cached != D_80127990.end)
                continue;
            func_800EFB58(edge_ab, tri_pos[1], tri_pos[0]);
            func_800EFB58(edge_ac, tri_pos[2], tri_pos[0]);
            func_800EE9EC(normal, edge_ab, edge_ac);
            if (normal[1] <= 0.0f)
                continue;
            func_800EF2A0(normal);
            if (normal[1] < min_normal_y) // too steep
                continue;
            if (D_80127990.end - D_80127990.triangles < 64) {
                D_80127990.end->position[0][0] = tri_pos[0][0];
                D_80127990.end->position[0][1] = tri_pos[0][1];
                D_80127990.end->position[0][2] = tri_pos[0][2];
                D_80127990.end->position[1][0] = tri_pos[1][0];
                D_80127990.end->position[1][1] = tri_pos[1][1];
                D_80127990.end->position[1][2] = tri_pos[1][2];
                D_80127990.end->position[2][0] = tri_pos[2][0];
                D_80127990.end->position[2][1] = tri_pos[2][1];
                D_80127990.end->position[2][2] = tri_pos[2][2];
                D_80127990.end++;
            }
            if (num_out < max_count) {
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 3; j++) {
                        (*out)->position[i][j] =
                            tri_pos[i][j] + origin_i[j];
                    }
                }
                (*out)++;
                num_out++;
            }
        }
    }
    return num_out;
}

// Returns 0 if a triangle edge blocks the segment, 1 if the path is clear.
s32 func_800AD894(ModelAD894 *col_list, void *model, f32 *seg_start, f32 *seg_end, f32 *dir,
                  f32 *origin, f32 normal_y_limit)
{
    s32 i;
    s32 j;
    GroupAD894 **group_begin;
    GroupAD894 **group_end;
    GroupAD894 **group_it;
    VertexAD894 *vertices;
    TriAD894 *tri_end;
    TriAD894 *tri;
    s32 start_i[3];
    s32 end_i[3];
    s32 box_min[3];
    s32 box_max[3];
    s32 tri_min[3];
    s32 tri_max[3];
    s32 tri_pos[3][3];
    s32 edge_ab[3];
    s32 edge_ac[3];
    TriAD894 *tri_start;
    VertexAD894 *vtx;
    f32 normal[3];
    for (i = 0; i < 3; i++) {
        start_i[i] = seg_start[i] - origin[i];
        end_i[i] = seg_end[i] - origin[i];
    }
    for (i = 0; i < 3; i++)
        box_min[i] =
            start_i[i] < end_i[i] ? start_i[i] : end_i[i];
    for (i = 0; i < 3; i++)
        box_max[i] =
            end_i[i] < start_i[i] ? start_i[i] : end_i[i];
    func_800AA7FC(col_list, box_min, box_max, &group_begin, &group_end);
    vertices = func_800B2190(model);
    for (group_it = group_begin; group_it < group_end; group_it++) {
        tri_start =
            (TriAD894 *) ((u8 *) col_list + col_list->local_0 * 4 + 0x18) + (*group_it)->local_0;
        tri_end = tri_start + (*group_it)->local_1;
        for (tri = tri_start; tri < tri_end; tri++) {
            vtx = tri->local_0[0] + vertices;
            tri_min[0] = tri_max[0] = vtx->local_0[0];
            tri_min[1] = tri_max[1] = vtx->local_0[1];
            tri_min[2] = tri_max[2] = vtx->local_0[2];
            func_800EE8CC(tri_pos[0], vtx->local_0);
            for (i = 1; i < 3; i++) {
                vtx = tri->local_0[i] + vertices;
                for (j = 0; j < 3; j++) {
                    if (vtx->local_0[j] < tri_min[j])
                        tri_min[j] = vtx->local_0[j];
                    if (tri_max[j] < vtx->local_0[j])
                        tri_max[j] = vtx->local_0[j];
                }
                func_800EE8CC(tri_pos[i], vtx->local_0);
            }
            if (tri_max[0] < box_min[0] || box_max[0] < tri_min[0] || tri_max[1] < box_min[1] ||
                box_max[1] < tri_min[1] || tri_max[2] < box_min[2] || box_max[2] < tri_min[2])
                continue;
            func_800EFB58(edge_ab, tri_pos[1], tri_pos[0]);
            func_800EFB58(edge_ac, tri_pos[2], tri_pos[0]);
            func_800EE9EC(normal, edge_ab, edge_ac);
            func_800EF2A0(normal);
            if (normal[1] <= normal_y_limit && func_800EEAA4(normal, dir) > 0.0f)
                continue;
            if (func_800EED58(end_i, tri_pos[0]) && func_800EED58(start_i, tri_pos[1]))
                return 0;
            if (func_800EED58(end_i, tri_pos[1]) && func_800EED58(start_i, tri_pos[2]))
                return 0;
            if (func_800EED58(end_i, tri_pos[2]) && func_800EED58(start_i, tri_pos[0]))
                return 0;
        }
    }
    return 1;
}
