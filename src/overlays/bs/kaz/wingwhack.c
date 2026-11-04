// Kazooie-alone Wing Whack: an air version (slow fall, wing hit spheres) and a ground version
// (three timed swings), both with trail particles and the attack flag set during hit windows.
#include "common.h"
#include "overlays/bs/kaz/wingwhack.h"

extern s32 D_80800920_bskazwingwhack[];
extern s32 D_80800A80_bskazwingwhack[];
extern s32 D_80800AB8_bskazwingwhack[];
extern s32 D_80800AC8_bskazwingwhack[];

// Spawns a wing-trail particle at a wing bone position.
void func_80800000_bskazwingwhack(PlayerState *self, f32 wing_pos[3], f32 arg2, f32 arg3)
{
    s32 emitter;
    f32 self_pos[3];

    emitter = func_800B5BE4(0xA);
    func_8009C128(self, self_pos);
    func_800BA77C(emitter, 0, func_800136E4(func_800F1DF4(self_pos, wing_pos) + arg2), arg3);
    if (func_8009EA2C() != 0) {
        func_800BA670(emitter, 0x619);
    } else {
        func_800BA670(emitter, 0x618);
    }
    func_800BABB8(emitter, wing_pos, NULL, 1.0f, D_80800A80_bskazwingwhack);
}

void func_808000DC_bskazwingwhack(PlayerState *self)
{
    func_8009E474(self);
    baflag_clear(self, BA_FLAG_36);
    baphysics_reset_gravity(self);
    baphysics_reset_terminal_velocity(self);
    yaw_set(self, func_80092BE8(self));
    func_800931AC(self, 1);
    _bskaz_entrypoint_2(self);
}

// Air wing whack: init.
void func_80800148_bskazwingwhack(PlayerState *self)
{
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_onceSmooth(self, 0x138, 1.25f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1,
                  BA_PHYSICS_3_LOCKED_ROTATION);
    yaw_setVelocityBounded(self, 400.0f, 7.5f);
    baflag_set(self, BA_FLAG_36);
    baflag_set(self, BA_FLAG_5_HAS_PECKED);
    self->unk16C = func_8009BB5C(self);
    self->unk16C = func_800F13F0(self->unk16C, 1200.0f);
    baphysics_set_target_horizontal_velocity(self, self->unk16C);
    func_800931AC(self, 3);
    func_8009328C(self, yaw_get(self));
    baphysics_set_vertical_velocity(self, 0.0f);
    baphysics_set_gravity(self, -200.0f);
    baphysics_set_terminal_velocity(self, -60.0f);
    func_8009DEC0(self, 0x459E, 0.95f, 1.05f, 26000, 26000);
    func_8009E4AC(self);
    self->unk170 = func_8009E138(self, 1);
}

// Air wing whack: update.
void func_80800278_bskazwingwhack(PlayerState *self)
{
    BanjoStateId next_state;
    f32 wing_pos[3];
    f32 anim_time;
    f32 timer;
    f32 radius;

    next_state = BS_STATE_0_INVALID;
    baphysics_set_target_yaw(self, yaw_get(self));
    anim_time = baanim_getTimer(self);
    if (anim_time < 0.5f) {
        radius = func_800F10B4(anim_time, 0.0f, 0.15f, self->unk170, 80.0f);
    } else {
        radius = func_800F10B4(anim_time, 0.8f, 0.6f, self->unk170, 80.0f);
    }
    // Matching: extra copy of the anim timer.
    timer = anim_time;
    func_8009E55C(self, 1, radius);
    if (baanim_isAt(self, 0.05f) != 0) {
        func_8009DF94(self, 0x3FF, 1.1f, 12000);
    }
    if (baanim_isAt(self, 0.24f) != 0) {
        func_8009DF94(self, 0x3FF, 1.0f, 12000);
    }
    if (baanim_isAt(self, 0.48f) != 0) {
        func_8009DF94(self, 0x3FF, 0.9f, 12000);
    }
    if ((timer > 0.16f) && (timer < 0.82f)) {
        func_800F3BD0(self, 7, wing_pos);
        func_80800000_bskazwingwhack(self, wing_pos, 45.0f, 0.0f);
        func_800F3BD0(self, 9, wing_pos);
        func_80800000_bskazwingwhack(self, wing_pos, 70.0f, 0.0f);
    }
    if ((baanim_isAt(self, 0.64f) != 0) && (func_8008DF8C(self, 0xA) == 0)) {
        next_state = BS_STATE_DF;
    }
    if (baanim_isStopped(self) != 0) {
        next_state = BS_STATE_DF;
    }
    if (bainput_should_feathery_flap(self) != 0) {
        next_state = BS_STATE_15C;
    }
    bs_setState(self, next_state);
}

s32 bskazwingwhack_entrypoint_0(s32 idx)
{
    return D_80800AB8_bskazwingwhack[idx];
}

void func_808004A8_bskazwingwhack(PlayerState *self)
{
    func_8009E474(self);
    baflag_clear(self, BA_FLAG_36);
    _bskaz_entrypoint_2(self);
}

// Ground wing whack: init.
void func_808004DC_bskazwingwhack(PlayerState *self)
{
    _bskaz_entrypoint_1(self);
    baanim_playForDuration_onceSmooth(self, ASSET_137_ANIM_BSKAZWINGWHACK_UNKNOWN, 1.5f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_3_BOUNDED, 1, BA_PHYSICS_E_UNKNOWN);
    yaw_setVelocityBounded(self, 300.0f, 6.5f);
    func_8009BA9C(self, NULL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_8009E4AC(self);
    func_8009E5A4(self, 2, 4);
    func_8009E55C(self, 2, 50.0f);
}

// Ground wing whack: three timed swings, each with a hit window.
void func_80800580_bskazwingwhack(PlayerState *self)
{
    AnimCtrl *anim_ctrl;
    BanjoStateId next_state;
    f32 anim_timer;
    f32 wing_pos[3];

    anim_ctrl = baanim_getAnimCtrlPtr(self);
    next_state = BS_STATE_0_INVALID;
    anim_timer = anctrl_getAnimTimer(anim_ctrl);
    if (anctrl_isAt(anim_ctrl, 0.27f) != 0) {
        func_8009E5A4(self, 2, 5);
    }
    if (anctrl_isAt(anim_ctrl, 0.442f) != 0) {
        func_8009E5A4(self, 2, 4);
    }
    if (anctrl_isAt(anim_ctrl, 0.71f) != 0) {
        func_8009E55C(self, 2, 0.0f);
    }
    baflag_clear(self, BA_FLAG_36);
    func_8009B9F0(self, func_800F3780(anim_timer, D_80800920_bskazwingwhack, 0x2C));
    if (anctrl_isAt(anim_ctrl, 0.104f) != 0) {
        func_8009DF18(self, 0x459F, 1.0f, 26000);
    }
    if (anctrl_isAt(anim_ctrl, 0.154f) != 0) {
        func_8009DF94(self, 0x3FF, 1.0f, 15000);
    }
    if (anctrl_isAt(anim_ctrl, 0.317f) != 0) {
        func_8009DF18(self, 0x45A0, 1.05f, 26000);
    }
    if (anctrl_isAt(anim_ctrl, 0.367f) != 0) {
        func_8009DF94(self, 0x3FF, 1.1f, 15000);
    }
    if (anctrl_isAt(anim_ctrl, 0.58f) != 0) {
        func_8009DF18(self, 0x45A1, 0.95f, 26000);
    }
    if (anctrl_isAt(anim_ctrl, 0.63f) != 0) {
        func_8009DF94(self, 0x3FF, 0.9f, 15000);
    }
    if ((anim_timer > 0.104f) && (anim_timer < 0.222f)) {
        func_800F3BD0(self, 7, wing_pos);
        func_80800000_bskazwingwhack(self, wing_pos, 45.0f, 0.0f);
        baflag_set(self, BA_FLAG_36);
    } else if ((anim_timer > 0.317f) && (anim_timer < 0.4f)) {
        func_800F3BD0(self, 9, wing_pos);
        func_80800000_bskazwingwhack(self, wing_pos, func_800136E4(295.0f), 180.0f);
        baflag_set(self, BA_FLAG_36);
    } else if ((anim_timer > 0.58f) && (anim_timer < 0.7f)) {
        func_800F3BD0(self, 7, wing_pos);
        func_80800000_bskazwingwhack(self, wing_pos, 90.0f, -30.0f);
        baflag_set(self, BA_FLAG_36);
    }
    if (anctrl_isStopped(anim_ctrl) != 0) {
        next_state = BS_STATE_BB;
    }
    if (player_isStable(self) == 0) {
        next_state = BS_STATE_DF;
    }
    if (player_inWater(self) != 0) {
        next_state = BS_STATE_160;
    }
    bs_setState(self, next_state);
}

s32 bskazwingwhack_entrypoint_1(s32 idx)
{
    return D_80800AC8_bskazwingwhack[idx];
}

// TU-NOTE: .data is defined in C; the tables point to functions of this file, and IDO schedules
// some of them differently unless the tables live in the same unit. Values are from the ROM.
extern void func_80099B94();
s32 D_80800920_bskazwingwhack[88] = {
    0x3D086595, 0x0,        0x3D63BCD3, 0x4289EB85, 0x3D9F559B, 0x4260C28F, 0x3DCCCCCD, 0x42C723D7,
    0x3DFA43FE, 0x430870A4, 0x3E13DD98, 0x431ED1EC, 0x3E2AB368, 0x42FFC7AE, 0x3E416F00, 0x429523D7,
    0x3E582A99, 0x42906148, 0x3E6EE632, 0x4280D70A, 0x3E888CE7, 0x4232851F, 0x3E93EAB3, 0x42DBD70A,
    0x3E9F4880, 0x4285999A, 0x3EB05532, 0x424E70A4, 0x3EBBC01A, 0x42F4FAE1, 0x3EC71DE7, 0x42AD2E14,
    0x3ED27BB3, 0x42C2199A, 0x3EDDD97F, 0x42BDAE14, 0x3EE94467, 0x42BE3852, 0x3EF4A234, 0x42A90F5C,
    0x3F000000, 0x4288A3D7, 0x3F05AEE6, 0x425C5C29, 0x3F0B5DCC, 0x424CB852, 0x3F111340, 0x4256AE14,
    0x3F16C227, 0x42846B85, 0x3F1C710D, 0x42BC0F5C, 0x3F221FF3, 0x4302AE14, 0x3F27D567, 0x4320A8F6,
    0x3F2D844D, 0x4329E148, 0x3F333333, 0x4323B5C3, 0x3F38E219, 0x430F23D7, 0x3F3E9100, 0x42ED23D7,
    0x3F444674, 0x42C7E666, 0x3F49F55A, 0x4288B333, 0x3F4FA440, 0x4196F5C3, 0x3F555326, 0x412D47AE,
    0x3F5B089A, 0x41C71EB8, 0x3F60B780, 0x416A3D71, 0x3F666666, 0x40CAE148, 0x3F6C154D, 0x40D8A3D7,
    0x3F71C433, 0x40D8A3D7, 0x3F7779A7, 0x4107851F, 0x3F7D288D, 0x411CF5C3, 0x3F800000, 0x40DB3333};
s32 D_80800A80_bskazwingwhack[14] = {0x7802002C, 0xFF06,    0x0,      -0xFA0000, 0x150000,
                                     0x20026,    0x0,       0x0,      0x0,       0x220200,
                                     0x2000100,  0x100002B, 0x260026, 0x11A0000};
s32 D_80800AB8_bskazwingwhack[4] = {(u32) func_808000DC_bskazwingwhack,
                                    (u32) func_80800148_bskazwingwhack,
                                    (u32) func_80800278_bskazwingwhack, (u32) func_80099B94};
s32 D_80800AC8_bskazwingwhack[6] = {(u32) func_808004A8_bskazwingwhack,
                                    (u32) func_808004DC_bskazwingwhack,
                                    (u32) func_80800580_bskazwingwhack,
                                    (u32) func_80099B94,
                                    0x0,
                                    0x0};
