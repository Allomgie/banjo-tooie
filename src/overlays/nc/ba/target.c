#include "nc/ba/target.h"

extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern void func_80112D08(void *, s32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);

s32 ncbatarget_entrypoint_0()
{
    return 0x10;
}

// Moves the focus point toward the target point by the blend factor.
void func_80800008_ncbatarget(PlayerState *cam, s32 focus)
{
    f32 delta[3];

    func_80112524(cam, focus);
    func_800EFB24(delta, *(u8 **) ((s8 *) cam + 0x58), focus);
    func_800EF174(focus, delta, *(s32 *) ((s8 *) *(u8 **) ((s8 *) cam + 0x58) + 0xC));
}

void func_80800058_ncbatarget(PlayerState *cam, f32 *focus)
{
    func_80112524(cam, focus);
}

s32 ncbatarget_entrypoint_1(s32 cam)
{
    func_801120CC(cam, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 1);
    func_80115870(cam, 0x40A00000);
    func_800EFD24(*(u8 **) (cam + 0x58));
    *(f32 *) ((char *) *(u8 **) (cam + 0x58) + 0xC) = 0.5f;
    func_8011607C(cam, 1);
}

void ncbatarget_entrypoint_2(s32 cam)
{
}

// Frames the player together with the target point and locks the yaw onto the target direction.
void ncbatarget_entrypoint_3(u8 *cam)
{
    f32 look_at[3];
    f32 focus[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 cam_rot[3];
    f32 dist;
    f32 angles[2];
    f32 target_yaw;
    func_8011607C(cam, 1);
    func_80800058_ncbatarget(cam, focus);
    func_80800008_ncbatarget(cam, look_at);
    func_801107F0(cam, cam_pos);
    func_800EFB24(offset, cam_pos, focus);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    dist = func_80115358(cam, dist);
    angles[0] = func_80115750(cam, angles[0]);
    func_800F1E6C(*(f32 **) (cam + 0x58), focus, &target_yaw);
    func_80112D08(cam, 5, target_yaw, target_yaw);
    angles[1] = func_80112C3C(cam, angles[1]);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(cam_pos, focus, offset);
    if (func_80111FD4(cam, cam_pos) && func_801138A0(cam) && func_801138F4(cam))
        func_80110F44(cam);
    func_80110A68(cam, cam_rot, look_at);
    func_80110790(cam, cam_rot);
}

// Sets the blend factor (+0xC of the target state).
int ncbatarget_entrypoint_4(s32 cam, f32 blend)
{
    // Matching: extra temporary needed for the match.
    int cam_copy;
    cam_copy = cam;
    *(f32 *) (*(s32 *) ((char *) cam_copy + 88) + 12) = blend;
}

void ncbatarget_entrypoint_5(Actor *cam)
{
    func_800EE7F8(*(s32 *) ((s8 *) cam + 0x58));
}
