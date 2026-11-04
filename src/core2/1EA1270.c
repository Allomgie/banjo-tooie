// Probably an API over path/spline objects: picks the evaluator by point count, evaluates
// position and direction at t, steps by arc length, and finds the parameter of a point.
#include "core2/1EA1270.h"

extern void _mlspline_entrypoint_6(void);
extern void _mlspline_entrypoint_7(void);
extern void _mlspline_entrypoint_8(void);
extern void _mlspline_entrypoint_10(void);
extern u8 _mlspline_entrypoint_0[];
extern u8 _mlspline_entrypoint_5[];
extern u8 _mlspline_entrypoint_4[];
extern u8 _mlspline_entrypoint_2[];
extern f32 _mlspline_entrypoint_13(s32, s32 *, f32, f32, f32, s32);
// TU-NOTE: path header: u8 point count at +2, u8 subtype at +3, flag at +4; points start at +0x14.
typedef struct {
    s16 pad_0;
    u8 point_count;
    u8 pad_3[0x11];
    f32 points[1][3];
} PathC7BCC;
typedef struct {
    s16 unk_0;
    u8 point_count, pad_3[9];
    f32 loop_t;
    s32 unk_10;
    f32 points[1][3];
} LocalSpline;
extern float func_800D8FF8(void);
extern float _glintrosyncDll_entrypoint_5(void);
typedef void (*FN_C810C)(f32, u8, void *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void func_800EF2A0(f32 *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);

// Spline evaluation and dispatch, direction angles, arc-length stepping, nearest-parameter search.
// Pick the evaluator by point count: linear (2), quadratic (3), cubic or closed cubic.
FN_C810C func_800C7980(path)
u8 *path;
{
    short point_count;
    u8 subtype;
    // Matching: extra temporary needed for the match.
    unsigned short subtype_copy;
    point_count = path[2];
    subtype_copy = (subtype = path[3]);
    if (point_count < 2) {
        return 0;
    }
    if (point_count == 2) {
        return _mlspline_entrypoint_6;
    }
    // Matching: the unsigned long cast is needed for the match.
    if ((unsigned long) point_count == 3) {
        return _mlspline_entrypoint_7;
    }
    if (subtype == 1) {
        return _mlspline_entrypoint_10;
    }
    return _mlspline_entrypoint_8;
}

// Pick the direction evaluator by point count and subtype.
void (*func_800C79EC(Unk800C7A68 *path))(f32, u8, s32 *, s32)
{
    u8 subtype;
    short point_count;
    point_count = *(u8 *) ((char *) path + 2);
    subtype = *(u8 *) ((char *) path + 3);
    if (point_count < 2) {
        return 0;
    }
    if (point_count == 2) {
        return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_0;
    }
    if (point_count == 3) {
        return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_2;
    }
    if (subtype == 1) {
        return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_5;
    }
    return (void (*)(f32, u8, s32 *, s32)) _mlspline_entrypoint_4;
}

void func_800C7A58(void)
{
}

void func_800C7A60(void)
{
}

// Evaluate the position at t (clamped to 0..1).
void func_800C7A68(Unk800C7A68 *path, f32 t, f32 *out_pos)
{
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }

    func_800C79EC(path)(t, path->unk2, &path->unk14, out_pos);
}

void func_800C7AE4(u8 *path, s32 param_1, s32 param_2)
{
    _mlspline_entrypoint_11(*(u8 *) ((s8 *) path + 2), path + 0x14, param_1, param_2,
                            func_800C7980());
}

int func_800C7B28(s32 path, s32 param_1, s32 param_2, volatile int param_3)
{
    int point_count;
    u32 evaluator;
    evaluator = func_800C7980();
    point_count = *(u8 *) (path + 2);
    _mlspline_entrypoint_12(point_count, path + 0x14, param_1, param_2, param_3 << 1, evaluator);
}

f32 func_800C7B7C(Unk800C7A68 *path, f32 param_1, f32 param_2, f32 param_3)
{
    return _mlspline_entrypoint_13(path->unk2, &path->unk14, param_1, param_2, 0.0f,
                                   func_800C7980());
}

// Parameter t of the point that exactly equals `pos`, or -1.0 if there is none.
f32 func_800C7BCC(PathC7BCC *path, f32 *pos)
{
    f32(*cur)[3];
    f32(*end)[3];
    s32 index;
    s32 point_count;
    point_count = path->point_count;
    cur = path->points;
    end = point_count + path->points;
    index = 0;
    for (; cur != end; cur++) {
        if (*cur[0] == pos[0] && (*cur)[1] == pos[1] &&
            (*cur)[2] == pos[2]) {
            return (f32) index / (point_count - 1);
        }
        index++;
    }
    return -1.0f;
}

// Find the loop point (first point equal to the last one) and cache its t in the path.
f32 func_800C7E28(LocalSpline *path)
{
    s32 point_count;
    s32 index;
    f32(*cur)[3];
    f32(*last)[3];
    point_count = path->point_count;
    cur = path->points;
    last = cur + point_count - 1;
    for (index = 0; cur != last; cur++, index++) {
        if (*cur[0] == *last[0] && (*cur)[1] == (*last)[1] &&
            (*cur)[2] == (*last)[2]) {
            return path->loop_t = (f32) index / (f32) (point_count - 1);
        }
    }
    return path->loop_t = 1.0f;
}

// Advance along a path with game time or intro-sync time.
// Advance t by speed * frame time; the flag at +4 selects intro-sync time over game time.
f32 func_800C7FD4(unsigned char *path, f32 t, float speed)
{
    // Matching: unused local needed for the match.
    int unk_0;
    float loop_t;
    float frame_dt;

    if (*(unsigned char *) ((signed char *) path + 4) != 0) {
        frame_dt = _glintrosyncDll_entrypoint_5();
    } else {
        frame_dt = func_800D8FF8();
    }
    loop_t = func_800C7E28(path);
    return _mlspline_entrypoint_13(*(unsigned char *) ((signed char *) path + 2),
                                   (s32 *) (path + 0x14), t, frame_dt * speed, loop_t,
                                   (s32) func_800C7980(path));
}

// Advance t; *wrapped is set when t moved past the path end in the direction of travel.
f32 func_800C8070(f32 path[3], f32 t, f32 speed, s32 *wrapped)
{
    f32 new_t = func_800C7FD4(path, t, speed);
    *wrapped = 0;
    if (speed > 0.0f) {
        if (new_t < t) {
            *wrapped = 1;
        }
    } else if (speed < 0.0f) {
        if (new_t > t) {
            *wrapped = 1;
        }
    }
    return new_t;
}

// Tangent at t and the angles derived from it.
void func_800C810C(void *path, f32 t, f32 *tangent, f32 *angles)
{
    FN_C810C eval = func_800C7980(path);
    eval(t, *(u8 *) ((u8 *) path + 2), (u8 *) path + 0x14, tangent);
    func_800F1A88(tangent, angles);
    angles[0] = func_800136E4(angles[0]);
    angles[1] = func_800136E4(angles[1] + 180.0f);
    angles[2] = 0.0f;
    func_800EF2A0(tangent);
}

// Sample t from `from` to `to` in steps of `step`; return the t whose position is
// closest to `point`.
f32 func_800C8198(Unk800C7A68 *path, f32 *point, f32 from, f32 to, f32 step)
{
    f32 diff[3];
    f32 pos[3];
    f32 t;
    f32 best_dist;
    f32 best_t;
    f32 dist;
    from = func_800F0E00(0.0f, from);
    to = func_800F13F0(1.0f, to);
    best_dist = 1e+08f;
    best_t = from;
    t = from;
    while (1) {
        func_800C7A68(path, t, pos);
        func_800EFB24(diff, point, pos);
        dist = diff[0] * diff[0] + diff[1] * diff[1] + diff[2] * diff[2];
        if (dist < best_dist) {
            best_dist = dist;
            best_t = t;
        }
        if (t == to)
            break;
        t += step;
        if (t > to)
            t = to;
    }
    return best_t;
}

// Parameter t of `point` on the path: exact match first, otherwise a coarse 0.01 search
// followed by five refinement passes.
f32 func_800C82CC(Unk800C7A68 *path, f32 *point)
{
    f32 t;
    f32 step;
    f32 lo;
    f32 hi;
    f32 best_pos[3];
    f32 end_pos[3];
    t = func_800C7BCC(path, point);
    if (0 <= t)
        return t;
    step = 0.01f;
    t = func_800C8198(path, point, 0.0f, 1.0f, step);
    lo = t - step;
    hi = t + step;
    step = step / 10.0f + step / 10.0f;
    t = func_800C8198(path, point, lo, hi, step);
    lo = t - step;
    hi = t + step;
    step = step / 10.0f + step / 10.0f;
    t = func_800C8198(path, point, lo, hi, step);
    lo = t - step;
    hi = t + step;
    step = step / 10.0f + step / 10.0f;
    t = func_800C8198(path, point, lo, hi, step);
    lo = t - step;
    hi = t + step;
    step = step / 10.0f + step / 10.0f;
    t = func_800C8198(path, point, lo, hi, step);
    lo = t - step;
    hi = t + step;
    step = step / 10.0f + step / 10.0f;
    t = func_800C8198(path, point, lo, hi, step);
    func_800C7A68(path, t, best_pos);
    func_800C7A68(path, 1.0f, end_pos);
    // Keep t only if it is closer to `point` than the path end.
    if (func_800EEB40(point, best_pos) < func_800EEB40(point, end_pos))
        return t;
    return 1.0f;
}

void func_800C84A4(u8 *path, int subtype)
{
    *(s8 *) ((s8 *) path + 3) = subtype;
}
