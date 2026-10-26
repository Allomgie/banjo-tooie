#include "common.h"

#define DOOR_EVENT_DATA_DEFINED
extern int D_80800160_chfactorylobbydoor;
extern int _chdoormake_entrypoint_3(s32, f32, s32, s32, s32, s32);
extern s32 D_808001A8_chfactorylobbydoor;
typedef union { s32 word; s16 half[2]; } DoorEventData;
extern void func_8010108C(Actor *, s32, s32);
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

int chfactorylobbydoor_entrypoint_0()
{
    return (int)&D_80800160_chfactorylobbydoor;
}

void func_8080000C_chfactorylobbydoor(s32 param_0) {
    if ((func_800EA090() == 1) && ((func_800D0A9C(0x35, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(param_0, 1);
    }
    if (_chdoormake_entrypoint_3(param_0, 0, 0x42B40000, 0x43480000, 8, -1) != 0) {
        _chdoormake_entrypoint_5(param_0, 0x3FC00000);
        _chdoormake_entrypoint_8(param_0, 0x5);
    }
}

void func_808000A8_chfactorylobbydoor(s32 arg0)
{
    func_808000D0_chfactorylobbydoor();
    _chdoor_entrypoint_0(arg0);
}
int func_808000D0_chfactorylobbydoor(s32 param_0)
{
  s32 local_0;
  local_0 = _subaddiedialog_entrypoint_7(param_0, param_0 + 4, &D_808001A8_chfactorylobbydoor);
  if (local_0 != 0)
  {
    _chmrtannoy_entrypoint_0();
  }
}

s32 func_80800108_chfactorylobbydoor(Actor *param_0, s32 param_1, DoorEventData param_2)
{
    if (param_1 == 0x2E) {
        if (param_2.half[0] == 0x1370) {
            func_8010108C(param_0, 7, 0);
        }
        return 1;
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
}
