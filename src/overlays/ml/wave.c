// Oscillator helper (mlwave) for bobbing/floating actors: advances a phase with an approaching
// speed, can be randomised, and maps sin(phase) into a [lo, hi] range.
#include "common.h"

extern f32 func_800DC178(f32, f32);
extern f32 func_8001395C(f32);
extern f32 func_800F13C4(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
f32 mlwave_entrypoint_6();

// Wave layout (f32[7]): [0] phase, [1] 2pi / period, [2] period, [3] speed,
// [4] target speed, [5] acceleration, [6] normalised value (0..1)
void mlwave_entrypoint_0(f32 *wave, f32 period, f32 speed)
{
    wave[3] = speed;
    wave[4] = speed;
    wave[2] = period;
    wave[0] = 0.0f;
    wave[5] = 100.0f;
    if (period) {
        wave[1] = 6.2831855f / period;
    } else {
        wave[1] = 0.0f;
    }
    wave[6] = 0.0f;
}

void mlwave_entrypoint_1(f32 *wave)
{
    extern f32 func_800D8FF8(void);
    extern f32 func_800F15F8(f32, f32, f32);
    f32 dt;

    dt = func_800D8FF8();
    wave[6] = mlwave_entrypoint_6(wave);
    wave[3] = func_800F15F8(wave[3], wave[4], wave[5] * dt);
    wave[0] += wave[3] * dt;
}

// Randomises the phase
void mlwave_entrypoint_2(f32 *wave, f32 lo, f32 hi)
{
    wave[0] = func_800DC178(lo, hi) * wave[2];
    wave[6] = mlwave_entrypoint_6(wave);
}

void mlwave_entrypoint_3(Actor *wave, f32 rate, f32 accel)
{
    f32 *field;
    // Matching: the pointer round trip is needed for the match.
    field = (char *) wave;
    *(f32 *) (field + 4) = rate;
    *(field = (f32 *) (field + 5)) = accel;
}

// Maps sin(phase) into [lo, hi]
f32 mlwave_entrypoint_4(f32 *wave, f32 time, f32 lo, f32 hi)
{
    return func_800F10B4(func_8001395C((time - wave[0]) * wave[1]), -1.0f, 1.0f, lo,
                         hi);
}

f32 mlwave_entrypoint_5(s32 wave, f32 lo, f32 hi)
{
    return mlwave_entrypoint_4(wave, 0.0f, lo, hi);
}

// Normalised value of the phase, wrapped by the period
f32 mlwave_entrypoint_6(wave)
f32 *wave;
{
    f32 wrapped;
    f32 limit;

    wrapped = func_800F13C4(wave[0], wave[2]);
    if (wave[0] < 0) {
        limit = -wave[2];
    } else {
        limit = wave[2];
    }
    return func_800F10B4(wrapped, 0.0f, limit, 0.0f, 1.0f);
}

int mlwave_entrypoint_7(f32 wave[3], f32 norm)
{
    wave[0] = wave[2] * norm;
    wave[6] = norm;
}

// Whether the normalised value passed `value` since the last update (handles wrap-around)
s32 mlwave_entrypoint_8(u8 *wave, f32 value)
{
    f32 cur;
    f32 prev;
    s32 crossed;

    prev = *(f32 *) (wave + 0x18);
    cur = mlwave_entrypoint_6((f32 *) wave);

    if (*(f32 *) (wave + 12) > 0.0f) {
        if (prev < cur) {
            return prev <= value && value < cur;
        }
        crossed = prev <= value || value < cur;
        // Matching: redundant tests needed for the match.
        if (crossed && crossed && crossed) {
        }
        return crossed | 0;
    }
    if (cur < prev) {
        crossed = value <= prev && cur < value;
    } else {
        crossed = value <= prev || cur < value;
    }
    return crossed | 0;
}

// Returns 1 if any value in the list (terminated by -1) was crossed
s32 mlwave_entrypoint_9(s32 wave, f32 *values)
{
    float end_marker;
    f32 *cursor;
    f32 value;
    end_marker = -1.0f;
    value = *values;
    cursor = values;
    if (*values != -1.0f) {
    loop_1:
        // Matching: `^ 0` needed for the match.
        if (mlwave_entrypoint_8(wave ^ 0, value) != 0) {
            return 1;
        }

        value = *(f32 *) ((char *) cursor + 4);
        cursor += 1;
        // Matching: comma expression needed for the match.
        if (value == (0, end_marker)) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return 0;
}
