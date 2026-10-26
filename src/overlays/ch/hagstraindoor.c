#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
typedef union { s32 word; void *pointer; } HagsTrainDoorEvent;
extern int D_80800150_chhagstraindoor;

void func_80800000_chhagstraindoor(Actor *param_0)
{
    f32 local_0;

    local_0 = 0.0f;
    func_800EFD24(param_0->position);
    func_80103014(param_0);
    if (param_0->unk74_7 == 0x32) local_0 = 180.0f;
    if (_chdoormake_entrypoint_3(param_0, local_0, 0.0f, 600.0f, 0x21, 0x403)) {
        _chdoormake_entrypoint_6(param_0, 4.4f);
        _chdoormake_entrypoint_5(param_0, 3.0f);
        if (param_0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(param_0, 13);
            _chdoormake_entrypoint_9(param_0, 0, 1, 0x10);
        }
    }
}

s32 func_808000D4_chhagstraindoor(Actor *param_0, s32 param_1, HagsTrainDoorEvent param_2)
{
    if (param_1 == 0x95) {
        func_80103140(param_0, (u16)(param_0->unk74_7 == 0x32 ? 0x94F : 0x950), 0);
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
}

int chhagstraindoor_entrypoint_0()
{
    return (int)&D_80800150_chhagstraindoor;
}
