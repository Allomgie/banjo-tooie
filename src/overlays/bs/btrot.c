// Talon Trot (Kazooie carries Banjo), including the shoe variants (turbo, springy, claw).
// Each state is a 4-entry table: end, start, update, interrupt handler.
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/anctrl.h"
extern f32 func_800F1214(f32, f32, f32);

extern s32 func_8008DE24(s32);
extern AnimCtrl *baanim_getAnimCtrlPtr();
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern int func_8009CA70(void *param_0, int param_1, int param_2);
extern int bs_getPreviousState(void);
extern void _bashoes_entrypoint_15(void *param_0);
extern void bastick_setZoneMax(void *param_0, int param_1, int param_2);
extern void func_800A0CF4(void *param_0, int param_1);
extern void func_800A0CE8(void *param_0, int param_1);
extern void func_8009BFE4(PlayerState *, f32, f32);
extern void baroll_setAngularVelocity(void *param_0, int param_1, int param_2);
extern void baflag_set(void *param_0, int param_1);
extern void func_80094F14(void *param_0, int param_1, int param_2, f32 param_3);
extern void func_800931AC(void *param_0, int param_1);
extern void func_8009E4AC(void *param_0);
extern s32 bs_getNextState();
extern void func_8009BF5C(PlayerState *, f32);
extern void baroll_setIdeal(PlayerState *, f32);
extern void bastatetimer_set(PlayerState *, s32, f32);
extern s32 D_80802E50_bsbtrot[];
extern s32 D_80802E60_bsbtrot[];
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern s32 D_80802E70_bsbtrot[];
extern void yaw_setUpdateType(PlayerState *, s32);
extern void func_8009D2D8(PlayerState *, s32);
extern void baphysics_set_type(PlayerState *, s32);
extern f32 bastick_distance(PlayerState *);
extern f32 bastick_getAngleRelativeToBanjo(PlayerState *);
extern void yaw_setIdeal(PlayerState *, f32);
extern f32 yaw_getIdeal(PlayerState *);
extern void baphysics_set_target_yaw(PlayerState *, f32);
extern f32 baphysics_get_target_horizontal_velocity(PlayerState *);
extern void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
extern void baphysics_set_vertical_velocity(PlayerState *, f32);
extern void baphysics_set_gravity(PlayerState *, f32);
extern void func_8009DE38(PlayerState *, s32, f32);
extern s32 D_80802E80_bsbtrot[];
extern void func_8008CA4C(s32, s32);
extern s32 D_80802E90_bsbtrot[];
extern f32 func_800D8FF8(void);
extern f32 func_800F0E00(f32, f32);
extern f32 func_8009BFD8(PlayerState *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800963C0(PlayerState *, f32 *);
extern void func_800F1EA4(f32 *, f32 *);
extern s32 D_80802EA0_bsbtrot[];
extern s32 D_80802EB0_bsbtrot[];
extern s32 D_80802EC0_bsbtrot[];
extern void baanim_playForDuration_once(PlayerState *, s32, f32);
extern void func_8009D89C(PlayerState *, f32);
extern void func_8009C128(PlayerState *, f32 *);
extern void func_800A32C4(PlayerState *, f32 *);
extern void func_800F1E6C(f32 *, f32 *, f32 *);
extern f32 func_800136E4(f32);
extern f32 _bareact_entrypoint_4(PlayerState *);
extern f32 _bareact_entrypoint_3(PlayerState *);
extern f32 _bareact_entrypoint_5(PlayerState *);
extern s32 D_80802ED0_bsbtrot[];
extern s32 D_80802EE0_bsbtrot[];
extern void func_8009DEC0(PlayerState *, s32, f32, f32, s32, s32);
extern s32 D_80802EF0_bsbtrot[];
extern void baanim_setEndAndDuration(PlayerState *, f32, f32);
extern void baanim_setEnd(PlayerState *, f32);
extern s32 D_80802F00_bsbtrot[];
extern void func_800956B8(s32);
extern void _bashoessuck_entrypoint_4(s32);
extern s32 func_8009BCD4(s32, f32);
extern s32 func_8008E40C();
extern s32 bakey_pressed(s32, s32);
extern s32 player_inWater(s32);
extern s32 _bamovespline_entrypoint_1(s32, f32);
extern s32 _bamovespline_entrypoint_3(s32);
extern s32 _bamovespline_entrypoint_2(s32);
extern s32 _bashoes_entrypoint_2(s32);
extern void _bashoessuck_entrypoint_1(s32, s32 *);
extern s32 _badrone_entrypoint_23(s32, s32 *);
extern void bs_setState(s32, s32);
extern s32 D_80802F10_bsbtrot[];
extern s32 D_80802F20_bsbtrot[];
extern f32 func_800F13C4(f32, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern void func_800A2D2C(PlayerState *, f32, s32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern f32 func_8009BBB8(PlayerState *);
extern void func_8008CA30(PlayerState *, f32);
extern f32 baanim_getTimer(PlayerState *);
extern void func_8009BB24(PlayerState *, f32 *);
extern s32 baanim_isAt(PlayerState *, f32);

// Picks a value by shoe type: claw, turbo, springy, else normal.
int func_80800000_bsbtrot(s32 player, s32 normal, s32 turbo, s32 springy, s32 claw)
{
    if (func_8008E40C(player)) {
        return claw;
    }
    if (func_8008E3E8(player)) {
        return turbo;
    }
    if (func_8008E430(player)) {
        return springy;
    }
    return normal;
}

// Float version of func_80800000_bsbtrot.
f32 func_80800070_bsbtrot(f32 player[3], f32 normal, f32 turbo, f32 springy, f32 claw)
{
    if (func_8008E40C()) {
        return claw;
    }
    if (func_8008E3E8(player)) {
        return turbo;
    }
    if (func_8008E430(player)) {
        return springy;
    }
    return normal;
}

void func_808000DC_bsbtrot(s32 player, s32 unk_1)
{
    if (unk_1 != 0) {
        func_8009DE38(player, 0x4433, 0.96f);
    } else {
        func_8009DE38(player, 0x4433, 1.04f);
    }
}

s32 func_80800120_bsbtrot(player) void *player;
{
    if (bakey_pressed(player, 9) != 0 && func_8008E39C(player) != 0) {
        _bashoes_entrypoint_6(player, 2);
    }
}

f32 func_80800164_bsbtrot(s32 player)
{
    if (func_8008DE24(player)) {
        return 300.0f;
    }
    return func_80800070_bsbtrot(player, 700.0f, 1000.0f, 700.0f, 700.0f);
}

f32 func_808001B8_bsbtrot(s32 player)
{
    func_80800070_bsbtrot(player, 30.0f, 80.0f, 30.0f, 30.0f);
}

f32 func_808001EC_bsbtrot(s32 player)
{
    if (func_8008DE24(player)) {
        return 0.7f;
    }
    return func_80800070_bsbtrot(player, 0.34f, 0.29f, 0.7f, 0.53f);
}

f32 func_80800248_bsbtrot(s32 player)
{
    if (func_8008DE24(player)) {
        return 0.8f;
    }
    return func_80800070_bsbtrot(player, 0.56f, 0.51f, 1.2f, 1.4f);
}

void func_808002A4_bsbtrot(player, anim_id) PlayerState *player;
s32 anim_id;
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (anctrl_getIndex(anim_ctrl) != anim_id) {
        anctrl_setIndex(anim_ctrl, anim_id);
        anctrl_setStart(anim_ctrl, anctrl_getAnimTimer(anim_ctrl));
        anctrl_start(anim_ctrl);
    }
}

// Interrupt handler (cases 0x12, 0x8D, 0x58); also the 4th entry of several state tables.
void func_80800308_bsbtrot(Actor *actor)
{
    f32 unk_0[3];

    switch (func_8009E6EC()) {
        case 0x12:
            *(s32 *) ((char *) actor + 0x164) = 1;
            return;
        case 0x8D:
            *(s32 *) ((char *) actor + 0x164) = 1;
            func_8009E830(actor, 2);
            return;
        case 0x58:
            if ((*(s32 *) ((char *) actor + 0x160) == 0) && (func_8008E40C(actor) != 0)) {
                switch (bs_getCurrentState(actor)) {
                    case 0x16:
                    case 0x95:
                        func_80099A7C(actor, unk_0);
                        if (_bashoessuck_entrypoint_5(actor, unk_0) != 0) {
                            *(s32 *) ((char *) actor + 0x160) = 1;
                            bs_setState(actor, 0x17C);
                        }
                }
            }
            return;
        default:
            func_80099B94(actor);
    }
}

s32 func_808003F0_bsbtrot(Actor *actor)
{
    if (func_8009E6EC() == 0x8d) {
        *(s32 *) ((char *) actor + 0x164) = 1;
        func_80800308_bsbtrot(actor);
    } else {
        func_80099B94(actor);
    }
}

extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);

void func_80800438_bsbtrot(PlayerState *player)
{
    f32 stick_pos;
    f32 speed;
    f32 max_speed;
    f32 min_speed;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0)
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    else {
        min_speed = func_808001B8_bsbtrot(player);
        max_speed = func_80800164_bsbtrot(player);
        speed = func_800F1214(stick_pos, min_speed, max_speed);
        baphysics_set_target_horizontal_velocity(player, speed);
    }
}

void func_808004B4_bsbtrot(player) void *player;
{
    if (func_8008E3E8(player) && bastick_getZone(player) == 1 &&
        bastick_getZonePosition(player) > 0.8f) {
        func_800962B0(player, 1);
    } else {
        func_800962B0(player, 0);
    }
}

// Common setup when entering a talon trot state.
void func_80800538_bsbtrot(player) void *player;
{
    if (!func_8009CA70(player, bs_getPreviousState(), 0x40)) {
        _bashoes_entrypoint_15(player);
        bastick_setZoneMax(player, 0, 0x3CF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        func_800A0CF4(player, 1);
        func_800A0CE8(player, 1);
        func_8009BFE4(player, 1000.0f, 12.0f);
        baroll_setAngularVelocity(player, 0x447A0000, 0x41400000);
        baflag_set(player, 3);
        func_80094F14(player, 4, 1, 0.24f);
        func_800931AC(player, 2);
        func_8009E4AC(player);
        *(int *) ((char *) player + 0x160) = 0;
        *(int *) ((char *) player + 0x164) = 0;
    }
}

// Common cleanup when leaving a talon trot state.
void func_8080061C_bsbtrot(player) PlayerState *player;
{
    s32 next_state;

    next_state = bs_getNextState(player);
    if (!func_8009CA70(player, next_state, 0x40)) {
        func_8009E474(player);
        func_800931AC(player, 1);
        bastick_resetZones(player);
        func_800A0CF4(player, 0);
        func_800A0CE8(player, 0);
        func_8009BF5C(player, 0.0f);
        baroll_setIdeal(player, 0.0f);
        baflag_clear(player, 3);
        if (next_state != 0x5A)
            bastatetimer_set(player, 3, 0.0f);
        func_808004B4_bsbtrot(player);
        func_800962B0(player, 0);
        func_8008CA4C(player, 1);
        func_80094F14(player, 4, 0, 0.0f);
        _bashoes_entrypoint_14(player);
    }
}

// Nonzero when the trot should end (state 0x17): exit flag set or Z released.
s32 func_80800710_bsbtrot(u8 *player)
{
    if (*(s32 *) (player + 0x164) != 0) {
        return 1;
    }
    if (func_8008E39C() != 0) {
        return 0;
    }
    return bakey_released(player, 1);
}

int func_8080075C_bsbtrot(s32 player, s32 state)
{
    if (baflag_isTrue(player, 0xF)) {
        return state;
    }
    if (func_8008D3B0(player) != 0) {
        return 0x23;
    }
    if (func_8008E430(player) != 0) {
        return 0x9C;
    }
    if (func_8008E40C(player) != 0) {
        return 0x95;
    }
    return 8;
}

s32 func_808007E0_bsbtrot(PlayerState *player, s32 state)
{
    if (bastick_getZone(player) > 0) {
        state = *(s32 *) ((u8 *) player + 0x160) ? 0x17C : 0x16;
    }
    if (bainput_should_enter_first_person(player)) {
        state = _badrone_entrypoint_24(player);
    }
    if (!*(s32 *) ((u8 *) player + 0x160) && func_8008DD04(player)) {
        state = 0x71;
    }
    if (func_80800710_bsbtrot(player)) {
        state = 0x17;
    }
    if (bakey_pressed(player, 8)) {
        state = func_8080075C_bsbtrot(player, state);
    }
    if (!*(s32 *) ((u8 *) player + 0x160) && func_8008DF18(player)) {
        state = 0x45;
    }
    if (player_inWater(player)) {
        state = 0x2D;
    }
    return state;
}

void func_808008D0_bsbtrot(player) PlayerState *player;
{
    void *anim_ctrl;
    f32 phase_1;
    f32 phase_2;
    s32 unk_0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    unk_0 = 1;
    phase_1 = 0.7781f;
    phase_2 = 0.2781f;
    switch (_bashoes_entrypoint_1(player)) {
        case 3:
            _bashoes_entrypoint_20(player);
            break;
        case 4:
            unk_0 = 0;
            break;
        case 5:
            phase_2 = 0.6583f;
            phase_1 = 0.1783f;
            if (anctrl_isAt(anim_ctrl, 0.6583f))
                _bashoes_entrypoint_19(player);
            if (anctrl_isAt(anim_ctrl, 0.1783f))
                _bashoes_entrypoint_18(player);
            break;
        default:
            if (anctrl_isAt(anim_ctrl, 0.2115f) || anctrl_isAt(anim_ctrl, 0.7115f))
                _badust_entrypoint_1(player);
            break;
    }
    if (anctrl_isAt(anim_ctrl, func_800F13C4(phase_2 + 0.2f, 1.0f)))
        func_808000DC_bsbtrot(player, 1);
    if (anctrl_isAt(anim_ctrl, func_800F13C4(phase_1 + 0.2f, 1.0f)))
        func_808000DC_bsbtrot(player, 0);
    if (unk_0) {
        func_800A2CE8(player, phase_2, 4);
        func_800A2CE8(player, phase_1, 3);
    } else {
        func_800A2D2C(player, phase_2, 4);
        func_800A2D2C(player, phase_1, 3);
    }
}

void bsbtrot_entrypoint_0(s32 player)
{
    func_80800538_bsbtrot();
    func_808004B4_bsbtrot(player);
    baanim_playForDuration_once(player, func_80800000_bsbtrot(player, 0x16, 0x16, 0x29F, 0xA0),
                                1.0f);
    func_8009FFD8(player, 1, 1, 2, 2);
    // Matching: the (double) cast is needed for the match.
    baphysics_set_target_horizontal_velocity(player, (double) 0);
    func_8009D874(player);
    bainput_enable(player, 0, 0);
}

void bsbtrot_entrypoint_1(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    bainput_enable(player, 0, 1);
    func_8009D3A8(player, 1);
    if (anctrl_isStopped(anim_ctrl))
        next_state = 0x15;
    if (anctrl_getAnimTimer(anim_ctrl) > 0.5f)
        next_state = func_808007E0_bsbtrot(player, next_state);
    bs_setState(player, next_state);
}

int bsbtrot_entrypoint_2(Actor *actor)
{
    bainput_enable(actor, 0, 1);
    func_8080061C_bsbtrot(actor);
}

int bsbtrot_entrypoint_3(s32 entry)
{
    return D_80802E50_bsbtrot[entry];
}

int func_80800C20_bsbtrot(player)
s32 player;
{
    func_80800000_bsbtrot(player, 0x26, 0x26, 0x29B, 0x86);

}

int bsbtrot_entrypoint_4(Actor *actor)
{
    if (func_8008E430(actor)) {
        baanim_playForDuration_loopSmooth(actor, 0x29B, 1.3f);
    }

else if (func_8008E40C(actor) != 0)
{
    baanim_playForDuration_loopSmooth(actor, 0x86, 1.3f);
}

else
{
    baanim_playForDuration_loopSmooth(actor, 0x26, 1.2f);
}
func_8009FFD8(actor, 1, 1, 1, 2);
// Matching: the (double) cast is needed for the match.
baphysics_set_target_horizontal_velocity(actor, (double) 0);
func_80800538_bsbtrot(actor);
}

void bsbtrot_entrypoint_5(s32 player)
{
    func_808002A4_bsbtrot(player, func_80800C20_bsbtrot());
    func_80800120_bsbtrot(player);
    func_808004B4_bsbtrot(player);

if (func_8008E3E8(player) != 0) {
    _bashoes_entrypoint_20(player);
}

func_8009D3A8(player, 1);
bs_setState(player, func_800A02DC(player, func_808007E0_bsbtrot(player, 0)));
}

void bsbtrot_entrypoint_6()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_7(s32 entry)
{
    return D_80802E60_bsbtrot[entry];
}

int func_80800DC4_bsbtrot(int player)
{
    func_80800000_bsbtrot(player, 0x15, 0x44, 0x29C, 0xA1);
}

void func_80800DF4_bsbtrot(player) PlayerState *player;
{
    f32 unk_0;
    f32 unk_1;
    f32 unk_2;
    f32 max_speed;
    f32 min_speed;
    min_speed = func_808001B8_bsbtrot(player);
    max_speed = func_80800164_bsbtrot(player);
    unk_2 = func_80800248_bsbtrot(player);
    unk_0 = func_808001EC_bsbtrot(player);
    func_8008C9F0(player, min_speed, max_speed, unk_2, unk_0);

if (func_8008E1A0(player)) {
    unk_1 = func_8009BBB8(player);
    func_8008CA30(player, func_800F10B4(unk_1, 0.0f, 1.0f, 0.6f, 0.9f));
}

else func_8008CA30(player, 1.0f);
}

void bsbtrot_entrypoint_8(PlayerState *player)
{
    baanim_playForDuration_loopSmooth(player, func_80800DC4_bsbtrot(player), 0.53f);
    func_8009FFD8(player, 2, 1, 1, 2);
    func_80800538_bsbtrot(player);
    func_80800DF4_bsbtrot(player);
}

void bsbtrot_entrypoint_9(s32 player)
{
    s32 next_state;

    next_state = 0;
    func_80800120_bsbtrot();
    func_80800DF4_bsbtrot(player);
    func_808004B4_bsbtrot(player);
    func_808002A4_bsbtrot(player, func_80800DC4_bsbtrot(player));
    func_8009D3A8(player, 1);
    func_80800438_bsbtrot(player);
    func_808008D0_bsbtrot(player);

if ((bastick_getZone(player) == 0) && (func_8009BCD4(player, 1.0f) != 0)) {
    next_state = 0x15;
}

if (func_8008DD04(player) != 0) {
    next_state = 0x71;
}

if (func_80800710_bsbtrot(player) != 0) {
    next_state = 0x17;
}

if (bakey_pressed(player, 8) != 0) {
    next_state = func_8080075C_bsbtrot(player, next_state);
}

if (func_8008DF18(player) != 0) {
    next_state = 0x45;
}

if (player_inWater(player) != 0) {
    next_state = 0x2D;
}

bs_setState(player, func_800A02DC(player, next_state));
}

void bsbtrot_entrypoint_10()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_11(s32 entry)
{
    return D_80802E70_bsbtrot[entry];
}

void bsbtrot_entrypoint_12(PlayerState *player)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x27);
    anctrl_setDuration(anim_ctrl, 1.4f);
    func_8008B1C8(anim_ctrl, 0.1f);
    anctrl_setStart(anim_ctrl, 0.2f);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.4002f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    anctrl_start(anim_ctrl);
    func_80800538_bsbtrot(player);
    func_8008CA4C(player, 1);
    yaw_setUpdateType(player, 1);
    func_8009D2D8(player, 3);
    baphysics_set_type(player, 6);

if (bastick_distance(player) != 0.0f) {
    yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
}

baphysics_set_target_yaw(player, yaw_getIdeal(player));
func_80800438_bsbtrot(player);
baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                  baphysics_get_target_horizontal_velocity(player));
baphysics_set_vertical_velocity(player, 693.5f);
baphysics_set_gravity(player, -1200.0f);
func_8009DE38(player, 0x4432, 1.0f);
player->unk15C.word = 0;
}

void bsbtrot_entrypoint_13(PlayerState *player)
{
    s32 next_state = 0;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808004B4_bsbtrot(player);

if (func_8008E3E8(player)) {
    _bashoes_entrypoint_20(player);
}

if (baflag_isTrue(player, 0xF)) {
    func_8009B7C0(player);
} else {

func_80800438_bsbtrot(player);
}
func_8009BB24(player, velocity);
if (bakey_released(player, 8) && velocity[1] > 0.0f) {
    baphysics_reset_gravity(player);

}
switch (player->unk15C.word) {
    case 0:
        if (anctrl_isStopped(anim_ctrl)) {
            anctrl_setSubrange(anim_ctrl, 0.0f, 0.4652999938f);
            anctrl_setDuration(anim_ctrl, 10.0f);
            anctrl_setPlaybackType(anim_ctrl, 1);
            player->unk15C.word = 1;
        }

break;

case 1:
    if (func_8008DF8C(player, 0x8C)) {
        anctrl_setSubrange(anim_ctrl, 0.0f, 0.7328000069f);
        anctrl_setDuration(anim_ctrl, 1.4f);
        anctrl_setPlaybackType(anim_ctrl, 1);
        player->unk15C.word = 2;
    }

break;
case 2:
    func_8009D3A8(player, 1);

if (player_isStable(player)) {
    func_8009FE58(player);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.8798000216f);
    anctrl_setDuration(anim_ctrl, 0.9f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    func_8009D2D8(player, 1);
    player->unk15C.word = 3;
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }
    _badust_entrypoint_1(player);
}

break;

case 3:
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }

func_8009D3A8(player, 1);

if (anctrl_isStopped(anim_ctrl)) {
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.8898000121f);
    anctrl_setDuration(anim_ctrl, 2.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    player->unk15C.word = 4;
}

_badust_entrypoint_1(player);
break;

case 4:
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }

func_8009D3A8(player, 1);

if (anctrl_isStopped(anim_ctrl)) {
    anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
    anctrl_setDuration(anim_ctrl, 1.2f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    player->unk15C.word = 5;
}

_badust_entrypoint_1(player);
break;

case 5:
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }

func_8009D3A8(player, 1);

if (anctrl_isStopped(anim_ctrl)) {
    next_state = 0x15;
}

break;

}
switch (_bashoes_entrypoint_1(player)) {
    case 1:
    case 2:
        if (bainput_func_80097DF4(player)) {
            next_state = 0x10;
        }

if (bainput_func_80097F08(player)) {
    next_state = 0x11;
}

}
if (player_inWater(player)) {
    next_state = 0x4C;

}
if (player_isStable(player)) {
    if (bakey_pressed(player, 8)) {
        next_state = func_8080075C_bsbtrot(player, next_state);
    }

if (func_8008DF18(player)) {
    next_state = 0x45;
}

}
if (func_8008E260(player)) {
    next_state = 0x3D;
}
bs_setState(player, next_state);
}

void bsbtrot_entrypoint_14(s32 player)
{
    baphysics_reset_gravity();
    func_8080061C_bsbtrot(player);
}
int bsbtrot_entrypoint_15(s32 entry)
{
    return D_80802E80_bsbtrot[entry];
}

void func_8080163C_bsbtrot(Actor *actor)
{
    int interrupt = func_8009E6EC();
    if (interrupt == 0x1A || interrupt == 0x1B || interrupt == 0x29 || interrupt == 0x2B) {
        return;
    }
    func_80099B94(actor);
}

void bsbtrot_entrypoint_16(s32 player)
{
    baanim_playForDuration_once(player, 7, 0.6f);
    func_8008CA4C(player, 1);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_800931AC(player, 1);
}

void bsbtrot_entrypoint_17(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    if (baanim_isStopped(player)) {
        next_state = 1;
    }
    if (baanim_getTimer(player) > 0.3f && bastick_getZone(player)) {
        next_state = 2;
    }
    if (func_8008DD04(player)) {
        next_state = 0x2F;
    }
    if (func_8008E124(player)) {
        next_state = _badata_entrypoint_30(player, func_8009CC68(player));
    }
    bs_setState(player, next_state);
}

int bsbtrot_entrypoint_18(Actor *actor)
{
    // Matching: the `| 0` is needed for the match.
    if (func_8009CA70(actor, bs_getNextState() | 0, 0x40)) {
        func_800931AC(actor, 2);
    }
    func_8080061C_bsbtrot(actor);
}

int bsbtrot_entrypoint_19(s32 entry)
{
    return D_80802E90_bsbtrot[entry];
}

void bsbtrot_entrypoint_20(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x27);
    anctrl_setStart(anim_ctrl, 0.069f);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_start(anim_ctrl);
    func_80800538_bsbtrot(player);
    func_8009FFD8(player, 1, 1, 3, 3);
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    baphysics_set_horizontal_velocity(player, yaw_getIdeal(player),
                                      baphysics_get_target_horizontal_velocity(player));
    func_800A0CF4(player, 1);
    func_800A0CE8(player, 1);
    func_8009BFE4(player, 1000.0f, 12.0f);
    baroll_setAngularVelocity(player, 0x447A0000, 0x41400000);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    func_8009D658(player);
    player->unk16C = 1.0f;
}

void bsbtrot_entrypoint_21(PlayerState *player)
{
    s32 next_state = 0;
    f32 unk_0[3];
    f32 yaw;

    func_808004B4_bsbtrot();
    if (func_8008E3E8(player))
        _bashoes_entrypoint_20(player);
    func_8009D658(player);
    *(f32 *) ((u8 *) player + 0x16C) =
        func_800F0E00(*(f32 *) ((u8 *) player + 0x16C) - func_800D8FF8(), 0.0f);
    if (func_8008DF18(player)) {
        func_800963C0(player, unk_0);
        func_800F1EA4(unk_0, &yaw);
        func_8009D3A8(player, 1);
        baphysics_set_target_horizontal_velocity(
            player, func_800F10B4(func_8009BFD8(player), 20.0f, 60.0f, 550.0f, 700.0f));
        baphysics_set_target_yaw(player, yaw);
        _badust_entrypoint_1(player);
    } else {
        next_state = 0x15;
    }
    if (player_inWater(player))
        next_state = 0x2D;
    if (*(f32 *) ((u8 *) player + 0x16C) == 0.0f && bakey_pressed(player, 8) &&
        player_isStable(player))
        next_state = func_8080075C_bsbtrot(player, next_state);
    bs_setState(player, next_state);
}

void bsbtrot_entrypoint_22()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_23(s32 entry)
{
    return D_80802EA0_bsbtrot[entry];
}

void bsbtrot_entrypoint_24(PlayerState *player)
{
    AnimCtrl *anim_ctrl;
    f32 speed;
    f32 yaw;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, 0x27);
    anctrl_setDuration(anim_ctrl, 1.4f);
    anctrl_setStart(anim_ctrl, 0.4653f);
    anctrl_setPlaybackType(anim_ctrl, 3);
    anctrl_start(anim_ctrl);
    func_80800538_bsbtrot(player);
    func_8009FFD8(player, 1, 1, 3, 6);
    baphysics_set_target_yaw(player, yaw_getIdeal(player));
    func_80800438_bsbtrot(player);
    yaw = yaw_getIdeal(player);
    speed = baphysics_get_target_horizontal_velocity(player);
    baphysics_set_horizontal_velocity(player, yaw, speed);
    player->unk15C.word = 0;
}

void bsbtrot_entrypoint_25(PlayerState *player)
{
    s32 next_state;
    AnimCtrl *anim_ctrl;
    f32 velocity[3];

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808004B4_bsbtrot(player);
    if (func_8008E3E8(player)) {
        _bashoes_entrypoint_20(player);
    }
    if (baflag_isTrue(player, 0xF)) {
        func_8009B7C0(player);
    } else {
        func_80800438_bsbtrot(player);

}
func_8009BB24(player, velocity);
switch (player->unk15C.word) {
    case 0:
        if (func_8008DF8C(player, 0x8C)) {
            anctrl_setSubrange(anim_ctrl, 0.0f, 0.7328f);
            anctrl_setDuration(anim_ctrl, 1.4f);
            anctrl_setPlaybackType(anim_ctrl, 1);
            player->unk15C.word = 1;
        }

break;
case 1:
    func_8009D3A8(player, 1);

if (player_isStable(player)) {
    func_8009FE58(player);
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.8798f);
    anctrl_setDuration(anim_ctrl, 0.9f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    func_8009D2D8(player, 1);
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }
    _badust_entrypoint_1(player);
    player->unk15C.word = 2;
}

break;

case 2:
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }

func_8009D3A8(player, 1);

if (anctrl_isStopped(anim_ctrl)) {
    anctrl_setSubrange(anim_ctrl, 0.0f, 0.8898f);
    anctrl_setDuration(anim_ctrl, 2.0f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    player->unk15C.word = 3;
}

_badust_entrypoint_1(player);
break;

case 3:
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }

func_8009D3A8(player, 1);

if (anctrl_isStopped(anim_ctrl)) {
    anctrl_setSubrange(anim_ctrl, 0.0f, 1.0f);
    anctrl_setDuration(anim_ctrl, 1.2f);
    anctrl_setPlaybackType(anim_ctrl, 1);
    player->unk15C.word = 4;
}

_badust_entrypoint_1(player);
break;

case 4:
    if (baphysics_get_target_horizontal_velocity(player) > 220.0f) {
        func_8009D658(player);
    }

func_8009D3A8(player, 1);

if (anctrl_isStopped(anim_ctrl)) {
    next_state = 0x15;
}

}
if (player_inWater(player)) {
    next_state = 0x4C;

}
if (player_isStable(player)) {
    if (bakey_pressed(player, 8)) {
        next_state = func_8080075C_bsbtrot(player, next_state);
    }

if (func_8008DF18(player)) {
    next_state = 0x45;
}

}
if (func_8008E260(player)) {
    next_state = 0x3D;
}
bs_setState(player, next_state);
}

void bsbtrot_entrypoint_26()
{
    func_8080061C_bsbtrot();
}

int bsbtrot_entrypoint_27(s32 entry)
{
    return D_80802EB0_bsbtrot[entry];
}

void bsbtrot_entrypoint_28(s32 player)
{
    _bsrest_entrypoint_14();
    func_8080061C_bsbtrot(player);
}
void bsbtrot_entrypoint_29(s32 player)
{
    func_80800538_bsbtrot();
    _bsrest_entrypoint_18(player);
    if (func_8008E430(player) != 0) {
        baanim_playForDuration_loopSmooth(player, 0x29B, 1.3f);
    } else if (func_8008E40C(player) != 0) {
        baanim_playForDuration_loopSmooth(player, 0x86, 1.3f);
    } else {
        baanim_playForDuration_loopSmooth(player, 0x26, 1.2f);
    }
    func_800931AC(player, 2);
}

void bsbtrot_entrypoint_30(u8 *player)
{
    s32 next_state;

    next_state = 0;
    func_808004B4_bsbtrot();
    func_8009D3A8(player, 1);
    if ((*(s32 *) ((s8 *) (player) + (0x164))) != 0) {
        next_state = 0x17;
    } else if (_bsrest_entrypoint_20(player) != 0) {
        next_state = _bsrest_entrypoint_13(player);
    }
    bs_setState(player, next_state);
}

int bsbtrot_entrypoint_31(s32 entry)
{
    return D_80802EC0_bsbtrot[entry];
}

void bsbtrot_entrypoint_32(PlayerState *player)
{
    f32 yaw;
    f32 unk_0[3];
    f32 unk_1[3];
    func_80800538_bsbtrot();
    _bareact_entrypoint_1(player, func_80099A58(player));
    baanim_playForDuration_once(player, 0x66, 1.1f);
    func_8009D89C(player, 1.0f);
    func_8009C128(player, unk_0);
    func_800A32C4(player, unk_1);
    func_800F1E6C(unk_1, unk_0, &yaw);
    yaw_setIdeal(player, func_800136E4(yaw + 180.0f));
    yaw_applyIdeal(player);
    baphysics_set_target_horizontal_velocity(player, _bareact_entrypoint_4(player));
    baphysics_set_target_yaw(player, yaw);
    baphysics_set_horizontal_velocity(player, yaw,
                                      baphysics_get_target_horizontal_velocity(player));
    func_8009FFD8(player, 1, 1, 2, 3);
    if (_bareact_entrypoint_2(player) == 2)
        baphysics_set_type(player, 6);
    baphysics_set_vertical_velocity(player, _bareact_entrypoint_3(player));
    baphysics_set_gravity(player, _bareact_entrypoint_5(player));
    func_8008E944(player);
    func_8009514C(player);
}

void bsbtrot_entrypoint_33(s32 player)
{
    s32 next_state;

    next_state = 0;
    if (_bareact_entrypoint_2() == 2) {
        func_80800438_bsbtrot(player);
    }
    if (baanim_isAt(player, 0.3f) != 0) {
        func_800951B4(player);
    }
    if (func_8008E260(player) != 0) {
        next_state = 0x3D;
    }
    if ((player_isStable(player) != 0) && (baanim_isStopped(player) != 0)) {
        next_state = 0x15;
    }
    if ((anctrl_isStopped(baanim_getAnimCtrlPtr(player)) != 0) && (player_inWater(player) != 0)) {
        next_state = 0x2D;
    }
    bs_setState(player, next_state);
}

int bsbtrot_entrypoint_34(Actor *player)
{
    s32 player_addr;
    // Matching: the extra temporary is needed for the match.
    long player_bits;
    player_bits = (s32) player;
    player_addr = player_bits;
    func_8009BD88();
    baphysics_reset_gravity(player_addr);
    func_8008E95C(player_addr);
    // Matching: empty block steers IDO's register allocation.
    if (player_addr == 0) {
    }
    func_800951B4(player_addr);
    func_8080061C_bsbtrot(player_addr);
}

int bsbtrot_entrypoint_35(s32 entry_idx)
{
    return D_80802ED0_bsbtrot[entry_idx];
}

void bsbtrot_entrypoint_36(s32 player)
{
    func_808004B4_bsbtrot();
    func_80800538_bsbtrot(player);
    _bsdrone_entrypoint_0(player);
}

void bsbtrot_entrypoint_37(s32 player)
{
    _bsdrone_entrypoint_1();
    func_808004B4_bsbtrot(player);
}
void bsbtrot_entrypoint_38(s32 player)
{
    _bsdrone_entrypoint_2();
    func_8080061C_bsbtrot(player);
}
int bsbtrot_entrypoint_39(s32 entry_idx)
{
    return D_80802EE0_bsbtrot[entry_idx];
}

// Springy Step Shoes jump, by phase.
void func_80802380_bsbtrot(PlayerState *player, s32 phase)
{
    switch (phase) {
        case 0:
            baphysics_reset_gravity(player);
            break;
        case 1:
            baanim_playForDuration_onceSmooth(player, 0x298, 1.9f);
            func_8009FFD8(player, 1, 1, 3, 6);
            baphysics_set_target_horizontal_velocity(player, 0.0f);
            baphysics_set_gravity(player, -2700.0f);
            break;
        case 2:
            _bashoes_entrypoint_17(player);
            baphysics_set_type(player, 6);
            baphysics_set_vertical_velocity(player, 2383.0f);
            func_8009DEC0(player, 0x4598, 0.95f, 1.05f, 0x7FFF, 0x7FFF);
    }
    player->unk15C.word = phase;
}

int bsbtrot_entrypoint_40(Actor *player)
{
    func_80802380_bsbtrot(player, 0);
    _bashoes_entrypoint_6(player, 2);
    _bashoes_entrypoint_5(player, 0);
    func_8080061C_bsbtrot(player);
}

int bsbtrot_entrypoint_41(Actor *player)
{
    func_80800538_bsbtrot();
    _bashoes_entrypoint_5(player, 1);
    *(s32 *) ((char *) player + 0x15c) = 0;
    func_80802380_bsbtrot(player, 1);
}

void bsbtrot_entrypoint_42(PlayerState *player)
{
    s32 next_state;
    s32 phase;

    next_state = 0;
    phase = player->unk15C.word;
    switch (phase) {
        case 1:
            if (baanim_isAt(player, 0.4744f))
                func_80802380_bsbtrot(player, 2);
            break;
        case 2:
            if (baanim_getTimer(player) < 0.87f)
                _bashoes_entrypoint_16(player);
            func_80800438_bsbtrot(player);
            if (baanim_isStopped(player))
                next_state = 0x2F;
    }
    bs_setState(player, next_state);
}

int bsbtrot_entrypoint_43(s32 entry_idx)
{
    return D_80802EF0_bsbtrot[entry_idx];
}

void func_808025D8_bsbtrot(PlayerState *player, s32 phase)
{
    AnimCtrl *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    switch (phase) {
        case 1:
            anctrl_reset(anim_ctrl);
            anctrl_setIndex(anim_ctrl, 0x11F);
            anctrl_setDuration(anim_ctrl, 0.9f);
            func_8008B1C8(anim_ctrl, 0.1f);
            anctrl_setStart(anim_ctrl, 0.1734f);
            anctrl_setSubrange(anim_ctrl, 0.0f, 0.4f);
            anctrl_setPlaybackType(anim_ctrl, 1);
            anctrl_start(anim_ctrl);
            func_8009FFD8(player, 1, 1, 3, 6);

if (bastick_distance(player) != 0.0f) {
    yaw_setIdeal(player, bastick_getAngleRelativeToBanjo(player));
}

baphysics_set_target_yaw(player, yaw_getIdeal(player));
func_80800438_bsbtrot(player);
baphysics_set_horizontal_velocity(player, (yaw_getIdeal(player)),
                                  baphysics_get_target_horizontal_velocity(player));
baphysics_set_vertical_velocity(player, 693.0f);
baphysics_set_gravity(player, -1200.0f);
func_8009DE38(player, 0x4432, 1.0f);
break;
case 2:
    baanim_setEndAndDuration(player, 0.6f, 4.0f);
    break;
case 3:
    baanim_setEndAndDuration(player, 0.7734f, 0.9f);
    break;
case 4:
    func_8009FE58(player);
    baanim_setEnd(player, 1.0f);
    }
    player->unk15C.word = phase;
    }

    void bsbtrot_entrypoint_44(s32 player)
    {
        baphysics_reset_gravity();
        func_8080061C_bsbtrot(player);
    }
    void bsbtrot_entrypoint_45(s32 player)
    {
        func_80800538_bsbtrot(player);
        *(s32 *) (player + 0x15C) = 0;
        func_808025D8_bsbtrot(player, 1);
    }

    void bsbtrot_entrypoint_46(Actor *player)
    {
        s32 next_state;
        s32 anim_ctrl;
        f32 unk_1[3];

        next_state = 0;
        anim_ctrl = baanim_getAnimCtrlPtr();
        func_808004B4_bsbtrot(player);
        if (baflag_isTrue(player, 0xF) != 0) {
            func_8009B7C0(player);
        } else {
            func_80800438_bsbtrot(player);
        }
        func_8009BB24(player, unk_1);
        if ((bakey_released(player, 8) != 0) && (unk_1[1] > 0.0f)) {
            baphysics_reset_gravity(player);

}
switch (*(s32 *) ((s8 *) player + 0x15C)) {
    case 1:
        if (anctrl_isStopped(anim_ctrl) != 0) {
            func_808025D8_bsbtrot(player, 2);
        }

break;

case 2:
    if (func_8008DF8C(player, 0x82) != 0) {
        func_808025D8_bsbtrot(player, 3);
    }

break;
case 3:
    func_8009D3A8(player, 1);

if (player_isStable(player) != 0) {
    func_808025D8_bsbtrot(player, 4);
}

break;

case 4:
    if (anctrl_isStopped(anim_ctrl) != 0) {
        next_state = 0x15;
    }

next_state = func_808007E0_bsbtrot(player, next_state);

}
if (player_isStable(player) == 0) {
    if (func_8008E260(player) != 0) {
        next_state = 0x3D;
    }

if (player_inWater(player) != 0) {
    next_state = 0x4C;
}

}
bs_setState(player, next_state);
}

int bsbtrot_entrypoint_47(s32 entry_idx)
{
    return D_80802F00_bsbtrot[entry_idx];
}

// Claw Clamber Boots wall walking: enter.
int func_808029D8_bsbtrot(Actor *player)
{
    if (!func_8009CA70(player, bs_getPreviousState(), 0x800)) {
        _bashoessuck_entrypoint_3(player);
        *(s32 *) ((char *) player + 0x160) = 1;
        func_80092880(player, 0);
        func_800A2018(player, 3);
        func_800A4DA4(player, 0x19);
    }
}

// Claw Clamber Boots wall walking: exit.
void func_80802A4C_bsbtrot(player) void *player;
{
    if (func_8009CA70(player, bs_getNextState(), 0x800) == 0) {
        _bashoessuck_entrypoint_2(player);
        (*(s32 *) ((s8 *) (player) + (0x160))) = 0;
        func_80092880(player, 1);
        func_800A2018(player, -1);
        func_800A4E30(player);
    }
}

void bsbtrot_entrypoint_48(Actor *player)
{
    // Matching: the copy of player into a local is needed for the match.
    s32 player_addr;
    player_addr = player;
    func_80800538_bsbtrot();
    func_808029D8_bsbtrot(player_addr);
    baanim_playForDuration_loopSmooth(player_addr, func_80800DC4_bsbtrot(player_addr), 0.53f);
    func_8009FFD8(player_addr, 2, 1, 9, 0x12);
    func_80800DF4_bsbtrot(player_addr);
}

void bsbtrot_entrypoint_49(s32 player)
{
    s32 next_state;
    s32 unk_0[3];

    next_state = 0;
    func_800956B8(player);
    func_80800120_bsbtrot(player);
    func_80800DF4_bsbtrot(player);
    func_808004B4_bsbtrot(player);
    func_808002A4_bsbtrot(player, func_80800DC4_bsbtrot(player));
    _bashoessuck_entrypoint_4(player);
    func_80800438_bsbtrot(player);
    func_808008D0_bsbtrot(player);
    if (!bastick_getZone(player) && func_8009BCD4(player, 1.0f)) {
        next_state = 0x17B;
    }
    if (func_80800710_bsbtrot(player) || !func_8008E40C(player)) {
        next_state = 0x17;
    }
    if (bakey_pressed(player, 8)) {
        next_state = func_8080075C_bsbtrot(player, next_state);
    }
    if (player_inWater(player)) {
        next_state = 0x2D;
    }
    if (_bamovespline_entrypoint_1(player, 100.0f)) {
        next_state = 0x71;
    }
    if (_bamovespline_entrypoint_3(player)) {
        next_state = 0x16;

}
if (_bamovespline_entrypoint_2(player)) {
    if (_bashoes_entrypoint_2(player) == 2) {
        _bashoessuck_entrypoint_1(player, unk_0);
        next_state = _badrone_entrypoint_23(player, unk_0);
    } else {

next_state = 0x16;
}
}
bs_setState(player, next_state);
}

void bsbtrot_entrypoint_50(s32 player)
{
    func_80802A4C_bsbtrot();
    func_8080061C_bsbtrot(player);
}
int bsbtrot_entrypoint_51(s32 entry_idx)
{
    return D_80802F10_bsbtrot[entry_idx];
}

int bsbtrot_entrypoint_52(Actor *player)
{
    // Matching: the copy of player into a local is needed for the match.
    s32 player_addr;
    player_addr = player;
    func_80800538_bsbtrot(player);
    func_808029D8_bsbtrot(player_addr);
    baanim_playForDuration_loopSmooth(player_addr, 0x86, 1.3f);
    func_8009FFD8(player_addr, 1, 1, 9, 0x12);
    baphysics_set_target_horizontal_velocity(player_addr, 0);
}

int bsbtrot_entrypoint_53(Actor *player)
{
    s32 next_state;
    next_state = 0;
    func_80800120_bsbtrot(player);
    func_808004B4_bsbtrot(player);
    _bashoessuck_entrypoint_4(player);
    if (!func_8008E40C(player)) {
        next_state = 0x17;
    }
    bs_setState(player, func_808007E0_bsbtrot(player, next_state));
}

void bsbtrot_entrypoint_54(s32 player)
{
    func_80802A4C_bsbtrot();
    func_8080061C_bsbtrot(player);
}
int bsbtrot_entrypoint_55(s32 entry_idx)
{
    return D_80802F20_bsbtrot[entry_idx];
}

// TU-NOTE: the overlay's .data (state tables) is defined here in C; tables holding function
// pointers must be in the same unit, otherwise IDO's assembler schedules those functions differently.
extern void _bsbtrot_entrypoint_2();
extern void _bsbtrot_entrypoint_0();
extern void _bsbtrot_entrypoint_1();
extern int func_80099B94();
extern void _bsbtrot_entrypoint_6();
extern void _bsbtrot_entrypoint_4();
extern void _bsbtrot_entrypoint_5();
extern void _bsbtrot_entrypoint_10();
extern void _bsbtrot_entrypoint_8();
extern void _bsbtrot_entrypoint_9();
extern void _bsbtrot_entrypoint_14();
extern void _bsbtrot_entrypoint_12();
extern void _bsbtrot_entrypoint_18();
extern void _bsbtrot_entrypoint_16();
extern void _bsbtrot_entrypoint_17();
extern void _bsbtrot_entrypoint_22();
extern void _bsbtrot_entrypoint_20();
extern void _bsbtrot_entrypoint_21();
extern void _bsbtrot_entrypoint_26();
extern void _bsbtrot_entrypoint_24();
extern void _bsbtrot_entrypoint_25();
extern void _bsbtrot_entrypoint_28();
extern void _bsbtrot_entrypoint_29();
extern void _bsbtrot_entrypoint_30();
extern void _bsbtrot_entrypoint_34();
extern void _bsbtrot_entrypoint_32();
extern void _bsbtrot_entrypoint_33();
extern void _bsbtrot_entrypoint_38();
extern void _bsbtrot_entrypoint_36();
extern void _bsbtrot_entrypoint_37();
extern void _bsdrone_entrypoint_3();
extern void _bsbtrot_entrypoint_40();
extern void _bsbtrot_entrypoint_41();
extern void _bsbtrot_entrypoint_42();
extern void _bsbtrot_entrypoint_44();
extern void _bsbtrot_entrypoint_45();
extern void _bsbtrot_entrypoint_46();
extern void _bsbtrot_entrypoint_50();
extern void _bsbtrot_entrypoint_48();
extern void _bsbtrot_entrypoint_49();
extern void _bsbtrot_entrypoint_54();
extern void _bsbtrot_entrypoint_52();
extern void _bsbtrot_entrypoint_53();
s32 D_80802E50_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_2, (u32) _bsbtrot_entrypoint_0,
                             (u32) _bsbtrot_entrypoint_1, (u32) func_80099B94};
s32 D_80802E60_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_6, (u32) _bsbtrot_entrypoint_4,
                             (u32) _bsbtrot_entrypoint_5, (u32) func_80800308_bsbtrot};
s32 D_80802E70_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_10, (u32) _bsbtrot_entrypoint_8,
                             (u32) _bsbtrot_entrypoint_9, (u32) func_80800308_bsbtrot};
// TU-NOTE: the original referenced the overlay's own bsbtrot_entrypoint_13 here. Rare's post-link tool
// redirected every overlay function referenced from data to its core2 trampoline _bsbtrot_entrypoint_13
// (0x80082C28); the addend reproduces that. The local reference is what makes as1 fill the delay slot after
// `beqz v0` in bsbtrot_entrypoint_13 as in the ROM.
s32 D_80802E80_bsbtrot[4] ={(u32) _bsbtrot_entrypoint_14, (u32) _bsbtrot_entrypoint_12,
                             (u32) bsbtrot_entrypoint_13 + (0x80082C28 - 0x808011D8),
                             (u32) func_80099B94};
s32 D_80802E90_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_18, (u32) _bsbtrot_entrypoint_16,
                             (u32) _bsbtrot_entrypoint_17, (u32) func_8080163C_bsbtrot};
s32 D_80802EA0_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_22, (u32) _bsbtrot_entrypoint_20,
                             (u32) _bsbtrot_entrypoint_21, (u32) func_80099B94};
s32 D_80802EB0_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_26, (u32) _bsbtrot_entrypoint_24,
                             (u32) _bsbtrot_entrypoint_25, (u32) func_80099B94};
s32 D_80802EC0_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_28, (u32) _bsbtrot_entrypoint_29,
                             (u32) _bsbtrot_entrypoint_30, (u32) func_808003F0_bsbtrot};
s32 D_80802ED0_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_34, (u32) _bsbtrot_entrypoint_32,
                             (u32) _bsbtrot_entrypoint_33, (u32) func_80099B94};
s32 D_80802EE0_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_38, (u32) _bsbtrot_entrypoint_36,
                             (u32) _bsbtrot_entrypoint_37, (u32) _bsdrone_entrypoint_3};
s32 D_80802EF0_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_40, (u32) _bsbtrot_entrypoint_41,
                             (u32) _bsbtrot_entrypoint_42, (u32) func_80099B94};
s32 D_80802F00_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_44, (u32) _bsbtrot_entrypoint_45,
                             (u32) _bsbtrot_entrypoint_46, (u32) func_80800308_bsbtrot};
s32 D_80802F10_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_50, (u32) _bsbtrot_entrypoint_48,
                             (u32) _bsbtrot_entrypoint_49, (u32) func_80800308_bsbtrot};
s32 D_80802F20_bsbtrot[4] = {(u32) _bsbtrot_entrypoint_54, (u32) _bsbtrot_entrypoint_52,
                             (u32) _bsbtrot_entrypoint_53, (u32) func_80800308_bsbtrot};
