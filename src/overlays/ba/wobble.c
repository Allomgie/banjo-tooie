// Player body wobble: an off/ramp-in/ramp-out state machine that scales bone 3 with three
// phase-shifted sine waves between a min and max scale.
#include "common.h"
#include "overlays/ba/wobble.h"
#include "core2/1E6A730.h"
#include "core2/1E6B900.h"
#include "core2/1EBA250.h"
#include "core2/1ECA640.h"

s32 bawobble_entrypoint_0(void)
{
    return sizeof(BaWobble);
}

// Starts a ramp: 2 = in, 3 = out.
void func_80800008_bawobble(PlayerState *self, s32 state)
{
    switch (state) {
        case 2:
            self->wobble->unk18 = self->wobble->unk10;
            break;
        case 3:
            self->wobble->unk18 = self->wobble->unk14;
    }
    self->wobble->unk1C = state;
}

void func_8080004C_bawobble(PlayerState *self, s32 mode)
{
    if ((mode != 1) && (mode == 2)) {
        if (self->wobble->unkC == 2) {
            return;
        }
        self->wobble->unk8 = 0.0f;
        func_80800008_bawobble(self, 2);
    }
    self->wobble->unkC = mode;
}

void bawobble_entrypoint_1(PlayerState *self)
{
    self->wobble->unk1D = 0;
    func_80800008_bawobble(self, 1);
    func_8080004C_bawobble(self, 1);
    bawobble_entrypoint_4(self, 0.0f, 0.0f);
}

void bawobble_entrypoint_2(PlayerState *self)
{
    func_8080004C_bawobble(self, 0);
}

void bawobble_entrypoint_3(PlayerState *self)
{
    self->wobble->unkC = 0;
    func_8080004C_bawobble(self, 1);
    bawobble_entrypoint_1(self);
}

// Sets the ramp-in and ramp-out durations.
void bawobble_entrypoint_4(PlayerState *self, f32 ramp_in_time, f32 ramp_out_time)
{
    self->wobble->unk10 = ramp_in_time;
    self->wobble->unk14 = ramp_out_time;
}

// Sets the scale range of the wobble.
void bawobble_entrypoint_5(PlayerState *self, f32 max_scale, f32 min_scale)
{
    self->wobble->unk4 = max_scale;
    self->wobble->unk0 = min_scale;
}

void bawobble_entrypoint_6(PlayerState *self)
{
    func_8080004C_bawobble(self, 2);
}

void bawobble_entrypoint_7(PlayerState *self)
{
    self->wobble->unk1D = 1;
}

// Scales bone 3 by three phase-shifted sine waves.
void func_808001C0_bawobble(PlayerState *self, f32 weight)
{
    f32 scale[3];
    Unkfunc_800E0960_1 *bone_list = func_80092AD8(self);
    s32 i;

    func_800E0AF0(bone_list, 1.0f);
    func_800D91B8(&self->wobble->unk8);
    for (i = 0; i < 3; i++) {
        scale[i] = func_800F101C(self->wobble->unk8 + (0.2f * (f32) i) * 0.25f, 0.2f);
        scale[i] = func_800F1214(scale[i], self->wobble->unk0, self->wobble->unk4);
    }
    func_800E0B8C(bone_list, 3, weight, scale[0], scale[1], scale[2]);
}

// Per-frame update: advances the ramp and applies the wobble.
void bawobble_entrypoint_8(PlayerState *self)
{
    f32 weight;

    if (self->wobble->unkC != 2) {
        return;
    }

    switch (self->wobble->unk1C) {
        case 2:
            func_800D9078(&self->wobble->unk18);
            weight = func_800F10B4(self->wobble->unk18, 0.0f, self->wobble->unk10, 1.0f, 0);
            if ((weight == 1.0f) && self->wobble->unk1D) {
                func_80800008_bawobble(self, 3);
            }
            break;
        case 3:
            func_800D9078(&self->wobble->unk18);
            weight = func_800F10B4(self->wobble->unk18, 0.0f, self->wobble->unk14, 0, 1.0f);
            if ((weight == 0.0f)) {
                func_8080004C_bawobble(self, 1);
            }
    }
    func_808001C0_bawobble(self, weight);
}
