#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
#include "core2/anctrl.h"
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void bainput_enable(PlayerState *, s32, s32);
extern int D_80802130_bstaxi[];
extern void func_8009C128(PlayerState *, f32 *);
extern s32 _bapackctrl_entrypoint_1(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern f32 yaw_get(PlayerState *);
extern void func_800CB598(s32, f32 *, f32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_8009BF5C(s32, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern void func_8008B1C8(AnimCtrl *, f32);
extern f32 func_80096364(PlayerState *);
extern u8 D_80802140_bstaxi[];
extern f32 _batimer_get(PlayerState *, s32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800F3BB0(PlayerState *, f32 *);
extern s32 D_80802188_bstaxi[];
extern s32 D_80802198_bstaxi[];
extern s32 D_808021A8_bstaxi[];
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 bakey_released(PlayerState *, s32);
extern void baphysics_reset_gravity(PlayerState *);
extern s32 func_8008DF8C(PlayerState *, s32);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void func_8009D3A8(PlayerState *, s32);
extern s32 player_isStable(PlayerState *);
extern void func_8009FE58(PlayerState *);
extern f32 func_8009BB5C(PlayerState *);
extern void func_8009D2D8(PlayerState *, s32);
extern s32 bakey_pressed(PlayerState *, s32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 player_inWater(PlayerState *);
extern s32 func_8008E148(PlayerState *);
extern s32 func_8008E260(PlayerState *);
extern void bs_setState(PlayerState *, s32);
extern s32 D_808021B8_bstaxi[];
extern void func_800A2CE8(PlayerState *, f32, s32);
extern s32 D_808021C8_bstaxi[];
extern s32 D_808021D8_bstaxi[];
extern s32 D_808021E8_bstaxi[];
extern s32 D_808021F8_bstaxi[];
extern s32 D_808020D0_bstaxi;
extern s32 D_808020F0_bstaxi;
extern s32 D_80802110_bstaxi;
extern s32 baanim_isAt(PlayerState *, f32);
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern void func_800CB5D4(s32, f32 *, f32);
extern void _bapackctrl_entrypoint_4();
extern void func_800A0CD0();
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void _babackpack_entrypoint_6();
extern f32 func_80099A34(PlayerState *);
extern void func_8009DC98(PlayerState *, s32, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void func_8009DFD4(PlayerState *, s32, f32, f32, s32, s32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void _subaddietaxi_entrypoint_8(s32, f32 *, f32, f32, s32);
void func_80800A18_bstaxi();
void func_80801600_bstaxi();

void func_80800000_bstaxi(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 200.0f));
    }
}

int func_80800064_bstaxi(s32 param_0, s32 param_1)
{
  if (bakey_released(param_0, 1))
  {
    param_1 = 0x127;
  }
  if (bakey_pressed(param_0, 9))
  {
    param_1 = 0x124;
  }
  if (bakey_pressed(param_0, 8))
  {
    param_1 = 0x126;
  }
  return param_1 | 0;
}

void bstaxi_entrypoint_0(param_0)
PlayerState *param_0;
{
    if (!func_8009E74C(param_0, 0xE)) {
        func_800A0CD0(param_0, 1);
        _babackpack_set_state(param_0, 1);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        bastick_popZone(param_0);
        func_8009E474(param_0);
    }
}

void bstaxi_entrypoint_1(param_0) PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 0xE)) {
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 1.0f);
        func_8009E4AC(param_0);
    }
}

void bstaxi_entrypoint_2(void *param_0)
{
    ((u32 *)param_0)[0x58] = 0;
    bstaxi_entrypoint_0(param_0);
}

void bstaxi_entrypoint_3(PlayerState *param_0)
{
    bstaxi_entrypoint_1(param_0);
    baanim_playForDuration_onceSmooth(param_0, 0x129, 5.0f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    bainput_enable(param_0, 0, 0);
}

void bstaxi_entrypoint_4(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1[3];
    s32 local_2;
    local_0 = 0;
    bainput_enable(param_0, 0, 1);
    func_8009D3A8(param_0, 0);
    if (baanim_isAt(param_0, 0.0161f)) { _babackpack_set_state(param_0, 3); func_800A0CD0(param_0, 0); }
    if (baanim_isAt(param_0, 0.33f)) func_8009D454(param_0, 0, &D_808020D0_bstaxi);
    if (baanim_isAt(param_0, 0.435f)) func_8009D454(param_0, 0, &D_808020F0_bstaxi);
    if (baanim_isAt(param_0, 0.545f)) func_8009D454(param_0, 0, &D_80802110_bstaxi);
    if (baanim_isAt(param_0, 0.5662f)) {
        _babackpack_entrypoint_6(param_0, local_1, 0);
        local_2 = _bapackctrl_entrypoint_1(param_0);
        _bapackctrl_entrypoint_4(param_0, 0);
        func_8009DB04(param_0, 0x5C2, 1.8f, 0x7FFF);
        func_800CB598(local_2, local_1, yaw_get(param_0));
    }
    if (baanim_isAt(param_0, 0.8153f)) { _babackpack_set_state(param_0, 1); func_800A0CD0(param_0, 1); }
    if (baanim_isStopped(param_0)) local_0 = 1;
    if (baanim_getTimer(param_0) > 0.8153f && bastick_getZone(param_0) > 0) local_0 = 2;
    bs_setState(param_0, local_0);
}

int bstaxi_entrypoint_5(s32 param_0)
{
  return D_80802130_bstaxi[param_0];
}

void func_80800420_bstaxi(PlayerState *param_0)
{
    f32 local_0[3];
    s32 local_1;
    func_8009C128(param_0, local_0);
    local_0[1] += 50.0f;
    local_1 = _bapackctrl_entrypoint_1(param_0);
    _bapackctrl_entrypoint_4(param_0, 0);
    func_8009DB04(param_0, 0x5C2, 1.8f, 0x7FFF);
    func_800CB598(local_1, local_0, yaw_get(param_0));
}

void func_808004A8_bstaxi(s32 param_0) {
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
    case 0x1F: ;
    case 0x20:
    case 0x21: ;
    case 0x24:
    case 0x2D: ;
    case 0x2E:
    case 0x45: ;
    case 0x4E:
    case 0x51: ;
    case 0x52:
    case 0x59: ;
    case 0x5A:
    case 0x5B: ;
    case 0x5C:
        func_80800420_bstaxi(param_0);
        func_80099B94(param_0);
        return;
    case 0x15: ;
    case 0x1C:
    case 0x1D: ;
    case 0x1E:
    case 0x25: ;
    case 0x43:
        func_80800420_bstaxi(param_0);
        func_80099B94(param_0);
        return;
    default:
        func_80099B94(param_0);
        return;
    }
}

void func_80800524_bstaxi(PlayerState *param_0)
{
    f32 local_0;
    f32 local_3;
    f32 local_1;
    f32 local_2[3];
    local_0 = bastick_distance(param_0);
    if (local_0 == 0.0f) _bamovehover_entrypoint_4(param_0, NULL);
    else {
        local_1 = bastick_getAngleRelativeToBanjo(param_0);
        local_3 = func_800F10B4(local_0, 0.0f, 1.0f, 0.0f, 400.0f);
        func_800EEB9C(local_2, local_1, local_3);
        _bamovehover_entrypoint_4(param_0, local_2);
    }
}

s32 func_808005B8_bstaxi(Actor *this)
{
  baroll_setIdeal(this, 0);
  func_8009BF5C(this, 0);
  bstaxi_entrypoint_0(this);
}

void func_808005F0_bstaxi(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_1[3];
    f32 local_2;

    bstaxi_entrypoint_1(param_0);
    _batimer_set(param_0, 0, *(f32 *)((u8 *)param_0 + 0x16C));
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x24A);
    anctrl_setDuration(local_0, 3.0f);
    func_8008B1C8(local_0, 0.6f);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 3, 1, 0x13);
    yaw_setVelocityBounded(param_0, 300.0f, 3.5f);
    func_8009C128(param_0, local_1);
    local_2 = func_80096364(param_0) + 200.0f;
    if (local_2 < local_1[1]) {
        local_2 = local_1[1] + 200.0f;
    }
    local_1[1] = local_2;
    _bamovehover_entrypoint_3(param_0, local_1);
}

void func_808006F4_bstaxi(PlayerState *param_0)
{
    s32 local_0 = 0;
    s32 local_1 = 0;
    s32 local_2;
    f32 local_3[3];
    _batimer_decrement(param_0, 0);
    func_800D2498(0x100, (s32)_batimer_get(param_0, 0), 0);
    func_80800524_bstaxi(param_0);
    if (func_8001210C(1)) {
        local_2 = func_800B5BE4(0x1C);
        func_800F3BB0(param_0, local_3);
        func_800BABB8(local_2, local_3, local_3, 1.0f, D_80802140_bstaxi);
        func_800BA22C(local_2, 1);
    }
    if (_batimer_isZero(param_0, 0)) {
        local_1 = 1;
        local_0 = 0x2F;
    } else if (bakey_pressed(param_0, 9)) {
        local_1 = 1;
        local_0 = 0x2F;
    }
    if (local_1) func_80800420_bstaxi(param_0);
    bs_setState(param_0, local_0);
}

int bstaxi_entrypoint_6(s32 param_0)
{
  return D_80802188_bstaxi[param_0];
}

void bstaxi_entrypoint_7()
{
    bstaxi_entrypoint_0();
}

int bstaxi_entrypoint_8(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  bstaxi_entrypoint_1(param_0);
  baanim_playForDuration_onceSmooth(param_0, 0xf3, 1.1f);
  func_8009FFD8(param_0, 1, 1, 3, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  bainput_enable(param_0, 0, 0);
}

void bstaxi_entrypoint_9(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1;
    bainput_enable(param_0, 0, 1);
    if (baanim_isAt(param_0, 0.3f)) func_8009DEC0(param_0, 0x588, 0.95f, 1.05f, 20000, 22000);
    func_8009D3A8(param_0, 0);
    if (baanim_isAt(param_0, 0.084f)) {
        _babackpack_set_state(param_0, 3);
        func_800A0CD0(param_0, 0);
    }
    if (baanim_isStopped(param_0)) local_0 = 0x125;
    local_1 = baanim_getTimer(param_0);
    if (local_1 > 0.6723f) {
        if (bastick_getZone(param_0) > 0) local_0 = 0x123;
        if (bakey_released(param_0, 1)) local_0 = 0x127;
    }
    if (local_1 > 0.2f && bakey_pressed(param_0, 9)) local_0 = 0x124;
    bs_setState(param_0, local_0);
}

int bstaxi_entrypoint_10(s32 param_0)
{
  return D_80802198_bstaxi[param_0];
}

void func_80800A18_bstaxi(void *param_0, unsigned int param_1)
{
  switch (param_1)
  {
    case 0:
      if (((u8 *) param_0)[0x15c] == 3)
    {
      _bapackctrl_entrypoint_5(param_0, 2);
    }
      break;

    case 1:
      ((u8 *) param_0)[0x15d] = 0;
      baanim_playForDuration_onceSmooth(param_0, 0x121, 1.1f);
      bainput_enable(param_0, 0, 0);
      break;

    case 2:
      baanim_playForDuration_loopSmooth(param_0, 0x12B, 4.5f);
      break;

    case 3:
      baanim_playForDuration_onceSmooth(param_0, 0x12D, 2.8f);
      break;

    case 4:
      baanim_playForDuration_onceSmooth(param_0, 0x12C, 1.4f);
      break;

  }

  ((u8 *) param_0)[0x15c] = param_1;
}

void bstaxi_entrypoint_11(s32 arg0)
{
    func_80800A18_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_12(s32 param_0)
{
  bstaxi_entrypoint_1();
  func_8009FFD8(param_0, 1, 1, 3, 2);
  baphysics_set_target_horizontal_velocity(param_0, ((0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF);
  func_80800A18_bstaxi(param_0, 1);
}

void bstaxi_entrypoint_13(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1;
    Vec3f local_2;
    Vec3f local_3;
    Vec3f local_4;
    s32 local_5;

    local_1 = baanim_getTimer(param_0);
    func_8009D3A8(param_0, 0);
    switch (((u8 *)param_0)[0x15C]) {
    case 1:
        bainput_enable(param_0, 0, 1);
        if (baanim_isAt(param_0, 0.084f)) {
            _babackpack_set_state(param_0, 3);
            func_800A0CD0(param_0, 0);
        }
        if (bakey_pressed(param_0, 9)) {
            ((u8 *)param_0)[0x15D] = 1;
        }
        if ((local_1 > 0.3883f && ((u8 *)param_0)[0x15D]) || baanim_isStopped(param_0)) {
            func_80800A18_bstaxi(param_0, 2);
        }
        break;
    case 2:
        if (bakey_pressed(param_0, 9) || ((u8 *)param_0)[0x15D]) {
            ((u8 *)param_0)[0x15D] = 0;
            func_8009C128(param_0, local_2.f);
            func_800EF1B8(local_2.f, yaw_get(param_0), 45.0f);
            local_2.pos.y += 80.0f;
            if (func_800C6C94(local_2.f, 40.0f, local_3.f, 0x420020)) {
                func_800FC6B0(0xF);
            } else {
                func_80800A18_bstaxi(param_0, 3);
            }
        }
        if (bakey_released(param_0, 1)) {
            func_80800A18_bstaxi(param_0, 4);
        }
        break;
    case 3:
        if (baanim_isAt(param_0, 0.16f)) {
            _babackpack_entrypoint_6(param_0, local_4.f, 0);
            local_5 = _bapackctrl_entrypoint_1(param_0);
            _bapackctrl_entrypoint_4(param_0, 0);
            func_8009DEC0(param_0, 0x53C, 0.95f, 1.05f, 0x6978, 0x6D60);
            func_800CB5D4(local_5, local_4.f, yaw_get(param_0));
        }
        if (baanim_isAt(param_0, 0.6511f)) {
            _babackpack_set_state(param_0, 1);
            func_800A0CD0(param_0, 1);
        }
        if (local_1 > 0.6511f) {
            local_0 = 0x20;
        }
        break;
    case 4:
        if (baanim_isAt(param_0, 0.48f)) {
            func_8009DEC0(param_0, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
        }
        if (baanim_isAt(param_0, 0.5053f)) {
            _babackpack_set_state(param_0, 1);
            func_800A0CD0(param_0, 1);
        }
        if (local_1 > 0.5053f) {
            local_0 = 0x20;
        }
        break;
    }
    bs_setState(param_0, local_0);
}

int bstaxi_entrypoint_14(s32 param_0)
{
  return D_808021A8_bstaxi[param_0];
}

void bstaxi_entrypoint_15(PlayerState *param_0)
{
    AnimCtrl *local_0;

    bstaxi_entrypoint_1(param_0);
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x125);
    anctrl_setStart(local_0, 0.1522f);
    anctrl_setSubrange(local_0, 0.0f, 0.3824f);
    anctrl_setDuration(local_0, 1.0f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800000_bstaxi(param_0);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0), baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 500.0f);
    baphysics_set_gravity(param_0, -1900.0f);
    func_8009D7A4(param_0, 0.91f, 1.09f);
    *(u8 *)((u8 *)param_0 + 0x15C) = 0;
}

void bstaxi_entrypoint_16(PlayerState *this)
{
    s32 next;
    void *aCtrl;
    f32 vec[3];

    next = 0;
    aCtrl = baanim_getAnimCtrlPtr(this);
    func_80800000_bstaxi(this);
    func_8009BB24(this, vec);
    if (bakey_released(this, 8) && 0.0f < vec[1]) {
        baphysics_reset_gravity(this);
    }
    switch (this->unk15C.bytes[0]) {
    case 0:
        if (func_8008DF8C(this, 0x82)) {
            baanim_setEndAndDuration(this, 1.0, 0.7f);
            this->unk15C.bytes[0] = 2;
        } else if (anctrl_isStopped(aCtrl)) {
            baanim_setEndAndDuration(this, 0.472f, 3.0f);
            this->unk15C.bytes[0] = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(this, 0x82)) {
            baanim_setEndAndDuration(this, 1.0, 1.0f);
            this->unk15C.bytes[0] = 2;
        }
        break;
    case 2:
        func_8009D3A8(this, 0);
        if (player_isStable(this)) {
            func_8009FE58(this);
            baanim_setEndAndDuration(this, 1.0, 1.0f);
            this->unk15C.bytes[0] = 3;
        }
        break;
    case 3:
        baphysics_set_target_horizontal_velocity(this, func_8009BB5C(this) * 0.25f);
        func_8009D2D8(this, 3);
        func_8009D3A8(this, 0);
        if (0.0f < func_8009BB5C(this)) {
            next = 0x123;
        } else if (anctrl_isStopped(aCtrl)) {
            next = 0x125;
        }
        if (bakey_pressed(this, 9)) {
            next = 0x124;
        }
        break;
    }
    if (baphysics_get_vertical_velocity(this) < 0.0f && player_inWater(this)) {
        next = 0x4C;
    }
    if (player_isStable(this) && bakey_pressed(this, 8)) {
        next = 0x126;
    }
    if (func_8008E148(this)) {
        next = 1;
    }
    if (func_8008E260(this)) {
        next = 0x3D;
    }
    bs_setState(this, next);
}

void bstaxi_entrypoint_17(s32 param_0) {
    baphysics_reset_gravity(param_0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    bstaxi_entrypoint_0(param_0);
}

int bstaxi_entrypoint_18(s32 param_0)
{
  return D_808021B8_bstaxi[param_0];
}

void bstaxi_entrypoint_19()
{
    bstaxi_entrypoint_0();
}

void bstaxi_entrypoint_20(PlayerState *param_0)
{
    bstaxi_entrypoint_1(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xF4, 1.0f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 200.0f, 1.1f, 0.53f);
    func_8008CA30(param_0, 1.0f);
}

void bstaxi_entrypoint_21(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_8009D3A8(param_0, 0);
    func_800A2CE8(param_0, 0.1f, 4);
    func_800A2CE8(param_0, 0.6f, 3);
    func_80800000_bstaxi(param_0);
    if (!bastick_getZone(param_0)) local_0 = 0x125;
    local_0 = func_80800064_bstaxi(param_0, local_0);
    if (func_8008E148(param_0)) local_0 = 1;
    if (func_8008E260(param_0)) local_0 = 0x3D;
    if (player_inWater(param_0)) local_0 = 0x4C;
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

int bstaxi_entrypoint_22(s32 param_0)
{
  return D_808021C8_bstaxi[param_0];
}

void bstaxi_entrypoint_23()
{
    bstaxi_entrypoint_0();
}

int bstaxi_entrypoint_24(Actor *param_0)
{
  bstaxi_entrypoint_1(param_0);
  baanim_playForDuration_onceSmooth(param_0, 0x128, 1.4f);
  func_8009FFD8(param_0, 1, 1, 3, 2);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
}

void bstaxi_entrypoint_25(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_8009D3A8(param_0, 0);
    if (baanim_isAt(param_0, 0.5053f)) {
        _babackpack_set_state(param_0, 1);
        func_800A0CD0(param_0, 1);
    }
    if (baanim_isAt(param_0, 0.48f)) func_8009DEC0(param_0, 0x584, 0.95f, 1.05f, 0x55F0, 0x55F0);
    if (baanim_getTimer(param_0) > 0.5053f) local_0 = 0x20;
    bs_setState(param_0, local_0);
}

int bstaxi_entrypoint_26(s32 param_0)
{
  return D_808021D8_bstaxi[param_0];
}

void func_80801600_bstaxi(param_0, param_1) u8 *param_0; u32 param_1; {
  s8 _sfpad[8];
    s32 local_0;
    s32 local_1;

    switch (param_1) {
    case 0:
        if (func_8008E0C8(param_0) != 0) {
            _bapackctrl_entrypoint_5(param_0, 1);
        }
        baflag_clear(param_0, 0x33);
        func_8009E55C(param_0, 2, 0.0f);
        local_1 = (*(s32 *)((s8 *)(param_0) + (0x160)));
        if (local_1 != 0) {
            func_800FFA88(local_1);
            (*(s32 *)((s8 *)(param_0) + (0x160))) = 0;
        }
        break;
    case 1:
        (*(s32 *)((s8 *)(param_0) + (0x160))) = 0;
        (*(f32 *)((s8 *)(param_0) + (0x16C))) = 0.0f;
        func_8009E55C(param_0, 2, 50.0f);
        func_8009E4E0(param_0, 2, &_babackpack_entrypoint_6);
        break;
    case 2:
        _bapackctrl_entrypoint_4(param_0, (*(u8 *)((s8 *)(param_0) + (0x164))));
        baflag_clear(param_0, 0x33);
        _batimer_set(param_0, 0, 0.5f);
        func_8009C128(param_0, &local_0);
        _subaddietaxi_entrypoint_7((*(s32 *)((s8 *)(param_0) + (0x160))));
        break;
    case 3:
        func_8009DBB0(param_0, 0x5AD, 0x3F666666, 0x3F8CCCCD, 0x3E80);
        break;
    case 4:
        func_800CB698((*(u8 *)((s8 *)(param_0) + (0x164))), 2);
        func_800FFA88((*(s32 *)((s8 *)(param_0) + (0x160))));
        (*(s32 *)((s8 *)(param_0) + (0x160))) = 0;
        break;
    case 5:
        baanim_playForDuration_onceSmooth(param_0, 0x126, 2.5f);
        break;
    }
    (*(s8 *)((s8 *)(param_0) + (0x15C))) = (s8) param_1;
}

void bstaxi_entrypoint_27(s32 arg0)
{
    func_80801600_bstaxi(arg0,0);
    bstaxi_entrypoint_0(arg0);
}

void bstaxi_entrypoint_28(PlayerState *param_0)
{
    bstaxi_entrypoint_1(param_0);
    baanim_playForDuration_onceSmooth(param_0, 0xF5, 0.7f);
    func_8009FFD8(param_0, 1, 1, 3, 2);
    param_0->unk15C.bytes[0] = 0;
    func_80801600_bstaxi(param_0, 1);
}

void bstaxi_entrypoint_29(PlayerState *param_0)
{
    switch (func_8009E6EC(param_0)) {
        case 0x1F: case 0x20: case 0x21: case 0x24:
        case 0x2D: case 0x2E: case 0x45: case 0x4E:
        case 0x51: case 0x52: case 0x59: case 0x5A:
        case 0x5B: case 0x5C:
            if (param_0->unk16C > 0.0f) {
                func_808004A8_bstaxi(param_0);
                return;
            }
            if (param_0->unk160.word == 0) {
                func_80099B94(param_0);
            }
            return;
        case 0x15: case 0x1C: case 0x1D: case 0x1E:
        case 0x25: case 0x43:
            if (param_0->unk16C > 0.0f) {
                func_808004A8_bstaxi(param_0);
            }
            break;
        case 0x48:
            if (param_0->unk160.word) {
                func_8009E830(param_0, 1);
                return;
            }
            param_0->unk160.word = func_80099A4C(param_0);
            param_0->unk164.bytes[0] = func_80099A58(param_0);
            func_80801600_bstaxi(param_0, 2);
            func_8009E830(param_0, 2);
            return;
        case 0x6E:
            param_0->unk16C = func_80099A34(param_0);
            func_8009E830(param_0, 2);
            return;
        default:
            func_80099B94(param_0);
            break;
    }
}

void bstaxi_entrypoint_30(PlayerState *param_0)
{
    s32 local_0 = 0;
    f32 local_1[3];
    f32 local_2;
    f32 local_3;

    func_8009D3A8(param_0, 0);
    switch (((u8 *)param_0)[0x15C]) {
    case 1:
        func_80800000_bstaxi(param_0);
        if (baflag_isTrue(param_0, 0x33)) {
            baflag_clear(param_0, 0x33);
        }
        if (baanim_isAt(param_0, 0.2f)) {
            baflag_set(param_0, 0x33);
        }
        if (baanim_isAt(param_0, 0.35f)) {
            func_80801600_bstaxi(param_0, 3);
        }
        break;
    case 2:
        if (baanim_isAt(param_0, 0.44f)) {
            func_8009DC98(param_0, 0x5AC, 0.95f, 1.05f);
        }
        if (baanim_isAt(param_0, 0.64f)) {
            baphysics_set_target_horizontal_velocity(param_0, 0);
        }
        _babackpack_entrypoint_6(param_0, local_1, 0);
        local_3 = func_800F10B4(_batimer_get(param_0, 0), 0.0f, 0.5f, 0, 1.0f);
        local_2 = func_800F10B4(_batimer_get(param_0, 0), 0.19999999f, 0.5f, 0.0f, 1.0f);
        _subaddietaxi_entrypoint_8(*(s32 *)((u8 *)param_0 + 0x160), local_1,
                                 local_2, local_3, _bapackctrl_entrypoint_1(param_0));
        if (_batimer_decrement(param_0, 0)) {
            func_80801600_bstaxi(param_0, 4);
        }
        break;
    case 3:
        if (baanim_isAt(param_0, 0.64f)) {
            baphysics_set_target_horizontal_velocity(param_0, 0);
        }
        if (baanim_isStopped(param_0)) {
            local_0 = 0x125;
        }
        break;
    case 4:
        if (baanim_isStopped(param_0)) {
            func_80801600_bstaxi(param_0, 5);
        }
        break;
    case 5:
        if (baanim_isAt(param_0, 0.1f)) {
            func_8009DF18(param_0, 0x5AF, 1.0f, 0x6D60);
        }
        if (baanim_isAt(param_0, 0.3f)) {
            func_8009DF18(param_0, 0x5AF, 0.9f, 0x6D60);
        }
        if (baanim_isAt(param_0, 0.5f)) {
            func_8009DFD4(param_0, 0x5AE, 0.95f, 1.05f, 0x4E20, 0x55F0);
        }
        if (baanim_isAt(param_0, 0.707f)) {
            _babackpack_set_state(param_0, 1);
            func_800A0CD0(param_0, 1);
            _bapackctrl_entrypoint_5(param_0, 5);
            func_8009E55C(param_0, 2, 0);
        }
        if (baanim_isStopped(param_0)) {
            if (*(f32 *)((u8 *)param_0 + 0x16C) != 0.0f) {
                local_0 = 0x6F;
            } else {
                local_0 = 1;
            }
        }
        break;
    }
    bs_setState(param_0, local_0);
}

int bstaxi_entrypoint_31(s32 param_0)
{
  return D_808021E8_bstaxi[param_0];
}

void bstaxi_entrypoint_32(s32 arg0)
{
    func_80090A2C();
    bstaxi_entrypoint_0(arg0);
}
void bstaxi_entrypoint_33(Actor *param_0) {
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  int new_var;
  s32 local_0;
  local_0 = param_0;
  bstaxi_entrypoint_1(param_0);
  new_var = 0x124;
  baanim_playForDuration_loopSmooth(local_0, new_var, 6.0f);
  func_8009FFD8(local_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(local_0, 0);
  func_800909CC(local_0);
}

void bstaxi_entrypoint_34(Actor *param_0)
{
  s32 local_0;
  s32 local_1 = 0;
  local_0 = (s32) param_0;
  func_8009D3A8(param_0, 0);
  if (bastick_getZone(param_0) > 0)
  {
    local_1 = 0x123;
  }
  local_1 = func_80800064_bstaxi(param_0, local_1);
  if (func_8008E148(param_0))
  {
    local_1 = 1;
  }
  if (func_8008E260(param_0))
  {
    local_1 = 0x3D;
  }
  if (player_inWater(param_0))
  {
    local_1 = 0x4C;
  }
  bs_setState(param_0, func_800A02DC(param_0, local_1));
}

int bstaxi_entrypoint_35(s32 param_0)
{
  return D_808021F8_bstaxi[param_0];
}
