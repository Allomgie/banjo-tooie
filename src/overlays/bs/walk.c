#include "common.h"
#include "overlays/bs/walk.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"

extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern f32 bastick_distance(void *);
extern f32 yaw_get(void *);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern void yaw_setIdeal(PlayerState *, f32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80801520_bswalk[];
extern s32 D_80801530_bswalk[];
extern f32 func_8009BB5C(PlayerState *);
extern s32 D_80801540_bswalk[];
extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern s32 D_80801550_bswalk[];
extern s32 D_80801560_bswalk[];
extern f32 bastick_getZonePosition(PlayerState *);
extern f32 func_800F1214(f32, f32, f32);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_8009BBB8(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
extern void *func_8008AEDC(AnimCtrl *);
extern f32 func_8008C0C8(void *);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_800A2EDC(PlayerState *, f32);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(PlayerState *, f32, f32);
extern void _badust_entrypoint_3(PlayerState *, f32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FF44(PlayerState *, s32, f32, f32, f32, f32);
void func_80800000_bswalk();
void func_8080016C_bswalk();

void func_80800000_bswalk(param_0) PlayerState *param_0;
{
    f32 local_0;
    u32 local_1;

    local_0 = bastick_getZonePosition(param_0);
    local_1 = bastick_getZone(param_0);
    if (func_8008DE24(param_0) && player_isStable(param_0)) {
        if (local_1 == 0) baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        else baphysics_set_target_horizontal_velocity(param_0,
            func_800F1214(bastick_distance(param_0), 30.0f, 150.0f));
        return;
    }
    switch (local_1) {
    case 0: baphysics_set_target_horizontal_velocity(param_0, 0.0f); break;
    case 1: baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 30.0f, 80.0f)); break;
    case 2: baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 80.0f, 150.0f)); break;
    case 3: baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 150.0f, 225.0f)); break;
    case 4: baphysics_set_target_horizontal_velocity(param_0, func_800F1214(local_0, 225.0f, 500.0f)); break;
    }
}

void func_8080016C_bswalk(param_0) PlayerState *param_0;
{
    if (func_8008E1A0(param_0)) {
        func_8008CA30(param_0, func_800F10B4(func_8009BBB8(param_0),
            0.0f, 1.0f, 0.5f, 0.9f));
    } else {
        func_8008CA30(param_0, 1.0f);
    }
}

void func_808001D8_bswalk(void *param_0, f32 param_1) {
    ((f32 *)param_0)[0x5B] = param_1;
}

void func_808001E4_bswalk(u8 *param_0) {
    f32 local_0 = func_800D8FF8();
    *(f32 *)(param_0 + 0x16C) = func_800F0E00(0.0f, *(f32 *)(param_0 + 0x16C) - local_0);
}

int func_80800220_bswalk(struct Actor *param_0)
{
    return *(f32 *)((char *)param_0 + 0x16C) == 0.0f;
}

s32 func_80800248_bswalk(PlayerState *param_0, s32 param_1)
{
    if (bakey_pressed(param_0, 9)) {
        if (baphysics_get_target_horizontal_velocity(param_0) > 225.0f) {
            param_1 = func_800A04F4(param_0, param_1);
        } else param_1 = func_800A055C(param_0, param_1);
    }
    return param_1;
}

f32 bswalk_entrypoint_0(s32 param_0) {
    return 500.0f;
}

void bswalk_entrypoint_1()
{
    func_80800000_bswalk();
}

void bswalk_entrypoint_2(s32 param_0) {
    func_800A2EDC(param_0, 1.0f);
    if (func_8008E0E8(param_0) != 0) {
        _bapackctrl_entrypoint_5(param_0, 3);
    }
}

void bswalk_entrypoint_3(PlayerState *param_0)
{
    AnimCtrl *local_1;
    f32 local_0;

    local_1 = baanim_getAnimCtrlPtr(param_0);
    if (bs_getPreviousState(param_0) == 2) {
        local_0 = func_8008C0C8(func_8008AEDC(local_1));
    } else {
        local_0 = 0.0f;
    }
    anctrl_reset(local_1);
    anctrl_setIndex(local_1, 2);
    anctrl_setDuration(local_1, 0.43f);
    anctrl_setStart(local_1, local_0);
    anctrl_setPlaybackType(local_1, 2);
    anctrl_start(local_1);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 80.0f, 1.8f, 1.2f);
    bastick_resetZones(param_0);
    func_800A2EDC(param_0, 0.2f);
    if (func_8008E0E8(param_0)) {
        _bapackctrl_entrypoint_5(param_0, 2);
    }
}

void bswalk_entrypoint_4(void *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_8080016C_bswalk(param_0);
    if (bastick_distance(param_0) == 0.0f) {
        yaw_setIdeal(param_0, yaw_get(param_0));
    }
    func_800A2CE8(param_0, 0.47f, 4);
    func_800A2CE8(param_0, 0.97f, 3);
    func_80800000_bswalk(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        if (func_8009BCD4(param_0, 1.0f)) {
            local_0 = 1;
        }
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
    if (func_8008DE24(param_0)) { local_0 = 0x7A; }
    if (bainput_should_enter_first_person(param_0)) { local_0 = _badrone_entrypoint_24(param_0); }
    if (func_8008DD04(param_0)) { local_0 = 0x2F; }
    if (bakey_held(param_0, 1)) { local_0 = 7; }
    local_0 = func_80800248_bswalk(param_0, local_0);
    if (bakey_pressed(param_0, 8)) {
        local_0 = bs_getTypeOfJump(param_0);
        if (baphysics_get_target_horizontal_velocity(param_0) == 0.0f) {
            if (func_8008D714(param_0)) {
                local_0 = 0xB8;
            } else if (func_8008D790(param_0)) {
                _baduo_entrypoint_12(param_0);
                return;
            }
        }
    }
    if (func_8008E148(param_0)) { local_0 = _badrone_entrypoint_25(param_0); }
    if (player_inWater(param_0)) { local_0 = 0x2D; }
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

int bswalk_entrypoint_5(s32 param_0)
{
  return D_80801520_bswalk[param_0];
}

void bswalk_entrypoint_6(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_1;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    if (bs_getPreviousState(param_0) == 3) local_1 = func_8008C0C8(func_8008AEDC(local_0));
    else local_1 = 0.0f;
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 3);
    anctrl_setDuration(local_0, 0.43f);
    anctrl_setStart(local_0, local_1);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 80.0f, 150.0f, 1.3f, 0.6f);
    bastick_resetZones(param_0);
    if (func_8008E0E8(param_0)) _bapackctrl_entrypoint_5(param_0, 2);
}

void bswalk_entrypoint_7(void *param_0)
{
    s32 local_0;
    local_0 = 0;
    func_8080016C_bswalk(param_0);
    if (bastick_distance(param_0) == 0.0f) {
        yaw_setIdeal(param_0, yaw_get(param_0));
    }
    func_800A2CE8(param_0, 0.4f, 4);
    func_800A2CE8(param_0, 0.9f, 3);
    func_80800000_bswalk(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        if (func_8009BCD4(param_0, 3.0f)) {
            local_0 = 1;
        }
        break;
    case 1:
        local_0 = 0x1F;
        break;
    case 3:
        local_0 = 3;
        break;
    case 4:
        local_0 = 4;
        break;
    }
    if (func_8008DE24(param_0)) { local_0 = 0x7A; }
    if (bainput_should_enter_first_person(param_0)) { local_0 = _badrone_entrypoint_24(param_0); }
    if (func_8008DD04(param_0)) { local_0 = 0x2F; }
    if (bakey_held(param_0, 1)) { local_0 = 7; }
    local_0 = func_80800248_bswalk(param_0, local_0);
    if (bakey_pressed(param_0, 8)) {
        local_0 = bs_getTypeOfJump(param_0);
        if (baphysics_get_target_horizontal_velocity(param_0) == 0.0f) {
            if (func_8008D714(param_0)) {
                local_0 = 0xB8;
            } else if (func_8008D790(param_0)) {
                _baduo_entrypoint_12(param_0);
                return;
            }
        }
    }
    if (func_8008E148(param_0)) { local_0 = _badrone_entrypoint_25(param_0); }
    if (player_inWater(param_0)) { local_0 = 0x2D; }
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

s32 bswalk_entrypoint_8(s32 param_0){
    if(func_8008E0E8()){
        _bapackctrl_entrypoint_5(param_0, 3);
    }
}

int bswalk_entrypoint_9(s32 param_0)
{
  return D_80801530_bswalk[param_0];
}

void bswalk_entrypoint_10(PlayerState *param_0)
{
    AnimCtrl *local_0;
    f32 local_1;
    s32 local_2;

    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_2 = bs_getPreviousState(param_0);
    if (local_2 != 2 && local_2 != 4) local_1 = 0.0f;
    else local_1 = func_8008C0C8(func_8008AEDC(local_0));
    anctrl_reset(local_0);
    anctrl_setIndex(local_0, 0xC);
    anctrl_setDuration(local_0, 0.66f);
    func_8008B1C8(local_0, 0.14f);
    anctrl_setStart(local_0, local_1);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 150.0f, 225.0f, 0.92f, 0.58f);
    func_808001D8_bswalk(param_0, 0.3f);
    bastick_resetZones(param_0);
    if (func_8008E0E8(param_0)) _bapackctrl_entrypoint_5(param_0, 2);
}

void bswalk_entrypoint_11(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_8080016C_bswalk(param_0);
    func_800A2CE8(param_0, 0.4f, 4);
    func_800A2CE8(param_0, 0.9f, 3);
    func_808001E4_bswalk(param_0);
    func_80800000_bswalk(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
    case 1:
    case 2:
        if (func_8009BCD4(param_0, 150.0f) && func_80800220_bswalk(param_0)) {
            local_0 = 2;
        }
        break;
    case 4:
        local_0 = 4;
        break;
    }
    if (func_8008DE24(param_0)) {
        local_0 = 0x7A;
    }
    if (func_8008E300(param_0) && func_8009BB5C(param_0) > 125.0f) {
        local_0 = 12;
    }
    if (bainput_should_enter_first_person(param_0)) {
        local_0 = _badrone_entrypoint_24(param_0);
    }
    if (func_8008DD04(param_0)) {
        local_0 = 0x2F;
    }
    if (bakey_held(param_0, 1)) {
        local_0 = 7;
    }
    local_0 = func_80800248_bswalk(param_0, local_0);
    if (bakey_pressed(param_0, 8)) {
        local_0 = bs_getTypeOfJump(param_0);
        if (baphysics_get_target_horizontal_velocity(param_0) == 0.0f) {
            if (func_8008D714(param_0)) {
                local_0 = 0xB8;
            } else if (func_8008D790(param_0)) {
                _baduo_entrypoint_12(param_0);
                return;
            }
        }
    }
    if (func_8008E148(param_0)) {
        local_0 = _badrone_entrypoint_25(param_0);
    }
    if (player_inWater(param_0)) {
        local_0 = 0x2D;
    }
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

s32 bswalk_entrypoint_12(s32 param_0) {
    if (func_8008E0E8()) {
        _bapackctrl_entrypoint_5(param_0, 3);
    }
}

int bswalk_entrypoint_13(s32 param_0)
{
  return D_80801540_bswalk[param_0];
}

void bswalk_entrypoint_14(PlayerState *param_0)
{
    void *local_0;
    f32 local_1;
    s32 local_2;
    local_0 = baanim_getAnimCtrlPtr(param_0);
    local_1 = 0.0f;
    local_2 = 1;
    switch (bs_getPreviousState(param_0)) {
    case 1:
    case 2: if (func_8009BB5C(param_0) < 200.0f) _badust_entrypoint_3(param_0, 0.0f, 0.0f); break;
    case 12: local_2 = 0; break;
    case 3: local_1 = func_8008C0C8(func_8008AEDC(local_0)); break;
    }
    anctrl_reset(local_0);
    anctrl_setSmoothTransition(local_0, local_2);
    anctrl_setIndex(local_0, 12);
    anctrl_setDuration(local_0, 0.66f);
    func_8008B1C8(local_0, 0.1f);
    anctrl_setStart(local_0, local_1);
    anctrl_setPlaybackType(local_0, 2);
    anctrl_start(local_0);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 225.0f, 500.0f, 0.54f, 0.44f);
    func_8009BFE4(param_0, 1000.0f, 12.0f);
    baroll_setAngularVelocity(param_0, 1000.0f, 12.0f);
    func_808001D8_bswalk(param_0, 0.3f);
    bastick_resetZones(param_0);
    if (func_8008E0E8(param_0)) _bapackctrl_entrypoint_5(param_0, 2);
}

void bswalk_entrypoint_15(PlayerState *param_0)
{
    extern void func_8009D2F0(PlayerState *, s32, f32);
    extern void func_800A2CE8(PlayerState *, f32, s32);
    extern s32 func_8009BCD4(PlayerState *, f32);
    extern f32 func_8009BB5C(PlayerState *);
    extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 local_0;
    local_0 = 0;
    func_8080016C_bswalk(param_0);
    func_8009D2F0(param_0, 0, 0.5f);
    func_800A2CE8(param_0, 0.4f, 4);
    func_800A2CE8(param_0, 0.9f, 3);
    func_808001E4_bswalk(param_0);
    func_80800000_bswalk(param_0);
    switch (bastick_getZone(param_0)) {
    case 0:
        if (func_8009BCD4(param_0, 18.0f)) { local_0 = 1; }
        if (bainput_should_enter_first_person(param_0)) { local_0 = _badrone_entrypoint_24(param_0); }
        break;
    case 1:
    case 2:
        if (func_8009BCD4(param_0, 150.0f)) { local_0 = 2; }
        if (bainput_should_enter_first_person(param_0)) { local_0 = _badrone_entrypoint_24(param_0); }
        break;
    case 3:
        if (func_8009BCD4(param_0, 225.0f) && func_80800220_bswalk(param_0)) { local_0 = 3; }
        if (bainput_should_enter_first_person(param_0)) { local_0 = _badrone_entrypoint_24(param_0); }
        break;
    }
    if (func_8008DE24(param_0)) { local_0 = 0x7A; }
    if (func_8008E300(param_0) && func_8009BB5C(param_0) > 125.0f) { local_0 = 0xC; }
    if (func_8008DD04(param_0)) { local_0 = 0x2F; }
    if (bakey_held(param_0, 1)) { local_0 = 7; }
    local_0 = func_80800248_bswalk(param_0, local_0);
    if (bakey_pressed(param_0, 8)) {
        local_0 = bs_getTypeOfJump(param_0);
        if (baphysics_get_target_horizontal_velocity(param_0) == 0.0f) {
            if (func_8008D714(param_0)) {
                local_0 = 0xB8;
            } else if (func_8008D790(param_0)) {
                _baduo_entrypoint_12(param_0);
                return;
            }
        }
    }
    if (func_8008E148(param_0)) { local_0 = _badrone_entrypoint_25(param_0); }
    if (player_inWater(param_0)) { local_0 = 0x2D; }
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

void bswalk_entrypoint_16(s32 param_0) {
    func_8009BF5C(param_0, 0);
    baroll_setIdeal(param_0, 0);
    if (func_8008E0E8(param_0) != 0) {
        _bapackctrl_entrypoint_5(param_0, 3);
    }
}

int bswalk_entrypoint_17(s32 param_0)
{
  return D_80801550_bswalk[param_0];
}

void bswalk_entrypoint_18(s32 arg0) 
{
}
void bswalk_entrypoint_19(PlayerState *param_0)
{
    baanim_playForDuration_loopSmooth(param_0, 0xB, 0.43f);
    func_8009FFD8(param_0, 2, 1, 1, 2);
    baanim_setDurationRange(param_0, 0.3f, 1.5f);
    func_8008C9F0(param_0, 30.0f, 150.0f, 1.2f, 0.9f);
}

void bswalk_entrypoint_20(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    func_8080016C_bswalk(param_0);
    func_800A2CE8(param_0, 0.4f, 4);
    func_800A2CE8(param_0, 0.9f, 3);
    func_80800000_bswalk(param_0);
    if (!func_8008DE24(param_0)) {
        local_0 = 2;
    }
    if (!bastick_getZone(param_0)) {
        local_0 = 1;
    }
    if (bainput_should_enter_first_person(param_0)) {
        local_0 = _badrone_entrypoint_24(param_0);
    }
    if (func_8008DD04(param_0)) {
        local_0 = 0x2F;
    }
    if (bakey_held(param_0, 1)) {
        local_0 = 7;
    }
    local_0 = func_80800248_bswalk(param_0, local_0);
    if (bakey_pressed(param_0, 8)) {
        local_0 = bs_getTypeOfJump(param_0);
    }
    if (func_8008E148(param_0)) {
        local_0 = _badrone_entrypoint_25(param_0);
    }
    if (player_inWater(param_0)) {
        local_0 = 0x2D;
    }
    bs_setState(param_0, func_800A02DC(param_0, local_0));
}

int bswalk_entrypoint_21(s32 param_0)
{
  return D_80801560_bswalk[param_0];
}

void bswalk_entrypoint_22(PlayerState *param_0, f32 param_1)
{
    if (param_1 < 150.0f) {
        func_8009FF44(param_0, 3, 80.0f, 150.0f, 1.3f, 0.6f);
    } else {
        func_8009FF44(param_0, 12, 225.0f, 500.0f, 0.54f, 0.44f);
    }
}
