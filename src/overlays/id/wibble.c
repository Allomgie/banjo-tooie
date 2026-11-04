#include "common.h"

typedef struct {
    s16 ob[3];
    u16 flag;
    s16 tc[2];
    u8 cn[4];
} WibVtx;
// One settings entry, selected by mesh id hundreds.
typedef struct {
    u8 pad_0[0xE];
    s16 id;
} WibbleRecord;
extern WibbleRecord D_80800770_idwibble[];
// Leading part of the effect state, as seen by the update functions.
typedef struct {
    f32 bbox_min[3];
    f32 bbox_max[3];
    u8 pad_18[0xC];
    f32 phase;
    s32 pad_28;
    f32 phase_speed;
    s32 pad_30;
    s16 y_offset;
    u8 pad_36;
    u8 always_on;
} WibbleState;
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern void _glid_entrypoint_0();
extern void _idwibble_entrypoint_0(void);
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800137D4(f32);
extern f32 func_80013788(f32);

// Full effect state (0x38 bytes).
typedef struct {
    f32 bbox_min[3];
    f32 bbox_max[3];
    s16 mid_height;
    s16 amplitude;
    f32 uv_scale;
    f32 bright_scale;
    f32 phase;
    f32 wave_k;
    f32 phase_speed;
    u8 bright_base;
    u8 height_mode;
    u8 bright_mode;
    u8 uv_enabled;
    s16 y_offset;
    u8 unk_36;
    u8 always_on;
} WibbleData50;
// Layout of one D_80800770 table entry.
typedef struct {
    f32 wavelength;
    f32 height;
    f32 speed;
    u8 brightness;
    u8 uv_amount;
    s16 id;
} WibbleSettings50;

// Ripple height at a vertex: sine of the distance from the centre minus the phase.
// Also writes the UV offset when UV distortion is enabled.
f32 func_80800000_idwibble(wib, vtx, uv_off)
u8 *wib;
s16 *vtx;
f32 *uv_off;
{
    f32 dist;
    f32 height;
    f32 uv_len;
    f32 pos[3];
    f32 inv_scale;

    pos[0] = vtx[0];
    pos[1] = vtx[1];
    pos[2] = vtx[2];
    dist = func_800EEF94(pos);
    height = *(s16 *) (wib + 0x1A) *
             func_800137D4(
                 func_800136D0((dist - *(f32 *) (wib + 0x24)) * *(f32 *) (wib + 0x28)));
    if (wib[0x33]) {
        uv_len = *(f32 *) (wib + 0x28) * (*(s16 *) (wib + 0x1A) * func_80013788(height));
        if (dist > 0.0001f) {
            inv_scale = uv_len / dist;
            uv_off[0] = pos[0] * inv_scale;
            uv_off[1] = pos[2] * inv_scale;
        } else {
            uv_off[0] = pos[0] * uv_len;
            uv_off[1] = pos[2] * uv_len;
        }
    }
    return height;
}

// Vertex kernel: ripple height, optional brightness and UV distortion.
void idwibble_entrypoint_0(s32 arg0, WibVtx *src, WibVtx *dst, s32 n, u8 *wib)
{
    f32 height;
    s32 bright;
    f32 uv_off[2];
    WibVtx *end;

    end = src + n;
    for (; src < end; src++, dst++) {
        height = func_80800000_idwibble(wib, src->ob, uv_off);
        if (wib[0x31] == 1) {
            dst->ob[1] = *(s16 *) (wib + 0x34) + (*(s16 *) (wib + 0x18) + height);
        } else if (wib[0x31] == 2) {
            dst->ob[1] = *(s16 *) (wib + 0x34) + (src->ob[1] + height);
        }
        if (wib[0x32] == 1) {
            bright = height * *(f32 *) (wib + 0x20) + (u32) wib[0x30];
            dst->cn[0] = (src->cn[0] * bright) >> 8;
            dst->cn[1] = (src->cn[1] * bright) >> 8;
            dst->cn[2] = (src->cn[2] * bright) >> 8;
        }
        if (wib[0x33]) {
            dst->tc[0] = src->tc[0] + *(f32 *) (wib + 0x1C) * uv_off[0];
            dst->tc[1] = src->tc[1] + *(f32 *) (wib + 0x1C) * uv_off[1];
        }
    }
}

void idwibble_entrypoint_1(s32 arg0)
{
}

// Pick the settings entry for a mesh id (hundreds); falls back to the first entry.
WibbleRecord *func_80800324_idwibble(s32 mesh_id)
{
    s32 i;

    mesh_id -= mesh_id % 100;
    for (i = 0; i < 6; i++) {
        if (mesh_id == D_80800770_idwibble[i].id) {
            return &D_80800770_idwibble[i];
        }
    }
    return D_80800770_idwibble;
}

// Init from the mesh bounding box and the settings entry for the mesh id.
void idwibble_entrypoint_2(WibbleData50 *wib, s32 mesh_id, s32 unk_2, s32 unk_3,
                           s32 mode)
{
    WibbleSettings50 *settings;
    s16 bbox_min[3];
    s16 bbox_max[3];
    f32 val;
    f32 amp;
    f32 zero = 0.0f; // Matching: comparison value kept in a local so the constant is on the left of c.eq.s.
    settings = (WibbleSettings50 *) func_80800324_idwibble(mesh_id);
    mesh_id %= 100;
    _glidmake_entrypoint_2(unk_2, unk_3, bbox_min, bbox_max);
    wib->mid_height = (bbox_min[1] + bbox_max[1]) / 2;
    func_800EE88C(wib->bbox_min, bbox_min);
    func_800EE88C(wib->bbox_max, bbox_max);
    wib->uv_scale = settings->uv_amount << 6;
    if (settings->uv_amount)
        wib->uv_enabled = 1;
    else
        wib->uv_enabled = 0;
    val = settings->height;
    if (val < 0.0f) {
        wib->amplitude = -val;
        wib->height_mode = 2;
    } else if (val > 0.0f) {
        wib->height_mode = 0;
        wib->amplitude = val;
    } else {
        wib->height_mode = 1;
        wib->amplitude = (wib->bbox_max[1] - wib->bbox_min[1]) * 0.5f;
    }
    amp = wib->amplitude;
    if (zero == amp) {
        wib->amplitude = 1;
        amp = wib->amplitude;
    }
    wib->bright_scale = (f32) (u32) settings->brightness / amp;
    wib->bright_base = 255 - settings->brightness;
    if (settings->brightness)
        wib->bright_mode = 1;
    else
        wib->bright_mode = 0;
    wib->phase = 0.0f;
    wib->wave_k = 6.2831855f / settings->wavelength;
    val = settings->speed;
    if (val < 0.0f)
        wib->phase_speed = -val;
    else
        wib->phase_speed = mesh_id * val;
    wib->y_offset = 0;
    if (mode != 1 && mode != 2)
        wib->always_on = 1;
    else
        wib->always_on = 0;
}

// Update gated by the frustum test, unless always_on is set.
void idwibble_entrypoint_3(WibbleState *wib, s32 unk_1, s32 unk_2)
{
    f32 box_min[3];
    f32 box_max[3];

    wib->phase += func_800D8FF8() * wib->phase_speed;
    func_800EE7F8(box_min, wib->bbox_min);
    func_800EE7F8(box_max, wib->bbox_max);
    box_min[1] += wib->y_offset;
    box_max[1] += wib->y_offset;
    if (wib->always_on || func_800E3D0C(wib->bbox_min, wib->bbox_max)) {
        _glid_entrypoint_0(unk_1, unk_2, _idwibble_entrypoint_0, wib);
    }
}

// Update without the frustum test.
void idwibble_entrypoint_4(f32 *wib, s32 unk_1, s32 unk_2)
{
    wib[9] += func_800D8FF8() * wib[11];
    _glid_entrypoint_0(unk_1, unk_2, _idwibble_entrypoint_0);
}

// Set the water level offset; used by Dippy's pool, the GI toxic pools and the CCL lake.
void idwibble_entrypoint_5(wib, y_offset) s32 wib;
s16 y_offset;
{
    *(s16 *) (wib + 0x34) = y_offset;
}

// TU-NOTE: the .data of this overlay is defined here in C, values taken from the ROM.
// D_8080077E_idwibble = D_80800770_idwibble + 0xE and D_8080078E_idwibble = D_80800780_idwibble + 0xE
// are linker symbols in undefined_syms.us.txt.
WibbleRecord D_80800770_idwibble[1] = {0x43, 0xC8, 0x0, 0x0, 0x41, 0xA0, 0x0, 0x0,
                                       0x41, 0xA0, 0x0, 0x0, 0xA,  0x1,  0x0};
u32 D_80800780_idwibble[20] = {0x43C80000, 0x41A00000, 0x40800000, 0x32080064, 0x43C80000,
                               0x41A00000, 0x40800000, 0x320000C8, 0x43C80000, 0x41A00000,
                               0x40800000, 0x8012C,    0x43C80000, 0x0,        0x40800000,
                               0x32080190, 0x43C80000, 0xC3480000, 0xC2200000, 0x32000384};
