// Swimming camera mode: follows the player underwater with waypoint support, tilting pitch/yaw
// by swim speed and direction.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_80115870(s32, f32);
extern f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern f32 func_80113978(void *, s32, s32);
extern f32 func_80115358(void *, f32);
extern f32 _baswim_entrypoint_14(PlayerState *);
extern f32 func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_8009BFCC(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_80013728(f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801155E8(void *);
extern PlayerState *func_800F53D0(s32);

s32 ncbaswim_entrypoint_0()
{
    return 0x4;
}

void ncbaswim_entrypoint_1(s32 cam)
{
}

s32 ncbaswim_entrypoint_2(s32 cam)
{
    func_801124D0(cam, 1);
    func_80115858(cam, 2);
    func_80115870(cam, 0);
}

// Follows the player underwater, tilting pitch/yaw by swim speed and direction.
void ncbaswim_entrypoint_3(u8 *cam)
{
    Vec3f focus;
    Vec3f offset;
    Vec3f cam_pos;
    Vec3f new_rot;
    f32 dist;
    f32 waypoint_dist;
    f32 total_dist;
    f32 angles[2];
    PlayerState *player;
    Vec3f cam_rot;
    f32 player_pitch;
    f32 yaw_diff;
    f32 speed;
    f32 pitch_diff;
    f32 tilt;

    func_80112524(cam, focus.f);
    func_801107F0(cam, cam_pos.f);
    if (**(s32 **) (cam + 0x5C)) {
        waypoint_dist = _ncbawaypoint_entrypoint_3(cam, focus.f, cam_pos.f);
    } else {
        waypoint_dist = 0.0f;
    }
    func_800EFB24(offset.f, cam_pos.f, focus.f);
    total_dist = func_800EEF94(offset.f) + waypoint_dist;
    func_800F1A88(offset.f, angles);
    angles[0] += func_80113978(cam, 1, 1);
    dist = func_80115358(cam, total_dist);
    player = func_800F53D0(func_80110840(cam));
    func_80110818(cam, cam_rot.f);
    speed = _baswim_entrypoint_14(player);
    player_pitch = func_800F1DCC(180.0f, func_8009BFCC(player));
    // Matching: empty block steers IDO's register allocation.
    if (cam) {
    }
    yaw_diff = func_80013728(cam_rot.pos.y - yaw_get(player) - 180.0f);
    // Matching: empty block steers IDO's register allocation.
    if (player_pitch) {
    }
    if (yaw_diff > 90.0f) {
        yaw_diff = 180.0f - yaw_diff;
    } else if (yaw_diff < -90.0f) {
        yaw_diff = -180.0f - yaw_diff;
    }
    pitch_diff = func_80013728(cam_rot.pos.x - player_pitch);
    if (pitch_diff > 90.0f) {
        pitch_diff = 180.0f - pitch_diff;
    } else if (pitch_diff < -90.0f) {
        pitch_diff = -180.0f - pitch_diff;
    }
    tilt = (speed / 900.0f) * 0.2f;
    angles[0] -= tilt * pitch_diff;
    angles[1] -= tilt * yaw_diff;
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    dist -= waypoint_dist;
    func_800EEBF0(offset.f, angles, dist);
    func_800EE780(cam_pos.f, focus.f, offset.f);
    if (func_80111CC8(cam, cam_pos.f)) {
        if (func_801138A0(cam)) {
            if (func_801138F4(cam)) {
                func_80110F44(cam);
            }
        } else if (func_80115580(cam, focus.f) && func_801155E8(cam) < total_dist) {
            func_801138F4(cam);
        }
    }
    func_80112524(cam, focus.f);
    func_80110A68(cam, new_rot.f, focus.f);
    func_80110790(cam, new_rot.f);
}
