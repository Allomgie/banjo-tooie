#include "common.h"
#include <PR/gbi.h>

#define LOCAL_MAX(a, b) ((a) > (b) ? (a) : (b))
typedef struct {
    u8 pad_0[6];
    s16 pos[3];
    f32 alpha;
    f32 rot[8];
    s16 size;
    u8 pad_32[7];
    u8 active : 1;
    u8 pad_39 : 7;
    u8 pad_3A[2];
} EntryBBD60;
typedef struct {
    s16 pad_0;
    u16 asset_id;
    u8 pad_4[8];
    s16 origin[3];
    u8 pad_12[0x41];
    u8 unk_53;
    u8 pad_54[0x2C];
    u8 color[4];
    u8 pad_84[8];
    EntryBBD60 *particle_begin;
    EntryBBD60 *particle_end;
} StateBBD60;
extern void func_800DF5D8(u32, u32, u32, s32);
extern void func_800DF830(s32);
extern s32 func_800DE448(f32 *, f32 *, f32, s32, s32);
typedef struct {
    u8 pad_0[0x5C];
    f32 period, phase[3], amplitude[3];
} LocalPulse;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F13C4(f32, f32);
extern f32 mlAbsF(f32);
typedef struct {
    u8 pad_0[6];
    s16 pos[3];
    f32 alpha;
    f32 pad_10[2];
    f32 rot_z;
    f32 age;
    u8 pad_20[12];
    s16 frame;
    u16 pad_2E;
    s16 size;
    u8 pad_32[7];
    u8 active : 1;
    u8 pad_39 : 7;
    u8 pad_3A[2];
} EntryBF;
typedef struct {
    u16 flags;
    u16 asset_id;
    u8 pad_4[8];
    s16 origin[3];
    u8 pad_12[0x41];
    u8 unk_53;
    u8 pad_54[8];
    f32 pulse_period;
    u8 pad_60[0x20];
    u8 color[4];
    u8 pad_84[8];
    EntryBF *particle_begin, *particle_end;
} StateBF;
extern void *func_800D674C(s32);
extern void func_800E2588(u32);
extern void func_800E24F8(s32, s32, s32);
extern void func_800E2440(s32, s32, s32);
extern void func_800E24B4(s32);
extern void func_800E24D8(s32);
extern void func_800E2594(s32, void *);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern s32 func_800E28A4(s32, s32, s32, f32 *, f32 *, f32 *, s32);
extern s32 func_800E2720(s32, s32, s32, f32 *, f32 *, s32);
extern void func_800E2530(f32);
extern void func_800E2A14(s32);
extern Gfx D_8011A730[];
void func_800BC474();

// Draws the emitter's model particles.
void func_800BBD60(emitter, gfx) StateBBD60 *emitter;
s32 gfx;
{
    s32 model;
    f32 world_pos[3];
    EntryBBD60 *particle;
    model = func_800D674C(emitter->asset_id);
    for (particle = emitter->particle_begin; particle < emitter->particle_end; particle++) {
        world_pos[0] = particle->pos[0] + emitter->origin[0];
        world_pos[1] = particle->pos[1] + emitter->origin[1];
        world_pos[2] = particle->pos[2] + emitter->origin[2];
        func_800DF5D8(emitter->color[0], emitter->color[1], emitter->color[2],
                      (s32) ((f32) (u32) emitter->color[3] * particle->alpha));
        func_800DF830(emitter->unk_53);
        particle->active |=
            func_800DE448(world_pos, particle->rot, particle->size * 0.00390625f, 0, model)
                ? 1
                : 0;
    }
}

// Pulses the per-axis scale with a triangle wave.
void func_800BBED8(LocalPulse *emitter, f32 time, f32 *scale)
{
    s32 i;
    f32 half_period;
    f32 factor;
    half_period = emitter->period * 0.5f;
    for (i = 0; i < 3; i++) {
        if (emitter->amplitude[i] != 0.0f) {
            factor = func_800F13C4(emitter->phase[i] + time, emitter->period);
            factor = mlAbsF(factor - half_period);
            factor = func_800F10B4(factor, 0.0f, half_period, 1.0f - emitter->amplitude[i],
                                    emitter->amplitude[i] + 1.0f);
            scale[i] *= factor;
        }
    }
}

// Draws the emitter's sprite particles.
void func_800BBFDC(emitter, gfx) StateBF *emitter;
s32 gfx;
{
    void *sprite;
    f32 world_pos[3];
    f32 rot[3];
    f32 scale[3];
    EntryBF *particle;
    s32 unk_0;
    sprite = func_800D674C(emitter->asset_id);
    unk_0 = (emitter->flags & 0x800) ? 1 : 0;
    if (!(emitter->flags & 0x20) && (emitter->color[0] != 255 || emitter->color[1] != 255 ||
                                       emitter->color[2] != 255 || emitter->color[3] != 255)) {
        func_800E2588(emitter->unk_53);
        func_800E24F8(emitter->color[0], emitter->color[1], emitter->color[2]);
        func_800E2440(emitter->color[0] < 8 ? 0 : emitter->color[0] - 8,
                      emitter->color[1] < 8 ? 0 : emitter->color[1] - 8,
                      emitter->color[2] < 8 ? 0 : emitter->color[2] - 8);
        func_800E24B4(0);
    } else {
        func_800E2588(emitter->unk_53 ? 2 : 0);
    }
    func_800E24D8(emitter->flags & 0x200 ? 1 : 0);
    func_800E2594(gfx, sprite);
    if (emitter->flags & 1)
        func_800EFA4C(rot, 90.0f, 0.0f, 0.0f);
    for (particle = emitter->particle_begin; particle < emitter->particle_end; particle++) {
        world_pos[0] = particle->pos[0] + emitter->origin[0];
        world_pos[1] = particle->pos[1] + emitter->origin[1];
        world_pos[2] = particle->pos[2] + emitter->origin[2];
        scale[0] = scale[1] = scale[2] = particle->size * 0.00390625f;
        if (emitter->pulse_period != 0.0f)
            func_800BBED8(emitter, particle->age, scale);

        if (emitter->flags & 1) {
            particle->active |=
                func_800E28A4(gfx, particle->frame >> 8, unk_0, world_pos, rot, scale,
                              (s32) ((u32) emitter->color[3] * particle->alpha));
        } else {
            func_800E2530(particle->rot_z);
            particle->active |=
                func_800E2720(gfx, particle->frame >> 8, unk_0, world_pos, scale,
                              (s32) ((u32) emitter->color[3] * particle->alpha));
        }
    }
    func_800E2A14(gfx);
}

// Draws the emitter if its pass bit (flag 4) equals pass.
void func_800BC358(void *emitter, s32 gfx, s32 pass)
{
    int pass_bit;
    void *base;
    u16 flags;
    char *type_field;
    u8 asset_type;
    // Matching: the empty block and the extra temporaries are needed for the match.
    if (!gfx) {
    }
    flags = (pass_bit = *((u16 *) emitter));
    base = emitter;
    pass_bit = flags & 4;
    if (pass_bit == pass) {
        asset_type = *((u8 *) (type_field = ((char *) base) + 0xA));
        switch (asset_type) {
            case 0:
                func_800BBD60();
                return;

            case 7:
                func_800BBFDC();
        }
    }
}

// Draws the emitter in both passes.
int func_800BC3B8(s32 emitter, s32 gfx)
{
    func_800BC358(emitter, gfx, 4);
    func_800BC358(emitter, gfx, 0);
}

void *func_800BC3F0(void *emitter)
{
    return defrag(emitter);
}

void func_800BC410(s32 gfx, s32 r, s32 g, s32 b)
{
    s32 rect[4];
    func_800E7FCC(rect);
    func_800BC474(gfx, rect[0], rect[1], rect[2], rect[3], r, g,
                  b);
}

// Fills a rectangle with the given RGB color.
void func_800BC474(gfx, x, y, width, height, r, g,
                   b) Gfx **gfx;
s32 x;
s32 y;
s32 width;
s32 height;
s32 r;
s32 g;
s32 b;
{
    gDma1p((*gfx)++, 0xDE, (u8 *) D_8011A730 - 0x80000000, 0, G_DL_PUSH);
    gDPSetFillColor((*gfx)++, (GPACK_RGBA5551(r, g, b, 1) << 16) |
                                      GPACK_RGBA5551(r, g, b, 1));
    gDPFillRectangle((*gfx)++, LOCAL_MAX(x, 0), LOCAL_MAX(y, 0),
                     LOCAL_MAX(x + width - 1, 0), LOCAL_MAX(y + height - 1, 0));
}

// Fills a rectangle with black.
void func_800BC580(s32 gfx, s32 x, s32 y, s32 width, s32 height)
{
    func_800BC474(gfx, x, y, width, height, 0, 0, 0);
}

// Fills a rectangle with 0xFFFC, used to clear the depth buffer.
void func_800BC5B0(Gfx **gfx, s32 x, s32 y, s32 width, s32 height)
{
    gDma1p((*gfx)++, 0xDE, (u8 *) D_8011A730 - 0x80000000, 0, G_DL_PUSH);
    gDPSetFillColor((*gfx)++, 0xFFFCFFFC);
    gDPFillRectangle((*gfx)++, LOCAL_MAX(x, 0), LOCAL_MAX(y, 0),
                     LOCAL_MAX(x + width - 1, 0), LOCAL_MAX(y + height - 1, 0));
}

// RDP setup for fill-mode rectangles.
Gfx D_8011A730[6] = {0xE7000000, 0x0, 0xE3000800, 0x0, 0xE3000A01, 0x300000,
                     0xE200001C, 0x0, 0xDF000000, 0x0, 0x0,        0x0};
