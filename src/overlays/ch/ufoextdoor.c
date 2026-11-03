#include "common.h"

typedef union {
    s32 word;
    Unk80132ED0 *marker;
} UfoMessage1438;
extern s32 D_80800100_chufoextdoor[];
extern s32 D_80800114_chufoextdoor[];
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern int D_80800148_chufoextdoor[];

s32 func_80800000_chufoextdoor(Actor *param_0, s32 param_1, UfoMessage1438 param_2)
{
    f32 *local_1;
    f32 local_0[3];

    if (param_1 == 0x3E) {
        if (param_2.marker->unk24 >> 22) {
            return 0;
        }
        if (func_800F52B8((u32) ((u16 *) param_2.marker)[0xD] >> 5, param_0->unk0) != 0x14) {
            return 0;
        }
        local_1 = param_0->position;
        func_800EE7F8(local_0, local_1);
        func_800EF1B8(local_0, param_0->rotation[1], -100.0f);
        _chexploder_entrypoint_3(param_0, local_0, 0xE);
        func_800BBCB8(local_1, local_0, 0.8f, 5, D_80800114_chufoextdoor);
        _subaddieaudioquick_entrypoint_2(param_0, local_1, D_80800100_chufoextdoor);
        func_800DA544(0x3AB);
        return 1;
    }
    return 0;
}

int *chufoextdoor_entrypoint_0()
{
    return &D_80800148_chufoextdoor;
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_80800100_chufoextdoor[5] = {0x1304A0, 0xA00E6, 0x166D60, 0x2001B, 0x0};
s32 D_80800114_chufoextdoor[13] = {0x1D09DD,    0x2B0300, 0x4000022, 0x1800200, 0x4800600,
                                   0x150000,    0x990019, 0x7,       0x2D0032,  0x4B0020,
                                   -0x7F373F40, 0xE0050,  0x640000};
int D_80800148_chufoextdoor[18] = {0x37C049A,
                                   0x93C0001,
                                   0x0,
                                   (u32) func_80102EC0,
                                   (u32) func_80105834,
                                   (u32) func_80101870,
                                   0x0,
                                   0x0,
                                   0x3AB0000,
                                   0x804,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FFFD400,
                                   (u32) func_80800000_chufoextdoor,
                                   0x0};
