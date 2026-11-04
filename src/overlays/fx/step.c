// Footstep sounds: alternates two sound sources per foot, picks the surface (or water) under the
// actor and plays the step sound with random pitch and volume; also one-shot surface sounds.
#include "common.h"

extern void func_800C301C(u8, s32);
extern void func_800C35E8(u8, void *);
extern void func_800C3BDC(u8);
extern int func_800C3058(u8, unsigned int);
extern void func_800C31DC(u8, f32);
extern f32 func_800DC178(f32, f32);
typedef struct {
    s32 unk_0;
    f32 pos[3];
    u8 pad_10[0x14];
    u8 source_a;
    u8 source_b;
    u8 foot;
} FxStepState;
// Per-surface entry: two sounds (one per foot), pitch range, volume.
typedef struct {
    s16 id;
    s16 first;
    s16 second;
    s16 pad_6;
    f32 low;
    f32 high;
    f32 scale;
    s16 count;
    s16 pad_16;
} StepEffect;
extern StepEffect D_80800830_fxstep[];
typedef struct {
    s16 id;
    s16 sound;
    f32 pitch;
    f32 pitch_range;
    s16 volume;
    s16 pad_E;
} StepSoundRecord;
extern StepSoundRecord D_80800AA0_fxstep[];
extern void *heap_alloc(s32);
extern u8 func_800C2E04(void);
extern void func_800C330C(u8, s32);
extern void func_800C3418();
extern void func_800C3584(u8, f32, f32);
void fxstep_entrypoint_4();
int fxstep_entrypoint_5(s32 param_0, s32 param_1, f32 param_2);
void fxstep_entrypoint_7();
extern s32 fxstep_entrypoint_15(s32, s32, s32 *, s32 *, f32 *);

// Returns the surface type under the actor; 4 = water.
s32 func_80800000_fxstep(u8 *state)
{
    f32 water_dist;
    s32 ground;
    water_dist = *(f32 *) ((s8 *) state + 0x10) - *(f32 *) ((s8 *) state + 8);
    if ((water_dist > 0.0f) && (water_dist < 60.0f)) {
        return 4;
    }
    ground = *(s32 *) ((s8 *) state + 0);
    if (ground == 0) {
        return 0;
    }
    // Matching: the repeated masks are needed for the match.
    return func_800C84B0(
        (((((ground & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) &
            0xFFFFFFFF,
        ground);
}

// Plays one step sound with randomized pitch, then switches foot.
void func_80800078_fxstep(u8 *state, s32 sound_id, f32 pitch, f32 pitch_range, s32 volume)
{
    f32 half_range;
    f32 rand_pitch;
    u8 source;

    half_range = pitch_range * 0.5f;
    rand_pitch = func_800DC178(pitch - half_range, pitch + half_range);
    if (state[0x26])
        source = state[0x24];
    else
        source = state[0x25];
    func_800C35E8(source, state + 4);
    func_800C301C(source, sound_id);
    func_800C31DC(source, rand_pitch);
    func_800C3058(source, volume);
    func_800C3BDC(source);
    state[0x26] ^= 1;
}

// Same as above, with a separate sound and pitch for each foot.
void func_8080012C_fxstep(FxStepState *state, s32 sound_a, s32 sound_b, f32 pitch_a, f32 pitch_b,
                          f32 pitch_range, s32 volume)
{
    f32 pitch;
    f32 half_range;
    s32 sound;
    u8 source;

    pitch = state->foot ? pitch_a : pitch_b;
    half_range = pitch_range * 0.5f;
    pitch = func_800DC178(pitch - half_range, pitch + half_range);
    sound = state->foot ? sound_a : sound_b;
    source = state->foot ? state->source_a : state->source_b;
    func_800C35E8(source, state->pos);
    func_800C301C(source, sound);
    func_800C31DC(source, pitch);
    func_800C3058(source, volume);
    func_800C3BDC(source);
    state->foot ^= 1;
}

int func_80800210_fxstep(void *state, f32 pitch_offset, f32 volume_scale, s32 surface)
{
    s32 i;

    for (i = 0; D_80800830_fxstep[i].id != 0; i++) {
        if (surface == D_80800830_fxstep[i].id) {
            func_8080012C_fxstep(
                state, D_80800830_fxstep[i].first, D_80800830_fxstep[i].second,
                D_80800830_fxstep[i].low + pitch_offset, D_80800830_fxstep[i].high + pitch_offset,
                D_80800830_fxstep[i].scale,
                (s32) ((f32) D_80800830_fxstep[i].count * volume_scale));
            return 1;
        }
    }
    return 0;
}

int func_808002B4_fxstep(void *state, f32 pitch_offset, f32 volume_scale, s32 surface)
{
    s32 i;

    for (i = 0; D_80800AA0_fxstep[i].id != 0; i++) {
        if (D_80800AA0_fxstep[i].id == surface) {
            func_80800078_fxstep(
                state, D_80800AA0_fxstep[i].sound, D_80800AA0_fxstep[i].pitch + pitch_offset,
                D_80800AA0_fxstep[i].pitch_range, (s32) (D_80800AA0_fxstep[i].volume * volume_scale));
            return 1;
        }
    }
    return 0;
}

void func_80800344_fxstep(void *state, f32 pitch_offset, f32 volume_scale, s32 play)
{
    s32 surface;
    void (*callback)(void *, s32, s32);

    surface = func_80800000_fxstep(state);
    if (play) {
        // Matching: the f32 reinterpret casts are needed for the match.
        func_80800210_fxstep(state, *(f32 *) &pitch_offset, *(f32 *) &volume_scale, surface);
    }
    callback = *(void (**)(void *, s32, s32))((u8 *) state + 0x14);
    if (callback != NULL) {
        callback(state, surface, *(s32 *) ((u8 *) state + 0x14 + 4));
    }
}

void func_808003B4_fxstep(void *state, f32 pitch_offset, f32 volume_scale, s32 play)
{
    s32 surface;
    void (*callback)(void *, s32, s32);

    surface = func_80800000_fxstep(state);
    if (play) {
        func_808002B4_fxstep(state, pitch_offset, volume_scale, surface);
    }
    callback = *(void (**)(void *, s32, s32))((u8 *) state + 0x1C);
    if (callback != NULL) {
        callback(state, surface, *(s32 *) ((u8 *) state + 0x1C + 4));
    }
}

void fxstep_entrypoint_0(void *state)
{
    func_800C2FDC(*(char *) ((char *) state + 0x24));
    func_800C2FDC(*(char *) ((char *) state + 0x25));
    heap_free(state);
}

void *fxstep_entrypoint_1(void)
{
    u8 *state;

    state = heap_alloc(0x28);
    state[0x26] = 0;
    state[0x27] = 1;
    state[0x24] = func_800C2E04();
    func_800C330C(state[0x24], 3);
    func_800C3418(state[0x24], 0);
    state[0x25] = func_800C2E04();
    func_800C330C(state[0x25], 3);
    func_800C3418(state[0x25], 0);
    func_800EFD24((f32 *) (state + 4));
    fxstep_entrypoint_4(state, 0, 0);
    fxstep_entrypoint_5(state, 0, 0.0f);
    fxstep_entrypoint_7(state, 0, 0);
    return state;
}

int fxstep_entrypoint_2(u8 *state, unsigned int foot)
{
    state[0x26] = foot;
}

fxstep_entrypoint_3(s32 state, s32 enabled)
{
    *(s8 *) (state + 0x27) = enabled;
}

void fxstep_entrypoint_4(state, callback, callback_arg) void *state;
s32 callback;
s32 callback_arg;
{
    ((u32 *) state)[7] = callback;
    ((u32 *) state)[8] = callback_arg;
}

fxstep_entrypoint_5(s32 state, s32 ground, f32 water_level)
{
    *(s32 *) (state + 0x0) = ground;
    *(f32 *) (state + 0x10) = water_level;
}

s32 fxstep_entrypoint_6(s32 *state)
{
    s32 *pos;
    int offset;
    // Matching: extra temporary and nested block are needed for the match.
    offset = 1;
    {
        pos = state + offset;
        func_800EE7F8(pos);
    }
}

void fxstep_entrypoint_7(void *state, s32 callback, s32 callback_arg)
{
    ((s32 *) state)[5] = callback;
    ((s32 *) state)[6] = callback_arg;
}

void fxstep_entrypoint_8(u8 *state, f32 pitch_offset, f32 volume_scale)
{
    func_808003B4_fxstep(state, pitch_offset, volume_scale, state[0x27]);
}

void fxstep_entrypoint_9(s32 state)
{
    func_808003B4_fxstep(state, 0.0f, 1.0f, 0);
}

int fxstep_entrypoint_10(s32 state, s32 surface)
{
    func_808002B4_fxstep(state, 0, 1.0f, surface);
}

void fxstep_entrypoint_11(u8 *state, f32 pitch_offset, f32 volume_scale)
{
    func_80800344_fxstep(state, pitch_offset, volume_scale, state[0x27]);
}

void fxstep_entrypoint_12(s32 state)
{
    func_80800344_fxstep(state, 0, 1.0f, 0);

}

void fxstep_entrypoint_13(u8 *state, s32 surface)
{
    if (state[0x27] != 0) {
        func_80800210_fxstep(state, 0, 1.0f, surface);
    }

}

// One-shot surface sound at a position, for actors without footstep state.
void fxstep_entrypoint_14(s32 surface, s32 variant, void *pos, s32 range_min, s32 range_max)
{
    s32 sound;
    s32 volume;
    f32 pitch;
    u8 source;

if (fxstep_entrypoint_15(surface, variant, &sound, &volume, &pitch)) {
    source = func_800C2E04();
    func_800C330C(source, 1);
    func_800C35E8(source, pos);
    func_800C301C(source, sound);
    func_800C31DC(source, func_800DC178(-0.05f, 0.05f) + pitch);
    func_800C3058(source, volume);
    func_800C3584(source, (f32) range_min, (f32) range_max);
    func_800C3BDC(source);
}

}

s32 fxstep_entrypoint_15(surface, variant, out_sound, out_volume, out_pitch)
s32 surface;
s32 variant;
s32 *out_sound;
s32 *out_volume;
f32 *out_pitch;
{
    s32 i;

    for (i = 0; D_80800830_fxstep[i].id != 0; i++) {

if (surface == D_80800830_fxstep[i].id) {
    if (variant) {
        *out_pitch = D_80800830_fxstep[i].low;
        *out_sound = D_80800830_fxstep[i].first;
    } else {
        *out_pitch = D_80800830_fxstep[i].high;
        *out_sound = D_80800830_fxstep[i].second;
    }
    *out_pitch += func_800DC178(-0.05f, 0.05f);
    *out_volume = D_80800830_fxstep[i].count;
    return 1;
}

}
return 0;
}

// TU-NOTE: the overlay's .data is defined here in C; values taken from the ROM.
StepEffect D_80800830_fxstep[26] = {
    0x1,   0x404,  0x404, 0x0,   1.0f,   1.2f,  0.05f, 0x2328, 0x0,   0x2,   0x403,  0x403,
    0x0,   1.0f,   1.2f,  0.05f, 0xBB8,  0x0,   0x3,   0x405,  0x405, 0x0,   1.0f,   1.2f,
    0.05f, 0x2AF8, 0x0,   0x4,   0x40A,  0x40A, 0x0,   1.0f,   1.2f,  0.05f, 0x32C8, 0x0,
    0x5,   0x419,  0x419, 0x0,   1.0f,   1.2f,  0.05f, 0x2328, 0x0,   0x6,   0x402,  0x402,
    0x0,   1.0f,   1.2f,  0.05f, 0x1B58, 0x0,   0x7,   0x41B,  0x41B, 0x0,   1.0f,   1.0f,
    0.05f, 0x2710, 0x0,   0x8,   0x401,  0x401, 0x0,   0.7f,   0.8f,  0.05f, 0x4268, 0x0,
    0xB,   0x40A,  0x40A, 0x0,   0.5f,   0.55f, 0.01f, 0x3E80, 0x0,   0x9,   0x459,  0x459,
    0x0,   1.0f,   1.1f,  0.05f, 0x5208, 0x0,   0xA,   0x45A,  0x45A, 0x0,   1.0f,   1.1f,
    0.05f, 0x5208, 0x0,   0xC,   0x482,  0x482, 0x0,   0.85f,  0.89f, 0.05f, 0x5208, 0x0,
    0xD,   0x3F0,  0x3F0, 0x0,   0.96f,  1.04f, 0.02f, 0x2710, 0x0,   0xE,   0x40A,  0x40A,
    0x0,   1.2f,   1.35f, 0.05f, 0x32C8, 0x0,   0xF,   0x46F,  0x46F, 0x0,   0.95f,  1.1f,
    0.05f, 0x3E80, 0x0,   0x10,  0x41B,  0x41B, 0x0,   1.0f,   1.0f,  0.05f, 0x2328, 0x0,
    0x11,  0x4AE,  0x4AE, 0x0,   1.0f,   1.0f,  0.05f, 0x2328, 0x0,   0x12,  0x4BC,  0x4BC,
    0x0,   1.0f,   1.0f,  0.05f, 0x2328, 0x0,   0x13,  0x56E,  0x56E, 0x0,   1.0f,   1.1f,
    0.05f, 0x2AF8, 0x0,   0x15,  0x40A,  0x40A, 0x0,   1.0f,   1.2f,  0.05f, 0x32C8, 0x0,
    0x16,  0x56E,  0x56E, 0x0,   1.0f,   1.1f,  0.05f, 0x32C8, 0x0,   0x17,  0x5C2,  0x5C2,
    0x0,   1.4f,   1.5f,  0.05f, 0x61A8, 0x0,   0x1A,  0x4D5,  0x4D5, 0x0,   1.0f,   1.5f,
    0.05f, 0x61A8, 0x0,   0x14,  0x60F,  0x60F, 0x0,   1.0f,   1.2f,  0.05f, 0x2AF8, 0x0,
    0x18,  0x402,  0x402, 0x0,   1.0f,   1.2f,  0.05f, 0x1B58, 0x0,   0x0,   0x0,    0x0,
    0x0,   0.0f,   0.0f,  0.0f,  0x0,    0x0};
StepSoundRecord D_80800AA0_fxstep[23] = {
    0x1,  0x44A, 1.0f, 0.05f, 0x2EE0, 0x0, 0x2,  0x44E, 1.0f,  0.05f, 0xBB8,  0x0,
    0x3,  0x405, 1.0f, 0.05f, 0x36B0, 0x0, 0x4,  0x40A, 1.0f,  0.05f, 0x32C8, 0x0,
    0x5,  0x450, 1.0f, 0.05f, 0x2AF8, 0x0, 0x6,  0x44C, 1.0f,  0.05f, 0x2710, 0x0,
    0x7,  0x41B, 1.0f, 0.05f, 0x4268, 0x0, 0x8,  0x401, 0.7f,  0.05f, 0x4268, 0x0,
    0xB,  0x40A, 0.5f, 0.03f, 0x4268, 0x0, 0x9,  0x459, 1.0f,  0.05f, 0x55F0, 0x0,
    0xA,  0x45A, 1.0f, 0.05f, 0x55F0, 0x0, 0xC,  0x482, 0.9f,  0.05f, 0x55F0, 0x0,
    0x10, 0x41B, 1.0f, 0.05f, 0x55F0, 0x0, 0x11, 0x4AE, 1.0f,  0.05f, 0x55F0, 0x0,
    0x12, 0x4BC, 1.0f, 0.05f, 0x55F0, 0x0, 0x13, 0x56E, 1.0f,  0.05f, 0x7FFF, 0x0,
    0x15, 0x40A, 1.0f, 0.05f, 0x32C8, 0x0, 0x16, 0x56E, 0.85f, 0.05f, 0x6D60, 0x0,
    0x17, 0x5C2, 1.4f, 0.05f, 0x7D00, 0x0, 0x1A, 0x4D5, 1.0f,  0.05f, 0x7D00, 0x0,
    0x14, 0x60F, 1.0f, 0.05f, 0x36B0, 0x0, 0x18, 0x44C, 1.0f,  0.05f, 0x2710, 0x0,
    0x0,  0x0,   0.0f, 0.0f,  0x0,    0x0};
