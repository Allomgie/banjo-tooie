#include "common.h"

extern void func_800C8E54(s32, f32, f32);
extern int D_808000F0_chjrinnlight[];

int func_80800000_chjrinnlight(Actor *param_0)
{
    s32 *local_0 = (s32 *) ((char *) param_0 + 0x58);
    if (*local_0 != 0) {
        func_800C8B84(*(s32 *) ((char *) param_0 + 0x58));
        *(s32 *) ((char *) param_0 + 88) = 0;
    }
}

s32 func_80800038_chjrinnlight(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x95:
            if (func_800DA298(0x3A9)) {
                *(s32 *) &param_0->unk58 = func_800C8A98();
                func_800C8CB8(*(s32 *) &param_0->unk58, param_0->position);
                func_800C8E54(*(s32 *) &param_0->unk58, 500.0f, 700.0f);
                func_800C8FB0(*(s32 *) &param_0->unk58, 0xFF, 0xFF, 0xFF);
                func_800C8F64(*(s32 *) &param_0->unk58, 0xB);
                return 1;
            }
            *(s32 *) &param_0->unk58 = 0;
            break;
        default:
            return 0;
    }
    return 1;
}

int chjrinnlight_entrypoint_0()
{
    return (int) &D_808000F0_chjrinnlight;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_808000F0_chjrinnlight[20] = {0x15804BD,
                                   0x1,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_8010A730,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x4,
                                   (u32) func_80800000_chjrinnlight,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FFFD9FE,
                                   (u32) func_80800038_chjrinnlight,
                                   0x0,
                                   0x0,
                                   0x0};
