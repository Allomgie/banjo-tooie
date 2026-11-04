// First-person camera mode: keeps current/target position and rotation, blends in from and out to
// the third-person camera, and exposes look-angle and sub-state accessors to the first-person code.
#include "common.h"

extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F7B9C(s32, s32);
extern s32 func_80110840(void);
typedef struct {
    f32 position[3];
    f32 rotation[3];
    f32 head_position[3];
    f32 head_rotation[3];
    f32 start_position[3];
    f32 start_rotation[3];
    f32 timer;
} CameraTransitionData1202;
typedef struct {
    CameraTransitionData1202 *data;
} CameraTransition1202;
extern void func_801163A0(void *, f32);
extern f32 func_800F130C(f32, f32, f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
typedef struct {
    f32 position[3];
    f32 rotation[3];
    f32 target_position[3];
    f32 target_rotation[3];
    u8 pad_30[0x20];
    u8 smooth;
} BaCameraTransform;
extern void func_80111410(void *, f32 *, f32 *, f32);
typedef struct {
    f32 vectors[6][3];
    u8 pad_48[4];
    s32 sub_state;
    u8 smooth;
    u8 msg_sent;
} FirstPersonCameraData;
typedef struct {
    FirstPersonCameraData *data;
} FirstPersonCamera;
extern void func_80111590(void *, f32, f32, f32, f32);
extern void func_80110728();
extern void func_801107F0();
extern void func_80110818();
extern void func_800EE7F8();
typedef struct {
    u8 unused[0x24];
    f32 angles[3];
} BaCameraOrientation;
void ncba1p_entrypoint_3();
void ncba1p_entrypoint_5();

void *D_exp_ncba1p_entrypoint_5[] = {(void *) ncba1p_entrypoint_5};

s32 ncba1p_entrypoint_0()
{
    return 0x54;
}

// True when the two positions are closer than 40 units.
int func_80800008_ncba1p(void *cam, f32 *pos_a, f32 *pos_b)
{
    return func_800EEAD4(pos_a, pos_b) < 40.0f;
}

// Sends a player message once per transition.
void func_8080004C_ncba1p(u8 **cam, s32 msg)
{
    s32 player;
    player = func_80110840();
    if ((*cam)[0x51] == 0) {
        func_800F7B9C(player, msg);
        player = 1;
        (*cam)[0x51] = player;
    }
}

void func_808000A0_ncba1p(CameraTransition1202 *cam, f32 *out_pos, f32 *out_rot)
{
    s32 i;
    f32 angle;
    f32 scale;

    func_800D9078(&cam->data->timer);
    scale = cam->data->timer * 1;
    func_801163A0(cam, scale);
    for (i = 0; i < 3; i++) {
        cam->data->position[i] =
            func_800F130C(cam->data->timer, 1, 0, cam->data->start_position[i],
                          cam->data->head_position[i]);
        angle = func_800F130C(
            cam->data->timer, 0.5f, 0.0f, 0.0f,
            func_800F1DCC(cam->data->head_rotation[i], cam->data->start_rotation[i]));
        angle += cam->data->start_rotation[i];
        cam->data->rotation[i] = func_800136E4(angle);
    }
    if (0 == cam->data->timer)
        ncba1p_entrypoint_5(cam, 2);
    if (func_80800008_ncba1p(cam, cam->data->position, cam->data->head_position))
        func_8080004C_ncba1p(cam, 0x62);
    func_800EE7F8(out_pos, cam->data->position);
    func_800EE7F8(out_rot, cam->data->rotation);
}

void func_80800230_ncba1p(CameraTransition1202 *cam, f32 *out_pos, f32 *out_rot)
{
    s32 i;
    f32 angle;
    f32 scale;

    func_800D9078(&cam->data->timer);
    scale = 1 - cam->data->timer * 1;
    func_801163A0(cam, scale);
    for (i = 0; i < 3; i++) {
        cam->data->position[i] =
            func_800F130C(cam->data->timer, 1, 0.0f, cam->data->head_position[i],
                          out_pos[i]);
        angle =
            func_800F130C(cam->data->timer, 1, 0.5f, 0.0f,
                          func_800F1DCC(out_rot[i], cam->data->head_rotation[i]));
        angle += cam->data->head_rotation[i];
        cam->data->rotation[i] = func_800136E4(angle);
    }
    if (0.0f == cam->data->timer)
        ncba1p_entrypoint_5(cam, 4);
    if (!func_80800008_ncba1p(cam, cam->data->head_position, cam->data->position))
        func_8080004C_ncba1p(cam, 0x63);
    func_800EE7F8(out_pos, cam->data->position);
    func_800EE7F8(out_rot, cam->data->rotation);
}

void func_808003DC_ncba1p(BaCameraTransform **cam, f32 *out_pos, f32 *out_rot)
{
    func_801163A0(cam, 0.0f);
    func_800EE7F8((*cam)->position, (*cam)->target_position);
    if ((*cam)->smooth) {
        func_80111410(cam, (*cam)->target_rotation, (*cam)->rotation, 120.0f);
    } else {
        func_800EE7F8((*cam)->rotation, (*cam)->target_rotation);
    }
    func_800EE7F8(out_pos, (*cam)->position);
    func_800EE7F8(out_rot, (*cam)->rotation);
}

void ncba1p_entrypoint_1(FirstPersonCamera *cam)
{
    if (!_plcamera_entrypoint_1(func_80110840())) {
        func_800EFD24(cam->data->vectors[0]);
        func_800EFD24(cam->data->vectors[1]);
        func_800EFD24(cam->data->vectors[2]);
        func_800EFD24(cam->data->vectors[3]);
        func_800EFD24(cam->data->vectors[4]);
        func_800EFD24(cam->data->vectors[5]);
        cam->data->sub_state = 0;
        cam->data->smooth = 1;
        cam->data->msg_sent = 0;
        func_80111590(cam, 10.0f, 20.0f, 120.0f, 300.0f);
    }
}

void ncba1p_entrypoint_2(s32 *cam)
{
    f32 pos[3];
    f32 rot[3];

    ((s32 *) cam[0])[0x13] = 2;
    ((u8 *) cam[0])[0x50] = 0;
    ncba1p_entrypoint_3(cam, pos, rot);
}

void ncba1p_entrypoint_3(cam, out_pos, out_rot) u8 **cam;
s32 out_pos;
s32 out_rot;
{
    s32 sub_state;

    sub_state = *(s32 *) (*cam + 0x4C);
    if (sub_state != 4 && sub_state != 0) {
        func_8011607C(cam, 0);
        sub_state = *(s32 *) (*cam + 0x4C);
    }
    switch (sub_state) {
        case 1:
            func_808000A0_ncba1p(cam, out_pos, out_rot);
            break;
        case 2:
            func_808003DC_ncba1p(cam, out_pos, out_rot);
            break;
        case 3:
            func_80800230_ncba1p(cam, out_pos, out_rot);
            break;
        case 4:
            break;
    }
}

void ncba1p_entrypoint_4(void *arg, s32 v)
{
    ((s8 *) *(void **) ((char *) arg + 0x0))[80] = v;
}

void ncba1p_entrypoint_5(cam, new_state) u8 **cam;
s32 new_state;
{
    u8 *data;

    switch (*(s32 *) (*cam + 0x4C)) {
        case 1:
            if (new_state == 1)
                break;
            func_8080004C_ncba1p(cam, 0x62);
            break;
        case 3:
            if (new_state == 3)
                break;
            func_8080004C_ncba1p(cam, 0x63);
    }
    switch (new_state) {
        case 1:
            func_80110728(cam, 1);
            data = *cam;
            if (*(u32 *) (data + 0x4C) == 3) {
                func_800EE7F8(*cam + 0x30, *cam);
                func_800EE7F8(*cam + 0x3C, *cam + 0xC);
            } else {
                func_801107F0(cam, *cam);
                func_80110818(cam, *cam + 0xC);
                func_801107F0(cam, *cam + 0x30);
                func_80110818(cam, *cam + 0x3C);
            }
            *(f32 *) (*cam + 0x48) = 1.0f;
            (*cam)[0x51] = 0;
            break;

        case 3:
            *(f32 *) (*cam + 0x48) = 1.0f;
            (*cam)[0x51] = 0;
            break;

        case 4:
            func_801163A0(cam, 1.0f);
            func_80110728(cam, 0);
            break;

        case 2:
            break;
    }
    *(s32 *) (*cam + 0x4C) = new_state;
}

void ncba1p_entrypoint_6(Actor *param_0)
{
    s32 *base;
    s32 *base_copy;
    // Matching: the double assignment through temporaries is needed for the match.
    base_copy = (s32 *) ((base = (char *) param_0) + 0);
    func_800EE7F8(*base + 24);
}

void ncba1p_entrypoint_7(BaCameraOrientation **cam, f32 *angles)
{
    (*cam)->angles[0] = func_800136E4(angles[0]);
    (*cam)->angles[1] = func_800136E4(angles[1]);
    (*cam)->angles[2] = func_800136E4(angles[2]);
}

void ncba1p_entrypoint_8(s32 *cam, s32 out_angles)
{
    func_800EE7F8(out_angles, *(s32 *) (cam + 0) + 0x24);
}

f32 ncba1p_entrypoint_9(u8 **cam)
{
    return *(f32 *) ((s8 *) *cam + 0x10);
}

s32 ncba1p_entrypoint_10(u8 **cam)
{
    return *(s32 *) ((s8 *) *cam + 0x4C);
}

f32 ncba1p_entrypoint_11(u8 **cam)
{
    return *(f32 *) ((char *) *cam + 0x48);
}

int ncba1p_entrypoint_12(s32 cam, f32 value)
{
    int offset;
    // Matching: the offset goes through a temporary assignment.
    *(f32 *) (*(u8 **) cam + (offset = 0x48)) = value;
}

int ncba1p_entrypoint_13(s32 cam[3], s32 out_pos, s32 out_rot)
{
    // Matching: `| 0` is needed for the match.
    func_800EE7F8(out_pos | 0, cam[0]);
    func_800EE7F8(out_rot, cam[0] + 0xC);
}
