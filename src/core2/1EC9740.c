// 3D geometry helpers on top of vec3: containment and overlap tests, closest points, plane
// projection, and ray/segment intersections.
#include "common.h"

f32 func_800EFC7C(f32 *param_0, f32 *param_1);
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V_F0130;
extern float func_800EEFD4(float *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFA20(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800EEB40(f32 *param_0, f32 (*param_1)[3]);
extern void func_800EFA4C(f32 *, f32, f32, f32);
f32 func_800EEF94(s32);
s32 func_800EEEA8(void);
extern f32 func_800EEAA4(s32 param_0, s32 param_1);
extern void func_800EF174(s32 param_0, s32 param_1, f32 param_2);

// Vec3 lerp: dst = start + t * (end - start).
func_800EFE50(f32 *dst, f32 *start, f32 *end, f32 t)
{
    s32 i;
    for (i = 0; i < 3; i++) {
        dst[i] = start[i] + t * (end[i] - start[i]);
    }
}

// Point-in-AABB test (strict bounds).
s32 func_800EFED0(f32 box_min[3], f32 box_max[3], f32 point[3])
{
    f32 x;
    s32 inside_copy;
    f32 y;
    f32 z;
    unsigned char inside;
    x = point[0];
    inside = 0;
    if (box_min[0] < x) {
        inside = 1;
    }
    if (inside != 0) {
        inside = 0;
        if (x < box_max[0]) {
            inside = 1;
        }
        if (inside != 0) {
            y = point[1];
            inside = 0;
            if (box_min[1] < y) {
                inside = 1;
            }
            if (inside != 0) {
                inside = 0;
                if (y < box_max[1]) {
                    inside = 1;
                }
                // Matching: the extra copy is needed for the match.
                inside_copy = inside;
                if (inside_copy != 0) {
                    z = point[2];
                    inside = 0;
                    if (box_min[2] < z) {
                        inside = 1;
                    }
                    if (inside != 0) {
                        inside = 0;
                        if (z < box_max[2]) {
                            inside = 1;
                        }
                    }
                }
            }
        }
    }
    // Matching: needed for the match.
    if (inside) {
    }
}

// Point-in-sphere test.
s32 func_800EFFB4(f32 *center, f32 radius, f32 *point)
{
    f32 delta[3];
    func_800EFB24(delta, point, center);
    return func_800EEFD4(delta) <= radius * radius;
}

// Sphere-sphere overlap test.
s32 func_800F0008(s32 center_a, f32 radius_a, s32 center_b, f32 radius_b)
{
    f32 delta[3];

    func_800EFB24(delta, center_a, center_b);
    return func_800EEFD4(delta) <= ((radius_a + radius_b) * (radius_a + radius_b));
}

// Point-in-circle test in the XZ plane.
s32 func_800F0064(s32 center, f32 radius, s32 point)
{
    return func_800EFC7C(center, point) < radius * radius;
}

// Point-in-vertical-cylinder test; the y offsets are relative to center.
int func_800F00A4(f32 center[3], f32 radius, f32 y_top, f32 y_bottom, f32 point[3])
{
    if ((point[1] < (center[1] + y_bottom)) || ((center[1] + y_top) < point[1])) {
        return 0;
    }
    return (func_800EFC7C(center, point) < (radius * radius));
}

s32 func_800F0130(V_F0130 *center, s32 radius, V_F0130 *point)
{
    s32 d[3];
    d[0] = point->x - center->x;
    d[2] = point->z - center->z;
    return ((d[0] * d[0]) + (d[2] * d[2])) < (radius * radius);
}

// Closest point on the infinite line through line_start and line_end.
void func_800F018C(s32 out, s32 line_start, s32 line_end, float point[3])
{
    float dir[3];
    float to_point[3];
    float len_sq;
    func_800EFB24(dir, line_end, line_start);
    len_sq = func_800EEFD4(dir);
    if (len_sq < 0.01f) {
        func_800EE7F8(out, line_start);
    } else {
        len_sq = 1.0f / sqrtf(len_sq);
        dir[0] *= len_sq;
        dir[1] *= len_sq;
        dir[2] *= len_sq;
        func_800EFB24(to_point, point, line_start);
        func_800EFA20(out, dir, func_800EEAA4(to_point, dir));
        func_800EF04C(out, line_start);
    }
}

// Closest point on the segment seg_start..seg_end.
void func_800F0274(f32 *out, f32 *seg_start, f32 *seg_end, f32 *point)
{
    f32 dir[3];
    f32 to_point[3];
    f32 len;
    f32 proj;
    func_800EFB24(dir, seg_end, seg_start);
    len = func_800EEFD4(dir);
    if (len < 0.01f) {
        func_800EE7F8(out, seg_start);
    } else {
        len = sqrtf(len);
        proj = 1.0f / len;
        dir[0] *= proj;
        dir[1] *= proj;
        dir[2] *= proj;
        func_800EFB24(to_point, point, seg_start);
        proj = func_800EEAA4(to_point, dir);
        if (proj <= 0.0f) {
            func_800EE7F8(out, seg_start);
        } else if (len <= proj) {
            func_800EE7F8(out, seg_end);
        } else {
            func_800EFA20(out, dir, proj);
            func_800EF04C(out, seg_start);
        }
    }
}

// Projects point onto the plane through plane_point with the given normal.
void func_800F03AC(s32 *out, s32 *plane_point, s32 normal, s32 point)
{
    s8 _sfpad[8];
    s32 offset;

    func_800EFB24(&offset, point, plane_point);
    func_800EFA20(&offset, normal, func_800EEAA4(normal, &offset));
    func_800EFB24(out, point, &offset);
}

// Closest point on the triangle's edges.
void func_800F0410(f32 *out, f32 *tri, f32 (*point)[3])
{
    f32 dist_ab;
    f32 dist_bc;
    f32 dist_ca;
    f32 closest_ab[3];
    f32 closest_bc[3];
    f32 closest_ca[3];
    func_800F0274(closest_ab, tri, tri + 3, point);
    func_800F0274(closest_bc, tri + 3, tri + 6, point);
    func_800F0274(closest_ca, tri + 6, tri, point);
    dist_ab = func_800EEB40(closest_ab, point);
    dist_bc = func_800EEB40(closest_bc, point);
    dist_ca = func_800EEB40(closest_ca, point);
    if (dist_ab < dist_bc) {
        if (dist_ca < dist_ab) {
            func_800EE7F8(out, closest_ca);
        } else {
            func_800EE7F8(out, closest_ab);
        }
    } else if (dist_ca < dist_bc) {
        func_800EE7F8(out, closest_ca);
    } else {
        func_800EE7F8(out, closest_bc);
    }
}

// Projects point onto the triangle's plane.
int func_800F0524(s32 out, s32 tri, s32 point)
{
    f32 edge1[3];
    f32 edge2[3];
    f32 normal[3];
    func_800EFB24(edge1, tri + 0xC, tri);
    func_800EFB24(edge2, tri + 0x18, tri);
    func_800EE97C(normal, edge1, edge2);
    func_800EF2A0(normal);
    func_800F03AC(out, tri, normal, point);
}

// Reflects vec about normal.
void func_800F059C(void *out, void *vec, void *normal)
{
    f32 scaled_normal[3];
    f32 dot;
    func_800EFA20(out, vec, -1.0f);
    dot = func_800EEAA4(out, normal);
    func_800EFA20(scaled_normal, normal, dot + dot);
    func_800EFB24(out, scaled_normal, out);
}

// Ray vs circle in XZ: solves a*t^2 + b*t + c = 0, stores the t values in out_t and
// returns how many there are.
int func_800F05F8(f32 *origin, f32 *dir, f32 *center, f32 radius, f32 *out_t)
{
    f32 offset[3];
    f32 a;
    f32 b;
    f32 c;
    f32 b_sq;
    offset[0] = origin[0] - center[0];
    offset[2] = origin[2] - center[2];
    a = dir[0] * dir[0] + dir[2] * dir[2];
    if (a == 0.0f)
        return 0;
    b = 2.0f * (dir[0] * offset[0] + dir[2] * offset[2]);
    c = offset[0] * offset[0] + offset[2] * offset[2] - radius * radius;
    b_sq = b * b;
    radius = 4.0f * a * c;
    if (b_sq < radius)
        return 0;
    c = sqrtf(b_sq - radius);
    a = 0.5f / a;
    out_t[0] = (c - b) * a;
    if (c != 0.0f) {
        out_t[1] = -(b + c) * a;
        return 2;
    }
    return 1;
}

// Segment vs vertical cylinder (base center plus height); writes the entry and exit points
// and returns 1 on a hit.
s32 func_800F0734(f32 *seg_start, f32 *seg_end, f32 *base, f32 radius, f32 height, f32 *out_enter,
                  f32 *out_exit)
{
    f32 rel_start[3];
    f32 rel_end[3];
    f32 seg_dir[3];
    f32 closest[3];
    f32 radius_sq;
    f32 dot;
    f32 len_sq;
    f32 dist_sq;
    f32 top;
    f32 len;
    f32 t_closest;
    f32 t_half;
    f32 t_exit;
    f32 t_enter;
    func_800EFB24(rel_start, seg_start, base);
    func_800EFB24(rel_end, seg_end, base);
    func_800EFB24(seg_dir, rel_end, rel_start);
    dot = rel_start[0] * seg_dir[0] + rel_start[2] * seg_dir[2];
    len_sq = seg_dir[0] * seg_dir[0] + seg_dir[2] * seg_dir[2];
    if (len_sq != 0.0f) {
        if (-dot / len_sq < 0.0f) {
            func_800EE7F8(closest, rel_start);
        } else if (-dot / len_sq < 1.0f) {
            func_800EFA20(closest, seg_dir, -dot / len_sq);
            func_800EF04C(closest, rel_start);
        } else {
            func_800EE7F8(closest, rel_end);
        }
        radius_sq = radius * radius;
        dist_sq = closest[0] * closest[0] + closest[2] * closest[2];
        if (radius_sq < dist_sq)
            return 0;
        t_closest = -dot / len_sq;
        len = sqrtf(len_sq);
        t_half = sqrtf(radius_sq - dist_sq) / len;
        t_enter = t_closest - t_half > 0.0f ? t_closest - t_half : 0.0f;
        t_exit = t_closest + t_half < 1.0f ? t_closest + t_half : 1;
        func_800EFE50(out_enter, seg_start, seg_end, t_enter);
        func_800EFE50(out_exit, seg_start, seg_end, t_exit);
        top = base[1] + height;
        if (base[1] <= out_enter[1] && out_enter[1] < top)
            return 1;
        if (base[1] <= out_exit[1] && out_exit[1] < top)
            return 1;
        return 0;
    } else {
        if (func_800F0064(seg_start, radius, base)) {
            if (seg_start[1] < base[1] && base[1] < seg_end[1]) {
                func_800EE7F8(out_enter, base);
                func_800EFA4C(out_exit, base[0], base[1] + height, base[2]);
                return 1;
            }
            top = base[1] + height;
            if (top < seg_start[1] && seg_end[1] < top) {
                func_800EFA4C(out_enter, base[0], top, base[2]);
                func_800EE7F8(out_exit, base);
                return 1;
            }
        }
        return 0;
    }
}

// 2D (XZ) segment-segment intersection test.
int func_800F0AA4(f32 *a_start, f32 *a_end, f32 *b_start, f32 *b_end)
{
    f32 line_a;
    f32 line_b;
    f32 line_c;
    f32 side_start;
    f32 side_end;
    line_a = a_end[2] - a_start[2];
    line_b = a_start[0] - a_end[0];
    line_c = a_end[0] * a_start[2] - a_start[0] * a_end[2];
    side_start = line_a * b_start[0] + line_b * b_start[2] + line_c;
    side_end = line_a * b_end[0] + line_b * b_end[2] + line_c;
    if (side_start * side_end > 0.0f)
        return 0;
    line_a = b_end[2] - b_start[2];
    line_b = b_start[0] - b_end[0];
    line_c = b_end[0] * b_start[2] - b_start[0] * b_end[2];
    side_start = line_a * a_start[0] + line_b * a_start[2] + line_c;
    side_end = line_a * a_end[0] + line_b * a_end[2] + line_c;
    if (side_start * side_end > 0.0f)
        return 0;
    return 1;
}

s32 func_800F0BD0(s32 dir, s32 vec, f32 max_dot, f32 min_ratio)
{
    f32 dot;
    f32 dir_len;
    float ratio;
    s32 result;
    if (func_800EEEA8() != 0) {
        return 0;
    }
    dot = func_800EEAA4(vec, dir);
    if (max_dot < dot) {
        return 0;
    }
    dir_len = func_800EEF94(dir);
    // Matching: the extra temporaries and the same-type cast are needed for the match.
    ratio = dot / dir_len;
    result = 1;
    dot = ratio;
    if ((float) dot < min_ratio) {
        return 0;
    }
    return result;
}

f32 func_800F0C68(s32 unk_0, s32 vec, f32 x, f32 y)
{
    func_800EF2A0(vec);
    return x / sqrtf((x * x) + (y * y));
}

// Ray-plane intersection; returns 0 when the ray is parallel to the plane.
s32 func_800F0CB4(s32 origin, s32 dir, s32 plane_point, s32 normal)
{
    f32 denom;
    f32 origin_dist;
    f32 plane_dist;
    f32 t;

    denom = func_800EEAA4(dir, normal);
    if (denom == 0.0f) {
        return 0;
    }
    plane_dist = func_800EEAA4(normal, plane_point);
    origin_dist = func_800EEAA4(origin, normal);
    t = plane_dist - origin_dist;
    t = t / denom;
    func_800EF174(origin, dir, t);
    return 1;
}
