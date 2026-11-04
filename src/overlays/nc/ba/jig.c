// Probably the camera for the jiggy celebration dance: orbit around the player at a fixed
// maximum distance and pitch.
#include "nc/ba/jig.h"

typedef struct {
    u8 pad_0[0x2C];
    f32 *limits;
} JigCameraState;
extern void func_80111B8C(void *, f32, f32);
extern void func_80115870(void *, f32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEF94(f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_80115358(void *, f32);
extern void func_80115828(void *, f32, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);

s32 ncbajig_entrypoint_0()
{
    return 0xC;
}

void func_80800008_ncbajig(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

void func_80800028_ncbajig(PlayerState *arg0, f32 *arg1)
{
    func_80112524(arg0, arg1);
}

// limits[0] is the maximum distance (290), limits[1] the pitch (12).
void ncbajig_entrypoint_1(JigCameraState *cam)
{
    func_80111B8C(cam, 1.8f, 14.0f);
    cam->limits[0] = 290.0f;
    cam->limits[1] = 12.0f;
    func_80115858(cam, 0);
    func_80115870(cam, 5.0f);
    func_801124D0(cam, 5);
}

void ncbajig_entrypoint_2(s32 arg0)
{
}

void ncbajig_entrypoint_3(u8 *cam)
{
    f32 target[3];
    f32 offset[3];
    f32 pos[3];
    f32 rot[3];
    f32 dist;
    f32 angles[2];
    func_80800028_ncbajig(cam, target);
    func_801107F0(cam, pos);
    func_800EFB24(offset, pos, target);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    dist = func_80115358(cam, dist);
    if (((f32 *) *(u8 **) (cam + 0x2C))[0] < dist)
        dist = ((f32 *) *(u8 **) (cam + 0x2C))[0];
    func_80115828(cam, ((f32 *) *(u8 **) (cam + 0x2C))[1],
                  ((f32 *) *(u8 **) (cam + 0x2C))[1]);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_80112C3C(cam, angles[1]);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(pos, target, offset);
    if (func_80111CC8(cam, pos) && func_801138A0(cam) && func_801138F4(cam))
        func_80110F44(cam);
    func_80800008_ncbajig(cam, target);
    func_80110A68(cam, rot, target);
    func_80110790(cam, rot);
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/ba/jig.data.s) is defined in C; values come from the ROM.
