// Player ledge grab: finds the nearest wall edge ahead, checks headroom and floor, stores the
// ledge position, and keeps the player attached to it in collision mode 7.
// TU-NOTE: second half of the former 1E6F080, from func_800967C0 on.
#include "core2/1E6F080.h"
#include "types.h"
#include "macros.h"

#define STATE(p) (*(LocalState **) ((u8 *) (p) + 0x98))
extern f32 mlAbsF(f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_8009C15C(PlayerState *, f32 *);
extern void func_8009C0F8(PlayerState *, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
// One candidate wall edge: ray distance, edge endpoints, wall normal, hit point.
typedef struct {
    f32 local_0;
    f32 start[3], end[3], normal[3], point[3];
} Hit967C8;
typedef struct {
    s32 local_0;
    Hit967C8 hits[1];
} Hits967C8;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF2A0(f32 *);
extern void func_800EE97C(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800EEAA4(f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_800BEE40(f32 *, f32 *, f32 *, f32);
typedef s16 Triangle96ACC[3][3];
typedef struct {
    s32 local_0;
    Hit967C8 hits[1];
} Result96ACC;
extern Triangle96ACC D_80126D20[];
extern Result96ACC D_80126E30;
extern s32 func_800BED70(f32 *, f32 *, Triangle96ACC **, s32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern s32 func_800EECE0(f32 *, f32 *);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
typedef struct {
    u8 pad_0[0x98];
    f32 *local_0;
} State97104;
extern void func_8009BB24(State97104 *, f32 *);
// Ledge component at PlayerState+0x98 (size 0x28).
typedef struct {
    f32 direction[3], position[3], offset[3];
    u8 active, state;
} LocalState;
typedef struct {
    f32 local_0[3], position[3];
} Motion97530;
typedef struct {
    u8 pad_0[0x98];
    Motion97530 *local_0;
} Actor97530;
extern void func_800EF04C(f32 *, f32 *);
extern void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
extern void *func_800C6C94(f32 *, f32, f32 *, u32);
typedef struct {
    f32 local_0[3];
    u8 pad_C[0x18];
    f32 unk_24[3];
    f32 normal[3];
    f32 pos[3];
    f32 height;
    f32 radius;
} local_0;
void func_80095870(u8 *param_0, f32 *param_1, f32 *param_2);
void func_8009646C(s32 *param_0, s32 param_1);

s32 func_800967C0()
{
    return 0x28;
}

// Tests one wall edge against the ray and keeps the nearest hit in D_80126E30.
void func_800967C8(f32 *edge_start, f32 *edge_end, f32 *ray_origin, f32 *ray_dir)
{
    f32 local_0;
    s32 i;
    f32 t;
    f32 along;
    f32 hit_pos[3];
    f32 dist;
    f32 edge_dir[3];
    f32 normal[3];
    f32 unk_0;
    f32 up[3];
    f32 edge_flat[3];
    f32 edge[3];
    f32 to_hit[3];
    f32 origin_dist;
    f32 plane_dist;
    func_800EFB24(edge, edge_end, edge_start);
    func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
    func_800EFA4C(edge_flat, edge[0], 0.0f, edge[2]);
    func_800EF2A0(edge_flat);
    func_800EE97C(normal, edge_flat, up);
    local_0 = func_800EEAA4(ray_dir, normal);
    if (local_0 > 0.0f || local_0 == 0.0f)
        return;
    plane_dist = func_800EEAA4(normal, edge_start);
    origin_dist = func_800EEAA4(normal, ray_origin);
    t = (plane_dist - origin_dist) / local_0;
    if (origin_dist < plane_dist)
        return;
    for (i = 0; i != 3; i++) {
        hit_pos[i] = ray_origin[i] + ray_dir[i] * t;
    }
    func_800EFA4C(edge_dir, edge[0], 0.0f, edge[2]);
    func_800EF2A0(edge_dir);
    func_800EFA4C(to_hit, hit_pos[0] - edge_start[0], 0.0f, hit_pos[2] - edge_start[2]);
    along = func_800EEAA4(to_hit, edge_dir);
    if (along < 0.0f)
        return;
    if (along > func_800EEF94(edge))
        return;
    if (func_800BEE40(edge_start, edge_end, normal, 0.028f)) {
        dist = func_800EEAD4(ray_origin, hit_pos);
        if ((*(Hits967C8 *) &D_80126E30).hits[0].local_0 < dist)
            return;
        if (dist < (*(Hits967C8 *) &D_80126E30).hits[0].local_0)
            (*(Hits967C8 *) &D_80126E30).local_0 = 0;
        (*(Hits967C8 *) &D_80126E30).hits[(*(Hits967C8 *) &D_80126E30).local_0].local_0 =
            dist;
        func_800EE7F8(
            (*(Hits967C8 *) &D_80126E30).hits[(*(Hits967C8 *) &D_80126E30).local_0].start,
            edge_start);
        func_800EE7F8(
            (*(Hits967C8 *) &D_80126E30).hits[(*(Hits967C8 *) &D_80126E30).local_0].end,
            edge_end);
        func_800EE7F8(
            (*(Hits967C8 *) &D_80126E30).hits[(*(Hits967C8 *) &D_80126E30).local_0].normal,
            normal);
        func_800EE7F8(
            (*(Hits967C8 *) &D_80126E30).hits[(*(Hits967C8 *) &D_80126E30).local_0].point,
            hit_pos);
        (*(Hits967C8 *) &D_80126E30).local_0++;
    }
}

// Finds the nearest near-vertical wall edge crossing the segment; returns 1 with hit position and wall normal.
s32 func_80096ACC(f32 *seg_start, f32 *seg_end, f32 *out_pos, f32 *out_normal)
{
    Triangle96ACC *tri;
    s32 j;
    Triangle96ACC *tri_end;
    s32 i;
    f32 box_min[3];
    f32 box_max[3];
    f32 seg_dir[3];
    f32 verts[3][3];
    s32 unk_0;
    s32 unk_1;
    f32 dx;
    func_800EFB24(seg_dir, seg_end, seg_start);
    for (i = 0; i < 3; i++) {
        box_min[i] =
            seg_start[i] < seg_end[i] ? seg_start[i] : seg_end[i];
    }
    for (i = 0; i != 3; i++) {
        box_max[i] =
            seg_start[i] > seg_end[i] ? seg_start[i] : seg_end[i];
    }
    box_max[1] += 100.0f;
    // Matching: the end parameter is reused as the triangle buffer pointer.
    seg_end = (f32 *) D_80126D20;
    tri_end = (Triangle96ACC *) seg_end;
    if (!func_800BED70(box_min, box_max, &tri_end, 15, 0.98f))
        return 0;
    D_80126E30.local_0 = 0;
    D_80126E30.hits[0].local_0 = 1e+05f;
    for (tri = (Triangle96ACC *) seg_end; tri < tri_end; tri++) {
        for (j = 0; j < 3; j++) {
            func_800EE88C(verts[j], (*tri)[j]);
        }
        func_800967C8(verts[0], verts[1], seg_start, seg_dir);
        func_800967C8(verts[1], verts[2], seg_start, seg_dir);
        func_800967C8(verts[2], verts[0], seg_start, seg_dir);
    }
    if (D_80126E30.hits[0].local_0 == 1e+05f)
        return 0;
    func_800EE7F8(out_pos, D_80126E30.hits[0].point);
    func_800EE7F8(out_normal, D_80126E30.hits[0].normal);
    dx = mlAbsF(D_80126E30.hits[0].start[0] - D_80126E30.hits[0].end[0]);
    if (mlAbsF(D_80126E30.hits[0].start[2] - D_80126E30.hits[0].end[2]) < dx) {
        out_pos[1] = func_800F10B4(
            out_pos[0], D_80126E30.hits[0].start[0], D_80126E30.hits[0].end[0],
            D_80126E30.hits[0].start[1], D_80126E30.hits[0].end[1]);
    } else {
        out_pos[1] = func_800F10B4(
            out_pos[2], D_80126E30.hits[0].start[2], D_80126E30.hits[0].end[2],
            D_80126E30.hits[0].start[1], D_80126E30.hits[0].end[1]);
    }
    return 1;
}

int func_80096DD4(s32 out_pos, s32 out_normal, s32 seg_start, s32 seg_end)
{
    f32 local_0[3];
    f32 end_pos[3];
    // Matching: "| 0" is needed for the match.
    func_800EE7F8(local_0, seg_start | 0);
    func_800EE7F8(end_pos, seg_end);
    if (!func_80096ACC(local_0, end_pos, out_pos, out_normal)) {
        return 0;
    }
    return 1;
}

s32 func_80096E30(f32 *dir, f32 *out_pos, f32 *origin, f32 reach, f32 back_offset, f32 skew)
{
    s32 unk_0;
    f32 local_0[3], left_normal[3], left_hit[3], left_start[3], side_left[3], skew_left[3];
    f32 right_end[3], right_normal[3], right_hit[3], right_start[3], side_right[3], skew_right[3];
    f32 fwd[3], base[3];
    func_800EFA20(fwd, dir, back_offset);
    func_800EE780(base, origin, fwd);
    func_800EFA20(fwd, dir, reach);
    func_800EF934(skew_left, fwd, -skew);
    func_800EF934(skew_right, fwd, skew);
    func_800EFA4C(side_left, fwd[2], fwd[1], -fwd[0]);
    func_800EFA4C(side_right, -fwd[2], fwd[1], fwd[0]);
    func_800EF368(side_left, 30.0f);
    func_800EF368(side_right, 30.0f);
    func_800EE780(left_start, base, side_left);
    func_800EE780(right_start, base, side_right);
    func_800EE780(local_0, left_start, skew_left);
    func_800EE780(right_end, right_start, skew_right);
    if (!func_80096DD4(left_hit, left_normal, left_start, local_0))
        return 0;
    if (!func_80096DD4(right_hit, right_normal, right_start, right_end))
        return 1;
    if (func_800EEAA4(left_normal, right_normal) <= 0.1f)
        return 4;
    func_800EFE50(out_pos, left_hit, right_hit, 0.5f);
    func_800EE780(dir, left_normal, right_normal);
    func_800EF334(dir, -0.5f);
    func_800EF2A0(dir);
    return func_800EECE0(left_normal, right_normal) ? 2 : 3;
}

// Ray test between two heights relative to pos; returns 1 on hit.
s32 func_8009700C(s32 player, s32 out_hit, u8 *pos, f32 top_offset, f32 bottom_offset)
{
    u8 *z_bytes;
    f32 *z_ptr;
    s32 end_pt;
    u8 *y_bytes;
    f32 *z_ptr2;
    s32 start_pt;
    // Matching: the extra pointer temporaries are needed for the match.
    z_ptr = (f32 *) (pos + 8);
    y_bytes = pos + 4;
    z_bytes = pos + 8;
    z_ptr2 = (f32 *) z_bytes;
    func_800EFA4C(&start_pt, *(f32 *) pos, *(f32 *) (pos + 4) + top_offset, *z_ptr2);
    func_800EFA4C(&end_pt, *(f32 *) pos, *(f32 *) y_bytes + bottom_offset, *z_ptr);
    if (func_800C6A7C(&start_pt, &end_pt, out_hit, 0x420025) != 0) {
        return 1;
    }
    return 0;
}

// Ray test from origin along dir for the given range; returns 1 on hit.
s32 func_800970A4(f32 *origin, f32 *dir, f32 range)
{
    s32 pad;
    f32 end[3];
    f32 hit[3];
    s32 blocked;

    func_800EE7B4(end, origin, dir, range);
    if (func_800C6A7C(origin, end, hit, 0x420025) != 0) {
        blocked = 1;
    } else {
        blocked = 0;
    }
    return blocked;
}

// Side ray checks around the ledge point; returns 0 if blocked.
s32 func_80097104(State97104 *player, f32 *point, f32 radius)
{
    f32 local_0[3];
    f32 probe_top[3];
    f32 probe_bottom[3];
    f32 up[3];
    f32 side[3];
    f32 neg_side[3];
    f32 range;
    f32 side_dot;
    f32 heading[3];
    func_800EFA20(local_0, player->local_0, radius);
    func_800EFB24(probe_top, point, local_0);
    func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
    func_800EE97C(side, player->local_0, up);
    func_800EFA20(neg_side, side, -1.0f);
    func_8009BB24(player, heading);
    heading[1] = 0.0f;
    func_800EF2A0(heading);
    side_dot = func_800EEAA4(side, heading);
    func_800EFA4C(probe_bottom, probe_top[0], probe_top[1] - 50.0f, probe_top[2]);
    if (side_dot > 0.0f) {
        range = radius + 4.0f;
        if (func_800970A4(probe_top, side, range))
            return 0;
        if (func_800970A4(probe_bottom, side, range))
            return 0;
    }
    if (side_dot < 0.0f) {
        range = -(radius + 4.0f);
        if (func_800970A4(probe_top, side, range))
            return 0;
        if (func_800970A4(probe_bottom, side, range))
            return 0;
    }
    return 1;
}

// Probes for a ledge near pos and stores the result code in the ledge state; returns 1 when found.
s32 func_800972BC(void *player, f32 *pos)
{
    f32 skew;
    f32 local_0;
    f32 height;
    f32 probe_pos[3];
    f32 edge_pos[3];
    f32 hit_normal[3];
    f32 inset[3];
    func_800EE7F8(probe_pos, pos);
    func_80095870(player, &height, &local_0);
    probe_pos[1] += height - local_0;
    if (STATE(player)->active)
        skew = 15.0f;
    else
        skew = 0.0f;
    switch (func_80096E30(STATE(player), edge_pos, probe_pos, local_0 + 30.0f, -local_0 * 0.5f,
                          skew)) {
        case 0:
            STATE(player)->state = 2;
            return 0;
        case 1:
            STATE(player)->state = 3;
            return 0;
        case 4:
            STATE(player)->state = 3;
            return 0;
        case 2:
            STATE(player)->active = 1;
            break;
        case 3:
            STATE(player)->active = 0;
            break;
    }
    func_800EE7F8(STATE(player)->position, edge_pos);
    if (!func_80097104(player, edge_pos, local_0))
        return 0;
    func_800EFA20(inset, STATE(player)->direction, local_0 + -18.0f);
    func_800EFB24(probe_pos, edge_pos, inset);
    probe_pos[1] = edge_pos[1] - height + -43.0f;
    if (func_8009700C(player, hit_normal, probe_pos, local_0 * 0.75f + height, -50.0f)) {
        if (hit_normal[1] > 0.0f) {
            STATE(player)->state = 4;
        } else {
            STATE(player)->state = 5;
        }
        return 0;
    }
    func_800EE7F8(STATE(player)->offset, probe_pos);
    STATE(player)->state = 1;
    return 1;
}

f32 func_800974FC(PlayerState *player)
{
    f32 local_0;
    func_800F1EA4(*(struct ba_unk_9C **) ((char *) player + 152), &local_0);
    return local_0;
}

// Returns the ledge state code.
s32 func_80097524(PlayerState *player)
{
    return (*(u8 **) ((char *) player + 0x98))[0x25];
}

// Headroom check above the ledge: returns 1 when the ray and both spheres are clear.
s32 func_80097530(PlayerState *player)
{
    f32 local_0, height;
    f32 probe_start[3], probe_end[3], target[3], hit[3];
    func_80095870(player, &height, &local_0);
    func_800EFA20(target, ((Actor97530 *) player)->local_0->local_0, 25.0f);
    func_800EF04C(target, ((Actor97530 *) player)->local_0->position);
    func_800EFA4C(probe_start, target[0], target[1] + 6.0f, target[2]);
    func_800EFA4C(probe_end, target[0], target[1] + height + local_0 + 5.0f, target[2]);
    if (func_800C6A7C(probe_start, probe_end, hit, 0x420025))
        return 0;
    func_800EFA4C(probe_start, target[0], target[1] + height, target[2]);
    if (func_800C6C94(probe_start, local_0 + 5.0f, hit, 0x420025))
        return 0;
    func_800EFA4C(probe_start, target[0], target[1] + height - local_0 * 0.75f, target[2]);
    if (func_800C6C94(probe_start, local_0 + 5.0f, hit, 0x420025))
        return 0;
    return 1;
}

// Can-grab-ledge check; blocked while state timer 7 (cooldown) is active.
s32 func_800976DC(u8 *player)
{
    local_0 info;
    u8 *ledge;

    if (bastatetimer_isActive(player, 7) != 0) {
        return 0;
    }
    if (func_8009650C(player) == 0) {
        return 0;
    }

    func_80096440(player, info.normal);
    if ((0.028f < info.normal[1]) && (0.98f > info.normal[1])) {
        return 0;
    }

    func_8009C128(player, info.pos);
    func_80095870(player, &info.height, &info.radius);
    info.pos[1] += info.height;
    func_8009646C(player, info.local_0);
    func_800F0410(info.unk_24, info.local_0, info.pos);
    func_800EFB24(*(u8 **) (player + 0x98), info.unk_24, info.pos);
    *(f32 *) (*(u8 **) (player + 0x98) + 4) = 0.0f;
    func_800EF2A0(*(u8 **) (player + 0x98));

    if ((*(f32 *) ((ledge = *(u8 **) (player + 0x98)) + 0) == 0.0f) &&
        (*(f32 *) (ledge + 8) == 0.0f)) {
        return 0;
    }

    ledge[0x24] = 1;
    func_8009C128(player, info.pos);
    if (func_800972BC(player, info.pos) == 0) {
        return 0;
    }
    return func_800972BC(player, *(u8 **) (player + 0x98) + 0x18);
}

// Marks the ledge active and starts the 0.2 s cooldown (state timer 7).
void func_80097858(player) u8 *player;
{
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (player) + (0x98)))) + (0x24))) = 1;
    bastatetimer_set(player, 7, 0x3E4CCCCD);
}

void func_8009788C(player) u8 *player;
{
    *((u8 *) ((*((u8 **) (player + 0x98))) + 0x24)) = 1 ^ 0; // Matching: "^ 0" is needed for the match.
    *((u8 *) ((*((u8 **) (player + 0x98))) + 0x26)) = 1;
}

// Collision mode 7 update: keeps the player attached to the ledge.
void func_800978A4(player) u8 *player;
{
    s32 local_0[3];
    s32 target_pos[3];
    s32 saved_dir[3];
    u8 *ledge;

    func_8009C15C(player, &local_0);
    // Matching: the bare block is needed for the match.
    {
        ledge = *(u8 **) (player + 0x98);
    }

    if (*(u8 *) (ledge + 0x26) != 0) {
        *(u8 *) (ledge + 0x26) = 0;
        func_800EE7F8(&target_pos, *(u8 **) (player + 0x98) + 0x18);
    }

    else {
        func_8009C128(player, &target_pos);
    }
    func_800EE7F8(&saved_dir, *((u8 **) (player + 0x98)));

    if (func_800972BC(player, &target_pos) != 0) {
        func_800EE7F8(&target_pos, *(u8 **) (player + 0x98) + 0x18);
        baphysics_set_vertical_velocity(player, 1.0f);
    }

    else {
        func_800EE7F8(&target_pos, &local_0);
        func_800EE7F8(*((u8 **) (player + 0x98)), &saved_dir);
    }
    func_8009C0F8(player, &target_pos);
}
