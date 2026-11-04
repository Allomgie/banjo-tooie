#include "common.h"

extern void *func_801040A8(Actor *);
extern void *func_800B27E0(void *);
extern s32 func_800AE630(void *, void *, s32, f32 *);
extern s32 _dbskeleton_entrypoint_2(void *, s32, f32 *);
extern void func_800EF334(f32 *, f32);
extern void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
extern Actor *func_80106790();
extern int func_80102F74(Actor *, s32);
extern void *func_80104130(void);
void *subaddieskeleton_entrypoint_4();

// World position of a bone: animated pose if present, else bind pose; scaled and rotated by the actor.
s32 subaddieskeleton_entrypoint_0(Actor *actor, s32 bone, f32 *out_pos)
{
    f32 bone_pos[3];
    void *anim;
    anim = func_801040A8(actor);
    if (func_800AE0D0(anim)) {
        if (func_800AE630(anim, func_800B27E0(func_801039E4(actor->unk0)), bone, bone_pos)) {
            func_800EF334(bone_pos, actor->scale);
            func_800EF5A0(bone_pos, actor->rotation, bone_pos[0], bone_pos[1], bone_pos[2]);
            func_800EE780(out_pos, bone_pos, actor->position);
            return 1;
        }
    } else if (_dbskeleton_entrypoint_2(func_800B27E0(func_801039E4(actor->unk0)), bone,
                                        bone_pos)) {
        func_800EF334(bone_pos, actor->scale);
        func_800EF5A0(bone_pos, actor->rotation, bone_pos[0], bone_pos[1], bone_pos[2]);
        func_800EE780(out_pos, bone_pos, actor->position);
        return 1;
    }
    return 0;
}

void subaddieskeleton_entrypoint_1(u8 **inst)
{
    func_800DBEFC(*(s32 *) ((s8 *) *inst + 4));
}

// Bone matrix from the actor's bone cache.
int subaddieskeleton_entrypoint_2(Unk80132ED0 *obj, s32 bone, s32 out)
{
    Actor *actor;
    void *bone_cache;
    actor = func_80106790(obj);
    if (actor->unk7C_12) {
        bone_cache = subaddieskeleton_entrypoint_4(actor);
        if (bone_cache) {
            func_800DBEFC(bone_cache, bone, out);
            return 1;
        }
    }
    return 0;
}

// Like entrypoint_2, but falls back to the actor position.
int subaddieskeleton_entrypoint_3(Unk80132ED0 *obj, s32 bone, f32 *out_pos)
{
    Actor *actor;
    void *bone_cache;

    actor = func_80106790(obj);
    if (actor->unk7C_12) {
        bone_cache = subaddieskeleton_entrypoint_4(actor);
        if (bone_cache) {
            func_800DBEFC(bone_cache, bone, out_pos);
            return 1;
        }
    }
    func_800EE7F8(out_pos, actor->position);
    return 0;
}

// Skeleton/bone cache of the actor, or NULL.
void *subaddieskeleton_entrypoint_4(actor)
Actor *actor;
{
    void *cache;

    cache = actor->unk0->unk4;
    if (cache) {
        return cache;
    }
    cache = func_80102F74(actor, 2) ? func_80104130() : NULL;
    return cache;
}

// TU-NOTE: the .data of this overlay is defined in C; values are taken from the ROM.
