#include "nc/ba/ledge.h"

extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801112B0(void *);
extern f32 func_800F1DCC(f32, f32);
extern void func_80112D08(void *, s32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void func_80800000_ncbaledge(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

void func_80800020_ncbaledge(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

int ncbaledge_entrypoint_0(Actor *cam)
{
    func_80111B8C(cam, 0x40800000, 0x41000000);
    func_801124D0(cam, 1);
    func_80115858(cam, 1);
    func_80115870(cam, 0x40A00000);
}

void ncbaledge_entrypoint_1(s32 arg0)
{
}

// Orbit camera with the yaw limited to +-45 degrees around a center yaw from the player's facing.
void ncbaledge_entrypoint_2(void *cam)
{
    f32 target[3];
    f32 offset[3];
    f32 pos[3];
    f32 rot[3];
    f32 dist;
    f32 angles[2];
    f32 center_yaw;

    func_80800020_ncbaledge(cam, target);
    func_801107F0(cam, pos);
    func_800EFB24(offset, pos, target);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    dist = func_80115358(cam, dist);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    center_yaw = func_800F1DCC(func_801112B0(cam), 180.0f);
    func_80112D08(cam, 5, center_yaw - 45.0f, center_yaw + 45.0f);
    angles[1] = func_80112C3C(cam, angles[1]);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(pos, target, offset);
    if (func_80111CC8(cam, pos) &&
        (func_801138A0(cam) || func_80115580(cam, target)) && func_801138F4(cam)) {
        func_80110F44(cam);
    }
    func_80800000_ncbaledge(cam, target);
    func_80110A68(cam, rot, target);
    func_80110790(cam, rot);
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/ba/ledge.data.s) is defined in C; values come from the ROM.
