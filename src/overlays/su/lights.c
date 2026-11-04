// Light animation manager: a pool of tween slots that fade, move or flicker point lights over
// time. Updated once per frame, cancellable per light, freed on world unload.
#include "common.h"

// Tween slot, kind 0 = free. Kinds: 1 colour fade, 2 radii fade, 3 colour flicker,
// 4 colour ping-pong, 5 radii ping-pong.
typedef struct {
    u8 kind;
    u8 light;
    u8 pad_2[0x32];
    f32 elapsed;
    u32 pad_38;
} LightSlot;
extern void *D_80127EF0;
extern void *vector_new(s32, s32);
extern void *vector_end(void *);
extern void *vector_begin(void *);
extern void *vector_push_back(void **);
extern void func_800C8E84();
typedef struct {
    u8 kind;
    u8 light;
    u8 pad_2[2];
    s32 start[3];
    s32 delta[3];
    u8 pad_1C[0x18];
    f32 elapsed;
    f32 duration;
} LightColorStep;
typedef struct {
    u8 kind;
    u8 light;
    u8 pad_2[0x1A];
    f32 start[3];
    f32 delta[3];
    f32 elapsed;
    f32 duration;
} LightPositionState;
extern void func_800C8D4C(s32, f32 *);
typedef struct {
    u8 kind;
    u8 light;
    u8 pad_2[2];
    s32 center[3];
    s32 range[3];
    u8 pad_1C[0x18];
    f32 elapsed;
    f32 speed;
} LightState30;
extern f32 func_800DC0C0(void);
typedef struct {
    u8 pad_0[4];
    s32 start[3];
    s32 delta[3];
    u8 pad_1C[0x18];
    f32 elapsed;
} LightS;
typedef struct {
    u8 pad_0[0x1C];
    f32 start[3];
    f32 delta[3];
    f32 elapsed;
} LightMotionState;
typedef struct {
    u8 kind;
    u8 pad_1[0x33];
    f32 elapsed;
    f32 duration;
} LightUpdate27;
typedef struct {
    void (*update)(LightUpdate27 *);
    void (*on_finish)(LightUpdate27 *);
} LightCallbacks27;
extern LightCallbacks27 D_80800A00_sulights[];
extern f32 func_800D8FF8(void);
extern void func_800EE830(s32 *, s32 *);

typedef struct {
    u32 header;
    s32 start[3];
    s32 delta[3];
    u8 pad_1C[0x1C];
    f32 duration;
} CodexLightTween;
typedef struct {
    s32 header;
    s32 start[3];
    s32 delta[3];
    u8 pad_1C[0x1C];
    f32 duration;
} LightColorTransition;

// Returns a free slot (growing the pool if needed), initialised for the given kind and light.
f32 *func_80800000_sulights(s32 kind, s32 light)
{
    LightSlot *slot;
    LightSlot *end;

    if (!D_80127EF0)
        D_80127EF0 = vector_new(sizeof(LightSlot), 1);
    end = vector_end(D_80127EF0);
    slot = vector_begin(D_80127EF0);
    while (slot < end && slot->kind)
        slot++;
    if (slot == end)
        slot = vector_push_back(&D_80127EF0);
    slot->kind = kind;
    slot->light = light;
    slot->elapsed = 0.0f;
    return (f32 *) slot;
}

// Frees the slot.
s32 func_808000D0_sulights(u8 *slot)
{
    *slot = 0;
}

void func_808000D8_sulights(LightColorStep *step)
{
    s32 color[4];
    s32 i;
    f32 t;
    t = step->elapsed / step->duration;
    for (i = 0; i < 3; i++) {
        color[i] = step->start[i] + step->delta[i] * t;
    }
    func_800C8E84(step->light, color);
}

void func_80800194_sulights(LightPositionState *step)
{
    s32 i;
    f32 radii[2];
    f32 t;
    t = step->elapsed / step->duration;
    for (i = 0; i < 2; i++) {
        radii[i] = step->start[i] + step->delta[i] * t;
    }
    func_800C8D4C(step->light, radii);
}

// Flicker: nudges the colour by a random sign, clamped to center +- range.
void func_8080021C_sulights(LightState30 *state)
{
    s32 i;
    s32 color[3];
    f32 sign;
    sign = func_800DC0C0() > 0.5f ? 1.0f : -1.0f;
    func_800C8900(state->light, color);
    for (i = 0; i < 3; i++) {
        color[i] += sign * (state->speed * state->range[i] * state->elapsed);
        if (state->range[i] + state->center[i] < color[i])
            color[i] = state->range[i] + state->center[i];
        if (color[i] < state->center[i] - state->range[i])
            color[i] = state->center[i] - state->range[i];
    }
    func_800C8E84(state->light, color);
    state->elapsed = 0.0f;
}

// Colour ping-pong finish: restarts the cycle in the opposite direction.
void func_80800340_sulights(LightS *slot)
{
    s32 i;
    slot->elapsed = 0.0f;
    for (i = 0; i < 3; i++) {
        slot->start[i] += slot->delta[i];
        slot->delta[i] *= -1;
    }
}

// Radii ping-pong finish: restarts the cycle in the opposite direction.
void func_8080038C_sulights(LightMotionState *slot)
{
    s32 i;

    slot->elapsed = 0.0f;
    for (i = 0; i < 2; i++) {
        slot->start[i] += slot->delta[i];
        slot->delta[i] *= -1.0f;
    }
}

// Colour fade from `from` to `to`.
void sulights_entrypoint_0(s32 light, s32 *from, s32 *to, f32 duration)
{
    s32 i;
    CodexLightTween *tween;

    tween = (CodexLightTween *) func_80800000_sulights(1, light);
    if (duration < 0.001f) {
        tween->duration = 0.001f;
    } else {
        tween->duration = duration;
    }
    func_800EE830(tween->start, from);
    for (i = 0; i != 3; i++) {
        tween->delta[i] = to[i] - from[i];
    }
    func_800C8E84(light, from);
}

// Colour fade from the current colour.
s32 sulights_entrypoint_1(s32 light, s32 to, f32 duration)
{
    f32 current[3];

    func_800C8900(light, current);
    sulights_entrypoint_0(light, current, to, duration);
}

// Radii fade from `from` to `to`.
void sulights_entrypoint_2(s32 light, f32 *from, f32 *to, f32 duration)
{
    f32 *tween;
    s32 i;
    tween = func_80800000_sulights(2, light);
    tween[14] = duration < 0.001f ? 0.001f : duration;
    for (i = 0; i < 2; i++) {
        tween[7 + i] = from[i];
        tween[10 + i] = to[i] - from[i];
    }
    func_800C8D4C(light, from);
}

// Radii fade from the current radii.
s32 sulights_entrypoint_3(s32 light, s32 to, f32 duration)
{
    f32 current[2];

    func_800C883C(light, current);
    sulights_entrypoint_2(light, current, to, duration);
}

// Colour flicker around `center` by up to `range`.
void sulights_entrypoint_4(s32 light, s32 *center, s32 *range, f32 duration)
{
    LightColorTransition *tween;
    f32 clamped;
    tween = (LightColorTransition *) func_80800000_sulights(3, light);
    if (duration < 0.001f)
        clamped = 0.001f;
    else
        clamped = duration;
    tween->duration = 4.0f / clamped;
    tween->start[0] = center[0];
    tween->start[1] = center[1];
    tween->start[2] = center[2];
    tween->delta[0] = range[0];
    tween->delta[1] = range[1];
    tween->delta[2] = range[2];
    func_800C8E84(light, center);
}

// Colour ping-pong between `from` and `to`.
void sulights_entrypoint_5(s32 light, s32 *from, s32 *to, f32 duration)
{
    LightColorTransition *tween;
    s32 i;

    tween = (LightColorTransition *) func_80800000_sulights(4, light);
    if (duration < 0.001f) {
        tween->duration = 0.001f;
    } else {
        tween->duration = duration * 0.5f;
    }
    tween->start[0] = from[0];
    tween->start[1] = from[1];
    tween->start[2] = from[2];
    for (i = 0; i < 3; i++) {
        tween->delta[i] = to[i] - from[i];
    }
    func_800C8E84(light, from);
}

// Radii ping-pong between `from` and `to`.
void sulights_entrypoint_6(s32 light[3], f32 from[3], f32 to[3], f32 duration)
{
    s32 i;
    int delta_idx;
    f32 *tween = func_80800000_sulights(5, light);
    if (duration < 0.001f) {
        tween[14] = 0.001f;
    } else {
        tween[14] = duration / 2.0f;
    }
    for (i = 0; i < 2; i++) {
        tween[7 + i] = from[i];
        delta_idx = 10 + i;
        tween[delta_idx] = to[i] - from[i];
    }

    func_800C8D4C(light, from);
}

// Cancels all tweens of the light.
void sulights_entrypoint_7(long light)
{
    u8 *slot;
    u8 *begin;
    u8 *end;
    if (D_80127EF0 != 0) {
        end = vector_end(D_80127EF0);
        begin = vector_begin(D_80127EF0);
        slot = begin;
        if (begin < end) {
            do {
                if ((slot[0] != 0) && (light == slot[1])) {
                    func_808000D0_sulights(slot);
                }
                slot += 0x3C;
            } while (slot < end);
        }
    }
}

s32 sulights_entrypoint_8(void)
{
    if ((s32) D_80127EF0 != 0) {
        vector_free((s32) D_80127EF0);
        D_80127EF0 = 0;
    }
}

void sulights_entrypoint_9(void)
{
    LightUpdate27 *slot;
    LightUpdate27 *end;
    f32 dt;

    dt = func_800D8FF8();
    end = vector_end(D_80127EF0);
    for (slot = vector_begin(D_80127EF0); slot < end; slot++) {
        if (slot->kind) {
            slot->elapsed += dt;
            if (slot->elapsed > slot->duration) {
                slot->elapsed = slot->duration;
            }
            D_80800A00_sulights[slot->kind - 1].update(slot);
            if (slot->elapsed >= slot->duration) {
                if (D_80800A00_sulights[slot->kind - 1].on_finish) {
                    D_80800A00_sulights[slot->kind - 1].on_finish(slot);
                }
            }
        }
    }
}

// TU-NOTE: the overlay .data (callback table, update/on_finish per kind) is defined here in C.
// IDO's assembler schedules some of these functions differently unless the table is in the
// same unit. Values are taken from the ROM.
LightCallbacks27 D_80800A00_sulights[6] = {(void *) func_808000D8_sulights,
                                           (void *) func_808000D0_sulights,
                                           (void *) func_80800194_sulights,
                                           (void *) func_808000D0_sulights,
                                           (void *) func_8080021C_sulights,
                                           0,
                                           (void *) func_808000D8_sulights,
                                           (void *) func_80800340_sulights,
                                           (void *) func_80800194_sulights,
                                           (void *) func_8080038C_sulights,
                                           0,
                                           0};
