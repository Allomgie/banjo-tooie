// Texture-scroll map-mesh effect: scrolls the mesh's V coordinate (speed from mesh id,
// wraps at 8192).
#include "common.h"

typedef struct {
    u8 pad_0[0xA];
    s16 tex_v;
    u8 pad_1[4];
} ScrollVertex;
typedef struct {
    u8 pad_0[4];
    s16 scroll;
} ScrollRenderState;
typedef struct {
    f32 offset;
    s16 wrapped;
    s16 pad_0;
    f32 speed;
} ScrollState;
extern f32 func_800D8FF8(void);
extern void _idscroll_entrypoint_0(void);

// Offsets the V texture coordinate by the scroll value.
void idscroll_entrypoint_0(void *unk_0, ScrollVertex *src, ScrollVertex *dst, s32 count,
                           ScrollRenderState *render_state)
{
    ScrollVertex *end;
    s16 scroll;
    s32 tex_v;
    scroll = render_state->scroll;
    end = src + count;
    for (; src < end; src++, dst++) {
        tex_v = src->tex_v + scroll;
        tex_v -= 0x2000;
        dst->tex_v = tex_v;
    }
}

void idscroll_entrypoint_1(s32 arg0)
{
}

// Init: offset 0, speed from the mesh parameter.
idscroll_entrypoint_2(f32 *state, s32 speed, s32 unk_2, s32 unk_3)
{
    f32 speed_f;
    speed_f = speed;
    state[0] = 0.0f;
    state[2] = speed_f;
}

// Update: advances the offset by speed and wraps at 8192.
void idscroll_entrypoint_3(ScrollState *state, void *unk_1, void *unk_2)
{
    state->offset += state->speed * 64.0f * func_800D8FF8();
    if ((s32) state->offset > 8192)
        state->offset -= 8192.0f;
    state->wrapped = (s32) state->offset;
    _glid_entrypoint_0(unk_1, unk_2, _idscroll_entrypoint_0, state);
}

// TU-NOTE: this overlay's .data is defined here in C; values are taken from the ROM.
