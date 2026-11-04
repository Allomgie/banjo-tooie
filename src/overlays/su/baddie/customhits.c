// Probably custom hit volumes for actors: marks an actor as using model-based hit detection and
// tests spheres against it, with the result cached per frame, and gives the hit centre and radius.
#include "common.h"

extern void func_800EC358(Unk80132ED0 *, void *);
extern int D_80800350_subaddiecustomhits[];
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *func_80106790(void);
extern s32 func_800B1F8C(s32, f32 *, s32, f32, s32, s32, f32 *, f32, s32, s32);
extern u8 *func_80104124(void);
extern void func_80103DFC(Actor *, f32 *);
extern s32 func_800EFFB4(f32 *, f32, void *);
typedef struct {
    f32 position[3];
    f32 radius;
    s32 id;
    s32 tick;
} CustomHitSnapshot;
typedef struct {
    u8 pad_0[0x12];
    u16 id : 15;
    u16 pad_1 : 1;
} CustomHitMarker;
extern f32 func_80103F38(Actor *, f32 *);
typedef struct {
    u8 pad_0[8];
    u32 pad_1 : 30;
    u32 custom : 1;
    u32 pad_2 : 1;
} CustomHitFlags;
extern f32 func_800EC75C(Unk80132ED0 *, f32 *);

// Mark the actor as using model-based hit detection.
void subaddiecustomhits_entrypoint_0(Actor *actor, void *unk_0)
{
    func_800EC358(actor->unk0, unk_0);
    actor->pad74_31 = 1;
}

int *subaddiecustomhits_entrypoint_1()
{
    return &D_80800350_subaddiecustomhits;
}

// Test a sphere against the actor's model collision; the result is cached for the frame.
s32 subaddiecustomhits_entrypoint_2(Unk80132ED0 *obj, f32 *center, f32 radius, s32 unk_0,
                                    s32 unk_1)
{
    Actor *actor;
    s32 model;
    s32 collision;
    s32 hit;
    s32 anim;
    u8 *cache;

    actor = func_80106790();
    model = func_80103AA0(obj);
    anim = func_801040A8(actor);
    if (!model || !func_800AE0B8(anim)) {
        return 0;
    }
    collision = func_800B2824(model);
    if (actor->scale == 0.0f) {
        hit = 0;
    } else {
        hit = func_800B1F8C(collision, actor->position, func_801027F4(actor), actor->scale,
                            0, anim, center, radius, unk_0, unk_1);
    }
    if (hit) {
        cache = func_80104124();
        func_800EE7F8(cache, center);
        *(f32 *) (cache + 0xC) = radius;
        *(u32 *) (cache + 0x10) = (u32) *(u16 *) ((u8 *) obj + 0x12) >> 1;
        *(s32 *) (cache + 0x14) = func_8001211C();
    }
    return hit;
}

// Sphere vs. actor radius test.
s32 subaddiecustomhits_entrypoint_3(Actor *actor, void *unk_0, f32 margin)
{
    f32 center[3];
    func_80103DFC(actor, center);
    return !func_800EFFB4(
        center, (f32) (u32) *(u16 *) ((u8 *) actor + 0x6A) * actor->scale + margin, unk_0);
}

// Get the hit centre and radius: the cached custom hit, else the default actor sphere.
s32 subaddiecustomhits_entrypoint_4(Actor *actor, f32 *out_center, f32 *out_radius)
{
    CustomHitSnapshot *cache;
    f32 radius;
    cache = (CustomHitSnapshot *) func_80104124();
    if (cache->id == ((CustomHitMarker *) actor->unk0)->id &&
        func_8001211C() == cache->tick) {
        func_800EE7F8(out_center, cache->position);
        if (out_radius != NULL)
            *out_radius = cache->radius;
        return 1;
    }
    radius = func_80103F38(actor, out_center);
    if (out_radius != NULL)
        *out_radius = radius;
    return 0;
}

// Hit centre and radius: custom hit if set, else the actor sphere * 1.15.
f32 subaddiecustomhits_entrypoint_5(Actor *actor, f32 *out_center)
{
    if (!((CustomHitFlags *) actor->unk0->unk0)->custom)
        return func_800EC75C(actor->unk0, out_center);
    func_80103328(actor);
    func_800EE7F8(out_center, actor->position);
    return (f32) (u32) *(u16 *) ((u8 *) actor + 0x6A) * actor->scale * 1.15f;
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM); the extern of
// D_80800350_subaddiecustomhits is declared as int[] to match the object.
extern void _subaddiecustomhits_entrypoint_2();
int D_80800350_subaddiecustomhits[4] = {0x0, 0x0, 0x0, (u32) _subaddiecustomhits_entrypoint_2};
