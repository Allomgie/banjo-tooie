#include "common.h"

extern void func_800FC6B0();
extern void func_800FCA90();
extern void func_800FCAE0();
typedef struct {
    s16 map;
    s16 music;
    s16 effect;
    s16 pad;
} IntroTickerAudio;
extern IntroTickerAudio D_80800830_chintroticker[15];
extern s32 D_808008A8_chintroticker[];
extern s32 D_808008C0_chintroticker[];
extern void _glintrosyncDll_entrypoint_2(f32);
extern void _glcutDll_entrypoint_14(s32);
extern void _glcutDll_entrypoint_24(s32, s32, s32);
extern f32 func_800D9004(void);
extern f32 func_800D8FF8(void);
extern void _glintrosyncDll_entrypoint_4(f32);
typedef struct {
    s16 local_0;
    s16 local_1;
} IntroTickerEntry;
extern IntroTickerEntry D_808008C4_chintroticker[28];
extern void *D_80800934_chintroticker;

void func_80800000_chintroticker(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_1 = func_800EA05C();
    for (local_0 = 0; local_0 < 15; local_0++) {
        if (D_80800830_chintroticker[local_0].map == local_1) {
            if (D_80800830_chintroticker[local_0].music != -1) {
                if (func_800FCCD4(D_80800830_chintroticker[local_0].music)) {
                    func_800FCAE0(D_80800830_chintroticker[local_0].music, 0, 0x2EE0);
                    func_800FCA90(D_80800830_chintroticker[local_0].music);
                }
            }
            if (D_80800830_chintroticker[local_0].effect != -1) {
                func_800FC6B0(D_80800830_chintroticker[local_0].effect);
            }
        }
    }
}

s32 func_808000B0_chintroticker(param_0, param_1)
Actor *param_0;
s32 param_1;
{
    s32 local_0;

    local_0 = 0;
    switch (param_1) {
        case 0x167:
            0;
            break;
        case 0xA1:
        case 0xA2:
        case 0xA3:
        case 0xA4:
        case 0xA5:
        case 0xA6:
        case 0xA7:
        case 0xA8:
        case 0xA9:
        case 0xAA:
        case 0xAB:
        case 0xAC:
            local_0 = 2;
            break;
        case 0x17E:
        case 0x18C:
        case 0x18D:
        case 0x18E:
        case 0x18F:
        case 0x190:
            local_0 = 3;
            break;
        case 0x192:
        case 0x193:
        case 0x194:
        case 0x195:
        case 0x197:
        case 0x198:
        case 0x199:
            local_0 = 4;
            break;
        case 0x191:
        case 0x196:
            local_0 = 5;
            break;
        case 0x18B:
            local_0 = 1;
            break;
    }
    if (D_808008A8_chintroticker[local_0])
        _gcfrontend_entrypoint_9(D_808008A8_chintroticker[local_0]);
    param_0->unk79_4 = local_0;
    return 1;
}

void func_80800188_chintroticker(param_0, param_1) Actor *param_0;
s32 param_1;
{
    if (param_1 == 0xA1 || param_1 == 0x18B || param_1 == 0x18E || param_1 == 0x194 ||
        param_1 == 0x196) {
        switch (param_0->unk79_4) {
            case 0:
            case 5:
                break;
            case 1:
                if (func_800167F4())
                    _chattract_entrypoint_1(3);
                break;
            case 2:
                func_800DA544(0x578);
                break;
            case 3:
                func_800DA524(0x360);
                func_800DA524(0x3B);
                break;
            case 4:
                func_800DA544(0x360);
                func_800DA524(0x3B);
                func_800DA524(0x578);
        }
    }
}

void func_80800254_chintroticker(param_0) u8 *param_0;
{
    int new_var2;
    u8 new_var;
    u32 temp_t7;
    new_var2 = 0x79;
    new_var = *(u8 *) ((s8 *) param_0 + new_var2);
    new_var2 = new_var;
    temp_t7 = (u8) new_var2 >> 4;
    switch (temp_t7) {
        case 2:
            func_800DA524(0x578);
            return;

        case 3:
            func_800DA544(0x360);
            func_800DA524(0x3B);
            return;

        case 4:
            func_800DA524(0x360);
            func_800DA544(0x3B);
            func_800DA524(0x1A5);
            func_800DA544(0x578);

        case 0:

        case 5:
            return;
    }
}

void func_808002DC_chintroticker(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_1 = func_800EA05C();
    for (local_0 = 0; local_0 < 1; local_0++) {
        if (local_1 == D_808008C0_chintroticker[local_0]) {
            _glintrosyncDll_entrypoint_2(0.0f);
        }
    }
    if (!func_808000B0_chintroticker(param_0, local_1)) {
        func_800FFAB0(param_0);
    } else {
        func_80800188_chintroticker(param_0, local_1);
        if (_glcutDll_entrypoint_18() == 0x68) {
            param_0->unk64_20 = 1;
        }
        func_80800000_chintroticker(param_0);
        ((f32 *) param_0->actorData)[5] = ((f32 *) param_0->actorData)[4] = 0;
    }
}

void func_808003BC_chintroticker(s32 arg0)
{
}

void func_808003C4_chintroticker(param_0) Actor *param_0;
{
    func_80800254_chintroticker();
    if (func_800D395C()) {
        _gcfrontend_entrypoint_10();
        func_800EA334(1);
        return;
    }
    if (func_800DB9B0()) {
        _glcutDll_entrypoint_12(1);
        _glcutDll_entrypoint_17();
        return;
    }
    switch (param_0->unk79_4) {
        case 2:
            func_800A7990(0xAF, 4, 1);
            break;
        case 1:
            _gsattract_entrypoint_5(0);
        case 3:
            break;
        case 4:
            func_800A7990(0x160, 4, 1);
            break;
        case 5:
            _gcfrontend_entrypoint_13();
    }
}

void func_808004A8_chintroticker(Actor *param_0, s32 param_1)
{
    if (!func_800A8264()) {
        if (param_1 >= 0) {
            if (param_0->unk64_20) {
                _glcutDll_entrypoint_14(1);
                _glcutDll_entrypoint_24(param_1, -1, -1);
            } else
                func_800A7990(param_1, 0, 1);
        } else
            func_808003C4_chintroticker(param_0);
    }
}

void func_80800530_chintroticker(s32 param_0, s32 param_1)
{
    s16 *local_0;
    int new_var;
    s16 local_1;
    u32 local_2;
    local_0 = (s16 *) D_808008C4_chintroticker;
    do { new_var = 0x1C; local_2 = 0; loop_1: if (param_1 != *local_0) { local_1 = new_var; local_2 += 1; local_0 += 2; if (local_2 != local_1) { goto loop_1; } } } while (0);
    if (local_2 < 0x1CU)
    {
        loop_4:
        local_1 = *(s16 *) ((s8 *) local_0 + 2);

        local_2 += 1;
        if (local_1 < 0)
        {
            func_808004A8_chintroticker(param_0, local_1);
            return;
        }
        local_0 += 2;
        if (local_2 >= 0x1CU)
        {}
        else
        {
            goto loop_4;
        }
    }
}

void func_808005AC_chintroticker(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800EA05C();
    if (func_800DA9E4(0, 0)) {
        for (local_1 = 0; local_1 < 28; local_1++) {
            if (local_0 == D_808008C4_chintroticker[local_1].local_0) {
                func_808004A8_chintroticker(param_0, D_808008C4_chintroticker[local_1].local_1);
            }
        }
    }
    switch (param_0->unk79_4) {
        case 1:
            if (func_800DA298(0xD56) && !func_800A8264() && func_80015FA0(0) == 1) {
                _gcfrontend_entrypoint_10();
            }
            break;
        case 2:
        default:
            if (func_80016B30(0, 1) == 1)
                func_80800530_chintroticker(param_0, local_0);
    }
    _glintrosyncDll_entrypoint_4(func_800D9004());
    *(f32 *) ((u8 *) param_0 + 0x28) += func_800D9004();
    *(f32 *) ((u8 *) param_0 + 0x2C) += func_800D8FF8();
}

void *chintroticker_entrypoint_0()
{
    return &D_80800934_chintroticker;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
IntroTickerAudio D_80800830_chintroticker[15] = {
    0x18E, -0x1, 0x87, 0x0, 0x18C, 0x87, 0x88, 0x0, 0x18F, 0x88, 0x89, 0x0, 0x190, 0x89, 0x8A, 0x0,
    0x17E, 0x8A, 0x8B, 0x0, 0x18D, 0x8B, 0x8C, 0x0, 0x194, -0x1, 0x8E, 0x0, 0x197, 0x8E, 0x8F, 0x0,
    0x198, 0x8F, 0x90, 0x0, 0x199, 0x90, 0x91, 0x0, 0x195, 0x91, 0x93, 0x0, 0x193, 0x93, 0x94, 0x0,
    0x192, 0x94, 0x95, 0x0, 0x191, -0x1, 0x98, 0x0, 0x196, 0x98, 0x99, 0x0};
s32 D_808008A8_chintroticker[6] = {0x0, 0x0, 0x80, 0x81, 0x82, 0x83};
s32 D_808008C0_chintroticker[1] = {0xA1};
IntroTickerEntry D_808008C4_chintroticker[28] = {
    0xA1,  0xA8,  0xA8,  0xA2,  0xA2,  0xA9,  0xA9,  0xA3, 0xA3,  0xAA,  0xAA,  0xA4,  0xA4,  0xAB,
    0xAB,  0xA5,  0xA5,  0xAC,  0xAC,  0xA6,  0xA6,  0xA7, 0xA7,  -0x2,  0x18E, 0x18C, 0x18C, 0x18F,
    0x18F, 0x190, 0x190, 0x17E, 0x17E, 0x18D, 0x18D, -0x3, 0x194, 0x197, 0x197, 0x198, 0x198, 0x199,
    0x199, 0x195, 0x195, 0x193, 0x193, 0x192, 0x192, -0x4, 0x191, 0x196, 0x196, -0x5,  0x18B, -0x1};
void *D_80800934_chintroticker = (void *) 0x02C50374;
static u32 D_80800934_chintroticker_rest[18] = {0x1,
                                                0x0,
                                                (u32) func_808005AC_chintroticker,
                                                (u32) func_80105834,
                                                (u32) func_8010A730,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x80004,
                                                (u32) func_808003BC_chintroticker,
                                                0x0,
                                                0x0,
                                                (u32) func_808002DC_chintroticker,
                                                (u32) func_80107C2C,
                                                0x80000202,
                                                0x0,
                                                0x0,
                                                0x0};
