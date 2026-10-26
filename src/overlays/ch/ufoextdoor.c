#include "common.h"

typedef union { s32 word; Unk80132ED0 *marker; } UfoMessage1438;
extern s32 D_80800100_chufoextdoor[];
extern s32 D_80800114_chufoextdoor[];
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern int D_80800148_chufoextdoor;

s32 func_80800000_chufoextdoor(Actor *param_0, s32 param_1, UfoMessage1438 param_2)
{
    f32 *local_1;
    f32 local_0[3];

    if (param_1 == 0x3E) {
        if (param_2.marker->unk24 >> 22) {
            return 0;
        }
        if (func_800F52B8((u32)((u16 *)param_2.marker)[0xD] >> 5, param_0->unk0) != 0x14) {
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
