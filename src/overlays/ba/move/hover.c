#include "common.h"
#include "overlays/ba/playerstate.h"

extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F15F8(f32, f32, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800EE7F8(int);

void bamovehover_entrypoint_0(s32 arg0) 
{
}
void bamovehover_entrypoint_1(u8 *param_0) {
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0xC8))) + 0xAC);
    func_800EFD24((*(s32 *)((s8 *)(param_0) + (0xC8))) + 0xB8);
    func_800EFA4C((*(s32 *)((s8 *)(param_0) + (0xC8))) + 0x10, 0x41855556, 0x42055556, 0x42480000);
}

void bamovehover_entrypoint_2(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1[3];
    s32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_5;

    local_0 = func_800D8FF8();
    func_800EF174(*(f32 **)((u8 *)param_0 + 0xC8) + 0xAC / 4,
        *(f32 **)((u8 *)param_0 + 0xC8) + 0xB8 / 4, local_0);
    for (local_2 = 0; local_2 < 3; local_2++) {
        local_3 = (*(f32 **)((u8 *)param_0 + 0xC8))[0xAC / 4 + local_2] -
            (*(f32 **)((u8 *)param_0 + 0xC8))[1 + local_2];
        local_4 = mlAbsF(local_3);
        if (local_4 > 5.0f) {
            local_5 = 220.0f * local_0;
            local_4 = func_800F10B4(local_4, 5.0f, 40.0f, 50.0f, 150.0f);
            local_1[local_2] = local_3 > 0.0f ? local_4 : -local_4;
            (*(f32 **)((u8 *)param_0 + 0xC8))[4 + local_2] =
                func_800F15F8((*(f32 **)((u8 *)param_0 + 0xC8))[4 + local_2],
                    local_1[local_2], local_5);
        }
    }
    func_800EF174(*(f32 **)((u8 *)param_0 + 0xC8) + 1,
        *(f32 **)((u8 *)param_0 + 0xC8) + 4, local_0);
}

void bamovehover_entrypoint_3(Actor *param_0)
{
    func_800EE7F8(*(int *)((char *)param_0 + 0xC8) + 0xAC);
}

void bamovehover_entrypoint_4(Actor *param_0, s32 param_1)
{
  if (!(param_1)) {
    func_800EFD24(*(s32 *)((char *)param_0 + 0xC8) + 0xB8);
  }
  else
  {
    func_800EE7F8(*(s32 *)((char *)param_0 + 0xC8) + 0xB8);
  }
}
