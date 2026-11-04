#include "common.h"

typedef struct {
    unsigned high : 26;
    unsigned enabled : 1;
    unsigned low : 5;
} FogInitFlags;
typedef struct {
    unsigned high : 12;
    unsigned active : 1;
    unsigned low : 19;
} FogActiveFlags;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern void *D_80800A90_chfog;
typedef struct {
    f32 unk_0, offset_x, offset_y;
    u8 pad_0C[12];
    f32 direction_x, direction_y;
    u8 pad_20[8];
    f32 speed_x, speed_y;
    u8 pad_30[4];
    f32 timer;
    u8 pad_38[12];
    f32 prev_pos[3];
    f32 prev_pitch, prev_yaw;
    u8 pad_58[12];
    struct {
        unsigned high : 12;
        unsigned active : 1;
        unsigned low : 19;
    } flags;
    u8 pad_68[10];
    struct {
        unsigned short value : 6;
        unsigned short low : 10;
    } state;
} FogState;
extern f32 func_800DC0C0(void);
extern void func_800E3B50(f32 *, f32 *, f32 *);
extern void func_800E3980(f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F54E4(void);
extern s32 func_800F690C(s32);
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800D90A4(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddiefade_entrypoint_1(void *, s32);

// Remove handler: pop the air-drain type.
void func_80800000_chfog(s32 unk_0)
{
    func_800CF494();
}

// Init: push the air-drain type for this map and set up the fog state.
void func_80800020_chfog(u8 *actor)
{
    // Capture the camera position and reset the fog motion vectors.
    func_800E3980(actor + 0x44);
    func_800EFD24(actor + 4);
    func_800EFD24(actor + 0x28);
    *(f32 *) (actor + 0x18) = 1.0f;
    *(f32 *) (actor + 0x1C) = 1.0f;

    // Select map-specific fog resources and fade behavior.
    switch (func_800EA05C()) {
        case 0x10D:
            if (func_800DA298(0x1BD) == 0) {
                func_800FFAB0(actor);
            } else if (((FogInitFlags *) (actor + 0x78))->enabled &&
                       func_800F6438(func_800F54E4()) != 0) {
                *(f32 *) (actor + 0x34) = 0.0f;
                func_800CF2D4(4);
            }
            ((FogActiveFlags *) (actor + 0x64))->active = 1;
            *(f32 *) (actor + 0x24) = 0.0f;
            return;
        case 0x138:
            func_800CF2D4(6);
            return;
        case 0x162:
            func_80101FDC(actor, 2);
            _subaddiefade_entrypoint_2(actor);
            func_800CF2D4(7);
            return;
        case 0x19A:
            func_80101FDC(actor, 2);
            _subaddiefade_entrypoint_2(actor);
            func_800CF2D4(8);
            actor[0x75] &= 0xFFFD;
            return;
        default:
            func_800CF2D4(2);
    }
}

void func_80800174_chfog(s32 *actor, s32 gfx)
{
    f32 view_pos[3];
    f32 view_rot[3];
    s32 *actor_416;
    s32 *actor_176;

    // Select the fog render mode and update the map-specific companion.
    switch (func_800EA05C()) {
        case 0x10D:
            actor_416 = _subaddiefind_entrypoint_2(0x416, 0);
            if (actor_416) {
                func_80101870(actor_416, gfx);
            }
            func_800DF744(3, 1);
            break;
        case 0xDB:
            actor_176 = _subaddiefind_entrypoint_2(0x176, 0);
            if (actor_176) {
                func_80101074(gfx);
                func_8010114C(*actor_176, 0xAB, 0);
            }
            func_800DF744(3, 1);
            break;
        case 0x138:
            func_800DF744(3, 2);
            break;
        case 0x162:
            func_800DF744(3, 2);
            break;
        case 0x19A:
            func_800DF744(3, 3);
            break;
        default:
            func_800DF744(3, 1);
    }

    // Temporarily use a fixed view to render the moving fog layer.
    func_800E41CC();
    func_800EFA4C(view_pos, 0.0f, 0.0f, 300.0f);
    func_800EFD24(view_rot);
    func_800E3BAC(view_pos);
    func_800E3C30(view_rot);
    func_800E3CE8();
    func_800E44FC(gfx);
    view_rot[0] = -90.0f;
    func_800DF410(_subaddiefade_entrypoint_0(actor));
    func_800DF830(0);
    func_800DE448((f32 *) (actor + 1), view_rot, 0.2f, 0, func_8010347C(*actor));
    func_800E4208();
    func_800E44FC(gfx);
}

// Per-frame update: drift the fog and compensate for camera movement.
void func_8080032C_chfog(FogState *fog)
{
    f32 cam_roll;
    f32 cam_pitch;
    f32 cam_yaw;
    f32 cam_pos[3];
    f32 cam_delta[3];
    s16 move_dir;

    // Occasionally reverse the independent drift directions.
    if (func_800DC0C0() < 0.01f)
        fog->direction_x = -fog->direction_x;
    if (func_800DC0C0() < 0.01f)
        fog->direction_y = -fog->direction_y;
    if (fog->direction_x == 1.0f) {
        if (fog->speed_x < 0.15f)
            fog->speed_x += 0.05f;
    } else if (fog->speed_x > -0.15f)
        fog->speed_x -= 0.05f;
    if (fog->direction_y == 1.0f) {
        if (fog->speed_y < 0.15f)
            fog->speed_y += 0.05f;
    } else if (fog->speed_y > -0.15f)
        fog->speed_y -= 0.05f;
    // Reverse at the bounds; do not advance an offset on the reversal tick.
    if (fog->offset_x < -200.0f && fog->direction_x != 1.0f) {
        fog->direction_x = 1.0f;
    } else if (fog->offset_x > 200.0f && fog->direction_x != -1.0f) {
        fog->direction_x = -1.0f;
    } else
        fog->offset_x += fog->speed_x;
    if (fog->offset_y < -200.0f && fog->direction_y != 1.0f) {
        fog->direction_y = 1.0f;
    } else if (fog->offset_y > 200.0f && fog->direction_y != -1.0f) {
        fog->direction_y = -1.0f;
    } else
        fog->offset_y += fog->speed_y;

    move_dir = 0;
    // Resolve horizontal movement against four yaw sectors. The alternate
    // camera mode uses angle changes instead of position displacement.
    func_800E3B50(&cam_pitch, &cam_yaw, &cam_roll);
    func_800E3980(cam_pos);
    func_800EFB24(cam_delta, cam_pos, fog->prev_pos);
    if (!func_800F690C(func_800F54E4())) {
        if (cam_yaw > 135.0f && cam_yaw < 225.0f) {
            if (cam_delta[0] < -5.0f)
                move_dir = 1;
            if (cam_delta[0] > 5.0f)
                move_dir = -1;
        }
        if (cam_yaw > 315.0f || cam_yaw < 45.0f) {
            if (cam_delta[0] < -5.0f)
                move_dir = -1;
            if (cam_delta[0] > 5.0f)
                move_dir = 1;
        }
        if (cam_yaw > 45.0f && cam_yaw < 135.0f) {
            if (cam_delta[2] < -5.0f)
                move_dir = 1;
            if (cam_delta[2] > 5.0f)
                move_dir = -1;
        }
        if (cam_yaw > 225.0f && cam_yaw < 315.0f) {
            if (cam_delta[2] < -5.0f)
                move_dir = -1;
            if (cam_delta[2] > 5.0f)
                move_dir = 1;
        }
    } else {
        if (fog->prev_yaw < cam_yaw)
            move_dir = -1;
        if (fog->prev_yaw > cam_yaw)
            move_dir = 1;
        if (fog->prev_pitch > cam_pitch)
            cam_delta[1] = -5.0f;
        if (fog->prev_pitch < cam_pitch)
            cam_delta[1] = 5.0f;
        fog->prev_yaw = cam_yaw;
        fog->prev_pitch = cam_pitch;
    }
    func_800EE7F8(fog->prev_pos, cam_pos);
    // Smooth toward the camera-response speeds, otherwise damp the drift.
    // Both damping tests use +0.15f, as in the original code.
    if (move_dir == 1) {
        fog->direction_x = -1.0f;
        fog->speed_x += (-5.0f - fog->speed_x) * 0.5f;
    } else if (move_dir == -1) {
        fog->direction_x = 1.0f;
        fog->speed_x += (5.0f - fog->speed_x) * 0.5f;
    } else {
        if (fog->speed_x > 0.15f || fog->speed_x < 0.15f)
            fog->speed_x *= 0.8f;
    }
    if (cam_delta[1] > 2.5f) {
        fog->direction_y = -1.0f;
        fog->speed_y += (-2.0f - fog->speed_y) * 0.5f;
    } else if (cam_delta[1] < -2.5f) {
        fog->direction_y = 1.0f;
        fog->speed_y += (2.0f - fog->speed_y) * 0.5f;
    } else if (fog->speed_x > 0.15f || fog->speed_x < 0.15f)
        fog->speed_x *= 0.3f;
    // The fallback above damps speed_x, not speed_y, as in the original.
    // State 1 updates the fade only when the active flag is set.
    switch (fog->state.value) {
        case 1:
            if (fog->flags.active) {
                if (!func_800D90A4(&fog->timer)) {
                    _subaddiefade_entrypoint_1(
                        fog, (s32) func_800F10B4(fog->timer, 0.0f, 8.0f, 255.0f, 0.0f));
                }
            }
        case 2:
            break;
    }
}

s32 func_808009F0_chfog(void *actor, s32 msg, s32 unk_2)
{
    switch (msg) {
        case 0x4F:
            // Release the fade state and fog resources, pop the air-drain type.
            _subaddiefade_entrypoint_3(actor);
            func_800CF494();
            break;
        default:
            return 0;
    }
    return 1;
}

int chfog_entrypoint_0()
{
    return &D_80800A90_chfog;
}

extern void func_80105834();
extern void func_80107C2C();
// TU-NOTE: the overlay .data is defined here in C (values from the ROM). IDO's
// assembler schedules some functions differently unless the tables that point
// to them are in the same unit.
void *D_80800A90_chfog = (void *) 0x025C0178;
static u32 D_80800A90_chfog_rest[19] = {0x68C0001,
                                        0x0,
                                        (u32) func_8080032C_chfog,
                                        (u32) func_80105834,
                                        (u32) func_80800174_chfog,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x21404,
                                        (u32) func_80800000_chfog,
                                        0x0,
                                        0x0,
                                        (u32) func_80800020_chfog,
                                        (u32) func_80107C2C,
                                        0x80000402,
                                        (u32) func_808009F0_chfog,
                                        0x0,
                                        0x0,
                                        0x0};
