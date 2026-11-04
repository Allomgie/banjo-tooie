// Surface swimming states: treading water and paddle swimming, plus rest and first-person
// wrappers. Enter/exit set water gravity and terminal velocity and tell the backpack about water.
#include "common.h"
#include "overlays/ba/playerstate.h"

extern s32 func_80096544(PlayerState *);
extern f32 func_800DC0C0(void);
extern void func_80092C00(PlayerState *, f32[3]);
extern void func_80092C24(PlayerState *, f32[3]);
extern s32 func_8009FBB0(PlayerState *, f32[3], f32);
extern void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
extern void func_800BA22C(s32, s32);
extern s16 D_80800B90_bsswim[10];
extern f32 anctrl_getAnimTimer(void *);
extern void anctrl_setStart(void *, f32);
extern f32 bastick_getZonePosition(PlayerState *);
extern s32 bastick_getZone(PlayerState *);
extern void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern int func_8001210C(int);
extern int func_8009FC34(Actor *, int);
extern void func_8009DEC0(Actor *, int, float, float, int, int);
extern int player_inWater(Actor *);
extern int bainput_should_enter_first_person(Actor *);
extern int _badrone_entrypoint_24(Actor *);
extern int bainput_should_dive(Actor *);
extern int func_80096500(Actor *);
extern int bakey_pressed(Actor *, int);
extern int baflag_isTrue(Actor *, int);
extern void bs_setState(Actor *, int);
extern s32 D_80800BA4_bsswim[];
extern s32 D_80800BB4_bsswim[];
extern s32 D_80800BC4_bsswim[];
extern s32 D_80800BD4_bsswim[];
extern void *baanim_getAnimCtrlPtr();
extern void func_8008B1C8(void *, f32);
extern void anctrl_setDuration(void *, f32);
extern void yaw_setVelocityBounded(PlayerState *, f32, f32);
extern f32 func_800CF67C(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_8009DF18(PlayerState *, s32, f32, s32);
extern void bainput_setDiveCooldown(PlayerState *, s32, f32);
extern void baanim_setDurationRange(PlayerState *, f32, f32);
extern void func_8008C9F0(PlayerState *, f32, f32, f32, f32);
extern s32 anctrl_isAt(void *, f32);
extern void func_8009DE74(void *, s32, f32, f32);
extern f32 func_800964DC(void *);
extern f32 func_8009C150(void *);

// Returns the dive state (0x6D or 0x30).
int func_80800000_bsswim()
{
    s32 next_state;
    if (func_8008E23C()) {
        next_state = 0x6D;
    } else {
        next_state = 0x30;
    }
    // Matching: the no-op OR is needed for the match.
    return next_state | 0;
}

// Spawns a breath bubble emitter.
void func_80800030_bsswim(PlayerState *player)
{
    f32 pos[3];
    s32 emitter;

    if (func_80096544(player)) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(player, pos);
        } else {
            func_80092C24(player, pos);
        }
        emitter = func_8009FBB0(player, pos, 0.0f);
        func_800BA930(emitter, -60, -100, -60, 60, 0, 60);
        func_800BA22C(emitter, 1);
    }
}

void func_808000E0_bsswim(PlayerState *player, void *anim_ctrl)
{
    s32 anim_id;
    anim_id = D_80800B90_bsswim[player->unk15C.word];
    if (anctrl_getIndex(anim_ctrl) != anim_id) {
        anctrl_setStart(anim_ctrl, anctrl_getAnimTimer(anim_ctrl));
        anctrl_setIndex(anim_ctrl, anim_id);
        anctrl_start(anim_ctrl);
    }
    player->unk15C.word++;
    if ((u32) player->unk15C.word >= 10)
        player->unk15C.word = 0;
}

void func_80800178_bsswim(PlayerState *player)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(player);
    if (bastick_getZone(player) == 0) {
        baphysics_set_target_horizontal_velocity(player, 0.0f);
    } else {
        baphysics_set_target_horizontal_velocity(player, func_800F1214(stick_pos, 30.0f, 300.0f));
    }
}

// Enter water: set gravity, terminal velocity, stick zones and collision mode.
void func_808001DC_bsswim(player) s32 player;
{
    if (func_8009E6C4(player, 1) == 0) {
        baphysics_set_gravity(player, 0x42C80000);
        baphysics_set_terminal_velocity(player, 0x4305547B);
        bastick_setZoneMax(player, 0, 0x3CF5C28F);
        bastick_setZoneMax(player, 1, 0x3F800000);
        func_800961AC(player, 3);
        if (func_8008E0E8(player) != 0) {
            _bapackctrl_entrypoint_5(player, 4);
        }
    }
}

// Leave water: undo the water physics and stick zones.
int func_80800270_bsswim(player)
s32 player;
{
    if (!func_8009E69C(player, 1)) {
        baphysics_reset_terminal_velocity(player);
        baphysics_reset_gravity(player);
        bastick_resetZones(player);
        func_800961AC(player, 1);
        if (func_8008E0E8(player)) {
            _bapackctrl_entrypoint_5(player, 3);
        }
    }
}

// Tread water: enter.
void func_808002E0_bsswim(PlayerState *player)
{
    s32 last_state;
    s32 prev_state;
    f32 blend;
    void *anim_ctrl;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808001DC_bsswim(player);
    prev_state = bs_getPreviousState(player);
    if (prev_state == 0x4C)
        blend = 0.8f;
    else
        blend = 0.5f;
    last_state = prev_state;
    if (func_8009CA70(player, last_state, 2)) {
        if (last_state == 0x54) {
            func_8009DF18(player, 0x461, 1.0f, 30000);
        } else if (last_state != 0x4C) {
            func_8009DF18(player, 0x461, 1.0f,
                          (s32) func_800F10B4(func_800CF67C(), 1.0f, 0.0f, 8000.0f, 30000.0f));
        }
        bainput_setDiveCooldown(player, 4, 0.7f);
    }
    if (anctrl_getIndex(anim_ctrl) == 0x57 && last_state != 0x4C) {
        anctrl_setDuration(anim_ctrl, 1.2f);
    } else {
        anctrl_reset(anim_ctrl);
        func_8008B1C8(anim_ctrl, blend);
        anctrl_setIndex(anim_ctrl, 0x57);
        anctrl_setPlaybackType(anim_ctrl, 2);
        anctrl_setStart(anim_ctrl, 0.3f);
        anctrl_setDuration(anim_ctrl, 1.2f);
        anctrl_start(anim_ctrl);
    }
    func_8009FFD8(player, 1, 3, 3, 2);
    yaw_setVelocityBounded(player, 500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(player, 0.0f);
    player->unk15C.word = 0;
    func_800A4DA4(player, 8);
}

// Tread water: update (breath bubbles, dive, first person, jump out).
void func_808004C4_bsswim(Actor *actor)
{
    s32 next_state;
    s32 anim_ctrl;
    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr();
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_8009FC34(actor, 1);
    }
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_80800030_bsswim(actor);
    }
    if (anctrl_isAt(anim_ctrl, 0.01f) != 0) {
        func_8009DEC0(actor, 0x46F, 0.85f, 1.15f, 0x3E80, 0x3E80);
    }
    if (anctrl_isAt(anim_ctrl, 0.4348f) != 0) {
        func_808000E0_bsswim(actor, anim_ctrl);
    }
    if (bastick_getZone(actor) == 1) {
        next_state = 0x2E;
    }
    if (player_inWater(actor) == 0) {
        next_state = 1;
    }
    if (bainput_should_enter_first_person(actor) != 0) {
        next_state = _badrone_entrypoint_24(actor);
    }
    if (bainput_should_dive(actor) != 0) {
        next_state = func_80800000_bsswim(actor);
    }
    if ((func_80096500(actor) != 0) && (bakey_pressed(actor, 8) != 0)) {
        next_state = 5;
    }
    if ((baflag_isTrue(actor, 6) != 0) || (baflag_isTrue(actor, 0x14) != 0)) {
        next_state = 0xD;
    }
    bs_setState(actor, next_state);
}

void func_80800688_bsswim(s32 player)
{
    func_80800270_bsswim();
    func_800A4E30(player);
}

int bsswim_entrypoint_0(s32 index)
{
    return D_80800BA4_bsswim[index];
}

// Paddle swim: enter.
void func_808006C4_bsswim(PlayerState *player)
{
    void *anim_ctrl;
    f32 blend;

    anim_ctrl = baanim_getAnimCtrlPtr(player);
    func_808001DC_bsswim(player);
    if (bs_getPreviousState(player) == 0x4C) {
        blend = 0.8f;
    } else {
        blend = 0.4f;
    }
    if (anctrl_getIndex(anim_ctrl) != 0x39) {
        anctrl_reset(anim_ctrl);
        anctrl_setIndex(anim_ctrl, 0x39);
        func_8008B1C8(anim_ctrl, blend);
        anctrl_setStart(anim_ctrl, 0.8f);
        anctrl_setPlaybackType(anim_ctrl, 2);
        anctrl_start(anim_ctrl);
    }
    func_8008CA4C(player, 2);
    baanim_setDurationRange(player, 0.3f, 1.5f);
    func_8008C9F0(player, 30.0f, 300.0f, 1.2f, 0.7f);
    yaw_setUpdateType(player, 3);
    yaw_setVelocityBounded(player, 500.0f, 5.0f);
    func_8009D2D8(player, 1);
    baphysics_set_type(player, 2);
}

// Paddle swim: update (stroke sounds, dive, jump out).
void func_808007F8_bsswim(PlayerState *player)
{
    s32 next_state;
    void *anim_ctrl;
    f32 unk_0[3];
    f32 unk_1;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(player);
    if (anctrl_isAt(anim_ctrl, 0.38f)) {
        func_8009FD24(player, 1);
    }
    if (anctrl_isAt(anim_ctrl, 0.88f)) {
        func_8009FD24(player, 0);
    }
    if (anctrl_isAt(anim_ctrl, 0.2f)) {
        func_8009DE74(player, 0x40C, 0.9f, 1.1f);
    }
    if (anctrl_isAt(anim_ctrl, 0.7f)) {
        func_8009DE74(player, 0x40C, 0.9f, 1.1f);
    }
    func_80800178_bsswim(player);
    if (bastick_getZone(player) == 0) {
        next_state = 0x2D;
    }
    if (!player_inWater(player)) {
        next_state = 1;
    }
    if (func_8009650C(player) && func_8008D214(player)) {
        func_80096440(player, &unk_0);
        if (unk_0[1] < -0.7f) {
            unk_1 = func_800964DC(player);
            if (unk_1 - func_8009C150(player) > 90.0f) {
                next_state = func_80800000_bsswim(player);
            }
        }
    }
    if (bainput_should_dive(player)) {
        next_state = func_80800000_bsswim(player);
    }
    if (func_80096500(player) && bakey_pressed(player, 8)) {
        next_state = 5;
    }
    if (baflag_isTrue(player, 6) || baflag_isTrue(player, 0x14)) {
        next_state = 0xD;
    }
    bs_setState(player, next_state);
}

void func_808009F0_bsswim()
{
    func_80800270_bsswim();
}

int bsswim_entrypoint_1(s32 index)
{
    return D_80800BB4_bsswim[index];
}

void func_80800A24_bsswim(s32 player)
{
    _bsrest_entrypoint_14();
    func_80800270_bsswim(player);
}

void func_80800A4C_bsswim(s32 player)
{
    func_808001DC_bsswim();
    _bsrest_entrypoint_16(player);
}

s32 func_80800A74_bsswim(Actor *actor)
{
    s32 need_rewind;

    need_rewind = 0;
    if (_bsrest_entrypoint_20())
        need_rewind = _bsrest_entrypoint_13(actor);

    bs_setState(actor, need_rewind);
}

int bsswim_entrypoint_2(s32 index)
{
    return D_80800BC4_bsswim[index];
}

void func_80800AC8_bsswim(s32 player)
{
    func_808001DC_bsswim();
    _bsdrone_entrypoint_0(player);
}

s32 func_80800AF0_bsswim(Actor *actor)
{
    s32 next_state = 0;
    if (_badrone_entrypoint_30(actor)) {
        next_state = 1;
    }
    _bsdrone_entrypoint_1(actor);
    bs_setState(actor, next_state);
}

void func_80800B34_bsswim(s32 player)
{
    _bsdrone_entrypoint_2();
    func_80800270_bsswim(player);
}

int bsswim_entrypoint_3(s32 index)
{
    return D_80800BD4_bsswim[index];
}

// TU-NOTE: the overlay .data is defined here in C. The tables point to functions of this
// file; IDO's assembler schedules some of them differently unless they share the unit.
// Values are taken from the ROM.
extern void func_80099B94();
extern void _bsdrone_entrypoint_3();
s16 D_80800B90_bsswim[10] = {0x57, 0x57, 0x57, 0x58, 0x57, 0x58, 0x57, 0x57, 0x58, 0x58};
s32 D_80800BA4_bsswim[4] = {(u32) func_80800688_bsswim, (u32) func_808002E0_bsswim,
                            (u32) func_808004C4_bsswim, (u32) func_80099B94};
s32 D_80800BB4_bsswim[4] = {(u32) func_808009F0_bsswim, (u32) func_808006C4_bsswim,
                            (u32) func_808007F8_bsswim, (u32) func_80099B94};
s32 D_80800BC4_bsswim[4] = {(u32) func_80800A24_bsswim, (u32) func_80800A4C_bsswim,
                            (u32) func_80800A74_bsswim, (u32) func_80099B94};
s32 D_80800BD4_bsswim[7] = {(u32) func_80800B34_bsswim,
                            (u32) func_80800AC8_bsswim,
                            (u32) func_80800AF0_bsswim,
                            (u32) _bsdrone_entrypoint_3,
                            0x0,
                            0x0,
                            0x0};
