#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/yaw.h"
extern void func_800C2FDC(u8);

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void func_80092864(Actor *, f32);
extern s32 D_80801D60_bswasher;
extern void _basudie_entrypoint_2(u8 *, f32, f32, f32);
extern f32 func_800F0E00(f32, f32);
extern s32 D_80801E10_bswasher[];
extern void _batimer_set(s32, s32, f32);
extern s32 D_80801E20_bswasher[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern void *baanim_getAnimCtrlPtr(void *);
extern void anctrl_reset(void *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setStart(void *, f32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern void func_8009FFD8(void *, s32, s32, s32, s32);
extern s32 anctrl_isStopped(void *);
extern void func_8009D3A8(PlayerState *, s32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 func_8008DF8C(PlayerState *, s32);
extern void baanim_setEnd(PlayerState *, f32);
extern int player_isStable(PlayerState *);
extern void func_800A2EAC(PlayerState *);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 _badrone_entrypoint_28(PlayerState *);
extern s32 D_80801E30_bswasher[];
extern void anctrl_setSmoothTransition(void *, s32);
void anctrl_setSubrange(s32, f32, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern s32 bakey_released(PlayerState *, s32);
extern void baphysics_reset_gravity(PlayerState *);
extern void func_8009D2D8(PlayerState *, s32);
extern f32 func_8009BB5C(PlayerState *);
extern s32 bakey_pressed(PlayerState *, s32);
extern void bs_setState(PlayerState *, s32);
extern s32 D_80801E40_bswasher[];
extern s32 func_8009E6EC();
extern s32 func_80099A4C();
extern void func_80099B94();
extern u8 D_80801E50_bswasher[];
extern s32 func_8009D454();
extern int D_80801E60_bswasher[];
extern s32 D_80801E70_bswasher[];
extern s32 D_80801E80_bswasher[];
extern s32 D_80801E90_bswasher[];
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern s32 D_80801EA0_bswasher[];
extern s32 D_80801EC4_bswasher[];
extern s32 D_80801ED4_bswasher[];
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void _bawasher_entrypoint_4(PlayerState *, f32);
extern void _bawasher_entrypoint_5(PlayerState *, f32);
extern void func_800C31DC(u8, f32);
extern void func_800C35E8();
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009DBB0(PlayerState *, s32, f32, f32, s32);
extern f32 yaw_get(PlayerState *);
extern u8 D_80801EB0_bswasher[];
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009DB04(PlayerState *, s32, f32, s32);
extern void _bawasher_entrypoint_3(PlayerState *, f32 *);
extern void _chfactoryworkerdirty_entrypoint_2(void *, f32 *, f32);
extern void _chfactoryworkerdirty_entrypoint_3(void *, f32);
extern f32 func_800D8FF8(void);
extern void _bawasher_entrypoint_7(PlayerState *);
extern int baanim_isStopped(PlayerState *);
void func_80800300_bswasher();
void func_80800F88_bswasher();
void func_808015EC_bswasher();

void func_80800000_bswasher(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 900.0f));
    }
}

s32 func_80800064_bswasher(s32 param_0, s32 param_1)
{
    if (bainput_should_enter_first_person())
    {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (bakey_pressed(param_0, 8))
    {
        param_1 = 0x35;
    }
    return param_1;
}

void func_808000BC_bswasher(Actor *param_0)
{
  yaw_setUpdateType(param_0, 0x3);
  yaw_setVelocityBounded(param_0, 3e+02f, 6.0f);
}

void func_808000F0_bswasher(param_0)
Actor *param_0;
{
    if (!func_8009E74C(param_0, 0x15)) {
        func_800947EC(param_0, 1, 0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        func_8009C000(param_0);
        baroll_resetAngularVelocity(param_0);
        bastick_popZone(param_0);
        func_80095A40(param_0);
        func_80095964(param_0, 0);
        func_8009E474(param_0);
        baflag_clear(param_0, 3);
        baflag_clear(param_0, 4);
        _bawasher_entrypoint_1(param_0);
        func_80092864(param_0, 1.0f);
    }
}

int func_808001A8_bswasher(param_0) s32 param_0;
{
  if (!func_8009E77C(param_0, 0x15))
  {
    _bawasher_entrypoint_2(param_0);
    func_8009BFE4(param_0, 0x447A0000, 0x41400000);
    baroll_setAngularVelocity(param_0, 0x447A0000, 0x41400000);
    bastick_pushZone(param_0);
    bastick_setZoneMax(param_0, 0, 0x3DF5C28F);
    bastick_setZoneMax(param_0, 1, 0x3F800000);
    func_800959C8(param_0, 0x42C80000, 0x42500000);
    func_80095964(param_0, 1);
    func_8009E4AC(param_0);
    func_8009E55C(param_0, 0, 0x428C0000);
    func_8009E55C(param_0, 1, 0x429C0000);
    baflag_set(param_0, 3);
    baflag_set(param_0, 4);
    func_800947EC(param_0, 1, 1);
    func_80092864(param_0, 1.7999878f);
  }
}

void bswasher_entrypoint_0(s32 param_0) {
    f32 local_0[3];
    s32 local_1;

    local_1 = func_800B5BE4(8);
    func_8009C128(param_0, local_0);
    func_800BABB8(local_1, local_0, 0, 0x3F800000, &D_80801D60_bswasher);
}

void func_80800300_bswasher(param_0) PlayerState *param_0;
{
    f32 local_1;
    f32 local_0;

    _bawasher_entrypoint_4(param_0, func_800F1DCC(yaw_getIdeal(param_0), yaw_get(param_0)));
    local_0 = func_8009BB5C(param_0);
    if (local_0 > 1.0f) {
        local_0 = func_800F10B4(local_0, 30.0f, 900.0f, 45.0f, 1350.0f);
    } else {
        local_0 = 0.0f;
    }
    _bawasher_entrypoint_5(param_0, local_0);
    local_0 = func_8009BB5C(param_0);
    if (local_0 > 0.0f) {
        local_1 = func_800F10B4(local_0, 30.0f, 900.0f, 0.8f, 1.25f);
    } else {
        local_1 = 0.8f;
    }
    if (!player_isStable(param_0)) {
        func_800F13F0(1.9f, local_1 + 0.3f);
    }
    _bawasher_entrypoint_9(param_0);
}

void func_8080042C_bswasher(Actor *param_0, s32 param_1)
{
  s32 *local_0;
  switch (param_1)
  {
    case 1:
    {
      local_0 = (s32 *) baanim_getAnimCtrlPtr(param_0);
      anctrl_reset(local_0);
      anctrl_setSmoothTransition(local_0, 0);
      anctrl_setIndex(local_0, 0x32);
      anctrl_setSubrange(local_0, 0, 0x3E821965);
      anctrl_setDuration(local_0, 0x40200000);
      anctrl_setPlaybackType(local_0, 1);
      anctrl_start(local_0);
      func_8009D820(param_0, 0x3FE66666);
      break;
    }

    case 2:
      baanim_setEnd(param_0, 0.5741f);
      func_8009DF94(param_0, 0x417, 0x3F4CCCCD, 0x4650);
      func_8009DF18(param_0, 0x428, 0x3FE66666, 0x4650);
      baphysics_set_vertical_velocity(param_0, 4e+02f);
      break;

    case 3:
      baanim_setEnd(param_0, 1.0f);
      func_8009DF94(param_0, 0x417, 0x3F4CCCCD, 0x4650);
      func_8009DF18(param_0, 0x428, 0x3FE66666, 0x4650);
      break;

    case 4:
      break;

  }

  *((s32 *) (((char *) param_0) + 0x15C)) = param_1;
}

void func_80800590_bswasher(s32 arg0)
{
    _basudie_entrypoint_6();
    func_808000F0_bswasher(arg0);
}
void func_808005B8_bswasher(u8 *param_0) {
    func_808001A8_bswasher(param_0);
    _basudie_entrypoint_2(param_0, *(f32 *)(param_0 + 0x16C), 4.2e+02f, -1.2e+03f);
    *(s32 *)(param_0 + 0x15C) = 0;
    *(f32 *)(param_0 + 0x16C) = 250.0f;
    func_8080042C_bswasher(param_0, 1);
}

void func_80800608_bswasher(PlayerState *param_0)
{
    _basudie_entrypoint_5(param_0);
    baphysics_set_target_horizontal_velocity(param_0, *(f32 *)((u8 *)param_0 + 0x16C));
    switch (*(s32 *)((u8 *)param_0 + 0x15C)) {
        case 1:
            if (player_isStable(param_0)) func_8080042C_bswasher(param_0, 2);
            break;
        case 2:
            if (player_isStable(param_0)) func_8080042C_bswasher(param_0, 3);
            break;
        case 3:
            func_8080042C_bswasher(param_0, 4);
            break;
        case 4:
            if (*(f32 *)((u8 *)param_0 + 0x16C) > 0.0f) {
                *(f32 *)((u8 *)param_0 + 0x16C) = func_800F0E00(0.0f, *(f32 *)((u8 *)param_0 + 0x16C) - 10.0f);
            }
            break;
    }
    func_80800300_bswasher(param_0);
    bs_setState(param_0, 0);
}

int bswasher_entrypoint_1(s32 param_0)
{
  return D_80801E10_bswasher[param_0];
}

s32 func_80800714_bswasher(Actor *this){
    if(_badrone_entrypoint_3(this) == 2){
        _bafpctrl_entrypoint_10(this, 0);
        func_800947EC(this, 2, 0);
    }
    func_808000F0_bswasher(this);
    _bsdrone_entrypoint_2(this);
}

void func_80800770_bswasher(s32 param_0)
{
    func_808001A8_bswasher();
    _bsdrone_entrypoint_0(param_0);
    _batimer_set(param_0, 2, 0);
    if (_badrone_entrypoint_3(param_0) == 2)
    {
        func_800947EC(param_0, 2, 1);
        _bafpctrl_entrypoint_10(param_0, 1);
    }
}

int func_808007DC_bswasher(s32 param_0)
{
    _bsdrone_entrypoint_1();
    func_80800300_bswasher(param_0);
    if (_badrone_entrypoint_3(param_0) == 2) {
        _batimer_decrement(param_0, 2);
        if (bakey_pressed(param_0, 1) != 0 && _batimer_isZero(param_0, 2) != 0) {
            func_8009DBB0(param_0, 0x573, 1.05f, 1.15f, 0x4E20);
            func_8009DBB0(param_0, 0x406, 0.85f, 0.95f, 0x4E20);
            _bawasher_entrypoint_7(param_0);
            _batimer_set(param_0, 2, 0.5f);
    }
  }
}

int bswasher_entrypoint_2(s32 param_0)
{
  return D_80801E20_bswasher[param_0];
}

s32 func_808008BC_bswasher(Actor *this)
{
  func_8009BF5C(this, 0);
  baroll_setIdeal(this, 0);
  func_808000F0_bswasher(this);
}

void func_808008F4_bswasher(void *param_0)
{
    void *local_0;

    func_808001A8_bswasher(param_0);
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0x355);
    anctrl_setStart(local_0, 0.5036000013f);
    anctrl_setDuration(local_0, 0x3F333333);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 3, 3, 6);
    func_808000BC_bswasher(param_0);
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
}

void func_8080099C_bswasher(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    f32 local_2[3];

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_8009D3A8(param_0, 0);
    func_80800000_bswasher(param_0);
    func_8009BB24(param_0, local_2);
    switch (param_0->unk15C.word) {
        case 0:
            if (func_8008DF8C(param_0, 0x82)) {
                baanim_setEnd(param_0, 0.706f);
                param_0->unk15C.word = 1;
            }
            break;
        case 1:
            if (player_isStable(param_0)) {
                func_800A2EAC(param_0);
                baphysics_set_target_horizontal_velocity(param_0, 0.0f);
                baanim_setEndAndDuration(param_0, 1.0, 1.0f);
                param_0->unk15C.word = 2;
            }
            break;
        case 2:
            break;
    }
    if (player_isStable(param_0) && (bastick_getZone(param_0) > 0 ||
        (param_0->unk15C.word == 2 && anctrl_isStopped(local_1)))) {
        if (baflag_isTrue(param_0, 0x19)) local_0 = _badrone_entrypoint_28(param_0);
        else local_0 = 0x32;
    }
    func_80800300_bswasher(param_0);
    bs_setState(param_0, local_0);
}

int bswasher_entrypoint_3(s32 param_0)
{
  return D_80801E30_bswasher[param_0];
}

void func_80800B08_bswasher(PlayerState *param_0)
{
    void *local_0;

    func_808001A8_bswasher(param_0);
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0x355);
    anctrl_setSubrange(local_0, 0.0f, 0x3F000000);
    anctrl_setDuration(local_0, 0x3F800000);
    anctrl_setStart(local_0, 0.15f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 3, 1, 6);
    func_808000BC_bswasher(param_0);
    if (bastick_distance(param_0) != 0.0f) {
        yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    }
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800000_bswasher(param_0);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0),
        baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 693.5f);
    baphysics_set_gravity(param_0, -2.4e+03f);
    func_8009D7A4(param_0, 1.35f, 1.45f);
    param_0->unk15C.word = 0;
}

void func_80800C70_bswasher(PlayerState *this)
{
    s32 next;
    void *aCtrl;
    f32 vec[3];

    next = 0;
    aCtrl = baanim_getAnimCtrlPtr(this);
    func_80800000_bswasher(this);
    func_8009BB24(this, vec);
    if (bakey_released(this, 8) && 0.0f < vec[1]) {
        baphysics_reset_gravity(this);
    }
    switch (this->unk15C.word) {
    case 0:
        if (func_8008DF8C(this, 0x82)) {
            baanim_setEndAndDuration(this, 1.0, 0.7f);
            this->unk15C.word = 2;
        } else if (anctrl_isStopped(aCtrl)) {
            baanim_setEndAndDuration(this, 0.706f, 3.0f);
            this->unk15C.word = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(this, 0x82)) {
            baanim_setEndAndDuration(this, 1.0, 1.0f);
            this->unk15C.word = 2;
        }
        break;
    case 2:
        func_8009D3A8(this, 0);
        if (player_isStable(this)) {
            func_800A2EAC(this);
            baanim_setEndAndDuration(this, 1.0, 1.0f);
            this->unk15C.word = 3;
        }
        break;
    case 3:
        func_8009D2D8(this, 3);
        func_8009D3A8(this, 0);
        if (0.0f < func_8009BB5C(this)) {
            next = 0x33;
        } else if (anctrl_isStopped(aCtrl)) {
            next = 0x32;
        }
        if (bakey_pressed(this, 8)) {
            next = 0x35;
        }
        break;
    }
    if (bakey_pressed(this, 1)) {
        next = 0x38;
    }
    func_80800300_bswasher(this);
    bs_setState(this, next);
}

void func_80800E74_bswasher(s32 param_0) {
    baphysics_reset_gravity(param_0);
    func_8009BF5C(param_0, 0.0f);
    baroll_setIdeal(param_0, 0.0f);
    func_808000F0_bswasher(param_0);
}

int bswasher_entrypoint_4(s32 param_0)
{
  return D_80801E40_bswasher[param_0];
}

void func_80800EC8_bswasher(u8 *param_0) {
    if (func_8009E6EC(param_0) == 0x65) {
        *(s32 *)(param_0 + 0x160) = func_80099A4C(param_0);
        bs_setState(param_0, 0x37);
    }
    func_80099B94(param_0);
}

void func_80800F1C_bswasher(param_0) Actor *param_0;
{
    u8 local_0;
    local_0 = *(u8 *)((char *)param_0 + 0x165);
    if (local_0 != 0) {
        func_800C2FDC(local_0);
        *(u8 *)((char *)param_0 + 0x165) = 0;
    }
}

void func_80800F54_bswasher(u8 *param_0) {
    param_0[0x165] = func_8009D454(param_0, 0, D_80801E50_bswasher);
}

void func_80800F88_bswasher(param_0) PlayerState *param_0;
{
    f32 local_2;
    f32 local_0;
    Vec3f local_1;

    if (param_0->unk164.bytes[1] != 0) {
        local_0 = func_8009BB5C(param_0);
        func_8009C128(param_0, local_1.f);
        func_800C35E8(param_0->unk164.bytes[1], local_1.f);
        local_2 = func_800F10B4(local_0, 0.0f, 900.0f, 0.9f, 1.2f);
        func_800C31DC(param_0->unk164.bytes[1], local_2);
    }
}

void func_8080100C_bswasher(s32 arg0)
{
    func_80800F1C_bswasher();
    func_808000F0_bswasher(arg0);
}
void func_80801034_bswasher(PlayerState *param_0)
{
    func_808001A8_bswasher(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0x359, 1.0f);
    func_8009FFD8(param_0, 2, 3, 1, 14);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 900.0f, 0.7f, 0.3f);
    func_8008CA30(param_0, 1.0f);
    func_808000BC_bswasher(param_0);
    func_80800F54_bswasher(param_0);
}

void func_808010DC_bswasher(Actor *param_0) {
    s32 var_s1;

    var_s1 = 0;
    func_80800F88_bswasher();
    func_8009D3A8(param_0, 0);
    func_80800000_bswasher(param_0);
    if (bastick_getZone(param_0) == 0) {
        var_s1 = 0x32;
    }
    if (func_8008DD04(param_0) != 0) {
        var_s1 = 0x36;
    }
    if (bakey_pressed(param_0, 8) != 0) {
        var_s1 = 0x35;
    }
    if (bakey_pressed(param_0, 1) != 0) {
        var_s1 = 0x38;
    }
    if (func_8008E148(param_0) != 0) {
        var_s1 = _badrone_entrypoint_25(param_0);
    }
    func_80800300_bswasher(param_0);
    bs_setState(param_0, var_s1);
}

int bswasher_entrypoint_5(s32 param_0)
{
  return D_80801E60_bswasher[param_0];
}

void func_808011B4_bswasher(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808000F0_bswasher(arg0);
}
void func_808011DC_bswasher(Actor *param_0)
{
    func_808001A8_bswasher(param_0);
    _baspin_entrypoint_2(param_0, 856, 0x3FE66666, 2, 0);
}

int func_80801218_bswasher(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  func_80800300_bswasher(param_0);
  if (func_8009640C(param_0))
  {
    func_800A2EAC(param_0);
  }
  if (_baspin_entrypoint_3(param_0) == 2)
  {
    local_0 = 0x32;
  }
  bs_setState(param_0, local_0);
}

int bswasher_entrypoint_6(s32 param_0)
{
  return D_80801E70_bswasher[param_0];
}

void func_80801294_bswasher(s32 arg0)
{
    _babounce_entrypoint_3();
    func_808000F0_bswasher(arg0);
}
void func_808012BC_bswasher(Actor *param_0)
{
  s16 new_var;
  func_808001A8_bswasher(param_0);
  new_var = 0x358;
  _babounce_entrypoint_4(param_0, 2);
  _babounce_entrypoint_5(param_0, new_var, 0x3F0346DC);
  func_8008B10C(baanim_getAnimCtrlPtr(param_0), 0x3DD21FF3);
}

int func_80801314_bswasher(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_babounce_entrypoint_2())
  {
    func_80800000_bswasher(param_0);
  }
  if (_babounce_entrypoint_9(param_0))
  {
    local_0 = 0x32;
  }
  bs_setState(param_0, local_0);
}

int bswasher_entrypoint_7(s32 param_0)
{
  return D_80801E80_bswasher[param_0];
}

void func_8080137C_bswasher(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808000F0_bswasher(arg0);
}
void func_808013A4_bswasher(s32 arg0)
{
    func_808001A8_bswasher();
    _bsrest_entrypoint_16(arg0);
}
s32 func_808013CC_bswasher(s32 param_0){
    s32 local_0 = 0;
    if(_bsrest_entrypoint_20(param_0)){
        local_0 = _bsrest_entrypoint_13(param_0);
    }
    func_80800300_bswasher(param_0);
    bs_setState(param_0, local_0);
}

int bswasher_entrypoint_8(s32 param_0)
{
  return D_80801E90_bswasher[param_0];
}

void func_8080142C_bswasher(s32 arg0)
{
    func_808000F0_bswasher();
    func_80090A2C(arg0);
}
int func_80801454_bswasher(Actor *param_0)
{
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  s32 local_0;
  local_0 = param_0;
  func_808001A8_bswasher();
  baanim_playForDuration_loopSmooth(local_0, 0x356, 3.9f);
  func_8009FFD8(local_0, 1, 3, 1, 2);
  func_808000BC_bswasher(local_0);
  baphysics_set_target_horizontal_velocity(local_0, 0);
  func_800909CC(local_0);
}

void func_808014C8_bswasher(PlayerState *param_0)
{
    s32 local_0 = 0;
    func_8009D3A8(param_0, 0);
    if (baanim_isAt(param_0, 0.1487f) || baanim_isAt(param_0, 0.2737f)) func_8009DEC0(param_0, 0x4A1, 0.9f, 1.1f, 3000, 4000);
    if (func_8008E148(param_0)) local_0 = _badrone_entrypoint_25(param_0);
    if (func_8008DD04(param_0)) local_0 = 0x36;
    if (bastick_getZone(param_0)) local_0 = 0x33;
    local_0 = func_800A02DC(param_0, func_80800064_bswasher(param_0, local_0));
    if (bakey_pressed(param_0, 1)) local_0 = 0x38;
    func_80800300_bswasher(param_0);
    bs_setState(param_0, local_0);
}

int bswasher_entrypoint_9(s32 param_0)
{
  return D_80801EA0_bswasher[param_0];
}

void func_808015EC_bswasher(param_0, param_1) PlayerState *param_0; u32 param_1;
{
    s32 local_0;

    if (param_0->unk15C.word == 3) {
        if (((u8 *)param_0)[0x164] != 0) {
            func_800C2FDC(((u8 *)param_0)[0x164]);
            ((u8 *)param_0)[0x164] = 0;
        }
    }
    param_0->unk15C.word = param_1;
    switch (param_1) {
        case 0:
            break;
        case 1:
            baanim_playForDuration_onceSmooth(param_0, 0x354, 6.7f);
            func_8009FFD8(param_0, 1, 3, 2, 2);
            func_808000BC_bswasher(param_0);
            yaw_setIdeal(param_0, yaw_get(param_0));
            ((u8 *)param_0)[0x164] = 0;
            break;
        case 2:
            _chfactoryworkerdirty_entrypoint_1(*(void **)((u8 *)param_0 + 0x160), 1);
            break;
        case 3:
            _chfactoryworkerdirty_entrypoint_1(*(void **)((u8 *)param_0 + 0x160), 2);
            break;
        case 4:
            func_8009DBB0(param_0, 0x573, 1.05f, 1.15f, 20000);
            func_8009DBB0(param_0, 0x406, 0.85f, 0.95f, 20000);
            _chfactoryworkerdirty_entrypoint_1(*(void **)((u8 *)param_0 + 0x160), 3);
            break;
        case 5:
            _chfactoryworkerdirty_entrypoint_1(*(void **)((u8 *)param_0 + 0x160), 4);
            break;
    }
}

void func_80801744_bswasher(s32 arg0)
{
    func_808015EC_bswasher(arg0,0);
    func_808000F0_bswasher(arg0);
}

void func_80801770_bswasher(Actor *param_0)
{
    func_808001A8_bswasher();
    *(s32 *)((char *)param_0 + 0x15C) = 0;
    func_808015EC_bswasher(param_0, 1);
}

void func_808017A0_bswasher(PlayerState *param_0)
{
    s32 local_0;
    f32 local_4;
    Vec3f local_1;
    f32 local_3;
    f32 local_2;

    local_4 = 0.0f;

    local_0 = 0;
    if (baanim_isAt(param_0, 0.0001f)) {
        func_8009DB04(param_0, 0x5E7, 1.1f, 20000);
    }
    if (baanim_isAt(param_0, 0.1052f)) {
        func_8009DB04(param_0, 0x519, 1.1f, 20000);
    }
    if (baanim_isAt(param_0, 0.275f)) {
        func_8009DB04(param_0, 0x5E7, 0.9f, 20000);
    }
    if (baanim_isAt(param_0, 0.8572f)) {
        func_8009DB04(param_0, 0x5E7, 1.1f, 20000);
    }
    if (baanim_isAt(param_0, 0.93f)) {
        func_8009DB04(param_0, 0x5E7, 0.85f, 20000);
    }
    switch (param_0->unk15C.word) {
    case 1:
        if (baanim_isAt(param_0, 0.07f)) {
            func_808015EC_bswasher(param_0, 2);
        }
        break;
    case 2:
        _bawasher_entrypoint_3(param_0, local_1.f);
        _chfactoryworkerdirty_entrypoint_2(*(void **)((u8 *)param_0 + 0x160), local_1.f,
            func_800F10B4(baanim_getTimer(param_0), 0.07f, 0.12f, 0.0f, 1.0f));
        if (baanim_isAt(param_0, 0.12f)) {
            func_808015EC_bswasher(param_0, 3);
        }
        break;
    case 3:
        if (baanim_isAt(param_0, 0.2949f)) {
            ((u8 *)param_0)[0x164] = func_8009D454(param_0, 0, D_80801EB0_bswasher);
        }
        local_2 = baanim_getTimer(param_0);
        if (local_2 < 0.77f) {
            local_3 = func_800F10B4(local_2, 0.2949f, 0.77f, 0.0f, 1400.0f);
        } else {
            local_3 = func_800F10B4(local_2, 0.84f, 0.77f, 0.0f, 1400.0f);
        }
        _chfactoryworkerdirty_entrypoint_3(*(void **)((u8 *)param_0 + 0x160), local_3);
        if (((u8 *)param_0)[0x164]) {
            func_800C31DC(((u8 *)param_0)[0x164], func_800F10B4(local_3, 0.0f, 800.0f, 0.8f, 1.9f));
        }
        if (baanim_isAt(param_0, 0.89f)) {
            func_808015EC_bswasher(param_0, 4);
        }
        break;
    case 4:
        _bawasher_entrypoint_3(param_0, local_1.f);
        _chfactoryworkerdirty_entrypoint_2(*(void **)((u8 *)param_0 + 0x160), local_1.f,
            func_800F10B4(baanim_getTimer(param_0), 0.89f, 0.94f, 1.0f, 0.0f));
        if (baanim_isAt(param_0, 0.94f)) {
            func_808015EC_bswasher(param_0, 5);
        }
        break;
    case 5:
        if (baanim_isStopped(param_0)) {
            local_0 = 0x32;
        }
        break;
    }
    bs_setState(param_0, local_0);
}

int bswasher_entrypoint_10(s32 param_0)
{
  return D_80801EC4_bswasher[param_0];
}

void func_80801B10_bswasher()
{
    func_808000F0_bswasher();
}

int func_80801B30_bswasher(Actor *param_0)
{
  s32 local_0;
  local_0 = param_0;
  func_808001A8_bswasher();
  baanim_playForDuration_onceSmooth(local_0, 0x357, 0.8f);
  func_8009FFD8(local_0, 1, 3, 2, 2);
  func_808000BC_bswasher(local_0);
  yaw_setIdeal(local_0, yaw_get(local_0));
}

void func_80801BA4_bswasher(PlayerState *param_0)
{
    s32 local_0;
    f32 local_2;
    f32 local_1;

    local_0 = 0;
    local_1 = baphysics_get_target_horizontal_velocity(param_0);
    local_2 = 0.028f / func_800D8FF8();
    baphysics_set_target_horizontal_velocity(param_0, local_2 * local_1);
    if (baanim_isAt(param_0, 0.1309f)) {
        func_8009DBB0(param_0, 0x573, 1.05f, 1.15f, 20000);
        func_8009DBB0(param_0, 0x406, 0.85f, 0.95f, 20000);
        _bawasher_entrypoint_7(param_0);
        func_8009D2D8(param_0, 1);
    }
    if (baanim_isStopped(param_0)) local_0 = 0x32;
    if (baanim_getTimer(param_0) > 0.8f) {
        if (bastick_getZone(param_0)) local_0 = 0x33;
        if (bakey_pressed(param_0, 1)) local_0 = 0x38;
    }
    bs_setState(param_0, local_0);
}

int bswasher_entrypoint_11(s32 param_0)
{
  return D_80801ED4_bswasher[param_0];
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/bs/washer.data.s) is defined here in C --
 * tables holding function pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently. */
extern void _basudie_entrypoint_11();
extern void _bsdrone_entrypoint_3();
extern void func_80099AA8();
s32 D_80801D60_bswasher = 0x1D09DC;
static s32 D_80801D60_bswasher_rest[43] = { 0x2CFFD8, 0x32FFD8, 0x280064, 0x280015, 0x140066, 0x20F0F0, -0xFAFFFDE, 0x1800199, 0x2000280, 0x161000, 0x180000, 0x30000, 0x2B, 0x1800199, 0x210000, 0x0, 0xAFFB0, 0x3C0000, -0x4FFFC4, 0x11A, 0x2B0199, 0x1B30021, 0x0, 0x5A000A, 0x50003C, 0x50, 0x3C0000, 0x11A002B, 0x1B301CC, 0x210000, 0xB4, 0xA0000, 0x3CFFB0, 0x3C, -0x4FFEE6, 0x2B01CC, 0x1E60021, 0x0, 0x10E000A, 0x3C, 0x500000, 0x3C0050, 0x11A0000 };
s32 D_80801E10_bswasher[4] = { (s32)func_80800590_bswasher, (s32)func_808005B8_bswasher, (s32)func_80800608_bswasher, (s32)_basudie_entrypoint_11 };
s32 D_80801E20_bswasher[4] = { (s32)func_80800714_bswasher, (s32)func_80800770_bswasher, (s32)func_808007DC_bswasher, (s32)_bsdrone_entrypoint_3 };
s32 D_80801E30_bswasher[4] = { (s32)func_808008BC_bswasher, (s32)func_808008F4_bswasher, (s32)func_8080099C_bswasher, (s32)func_80800EC8_bswasher };
s32 D_80801E40_bswasher[4] = { (s32)func_80800E74_bswasher, (s32)func_80800B08_bswasher, (s32)func_80800C70_bswasher, (s32)func_80800EC8_bswasher };
u8 D_80801E50_bswasher[16] = { 0x3, 0x6, 0x0, 0x16, 0x2E, 0xE0, 0x0, 0x13, 0x5, 0xE8, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0 };
int D_80801E60_bswasher[4] = { (int)func_8080100C_bswasher, (int)func_80801034_bswasher, (int)func_808010DC_bswasher, (int)func_80800EC8_bswasher };
s32 D_80801E70_bswasher[4] = { (s32)func_808011B4_bswasher, (s32)func_808011DC_bswasher, (s32)func_80801218_bswasher, (s32)func_80099AA8 };
s32 D_80801E80_bswasher[4] = { (s32)func_80801294_bswasher, (s32)func_808012BC_bswasher, (s32)func_80801314_bswasher, (s32)func_80800EC8_bswasher };
s32 D_80801E90_bswasher[4] = { (s32)func_8080137C_bswasher, (s32)func_808013A4_bswasher, (s32)func_808013CC_bswasher, (s32)func_80800EC8_bswasher };
s32 D_80801EA0_bswasher[4] = { (s32)func_8080142C_bswasher, (s32)func_80801454_bswasher, (s32)func_808014C8_bswasher, (s32)func_80800EC8_bswasher };
u8 D_80801EB0_bswasher[20] = { 0x3, 0x6, 0x0, 0x16, 0x6D, 0x60, 0x0, 0xA, 0x0, 0xCC, 0x0, 0x13, 0x5, 0xE6, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0 };
s32 D_80801EC4_bswasher[4] = { (s32)func_80801744_bswasher, (s32)func_80801770_bswasher, (s32)func_808017A0_bswasher, (s32)func_80800EC8_bswasher };
s32 D_80801ED4_bswasher[7] = { (s32)func_80801B10_bswasher, (s32)func_80801B30_bswasher, (s32)func_80801BA4_bswasher, (s32)func_80800EC8_bswasher, 0x0, 0x0, 0x0 };
