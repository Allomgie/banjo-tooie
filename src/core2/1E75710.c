#include "core2/1E75710.h"

extern f32 func_800D8FF8(void);
extern f32 func_80013728(f32);
extern f32 func_800F0D50(f32, f32, f32);
extern f32 func_800F212C(f32, f32);
extern f32 func_800136E4(f32);

typedef struct {
    f32 value;
    f32 ideal;
} Struct8009BF04Local;
typedef struct {
    u8 pad_0[0xDC];
    Struct8009BF04Local *pitch; // {value, ideal, max_speed, step_factor}
} Struct8009BF04;

s32 func_8009BE20()
{
    return 0x10;
}

// Moves pitch toward its ideal angle at a limited rate (same as the yaw limited mode).
// Matching: the line breaks in this function are needed for the match.
void func_8009BE28(u8 *player, f32 max_speed, f32 step_factor)
{
    f32 speed;
    f32 limited;
    f32 diff_saved;
    f32 dt;
    u8 *pitch;
    f32 step;
    int offset;
    f32 diff;
    f32 speed_copy;
    dt = func_800D8FF8();
    pitch = *(u8 **) ((s8 *) player + 0xDC);
    offset = 0; // Matching: needed for the match.
    diff = func_80013728(*(f32 *) ((s8 *) pitch + 4) - *(f32 *) ((s8 *) pitch + offset));
    diff_saved = diff;
    speed_copy = (speed = diff * step_factor);
    if (speed != 0.0f)
    {
        {
            if (speed < 0.0f)
            {
                limited = func_800F0D50(speed, -max_speed, -3.0f); } else { limited = func_800F0D50(speed, 3.0f * 1.0f, max_speed); }  } speed = limited; } 0; step = func_800F212C(speed * dt, diff_saved);
    *(f32 *) pitch = *(f32 *) pitch + step;
    *(f32 *) pitch = func_800136E4(*(f32 *) pitch);

}

void func_8009BF04(Struct8009BF04 *player)
{
    player->pitch->value = 0.0f;
    player->pitch->ideal = 0.0f;
    func_8009C000(player);
}

void func_8009BF34(u8 *player)
{
    u8 **pitch;
    pitch = *(u8 ***) (player + 0xDC);
    func_8009BE28(player, *(f32 *) (pitch + 2), *(f32 *) (pitch + 3));
}

void func_8009BF5C(PlayerState *player, f32 ideal)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xDC) + 0x4) = func_800136E4(ideal);
}

void func_8009BF8C(PlayerState *player, f32 value)
{
    *(f32 *) (*(s32 *) ((char *) player + 0xDC) + 0x0) = func_800136E4(value);
}

// Snaps pitch to its ideal angle.
void func_8009BFBC(void *player)
{
    f32 *pitch = *(f32 **) ((char *) player + 0xDC);
    pitch[0] = pitch[1];
}

f32 func_8009BFCC(PlayerState *player)
{
    return *(f32 *) ((char *) *(struct ba_unknown_c_s **) ((u8 *) player + 0xDC) + 0x0);
}

f32 func_8009BFD8(PlayerState *player)
{
    return *(f32 *) ((char *) *(struct ba_unknown_c_s **) ((char *) player + 0xDC) + 0x4);
}

void func_8009BFE4(PlayerState *player, f32 max_speed, f32 step_factor)
{
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xDC) + 8) = max_speed;
    *(f32 *) ((s8 *) *(u8 **) ((s8 *) player + 0xDC) + 0xC) = step_factor;
}

// Default rate: 500 deg/s, step factor 0.8.
void func_8009C000(PlayerState *player)
{
    // Matching: needed for the match.
    float max_speed;
    max_speed = 500.0f;
    func_8009BFE4(player, max_speed, 0.8f);
}
