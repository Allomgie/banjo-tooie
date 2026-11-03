#include "common.h"
#include "playerstate.h"

extern f32 D_80800100_bashake[][3];
extern f32 D_8080013C_bashake[][2];
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800E1610(s32, f32, f32, f32 *);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);

// Camera shake at the player's position from presets, plus the matching rumble.
void bashake_entrypoint_0(PlayerState *player, s32 strength, s32 duration)
{
    f32 pos[3];
    func_8009C128(player, pos);
    func_800E1610(0, D_80800100_bashake[strength][0], D_8080013C_bashake[duration][0], pos);
    _bamotor_entrypoint_1(player, D_80800100_bashake[strength][1], D_80800100_bashake[strength][2],
                          D_8080013C_bashake[duration][1]);
}

// Same shake without rumble.
void bashake_entrypoint_1(PlayerState *player, s32 strength, s32 duration)
{
    f32 pos[3];

    func_8009C128(player, pos);
    func_800E1610(0, D_80800100_bashake[strength][0], D_8080013C_bashake[duration][0], pos);
}

// TU-NOTE: the overlay .data is defined here in C; values are taken from the ROM.
f32 D_80800100_bashake[5][3] = {5.0f,  0.4f,  0.3f, 15.0f, 0.65f,  0.35f, 25.0f, 0.85f,
                                0.45f, 45.0f, 1.0f, 0.7f,  6e+01f, 1.0f,  0.8f};
f32 D_8080013C_bashake[6][2] = {0.5f,  0.25f, 0.6f,  0.4f, 0.7f, 0.6f,
                                0.85f, 0.9f,  0.95f, 1.2f, 0.0f, 0.0f};
