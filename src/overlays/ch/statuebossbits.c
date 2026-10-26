#include "common.h"

extern int D_808006F0_chstatuebossbits;
extern int D_80800738_chstatuebossbits;
extern int D_80800780_chstatuebossbits;
extern s32 D_808007C8_chstatuebossbits[];
extern int D_80800810_chstatuebossbits;
extern int D_8080084C_chstatuebossbits;
extern void func_800EE7F8(f32 *, f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);
typedef struct { u8 pad_0[0x54]; s32 local_0; } StatueBossSelector;
extern void *func_80100094();
extern u8 D_8080085C_chstatuebossbits[];
typedef union { s32 word; s16 half; } StatueBitsPayload31;
extern s32 D_80800864_chstatuebossbits;
extern void func_800EC398(s32, f32 *);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void func_80109FB8();
extern f32 func_800D8FF8(void);
extern Actor *func_80106790(void *);
extern void func_800EF1B8(f32 *, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
void func_80800270_chstatuebossbits();
void func_80800604_chstatuebossbits();

int chstatuebossbits_entrypoint_0()
{
    return (int) &D_808006F0_chstatuebossbits;
}

int chstatuebossbits_entrypoint_1()
{
    return (int)&D_80800738_chstatuebossbits;
}

int *chstatuebossbits_entrypoint_2()
{
    return &D_80800780_chstatuebossbits;
}

int chstatuebossbits_entrypoint_3()
{
  return D_808007C8_chstatuebossbits;
}

void func_80800030_chstatuebossbits(s32 arg0) 
{
}
void func_80800038_chstatuebossbits(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    Actor *local_2;
    s32 local_3;
    s32 local_4;

    switch (param_0->unk70_10) {
    case 1:
        *(s32 *)&param_0->unk3C = 0;
        func_800EA600(func_80109FB8, param_0->unk0);
        local_0 = func_8010B990(param_0, 0x100005);
        func_800EA614();
        param_0->rotation[2] += func_800D8FF8() * 150.0f;
        if (local_0) {
            local_1 = 0;
            if (*(void **)&param_0->unk3C) {
                local_2 = func_80106790(*(void **)&param_0->unk3C);
                if (local_2->unk6C_9 == 0x449) {
                    func_8010108C(local_2, 0x40, param_0->unk0);
                    if (*(s32 *)&local_2->unk54 >= 3) {
                        local_1 = 1;
                    }
                }
            }
            func_800EF1B8(param_0->position, param_0->rotation[1] + 180.0f, 100.0f);
            func_80800270_chstatuebossbits(param_0);
            func_8010A570(param_0);
            if (local_1) {
                func_80101FDC(param_0, 3);
                _subaddiefade_entrypoint_3(param_0);
            } else {
                func_80101FDC(param_0, 2);
                param_0->unk58 = 1.4f;
            }
        }
        break;
    case 2:
        local_3 = func_800D9078(&param_0->unk58);
        local_4 = func_8001210C(1) ? -1 : 1;
        param_0->rotation[0] = func_800F10B4(param_0->unk58, 0.0f, 1.4f, 0.0f, 10.0f) * (f32)local_4;
        if (local_3) {
            _subaddiefade_entrypoint_3(param_0);
        }
        break;
    }
}

int func_80800224_chstatuebossbits(s32 *param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x40)
  {
    func_80800270_chstatuebossbits();
    func_800FFA88(param_0[0]);
    } else {
        return 0;
    }
    return 1;
}

void func_80800270_chstatuebossbits(param_0) u8 *param_0;
{
    func_800BBCB8(param_0 + 4, 0, *(s32 *)(param_0 + 0x38), 2, &D_80800810_chstatuebossbits);
    func_8010D930(4, -1, param_0 + 4, &D_8080084C_chstatuebossbits);
}

void func_808002CC_chstatuebossbits(Actor *param_0)
{
    s32 local_0;
    local_0 = func_800DA298(0x88);
    func_800EE7F8((f32 *)param_0->actorData, param_0->position);
    func_800EE7F8((f32 *)(param_0->actorData + 4), param_0->position);
    ((f32 *)param_0->actorData)[5] -= 180.0f;
    *(s32 *)&param_0->unk54 = 0;
    if (local_0) {
        func_80101FDC(param_0, 1);
        func_8010A590(param_0);
    } else param_0->position[1] = ((f32 *)param_0->actorData)[5];
}

void func_80800360_chstatuebossbits(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk70_10) {
        case 1:
        case 2:
            break;
        case 3:
            local_0 = func_800D9078(&param_0->unk58);
            func_800EFE50(param_0->position, &param_0->actorData[4], param_0->actorData,
                func_800F12D4(param_0->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
            if (local_0) {
                func_80101FDC(param_0, 1);
                func_80103110(param_0, 0);
                func_8010A590(param_0);
            }
            break;
    }
}

void func_8080040C_chstatuebossbits(Actor *param_0, s32 param_1)
{
    func_800DF744(1, ((StatueBossSelector *)param_0)->local_0 == 0 ? 1 : 0);
    func_800DF744(2, ((StatueBossSelector *)param_0)->local_0 == 1 ? 1 : 0);
    func_800DF744(3, ((StatueBossSelector *)param_0)->local_0 == 2 ? 1 : 0);
    func_800DF744(4, ((StatueBossSelector *)param_0)->local_0 == 3 ? 1 : 0);
    func_800DF744(5, 0);
    func_80101870(param_0, param_1);
}

s32 func_808004D8_chstatuebossbits(Actor *param_0, s32 param_1, StatueBitsPayload31 param_2)
{
    s32 local_0;
    s32 pad;

    switch (param_1) {
        case 0x40:
            local_0 = *(s32 *)&param_2;
            (*(s32 *)&param_0->unk54)++;
            func_80800604_chstatuebossbits(param_0, local_0);
            if (*(s32 *)&param_0->unk54 >= 3) {
                func_800EC398(local_0, param_0->actorData);
                *(f32 *)&param_0->actorData[1] = param_0->position[1];
                _chexploder_entrypoint_3(param_0, param_0->actorData, 12);
                _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_8080085C_chstatuebossbits);
                return 1;
            }
            break;
        case 7:
            func_80101FDC(param_0, 3);
            func_80103110(param_0, 1);
            param_0->unk58 = 3.0f;
            break;
        case 0x90:
            param_0 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(param_0, 2, 0);
            _chexploder_entrypoint_9(param_0, 5, 1);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_80800604_chstatuebossbits(param_0, param_1) s32 param_0; s32 param_1; {
    f32 local_0[3];
    func_800EC398(param_1, local_0);
    func_800BBCB8(local_0, local_0, 0x3F800000, 4, &D_80800864_chstatuebossbits);
}

void func_8080064C_chstatuebossbits(Actor *param_0)
{
    s32 local_0;
    local_0 = func_800DA298(0x88) || _glcutDll_entrypoint_20();
    if (local_0) func_80101FDC(param_0, 1);
    _chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, 180.0f, 0x102, -1);
    _chdoormake_entrypoint_5(param_0, 2.0f);
    _chdoormake_entrypoint_8(param_0, 13);
}
