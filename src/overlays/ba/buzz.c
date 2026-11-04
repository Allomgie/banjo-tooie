// Bee wing buzz loop: one looping sound whose pitch and volume glide toward targets, with a small
// triangle-wave pitch wobble.
#include "common.h"
#include "overlays/ba/buzz.h"
#include "core2/1E9A960.h"
#include "core2/1EB2840.h"
#include "core2/1ECA640.h"

s32 babuzz_entrypoint_0(void)
{
    return sizeof(BaBuzz);
}

// Triangle-wave pitch wobble.
f32 func_80800008_babuzz(f32 time)
{
    f32 wave = func_800F0F9C(time, 0.7f);
    wave *= 2.0f;

    if (1.0f <= wave) {
        wave = 2.0f - wave;
    }

    wave -= 0.5f;
    wave *= 0.04f;
    return wave;
}

// Moves value toward target by rate per second.
f32 func_80800074_babuzz(f32 value, f32 target, f32 rate)
{
    f32 dt;

    dt = func_800D8FF8();
    if (value < target) {
        value += dt * rate;
        if (target < value) {
            value = target;
        }
    } else {
        value -= dt * rate;
        if (value < target) {
            value = target;
        }
    }
    return value;
}

void babuzz_entrypoint_1(PlayerState *self)
{
    func_800C2FDC(self->buzz->unk0);
    self->buzz->unk0 = 0;
}

void babuzz_entrypoint_2(PlayerState *self)
{
    self->buzz->unk0 = func_800C2E04();
    self->buzz->unk4 = self->buzz->unkC = 1.0f;
    self->buzz->unk8 = self->buzz->unk10 = 8000;
    func_800C301C(self->buzz->unk0, 0x49B);
    func_800C330C(self->buzz->unk0, 2);
    func_800C31DC(self->buzz->unk0, self->buzz->unk4);
    func_800C3058(self->buzz->unk0, self->buzz->unk8);
    self->buzz->unk14 = 0;
}

void babuzz_entrypoint_3(PlayerState *self)
{
    self->buzz->unk14 += func_800D8FF8();
    self->buzz->unk4 = func_80800074_babuzz(self->buzz->unk4, self->buzz->unkC, 0.3f);
    self->buzz->unk8 =
        (s32) func_80800074_babuzz((f32) self->buzz->unk8, (f32) self->buzz->unk10, 100.0f);
    func_800C31DC(self->buzz->unk0, self->buzz->unk4 + func_80800008_babuzz(self->buzz->unk14));
    func_800C3058(self->buzz->unk0, self->buzz->unk8);
    func_800C3BDC(self->buzz->unk0);
}

void babuzz_entrypoint_4(PlayerState *self, f32 target_pitch)
{
    self->buzz->unkC = target_pitch;
}

void babuzz_entrypoint_5(PlayerState *self, s32 target_volume)
{
    self->buzz->unk10 = target_volume;
}
