#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 D_80800700_bssplitup[];
extern void _baduo_entrypoint_7(void *param_0, int param_1);
extern void func_800F8EE4(int param_0);
extern s32 D_80800710_bssplitup[];
extern s32 _batimer_decrement(s32, s32);
extern void _baduo_entrypoint_16(s32);
extern s32 D_80800720_bssplitup[];
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern f32 yaw_get(PlayerState *);
extern f32 func_800136E4(f32);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern s32 baanim_isStopped();
extern void bs_setState(s32, s32);
extern s32 D_80800730_bssplitup[];
extern s32 D_80800740_bssplitup[];
extern f32 func_800EEB40(f32 *, f32 *);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void _subaddiefind_entrypoint_5(s32, Actor **, s32, f32 *, f32, f32 (*)(f32 *, f32 *));
extern f32 baanim_getTimer(PlayerState *);
extern void _bamovegoto_entrypoint_7(PlayerState *, f32);
void func_8080012C_bssplitup();

void bssplitup_entrypoint_0(s32 param_0) {
    func_800A3410(param_0, 0xA);
    _bapackctrl_entrypoint_5(param_0, 3);
    baanim_playForDuration_onceSmooth(param_0, 0xA2, 2.2f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    func_8009B94C(param_0, 0);
    func_8009BA9C(param_0, 0);
}

void bssplitup_entrypoint_1(u8 *param_0) {
    s32 local_0;

    local_0 = 0;
    if (baanim_isStopped() != 0) {
        local_0 = 1;
        if (func_800F54E4() != (*(s32 *)((s8 *)(param_0) + (0x184)))) {
            func_800F457C(param_0, 2);
        }
    }
    bs_setState(param_0, local_0);
}

int bssplitup_entrypoint_2(Actor *param_0)
{
  _baduo_entrypoint_7(param_0, 3);
  if (bs_getNextState(param_0) != 0x5A)
  {
    _sudialog_entrypoint_0(0x4F5, 0xc);
  }
}

int bssplitup_entrypoint_3(s32 param_0)
{
  return D_80800700_bssplitup[param_0];
}

void func_8080012C_bssplitup(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    f32 local_0[4];
    Actor *local_1;

    *(s32 *)((u8 *)param_0 + 0x15C) = param_1;
    switch (param_1) {
        case 1:
            baanim_playForDuration_onceSmooth(param_0, 0xA3, 2.2f);
            func_8009FFD8(param_0, 1, 1, 3, 2);
            func_8009B94C(param_0, 0);
            func_8009BA9C(param_0, 0);
            func_8009DF18(param_0, 0x4592, 1.0f, 0x6D60);
            break;
        case 2:
            func_8009C128(param_0, &local_0[1]);
            _subaddiefind_entrypoint_5(0x156, &local_1, 2, &local_0[1], 800.0f, func_800EEB40);
            func_800EE7F8(&local_0[1], local_1->position);
            _bamovegoto_entrypoint_0(param_0);
            _bamovegoto_entrypoint_12(param_0, &local_0[1]);
            _bamovegoto_entrypoint_7(param_0, (0.51f - baanim_getTimer(param_0)) * 2.2f);
            _bamovegoto_entrypoint_13(param_0);
            func_800F9098(0xB, &local_0[1]);
            break;
        case 3:
            baphysics_set_type(param_0, 2);
            break;
    }
}

void bssplitup_entrypoint_4(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 | 0;
  func_800A3410(local_0, 11);
  func_800A38F0(local_0, 0, 0);
  func_80092778(local_0);
  bastick_func_8009F258(local_0);
  *(s32 *)((char *)(param_0) + 0x15C) = 0;

  func_8080012C_bssplitup(local_0, 1);
}

void bssplitup_entrypoint_5(u8 *param_0) {
    s32 local_0;
    s32 local_1;

    local_0 = 0;
    local_1 = (*(s32 *)((s8 *)(param_0) + (0x15C)));
    switch (local_1) {                              
    case 3:
        break;
    case 1:
        if (baanim_isAt(param_0, 0x3D4CCCCD) != 0) {
            func_8080012C_bssplitup(param_0, 2);
        }
        break;
    case 2:
        if (baanim_isAt(param_0, 0x3F028F5C) != 0) {
            func_8080012C_bssplitup(param_0, 3);
        }
        break;
    }
    if (baanim_isStopped(param_0) != 0) {
        local_0 = 0xBB;
        if (func_800F54E4() != (*(s32 *)((s8 *)(param_0) + (0x184)))) {
            func_800F457C(param_0, 2);
        }
    }
    bs_setState(param_0, local_0);
}

void bssplitup_entrypoint_6(Actor *param_0)
{
  _baduo_entrypoint_7(param_0, 3);
  func_800F8EE4(*(int *)((char *)param_0 + 0x184));
}

int bssplitup_entrypoint_7(s32 param_0)
{
  return D_80800710_bssplitup[param_0];
}

void bssplitup_entrypoint_8(Actor *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0x6F, 0x40B00000);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    func_8009B94C(param_0, 0);
    func_8009BA9C(param_0, 0);
    _batimer_set(param_0, 0, 0x3DCCCCCD);
}

void bssplitup_entrypoint_9(s32 param_0) {
    s32 local_0 = 0;
    if (_batimer_decrement(param_0, 0)) {
        _baduo_entrypoint_16(param_0);
        local_0 = 0xB9;
    }
    bs_setState(param_0, local_0);
}

void bssplitup_entrypoint_10(s32 arg0) 
{
}
int bssplitup_entrypoint_11(s32 param_0)
{
  return D_80800720_bssplitup[param_0];
}

void bssplitup_entrypoint_12(PlayerState *param_0)
{
    baanim_playForDuration_once(param_0, 0x296, 0.8f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    func_8009B94C(param_0, 0);
    baphysics_set_horizontal_velocity(param_0, func_800136E4(yaw_get(param_0) + 180.0f), 800.0f);
    func_800A0CF4(param_0, 1);
    func_8009DF18(param_0, 0x3EA, 1.0f, 0x6D60);
}

void bssplitup_entrypoint_13(s32 param_0) {
    s32 local_0 = 0;
    if (baanim_isStopped(param_0) != 0) {
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

void bssplitup_entrypoint_14(s32 arg0)
{
    func_800A0CF4(arg0,0);
}

int bssplitup_entrypoint_15(s32 param_0)
{
  return D_80800730_bssplitup[param_0];
}

void bssplitup_entrypoint_16(PlayerState *param_0)
{
    baanim_playForDuration_once(param_0, 0x292, 0.8f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    func_8009B94C(param_0, 0);
    baphysics_set_horizontal_velocity(param_0, yaw_get(param_0), 800.0f);
    func_800A0CF4(param_0, 1);
    func_8009DF18(param_0, 0x3EA, 1.0f, 0x6D60);
}

s32 bssplitup_entrypoint_17(s32 param_0){
    s32 local_0;
    local_0 = 0;
    if(baanim_isStopped()){
        local_0 = 1;
    }
    bs_setState(param_0, local_0);
}

void bssplitup_entrypoint_18(s32 arg0)
{
    func_800A0CF4(arg0,0);
}

int bssplitup_entrypoint_19(s32 param_0)
{
  return D_80800740_bssplitup[param_0];
}
