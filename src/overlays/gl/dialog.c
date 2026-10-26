#include "common.h"

extern s32 D_80127600[];
extern void func_800D70D0();
typedef struct { u8 pad_0[0x20]; u8 *local_0; s32 local_1; } DialogAsset59;
extern DialogAsset59 D_801275E0;
extern void *func_800D674C(s32);

s32 gldialog_entrypoint_0(void){
    return 0;
}

int gldialog_entrypoint_1(u8 *param_0)
{
    return param_0[0] == 0xFD && param_0[1] == 0x6A;
}

void gldialog_entrypoint_2(void) {
    D_80127600[0] = 0;
    D_80127600[1] = -1;
}

void gldialog_entrypoint_3(void) {
}

u8 *gldialog_entrypoint_4(s32 param_0)
{
    u8 *local_0;
    s32 local_1;
    u8 *local_2;

    D_801275E0.local_0 = func_800D674C(param_0);
    func_800D70D0(1);
    func_800D71F4(1);
    local_0 = D_801275E0.local_0;
    local_0++;
    local_0 += gldialog_entrypoint_0() * 2;
    local_1 = *local_0++;
    local_1 += *local_0++ << 8;
    local_2 = D_801275E0.local_0 + local_1;
    D_801275E0.local_1 = param_0;
    return local_2;
}

void gldialog_entrypoint_5(s32 param_0)
{
    func_800D721C(D_801275E0.local_1, 0);
    func_800D70F8(D_801275E0.local_1, 0);
    func_800D6CEC(D_801275E0.local_1);
    D_80127600[0] = 0;
    D_80127600[1] = -1;
}
