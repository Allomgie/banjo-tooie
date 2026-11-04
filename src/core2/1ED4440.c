// Probably collision query helpers on top of the map-collision dispatcher: raycasts, ground snap,
// sphere push-out, wall-slide responses, line-of-sight test and a collision-triangle copy.
#include "common.h"
void func_800EF368(f32 vec[3], f32 target_length);

extern u8 *func_800C6A7C(f32 *, f32 *, f32 *, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern f32 func_800EEAA4(OSPiHandle *, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern f32 D_801357C0;
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF410(f32 *, f32 *);
extern void func_800C7A68(s32 *, f32, s32 *);
void func_800EE780(f32 *a0, s32 a1, f32 *a2);
s32 func_800BEF00(f32 *a0, f32 *a1, f32 *a2, s32 a3);
s32 func_800EE7F8();
extern f32 func_800EEB40(void);
extern s32 func_800C6B78(f32 *, f32 *, f32, s32, s32, s32);

// Raycast from start to end, extended by margin. On a hit, stores the hit point
// backed off by margin in end.
int func_800FAB50(s32 start, s32 end, s32 normal, s32 filter, f32 margin)
{
    f32 offset[3];
    f32 hit_pos[3];
    s32 result;
    s32 hit;

    func_800EE7F8(hit_pos);
    func_800EFB24(offset, hit_pos, start);
    func_800EF368(offset, margin);
    func_800EF04C(hit_pos, offset);
    hit = func_800C6A7C(start, hit_pos, normal, filter);
    result = hit;
    if (hit == 0) {
        return 0;
    }
    func_800EF3DC(hit_pos, offset);
    func_800EE7F8(end, hit_pos);
    return result;
}

// func_800FAB50 with both endpoints raised by y_offset.
int func_800FABF4(s32 start, s32 end, f32 *normal, f32 *filter, f32 margin, f32 y_offset)
{
    f32 raised_start[3];
    f32 raised_end[3];
    s32 hit;
    // Matching: "| 0" is needed for the match.
    func_800EE7F8(raised_start, start | 0);
    func_800EE7F8(raised_end, end);
    raised_start[1] += y_offset;
    raised_end[1] += y_offset;
    if (!(hit = func_800FAB50(raised_start, raised_end, normal, filter, margin))) {
        return 0;
    }
    raised_end[1] -= y_offset;
    func_800EE7F8(end, raised_end);
    return hit;
}

// Ground snap: ray from 100 above to 500 below pos; raises pos to the hit point.
void func_800FACA0(f32 *pos, f32 param_1, void *filter)
{
    f32 normal[3];
    f32 top[3];
    f32 bottom[3];
    u8 *tri;
    func_800EE7F8(top, pos);
    func_800EE7F8(bottom, pos);
    top[1] += 100.0f;
    bottom[1] -= 500.0f;
    tri = func_800C6A7C(top, bottom, normal, filter);
    if (tri) {
        if (normal[1] < 0.0f && !(*(u32 *) (tri + 8) & 0x10000))
            return;
        if (pos[1] < bottom[1])
            pos[1] = bottom[1];
    }
}

// Sphere push-out at pos raised by y_offset, optionally followed by a ground snap.
void func_800FAD68(f32 *pos, f32 radius, f32 y_offset, s32 snap, s32 filter)
{
    f32 push[3];
    f32 center[3];
    f32 factor;
    func_800EFA4C(center, pos[0], pos[1] + y_offset, pos[2]);
    if (func_800C6C94(center, radius, push, filter)) {
        factor = 1.3f;
        pos[0] += factor * push[0];
        pos[1] += factor * push[1];
        pos[2] += factor * push[2];
        if (snap)
            func_800FACA0(pos, y_offset + radius, filter);
    }
}

// Like func_800FAD68, but also writes the pushed position to out_pos.
void func_800FAE44(f32 *pos, f32 *out_pos, f32 radius, f32 y_offset, s32 snap, s32 filter)
{
    f32 new_pos[3];
    f32 push[3];
    f32 center[3];
    // Matching: unused locals, needed for the match.
    s32 unk_0;
    s32 unk_1;
    func_800EFA4C(center, pos[0], pos[1] + y_offset, pos[2]);
    func_800EE7F8(out_pos, pos);
    if (func_800C6C94(center, radius, push, filter)) {
        out_pos[0] = pos[0] + push[0] * 2;
        out_pos[1] = pos[1] + push[1] * 2;
        out_pos[2] = pos[2] + push[2] * 2;
        new_pos[0] = pos[0] + push[0] * 2;
        new_pos[1] = pos[1] + push[1] * 2;
        new_pos[2] = pos[2] + push[2] * 2;
        func_800EE7F8(pos, new_pos);
        if (snap)
            func_800FACA0(pos, y_offset + radius, filter);
    }
}

// Wall-slide response: moves dest along the hit normal by at least 5 units.
void func_800FAF78(f32 *start, f32 *dest, u32 raised_start, s32 raised_dest, OSPiHandle *normal)
{
    f32 move[3];
    f32 raised_move[3];
    f32 diff[3];
    f32 dist;
    func_800EFB24(move, (s32) dest, (u32) start);
    func_800EFB24(raised_move, raised_dest, raised_start);
    func_800EFB24(diff, (s32) move, (u32) raised_move);
    dist = func_800EEAA4(normal, diff);
    dist = -dist;
    if (dist < 5.0f) {
        dist = 5.0f;
    }
    dest[0] += dist * ((f32 *) normal)[0];
    dest[1] += dist * ((f32 *) normal)[1];
    dest[2] += dist * ((f32 *) normal)[2];
}

// Wall-slide response, variant of func_800FAF78.
void func_800FB040(f32 *start, f32 *dest, f32 *raised_start, f32 *raised_dest, f32 *normal,
                   s32 update_side)
{
    f32 move[3];
    f32 raised_move[3];
    f32 diff[3];
    f32 slide_dir[3];
    f32 diff_dir[3];
    f32 diff_perp[3];
    f32 dist;
    f32 dot;
    func_800EFB24(move, dest, start);
    func_800EFB24(raised_move, raised_dest, raised_start);
    func_800EFB24(diff, move, raised_move);
    func_800EF410(diff_dir, diff);
    func_800EF934(diff_perp, diff_dir, 90.0f);
    dot = func_800EEAA4(normal, diff_dir);
    if (update_side)
        D_801357C0 = func_800EEAA4(normal, diff_perp);
    func_800EF934(slide_dir, normal, (D_801357C0 < 0.0f ? -1.0f : 1.0f) * dot * 45.0f);
    dist = -func_800EEAA4(slide_dir, diff);
    if (dist < 5.0f)
        dist = 5.0f;
    dest[0] += dist * slide_dir[0];
    dest[1] += dist * slide_dir[1];
    dest[2] += dist * slide_dir[2];
}

// Line of sight: returns the hit triangle, 0 if the path is clear.
int func_800FB1B0(f32 start[3], f32 end[3], f32 filter[3])
{
    f32 normal[3];
    f32 hit_pos[3];
    func_800EE7F8(hit_pos, end);
    return func_800C6A7C(start, hit_pos, normal, filter);
}

// Picks the first of t, 1.0, 0.0 whose point is visible from start; falls back to t.
f32 func_800FB1EC(s32 *param_0, f32 t, s32 start, s32 filter)
{
    // Matching: stack padding needed for the match.
    s8 _sfpad[8];
    s32 point;

    func_800C7A68(param_0, t, &point);
    if (func_800FB1B0(start, &point, filter) == 0) {
        return t;
    }
    func_800C7A68(param_0, 1.0f, &point);
    if (func_800FB1B0(start, &point, filter) == 0) {
        return 1.0f;
    }
    func_800C7A68(param_0, 0.0f, &point);
    if (func_800FB1B0(start, &point, filter) == 0) {
        return 0.0f;
    }
    return t;
}

// Vertical ray from pos+height down to pos-height; on a hit moves pos to the hit point.
s32 func_800FB2AC(s32 pos, f32 height)
{
    f32 normal[3];
    f32 bottom[3];
    f32 top[3];
    f32 offset[3];
    s32 result;
    s32 hit;

    func_800EFA4C(offset, 0.0f, height, 0.0f);
    func_800EE780(top, pos, offset);
    func_800EFB24(bottom, pos, offset);
    hit = func_800BEF00(top, bottom, normal, 0x1F00);
    result = hit;
    if (hit != 0) {
        hit = func_800EE7F8(pos, bottom);
    }
    return result;
}

int func_800FB338(f32 param_0[3], f32 param_1[3], f32 param_2[3], f32 param_3[3])
{
    s32 result;
    result = 0;
    param_3[0] = param_0[1];
    return result;
}

s32 func_800FB350(u8 *pos, s32 *param_1, f32 *out_y)
{
    s32 hit;
    f32 ground_pos[3];

    *param_1 = 0;
    *out_y = *(f32 *) (pos + 4);
    func_800EE7F8(ground_pos, pos);
    hit = func_800FB2AC(ground_pos, 20.0f);
    if (hit == 0) {
        return 0;
    }
    return func_800FB338(ground_pos, hit, param_1, out_y);
}

// Swept-sphere test that is skipped when the squared distance exceeds radius squared.
s32 func_800FB3C0(s32 start, s32 end, float radius, s32 normal, s32 param_4, s32 filter)
{
    float dist_sq = func_800EEB40();
    if (radius * radius < dist_sq) {
        return 0;
    }
    return func_800C6B78(start, end, radius, normal, param_4, filter);
}

// Swept sphere with both endpoints raised by y_offset; on a hit end is lowered back.
s32 func_800FB434(f32 *start, f32 *end, f32 y_offset, f32 radius, s32 normal, s32 param_5,
                  s32 filter)
{
    s32 hit;
    f32 raised_start[3];
    f32 raised_end[3];
    func_800EFA4C(raised_start, start[0], start[1] + y_offset, start[2]);
    func_800EFA4C(raised_end, end[0], end[1] + y_offset, end[2]);
    hit = func_800C6B78(raised_start, raised_end, radius, normal, param_5, filter);
    if (hit)
        func_800EFA4C(end, raised_end[0], raised_end[1] - y_offset, raised_end[2]);
    return hit;
}

// Copies a collision-triangle record (3 u16 vertex indices, s16, s32 flags).
void func_800FB508(u8 *dst, u8 *src)
{
    *(u16 *) (dst + 0) = *(u16 *) (src + 0);
    *(u16 *) (dst + 2) = *(u16 *) (src + 2);
    *(u16 *) (dst + 4) = *(u16 *) (src + 4);
    *(s32 *) (dst + 8) = *(s32 *) (src + 8);
    *(s16 *) (dst + 6) = *(s16 *) (src + 6);
}
