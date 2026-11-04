// Possibly the camera mode used while the player is being sucked or pulled: pitch limited to
// -60..60 and, while a player flag is set, yaw held within +-45 degrees of a stored angle.
#include "nc/ba/suck.h"

extern void func_80115870(s32, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(s32, f32);
extern f32 func_80115750(s32, f32);
extern f32 func_80112C3C(s32, f32);
extern void func_80115828(s32, f32, f32);
extern void func_80112D08(s32, s32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void func_80800000_ncbasuck(PlayerState *cam, f32 *focus)
{
    func_80112524(cam, focus);
}

void func_80800020_ncbasuck(PlayerState *cam, f32 *focus)
{
    func_80112524(cam, focus);
}

int ncbasuck_entrypoint_0(Actor *cam)
{
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 0);
    func_80115870(cam, 0);
}

void ncbasuck_entrypoint_1(s32 cam)
{
}

// Flag (+0xC4) of the player model component.
// Matching: the `| 0` is needed for the match.
int func_80800094_ncbasuck()
{
    func_80092BC4(func_800F53D0(func_80110840()) | 0);
}

// Angle (+0xC8) of the player model component.
// Matching: the `| 0` is needed for the match.
f32 func_808000C4_ncbasuck()
{
    func_80092BD0(func_800F53D0(func_80110840()) | 0);
}

// Pitch is limited to -60..60; while the flag is set, yaw is held within +-45 deg of the stored angle.
void ncbasuck_entrypoint_2(s32 cam)
{
    f32 focus[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 cam_rot[3];
    f32 dist;
    f32 angles[2];
    f32 stored_yaw;
    int locked;
    locked = func_80800094_ncbasuck(cam);
    func_80800020_ncbasuck(cam, focus);
    func_801107F0(cam, cam_pos);
    func_800EFB24(offset, cam_pos, focus);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    if (!locked)
        func_80113978(cam, 1, 0);
    dist = func_80115358(cam, dist);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    func_80115828(cam, -60.0f, 60.0f);
    angles[0] = func_80115750(cam, angles[0]);
    if (locked) {
        stored_yaw = func_808000C4_ncbasuck(cam);
        func_80112D08(cam, 5, stored_yaw - 45.0f, stored_yaw + 45.0f);
        angles[1] = func_80112C3C(cam, angles[1]);
    }
    func_800EEBF0(offset, angles, dist);
    func_800EE780(cam_pos, focus, offset);
    if (func_80111CC8(cam, cam_pos) &&
        (func_801138A0(cam) || func_80115580(cam, focus)) && func_801138F4(cam))
        func_80110F44(cam);
    func_80800000_ncbasuck(cam, focus);
    func_80110A68(cam, cam_rot, focus);
    func_80110790(cam, cam_rot);
}
