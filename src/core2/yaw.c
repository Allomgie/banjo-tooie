// Player yaw (facing): value and ideal, update modes NONE/DEFAULT(700, 7.5)/UNBOUNDED/BOUNDED,
// timed rotation, and getters and setters.

#include "common.h"
#include "overlays/ba/yaw.h"
#include "core2/1E2B200.h"
#include "core2/1EB2840.h"
#include "core2/1ECB9F0.h"
#include "ml.h"

s32 yaw_size(void)
{
    return sizeof(BaYaw);
}

// Turns at a constant speed toward ideal yaw along the shortest arc.
void __yaw_update_limitless(PlayerState *self, f32 speed)
{
    f32 diff;
    f32 step;

    speed *= func_800D8FF8();
    diff = self->yaw->ideal - self->yaw->value;
    if (mlAbsF(diff) > 180.0f) {
        diff += (diff < 0.0f) ? 360.0f : -360.0f;
    }

    step = (mlAbsF(diff) > 180.0f)
               ? speed
               : ((diff < 0.0f) ? -speed : speed);

    if (mlAbsF(step) <= mlAbsF(diff)) {
        self->yaw->value += step;
    } else {
        self->yaw->value = self->yaw->ideal;
    }

    // wrap to [0, 360)
    if (self->yaw->value < 360.0f) {
        if (self->yaw->value < 0.0f) {
            self->yaw->value = (f32) (self->yaw->value + 360.0f);
        }
    } else {
        self->yaw->value -= 360.0f;
    }
}

// Turns toward ideal yaw proportionally to the remaining angle, speed clamped by limit.
void __yaw_update_limited(PlayerState *self, f32 limit, f32 rate)
{
    BaYaw *yaw;
    f32 speed;
    f32 diff;
    f32 dt;

    dt = func_800D8FF8();
    yaw = self->yaw;
    diff = func_80013728(yaw->ideal - yaw->value);

    speed = diff * rate;
    if (speed != 0) {
        speed = (speed < 0) ? func_800F0D50(speed, -limit, -3.0f)
                            : func_800F0D50(speed, 3.0f, limit);
    }
    yaw->unk8 = speed;
    yaw->value += func_800F212C(speed * dt, diff);
    yaw->value = func_800136E4(yaw->value);
}

void yaw_init(PlayerState *self)
{
    self->yaw->value = 0.0f;
    self->yaw->ideal = 0.0f;
    yaw_setVelocityBounded(self, 700.0f, 7.5f);
    yaw_setVelocityUnbounded(self, 360.0f);
    self->yaw->update_type = YAW_TYPE_0_NONE;
    yaw_setUpdateType(self, YAW_TYPE_1_DEFAULT);
}

void yaw_update(PlayerState *self)
{
    switch (self->yaw->update_type) {
        case YAW_TYPE_0_NONE:
            break;
        case YAW_TYPE_1_DEFAULT:
            __yaw_update_limited(self, 700.0f, 7.5f);
            break;
        case YAW_TYPE_2_UNBOUNDED:
            __yaw_update_limitless(self, self->yaw->velocity_degPerSec);
            break;
        case YAW_TYPE_3_BOUNDED:
            __yaw_update_limited(self, self->yaw->limit_degPerSec, self->yaw->step_percent);
    }
}

void yaw_setUpdateType(PlayerState *self, YawType type)
{
    self->yaw->update_type = type;
}

void yaw_setIdeal(PlayerState *self, f32 angle)
{
    self->yaw->ideal = func_800136E4(angle);
}

void yaw_set(PlayerState *self, f32 angle)
{
    self->yaw->value = func_800136E4(angle);
}

void yaw_applyIdeal(PlayerState *self)
{
    self->yaw->value = self->yaw->ideal;
}

f32 yaw_get(PlayerState *self)
{
    return self->yaw->value;
}

f32 yaw_getIdeal(PlayerState *self)
{
    return self->yaw->ideal;
}

void yaw_setVelocityBounded(PlayerState *self, f32 limit, f32 rate)
{
    self->yaw->limit_degPerSec = limit;
    self->yaw->step_percent = rate;
}

void yaw_setVelocityUnbounded(PlayerState *self, f32 speed)
{
    self->yaw->velocity_degPerSec = speed;
}

// Sets the unbounded speed so the turn to ideal yaw takes time seconds.
void yaw_rotateTimed(PlayerState *self, f32 time)
{
    f32 diff = self->yaw->ideal - self->yaw->value;
    if (180.0f < mlAbsF(diff)) {
        diff += (diff < 0.0f) ? 360.0f : -360.0f;
    }

    self->yaw->velocity_degPerSec = mlAbsF(diff / time);
}
