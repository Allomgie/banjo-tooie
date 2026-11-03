#include "common.h"
#include "overlays/ba/playerstate.h"
#include "overlays/ba/playerstate.h"

extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void func_80092864(PlayerState *, f32);
extern void _batimer_set(PlayerState *, s32, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void bastick_setZoneMax(PlayerState *, s32, f32);
extern void func_800959C8(PlayerState *, f32, f32);
extern void func_8009590C(PlayerState *, f32);
extern void func_8009E55C(PlayerState *, s32, f32);
extern s32 D_80801B90_bsvan;
extern void *baanim_getAnimCtrlPtr(PlayerState *);
extern void _basudie_entrypoint_2(PlayerState *, f32, f32, f32);
extern void anctrl_setSubrange(void *, f32, f32);
extern void anctrl_setDuration(void *, f32);
extern void func_8009D820(PlayerState *, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern f32 func_800F0E00(f32, f32);
extern s32 D_80801C8C_bsvan[];
extern s32 D_80801C9C_bsvan[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern void anctrl_setStart(void *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern s32 anctrl_isStopped(void *);
extern void func_8009D3A8(PlayerState *, s32);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 func_8008DF8C(PlayerState *, s32);
extern int player_isStable(PlayerState *);
extern void func_800A2EAC(PlayerState *);
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern s32 baflag_isTrue(PlayerState *, s32);
extern s32 _badrone_entrypoint_28(PlayerState *);
extern s32 player_inWater(PlayerState *);
extern s32 D_80801CAC_bsvan[];
extern void _bavan_entrypoint_7(PlayerState *, f32);
extern void anctrl_reset(void *);
extern void anctrl_setSmoothTransition(void *, s32);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_setPlaybackType(void *, s32);
extern void anctrl_start(void *);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009D7A4(PlayerState *, f32, f32);
extern f32 func_8009BB5C(PlayerState *);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 D_80801CBC_bsvan[];
extern void func_80099B94(void);
extern s32 _bsdrone_entrypoint_3;
extern s32 D_80801CCC_bsvan[];
extern s32 D_80801CDC_bsvan[];
extern s32 D_80801CEC_bsvan[];
extern s32 D_80801CFC_bsvan[];
extern s32 D_80801D70_bsvan[];
extern s32 D_80801D80_bsvan[];
extern s32 func_800B5BE4(s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800BA77C(s32, s16, s16, s16);
extern s32 D_80801C40_bsvan[];
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F13F0(f32, f32);
extern void _bavan_entrypoint_5(PlayerState *, f32);
extern void _bavan_entrypoint_6(PlayerState *, f32);
extern void _bavan_entrypoint_4(PlayerState *, f32);
typedef struct { s32 handle; f32 position[3]; s32 result; } VanCoinState;
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern s32 D_80801D0C_bsvan;
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_80092C90(PlayerState *, f32 *, s32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800F1A88(f32 *, f32 *);
extern void func_800BA994(s32, s32, s16, s32, s32, s32, s32);
extern s32 func_8008E148(PlayerState *);
extern s32 _badrone_entrypoint_25(PlayerState *);
extern s32 func_800A02DC(PlayerState *, s32);
extern void bs_setState(PlayerState *, s32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void _bsvan_entrypoint_15();
extern void _chbaddiesetup_entrypoint_1();
extern void func_8080032C_bsvan(PlayerState *);
extern void bsvan_entrypoint_3(PlayerState *);
void func_80800E60_bsvan();
void func_8080164C_bsvan();

extern void func_80800000_bsvan(PlayerState *);
s32 func_80800064_bsvan(s32 param_0, s32 param_1);
int func_808000BC_bsvan(Actor *param_0);
void bsvan_entrypoint_0();
void bsvan_entrypoint_1();
void bsvan_entrypoint_2(s32 param_0);
void func_808004F8_bsvan(s32 arg0);
void func_80800520_bsvan(PlayerState *param_0);
void func_808005E4_bsvan(PlayerState *param_0);
int bsvan_entrypoint_4(s32 param_0);
void func_80800760_bsvan(s32 arg0);
void func_80800788_bsvan(s32 arg0);
void func_808007B0_bsvan(s32 arg0);
int bsvan_entrypoint_5(s32 param_0);
s32 func_808007EC_bsvan(Actor *this);
void func_80800824_bsvan(PlayerState *param_0);
void func_808008D4_bsvan(PlayerState *param_0);
int bsvan_entrypoint_6(s32 param_0);
void func_80800A5C_bsvan(PlayerState *param_0);
void func_80800BDC_bsvan(PlayerState *param_0);
void func_80800E0C_bsvan(Actor *this);
int bsvan_entrypoint_7(s32 param_0);
void bsvan_entrypoint_8(s32 param_0);
void bsvan_entrypoint_9(s32 param_0);
void func_80800F50_bsvan();
void func_80800F70_bsvan(PlayerState *param_0);
void func_80801034_bsvan(s32 param_0);
int bsvan_entrypoint_10(s32 param_0);
void func_80801118_bsvan(s32 arg0);
int func_80801140_bsvan(Actor *param_0);
void func_80801198_bsvan(Actor *param_0);
int bsvan_entrypoint_11(s32 param_0);
void func_80801224_bsvan(s32 arg0);
int func_8080124C_bsvan(Actor *param_0);
s32 func_808012A4_bsvan(s32 param_0);
int bsvan_entrypoint_12(s32 param_0);
void func_8080130C_bsvan(s32 arg0);
void func_80801334_bsvan(s32 arg0);
s32 func_8080135C_bsvan(Actor *this);
int bsvan_entrypoint_13(s32 param_0);
void func_808013BC_bsvan(s32 arg0);
int func_808013E4_bsvan(Actor *param_0);
void func_8080145C_bsvan(PlayerState *this);
int bsvan_entrypoint_14(s32 param_0);
void func_80801770_bsvan(u8 *arg0);
void func_808017A0_bsvan(Actor *param_0);
void bsvan_entrypoint_15();
void func_80801890_bsvan(PlayerState *param_0);
int bsvan_entrypoint_16(s32 param_0);
void func_80800000_bsvan(PlayerState *param_0)
{
    f32 local_0;

    local_0 = bastick_getZonePosition(param_0);
    if (bastick_getZone(param_0) == 0) {
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 900.0f));
    }
}

s32 func_80800064_bsvan(s32 param_0, s32 param_1)
{
    if (bainput_should_enter_first_person())
    {
        param_1 = _badrone_entrypoint_24(param_0);
    }
    if (bakey_pressed(param_0, 8))
    {
        param_1 = 0x115;
    }
    return param_1;
}

int func_808000BC_bsvan(Actor *param_0)
{
  if (bakey_pressed(param_0, 9))
  {
    _bavan_entrypoint_1(param_0);
  }
}

void bsvan_entrypoint_0(param_0)
PlayerState *param_0;
{
    if (!func_8009E74C(param_0, 0xD)) {
        _bastatemem_entrypoint_1(param_0);
        func_80092864(param_0, 1.0f);
        func_800947EC(param_0, 1, 0);
        func_8009BF5C(param_0, 0.0f);
        baroll_setIdeal(param_0, 0.0f);
        func_8009C000(param_0);
        baroll_resetAngularVelocity(param_0);
        bastick_popZone(param_0);
        func_80095A40(param_0);
        func_8009E474(param_0);
        baflag_clear(param_0, 3);
        baflag_clear(param_0, 4);
        _bavan_entrypoint_2(param_0);
    }
}

void bsvan_entrypoint_1(param_0)
PlayerState *param_0;
{
    if (!func_8009E77C(param_0, 13)) {
        _bastatemem_entrypoint_0(param_0, 0x14);
        _bavan_entrypoint_3(param_0);
        *(s32 *)param_0->kazfly = 0;
        param_0->unk174 = 1.0f;
        _batimer_set(param_0, 2, 0.0f);
        func_80092864(param_0, 2.29998779296875f);
        func_8009BFE4(param_0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(param_0, 1000.0f, 12.0f);
        bastick_pushZone(param_0);
        bastick_setZoneMax(param_0, 0, 0.12f);
        bastick_setZoneMax(param_0, 1, 1.0f);
        func_800959C8(param_0, 110.0f, 65.0f);
        func_8009590C(param_0, 110.0f);
        func_8009E4AC(param_0);
        func_8009E55C(param_0, 0, 70.0f);
        func_8009E55C(param_0, 1, 78.0f);
        baflag_set(param_0, 3);
        baflag_set(param_0, 4);
        func_800947EC(param_0, 1, 1);
    }
}

void bsvan_entrypoint_2(s32 param_0) {
    f32 local_0[3];
    s32 local_1;

    local_1 = func_800B5BE4(8);
    func_8009C128(param_0, local_0);
    func_800BABB8(local_1, local_0, 0, 1.0f, &D_80801B90_bsvan);
}

void func_8080032C_bsvan(PlayerState *param_0)
{
    f32 local_0[3];
    s32 local_1;
    func_80092C90(param_0, local_0, 4);
    local_1 = func_800B5BE4(8);
    func_800BABB8(local_1, local_0, 0, 1.0f, D_80801C40_bsvan);
    func_800BA77C(local_1, 0, 0, (s32)func_800DC178(0.0f, 359.0f));
    func_800BA22C(local_1, 1);
}

void bsvan_entrypoint_3(param_0) PlayerState *param_0;
{
    f32 local_1;
    f32 local_0;

    _bavan_entrypoint_5(param_0, func_800F1DCC(yaw_getIdeal(param_0), yaw_get(param_0)));
    local_0 = func_8009BB5C(param_0);
    if (local_0 > 1.0f) {
        local_0 = func_800F10B4(local_0, 30.0f, 900.0f, 45.0f, 1350.0f);
    } else {
        local_0 = 0.0f;
    }
    _bavan_entrypoint_6(param_0, local_0);
    local_0 = func_8009BB5C(param_0);
    if (local_0 > 0.0f) {
        local_1 = func_800F10B4(local_0, 30.0f, 900.0f, 0.8f, 1.25f);
    } else {
        local_1 = 0.8f;
    }
    if (!player_isStable(param_0)) {
        local_1 = func_800F13F0(1.9f, local_1 + 0.3f);
    }
    _bavan_entrypoint_4(param_0, local_1);
    _bavan_entrypoint_8(param_0);
}

void func_808004F8_bsvan(s32 arg0)
{
    _basudie_entrypoint_6();
    bsvan_entrypoint_0(arg0);
}
void func_80800520_bsvan(PlayerState *param_0)
{
    void *local_0;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    bsvan_entrypoint_1(param_0);
    param_0->unk16C = 250.0f;
    _basudie_entrypoint_2(param_0, 250.0f, 420.0f, -1200.0f);
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, 0);
    anctrl_setIndex(local_0, 0xD7);
    anctrl_setSubrange(local_0, 0.0f, 0.3966f);
    anctrl_setDuration(local_0, 1.7f);
    anctrl_setPlaybackType(local_0, 1);
    anctrl_start(local_0);
    func_8009D820(param_0, 1.8f);
    param_0->unk15C.word = 0;
}

void func_808005E4_bsvan(PlayerState *param_0)
{
    _basudie_entrypoint_5(param_0);
    baphysics_set_target_horizontal_velocity(param_0, param_0->unk16C);
    switch (param_0->unk15C.word) {
    case 0:
        if (player_isStable(param_0)) {
            baanim_setEnd(param_0, 0.7453f);
            func_8009DF18(param_0, 0x417, 0.8f, 0x4650);
            func_8009DF18(param_0, 0x428, 1.8f, 0x4650);
            baphysics_set_vertical_velocity(param_0, 400.0f);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        if (player_isStable(param_0)) {
            baanim_setEnd(param_0, 1.0f);
            func_8009DF18(param_0, 0x417, 0.8f, 0x4650);
            func_8009DF18(param_0, 0x428, 1.8f, 0x4650);
            param_0->unk15C.word = 2;
        }
        break;
    case 2:
        param_0->unk15C.word = 3;
        break;
    case 3:
        if (param_0->unk16C > 0.0f) {
            param_0->unk16C = func_800F0E00(0.0f, param_0->unk16C - 10.0f);
        }
        break;
    }
    bsvan_entrypoint_3(param_0);
    bs_setState(param_0, 0);
}

int bsvan_entrypoint_4(s32 param_0)
{
  return D_80801C8C_bsvan[param_0];
}

void func_80800760_bsvan(s32 arg0)
{
    _bsdrone_entrypoint_2();
    bsvan_entrypoint_0(arg0);
}
void func_80800788_bsvan(s32 arg0)
{
    bsvan_entrypoint_1();
    _bsdrone_entrypoint_0(arg0);
}
void func_808007B0_bsvan(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bsvan_entrypoint_3(arg0);
}
int bsvan_entrypoint_5(s32 param_0)
{
  return D_80801C9C_bsvan[param_0];
}

s32 func_808007EC_bsvan(Actor *this)
{
  func_8009BF5C(this, 0);
  baroll_setIdeal(this, 0);
  bsvan_entrypoint_0(this);
}

void func_80800824_bsvan(PlayerState *param_0)
{
    void *local_0;

    bsvan_entrypoint_1(param_0);
    local_0 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0xED);
    anctrl_setStart(local_0, 0.359f);
    anctrl_setDuration(local_0, 0.7f);
    anctrl_setPlaybackType(local_0, 3);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 1, 3, 3, 6);
    yaw_setVelocityBounded(param_0, 300.0f, 6.5f);
    param_0->unk15C.word = 0;
}

void func_808008D4_bsvan(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    f32 local_2[3];

    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_8009D3A8(param_0, 0);
    func_80800000_bsvan(param_0);
    func_8009BB24(param_0, local_2);
    switch (param_0->unk15C.word) {
        case 0:
            if (func_8008DF8C(param_0, 0x82)) {
                baanim_setEnd(param_0, 0.6939f);
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
        else local_0 = 0x11A;
    }
    if (player_inWater(param_0)) local_0 = 0x11D;
    func_808000BC_bsvan(param_0);
    bsvan_entrypoint_3(param_0);
    bs_setState(param_0, local_0);
}

int bsvan_entrypoint_6(s32 param_0)
{
  return D_80801CAC_bsvan[param_0];
}

void func_80800A5C_bsvan(PlayerState *param_0)
{
    void *local_1;
    f32 local_2;
    f32 local_0;
    s32 local_3;
    bsvan_entrypoint_1(param_0);
    local_1 = baanim_getAnimCtrlPtr(param_0);
    anctrl_reset(local_1);
    anctrl_setSmoothTransition(local_1, 0);
    anctrl_setIndex(local_1, 0xED);
    anctrl_setSubrange(local_1, 0.0f, 0.359f);
    anctrl_setDuration(local_1, 1.0f);
    anctrl_setStart(local_1, 0.15f);
    anctrl_setPlaybackType(local_1, 1);
    anctrl_start(local_1);
    func_8009FFD8(param_0, 1, 3, 1, 6);
    yaw_setVelocityBounded(param_0, 300.0f, 6.5f);
    if (bastick_distance(param_0) != 0.0f) yaw_setIdeal(param_0, bastick_getAngleRelativeToBanjo(param_0));
    baphysics_set_target_yaw(param_0, yaw_getIdeal(param_0));
    func_80800000_bsvan(param_0);
    local_0 = yaw_getIdeal(param_0);
    local_2 = baphysics_get_target_horizontal_velocity(param_0);
    baphysics_set_horizontal_velocity(param_0, local_0, local_2);
    baphysics_set_vertical_velocity(param_0, 693.5f);
    baphysics_set_gravity(param_0, -1200.0f);
    func_8009D7A4(param_0, 1.35f, 1.45f);
    _bavan_entrypoint_7(param_0, 0);
    param_0->unk15C.word = 0;
}

void func_80800BDC_bsvan(PlayerState *param_0)
{
    s32 local_0;
    void *local_1;
    f32 local_2[3];
    local_0 = 0;
    local_1 = baanim_getAnimCtrlPtr(param_0);
    func_8080032C_bsvan(param_0);
    func_80800000_bsvan(param_0);
    func_8009BB24(param_0, local_2);
    if (bakey_released(param_0, 8) && local_2[1] > 0.0f) baphysics_reset_gravity(param_0);
    switch (param_0->unk15C.word) {
    case 0:
        if (func_8008DF8C(param_0, 0x82)) {
            baanim_setEndAndDuration(param_0, 1.0, 0.7f);
            param_0->unk15C.word = 2;
        } else if (anctrl_isStopped(local_1)) {
            baanim_setEndAndDuration(param_0, 0.69f, 3.0f);
            param_0->unk15C.word = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(param_0, 0x82)) {
            baanim_setEndAndDuration(param_0, 1.0, 1.0f);
            param_0->unk15C.word = 2;
        }
        break;
    case 2:
        func_8009D3A8(param_0, 0);
        if (player_isStable(param_0)) {
            func_800A2EAC(param_0);
            baanim_setEndAndDuration(param_0, 1.0, 1.0f);
            param_0->unk15C.word = 3;
        }
        break;
    case 3:
        func_8009D2D8(param_0, 3);
        func_8009D3A8(param_0, 0);
        if (func_8009BB5C(param_0) > 0.0f) local_0 = 0x116;
        else if (anctrl_isStopped(local_1)) local_0 = 0x11A;
        if (bakey_pressed(param_0, 8)) local_0 = 0x115;
        break;
    }
    if (baphysics_get_vertical_velocity(param_0) < 0.0f && player_inWater(param_0)) local_0 = 0x11D;
    func_808000BC_bsvan(param_0);
    bsvan_entrypoint_3(param_0);
    bs_setState(param_0, local_0);
}

void func_80800E0C_bsvan(Actor *this)
{
  baphysics_reset_gravity();
  func_8009BF5C(this, 0);
  baroll_setIdeal(this, 0);
  bsvan_entrypoint_0(this);
}

int bsvan_entrypoint_7(s32 param_0)
{
  return D_80801CBC_bsvan[param_0];
}

void func_80800E60_bsvan(param_0, param_1) PlayerState *param_0; void (*param_1)(PlayerState *);
{
    switch (func_8009E6EC(param_0)) {
        case 0x46:
            ((VanCoinState *)param_0->kazfly)->handle = func_80099A4C(param_0);
            ((VanCoinState *)param_0->kazfly)->result = _chfaircoinbox_entrypoint_0(((VanCoinState *)param_0->kazfly)->handle, ((VanCoinState *)param_0->kazfly)->position);
            func_8009E830(param_0, 2);
            bs_setState(param_0, 0x121);
            break;
        default: param_1(param_0); break;
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x2E:
        case 0x4E:
        case 0x51:
        case 0x52: break;
    }
}

void bsvan_entrypoint_8(s32 param_0) {
    func_80800E60_bsvan(param_0, func_80099B94);
}

void bsvan_entrypoint_9(s32 param_0) {
    func_80800E60_bsvan(param_0, &_bsdrone_entrypoint_3);
}

void func_80800F50_bsvan()
{
    bsvan_entrypoint_0();
}

void func_80800F70_bsvan(PlayerState *param_0)
{
    bsvan_entrypoint_1(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xEC, 1.0f);
    func_8009FFD8(param_0, 2, 3, 1, 0xE);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 900.0f, 1.0f, 0.4f);
    func_8008CA30(param_0, 1.0f);
    yaw_setVelocityBounded(param_0, 300.0f, 6.5f);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(param_0, 1000.0f, 12.0f);
}

void func_80801034_bsvan(s32 param_0)
{
  s32 local_0;
  local_0 = 0;
  func_8009D3A8(param_0, 0);
  func_80800000_bsvan(param_0);
  func_8080032C_bsvan(param_0);
  if (bastick_getZone(param_0) == 0)
  {
    local_0 = 0x11A;
  }
  if (func_8008E148(param_0) != 0)
  {
    local_0 = _badrone_entrypoint_25(param_0);
  }
  if (func_8008DD04(param_0) != 0)
  {
    local_0 = 0x114;
  }
  func_808000BC_bsvan(param_0);
  if (bakey_pressed(param_0, 8) != 0)
  {
    local_0 = 0x115;
  }
  if (player_inWater(param_0) != 0)
  {
    local_0 = 0x11B;
  }
  bsvan_entrypoint_3(param_0);
  bs_setState(param_0, local_0);
}

int bsvan_entrypoint_10(s32 param_0)
{
  return D_80801CCC_bsvan[param_0];
}

void func_80801118_bsvan(s32 arg0)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(arg0);
}
int func_80801140_bsvan(Actor *param_0)
{
  int new_var;
  bsvan_entrypoint_1(param_0);
  _babounce_entrypoint_4(param_0, 1);
  _babounce_entrypoint_5(param_0, 0xef, new_var = 0x3F0346DC);
  new_var = 0x3DD21FF3;
  func_8008B10C(baanim_getAnimCtrlPtr(param_0), new_var);
}

void func_80801198_bsvan(Actor *param_0)
{
  s32 local_0;
  local_0 = 0;
  if (baanim_isAt(param_0, 0.5f) != 0)
  {
    func_800951B4(param_0);
  }
  if (_babounce_entrypoint_2(param_0) != 0)
  {
    func_80800000_bsvan(param_0);
  }
  if (_babounce_entrypoint_9(param_0) != 0)
  {
    local_0 = 0x11A;
  }
  bs_setState(param_0, local_0);
}

int bsvan_entrypoint_11(s32 param_0)
{
  return D_80801CDC_bsvan[param_0];
}

void func_80801224_bsvan(s32 arg0)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(arg0);
}
int func_8080124C_bsvan(Actor *param_0)
{
  int new_var;
  bsvan_entrypoint_1(param_0);
  {
    new_var = 2;
    _babounce_entrypoint_4(param_0, new_var);
    new_var = 0x3F0346DC;
    _babounce_entrypoint_5(param_0, 0xef, new_var);
    func_8008B10C(baanim_getAnimCtrlPtr(param_0), 0x3DD21FF3);
  }
}

s32 func_808012A4_bsvan(s32 param_0) {
    s32 local_0 = 0;

    if (_babounce_entrypoint_2(param_0)) {
        func_80800000_bsvan(param_0);
    }

    if (_babounce_entrypoint_9(param_0)) {
        local_0 = 0x11A;
    }

    bs_setState(param_0, local_0);
}

int bsvan_entrypoint_12(s32 param_0)
{
  return D_80801CEC_bsvan[param_0];
}

void func_8080130C_bsvan(s32 arg0)
{
    _bsrest_entrypoint_14();
    bsvan_entrypoint_0(arg0);
}
void func_80801334_bsvan(s32 arg0)
{
    bsvan_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
s32 func_8080135C_bsvan(Actor *this){
    s32 local_0 = 0;
    if(_bsrest_entrypoint_20()){
        local_0 = _bsrest_entrypoint_13(this);
    }
    bsvan_entrypoint_3(this);
    bs_setState(this, local_0);
}

int bsvan_entrypoint_13(s32 param_0)
{
  return D_80801CFC_bsvan[param_0];
}

void func_808013BC_bsvan(s32 arg0)
{
    bsvan_entrypoint_0();
    func_80090A2C(arg0);
}
int func_808013E4_bsvan(Actor *param_0)
{
  int new_var;
  extern void func_800909CC(Actor *a0);
  bsvan_entrypoint_1(param_0);
  baanim_playForDuration_loopSmooth(param_0, 0xee, 1.0f);
  new_var = 1;
  func_8009FFD8(param_0, new_var, 3, 1, 2);
  yaw_setVelocityBounded(param_0, 300.0f, 6.5f);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  func_800909CC(param_0);
}

void func_8080145C_bsvan(PlayerState *this)
{
    s32 next;
    f32 rot[2];
    f32 pos[3];
    f32 dir[3];
    f32 target[3];
    s32 handle;

    next = 0;
    func_8009D3A8(this, 0);
    if (baanim_isAt(this, 0.0122f) || baanim_isAt(this, 0.5122f)) {
        handle = func_800B5BE4(8);
        func_8009C128(this, pos);
        func_80092C90(this, target, 4);
        func_800EFB24(dir, target, pos);
        func_800F1A88(dir, rot);
        rot[0] = -rot[0] - 10;
        func_800BA994(handle, (s16)rot[0], rot[1] - 10.0f, 150, (s16)rot[0], (s32)(rot[1] + 10.0f), 200);
        func_800BA77C(handle, 0, 0, func_800DC178(0.0f, 359.0f));
        func_800BABB8(handle, target, 0, 1.0f, &D_80801D0C_bsvan);
    }
    func_808000BC_bsvan(this);
    if (bastick_getZone(this) > 0) {
        next = 0x116;
    }
    if (func_8008E148(this)) {
        next = _badrone_entrypoint_25(this);
    }
    if (player_inWater(this)) {
        next = 0x11D;
    }
    next = func_800A02DC(this, func_80800064_bsvan(this, next));
    bsvan_entrypoint_3(this);
    bs_setState(this, next);
}

int bsvan_entrypoint_14(s32 param_0)
{
  return D_80801D70_bsvan[param_0];
}

void func_8080164C_bsvan(param_0, param_1) PlayerState *param_0; s32 param_1;
{
    f32 local_0[3];
    func_8009C128(param_0, local_0);
    switch (param_1) {
    case 1:
        yaw_setIdeal(param_0, func_800F1DF4(local_0, (f32 *)((u8 *)param_0->kazfly + 4)) + 180.0f);
        break;
    case 2:
        baanim_playForDuration_onceSmooth(param_0, 0xF1, 1.2f);
        break;
    case 3:
        if (param_0->unk15C.word == 2) _batimer_set(param_0, 3, 0.001f);
        else _batimer_set(param_0, 3, 0.5f);
        break;
    case 4:
        baanim_playForDuration_onceSmooth(param_0, 0xF2, 1.3f);
        break;
    case 5:
        yaw_setIdeal(param_0, func_800F1DF4(local_0, (f32 *)((u8 *)param_0->kazfly + 4)));
        break;
    }
    param_0->unk15C.word = param_1;
}

void func_80801770_bsvan(u8 *arg0)
{
  s32 *temp_a0;
  s32 *new_var;
  s32 *temp_t7;
  temp_t7 = *((s32 **) (arg0 + 0x188));
  new_var = *((s32 **) (arg0 + 0x188));
  temp_t7 = new_var;
  temp_a0 = *temp_t7;
  _chfaircoinbox_entrypoint_1(temp_a0);
  bsvan_entrypoint_0(arg0);
}

void func_808017A0_bsvan(Actor *param_0)
{

    bsvan_entrypoint_1(param_0);
    baanim_playForDuration_loopSmooth(param_0, 0xEE, 1.0f);
    func_8009FFD8(param_0, 1, 3, 3, 2);
    yaw_setVelocityBounded(param_0, 3e+02f, 6.5f);
    *(s32*)((char*)param_0 + 0x15C) = 0;
    func_8080164C_bsvan(param_0, 1);
}

void bsvan_entrypoint_15()
{
  s32 *new_var;
  f32 local_1[3];
  f32 local_2[3];

  new_var = func_800F53D0();
  func_8009C128(new_var, local_1);
  func_800EE7F8(local_2, *(s32*)((char*)new_var + 0x188) + 4);
  local_1[1] += 20.0f;
  local_2[1] += 40.0f;
  _chfaircoin_entrypoint_0(local_1, local_2, 0x3F000000);
}

void func_80801890_bsvan(PlayerState *param_0)
{
    s32 local_0;
    f32 local_1;
    local_0 = 0;
    func_8009D3A8(param_0, 0);
    switch (param_0->unk15C.word) {
    case 1:
        local_1 = yaw_get(param_0);
        if (yaw_getIdeal(param_0) == local_1) func_8080164C_bsvan(param_0, 2);
        break;
    case 2:
        if (baanim_isAt(param_0, 0.08f)) func_8009DF18(param_0, 0x56D, 1.0f, 0x55F0);
        if (baanim_isAt(param_0, 0.5049f)) func_8080164C_bsvan(param_0, 3);
        break;
    case 3:
        if (_batimer_decrement(param_0, 3)) {
            _chbaddiesetup_entrypoint_1(&_bsvan_entrypoint_15, param_0->unk184);
            (*(s32 *)((u8 *)param_0->kazfly + 0x10))--;
            if (*(s32 *)((u8 *)param_0->kazfly + 0x10)) func_8080164C_bsvan(param_0, 3);
            else func_8080164C_bsvan(param_0, 4);
        }
        break;
    case 4:
        if (baanim_isStopped(param_0)) func_8080164C_bsvan(param_0, 5);
        break;
    case 5:
        local_1 = yaw_get(param_0);
        if (yaw_getIdeal(param_0) == local_1) {
            if (func_8008E124(param_0)) local_0 = 0x119;
            else local_0 = 0x11A;
        }
        break;
    }
    bsvan_entrypoint_3(param_0);
    bs_setState(param_0, local_0);
}

int bsvan_entrypoint_16(s32 param_0)
{
  return D_80801D80_bsvan[param_0];
}
