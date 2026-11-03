// TU-NOTE: not including core2/1EB5980.h; it declares func_800DC128 as returning u8
// (what callers were compiled against), but the definition returns the full word.
#include "common.h"

extern s32 D_8012C7F0;
extern s32 D_8011B9A0;
extern s32 D_8011B9A4;
extern s32 D_8012C7F4;
extern s32 D_8012C7F8;
extern s32 D_8012C7FC;

// Two independent LCG streams: seed = seed * 1664525 + 1013904223.
// Stream 0 uses D_8012C7F0, stream 1 uses D_8012C7F4.
s32 func_800DC090(void)
{
    return D_8012C7F0 = D_8012C7F0 * 0x19660D + 0x3C6EF35F;
}

// Random float in [0, 1): random mantissa bits under exponent 1.0f, minus 1.0f.
f32 func_800DC0C0(void)
{
    s32 bits;
    f32 value;

    D_8012C7F0 = D_8012C7F0 * 0x19660D + 0x3C6EF35F;
    bits = (D_8011B9A4 & D_8012C7F0) | D_8011B9A0;
    value = *(f32 *) &bits - 1.0f;
    return value;
}

s32 func_800DC128(s32 lo, s32 hi)
{
    f32 range;
    f32 result;
    range = hi - lo;
    result = (range * func_800DC0C0()) + lo;
    return result;
}

f32 func_800DC178(f32 lo, f32 hi)
{
    return func_800DC0C0() * (hi - lo) + lo;
}

// Same as func_800DC0C0, on stream 1.
f32 func_800DC1AC(void)
{
    s32 bits;
    f32 value;

    D_8012C7F4 = D_8012C7F4 * 0x19660D + 0x3C6EF35F;
    bits = (D_8011B9A4 & D_8012C7F4) | D_8011B9A0;
    value = *(f32 *) &bits - 1.0f;
    return value;
}

s32 func_800DC214(s32 lo, s32 hi)
{
    return (s32) ((func_800DC1AC() * (f32) (hi - lo)) + (f32) lo);
}

f32 func_800DC264(f32 lo, f32 hi)
{
    return func_800DC1AC() * (hi - lo) + lo;
}

// Returns 1 with probability `chance` (stream 0).
// Matching: the line breaks in this function are needed for the match.
int func_800DC298(f32 chance)
{
    f32 value;
    s32 result;
    do { value = func_800DC0C0(); result = 0; if (value < chance) { result |= 1; goto block_1; } result ^= 0; block_1: return result; } while (0);
}

// Returns 1 with probability `chance` (stream 1).
// Matching: the line breaks in this function are needed for the match.
int func_800DC2D4(f32 chance)
{
    f32 value;
    f32 sample;
    s32 result;
    sample = func_800DC1AC();
    do { 0; value = sample; if (value < chance) { result = 1; } else { result = 0; } return result; } while (0);
}

// Resets stream 0 to its default seed.
void func_800DC310()
{
    D_8012C7F0 = 0x00EAA0C7;
}

int func_800DC324(s32 seed)
{
    D_8012C7F0 = seed;
}

// Saves both seeds.
void func_800DC330()
{
    D_8012C7F8 = D_8012C7F0;
    D_8012C7FC = D_8012C7F4;
}

// Restores both seeds saved by func_800DC330.
void func_800DC354()
{
    D_8012C7F0 = D_8012C7F8;
    D_8012C7F4 = D_8012C7FC;
}

// TU-NOTE: the .data of this file (formerly asm/data/core2/1EB5980.data.s) is defined here
// in C; values are taken from the ROM.
s32 D_8011B9A0 = 0x3F800000;
s32 D_8011B9A4 = 0x7FFFFF;
