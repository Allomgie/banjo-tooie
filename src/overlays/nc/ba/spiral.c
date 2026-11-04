// Spiral camera mode (camera-database volume type 7): keeps the yaw within +-10 degrees of the
// direction from a centre prop to the player, for spiral paths around towers.
#include "nc/ba/spiral.h"

extern f32 func_800EEF94(f32 *);
extern void func_800EEBF0(f32 *, f32 *, f32);
extern f32 func_80115358(void *, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_80112D08(void *, s32, f32, f32);

s32 ncbaspiral_entrypoint_0()
{
    return 0x10;
}

void func_80800008_ncbaspiral(PlayerState *cam, f32 *focus)
{
    func_80112524(cam, focus);
}

void func_80800028_ncbaspiral(PlayerState *cam, f32 *focus)
{
    func_80112524(cam, focus);
}

void ncbaspiral_entrypoint_1(u8 *cam)
{
    extern void func_80111B8C(u8 *, f32, f32);
    extern void func_80115870(u8 *, f32);

    func_80111B8C(cam, 4.0f, 8.0f);
    func_801124D0(cam, 1);
    func_80115858(cam, 1);
    func_80115870(cam, 5.0f);
    func_800EFD24(*(u8 **) (cam + 0x48) + 4);
    **(s32 **) (cam + 0x48) = -1;
}

void ncbaspiral_entrypoint_2(s32 cam)
{
}

// Keeps the yaw within +-10 deg of the centre-prop-to-player direction.
void ncbaspiral_entrypoint_3(void *cam)
{
    f32 focus[3];
    f32 offset[3];
    f32 cam_pos[3];
    f32 cam_rot[3];
    f32 dist;
    f32 angles[2];
    f32 center_yaw;

    func_80800028_ncbaspiral(cam, focus);
    func_801107F0(cam, cam_pos);
    func_800EFB24(offset, cam_pos, focus);
    dist = func_800EEF94(offset);
    func_800F1A88(offset, angles);
    dist = func_80115358(cam, dist);
    angles[0] = func_80115750(cam, angles[0]);
    func_800F1E6C(*(u8 **) ((u8 *) cam + 0x48) + 4, focus, &center_yaw);
    func_80112D08(cam, 5, center_yaw - 10.0f, center_yaw + 10.0f);
    angles[1] = func_80112C3C(cam, angles[1]);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(cam_pos, focus, offset);
    if (func_80111CC8(cam, cam_pos) &&
        (func_801138A0(cam) || func_80115580(cam, focus)) && func_801138F4(cam)) {
        func_80110F44(cam);
    }
    func_80800008_ncbaspiral(cam, focus);
    func_80110A68(cam, cam_rot, focus);
    func_80110790(cam, cam_rot);
}

void ncbaspiral_entrypoint_4(u8 *cam)
{
    func_800EE7F8(*(u8 **) ((s8 *) cam + 0x48) + 4);
    **(s32 **) ((s8 *) cam + 0x48) = -1;
}

// Finds the centre prop (cube search marker 0x1D1 + n) when the volume id changes.
void ncbaspiral_entrypoint_5(u8 *cam, s32 id)
{
    s32 n;
    f32 pos[4];

    if (id != **(s32 **) ((s8 *) cam + 0x48)) {
        func_800A5800(id);
        _cadbfunc_entrypoint_24(&n);
        func_801107B0(cam, pos);
        _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(n + 0x1D1, pos),
                                  *(u8 **) ((s8 *) cam + 0x48) + 4);
        **(s32 **) ((s8 *) cam + 0x48) = id;
    }
}
