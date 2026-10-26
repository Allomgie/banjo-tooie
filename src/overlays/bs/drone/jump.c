#include "common.h"
#include "overlays/ba/playerstate.h"

typedef struct { u8 pad_0[0x190]; f32 local_0; f32 local_1; } DroneJumpPlayer;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8008C990(PlayerState *, f32);
extern f32 _bamovegoto_entrypoint_3(PlayerState *);
extern f32 func_80013970(f32);
extern void _bsdronejump_entrypoint_0();
extern void _badata_entrypoint_8(PlayerState *, s32 *, f32 *, f32 *);
extern void baanim_playForDuration_loopStartingAt(PlayerState *, s32, f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void _bamovegoto_entrypoint_7(PlayerState *, f32);

void bsdronejump_entrypoint_0(PlayerState *param_0, f32 *param_1, f32 param_2)
{
    f32 local_0;
    f32 local_1;
    local_0 = func_800F10B4(param_2, 0.0f, 1.0f,
        ((DroneJumpPlayer *)param_0)->local_0, ((DroneJumpPlayer *)param_0)->local_1);
    func_8008C990(param_0, local_0);
    local_1 = _bamovegoto_entrypoint_3(param_0);
    param_1[1] += func_80013970(param_2 * 180.0f) * local_1 * 0.5f;
}

void bsdronejump_entrypoint_1(s32 arg0)
{
    func_800961A0(arg0,0);
}

void bsdronejump_entrypoint_2(PlayerState *param_0)
{
    f32 local_0;
    f32 local_3;
    f32 local_1[3];
    s32 local_2;
    _badata_entrypoint_8(param_0, &local_2, (f32 *)((u8 *)param_0 + 0x190), (f32 *)((u8 *)param_0 + 0x194));
    baanim_playForDuration_loopStartingAt(param_0, local_2, 1000.0f, *(f32 *)((u8 *)param_0 + 0x190));
    func_8009FFD8(param_0, 1, 1, 3, 2);
    func_8009C128(param_0, local_1);
    local_0 = func_800EEAD4(local_1, (f32 *)(*(u8 **)((u8 *)param_0 + 0x54) + 0x34));
    local_3 = func_800F1DF4(local_1, (f32 *)(*(u8 **)((u8 *)param_0 + 0x54) + 0x34));
    yaw_setIdeal(param_0, local_3);
    _bamovegoto_entrypoint_0(param_0);
    _bamovegoto_entrypoint_7(param_0, func_800F10B4(local_0, 100.0f, 5000.0f, 0.4f, 4.5f));
    _bamovegoto_entrypoint_12(param_0, *(u8 **)((u8 *)param_0 + 0x54) + 0x34);
    _bamovegoto_entrypoint_11(param_0, 0, _bsdronejump_entrypoint_0);
    _bamovegoto_entrypoint_13(param_0);
    func_800961A0(param_0, 1);
}

void bsdronejump_entrypoint_3()
{
    func_80099AA8();
}

int bsdronejump_entrypoint_4(Actor *param_0)
{
  int local_0;
  local_0 = 0;
  if (_bamovegoto_entrypoint_4(param_0))
  {
    local_0 |= _badata_entrypoint_34(param_0);
  }
  bs_setState(param_0, local_0);
}
