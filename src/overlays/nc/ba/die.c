// Death camera mode: orbit looking at the player, distance capped at 220, pitch derived from a
// height value that every dying or timeout state sets.
#include "nc/ba/die.h"

extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(Actor *, f32);
extern f32 func_80013AAC(f32);
extern void func_80115828(Actor *, f32, f32);
extern f32 func_80115750(Actor *, f32);
extern f32 func_80112C3C(Actor *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
int ncbadie_entrypoint_3(s32 param_0, f32 param_1);

s32 ncbadie_entrypoint_0()
{
    return 0x4;
}

void func_80800008_ncbadie(u8 *camera, u8 *target)
{
    func_80112524(camera, target);
    *(f32 *) ((char *) target + 4) = *(f32 *) ((char *) *(f32 **) ((char *) camera + 0x10) + 0) +
                                      *(f32 *) ((char *) target + 4);
}

void func_80800048_ncbadie(PlayerState *camera, f32 *target)
{
    func_80112524(camera, target);
}

s32 ncbadie_entrypoint_1(Actor *camera)
{
    ncbadie_entrypoint_3(camera, 3e+01f);
    func_80111B8C(camera, 0x3FB33333, 0x41600000);
    func_80115858(camera, 0);
    func_80115870(camera, 0x40A00000);
    func_801124D0(camera, 4);
}

void ncbadie_entrypoint_2(s32 arg0)
{
}

// Stores the height used to derive the camera pitch.
ncbadie_entrypoint_3(s32 camera, f32 height)
{
    *(f32 *) (*(s32 *) (camera + 16) + 0) = height;
}

// Per-frame update: orbit around the player, distance capped at 220.
void ncbadie_entrypoint_4(Actor *camera)
{
    f32 target[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 rotation[3];
    f32 distance;
    f32 angles[2];
    f32 pitch;

    func_80800048_ncbadie(camera, target);
    func_801107F0(camera, cam_pos);
    func_800EFB24(offset, cam_pos, target);
    distance = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    distance = func_80115358(camera, distance);
    if (distance > 220.0f)
        distance = 220.0f;
    pitch = func_80013AAC((120.0f - **(f32 **) ((u8 *) camera + 0x10)) / 220.0f);
    func_80115828(camera, pitch, pitch);
    angles[0] = func_80115750(camera, angles[0]);
    angles[1] = func_80112C3C(camera, angles[1]);
    func_800EEBF0(offset, angles, distance);
    func_800EE780(cam_pos, target, offset);
    if (func_80111CC8(camera, cam_pos) && func_801138A0(camera) && func_801138F4(camera))
        func_80110F44(camera);
    func_80800008_ncbadie(camera, target);
    func_80110A68(camera, rotation, target);
    func_80110790(camera, rotation);
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
