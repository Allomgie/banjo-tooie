// Camera mode for Kazooie's Talon Torpedo: follows the player and tilts pitch/yaw by the thrust
// speed and the angle between camera and swim direction.
#include "common.h"

extern void func_80115870(s32, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(s32, f32);
extern f32 _bamovethrust_entrypoint_6(s32);
extern f32 func_8009BFCC(s32);
extern f32 func_800F1DCC(f32, f32);
extern f32 yaw_get(s32);
extern f32 func_80013728(f32);
extern f32 func_80115750(s32, f32);
extern f32 func_80112C3C(s32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);

void ncbakaztorp_entrypoint_0(s32 cam)
{
}

s32 ncbakaztorp_entrypoint_1(s32 cam)
{
    func_801120CC(cam, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 2);
    func_80115870(cam, 0);
}

// Follows the player, tilting pitch/yaw by the thrust speed and the camera-to-swim-direction angle.
void ncbakaztorp_entrypoint_2(s32 cam)
{
    f32 focus[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 new_rot[3];
    f32 dist;
    f32 angles[2];
    s32 player;
    f32 cam_rot[3];
    f32 pitch;
    f32 yaw_err;
    f32 thrust;
    f32 yaw_diff;
    f32 pitch_diff;
    f32 tilt;

    func_80112524(cam, focus);
    func_801107F0(cam, cam_pos);
    func_800EFB24(offset, cam_pos, focus);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    func_80113978(cam, 1, 1);
    dist = func_80115358(cam, dist);
    player = func_800F53D0(func_80110840(cam));
    func_80110818(cam, cam_rot);
    thrust = _bamovethrust_entrypoint_6(player);
    pitch = func_800F1DCC(180.0f, func_8009BFCC(player));
    yaw_diff = func_80013728(cam_rot[1] - yaw_get(player) - 180.0f);
    yaw_err = yaw_diff;
    if (yaw_diff > 90.0f)
        yaw_err = 180.0f - yaw_diff;
    else if (yaw_diff < -90.0f)
        yaw_err = -180.0f - yaw_diff;
    pitch_diff = func_80013728(cam_rot[0] - pitch);
    pitch = pitch_diff;
    if (pitch_diff > 90.0f)
        pitch = 180.0f - pitch_diff;
    else if (pitch_diff < -90.0f)
        pitch = -180.0f - pitch_diff;
    tilt = thrust / 225.0f * 0.4f;
    angles[0] -= tilt * pitch;
    angles[1] -= tilt * yaw_err;
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(cam_pos, focus, offset);
    if (func_80111FD4(cam, cam_pos))
        func_801138F4(cam);
    func_80110A68(cam, new_rot, focus);
    func_80110790(cam, new_rot);
}
