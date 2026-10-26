#include "common.h"

extern void *D_808002A0_chfloater;
extern void *func_80100094(Actor *, s32);
extern f32 _mlwave_entrypoint_5(void *, f32, f32);
extern f32 func_800136E4(f32);
typedef struct { u8 pad_0[8]; u32 pad_1 : 26; u32 local_0 : 1; u32 local_1 : 1; u32 pad_2 : 4; } FloaterNodeFlags;
extern void func_80102FDC(Actor *, f32);
extern void _mlwave_entrypoint_0(void *, f32, f32);
extern void _mlwave_entrypoint_2(void *, f32, f32);

int chfloater_entrypoint_0()
{
  return &D_808002A0_chfloater;
}

void func_8080000C_chfloater(Actor *param_0)
{
    u8 *local_0;

    local_0 = func_80100094(param_0, 0);
    _mlwave_entrypoint_1(local_0);
    _mlwave_entrypoint_1(local_0 + 0x1C);
    _mlwave_entrypoint_1(local_0 + 0x38);
    param_0->rotation[2] = func_800136E4(((f32 *)param_0->actorData)[4] + _mlwave_entrypoint_5(local_0 + 0x1C, -7.5f, 7.5f));
    param_0->rotation[0] = func_800136E4(((f32 *)param_0->actorData)[5] + _mlwave_entrypoint_5(local_0, -3.0f, 3.0f));
    param_0->position[1] = ((f32 *)param_0->actorData)[6] + _mlwave_entrypoint_5(local_0 + 0x38, -20.0f, 20.0f);
}

void func_808000C0_chfloater(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    u8 *local_2;
    s32 local_3[3];
    u8 *local_5;
    local_0 = func_80100094(param_0, 0);
    func_800EE904(local_3, param_0->position);
    if (_gccubesearch_entrypoint_16(local_3, &local_1, &local_2, 2, 500)) {
        local_5 = local_2;
        ((FloaterNodeFlags *)local_5)->local_0 = 1;
        ((FloaterNodeFlags *)local_5)->local_1 = 0;
        func_800EE88C(param_0->position, local_5 + 4);
        param_0->rotation[1] = func_800136E4(2.0f * (f32)(u32)local_5[2]);
        param_0->rotation[0] = func_800136E4(2.0f * (f32)(u32)local_5[3]);
        ((f32 *)param_0->actorData)[5] = param_0->rotation[0];
        ((f32 *)param_0->actorData)[4] = 0.0f;
        ((f32 *)param_0->actorData)[6] = param_0->position[1];
        func_80102FDC(param_0, (f32)(u32)local_5[0xA] * 0.01f);
        func_80103140(param_0, _gsproplookup_entrypoint_0(local_5) & 0xFFFF, 0);
        _mlwave_entrypoint_0(local_0, 100.0f, 30.0f);
        local_5 = local_0 + 0x1C;
        _mlwave_entrypoint_0(local_5, 100.0f, 20.0f);
        _mlwave_entrypoint_0(local_0 + 0x38, 100.0f, 20.0f);
        _mlwave_entrypoint_2(local_0, 0.0f, 5.0f);
        _mlwave_entrypoint_2(local_5, 5.0f, 10.0f);
        _mlwave_entrypoint_2(local_0 + 0x38, 3.0f, 7.0f);
        func_8010A800(param_0, 2);
        func_80104E78(param_0);
    }
}
