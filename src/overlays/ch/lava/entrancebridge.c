// Bridge to the Hailfire Peaks entrance: on message 0x60 from its switch it slides out with
// sound, camera shake and rumble. Starts extended when FLAG_391 is set.
#include "common.h"

extern int D_80800230_chlavaentrancebridge[];
extern s32 D_80800220_chlavaentrancebridge[];
extern s32 D_80800228_chlavaentrancebridge[];
extern f32 func_800D8FF8(void);
extern void func_800EDCEC(s32, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);

void func_80800000_chlavaentrancebridge(void *actor)
{
    *(float *) ((char *) actor + 0x58) = -2750.0f;
}

s32 func_80800010_chlavaentrancebridge(Actor *actor, s32 msg, s32 param_2)
{
    switch (msg) {
        case 0x95:
            if (func_800DA298(0x391))
                func_80101FDC(actor, 4);
            break;
        case 0x60:
            func_80101FDC(actor, 2);
            break;
        default:
            return 0;
    }
    return 1;
}

// Slides the bridge parts along the offset; starts at -2750 and ends extended at 0.
void func_8080008C_chlavaentrancebridge(Actor *actor)
{
    s32 part_190;
    s32 part_191;
    f32 offset;

    part_190 = _idworld_entrypoint_3(0x190);
    part_191 = _idworld_entrypoint_3(0x191);
    offset = -2750.0f;
    switch (actor->unk70_10) {
        case 2:
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            &D_80800220_chlavaentrancebridge);
            *(f32 *) ((u8 *) actor + 0x58) += 450.0f * func_800D8FF8();
            if (*(f32 *) ((u8 *) actor + 0x58) >= 0.0f) {
                *(f32 *) ((u8 *) actor + 0x58) = 0.0f;
                func_80101FDC(actor, 4);
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 &D_80800228_chlavaentrancebridge);
                func_800E15CC(0, 20.0f, 0.85f);
                func_80018820(0, 1.0f, 0.4f);
            }
            offset = *(f32 *) ((u8 *) actor + 0x58);
            break;
        case 4:
            offset = 0.0f;
            break;
    }
    if (part_190)
        func_800EDCEC(part_190, offset);
    if (part_191)
        func_800EDCEC(part_191, offset >= -1350.0f ? offset : -1350.0f);
}

int *chlavaentrancebridge_entrypoint_0()
{
    return &D_80800230_chlavaentrancebridge;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
s32 D_80800220_chlavaentrancebridge[2] = {0x1304AD, 0x20000};
s32 D_80800228_chlavaentrancebridge[2] = {0x1304CC, 0x20000};
int D_80800230_chlavaentrancebridge[20] = {0x158038E,
                                           0x1,
                                           0x0,
                                           (u32) func_8080008C_chlavaentrancebridge,
                                           (u32) func_80105834,
                                           (u32) func_8010A730,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x4,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_80800000_chlavaentrancebridge,
                                           (u32) func_80107C2C,
                                           -0x7FFFDBFE,
                                           (u32) func_80800010_chlavaentrancebridge,
                                           0x0,
                                           0x0,
                                           0x0};
