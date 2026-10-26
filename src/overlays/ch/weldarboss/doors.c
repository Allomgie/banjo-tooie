#include "common.h"

extern void *D_80800270_chweldarbossdoors;
extern int D_808002B8_chweldarbossdoors;
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } WeldS2;
extern void func_80103140(WeldS2 *, s32, s32);
extern s32 _chdoor_entrypoint_1(WeldS2 *, s32, s32);
typedef struct { u8 pad[0x72]; u16 f72:6; u16 rest:10; } WeldS;
extern void func_800DF744(s32, s32, WeldS *);
extern void func_80101870(WeldS *, s32);

void *chweldarbossdoors_entrypoint_0()
{
    return &D_80800270_chweldarbossdoors;
}

int chweldarbossdoors_entrypoint_1()
{
    return &D_808002B8_chweldarbossdoors;
}

void func_80800018_chweldarbossdoors(Actor *param_0)
{
    f32 local_0;
    s32 local_1;

    local_0 = param_0->rotation[1];
    local_1 = 0;
    if (param_0->unk74_7 == 0x32) {
        local_1 = 1;
        local_0 += 180.0f;
    }
    _subaddiefade_entrypoint_14(param_0);
    if (_chdoormake_entrypoint_3(param_0, local_0 + 90.0f, 0.0f, 750.0f, 0x102, -1)) {
        _chdoormake_entrypoint_5(param_0, 8.5f);
        _chdoormake_entrypoint_6(param_0, 1.0f);
        if (local_1) _chdoormake_entrypoint_8(param_0, 8);
    }
}

s32 func_808000E0_chweldarbossdoors(WeldS2 *param_0, s32 param_1, s32 param_2) {
    if (param_1 == 0x95) {
        func_80103140(param_0, (u16)(param_0->f76 + 0x837), 0);
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

void func_80800140_chweldarbossdoors(WeldS *param_0, s32 param_1) {
    func_800DF744(1, (param_0->f72 == 1) ? 0 : 1, param_0);
    func_80101870(param_0, param_1);
}

void func_80800194_chweldarbossdoors(Actor *param_0)
{
    s32 local_0;

    local_0 = func_800DA298(0x174) != 0;
    if (local_0) {
        local_0 = func_800DA298(0x18C) == 0;
        if (local_0) local_0 = func_800F64A4(func_800F54E4(), 1) != 0;
    }
    if (local_0 || _glcutDll_entrypoint_20()) func_80101FDC(param_0, 1);
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 350.0f, 2, -1)) {
        _chdoormake_entrypoint_5(param_0, 3.0f);
        _chdoormake_entrypoint_6(param_0, 0.15f);
        _chdoormake_entrypoint_8(param_0, 4);
    }
}
