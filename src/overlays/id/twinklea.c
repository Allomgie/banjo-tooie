#include "common.h"

extern u8 _idtwinklea_entrypoint_3[];

// Init: clears the point range.
s32 idtwinklea_entrypoint_0(s32 *ret, s32 unk_1, s32 unk_2, s32 unk_3)
{
    *ret = 0;
    *(ret + 1) = 0;
}

void idtwinklea_entrypoint_1(s32 arg0)
{
}

// Update: reads the sparkle points of the twinkle entry 200 ids lower.
void idtwinklea_entrypoint_2(s32 range, s32 unk_1, s32 mesh_id)
{
    s32 twinkle;

    twinkle = _idworld_entrypoint_2(mesh_id - 0xC8);
    if (twinkle != 0) {
        _idtwinkle_entrypoint_6(twinkle, range, range + 4);
        _glid_entrypoint_0(unk_1, mesh_id, &_idtwinklea_entrypoint_3, range);
    }
}

// Kernel: vertices that match a sparkle point get alpha 255, the others 0.
void idtwinklea_entrypoint_3(s32 unk_0, u8 *src, u8 *dst, s32 count, u8 *range)
{
    u8 *point;
    u8 *points_end;
    u8 *end = src + count * 0x10;
    f32 alpha;

    for (; src < end; src += 0x10, dst += 0x10) {
        point = *(u8 **) range;
        points_end = *(u8 **) (range + 4);
        for (; point < points_end; point += 0x10) {
            if (*(s16 *) src == *(s16 *) (point + 8) &&
                *(s16 *) (src + 2) == *(s16 *) (point + 10) &&
                *(s16 *) (src + 4) == *(s16 *) (point + 12)) {
                break;
            }
        }
        alpha = point == points_end ? 0.0f : 1.0f;
        if (alpha > 1.0f)
            alpha = 1.0f;
        dst[15] = (u32) (alpha * 255.0f);
    }
}

// TU-NOTE: this overlay's .data is defined here in C; values are taken from the ROM.
