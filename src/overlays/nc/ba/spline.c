// Spline (rail) camera mode: a trigger prop attaches the camera to a level path, and it slides
// along the rail to stay 500..550 units from the player with eased speed and blend-in.
#include "common.h"

extern s32 func_800D5424(s32);
typedef struct {
    s32 path_id;
    s32 unk_4;
    f32 t;
    f32 start_pos[3];
    f32 blend;
    f32 rail_pos[3];
    s32 trigger_id;
    u8 unk_2C;
    u8 unk_2D;
    u8 unk_2E;
    u8 unk_2F;
} SplineState48;
extern f32 func_800C82CC(s32, f32 *);
extern f32 func_800FB1EC(s32, f32, f32 *, s32);
extern void func_800C7A68(s32, f32, f32 *);
extern void _gspropctrl_entrypoint_11(void *, f32 *);
extern void *_gccubesearch_entrypoint_14(s32, s32 *);
extern f32 func_800C7B28(s32, f32, f32, s32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800EF368(f32 *, f32);
extern f32 func_800C7FD4(s32, f32, f32);
extern f32 mlAbsF(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF334(f32 *, f32);
extern void func_800EE780();
extern void func_80110770();
extern void func_80110790();
extern void func_801107F0();
extern void func_80110A68();
extern void func_80112524();
void ncbaspline_entrypoint_7();

s32 ncbaspline_entrypoint_0()
{
    return 0x30;
}

int func_80800008_ncbaspline(u8 *cam)
{
    func_800D7520(**(s32 **) ((s8 *) cam + 0x44));
}

void func_8080002C_ncbaspline(cam) u8 *cam;
{
    u8 *state;

    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (0))) = -1;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (4))) = 0.0f;
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (8))) = 0.0f;
    (*(s32 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (0x28))) = 0;
    (*(s8 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (0x2C))) = 0;
    (*(u8 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (0x2F))) = 0U;
    state = (*(u8 **) ((s8 *) (cam) + (0x44)));
    (*(u8 *) ((s8 *) (state) + (0x2E))) = (u8) (*(u8 *) ((s8 *) (state) + (0x2F)));
    func_800EFD24((*(u8 **) ((s8 *) (cam) + (0x44))) + 0xC, cam);
    func_800EFD24((*(u8 **) ((s8 *) (cam) + (0x44))) + 0x1C, cam);
    (*(f32 *) ((s8 *) ((*(u8 **) ((s8 *) (cam) + (0x44)))) + (0x18))) = 0.0f;
}

void ncbaspline_entrypoint_1()
{
    func_8080002C_ncbaspline();
}

int ncbaspline_entrypoint_2(Actor *cam)
{
    func_801124D0(cam, 0x1);
    func_80111B8C(cam, 0x40400000, 0x41000000);
}

void ncbaspline_entrypoint_3()
{
    func_8080002C_ncbaspline();
}

s32 func_80800130_ncbaspline(s32 cam, s32 focus)
{
    s32 saved;

    saved = func_80112518(cam);
    func_801124D0(cam, 1);
    func_80112524(cam, focus);
    func_801124D0(cam, saved);
}

f32 func_8080017C_ncbaspline(u8 *cam, s32 path, f32 *focus, f32 *cam_pos)
{
    f32 proj_pos[3];
    f32 near_pos[3];
    f32 step_pos[3];
    f32 dir[3];
    f32 near_t;
    f32 cur_t;
    near_t = func_800C82CC(path, focus);

if (near_t == 0.0f || near_t == 1.0f) {
    func_800C7A68(path, near_t, near_pos);
    if (near_t == 0.0f) {
        func_800C7A68(path, near_t + 0.001f, step_pos);
    } else {
        func_800C7A68(path, near_t - 0.001f, step_pos);
    }
    func_800EFB24(dir, step_pos, near_pos);
    func_800EF368(dir, 400.0f);
    func_800EE780(step_pos, dir, near_pos);
    func_800F018C(proj_pos, near_pos, step_pos, focus);
    return func_800EEAD4(proj_pos, cam_pos);
}

func_800C7A68(path, near_t, proj_pos);
cur_t = (*(f32 **) (cam + 0x44))[2];

if (near_t < cur_t) {
    return func_800C7B28(path, near_t, cur_t, 0xF);
}

else
{
    return func_800C7B28(path, cur_t, near_t, 0xF);
}
}

// Adjusts the rail speed to keep 500..550 units from the player; returns 0 to release the camera.
s32 func_80800318_ncbaspline(cam, cam_pos)
u8 *cam;
f32 *cam_pos;
{
    Vec3f ahead_pos;
    Vec3f behind_pos;
    Vec3f focus;
    f32 ahead_dist;
    f32 behind_dist;
    f32 ahead_t;
    f32 behind_t;
    f32 speed;
    f32 dir;
    f32 rail_dist;
    s32 path;

    path = func_80800008_ncbaspline(cam);
    func_80800130_ncbaspline(cam, focus.f);
    rail_dist = func_8080017C_ncbaspline(cam, path, focus.f, cam_pos);
    ahead_t = func_800C7FD4(path, (*(f32 **) (cam + 0x44))[2], 1000.0f);
    behind_t = func_800C7FD4(path, (*(f32 **) (cam + 0x44))[2], -1000.0f);
    func_800C7A68(path, ahead_t, ahead_pos.f);
    func_800C7A68(path, behind_t, behind_pos.f);
    ahead_dist = func_800EEAD4(focus.f, ahead_pos.f);
    behind_dist = func_800EEAD4(focus.f, behind_pos.f);
    speed = 0.0f;

if (mlAbsF(ahead_dist - behind_dist) > 3.0f) {
    dir = ahead_dist < behind_dist ? 1.0f : -1.0f;
    if (rail_dist > 550.0f) {
        speed = func_800F10B4(rail_dist, 550.0f, 650.0f, 0.0, 1500.0f) * dir;
    } else if (rail_dist < 500.0f) {
        speed = func_800F10B4(rail_dist, 4e+02f, 500.0f, 1500.0f, 0.0f) * -dir;
    }
    if (mlAbsF((*(f32 **) (cam + 0x44))[1]) < mlAbsF(speed)) {
        (*(f32 **) (cam + 0x44))[1] += (speed - (*(f32 **) (cam + 0x44))[1]) * 0.08f;
    } else {
        (*(f32 **) (cam + 0x44))[1] = speed;
    }
    (*(f32 **) (cam + 0x44))[2] =
        func_800C7FD4(path, (*(f32 **) (cam + 0x44))[2], (*(f32 **) (cam + 0x44))[1]);
    if ((speed > 0.0f && (*(f32 **) (cam + 0x44))[2] == 1.0f &&
         (*(u8 **) (cam + 0x44))[0x2F] == 0) ||
        (speed < 0.0f && (*(f32 **) (cam + 0x44))[2] == 0.0f &&
         (*(u8 **) (cam + 0x44))[0x2E] == 0)) {
        return 0;
    }
} else {

return 1;
}
if (speed) {
    return 1;
}
return 2;
}

void ncbaspline_entrypoint_4(u8 *cam)
{
    f32 focus[3];
    f32 offset[3];
    f32 fade;
    f32 cam_pos[3];
    f32 cam_rot[3];
    if (**(s32 **) (cam + 0x44) == -1) {
        return;
    }

if ((*(u8 **) (cam + 0x44))[0x2C] == 1) {
    (*(u8 **) (cam + 0x44))[0x2C] = 2;
}

func_801107F0(cam, cam_pos);

if (*(s32 *) (*(u8 **) (cam + 0x44) + 0x28) == -1 ||
    !func_80800318_ncbaspline(cam, cam_pos)) {
    *(s32 *) (*(u8 **) (cam + 0x44) + 0x28) = 0;
    return;
}

func_800C7A68(func_80800008_ncbaspline(cam), *(f32 *) (*(u8 **) (cam + 0x44) + 8), cam_pos);

if (*(f32 *) (*(u8 **) (cam + 0x44) + 0x18) < 1.0f) {
    fade = func_800F10B4(*(f32 *) (*(u8 **) (cam + 0x44) + 0x18), 0.5f, 1.0f, 0.05f, 0.01f);
    *(f32 *) (*(u8 **) (cam + 0x44) + 0x18) += (30.0f * func_800D8FF8()) * fade;
    if (*(f32 *) (*(u8 **) (cam + 0x44) + 0x18) < 1.0f) {
        func_800EFB24(offset, cam_pos, *(u8 **) (cam + 0x44) + 0xC);
        func_800EF334(offset, *(f32 *) (*(u8 **) (cam + 0x44) + 0x18));
        func_800EE780(cam_pos, *(u8 **) (cam + 0x44) + 0xC, offset);
    }
}

func_80110770(cam, cam_pos);
func_80112524(cam, focus);
func_80110A68(cam, cam_rot, focus);
func_80110790(cam, cam_rot);
}

void ncbaspline_entrypoint_5(void *cam, int unk_1, int unk_2)
{
    int *state;

    state = (int *) *((int *) cam + 0x11);

if (state[0xa] != 0) {
    state[0xa] = -1;
}

}

void ncbaspline_entrypoint_6(s32 cam, u8 *prop, s32 unk_2)
{
    ncbaspline_entrypoint_7(cam, func_800D5424(*(u16 *) (prop + 8)));
}

void ncbaspline_entrypoint_7(cam, trigger) u8 *cam;
s32 trigger;
{
    f32 pos[3];
    s32 cube[3];
    f32 cam_pos[3];
    s32 id;
    s32 player;
    void *prop;

    player = func_80110840(cam);

if (func_800F5C94(player) != 4) {
    id = func_800D542C(trigger);
    if (id != (*(SplineState48 **) (cam + 0x44))->trigger_id &&
        (*(SplineState48 **) (cam + 0x44))->trigger_id != -1) {
        func_801107B0(cam, pos);
        func_800EE904(cube, pos);
        prop = _gccubesearch_entrypoint_14(id, cube);
        if (prop != NULL) {
            _gspropctrl_entrypoint_11(prop, pos);
            switch (_gspropctrl_entrypoint_13(prop)) {
                case 1:
                    (*(SplineState48 **) (cam + 0x44))->unk_2E = 1;
                    (*(SplineState48 **) (cam + 0x44))->unk_2F = 0;
                    break;
                case 2:
                    (*(SplineState48 **) (cam + 0x44))->unk_2E = 0;
                    (*(SplineState48 **) (cam + 0x44))->unk_2F = 1;
                    break;
                case 3:
                    (*(SplineState48 **) (cam + 0x44))->unk_2E = 1;
                    (*(SplineState48 **) (cam + 0x44))->unk_2F = 1;
                    break;
                default:
                    (*(SplineState48 **) (cam + 0x44))->unk_2E = 0;
                    (*(SplineState48 **) (cam + 0x44))->unk_2F = 0;
                    break;
            }
            (*(SplineState48 **) (cam + 0x44))->unk_2D = func_801106A0(cam);
            func_801107F0(cam, cam_pos);
            func_800EE7F8((*(SplineState48 **) (cam + 0x44))->start_pos, cam_pos);
            (*(SplineState48 **) (cam + 0x44))->blend = 0.0f;
            (*(SplineState48 **) (cam + 0x44))->trigger_id = id;
            (*(SplineState48 **) (cam + 0x44))->path_id = _glsplinefind_entrypoint_3(pos);
            (*(SplineState48 **) (cam + 0x44))->t =
                func_800C82CC(func_80800008_ncbaspline(cam), cam_pos);
            (*(SplineState48 **) (cam + 0x44))->t =
                func_800FB1EC(func_80800008_ncbaspline(cam),
                              (*(SplineState48 **) (cam + 0x44))->t, cam_pos, 0x20020);
            (*(SplineState48 **) (cam + 0x44))->unk_2C = 1;
            func_800C7A68(func_80800008_ncbaspline(cam),
                          (*(SplineState48 **) (cam + 0x44))->t,
                          (*(SplineState48 **) (cam + 0x44))->rail_pos);
            if (func_80800318_ncbaspline(cam,
                                         (*(SplineState48 **) (cam + 0x44))->rail_pos) == 1) {
                func_801106A8(cam, 14);
                func_800F7E9C(func_80110840(cam), 1);
            } else {
                (*(SplineState48 **) (cam + 0x44))->trigger_id = 0;
            }
        }
    }
}

}

int ncbaspline_entrypoint_8(void *cam)
{
    return (*(int **) ((char *) cam + 0x44))[0x28 / 4] < 1;
}
