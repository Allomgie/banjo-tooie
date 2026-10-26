#include "common.h"

extern u8 unk4[];
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern void _idglowa_entrypoint_0();

void idglowa_entrypoint_0(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, f32 *param_4)
{
    Vtx *local_0;
    f32 local_1;

    local_1 = param_4[1];
    local_0 = param_1 + param_3;
    for (; param_1 < local_0; param_1++, param_2++) {
        param_2->v.cn[3] = (u32)((u32)param_1->v.cn[3] * local_1);
    }
}

f32 idglowa_entrypoint_1(Actor *param_0)
{
  return (*(f32 *)((char *)(param_0) + 0x4));
}

void func_808000E8_idglowa(u8 *param_0, s32 param_1) {
    if (param_1 == 2) {
        (*(f32 *)((s8 *)(param_0) + (0xC))) = 1.0f;
    }
    (*(s32 *)((s8 *)(param_0) + (0))) = param_1;
}

void idglowa_entrypoint_2(s32 arg0) 
{
}
void idglowa_entrypoint_3(u8 *param_0, s32 param_1, f32 param_2, f32 param_3) {
    *(s32 *)param_0 = 0;
    *(f32 *)(param_0 + 4) = 0.5f;
    *(f32 *)(param_0 + 8) = (param_1 + 1) * 0.01f;
    func_808000E8_idglowa(param_0, 1);
}

void idglowa_entrypoint_4(u8 *param_0, s32 param_1, s32 param_2)
{
    f32 local_0;

    local_0 = func_800D8FF8();
    if (*(s32 *)param_0 == 1) {
        *(f32 *)(param_0 + 4) += *(f32 *)(param_0 + 8) * local_0;
        if (*(f32 *)(param_0 + 4) >= 1.0f) {
            *(f32 *)(param_0 + 4) = 1.0f;
            *(f32 *)(param_0 + 8) = -*(f32 *)(param_0 + 8);
        } else if (*(f32 *)(param_0 + 4) < 0.0f) {
            *(f32 *)(param_0 + 4) = 0.0f;
            *(f32 *)(param_0 + 8) = -*(f32 *)(param_0 + 8);
            func_808000E8_idglowa(param_0, 2);
            return;
        }
    }
    if (*(s32 *)param_0 == 2 && func_800F1574((f32 *)(param_0 + 0xC), local_0)) {
        func_808000E8_idglowa(param_0, 1);
    }
    _glid_entrypoint_0(param_1, param_2, _idglowa_entrypoint_0, param_0);
}
