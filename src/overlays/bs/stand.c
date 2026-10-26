#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
void baphysics_set_target_horizontal_velocity(s32, f32);

extern s32 D_80800D90_bsstand[];
extern void func_8009DF58(Actor *, s32, f32);
extern void _bamotor_entrypoint_1(Actor *, f32, f32, f32);
extern void func_8009514C(Actor *);
extern void func_800951B4(Actor *);
extern void func_800909EC(Actor *);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern f32 bastick_distance(PlayerState *);
extern f32 yaw_get(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009DF94(PlayerState *, s32, f32, s32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_80090A2C();
extern void func_800A0CF4();
extern s32 D_80800D98_bsstand[];
extern s32 D_80800DA8_bsstand[];
extern s32 D_80800DB8_bsstand[];

u8 * func_80800000_bsstand(Actor *param_0)
{
  return D_80800D90_bsstand[*(s32 *)((char *)param_0 + 0x160)];
}

s32 func_80800018_bsstand(u8 *param_0, s32 param_1) {
    param_1++;
    if (param_1 >= *(s32 *)(param_0 + 0x164)) {
        param_1 = 0;
    }
    return param_1;
}

s32 func_80800038_bsstand(param_0, param_1) s32 param_0; s32 param_1;
{
  s32 local_0;
  local_0 = param_1;
  switch (bastick_getZone())
  {
    case 1:
      local_0 = 0x1F;
      break;

    case 2:
      local_0 = 2;
      break;

    case 3:
      local_0 = 3;
      break;

    case 4:
      local_0 = 4;
      break;

  }

  if (bakey_held(param_0, 1) != 0)
  {
    local_0 = 7;
  }
  if (bakey_pressed(param_0, 9) != 0)
  {
    local_0 = func_800A055C(param_0, local_0);
  }
  if (bakey_pressed(param_0, 8) != 0)
  {
    local_0 = bs_getTypeOfJump(param_0);
    if (func_8008D714(param_0) != 0)
    {
      local_0 = 0xB8;
      goto block_18;
    }
    if (func_8008D790(param_0) != 0)
    {
      _baduo_entrypoint_12(param_0);
      if (((!param_0) && (!param_0)) && (!param_0))
      {
      }
      return 0;
    }
    goto block_18;
  }
  block_18:
  if (bainput_should_enter_first_person(param_0) != 0)
  {
    local_0 = _badrone_entrypoint_24(param_0);
  }

  if (func_8008E148(param_0) != 0)
  {
    local_0 = _badrone_entrypoint_25(param_0);
  }
  if (player_inWater(param_0) != 0)
  {
    local_0 = 0x2D;
  }
  return func_800A02DC(param_0, local_0);
}

void bsstand_entrypoint_0(u8 *param_0)
{
  s32 local_0;
  int new_var;
  s32 local_1;
  local_1 = bs_getPreviousState();
  local_0 = local_1;
  if (func_8009CBDC(param_0, local_1) == 0xA)
  {
    func_80098840(param_0);
  }
  new_var = 1;
  if (local_0 == 0x5B)
  {
    baanim_playForDuration_once(param_0, 0x6F, 0x40B00000);
  }
  else
  {
    baanim_playForDuration_onceSmooth(param_0, 0x6F, 5.5f);
  }
  func_8009FFD8(param_0, new_var, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0 & 0xFFFFFFFFFFFFFFFFu);
  func_800909CC(param_0);
  if (func_8008E23C(param_0) != 0)
  {
    *((s32 *) (((s8 *) param_0) + 0x160)) = 0;
    *((s32 *) (((s8 *) param_0) + 0x164)) = 6;
  }
  else
  {
    *((s32 *) (((s8 *) param_0) + 0x160)) = 1;
    *((s32 *) (((s8 *) param_0) + 0x164)) = 0x15;
  }
  *((s32 *) (((s8 *) param_0) + 0x15C)) = 0;
  *((s32 *) (((s8 *) param_0) + 0x168)) = 0;
}

void func_80800274_bsstand(Actor *param_0, void *param_1)
{
    if (anctrl_isAt(param_1, 0.2057f)) {
        func_8009DF94(param_0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(param_0, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(param_1, 0.2057f)) {
        func_8009514C(param_0);
    }

    if (anctrl_isAt(param_1, 0.2555f)) {
        func_8009DF94(param_0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(param_0, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(param_1, 0.2896f)) {
        func_8009DF94(param_0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(param_0, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(param_1, 0.3f)) {
        func_8009DF94(param_0, 0x445, 1.0f, 28000);
    }

    if (anctrl_isAt(param_1, 0.3607f)) {
        func_800951B4(param_0);
    }

    if (anctrl_isAt(param_1, 0.4183f)) {
        func_8009DF58(param_0, 0x43EF, 1.6f);
    }

    if (anctrl_isAt(param_1, 0.455f)) {
        func_8009DF58(param_0, 0x43EF, 1.45f);
    }

    if (anctrl_isAt(param_1, 0.49f)) {
        func_8009DF58(param_0, 0x43EF, 1.4f);
    }

    if (anctrl_isAt(param_1, 0.5397f)) {
        func_800909EC(param_0);
    }

    if (anctrl_isAt(param_1, 0.6619f)) {
        func_8009DF94(param_0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(param_0, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(param_1, 0.6688f)) {
        func_8009514C(param_0);
    }

    if (anctrl_isAt(param_1, 0.6964f)) {
        func_8009DF94(param_0, 0x418, 1.8f, 16000);
        _bamotor_entrypoint_1(param_0, 0.5f, 0.25f, 0.4f);
    }

    if (anctrl_isAt(param_1, 0.7747f)) {
        func_800951B4(param_0);
    }

    if (anctrl_isAt(param_1, 0.7822f)) {
        func_8009DF94(param_0, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(param_1, 0.8322f)) {
        func_8009DF94(param_0, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(param_1, 0.8669f)) {
        func_8009DF94(param_0, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(param_1, 0.9048f)) {
        func_8009DF94(param_0, 0x449, 1.0f, 14000);
    }

    if (anctrl_isAt(param_1, 0.9649f)) {
        func_800909EC(param_0);
    }
}

void bsstand_entrypoint_1(PlayerState *param_0)
{
    s32 local_0;
    AnimCtrl *local_1;
    f32 local_2;
    s32 local_3;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (bastick_getZone(param_0) == 0 && bastick_distance(param_0) > 0.0f) {
        param_0->unk168.word = 1;
        yaw_setUpdateType(param_0, 3);
        yaw_setVelocityBounded(param_0, 200.0f, 14.0f);
    } else {
        if (param_0->unk168.word) {
            yaw_setIdeal(param_0, yaw_get(param_0));
        }
        param_0->unk168.word = 0;
        yaw_setUpdateType(param_0, 1);
    }
    local_0 = func_80800038_bsstand(param_0, 0);
    local_3 = func_80800000_bsstand(param_0)[param_0->unk15C.word];
    if (local_3 & 8) {
        if (local_3 & 4) {
            if (anctrl_isAt(local_1, 0.0909f)) {
                func_8009D874(param_0);
            }
            if (anctrl_isAt(local_1, 0.0909f)) {
                func_800A0CF4(param_0, 1);
            }
            if (anctrl_isAt(local_1, 0.6818f)) {
                func_800A0CF4(param_0, 0);
            }
        }
        if (local_3 & 2) {
            if (anctrl_isAt(local_1, 0.7727f)) {
                func_800A0CF4(param_0, 1);
            }
            if (anctrl_isAt(local_1, 0.9999f)) {
                func_800A0CF4(param_0, 0);
            }
        }
    } else if (local_3 & 0x20) {
        if (anctrl_getIndex(local_1) == 0x95) {
            func_80800274_bsstand(param_0, local_1);
            if (anctrl_isAt(local_1, 0.37f)) {
                anctrl_reset(local_1);
                func_8008B1C8(local_1, 0.1f);
                anctrl_setIndex(local_1, 0xF6);
                anctrl_setDuration(local_1, 5.0f);
                anctrl_setPlaybackType(local_1, 1);
                anctrl_start(local_1);
            }
        } else {
            if (anctrl_isAt(local_1, 0.069f)) {
                func_8009DF94(param_0, 0x434, 1.4f, 18000);
            }
            if (anctrl_isAt(local_1, 0.1677f)) {
                func_8009DF94(param_0, 0x4454, 1.0f, 18000);
            }
            if (anctrl_isAt(local_1, 0.2441f)) {
                func_8009DF94(param_0, 0x4454, 1.03f, 18000);
            }
            if (anctrl_isAt(local_1, 0.3141f)) {
                func_8009DF94(param_0, 0x4454, 1.06f, 18000);
            }
            if (anctrl_isAt(local_1, 0.3859f)) {
                func_8009DF94(param_0, 0x4454, 1.5f, 32000);
            }
            if (anctrl_isAt(local_1, 0.414f)) {
                func_8009DF18(param_0, 0x41E, 1.0f, 18000);
            }
            if (anctrl_isAt(local_1, 0.6187f)) {
                func_8009DF94(param_0, 0x445B, 1.7f, 18000);
            }
            if (anctrl_isAt(local_1, 0.7108f)) {
                func_8009DF94(param_0, 0x445B, 1.6f, 18000);
            }
            if (anctrl_isAt(local_1, 0.7927f)) {
                func_8009DF94(param_0, 0x445B, 1.5f, 18000);
            }
        }
    } else if (local_3 & 0x10) {
        func_80800274_bsstand(param_0, local_1);
    }
    if (anctrl_isAt(local_1, 0.9999f)) {
        param_0->unk15C.word = func_80800018_bsstand(param_0, param_0->unk15C.word);
        local_3 = func_80800000_bsstand(param_0)[param_0->unk15C.word];
        if (local_3 & 0x10) {
            baanim_playForDuration_onceSmooth(param_0, 0x95, 5.5f);
            anctrl_start(local_1);
            func_800A0CF4(param_0, 1);
            func_80090A2C(param_0);
        } else if (local_3 & 0x40) {
            baanim_playForDuration_onceSmooth(param_0, 0xAE, 4.3f);
            anctrl_start(local_1);
            func_800A0CF4(param_0, 0);
            func_80090A2C(param_0);
        } else if (local_3 & 0x20) {
            baanim_playForDuration_onceSmooth(param_0, 0x95, 5.5f);
            func_800A0CF4(param_0, 1);
            func_80090A2C(param_0);
        } else if (local_3 & 8) {
            if (anctrl_getIndex(local_1) == 0x6F) {
                local_2 = anctrl_getAnimTimer(local_1);
            } else {
                local_2 = 0.0f;
                func_800909CC(param_0);
            }
            anctrl_reset(local_1);
            anctrl_setIndex(local_1, 0x6F);
            anctrl_setDuration(local_1, 5.5f);
            anctrl_setPlaybackType(local_1, 2);
            anctrl_setStart(local_1, local_2);
            anctrl_start(local_1);
            func_800A0CF4(param_0, 0);
        }
    }
    if (func_8008DD04(param_0)) {
        local_0 = 0x2F;
    }
    bs_setState(param_0, local_0);
}

s32 bsstand_entrypoint_2(Actor *this){
    func_800A0CF4(this, 0);
    func_80090A2C(this);
    func_800951B4(this);
}

int bsstand_entrypoint_3(s32 param_0)
{
  return D_80800D98_bsstand[param_0];
}

void bsstand_entrypoint_4(Actor *param_0)
{
  func_8009FFD8(param_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0 & 0xFFFFFFFFFFFFFFFF);
  return;
}

void bsstand_entrypoint_5(s32 param_0) {
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    sp24 = 0;
    temp_v0 = baanim_getAnimCtrlPtr(param_0);
    sp20 = temp_v0;
    if (anctrl_getIndex(temp_v0) == 0xD2) {
        if (anctrl_isAt(sp20, 0.8264f) != 0) {
            func_8009DF18(param_0, 0x449, 1.0f, 0x36B0);
        }
        if (anctrl_isAt(sp20, 0.8864f) != 0) {
            func_8009DF18(param_0, 0x449, 1.0f, 0x36B0);
        }
    }
    if (anctrl_isStopped(sp20) != 0) {
        sp24 = 1;
    }
    bs_setState(param_0, func_80800038_bsstand(param_0, sp24));
}

void bsstand_entrypoint_6(s32 arg0) 
{
}
int bsstand_entrypoint_7(s32 param_0)
{
  return D_80800DA8_bsstand[param_0];
}

void bsstand_entrypoint_8()
{
    func_80800038_bsstand();
}

void bsstand_entrypoint_9()
{
    _bsdrone_entrypoint_0();
}

void bsstand_entrypoint_10(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstand_entrypoint_11(s32 arg0)
{
    _bafpctrl_entrypoint_10(arg0,0);
    _bsdrone_entrypoint_2(arg0);
}

int bsstand_entrypoint_12(s32 param_0)
{
  return D_80800DB8_bsstand[param_0];
}
