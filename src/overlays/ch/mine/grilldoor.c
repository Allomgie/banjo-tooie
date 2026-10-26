#include "ch/minegrilldoor.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern u8 unk6A[];

extern u32 D_80800190_chminegrilldoor;

void func_80800000_chminegrilldoor(Actor *param_0)
{
    param_0->unk6C_0 = 0;
    if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 220.0f, 4, 0x43B)) {
        _chdoormake_entrypoint_8(param_0, 2);
    }
}

s32 func_80800068_chminegrilldoor(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    if (!func_800DA298(0x43B) && param_1 >= 0x79 && param_1 < 0x7D) {
        local_0 = param_1 - 0x79;
        local_1 = (local_0 & 2) ? 2 : 1;
        param_0->unk6C_0 = (param_0->unk6C_0 & (3 - local_1)) + (local_0 & 1) * local_1;
        if (param_0->unk6C_0 == 3) {
            func_800DA544(0x43B);
            _capod_entrypoint_13(param_0->unk0, 0, 8, 0x10);
        }
        return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2);
}

int func_80800144_chminegrilldoor(Actor *param_0)
{
  if (((*(s32 *)((char *)(param_0) + 0x6C)) & 0x1FF) == 3)
  {
    _chdoor_entrypoint_0();
  }
}

void* chminegrilldoor_entrypoint_0(void) {
    return &D_80800190_chminegrilldoor;
}

