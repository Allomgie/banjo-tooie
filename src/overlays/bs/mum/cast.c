#include "overlays/bs/mum/cast.h"
#include "overlays/ba/anim.h"
#include "core2/physics.h"
#include "overlays/ba/playerstate.h"

extern int baanim_isAt(PlayerState *, f32);

#ifndef NONMATCHINGS
s32 func_80800000_bsmumcast(PlayerState *self, s32);
s32 func_80800000_bsmumcast(PlayerState *param_0, s32 param_1)
{
    param_0->unk15C.word = param_1;
    switch (param_1) {
    case 1:
        baanim_playForDuration_onceSmooth(param_0, 0xFC, 3.0f);
        func_8009FFD8(param_0, 1, 1, 3, 3);
        func_8009BA9C(param_0, NULL);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        break;
    case 2:
        baanim_playForDuration_loopSmooth(param_0, 0x4A1, 1.71f);
        func_8009EAA0(1);
        func_800FC6B0(0x60);
        func_800DA544(0x9DE);
        break;
    case 3:
        func_800DA3B8(0x9DF, 0);
        baanim_playForDuration_onceSmooth(param_0, 0xFB, 3.0f);
        func_8009DB04(param_0, 0x3FE, 1.0f, 0x7FFF);
        func_800FCAE0(0x60, 0, 0x708);
        func_800FCA90(0x60);
        func_8009EAA0(0);
        break;
    case 4:
        baanim_playForDuration_onceStartingAt(param_0, 0xFC, 3.0f, 0.9999f);
        func_8009FFD8(param_0, 1, 1, 2, 3);
        func_8009BA9C(param_0, NULL);
        baphysics_set_target_horizontal_velocity(param_0, 0.0f);
        func_800A0DAC(param_0, 0);
        func_800A0DA0(param_0, 1);
        break;
    case 0:
        break;
    }
}
#else
// Decomp failure
#endif

void bsmumcast_entrypoint_0(PlayerState *self) {
    func_8008E95C(self);
    func_800A0DA0(self, 0);
    func_800A0DAC(self, 1);
    _bsmum_entrypoint_1(self);
}

void bsmumcast_entrypoint_1(PlayerState *self) {
    f32 sp24[3];

    _bsmum_entrypoint_2(self);
    func_8008E944(self);
    func_80099A7C(self, sp24);
    func_800A00CC(self, sp24);
    self->unk15C.word = 0;
    if (func_8009EA20() != 0) {
        func_80800000_bsmumcast(self, 4);
        return;
    }
    func_80800000_bsmumcast(self, 1);
}

#ifndef NONMATCHINGS
void bsmumcast_entrypoint_2(PlayerState *param_0)
{
    switch (func_8009E6EC(param_0)) {
    case 0x15:
    case 0x1C:
    case 0x1D:
    case 0x1E:
    case 0x25:
    case 0x43:
        break;
    default:
        func_80099B94(param_0);
        break;
    }
}
#else
// Decomp failure
#endif

#ifndef NONMATCHINGS
void bsmumcast_entrypoint_3(PlayerState *param_0)
{
    s32 local_0;

    local_0 = 0;
    switch ((u32)param_0->unk15C.word) {
    case 0:
        break;
    case 1:
        if (baanim_isStopped(param_0)) func_80800000_bsmumcast(param_0, 2);
        if (baanim_isAt(param_0, 0.3608f)) {
            func_800A0DAC(param_0, 0);
            func_800A0DA0(param_0, 1);
        }
        if (baanim_isAt(param_0, 0.5f)) _chjujubagfx_entrypoint_2();
        break;
    case 2:
        if (func_800DA298(0x9DF)) func_80800000_bsmumcast(param_0, 3);
        break;
    case 3:
        if (baanim_isAt(param_0, 0.3608f)) {
            func_800A0DAC(param_0, 1);
            func_800A0DA0(param_0, 0);
        }
        if (baanim_isAt(param_0, 0.2f)) func_800DA544(0x9F3);
        if (baanim_isStopped(param_0)) {
            if (func_8008E124(param_0)) local_0 = _badata_entrypoint_32(param_0);
            else local_0 = 0xE5;
        }
        break;
    case 4:
        func_80800000_bsmumcast(param_0, 3);
        break;
    }
    bs_setState(param_0, local_0);
}
#else
// Decomp failure
#endif

s32 bsmumcast_entrypoint_4(s32 idx) {
    return D_808004A0_bsmumcast[idx];
}
