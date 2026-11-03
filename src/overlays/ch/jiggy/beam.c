#include "common.h"

extern u32 D_80800070_chjiggybeam[];

int chjiggybeam_entrypoint_0()
{
    return (int) &D_80800070_chjiggybeam;
}

func_8080000C_chjiggybeam(f32 param_0[3])
{
    f32 local_0 = 1.0f;
    param_0[6] = local_0;
}

void func_8080001C_chjiggybeam(void)
{
}

s32 func_80800024_chjiggybeam(s32 param_0, s32 param_1)
{
    f32 local_0[3];

    func_800E3A58(local_0);
    func_80101870(param_0, param_1);
}

s32 func_80800058_chjiggybeam(s32 arg0, u32 arg1, u32 arg2)
{
    return 0;
}

extern void func_80102EC0();
extern void func_80107C2C();
u32 D_80800070_chjiggybeam[24] = {0x15804B3,
                                  0x81B0001,
                                  0x0,
                                  (u32) func_8080001C_chjiggybeam,
                                  (u32) func_80102EC0,
                                  (u32) func_80800024_chjiggybeam,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x20400,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_8080000C_chjiggybeam,
                                  (u32) func_80107C2C,
                                  0x80000402,
                                  (u32) func_80800058_chjiggybeam,
                                  0x0,
                                  0xFF,
                                  0xFF,
                                  0xFF,
                                  0x0,
                                  0x0,
                                  0x0};
