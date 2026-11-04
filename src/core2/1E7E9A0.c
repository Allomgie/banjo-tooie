// Probably thin wrappers that apply camera-instance calls to the current player's camera, plus a
// helper turning the direction between two points into pitch and yaw.
#include "core2/1E7E9A0.h"

f32 func_800136E4(f32);

// Facade over the current player's camera instance.

// Set the camera type of the current player's camera.
void func_800A50B0(s32 type)
{
    func_8010F9C0(func_8008FFE8(), type);
}

// Get the camera type of the current player's camera.
void func_800A50DC()
{
    func_8010FAE4(func_8008FFE8());
}

// Applies to all player cameras.
void func_800A5104()
{
    func_800A92A8();
}

// Applies to all player cameras.
void func_800A5124()
{
    func_800A9318();
}

void func_800A5144()
{
    func_8010FD88(func_8008FFE8());
}

// Look-at rotation (pitch/yaw) from two points.
// Pitch and yaw angles (roll 0) of the direction from one point to another.
void func_800A516C(f32 angles[3], f32 from[3], f32 to[3])
{
    func_800F18FC(from, to, angles);
    angles[0] = func_800136E4(-angles[0]);
    angles[2] = 0.0f;
}
