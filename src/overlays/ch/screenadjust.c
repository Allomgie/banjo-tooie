// Screen-adjust option: lets the player shift the picture with the stick, stores the offset in
// the global settings and draws two nested sets of corner brackets as guides.
#include "common.h"

extern int D_80800430_chscreenadjust[];
extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);

// Moves the screen offset with the stick.
void func_80800000_chscreenadjust(Actor *actor)
{
    f32 stick[2];
    f32 frame_time;

    frame_time = func_800D8FF8();
    func_80016068(0, stick);
    if (mlAbsF(stick[0]) > 0.05f) {
        *(f32 *) &actor->actorData[0] += stick[0] * frame_time * 64.0f;
    }
    if (*(f32 *) &actor->actorData[0] < -32.0f)
        *(f32 *) &actor->actorData[0] = -32.0f;
    else if (*(f32 *) &actor->actorData[0] > 32.0f)
        *(f32 *) &actor->actorData[0] = 32.0f;
    if (mlAbsF(stick[1]) > 0.05f) {
        *(f32 *) &actor->actorData[1] += stick[1] * frame_time * -64.0f;
    }
    if (*(f32 *) &actor->actorData[1] < -40.0f)
        *(f32 *) &actor->actorData[1] = -40.0f;
    else if (*(f32 *) &actor->actorData[1] > 24.0f)
        *(f32 *) &actor->actorData[1] = 24.0f;
    _glglobalsettings_entrypoint_6((s32) *(f32 *) &actor->actorData[0],
                                   (s32) *(f32 *) &actor->actorData[1]);
}

s32 func_8080016C_chscreenadjust(u8 *actor, s32 param_1, s32 param_2)
{
    s32 offset_x;
    s32 offset_y;

    if (param_1 == 0x95) {
        _glglobalsettings_entrypoint_5(&offset_x, &offset_y, actor);
        *(f32 *) ((s8 *) actor + 0x18) = (f32) offset_x;
        *(f32 *) ((s8 *) actor + 0x1C) = (f32) offset_y;
        return 1;
    }
    return 0;
}

// Draws four corner brackets around the rectangle.
void func_808001E0_chscreenadjust(s32 gfx, s32 left, s32 top, s32 right, s32 bottom,
                                  s32 arm_len, s32 thickness, s32 red, s32 green, s32 blue)
{
    func_800BC474(gfx, left, top, arm_len, thickness, red, green, blue);
    func_800BC474(gfx, left, top, thickness, arm_len, red, green, blue);
    func_800BC474(gfx, right - arm_len, top, arm_len, thickness, red, green, blue);
    func_800BC474(gfx, right - thickness, top, thickness, arm_len, red, green, blue);
    func_800BC474(gfx, left, bottom - thickness, arm_len, thickness, red, green, blue);
    func_800BC474(gfx, left, bottom - arm_len, thickness, arm_len, red, green, blue);
    func_800BC474(gfx, right - arm_len, bottom - thickness, arm_len, thickness, red, green,
                  blue);
    func_800BC474(gfx, right - thickness, bottom - arm_len, thickness, arm_len, red, green,
                  blue);
}

// Draws the outer and inner guide brackets.
void func_8080037C_chscreenadjust(s32 actor, s32 gfx)
{
    func_808001E0_chscreenadjust(gfx, 0, 0, 0x130, 0xE4, 0x40, 0xA, 0xFF, 0, 0);
    func_808001E0_chscreenadjust(gfx, 0x20, 0x20, 0x110, 0xC4, 0x20, 5, 0xFF, 0, 0);
}

int chscreenadjust_entrypoint_0()
{
    return (int) &D_80800430_chscreenadjust;
}

// TU-NOTE: the data table is defined in this file; IDO schedules some functions differently otherwise.
extern void func_80102EC0();
extern void func_80107C2C();
int D_80800430_chscreenadjust[20] = {0x15801E8,
                                     -0xFFFF,
                                     0x0,
                                     (u32) func_80800000_chscreenadjust,
                                     (u32) func_80102EC0,
                                     (u32) func_8080037C_chscreenadjust,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x400004,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80107C2C,
                                     -0x7FFFDFFE,
                                     (u32) func_8080016C_chscreenadjust,
                                     0x0,
                                     0x0,
                                     0x0};
