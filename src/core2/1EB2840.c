// Frame delta time: VI frames elapsed (clamped 1..15), delta in seconds, and timer helpers.
#include "core2/1EB2840.h"

extern s32 func_800F1574(f32 *param_0, f32 param_1);

extern s32 D_8012C764;
extern f32 D_8012C760;

// Sets the delta time in seconds, clamped to 0.05.
void func_800D8F50(f32 delta)
{
    if (delta < 0.050000004f) {
        D_8012C760 = delta;
    } else {
        D_8012C760 = 0.050000004f;
    }
}

void func_800D8F84()
{
    D_8012C760 = 0.01f;
    D_8012C764 = 0;
}

// Called once per frame with the elapsed VI frames (clamped to 1..15); delta = frames / 60.
void func_800D8FA0(s32 vi_frames)
{
    func_800D8F50((f32) (D_8012C764 = func_800F0D90(vi_frames, 1, 0xF)) * 0.016666668f);
}

// Returns the clamped number of elapsed VI frames.
u32 func_800D8FEC()
{
    return D_8012C764;
}

// Get Gamespeed: delta time in seconds.
f32 func_800D8FF8()
{
    return D_8012C760;
}

// Delta time in seconds without the 0.05 clamp (frames / 60).
f32 func_800D9004(void)
{
    return (f32) (s32) D_8012C764 * 0.016666668f;
}

// Delta time in 30 fps frames.
f32 func_800D902C(void)
{
    return func_800D8FF8() * 30.0f;
}

func_800D9058(f32 seconds)
{
    f32 scaled;
    s32 frames;

    scaled = seconds * 30.0f;
    frames = scaled;
    return frames;
}

// Steps a timer by the delta time (wraps func_800F1574).
u8 func_800D9078(f32 *timer)
{
    f32 delta;
    delta = func_800D8FF8();
    func_800F1574((s32) timer, delta);
}

// Steps a timer by the delta time; a timer at or below 0 is set to 0 and returns 1.
s32 func_800D90A4(f32 *timer)
{
    if (*timer > 0.0f) {
        return func_800F1574(timer, func_800D8FF8());
    }
    *timer = 0.0f;
    return 1;
}

// Counts the timer down by the delta; at limit it is clamped and 1 is returned.
int func_800D90F8(f32 *timer, f32 limit)
{
    *timer -= func_800D8FF8();
    if (*timer < limit) {
        *timer = limit;
        return 1;
    }
    return 0;
}

// Counts the timer down by the delta; below 0 it wraps by period and 1 is returned.
int func_800D9154(f32 *timer, f32 period)
{
    *timer -= func_800D8FF8();
    if (*timer < 0.0f) {
        *timer += period;
        return 1;
    }
    return 0;
}

// Counts the timer up by the delta and returns it.
f32 func_800D91B8(timer)
f32 *timer;
{
    *timer += func_800D8FF8();
    return *timer;

}

// TU-NOTE: func_800D91B8 is called here without an argument (K&R declaration).
s32 func_800D91EC(f32 *timer, f32 limit)
{
    if (limit < func_800D91B8()) {
        *timer = limit;
        return 1;
    }

return 0;
}
