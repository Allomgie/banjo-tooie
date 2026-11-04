#include "nc/ba/bee.h"

extern f32 func_800F5AE0(s32);
extern f32 func_80013728(f32);
extern f32 func_800136E4(f32);
extern void func_80115828(void *, f32, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_801112B0(void *);
extern void func_800EEBF0(f32 *, f32 *, f32);

int ncbabee_entrypoint_0(Actor *cam)
{
    extern void func_80115870(Actor * a0, f32 a1);
    int zero;
    func_801120CC(cam, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(cam, 0x40800000, 0x41000000);
    // Matching: extra temporary needed for the match.
    zero = 0;
    func_80115858(cam, zero);
    func_80115870(cam, 0);
    func_801124D0(cam, 1);
}

void ncbabee_entrypoint_1(s32 arg0)
{
}

void func_80800070_ncbabee(PlayerState *arg0, f32 *arg1)
{
    func_80112550(arg0, arg1);
}

// Bee chase camera: behind the player (yaw + 180), pitch from the player, with collision push-out.
void ncbabee_entrypoint_2(void *cam)
{
    f32 target[3];
    f32 cam_pos[3];
    f32 rotation[3];
    f32 distance;
    f32 angles[3];
    s32 unk_0;
    f32 offset[3];
    s32 player;
    f32 pitch;

    player = func_80110840();
    func_8011607C(cam, 1);
    func_801107F0(cam, cam_pos);
    func_80800070_ncbabee(cam, target);
    func_80115444(cam, &distance, &unk_0);
    pitch = func_80013728(func_800F5AE0(player));
    func_80115828(cam, pitch, pitch);
    func_800EFB24(offset, cam_pos, target);
    func_800F1A88(offset, angles);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_800136E4(func_801112B0(cam) + 180.0f);
    func_800EEBF0(offset, angles, distance);
    func_800EE780(cam_pos, target, offset);
    if (func_80111FD4(cam, cam_pos)) {
        func_801138F4(cam);
    }
    func_80112524(cam, target);
    func_80110A68(cam, rotation, target);
    func_80110790(cam, rotation);
}
