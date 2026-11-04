// The rotating planets of the Witchyworld Star Spinner: they spin only while the ride is powered,
// and are tinted grey and culled outside the Star Spinner map.

#include "common.h"

extern void *D_80800260_chstarspinnerplanet;
extern int D_808002A8_chstarspinnerplanet[];
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 func_800136E4(f32);
extern u8 D_808002F0_chstarspinnerplanet[];
extern void func_80108A30(s32, void *, f32, s32);

int chstarspinnerplanet_entrypoint_0()
{
    return &D_80800260_chstarspinnerplanet;
}

int chstarspinnerplanet_entrypoint_1()
{
    return (int) &D_808002A8_chstarspinnerplanet;
}

// Spins on two axes (with hum loop) only while the ride is powered (map flag 0).
void func_80800018_chstarspinnerplanet(Actor *actor)
{
    f32 dt;

    if (func_800DA298(0)) {
        dt = func_800D8FF8();
        *(f32 *) &actor->actorData[5] =
            func_800F15F8(*(f32 *) &actor->actorData[5], 20.0f, 0.5f);
        *(f32 *) &actor->actorData[4] =
            func_800F15F8(*(f32 *) &actor->actorData[4], 40.0f, 0.8f);
        actor->rotation[1] =
            func_800136E4(actor->rotation[1] + *(f32 *) &actor->actorData[5] * dt);
        actor->rotation[0] =
            func_800136E4(actor->rotation[0] + *(f32 *) &actor->actorData[4] * dt);
    }
    _subaddieaudioloop_entrypoint_4(actor, actor->position, func_800DA298(0),
                                    D_808002F0_chstarspinnerplanet);
}

// Init: grey tint, culled outside the Star Spinner map.
int func_808000E4_chstarspinnerplanet(s32 actor)
{
    if (func_800DA298(0xEA) != 0 || _glcutDll_entrypoint_20() != 0) {
        func_800DA544(0);
    }
    func_80108A30(0x335, actor + 4, 0, 0x32);
    if (func_800EA05C() != 0xE6) {
        func_8010A624(actor);
    }
    _subaddiefade_entrypoint_12(actor, 0xA0, 0xA0, 0xA0);
}

// Spins around Y in the opposite direction while the ride is powered.
void func_80800170_chstarspinnerplanet(Actor *actor)
{
    f32 dt;
    if (func_800DA298(0)) {
        dt = func_800D8FF8();
        *(f32 *) &actor->actorData[5] =
            func_800F15F8(*(f32 *) &actor->actorData[5], 25.0f, 0.6f);
        actor->rotation[1] =
            func_800136E4(actor->rotation[1] - *(f32 *) &actor->actorData[5] * dt);
    }
}

void func_808001E8_chstarspinnerplanet(s32 actor)
{
    if ((func_800DA298(0xEA) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800DA544(0);
    }
    if (func_800EA05C() != 0xE6) {
        func_8010A624(actor);
    }
    _subaddiefade_entrypoint_12(actor, 0xA0, 0xA0, 0xA0);
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800260_chstarspinnerplanet = (void *) 0x01AF0334;
static u32 D_80800260_chstarspinnerplanet_rest[17] = {0x7770001,
                                                      0x0,
                                                      (u32) func_80800018_chstarspinnerplanet,
                                                      (u32) func_80105834,
                                                      (u32) func_80101870,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      0x30804C00,
                                                      0x0,
                                                      0x0,
                                                      0x0,
                                                      (u32) func_808000E4_chstarspinnerplanet,
                                                      (u32) func_80107C2C,
                                                      0x80080402,
                                                      0x0,
                                                      0x0};
int D_808002A8_chstarspinnerplanet[18] = {0x1B60335,
                                          0x7780001,
                                          0x0,
                                          (u32) func_80800170_chstarspinnerplanet,
                                          (u32) func_80105834,
                                          (u32) func_80101870,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x30804C00,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_808001E8_chstarspinnerplanet,
                                          (u32) func_80107C2C,
                                          -0x7FF7FBFE,
                                          0x0,
                                          0x0};
u8 D_808002F0_chstarspinnerplanet[32] = {
    0x0, 0x13, 0x4, 0xCB, 0x0, 0x16, 0x75, 0x30, 0x0, 0x1, 0x5, 0xDC, 0xF, 0xA0, 0x0, 0xA,
    0x0, 0x66, 0x0, 0x0,  0x0, 0x0,  0x0,  0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
