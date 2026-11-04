#include "common.h"
#include "overlays/ba/playerstate.h"
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
typedef struct {
    f32 yaw;
    f32 speed;
    s32 new_state;
    AnimCtrl *anim;
} StoneMotion61;
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
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopStartingAt(PlayerState *, s32, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_800909CC(PlayerState *);

void func_80800000_bsstonehead(player) s32 player;
{

if (func_8009E74C(player, 3) == 0) {
    func_800947EC(player, 1, 0);
    func_80095A40(player);
    func_80092864(player, 0x3F800000);
    func_80095A74(player, 0);
}

}

int func_80800060_bsstonehead(player)
s32 player;
{
    s32 player_copy;
    // Matching: the copy and `| 0` are needed for the match.
    player_copy = player | 0;

if (!func_8009E77C(player_copy, 3)) {
    func_800959C8(player_copy, 0x42820000, 0x420C0000);
    func_80092864(player_copy, 0x3F666600);
    func_800947EC(player_copy, 1, 1);
    func_80095A74(player_copy, 1);
}

}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

// Sets the target ground speed from the stick position.
void func_808000CC_bsstonehead(PlayerState *player)
{
    f32 stick_pos;
    f32 max_speed;

    stick_pos = bastick_getZonePosition(player);
    if (_baattach_entrypoint_1(player))
        max_speed = 250.0f;
    else if (func_8008DE24(player) && player_isStable(player))
        max_speed = 80.0f;
    else
        max_speed = 400.0f;
    if (!bastick_getZone(player))
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    else
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, max_speed));
}

// Charge/dash: switches between its sub-states (1 start, 2 hold, 3 slow down, 0 exit).
void func_80800194_bsstonehead(PlayerState *player, s32 state)
{
    StoneMotion61 motion;
    motion.new_state = state;

    motion.anim = baanim_getAnimCtrlPtr(player);

if (player->unk15C.word == 0) {
    func_80800060_bsstonehead(player, motion.new_state);
}

player->unk15C.word = motion.new_state;

switch (motion.new_state) {
    case 1:
        if (func_8008DE24(player) && player_isStable(player)) {
            player->unk16C = 150.0f;
        } else {
            player->unk16C = 600.0f;
        }
        func_8009DF94(player, 0x5A7, 1.4f, 22000);
        baflag_set(player, 0x20);
        _batimer_set(player, 0, 0x3C23D70A);
        func_8009FFD8(player, 1, 1, 3, 3);
        _badust_entrypoint_12(player, 2);
        baphysics_set_target_yaw(player, yaw_getIdeal(player));
        baphysics_set_target_horizontal_velocity(player, player->unk16C);
        motion.yaw = yaw_getIdeal(player);
        motion.speed = baphysics_get_target_horizontal_velocity(player);
        baphysics_set_horizontal_velocity(player, motion.yaw, motion.speed);
        anctrl_reset(motion.anim);
        anctrl_setIndex(motion.anim, 0x64);
        anctrl_setDuration(motion.anim, 1.0f);
        anctrl_setSubrange(motion.anim, 0.0f, 0.26f);
        anctrl_setPlaybackType(motion.anim, 1);
        anctrl_start(motion.anim);
        return;
    case 2:
        anctrl_setDuration(motion.anim, 5.0f);
        baanim_setEnd(player, 0.3078f);
        return;
    case 3:
        _badust_entrypoint_12(player, 1);
        baflag_clear(player, 0x20);
        anctrl_setDuration(motion.anim, 1.0f);
        baanim_setEnd(player, 1.0f);
        return;
    case 0:
        _badust_entrypoint_12(player, 1);
        baflag_clear(player, 0x20);
        func_80800000_bsstonehead(player);
}

}

// Button 8 pressed and not blocked by flag 0x65A.
int func_808003B8_bsstonehead(PlayerState *player)
{
    return (bakey_pressed(player, 8) != 0) && (func_800DA298(0x65A) == 0);

}

s32 func_808003F4_bsstonehead(PlayerState *player, s32 next_state)
{
    if (bainput_should_enter_first_person(player)) {
        next_state = _badrone_entrypoint_24(player);
    }

if (bastick_getZone(player) > 0) {
    next_state = 0xB2;
}

if (func_808003B8_bsstonehead(player)) {
    next_state = 0xAE;
}

return next_state;
}

void bsstonehead_entrypoint_0(s32 player)
{
    func_80800194_bsstonehead(player, 0);
}

void bsstonehead_entrypoint_1(u8 *player)
{
    (*(s32 *) ((s8 *) (player) + (0x15C))) = 0;
    func_80800194_bsstonehead(player, 1);
}

void bsstonehead_entrypoint_2(PlayerState *player)
{
    s32 next_state;

    next_state = 0;

switch (player->unk15C.word) {
    case 1:
        if (baanim_isStopped(player)) {
            func_80800194_bsstonehead(player, 2);
        }
        break;
    case 2:
        _batimer_decrement(player, 0);
        if (_batimer_isZero(player, 0)) {
            player->unk16C -= 80.0f;
            baphysics_set_target_horizontal_velocity(player, player->unk16C);
            if (player->unk16C < 200.0f) {
                func_80800194_bsstonehead(player, 3);
            }
        }
        break;
    case 3:
        func_800F1574(&player->unk16C, 0.8f);
        if (baanim_isStopped(player)) {
            next_state = 0xB3;
        }
        if (baanim_getTimer(player) > 0.8f) {
            next_state = func_808003F4_bsstonehead(player, next_state);
        }
}

bs_setState(player, next_state);
}

int bsstonehead_entrypoint_3(s32 index)
{
    return D_80801630_bsstonehead[index];
}

void func_808005F0_bsstonehead(PlayerState *player, s32 state)
{
    AnimCtrl *anim;

switch (state) {
    case 1:
        anim = baanim_getAnimCtrlPtr(player);
        player->unk16C = 250.0f;
        _basudie_entrypoint_2(player, 250.0f, 420.0f, -1200.0f);
        anctrl_reset(anim);
        anctrl_setSmoothTransition(anim, 0);
        anctrl_setIndex(anim, 0x33);
        anctrl_setSubrange(anim, 0, 0.46f);
        anctrl_setDuration(anim, 2.5f);
        anctrl_setPlaybackType(anim, 1);
        anctrl_start(anim);
        func_8009D820(player, 1.8f);
        break;
    case 2:
        baanim_setEnd(player, 1.0f);
        func_8009DF94(player, 0x417, 0.8f, 0x4650);
        func_8009DF18(player, 0x428, 1.8f, 0x4650);
    case 3:
        break;
}

player->unk15C.word = state;
}

void bsstonehead_entrypoint_4(Actor *player)
{
    func_80800060_bsstonehead();
    *(int *) ((char *) player + 0x15c) = 0;
    func_808005F0_bsstonehead(player, 1);
}

void bsstonehead_entrypoint_5(PlayerState *player)
{
    _basudie_entrypoint_5(player);
    baphysics_set_target_horizontal_velocity(player, player->unk16C);

switch (player->unk15C.word) {
    case 1:
        if (player_isStable(player))
            func_808005F0_bsstonehead(player, 2);
        break;
    case 2:
        func_808005F0_bsstonehead(player, 3);
        break;
    case 3:
        if (player->unk16C > 0.0f)
            player->unk16C = func_800F0E00(0.0f, player->unk16C - 10.0f);
}

bs_setState(player, 0);
}

void bsstonehead_entrypoint_6()
{
    _basudie_entrypoint_6();
}

int bsstonehead_entrypoint_7(s32 index)
{
    return D_80801640_bsstonehead[index];
}

void bsstonehead_entrypoint_8(s32 player)
{
    func_80800060_bsstonehead();
    _bsdrone_entrypoint_0(player);
}
void bsstonehead_entrypoint_9(PlayerState *self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstonehead_entrypoint_10(s32 player)
{
    func_80800000_bsstonehead();
    _bsdrone_entrypoint_2(player);
}
int bsstonehead_entrypoint_11(s32 index)
{
    return D_80801650_bsstonehead[index];
}

void func_808008CC_bsstonehead(Actor *player, s32 state)
{
    s32 anim;

switch (state) {
    case 0:
        break;

    case 1:
        anim = baanim_getAnimCtrlPtr(player);
        anctrl_reset((void *) anim);
        anctrl_setIndex((void *) anim, 0x122);
        anctrl_setStart((void *) anim, 0.6364f);
        anctrl_setSubrange((void *) anim, 0.6364f, 0.7576f);
        anctrl_setDuration((void *) anim, 4.0f);
        anctrl_setPlaybackType((void *) anim, 1);
        anctrl_start((void *) anim);
        func_8009FFD8(player, 1, 1, 3, 6);
        break;

    case 2:
        baanim_setEndAndDuration(player, 1.0f, 0.8f);
        break;

    case 3:
        func_800A2E18(player);
        // Matching: the (double) cast is needed for the match.
    baphysics_set_target_horizontal_velocity(player, (double) 0);
}

*((s32 *) (((char *) player) + 0x15C)) = state;
}

void bsstonehead_entrypoint_12(s32 player)
{
    func_808008CC_bsstonehead(player, 0);
    func_80800000_bsstonehead(player);
}

void bsstonehead_entrypoint_13(Actor *player)
{
    func_80800060_bsstonehead();
    *(s32 *) ((char *) player + 0x15c) = 1;
    func_808008CC_bsstonehead(player, 1);
}

int bsstonehead_entrypoint_14(void *player)
{
    s32 next_state;
    char *state_ptr;
    next_state = 0;
    func_808000CC_bsstonehead(player);

// Matching: the do/while (0) wrapper is needed for the match.
do {
    func_8009D3A8(player, 0);
    state_ptr = (char *) player + 0x15c;
} while (0);
switch (*(s32 *) state_ptr) {
    case 1:
        if (func_8008DF8C(player, 0x82)) {
            func_808008CC_bsstonehead(player, 2);
        }
        break;

    case 2:
        if (player_isStable(player)) {
            func_808008CC_bsstonehead(player, 3);
        }
        break;

    case 3:
        if (baanim_isStopped(player)) {
            next_state = 0xB3;
        }
}

if (player_isStable(player)) {
    next_state = func_808003F4_bsstonehead(player, next_state);
}

bs_setState(player, next_state);
}

int bsstonehead_entrypoint_15(s32 index)
{
    return D_80801660_bsstonehead[index];
}

void func_80800B38_bsstonehead(player, state) PlayerState *player;
s32 state;
{
    AnimCtrl *anim;
    f32 stick_angle;
    f32 yaw;

switch (state) {
    case 0:
        baphysics_set_target_horizontal_velocity(player, 0.0f);
        baphysics_reset_gravity(player);
        break;
    case 1:
        anim = baanim_getAnimCtrlPtr(player);
        _baattach_entrypoint_6(player, 3, 0, 0);
        anctrl_reset(anim);
        anctrl_setIndex(anim, 0x122);
        anctrl_setDuration(anim, 0.8f);
        anctrl_setSubrange(anim, 0.0f, 0.636399984360f);
        anctrl_setPlaybackType(anim, 1);
        anctrl_start(anim);
        func_8009FFD8(player, 1, 1, 3, 6);
        if (0.0f != bastick_distance(player)) {
            stick_angle = bastick_getAngleRelativeToBanjo(player);
            yaw_setIdeal(player, stick_angle);
        }
        baphysics_set_target_yaw(player, yaw_getIdeal(player));
        func_808000CC_bsstonehead(player);
        yaw = yaw_getIdeal(player);
        baphysics_set_horizontal_velocity(player, yaw,
                                          baphysics_get_target_horizontal_velocity(player));
        baphysics_set_vertical_velocity(player, 576.0f);
        baphysics_set_gravity(player, -1200.0f);
        func_8009D7A4(player, 1.35f, 1.45f);
        break;
    case 2:
        baanim_setEndAndDuration(player, 0.757600009441f, 4.0f);
        break;
    case 3:
        baanim_setEndAndDuration(player, 1.0f, 0.8f);
        break;
    case 4:
        func_800A2E18(player);
}

player->unk15C.word = state;
}

void bsstonehead_entrypoint_16(s32 player)
{
    func_80800B38_bsstonehead(player, 0);
    func_80800000_bsstonehead(player);
}

void bsstonehead_entrypoint_17(Actor *player)
{
    func_80800060_bsstonehead();
    *(int *) ((char *) player + 0x15c) = 0;
    func_80800B38_bsstonehead(player, 1);
}

void bsstonehead_entrypoint_18(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_808000CC_bsstonehead(player);

if (bakey_released(player, 8) && baphysics_get_vertical_velocity(player) > 0.0f) {
    baphysics_reset_gravity(player);
}

switch (player->unk15C.word) {
    case 1:
        if (func_8008DF8C(player, 0x82))
            func_80800B38_bsstonehead(player, 3);
        else if (baanim_isStopped(player))
            func_80800B38_bsstonehead(player, 2);
        break;
    case 2:
        if (func_8008DF8C(player, 0x82))
            func_80800B38_bsstonehead(player, 3);
        break;
    case 3:
        func_8009D3A8(player, 0);
        if (player_isStable(player))
            func_80800B38_bsstonehead(player, 4);
        break;
    case 4:
        func_8009D3A8(player, 0);
        if (baanim_isStopped(player))
            next_state = 0xB3;
}

if (player_isStable(player))
    next_state = func_808003F4_bsstonehead(player, next_state);
bs_setState(player, next_state);
}

int bsstonehead_entrypoint_19(s32 index)
{
    return D_80801670_bsstonehead[index];
}

void bsstonehead_entrypoint_20(PlayerState *player)
{
    func_80800060_bsstonehead(player);
    baanim_playForDuration_loopStartingAt(player, 0x62, 0.8f, 0.4f);
    func_8009FFD8(player, 2, 1, 1, 2);
    func_8008C9F0(player, 30.0f, 400.0f, 1.0f, 0.45f);
    func_800909CC(player);
}

void bsstonehead_entrypoint_21(s32 player)
{
    s32 next_state;

    next_state = 0;
    func_8009D3A8(player, 0);
    func_808000CC_bsstonehead(player);
    func_800A2CE8(player, 0x3DCCCCCD, 4);
    func_800A2CE8(player, 0x3F19999A, 3);

if ((bastick_getZone(player) == 0) && (func_8009BCD4(player, 0x3F800000) != 0)) {
    next_state = 0xB3;
}

if (func_8008E148(player) != 0) {
    next_state = _badrone_entrypoint_25(player);
}

if (func_8008DD04(player) != 0) {
    next_state = 0xAD;
}

if (func_808003B8_bsstonehead(player) != 0) {
    next_state = 0xAE;
}

if (bakey_pressed(player, 9) != 0) {
    next_state = 0xB4;
}

if (bakey_newlyReleased(player, 1) != 0) {
    _baattach_entrypoint_6(player, 1, bakey_func_80091940(player, 1, 1), 0);
}

bs_setState(player, next_state);
}

void bsstonehead_entrypoint_22(s32 player)
{
    func_80800000_bsstonehead();
    func_80090A2C(player);
}
int bsstonehead_entrypoint_23(s32 index)
{
    return D_80801680_bsstonehead[index];
}

void bsstonehead_entrypoint_24(s32 player)
{
    _baspin_entrypoint_1();
    func_80800000_bsstonehead(player);
}
int bsstonehead_entrypoint_25(Actor *player)
{
    func_80800060_bsstonehead();
    _baattach_entrypoint_6(player, 3, 0, 0);
    _baspin_entrypoint_2(player, 99, 0x3FE66666, 2, 0);
}

int bsstonehead_entrypoint_26(Actor *player)
{
    s32 next_state;
    next_state = 0;

if (_baspin_entrypoint_3(player) == 2) {
    next_state = 0xB3;
}

bs_setState(player, next_state);
}

int bsstonehead_entrypoint_27(s32 index)
{
    return D_80801690_bsstonehead[index];
}

void bsstonehead_entrypoint_28(s32 player)
{
    _babounce_entrypoint_3();
    func_80800000_bsstonehead(player);
}
int bsstonehead_entrypoint_29(Actor *player)
{
    func_80800060_bsstonehead();
    _baattach_entrypoint_6(player, 3, 0, 0);
    _babounce_entrypoint_4(player, 2);
    _babounce_entrypoint_5(player, 0x122, 0x3F4075F7);
}

s32 bsstonehead_entrypoint_30(s32 player)
{
    s32 next_state = 0;

if (_babounce_entrypoint_2(player)) {
    func_808000CC_bsstonehead(player);
}

if (_babounce_entrypoint_9(player)) {
    next_state = 0xB3;
}

bs_setState(player, next_state);
}

int bsstonehead_entrypoint_31(s32 index)
{
    return D_808016A0_bsstonehead[index];
}

void bsstonehead_entrypoint_32(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800000_bsstonehead(player);
}
void bsstonehead_entrypoint_33(s32 player)
{
    func_80800060_bsstonehead();
    _bsrest_entrypoint_16(player);
}
s32 bsstonehead_entrypoint_34(Actor *this)
{
    s32 next_state = 0;
    if (_bsrest_entrypoint_20(this))
        next_state = _bsrest_entrypoint_13(this);

    bs_setState(this, next_state);
}

int bsstonehead_entrypoint_35(s32 index)
{
    return D_808016B0_bsstonehead[index];
}

void bsstonehead_entrypoint_36()
{
    func_80800000_bsstonehead();
}

int bsstonehead_entrypoint_37(Actor *player)
{
    s32 player_copy;
    player_copy = player;
    func_80800060_bsstonehead(player);
    baanim_playForDuration_loopSmooth(player_copy, 0x63, 6.1f);
    func_8009FFD8(player_copy, 1, 1, 3, 3);
    baphysics_set_target_horizontal_velocity(player_copy, 0);
    _batimer_set(player_copy, 1, 0x40400000);
}

void bsstonehead_entrypoint_38(PlayerState *player)
{
    s32 next_state;
    f32 spin_delta;
    f32 spin_speed;

    next_state = 0;
    spin_speed = func_800F10B4(_batimer_get(player, 1), 0.0f, 3.0f, 30.0f, 800.0f);
    spin_delta = func_800D8FF8() * spin_speed;
    yaw_setIdeal(player, yaw_getIdeal(player) + spin_delta);
    yaw_applyIdeal(player);

if (_batimer_decrement(player, 1)) {
    next_state = 0xB3;
}

bs_setState(player, next_state);
}

int bsstonehead_entrypoint_39(s32 index)
{
    return D_808016C0_bsstonehead[index];
}

void bsstonehead_entrypoint_40(s32 player)
{
    func_80800000_bsstonehead();
    func_80090A2C(player);
}
int bsstonehead_entrypoint_41(Actor *player)
{
    s32 player_copy;
    player_copy = player;
    func_80800060_bsstonehead(player);
    baanim_playForDuration_loopSmooth(player_copy, 0x63, 6.1f);
    func_8009FFD8(player_copy, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(player_copy, 0x0);
    func_800909CC(player_copy);
}

void bsstonehead_entrypoint_42(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    if (func_8008DD04(player))
        next_state = 0xAD;
    next_state = func_808003F4_bsstonehead(player, next_state);
    if (func_8008E148(player))
        next_state = _badrone_entrypoint_25(player);
    if (bakey_pressed(player, 9))
        next_state = 0xB4;

if (bakey_newlyReleased(player, 1)) {
    _baattach_entrypoint_6(player, 1, bakey_func_80091940(player, 1, 1), 0);
}

if (bainput_should_enter_first_person(player))
    next_state = _badrone_entrypoint_24(player);
bs_setState(player, func_800A02DC(player, next_state));
}

int bsstonehead_entrypoint_43(s32 index)
{
    return D_808016D0_bsstonehead[index];
}

// TU-NOTE: the .data of this overlay (formerly asm/data/overlays/bs/stonehead.data.s) is defined here in C.
// The tables hold pointers to functions of this file; IDO's assembler schedules some of these functions
// differently unless the tables are defined in the same unit. Values are taken from the ROM.
extern void _bsstonehead_entrypoint_0();
extern void _bsstonehead_entrypoint_1();
extern void _bsstonehead_entrypoint_2();
extern void func_80099B94();
extern void _bsstonehead_entrypoint_6();
extern void _bsstonehead_entrypoint_4();
extern void _bsstonehead_entrypoint_5();
extern void _basudie_entrypoint_11();
extern void _bsstonehead_entrypoint_10();
extern void _bsstonehead_entrypoint_8();
extern void _bsstonehead_entrypoint_9();
extern void _bsdrone_entrypoint_3();
extern void _bsstonehead_entrypoint_12();
extern void _bsstonehead_entrypoint_13();
extern void _bsstonehead_entrypoint_14();
extern void _bsstonehead_entrypoint_16();
extern void _bsstonehead_entrypoint_17();
extern void _bsstonehead_entrypoint_18();
extern void _bsstonehead_entrypoint_22();
extern void _bsstonehead_entrypoint_20();
extern void _bsstonehead_entrypoint_21();
extern void _bsstonehead_entrypoint_24();
extern void _bsstonehead_entrypoint_25();
extern void _bsstonehead_entrypoint_26();
extern void func_80099AA8();
extern void _bsstonehead_entrypoint_28();
extern void _bsstonehead_entrypoint_29();
extern void _bsstonehead_entrypoint_30();
extern void _bsstonehead_entrypoint_32();
extern void _bsstonehead_entrypoint_33();
extern void _bsstonehead_entrypoint_34();
extern void _bsstonehead_entrypoint_36();
extern void _bsstonehead_entrypoint_37();
extern void _bsstonehead_entrypoint_38();
extern void _bsstonehead_entrypoint_40();
extern void _bsstonehead_entrypoint_41();
extern void _bsstonehead_entrypoint_42();
s32 D_80801630_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_0, (u32) _bsstonehead_entrypoint_1,
                                 (u32) _bsstonehead_entrypoint_2, (u32) func_80099B94};
s32 D_80801640_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_6, (u32) _bsstonehead_entrypoint_4,
                                 (u32) _bsstonehead_entrypoint_5, (u32) _basudie_entrypoint_11};
s32 D_80801650_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_10, (u32) _bsstonehead_entrypoint_8,
                                 (u32) _bsstonehead_entrypoint_9, (u32) _bsdrone_entrypoint_3};
s32 D_80801660_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_12, (u32) _bsstonehead_entrypoint_13,
                                 (u32) _bsstonehead_entrypoint_14, (u32) func_80099B94};
s32 D_80801670_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_16, (u32) _bsstonehead_entrypoint_17,
                                 (u32) _bsstonehead_entrypoint_18, (u32) func_80099B94};
s32 D_80801680_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_22, (u32) _bsstonehead_entrypoint_20,
                                 (u32) _bsstonehead_entrypoint_21, (u32) func_80099B94};
s32 D_80801690_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_24, (u32) _bsstonehead_entrypoint_25,
                                 (u32) _bsstonehead_entrypoint_26, (u32) func_80099AA8};
s32 D_808016A0_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_28, (u32) _bsstonehead_entrypoint_29,
                                 (u32) _bsstonehead_entrypoint_30, (u32) func_80099B94};
s32 D_808016B0_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_32, (u32) _bsstonehead_entrypoint_33,
                                 (u32) _bsstonehead_entrypoint_34, (u32) func_80099B94};
s32 D_808016C0_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_36, (u32) _bsstonehead_entrypoint_37,
                                 (u32) _bsstonehead_entrypoint_38, (u32) func_80099B94};
s32 D_808016D0_bsstonehead[4] = {(u32) _bsstonehead_entrypoint_40, (u32) _bsstonehead_entrypoint_41,
                                 (u32) _bsstonehead_entrypoint_42, (u32) func_80099B94};
