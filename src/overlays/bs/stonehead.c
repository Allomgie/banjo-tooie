#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/anctrl.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void baanim_setEnd(PlayerState *, f32);
extern void func_8009DF94(PlayerState *, s32, f32, s32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
typedef struct { f32 local_1; f32 local_3; s32 local_4; AnimCtrl *local_0; } StoneMotion61;
extern s32 bakey_pressed(PlayerState *, s32);
extern s32 func_800DA298(s32);
extern s32 D_80801630_bsstonehead[];
extern void _basudie_entrypoint_2(PlayerState *, f32, f32, f32);
extern void func_8009D820(PlayerState *, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern f32 func_800F0E00(f32, f32);
extern s32 D_80801640_bsstonehead[];
extern s32 D_80801650_bsstonehead[];
extern int func_8008DF8C(void *param_0, int param_1);
extern int func_8009D3A8(void *param_0, int param_1);
extern int baanim_isStopped(void *param_0);
extern int player_isStable(void *param_0);
extern void bs_setState(void *param_0, int param_1);
extern s32 D_80801660_bsstonehead[];
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 D_80801670_bsstonehead[];
extern s32 D_80801680_bsstonehead[];
extern s32 D_80801690_bsstonehead[];
extern s32 D_808016A0_bsstonehead[];
extern s32 D_808016B0_bsstonehead[];
extern f32 _batimer_get(PlayerState *, s32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 D_808016C0_bsstonehead[];
extern s32 D_808016D0_bsstonehead[];
extern s32 func_800F1574(f32 *, f32);
extern f32 baanim_getTimer(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern void anctrl_setDuration(AnimCtrl *, f32);
extern void anctrl_setSubrange(AnimCtrl *, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopStartingAt(PlayerState *, s32, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_800909CC(PlayerState *);
void func_80800B38_bsstonehead();

void func_80800000_bsstonehead(param_0) s32 param_0; {
    if (func_8009E74C(param_0, 3) == 0) {
        func_800947EC(param_0, 1, 0);
        func_80095A40(param_0);
        func_80092864(param_0, 0x3F800000);
        func_80095A74(param_0, 0);
    }
}

int func_80800060_bsstonehead(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = param_0 | 0;
  if (!func_8009E77C(local_0, 3))
  {
    func_800959C8(local_0, 0x42820000, 0x420C0000);
    func_80092864(local_0, 0x3F666600);
    func_800947EC(local_0, 1, 1);
    func_80095A74(local_0, 1);
  }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_808000CC_bsstonehead(PlayerState *param_0)
{
    f32 local_0;
    f32 local_1;

    local_0 = bastick_getZonePosition(param_0);
    if (_baattach_entrypoint_1(param_0)) local_1 = 250.0f;
    else if (func_8008DE24(param_0) && player_isStable(param_0)) local_1 = 80.0f;
    else local_1 = 400.0f;
    if (!bastick_getZone(param_0)) baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    else baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, local_1));
}

void func_80800194_bsstonehead(PlayerState *param_0, s32 param_1)
{
    StoneMotion61 local_2;
    local_2.local_4 = param_1;

    local_2.local_0 = baanim_getAnimCtrlPtr(param_0);
    if (param_0->unk15C.word == 0) {
        func_80800060_bsstonehead(param_0, local_2.local_4);
    }
    param_0->unk15C.word = local_2.local_4;
    switch (local_2.local_4) {
    case 1:
        if (func_8008DE24(param_0) && player_isStable(param_0)) {
            param_0->unk16C = 150.0f;
        } else {
            param_0->unk16C = 600.0f;
        }
        func_8009DF94(param_0, 0x5A7, 1.4f, 22000);
        baflag_set(param_0, 0x20);
        _batimer_set(param_0, 0, 0x3C23D70A);
        func_8009FFD8(param_0, 1, 1, 3, 3);
        _badust_entrypoint_12(param_0, 2);
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
        local_2.local_1 = yaw_getIdeal(param_0);
        local_2.local_3 = baphysics_get_target_horizontal_velocity(param_0);
        baphysics_set_horizontal_velocity(param_0, local_2.local_1, local_2.local_3);
        anctrl_reset(local_2.local_0);
        anctrl_setIndex(local_2.local_0, 0x64);
        anctrl_setDuration(local_2.local_0, 1.0f);
        anctrl_setSubrange(local_2.local_0, 0.0f, 0.26f);
        anctrl_setPlaybackType(local_2.local_0, 1);
        anctrl_start(local_2.local_0);
        return;
    case 2:
        anctrl_setDuration(local_2.local_0, 5.0f);
        baanim_setEnd(param_0, 0.3078f);
        return;
    case 3:
        _badust_entrypoint_12(param_0, 1);
        baflag_clear(param_0, 0x20);
        anctrl_setDuration(local_2.local_0, 1.0f);
        baanim_setEnd(param_0, 1.0f);
        return;
    case 0:
        _badust_entrypoint_12(param_0, 1);
        baflag_clear(param_0, 0x20);
        func_80800000_bsstonehead(param_0);
        return;
    }
}

int func_808003B8_bsstonehead(PlayerState *param_0)
{
    return (bakey_pressed(param_0, 8) != 0) && (func_800DA298(0x65A) == 0);
}

s32 func_808003F4_bsstonehead(PlayerState *param_0, s32 param_1)
{
    if (bainput_should_enter_first_person(param_0)) {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (bastick_getZone(param_0) > 0) {
        param_1 = 0xB2;
    }
    if (func_808003B8_bsstonehead(param_0)) {
        param_1 = 0xAE;
    }
    return param_1;
}

void bsstonehead_entrypoint_0(s32 arg0)
{
    func_80800194_bsstonehead(arg0,0);
}

void bsstonehead_entrypoint_1(u8 *param_0) {
    (*(s32 *)((s8 *)(param_0) + (0x15C))) = 0;
    func_80800194_bsstonehead(param_0, 1);
}

void bsstonehead_entrypoint_2(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    switch (param_0->unk15C.word) {
        case 1:
            if (baanim_isStopped(param_0)) {
                func_80800194_bsstonehead(param_0, 2);
            }
            break;
        case 2:
            _batimer_decrement(param_0, 0);
            if (_batimer_isZero(param_0, 0)) {
                param_0->unk16C -= 80.0f;
                baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
                if (param_0->unk16C < 200.0f) {
                    func_80800194_bsstonehead(param_0, 3);
                }
            }
            break;
        case 3:
            func_800F1574(&param_0->unk16C, 0.8f);
            if (baanim_isStopped(param_0)) {
                local_0 = 0xB3;
            }
            if (baanim_getTimer(param_0) > 0.8f) {
                local_0 = func_808003F4_bsstonehead(param_0, local_0);
            }
            break;
    }
    bs_setState(param_0, local_0);
}

int bsstonehead_entrypoint_3(s32 param_0)
{
  return D_80801630_bsstonehead[param_0];
}

void func_808005F0_bsstonehead(PlayerState *param_0, s32 param_1)
{
    AnimCtrl *local_0;

    switch (param_1) {
        case 1:
            local_0 = baanim_getAnimCtrlPtr(param_0);
            param_0->unk16C = 250.0f;
            _basudie_entrypoint_2(param_0, 250.0f, 420.0f, -1200.0f);
            anctrl_reset(local_0);
            anctrl_setSmoothTransition(local_0, 0);
            anctrl_setIndex(local_0, 0x33);
            anctrl_setSubrange(local_0, 0, 0.46f);
            anctrl_setDuration(local_0, 2.5f);
            anctrl_setPlaybackType(local_0, 1);
            anctrl_start(local_0);
            func_8009D820(param_0, 1.8f);
            break;
        case 2:
            baanim_setEnd(param_0, 1.0f);
            func_8009DF94(param_0, 0x417, 0.8f, 0x4650);
            func_8009DF18(param_0, 0x428, 1.8f, 0x4650);
            break;
        case 3:
        default:
            break;
    }
    param_0->unk15C.word = param_1;
}

void bsstonehead_entrypoint_4(Actor *param_0)
{
    func_80800060_bsstonehead();
    *(int *)((char *)param_0 + 0x15c) = 0;
    func_808005F0_bsstonehead(param_0, 1);
}

void bsstonehead_entrypoint_5(PlayerState *param_0)
{
    _basudie_entrypoint_5(param_0);
    baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
    switch (param_0->unk15C.word) {
    case 1:
        if (player_isStable(param_0)) func_808005F0_bsstonehead(param_0, 2);
        break;
    case 2:
        func_808005F0_bsstonehead(param_0, 3);
        break;
    case 3:
        if (param_0->unk16C > 0.0f) param_0->unk16C = func_800F0E00(0.0f, param_0->unk16C - 10.0f);
        break;
    }
    bs_setState(param_0, 0);
}

void bsstonehead_entrypoint_6()
{
    _basudie_entrypoint_6();
}

int bsstonehead_entrypoint_7(s32 param_0)
{
  return D_80801640_bsstonehead[param_0];
}

void bsstonehead_entrypoint_8(s32 arg0)
{
    func_80800060_bsstonehead();
    _bsdrone_entrypoint_0(arg0);
}
void bsstonehead_entrypoint_9(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstonehead_entrypoint_10(s32 arg0)
{
    func_80800000_bsstonehead();
    _bsdrone_entrypoint_2(arg0);
}
int bsstonehead_entrypoint_11(s32 param_0)
{
  return D_80801650_bsstonehead[param_0];
}

void func_808008CC_bsstonehead(Actor *param_0, s32 param_1)
{
  s32 temp_v0;
  switch (param_1)
  {
    case 0:
      break;

    case 1:
      temp_v0 = baanim_getAnimCtrlPtr(param_0);
      anctrl_reset((void *) temp_v0);
      anctrl_setIndex((void *) temp_v0, 0x122);
      anctrl_setStart((void *) temp_v0, 0.6364f);
      anctrl_setSubrange((void *) temp_v0, 0.6364f, 0.7576f);
      anctrl_setDuration((void *) temp_v0, 4.0f);
      anctrl_setPlaybackType((void *) temp_v0, 1);
      anctrl_start((void *) temp_v0);
      func_8009FFD8(param_0, 1, 1, 3, 6);
      break;

    case 2:
      baanim_setEndAndDuration(param_0, 1.0f, 0.8f);
      break;

    case 3:
      func_800A2E18(param_0);
      baphysics_set_target_horizontal_velocity(param_0, (double) 0);
      break;

  }

  *((s32 *) (((char *) param_0) + 0x15C)) = param_1;
}

void bsstonehead_entrypoint_12(s32 arg0)
{
    func_808008CC_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_13(Actor *param_0)
{
    func_80800060_bsstonehead();
    *(s32 *)((char *)param_0 + 0x15c) = 1;
    func_808008CC_bsstonehead(param_0, 1);
}

int bsstonehead_entrypoint_14(void *param_0)
{
  s32 local_0;
  char *new_var;
  local_0 = 0;
  func_808000CC_bsstonehead(param_0);
 do { func_8009D3A8(param_0, 0); new_var = ((char *) param_0) + 0x15c; } while (0);
  switch (*((s32 *) new_var))
  {
    case 1:
      if (func_8008DF8C(param_0, 0x82))
    {
      func_808008CC_bsstonehead(param_0, 2);
    }
      break;

    case 2:
      if (player_isStable(param_0))
    {
      func_808008CC_bsstonehead(param_0, 3);
    }
      break;

    case 3:
      if (baanim_isStopped(param_0))
    {
      local_0 = 0xB3;
    }

  }

  if (player_isStable(param_0))
  {
    local_0 = func_808003F4_bsstonehead(param_0, local_0);
  }
  bs_setState(param_0, local_0);
}

int bsstonehead_entrypoint_15(s32 param_0)
{
  return D_80801660_bsstonehead[param_0];
}

void func_80800B38_bsstonehead(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    AnimCtrl *local_0;
    f32 local_2;
    f32 local_1;

    switch (param_1) {
    case 0:
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        baphysics_reset_gravity(param_0);
        break;
    case 1:
        local_0 = baanim_getAnimCtrlPtr(param_0);
        _baattach_entrypoint_6(param_0, 3, 0, 0);
        anctrl_reset(local_0);
        anctrl_setIndex(local_0, 0x122);
        anctrl_setDuration(local_0, 0.8f);
        anctrl_setSubrange(local_0, 0.0f, 0.636399984360f);
        anctrl_setPlaybackType(local_0, 1);
        anctrl_start(local_0);
        func_8009FFD8(param_0, 1, 1, 3, 6);
        if (0.0f != bastick_distance(param_0)) {
            local_2 = bastick_getAngleRelativeToBanjo(param_0);
            yaw_setIdeal(param_0, local_2);
        }
        baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
        func_808000CC_bsstonehead(param_0);
        local_1 = yaw_getIdeal(param_0);
        baphysics_set_horizontal_velocity(param_0, local_1, baphysics_get_target_horizontal_velocity(param_0));
        baphysics_set_vertical_velocity(param_0, 576.0f);
        baphysics_set_gravity(param_0, -1200.0f);
        func_8009D7A4(param_0, 1.35f, 1.45f);
        break;
    case 2:
        baanim_setEndAndDuration(param_0, 0.757600009441f, 4.0f);
        break;
    case 3:
        baanim_setEndAndDuration(param_0, 1.0f, 0.8f);
        break;
    case 4:
        func_800A2E18(param_0);
        break;
    }
    param_0->unk15C.word = param_1;
}

void bsstonehead_entrypoint_16(s32 arg0)
{
    func_80800B38_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

void bsstonehead_entrypoint_17(Actor *param_0)
{
    int local_0;

    local_0 = 0;
    func_80800060_bsstonehead();
    *(int *)((char *)param_0 + 0x15c) = 0;
    func_80800B38_bsstonehead(param_0, 1);
    return;
}

void bsstonehead_entrypoint_18(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_808000CC_bsstonehead(param_0);
    if (bakey_released(param_0, 8) && baphysics_get_vertical_velocity(param_0) > 0.0f) {
        baphysics_reset_gravity(param_0);
    }
    switch (param_0->unk15C.word) {
    case 1:
        if (func_8008DF8C(param_0, 0x82)) func_80800B38_bsstonehead(param_0, 3);
        else if (baanim_isStopped(param_0)) func_80800B38_bsstonehead(param_0, 2);
        break;
    case 2:
        if (func_8008DF8C(param_0, 0x82)) func_80800B38_bsstonehead(param_0, 3);
        break;
    case 3:
        func_8009D3A8(param_0, 0);
        if (player_isStable(param_0)) func_80800B38_bsstonehead(param_0, 4);
        break;
    case 4:
        func_8009D3A8(param_0, 0);
        if (baanim_isStopped(param_0)) local_0 = 0xB3;
        break;
    }
    if (player_isStable(param_0)) local_0 = func_808003F4_bsstonehead(param_0, local_0);
    bs_setState(param_0, local_0);
}

int bsstonehead_entrypoint_19(s32 param_0)
{
  return D_80801670_bsstonehead[param_0];
}

void bsstonehead_entrypoint_20(PlayerState *param_0)
{
    func_80800060_bsstonehead(param_0);
    baanim_playForDuration_loopStartingAt(param_0, 0x62, 0.8f, 0.4f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    func_8008C9F0(param_0, 30.0f, 400.0f, 1.0f, 0.45f);
    func_800909CC(param_0);
}

void bsstonehead_entrypoint_21(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    func_8009D3A8(param_0, 0);
    func_808000CC_bsstonehead(param_0);
    func_800A2CE8(param_0, 0x3DCCCCCD, 4);
    func_800A2CE8(param_0, 0x3F19999A, 3);
    if ((bastick_getZone(param_0) == 0) && (func_8009BCD4(param_0, 0x3F800000) != 0)) {
        local_0 = 0xB3;
    }
    if (func_8008E148(param_0) != 0) {
        local_0 = _badrone_entrypoint_25(param_0);
    }
    if (func_8008DD04(param_0) != 0) {
        local_0 = 0xAD;
    }
    if (func_808003B8_bsstonehead(param_0) != 0) {
        local_0 = 0xAE;
    }
    if (bakey_pressed(param_0, 9) != 0) {
        local_0 = 0xB4;
    }
    if (bakey_newlyReleased(param_0, 1) != 0) {
        _baattach_entrypoint_6(param_0, 1, bakey_func_80091940(param_0, 1, 1), 0);
    }
    bs_setState(param_0, local_0);
}

void bsstonehead_entrypoint_22(s32 arg0)
{
    func_80800000_bsstonehead();
    func_80090A2C(arg0);
}
int bsstonehead_entrypoint_23(s32 param_0)
{
  return D_80801680_bsstonehead[param_0];
}

void bsstonehead_entrypoint_24(s32 arg0)
{
    _baspin_entrypoint_1();
    func_80800000_bsstonehead(arg0);
}
int bsstonehead_entrypoint_25(Actor *param_0)
{
  func_80800060_bsstonehead();
  _baattach_entrypoint_6(param_0, 3, 0, 0);
  _baspin_entrypoint_2(param_0, 99, 0x3FE66666, 2, 0);
}

int bsstonehead_entrypoint_26(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_baspin_entrypoint_3(param_0) == 2)
  {
    local_0 = 0xB3;
  }
  bs_setState(param_0, local_0);
}

int bsstonehead_entrypoint_27(s32 param_0)
{
  return D_80801690_bsstonehead[param_0];
}

void bsstonehead_entrypoint_28(s32 arg0)
{
    _babounce_entrypoint_3();
    func_80800000_bsstonehead(arg0);
}
int bsstonehead_entrypoint_29(Actor *param_0)
{
  func_80800060_bsstonehead();
  _baattach_entrypoint_6(param_0, 3, 0, 0);
  _babounce_entrypoint_4(param_0, 2);
  _babounce_entrypoint_5(param_0, 0x122, 0x3F4075F7);
}

s32 bsstonehead_entrypoint_30(s32 param_0){
    s32 local_0 = 0;
    if(_babounce_entrypoint_2(param_0)){
        func_808000CC_bsstonehead(param_0);
    }
    if(_babounce_entrypoint_9(param_0)){
        local_0 = 0xB3;
    }
    bs_setState(param_0, local_0);
}

int bsstonehead_entrypoint_31(s32 param_0)
{
  return D_808016A0_bsstonehead[param_0];
}

void bsstonehead_entrypoint_32(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_33(s32 arg0)
{
    func_80800060_bsstonehead();
    _bsrest_entrypoint_16(arg0);
}
s32 bsstonehead_entrypoint_34(Actor *this){
    s32 next_state = 0;
    if(_bsrest_entrypoint_20(this))
        next_state = _bsrest_entrypoint_13(this);
    
    bs_setState(this, next_state);
}

int bsstonehead_entrypoint_35(s32 param_0)
{
  return D_808016B0_bsstonehead[param_0];
}

void bsstonehead_entrypoint_36()
{
    func_80800000_bsstonehead();
}

int bsstonehead_entrypoint_37(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  local_0 = param_0;
  func_80800060_bsstonehead(param_0);
  baanim_playForDuration_loopSmooth(local_0, 0x63, 6.1f);
  func_8009FFD8(local_0, 1, 1, 3, 3);
  baphysics_set_target_horizontal_velocity(local_0, 0);
  _batimer_set(local_0, 1, 0x40400000);
}

void bsstonehead_entrypoint_38(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;

    local_0 = 0;
    local_2 = func_800F10B4(_batimer_get(param_0, 1), 0.0f, 3.0f, 30.0f, 800.0f);
    local_1 = func_800D8FF8() * local_2;
    yaw_setIdeal(param_0, yaw_getIdeal(param_0) + local_1);
    yaw_applyIdeal(param_0);
    if (_batimer_decrement(param_0, 1)) {
        local_0 = 0xB3;
    }
    bs_setState(param_0, local_0);
}

int bsstonehead_entrypoint_39(s32 param_0)
{
  return D_808016C0_bsstonehead[param_0];
}

void bsstonehead_entrypoint_40(s32 arg0)
{
    func_80800000_bsstonehead();
    func_80090A2C(arg0);
}
int bsstonehead_entrypoint_41(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  local_0 = param_0;
  func_80800060_bsstonehead(param_0);
  baanim_playForDuration_loopSmooth(local_0, 0x63, 6.1f);
  func_8009FFD8(local_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(local_0, 0x0);
  func_800909CC(local_0);
}

void bsstonehead_entrypoint_42(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    if (func_8008DD04(param_0)) local_0 = 0xAD;
    local_0 = func_808003F4_bsstonehead(param_0, local_0);
    if (func_8008E148(param_0)) local_0 = _badrone_entrypoint_25(param_0);
    if (bakey_pressed(param_0, 9)) local_0 = 0xB4;
    if (bakey_newlyReleased(param_0, 1)) {
        _baattach_entrypoint_6(param_0, 1, bakey_func_80091940(param_0, 1, 1), 0);
    }
    if (bainput_should_enter_first_person(param_0)) local_0 = _badrone_entrypoint_24(param_0);
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

int bsstonehead_entrypoint_43(s32 param_0)
{
  return D_808016D0_bsstonehead[param_0];
}
