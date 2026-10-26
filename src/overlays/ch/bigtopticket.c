#include "common.h"

extern void *D_80800120_chbigtopticket;
extern f32 func_800D8FF8(void);
extern void func_80101870(void);
extern void func_80103110(void *param_0, int param_1);

void *chbigtopticket_entrypoint_0()
{
    return &D_80800120_chbigtopticket;
}

void func_8080000C_chbigtopticket(s32 arg0) 
{
}
void func_80800014_chbigtopticket(u8 *param_0) {
    *(f32 *)(param_0 + 0x48) -= func_800D8FF8() * 175.0f;
    func_80103110(param_0, 0);
}

void func_80800058_chbigtopticket(Actor *param_0)
{
    func_80101870();
    func_80103110(param_0, ((*(u32 *)((char *)param_0 + 0x7C)) << 19) >> 31);
}

s32 func_8080008C_chbigtopticket(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x3E:
        _sudialog_entrypoint_0(0x19F, 4);
        func_800D0BD4(*(s32 *)&param_0->unk54, 8);
        func_800D1844(0x4D);
        func_800FC6B0(0x73);
        _fxsparkle_entrypoint_1(param_0->position, 0x11);
        func_8010A570(param_0);
        func_800FFAB0(param_0);
        return 1;
    case 0x13:
        *(s32 *)&param_0->unk54 = param_2;
        break;
    default:
        return 0;
    }
    return 1;
}
