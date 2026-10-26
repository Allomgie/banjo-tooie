#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern f32 yaw_getIdeal(void *);
extern void baphysics_set_target_yaw(void *, f32);
extern f32 func_80099A34(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_applyIdeal(PlayerState *);
extern void func_8009D89C(PlayerState *, f32);
extern void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void func_800F1574(f32 *, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern s32 baanim_isAt(PlayerState *, f32);
extern s32 D_808003D0_bscrashout[];
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
void func_80800000_bscrashout();

void func_80800000_bscrashout(param_0) PlayerState *param_0;
{
    if (baanim_isAt(param_0, 0.3659f)) {
        func_8009DB04(param_0, 0x417, 1.0f, 0x36B0);
    }
    if (baanim_isAt(param_0, 0.6862f)) {
        func_8009DB04(param_0, 0x417, 0.8f, 0x4650);
        func_8009DB04(param_0, 0x427, 1.0f, 0x55F0);
    }
    if (baanim_getTimer(param_0) < 0.8f) {
        _badust_entrypoint_9(param_0);
    }
}

void func_808000B0_bscrashout(u8 *param_0, s32 param_1) {
    (*(s32 *)((s8 *)(param_0) + (0x15C))) = param_1;
    switch (param_1) {                                 
    case 1:
        baanim_playForDuration_onceSmooth(param_0, 0x3E, 0x3FB33333);
        func_8009FFD8(param_0, 1, 3, 3, 3);
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        baphysics_set_target_horizontal_velocity(param_0, (*(f32 *)((s8 *)(param_0) + (0x16C))));
        baphysics_set_horizontal_velocity(param_0, 0x42C80000, (*(s32 *)((s8 *)(param_0) + (0x16C))));
        return;
    case 2:
        func_800951B4(param_0);
        baanim_playForDuration_onceSmooth(param_0, 0xD2, 0x40100000);
        return;
    case 3:
        func_800A0180(param_0);
        func_800A4DFC(param_0, 0xA);
        _ncbadie_entrypoint_3(func_800A4CA8(param_0), 0x41F00000);
        _basudie_entrypoint_1(param_0);
        _batimer_set(param_0, 0, 0x404CCCCD);
        return;
    }
}

void bscrashout_entrypoint_0(s32 arg0)
{
    func_8009BD88();
    func_8008E95C(arg0);
    func_800951B4(arg0);
}

void bscrashout_entrypoint_1(PlayerState *param_0)
{
    yaw_setIdeal(param_0, func_80099A34(param_0));
    yaw_applyIdeal(param_0);
    func_8009D89C(param_0, 1.0f);
    _bamotor_entrypoint_1(param_0, 1.0f, 0.5f, 0.5f);
    func_8008E944(param_0);
    func_8009514C(param_0);
    param_0->unk15C.word = 0;
    param_0->unk16C = 600.0f;
    func_808000B0_bscrashout(param_0, 1);
}

void bscrashout_entrypoint_2(PlayerState *param_0)
{
    s32 local_0 = 0;
    func_800F1574(&param_0->unk16C, func_800D8FF8() * 300.0f);
    baphysics_set_target_horizontal_velocity(param_0, *(f32 *)&param_0->unk16C);
    switch (param_0->unk15C.word) {
    case 1:
        func_80800000_bscrashout(param_0);
        if (baanim_isAt(param_0, 0.2f) && !func_800A1718(param_0)) func_808000B0_bscrashout(param_0, 3);
        if (baanim_isStopped(param_0)) func_808000B0_bscrashout(param_0, 2);
        break;
    case 2:
        if (baanim_isStopped(param_0)) local_0 = 1;
        break;
    case 3:
        func_80800000_bscrashout(param_0);
        if (_batimer_decrement(param_0, 0)) _basudie_entrypoint_0(param_0);
        break;
    }
    bs_setState(param_0, local_0);
}

int bscrashout_entrypoint_3(s32 param_0)
{
  return D_808003D0_bscrashout[param_0];
}
