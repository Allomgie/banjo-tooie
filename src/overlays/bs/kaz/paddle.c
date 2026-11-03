#include "common.h"
#include "overlays/bs/kaz/paddle.h"

// TU-NOTE: The overlay .data tables at the bottom are defined in this file; IDO schedules some
// functions differently unless they are in the same unit. Values come from the ROM.
extern s32 D_80800A50_bskazpaddle[];
extern s32 D_80800A60_bskazpaddle[];
extern s32 D_80800A70_bskazpaddle[];
extern s32 D_80800A80_bskazpaddle[];
extern s32 D_80800A90_bskazpaddle[];
extern s32 D_80800AA0_bskazpaddle[];

// Shared water exit setup.
void func_80800000_bskazpaddle(PlayerState *self)
{
    if (func_8009E69C(self, 1) == 0) {
        baphysics_reset_terminal_velocity(self);
        baphysics_reset_gravity(self);
        func_800961AC(self, 1);
        bastick_func_8009F258(self);
        func_800A1040(self);
        _bskaz_entrypoint_2(self);
    }
}

// Shared water enter setup.
void func_80800068_bskazpaddle(PlayerState *self)
{
    if (func_8009E6C4(self, 1) == 0) {
        _bskaz_entrypoint_1(self);
        baphysics_set_gravity(self, 100);
        baphysics_set_terminal_velocity(self, 133.33);
        bastick_setZoneMax(self, 0, 0.03);
        bastick_setZoneMax(self, 1, 1);
        func_800961AC(self, 3);
        func_800A106C(self, 30, 50);
    }
}

void func_80800100_bskazpaddle(PlayerState *self)
{
    f32 stick_pos;

    stick_pos = bastick_getZonePosition(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        baphysics_set_target_horizontal_velocity(self, 0);
        return;
    }
    baphysics_set_target_horizontal_velocity(self, func_800F1214(stick_pos, 30, 350));
}

void func_80800164_bskazpaddle(PlayerState *self)
{
    func_8009BC34(self);
    func_800961AC(self, 1);
}

void func_80800190_bskazpaddle(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    f32 unk_0;

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    baphysics_set_gravity(self, 0);
    baphysics_set_terminal_velocity(self, -399.99);
    func_800961AC(self, 3);
    func_8009BC5C(self, 2);
    func_800A046C(self);
    unk_0 = func_800A3298(self);
    anctrl_reset(anim_ctrl);
    anctrl_setIndex(anim_ctrl, ASSET_139_ANIM_BSKAZPADDLE_UNKNOWN);
    anctrl_setPlaybackType(anim_ctrl, 2);
    anctrl_setDuration(anim_ctrl, 1.2);
    anctrl_setStart(anim_ctrl, 0.6412);
    anctrl_start(anim_ctrl);
    self->unk16C = func_800F10B4(unk_0, 40, 1000, -300, -1200.0f);
    baphysics_set_vertical_velocity(self, self->unk16C);
    func_8009FFD8(self, 1, 3, 3, 6);
}

void func_808002A0_bskazpaddle(PlayerState *self)
{
    BanjoStateId next_state;
    f32 emitter_pos[3];
    s32 emitter;

    next_state = BS_STATE_0_INVALID;
    func_8009C128(self, emitter_pos);
    emitter_pos[1] = emitter_pos[1] + 60.0f;
    emitter = func_8009FBB0(self, emitter_pos, 20);
    func_800BA930(emitter, -30, -30, -30, 30, 30, 30);
    func_800BA22C(emitter, 1);
    if (self->unk16C < 0.0f) {
        self->unk16C += func_800F0E00(mlAbsF(self->unk16C) * 0.1f, 50);
        baphysics_set_vertical_velocity(self, self->unk16C);
    }
    if (player_isStable(self) != 0) {
        next_state = BS_STATE_15D;
    }
    if (player_inWater(self) == 0) {
        next_state = BS_STATE_BB;
    }
    if (baphysics_get_vertical_velocity(self) >= 0.0f) {
        next_state = BS_STATE_15D;
    }
    bs_setState(self, next_state);
}

s32 bskazpaddle_entrypoint_0(s32 idx)
{
    return D_80800A50_bskazpaddle[idx];
}

// Spawns a bubble emitter at pos.
void func_808003F4_bskazpaddle(PlayerState *self, f32 pos[3])
{
    s32 emitter;

    emitter = func_8009FBB0(self, pos, 40);
    func_800BA930(emitter, 0, 100, 0, 0, 100, 0);
    func_800BA22C(emitter, 1);
}

void func_80800448_bskazpaddle(PlayerState *self)
{
    func_80800000_bskazpaddle(self);
}

void func_80800468_bskazpaddle(PlayerState *self)
{
    func_80800068_bskazpaddle(self);
    baanim_playForDuration_loopSmooth(self, ASSET_139_ANIM_BSKAZPADDLE_UNKNOWN, 0.7);
    func_8008CA4C(self, 2);
    baanim_setDurationRange(self, 0.3, 1.5);
    func_8008C9F0(self, 30, 350, 1, 0.5f);
    yaw_setUpdateType(self, 3);
    yaw_setVelocityBounded(self, 500, 5);
    func_8009D2D8(self, 1);
    baphysics_set_type(self, 2);
}

void func_80800518_bskazpaddle(PlayerState *self)
{
    BanjoStateId next_state;
    AnimCtrl *anim_ctrl;
    f32 pos[3];

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    func_80092C24(self, pos);
    func_808003F4_bskazpaddle(self, pos);
    func_80092C00(self, pos);
    func_808003F4_bskazpaddle(self, pos);
    // Paddle sound at two points of the animation.
    if (anctrl_isAt(anim_ctrl, 0.2) != 0) {
        func_8009DE74(self, 0x40C, 0.9f, 1.1f);
    }
    if (anctrl_isAt(anim_ctrl, 0.7) != 0) {
        func_8009DE74(self, 0x40C, 0.9f, 1.1f);
    }
    func_80800100_bskazpaddle(self);
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_0) {
        next_state = BS_STATE_15D;
    }
    if (player_inWater(self) == 0) {
        next_state = BS_STATE_BB;
    }
    if (bakey_pressed(self, BUTTON_B) != 0) {
        next_state = BS_STATE_15F;
    }
    if ((func_80096500(self) != 0) && (bakey_pressed(self, BUTTON_A) != 0)) {
        next_state = BS_STATE_BD;
    }
    bs_setState(self, next_state);
}

s32 bskazpaddle_entrypoint_1(s32 idx)
{
    return D_80800A60_bskazpaddle[idx];
}

void func_80800664_bskazpaddle(PlayerState *self)
{
    func_80800000_bskazpaddle(self);
    func_800A4E30(self);
}

void func_8080068C_bskazpaddle(PlayerState *self)
{
    func_80800068_bskazpaddle(self);
    baanim_playForDuration_loopSmooth(self, ASSET_139_ANIM_BSKAZPADDLE_UNKNOWN, 2.8);
    func_8009FFD8(self, 1, 3, 3, 2);
    yaw_setVelocityBounded(self, 500, 5);
    baphysics_set_target_horizontal_velocity(self, 0);
    func_800A4DA4(self, 8);
}

void func_8080070C_bskazpaddle(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_8009FC34(self, 1);
    }
    if (bastick_getZone(self) == BS_STICK_ZONE_ID_1) {
        next_state = BS_STATE_15E;
    }
    if (player_inWater(self) == 0) {
        next_state = BS_STATE_BB;
    }
    if (bainput_should_enter_first_person(self) != 0) {
        next_state = _badrone_entrypoint_24(self);
    }
    if (bakey_pressed(self, 9) != 0) {
        next_state = BS_STATE_15F;
    }
    if ((func_80096500(self) != 0) && (bakey_pressed(self, BUTTON_A) != 0)) {
        next_state = BS_STATE_BD;
    }
    bs_setState(self, next_state);
}

s32 bskazpaddle_entrypoint_2(s32 idx)
{
    return D_80800A70_bskazpaddle[idx];
}

void func_80800818_bskazpaddle(PlayerState *self)
{
    func_80800000_bskazpaddle(self);
}

void func_80800838_bskazpaddle(PlayerState *self)
{
    func_80800068_bskazpaddle(self);
    baanim_playForDuration_onceSmooth(self, ASSET_13A_ANIM_BSKAZPADDLE_UNKNOWN, 2.4);
    func_8009FFD8(self, 1, 3, 3, 2);
    baphysics_set_target_horizontal_velocity(self, 0);
}

void func_80800894_bskazpaddle(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (baanim_isAt(self, 0.9) != 0) {
        next_state = BS_STATE_15D;
    }
    bs_setState(self, next_state);
}

s32 bskazpaddle_entrypoint_3(s32 idx)
{
    return D_80800A80_bskazpaddle[idx];
}

void func_808008EC_bskazpaddle(PlayerState *self)
{
    _bsrest_entrypoint_14(self);
    func_80800000_bskazpaddle(self);
}

void func_80800914_bskazpaddle(PlayerState *self)
{
    func_80800068_bskazpaddle(self);
    _bsrest_entrypoint_16(self);
}

void func_8080093C_bskazpaddle(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (_bsrest_entrypoint_20(self) != 0) {
        next_state = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, next_state);
}

s32 bskazpaddle_entrypoint_4(s32 idx)
{
    return D_80800A90_bskazpaddle[idx];
}

void func_80800990_bskazpaddle(PlayerState *self)
{
    func_80800068_bskazpaddle(self);
    _bsdrone_entrypoint_0(self);
}

void func_808009B8_bskazpaddle(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;
    if (_badrone_entrypoint_30(self) != 0) {
        next_state = BS_STATE_BB;
    }
    _bsdrone_entrypoint_1(self);
    bs_setState(self, next_state);
}

void func_808009FC_bskazpaddle(PlayerState *self)
{
    _bsdrone_entrypoint_2(self);
    func_80800000_bskazpaddle(self);
}

s32 bskazpaddle_entrypoint_5(s32 idx)
{
    return D_80800AA0_bskazpaddle[idx];
}

extern void func_80099B94();
s32 D_80800A50_bskazpaddle[4] = {(u32) func_80800164_bskazpaddle, (u32) func_80800190_bskazpaddle,
                                 (u32) func_808002A0_bskazpaddle, (u32) func_80099B94};
s32 D_80800A60_bskazpaddle[4] = {(u32) func_80800448_bskazpaddle, (u32) func_80800468_bskazpaddle,
                                 (u32) func_80800518_bskazpaddle, (u32) func_80099B94};
s32 D_80800A70_bskazpaddle[4] = {(u32) func_80800664_bskazpaddle, (u32) func_8080068C_bskazpaddle,
                                 (u32) func_8080070C_bskazpaddle, (u32) func_80099B94};
s32 D_80800A80_bskazpaddle[4] = {(u32) func_80800818_bskazpaddle, (u32) func_80800838_bskazpaddle,
                                 (u32) func_80800894_bskazpaddle, (u32) func_80099B94};
s32 D_80800A90_bskazpaddle[4] = {(u32) func_808008EC_bskazpaddle, (u32) func_80800914_bskazpaddle,
                                 (u32) func_8080093C_bskazpaddle, (u32) func_80099B94};
s32 D_80800AA0_bskazpaddle[4] = {(u32) func_808009FC_bskazpaddle, (u32) func_80800990_bskazpaddle,
                                 (u32) func_808009B8_bskazpaddle, (u32) _bsdrone_entrypoint_3};
