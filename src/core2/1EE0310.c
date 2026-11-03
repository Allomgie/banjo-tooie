#include "common.h"

extern s32 D_80136EF0;
typedef struct {
    u8 pad0[0x60];
    s16 id;
    u8 pad1[0x12];
    u32 unused0 : 6, flat : 1, unused1 : 18, negative : 1, unused2 : 6;
    u32 unused3 : 24, count : 2, unused4 : 4, active : 1, unused5 : 1;
    u8 pad2[0x1A];
    s16 mode;
    u8 red, green, blue, alpha;
} LocalActor_80106A98;
extern void func_800DF660(s32, s32, s32, u8);
extern void func_800DF720(s32);
extern s32 func_80100AC4(s16);
extern s32 func_800B27A0(s32);
extern void func_800DF5D8(u8, u8, u8, u8);
typedef struct {
    u8 pad[0x74];
    u32 unused : 25, special : 1, rest : 6;
    u32 unused1 : 24, count : 2, unused2 : 4, active : 1, rest1 : 1;
} LocalActor_80106C4C;
typedef struct {
    u8 pad[0x18];
    f32 radius;
} LocalLight;
extern void _subaddiefade_entrypoint_9(LocalActor_80106C4C *, s32 *);
extern f32 func_80103F38(LocalActor_80106C4C *, f32 *);
extern s32 func_800B3494(s32, f32 *, f32);
extern void func_800B37A4(s32, LocalLight **, s32 *);
extern void func_800C8960(s32 *, s32 *);
extern void func_800B36C0(s32, s32 *, s32 *, f32);
s32 func_80106C4C();
int func_80106D60(s32 param_0, s32 param_1, f32 param_2[3]);
int func_80106DA4();

void func_80106A20(void)
{
}

int func_80106A28()
{
    if (D_80136EF0 != 0) {
        func_800B3370(D_80136EF0);
        D_80136EF0 = 0;
    }
}

void func_80106A60()
{
    if (D_80136EF0 != 0) {
        D_80136EF0 = func_800B38E8(D_80136EF0);
    }
}

// Chooses the model lighting mode for the actor at draw time and sets its vertex buffer.
void func_80106A98(LocalActor_80106A98 *actor, s32 unk_1)
{
    s32 lights;
    if (actor->count) {
        if (((s32) actor->mode >> 15) != 0) {
            func_800DF660(3, actor->count, 0, actor->alpha);
            func_800DF720(func_80100AC4(actor->id));
            return;
        }
        if (actor->flat) {
            func_800DF660(2, actor->count, 0, actor->alpha);
            func_800DF720(func_80100AC4(actor->id));
            return;
        }
        lights = func_80106C4C(actor);
        if (!func_800B27A0(unk_1)) {
            actor->count = 0;
            actor->negative = 0;
            return;
        }
        if (lights)
            func_800DF660(1, 0, lights, actor->alpha);
        else
            func_800DF660(1, actor->negative ? -(s32) actor->count : (s32) actor->count, 0,
                          actor->alpha);
        func_800DF720(func_80100AC4(actor->id));
        return;
    }
    if (actor->active)
        func_800DF5D8(actor->red, actor->green, actor->blue, actor->alpha);
}

// Returns the light collector (6 lights), creating it on first use.
int func_80106C08()
{
    if (!D_80136EF0) {
        D_80136EF0 = func_800B3310(6);
    }
    return D_80136EF0;
}

// Gathers the lights around the actor's model centre into the collector and returns it.
s32 func_80106C4C(actor)
LocalActor_80106C4C *actor;
{
    f32 center[3];
    s32 collector;
    s32 light_count;
    s32 color[3];
    LocalLight *light;
    s32 unk_0;
    s32 unk_1; // Matching: unused local, needed for the match.
    s32 unk_2[3];
    s32 ambient[3];
    s32 unk_3; // Matching: unused local, needed for the match.
    if (!actor->active)
        return 0;
    _subaddiefade_entrypoint_9(actor, color);
    collector = func_80106C08();
    func_80106D60(actor, collector, color);
    light_count = func_800B3494(collector, center, func_80103F38(actor, center));
    func_800B37A4(collector, &light, &unk_0);
    if (light_count < (s32) actor->count && actor->special) {
        func_800C8960(ambient, unk_2);
        func_80106DA4(ambient, color);
        func_800B36C0(collector, unk_2, ambient, light_count ? light->radius : 500.0f);
    }
    return collector;
}

int func_80106D60(s32 actor, s32 collector, f32 color[3])
{
    f32 ambient[3];
    func_800C87B8(ambient);
    func_80106DA4(ambient, color);
    func_800B38A8(collector, ambient);
}

// Scales each channel of color by (scale / 256).
func_80106DA4(color, scale) s32 *color;
s32 *scale;
{
    s32 i;
    for (i = 0; i < 3; i++) {
        color[i] = color[i] * scale[i] >> 8;
    }
}
