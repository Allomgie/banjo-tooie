// Intro timing sync. Most likely it busy-waits until real time matches the scripted time of the
// current step, so the intro stays in step with its music, and returns the scaled delta time.
#include "common.h"

extern s32 D_808004A0_glintrosyncDll;
extern s32 D_808004A8_glintrosyncDll;
extern s32 D_808004B0_glintrosyncDll;
extern s32 D_808004B8_glintrosyncDll[];
extern u8 D_80127194[];
extern s32 func_800C954C(void);
extern f32 func_800D8FF8(void);
extern f32 func_800D9004(void);
typedef struct {
    f32 pad0;
    f32 pad4;
    f32 time;
    f32 val;
    u8 flag;
} IntroSync90;
typedef struct {
    s32 key;
    f32 value;
} IntroKey90;
extern IntroKey90 D_808004F8_glintrosyncDll[27];
extern s32 _gcsectionDll_entrypoint_4(void);
extern f32 D_808004A4_glintrosyncDll[][2];
typedef struct {
    s32 a;
    s32 idx;
    f32 f;
} IntroSyncCtx;
extern IntroSyncCtx D_801275D0;

typedef struct {
    f32 pad0;
    f32 pad4;
    f32 time;
    f32 val;
} IntroSync78;

s32 func_80800000_glintrosyncDll(s32 seq_id)
{
    s8 *entry;
    s32 index;

    if (seq_id == D_808004A0_glintrosyncDll) {
        return 0;
    }
    if (seq_id == D_808004A8_glintrosyncDll) {
        return 1;
    }
    entry = &D_808004B8_glintrosyncDll;
    index = 3;
    if (seq_id == D_808004B0_glintrosyncDll) {
        return 2;
    }
loop_7:
    if (seq_id == *(s32 *) ((s8 *) entry + 0)) {
        return index;
    }
    if (seq_id == *(s32 *) ((s8 *) entry + 0x8)) {
        return index + 1;
    }
    if (seq_id == *(s32 *) ((s8 *) entry + 0x10)) {
        return index + 2;
    }
    if (seq_id == *(s32 *) ((s8 *) entry + 0x18)) {
        return index + 3;
    }
    index += 4;
    entry += 0x20;
    if (index == 0xB) {
        return -1;
    }
    goto loop_7;
}

// Microseconds since the sequence start was recorded.
u32 func_808000BC_glintrosyncDll(s32 seq_id)
{
    s32 delta;
    u32 now;

    now = osGetCount();
    if (now >= *(u32 *) (D_80127194 + 0x43C)) {
        delta = now - *(u32 *) (D_80127194 + 0x43C);
    } else {
        delta = (0xFFFFFFFFU - *(u32 *) (D_80127194 + 0x43C)) + now + 1;
    }
    return (u32) ((f32) delta * 0.0213333331f);
}

int glintrosyncDll_entrypoint_0(s32 seq_id)
{
    s32 index;
    ((int *) D_80127194)[0x10F] = osGetCount();
    index = func_80800000_glintrosyncDll(seq_id);
    ((int *) D_80127194)[0x110] = index;
}

// Busy-waits until real time catches up with the scripted time of the current step.
void glintrosyncDll_entrypoint_1(void)
{
    s32 step = D_801275D0.idx;
    if (step >= 0) {
        f32 target_time;
        u32 target_us;
        target_time = D_808004A4_glintrosyncDll[step][0] - D_801275D0.f;
        target_time = target_time * 1000000.0f;
        target_us = target_time < 0.0f ? 0 : (u32) target_time;
        while (func_808000BC_glintrosyncDll(D_801275D0.a) < target_us) {
        }
        D_801275D0.f += (f32) func_808000BC_glintrosyncDll(D_801275D0.a) / 1000000.0f;
    }
}

void glintrosyncDll_entrypoint_2(f32 value)
{
    *(f32 *) ((u8 *) (u8 *) D_80127194 + 0x444) = value;
}

float glintrosyncDll_entrypoint_3()
{
    return ((f32 *) D_80127194)[0x111];
}

// Advances the intro clock; the speed factor drops to 0.86 from 364.5 s on.
void glintrosyncDll_entrypoint_4(f32 delta)
{
    f32 time = (*(IntroSync78 *) &D_801275D0).time;
    if (time < 364.5f && time + delta >= 364.5f) {
        (*(IntroSync78 *) &D_801275D0).val = 0.86f;
    }
    (*(IntroSync78 *) &D_801275D0).time = time + delta;
}

// Scaled frame delta time.
f32 glintrosyncDll_entrypoint_5(void)
{
    if (func_800C954C()) {
        return *(f32 *) (D_80127194 + 0x448) * func_800D8FF8();
    }
    return *(f32 *) (D_80127194 + 0x448) * func_800D9004();
}

void glintrosyncDll_entrypoint_6(s32 map_id)
{
    s32 i;

    if (_gcsectionDll_entrypoint_4() == 0xD) {
        (*(IntroSync90 *) &D_801275D0).flag = 1;
    } else {
        (*(IntroSync90 *) &D_801275D0).flag = 0;
    }
    (*(IntroSync90 *) &D_801275D0).val = 1.0f;
    if ((*(IntroSync90 *) &D_801275D0).flag) {
        for (i = 0; i < 27; i++) {
            if (map_id == D_808004F8_glintrosyncDll[i].key) {
                (*(IntroSync90 *) &D_801275D0).val = D_808004F8_glintrosyncDll[i].value;
                break;
            }
        }
    }
}

s32 D_808004A0_glintrosyncDll = 0xA8;
f32 D_808004A4_glintrosyncDll[1][2] = {64.6f, 2.27e-43f};
static u32 D_808004A4_glintrosyncDll_rest[1] = {0x42EC0000};
s32 D_808004B0_glintrosyncDll = 0xA9;
static u32 D_808004B0_glintrosyncDll_rest[1] = {0x43180000};
s32 D_808004B8_glintrosyncDll[16] = {0xA3, 0x43344000, 0xAA, 0x437C0000, 0xA4, 0x43921333,
                                     0xAB, 0x43D9A000, 0xA5, 0x43E60000, 0xAC, 0x43ECC000,
                                     0xA6, 0x43FE0000, 0xA7, 0x440D8000};
IntroKey90 D_808004F8_glintrosyncDll[27] = {
    0xA1,  1.02f, 0xA8,  0.94f, 0xA2,  0.98f, 0xA9,  0.98f, 0xA3,  0.88f, 0xAA,
    0.9f,  0xA4,  0.92f, 0xAB,  1.0f,  0xA5,  0.95f, 0xAC,  1.0f,  0xA6,  0.89f,
    0xA7,  0.97f, 0x18E, 1.0f,  0x18C, 1.0f,  0x18F, 0.95f, 0x190, 0.8f,  0x17E,
    0.95f, 0x18D, 0.95f, 0x194, 0.95f, 0x197, 0.95f, 0x198, 0.95f, 0x199, 0.95f,
    0x195, 0.95f, 0x193, 0.9f,  0x192, 0.94f, 0x191, 1.0f,  0x196, 1.0f};
