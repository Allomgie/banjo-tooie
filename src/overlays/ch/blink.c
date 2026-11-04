// Probably an eye-blink helper for scripted characters: steps a blink sequence table with random
// delays and writes the interpolated values as eye texture frames before drawing.
#include "common.h"

extern f32 func_800DC178(f32, f32);
extern u8 func_800DC128(s32, s32);
typedef struct {
    f32 cur[2];
    f32 target[2];
    f32 speed[2];
    u8 pad_18[0xC];
    s32 eye_set;
    s32 unk_28;
} BlinkStorage;
extern void *func_8001B798();
typedef struct {
    f32 duration;
    u8 kind;
    u8 pad_5[3];
    f32 minimum;
    f32 maximum;
} BlinkStep;
typedef struct {
    u8 pad_0[0x18];
    f32 timer;
    s32 index;
} BlinkSequence;
extern f32 func_800D8FF8(void);
extern f32 mlAbsF(f32);
typedef struct {
    f32 cur[2];
    f32 target[2];
    f32 speed[2];
} BlinkState;
extern f32 D_80800430_chblink[];
extern void func_8001B754();
extern s32 D_80800580_chblink[][3];
extern f32 func_800F1214(f32, f32, f32);

// Reset the blink state: set mode and pick a random initial delay and step.
void chblink_entrypoint_0(u8 *blink, s32 unk_0)
{
    *(s32 *) (blink + 0x28) = unk_0;
    *(f32 *) (blink + 0x18) = func_800DC178(0.0f, 5.0f);
    *(s32 *) (blink + 0x1C) = func_800DC128(0, 0x14);
}

// Allocate a blink handle; eye_set selects the texture frame row.
s16 chblink_entrypoint_1(s32 eye_set)
{
    s16 handle;
    BlinkStorage *storage;
    s32 i;
    handle = func_8001B668(0, 0x2C);
    storage = func_8001B798(handle);
    storage->eye_set = eye_set;
    for (i = 0; i < 2; i++) {
        storage->speed[i] = 0.0f;
        storage->target[i] = 0.0f;
        storage->cur[i] = 0.0f;
    }
    chblink_entrypoint_0(storage, 2);
    return handle;
}

// Set the target of value slot and the speed to reach it in duration (or jump if 0).
int func_808000CC_chblink(volatile f32 *values, s32 slot, f32 target, f32 duration)
{
    values[slot + 2] = target;
    if (duration != 0.0f) {
        values[slot + 4] = (values[slot + 2] - values[slot]) / duration;
    } else {
        values[slot] = values[slot + 2];
    }
}

// Advance the step table by the frame time.
void func_80800118_chblink(BlinkSequence *seq, BlinkStep *steps, s32 loop)
{
    f32 dt;
    BlinkStep *step;
    dt = func_800D8FF8();
    while (dt > 0.0f) {
        seq->timer -= dt;
        if (seq->timer > 0.0f)
            break;
        dt = mlAbsF(seq->timer);
        step = &steps[seq->index];
        func_808000CC_chblink(seq, step->kind, step->minimum, step->maximum);
        step++;
        if (step->kind == 2) {
            step = steps;
            if (!loop) {
                chblink_entrypoint_0(seq, 1);
                break;
            }
            seq->index = 0;
        } else {
            seq->index++;
        }
        seq->timer = step->duration;
    }
}

void chblink_entrypoint_2(handle) s16 handle;
{
    BlinkState *state;
    f32 dt;
    s32 i;

    state = func_8001B798(handle);
    dt = func_800D8FF8();
    func_80800118_chblink(state, &D_80800430_chblink, 1);
    for (i = 0; i < 2; i++) {
        if (state->target[i] != state->cur[i]) {
            state->cur[i] += state->speed[i] * dt;
            if ((0.0f < state->speed[i] && state->target[i] < state->cur[i]) ||
                (state->speed[i] < 0.0f && state->cur[i] < state->target[i])) {
                state->cur[i] = state->target[i];
            }
        }
    }
}

void chblink_entrypoint_3(handle) s16 handle;
{
    func_8001B754(handle);
}

// Write the eye texture frames for the current blink value.
void chblink_entrypoint_4(handle) s16 handle;
{
    u8 *blink;
    s32 i;
    s32 model_part;

    blink = func_8001B798(handle);
    for (i = 0; i < 2; i++) {
        model_part = D_80800580_chblink[*(s32 *) (blink + 0x24)][i];

if (model_part != -1) {
    func_800DF744(model_part, (s32) func_800F1214(*(f32 *) blink, 1.0f,
                                               D_80800580_chblink[*(s32 *) (blink + 0x24)][2]));
}

}
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM); the extern of
// D_80800430_chblink is declared as f32[] to match the object.
f32 D_80800430_chblink[84] = {2.0f, 2.3509887e-38f, 1.0f, 0.1f,  0.034f, 0.0f, 1.0f, 0.1f,
                              0.1f,  2.3509887e-38f, 0.0f, 0.1f,  0.034f, 0.0f, 0.0f, 0.1f,
                              5.0f,  2.3509887e-38f, 1.0f, 0.06f, 0.034f, 0.0f, 1.0f, 0.06f,
                              0.06f, 2.3509887e-38f, 0.0f, 0.06f, 0.034f, 0.0f, 0.0f, 0.06f,
                              0.2f,  2.3509887e-38f, 1.0f, 0.09f, 0.034f, 0.0f, 1.0f, 0.09f,
                              0.09f, 2.3509887e-38f, 0.0f, 0.09f, 0.034f, 0.0f, 0.0f, 0.09f,
                              1.0f,  2.3509887e-38f, 1.0f, 0.1f,  0.034f, 0.0f, 1.0f, 0.1f,
                              0.1f,  2.3509887e-38f, 0.0f, 0.1f,  0.034f, 0.0f, 0.0f, 0.1f,
                              5.0f,  2.3509887e-38f, 1.0f, 0.1f,  0.034f, 0.0f, 1.0f, 0.1f,
                              0.1f,  2.3509887e-38f, 0.0f, 0.1f,  0.034f, 0.0f, 0.0f, 0.1f,
                              0.0f,  9.403955e-38f,  0.0f, 0.0f};
s32 D_80800580_chblink[4][3] = {0x34, 0x35, 0x8, 0x1, -0x1, 0x4, 0x3, 0x3, 0x4, 0x38, 0x39, 0x8};
