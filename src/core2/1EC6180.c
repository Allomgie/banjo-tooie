// Most likely an animator for map-model vertex groups: translate, offset, scale, alpha and colour
// effects with a timer, an optional looping sfx and callbacks, run per vertex via the glid overlay.

#include "common.h"

extern void _glidmake_entrypoint_2();
extern s16 D_80123580[];
typedef struct {
    u8 pad_0[12];
    u8 rgba[4];
} VertexColor;
typedef struct {
    u8 pad_0[0x50];
    f32 fade_from[4], fade_to[4];
    f32 fade_time, fade_duration;
    f32 color_from[4], color_to[4];
    f32 color_time, color_duration;
} ColorState;
typedef struct {
    s16 pos[3];
    u8 pad_6[10];
} VertexECEEC;
typedef struct {
    u8 pad_0[0x2C];
    f32 start[3];
    f32 end[3];
    f32 time;
    f32 duration;
} StateECEEC;
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
typedef struct {
    s16 pos[3];
    s16 pad_6[5];
} VertexED;
typedef struct {
    u8 pad_0[0x78];
    f32 color_from[4], color_to[4], color_time, color_duration;
} ColorED144;
typedef struct {
    s32 pad_0;
    f32 scale_from;
    f32 scale_to;
    u8 pad_C[8];
    s16 bbox[6];
    u8 pad_20[0x24];
    f32 time;
    f32 duration;
} StateED7F8;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF9A8(f32 *, f32 *, f32);
typedef struct LocalEffect LocalEffect;
struct LocalEffect {
    u8 sound;
    u8 pad_1[0xF];
    void (*callback)(LocalEffect *);
    u8 pad_14[0xC];
    f32 pitch_min, pitch_max;
    u8 pending, mode;
    u8 pad_2A[0x1A];
    f32 time, duration;
    s16 current, target;
    u8 pad_50[0x20];
    f32 fade_time, fade_duration;
    u8 pad_78[0x20];
    f32 color_time, color_duration;
};

extern f32 func_800D8FF8(void);
extern f32 func_800C395C(u8);
extern s32 func_800C3920(u8);
extern f32 func_800DC264(f32, f32);
extern s32 func_800DC214(s32, s32);
extern void func_800C31DC(u8, f32);
extern void func_800C3058(u8, s32);
extern void func_800C2FDC(u8);
extern void _glid_entrypoint_0(s32, s32, void (*)(), LocalEffect *);
void func_800EE010();
// Starts the looping positional sound.
void func_800EE040(u8 *effect, long sound_id, f32 pitch_min, f32 pitch_max);

// Controller: init from the mesh bbox, start-move/colour/alpha/scale commands, sfx, callbacks, update.
void func_800EC890(s32 arg0)
{
}

void func_800EC898(u8 *state, s32 param_1, s32 model, s32 mesh_id)
{
    s16 *entry;
    s16 period;
    s32 flags;
    s32 world_section;
    world_section = func_800EA05C();
    entry = D_80123580;
    while (entry[0] != 0) {
        if ((world_section == entry[0]) && (mesh_id == entry[1])) {
            break;
        }
        entry += 4;
    }

    *(f32 *) ((s8 *) state + 0x14) = (f32) (2048.0f / (f32) entry[2]);
    *(f32 *) ((s8 *) state + 0xC) = (f32) (entry[3] << 6);
    _glidmake_entrypoint_2((void *) model, mesh_id, (s16 *) state, (s16 *) (state + 6));
    flags = param_1 / 10;
    if (flags & 1) {
        *(s8 *) ((s8 *) state + 0x1A) = 0;
    } else {
        *(s8 *) ((s8 *) state + 0x1A) = 1;
    }
    if (flags & 2) {
        *(s8 *) ((s8 *) state + 0x1B) = 0;
    } else {
        *(s8 *) ((s8 *) state + 0x1B) = 1;
    }
    if (flags & 4) {
        *(s8 *) ((s8 *) state + 0x1C) = 0;
    } else {
        *(s8 *) ((s8 *) state + 0x1C) = 1;
    }
    period = *(s16 *) ((s8 *) state + 0x18);
    if (period == 0) {
        *(s8 *) ((s8 *) state + 0x1C) = 0;
        return;
    }
    *(f32 *) ((s8 *) state + 0x10) = (f32) (50.0f / (f32) period);
}

void func_800EC9E0(s32 arg0, s32 arg1, s32 arg2)
{
}

// Per-vertex kernels: translate, offset, colour, alpha and scale.
// Vertex colour fade kernel.
void func_800EC9F0(void *param_0, VertexColor *src, VertexColor *dst, s32 count,
                   ColorState *state)
{
    f32 t;
    f32 step[4];
    VertexColor *src_end;
    t = state->fade_time / state->fade_duration;
    step[0] = (state->fade_to[0] - state->fade_from[0]) * t;
    step[1] = (state->fade_to[1] - state->fade_from[1]) * t;
    step[2] = (state->fade_to[2] - state->fade_from[2]) * t;
    step[3] = (state->fade_to[3] - state->fade_from[3]) * t;
    src_end = src + count;
    for (; src < src_end; src++, dst++) {
        dst->rgba[0] = (state->fade_from[0] + step[0]) * (u32) src->rgba[0];
        dst->rgba[1] = (state->fade_from[1] + step[1]) * (u32) src->rgba[1];
        dst->rgba[2] = (state->fade_from[2] + step[2]) * (u32) src->rgba[2];
        dst->rgba[3] = (state->fade_from[3] + step[3]) * (u32) src->rgba[3];
    }
}

// Mode 1 kernel: translate with ease^4.
void func_800ECD60(s32 param_0, VertexECEEC *src, VertexECEEC *dst, s32 count,
                   StateECEEC *state)
{
    f32 t;
    f32 offset[3];
    VertexECEEC *src_end;
    t = state->time / state->duration;
    t = t * t * t * t;
    func_800EFE50(offset, state->start, state->end, t);
    for (src_end = src + count; src < src_end; src++, dst++) {
        dst->pos[0] = src->pos[0] + offset[0];
        dst->pos[1] = src->pos[1] + offset[1];
        dst->pos[2] = src->pos[2] + offset[2];
    }
}

// Mode 2 kernel: linear translate.
void func_800ECEEC(s32 param_0, VertexECEEC *src, VertexECEEC *dst, s32 count,
                   StateECEEC *state)
{
    f32 t;
    f32 offset[3];
    VertexECEEC *src_end;
    t = state->time / state->duration;
    func_800EFE50(offset, state->start, state->end, t);
    for (src_end = src + count; src < src_end; src++, dst++) {
        dst->pos[0] = src->pos[0] + offset[0];
        dst->pos[1] = src->pos[1] + offset[1];
        dst->pos[2] = src->pos[2] + offset[2];
    }
}

// Mode 3 kernel: Y offset.
void func_800ED064(s32 param_0, VertexED *src, VertexED *dst, s32 count, f32 *state)
{
    s16 offset;
    VertexED *src_end;
    offset = (state[17] / state[18]) * (state[2] - state[1]) + state[1];
    src_end = src + count;
    for (; src < src_end; src++, dst++) {
        dst->pos[1] = src->pos[1] + offset;
    }
}

// Mode 7 kernel: Z offset.
void func_800ED0D4(s32 param_0, VertexED *src, VertexED *dst, s32 count, f32 *state)
{
    s16 offset;
    VertexED *src_end;
    offset = (state[17] / state[18]) * (state[2] - state[1]) + state[1];
    src_end = src + count;
    for (; src < src_end; src++, dst++) {
        dst->pos[2] = src->pos[2] + offset;
    }
}

// Colour lerp kernel (default case).
void func_800ED144(s32 param_0, Vtx *src, Vtx *dst, s32 count, ColorED144 *state)
{
    f32 t;
    f32 step[4];
    Vtx *src_end;
    t = state->color_time / state->color_duration;
    step[0] = (state->color_to[0] - state->color_from[0]) * t;
    step[1] = (state->color_to[1] - state->color_from[1]) * t;
    step[2] = (state->color_to[2] - state->color_from[2]) * t;
    step[3] = (state->color_to[3] - state->color_from[3]) * t;
    src_end = count + src;
    for (; src < src_end; src++, dst++) {
        dst->v.cn[0] = state->color_from[0] + step[0];
        dst->v.cn[1] = state->color_from[1] + step[1];
        dst->v.cn[2] = state->color_from[2] + step[2];
        dst->v.cn[3] = state->color_from[3] + step[3];
    }
}

// Mode 6 kernel: colour scale.
void func_800ED424(void *param_0, VertexColor *src, VertexColor *dst, s32 count,
                   ColorState *state)
{
    f32 t;
    f32 scale[4];
    VertexColor *src_end;
    t = state->color_time / state->color_duration;
    scale[0] =
        (state->color_from[0] + (state->color_to[0] - state->color_from[0]) * t) / 255.0f;
    scale[1] =
        (state->color_from[1] + (state->color_to[1] - state->color_from[1]) * t) / 255.0f;
    scale[2] =
        (state->color_from[2] + (state->color_to[2] - state->color_from[2]) * t) / 255.0f;
    scale[3] =
        (state->color_from[3] + (state->color_to[3] - state->color_from[3]) * t) / 255.0f;
    src_end = src + count;
    for (; src < src_end; src++, dst++) {
        dst->rgba[0] = (u32) src->rgba[0] * scale[0];
        dst->rgba[1] = (u32) src->rgba[1] * scale[1];
        dst->rgba[2] = (u32) src->rgba[2] * scale[2];
        dst->rgba[3] = (u32) src->rgba[3] * scale[3];
    }
}

// Mode 5 kernel: alpha.
void func_800ED79C(s32 param_0, u8 *src, u8 *dst, s32 count, f32 *state)
{
    int alpha;
    u8 *src_end;
    f32 t;
    t = state[38] / state[39];
    alpha = state[33] + (state[37] - state[33]) * t;
    src_end = src + count * 16;
    while (src < src_end) {
        src += 16;
        dst += 16;
        dst[-1] = alpha;
    }
}

// Mode 4 kernel: 2D scale about the bbox centre.
void func_800ED7F8(s32 param_0, VertexECEEC *src, VertexECEEC *dst, s32 count,
                   StateED7F8 *state)
{
    f32 center[3];
    f32 rel[3];
    f32 scale;
    VertexECEEC *src_end;
    scale = state->scale_from +
              (state->time / state->duration) * (state->scale_to - state->scale_from);
    center[0] = (state->bbox[0] + state->bbox[3]) * 0.5f;
    center[1] = (state->bbox[1] + state->bbox[4]) * 0.5f;
    center[2] = 0.0f;
    for (src_end = src + count; src < src_end; src++, dst++) {
        func_800EFA4C(rel, src->pos[0] - center[0], src->pos[1] - center[1],
                      0.0f);
        func_800EF9A8(rel, rel, scale);
        dst->pos[0] = (s32) (center[0] + rel[0]);
        dst->pos[1] = (s32) (center[1] + rel[1]);
    }
}

// Starts the effect: avoids a zero duration, runs the callback.
void func_800ED964(f32 effect[3])
{
    if (effect[18] == 0.0f) {
        effect[18] = 1e-05f;
    }
    {
        s32 func_ptr = *(s32 *) &effect[3];
        if (func_ptr != 0) {
            ((void (*)(void)) func_ptr)();
        }
    }
}

// Sets up a mode 1 effect.
void func_800ED9B4(u8 *effect, u8 *start, u8 *end, f32 duration, s32 target)
{
    s8 mode;
    s32 target_tmp;
    // Matching: the temporaries are needed for the match.
    mode = 1;
    *(f32 *) (effect + 0x2C) = *(f32 *) (start + 0);
    *(f32 *) (effect + 0x30) = *(f32 *) (start + 4);
    *(f32 *) (effect + 0x34) = *(f32 *) (start + 8);
    *(f32 *) (effect + 0x38) = *(f32 *) (end + 0);
    *(f32 *) (effect + 0x3C) = *(f32 *) (end + 4);
    *(f32 *) (effect + 0x40) = *(f32 *) (end + 8);
    *(s8 *) (effect + 0x29) = mode;
    *(s16 *) (effect + 0x4C) = 0;
    *(f32 *) (effect + 0x48) = duration;
    *(f32 *) (effect + 0x44) = 0.0f;
    target_tmp = target;
    *(s16 *) (effect + 0x4E) = (s16) target_tmp;
    func_800ED964((f32 *) effect);
}

s16 func_800EDA24(s32 param_0)
{
    return ((s16 *) param_0)[0x26];
}

int func_800EDA2C(s16 *bbox, f32 *pos)
{
    return bbox[10] <= pos[0] && pos[0] < bbox[13] && bbox[12] <= pos[2] &&
           pos[2] < bbox[15];
}

int func_800EDAF4(u8 *effect)
{
    int mask;
    int sound;
    // Matching: the redundant masks are needed for the match.
    mask = 0xFFFFFFFFFFFFFFFF;
    if (*effect != 0) {
        sound = (((*effect & mask) & mask) & mask) & 0xFFFFFFFFFFFFFFFF;
        func_800C2FDC(((((sound & mask) & 0xFF) & 0xFF) & 0xFF) & 0xFF);
    }
}

// Clears the effect state.
void func_800EDB20(u8 *effect, s32 param_1, s32 model, s32 mesh_id)
{
    int offset;
    *(s8 *) ((s8 *) effect + 0) = 0;
    // Matching: the XOR with 0 is needed for the match.
    *(s32 *) ((s8 *) effect + 0xC) = 0 ^ 0;
    *(s32 *) ((s8 *) effect + 0x10) = 0;
    *(s8 *) ((s8 *) effect + 0x29) = 0;
    *(s8 *) ((s8 *) effect + 0x28) = 0;
    *(s16 *) ((s8 *) effect + 0x4C) = 0;
    *(s16 *) ((s8 *) effect + 0x4E) = 0;
    *(f32 *) ((s8 *) effect + 0x70) = 0.0f;
    *(f32 *) ((s8 *) effect + 0x74) = 0.0f;
    *(f32 *) ((s8 *) effect + 0x9C) = 0.0f;
    *(f32 *) ((s8 *) effect + 0x98) = 0.0f;
    // Matching: the int cast and the offset temporary are needed for the match.
    *(f32 *) ((s8 *) effect + 0x44) = (int) 0.0f;
    offset = 0x48;
    *(f32 *) ((s8 *) effect + offset) = 0;
    _glidmake_entrypoint_2(model, mesh_id, effect + 0x14, effect + 0x1A);
}

// Sets up a mode 2 effect.
void func_800EDBA0(s32 effect, f32 *start, f32 *end, f32 duration, s32 target)
{
    *(f32 *) ((char *) effect + 0x2C) = start[0];
    *(f32 *) ((char *) effect + 0x30) = start[1];
    *(f32 *) ((char *) effect + 0x34) = start[2];
    *(f32 *) ((char *) effect + 0x38) = end[0];
    *(f32 *) ((char *) effect + 0x3C) = end[1];
    *(f32 *) ((char *) effect + 0x40) = end[2];
    *(s8 *) ((char *) effect + 0x29) = 2;
    *(s16 *) ((char *) effect + 0x4C) = 0;
    *(f32 *) ((char *) effect + 0x44) = 0.0f;
    *(f32 *) ((char *) effect + 0x48) = duration;
    *(s16 *) ((char *) effect + 0x4E) = (s16) target;
    func_800ED964((f32 *) effect);
}

// Sets up a mode 3 effect.
int func_800EDC10(s32 effect, f32 from_value, f32 to_value, f32 new_duration, s32 new_target)
{
    u8 *mode = (u8 *) (effect + 0x29);
    f32 *from = (f32 *) (effect + 0x4);
    f32 *to = (f32 *) (effect + 0x8);
    f32 *elapsed = (f32 *) (effect + 0x44);
    f32 *duration = (f32 *) (effect + 0x48);
    s16 *current = (s16 *) (effect + 0x4C);
    s16 *target = (s16 *) (effect + 0x4E);
    *mode = 3;
    *from = from_value;
    *elapsed = 0.0f;
    *duration = new_duration;
    *to = to_value;
    *current = 0;
    *target = new_target;
    func_800ED964(effect);
}

// Sets up a mode 7 effect.
int func_800EDC64(s32 effect, f32 from_value, f32 to_value, f32 new_duration, s32 new_target)
{
    u8 *mode = (u8 *) (effect + 0x29);
    f32 *from = (f32 *) (effect + 0x4);
    f32 *to = (f32 *) (effect + 0x8);
    f32 *elapsed = (f32 *) (effect + 0x44);
    f32 *duration = (f32 *) (effect + 0x48);
    s16 *current = (s16 *) (effect + 0x4C);
    s16 *target = (s16 *) (effect + 0x4E);
    *mode = 7;
    *from = from_value;
    *elapsed = 0.0f;
    *duration = new_duration;
    *to = to_value;
    *current = 0;
    *target = new_target;
    func_800ED964(effect);
}

void func_800EDCB8(s32 effect, f32 amount)
{
    func_800EDC10(effect, amount, amount, 0, 1);
}

int func_800EDCEC(s32 effect, f32 amount)
{
    return func_800EDC64(effect, amount, amount, 0, 1);
}

s32 func_800EDD20(s32 effect, f32 from_value, f32 to_value, f32 new_duration, s32 new_target)
{
    func_800EE010(effect);
    func_800EDC10(effect, from_value, to_value, new_duration, new_target);
}

func_800EDD68(Actor *effect, f32 fade_from[4], f32 fade_to[4], f32 duration)
{
    *(f32 *) ((char *) effect + 0x50) = fade_from[0];
    *(f32 *) ((char *) effect + 0x54) = fade_from[1];
    *(f32 *) ((char *) effect + 0x58) = fade_from[2];
    *(f32 *) ((char *) effect + 0x5C) = fade_from[3];
    *(f32 *) ((char *) effect + 0x60) = fade_to[0];
    *(f32 *) ((char *) effect + 0x64) = fade_to[1];
    *(f32 *) ((char *) effect + 0x68) = fade_to[2];
    *(f32 *) ((char *) effect + 0x6C) = fade_to[3];
    *(u8 *) ((char *) effect + 0x28) = 0;
    *(f32 *) ((char *) effect + 0x70) = 0.0f;
    if (duration > 0.0f) {
        *(f32 *) ((char *) effect + 0x74) = duration;
    } else {
        *(f32 *) ((char *) effect + 0x74) = 0.001f;
    }
}

// Sets up a mode 6 effect.
void func_800EDDDC(f32 effect[4], f32 fade_from[4], f32 fade_to[4], f32 duration)
{
    effect[20] = fade_from[0];
    effect[21] = fade_from[1];
    effect[22] = fade_from[2];
    effect[23] = fade_from[3];
    effect[24] = fade_to[0];
    effect[25] = fade_to[1];
    effect[26] = fade_to[2];
    effect[27] = fade_to[3];
    *(u8 *) ((char *) effect + 0x28) = 0;
    effect[28] = 0.0f;
    if (duration > 0.0f) {
        effect[29] = duration;
    } else {
        effect[29] = 0.001f;
    }
    *(u8 *) ((char *) effect + 0x29) = 6;
}

void func_800EDE54(f32 effect[10], s32 color_from[4], s32 color_to[4], f32 duration)
{
    effect[30] = color_from[0];
    effect[31] = color_from[1];
    effect[32] = color_from[2];
    effect[33] = color_from[3];
    effect[34] = color_to[0];
    effect[35] = color_to[1];
    effect[36] = color_to[2];
    effect[37] = color_to[3];
    *(u8 *) ((u8 *) effect + 0x28) = 0;
    if (duration > 0.0f) {
        effect[39] = duration;
    } else {
        effect[39] = 0.001f;
    }
    effect[38] = 0;
}

// Sets up a mode 5 effect.
void func_800EDF2C(u8 *effect, s32 alpha_from, s32 alpha_to, f32 duration)
{
    f32 zero;
    zero = 0.0f;
    effect[0x29] = 5;
    effect[0x28] = 0;
    *(f32 *) &effect[0x84] = (f32) alpha_from;
    *(f32 *) &effect[0x80] = zero;
    *(f32 *) &effect[0x7C] = zero;
    *(f32 *) &effect[0x78] = zero;
    *(f32 *) &effect[0x94] = (f32) alpha_to;
    *(f32 *) &effect[0x90] = zero;
    *(f32 *) &effect[0x8C] = zero;
    *(f32 *) &effect[0x88] = zero;
    if (duration > 0) {
        *(f32 *) &effect[0x9C] = duration;
    } else {
        *(f32 *) &effect[0x9C] = 0.001f;
    }
    *(f32 *) &effect[0x98] = zero;
}

void func_800EDF98(s32 effect, s32 alpha)
{
    func_800EDF2C(effect, alpha, alpha, 0);
}

// Sets up a mode 4 effect.
int func_800EDFBC(s32 effect, f32 from_value, f32 to_value, f32 new_duration, s32 new_target)
{
    u8 *mode = (u8 *) (effect + 0x29);
    f32 *from = (f32 *) (effect + 0x4);
    f32 *to = (f32 *) (effect + 0x8);
    f32 *elapsed = (f32 *) (effect + 0x44);
    f32 *duration = (f32 *) (effect + 0x48);
    s16 *current = (s16 *) (effect + 0x4C);
    s16 *target = (s16 *) (effect + 0x4E);
    *mode = 4;
    *from = from_value;
    *elapsed = 0.0f;
    *duration = new_duration;
    *to = to_value;
    *current = 0;
    *target = new_target;
    func_800ED964(effect);
}

void func_800EE010(s32 effect)
{
    func_800EE040((u8 *) effect, 1004, 0.7f, 0.9f);
}

void func_800EE040(u8 *effect, long sound_id, f32 pitch_min, f32 pitch_max)
{
    u8 source;
    source = *effect;
    if (source == 0) {
        *effect = func_800C2E04(effect);
        source = *effect;
    }
    *(f32 *) (effect + 0x20) = pitch_min;
    *(f32 *) (effect + 0x24) = pitch_max;
    func_800C301C(source & 0xFF, sound_id, source);
    func_800C330C(*effect, 3);
    func_800C31DC(*effect, (pitch_min + pitch_max) * 0.5f);
    func_800C3058(*effect, 0x7D00);
    func_800C3BDC(*effect);
}

func_800EE0F0(s32 *effect, s32 callback)
{
    s32 callback_copy;
    // Matching: the copy is needed for the match.
    callback_copy = callback;
    effect[3] = callback_copy;
}

func_800EE0F8(s32 *effect, s32 callback)
{
    effect[4] = callback;
}

void func_800EE100(void *effect, int value)
{
    s16 *base;
    s16 *out;
    s16 *next;
    // Matching: the extra pointers and comma expression are needed for the match.
    base = (s16 *) ((char *) effect + 0x4A);
    next = base;
    next++;
    out = (0, base = next);
    *out = value;
}

// Per-frame update: runs the vertex kernels over the mesh.
void func_800EE108(LocalEffect *effect, s32 model, s32 mesh_id)
{
    f32 dt;
    f32 progress;
    f32 pitch;
    s32 volume;

    dt = func_800D8FF8();
    if (effect->fade_duration > 0.0f) {
        effect->fade_time += dt;
        if (effect->fade_duration <= effect->fade_time) {
            effect->fade_time = effect->fade_duration;
            if (!effect->pending) {
                effect->pending = 2;
            }
        }
        _glid_entrypoint_0(model, mesh_id, func_800EC9F0, effect);
        if (effect->pending) {
            effect->pending--;
            if (effect->pending == 0) {
                effect->fade_duration = 0.0f;
            }
        }
    }
    if (effect->color_duration > 0.0f) {
        effect->color_time += dt;
        if (effect->color_duration <= effect->color_time) {
            effect->color_time = effect->color_duration;
            if (!effect->pending) {
                effect->pending = 2;
            }
        }
        switch (effect->mode) {
            case 5:
                _glid_entrypoint_0(model, mesh_id, func_800ED79C, effect);
                break;
            case 6:
                _glid_entrypoint_0(model, mesh_id, func_800ED424, effect);
                break;
            default:
                _glid_entrypoint_0(model, mesh_id, func_800ED144, effect);
        }
        if (effect->pending) {
            effect->pending--;
            if (effect->pending == 0) {
                effect->color_duration = 0.0f;
            }
        }
    }
    if (effect->mode == 0 || effect->mode == 5)
        return;
    {
        effect->time += dt;
        if (effect->duration < effect->time) {
            effect->time = effect->duration;
        }
        if (effect->sound) {
            progress = effect->time / effect->duration;
            pitch = func_800C395C(effect->sound);
            volume = func_800C3920(effect->sound);
            pitch += func_800DC264(-1.0f, 1.0f) * dt;
            pitch = effect->pitch_min > pitch ? effect->pitch_min : pitch;
            pitch = effect->pitch_max < pitch ? effect->pitch_max : pitch;
            volume += func_800DC214(-15, 15);
            volume = 0x7FFF < volume ? 0x7FFF : volume;
            volume = 0x7918 > volume ? 0x7918 : volume;
            if (progress >= 0.85f) {
                volume = (1.0f - (progress - 0.85f) / 0.14999998f) * volume;
            }
            func_800C31DC(effect->sound, pitch);
            func_800C3058(effect->sound, volume);
        }
        switch (effect->mode) {
            case 1:
                _glid_entrypoint_0(model, mesh_id, func_800ECD60, effect);
                break;
            case 2:
                _glid_entrypoint_0(model, mesh_id, func_800ECEEC, effect);
                break;
            case 3:
                _glid_entrypoint_0(model, mesh_id, func_800ED064, effect);
                break;
            case 4:
                _glid_entrypoint_0(model, mesh_id, func_800ED7F8, effect);
                break;
            case 7:
                _glid_entrypoint_0(model, mesh_id, func_800ED0D4, effect);
        }
        if (effect->duration <= effect->time) {
            effect->mode = 0;
            effect->current = effect->target;
            if (effect->callback) {
                effect->callback(effect);
            }
            if (effect->sound) {
                func_800C2FDC(effect->sound);
                effect->sound = 0;
            }
        }
    }
}

// {world section, mesh id, divisor for 2048.0, value << 6}, zero-terminated.
s16 D_80123580[8] = {0xB0, 0x514, 0x190, 0x10, 0x0, 0x0, 0x320, 0x8};
