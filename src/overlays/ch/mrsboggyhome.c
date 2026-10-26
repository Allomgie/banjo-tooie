#include "common.h"

extern int D_808001F0_chmrsboggyhome;
extern void _sudeflect_entrypoint_1(u32 *, s32, f32, s32, s32);
extern int _suexpression_entrypoint_10();
extern int _suexpression_entrypoint_20();
typedef union { s32 local_0; f32 local_1; void *local_2; } BoggyHomeEvent59;
extern void _suexpression_entrypoint_12(s32, f32, f32);
extern u8 D_80800238_chmrsboggyhome;
extern u8 D_808001B0_chmrsboggyhome;
int func_80800174_chmrsboggyhome();

int *chmrsboggyhome_entrypoint_0()
{
    return &D_808001F0_chmrsboggyhome;
}

s32 func_8080000C_chmrsboggyhome(s32 param_0) {
    if (_glcutDll_entrypoint_20()) {
        func_80102424(param_0, 3);
    } else {
        if (func_800DA298(0x1CD) == 0) {
            func_800FFAB0(param_0);
        }
    }
}

void func_8080005C_chmrsboggyhome(s32 *param_0)
{
    _sudeflect_entrypoint_1((u32 *)param_0 + 1, 0x43480000, 0, 0x42C80000, 0xA);
  _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0[0], 0);
  if (((u32)((*(u16 *)((char *)(param_0) + 114))) >> 10) == 1)
  {
    func_80800174_chmrsboggyhome(param_0);
  }
}

void func_808000D0_chmrsboggyhome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808000F0_chmrsboggyhome(Actor *param_0, s32 param_1, BoggyHomeEvent59 param_2)
{
    s32 local_0;

    switch (param_1) {
        case 0x2E:
            func_80102424(param_0, 1);
            break;
        case 0x95:
            local_0 = _suexpression_entrypoint_7(param_0, 1, 0x3E);
            _suexpression_entrypoint_12(local_0, 60.0f, 20.0f);
            _suexpression_entrypoint_17(local_0, 1000);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800174_chmrsboggyhome(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = 4;
  _subaddiedialog_entrypoint_8(param_0, param_0 + 4, &D_80800238_chmrsboggyhome, &D_808001B0_chmrsboggyhome, local_0);
}
