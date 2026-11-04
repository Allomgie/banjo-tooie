// Mumbo hard-landing (splat) state: fall damage, flop, slide, then get up or die at zero health.
#include "overlays/bs/mum/splat.h"

// Hard landing: fall damage, flop animation, slide to a stop.
void func_80800000_bsmumsplat(PlayerState *self)
{
    _bsmum_entrypoint_2(self);
    baanim_playForDuration_onceStartingAt(self, ASSET_CB_ANIM_BSMUMSPLAT_UNKNOWN, 3.08f, 0.085f);
    func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3,
                  BA_PHYSICS_3_LOCKED_ROTATION);
    _bssplat_entrypoint_0(self);
    func_8009DF18(self, 0x50F, 1.0f, 0x7FFF);
    func_8009BA9C(self, NULL);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    self->unk15C.word = 0;
    func_8008E944(self);
}

// Gets up (0xEF) when the animation ends, dies (0xEB) if health is zero.
void func_808000A0_bsmumsplat(PlayerState *self)
{
    enum bs_state_e next_state;
    AnimCtrl *anim_ctrl;

    next_state = BS_STATE_0_INVALID;
    anim_ctrl = baanim_getAnimCtrlPtr(self);
    if (baphysics_get_target_horizontal_velocity(self) > 140.0f) {
        _badust_entrypoint_9(self);
    }
    if (func_8008DD04(self) != 0) {
        next_state = BS_STATE_E9;
    }
    if (anctrl_isAt(anim_ctrl, 0.48f) != 0) {
        func_8009DB04(self, 0x4B1, 0.9f, 28000);
    }
    if (anctrl_isAt(anim_ctrl, 0.7414f) != 0) {
        next_state = BS_STATE_EF;
    }
    if ((player_isStable(self) == 0) && (player_inWater(self) != 0)) {
        next_state = BS_STATE_F0;
    }
    if (func_800A1718(self) == 0) {
        next_state = BS_STATE_EB;
    }
    bs_setState(self, next_state);
}

void func_8080019C_bsmumsplat(PlayerState *self)
{
    func_8008E95C(self);
    func_8009BD88(self);
    _bsmum_entrypoint_1(self);
}

s32 bsmumsplat_entrypoint_0(s32 idx)
{
    return D_808001E0_bsmumsplat[idx];
}

// TU-NOTE: the .data table below (formerly asm/data/overlays/bs/mum/splat.data.s) is defined in C.
// IDO schedules some functions differently unless the table is in the same unit.
// Values are taken from the ROM.
extern void func_80099AA8();
s32 D_808001E0_bsmumsplat[4] = {(u32) func_8080019C_bsmumsplat, (u32) func_80800000_bsmumsplat,
                                (u32) func_808000A0_bsmumsplat, (u32) func_80099AA8};
