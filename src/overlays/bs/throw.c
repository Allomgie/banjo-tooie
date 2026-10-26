#include "common.h"

extern void anctrl_reset(void *local_0);
extern void anctrl_setIndex(void *local_0, int index);
extern void anctrl_setDuration(void *local_0, float duration);
extern void anctrl_setPlaybackType(void *local_0, int type);
extern void anctrl_start(void *local_0);
extern void func_8008CA4C(void *param_0, int arg1);
extern void yaw_setUpdateType(void *param_0, int type);
extern void func_8009D2D8(void *param_0, int arg1);
extern void baphysics_set_type(void *param_0, int type);
extern void baphysics_set_target_horizontal_velocity(void *param_0, float velocity);
extern void func_8009BA9C(void *param_0, int arg1);
extern void *baanim_getAnimCtrlPtr();
extern void *_bahold_entrypoint_5(void *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern void yaw_setIdeal(void *, f32);
extern s32 anctrl_isAt(void *, f32);
extern Actor *func_80106790(void *);
extern s32 D_808002F0_bsthrow[];

void bsthrow_entrypoint_0(Actor *param_0)
{
    void *local_0;
    
    local_0 = baanim_getAnimCtrlPtr();
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x11B);
    anctrl_setDuration(local_0, 1.0f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8008CA4C(param_0, 1);
    yaw_setUpdateType(param_0, 1);
    func_8009D2D8(param_0, 3);
    baphysics_set_type(param_0, 3);
    baphysics_set_target_horizontal_velocity(param_0, 0);
    func_8009BA9C(param_0, 0);
    *(int *)((char *)param_0 + 0x15c) = 0;
}

void bsthrow_entrypoint_1(void *param_0)
{
    s32 local_0;
    void *local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;
    void *local_5;

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    local_5 = _bahold_entrypoint_5(param_0);
    if (*(s32 *)((u8 *)param_0 + 0x15C) == 0 && local_5 != NULL) {
        _bahold_entrypoint_6(param_0, local_5);
    }
    func_8009C128(param_0, local_3);
    func_800A33CC(param_0, local_2);
    func_800F1E6C(local_3, local_2, &local_4);
    yaw_setIdeal(param_0, local_4);
    if (anctrl_isAt(local_1, 0.35f) && local_5 != NULL) {
        *(s32 *)((u8 *)param_0 + 0x15C) = 1;
        func_80106790(local_5)->unk64_22 = 1;
    }
    if (anctrl_isStopped(local_1)) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

void bsthrow_entrypoint_2(u8 *param_0)
{
  if (!param_0)
  {
  }
 *((s32 *) (((s8 *) param_0) + 0x15C)) = 0; if (bs_getNextState() == 1) {
    bastatetimer_set(param_0, 0, 0x3E0F5C29);
    bastatetimer_set(param_0, 1, 0x3E8F5C29);
  }
}

int bsthrow_entrypoint_3(s32 param_0)
{
  return D_808002F0_bsthrow[param_0];
}

void bsthrow_entrypoint_4(u8 *param_0) {
    s32 local_0;

    local_0 = func_8009E6EC();
    switch (local_0) {
    case 18:
        if ((*(s32 *)((s8 *)(param_0) + (0x15C))) == 0) {
            func_8008F6B8(param_0, func_8008E9AC(param_0));
            return;
        }
        func_8009E830(param_0, 1);
        return;
    case 21: ;
    case 28:
    case 29: ;
    case 30:
    case 37:
        func_8009E830(param_0, 1);
        return;
    default:
        func_80099B94(param_0);
        return;
    }
}
