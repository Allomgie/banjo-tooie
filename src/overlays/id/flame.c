#include "common.h"

typedef struct FlameModifier {
    u8 pad_0[8];
    s16 scroll;
    u8 pad_A[0x12];
    f32 phase[8];
    f32 freq[8];
    f32 phase_speed[8];
    f32 amp[8];
} FlameModifier;
extern f32 func_8001395C(f32);
typedef struct {
    f32 scroll;
    f32 speed;
    s16 scroll_int;
    u8 count;
    u8 pad_B[17];
    f32 phase[16];
    f32 phase_speed[16];
} FlameScrollState;
extern f32 func_800D8FF8(void);
extern void _idflame_entrypoint_0(void);
typedef struct {
    f32 scroll;
    f32 speed;
    u8 pad_8[2];
    u8 count;
    u8 pad_B;
    s16 peaks[8];
    f32 phase[8];
    f32 freq[8];
    f32 phase_speed[8];
    f32 amp[8];
} IdFlame;
extern void _glidmake_entrypoint_2();
extern s16 _glidmake_entrypoint_3(s32, s32);
extern void *heap_alloc(s32);
extern void heap_free();
extern void _glid_entrypoint_2(s32, s32, void *, void *);
extern void _idflame_entrypoint_1();
extern f32 func_800DC264(f32, f32);

// Returns the band of a vertex: the number of table entries <= its x.
int func_80800000_idflame(u8 *modifier, s16 vtx_x)
{
    s32 band;
    s16 x;
    u8 *cursor;
    u8 *base;
    x = vtx_x;
    band = 0;
    if ((s32) modifier[0xA] > 0) {
        base = modifier;
        cursor = base;
        while (1) {
            if (x >= *(s16 *) (cursor + 12)) {
                band += 1;
                cursor += 2;
                if (band >= (s32) modifier[0xA]) {
                    break;
                }
            } else {
                break;
            }
        }
    }
    return band;
}

// Kernel: scrolls texture V and sways each vertex sideways by a sine of its height.
void idflame_entrypoint_0(void *param_0, Vtx *src, Vtx *dst, s32 count,
                          FlameModifier *modifier)
{
    Vtx *vin;
    Vtx *vout;
    Vtx *end;
    s32 scroll;
    s32 band;

    scroll = modifier->scroll;
    end = count + src;
    vin = src;
    vout = dst;
    while (vin < end) {
        vout->v.tc[1] = vin->v.tc[1] + scroll;
        band = func_80800000_idflame(modifier, vin->v.ob[0]);
        vout->v.ob[0] =
            vin->v.ob[0] + modifier->amp[band] *
                                   func_8001395C((modifier->phase[band] - vin->v.ob[1]) *
                                                 modifier->freq[band]);
        vin++;
        vout++;
    }
}

// TU-NOTE: .bss defined here, ahead of its first use: IDO places .bss objects used before their
// definition first. Scratch table [0] = start, [1] = end (index 2 is accessed through casts).
s16 *B_80800560_idflame[2];

// Vertex callback: inserts the vertex x into the sorted scratch table.
void idflame_entrypoint_1(s32 param_0, s16 *src, s32 param_2, s32 param_3)
{
    s16 *pos;
    s16 *dst;
    s16 value;
    value = *src;
    for (pos = B_80800560_idflame[0]; pos < B_80800560_idflame[1]; pos++) {
        if (value < *pos)
            break;
    }
    if (pos == B_80800560_idflame[1]) {
        *pos = value;
        B_80800560_idflame[1]++;
        return;
    }
    src = B_80800560_idflame[1] - 1;
    for (dst = B_80800560_idflame[1]; pos < dst; dst--, src--) {
        *dst = *src;
    }
    *pos = value;
    B_80800560_idflame[1]++;
}

void idflame_entrypoint_2(s32 arg0)
{
}

// Init: splits the mesh into up to 8 bands at large x gaps and randomizes each band's sway.
void idflame_entrypoint_3(IdFlame *flame, s32 param_1, s32 param_2, s32 param_3)
{
    s16 *buf;
    s32 vtx_count;
    f32 height;
    s16 *p;
    f32 gap_min;
    s16 bbox_min[3];
    s16 bbox_max[3];
    f32 speed_f;
    f32 delta;
    s32 i;
    f32 rate;

    vtx_count = _glidmake_entrypoint_3(param_2, param_3);
    speed_f = param_1;
    flame->scroll = 0;
    flame->speed = speed_f;
    _glidmake_entrypoint_2(param_2, param_3, bbox_min, bbox_max);
    buf = heap_alloc(vtx_count * 2);
    // Matching: empty block steers IDO's register allocation.
    if (param_1 && param_1) {
    }
    ((s16 **) B_80800560_idflame)[0] = buf;
    ((s16 **) B_80800560_idflame)[1] = buf;
    ((s16 **) B_80800560_idflame)[2] = buf + vtx_count;
    _glid_entrypoint_2(param_2, param_3, _idflame_entrypoint_1, flame);
    gap_min = (bbox_max[0] - bbox_min[0]) * 0.11f;
    flame->count = 0;
    for (p = ((s16 **) B_80800560_idflame)[0] + 1; p < ((s16 **) B_80800560_idflame)[1]; p++) {
        delta = p[0] - p[-1];
        if (delta <= gap_min) {
            continue;
        }
        if (flame->count < 8) {
            flame->peaks[flame->count] = p[0];
            flame->count++;
        }
    }
    heap_free((s16 **) B_80800560_idflame[0]);
    // Matching: empty block, needed for the match.
    if ((s16 **) B_80800560_idflame[0] && (s16 **) B_80800560_idflame[0]) {
    }
    ((s16 **) B_80800560_idflame)[2] = NULL;
    ((s16 **) B_80800560_idflame)[1] = ((s16 **) B_80800560_idflame)[2];
    ((s16 **) B_80800560_idflame)[0] = ((s16 **) B_80800560_idflame)[1];
    height = bbox_max[1] - bbox_min[1];
    delta = (bbox_max[0] - bbox_min[0]) * 0.0125f;
    rate = param_1 * height * 0.03125f;
    for (i = 0; i <= flame->count; i++) {
        flame->phase[i] = 0.0f;
        flame->freq[i] = 6.2831855f / func_800DC264(height * 0.5f, height);
        flame->phase_speed[i] = func_800DC264(rate * 0.5f, rate);
        flame->amp[i] = func_800DC264(delta * 2.0f, delta * 5.0f);
    }
}

// Advances the scroll (wrapped at 8192) and the band phases, then runs the kernel.
void idflame_entrypoint_4(FlameScrollState *state, s32 param_1, s32 param_2)
{
    f32 dt;
    s32 scroll;
    s32 i;

    dt = func_800D8FF8();
    state->scroll += state->speed * 64.0f * dt;
    scroll = (s32) state->scroll;
    if (scroll > 8192) {
        state->scroll -= 8192.0f;
        scroll = (s32) state->scroll;
    }
    state->scroll_int = scroll;
    for (i = 0; i <= state->count; i++) {
        state->phase[i] += state->phase_speed[i] * dt;
    }
    _glid_entrypoint_0(param_1, param_2, _idflame_entrypoint_0, state);
}
