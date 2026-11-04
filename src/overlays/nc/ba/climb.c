#include "nc/ba/climb.h"

void func_80115870(s32, f32);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern f32 func_801112B0(void *);
extern f32 func_800F1DCC(f32, f32);
extern void func_80115828(void *, f32, f32);
extern void func_80112D08(void *, s32, f32, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

s32 ncbaclimb_entrypoint_0()
{
    return 0x4;
}

void func_80800008_ncbaclimb(PlayerState *camera, f32 *target)
{
    func_80112524(camera, target);
}

void func_80800028_ncbaclimb(PlayerState *camera, f32 *target)
{
    func_80112524(camera, target);
}

int ncbaclimb_entrypoint_1(Actor *camera)
{
    func_80111B8C(camera, 0x40800000, 0x41000000);
    func_801124D0(camera, 2);
    func_80115858(camera, 0);
    func_80115870(camera, 0);
}

void ncbaclimb_entrypoint_2(s32 arg0)
{
}

// Per-frame update: orbit around the target with limited pitch.
void ncbaclimb_entrypoint_3(void *camera)
{
    f32 target[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 rotation[3];
    f32 orbit[3];
    f32 player_yaw;
    s32 is_type_2;

    is_type_2 = func_8009861C(func_800F53D0(func_80110840(camera))) == 2;
    if (!is_type_2)
        func_80113978(camera, 1, 0);
    func_80800028_ncbaclimb(camera, target);
    func_801107F0(camera, cam_pos);
    func_800EFB24(offset, cam_pos, target);
    orbit[2] = func_800EEF94(offset);
    func_800F1A88(offset, orbit);
    orbit[2] = func_80115358(camera, orbit[2]);
    orbit[0] = func_80115750(camera, orbit[0]);
    orbit[1] = func_80112C3C(camera, orbit[1]);
    func_80115828(camera, -60.0f, 60.0f);
    orbit[0] = func_80115750(camera, orbit[0]);
    if (is_type_2) {
        player_yaw = func_800F1DCC(func_801112B0(camera), 180.0f);
        func_80112D08(camera, 5, player_yaw - 45.0f, player_yaw + 45.0f);
        orbit[1] = func_80112C3C(camera, orbit[1]);
    }
    func_800EEBF0(offset, orbit, orbit[2]);
    func_800EE780(cam_pos, target, offset);
    if (func_80111CC8(camera, cam_pos) &&
        (func_801138A0(camera) || func_80115580(camera, target))) {
        if (func_801138F4(camera))
            func_80110F44(camera);
    }
    func_80800008_ncbaclimb(camera, target);
    func_80110A68(camera, rotation, target);
    func_80110790(camera, rotation);
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
