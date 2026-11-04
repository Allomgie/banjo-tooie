// Node/spline cutscene camera of the pod system: builds a camera spline from camera-database
// nodes, advances it with game or intro time, optionally looks at an actor, reports end events.
#include "common.h"
extern void _susplinet_entrypoint_11(void *, f32);

extern s32 func_8001B754(s16);
extern void func_800EF334(f32 *, f32);
typedef struct {
    s16 spline_handle;
    s16 pad_2;
    f32 cam_pos[3];
    f32 cam_rot[3];
    u8 pad_1C[0x20];
    f32 target_pos[3];
    u8 pad_48[8];
    f32 fov;
    f32 unk_54;
} CameraSplineView;
extern f32 _suspline_entrypoint_4(void *, s32);
extern void _suspline_entrypoint_9(s32, f32);
extern void *func_8001B798();
typedef struct {
    s16 spline_handle;
    s16 splinet_handle;
    u8 pad_4[0x5C];
    u8 kind;
    u8 pad_61[4];
    u8 use_intro_sync;
} PodUCamSplineState;
extern f32 _glintrosyncDll_entrypoint_5(void);
extern f32 func_800D8FF8(void);
extern f32 _susplinet_entrypoint_9(void *);
extern void _susplinet_entrypoint_16(void *, f32, f32);
extern f32 _susplinet_entrypoint_8(s32, s32);
extern void _ncpod_entrypoint_9(s32, f32);
extern void _ncpod_entrypoint_11(s32, f32);
typedef struct {
    u8 pad_0[2];
    s16 splinet_handle;
    u8 pad_4[0x54];
    s16 node_id;
    u8 pad_5A[6];
    u8 kind;
} UCamSpline49;
extern f32 *_susplinet_entrypoint_14(void *, s32);
extern s32 *_susplinet_entrypoint_15(void *, s32);
extern s16 *_susplinet_entrypoint_12(void *);
extern s16 *_susplinet_entrypoint_13(void *);
extern void _susplinet_entrypoint_0(void *, s32, s32, f32);
extern void *_suspline_entrypoint_10(void *, s32);
extern void *_suspline_entrypoint_11(void *, s32);
extern void func_800F0EF0(s32, f32 *);
extern void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
typedef struct {
    u8 pad_0[0x58];
    s16 node_id;
    u8 pad_5A[2];
    s32 state;
    u8 kind;
} PodUserCameraState;
typedef struct {
    u8 pad_0[2];
    s16 splinet_handle;
    u8 pad_4[0x5C];
    u8 kind;
} PodCameraState;
extern s32 _susplinet_entrypoint_4(void *, s32);
extern s32 _suspline_entrypoint_2(void *, f32);
extern s32 _susplinet_entrypoint_5(void *, f32);
extern f32 _suspline_entrypoint_6(void *);
extern void _suspline_entrypoint_3(void *, s32, f32 *);
extern void _suspline_entrypoint_5(void *, f32 *);
extern Actor *_subaddiefind_entrypoint_12(s32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern f32 func_800136E4(f32);
extern void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
s32 ncpoducam_entrypoint_1();
// State change; state 1 picks the node kind and builds the spline.
void func_8080145C_ncpoducam();

// Resets the vectors and sets the default FOV (40).
void func_80800000_ncpoducam(u8 *cam)
{
    func_800EFD24(cam + 4);
    func_800EFD24(cam + 0x10);
    func_800EFD24(cam + 0x24);
    func_800EFD24(cam + 0x30);
    *(s8 *) ((s8 *) cam + 0x63) = 0;
    *(f32 *) ((s8 *) cam + 0x50) = 40.0f;
    *(f32 *) ((s8 *) cam + 0x54) = 1.0f;
}

s16 ncpoducam_entrypoint_0(void)
{
    s16 handle;
    u8 *cam;

    handle = func_8001B668(0, 0x68);
    cam = ncpoducam_entrypoint_1(handle);
    *(s32 *) ((s8 *) cam + 0x5C) = 0;
    *(s32 *) ((s8 *) cam + 0x1C) = 0;
    *(s16 *) ((s8 *) cam + 0) = 0;
    *(s16 *) ((s8 *) cam + 2) = 0;
    func_800EFD24(cam + 0x3C);
    func_800EFD24(cam + 4);
    func_800EFD24(cam + 0x10);
    *(s16 *) ((s8 *) cam + 0x48) = 0;
    *(s32 *) ((s8 *) cam + 0x4C) = 0;
    *(s16 *) ((s8 *) cam + 0x58) = -1;
    *(u8 *) ((s8 *) cam + 0x60) = 0xFF;
    *(s8 *) ((s8 *) cam + 0x62) = 0;
    *(s8 *) ((s8 *) cam + 0x65) = func_800E6A00();
    return handle;
}

s32 ncpoducam_entrypoint_1(handle)
s16 handle;
{
    s32 handle_s32 = handle;
    func_8001B798(handle_s32);
}

s32 ncpoducam_entrypoint_2(void *cam, s32 pod, s32 node_id)
{
    *(s16 *) ((char *) cam + 0x58) = node_id;
    func_8080145C_ncpoducam(cam, pod, 1);
}

void ncpoducam_entrypoint_3(s32 *cam, s32 *actor)
{
    cam[7] = actor;
    cam[8] = (u32) ((unsigned short) (*(u16 *) ((char *) (actor) + 18))) >> 1;
}

void ncpoducam_entrypoint_4(void *cam, int flags)
{
    void *cam_alias;
    cam_alias = cam;
    *((s16 *) (0x48 + ((char *) cam_alias))) = flags;
}

int ncpoducam_entrypoint_5(union U1 *cam)
{
    return *(s16 *) ((char *) cam + 0x48);

}

// Frees the spline objects of the camera.
void func_80800160_ncpoducam(s16 *handles)
{
    if (handles[0] != 0) {
        func_8001B754(handles[0]);
        handles[0] = 0;
    }

if (handles[1] != 0) {
    func_8001B754(handles[1]);
    handles[1] = 0;
}

}

s32 ncpoducam_entrypoint_6(handle)
s16 handle;
{
    s32 cam;

    cam = ncpoducam_entrypoint_1(handle);
    func_80800160_ncpoducam(cam | 0); // Matching: "| 0" is needed for the match.
    return func_8001B754(handle);
}

int func_808001F0_ncpoducam(u16 *actor, u32 actor_id)
{
    s32 ret;

if (actor_id == -1) {
    ret = 0;
} else {

ret = (actor_id == ((u32) *(u16 *) (actor + 9) >> 1));

}
return ret;
}

// Updates the look-at target from the tracked actor (flag 1) or the player (flag 0x40), with optional smoothing (0x400).
int func_8080021C_ncpoducam(u8 *cam)
{
    f32 pos[3];
    s16 flags;
    f32 delta_actor[3];
    f32 unk_0[3];
    f32 delta_player[3];
    flags = *(s16 *) (cam + 0x48);
    if (flags & 1) {
        if (func_808001F0_ncpoducam(*(s32 *) (cam + 0x1C), *(s32 *) (cam + 0x20))) {
            func_80103DFC(func_80106790(*(s32 *) (cam + 0x1C)), pos);
            if ((*(s16 *) (cam + 0x48) & 0x400) && cam[0x63]) {
                func_800EFB24(delta_actor, pos, (f32 *) (cam + 0x3C));
                func_800EF334(delta_actor, 0.3f);
                func_800EF04C((f32 *) (cam + 0x3C), delta_actor);
                return 1;
            }
            func_800EE7F8(cam + 0x3C, pos);
            cam[0x63] = 1;
        }

return 1;
}
if (flags & 0x40) {
    func_800F5BC4(func_800F54E4(), unk_0);
    func_800F5A00(func_800F54E4(), pos);
    func_800EF04C(pos, unk_0);

if ((*(s16 *) (cam + 0x48) & 0x400) && cam[0x63]) {
    func_800EFB24(delta_player, pos, (f32 *) (cam + 0x3C));
    func_800EF334(delta_player, 0.3f);
    func_800EF04C((f32 *) (cam + 0x3C), delta_player);
    return 1;
}

cam[0x63] = 1;
func_800EE7F8(cam + 0x3C, pos);
return 1;
}
if (flags & 0x80) {
    return 1;
}
return 0;
}

// Kind 6: spline relative to an actor.
void func_808003A8_ncpoducam(cam, unk_arg) u8 *cam;
s32 unk_arg;
{
    f32 unk_0[3];
    f32 unk_1[3];
    f32 unk_2[3];
    f32 unk_3[3];
    f32 unk_4[3];
    f32 unk_5[3];
    Actor *actor;
    void *spline;
    s32 actor_id;

    spline = func_8001B798(*(s16 *) cam);
    _suspline_entrypoint_3(spline, 0, unk_3);
    _suspline_entrypoint_3(spline, 2, unk_4);
    _suspline_entrypoint_3(spline, 1, unk_5);

if (*(s16 *) (cam + 0x48) & 8) {
    if (func_808001F0_ncpoducam(*(s32 *) (cam + 0x1C), *(s32 *) (cam + 0x20))) {
        actor = (Actor *) func_80106790(*(s32 *) (cam + 0x1C));
    } else {
        actor = NULL;
    }
} else {

func_800A5800(*(s16 *) (cam + 0x58));
_cadbfunc_entrypoint_24(&actor_id);
actor = _subaddiefind_entrypoint_12(actor_id);

}
if (actor) {
    if (!(*(s16 *) (cam + 0x48) & 0x400) || !cam[0x63]) {
        func_800EE7F8((f32 *) (cam + 0x30), actor->rotation);
        func_800EE7F8((f32 *) (cam + 0x24), actor->position);
        cam[0x63] = 1;
    } else {

*(f32 *) (cam + 0x30) += func_800F1DCC(actor->rotation[0], *(f32 *) (cam + 0x30)) * 0.1f;
*(f32 *) (cam + 0x34) += func_800F1DCC(actor->rotation[1], *(f32 *) (cam + 0x34)) * 0.1f;
*(f32 *) (cam + 0x38) += func_800F1DCC(actor->rotation[2], *(f32 *) (cam + 0x38)) * 0.1f;
*(f32 *) (cam + 0x24) += (actor->position[0] - *(f32 *) (cam + 0x24)) * 0.1f;
*(f32 *) (cam + 0x28) += (actor->position[1] - *(f32 *) (cam + 0x28)) * 0.1f;
*(f32 *) (cam + 0x2C) += (actor->position[2] - *(f32 *) (cam + 0x2C)) * 0.1f;
}
}
func_800EE7F8((f32 *) (cam + 4), unk_4);
func_800EF6A8((f32 *) (cam + 4), (f32 *) (cam + 0x30), *(f32 *) (cam + 4),
              *(f32 *) (cam + 8), *(f32 *) (cam + 0xC));
func_800EF04C((f32 *) (cam + 4), (f32 *) (cam + 0x24));
if (!(*(s16 *) (cam + 0x48) & 1)) {
    func_800EE7F8(unk_0, unk_3);
    func_800EF6A8(unk_0, (f32 *) (cam + 0x30), unk_0[0], unk_0[1], unk_0[2]);
    func_800EF04C(unk_0, (f32 *) (cam + 0x24));
    func_800EE7F8(unk_1, unk_3);
    func_800EF5A0(unk_2, unk_5, 100.0f, 0.0f, 0.0f);
    func_800EF04C(unk_1, unk_2);
    func_800EF6A8(unk_1, (f32 *) (cam + 0x30), unk_1[0], unk_1[1], unk_1[2]);
    func_800EF04C(unk_1, (f32 *) (cam + 0x24));
    *(f32 *) (cam + 0x18) = func_800136E4(-func_800F1828(unk_0, unk_1));
    *(f32 *) (cam + 0x10) = -func_800136E4(func_800F1828(unk_0, (f32 *) (cam + 4)));
    *(f32 *) (cam + 0x14) = func_800136E4(func_800F1DF4(unk_0, (f32 *) (cam + 4)));
}
if (func_8080021C_ncpoducam(cam)) {
    func_800F18FC((f32 *) (cam + 0x3C), (f32 *) (cam + 4), (f32 *) (cam + 0x10));
    *(f32 *) (cam + 0x10) = -*(f32 *) (cam + 0x10);
    *(f32 *) (cam + 0x18) = 0.0f;
}
*(f32 *) (cam + 0x50) = _suspline_entrypoint_4(spline, 0);
if (!unk_arg) {
    _suspline_entrypoint_5(spline, unk_4);
}
}

// Kind 5: position spline.
void func_80800704_ncpoducam(CameraSplineView *view, s32 unk_arg)
{
    void *spline;

    spline = func_8001B798(view->spline_handle);
    _suspline_entrypoint_3(spline, 0, view->cam_pos);
    if (!func_8080021C_ncpoducam(view)) {
        _suspline_entrypoint_3(spline, 1, view->cam_rot);
    } else {
        func_800F18FC(view->target_pos, view->cam_pos, view->cam_rot);
        view->cam_rot[0] = -view->cam_rot[0];
        view->cam_rot[2] = 0.0f;
    }
    view->fov = _suspline_entrypoint_4(spline, 0);
    view->unk_54 = _suspline_entrypoint_4(spline, 1);
    if (!unk_arg)
        _suspline_entrypoint_5(spline, view->cam_pos);
}

int func_808007D0_ncpoducam(u8 *cam)
{
    s32 spline;
    switch (cam[0x60]) {
        case 5:
        case 6:
            spline = func_8001B798(*(short *) (cam + 0), cam);
            _suspline_entrypoint_13(spline);
            _suspline_entrypoint_9(spline, _suspline_entrypoint_6(spline));
            _suspline_entrypoint_14(spline);
            _suspline_entrypoint_17(spline);
        case 8:
            return;
    }
}

// Reports progress (14) and end (12) events to the pod owner.
s32 func_80800854_ncpoducam(u8 *cam, s32 pod)
{
    s32 ended = 0;
    s32 result;

    result =
        _ncpod_entrypoint_5(pod, func_80110024(pod), 14, *(s16 *) (cam + 0x58), 0);
    if (result == 4) {
        return result;
    }
    *(s32 *) (cam + 0x4C) = result;
    switch (cam[0x60]) {
        case 5:
        case 6:
            ended = _suspline_entrypoint_7(func_8001B798(*(s16 *) cam));
        case 8:
            break;
    }
    if (ended) {
        result =
            _ncpod_entrypoint_5(pod, func_80110024(pod), 12, *(s16 *) (cam + 0x58), 0);
        if (result == 4) {
            return result;
        }
        *(s32 *) (cam + 0x4C) = result;
    }
    return result;
}

// Advances the spline time by intro-sync or game time.
void func_80800944_ncpoducam(PodUCamSplineState *state)
{
    f32 dt;
    void *splinet;
    f32 current;

    if (state->use_intro_sync)
        dt = _glintrosyncDll_entrypoint_5();
    else
        dt = func_800D8FF8();
    switch (state->kind) {
        case 8:
            splinet = func_8001B798(state->splinet_handle);
            current = _susplinet_entrypoint_9(splinet);
            _susplinet_entrypoint_11(splinet, current);
            _susplinet_entrypoint_16(splinet, current, 100.0f * dt + current);
            break;
        case 5:
        case 6:
            _suspline_entrypoint_16(func_8001B798(state->spline_handle));
    }
}

void func_80800A18_ncpoducam(u8 *cam)
{
    s32 splinet;
    splinet = func_8001B798(*(s16 *) (cam + 2));
    _susplinet_entrypoint_17(splinet);
    _susplinet_entrypoint_7(splinet, 0, cam + 4);
    _susplinet_entrypoint_7(splinet, 1, cam + 0x10);
    *(f32 *) (cam + 0x50) = _susplinet_entrypoint_8(splinet, 0);
    *(f32 *) (cam + 0x54) = _susplinet_entrypoint_8(splinet, 1);
}

void func_80800A94_ncpoducam(u8 *cam, s32 pod)
{
    s32 out_cam;

    switch (cam[0x60]) {
        case 8:
            func_80800A18_ncpoducam(cam);
            break;
        case 5:
            func_80800704_ncpoducam(cam, 0);
            break;
        case 6:
            func_808003A8_ncpoducam(cam, 0);
            break;
    }
    out_cam = func_80110024(pod);
    _ncpod_entrypoint_8(out_cam, cam + 4, cam + 16);
    _ncpod_entrypoint_9(out_cam, *(f32 *) (cam + 0x50));
    if (*(f32 *) (cam + 0x50) == 40.0f && (cam[0x60] == 5 || cam[0x60] == 8)) {
        _ncpod_entrypoint_11(out_cam, *(f32 *) (cam + 0x54));
    }
}

s32 func_80800B74_ncpoducam(u8 *cam, s32 pod)
{
    s32 ended = 0;
    s32 result = 3;

    switch (cam[0x60]) {
        case 8:
            ended = _susplinet_entrypoint_2(func_8001B798(*(s16 *) (cam + 2)));
            break;
        case 5:
        case 6:
            ended = _suspline_entrypoint_1(func_8001B798(*(s16 *) cam));
    }
    if (ended) {
        if (*(s16 *) (cam + 0x48) & 0x20) {
            func_8080145C_ncpoducam(cam, pod, 2);
            result = _ncpod_entrypoint_5(pod, func_80110024(pod), 11,
                                          *(s16 *) (cam + 0x58), 0);
            if (result == 4)
                return result;
            *(s32 *) (cam + 0x4C) = result;
        } else {
            result = _ncpod_entrypoint_5(pod, func_80110024(pod), 11,
                                          *(s16 *) (cam + 0x58), 0);
            if (result == 4)
                return result;
            *(s32 *) (cam + 0x4C) = result;
            func_8080145C_ncpoducam(cam, pod, 3);
        }
    }
    return result;
}

// Counts the nodes in the chain starting at node_id.
int func_80800CB8_ncpoducam(node_id, kind)
s16 node_id;
s32 kind;
{
    u32 count = 0;
    while (node_id != -1) {
        func_800A5800(node_id);
        _cadbfunc_entrypoint_16(&node_id);
        count++;
    }

    return count;
}

// Kind 8: builds the timed spline from the node chain.
void func_80800D28_ncpoducam(UCamSpline49 *cam)
{
    f32 *vec_out[2];
    s32 *int_out[2];
    s16 *actor_ids;
    void *splinet;
    s32 count;
    s16 node;
    s16 i;
    s32 node_val[2];
    s32 unk_0;
    s16 *unk_1;
    f32 value;
    count = func_80800CB8_ncpoducam(cam->node_id, cam->kind);
    splinet = (void *) _susplinet_entrypoint_18(count, 2, 2);
    cam->splinet_handle = func_8001B668(0, splinet);
    splinet = func_8001B798(cam->splinet_handle);
    _susplinet_entrypoint_19(splinet, count, 2, 2);
    _susplinet_entrypoint_1(splinet, 1, 1);
    for (count = 0; count < 2; count++) {
        vec_out[count] = _susplinet_entrypoint_14(splinet, count);
    }
    for (count = 0; count != 2; count++) {
        int_out[count] = _susplinet_entrypoint_15(splinet, count);
    }
    actor_ids = _susplinet_entrypoint_12(splinet);
    unk_1 = _susplinet_entrypoint_13(splinet);
    node = cam->node_id;
    i = 0;
    while (node != -1) {
        func_800A5800(node);
        _cadbfunc_entrypoint_0(vec_out[0]);
        _cadbfunc_entrypoint_2(vec_out[1]);
        *unk_1 = -1;
        _cadbfunc_entrypoint_12(int_out[0]);
        _cadbfunc_entrypoint_24(node_val);
        *actor_ids = node_val[0];
        _cadbfunc_entrypoint_14(int_out[1]);
        _cadbfunc_entrypoint_29(0x100, &value);
        _susplinet_entrypoint_0(splinet, i, 2, value);
        _cadbfunc_entrypoint_29(0x200, &value);
        _susplinet_entrypoint_0(splinet, i, 4, value);
        _cadbfunc_entrypoint_29(0x400, &value);
        _susplinet_entrypoint_0(splinet, i, 1, value);
        actor_ids++;
        unk_1++;
        vec_out[0] += 3;
        vec_out[1] += 3;
        int_out[0]++;
        int_out[1]++;
        i++;
        _cadbfunc_entrypoint_16(&node);
    }
}

// Kind 6: builds the spline from the node chain.
void func_80800F64_ncpoducam(u8 *cam)
{
    f32 *vec_out[3];
    f32 *val_out[4];
    s32 count;
    s16 node;
    s16 i;
    f32 prev;
    s32 node_time[2];
    void *spline;

    count = func_80800CB8_ncpoducam(*(s16 *) (cam + 0x58), cam[0x60]);
    *(s16 *) cam = func_8001B668(0, _suspline_entrypoint_18(count, 3, 4));
    spline = func_8001B798(*(s16 *) cam);
    _suspline_entrypoint_19(spline, count, 3, 4, 2, 2);
    for (i = 0; i < 3; i++) {
        vec_out[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 4; i++) {
        val_out[i] = _suspline_entrypoint_11(spline, i);
    }
    i = 0;
    node = *(s16 *) (cam + 0x58);
    while (node != -1) {
        func_800A5800(node);
        _cadbfunc_entrypoint_0(vec_out[0]);
        _cadbfunc_entrypoint_2(vec_out[1]);
        _cadbfunc_entrypoint_10(val_out[2]);
        _cadbfunc_entrypoint_12(val_out[0]);
        *val_out[1] = 1.0f;
        _cadbfunc_entrypoint_18(val_out[3]);
        _cadbfunc_entrypoint_29(8, node_time);
        _suspline_entrypoint_0(spline, i, node_time[0]);
        vec_out[0] += 3;
        vec_out[1] += 3;
        val_out[2]++;
        val_out[0]++;
        val_out[1]++;
        val_out[3]++;
        i++;
        _cadbfunc_entrypoint_16(&node);
    }
    for (i = 0; i < 3; i++) {
        vec_out[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 4; i++) {
        val_out[i] = _suspline_entrypoint_11(spline, i);
    }
    func_800F0EF0(count, vec_out[1]);
    for (i = 0; i < count; i++) {
        prev = *val_out[3];
        *val_out[3] = vec_out[1][2];
        func_800EE7F8(vec_out[2], vec_out[1]);
        func_800EF4E4(vec_out[2], vec_out[2][0], vec_out[2][1], 0.0f, 0.0f, -prev);
        func_800EF04C(vec_out[2], vec_out[0]);
        vec_out[0] += 3;
        vec_out[1] += 3;
        vec_out[2] += 3;
        val_out[3]++;
    }
}

// Kind 5: builds the spline from the node chain.
void func_80801274_ncpoducam(u8 *cam)
{
    u8 *vec_out[2];
    u8 *val_out[3];
    void *count;
    s16 node;
    void *spline;
    s16 i;
    s32 node_time;

    count = func_80800CB8_ncpoducam(*(s16 *) (cam + 0x58), cam[0x60]);
    *(s16 *) cam = func_8001B668(0, _suspline_entrypoint_18(count, 2, 3));
    spline = func_8001B798(*(s16 *) cam);
    _suspline_entrypoint_19(spline, count, 2, 3, 0, 2);
    for (i = 0; i < 2; i++) {
        vec_out[i] = _suspline_entrypoint_10(spline, i);
    }
    for (i = 0; i < 3; i++) {
        val_out[i] = _suspline_entrypoint_11(spline, i);
    }
    i = 0;
    node = *(s16 *) (cam + 0x58);
    while (node != -1) {
        func_800A5800(node);
        _cadbfunc_entrypoint_0(vec_out[0]);
        _cadbfunc_entrypoint_2(vec_out[1]);
        _cadbfunc_entrypoint_10(val_out[2]);
        _cadbfunc_entrypoint_12(val_out[0]);
        _cadbfunc_entrypoint_14(val_out[1]);
        _cadbfunc_entrypoint_29(8, &node_time);
        _suspline_entrypoint_0(spline, i, node_time);
        vec_out[0] += 12;
        vec_out[1] += 12;
        val_out[2] += 4;
        val_out[0] += 4;
        val_out[1] += 4;
        i++;
        _cadbfunc_entrypoint_16(&node);
    }
    func_800F0EF0(count, _suspline_entrypoint_10(spline, 1));
}

// State change; state 1 picks the node kind and builds the spline.
void func_8080145C_ncpoducam(cam, pod, state) void *cam;
s32 pod;
s32 state;
{
    ((PodUserCameraState *) cam)->state = state;
    switch (state) {
        case 1:
            func_80800160_ncpoducam(cam);
            func_80800000_ncpoducam(cam);
            switch (((PodUserCameraState *) cam)->kind =
                        func_800A5854(((PodUserCameraState *) cam)->node_id)) {
                case 8:
                    func_80800D28_ncpoducam(cam);
                    return;
                case 5:
                    func_80801274_ncpoducam(cam);
                    return;
                case 6:
                    func_80800F64_ncpoducam(cam);
            }
            break;
        case 3:
            _ncpod_entrypoint_12(func_80110024(pod), 0);
    }
}

s32 ncpoducam_entrypoint_7(s16 handle, void *pod)
{
    u8 *cam;
    s32 result;

    cam = (u8 *) ncpoducam_entrypoint_1(handle);
    result = 3;
    switch (*(s32 *) (cam + 0x5C)) {
        case 0:
            break;
        case 1:
            func_808007D0_ncpoducam(cam);
            result = func_80800854_ncpoducam(cam, pod);
            if (result == 4) {
                return result;

}
if (*(s16 *) (cam + 0x48) & 2) {
    if (cam[0x64]) {
        func_80800944_ncpoducam(cam);
    } else {

cam[0x64] = 1;
}
}
func_80800A94_ncpoducam(cam, pod);
if (!(*(s16 *) (cam + 0x48) & 2)) {
    func_80800944_ncpoducam(cam);
}
result = func_80800B74_ncpoducam(cam, pod);
break;
case 2:
    result = func_80800854_ncpoducam(cam, pod);
    if (result == 4) {
        return result;
    }
    func_80800A94_ncpoducam(cam, pod);
case 3:
    break;
    }
    return result;
    }

    s32 ncpoducam_entrypoint_8(PodCameraState *cam, s32 arg)
    {
        switch ((*(PodCameraState **) &cam)->kind) { // Matching: the cast through &cam is needed for the match.
            case 8:
                return _susplinet_entrypoint_4(func_8001B798(cam->splinet_handle), arg);
            case 5:
            case 6:
                break;
        }
        return 0;
    }

    s32 ncpoducam_entrypoint_9(u8 *cam, f32 t)
    {
        void *spline;

        switch (cam[0x60]) {
            case 8:
                spline = func_8001B798(*(s16 *) (cam + 2));
                return _susplinet_entrypoint_5(spline, t);
            case 5:
            case 6:
                spline = func_8001B798(*(s16 *) cam);
                return _suspline_entrypoint_2(spline, t);
        }
        return 0;
    }

    f32 ncpoducam_entrypoint_10(u8 *cam)
    {
        switch (cam[0x60]) {
            case 8:
                return _susplinet_entrypoint_9(func_8001B798(*(s16 *) (cam + 2)));
            case 5:
            case 6:
                return _suspline_entrypoint_6(func_8001B798(*(s16 *) cam));
            default:
                return 0.0f;
        }
    }

    int ncpoducam_entrypoint_11(s32 cam[3])
    {
        func_800EE7F8(&cam[15]);
    }
