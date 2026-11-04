#include "common.h"

extern void func_80115870(s32, f32);
extern void *func_80110840(void *);
extern void *func_800F53D0(void *);
extern f32 func_800F5E7C(void *);
extern f32 func_800F5F7C(void *);
extern f32 func_800EEF94(f32 *);
extern f32 func_80115358(void *, f32);
extern f32 _bamovethrust_entrypoint_6(void *);
extern f32 func_8009BFCC(void *);
extern f32 func_800F1DCC(f32, f32);
extern f32 yaw_get(void *);
extern f32 func_80013728(f32);
extern f32 func_80115750(void *, f32);
extern f32 func_80112C3C(void *, f32);
extern void func_800EEBF0(f32 *, f32 *, f32);

void ncbasub_entrypoint_0(s32 camera)
{
}

void ncbasub_entrypoint_1(s32 camera)
{
    func_801124D0(camera, 1);
    func_80115858(camera, 2);
    func_80115870(camera, 0);
}

// Per-frame update: tilts pitch/yaw by thrust and swim direction; no pitch tilt near the surface.
void ncbasub_entrypoint_2(void *camera)
{
    Vec3f unk_0;
    Vec3f unk_1;
    Vec3f unk_2;
    Vec3f unk_3;
    Vec3f unk_4;
    void *unk_5;
    s32 near_surface;
    void *player;
    Vec3f unk_6;
    f32 unk_9;
    f32 unk_8;
    f32 thrust;
    f32 unk_7;
    f32 tilt_scale;

    unk_5 = func_80110840(camera);
    near_surface = func_800F5E7C(unk_5) - func_800F5F7C(unk_5) < 200.0f;
    func_80112524(camera, unk_0.f);
    func_801107F0(camera, unk_2.f);
    func_800EFB24(unk_1.f, unk_2.f, unk_0.f);
    unk_4.pos.z = func_800EEF94(unk_1.f);
    func_800F1A88(unk_1.f, unk_4.f);
    func_80113978(camera, 1, 1);
    unk_4.pos.z = func_80115358(camera, unk_4.pos.z);
    player = func_800F53D0(func_80110840(camera));
    func_80110818(camera, unk_6.f);
    thrust = _bamovethrust_entrypoint_6(player);
    unk_9 = func_800F1DCC(180.0f, func_8009BFCC(player));
    unk_8 = func_80013728(unk_6.pos.y - yaw_get(player) - 180.0f);
    if (unk_8 > 90.0f) {
        unk_8 = 180.0f - unk_8;
    } else if (unk_8 < -90.0f) {
        unk_8 = -180.0f - unk_8;
    }
    unk_7 = unk_6.pos.x - unk_9;
    unk_9 = func_80013728(unk_7);
    if (unk_9 > 90.0f) {
        unk_9 = 180.0f - unk_9;
    } else if (unk_9 < -90.0f) {
        unk_9 = -180.0f - unk_9;
    }
    tilt_scale = (thrust / 90.0f) * 0.3f;
    unk_4.pos.x -= tilt_scale * unk_9;
    if (!near_surface) {
        unk_4.pos.y -= tilt_scale * unk_8;
    }
    unk_4.pos.x = func_80115750(camera, unk_4.pos.x);
    unk_4.pos.y = func_80112C3C(camera, unk_4.pos.y);
    func_800EEBF0(unk_1.f, unk_4.f, unk_4.pos.z);
    func_800EE780(unk_2.f, unk_0.f, unk_1.f);
    if (func_80111CC8(camera, unk_2.f) &&
        (func_801138A0(camera) || func_80115580(camera, unk_0.f))) {
        func_801138F4(camera);
    }
    func_80110A68(camera, unk_3.f, unk_0.f);
    func_80110790(camera, unk_3.f);
    func_80115858(camera, near_surface ? 1 : 2);
}
