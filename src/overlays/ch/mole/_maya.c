#include "ch/mole.h"

extern void *D_80800258_chmole_maya;

extern MoveData D_808001E0_chmole_maya[];
extern D_808000D0 D_80800210_chmole_maya;

void func_80800000_chmole_maya(Actor *a0, u32 a1, u32 a2)
{
    _sumole_entrypoint_3(a0, a1, a2, D_808001E0_chmole_maya);
}

void func_80800024_chmole_maya(Actor *a0)
{
    _sumole_entrypoint_0(a0, 0);
    a0->unk74_7 = a0->unk74_7 - 0x32;
    a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_maya(Actor *a0)
{
    _sumole_entrypoint_4(a0, D_808001E0_chmole_maya);
}

void *chmole_maya_entrypoint_0()
{
    return &D_80800210_chmole_maya;
}

void func_808000C0_chmole_maya(u8 *param_0)
{
    if ((func_8010C500(param_0) != 0) && (func_8008FA2C(-1, 0) != 0)) {
        *(u8 *) ((s8 *) param_0 + 0x7E) = (u8) (*(u8 *) ((s8 *) param_0 + 0x7E) & 0xFFBF);
        func_800DA544(0x506);
        _subaddiedialog_entrypoint_11(*(s32 *) ((s8 *) param_0 + 0), 0xDBF, 0xC, param_0 + 4, 0x6F);
        _capod_entrypoint_13(*(s32 *) ((s8 *) param_0 + 0), 0, 0xB, 0x20);
    }
}

void func_80800144_chmole_maya(s32 arg0)
{
}

s32 func_8080014C_chmole_maya(s32 param_0)
{
    if (func_800DA298(0x506)) {
        func_800FFAB0(param_0);
    }
}

int func_80800180_chmole_maya(s32 param_0, s32 param_1, s32 param_2)
{
    if (param_1 == 0x2E) {
        _capod_entrypoint_14();
        func_800FFAB0(param_0);
    } else {
        return 0;
    }
    return 1;
}

int chmole_maya_entrypoint_1()
{
    return &D_80800258_chmole_maya;
}

extern void func_8010A730();
extern void func_80107C2C();
extern void func_80105834();
MoveData D_808001E0_chmole_maya[3] = {0x1, 0xD44, 0xD42, 0xD43, 0x14, 0xFF, 0x23, 0xE,  0x0,
                                      0x1, 0xD47, 0xD45, 0xD46, 0x15, 0xFF, 0x1E, 0xF,  0x0,
                                      0x1, 0xD4A, 0xD48, 0xD49, 0x16, 0xFF, 0x19, 0x10, 0x0};
D_808000D0 D_80800210_chmole_maya = {0x2EA01A7,
                                     0x1,
                                     0x0,
                                     (void *) func_80800090_chmole_maya,
                                     0x0,
                                     (void *) func_8010A730,
                                     0x1F40000,
                                     0x0,
                                     0x0,
                                     0x80004,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (void *) func_80800024_chmole_maya,
                                     (void *) func_80107C2C,
                                     0x80002202,
                                     (u32) func_80800000_chmole_maya,
                                     0x0,
                                     0x158030B};
static u32 D_80800210_chmole_maya_rest[17] = {0x1,
                                              0x0,
                                              (u32) func_808000C0_chmole_maya,
                                              (u32) func_80105834,
                                              (u32) func_8010A730,
                                              0x13880000,
                                              0x0,
                                              0x0,
                                              0x80005,
                                              (u32) func_80800144_chmole_maya,
                                              0x0,
                                              0x0,
                                              (u32) func_8080014C_chmole_maya,
                                              (u32) func_80107C2C,
                                              0x80000002,
                                              (u32) func_80800180_chmole_maya,
                                              0x0};
