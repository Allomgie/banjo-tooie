#include "overlays/bs/mum/cast.h"
#include "overlays/ba/anim.h"
#include "core2/physics.h"
#include "overlays/ba/playerstate.h"

#ifndef NONMATCHINGS

// Cast sub-state: 1 raises the wand, 2 loops the casting animation, 3 plays the finish.
s32 func_80800000_bsmumcast(PlayerState *self, s32 state)
{
    self->unk15C.word = state;
    switch (state) {
        case 1:
            baanim_playForDuration_onceSmooth(self, 0xFC, 3.0f);
            func_8009FFD8(self, 1, 1, 3, 3);
            func_8009BA9C(self, NULL);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            break;
        case 2:
            baanim_playForDuration_loopSmooth(self, 0x4A1, 1.71f);
            func_8009EAA0(1);
            func_800FC6B0(0x60);
            func_800DA544(0x9DE);  // flag read by the Mumbo pad
            break;
        case 3:
            func_800DA3B8(0x9DF, 0);  // clear the completion flag
            baanim_playForDuration_onceSmooth(self, 0xFB, 3.0f);
            func_8009DB04(self, 0x3FE, 1.0f, 0x7FFF);
            func_800FCAE0(0x60, 0, 0x708);
            func_800FCA90(0x60);
            func_8009EAA0(0);
            break;
        case 4:
            baanim_playForDuration_onceStartingAt(self, 0xFC, 3.0f, 0.9999f);
            func_8009FFD8(self, 1, 1, 2, 3);
            func_8009BA9C(self, NULL);
            baphysics_set_target_horizontal_velocity(self, 0.0f);
            func_800A0DAC(self, 0);
            func_800A0DA0(self, 1);
        case 0:
            break;
    }
}

#endif

void bsmumcast_entrypoint_0(PlayerState *self)
{
    func_8008E95C(self);
    func_800A0DA0(self, 0);
    func_800A0DAC(self, 1);
    _bsmum_entrypoint_1(self);
}

void bsmumcast_entrypoint_1(PlayerState *self)
{
    f32 pos[3];

    _bsmum_entrypoint_2(self);
    func_8008E944(self);
    func_80099A7C(self, pos);
    func_800A00CC(self, pos);
    self->unk15C.word = 0;
    if (func_8009EA20() != 0) {
        func_80800000_bsmumcast(self, 4);
        return;
    }
    func_80800000_bsmumcast(self, 1);
}

#ifndef NONMATCHINGS

void bsmumcast_entrypoint_2(PlayerState *self)
{
    // These states do not interrupt the cast.
    switch (func_8009E6EC(self)) {
        case 0x15:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x25:
        case 0x43:
            break;
        default:
            func_80099B94(self);
    }
}

#endif

#ifndef NONMATCHINGS

void bsmumcast_entrypoint_3(PlayerState *self)
{
    s32 next_state;

    next_state = 0;
    switch ((u32) self->unk15C.word) {
        case 0:
            break;
        case 1:
            if (baanim_isStopped(self))
                func_80800000_bsmumcast(self, 2);
            if (baanim_isAt(self, 0.3608f)) {
                func_800A0DAC(self, 0);
                func_800A0DA0(self, 1);
            }
            if (baanim_isAt(self, 0.5f))
                _chjujubagfx_entrypoint_2();
            break;
        case 2:
            // Wait for the spell target to set the completion flag.
            if (func_800DA298(0x9DF))
                func_80800000_bsmumcast(self, 3);
            break;
        case 3:
            if (baanim_isAt(self, 0.3608f)) {
                func_800A0DAC(self, 1);
                func_800A0DA0(self, 0);
            }
            if (baanim_isAt(self, 0.2f))
                func_800DA544(0x9F3);
            if (baanim_isStopped(self)) {
                if (func_8008E124(self))
                    next_state = _badata_entrypoint_32(self);
                else
                    next_state = 0xE5;
            }
            break;
        case 4:
            func_80800000_bsmumcast(self, 3);
    }
    bs_setState(self, next_state);
}

#endif

s32 bsmumcast_entrypoint_4(s32 idx)
{
    return D_808004A0_bsmumcast[idx];
}

// TU-NOTE: this overlay's .data is defined here in C so IDO schedules the functions the table points to correctly; values are from the ROM.
extern void _bsmumcast_entrypoint_3();
extern void _bsmumcast_entrypoint_2();
s32 D_808004A0_bsmumcast[4] = {(u32) _bsmumcast_entrypoint_0, (u32) _bsmumcast_entrypoint_1,
                               (u32) _bsmumcast_entrypoint_3, (u32) _bsmumcast_entrypoint_2};
