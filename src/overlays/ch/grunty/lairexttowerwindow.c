#include "common.h"

extern u8 D_808000D0_chgruntylairexttowerwindow[];
extern u8 D_8080013C_chgruntylairexttowerwindow[];
extern int D_80800150_chgruntylairexttowerwindow;
int func_80800070_chgruntylairexttowerwindow();

void func_80800000_chgruntylairexttowerwindow(s32 arg0) 
{
}
s32 func_80800008_chgruntylairexttowerwindow(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x40:
        _chexploder_entrypoint_3(param_0, param_0->position, 0xC);
        break;
    case 0x90:
        func_80800070_chgruntylairexttowerwindow(param_0);
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800070_chgruntylairexttowerwindow(param_0) Actor *param_0;
{
    func_800BABB8(0, (s32 *)((char *)param_0 + 0x4), (s32 *)((char *)param_0 + 0x4), (*(s32 *)((char *)(param_0) + 0x38)), &D_808000D0_chgruntylairexttowerwindow);
    func_800C4AF0((s32 *)((char *)param_0 + 0x4), &D_8080013C_chgruntylairexttowerwindow);
}

int chgruntylairexttowerwindow_entrypoint_0()
{
  return &D_80800150_chgruntylairexttowerwindow;
}
