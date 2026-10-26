#include "common.h"

extern int D_808001F8_chfireimp;
extern void func_8010A3E8(void *param_0, float param_1);
extern void *_sucoasterfly_entrypoint_1(void *param_0, int param_1);
extern void *_sucoasterfly_entrypoint_5(void *param_0);
extern f32 func_800DC178(f32, f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s16 D_80800240_chfireimp[];

int chfireimp_entrypoint_0()
{
    return (int)&D_808001F8_chfireimp;
}

void func_8080000C_chfireimp(Actor *param_0)
{
    void *local_0;
    local_0 = _sucoasterfly_entrypoint_1(param_0, 4);
    if (local_0 != 0)
    {
        local_0 = _sucoasterfly_entrypoint_5(param_0);
        *(float *)local_0 = 3.4f;
    }
    func_8010A3E8(param_0, 0.65f);
}

void func_8080005C_chfireimp(Actor *param_0)
{
    f32 *local_0;
    s32 local_1;
    f32 local_2[3];

    local_0 = _sucoasterfly_entrypoint_5(param_0);
    local_1 = 1;
    _sucoasterfly_entrypoint_3(param_0);
    switch (param_0->unk70_10) {
        case 10: case 11: case 12: case 13: case 14: case 15: case 16:
            local_1 = 0;
            break;
    }
    if (local_1 && func_800D90A4(local_0)) {
        func_8010D640(local_2);
        if (func_800EFFB4(param_0->position, 1800.0f, local_2)) {
            *local_0 = func_800DC178(2.4f, 3.4f);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800240_chfireimp);
        }
    }
}
