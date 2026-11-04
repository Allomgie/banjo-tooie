#include "common.h"

extern void *func_800F5EF8();
extern void *func_80110014(void *);
extern void _ncbadeflect_entrypoint_0(void *, s32, s32, s32, f32, f32);
extern void _ncbadeflect_entrypoint_1(s32, s32, s32, s32, f32);
extern void func_801110EC(s32, s32, s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_80110848(void *, s32, s32);
extern u8 D_80800510_plcamera[];
extern void *_gccubesearch_entrypoint_6(void *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);

// Reset the camera behind the player.
void plcamera_entrypoint_0(void)
{
    s32 saved;
    s32 controller;

    controller = func_800F5EF8();
    // Matching: extra temporary copy needed for the match.
    saved = controller;
    func_801108A0(func_80110014(controller));
    func_8010FD88(saved);
}

// Leave first-person view when the scene condition holds.
int plcamera_entrypoint_1(s32 unk_0)
{
    s32 unk_1;
    s32 unk_2;
    unk_1 = func_800F53E4();
    if (unk_1 == 0) {
        return 0;
    }
    unk_2 = unk_1;
    if ((func_800A3404(unk_2) != 0) && (func_800F693C(unk_0) != 0) && (func_800EA068(8) != 0)) {
        _bsfirstp_entrypoint_2(unk_2);
        return 1;
    }
    if (func_800A3404(unk_2) != 0) {
        return 1;
    }
    return 0;
}

// Set camera mode.
int plcamera_entrypoint_2(s32 player, s32 mode)
{
    int camera;
    camera = func_800F5EF8(player);
    camera = func_80110014(camera);
    func_801106A8(camera, mode);
}

// Set camera mode flag.
int plcamera_entrypoint_3(s32 player, s32 flag)
{
    int camera;
    camera = func_800F5EF8(player);
    camera = func_80110014(camera);
    func_80110720(camera, flag);
}

// Set camera position.
int plcamera_entrypoint_4(s32 player, s32 pos)
{
    u32 controller;
    controller = func_800F5EF8(player);
    func_80110770(func_80110014(controller), pos);
}

// Set camera target.
int plcamera_entrypoint_5(s32 player, s32 target)
{
    s32 controller;
    controller = func_800F5EF8(player);
    func_80110790(func_80110014(controller), target);
}

// Camera deflect: push the camera away.
void plcamera_entrypoint_6(void *player, s32 unk_1, s32 unk_2, s32 unk_3, f32 unk_4)
{
    void *camera;

    camera = func_800F5EF8(player);
    if (camera != NULL) {
        camera = func_80110014(camera);
        if (camera != NULL) {
            _ncbadeflect_entrypoint_0(camera, unk_1, unk_2, unk_3, unk_4, 1000.0f);
        }
    }
}

// Camera deflect, second variant.
void plcamera_entrypoint_7(s32 player, s32 unk_1, s32 unk_2, s32 unk_3)
{
    s32 camera = func_800F5EF8(player);
    if (camera != 0) {
        camera = func_80110014(camera);
        if (camera != 0) {
            _ncbadeflect_entrypoint_1(camera, unk_1, unk_2, unk_3, 1000.0f);
        }
    }
}

// Set camera yaw to player yaw + 180.
void plcamera_entrypoint_8(void)
{
    s32 saved;
    s32 controller;

    controller = func_800F5EF8();
    // Matching: extra temporary copy needed for the match.
    saved = controller;
    func_80110928(func_80110014(controller));
    func_8010FD88(saved);
}

// Set target-mode parameters (only in camera mode 0x14).
void plcamera_entrypoint_9(s32 player, s32 unk_1, s32 unk_2)
{
    func_801110EC(func_80110014(func_800F5EF8(player)), unk_1, unk_2);
}

// Get camera mode.
int plcamera_entrypoint_10()
{
    // Matching: `| 0` is needed for the match.
    func_801106A0((s32) func_80110014(func_800F5EF8()) | 0);
}

s32 func_80800300_plcamera(origin, point)
f32 *origin;
f32 *point;
{
    void *cube;
    cube = _gccubesearch_entrypoint_6(D_80800510_plcamera, origin);
    if (cube == NULL)
        return 0;
    _gspropctrl_entrypoint_11(cube, point);
    return func_800EEB40(origin, point) < 4000000.0f;
}

// Look-at "goto" that probes the cube grid.
void plcamera_entrypoint_11(s32 player, f32 *pos)
{
    s32 controller;
    s32 camera;
    f32 cam_pos[3];
    f32 player_pos[3];
    f32 cam_rel[3];
    f32 pos_rel[3];
    f32 dot;
    f32 delta[3];

    controller = (s32) func_800F5EF8((void *) player);
    camera = func_80110014(controller);
    func_800F5A00(player, player_pos);
    func_801107F0(camera, cam_pos);
    func_800EFB24(cam_rel, cam_pos, player_pos);
    func_800EFB24(pos_rel, pos, player_pos);
    dot = func_800EEAA4(cam_rel, pos_rel);
    func_80110720(camera, 0);
    if (dot > 0.0f && func_80800300_plcamera(player_pos, cam_pos)) {
        func_800A516C(delta, pos, cam_pos);
        delta[0] += 10.0f;
        func_8010FE14(controller, cam_pos, delta);
    }
}

// Queue position and rotation request (0x28).
int plcamera_entrypoint_12(s32 player, s32 unk_1, s32 unk_2)
{
    // Matching: `| 0` is needed for the match.
    func_8010FDA8((s32) func_800F5EF8(player) | 0, unk_1, unk_2);
}

// Queue look-at request (0x29).
s32 plcamera_entrypoint_13(s32 player, s32 unk_1)
{
    s32 controller;

    controller = func_800F5EF8(player);
    func_8010FDEC(controller, unk_1);
}

void plcamera_entrypoint_14(void *player, s32 unk_1, s32 unk_2)
{
    func_80110848(func_80110014(func_800F5EF8(player)), unk_1, unk_2);
}

// TU-NOTE: overlay .data is defined here in C (values taken from the ROM).
u8 D_80800510_plcamera[16] = {0x0, 0x0, 0x4, 0xC8, 0xFF, 0xFF, 0xFF, 0xFF,
                              0x0, 0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x0};
