// The view (camera lens) object: position, rotation, FOV, aspect, near/far, matrices and frustum
// planes, with frustum culling tests and the perspective matrix (a guPerspective equivalent).
#include "core2/1EA3AA0.h"
#include <types.h>

extern void func_800EF8BC(void *, void *, f32);
extern void func_800EF934(void *, void *, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
typedef struct {
    u8 pad_0[0xE8];
    f32 aspect;
    u8 pad_EC[0x24];
    f32 unk_110;
    f32 unk_114;
    f32 unk_118;
    f32 unk_11C;
    f32 unk_120;
    f32 unk_124;
} S_CA2A8;
extern f32 func_800137F4(f32);
extern f32 func_80013788(void);
extern void func_800EF2A0(f32 *);
typedef struct {
    u8 pad_0[0x18];
    s32 pitch;
    s32 yaw;
} S_CA3A4;
extern void func_800EF4E4(f32 *, s32, s32, f32, f32, f32);
extern void func_800EF04C(S_CA3A4 *, f32 *);
typedef struct Actor {
    char pad_0[0xE4];
    f32 fov;
    f32 aspect;
    char pad_EC[8];
    f32 cot;
} Actor;
extern f32 func_800139F8(float);
typedef struct {
    char pad_0[0xEC];
    f32 near;
} unk_struct;
typedef struct {
    u8 pad_0[0x24];
    f32 planes[4][4];
} LocalPlanes;
typedef struct {
    u8 pad_0[0x24];
    f32 planes[4][4];
} StateCAB70;
f32 func_800EEAA4();
void func_800136E4(f32);
typedef struct {
    f32 pos[3], forward[3], rot[3];
    f32 world_plane_0[4], world_plane_1[4], world_plane_2[4], world_plane_3[4];
    f32 unk_64[4][4], unk_A4[4][4];
    u8 pad_E4[0x14];
    f32 unk_F8[3], unk_104[3], unk_110[3], unk_11C[3];
    f32 unk_128[3], unk_134[3], unk_140[3], unk_14C[3], unk_158[3];
} ViewCAF34;
extern void func_800D93A0(f32 *, f32 *);
extern void func_800D965C(f32 *, f32 (*)[4]);
extern void func_800D9624(f32 *, f32 *);
extern void mlMtxSet(f32 (*)[4]);
extern void func_80019224(f32 *, f32 *);
extern void func_80019480(f32 *, f32, f32, f32);
typedef struct {
    u8 pad_0[0xE8];
    f32 aspect;
    f32 near;
    f32 far;
    f32 cot;
} StateCB124;
extern void func_800F274C(f32 mf[4][4]);
void func_800CA440();
void func_800CA5F8(s32 param_0, f32 param_1, f32 param_2, f32 param_3);
int func_800CA688(s32 param_0[3], f32 param_1, f32 param_2, f32 param_3);
int func_800CA6C0(f32 param_0[3], f32 param_1, f32 param_2);
void func_800CA6F0(f32 *param_0, f32 param_1);
void func_800CAF34();

void func_800CA1B0(u8 *view)
{
    s32 vec;
    u8 *base;
    base = view + 0xF8;
    // Matching: empty block and the `base` reassignment below are needed for the match.
    if (0) {
    }
    vec = base;
    func_800EFA4C(vec, -1.0f, 0.0f, 0.0f);
    func_800EF934(vec, vec,
                  *(f32 *) (view + 0xE8) * (*(f32 *) ((base = view) + 0xE4) * 0.5f));
}

void func_800CA218(u8 *view, f32 half_fov)
{
    func_800EFA4C((f32 *) (view + 0x104), 0.0f, 1.0f, 0.0f);
    func_800EF8BC((f32 *) (view + 0x104), (f32 *) (view + 0x104), half_fov);
    func_800EFA4C((f32 *) (view + 0xF8), -1.0f, 0.0f, 0.0f);
    func_800EF934((f32 *) (view + 0xF8), (f32 *) (view + 0xF8),
                  ((f32 *) view)[0xE8 / 4] * half_fov);
}

void func_800CA2A8(S_CA2A8 *view, f32 half_fov)
{
    f32 s;
    f32 c;
    view->unk_110 = 0.0f;
    s = func_800137F4(half_fov);
    view->unk_120 = s;
    view->unk_114 = -s;
    c = func_80013788();
    view->unk_124 = -c;
    view->unk_118 = -c;
    view->unk_11C = view->unk_120 * view->aspect;
    func_800EF2A0(&view->unk_11C);
}

void func_800CA314(s32 dst, s32 src)
{
    aligned4_memcpy(dst, src, 0x168);
}

int func_800CA334()
{
    void *view;
    view = heap_alloc(0x168);
    // Matching: `| 0` is needed for the match.
    func_800CA440((s32) view | 0);
    return (int) view;
}

void func_800CA364(void *view)
{
    heap_free(view);
}

void *func_800CA384(void *view)
{
    return defrag(view);
}

void func_800CA3A4(S_CA3A4 *view, f32 distance)
{
    f32 delta[3];
    func_800EF4E4(delta, view->pitch, view->yaw, 0.0f, 0.0f, distance);
    func_800EF04C(view, delta);
}

int func_800CA3F4(s32 param_0, s32 view, f32 param_2[3])
{
    f32 offset[3];
    // Matching: `| 0` is needed for the match.
    func_800EFB24(offset, param_0 | 0, view);
    func_800EF368(offset, param_2);
    func_800EF04C(view, offset);
}

// Sets the defaults: FOV 40, aspect 4:3, near 1, far 10000.
void func_800CA440(view) Actor *view;
{
    f32 half_fov;
    func_800CA5F8(view, 0.0f, 0.0f, 0.0f);
    func_800CA688(view, 0.0f, 0.0f, 0.0f);
    func_800CA6C0(view, 1.0f, 10000.0f);
    func_800CA6F0(view, 1.0f);
    view->fov = 40.0f;
    half_fov = view->fov * 0.5f;
    view->cot = 1.0f / func_800139F8(half_fov);
    view->aspect = 1.3333334f;
    func_800CA218(view, half_fov);
    func_800CA2A8(view, half_fov);
    func_800CAF34(view);
}

// Sets the aspect ratio.
int func_800CA510(f32 view[3], f32 aspect)
{
    *(f32 *) ((s8 *) view + 232) = aspect;
    func_800CA1B0(view);
    func_800CA2A8(view, view[57] * 0.5f);
}

// Sets the FOV.
void func_800CA558(void *view, f32 fov)
{
    f32 half = fov * 0.5f;
    *(f32 *) ((u8 *) view + 0xE4) = fov;
    *(f32 *) ((u8 *) view + 0xF4) = 1.0f / func_800139F8(half);
    func_800CA218(view, half);
    func_800CA2A8(view, half);
}

void func_800CA5B8()
{
    func_800EE7F8();
}

void func_800CA5D8()
{
    func_800EE84C();
}

// Sets the position.
void func_800CA5F8(s32 view, f32 x, f32 y, f32 z)
{
    func_800EFA4C(view, x, y, z);
}

// Sets position and rotation.
func_800CA628(f32 view[3], f32 pos[3], f32 rot[3])
{
    s32 i;
    for (i = 0; i < 3; i++) {
        view[i] = pos[i];
        view[i + 6] = rot[i];
    }
}

int func_800CA668(s32 view)
{
    func_800EE7F8(view + 0x18);
}

// Sets the rotation.
int func_800CA688(s32 view[3], f32 pitch, f32 yaw, f32 roll)
{
    func_800EFA4C(&view[6], pitch, yaw, roll);
}

// Sets near and far.
int func_800CA6C0(f32 view[3], f32 near_plane, f32 far_plane)
{
    f32 near_tmp;
    f32 far_tmp;
    // Matching: the temporaries and `* 1.0f` are needed for the match.
    *(f32 *) ((s8 *) view + 236) = (near_tmp = near_plane);
    view[60] = (far_tmp = far_plane) * 1.0f;
}

// Gets near and far.
int func_800CA6D4(f32 *view, f32 *near_out, f32 *far_out)
{
    f32 *far_dst;
    int near_idx;
    // Matching: the aliases and index temporary are needed for the match.
    far_dst = far_out;
    *near_out = view[near_idx = 59];
    *far_dst = view[60];
}

f32 func_800CA6E8(f32 *view)
{
    return view[89];
}

void func_800CA6F0(f32 *view, f32 param_1)
{
    view[0x59] = param_1;
}

// Returns the aspect ratio.
f32 func_800CA6FC(f32 *view)
{
    return view[58];
}

void func_800CA704(s32 view, s32 point, s32 delta)
{
    func_800EFB24(delta, point, view);
    func_800EEAA4(view + 0xC, delta);
}

int func_800CA740(s32 view, s32 dst)
{
    // Matching: `| 0` is needed for the match.
    func_800EE7F8(dst | 0, view + 0xC);
}

int func_800CA768(s32 param_0, s32 param_1)
{
    // Matching: `| 0` is needed for the match.
    func_800EEAD4(param_1 | 0, param_0 | 0);
}

// Returns the FOV.
f32 func_800CA794(f32 *view)
{
    return view[57];
}

// Returns cot(FOV / 2).
f32 func_800CA79C(f32 *view)
{
    return view[61];
}

int func_800CA7A4(s32 view)
{
    return view + 100;
}

int func_800CA7AC(s32 view)
{
    long addr;
    addr = view;
    return addr + 0xA4;
}

f32 func_800CA7B4(unk_struct *view)
{
    return view->near;
}

// Gets FOV, aspect, near and far.
int func_800CA7BC(f32 view[4], f32 *fov, f32 *aspect, f32 *near, f32 *far)
{
    *fov = view[57];
    *aspect = view[58];
    *near = view[59];
    *far = view[60];
}

int func_800CA7E4(s32 view, s32 dst)
{
    // Matching: `| 0` is needed for the match.
    func_800EE7F8(dst | 0, view | 0);
}

// Truncates the position to 1/500 steps.
void func_800CA810(f32 pos[3], s32 *out)
{
    out[0] = (s32) ((f32) (s32) (pos[0] * 500.0f) / 500.0f);
    out[1] = (s32) ((f32) (s32) (pos[1] * 500.0f) / 500.0f);
    out[2] = (s32) ((f32) (s32) (pos[2] * 500.0f) / 500.0f);
}

func_800CA8B4(f32 view[3], f32 pos[3], f32 rot[3])
{
    s32 i;
    for (i = 0; i < 3; i++) {
        pos[i] = view[i];
        rot[i] = view[i + 6];
    }
}

func_800CA8F4(f32 view[3], f32 pos[3], f32 forward[3])
{
    s32 i;
    for (i = 0; i < 3; i++) {
        pos[i] = view[i];
        forward[i] = view[i + 3];
    }
}

// Truncates the position to 1/500 steps, stored as s16.
void func_800CA934(u8 *pos, u8 *out)
{
    (*(s16 *) ((s8 *) (out) + (0))) =
        (s16) (s32) ((f32) (s32) ((*(f32 *) ((s8 *) (pos) + (0))) * 500.0f) / 500.0f);
    (*(s16 *) ((s8 *) (out) + (2))) =
        (s16) (s32) ((f32) (s32) ((*(f32 *) ((s8 *) (pos) + (4))) * 500.0f) / 500.0f);
    (*(s16 *) ((s8 *) (out) + (4))) =
        (s16) (s32) ((f32) (s32) ((*(f32 *) ((s8 *) (pos) + (8))) * 500.0f) / 500.0f);
}

void func_800CA9D8(f32 *view, s32 *dst)
{
    // Matching: the extra copies of the parameters are needed for the match.
    s32 dst_copy = dst;
    s32 view_addr = view;
    func_800EE7F8(dst, view_addr + 0x18);
}

// Gets the rotation.
void func_800CAA00(f32 *view, f32 *pitch, f32 *yaw, f32 *roll)
{
    *pitch = view[6];
    *yaw = view[7];
    *roll = view[8];
}

// Returns the yaw.
f32 func_800CAA1C(f32 *view)
{
    return view[7];
}

// AABB vs the four frustum planes; returns 1 if possibly visible.
s32 func_800CAA24(LocalPlanes *view, f32 *box_max, f32 *box_min)
{
    s32 i;
    f32 term_x, term_y, term_z;
    f32 *plane;
    for (i = 0; i < 4; i++) {
        plane = view->planes[i];
        term_x = plane[0];
        term_y = plane[1];
        term_z = plane[2];
        term_x *= term_x >= 0.0f ? box_max[0] : box_min[0];
        term_y *= term_y >= 0.0f ? box_max[1] : box_min[1];
        term_z *= term_z >= 0.0f ? box_max[2] : box_min[2];
        if (plane[3] + (term_x + term_y + term_z) >= 0.0f)
            return 0;
    }
    return 1;
}

// Same as func_800CAA24, with s16 box corners.
s32 func_800CAB70(StateCAB70 *view, s16 *box_max, s16 *box_min)
{
    s32 i;
    f32 term_x;
    f32 term_y;
    f32 term_z;
    f32 *plane;
    for (i = 0; i < 4; i++) {
        plane = view->planes[i];
        term_x = view->planes[i][0];
        term_y = view->planes[i][1];
        term_z = view->planes[i][2];
        term_x *= term_x >= 0.0f ? box_max[0] : box_min[0];
        term_y *= term_y >= 0.0f ? box_max[1] : box_min[1];
        term_z *= term_z >= 0.0f ? box_max[2] : box_min[2];
        if (plane[3] + (term_x + term_y + term_z) >= 0.0f)
            return 0;
    }
    return 1;
}

// Sphere vs the four frustum planes; returns 1 if possibly visible.
s32 func_800CACEC(u8 *view, u8 *center, f32 radius)
{
    // Matching: volatile and the goto loop are needed for the match.
    volatile f32 delta_z;
    volatile f32 delta_y;
    f32 delta_x;
    s32 offset;
    u8 *plane;

    offset = 0;
    plane = view + 0x24;
    delta_x = (*(f32 *) ((s8 *) center + 0)) - (*(f32 *) ((s8 *) view + 0));
    delta_y = (*(f32 *) ((s8 *) center + 4)) - (*(f32 *) ((s8 *) view + 4));
    delta_z = (*(f32 *) ((s8 *) center + 8)) - (*(f32 *) ((s8 *) view + 8));
loop_1:
    if (radius <= func_800EEAA4(&delta_x, plane)) {
        return 0;
    }
    offset += 0x10;
    plane += 0x10;
    if (offset == 0x40) {
        return 1;
    }
    goto loop_1;
}

// Point inside all four frustum planes.
int func_800CAD9C(f32 *view, f32 x, f32 y, f32 z)
{
    if ((view[9] * x + view[10] * y + view[11] * z + view[12] <=
         0.0f) &&
        (view[13] * x + view[14] * y + view[15] * z + view[16] <=
         0.0f) &&
        (view[17] * x + view[18] * y + view[19] * z + view[20] <=
         0.0f) &&
        (view[21] * x + view[22] * y + view[23] * z + view[24] <=
         0.0f))
        return 1;
    return 0;
}

// Point against the third frustum plane only.
int func_800CAEA4(f32 view[3], f32 x, f32 y, f32 z)
{
    return (((view[17] * x) + (view[18] * y)) + (view[19] * z) +
            view[20]) <= 0.0f;
}

f32 func_800CAF00(f32 view[3], f32 offset)
{
    func_800136E4(view[7] + offset + 90.0f);
}

// Rebuilds the matrices and frustum planes from position and rotation.
void func_800CAF34(view) ViewCAF34 *view;
{
    f32 quat_0[4];
    f32 quat_1[4];
    func_800D93A0(quat_0, view->rot);
    func_800D965C(quat_0, view->unk_64);
    func_800D9624(quat_1, quat_0);
    func_800D965C(quat_1, view->unk_A4);
    mlMtxSet(view->unk_64);
    func_800EFA4C(view->forward, 0.0f, 0.0f, -1.0f);
    func_80019224(view->forward, view->forward);
    func_80019224(view->world_plane_0, view->unk_F8);
    func_80019480(view->world_plane_1, -view->unk_F8[0], view->unk_F8[1], view->unk_F8[2]);
    func_80019224(view->world_plane_2, view->unk_104);
    func_80019480(view->world_plane_3, view->unk_104[0], -view->unk_104[1],
                  view->unk_104[2]);
    view->world_plane_0[3] = -func_800EEAA4(view->pos, view->world_plane_0);
    view->world_plane_1[3] = -func_800EEAA4(view->pos, view->world_plane_1);
    view->world_plane_2[3] = -func_800EEAA4(view->pos, view->world_plane_2);
    view->world_plane_3[3] = -func_800EEAA4(view->pos, view->world_plane_3);
    func_80019480(view->unk_128, -view->unk_11C[0], -view->unk_11C[1],
                  view->unk_11C[2]);
    func_80019224(view->unk_134, view->unk_11C);
    func_80019224(view->unk_140, view->unk_110);
    func_80019480(view->unk_14C, -view->unk_11C[0], view->unk_11C[1],
                  view->unk_11C[2]);
    func_80019480(view->unk_158, view->unk_11C[0], -view->unk_11C[1],
                  view->unk_11C[2]);
}

void func_800CB0E8(s32 view, u32 dst, s32 index)
{
    func_800EE7F8(dst, (void *) ((char *) view + 0x128 + index * 0xC));
}

// guPerspectiveF equivalent; returns perspNorm.
u16 func_800CB124(StateCB124 *view, f32 mf[4][4])
{
    u16 perspNorm;
    f32 tmp;
    f32 near;
    f32 far;
    s32 i;
    s32 j;
    near = view->near;
    far = view->far;
    if (near < 1.0f)
        near = 1.0f;
    if (far < near + 100.0f)
        far = near + 100.0f;
    tmp = ((2 * near) * far) / (near - far);
    if (((tmp * 0.5f) > 32767) || ((tmp * 0.5f) < (-32767))) {
        tmp = ((tmp * 0.5f) > 32767) ? (32767) : (-32767);
        near = ((-(tmp / 0.5f)) * far) / ((2 * far) - (tmp / 0.5f));
    }
    func_800F274C(mf);
    mf[0][0] = view->cot / view->aspect;
    mf[1][1] = view->cot;
    mf[2][2] = (near + far) / (near - far);
    mf[2][3] = -1;
    mf[3][2] = ((near + near) * far) / (near - far);
    mf[3][3] = 0;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            mf[i][j] *= 0.5f;
        }
    }
    if ((near + far) <= 2.0f) {
        perspNorm = (u16) 0xFFFF;
    } else {
        perspNorm = (u16) ((2.0f * 65536.0f) / (near + far));

        if (perspNorm <= 0) {
            perspNorm = (u16) 0x0001;
        }
    }
    return perspNorm;
}
