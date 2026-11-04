// Conversation camera of the pod system: frames player and NPC from their bounding boxes in one of
// shot types 0..9, refines framing iteratively, keeps line of sight and moves along an eased arc.
#include "common.h"

typedef struct {
    f32 local_0;
    f32 pad_0[2];
    f32 local_1;
} PodDialogRange;
typedef struct {
    PodDialogRange local_0[2];
    u8 pad_0[8];
    f32 local_1[2][3];
} PodDialogPositions;
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    u8 pad_0[0x28];
    f32 first[3];
    f32 second[3];
    f32 pad_1;
    f32 angle;
    u8 pad_2[0x1CC];
    u8 positive;
} PodDialogDirection;
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800139F8(f32);
typedef struct {
    u8 padC4[0xC4];
    f32 unkC4[30];
    f32 unk13C[6];
    f32 unk154;
    u8 pad158[0x9C];
    f32 unk1F4[3];
    f32 unk200[3];
    f32 unk20C;
    u8 unk210;
    s8 unk211;
    u8 unk212;
    u8 unk213;
    u8 unk214;
    u8 unk215;
} PodDialog;
extern s32 _ncpod_entrypoint_5(s32, s32, s32, s32, PodDialog *);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF9A8(f32 *, f32 *, f32);
extern void func_800EF8BC(f32 *, f32 *, f32);
extern void func_800EF934(f32 *, f32 *, f32);
typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
} PodDialogEntry;
extern PodDialogEntry D_80802A40_ncpoddialog[];
typedef struct {
    u8 pad_0[0x211];
    s8 local_0;
    u8 pad_1[5];
    u8 local_1;
} DialogFraming301;
extern void func_800A8A04(s32, s32 *, s32 *, s32 *, s32 *);
extern void func_8001B798();
typedef struct {
    f32 range[2][4];
    f32 weight[2];
    f32 posA[2][3];
    f32 posB[2][3];
    f32 pathA[10][3];
    f32 pathB[10][3];
    f32 vec148[3];
    f32 unk154;
    u8 pad158[0x18];
    f32 vec170[3];
    f32 vec17C[3];
    f32 pathC[10][3];
    f32 vec200[3];
    f32 unk20C;
    u8 unk210;
    s8 unk211;
    u8 unk212;
    u8 unk213;
    u8 unk214;
    u8 unk215;
    u8 unk216;
    u8 unk217;
} PodDialogState;
extern s16 func_8001B668(s32, s32);
extern void func_800EFD24(f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s32 _ncpod_entrypoint_4(s32 param_0);
extern s32 func_80110024(s32 param_0);
extern s32 func_800BF340(f32 *, f32 *, f32 *, u32, f32);
typedef struct {
    u8 pad_0[0x58];
    f32 local_0[10][3];
} DialogCameraSegments;
typedef struct {
    u8 pad_0[0x58];
    f32 position[3];
    u8 pad_1[0x60];
    f32 first[3];
    f32 angles[2];
    u8 pad_2[0x64];
    f32 pitch;
    f32 yaw;
    f32 pad_3;
    f32 second[3];
} PodDialogOrientation;
extern f32 func_800136E4(f32);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct {
    f32 local_0[10][3];
} DialogPoseChain;
extern void func_800EEB9C(f32 *, f32, f32);
typedef struct {
    u8 pad0[0x58];
    f32 path[10][3];
    f32 rot[10][3];
    f32 center[3];
    u8 pad154[0x34];
    f32 out[10][3];
    f32 unk200[3];
} PodPath;
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F0EF0(s32, f32 *);
typedef struct PodDialogRotation {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
} PodDialogRotation;
extern void func_800EF334(f32 *, f32);
typedef struct {
    u8 pad_0[0x20];
    f32 distances[2];
} NcPodPlayerDistances;
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern void func_800EE7B4(f32 *, f32 *, f32 *, f32);
extern f32 func_800F2094(f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern s32 func_800F05F8(f32 *, f32 *, f32 *, f32, f32 *);
typedef struct {
    f32 local_0[2][4];
    f32 local_1[2];
    u8 pad_0[0x1EE];
    u8 local_2;
} PodDialogLimits;
extern s32 func_800EEDE8(f32 *, f32 *, f32);
typedef struct {
    u8 pad_0[0x211];
    s8 local_0;
    u8 local_1;
    u8 local_2;
    u8 pad_1[2];
    u8 local_3;
} NcpodDialogState;
extern f32 func_800D8FF8(void);
extern f32 _mlspline_entrypoint_13(s32, f32 *, f32, f32, f32, void *);
extern void _mlspline_entrypoint_8(void);
extern void _mlspline_entrypoint_4(f32, s32, f32 *, f32 *);
extern void _ncpod_entrypoint_9(s32, f32);
extern void func_800EF368(f32 *, f32);
void func_80800D10_ncpoddialog();
s32 func_808013C0_ncpoddialog();
s32 func_80801504_ncpoddialog();
void func_808017F4_ncpoddialog();
void func_80801B98_ncpoddialog();
s32 ncpoddialog_entrypoint_11();
s32 func_808015CC_ncpoddialog();
extern void func_8080189C_ncpoddialog(f32 *);
void func_808023B4_ncpoddialog();

// Writes the aim point of participant idx (position plus a height offset) to out.
void func_80800000_ncpoddialog(PodDialogPositions *dialog, s32 idx, f32 *out)
{
    func_800EE7F8(out, dialog->local_1[idx]);
    out[1] += dialog->local_0[idx].local_1;
    out[1] += 0.5f * (dialog->local_0[idx].local_0 - dialog->local_0[idx].local_1);
}

void func_8080008C_ncpoddialog(PodDialogDirection *dialog)
{
    f32 angle;
    angle = func_800F1DCC(func_800F1DF4(dialog->first, dialog->second), dialog->angle);
    if (angle < -90.0f || angle > 90.0f)
        angle = -angle;
    if (angle > 0.0f)
        dialog->positive = 1;
    else
        dialog->positive = 0;
}

// Projects a world point to screen coordinates (20 degree FOV) within the screen rect.
s32 func_80800128_ncpoddialog(f32 *point, f32 *out, f32 *cam_pos, f32 *cam_rot, s32 *rect)
{
    f32 view[3];
    f32 focal;
    f32 inv_depth;
    f32 unk_0[4];
    f32 unk_1[4];
    f32 unk_2[4][4];
    f32 fov_scale;
    f32 unk_3[4][4];

    fov_scale = 1.0f / func_800139F8(20.0f);
    func_800D93A0(unk_0, cam_rot);
    func_800D965C(unk_0, unk_2);
    func_800D9624(unk_1, unk_0);
    func_800D965C(unk_1, unk_3);
    func_800EFB24(view, point, cam_pos);
    func_800F23D0(unk_3, view, view);
    focal = (f32) (rect[3] - rect[1]) * fov_scale * 0.5f;
    inv_depth = 1.0f / view[2];
    out[0] = (f32) (rect[2] - rect[0]) * 0.5f - view[0] * focal * inv_depth;
    out[1] = (f32) (rect[3] - rect[1]) * 0.5f + view[1] * focal * inv_depth;
    out[0] += (f32) rect[0];
    out[1] += (f32) rect[1];
    if (view[2] > 0.0f || out[0] < (f32) rect[0] || (f32) rect[0] < out[0] ||
        out[1] < (f32) rect[1] || (f32) rect[3] < out[1]) {
        return 0;
    }
    return 1;
}

// Sets the state and (for state 2) rebuilds the shot: positions, framing and validity checks.
s32 func_80800338_ncpoddialog(PodDialog *dialog, s32 pod, s32 state)
{
    s32 los_ok;
    s32 path_ok;

    dialog->unk210 = state;
    if (dialog->unk210 == 2) {
        if (dialog->unk215 == 0) {
            func_8080008C_ncpoddialog(dialog);
        }
        dialog->unk154 = 0;
        switch (dialog->unk213) {
            case 1:
                dialog->unk20C = 1.0f;
                break;
            case 0:
            case 2:
                dialog->unk20C = 0.0f;
        }
        func_808017F4_ncpoddialog(dialog, pod);
        if (dialog->unk211 != 0 && dialog->unk211 != 1) {
            func_80800D10_ncpoddialog(dialog, dialog->unkC4, dialog->unk13C);
        }
        func_80801B98_ncpoddialog(dialog);
        los_ok = func_808013C0_ncpoddialog(dialog);
        path_ok = func_80801504_ncpoddialog(dialog);
        if (dialog->unk211 == 9) {
        } else if (dialog->unk212 && dialog->unk211 == 8 && los_ok == 0) {
            if (_ncpod_entrypoint_5(pod, func_80110024(pod), 0xAC, dialog->unk211, dialog) != 5) {
                path_ok = _ncpod_entrypoint_5(pod, func_80110024(pod), 0x58, dialog->unk211, NULL);
                if (path_ok == 4) {
                    return path_ok;
                }
                dialog->unk212 = 0;
                func_80800338_ncpoddialog(dialog, pod, 1);
                return 3;
            }
            dialog->unk211 = 9;
            dialog->unk212 = 1;
            func_80800338_ncpoddialog(dialog, pod, 2);
        } else {
            switch (dialog->unk213) {
                case 0:
                case 2:
                    if (path_ok == 0) {
                        dialog->unk213 = 1;
                        func_80800338_ncpoddialog(dialog, pod, 2);
                        return 3;
                    }
                case 1:
                    if (los_ok == 0) {
                        if (dialog->unk211 != 2 && dialog->unk211 != 6) {
                            dialog->unk211 = 8;
                        } else {
                            dialog->unk211 = 4;
                        }
                        dialog->unk212 = 1;
                        func_80800338_ncpoddialog(dialog, pod, 2);
                        return 3;
                    }
                    func_800EE7F8(dialog->unk200, dialog->unk1F4);
            }
        }
    }
    return 3;
}

// Projects a point and grows the screen bounds; returns 2 if first point, 1 if grown, else 0.
s32 func_80800584_ncpoddialog(f32 *point, f32 *bounds_min, f32 *bounds_max, f32 *cam_pos, f32 *cam_rot,
                              s32 unused, s32 *has_bounds, s32 *rect)
{
    f32 screen[2];
    s32 changed = 0;
    func_80800128_ncpoddialog(point, screen, cam_pos, cam_rot, rect);
    if (!*has_bounds) {
        bounds_min[0] = screen[0];
        bounds_min[1] = screen[1];
        bounds_max[0] = screen[0];
        bounds_max[1] = screen[1];
        *has_bounds = 1;
        changed = 2;
    } else {
        if (screen[0] < bounds_min[0]) {
            bounds_min[0] = screen[0];
            changed = 1;
        }
        if (bounds_max[0] < screen[0]) {
            bounds_max[0] = screen[0];
            changed = 1;
        }
        if (screen[1] < bounds_min[1]) {
            bounds_min[1] = screen[1];
            changed = 1;
        }
        if (bounds_max[1] < screen[1]) {
            bounds_max[1] = screen[1];
            changed = 1;
        }
    }
    return changed;
}

// Returns 1 if the current shot frames participant B.
s32 func_80800698_ncpoddialog(dialog)
u8 *dialog;
{

switch (*(s8 *) ((char *) dialog + 0x211) - 2) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
        return 1;
}

return 0;

}

// Returns 1 if the current shot frames participant A.
int func_808006D4_ncpoddialog(dialog)
s32 dialog[0];
{
    switch (*(s8 *) ((char *) dialog + 0x211) - 2) {
        case 0:
        case 1:
        case 2:
        case 4:
        case 6:
        case 7:
            return 1;
    }

return 0;
}

// Projects the 8 corners of each framed participant's bounding box and accumulates the
// screen-space min/max.
void func_80800710_ncpoddialog(f32 *dialog, f32 *bounds_min, f32 *bounds_max, f32 *cam_pos, f32 *cam_rot,
                               s32 unused, s32 *rect)
{
    f32 center[3];
    f32 corner[3];
    s32 sx;
    s32 sy;
    s32 sz;
    s32 has_bounds;
    f32 half_a[3];
    f32 rot_b[3];
    f32 pos_b[3];
    f32 half_b[3];

    has_bounds = 0;

if (func_808006D4_ncpoddialog(dialog)) {
    half_a[1] = (dialog[0] - dialog[3]) * 0.5f;
    half_a[0] = dialog[1] * 0.5f;
    half_a[2] = dialog[2] * 0.5f;
    center[0] = 0.0f;
    center[1] = dialog[3] + half_a[1];
    center[2] = 0.0f;
    func_800EF5A0(center, &dialog[0x10], center[0], center[1], center[2]);
    func_800EF04C(center, &dialog[0xA]);
    for (sx = -1; sx < 2; sx += 2) {
        for (sy = -1; sy < 2; sy += 2) {
            for (sz = -1; sz < 2; sz += 2) {
                func_800EF5A0(corner, &dialog[0x10], half_a[0] * sx, half_a[1] * sy,
                              half_a[2] * sz);
                func_800EF04C(corner, center);
                func_80800584_ncpoddialog(corner, bounds_min, bounds_max, cam_pos, cam_rot, unused,
                                          &has_bounds, rect);
            }
        }
    }
}

if (func_80800698_ncpoddialog(dialog)) {
    half_b[1] = (dialog[4] - dialog[7]) * 0.5f;
    half_b[0] = dialog[5] * 0.5f;
    half_b[2] = dialog[6] * 0.5f;
    center[0] = 0.0f;
    center[1] = dialog[7] + half_b[1];
    center[2] = 0.0f;
    func_800EE7F8(rot_b, &dialog[0x13]);
    rot_b[0] = 0.0f;
    func_800EF5A0(center, rot_b, center[0], center[1], center[2]);
    func_800EE7F8(pos_b, &dialog[0xD]);
    func_800EF04C(center, pos_b);
    for (sx = -1; sx < 2; sx += 2) {
        for (sy = -1; sy < 2; sy += 2) {
            for (sz = -1; sz < 2; sz += 2) {
                func_800EF5A0(corner, rot_b, half_b[0] * sx, half_b[1] * sy,
                              half_b[2] * sz);
                func_800EF04C(corner, center);
                func_80800584_ncpoddialog(corner, bounds_min, bounds_max, cam_pos, cam_rot, unused,
                                          &has_bounds, rect);
            }
        }
    }
}

}

// Rotates the offset (dx, dy, dz) by rot and adds it to cam_pos.
void func_80800A98_ncpoddialog(f32 *cam_pos, f32 *rot, f32 dx, f32 dy, f32 dz)
{
    f32 offset[3];
    func_800EFA4C(offset, dx, dy, dz);
    func_800EF9A8(offset, offset, rot[2]);
    func_800EF8BC(offset, offset, rot[0]);
    func_800EF934(offset, offset, rot[1]);
    func_800EF04C(cam_pos, offset);
}

// Moves the camera by offset idx (D_80802A40) and measures the projected boxes.
// For idx 5/6 returns 0 if the bounds come within 20 px of the rect edge.
s32 func_80800B28_ncpoddialog(f32 *dialog, f32 *cam_pos, f32 *cam_rot, s32 *rect, s32 idx, f32 *center,
                              f32 *size)
{
    f32 max[2];
    f32 min[2];

    func_80800A98_ncpoddialog(cam_pos, cam_rot, D_80802A40_ncpoddialog[idx].unk0,
                              D_80802A40_ncpoddialog[idx].unk4, D_80802A40_ncpoddialog[idx].unk8);
    func_80800710_ncpoddialog(dialog, max, min, cam_pos, cam_rot, 0, rect);
    size[0] = max[0] - min[0];
    size[1] = max[1] - min[1];
    center[0] = min[0] + size[0] * 0.5f;
    center[1] = min[1] + size[1] * 0.5f;

switch (idx) {
    case 5:
    case 6:
        if (min[0] < rect[0] + 20 || rect[2] - 20 < min[0] || min[1] < rect[1] + 20 ||
            rect[3] - 20 < min[1]) {
            return 0;
        }
        if (max[0] < rect[0] + 20 || rect[2] - 20 < max[0] || max[1] < rect[1] + 20 ||
            rect[3] - 20 < max[1]) {
            return 0;
        }
        break;
}

return 1;
}

// Refines the framing: centre horizontally (offsets 1/2), centre vertically (3/4), then
// zoom (5/6), each in at most 10 steps.
void func_80800D10_ncpoddialog(dialog, cam_pos, cam_rot) DialogFraming301 *dialog;
f32 *cam_pos;
f32 *cam_rot;
{
    f32 size[2];
    f32 center[2];
    s32 rect[4];
    f32 target;
    s32 rect_cx;
    s32 steps = 0;

    func_800A8A04(0, &rect[0], &rect[1], &rect[2], &rect[3]);
    rect[1] = 28;
    rect[3] = 200;
    rect_cx = (f32) rect[0] + (f32) rect[2] * 0.5f;
    func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 0, center, size);

if (dialog->local_0 != 8 && dialog->local_0 != 9) {
    target = rect_cx;
    while (target < center[0] && steps != 10) {
        steps++;
        func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 1, center, size);
    }
    steps = 0;
    while (center[0] < target && steps != 10) {
        steps++;
        func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 2, center, size);
    }
    steps = 0;
    // Matching: steps + 0x72 (not the literal) makes IDO convert int to float at runtime.
    target = steps + 0x72;
    while (center[1] < target && steps != 10) {
        steps++;
        func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 3, center, size);
    }
    steps = 0;
    while (target < center[1] && steps != 10) {
        steps++;
        func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 4, center, size);
    }
    steps = 0;
}

if (!dialog->local_1) {
    while (func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 5, center, size) &&
           steps < 10) {
        steps++;
    }
    steps = 0;
}

while (!func_80800B28_ncpoddialog(dialog, cam_pos, cam_rot, rect, 6, center, size) &&
       steps < 10) {
    steps++;
}

}

s32 func_80801058_ncpoddialog(u8 *dialog, s32 pod)
{
    if (dialog[0x212]) {
        dialog[0x212] = 0;
        return func_80800338_ncpoddialog(dialog, pod, 2);
    }

return 3;
}

// Matching: no return statement here; the result stays in v0.
s32 ncpoddialog_entrypoint_0(s16 handle)
{
    s32 id = handle;
    func_8001B798(id);
}

// Matching: '| 0', '& 0xFFFFFFFFu' and the pod_copy temporary are needed for the match.
int ncpoddialog_entrypoint_1(handle, pod)
s16 handle;
s32 pod;
{
    u32 dialog;
    s32 pod_copy;
    u32 result;
    dialog = ncpoddialog_entrypoint_0(handle);
    result = func_80801058_ncpoddialog(dialog | 0, pod);

if (4 == result) {
    return result;
}

if ((*(u8 *) (dialog + 0x210) != 1) && (*(u8 *) (dialog + 0x210) == 2)) {
    pod_copy = pod;
    result = func_808015CC_ncpoddialog(dialog & 0xFFFFFFFFu, pod_copy, dialog);
    if (4 == result) {
        return result;
    }
}

return result;
}

// Creates and resets the dialog camera state; returns its handle.
int ncpoddialog_entrypoint_2(void)
{
    s16 handle;
    PodDialogState *dialog;
    s32 i;
    s32 j;
    f32 *weight;

    handle = func_8001B668(0, 0x21C);
    dialog = ncpoddialog_entrypoint_0(handle);
    dialog->unk210 = 1;
    for (i = 0; i != 10; i++) {
        func_800EFD24(dialog->pathA[i]);
        func_800EFD24(dialog->pathB[i]);
        func_800EFD24(dialog->pathC[i]);
    }
    dialog->unk20C = 0.0f;
    func_800EFD24(dialog->vec148);
    dialog->unk154 = 0.0f;
    dialog->unk211 = -1;
    dialog->unk212 = 0;
    dialog->unk213 = 0;
    dialog->unk214 = 0;
    dialog->unk215 = 0;
    dialog->unk217 = 0;
    func_800EFD24(dialog->vec170);
    func_800EFD24(dialog->vec17C);
    func_800EFD24(dialog->vec200);
    for (j = 0; j != 2; j++) {
        func_800EFD24(dialog->posA[j]);
        func_800EFD24(dialog->posB[j]);
        weight = &dialog->weight[j];
        dialog->range[j][1] = 0.0f;
        dialog->range[j][2] = 0.0f;
        dialog->range[j][3] = 0.0f;
        dialog->range[j][0] = 0.0f;
        *weight = 0.0f;
    }
    return handle;
}

// Reads the current camera position and rotation.
// Matching: no return statement here (needed for the match).
int func_808012A0_ncpoddialog(s32 camera, s32 pos, s32 rot)
{
    if (func_800F690C(camera) || func_800F693C(camera)) {
        _plcamera_entrypoint_14(camera, pos, rot);
    } else {
        func_8010FFB0(func_800F5EF8(camera), pos, rot);
    }
}

void func_80801310_ncpoddialog(dialog, pod) u8 *dialog;
s32 pod;
{
    f32 cam_rot[3];
    func_808012A0_ncpoddialog(_ncpod_entrypoint_4(func_80110024(pod)), dialog + 0x158,
                              dialog + 0x164);
    func_800EE7F8(dialog + 0x200, dialog + 0x158);
    func_800EE7F8(cam_rot, dialog + 0x164);
    func_800EF214(dialog + 0x200, -cam_rot[0], cam_rot[1], -5e+02f);
}

// Matching: no return statement here; the result stays in v0.
s32 ncpoddialog_entrypoint_3(handle)
s16 handle;
{
    func_8001B754(handle);
}

// Returns 1 if the line from the camera to each framed participant is clear of map geometry.
s32 func_808013C0_ncpoddialog(dialog)
u8 *dialog;
{
    Vec3f hit;
    Vec3f target_pos;
    Vec3f cam_pos;
    s32 clear = 1;

    if (func_808006D4_ncpoddialog(dialog)) {
        func_80800000_ncpoddialog(dialog, 0, target_pos.f);
        func_800EE7F8(cam_pos.f, (f32 *) (dialog + 0xC4));
        if (func_800BF340(cam_pos.f, target_pos.f, hit.f, 0x860020, 30.0f))
            clear = 0;
        else if (func_800BF340(target_pos.f, cam_pos.f, hit.f, 0x860020, 30.0f))
            clear = 0;
    }
    if (func_80800698_ncpoddialog(dialog)) {
        func_80800000_ncpoddialog(dialog, 1, target_pos.f);
        func_800EE7F8(cam_pos.f, (f32 *) (dialog + 0xC4));
        if (func_800BF340(cam_pos.f, target_pos.f, hit.f, 0x860020, 30.0f))
            clear = 0;
        else if (func_800BF340(target_pos.f, cam_pos.f, hit.f, 0x860020, 30.0f))
            clear = 0;
    }
    return clear;
}

// Returns 1 if every segment of the 10-point camera path is clear of map geometry.
s32 func_80801504_ncpoddialog(path)
DialogCameraSegments *path;
{
    f32 hit[3];
    f32 next[3];
    s32 i;
    s32 clear;

    clear = 1;
    for (i = 0; i < 9; i++) {
        func_800EE7F8(next, path->local_0[i + 1]);
        if (func_800BF340(path->local_0[i], next, hit, 0x860020, 30.0f))
            clear = 0;
    }
    return clear;
}

// Advances the camera along the 10-point path with eased speed (slow at both ends).
s32 func_808015CC_ncpoddialog(dialog, pod)
u8 *dialog;
s32 pod;
{
    f32 edge_speed;
    f32 cruise_speed;
    f32 *path;

    switch (dialog[0x213]) {
        case 2:
            edge_speed = 10.0f;
            cruise_speed = 20.0f;
            break;
        case 0:
            edge_speed = 125.0f;
            cruise_speed = 500.0f;
            break;
        case 1:
            cruise_speed = edge_speed = 5000.0f;
    }
    if (*(f32 *) (dialog + 0x20C) < 0.15f) {
        *(f32 *) (dialog + 0x154) =
            func_800F10B4(*(f32 *) (dialog + 0x20C), 0.0f, 0.15f, edge_speed, cruise_speed);
    } else if (*(f32 *) (dialog + 0x20C) > 0.85f) {
        *(f32 *) (dialog + 0x154) =
            func_800F10B4(*(f32 *) (dialog + 0x20C), 0.85f, 1.0, cruise_speed, edge_speed);

}
if (*(f32 *) (dialog + 0x20C) < 1.0f) {
    if (dialog[0x213] == 1) {
        *(f32 *) (dialog + 0x20C) = 1.0f;
        path = (f32 *) (dialog + 0x58);
    } else {

path = (f32 *) (dialog + 0x58);
*(f32 *) (dialog + 0x20C) = _mlspline_entrypoint_13(10, path, *(f32 *) (dialog + 0x20C),
                                                     *(f32 *) (dialog + 0x154) * func_800D8FF8(),
                                                     1.0f, _mlspline_entrypoint_8);
}
}
else
{
    *(f32 *) (dialog + 0x20C) = 1.0f;
    if (_ncpod_entrypoint_5(pod, func_80110024(pod), 0x58, *(s8 *) (dialog + 0x211), 0) ==
        4) {
        return 4;
    }
    func_80800338_ncpoddialog(dialog, pod, 1);
    path = (f32 *) (dialog + 0x58);
}
_mlspline_entrypoint_4(*(f32 *) (dialog + 0x20C), 10, path, (f32 *) (dialog + 0x170));
_mlspline_entrypoint_4(*(f32 *) (dialog + 0x20C), 10, (f32 *) (dialog + 0xD0),
                       (f32 *) (dialog + 0x17C));
_ncpod_entrypoint_8(func_80110024(pod), (f32 *) (dialog + 0x170), (f32 *) (dialog + 0x17C));
_ncpod_entrypoint_9(func_80110024(pod), 40.0f);
return 0;
}

// Builds the shot targets, stores the current camera pose as the path start and sets yaw/pitch.
void func_808017F4_ncpoddialog(dialog, pod) PodDialogOrientation *dialog;
s32 pod;
{
    s32 camera;
    camera = _ncpod_entrypoint_4(func_80110024(pod));
    func_808023B4_ncpoddialog(dialog, pod);
    func_808012A0_ncpoddialog(camera, dialog->position, dialog->angles);
    dialog->angles[0] = func_800136E4(dialog->angles[0]);
    dialog->angles[1] = func_800136E4(dialog->angles[1]);
    dialog->yaw = func_800136E4(func_800F1DF4(dialog->second, dialog->first));
    dialog->pitch = func_800136E4(-func_800F1828(dialog->second, dialog->first));
}

// Fills entries 1..8 by linear interpolation between the end angles, taking the short way round.
void func_8080189C_ncpoddialog(angles) f32 *angles;
{
    s32 i;
    if (angles[9] + 178.0f <= angles[0]) {
        angles[0] -= 360.0f;
    }
    if (angles[0] + 178.0f <= angles[9]) {
        angles[9] -= 360.0f;
    }
    for (i = 1; i < 9; i++) {
        angles[i] = angles[0] * ((f32) (9 - i) * 0.11111111f) +
                           angles[9] * ((f32) i * 0.11111111f);
    }
}

// Fills entries 1..8 by interpolating between the first and last value.
void func_80801A30_ncpoddialog(f32 *values)
{
    s32 i;
    for (i = 1; i < 9; i++) {
        values[i] = func_800F10B4(i, 0.0f, 9.0f, values[0], values[9]);
    }
}

// Places path points 1..8 on an arc around center from interpolated angle and distance.
void func_80801AC0_ncpoddialog(DialogPoseChain *path, f32 *angles, f32 *dists, f32 *center)
{
    s32 i;
    for (i = 1; i < 9; i++) {
        func_800EEB9C(path->local_0[i], angles[i], dists[i]);
        func_800EF04C(path->local_0[i], center);
        path->local_0[i][1] = func_800F10B4(
            (f32) i, 0.0f, 9.0f, path->local_0[0][1], path->local_0[9][1]);
    }
}

// Fills in the 10-point path, the look-at points and the rotations between first and last entry.
void func_80801B98_ncpoddialog(PodPath *dialog)
{
    f32 angs[10];
    f32 dists[10];
    f32 pts[10][3];
    f32 end_dist;
    s32 i;
    s32 j;

    angs[0] = func_800136E4(func_800F1DF4(dialog->center, dialog->path[0]));
    angs[9] = func_800136E4(func_800F1DF4(dialog->center, dialog->path[9]));
    func_8080189C_ncpoddialog(angs);
    dists[0] = func_800EFB8C(dialog->path[0], dialog->center);
    dists[9] = func_800EFB8C(dialog->path[9], dialog->center);
    func_80801A30_ncpoddialog(dists);
    func_80801AC0_ncpoddialog(dialog->path[0], angs, dists, dialog->center);
    end_dist = func_800EEAD4(dialog->path[9], dialog->center);
    func_800EE7F8(pts[0], dialog->unk200);
    func_800EE7F8(pts[9], dialog->path[9]);
    func_800EF214(pts[9], -dialog->rot[9][0], dialog->rot[9][1], -end_dist);
    for (i = 1; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            pts[i][j] = func_800F10B4(i, 0.0f, 9.0f, pts[0][j], pts[9][j]);
        }
    }
    for (i = 0; i < 10; i++) {
        func_800EE7F8(dialog->out[i], pts[i]);
    }
    for (i = 1; i < 9; i++) {
        dialog->rot[i][1] = func_800136E4(func_800F1DF4(pts[i], dialog->path[i]));
        dialog->rot[i][0] = func_800136E4(-func_800F1828(pts[i], dialog->path[i]));
        dialog->rot[i][2] = 0.0f;
    }
    func_800F0EF0(10, dialog->rot[0]);
}

// Close-up shot of participant idx (shots 3 and 5).
void func_80801DB8_ncpoddialog(u8 *dialog, s32 idx, f32 angle)
{
    f32 dist;
    func_80800000_ncpoddialog(dialog, idx, ((f32 *) (dialog + 0x148)));
    angle += ((f32(*)[3])(dialog + 0x44))[idx][0];
    dist = ((PodDialogRotation *) dialog)[idx].local_0 -
              ((PodDialogRotation *) dialog)[idx].local_3;
    if (dist < ((PodDialogRotation *) dialog)[idx].local_1) {
        dist = ((PodDialogRotation *) dialog)[idx].local_1;
    }
    if (dist < ((PodDialogRotation *) dialog)[idx].local_2) {
        dist = ((PodDialogRotation *) dialog)[idx].local_2;
    }
    func_800EEB9C((f32 *) (dialog + 0xC4), angle, dist);
    func_800EF04C((f32 *) (dialog + 0xC4), ((f32 *) (dialog + 0x148)));
    *(f32 *) (dialog + 0xC8) = *(f32 *) (dialog + 0x14C);
}

// Side two-shot (shots 2 and 6).
void func_80801E78_ncpoddialog(u8 *dialog, s32 idx, s32 flip)
{
    f32 offset[3];
    f32 *cam_pos;
    f32 angle;
    cam_pos = (f32 *) (dialog + 0xC4);
    func_80800000_ncpoddialog(dialog, 1 - idx, cam_pos);
    func_80800000_ncpoddialog(dialog, idx, (f32 *) (dialog + 0x148));
    *(f32 *) (dialog + 0xC8) += *(f32 *) (dialog + 0x14C);
    *(f32 *) (dialog + 0xC8) *= 0.5f;
    *(f32 *) (dialog + 0x14C) = *(f32 *) (dialog + 0xC8);
    angle = func_800F1DF4((f32 *) (dialog + 0x148), cam_pos);
    if (flip)
        angle += 90.0f;
    else
        angle -= 90.0f;
    func_800EEB9C(offset, angle, ((NcPodPlayerDistances *) dialog)->distances[1 - idx]);
    func_800EF04C(cam_pos, offset);
    func_800EFB24(offset, cam_pos, (f32 *) (dialog + 0x148));
    func_800EF334(offset, 0.5f);
    func_800EF04C(cam_pos, offset);
}

// Over-the-shoulder shot (shot 4).
void func_80801F88_ncpoddialog(u8 *dialog, f32 angle_offset)
{
    f32 angle;
    f32 *cam_pos;
    f32 pos_b[3];
    f32 unk_0[3];

    func_80800000_ncpoddialog(dialog, 1, pos_b);
    func_800EE780(unk_0, (f32 *) (dialog + 0x28), pos_b);
    func_800EF334(unk_0, 0.5f);
    angle = func_800F1DF4((f32 *) (dialog + 0x28), pos_b);
    func_800F1828((f32 *) (dialog + 0x28), pos_b);
    angle += angle_offset;
    cam_pos = (f32 *) (dialog + 0xC4);
    func_800EEC30(cam_pos, 0.0f, angle, 500.0f);
    func_800EE7B4((f32 *) (dialog + 0x148), unk_0, cam_pos, -0.1f);
    func_800EF04C(cam_pos, unk_0);
}

// Swings the camera around a participant's sphere when it would block the line to the focus point.
void func_80802048_ncpoddialog(void *dialog, f32 *focus, f32 *cam_pos, f32 *sphere_pos, f32 radius)
{
    f32 saved_y;
    f32 cam_dist;
    f32 sphere_dist;
    f32 sphere_angle;
    f32 cam_angle;
    f32 half_angle;
    s32 in_cone;
    Vec3f edge_b;
    Vec3f edge_a;
    s32 plus_side;
    s32 iter;
    s32 turn;
    f32 min_dist;
    f32 unk_0;
    f32 hit_t;
    s32 hit;
    Vec3f ray_end;

    saved_y = cam_pos[1];
    radius *= 0.75f;
    if (radius < 5.0f) {
        return;
    }
    cam_dist = func_800EFB8C(focus, cam_pos);
    if (cam_dist < func_800EFB8C(focus, sphere_pos) - radius) {
        return;
    }
    sphere_dist = func_800EFB8C(focus, sphere_pos);
    sphere_angle = func_800F1DF4(focus, sphere_pos);
    cam_angle = func_800F1DF4(focus, cam_pos);
    func_800EEB9C(edge_a.f, sphere_angle + 90.0f, radius);
    func_800EE7F8(edge_b.f, edge_a.f);
    func_800EF04C(edge_a.f, sphere_pos);
    func_800EFB24(edge_b.f, sphere_pos, edge_b.f);
    half_angle = func_800F2094(func_800F1DF4(focus, edge_a.f), sphere_angle);
    in_cone = func_800F20BC(cam_angle, sphere_angle, half_angle);
    if (in_cone) {
        min_dist = radius * 0.5f + sphere_dist;
        if (cam_dist < min_dist) {
            cam_dist = min_dist;
        }
        unk_0 = half_angle * 0.5f;
        plus_side = func_800F20BC(cam_angle, unk_0 + sphere_angle, unk_0);
        if (plus_side) {
            cam_angle = sphere_angle + half_angle;
        } else {
            cam_angle = sphere_angle - half_angle;
        }
        func_800EEB9C(cam_pos, cam_angle, cam_dist);
        func_800EF04C(cam_pos, focus);
        func_800EFB24(ray_end.f, cam_pos, focus);
        hit = 1;
        iter = 0;
        while (hit && iter++ < 5) {
            hit = func_800F05F8(focus, ray_end.f, sphere_pos, radius, &hit_t);

if (hit && hit_t < 1.0f) {
    turn = half_angle < 0.0f ? -5 : 5;
    cam_angle += turn;
    func_800EEB9C(ray_end.f, cam_angle, cam_dist);
}

}
func_800EEB9C(cam_pos, cam_angle, cam_dist);
func_800EF04C(cam_pos, focus);
}
cam_pos[1] = saved_y;
}

// Applies the sphere clearance for each participant, depending on the shot type.
void func_8080230C_ncpoddialog(u8 *dialog, u8 *focus, u8 *cam_pos)
{
    s8 shot;

    shot = ((s8 *) dialog)[0x211];
    if (shot == 4 || shot == 5 || shot == 6 || shot == 8) {
        func_80802048_ncpoddialog(dialog, focus, cam_pos, dialog + 0x28,
                                  (*(f32 *) ((u8 *) dialog + 0x20)));
        shot = ((s8 *) dialog)[0x211];
    }
    if (shot == 2 || shot == 3 || shot == 4 || shot == 8) {
        func_80802048_ncpoddialog(dialog, focus, cam_pos, dialog + 0x34,
                                  (*(f32 *) ((u8 *) dialog + 0x24)));
    }
}

// Computes the camera position and look-at point for the current shot type.
void func_808023B4_ncpoddialog(dialog, pod) u8 *dialog;
s32 pod;
{
    s32 mirror;
    Vec3f cam_pos;
    Vec3f cam_rot;
    Vec3f pos_a;
    Vec3f fixed_pos_a;
    Vec3f unk_0;

    mirror = 0;
    if (dialog[0x214] == 1) {
        mirror = 1;
    }
    switch (dialog[0x211]) {
        case 0:
        case 1:
            func_800EE7F8((f32 *) (dialog + 0xC4), (f32 *) (dialog + 0x158));
            func_800EEC30((f32 *) (dialog + 0x148), -*(f32 *) (dialog + 0x164),
                          *(f32 *) (dialog + 0x168), 500.0f);
            func_800EF04C((f32 *) (dialog + 0x148), (f32 *) (dialog + 0x158));
            break;
        case 4:
            func_80801F88_ncpoddialog(dialog, (f32) (mirror ? -90 : 90));
            break;
        case 2:
            func_80801E78_ncpoddialog(dialog, 0, 1 - mirror);
            break;
        case 6:
            func_80801E78_ncpoddialog(dialog, 1, mirror);
            break;
        case 5:
            func_80801DB8_ncpoddialog(dialog, 1, (f32) (mirror ? 10 : -10));
            break;
        case 3:
            func_80801DB8_ncpoddialog(dialog, 0, (f32) (mirror ? -10 : 10));
            break;
        case 8:
            func_800EE7F8(cam_pos.f, (f32 *) (dialog + 0x158));
            func_800EE7F8(cam_rot.f, (f32 *) (dialog + 0x164));
            func_80800000_ncpoddialog(dialog, 0, pos_a.f);
            func_80800000_ncpoddialog(dialog, 1, (f32 *) (dialog + 0x148));
            func_800EF04C((f32 *) (dialog + 0x148), pos_a.f);
            func_800EF334((f32 *) (dialog + 0x148), 0.5f);
            func_800EFB24((f32 *) (dialog + 0xC4), (f32 *) (dialog + 0x148), cam_pos.f);
            func_800EF368((f32 *) (dialog + 0xC4), 250.0f);
            func_800EF04C((f32 *) (dialog + 0xC4), cam_pos.f);
            func_800EEC30((f32 *) (dialog + 0x188), -*(f32 *) (dialog + 0xD0),
                          *(f32 *) (dialog + 0xD4), -200.0f);
            func_800EF04C((f32 *) (dialog + 0x188), (f32 *) (dialog + 0x58));
            func_800EE7F8((f32 *) (dialog + 0x200), (f32 *) (dialog + 0x188));
            break;
        case 9:
            func_80800000_ncpoddialog(dialog, 0, fixed_pos_a.f);
            func_80800000_ncpoddialog(dialog, 1, (f32 *) (dialog + 0x148));
            func_800EF04C((f32 *) (dialog + 0x148), fixed_pos_a.f);
            func_800EF334((f32 *) (dialog + 0x148), 0.5f);
            func_800A5800(dialog[0x218]);
            _cadbfunc_entrypoint_0((f32 *) (dialog + 0xC4));
            _cadbfunc_entrypoint_2(unk_0.f);
            break;
        default:
            break;
    }
    func_8080230C_ncpoddialog(dialog, (f32 *) (dialog + 0x148), (f32 *) (dialog + 0xC4));
}

// Stores the new bounding box of participant idx if a value changed by more than 10.
void ncpoddialog_entrypoint_4(PodDialogLimits *dialog, s32 idx, f32 *new_range)
{
    s32 i;
    s32 changed = 0;

    for (i = 0; i < 4; i++) {
        if (new_range[i] + 10.0f < dialog->local_0[idx][i] ||
            dialog->local_0[idx][i] < new_range[i] - 10.0f) {
            dialog->local_0[idx][i] = new_range[i];
            changed = 1;
        }
    }
    if (changed) {
        dialog->local_1[idx] = dialog->local_0[idx][2] < dialog->local_0[idx][1]
                                        ? dialog->local_0[idx][1]
                                        : dialog->local_0[idx][2];
        dialog->local_2 = 1;
    }
}

// Stores the position of participant idx if it moved by more than 10.
void ncpoddialog_entrypoint_5(u8 *dialog, s32 idx, f32 *pos)
{
    if (!func_800EEDE8(((f32(*)[3])(dialog + 0x28))[idx], pos, 10.0f)) {
        func_800EE7F8(((f32(*)[3])(dialog + 0x28))[idx], pos);
        dialog[0x216] = 1;
    }
}

// Stores the rotation of participant idx.
// Matching: the offset temporary is needed for the match.
void ncpoddialog_entrypoint_6(s32 dialog, s32 idx, s32 rot)
{
    int offset;
    offset = 0x40;
    func_800EE7F8(offset + (dialog + (idx * 0xC)), rot);
}

// side < 0: choose the side automatically; otherwise force it (0 or 1).
void ncpoddialog_entrypoint_7(u8 *dialog, s32 side)
{
    if (side >= 0) {
        (*(u8 *) ((u8 *) (dialog) + 0x215)) = 1;
        if (side == 0) {
            (*(u8 *) ((u8 *) (dialog) + 0x214)) = 0;
            return;
        }
        (*(u8 *) ((u8 *) (dialog) + 0x214)) = 1;
        return;
    }
    (*(u8 *) ((u8 *) (dialog) + 0x215)) = 0;
}

// Sets the camera-database node used by shot 9.
int ncpoddialog_entrypoint_8(Actor *dialog, s32 node)
{
    *(u8 *) ((char *) dialog + 0x218) = node;
    return 5;
}

// Switches to a new shot type and tells the player; mode selects the speed profile.
void ncpoddialog_entrypoint_9(NcpodDialogState *dialog, s32 pod, s32 shot, s32 mode)
{
    if (dialog->local_0 == -1) {
        func_80801310_ncpoddialog();
    }
    if (shot == dialog->local_0 && dialog->local_3 == 0) {
        return;
    }
    dialog->local_3 = 0;
    dialog->local_0 = shot;
    dialog->local_2 = mode;
    func_8009055C(100, (mode << 16) | shot);
    if ((dialog->local_0 == 0 && dialog->local_2 == 1) || dialog->local_0 == 7) {
        if (_ncpod_entrypoint_5(pod, func_80110024(pod), 0x58, dialog->local_0, 0) != 4) {
            func_80800338_ncpoddialog(dialog, pod, 1);
        }
    } else {
        dialog->local_1 = 1;
    }
}

// The argument packs the shot (low 16 bits) and the mode (high 16 bits).
void ncpoddialog_entrypoint_10(u32 packed_arg)
{
    u32 packed_copy = packed_arg;
    u32 high_masked = packed_copy & 0xFFFF0000;
    u32 high = high_masked >> 16;
    u32 low = packed_arg & 0xFFFF;
    ncpoddialog_entrypoint_11(low, high, 1);
}

// query 0: shot is 0 or 7. query 1: mode is 1 and shot is 0 or 1. Returns 1 on a match.
s32 ncpoddialog_entrypoint_11(shot, mode, query)
s32 shot;
s32 mode;
s32 query;
{
    switch (query) {
        case 0:
            if (shot == 0 || shot == 7) {
                return 1;
            }
            break;
        case 1:
            if (mode == 1 && (shot == 0 || shot == 1)) {
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 0;
}

// TU-NOTE: this overlay's .data is defined here in C; values are taken from the ROM.
// Camera offsets (x, y, z) per framing step: 1/2 shift x, 3/4 shift y, 5/6 zoom z.
PodDialogEntry D_80802A40_ncpoddialog[8] ={0.0f, 0.0f,    0.0f, 5.0f, 0.0f,   0.0f,  -5.0f, 0.0f,
                                            0.0f, 0.0f,    5.0f, 0.0f, 0.0f,   -5.0f, 0.0f,  0.0f,
                                            0.0f, -2e+01f, 0.0f, 0.0f, 2e+01f, 0.0f,  0.0f,  0.0f};
