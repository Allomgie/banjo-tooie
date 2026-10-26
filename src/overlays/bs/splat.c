#include "common.h"
#include "overlays/ba/playerstate.h"

extern void func_800954E8(PlayerState *, s32 *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern f32 func_800F0E00(f32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 anctrl_isAt(void *, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern s32 D_808002B0_bssplat[];

void bssplat_entrypoint_0(PlayerState *param_0)
{
    s32 local_0;
    func_800954E8(param_0, &local_0);
    func_800A17A8(param_0, -local_0);
    if (func_80096694(param_0) == 3) {
        func_8009DB04(param_0, 0x417, 0.8f, 0x7FFF);
    } else {
        func_8009DB04(param_0, 0x417, 0.8f, 0x7FFF);
    }
    _badust_entrypoint_8(param_0);
    _bashake_entrypoint_0(param_0, 3, 2);
}

void func_8080009C_bssplat(PlayerState *param_0)
{
    baanim_playForDuration_once(param_0, 0x46, 1.1f);
    func_8009FFD8(param_0, 1, 1, 3, 3);
    bssplat_entrypoint_0(param_0);
    func_8009DF18(param_0, 0x427, 1.0f, 0x6D60);
    param_0->unk15C.word = 0;
    func_8008E944(param_0);
}

void func_80800114_bssplat(PlayerState *param_0)
{
    s32 local_0 = 0;
    void *local_1 = baanim_getAnimCtrlPtr(param_0);

    baphysics_set_target_horizontal_velocity(param_0, func_800F0E00(0.0f, baphysics_get_target_horizontal_velocity(param_0) - 15.0f));
    switch (*(s32 *)((u8 *)param_0 + 0x15C)) {
        case 0:
            if (baphysics_get_target_horizontal_velocity(param_0) > 140.0f) _badust_entrypoint_9(param_0);
            if (func_8008DD04(param_0)) local_0 = 0x2F;
            if (anctrl_isStopped(local_1)) {
                baanim_playForDuration_onceSmooth(param_0, 0xD2, 2.25f);
                *(s32 *)((u8 *)param_0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (anctrl_isAt(local_1, 0.63f)) local_0 = 0x20;
            if (anctrl_isStopped(local_1)) local_0 = 1;
            if (func_8008DD04(param_0)) local_0 = 0x2F;
            break;
    }
    if (!player_isStable(param_0) && player_inWater(param_0)) local_0 = 0x2D;
    if (!func_800A1718(param_0)) local_0 = 0x41;
    bs_setState(param_0, local_0);
}

void func_80800274_bssplat(s32 arg0)
{
    func_8008E95C();
    func_8009BD88(arg0);
}
int bssplat_entrypoint_1(s32 param_0)
{
  return D_808002B0_bssplat[param_0];
}
