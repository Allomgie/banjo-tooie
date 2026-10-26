#include "common.h"

extern int D_808000C0_chmumboskulls;
extern u16 D_80800108_chmumboskulls[];
extern void func_80103140();
void func_8080007C_chmumboskulls();

int chmumboskulls_entrypoint_0()
{
    return (int)&D_808000C0_chmumboskulls;
}

void func_8080000C_chmumboskulls(s32 arg0)
{
    func_8010A800(arg0,1);
}

void func_8080002C_chmumboskulls(s32 arg0) 
{
}
int func_80800034_chmumboskulls(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x95)
  {
    func_8080007C_chmumboskulls(param_0);
    func_8010A63C(param_0);
    } else {
        return 0;
    }
    return 1;
}

void func_8080007C_chmumboskulls(param_0) Actor *param_0;
{
    s32 local_0;

    local_0 = param_0->unk74_7 - 0x32;
    func_80103140(param_0, D_80800108_chmumboskulls[local_0], 0);
}
