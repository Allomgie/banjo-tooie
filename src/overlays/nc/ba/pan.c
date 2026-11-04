// Most likely the panning camera mode: orbits with a stored yaw that only changes when
// collision or clamping moves the camera, otherwise it keeps the yaw and pans to follow.
#include "nc/ba/pan.h"

extern void func_801107F0();
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern s32 func_800F1EA4(f32 *, s32);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(Actor *, f32);
extern f32 func_80115750(Actor *, f32);
extern f32 func_80112C3C(Actor *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

s32 ncbapan_entrypoint_0()
{
    return 0x4;
}

void func_80800008_ncbapan(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

void func_80800028_ncbapan(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

// Stores the current yaw (camera to target) into the camera state at 0x38.
void func_80800048_ncbapan(u8 *cam)
{
    f32 pos[3];
    f32 offset[3];
    f32 target[3];
    func_801107F0(cam, pos);
    func_80800028_ncbapan(cam, target);
    func_800EFB24(offset, pos, target);
    func_800F1EA4(offset, *(s32 *) (cam + 0x38));
}

s32 ncbapan_entrypoint_1(s32 cam)
{
    func_801120CC(cam, 0x44FA0000, 0x457A0000, 0xC57A0000);
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 1);
    func_80115870(cam, 0x40A00000);
    func_80800048_ncbapan(cam);
}

void ncbapan_entrypoint_2(s32 arg0)
{
}

// The stored yaw only changes when collision or clamping moves the camera.
void ncbapan_entrypoint_3(Actor *cam)
{
    f32 target[3];
    f32 offset[3];
    f32 pos[3];
    f32 rot[3];
    f32 dist;
    f32 angles[2];
    f32 new_yaw;

    func_80800028_ncbapan(cam, target);
    func_801107F0(cam, pos);
    func_800EFB24(offset, pos, target);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    func_80113978(cam, 1, 0);
    dist = func_80115358(cam, dist);
    angles[0] = func_80115750(cam, angles[0]);
    new_yaw = func_80112C3C(cam, angles[1]);
    if (new_yaw != angles[1])
        **(f32 **) ((u8 *) cam + 0x38) = new_yaw;
    angles[1] = **(f32 **) ((u8 *) cam + 0x38);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(pos, target, offset);
    if (func_80111FD4(cam, pos)) {
        if ((func_801138A0(cam) || func_80115580(cam, target)) && func_801138F4(cam))
            func_80110F44(cam);
        func_80800048_ncbapan(cam);
    }
    func_80800008_ncbapan(cam, target);
    func_80110A68(cam, rot, target);
    func_80110790(cam, rot);
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/ba/pan.data.s) is defined in C; values come from the ROM.
