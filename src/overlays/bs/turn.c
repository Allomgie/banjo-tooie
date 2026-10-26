#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern f32 yaw_get(s32);
extern f32 func_800136E4(f32);
extern void yaw_set(s32, f32);
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80800360_bsturn[];
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 anctrl_getAnimTimer(AnimCtrl *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8009BB18(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern void _badust_entrypoint_3(PlayerState *, f32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);

void bsturn_entrypoint_0(void *param_0)
{
    void *local_2;
    float local_0[3];

    local_2 = baanim_getAnimCtrlPtr();
    anctrl_reset(local_2);
    anctrl_setIndex(local_2, 0xE);
    anctrl_setDuration(local_2, 0.3f);
    func_8008B1C8(local_2, 0.1f);
    anctrl_setPlaybackType(local_2, 1);
    anctrl_start(local_2);
    func_8008CA4C(param_0, 1);
    yaw_setUpdateType(param_0, 1);
    func_8009D2D8(param_0, 2);
    baphysics_set_type(param_0, 3);
    func_8009BB24(param_0, local_0);
    *(float *)((char *)param_0 + 0x16C) = sqrtf((local_0[0] * local_0[0]) + (local_0[2] * local_0[2]));
    func_8009DEC0(param_0, 0x411, 0x3F733333, 0x3F866666, 0x7530, 0x7D00);
    *(int *)((char *)param_0 + 0x15C) = 0;
}

void bsturn_entrypoint_1(PlayerState *param_0)
{
    s32 local_0 = 0;

    baphysics_set_target_horizontal_velocity(param_0,
        func_800F10B4(anctrl_getAnimTimer(baanim_getAnimCtrlPtr(param_0)),
            0.18f, 1.0f, param_0->unk16C, 0.0f));
    param_0->unk15C.word++;
    if (!((s32)param_0->unk15C.word < 6)) {
        param_0->unk15C.word = -1;
    }
    switch ((s32)param_0->unk15C.word) {
    case -1:
        _badust_entrypoint_3(param_0, func_8009BB18(param_0) - 10.0f, func_8009BB5C(param_0) * 0.88f);
        break;
    case 0:
        _badust_entrypoint_3(param_0, func_8009BB18(param_0), func_8009BB5C(param_0));
        break;
    case 1:
        _badust_entrypoint_3(param_0, func_8009BB18(param_0) + 10.0f, func_8009BB5C(param_0) * 0.88f);
        break;
    }
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(param_0))) local_0 = 4;
    if (bakey_held(param_0, 1)) local_0 = 7;
    if (bakey_pressed(param_0, 9)) local_0 = func_800A055C(param_0, local_0);
    if (bakey_pressed(param_0, 8)) local_0 = bs_getTypeOfJump(param_0);
    bs_setState(param_0, local_0);
}

void bsturn_entrypoint_2(s32 param_0) {
    yaw_set(param_0, func_800136E4(yaw_get(param_0) - 180.0f));
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
}

int bsturn_entrypoint_3(s32 param_0)
{
  return D_80800360_bsturn[param_0];
}
