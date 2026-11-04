// Player roll angle: value, ideal, limit and rate, approached at a limited, wrap-aware rate
// (default 700 deg/s, 7.5), with getters and setters.

#include "overlays/ba/roll.h"
#include "common.h"
#include "overlays/ba/playerstate.h"
#include "core2/1E2B200.h"
#include "core2/1EB2840.h"
#include "core2/1ECA640.h"
#include "core2/1ECB9F0.h"

s32 baroll_getStructSize(void)
{
    return sizeof(BaRoll);
}

// Moves roll toward ideal along the shortest arc, step clamped by limit (deg/s) and rate.
void __baroll_update(PlayerState *self, f32 limit, f32 rate)
{
    f32 diff;
    f32 step;
    f32 dt;
    f32 max_step;

    dt = func_800D8FF8();
    max_step = limit * dt;
    diff = self->roll->ideal - self->roll->value;
    if (180.0f < mlAbsF(diff)) {
        diff += (diff < 0.0f) ? 360.0f : -360.0f;
    }
    step = diff * rate * dt;
    step = (step < 0.0f) ? func_800F0D50(step, -max_step, -0.1f) : func_800F0D50(step, 0.1f, max_step);
    if (mlAbsF(step) <= mlAbsF(diff)) {
        self->roll->value = self->roll->value + step;
    } else {
        self->roll->value = self->roll->ideal;
    }
    // wrap to [0, 360)
    if (self->roll->value < 360.0f) {
        if (self->roll->value < 0.0f) {
            self->roll->value += 360.0f;
        }
    } else {
        self->roll->value -= 360.0f;
    }
}

void baroll_reset(PlayerState *self)
{
    self->roll->value = 0.0f;
    self->roll->ideal = 0.0f;
    baroll_resetAngularVelocity(self);
}

void baroll_update(PlayerState *self)
{
    __baroll_update(self, self->roll->limit, self->roll->rate);
}

void baroll_setIdeal(PlayerState *self, f32 angle)
{
    self->roll->ideal = func_800136E4(angle);
}

void baroll_set(PlayerState *self, f32 angle)
{
    self->roll->value = func_800136E4(angle);
}

void baroll_applyIdeal(PlayerState *self)
{
    self->roll->value = self->roll->ideal;
}

f32 baroll_get(PlayerState *self)
{
    return self->roll->value;
}

f32 baroll_getIdeal(PlayerState *self)
{
    return self->roll->ideal;
}

void baroll_setAngularVelocity(PlayerState *self, f32 limit, f32 rate)
{
    self->roll->limit = limit;
    self->roll->rate = rate;
}

// Defaults: 700 deg/s limit, rate 7.5.
void baroll_resetAngularVelocity(PlayerState *self)
{
    baroll_setAngularVelocity(self, 700.0f, 7.5f);
}
