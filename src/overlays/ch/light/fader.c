#include "common.h"

extern int D_808003A0_chlightfader[];
extern s32 func_800C954C(void);
extern void _chbaddiesetup_entrypoint_3(void (*)(void), s32, s32, s32);
extern void _chlightfader_entrypoint_2(void);
extern void func_800C8B84(s32);
typedef struct LightFadeSample {
    f32 radius[2];
    f32 color[3];
} LightFadeSample;
// Helper actor data; samples are {start, current}.
typedef struct LightFadeState {
    s32 light;
    f32 duration;
    s32 flags;
    s32 unk_C;
    f32 cull_radius;
    LightFadeSample samples[2];
} LightFadeState;
extern void func_800C8800(s32, f32 *);
extern Actor *func_80108474(u32, f32 *, s32);
extern void *func_80100094(Actor *, u32);
extern s32 func_800C89A8(s32);
extern void func_800C8900(s32, f32 *);
extern void func_800C883C(s32, f32 *);
extern s32 func_8001210C(s32);
extern void *func_800A93F8(s32);
extern s32 func_800A9420(s32);
extern s32 func_800A946C(void);
extern void func_800C8D4C(s32, f32 *);
extern void func_800C8E84(s32, f32 *);
extern s32 func_800CACEC(void *, void *, f32);
extern s32 func_800D9078(f32 *);
extern s32 func_800E3E8C(void *, f32);
extern void func_800F2E60(f32 *, f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800F2F60(f32 *, f32 *, f32);
extern s32 func_800F6438(s32);
extern void func_800FFA88(s32);
// Same layout as LightFadeState, as seen by the update function.
typedef struct {
    s32 light;
    f32 duration;
    u32 flags;
    u8 pad_C[4];
    f32 cull_radius;
    f32 radius_start[2];
    f32 color_start[3];
    f32 radius[2];
    f32 color[3];
} LF;
extern void func_80105834(), func_80107C2C(), func_8010A730(), func_8080000C_chlightfader();

int chlightfader_entrypoint_0()
{
    return &D_808003A0_chlightfader;
}

void func_8080000C_chlightfader(s32 arg0)
{
}

// Fades the light's radius and colour until the timer ends, then frees the light and the actor.
// Only updates the light while it is inside some player's view.
void func_80800014_chlightfader(Actor *actor)
{
    s32 done;
    f32 fade;
    s32 i;
    s32 j;
    LF *state;
    f32 tint[3];
    s32 resize;
    s32 visible;
    f32 flicker;
    void *viewport;
    f32 scale;

    state = func_80100094(actor, 0);
    resize = 0;
    done = func_800D9078(&actor->unk58);
    fade = func_800F10B4(actor->unk58, 0, state->duration, 1.0f, 0.1f);
    scale = 1.0f - fade;
    if (state->flags & 1) {
        for (j = 0; j < 2; j++) {
            state->radius[j] = state->radius_start[j] * scale;
        }
        resize = 1;
    }
    if (state->flags & 2) {
        func_800F2F60(state->color, state->color_start, 1.0f - fade);
    }
    func_800F2E60(tint, state->color);
    if (state->flags & 4) {
        if (func_8001210C(1)) {
            flicker = 1.0f;
        } else {
            flicker = 0.6f;
        }
        func_800F2F60(tint, tint, flicker);
    }
    if (func_800A946C() >= 2) {
        visible = 0;
        for (i = 0; i != 8; i++) {
            if (func_800F6438(i) && func_800A9420(i)) {
                viewport = func_800A93F8(i);
                if (viewport != 0 && func_800CACEC(viewport, &actor->position, state->cull_radius)) {
                    visible = 1;
                    break;
                }
            }
        }
    } else {
        visible = func_800E3E8C(&actor->position, state->cull_radius);
    }
    if (visible != 0) {
        state->cull_radius = state->radius[1];
        func_800C8E84(state->light, tint);
        if (resize != 0) {
            func_800C8D4C(state->light, state->radius);
        }
    }
    if (done != 0) {
        func_800C8B84(state->light);
        func_800FFA88(*(s32 *) actor);
    }
}

s32 chlightfader_entrypoint_1(s32 light, s32 duration, s32 flags)
{
    if (func_800C954C() == 0) {
        _chbaddiesetup_entrypoint_3(_chlightfader_entrypoint_2, light, duration, flags);
    } else {
        func_800C8B84(light);
    }
    return 0;
}

// Spawns helper actor 0x33C that copies the light's position, colour and radius.
void chlightfader_entrypoint_2(s32 light, f32 duration_arg, s32 flags)
{
    Actor *fader;
    f32 *pos_ptr;
    f32 duration;
    f32 pos[3];
    f32 unk_0;
    LightFadeState *state;
    s32 offset;
    f32 *color_ptr;
    f32 *radius_ptr;

    // Matching: the f32 reinterpret cast is needed for the match.
    duration = *(f32 *) &duration_arg;
    pos_ptr = pos;
    func_800C8800(light, pos_ptr);
    fader = func_80108474(0x33C, pos_ptr, 0);
    state = func_80100094(fader, 0);
    state->unk_C = func_800C89A8(light);
    offset = 0;
    color_ptr = state->samples[0].color;
    radius_ptr = state->samples[0].radius;
    do {
        func_800C8900(light, color_ptr);
        func_800C883C(light, radius_ptr);
        offset += 0x14;
        color_ptr += 5;
        radius_ptr += 5;
    } while (offset != 0x28);
    state->light = light;
    state->duration = duration;
    state->flags = flags;
    state->cull_radius = state->samples[1].radius[1];
    fader->unk58 = duration;
}

// TU-NOTE: the overlay's .data is defined here in C; its table points to functions of this
// file, and IDO's assembler schedules them differently otherwise. Values taken from the ROM.
// The extern of D_808003A0_chlightfader is adjusted to int[] (same address).
int D_808003A0_chlightfader[20] = {0x334033C,
                                   0x1,
                                   0x0,
                                   (u32) func_80800014_chlightfader,
                                   (u32) func_80105834,
                                   (u32) func_8010A730,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x4,
                                   0x0,
                                   0x0,
                                   0x3C0000,
                                   (u32) func_8080000C_chlightfader,
                                   (u32) func_80107C2C,
                                   -0x7FFFDDFE,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0};
