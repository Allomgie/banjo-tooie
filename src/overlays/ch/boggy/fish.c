#include "common.h"

extern u8 func_800D731C(s32);
extern void func_800DBE60(u8, s32, s32);
typedef union {
    s32 word;
    s16 half;
} BoggyFishPayload31;
typedef struct {
    u8 pad_0[0x28];
    f32 value;
    f32 velocity;
} BoggyFishFloatState1408;
extern int D_80800220_chboggyfish[];

void func_80800000_chboggyfish(s32 *param_0, u8 *param_1)
{
    if ((*(u32 *) ((u8 *) param_1 + 0x24) >> 22) == 0) {
        func_800F6388(func_800F54E4(), 0x4BA);
        func_800D1844(0x51);
        func_800FC6B0(0xE);
        func_800DA544(0x438);
        func_800FFA88(*param_0);
    }
}

s32 func_80800064_chboggyfish(Actor *param_0, s32 param_1, BoggyFishPayload31 param_2)
{
    u8 local_0;
    s32 local_1;

    switch (param_1) {
        case 0x3E:
            func_80800000_chboggyfish(param_0, param_2.word);
            return 1;
        case 0x1F:
            func_801015D0(param_0);
            local_0 = func_800D731C(param_0->unk0->unk14);
            if (local_0) {
                local_1 = (s32) *(f32 *) ((u8 *) param_0 + 0x28);
                func_800DBE60(local_0, 0, local_1);
                func_800DBE60(local_0, 1, local_1);
                func_800DBE60(local_0, 2, local_1);
                func_800DBE60(local_0, 3, local_1);
            }
            break;
        case 0x95:
            if (func_800DA298(0x438) && !_glcutDll_entrypoint_20()) {
                func_800FFAB0(param_0);
                return 0;
            } else {
                *(f32 *) ((u8 *) param_0 + 0x28) = 0.0f;
                *(f32 *) ((u8 *) param_0 + 0x2C) = 0.5f;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080018C_chboggyfish(BoggyFishFloatState1408 *param_0)
{
    param_0->value += param_0->velocity;
    if (param_0->value <= 0.0f) {
        param_0->value = 0.0f;
        param_0->velocity = 0.0f - param_0->velocity;
    }
    if (param_0->value >= 4.0f) {
        param_0->value = 4.0f;
        param_0->velocity = 0.0f - param_0->velocity;
    }
}

int chboggyfish_entrypoint_0()
{
    return (int) &D_80800220_chboggyfish;
}

extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800210_chboggyfish[4] = {0x0, 0x0, 0x3F99999A, 0x4440049};
int D_80800220_chboggyfish[20] = {0x37A04BA,
                                  0x8FA0001,
                                  (u32) &D_80800210_chboggyfish,
                                  (u32) func_8080018C_chboggyfish,
                                  (u32) func_80105834,
                                  (u32) func_801018A4,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80108ED0,
                                  0x14,
                                  0x0,
                                  (u32) func_80107C2C,
                                  -0x7FBFABFC,
                                  (u32) func_80800064_chboggyfish,
                                  0x0,
                                  0x0,
                                  0x0};
