#include "overlays/bs/kaz/hatch.h"

extern void func_80099B94(PlayerState *);
extern void func_800FC660(s32);
extern s32 func_80099A4C(PlayerState *);

// Enters a hatch stage: 1 = sit on the egg, 2 = hatch, 3 = get up again.
void func_80800000_bskazhatch(PlayerState *self, s32 stage)
{
    switch (stage) {
        case 0:
        case 3:
            break;
        case 1:
            baanim_playForDuration_onceSmooth(self, ASSET_13F_ANIM_KAZHATCH_UNKNOWN, 2.5);
            func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_2_NORMAL);
            baphysics_set_target_horizontal_velocity(self, 0);
            break;
        case 2:
            baanim_playForDuration_onceSmooth(self, ASSET_140_ANIM_KAZHATCH_UNKNOWN, 3);
    }
    self->unk15C.bytes[0] = (s8) stage;
}

void func_808000A8_bskazhatch(PlayerState *self)
{
    func_80800000_bskazhatch(self, 0);
    _bskaz_entrypoint_2(self);
}

void func_808000D4_bskazhatch(PlayerState *self)
{
    _bskaz_entrypoint_1(self);
    self->unk15C.bytes[0] = 0;
    self->unk160.word = 0;
    func_80800000_bskazhatch(self, 1);
}

// Interrupt handler: interrupt 0x53 means an egg actor wants to be sat on.
void func_80800108_bskazhatch(PlayerState *self)
{
    s32 interrupt;
    s32 egg;

    interrupt = func_8009E6EC(self);
    // Matching: the empty statements after some case labels are needed for the match.
    switch (interrupt) {
        case 0x15:;
        case 0x1C:
        case 0x1D:;
        case 0x1E:
        case 0x25:
            func_8009E830(self, 1);
            return;
        case 0x53:
            if (self->unk160.word == 0) {
                egg = func_80099A4C(self);
                self->unk160.word = egg;
                if (func_8010114C(egg, 0xA0, 0) <= 0) {
                    func_800FC660(0xE);
                }
                baphysics_set_type(self, 7);
            }
            func_8009E830(self, 2);
            return;
        default:
            func_80099B94(self);
    }
}

BanjoStateId func_808001E4_bskazhatch(PlayerState *self)
{
    if (func_8008E124(self) != 0) {
        return _badata_entrypoint_32(self);
    }
    return BS_STATE_BB;
}

// Update: sit on the egg, ask it whether it can hatch, then hatch or get up.
void func_80800220_bskazhatch(PlayerState *self)
{
    BanjoStateId next_state;

    next_state = BS_STATE_0_INVALID;

    switch (self->unk15C.bytes[0]) {
        case 1:
            if (baanim_isAt(self, 0.01) != 0) {
                func_8009DEC0(self, 0x459A, 0.95, 1.05, 26000, 26000);
            }

            if (baanim_isAt(self, 0.2) != 0) {
                func_8009DEC0(self, 0x459B, 0.95, 1.05, 26000, 26000);
            }

            if (baanim_isAt(self, 0.4) != 0) {
                func_8009DEC0(self, 0x459C, 0.95, 1.05, 26000, 26000);
            }

            if (baanim_isAt(self, 0.46) != 0) {
                if ((self->unk160.word != 0) && (func_8010114C(self->unk160.word, 0xA0, 1) <= 0)) {
                    func_80800000_bskazhatch(self, 2);
                } else {
                    func_80800000_bskazhatch(self, 3);
                }
            }
            break;

        case 2:
            if (baanim_isAt(self, 0.6) != 0) {
                func_8009DEC0(self, 0x4599, 0.95, 1.05, 26000, 26000);
            }
            if (baanim_isStopped(self) != 0) {
                baphysics_set_type(self, BA_PHYSICS_2_NORMAL);
                if (func_8010114C(self->unk160.word, 0x18, self->unk184) > 0) {
                    return;
                }
                next_state = func_808001E4_bskazhatch(self);
            }
            break;

        case 3:
            if (baanim_isAt(self, 0.6) != 0) {
                func_8009DEC0(self, 0x459D, 0.95, 1.05, 26000, 26000);
            }
            if (baanim_isStopped(self) != 0) {
                next_state = func_808001E4_bskazhatch(self);
            }
    }

    bs_setState(self, next_state);
}

s32 bskazhatch_entrypoint_0(s32 idx)
{
    return D_808004E0_bskazhatch[idx];
}

// TU-NOTE: the .data of this overlay is defined here in C. The table holds pointers to functions of
// this file; IDO's assembler schedules some of these functions differently unless the table is
// defined in the same unit. Values are taken from the ROM.
s32 D_808004E0_bskazhatch[4] ={(u32) func_808000A8_bskazhatch, (u32) func_808000D4_bskazhatch,
                                (u32) func_80800220_bskazhatch, (u32) func_80800108_bskazhatch};
