// Stone building on Hailfire Peaks (lava side) that an egg hit blows up with dust, sound and
// camera shake, setting a broken flag. A second callback tracks whether the player is nearby.
#include "ch/lavaexplodbuild.h"

extern int D_80800290_chlavaexplodbuild[];
extern s32 D_808002A4_chlavaexplodbuild[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern int D_808002E0_chlavaexplodbuild[];
void func_80800138_chlavaexplodbuild();

int func_80800000_chlavaexplodbuild(Actor *actor)
{
    f32 *pos = (f32 *) ((char *) actor + 4);
    *(f32 *) ((char *) pos + 68) = 45.0f;
    func_800EFA4C(pos, 0xC6115000, 0x42480000, 0xC3FA0000);
    func_80103014(actor);
}

// Stores in FLAG3_A24 whether the player is inside a cylinder around the building.
s32 func_80800048_chlavaexplodbuild(s32 actor)
{
    s32 inside = func_8010CB0C(actor + 4, 0x708, 0x7D0, -0x1F4);
    func_800DA3B8(0xA24, inside);
}

void func_80800084_chlavaexplodbuild(s32 arg0)
{
    func_800DA524(FLAG3_A24_UNK);
}

// Egg hit (message 0x40): explode the building and set the broken flag.
int func_808000A8_chlavaexplodbuild(s32 actor, s32 msg, s32 param_2)
{
    u8 *pos;
    if (msg == 0x40) {
        pos = actor + 4;
        _chexploder_entrypoint_3(actor, pos, 0xC);
        func_80800138_chlavaexplodbuild(actor);
        func_800C4AF0(pos, &D_80800290_chlavaexplodbuild);
        func_800E15CC(0, 0x42A00000, 0x3F733333);
        func_80018820(0, 0x40800000, 0x3EE66666);
        func_800DA544(0x49);
    } else {
        return 0;
    }
    return 1;
}

// Spawns a ring of 10 dust particles around the building.
void func_80800138_chlavaexplodbuild(actor) Actor *actor;
{
    s32 emitter;
    Vec3f velocity;
    Vec3f origin;
    s32 i;

    func_800EE7F8(origin.f, actor->position);
    emitter = func_800B53A4(10);
    for (i = 0; i != 10; i++) {
        func_800EEB9C(velocity.f, (f32) i * 36.0f, func_800DC178(300.0f, 400.0f));
        func_800EF04C(velocity.f, actor->position);
        velocity.f[1] += func_800DC178(400.0f, 600.0f);
        func_800BABB8(emitter, velocity.f, origin.f, 2.25f, D_808002A4_chlavaexplodbuild);
    }
}

int chlavaexplodbuild_entrypoint_0()
{
    return (int) &D_808002E0_chlavaexplodbuild;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
// TU-NOTE: the overlay .data is defined here in C because its tables point to functions of this
// file and IDO schedules them differently otherwise. Values are from the ROM.
int D_80800290_chlavaexplodbuild[5] ={0x130413, 0xA0099, 0x167D00, 0x11F40, 0x1F400000};
s32 D_808002A4_chlavaexplodbuild[15] = {0x1D09DD, 0x2B0200,  0x2990022, 0x1800200,   0x3800400,
                                        0x150000, 0x990027,  -0x630064, 0x640064,    0x190000,
                                        0x7002D,  0x15E01C2, 0x2080C0,  -0x3F3FFEE6, 0x0};
int D_808002E0_chlavaexplodbuild[20] = {0x15804A4,
                                        0x8F00001,
                                        0x0,
                                        (u32) func_80800048_chlavaexplodbuild,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x490000,
                                        0xC00,
                                        (u32) func_80800084_chlavaexplodbuild,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_80800000_chlavaexplodbuild,
                                        (u32) func_80107C2C,
                                        -0x7FFFDBFE,
                                        (u32) func_808000A8_chlavaexplodbuild,
                                        0x0,
                                        0x0,
                                        0x0};
