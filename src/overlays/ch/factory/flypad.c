#include "ch/factory/flypad.h"

extern void *D_80800250_chfactoryflypad;
extern int D_80800298_chfactoryflypad[];
typedef union {
    s32 word;
    void *pointer;
} FlypadMessage29;
extern Actor *func_801084B0(s32, Actor **);
extern Actor *_subaddiefind_entrypoint_1(Actor *, s32, s32, s32);
extern void _chappearfx_entrypoint_1(Actor *, s32, s32, f32);

int chfactoryflypad_entrypoint_0()
{
    return &D_80800250_chfactoryflypad;
}

int *chfactoryflypad_entrypoint_1()
{
    return &D_80800298_chfactoryflypad;
}

void func_80800018_chfactoryflypad(s32 arg0)
{
    _chswitch_entrypoint_7(arg0, FLAG_16B_UNK);
    _chswitch_entrypoint_9(arg0);
}

int func_80800044_chfactoryflypad(s32 param_0, s32 param_1)
{
    if (param_1 == 7) {
        _glcutDll_entrypoint_6(0x100, 0x42);
        return 1;
    }
    return _chswitch_entrypoint_10(param_0, param_1);
}

void func_80800080_chfactoryflypad(s32 arg0)
{
}

void func_80800088_chfactoryflypad(Actor *param_0)
{
    s32 local_0 = 0;
    if (((u32) *(u16 *) ((char *) param_0 + 0x76) >> 7) == 0x32 &&
        _glcutDll_entrypoint_19(0x42) != 0) {
        func_80108B04(param_0, 0);
        local_0 = 1;
    }
    if (_glcutDll_entrypoint_19(0x42) == 0 && func_800DA298(0x16B) != 0) {
        func_80108B04(param_0, 0);
        local_0 = 1;
    }
    if (local_0 == 0 && _glcutDll_entrypoint_19(0x42) == 0) {
        func_800FFAB0(param_0);
    }
}

s32 func_80800130_chfactoryflypad(Actor *param_0, s32 param_1, FlypadMessage29 param_2)
{
    Actor *local_0;
    switch (param_1) {
        case 0x3D:
            local_0 = func_801084B0(0x234, &param_0);
            if (_glcutDll_entrypoint_19(0x42))
                _chappearfx_entrypoint_1(local_0, 0x22, 2, 1.0f);
            func_800FFAB0(param_0);
            break;
        case 0x49:
            if (param_0->unk74_7 == 0x32 && _glcutDll_entrypoint_19(0x42)) {
                _capod_entrypoint_13(param_0->unk0,
                                     _subaddiefind_entrypoint_1(param_0, 0x42F, -1, 0)->unk0, 5,
                                     0x900);
                break;
            }
            return 0;
        case 0xC:
            func_80108B04(param_0, 0);
            return 3;
        case 0x95:
            func_80800088_chfactoryflypad(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void func_80102EC0();
void *D_80800250_chfactoryflypad = (void *) 0x0343042E;
static u32 D_80800250_chfactoryflypad_rest[17] = {0x7BA0001,
                                                  (u32) &D_8011A270,
                                                  (u32) _chswitch_entrypoint_6,
                                                  (u32) func_80105834,
                                                  (u32) func_80101870,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  0x40000808,
                                                  0x0,
                                                  0x0,
                                                  0x0,
                                                  (u32) func_80800018_chfactoryflypad,
                                                  (u32) func_80107C2C,
                                                  0x80082C12,
                                                  (u32) func_80800044_chfactoryflypad,
                                                  0x0};
int D_80800298_chfactoryflypad[18] = {0x342042F,
                                      0x1,
                                      0x0,
                                      (u32) func_80102EC0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_80800080_chfactoryflypad,
                                      (u32) func_80107C2C,
                                      -0x7FFFF9FE,
                                      (u32) func_80800130_chfactoryflypad,
                                      0x0};
