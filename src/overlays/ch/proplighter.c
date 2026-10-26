#include "common.h"

extern int D_808001A0_chproplighter;
extern void func_80103014();
extern void func_80108944();
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);
typedef struct { u8 pad_0[8]; u32 pad_1 : 26; u32 local_0 : 1; u32 local_1 : 1; u32 pad_2 : 4; } PropLightFlags1001;

int chproplighter_entrypoint_0()
{
    return (int)&D_808001A0_chproplighter;
}

void func_8080000C_chproplighter(Actor *param_0)
{
    s32 local_0;
    u8 *local_1;
    s32 local_2[3];
    u8 *local_3;

    func_800EE904(local_2, param_0->position);
    if (_gccubesearch_entrypoint_16(local_2, &local_0, &local_1, 2, 500)) {
        local_3 = local_1;
        ((PropLightFlags1001 *)local_3)->local_0 = 1;
        ((PropLightFlags1001 *)local_3)->local_1 = 0;
        func_800EE88C(param_0->position, local_3 + 4);
        *(f32 *)((u8 *)param_0 + 0x48) = func_800136E4(2.0f * (f32)(u32)local_3[2]);
        *(f32 *)((u8 *)param_0 + 0x44) = func_800136E4(2.0f * (f32)(u32)local_3[3]);
        func_80103140(param_0, _gsproplookup_entrypoint_0(local_3) & 0xFFFF, 0);
        func_80102FDC(param_0, (f32)(u32)local_3[0xA] * 0.01f);
        func_80103014(param_0);
        func_80108944(param_0, param_0);
        if (!func_80105010(param_0)) func_80104E78(param_0);
        func_8010A63C(param_0);
    } else func_800FFAB0(param_0);
}

s32 func_8080017C_chproplighter(s32 param_0){
    s32 local_0;
    local_0 = param_0;
}
