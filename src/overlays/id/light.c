// Flickering light map-mesh effect: vertex brightness takes a random +-0.04 step per frame,
// kept within 0.8..1.0.
#include "common.h"

extern void _glid_entrypoint_0(s32, s32, void *, f32 *);
extern f32 func_800DC264(f32, f32);
extern f32 _idlight_entrypoint_0;

// Scales vertex RGB by the brightness level.
void idlight_entrypoint_0(s32 unk_0, Vtx *src, Vtx *dst, s32 count, f32 *level_ptr)
{
    Vtx *end;
    f32 level;
    level = *level_ptr;
    end = src + count;
    for (; src < end; src++, dst++) {
        dst->v.cn[0] = src->v.cn[0] * level;
        dst->v.cn[1] = src->v.cn[1] * level;
        dst->v.cn[2] = src->v.cn[2] * level;
    }
}

void idlight_entrypoint_1(s32 arg0)
{
}

// Init: brightness starts at 1.0.
s32 idlight_entrypoint_2(f32 *level, s32 unk_1, s32 unk_2, s32 unk_3)
{
    *level = 1.0f;
}

// Matching: the temporaries and repeated stores are needed for the match.
// Update: random step of +-0.04, clamped to 0.8..1.0.
void idlight_entrypoint_3(f32 *level, s32 unk_1, s32 unk_2)
{
    f32 value;
    f32 clamped;
    *level += func_800DC264(-0.04f, 0.04f);
    value = *level;
    if (value > 1.0f) {
        *level = 1.0f;
    } else {
        *level = value;
    }
    value = *level;
    clamped = value;
    if (clamped < 0.8f) {
        *level = 0.8f;
    } else {
        *level = clamped;
    }
    _glid_entrypoint_0(unk_1, unk_2, &_idlight_entrypoint_0, level);
}

// TU-NOTE: this overlay's .data is defined here in C; values are taken from the ROM.
