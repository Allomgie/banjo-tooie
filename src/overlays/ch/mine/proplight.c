#include "common.h"

extern int D_80800240_chmineproplight;
extern void func_800FFAB0();
extern void func_80103014();
extern void func_80108944();
extern void func_8010A828();
extern f32 func_800136E4(f32);
extern void func_80102FDC(Actor *, f32);
typedef struct { u8 pad_0[8]; u32 pad_1 : 26; u32 local_0 : 1; u32 local_1 : 1; u32 pad_2 : 4; } MinePropLightFlags1081;

int chmineproplight_entrypoint_0()
{
    return (int)&D_80800240_chmineproplight;
}

void func_8080000C_chmineproplight(Actor *param_0)
{
    s32 local_0;
    u8 *local_1;
    s32 local_2[3];
    u8 *local_4;

    func_800EE904(local_2, param_0->position);
    if (_gccubesearch_entrypoint_16(local_2, &local_0, &local_1, 2, 500)) {
        local_4 = local_1;
        ((MinePropLightFlags1081 *)local_4)->local_0 = 1;
        ((MinePropLightFlags1081 *)local_4)->local_1 = 0;
        func_800EE88C(param_0->position, local_4 + 4);
        param_0->rotation[1] = func_800136E4(2.0f * (f32)(u32)local_4[2]);
        param_0->rotation[0] = func_800136E4(2.0f * (f32)(u32)local_4[3]);
        func_80103140(param_0, _gsproplookup_entrypoint_0(local_4) & 0xFFFF, 0);
        func_80102FDC(param_0, (f32)(u32)local_4[10] * 0.01f);
        func_80103014(param_0);
        func_80108944(param_0, param_0);
        func_8010A828(param_0, 5);
    } else {
        func_800FFAB0(param_0);
    }
}

void func_80800168_chmineproplight(u8 *param_0, s32 param_1) {
    s32 local_2;

    local_2 = func_800EB854();
    if (local_2 != 0) {
        if (local_2 == 2) {
            func_800DF830(1);
            func_800DE498(param_1, param_0 + 4, param_0 + 0x44, *(s32 **)(param_0 + 0x38), 0, func_800D674C(0x695));
            func_800DF7E8(func_800D731C(0x696) & 0xFF);
            func_800DF830(1);
            func_800DE498(param_1, param_0 + 4, param_0 + 0x44, *(s32 **)(param_0 + 0x38), 0, func_800D674C(0x696));
        }
    } else {
        func_80101870(param_0, param_1);
    }
}

void func_80800228_chmineproplight(s32 arg0) 
{
}
