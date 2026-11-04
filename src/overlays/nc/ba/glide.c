// Gliding camera mode: the same chase-behind-player logic as the fly camera,
// with its own setup values.
#include "nc/ba/glide.h"

extern void func_80111590(void *, f32, f32, f32, f32);
extern void func_80111B8C(void *, f32, f32);
extern void func_80115858(void *, s32);
extern void func_80115870(void *, f32);
extern void func_801124D0(void *, s32);
extern f32 func_800F5AE0(s32);
extern f32 func_80013728(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_80115828(void *, f32, f32);
extern f32 func_80115750(void *, f32);
extern f32 func_801112B0(void *);
extern f32 func_800136E4(f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void ncbaglide_entrypoint_0(void *cam)
{
    func_80111590(cam, 10.0f, 20.0f, 120.0f, 200.0f);
    func_80111B8C(cam, 4.0f, 8.0f);
    func_80115858(cam, 0);
    func_80115870(cam, 0.0f);
    func_801124D0(cam, 1);
}

void ncbaglide_entrypoint_1(s32 arg0)
{
}

void func_8080007C_ncbaglide(PlayerState *arg0, f32 *arg1)
{
    func_80112550(arg0, arg1);
}

// Chase camera behind the player; the pitch follows the player pitch and is compressed downwards.
void ncbaglide_entrypoint_2(void *cam)
{
    f32 target[3];
    f32 pos[3];
    f32 rot[3];
    f32 dist;
    f32 angles[3];
    f32 unk_0;
    f32 offset[3];
    s32 player;
    f32 pitch;

    player = func_80110840(cam);
    func_8011607C(cam, 1);
    func_801107F0(cam, pos);
    func_8080007C_ncbaglide(cam, target);
    func_80115444(cam, &dist, &unk_0);
    pitch = func_80013728(func_800F5AE0(player));
    if (pitch < 0.0f) {
        pitch = func_800F10B4(pitch, -30.0f, -60.0f, 0.0f, 84.0f);
        func_80115828(cam, pitch, pitch);
    } else {
        func_80115828(cam, pitch, pitch);
    }
    func_800EFB24(offset, pos, target);
    func_800F1A88(offset, angles);
    angles[0] = func_80115750(cam, angles[0]);
    angles[1] = func_800136E4(func_801112B0(cam) + 180.0f);
    func_800EEBF0(offset, angles, dist);
    func_800EE780(pos, target, offset);
    if (func_80111CC8(cam, pos))
        func_801138F4(cam);
    func_80112524(cam, target);
    func_80110A68(cam, rot, target);
    func_80110790(cam, rot);
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/nc/ba/glide.data.s) is defined in C; values come from the ROM.
