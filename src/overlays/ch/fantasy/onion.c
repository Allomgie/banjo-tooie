// Most likely the floating onion platforms of Cloud Cuckooland. They move along a spline, carry and
// turn the player, bob when landed on, change VI pacing while ridden and draw a z-probed shadow.
#include "common.h"

// Actor data slots: 3 move timer, 4 ground height, 5 rider, 6 bob timer, 7 spline index.
#define OD(n) (((f32 *) param_0->actorData)[n])
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern int func_800E8714(s32);
extern void func_800E8870(u8, f32);
extern void func_800E8830();
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800C7A68(s32, f32, f32 *);
extern s32 func_800EEDE8(f32 *, f32 *, f32);
extern f32 func_800DC0C0(void);
extern void func_80101EE4(Actor *, f32);
typedef struct {
    u32 pad : 12;
    u32 flag : 1;
    u32 pad2 : 19;
} BitTest12;
typedef struct {
    u32 pad : 27;
    u32 flag : 1;
    u32 pad2 : 4;
} BitTest27;
extern s32 _plsu_entrypoint_3(Unk80132ED0 *);
extern s32 func_80015184(void);
extern void func_80015178(s32);
extern s32 func_800F5C94(s32);
extern void func_800F79DC(s32, s32, Unk80132ED0 *);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, f32 *);
extern void func_800EF3DC(f32 *, f32 *);
extern s32 func_800D90A4(f32 *);
extern s32 func_800D7520(s32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_80102BAC(Actor *, f32, f32, f32);
extern f32 func_80013970(f32);
extern void func_800F5B38(s32, f32 *);
extern void func_800F832C(s32, f32 *);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern void func_800F8418(s32, f32 *);
extern u8 D_80800748_chfantasyonion[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800DE498(s32, f32 *, void *, f32, s32, s32);
extern int D_80800754_chfantasyonion[];

// Z-buffer probe below the platform; returns the ground height.
f32 func_80800000_chfantasyonion(Actor *actor)
{
    Vec3f probe_start;
    Vec3f ground;
    Vec3f unk_0;

    func_800EE7F8(ground.f, actor->position);
    func_800EE7F8(probe_start.f, actor->position);
    probe_start.f[1] += 250.0f;
    ground.f[1] -= 1400.0f;
    func_800BEF00(probe_start.f, ground.f, unk_0.f, 0);
    if (actor->actorData[0] == 0) {
        actor->actorData[0] = func_800E8714(1);
        func_800E8870((u8) actor->actorData[0], 300.0f);
    }
    func_800E8830((u8) actor->actorData[0], ground.f);
    return ground.f[1];
}

// Setup: looks up the spline and the movement direction.
void func_808000BC_chfantasyonion(Actor *actor)
{
    f32 spline_start[3];
    f32 spline_end[3];
    if (func_8010568C(actor, 0)) {
        func_80105634(actor);
        ((BitTest27 *) ((u8 *) actor + 0x74))->flag = 0;
        if (actor->rotation[1] > 99.0f) {
            actor->unk64_20 = 1;
        } else {
            actor->unk64_20 = 0;
        }
        *(f32 *) ((u8 *) actor + 0x24) =
            func_800F10B4(func_800F13C4(actor->rotation[1], 100.0f), 0.0f, 99.0f, 0.0f,
                          (f32) ((s32) actor->unk74_7 / 10));
        *(f32 *) ((u8 *) actor + 0x34) = _glsplinefind_entrypoint_3(actor->position);
        func_800C7A68(func_800D7520((s32) *(f32 *) ((u8 *) actor + 0x34)), 0.0f, spline_start);
        func_800C7A68(func_800D7520((s32) *(f32 *) ((u8 *) actor + 0x34)), 1.0f, spline_end);
        if (func_800EEDE8(spline_start, spline_end, 200.0f)) {
            ((BitTest12 *) ((u8 *) actor + 0x64))->flag = 1;
            func_800D8648((s32) *(f32 *) ((u8 *) actor + 0x34), spline_end);
        } else {
            ((BitTest12 *) ((u8 *) actor + 0x64))->flag = 0;
        }
        func_80101FDC(actor, 2);
    }
    *(f32 *) ((u8 *) actor + 0x28) = func_80800000_chfantasyonion(actor);
    func_80101EE4(actor, func_800DC0C0());
}

// Moves along the spline, carries the player, bobs when landed on.
void func_80800254_chfantasyonion(Actor *param_0)
{
    s32 rider;
    f32 rider_pos[3];
    f32 yaw;
    f32 spline_t;
    f32 prev_pos[3];
    s32 prev_dir;
    f32 bob_t;
    f32 rider_rot[3];

    rider = _plsu_entrypoint_3(param_0->unk0);
    if (rider != -1) {
        if (OD(5) == -1.0f && OD(6) == 0.0f) {
            param_0->unk79_4 = func_80015184();
            func_80015178(4);
            OD(6) = 3.0f;
        }
        if (func_800F5C94(rider) != 0xC) {
            func_800F79DC(rider, 4, param_0->unk0);
            rider = -1;
        }
        if (rider != -1) {
            func_800F5A00(func_800F54E4(), rider_pos);
            func_800EF3DC(rider_pos, param_0->position);
            yaw = param_0->rotation[1];
        }
    } else if (OD(5) != -1.0f) {
        func_80015178(param_0->unk79_4);
    }
    switch (param_0->unk70_10) {
        case 1:
            break;
        case 2:
            prev_dir = param_0->unk64_20;
            func_800EE7F8(prev_pos, param_0->position);
            if (func_800D90A4(&OD(3))) {
                if (!param_0->unk64_19) {
                    param_0->unk64_20 = !param_0->unk64_20;
                }
                OD(3) = (s32) param_0->unk74_7 / 10;
            }
            if (param_0->unk64_20) {
                spline_t = func_800F10B4(OD(3), 0.0f, (s32) param_0->unk74_7 / 10, 0.0f, 1.0f);
            } else {
                spline_t = func_800F10B4(OD(3), 0.0f, (s32) param_0->unk74_7 / 10, 1.0f, 0.0f);
            }
            func_800C7A68(func_800D7520(OD(7)), spline_t, param_0->position);
            if (prev_dir) {
                param_0->unk54 = func_800F1DF4(prev_pos, param_0->position);
            } else {
                param_0->unk54 = func_800F1DF4(param_0->position, prev_pos);
            }
            func_80102BAC(param_0, 0.05f, 0.01f, 4.0f);
    }
    if (!func_800D90A4(&OD(6))) {
        bob_t = func_800F10B4(OD(6), 3.0f, 0.0f, 1.0f, 0.0f);
        param_0->position[1] += func_80013970(bob_t * 2160.0f) * (20.0f * bob_t);
    }
    if (rider != -1) {
        yaw -= param_0->rotation[1];
        func_800F5B38(func_800F54E4(), rider_rot);
        rider_rot[1] -= yaw;
        func_800F832C(func_800F54E4(), rider_rot);
        func_800EF934(rider_pos, rider_pos, -yaw);
        func_800EF04C(rider_pos, param_0->position);
        func_800F8418(func_800F54E4(), rider_pos);
    }
    OD(5) = rider;
    OD(4) = func_80800000_chfantasyonion(param_0);
}

// Draws the ground shadow when the z-buffer probe says it is visible.
void func_80800624_chfantasyonion(Actor *actor, s32 gfx)
{
    f32 shadow_pos[3];
    f32 ground_y;
    if (func_800E88E4((u8) actor->actorData[0])) {
        ground_y = *(f32 *) &actor->actorData[4];
        func_800EFA4C(shadow_pos, actor->position[0], ground_y, actor->position[2]);
        func_800DF830(0);
        func_800DE498(gfx, shadow_pos, D_80800748_chfantasyonion,
                      func_800F10B4(actor->position[1] - ground_y, 1400.0f, 0.0f, 0.25f, 1.0f), 0,
                      func_800D674C(0x637));
    }
    func_80101870(actor, gfx);
}

// Cleanup: releases the z-buffer probe.
void func_808006E0_chfantasyonion(u8 *actor)
{
    s32 probe_id;

    probe_id = *(s32 *) ((char *) actor + 0x18);
    if (probe_id != 0) {
        func_800E87E0(probe_id & 0xFF, actor);
        *(s32 *) ((char *) actor + 0x18) = 0;
    }
}

int chfantasyonion_entrypoint_0()
{
    return (int) &D_80800754_chfantasyonion;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800730_chfantasyonion[6] = {0x0, 0x0, 0x3FA66666, 0x40A0001, 0x3FA66666, 0x40A0001};
u8 D_80800748_chfantasyonion[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
int D_80800754_chfantasyonion[19] = {0x158047F,
                                     0x89F0001,
                                     (u32) &D_80800730_chfantasyonion,
                                     (u32) func_80800254_chfantasyonion,
                                     (u32) func_80105834,
                                     (u32) func_80800624_chfantasyonion,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x800820,
                                     (u32) func_808006E0_chfantasyonion,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_808000BC_chfantasyonion,
                                     (u32) func_80107C2C,
                                     -0x7FDFBBFE,
                                     0x0,
                                     0x0,
                                     0x0};
