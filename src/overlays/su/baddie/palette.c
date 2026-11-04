// Probably an animated texture-palette swap for an actor: copies a palette asset into a per-actor
// buffer, cross-fades between two palettes over a duration, and uploads it to the actor's model.
#include "common.h"

typedef struct {
    u16 to_id;
    u16 from_id;
    u16 state;
    u8 pad_6[10];
    u8 colors[0x800];
} BaddiePalette;
extern void *func_800D674C(s32);
extern void func_801032B0(Actor *, s32, u16);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800F3214(s32 *, s32 *, s32 *, f32);
typedef struct {
    u16 to_id;
    u16 from_id;
    s16 state;
    s16 pad_6;
    f32 timer;
    f32 duration;
} PalS;
extern void func_800B25D8();
extern void func_80100F0C();
extern void *func_80103C94(Actor *);
extern void *func_800B2840(void *);
void subaddiepalette_entrypoint_4();

// Load palette asset id into the buffer and upload it.
void subaddiepalette_entrypoint_0(Actor *actor, BaddiePalette *palette, u16 id)
{
    rare_memcpy(palette->colors, func_800D674C(id), 0x800);
    func_800D6CEC(id);
    palette->to_id = id;
    palette->state = 0;
    subaddiepalette_entrypoint_4(actor, palette);
    func_801032B0(actor, actor->unk0->unk14, id);
}

// Per-frame update: cross-fade between two palettes and re-upload.
void subaddiepalette_entrypoint_1(Actor *actor, BaddiePalette *palette)
{
    s32 from_color[4];
    s32 to_color[4];
    s32 blend[4];
    f32 factor;
    int done;
    void *from_data;
    void *to_data;
    s32 i;
    switch (*(s16 *) &palette->state) {
        case 0:
            break;
        case 1: {
            done = func_800D9078((u8 *) palette + 8);
            factor = func_800F12D4(*(f32 *) ((u8 *) palette + 8), 0.0f,
                                    *(f32 *) ((u8 *) palette + 12), 1.0f, 0.0f);
            from_data = func_800D674C(palette->from_id);
            to_data = func_800D674C(palette->to_id);
            for (i = 0; i != 512; i++) {
                _dbpalette_entrypoint_0(from_data, i, from_color);
                _dbpalette_entrypoint_0(to_data, i, to_color);
                func_800F3214(blend, from_color, to_color, factor);
                _dbpalette_entrypoint_1(palette->colors, i, blend);
            }
            subaddiepalette_entrypoint_4(actor, palette);
            if (done)
                palette->state = 0;
        }
    }
}

// Start a fade to palette id; returns 0 if it is already current.
s32 subaddiepalette_entrypoint_2(u8 **unk_0, PalS *fade, u16 id, f32 duration)
{
    if (fade->to_id == id) {
        return 0;
    }
    fade->state = 1;
    fade->duration = duration;
    fade->timer = duration;
    fade->from_id = fade->to_id;
    fade->to_id = id;
    *(u16 *) (*unk_0 + 0x16) = id;
    return 1;
}

// Upload the palette to the model or vertex instance and count down the frames.
void subaddiepalette_entrypoint_3(Actor *actor, u8 *palette, void *model)
{
    s16 frames;

    frames = *(s16 *) (palette + 6);
    if (frames != 0) {
        if (*(s16 *) &actor->pad60 != 0 && (u32) ((u8 *) actor)[0x7B] >> 6) {
            func_80100F0C(*(s16 *) &actor->pad60, palette + 0x10);
            func_800DF720(func_80100AC4(*(s16 *) &actor->pad60));
        } else {
            func_800B25D8(func_80103C94(actor), func_800B2840(model), palette + 0x10);
        }
        frames = *(s16 *) (palette + 6);
    }
    if (frames)
        *(s16 *) (palette + 6) = frames - 1;
}

// Request a palette upload for one or two frames.
void subaddiepalette_entrypoint_4(actor, palette) u8 *actor;
u8 *palette;
{
    *(s16 *) ((u8 *) palette + 6) = 1;
    if (((*(s16 *) ((u8 *) actor + 0x60) == 0) ||
         (((unsigned long) (u8) *(u8 *) ((u8 *) actor + 0x7B) >> 6) == 0)) &&
        (*(u8 *) ((u8 *) actor + 0x70) & 1)) {
        *(s16 *) ((u8 *) palette + 6) = (s16) (*(s16 *) ((u8 *) palette + 6) + 1);
    }
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
