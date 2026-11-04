// Probably z-buffer occlusion probes: tests whether a projected point is hidden behind geometry.
#include "common.h"
#include "freelist.h"
#include <freelist.h>

typedef struct {
    s32 shift, base;
} LocalExponent;
extern LocalExponent D_801234C0[];
extern u16 func_8001A0C0(s32, s32);
extern f32 mlAbsF(f32);
typedef struct {
    s32 vector[3];
} LocalRecord;
// TU-NOTE: D_8012D600 is the probe freelist pointer, but it is also accessed as
// StateE82: the pointer, then the per-frame view table (D_8012D604..), then the
// frame index (D_8012D67C).
// Per-viewport depth decode constants, valid when the viewport exists.
typedef struct {
    f32 proj_a, proj_b;
    s32 active;
} ViewE82;
typedef struct {
    void *freelist;
    ViewE82 views[2][5];
    s32 frame;
} StateE82;
// One probe sample: screen position (x, y, distance) and visibility state
// (1 visible, 0 occluded, -1 unknown).
typedef struct {
    f32 screen_pos[3], depth;
    f32 unk_10[3], unk_1C[3], unk_28[3];
    s16 state, pending;
} SampleE82;
typedef struct {
    u8 pad[0xC];
    f32 tolerance;
    SampleE82 samples[2][5];
    s16 mode;
} EntryE82;
extern void *func_800A8984(s32);
extern void func_800CA6D4(void *, f32 *, f32 *);
extern void _chjiggygamenew_entrypoint_2(void);
extern s32 func_800DA298(s32);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF04C(f32 *, f32 *);
extern u8 *D_8012D600;
typedef struct {
    u8 pad_0[0x34];
    s16 state;
    u8 pad_36[2];
} local_entry;
typedef struct {
    u8 pad_0[12];
    f32 tolerance;
    local_entry samples[2][5];
    s16 mode;
    u16 unk_242;
} local_type;
extern void func_800EE7F8(void *param_0, s32 param_1);
typedef struct {
    f32 screen_x;
    f32 screen_y;
    f32 dist;
    u8 unk_C[4];
    f32 unk_10[3];
    f32 unk_1C[3];
    f32 unk_28[3];
    s16 state;
    s16 pending;
} local_inner;
typedef struct {
    u8 pad_0[0xC];
    f32 tolerance;
    local_inner samples[2][5];
    s16 mode;
} local_outer;
extern s32 D_8012D67C;
extern s32 func_800C4C34(s32, local_outer *, local_inner *, s32 *);
extern f32 func_800E3928(local_outer *, f32 *);
extern void func_800E3980(f32 *);
s16 func_800E8918();

// TU-NOTE: the .rodata of this file starts with these constants; each is a
// 16-byte object whose zero words belong to it (alignment in the ROM).
const struct {
    f32 z_scale;
    f32 epsilon;
    f32 pad[2];
} D_80125E40 = {511.0f, 1e-06f};

// Decodes the N64 compressed z-buffer value into linear depth.
// Decode the N64 compressed 16-bit z-buffer sample at (x, y) to a linear depth.
f32 func_800E81E0(s32 x, s32 y, f32 proj_a, f32 proj_b)
{
    s32 raw;
    s32 decoded;
    LocalExponent *exp_entry;
    s32 exp_idx, mantissa, z_scaled;
    f32 denom;
    raw = func_8001A0C0(x, y);
    exp_idx = (raw >> 13) & 7;
    exp_entry = &D_801234C0[exp_idx];
    mantissa = (raw >> 2) & 0x7FF;
    decoded = exp_entry->base + (mantissa << exp_entry->shift);
    z_scaled = decoded / 256 - 511;
    denom = z_scaled / D_80125E40.z_scale - proj_a;
    return mlAbsF(denom) < D_80125E40.epsilon ? 0.0f : proj_b / denom;
}

// Probe pool, per-frame visibility evaluation, register/unregister and queries.
void func_800E829C(void)
{
    s32 i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            ((LocalRecord *) &D_8012D600)[i * 5 + j + 1].vector[0] = 0;
        }
    }
}

// Per-frame update: refresh each viewport's depth constants, flip the frame index,
// then resolve last frame's probe samples against the z-buffer.
void func_800E82EC(void)
{
    s32 unk_0;
    s32 idx;
    s32 capacity;
    f32 diff;
    f32 near_z;
    f32 far_z;
    f32 scratch;
    s32 vp;
    EntryE82 *probe;
    SampleE82 *sample;
    diff = 2.0f;
    for (vp = 0; vp < 5; vp++) {
        probe = func_800A8984(vp);
        if (probe) {
            func_800CA6D4(probe, &near_z, &far_z);
            scratch = 1.0f / (near_z - far_z);
            (*(StateE82 *) &D_8012D600)
                .views[(*(StateE82 *) &D_8012D600).frame][vp]
                .proj_a = -((near_z + far_z) * scratch);
            (*(StateE82 *) &D_8012D600)
                .views[(*(StateE82 *) &D_8012D600).frame][vp]
                .proj_b = -(diff * near_z * far_z * scratch);
            (*(StateE82 *) &D_8012D600)
                .views[(*(StateE82 *) &D_8012D600).frame][vp]
                .active = 1;
        } else {
            (*(StateE82 *) &D_8012D600)
                .views[(*(StateE82 *) &D_8012D600).frame][vp]
                .active = 0;
        }
    }
    if (++(*(StateE82 *) &D_8012D600).frame >= 2)
        (*(StateE82 *) &D_8012D600).frame = 0;
    if (func_800DA298(0xD4E) || func_800DA298(0xD4F))
        _chjiggygamenew_entrypoint_2();
    if ((*(StateE82 *) &D_8012D600).freelist) {
        capacity = freelist_capacity((*(StateE82 *) &D_8012D600).freelist);
        for (idx = 1; idx < capacity; idx++) {
            if (freelist_is_element_alive((*(StateE82 *) &D_8012D600).freelist, idx)) {
                probe = freelist_at((*(StateE82 *) &D_8012D600).freelist, idx);
                for (vp = 0; vp < 5; vp++) {
                    sample = &probe->samples[(*(StateE82 *) &D_8012D600).frame][vp];
                    if (sample->pending &&
                        (*(StateE82 *) &D_8012D600)
                            .views[(*(StateE82 *) &D_8012D600).frame][vp]
                            .active) {
                        if (!(sample->screen_pos[0] < 0.0f) && !(sample->screen_pos[0] >= 304.0f) &&
                            !(sample->screen_pos[1] < 0.0f) && !(sample->screen_pos[1] >= 228.0f)) {
                            switch (probe->mode) {
                                case 1:
                                    scratch = -func_800E81E0(
                                        sample->screen_pos[0], sample->screen_pos[1],
                                        (*(StateE82 *) &D_8012D600)
                                            .views[(*(StateE82 *) &D_8012D600).frame][vp]
                                            .proj_a,
                                        (*(StateE82 *) &D_8012D600)
                                            .views[(*(StateE82 *) &D_8012D600).frame][vp]
                                            .proj_b);
                                    diff = sample->screen_pos[2] - scratch;
                                    sample->depth = scratch;
                                    if (mlAbsF(diff) < probe->tolerance)
                                        sample->state = 1;
                                    else if (diff > 0.0f)
                                        sample->state = 0;
                                    else
                                        sample->state = 1;
                                    func_800EFB24(sample->unk_28, sample->unk_1C,
                                                  sample->unk_10);
                                    func_800EF334(sample->unk_28,
                                                  sample->depth / sample->screen_pos[2]);
                                    func_800EF04C(sample->unk_28, sample->unk_10);
                                    break;
                                case 0:
                                    if (func_8001A0C0(sample->screen_pos[0], sample->screen_pos[1]) ==
                                        0xFFFC)
                                        sample->state = 1;
                                    else
                                        sample->state = 0;
                            }
                        } else {
                            sample->state = -1;
                        }
                    } else {
                        sample->state = -1;
                    }
                    sample->pending = 0;
                }
            }
        }
    }
}

int func_800E86DC()
{
    if (D_8012D600 != 0) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

int func_800E8714(s32 mode)
{
    s32 handle;
    local_type *probe;
    s32 i;
    s32 j;
    if (!(FreeList *) D_8012D600)
        D_8012D600 = freelist_new(sizeof(local_type), 4);
    probe = freelist_next((FreeList **) &D_8012D600, &handle);
    bzero(probe, sizeof(local_type));
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 5; j++) {
            probe->samples[i][j].state = -1;
        }
    }
    probe->tolerance = 20.0f;
    probe->mode = mode;
    return (u8) handle;
}

s32 func_800E87E0(handle)
u8 handle;
{
    freelist_erase(D_8012D600, handle);

    if (!freelist_used_count(D_8012D600)) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

void func_800E8830(handle, unk_0) u8 handle;
s32 unk_0;
{
    void *probe;
    probe = freelist_at(((void *) D_8012D600), handle);
    func_800EE7F8(probe, unk_0);
}

void func_800E8870(handle, tolerance) u8 handle;
s32 tolerance;
{
    u8 *probe;
    probe = freelist_at(((FreeList *) D_8012D600), handle);
    *((float *) (probe + 12)) = *((float *) (&tolerance));
}

int func_800E88AC(handle, screen_out)
u8 handle;
s32 screen_out;
{
    u32 viewport;
    viewport = func_800A89F8();
    // Matching: the "| 0" is needed for the match.
    func_800E8918(handle, viewport | 0, 0, screen_out);
}

int func_800E88E4(handle)
u8 handle;
{
    u32 viewport;
    viewport = func_800A89F8();
    // Matching: the "| 0" is needed for the match.
    func_800E8918(handle, viewport | 0, 0, 0);
}

s16 func_800E8918(handle, viewport, out_vec, out_screen)
u8 handle;
s32 viewport;
f32 *out_vec;
f32 *out_screen;
{
    f32 tmp_vec[3];
    local_inner *sample;
    local_outer *probe;
    s32 projected;
    s32 unk_0;
    probe = freelist_at(((FreeList *) D_8012D600), handle);
    sample = &probe->samples[D_8012D67C][viewport];
    if (sample->pending)
        sample->pending = 0;
    projected = func_800C4C34(viewport, probe, sample, &unk_0);

    if (unk_0 && projected) {
        sample->dist = func_800E3928(probe, tmp_vec);
        func_800E3980(sample->unk_10);
        func_800EE7F8(sample->unk_1C, (f32 *) probe);
        sample->pending = 1;
    }

    if (out_screen) {
        out_screen[0] = sample->screen_x;
        out_screen[1] = sample->screen_y;
    }

    if (out_vec)
        func_800EE7F8(out_vec, sample->unk_28);
    return sample->state;
}

void func_800E8A20()
{
    if (D_8012D600 != 0) {
        D_8012D600 = freelist_defrag(D_8012D600);
    }
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
LocalExponent D_801234C0[8] = {0x6, 0x0,     0x5, 0x20000, 0x4, 0x30000, 0x3, 0x38000,
                               0x2, 0x3C000, 0x1, 0x3E000, 0x0, 0x3F000, 0x0, 0x3F800};
