#include "common.h"

extern s32 D_80800270_chcolldoors;
extern f32 func_800D8FF8(void);
extern void *D_80800280_chcolldoors;

void func_80800000_chcolldoors(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk74_7) {
    case 0x33:
        local_0 = func_800DA298(0x577);
        break;
    case 0x34:
        local_0 = func_800DA298(0x368);
        break;
    case 0x35:
        local_0 = func_800DA298(0x369);
        break;
    }
    if (local_0) {
        param_0->unk70_10 = 3;
        param_0->position[1] += 250.0f;
    }
}

void func_808000B8_chcolldoors(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk70_10) {
    case 1:
        local_0 = 0;
        switch (param_0->unk74_7) {
        case 0x33:
            local_0 = func_800DA298(0x577);
            param_0->unk58 = 1.5f;
            _gcfrontend_entrypoint_9(0x6E);
            break;
        case 0x34:
            local_0 = func_800DA298(0x368);
            param_0->unk58 = 1.5f;
            _gcfrontend_entrypoint_9(0x6F);
            break;
        case 0x35:
            local_0 = func_800DA298(0x369);
            param_0->unk58 = 1.5f;
            _gcfrontend_entrypoint_9(0x70);
            break;
        }
        if (local_0) {
            param_0->unk70_10 = 2;
            *(f32 *)&param_0->actorData[1] = param_0->position[1] + 250.0f;
        }
        break;
    case 2:
        if (param_0->unk58 <= 0.0f) {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_80800270_chcolldoors);
            if (param_0->position[1] < *(f32 *)&param_0->actorData[1]) {
                param_0->position[1] += 150.0f * func_800D8FF8();
            } else {
                param_0->unk70_10 = 3;
            }
        } else {
            param_0->unk58 -= func_800D8FF8();
        }
        break;
    }
}

int chcolldoors_entrypoint_0()
{
  return &D_80800280_chcolldoors;
}
