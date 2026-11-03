#include "common.h"

extern s32 func_80110840(void);
extern f32 func_800F5CC0(s32);
extern f32 func_80013728(f32);
extern f32 func_800F5CEC(s32);
extern void func_800F5D70(s32, f32 *);
extern f32 func_800EEFFC(f32 *);
extern s32 func_800F5B0C(s32);

s32 func_801125B0()
{
    return 0x10;
}

void func_801125B8(Actor *camera)
{
    // Matching: the comma expression is needed for the match.
    **(f32 **) ((u8 *) camera + 0x4C) = (0, 0.0f);
    *(*(f32 **) ((u8 *) camera + 0x4C) + 1) = 0.0f;
    *(*(f32 **) ((u8 *) camera + 0x4C) + 2) = 0.0f;
}

// Sets the roll factor.
int func_801125D8(s32 camera, f32 factor)
{
    s32 offset;
    // Matching: the negated offset is needed for the match.
    offset = -0x4C;
    *(f32 *) (*(s32 *) (camera - offset) + 8) = factor;
}

f32 func_801125E8(void *camera)
{
    return *(f32 *) ((char *) *(void **) ((char *) camera + 0x4C) + 0xC);
}

int func_801125F4()
{
    s32 player;
    s32 unk_0;
    s32 unk_1;

    player = func_800F53D0();
    unk_0 = func_8009D2E4(player);
    unk_1 = func_8009BAF4(player);
    return unk_0 == 1 && unk_1 == 2;
}

void func_80112648(u8 *camera)
{
    f32 angle;
    f32 velocity[3];
    s32 player;
    u8 *slot;
    f32 *state;

    player = func_80110840();
    // Heading + 90 deg, folded to +-90.
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x4C) + 0) =
        func_80013728(func_800F5CC0(player) + 90.0f);
    slot = *(u8 **) ((s8 *) camera + 0x4C);
    angle = *(f32 *) ((s8 *) slot + 0);
    if (angle > 90.0f) {
        *(f32 *) ((s8 *) slot + 0) = (f32) (180.0f - angle);
    } else if (angle < -90.0f) {
        *(f32 *) ((s8 *) slot + 0) = (f32) (-180.0f - angle);
    }
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x4C) + 4) = func_800F5CEC(player);
    func_800F5D70(player, velocity);
    // Tilt is zeroed when the player is not moving or not in the required state.
    if ((func_800EEFFC(velocity) < 0.01f) || (func_800F5B0C(player) != 0) ||
        (func_801125F4(player) == 0)) {
        *(f32 *) ((s8 *) *(u8 **) ((s8 *) camera + 0x4C) + 4) = 0.0f;
    }
    state = *(f32 **) (camera + 0x4C);
    state[3] = state[2] * (state[1] * -state[0]);
}

f32 func_80112788(u8 *camera)
{
    return *(f32 *) (*(u32 *) (camera + 0x4c) + 8);
}
