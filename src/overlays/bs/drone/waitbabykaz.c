#include "common.h"
#include "overlays/ba/playerstate.h"

void bsdronewaitbabykaz_entrypoint_0(s32 arg0) 
{
}
int bsdronewaitbabykaz_entrypoint_1(Actor *param_0)
{
  s32 local_1;
  s32 local_0;
  _badata_entrypoint_3(param_0, &local_0, &local_1);
  baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
  func_8009FFD8(param_0, 1, 1, 3, 2);
}

void bsdronewaitbabykaz_entrypoint_2(PlayerState *param_0)
{
    s32 local_0;

    switch (func_8009E6EC(param_0)) {
    case 0x20: case 0x21: case 0x24: case 0x2D: case 0x2E: case 0x2F:
    case 0x4E: case 0x51: case 0x52: case 0x59: case 0x5A: case 0x5B: case 0x5C:
        func_80099B94(param_0);
        local_0 = _plsu_entrypoint_1(0x11);
        if (local_0 != -1) func_800F7B9C(local_0, 0x87);
        func_8009E830(param_0, 2);
        return;
    case 0x6B:
        func_80099B94(param_0);
        return;
    case 0x15: case 0x1C: case 0x1D: case 0x1E:
        break;
    default:
        func_80099B94(param_0);
        return;
    }
}

s32 bsdronewaitbabykaz_entrypoint_3(void *arg){
    s32 local_0 = 0;
    if(_plsu_entrypoint_1(0x11) == -1){
        local_0 = _badata_entrypoint_34(arg);
    }
    bs_setState(arg, local_0);
}
