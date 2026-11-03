#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern void func_8009C128(s32, f32 *);
extern f32 yaw_get(s32);
extern s32 _bababykaz_entrypoint_4(s32);
extern void _cheggclockwork_entrypoint_3(f32 *, f32, s32, s32);
extern void *func_80092AD8(PlayerState *);
extern void func_800E0AF0(void *, f32);
extern void func_800E0AFC(void *, s32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone();
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern s32 D_80801730_bsbabykaz[];
extern s32 func_8009E69C(PlayerState *, s32);
extern void func_800A4D6C(PlayerState *, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void func_8009590C(PlayerState *, f32);
extern void func_800947EC(PlayerState *, s32, s32);
extern s32 D_80801740_bsbabykaz[];
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 D_80801750_bsbabykaz[];
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern f32 yaw_getIdeal(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8008B1C8(AnimCtrl *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 D_80801760_bsbabykaz[];
extern s32 D_80801770_bsbabykaz[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80801780_bsbabykaz[];
extern s32 D_80801790_bsbabykaz[];
extern s32 func_8009E6EC(PlayerState *);
extern void _batimer_set(PlayerState *, s32, f32);
extern s32 _bababykaz_entrypoint_5(PlayerState *);
extern u8 D_8012762C;
extern void func_800F3BB0(PlayerState *, f32 *);
extern s32 D_808017A0_bsbabykaz[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800C6A7C(f32 *, f32 *, f32 *, s32);
extern s32 func_800C6C94(f32 *, f32, f32 *, s32);
extern void func_800A106C(PlayerState *, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern void func_8009E53C(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern int func_800EA068(int param_0);
void func_80801134_bsbabykaz();
void bsbabykaz_entrypoint_1();
void *D_exp_bsbabykaz_entrypoint_1[] = { (void *)bsbabykaz_entrypoint_1 };

void bsbabykaz_entrypoint_0(s32 param_0);
unsigned int func_80800050_bsbabykaz(void *param_0);
void func_8080005C_bsbabykaz(PlayerState *param_0);
int func_808000F8_bsbabykaz(Actor *param_0);
void func_80800134_bsbabykaz(PlayerState *param_0);
int func_808001A8_bsbabykaz(s32 param_0, s32 param_1);
void func_80800214_bsbabykaz(s32 *param_0);
void bsbabykaz_entrypoint_1(PlayerState *param_0);
void func_808003D0_bsbabykaz();
int func_808003F0_bsbabykaz(Actor *param_0);
int func_80800438_bsbabykaz(Actor *param_0);
s32 bsbabykaz_entrypoint_2(s32 param_0);
void bsbabykaz_entrypoint_3();
void bsbabykaz_entrypoint_4();
void bsbabykaz_entrypoint_5();
void func_8080072C_bsbabykaz(s32 arg0);
void func_80800754_bsbabykaz(s32 arg0);
void func_8080077C_bsbabykaz(s32 param_0);
int bsbabykaz_entrypoint_6(s32 param_0);
void func_808007EC_bsbabykaz();
void func_8080080C_bsbabykaz(u8 *param_0);
void func_80800864_bsbabykaz(PlayerState *param_0);
int bsbabykaz_entrypoint_7(s32 param_0);
void func_808009C4_bsbabykaz(s32 arg0);
void func_808009EC_bsbabykaz(PlayerState *param_0);
void func_80800B54_bsbabykaz(Actor *param_0);
int bsbabykaz_entrypoint_8(s32 param_0);
void func_80800D18_bsbabykaz(s32 arg0);
void func_80800D40_bsbabykaz(s32 arg0);
int func_80800D68_bsbabykaz(Actor *param_0);
int bsbabykaz_entrypoint_9(s32 param_0);
s32 func_80800DD4_bsbabykaz(Actor *this);
void func_80800E0C_bsbabykaz(PlayerState *param_0);
void func_80800EC8_bsbabykaz(s32 param_0);
int bsbabykaz_entrypoint_10(s32 param_0);
void func_80801014_bsbabykaz(s32 arg0);
void func_80801044_bsbabykaz(Actor *param_0);
int func_808010AC_bsbabykaz(Actor *param_0);
int bsbabykaz_entrypoint_11(s32 param_0);
void func_808011EC_bsbabykaz(PlayerState *param_0);
void func_808012C4_bsbabykaz(s32 arg0);
void func_808012EC_bsbabykaz(PlayerState *param_0);
void func_80801384_bsbabykaz(PlayerState *param_0);
int bsbabykaz_entrypoint_12(s32 param_0);
void bsbabykaz_entrypoint_13(s32 arg0);
s32 bsbabykaz_entrypoint_14(f32 *param_0);
void bsbabykaz_entrypoint_0(s32 param_0) {
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    _cheggclockwork_entrypoint_3(local_0, yaw_get(param_0), _bababykaz_entrypoint_4(param_0), *(s32 *)(param_0 + 0x160));
}

unsigned int func_80800050_bsbabykaz(void *param_0)
{
  float f4 = 0.0f;
  *(float *)((char *)param_0 + 0x170) = f4;
}

void func_8080005C_bsbabykaz(PlayerState *param_0)
{
    void *local_0;
    local_0 = func_80092AD8(param_0);
    func_800E0AF0(local_0, 1.0f);
    func_800E0AFC(local_0, 0x5B, 1.0f, -50.0f, 0.0f, 0.0f);
    func_800E0AFC(local_0, 0x5D, 1.0f, 0.0f, param_0->unk170, 0.0f);
    param_0->unk170 += func_800D8FF8() * 500.0f;
}

int func_808000F8_bsbabykaz(Actor *param_0)
{
  if (bakey_pressed(param_0, 9))
  {
    _bababykaz_entrypoint_7(param_0, 1);
  }
  _bababykaz_entrypoint_3(param_0);
}

void func_80800134_bsbabykaz(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 1:
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 80.0f, 400.0f));
        break;
    }
}

int func_808001A8_bsbabykaz(s32 param_0, s32 param_1)
{
  if (bastick_getZone() == 1)
  {
    param_1 = 0x135;
  }
  if (bakey_pressed(param_0, 8))
  {
    param_1 = 0x134;
  }
  if (func_808000F8_bsbabykaz(param_0))
  {
    param_1 = 0x94;
  }
  return param_1;
}

void func_80800214_bsbabykaz(s32 *param_0)
{
  s8 _sfpad[8];
    s32 local_0;

    func_8009C128(param_0, &local_0);
    func_801013A8(&local_0, 0x39, 0);
    bs_setState(param_0, 0x5A);
    _bababykaz_entrypoint_9(param_0);
    func_800F82C0(param_0[0x184 / 4]);
    func_800F9AFC();
}

void bsbabykaz_entrypoint_1(PlayerState *param_0)
{
    s32 local_0 = func_8009E6EC(param_0);

    switch (local_0) {
        case 0x1F: case 0x20: case 0x21: case 0x23: case 0x24:
        case 0x2D: case 0x2E: case 0x45: case 0x4E: case 0x51:
        case 0x52: case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x91:
            bs_setState(param_0, 0x94);
            func_8009E830(param_0, 2);
            break;
        case 0x66:
            func_8009E830(param_0, 1);
            break;
        case 0x87:
            bs_setState(param_0, 0x94);
            func_8009E830(param_0, 2);
            _batimer_set(param_0, 0, 0.0f);
            break;
        case 0x86:
            func_80800214_bsbabykaz(param_0);
            func_8009E830(param_0, 2);
            break;
        case 0x8E:
            *(s32 *)((u8 *)param_0 + 0x160) = 0;
            bs_setState(param_0, 0x94);
            func_8009E830(param_0, 2);
            _batimer_set(param_0, 0, 0.0f);
            break;
        default:
            func_80099B94(param_0);
            break;
    }
}

void func_808003D0_bsbabykaz()
{
    bsbabykaz_entrypoint_3();
}

int func_808003F0_bsbabykaz(Actor *param_0)
{
  long long new_var2;
  Actor *new_var;
  bsbabykaz_entrypoint_4();
  new_var = param_0;
  func_8009FFD8(new_var, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(new_var, 0);
}

int func_80800438_bsbabykaz(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  bsbabykaz_entrypoint_5(param_0);
  if (baanim_isStopped(param_0))
  {
    local_0 = 0x136;
  }
  if (func_8008DD04(param_0))
  {
    local_0 = 0x133;
  }
  bs_setState(param_0, func_808001A8_bsbabykaz(param_0, local_0));
}

s32 bsbabykaz_entrypoint_2(s32 param_0) {
    return D_80801730_bsbabykaz[param_0];
}

void bsbabykaz_entrypoint_3(param_0)
PlayerState *param_0;
{
    if (!func_8009E69C(param_0, 0x20)) {
        bastick_popZone(param_0);
        func_800A4D6C(param_0, 1.0f, 1.0f);
        func_80095A40(param_0);
        func_8009590C(param_0, 0.0f);
        func_800A1040(param_0);
        func_8009E474(param_0);
        func_800947EC(param_0, 1, 0);
        func_80092864(param_0, 1.0f);
        func_80095A74(param_0, 0);
    }
}

void bsbabykaz_entrypoint_4(param_0)
PlayerState *param_0;
{
    if (!func_8009E6C4(param_0, 0x20)) {
        _bababykaz_entrypoint_7(param_0, 0);
        func_800A106C(param_0, 20.0f, 40.0f);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 1.0f);
        func_800A4D6C(param_0, 0.329986572265625f, 0.329986572265625f);
        func_800959C8(param_0, 35.0f, 12.0f);
        func_8009590C(param_0, 35.0f);
        func_8009E4AC(param_0);
        func_8009E55C(param_0, 0, 20.0f);
        func_8009E53C(param_0, 0, 0.0f);
        func_8009E55C(param_0, 1, 0.0f);
        _bababykaz_entrypoint_10(param_0, -1);
        _bababykaz_entrypoint_6(param_0);
        func_800947EC(param_0, 1, 1);
        func_80800050_bsbabykaz(param_0);
        param_0->unk160.word = 1;
        func_80092864(param_0, 0.29998779296875f);
        func_80095A74(param_0, 1);
    }
}

void bsbabykaz_entrypoint_5(param_0) s32 param_0; {
    s32 local_0;

    if (func_8008DD70() == 0) {
        local_0 = _bababykaz_entrypoint_5(param_0);
        if ((local_0 != -1) && (func_800F7180(local_0) == 0)) {
            _bababykaz_entrypoint_7(param_0, 1);
        }
        if ((player_isStable(param_0) != 0) && (func_80096694(param_0) == 0x14)) {
            _bababykaz_entrypoint_7(param_0, 1);
        }
    }
    func_8080005C_bsbabykaz(param_0);
    _bababykaz_entrypoint_11(param_0);
}

void func_8080072C_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_3();
    _bsdrone_entrypoint_2(arg0);
}
void func_80800754_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_4();
    _bsdrone_entrypoint_0(arg0);
}
void func_8080077C_bsbabykaz(s32 param_0)
{
  s32 new_var;
  s32 local_0;
  local_0 = (new_var = param_0 | 0);
  _bsdrone_entrypoint_1(new_var);
  bsbabykaz_entrypoint_5(new_var);
  if ((_bababykaz_entrypoint_3(new_var) != 0) && (_badrone_entrypoint_3(new_var) != 1))
  {
    bs_setState(new_var, 0x94);
  }
}

int bsbabykaz_entrypoint_6(s32 param_0)
{
  return D_80801740_bsbabykaz[param_0];
}

void func_808007EC_bsbabykaz()
{
    bsbabykaz_entrypoint_3();
}

void func_8080080C_bsbabykaz(u8 *param_0) {
    bsbabykaz_entrypoint_4();
    baanim_playForDuration_loopSmooth(param_0, 0xA9, 0.38f);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    *(s32 *)((u8 *)param_0 + 0x15C) = 0;
}

void func_80800864_bsbabykaz(PlayerState *param_0)
{
    s32 local_0 = 0;
    AnimCtrl *local_1;
    f32 local_2[3];
    local_1 = baanim_getAnimCtrlPtr(param_0);
    bsbabykaz_entrypoint_5(param_0);
    if (baflag_isTrue(param_0, 15)) func_8009B7C0(param_0);
    else func_80800134_bsbabykaz(param_0);
    func_8009BB24(param_0, local_2);
    switch (param_0->unk15C.word) {
    case 1:
        break;
    case 0:
        if (func_8008DF8C(param_0, 90)) {
            anctrl_reset(local_1);
            anctrl_setIndex(local_1, 0xA9);
            anctrl_setStart(local_1, 0.6667f);
            anctrl_setDuration(local_1, 2.0f);
            anctrl_setPlaybackType(local_1, 1);
            anctrl_start(local_1);
            param_0->unk15C.word = 1;
        }
        break;
    }
    if (player_isStable(param_0)) {
        func_8009FE58(param_0);
        if (anctrl_getPlaybackType(local_1) == 1) local_0 = 0x132;
        else local_0 = 0x136;
    }
    if (func_808000F8_bsbabykaz(param_0)) local_0 = 0x94;
    bs_setState(param_0, local_0);
}

int bsbabykaz_entrypoint_7(s32 param_0)
{
  return D_80801750_bsbabykaz[param_0];
}

void func_808009C4_bsbabykaz(s32 arg0)
{
    baphysics_reset_gravity();
    bsbabykaz_entrypoint_3(arg0);
}
void func_808009EC_bsbabykaz(PlayerState *param_0)
{
    AnimCtrl *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    bsbabykaz_entrypoint_4(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0xA9);
    anctrl_setDuration(local_0, 1.9f);
    func_8008B1C8(local_0, 0.134f);
    anctrl_setStart(local_0, 0.3f);
    anctrl_setSubrange(local_0, 0.0f, 0.5042f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 1, 3, 6);
    if (bastick_distance(param_0) != 0.0f) {
        yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    }
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800134_bsbabykaz(param_0);
    baphysics_set_horizontal_velocity(param_0, yaw_getIdeal(param_0),
        baphysics_get_target_horizontal_velocity(param_0));
    baphysics_set_vertical_velocity(param_0, 475.0f);
    baphysics_set_gravity(param_0, -1200.0f);
    param_0->unk15C.word = 0;
    func_8009DE38(param_0, 0x432, 1.4f);
}

void func_80800B54_bsbabykaz(Actor *param_0) {
    s32 local_0;
    s32 *local_2;
    f32 local_1[3];

    local_0 = 0;
    local_2 = baanim_getAnimCtrlPtr(param_0);
    bsbabykaz_entrypoint_5(param_0);
    if (baflag_isTrue(param_0, 0xF) != 0) {
        func_8009B7C0(param_0);
    } else {
        func_80800134_bsbabykaz(param_0);
    }
    func_8009BB24(param_0, local_1);
    if (((bakey_released(param_0, 8) != 0) && (local_1[1] > 0.0f)) || (func_8008D544(param_0) == 0)) {
        baphysics_reset_gravity(param_0);
    }
    switch (*(s32 *)((char *)param_0 + 0x15C)) {
    case 2:
        break;
    case 0:
        if (anctrl_isStopped(local_2) != 0) {
            baanim_setEndAndDuration(param_0, 0x3F2AACDA, 0x40800000);
            *(s32 *)((char *)param_0 + 0x15C) = 1;
        }
        if (func_8008DF8C(param_0, 0x82) != 0) {
            baanim_setEndAndDuration(param_0, 0x3F800000, 0x3FB33333);
            *(s32 *)((char *)param_0 + 0x15C) = 2;
        }
        break;
    case 1:
        if (baanim_isStopped(param_0) != 0) {
            local_0 = 0x133;
        }
        if (func_8008DF8C(param_0, 0x5A) != 0) {
            baanim_setEndAndDuration(param_0, 0x3F800000, 0x40000000);
            *(s32 *)((char *)param_0 + 0x15C) = 2;
        }
        break;
    }
    if (player_isStable(param_0) != 0) {
        func_8009FE58(param_0);
        local_0 = 0x132;
    }
    if (func_808000F8_bsbabykaz(param_0) != 0) {
        local_0 = 0x94;
    }
    bs_setState(param_0, local_0);
}

int bsbabykaz_entrypoint_8(s32 param_0)
{
  return D_80801760_bsbabykaz[param_0];
}

void func_80800D18_bsbabykaz(s32 arg0)
{
    _bsrest_entrypoint_14();
    bsbabykaz_entrypoint_3(arg0);
}
void func_80800D40_bsbabykaz(s32 arg0)
{
    bsbabykaz_entrypoint_4();
    _bsrest_entrypoint_16(arg0);
}
int func_80800D68_bsbabykaz(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (_bsrest_entrypoint_20())
  {
    local_0 = 0x136;
  }
  bsbabykaz_entrypoint_5(param_0);
  if (_bababykaz_entrypoint_3(param_0))
  {
    local_0 = 0x94;
  }
  bs_setState(param_0, local_0);
}

int bsbabykaz_entrypoint_9(s32 param_0)
{
  return D_80801770_bsbabykaz[param_0];
}

s32 func_80800DD4_bsbabykaz(Actor *this)
{
  func_8009BF5C(this, 0);
  baroll_setIdeal(this, 0);
  bsbabykaz_entrypoint_3(this);
}

void func_80800E0C_bsbabykaz(PlayerState *param_0)
{
    bsbabykaz_entrypoint_4(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xA6, 0.66f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 80.0f, 400.0f, 0.54f, 0.35f);
    func_8008CA30(param_0, 1.0f);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(param_0, 1000.0f, 12.0f);
}

void func_80800EC8_bsbabykaz(s32 param_0) {
    s32 local_0;

    local_0 = 0;
    bsbabykaz_entrypoint_5();
    func_8009D2F0(param_0, 0, 0x3F000000);
    if (baanim_isAt(param_0, 0x3EF0A3D7) != 0) {
        func_8009DBB0(param_0, 0x555, 0x3FA00000, 0x3FACCCCD, 0x2710);
    }
    if (baanim_isAt(param_0, 0x3F7851EC) != 0) {
        func_8009DBB0(param_0, 0x556, 0x3FA00000, 0x3FACCCCD, 0x2710);
    }
    func_80800134_bsbabykaz(param_0);
    if ((bastick_getZone(param_0) == 0) && (func_8009BCD4(param_0, 0x40400000) != 0)) {
        local_0 = 0x136;
    }
    if (func_8008E148(param_0) != 0) {
        local_0 = _badrone_entrypoint_25(param_0);
    }
    if (func_8008DD04(param_0) != 0) {
        local_0 = 0x133;
    }
    if (bakey_pressed(param_0, 8) != 0) {
        local_0 = 0x134;
    }
    if (func_808000F8_bsbabykaz(param_0) != 0) {
        local_0 = 0x94;
    }
    bs_setState(param_0, local_0);
}

int bsbabykaz_entrypoint_10(s32 param_0)
{
  return D_80801780_bsbabykaz[param_0];
}

void func_80801014_bsbabykaz(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bsbabykaz_entrypoint_3(arg0);
}

void func_80801044_bsbabykaz(Actor *param_0) {
  int new_var;
  s32 local_0;
  local_0 = param_0;
  bsbabykaz_entrypoint_4(param_0);
  new_var = 0xa4;
  baanim_playForDuration_loopSmooth(local_0, new_var, 6.5f);
  func_8009FFD8(local_0, 1, 1, 1, 2);
  baphysics_set_target_horizontal_velocity(local_0, 0);
  func_800909CC(local_0);
}

int func_808010AC_bsbabykaz(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  bsbabykaz_entrypoint_5(param_0);
  if (func_8008E148(param_0))
  {
    local_0 = _badrone_entrypoint_25(param_0);
  }
  if (func_8008DD04(param_0))
  {
    local_0 = 0x133;
  }
  return bs_setState(param_0, func_808001A8_bsbabykaz(param_0, local_0));
}

int bsbabykaz_entrypoint_11(s32 param_0)
{
  return D_80801790_bsbabykaz[param_0];
}

void func_80801134_bsbabykaz(param_0, param_1) Actor *param_0; s32 param_1;
{
  f32 local_0;
  f32 local_4;
  switch (param_1)
  {
    case 1:
      if (func_800EA068(0x400))
    {
      local_0 = 0.3f;
    }
    else
    {
      local_0 = 2.0f;
    }
      _batimer_set(param_0, 0, local_0);
      break;

    case 2:
      if (func_800EA068(0x400))
    {
      local_4 = 0.3f;
    }
    else
    {
      local_4 = 2.0f;
    }
      _batimer_set(param_0, 0, local_4);

    default:
      break;
      return;

  }

  *((s32 *) (((u8 *) param_0) + 0x15c)) = param_1;
}

void func_808011EC_bsbabykaz(PlayerState *param_0)
{
    switch (func_8009E6EC(param_0)) {
        case 0x87:
            _batimer_set(param_0, 0, 0.0f);
            func_8009E830(param_0, 2);
            break;
        case 0x17:
            if (func_80099A58(param_0) == 1) {
                func_800F9BA4();
                func_80801134_bsbabykaz(param_0, 3);
                func_8009E830(param_0, 2);
            }
            break;
        case 0x94:
            if (param_0->unk15C.word == 2) {
                func_800F9B54();
                func_80801134_bsbabykaz(param_0, 3);
            }
            break;
        case 0x86:
            break;
    }
}

void func_808012C4_bsbabykaz(s32 arg0)
{
    func_80091E6C();
    bsbabykaz_entrypoint_3(arg0);
}
void func_808012EC_bsbabykaz(PlayerState *param_0)
{
    s32 local_0;
    bsbabykaz_entrypoint_4(param_0);
    local_0 = _bababykaz_entrypoint_5(param_0);
    _bababykaz_entrypoint_10(param_0, local_0);
    bsbabykaz_entrypoint_0(param_0);
    _bababykaz_entrypoint_9(param_0);
    func_80091E48(param_0, 0x20);
    if (local_0 < 0) {
        func_80801134_bsbabykaz(param_0, 1);
    } else {
        func_800F80D8(local_0);
        func_800F8EBC(local_0);
        func_80801134_bsbabykaz(param_0, 2);
    }
}

void func_80801384_bsbabykaz(PlayerState *param_0)
{
    s32 local_0;
    Vec3f local_1;
    s32 local_4;
    Vec3f local_2;
    s32 local_3;

    if (param_0->unk15C.word != 3) {
        _batimer_decrement(param_0, 0);
        local_0 = _batimer_isZero(param_0, 0);
        if (!func_8009CC68(param_0) && !func_800DB9B0() && !func_800F6D24(func_800F54E4())) {
            switch (param_0->unk15C.word) {
                case 1:
                    if (local_0) {
                        func_800F3BB0(param_0, local_1.f);
                        if (D_8012762C == 0x18) local_3 = func_80101180(0x418, 0x39, 0);
                        else local_3 = 0;
                        if (local_3 != 1) func_800F9ADC();
                        func_80801134_bsbabykaz(param_0, 3);
                    }
                    break;
                case 2:
                    if (local_0) {
                        func_800F3BB0(param_0, local_2.f);
                        func_801013A8(local_2.f, 0x39, 0);
                        func_800F9ADC();
                        func_80801134_bsbabykaz(param_0, 3);
                    }
                    break;
                case 3:
                    break;
            }
        }
    }
}

int bsbabykaz_entrypoint_12(s32 param_0)
{
  return D_808017A0_bsbabykaz[param_0];
}

void bsbabykaz_entrypoint_13(s32 arg0)
{
    _bababykaz_entrypoint_7(arg0,1);
}

s32 bsbabykaz_entrypoint_14(f32 *param_0)
{
    f32 local_4;
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];

    func_800EE7F8(local_0, param_0);
    local_4 = 35.0f;
    func_800EFA4C(local_2, param_0[0], param_0[1] + local_4, param_0[2]);
    if (func_800C6A7C(local_2, local_0, local_1, 0x400005)) return 0;
    func_800EE7F8(local_0, param_0);
    func_800EE7F8(local_3, local_2);
    if (func_800C6A7C(local_0, local_2, local_1, 0x400005)) return 0;
    func_800EE7F8(local_2, local_3);
    if (func_800C6C94(local_2, 12.0f, local_1, 0x400005)) return 0;
    return 1;
}
