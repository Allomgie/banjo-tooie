#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(s32);
extern s32 bastick_getZone(s32);
extern void baphysics_set_target_horizontal_velocity(s32, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void _badata_entrypoint_4(PlayerState *, s32 *, f32 *);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
typedef struct { u8 pad_0[0x191]; u8 local_0; } DroneBitten1472;
extern f32 _bamovegoto_entrypoint_3(void *);
extern f32 func_80013970(f32);
extern void func_8008E95C();
extern void func_800961A0();
extern void _bsdronebitten_entrypoint_4(void);
extern void _bsdronebitten_entrypoint_5(void);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void _bamovegoto_entrypoint_8(void *, f32);
extern void _bamovegoto_entrypoint_7(void *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
typedef struct _AnCtrl AnCtrl;
extern void func_8009DB04(PlayerState *, s32, f32, s32);

void func_80800000_bsdronebitten(s32 param_0) {
    f32 local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 500.0f));
    }
}

void bsdronebitten_entrypoint_0(s32 arg0)
{
    func_8008E95C();
    bastick_popZone(arg0);
}
void bsdronebitten_entrypoint_1(PlayerState *param_0)
{
    f32 local_1;
    s32 local_0;

    _badata_entrypoint_4(param_0, &local_0, &local_1);
    baanim_playForDuration_loopSmooth(param_0, local_0, local_1);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    baphysics_set_vertical_velocity(param_0, 900.0f);
    baphysics_set_gravity(param_0, -1200.0f);
    bastick_pushZone(param_0);
    bastick_setZoneMax(param_0, 0, 0.12f);
    bastick_setZoneMax(param_0, 1, 1.0f);
    func_8008E944(param_0);
    func_8009D9D4(param_0);
}

void bsdronebitten_entrypoint_2()
{
    func_80099AA8();
}

void bsdronebitten_entrypoint_3(PlayerState *param_0)
{
    s32 local_0;
  s32 pad0;
    s32 local_1;
    local_0 = 0;
    func_80800000_bsdronebitten(param_0);
    if (func_800F64A4(param_0->unk184, 0x201) && func_8008DA24(param_0)) local_0 = 0xA8;
    local_1 = baphysics_get_vertical_velocity(param_0) < 0.0f;
    if (func_8008DF8C(param_0, 0x96) || (local_1 && player_inWater(param_0))) local_0 = _badata_entrypoint_24(param_0);
    bs_setState(param_0, local_0);
}

f32 bsdronebitten_entrypoint_4(u8 *param_0, f32 param_1)
{
    f32 local_0;
    switch (param_0[0x191])
    {
        case 1:
            return param_1;

        case 2:
            local_0 = 1.0f - param_1;
            return 1.0f - local_0 * local_0;

        default:
            return param_1;
    }
}

void bsdronebitten_entrypoint_5(DroneBitten1472 *param_0, f32 *param_1, f32 param_2)
{
  f32 local_0;
  switch (param_0->local_0)
  {
    case 1:
      break;

    case 2:
      local_0 = (_bamovegoto_entrypoint_3(param_0) * (func_80013970(param_2 * 180.0f) * 1.0f)) * 0.5f;
      param_1[1] += local_0;
      break;

  }

}

s32 bsdronebitten_entrypoint_6(Actor *this){
    func_800961A0(this, 0);
    func_8008E95C(this);
    _bafpctrl_entrypoint_19(this);
    
}

void bsdronebitten_entrypoint_7(u8 *param_0)
{
    f32 local_0;
    f32 local_1;
    s32 local_2;
    f32 local_3[3];

    _badata_entrypoint_4(param_0, &local_2, &local_1);
    baanim_playForDuration_loopSmooth(param_0, local_2, local_1);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    func_8009C128(param_0, local_3);
    local_0 = func_800EEAD4(local_3, (f32 *)(*(u8 **)(param_0 + 0x54) + 0x34));
    param_0[0x191] = (*(u8 **)(param_0 + 0x54))[0x30];
    _bamovegoto_entrypoint_0(param_0);
    if (param_0[0x191] == 1) {
        _bamovegoto_entrypoint_8(param_0, 2400.0f);
    } else {
        local_1 = func_800F10B4(local_0, 100.0f, 5000.0f, 0.4f, 4.5f);
        _bamovegoto_entrypoint_7(param_0, local_1);
    }
    _bamovegoto_entrypoint_12(param_0, *(u8 **)(param_0 + 0x54) + 0x34);
    _bamovegoto_entrypoint_11(param_0, _bsdronebitten_entrypoint_4, _bsdronebitten_entrypoint_5);
    _bamovegoto_entrypoint_13(param_0);
    func_800961A0(param_0, 1);
    func_8008E944(param_0);
    func_8009D9D4(param_0);
    param_0[0x190] = 0;
}

void bsdronebitten_entrypoint_8()
{
    func_80099AA8();
}

int func_80800478_bsdronebitten(int param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  local_1 = param_0;
  if (param_0 && param_0)
  {
  }
  if (func_8008E124(local_1))
  {
    local_0 = _badata_entrypoint_32(local_1);
  }
  else
  {
    local_0 = _badata_entrypoint_34();
  }
  return local_0;
}

int func_808004C4_bsdronebitten(Actor *param_0, s32 param_1, f32 param_2)
{
  AnCtrl *local_0;
  extern AnCtrl *baanim_getAnimCtrlPtr(Actor *);
  extern void anctrl_reset(AnCtrl *);
  extern void anctrl_setIndex(AnCtrl *, s32);
  extern void anctrl_setDuration(AnCtrl *, f32);
  extern void anctrl_setPlaybackType(AnCtrl *, s32);
  extern void anctrl_setSmoothTransition(AnCtrl *, s32);
  extern void anctrl_start(AnCtrl *);
  local_0 = baanim_getAnimCtrlPtr(param_0);
  anctrl_reset(local_0);
  anctrl_setIndex(local_0, param_1);
  anctrl_setDuration(local_0, param_2);
  anctrl_setPlaybackType(local_0, 1);
  anctrl_setSmoothTransition(local_0, 0);
  anctrl_start(local_0);
  *(s8 *)((char *)param_0 + 0x190) = 1;
}

void bsdronebitten_entrypoint_9(PlayerState *param_0)
{
    s32 local_0 = 0;

    switch (((u8 *)param_0)[0x190]) {
        case 0:
            if (_bamovegoto_entrypoint_4(param_0)) {
                func_8009D9D4(param_0);
                func_8009DB04(param_0, 0x417, 0.8f, 0x4650);
                _bashake_entrypoint_0(param_0, 3, 1);
                _badust_entrypoint_8(param_0);
                if (!func_800A1718(param_0)) {
                    local_0 = _badata_entrypoint_20(param_0);
                } else {
                    switch (func_800A3274(param_0)) {
                        case 1:
                        case 10:
                            func_808004C4_bsdronebitten(param_0, 0xD2, 2.25f);
                            break;
                        case 11:
                            func_808004C4_bsdronebitten(param_0, 0x11E, 1.6f);
                            break;
                        default:
                            local_0 = func_80800478_bsdronebitten(param_0, 0);
                            break;
                    }
                }
            }
            break;
        case 1:
            if (baanim_isStopped(param_0)) local_0 = func_80800478_bsdronebitten(param_0, 0);
            break;
    }
    bs_setState(param_0, local_0);
}
