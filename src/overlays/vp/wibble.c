#include "common.h"

typedef struct {
    u8 pad_0[0xE];
    s16 id;
} WibbleRecord;
extern WibbleRecord D_80800700_vpwibble[];
typedef struct {
    u8 pad_0[0x24];
    f32 phase;
    u8 pad_28[4];
    f32 speed;
    u8 pad_30[4];
    s32 count;
} WibbleState;
typedef struct {
    u8 pad_0[3];
    u8 dirty;
    u8 pad_4[16];
} WibbleVertex;
typedef struct {
    u8 pad_0[0x1C];
    s32 offset;
} WibbleModel;
extern f32 func_800D8FF8(void);
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800137D4(f32);
extern f32 func_80013788(f32);

// Finds the preset for an id (rounded down to the hundred); falls back to the first one.
WibbleRecord *func_80800000_vpwibble(s32 id)
{
    s32 i;

    id -= id % 100;
    for (i = 0; i < 6; i++) {
        if (id == D_80800700_vpwibble[i].id) {
            return &D_80800700_vpwibble[i];
        }
    }
    return D_80800700_vpwibble;
}

// Derives the wave parameters in the state from the preset and the min/max bounds.
void func_808000B0_vpwibble(state, id) u8 *state;
s32 id;
{
    u8 *preset;
    f32 value;
    f32 max_y;
    f32 min_y;
    preset = (u8 *) func_80800000_vpwibble(id);
    id %= 100;
    *(f32 *) (state + 0x1C) = preset[13] << 6;
    if (preset[13])
        state[0x33] = 1;
    else
        state[0x33] = 0;
    max_y = *(f32 *) (state + 0x10);
    min_y = *(f32 *) (state + 4);
    *(s16 *) (state + 0x18) = (s32) ((max_y + min_y) / 2);
    value = *(f32 *) (preset + 4);
    if (value < 0.0f) {
        *(s16 *) (state + 0x1A) = (s32) -value;
        state[0x31] = 2;
    } else if (value > 0.0f) {
        state[0x31] = 0;
        *(s16 *) (state + 0x1A) = (s32) value;
    } else {
        state[0x31] = 1;
        *(s16 *) (state + 0x1A) = (s32) ((max_y - min_y) * 0.5f);
    }
    *(f32 *) (state + 0x20) = (f32) (u32) preset[12] / *(s16 *) (state + 0x1A);
    state[0x30] = 255 - preset[12];
    if (preset[12])
        state[0x32] = 1;
    else
        state[0x32] = 0;
    *(f32 *) (state + 0x24) = 0.0f;
    *(f32 *) (state + 0x28) = 6.2831855f / *(f32 *) preset;
    value = *(f32 *) (preset + 8);
    if (value < 0.0f)
        *(f32 *) (state + 0x2C) = -value;
    else
        *(f32 *) (state + 0x2C) = id * value;
}

// Matching: the line breaks in this function are needed for the match.
// Allocates the wibble state: bounds copied from the definition, enabled group indices listed.
u8 *vpwibble_entrypoint_0(u8 *model, u8 *def)
{
    u32 first;
    u32 end;
    u8 *item;
    u8 *state;
    state = heap_alloc((*(s32 *) ((char *) model + 0x14) * 2) + 0x38);
    first = (u32) def + 0x14;
    do { item = (u8 *) first; end = ((*(s32 *) ((char *) model + 0x14) * 4) + (u32) def) + 0x14; *(s32 *) ((char *) state + 0x34) = 0; if ((0 && 0) && 0) {} if (first < end) { do { if (*(u16 *) ((char *) item + 2) != 0) { *(s16 *) ((char *) (state + (*(s32 *) ((char *) state + 0x34) * 2)) + 0x38) = (s16) ((s32) (item - (u8 *) first) >> 2); *(s32 *) ((char *) state + 0x34) = (s32) (*(s32 *) ((char *) state + 0x34) + 1); } item = item + 4; } while (item < (u8 *) end); } func_800EE88C(state, def + 8); } while (0);
    func_800EE88C(state + 0xC, def + 14);
    func_808000B0_vpwibble(state, *(s32 *) def);
    return state;
}

void vpwibble_entrypoint_1(void *state)
{
    heap_free(state);
}

// Advances the phase and marks the affected vertex groups dirty.
void vpwibble_entrypoint_2(WibbleState *state, WibbleModel *model)
{
    WibbleVertex *dirty;
    s32 i;
    s16 *indices;
    state->phase += func_800D8FF8() * state->speed;
    dirty = (WibbleVertex *) ((u8 *) model + model->offset);
    indices = (s16 *) (state + 1);
    for (i = 0; i < state->count;) {
        dirty[indices[i++]].dirty = 1;
    }
}

// Evaluates the ripple at a vertex: returns the wave height, writes the S/T wobble to uv_out.
f32 func_808003F0_vpwibble(state, vtx, uv_out)
u8 *state;
s16 *vtx;
f32 *uv_out;
{
    f32 dist;
    f32 wave;
    f32 uv_mag;
    f32 pos[3];
    f32 scale;

    pos[0] = vtx[0];
    pos[1] = vtx[1];
    pos[2] = vtx[2];
    dist = func_800EEF94(pos);
    wave = *(s16 *) (state + 0x1A) *
           func_800137D4(
               func_800136D0((dist - *(f32 *) (state + 0x24)) * *(f32 *) (state + 0x28)));
    if (state[0x33]) {
        uv_mag = *(f32 *) (state + 0x28) * (*(s16 *) (state + 0x1A) * func_80013788(wave));
        if (dist > 0.0001f) {
            scale = uv_mag / dist;
            uv_out[0] = pos[0] * scale;
            uv_out[1] = pos[2] * scale;
        } else {
            uv_out[0] = pos[0] * uv_mag;
            uv_out[1] = pos[2] * uv_mag;
        }
    }
    return wave;
}

// Applies the ripple to each vertex: Y displacement, colour modulation and S/T wobble.
void vpwibble_entrypoint_3(u8 *state, s32 unk_0, u8 *vtx, s32 count)
{
    f32 wave;
    s32 shade;
    f32 uv[2];
    u8 *end;
    end = vtx + count * 16;
    for (; vtx < end; vtx += 16) {
        wave = func_808003F0_vpwibble(state, vtx, uv);
        if (state[0x31] == 1)
            *(s16 *) (vtx + 2) = (s32) (*(s16 *) (state + 0x18) + wave);
        else if (state[0x31] == 2)
            *(s16 *) (vtx + 2) = (s32) (*(s16 *) (vtx + 2) + wave);
        if (state[0x32]) {
            shade = (s32) (wave * *(f32 *) (state + 0x20) + (f32) (u32) state[0x30]);
            vtx[12] = (vtx[12] * shade) >> 8;
            vtx[13] = (vtx[13] * shade) >> 8;
            vtx[14] = (vtx[14] * shade) >> 8;
        }
        if (state[0x33]) {
            *(s16 *) (vtx + 8) =
                (s32) (*(s16 *) (vtx + 8) + *(f32 *) (state + 0x1C) * uv[0]);
            *(s16 *) (vtx + 10) =
                (s32) (*(s16 *) (vtx + 10) + *(f32 *) (state + 0x1C) * uv[1]);
        }
    }
}

// TU-NOTE: the data is defined in C with values from the ROM. D_8080070E_vpwibble and
// D_8080071E_vpwibble are linker symbols (undefined_syms.us.txt) at D_80800700_vpwibble + 0xE
// and D_80800710_vpwibble + 0xE.
WibbleRecord D_80800700_vpwibble[1] = {0x43, 0xC8, 0x0, 0x0, 0x41, 0xA0, 0x0,  0x0,
                                       0x41, 0xA0, 0x0, 0x0, 0xA,  0x1,  0x4B0};
u32 D_80800710_vpwibble[20] = {0x43C80000, 0x41A00000, 0x40800000, 0x32080514, 0x43C80000,
                               0x41A00000, 0x40800000, 0x32000578, 0x43C80000, 0x41A00000,
                               0x40800000, 0x805DC,    0x43C80000, 0x0,        0x40800000,
                               0x32080640, 0x43C80000, 0xC3480000, 0xC2200000, 0x32000834};
