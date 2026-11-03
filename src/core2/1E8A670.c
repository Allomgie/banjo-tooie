#include "common.h"

typedef struct {
    s16 radius;
    s16 center[3];
    u8 hit_id;
    s8 bone;
    u8 pad_A[2];
} LocalPoint;
typedef struct {
    s16 box_count, cyl_count, sphere_count, pad_6;
    u8 data[1];
} LocalModel_800B0D80;
extern f32 D_80127EA0[4][4];
extern void func_800EE88C();
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_80019CD4(void);
extern void func_80019750(f32 *, f32 *, f32, s32);
extern void mlMtxGet(f32 (*)[4]);
extern void *func_800ADE2C(void *, s32);
extern void func_80019AA0(f32 (*)[4], void *);
extern void func_80019224(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
typedef struct {
    s16 bounds_min[3], bounds_max[3], unk_C[3];
    u8 unk_12[3], hit_id;
    u8 pad_16[2];
} LocalBox_800B0ECC;
typedef struct {
    s16 box_count;
    u8 pad_2[6];
    LocalBox_800B0ECC boxes[1];
} LocalModel_800B0ECC;
extern void func_800EF334(f32 *, f32);
extern void func_80019A10(f32 *, f32 *);
extern void func_800193C4(f32 *, f32 *);
typedef struct {
    s16 radius, height;
    s16 center[3];
    u8 unk_A[3];
    u8 hit_id;
    u8 pad[2];
} CylinderB1110;
typedef struct {
    s16 box_count, cyl_count;
    s32 pad;
    u8 data[1][24];
} MeshB1110;
extern void func_80019924(f32 *, f32 *);
extern void func_8001980C(f32 *, f32 *, f32, f32 *);
typedef struct {
    s16 box_count, cyl_count, sphere_count;
    s16 pad;
} MeshB1328;
typedef struct {
    s16 radius;
    s16 center[3];
    u8 hit_id;
    u8 pad[3];
} SphereB1328;
extern s16 D_80127EE0;
typedef struct {
    s16 bounds_min[3], bounds_max[3], unk_C[3];
    u8 unk_12[3], hit_id;
    s8 bone;
    u8 pad_17;
} LocalBox_800B1508;
typedef struct {
    s16 box_count;
    u8 pad_2[6];
    LocalBox_800B1508 boxes[1];
} LocalModel_800B1508;
extern void func_80019994(f32 *, f32 *);
extern void func_80019480(f32 *, f32, f32, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF2A0(f32 *);
extern void mlMtxPop(void);
typedef struct {
    s16 box_count, cyl_count;
    s32 pad;
} MeshB196C;
typedef struct {
    s16 radius, height, center[3];
    u8 unk_A[3], hit_id;
    s8 bone;
    u8 pad;
} CylinderB196C;
extern void func_800198D4(f32 *, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
typedef struct {
    s16 box_count, cyl_count, sphere_count, pad;
} ModelB1D3C;
typedef struct {
    s16 radius, center[3];
    u8 hit_id;
    s8 bone;
    s16 pad;
} SphereB1D3C;
extern void mlMtxSet(void *);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 mlAbsF(f32);
typedef struct {
    u8 pos[6];
    u16 unk_6;
    u8 unk_8[4];
    u8 color[4];
} local_entry;
typedef struct {
    u8 header[0x16];
    u16 count_x2;
    local_entry vtx[1];
} local_type;
extern void _dbpalette_entrypoint_0(s32, s32, s32 *);

// Finds sphere hit_id and returns its world-space center and radius.
s32 func_800B0D80(LocalModel_800B0D80 *model, s32 hit_id, f32 *pos, f32 *rot,
                  f32 scale, s32 unk_0, void *anim_list, f32 *out_pos, f32 *out_radius)
{
    LocalPoint *sphere;
    LocalPoint *end;
    u8 *cyl_start;
    u8 *unk_1;
    f32 top[3];
    cyl_start = model->box_count * 24 + model->data;
    sphere = (LocalPoint *) (cyl_start + model->cyl_count * 16);
    end = sphere + model->sphere_count;
    for (; sphere < end; sphere++)
        if (hit_id == sphere->hit_id)
            break;
    if (sphere == end)
        return 0;
    func_800EE88C(out_pos, sphere->center);
    func_800EFA4C(top, out_pos[0], out_pos[1] + sphere->radius, out_pos[2]);
    func_80019CD4();
    func_80019750(pos, rot, scale, unk_0);
    mlMtxGet(D_80127EA0);
    func_80019AA0(D_80127EA0, func_800ADE2C(anim_list, sphere->bone));
    func_80019224(out_pos, out_pos);
    func_80019224(top, top);
    if (out_radius)
        *out_radius = func_800EEAD4(out_pos, top);
    return 1;
}

// Sphere vs. boxes in model space; returns the hit id or 0.
s32 func_800B0ECC(LocalModel_800B0ECC *model, f32 *pos, f32 *rot, f32 scale,
                  s32 unk_0, f32 *query_pos, f32 query_radius, s32 hit_mask)
{
    s32 bit;
    f32 box_origin[3];
    f32 lo[3];
    f32 hi[3];
    f32 size[3];
    f32 local_radius;
    s32 axis;
    f32 local_pos[3];
    LocalBox_800B0ECC *box;
    LocalBox_800B0ECC *box_end;
    box_end = model->box_count + model->boxes;
    for (box = model->boxes; box < box_end; box++) {
        bit = box->hit_id - 1;
        if ((1 << bit) & hit_mask)
            continue;
        local_radius = query_radius / scale;
        func_800EE88C(box_origin, box->unk_C);
        func_800EE88C(lo, box->bounds_min);
        func_800EE88C(hi, box->bounds_max);
        size[0] = (u32) box->unk_12[0];
        size[1] = (u32) box->unk_12[1];
        size[2] = (u32) box->unk_12[2];
        func_800EF334(size, 2.0f);
        func_80019CD4();
        func_80019A10(box_origin, size);
        func_8001980C(pos, rot, scale, unk_0);
        func_800193C4(local_pos, query_pos);
        for (axis = 0; axis < 3; axis++) {
            if (local_pos[axis] + local_radius <= lo[axis])
                break;
            if (hi[axis] <= local_pos[axis] - local_radius)
                break;
        }
        if (axis == 3)
            return box->hit_id;
    }
    return 0;
}

// Sphere vs. cylinders in model space; returns the hit id or 0.
s32 func_800B1110(MeshB1110 *model, f32 *pos, f32 *rot, f32 scale, f32 *unk_0,
                  f32 *query_pos, f32 query_radius, u32 hit_mask)
{
    s32 unk_1;
    f32 cyl_center[3];
    f32 cyl_size[3];
    f32 local_radius, cyl_radius, cyl_height;
    s32 bit;
    f32 local_pos[3];
    CylinderB1110 *cyl, *cyl_end;
    s32 unk_2[2];
    cyl = (CylinderB1110 *) (model->box_count * 24 + (u8 *) model + 8);
    cyl_end = cyl + model->cyl_count;
    for (; cyl < cyl_end; cyl++) {
        bit = cyl->hit_id - 1;
        if ((1 << bit) & hit_mask)
            continue;
        local_radius = query_radius / scale;
        func_800EE88C(cyl_center, cyl->center);
        cyl_size[0] = cyl->unk_A[0] * 2;
        cyl_size[1] = cyl->unk_A[1] * 2;
        cyl_size[2] = cyl->unk_A[2] * 2;
        cyl_radius = cyl->radius;
        cyl_height = cyl->height;
        func_80019CD4();
        func_80019924(cyl_center, cyl_size);
        func_8001980C(pos, rot, scale, unk_0);
        func_800193C4(local_pos, query_pos);
        if (local_pos[2] - local_radius >= cyl_height * 0.5f)
            continue;
        if (local_pos[2] + local_radius <= -(cyl_height * 0.5f))
            continue;
        if ((local_pos[0] * local_pos[0] + local_pos[1] * local_pos[1]) >=
            (local_radius + cyl_radius) * (local_radius + cyl_radius))
            continue;
        return cyl->hit_id;
    }
    return 0;
}

// Sphere vs. spheres in model space; returns the hit id or 0, stores the index in D_80127EE0.
s32 func_800B1328(MeshB1328 *model, f32 *pos, f32 *rot, f32 scale, f32 *unk_0,
                  f32 *query_pos, f32 query_radius, u32 hit_mask)
{
    s32 unk_1;
    u8 *cyl_start;
    f32 local_pos[3];
    s32 bit;
    f32 sphere_center[3];
    f32 sphere_radius, local_radius, unk_2;
    f32 delta[3];
    SphereB1328 *sphere, *sphere_end;
    func_80019CD4();
    func_8001980C(pos, rot, scale, unk_0);
    func_800193C4(local_pos, query_pos);
    cyl_start = model->box_count * 24 + (u8 *) model + 8;
    sphere = (SphereB1328 *) (model->cyl_count * 16 + cyl_start);
    sphere_end = sphere + model->sphere_count;
    for (; sphere < sphere_end; sphere++) {
        bit = sphere->hit_id - 1;
        if ((1 << bit) & hit_mask)
            continue;
        local_radius = query_radius / scale;
        sphere_center[0] = sphere->center[0];
        sphere_center[1] = sphere->center[1];
        sphere_center[2] = sphere->center[2];
        sphere_radius = sphere->radius;
        delta[0] = sphere_center[0] - local_pos[0];
        delta[1] = sphere_center[1] - local_pos[1];
        delta[2] = sphere_center[2] - local_pos[2];
        if (sqrtf(delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2]) >=
            local_radius + sphere_radius)
            continue;
        D_80127EE0 =
            (SphereB1328 *) ((u8 *) sphere - model->cyl_count * 16) - (SphereB1328 *) cyl_start;
        return sphere->hit_id;
    }
    return 0;
}

// Sphere vs. boxes in bone space; returns the hit id or 0.
s32 func_800B1508(LocalModel_800B1508 *model, f32 *pos, f32 *rot, f32 scale,
                  s32 unk_0, void *anim_list, f32 *query_pos, f32 query_radius, u32 hit_mask)
{
    f32 box_origin[3];
    f32 lo[3];
    f32 hi[3];
    f32 size[3];
    LocalBox_800B1508 *box;
    LocalBox_800B1508 *box_end;
    f32 normal[3];
    f32 corner_lo[3];
    f32 rel_lo[3];
    f32 corner_z[3];
    f32 rel_z[3];
    f32 corner_x[3];
    f32 rel_x[3];
    f32 corner_y[3];
    f32 rel_y[3];
    s32 bit;
    box_end = model->box_count + model->boxes;
    for (box = model->boxes; box < box_end; box++) {
        bit = box->hit_id - 1;
        if ((1 << bit) & hit_mask)
            continue;
        func_800EE88C(box_origin, box->unk_C);
        func_800EE88C(lo, box->bounds_min);
        func_800EE88C(hi, box->bounds_max);
        size[0] = (u32) box->unk_12[0];
        size[1] = (u32) box->unk_12[1];
        size[2] = (u32) box->unk_12[2];
        func_800EF334(size, 2.0f);
        func_80019AA0(D_80127EA0, func_800ADE2C(anim_list, box->bone));
        func_80019994(box_origin, size);
        func_80019480(corner_lo, lo[0], lo[1], lo[2]);
        func_80019480(corner_z, lo[0], lo[1], hi[2]);
        func_800EFB24(normal, corner_lo, corner_z);
        func_800EF2A0(normal);
        func_800EFB24(rel_lo, query_pos, corner_lo);
        if (query_radius <= rel_lo[0] * normal[0] + rel_lo[1] * normal[1] + rel_lo[2] * normal[2])
            goto next_box;
        func_800EFB24(rel_z, query_pos, corner_z);
        if (query_radius <=
            -(rel_z[0] * normal[0] + rel_z[1] * normal[1] + rel_z[2] * normal[2]))
            goto next_box;
        func_80019480(corner_x, hi[0], lo[1], lo[2]);
        func_800EFB24(normal, corner_lo, corner_x);
        func_800EF2A0(normal);
        if (query_radius <= rel_lo[0] * normal[0] + rel_lo[1] * normal[1] + rel_lo[2] * normal[2])
            goto next_box;
        rel_x[0] = query_pos[0] - corner_x[0];
        rel_x[1] = query_pos[1] - corner_x[1];
        rel_x[2] = query_pos[2] - corner_x[2];
        if (query_radius <=
            -(rel_x[0] * normal[0] + rel_x[1] * normal[1] + rel_x[2] * normal[2]))
            goto next_box;
        func_80019480(corner_y, lo[0], hi[1], lo[2]);
        normal[0] = corner_lo[0] - corner_y[0];
        normal[1] = corner_lo[1] - corner_y[1];
        normal[2] = corner_lo[2] - corner_y[2];
        func_800EF2A0(normal);
        if (query_radius <= rel_lo[0] * normal[0] + rel_lo[1] * normal[1] + rel_lo[2] * normal[2])
            goto next_box;
        rel_y[0] = query_pos[0] - corner_y[0];
        rel_y[1] = query_pos[1] - corner_y[1];
        rel_y[2] = query_pos[2] - corner_y[2];
        if (query_radius <=
            -(rel_y[0] * normal[0] + rel_y[1] * normal[1] + rel_y[2] * normal[2]))
            goto next_box;
        return box->hit_id;
    next_box:
        mlMtxPop();
    }
    return 0;
}

// Sphere vs. cylinders in bone space; returns the hit id or 0.
s32 func_800B196C(MeshB196C *model, f32 *pos, f32 *rot, f32 scale, f32 *unk_0,
                  void *anim_list, f32 *query_pos, f32 query_radius, u32 hit_mask)
{
    s32 unk_1;
    f32 cyl_center[3];
    f32 cyl_size[3];
    s32 bit;
    f32 proj;
    f32 bottom[3];
    f32 top[3];
    f32 axis[3];
    f32 rel[3];
    f32 radius_vec[3];
    CylinderB196C *cyl, *cyl_end;
    cyl = (CylinderB196C *) (model->box_count * 24 + (u8 *) model + 8);
    cyl_end = cyl + model->cyl_count;
    for (; cyl < cyl_end; cyl++) {
        bit = cyl->hit_id - 1;
        if ((1 << bit) & hit_mask)
            continue;
        cyl_center[0] = cyl->center[0];
        cyl_center[1] = cyl->center[1];
        cyl_center[2] = cyl->center[2];
        cyl_size[0] = cyl->unk_A[0] * 2;
        cyl_size[1] = cyl->unk_A[1] * 2;
        cyl_size[2] = cyl->unk_A[2] * 2;
        func_80019AA0((f32 *) D_80127EA0, func_800ADE2C(anim_list, cyl->bone));
        func_800198D4(cyl_center, cyl_size);
        func_80019480(bottom, 0.0f, 0.0f, -cyl->height * 0.5f);
        func_80019480(top, 0.0f, 0.0f, cyl->height * 0.5f);
        func_80019480(radius_vec, cyl->radius, 0.0f, -cyl->height * 0.5f);
        func_800EF3DC(radius_vec, bottom);
        func_800EFB24(axis, bottom, top);
        func_800EF2A0(axis);
        func_800EFB24(rel, query_pos, bottom);
        proj = axis[0] * rel[0] + axis[1] * rel[1] + axis[2] * rel[2];
        if (query_radius < proj)
            goto next;
        func_800EFB24(rel, query_pos, top);
        if (query_radius <
            -(axis[0] * rel[0] + axis[1] * rel[1] + axis[2] * rel[2]))
            goto next;
        rel[0] = query_pos[0] - (bottom[0] + axis[0] * proj);
        rel[1] = query_pos[1] - (bottom[1] + axis[1] * proj);
        rel[2] = query_pos[2] - (bottom[2] + axis[2] * proj);
        proj =
            sqrtf(rel[0] * rel[0] + rel[1] * rel[1] + rel[2] * rel[2]);
        if (sqrtf(radius_vec[0] * radius_vec[0] + radius_vec[1] * radius_vec[1] + radius_vec[2] * radius_vec[2]) <
            proj - query_radius)
            goto next;
        return cyl->hit_id;
    next:
        mlMtxPop();
    }
    return 0;
}

// Sphere vs. spheres in bone space; returns the hit id or 0, stores the index in D_80127EE0.
s32 func_800B1D3C(ModelB1D3C *model, f32 *pos, f32 *rot, f32 scale, f32 *unk_0,
                  void *anim_list, f32 *query_pos, f32 query_radius, u32 hit_mask)
{
    s32 bit;
    u8 *cyl_start;
    f32 local_pos[3], sphere_center[3], sphere_edge[3];
    f32 query_radius_sq, sphere_radius_sq, sphere_radius;
    f32 radius_vec[3];
    SphereB1D3C *sphere, *sphere_end;
    func_80019CD4();
    func_8001980C(pos, rot, scale, unk_0);
    func_800193C4(local_pos, query_pos);
    cyl_start = model->box_count * 24 + (u8 *) model + 8;
    sphere = (SphereB1D3C *) (cyl_start + model->cyl_count * 16);
    sphere_end = sphere + model->sphere_count;
    query_radius /= scale;
    for (; sphere < sphere_end; sphere++) {
        bit = sphere->hit_id - 1;
        if (hit_mask & (1 << bit))
            continue;
        query_radius_sq = query_radius * query_radius;
        func_800EE88C(sphere_center, sphere->center);
        func_800EFA4C(sphere_edge, sphere_center[0] + sphere->radius, sphere_center[1], sphere_center[2]);
        mlMtxSet(func_800ADE2C(anim_list, sphere->bone));
        func_80019224(sphere_center, sphere_center);
        func_80019224(sphere_edge, sphere_edge);
        radius_vec[0] = sphere_edge[0] - sphere_center[0];
        radius_vec[1] = sphere_edge[1] - sphere_center[1];
        radius_vec[2] = sphere_edge[2] - sphere_center[2];
        sphere_radius_sq = func_800EEFD4(radius_vec);
        sphere_radius = sqrtf(sphere_radius_sq);
        if (func_800EEB40(sphere_center, local_pos) <=
            query_radius_sq + sphere_radius_sq + (sphere_radius + sphere_radius) * query_radius) {
            D_80127EE0 = ((u8 *) sphere - model->cyl_count * 16 - cyl_start) / 12;
            return sphere->hit_id;
        }
    }
    return 0;
}

// Tries spheres, boxes, cylinders (bone space if anim_list is set); sets out_normal to (0,1,0) on hit.
s32 func_800B1F8C(void *model, f32 *pos, f32 *rot, f32 scale, s32 unk_0,
                  void *anim_list, f32 *query_pos, f32 query_radius, f32 *out_normal, s32 hit_mask)
{
    s32 result;
    // Matching: needed for the match.
    f32 **pos_ref = &pos;
    f32 **rot_ref = &rot;
    if (anim_list) {
        func_80019CD4();
        func_80019750(*pos_ref, *rot_ref, scale, unk_0);
        mlMtxGet(D_80127EA0);
        result = func_800B1D3C(model, pos, rot, scale, unk_0, anim_list, query_pos,
                                query_radius, hit_mask);
        if (!result)
            result = func_800B1508(model, pos, rot, scale, unk_0, anim_list, query_pos,
                                    query_radius, hit_mask);
        if (!result)
            result = func_800B196C(model, pos, rot, scale, unk_0, anim_list, query_pos,
                                    query_radius, hit_mask);
    } else {
        result =
            func_800B1328(model, pos, rot, scale, unk_0, query_pos, query_radius, hit_mask);
        if (!result)
            result = func_800B0ECC(model, pos, rot, scale, unk_0, query_pos, query_radius,
                                    hit_mask);
        if (!result)
            result = func_800B1110(model, pos, rot, scale, unk_0, query_pos, query_radius,
                                    hit_mask);
    }
    if (result)
        func_800EFA4C(out_normal, 0.0f, 1.0f, 0.0f);
    return result;
}

// Returns the vertex array.
func_800B2190(vtx_list)
{
    return vtx_list + 0x18;
}

// Reads the s16 bounds min/max.
func_800B2198(s16 *vtx_list, s32 *out_min, s32 *out_max)
{
    out_min[0] = vtx_list[0];
    out_min[1] = vtx_list[1];
    out_min[2] = vtx_list[2];
    out_max[0] = vtx_list[3];
    out_max[1] = vtx_list[4];
    out_max[2] = vtx_list[5];
}

// Reads the bounds min/max as floats.
func_800B21CC(s16 *vtx_list, f32 out_min[3], f32 out_max[3])
{
    out_min[0] = vtx_list[0];
    out_min[1] = vtx_list[1];
    out_min[2] = vtx_list[2];
    out_max[0] = vtx_list[3];
    out_max[1] = vtx_list[4];
    out_max[2] = vtx_list[5];
}

s32 func_800B2248(u8 *vtx_list)
{
    s32 max_abs;
    s32 value;
    max_abs = (s32) mlAbsF((f32) *(s16 *) vtx_list);
    value = (s32) mlAbsF((f32) *(s16 *) (vtx_list + 4));
    if (max_abs < value) {
        max_abs = value;
    }
    value = (s32) mlAbsF((f32) *(s16 *) (vtx_list + 6));
    if (max_abs < value) {
        max_abs = value;
    }
    value = (s32) mlAbsF((f32) *(s16 *) (vtx_list + 0xA));
    if (max_abs < value) {
        max_abs = value;
    }
    return max_abs;
}

// Outputs the vertex array start and end.
void func_800B2324(u8 *vtx_list, s32 *out_start, s32 *out_end)
{
    u16 raw_count;
    s32 start;
    s32 count;
    start = (s32) vtx_list + 0x18;
    // Matching: needed for the match.
    do {
    } while (0);
    *out_start = start;
    count = (u32) *(u16 *) (vtx_list + 0x16) >> 1;
    raw_count = *(u16 *) (vtx_list + 0x16);
    *out_end = start + ((((u32) raw_count >> 1) * 8) * 2);
}

// Returns the vertex count.
int func_800B2344(u16 *vtx_list)
{
    return (unsigned int) *&vtx_list[11] >> 1;
}

volatile unsigned short func_800B2354(u16 *vtx_list)
{
    f32 unk_0;
    f32 unk_1;
    u16 *list;
    list = vtx_list;
    unk_1 = list[10];
    unk_0 = unk_1;
    // Matching: needed for the match.
    if ((u32) unk_0 < 0) {
        return unk_1 = unk_0;
    }
}

// Outputs the center and radius.
void func_800B237C(u8 *vtx_list, u8 *out_center, f32 *out_radius)
{
    s16 *src_y;
    s16 *src_z;
    s8 *dst_y;
    f32 radius_f;
    u16 radius;
    *(f32 *) ((s8 *) out_center + 0) = (f32) *(s16 *) ((s8 *) vtx_list + 0xC);
    src_y = (s16 *) ((s8 *) vtx_list + 0xE);
    *(f32 *) (dst_y = (s8 *) out_center + 4) = (f32) *src_y;
    src_z = &*(s16 *) ((s8 *) vtx_list + 0x10);
    *(f32 *) ((s8 *) out_center + 8) = (f32) *src_z;
    // Matching: ^ 0, the do/while and the empty if are needed for the match.
    radius = *(u16 *) ((s8 *) vtx_list + 0x12) ^ 0;
    do {
        radius_f = (*out_radius = (f32) radius);
        if ((s32) radius < 0) {
        }
    } while (0);
}

void func_800B23E0(void *vtx_list)
{
    heap_free(vtx_list);
}

// Clones a vertex list.
void *func_800B2400(u16 *vtx_list, u32 side_flag)
{
    void *clone;
    u32 size;

    size = (((u32) vtx_list[11] >> 1) << 4) + 0x18;
    clone = heap_alloc_sided(size, side_flag != 0 ? 1 : 2);
    aligned4_memcpy(clone, vtx_list, size);
    return clone;
}

// Vertex colors = src color * tint / 256; skipped if tint is 0xFF,0xFF,0xFF.
void func_800B2464(u8 *vtx_list, s32 *tint, s32 src_list)
{
    s32 *tint_ch;
    s32 i;
    u8 *verts;
    u8 *verts_end;
    u8 *dst_vtx;
    u8 *src_ch;
    u8 *src_vtx;
    u8 *dst_ch;

    if ((*(s32 *) tint != 0xFF) || (*(s32 *) ((s8 *) tint + 4) != 0xFF) ||
        (*(s32 *) ((s8 *) tint + 8) != 0xFF)) {
        verts = vtx_list + 0x18;
        dst_vtx = verts;
        verts_end = (((u32) *(u16 *) ((s8 *) vtx_list + 0x16) >> 1) * 0x10) + vtx_list + 0x18;
        src_vtx = (u8 *) (src_list + 0x18);
        if ((u32) verts < (u32) verts_end) {
            do {
                i = 0;
                dst_ch = dst_vtx;
                tint_ch = tint;
                src_ch = src_vtx;
                do {
                    i += 1;
                    dst_ch += 1;
                    *(s8 *) ((u8 *) dst_ch + 0xB) =
                        (s8) ((*(u8 *) ((u8 *) src_ch + 0xC) * *tint_ch) >> 8);
                    tint_ch += 1;
                    src_ch += 1;
                } while (i != 3);
                dst_vtx += 0x10;
                src_vtx += 0x10;
            } while ((u32) dst_vtx < (u32) verts_end);
        }
        osWritebackDCache(verts, ((s32) (verts_end - verts) >> 4) << 4);
    }
}

// Sets all vertex colors to rgb.
void func_800B2540(u8 *vtx_list, s32 *rgb)
{
    u8 *rgb_ch;
    s32 i;
    u8 *verts_end;
    u8 *verts;
    u8 *vtx;
    u8 *dst_ch;
    verts = vtx_list + 0x18;
    verts_end = ((((u32) *(u16 *) ((s8 *) vtx_list + 0x16) >> 1) * 0x10) + vtx_list) + 0x18;
    vtx = verts;
    if ((u32) verts < (u32) verts_end) {
        do {
            i = 0;
            dst_ch = vtx;
            rgb_ch = rgb;
        // Matching: needed for the match.
        loop_3:

            i += 1;
            dst_ch += 1;
            *(s8 *) ((s8 *) dst_ch + 0xB) = (s8) *(s32 *) rgb_ch;
            rgb_ch += 4;
            if (i != 3) {
                goto loop_3;
            }
            vtx += 0x10;
        } while ((u32) vtx < (u32) verts_end);
    }
    osWritebackDCache(verts, ((s32) (verts_end - verts) >> 4) * 0x10);
}

// Vertex colors = src color * palette color / 256.
void func_800B25D8(local_type *dst_list, local_type *src_list, s32 unk_0)
{
    u8 unk_1[8];
    s32 rgb[3];
    local_entry *dst_verts;
    local_entry *dst_end;
    local_entry *dst;
    local_entry *src;
    s32 i;
    dst_verts = dst_list->vtx;
    dst_end = ((u32) dst_list->count_x2 >> 1) + dst_list->vtx;
    dst = dst_verts;
    src = src_list->vtx;
    for (; dst < dst_end; dst++, src++) {
        _dbpalette_entrypoint_0(unk_0, src->unk_6 & 0x1FF, rgb);
        for (i = 0; i < 3; i++) {
            dst->color[i] = (src->color[i] * rgb[i]) >> 8;
        }
    }
    osWritebackDCache(dst_verts, (dst_end - dst_verts) * sizeof(local_entry));
}

int func_800B26C8()
{
    defrag();
}
