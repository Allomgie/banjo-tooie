#include "common.h"

extern int D_80800430_chscreenadjust;
extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);

void func_80800000_chscreenadjust(Actor *param_0)
{
    f32 local_0[2];
    f32 local_1;

    local_1 = func_800D8FF8();
    func_80016068(0, local_0);
    if (mlAbsF(local_0[0]) > 0.05f) {
        *(f32 *)&param_0->actorData[0] += local_0[0] * local_1 * 64.0f;
    }
    if (*(f32 *)&param_0->actorData[0] < -32.0f) *(f32 *)&param_0->actorData[0] = -32.0f;
    else if (*(f32 *)&param_0->actorData[0] > 32.0f) *(f32 *)&param_0->actorData[0] = 32.0f;
    if (mlAbsF(local_0[1]) > 0.05f) {
        *(f32 *)&param_0->actorData[1] += local_0[1] * local_1 * -64.0f;
    }
    if (*(f32 *)&param_0->actorData[1] < -40.0f) *(f32 *)&param_0->actorData[1] = -40.0f;
    else if (*(f32 *)&param_0->actorData[1] > 24.0f) *(f32 *)&param_0->actorData[1] = 24.0f;
    _glglobalsettings_entrypoint_6((s32)*(f32 *)&param_0->actorData[0], (s32)*(f32 *)&param_0->actorData[1]);
}

s32 func_8080016C_chscreenadjust(u8 *param_0, s32 param_1, s32 param_2)
{
    s32 sp1C;
    s32 sp18;

    if (param_1 == 0x95)
    {
        _glglobalsettings_entrypoint_5(&sp1C, &sp18, param_0);
        (*(f32 *)((s8 *)param_0 + 0x18)) = (f32)sp1C;
        (*(f32 *)((s8 *)param_0 + 0x1C)) = (f32)sp18;
        return 1;
    }
    return 0;
}

void func_808001E0_chscreenadjust(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9)
{
    func_800BC474(param_0, param_1, param_2, param_5, param_6, param_7, param_8, param_9);
    func_800BC474(param_0, param_1, param_2, param_6, param_5, param_7, param_8, param_9);
    func_800BC474(param_0, param_3 - param_5, param_2, param_5, param_6, param_7, param_8, param_9);
    func_800BC474(param_0, param_3 - param_6, param_2, param_6, param_5, param_7, param_8, param_9);
    func_800BC474(param_0, param_1, param_4 - param_6, param_5, param_6, param_7, param_8, param_9);
    func_800BC474(param_0, param_1, param_4 - param_5, param_6, param_5, param_7, param_8, param_9);
    func_800BC474(param_0, param_3 - param_5, param_4 - param_6, param_5, param_6, param_7, param_8, param_9);
    func_800BC474(param_0, param_3 - param_6, param_4 - param_5, param_6, param_5, param_7, param_8, param_9);
}

void func_8080037C_chscreenadjust(s32 param_0, s32 param_1) {
    func_808001E0_chscreenadjust(param_1, 0, 0, 0x130, 0xE4, 0x40, 0xA, 0xFF, 0, 0);
    func_808001E0_chscreenadjust(param_1, 0x20, 0x20, 0x110, 0xC4, 0x20, 5, 0xFF, 0, 0);
}

int chscreenadjust_entrypoint_0()
{
  return (int)&D_80800430_chscreenadjust;
}
