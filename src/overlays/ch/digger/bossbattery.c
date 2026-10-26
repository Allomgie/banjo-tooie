#include "common.h"

extern int D_808002F0_chdiggerbossbattery;
extern void func_800FFAB0();
extern f32 func_800DC178(f32, f32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EFD24(f32 *);
extern u8 D_80800338_chdiggerbossbattery[];
extern s32 func_800DC298(f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);

int chdiggerbossbattery_entrypoint_0()
{
    return (int)&D_808002F0_chdiggerbossbattery;
}

void func_8080000C_chdiggerbossbattery(Actor *param_0)
{
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    func_800EFD24(param_0->position);
    func_80102FDC(param_0, 0x3E800000);
    param_0->unk58 = func_800DC178(1.5f, 3.0f);
    if (func_800DA298(param_0->unk74_7 + 0xA1D)) {
        func_800FFAB0(param_0);
    }
}

void func_80800090_chdiggerbossbattery(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1;

    _subaddieaudioloop_entrypoint_4(param_0, param_0->actorData, 1, D_80800338_chdiggerbossbattery);
    if (func_800D9078(&param_0->unk58)) {
        func_800EE7F8(local_0, param_0->actorData);
        if (func_800DC298(0.5f)) local_1 = 1.0f;
        else local_1 = -1.0f;
        func_800EF1B8(local_0, local_1 * 90.0f, 80.0f);
        local_0[1] += 300.0f;
        _chelectricfence_entrypoint_1(param_0, local_0);
        param_0->unk58 = func_800DC178(1.5f, 3.0f);
    }
}

s32 func_80800170_chdiggerbossbattery(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    Actor *local_1;
    Actor *local_2;
    switch (param_1) {
    case 0x40:
        func_800EE7F8(local_0, (f32 *)param_0->actorData);
        func_800EF1B8(local_0, param_0->rotation[1], -400.0f);
        local_0[1] -= 80.0f;
        func_800DA544(param_0->unk74_7 + 0xA1D);
        func_8010A624(param_0);
        _chexploder_entrypoint_3(param_0, local_0, 12);
        func_800FC660(14);
        local_1 = (Actor *)_subaddiefind_entrypoint_1(param_0, param_0->unk6C_9, -1, 0);
        local_2 = local_1;
        if (!local_1) break;
        func_8010A570(local_2);
        break;
    case 0x90:
        local_1 = func_80106790((Unk80132ED0 *)func_80101080());
        _chexploder_entrypoint_9(local_1, 1, 2);
        _chexploder_entrypoint_15(local_1, 2, 1.0f);
        _chexploder_entrypoint_13(local_1, 1);
        break;
    case 0x95:
        func_80103140(param_0, ((u16 *)((u8 *)&D_808002F0_chdiggerbossbattery - 8))[param_0->unk74_7], 0);
        break;
    case 0x1F: func_801015D0(param_0); func_800DF744(1, 1); break;
    default: return 0;
    }
    return 1;
}
