#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/anim.h"
#include "core2/physics.h"
#include "overlays/ba/yaw.h"
#include "overlays/ba/timer.h"
extern f32 mlAbsF(f32);
extern void baphysics_set_target_horizontal_velocity(Actor *, f32);
void baphysics_set_target_yaw(PlayerState *, f32 target_yaw);

extern s32 D_80800990_bscrouch[];
extern void * _bapackctrl_entrypoint_1(PlayerState *);
extern void func_8009C128(PlayerState *, f32 *);
extern s32 func_800CB7C4(void *, f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 bakey_released(PlayerState *, s32);
extern s32 bakey_pressed(PlayerState *, s32);
extern s32 func_800A055C(PlayerState *, s32);
extern s32 bs_getTypeOfJump(PlayerState *);
extern s32 func_8008E23C(PlayerState *);
extern s32 func_800C6E38(s32);
extern s32 func_8008E0C8(PlayerState *);
extern s32 bainput_should_wonderwing(PlayerState *);
extern void _suinv_entrypoint_0(s32 *, s32, s32, s32, s32);
extern s32 bainput_should_trot(PlayerState *);
extern s32 bainput_should_poop_egg(PlayerState *);
extern s32 func_80094B14(PlayerState *);
extern s32 bainput_should_shoot_egg(PlayerState *);
extern s32 bainput_should_flap_flip(PlayerState *);
extern s32 bainput_should_beak_barge(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800F1EA4(f32 *, f32 *);
extern void func_8009CFD8(PlayerState *, f32);
extern void _badust_entrypoint_9(PlayerState *);
extern void func_8009D658(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern s32 func_8008E148(PlayerState *);
extern s32 _badrone_entrypoint_25(PlayerState *);
extern s32 func_8008DD04(PlayerState *);
extern s32 player_inWater(PlayerState *);
extern void bs_setState(PlayerState *, s32);

void func_80800000_bscrouch(void *param_0) {
    baanim_playForDuration_loopSmooth(param_0, 0x10C, 0.5f);
    *(s32 *)((char *)param_0 + 0x15C) = 4;
}

void func_80800034_bscrouch(void *param_0)
{
  baanim_playForDuration_onceSmooth(param_0, 0x116, 2.0f);
  *((s32 *) (((char *) param_0) + 0x15c)) = 2;
}

void func_80800068_bscrouch(Actor *param_0)
{
  baanim_playForDuration_onceSmoothStartingAt(param_0, 0x10C, 0.5f, 0.9999f);
  _batimer_set(param_0, 2, 2.0f);
  *(int *)((char *)param_0 + 0x15C) = 1;
}

void func_808000B4_bscrouch(s32 param_0, f32 param_1) {
    anctrl_setDuration(param_0, func_800F10B4(param_1, 0.0f, 180.0f, 0.5f, 0.2f));
}

int func_808000FC_bscrouch(s32 param_0, s32 param_1)
{
  func_800A2CE8(param_0, 0x3ED1EB85, 4);
  func_800A2CE8(param_0, 0x3F68F5C3, 3);
}

void bscrouch_entrypoint_0(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_1[3];
    f32 local_2;
    f32 local_3;
    s32 local_4;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_4 = bs_getPreviousState(param_0);
    if (local_4 != 9 && local_4 != 0xA && local_4 != 0x1A) local_2 = 0.0f;
    else local_2 = 0.5357f;
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 1);
    anctrl_setDuration(local_0, 0.5f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_setStart(local_0, local_2);
    anctrl_start(local_0);
    func_8008CA4C(param_0, 1);
    yaw_setUpdateType(param_0, 3);
    yaw_setVelocityBounded(param_0, 350.0f, 14.0f);
    func_8009D2D8(param_0, 7);
    func_8009CFD8(param_0, 8.0f);
    baphysics_set_type(param_0, 3);
    _batimer_set(param_0, 0, 0.7f);
    _batimer_set(param_0, 1, 0.2f);
    func_8009BB24(param_0, local_1);
    param_0->unk16C = sqrtf(local_1[0] * local_1[0] + local_1[2] * local_1[2]);
    if (param_0->unk16C > 140.0f) func_8009D658(param_0);
    if (func_800F1EA4(local_1, &local_3)) baphysics_set_target_yaw(param_0, local_3);
    param_0->unk15C.word = 0;
}

s32 bscrouch_entrypoint_4();

void bscrouch_entrypoint_1(PlayerState *this)
{
    s32 next;
    f32 sp30;
    AnimCtrl *aCtrl;
    f32 temp_f2;
    f32 pad;
    f32 sp20;

    next = 0;
    aCtrl = baanim_getAnimCtrlPtr(this);
    _batimer_decrement(this, 0);
    _batimer_decrement(this, 1);
    sp30 = func_800F10B4(_batimer_get(this, 0), 0.0f, 0.3f, 0.0f, this->unk16C);
    baphysics_set_target_horizontal_velocity(this, sp30);
    if (220.0f < sp30)
        _badust_entrypoint_9(this);
    if (160.0f < sp30)
        func_8009D658(this);
    if (bastick_distance(this) == 0.0f)
        yaw_setIdeal(this, yaw_get(this));
    sp20 = yaw_getIdeal(this);
    temp_f2 = mlAbsF(func_800F1DCC(sp20, yaw_get(this)));

    switch (this->unk15C.word) {
    case 0:
        if (sp30 != 0.0f)
            break;
        _batimer_set(this, 2, 2.0f);
        this->unk15C.word = 1;
        break;

    case 1:
        if (temp_f2 != 0.0f) {
            func_80800000_bscrouch(this);
        } else {
            _batimer_decrement(this, 2);
            if (_batimer_isZero(this, 2))
                func_80800034_bscrouch(this);
        }
        break;

    case 2:
        if (temp_f2 != 0.0f) {
            func_80800000_bscrouch(this);
        } else {
            if (anctrl_isStopped(aCtrl))
                func_80800068_bscrouch(this);
        }
        break;

    case 4:
        func_808000B4_bscrouch(aCtrl, temp_f2);
        func_808000FC_bscrouch(this, aCtrl);
        if (temp_f2 != 0.0f)
            break;
        if (anctrl_getAnimTimer(aCtrl) <= 0.5f) {
            anctrl_setSubrange(aCtrl, 0, 0.5f);
        } else {
            anctrl_setSubrange(aCtrl, 0, 1.0f);
        }
        anctrl_setPlaybackType(aCtrl, 1);
        this->unk15C.word = 3;
        break;

    case 3:
        func_808000B4_bscrouch(aCtrl, temp_f2);
        func_808000FC_bscrouch(this, aCtrl);
        if (temp_f2 != 0.0f) {
            anctrl_setSubrange(aCtrl, 0, 1.0f);
            anctrl_setPlaybackType(aCtrl, 2);
            this->unk15C.word = 4;
        } else {
            if (anctrl_isStopped(aCtrl)) {
                yaw_setIdeal(this, yaw_get(this));
                func_80800068_bscrouch(this);
            }
        }
        break;
    }

    if (func_8008E148(this))
        next = _badrone_entrypoint_25(this);
    if (func_8008DD04(this))
        next = 0x2F;
    next = bscrouch_entrypoint_4(this, next);
    if (next == 1 && _batimer_isNonzero(this, 1))
        next = 0;
    if (player_inWater(this))
        next = 0x2D;
    bs_setState(this, next);
}

void bscrouch_entrypoint_2(s32 arg0) 
{
}
int bscrouch_entrypoint_3(s32 param_0)
{
  return D_80800990_bscrouch[param_0];
}

s32 func_808006A4_bscrouch(PlayerState *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    void *local_2;
    s32 local_3;

    local_2 = _bapackctrl_entrypoint_1(param_0);
    func_8009C128(param_0, local_0);
    local_3 = func_800CB7C4(local_2, local_0, local_1);
    if (local_3 == 2) {
        yaw_setIdeal(param_0, func_800F1DF4(local_0, local_1));
    }
    return local_3;
}

s32 bscrouch_entrypoint_4(PlayerState *this, s32 next)
{
    if (bakey_released(this, 1)) {
        next = 1;
        if (bakey_pressed(this, 9)) {
            next = func_800A055C(this, next);
        }
        if (bakey_pressed(this, 8)) {
            next = bs_getTypeOfJump(this);
        }
        return next;
    }
    if (func_8008E23C(this)) {
        if (bakey_pressed(this, 0xB) && func_800C6E38(0x21)) {
            next = 0x16A;
        } else if (bakey_pressed(this, 0xC) && func_800C6E38(0x2A)) {
            next = 0x163;
        } else if (bakey_pressed(this, 0xD) && func_800C6E38(0x23)) {
            next = 0x171;
        } else if (bakey_pressed(this, 0xA) && func_800C6E38(0x27)) {
            if (!func_8008E0C8(this)) {
                next = 0x122;
            } else {
                switch (func_808006A4_bscrouch(this)) {
                case 0:
                    break;
                case 1:
                    next = 0x129;
                    break;
                case 2:
                    next = 0x128;
                    break;
                }
            }
        }
        if (bakey_pressed(this, 8)) {
            next = 0x6C;
        }
        return next;
    } else {
        if (bainput_should_wonderwing(this)) {
            _suinv_entrypoint_0(&next, -1, 0x1A, 0x47, 1);
        }
        if (bainput_should_trot(this)) {
            next = 0x14;
        }
        if (bainput_should_poop_egg(this) && func_80094B14(this)) {
            next = 0xA;
        }
        if (bainput_should_shoot_egg(this) && func_80094B14(this)) {
            next = 9;
        }
        if (bainput_should_flap_flip(this)) {
            next = 0x12;
        }
        if (bainput_should_beak_barge(this)) {
            next = 0x13;
        }
    }
    return next;
}
