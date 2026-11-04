// Banjo-solo Shack Pack states: Banjo hides in his backpack as a shack (idle, walk, jump, fall).
#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 bastick_getZone(PlayerState *);
extern f32 bastick_getZonePosition(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
extern void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
extern void bainput_enable(PlayerState *, s32, s32);
extern s32 baanim_isAt(PlayerState *, f32);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern s32 D_80800CB0_bsbanshack[];
extern s32 D_80800CC0_bsbanshack[];
void anctrl_setSubrange(s32, f32, s32);
extern f32 baphysics_get_vertical_velocity(PlayerState *);
extern s32 D_80800CD0_bsbanshack[];
extern void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern void func_8008CA30(PlayerState *, f32);
extern void func_800A2CE8(PlayerState *, f32, s32);
extern f32 func_800DC0C0(void);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern s32 func_8009BCD4(PlayerState *, f32);
extern s32 D_80800CE0_bsbanshack[];
extern s32 D_80800CF0_bsbanshack[];
extern s32 D_80800D00_bsbanshack[];
extern s32 D_80800D10_bsbanshack[];

// Common transitions: B pressed -> 0x16E, B released -> exit (0x16B).
s32 func_80800000_bsbanshack(PlayerState *player, s32 next_state)
{
    if (bakey_pressed(player, 8))
        next_state = 0x16E;
    if (func_8008E148(player))
        next_state = 1;
    if (func_8008E260(player))
        next_state = 0x3D;
    if (bakey_released(player, 1))
        next_state = 0x16B;
    return next_state;
}

// Same as above, plus 0x16D when the stick is pushed.
int func_80800074_bsbanshack(PlayerState *player, unsigned int next_state)
{
    if (bastick_getZone(player) > 0) {
        next_state = 0x16D;
    }
    if (bakey_pressed(player, 8)) {
        next_state = 0x16E;
    }
    if (func_8008E148(player)) {
        next_state = 1;
    }
    if (func_8008E260(player)) {
        next_state = 0x3D;
    }
    if (bakey_released(player, 1)) {
        next_state = 0x16B;
    }
    return next_state;
}

void func_80800100_bsbanshack(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 300.0f));
    }
}

// Leaves the shack pack: restores backpack state and pops the stick zone.
int func_80800164_bsbanshack(actor)
Actor *actor;
{
    if (func_8009E74C(actor, 0x13)) {
        if (_babackpack_get_state(actor) != 5) {
            _babackpack_set_state(actor, 5);
        }
    } else {
        if (_babackpack_get_state(actor) != 1) {
            _babackpack_set_state(actor, 1);
        }
        func_800A0CD0(actor, 1);
        if (bs_getCurrentState(actor) != 0x16B) {
            baanim_playForDuration_once(actor, 0x6F, 0x40B00000);
            func_8008CA98(actor);
        }
        func_80095A40(actor);
        bastick_popZone(actor);
    }
}

// Enters the shack pack: sets backpack state and pushes the stick zone.
int func_8080021C_bsbanshack(player_arg)
s32 player_arg;
{
    s32 player;
    // Matching: the `| 0` copy is needed for the match.
    player = player_arg | 0;
    if (!func_8009E77C(player, 0x13)) {
        _babackpack_set_state(player, 5);
        func_800A0CD0(player, 0);
        bastick_pushZone(player);
        bastick_setZoneMax(player, 0, 0x3DF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        func_800959C8(player, 0x42540000, 0x41c80000);
        func_8009590C(player, 0x42540000);
    }
}

int func_808002AC_bsbanshack(u8 *player)
{
    if (player[0x15D]) {
        // Matching: empty if steers IDO's register allocation.
        if ((player && player) && player) {
        }
        func_80800164_bsbanshack();
    } else if (_babackpack_get_state() != 1) {
        func_800A0CD0(player, 1);
        _babackpack_set_state(player, 1);
    }
}

// Enter transformation: start the animation.
void func_8080030C_bsbanshack(PlayerState *player)
{
    player->unk15C.bytes[1] = 0;
    baanim_playForDuration_onceSmooth(player, 0x145, 1.4f);
    func_8009FFD8(player, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    bainput_enable(player, 5, 0);
}

void func_8080037C_bsbanshack(PlayerState *player)
{
    s32 next_state = 0;

    bainput_enable(player, 5, 1);
    if (baanim_isAt(player, 0.31f)) {
        func_8009DBF0(player, 0x3FF, 0.9f);
    }
    if (baanim_isAt(player, 0.1976f)) {
        player->unk15C.bytes[1] = 1;
        func_8080021C_bsbanshack(player);
    }
    if (baanim_isStopped(player)) {
        next_state = 0x16C;
    }
    bs_setState(player, next_state);
}

int bsbanshack_entrypoint_0(s32 param_0)
{
    return D_80800CB0_bsbanshack[param_0];
}

void func_80800430_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800450_bsbanshack(Actor *actor)
{
    Actor *actor_copy;
    // Matching: extra copy of the parameter is needed for the match.
    actor_copy = actor;
    func_8080021C_bsbanshack();
    baanim_playForDuration_onceSmooth(actor_copy, 0x295, 1.4f);
    func_8009FFD8(actor_copy, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(actor_copy, 0x0 & 0xFFFFFFFFFFFFFFFF);
}

void func_808004AC_bsbanshack(s32 player)
{
    s32 next_state;
    s32 anim_ctrl_copy;
    s32 anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    anim_ctrl_copy = anim_ctrl;
    if (anctrl_isAt(anim_ctrl, 0x3E947AE1) != 0) {
        func_8009DEC0(player, 0x583, 0x3F733333, 0x3F866666, 0x55F0, 0x55F0);
    }
    if (anctrl_isAt(anim_ctrl_copy, 0x3F3D70A4) != 0) {
        func_8009DEC0(player, 0x584, 0x3F733333, 0x3F866666, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(player, 0.1351f) != 0) {
        baphysics_set_vertical_velocity(player, 0x44160000);
    }
    if (baanim_isAt(player, 0.6757f) != 0) {
        _babackpack_set_state(player, 1);
        func_800A0CD0(player, 1);
    }
    if (baanim_isStopped(player) != 0) {
        next_state = 1;
    }
    bs_setState(player, next_state);
}

int bsbanshack_entrypoint_1(s32 param_0)
{
    return D_80800CC0_bsbanshack[param_0];
}

// Switches the jump phase stored at +0x15C (0 resets gravity, 1 starts the jump).
void func_808005DC_bsbanshack(void *player, s32 phase)
{
    s32 anim_ctrl_copy;
    s32 anim_ctrl;
    switch (phase) {
        case 0:
            baphysics_reset_gravity(player);
            break;

        case 1:
            anim_ctrl = baanim_getAnimCtrlPtr(player);
            anim_ctrl_copy = anim_ctrl;
            *(s32 *) ((char *) player + 0x160) = 0;
            anctrl_reset(anim_ctrl);
            anctrl_setIndex(anim_ctrl_copy, 0x294);
            anctrl_setDuration(anim_ctrl_copy, 0x3F800000);
            func_8008B1C8(anim_ctrl_copy, 0x3E09374C);
            anctrl_setStart(anim_ctrl_copy, 0x3E0F5C29);
            anctrl_setSubrange(anim_ctrl_copy, 0, 0x3F333333 & 0xFFFFFFFFFFFFFFFF);
            anctrl_setPlaybackType(anim_ctrl_copy, 1);
            anctrl_start(anim_ctrl_copy);
            func_8009FFD8(player, 1, 1, 1, 2);
            baphysics_set_vertical_velocity(player, 0x44188000);
            baphysics_set_gravity(player, 0xC47A0000);
            func_8009DF18(player, 0x589, 1.0f, 0x3A98);
            break;

        case 2:
            baanim_setEndAndDuration(player, 0x3F4F5C29, 0x404CCCCD);
            break;

        case 3:
            baanim_setEndAndDuration(player, 0x3F800000, 0x3F4CCCCD);
    }

    *(s8 *) ((char *) player + 0x15C) = (s8) phase;
}

void func_80800744_bsbanshack(s32 player)
{
    func_808005DC_bsbanshack(player, 0);
    func_80800164_bsbanshack(player);
}

void func_80800770_bsbanshack(s32 player)
{
    func_8080021C_bsbanshack(player);
    *(u8 *) (player + 0x15C) = 0;
    func_808005DC_bsbanshack(player, 1);
}

void func_808007A0_bsbanshack(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    if (bakey_released(player, 8) && baphysics_get_vertical_velocity(player) > 0.0f) {
        baphysics_reset_gravity(player);
    }
    switch (*((u8 *) player + 0x15C)) {
        case 1:
            func_80800100_bsbanshack(player);
            if (baanim_isStopped(player))
                func_808005DC_bsbanshack(player, 2);
            if (func_8008DF8C(player, 0x5A))
                func_808005DC_bsbanshack(player, 3);
            break;
        case 2:
            func_80800100_bsbanshack(player);
            if (func_8008DF8C(player, 0x5A))
                func_808005DC_bsbanshack(player, 3);
            break;
        case 3:
            if (player_isStable(player)) {
                if (*(s32 *) ((u8 *) player + 0x160) == 0) {
                    (*(s32 *) ((u8 *) player + 0x160))++;
                    func_8009FE58(player);
                }
                if (baanim_isStopped(player))
                    next_state = 0x16C;
                next_state = func_80800074_bsbanshack(player, next_state);
                if (next_state == 0)
                    baphysics_set_target_horizontal_velocity(player, 0.0f);
            }
    }
    if (func_8008E260(player))
        next_state = 0x3D;
    bs_setState(player, next_state);
}

int bsbanshack_entrypoint_2(s32 param_0)
{
    return D_80800CD0_bsbanshack[param_0];
}

void func_80800928_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800948_bsbanshack(PlayerState *player)
{
    func_8080021C_bsbanshack(player);
    baanim_playForDuration_loopSmooth(player, 0x146, 0.7f);
    func_8009FFD8(player, 2, 1, 1, 2);
    baanim_setDurationRange(player, 0.1f, 5.0f);
    func_8008C9F0(player, 30.0f, 300.0f, 0.8f, 0.5f);
    func_8008CA30(player, 1.0f);
}

void func_808009E4_bsbanshack(PlayerState *player)
{
    s32 next_state;

    next_state = 0;
    func_80800100_bsbanshack(player);
    func_800A2CE8(player, 0.25f, 4);
    func_800A2CE8(player, 0.75f, 3);
    if (baanim_isAt(player, 0.51f)) {
        func_8009DF18(player, func_800DC0C0() < 0.5f ? 0x58A : 0x58B, 1.0f, 0x1388);
    }
    if (bastick_getZone(player) == 0 && func_8009BCD4(player, 3.0f))
        next_state = 0x16C;
    bs_setState(player, func_80800000_bsbanshack(player, next_state));
}

int bsbanshack_entrypoint_3(s32 param_0)
{
    return D_80800CE0_bsbanshack[param_0];
}

void func_80800AD0_bsbanshack(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800164_bsbanshack(player);
}

void func_80800AF8_bsbanshack(s32 player)
{
    func_8080021C_bsbanshack();
    _bsdrone_entrypoint_0(player);
}

void func_80800B20_bsbanshack(PlayerState *self)
{
    _bsdrone_entrypoint_1(self);
}

int bsbanshack_entrypoint_4(s32 param_0)
{
    return D_80800CF0_bsbanshack[param_0];
}

void func_80800B54_bsbanshack(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800164_bsbanshack(player);
}

void func_80800B7C_bsbanshack(s32 player)
{
    func_8080021C_bsbanshack();
    _bsrest_entrypoint_16(player);
}

int func_80800BA4_bsbanshack(Actor *actor)
{
    s32 next_state;
    next_state = 0;
    if (_bsrest_entrypoint_20()) {
        next_state = 0x16C;
    }
    bs_setState(actor, next_state);
}

int bsbanshack_entrypoint_5(s32 param_0)
{
    return D_80800D00_bsbanshack[param_0];
}

void func_80800BF0_bsbanshack()
{
    func_80800164_bsbanshack();
}

void func_80800C10_bsbanshack(s32 player)
{
    s32 *player_ref;
    func_8080021C_bsbanshack();
    baanim_playForDuration_loopSmooth(player, 0x293, 5.4f);

    func_8009FFD8(player, 1, 1, 1, 2);
    // Matching: the pointer temporary and casts are needed for the match.
    baphysics_set_target_horizontal_velocity(*(player_ref = &player), (double) 0);
}

s32 func_80800C6C_bsbanshack(s32 player)
{
    s32 next_state = func_80800074_bsbanshack(player, 0);
    bs_setState(player, next_state | 0x20000000 & 0xFF);
}

int bsbanshack_entrypoint_6(s32 param_0)
{
    return D_80800D10_bsbanshack[param_0];
}

// TU-NOTE: the overlay .data is defined here in C. The tables point to functions of this file;
// IDO's assembler schedules some of them differently unless the tables are in the same unit.
extern void func_80099B94();
extern void _bsdrone_entrypoint_3();
s32 D_80800CB0_bsbanshack[4] = {(u32) func_808002AC_bsbanshack, (u32) func_8080030C_bsbanshack,
                                (u32) func_8080037C_bsbanshack, (u32) func_80099B94};
s32 D_80800CC0_bsbanshack[4] = {(u32) func_80800430_bsbanshack, (u32) func_80800450_bsbanshack,
                                (u32) func_808004AC_bsbanshack, (u32) func_80099B94};
s32 D_80800CD0_bsbanshack[4] = {(u32) func_80800744_bsbanshack, (u32) func_80800770_bsbanshack,
                                (u32) func_808007A0_bsbanshack, (u32) func_80099B94};
s32 D_80800CE0_bsbanshack[4] = {(u32) func_80800928_bsbanshack, (u32) func_80800948_bsbanshack,
                                (u32) func_808009E4_bsbanshack, (u32) func_80099B94};
s32 D_80800CF0_bsbanshack[4] = {(u32) func_80800AD0_bsbanshack, (u32) func_80800AF8_bsbanshack,
                                (u32) func_80800B20_bsbanshack, (u32) _bsdrone_entrypoint_3};
s32 D_80800D00_bsbanshack[4] = {(u32) func_80800B54_bsbanshack, (u32) func_80800B7C_bsbanshack,
                                (u32) func_80800BA4_bsbanshack, (u32) func_80099B94};
s32 D_80800D10_bsbanshack[4] = {(u32) func_80800BF0_bsbanshack, (u32) func_80800C10_bsbanshack,
                                (u32) func_80800C6C_bsbanshack, (u32) func_80099B94};
