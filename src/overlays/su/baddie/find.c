#include "common.h"
// TU-NOTE: the .data of this overlay is defined here in C; values come from the ROM.

extern Actor *func_801067C4(s32 *);
extern Actor *func_8010682C(s32 *);
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct ActorSearchProp {
    Unk80132ED0 *marker;
    u32 pad_0;
    u32 flags;
} ActorSearchProp;
extern Actor **func_8010413C(void);
extern void **func_800BE3F8(f32 *);
extern void *func_800E9E88(void *);
extern void *func_800E9EB4(void *);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800EEAD4(f32 *, f32 *);
Actor *subaddiefind_entrypoint_11();

// Nearest live actor of a kind (kind < 0 = any) to a point; writes the distance.
Actor *subaddiefind_entrypoint_0(f32 *pos, s32 kind, s32 exclude, f32 *out_dist)
{
    f32 dist_sq;
    f32 best_dist_sq;
    s32 found;
    Actor *best;
    s32 iter;
    Actor *actor;

    best_dist_sq = 0.0f;
    best = NULL;
    found = 0;
    actor = func_801067C4(&iter);
    while (actor) {
        if ((kind == actor->unk6C_9 || kind < 0) && exclude != actor->unk70_10 &&
            actor->unk6C_9 != 0x215 && actor->unk6C_9 != 0x243 && !actor->unk64_17) {
            dist_sq = func_800EEB40(pos, actor->position);
            if (dist_sq < best_dist_sq || !found) {
                best_dist_sq = dist_sq;
                best = actor;
                found = 1;
            }
        }
        actor = func_8010682C(&iter);
    }
    if (out_dist) {
        *out_dist = sqrtf(best_dist_sq);
    }
    return best;
}

// Nearest live actor of a kind to another actor, skipping actors sharing its marker.
Actor *subaddiefind_entrypoint_1(Actor *from, s32 kind, s32 exclude, f32 *out_dist)
{
    f32 best_dist;
    Actor *best;
    Actor *actor;
    s32 iter;

    best = 0;
    best_dist = 1e10f;
    actor = func_801067C4(&iter);
    while (actor) {
        if ((kind == actor->unk6C_9 || kind < 0) && exclude != actor->unk70_10 &&
            actor->unk6C_9 != 0x215 && actor->unk6C_9 != 0x243 && !actor->unk64_17 &&
            actor->unk0 != from->unk0) {
            f32 dist = func_800EEAD4(from->position, actor->position);
            if (dist < best_dist) {
                best_dist = dist;
                best = actor;
            }
        }
        actor = func_8010682C(&iter);
    }
    if (out_dist) {
        *out_dist = best_dist;
    }
    return best;
}

// First live actor of a kind; optionally writes the iterator state.
Actor *subaddiefind_entrypoint_2(s32 kind, s32 *out_iter)
{
    Actor *actor;
    s32 iter;

    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        if (kind == actor->unk6C_9 && !actor->unk64_17) {
            if (out_iter != NULL) {
                *out_iter = iter;
            }
            return actor;
        }
    }
    return NULL;
}

// Continues an iteration to the next live actor with a matching id.
// Matching: needed for the match.
u8 *subaddiefind_entrypoint_3(s32 id, s32 iter)
{
    Actor *actor;
    Actor *result;
    actor = func_8010682C(iter);
    result = actor;
    if (actor != NULL) {
    loop_1:
        if ((id == ((u32) (*(s32 *) ((u8 *) actor + 0x6C) << 11) >> 20)) &&
            !actor->unk64_17) {
            return (u8 *) result;
        }
        actor = func_8010682C(iter);
        result = actor;
        if (actor == NULL)
            goto block_5;
        goto loop_1;
    }
block_5:
    return NULL;
}

// Collects up to max_count live actors of a kind into out.
s32 subaddiefind_entrypoint_4(s32 kind, Actor **out, s32 max_count)
{
    Actor *actor;
    s32 iter;
    s32 count;

    count = 0;

    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        if (kind == actor->unk6C_9 && !actor->unk64_17) {
            count++;
            *out++ = actor;
            if (count == max_count) {
                return count;
            }
        }
    }
    return count;
}

// Like entry 4, but only actors within radius of center by dist_fn.
s32 subaddiefind_entrypoint_5(s32 kind, Actor **out, s32 max_count, f32 *center, f32 radius,
                              f32 (*dist_fn)(f32 *, f32 *))
{
    Actor *actor;
    s32 iter;
    s32 count = 0;

    radius *= radius;
    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        if (actor->unk6C_9 == kind && !actor->unk64_17 &&
            dist_fn(center, actor->position) < radius) {
            *out++ = actor;
            count++;
            if (count == max_count) {
                return count;
            }
        }
    }
    return count;
}

// Collects live actors whose kind is in the -1-terminated list.
s32 subaddiefind_entrypoint_6(s16 *kinds, Actor **out, s32 max_count)
{
    s32 count;
    Actor *actor;
    s32 iter;
    s16 *kind;

    count = 0;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        if (!actor->unk64_17) {
            for (kind = kinds; *kind != -1; kind++) {
                if (actor->unk6C_9 == *kind) {
                    count++;
                    *out++ = actor;
                    if (count == max_count)
                        return count;
                }
            }
        }
    }
    return count;
}

// Targets the nearest actor of a kind within max_dist; returns the distance or -1.
s32 subaddiefind_entrypoint_7(Actor *actor, s32 kind, s32 max_dist)
{
    f32 dist;
    Actor *nearest;
    nearest = subaddiefind_entrypoint_0(actor->position, kind, -1, &dist);
    if (nearest && dist < max_dist)
        actor->unk3C = nearest->unk0;
    else
        actor->unk3C = NULL;
    return actor->unk3C ? dist : -1.0f;
}

// Finds a live actor by marker id.
Actor *subaddiefind_entrypoint_8(s32 marker_id)
{
    Actor *actor;
    s32 iter;

    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        if (marker_id == ((u32) *(u16 *) ((u8 *) actor->unk0 + 0x12) >> 1) && !actor->unk64_17) {
            return actor;
        }
    }
    return NULL;
}

// Counts live actors of a kind.
s32 subaddiefind_entrypoint_9(s32 kind)
{
    Actor *actor;
    s32 count = 0;
    s32 iter;

    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        if (kind == actor->unk6C_9 && !actor->unk64_17) {
            count++;
        }
    }
    return count;
}

// Links the actor to the first instance of a kind with the given id.
s32 subaddiefind_entrypoint_10(u8 *actor, s32 kind, s32 id)
{
    s32 *found = subaddiefind_entrypoint_11(kind, id);
    if (found != NULL) {
        *(s32 *) (actor + 0x3C) = *found;
    } else {
        *(s32 *) (actor + 0x3C) = 0;
    }
    return (*(s32 *) (actor + 0x3C) != 0) ? 1 : 0;
}

// Finds a live actor of a kind by instance id.
Actor *subaddiefind_entrypoint_11(kind, id)
s32 kind;
s32 id;
{
    Actor *actors[20];
    s32 count;
    s32 i;

    count = subaddiefind_entrypoint_4(kind, actors, 20);
    for (i = 0; i < count; i++) {
        if (actors[i]->unk74_7 == id) {
            return actors[i];
        }
    }
    return NULL;
}

// Finds a live actor by unique id.
Actor *subaddiefind_entrypoint_12(s32 unique_id)
{
    Actor *actor;
    s32 iter;

    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        if (!actor->unk64_17 && unique_id == (*(u32 *) ((u8 *) actor + 0x6C) >> 21)) {
            return actor;
        }
    }
    return NULL;
}

// Collects all live actors in the cube cells around a point (NULL-terminated).
Actor **subaddiefind_entrypoint_13(f32 *pos)
{
    ActorSearchProp *entry;
    s32 count;
    ActorSearchProp *end;
    Actor **list;
    void **cell;
    Actor *actor;

    list = func_8010413C();
    count = 0;
    for (cell = func_800BE3F8(pos); *cell; cell++) {
        entry = func_800E9E88(*cell);
        end = func_800E9EB4(*cell);
        for (; entry < end; entry++) {
            if ((entry->flags & 1) && (*(u16 *) ((u8 *) entry->marker + 0x18) & 1)) {
                actor = func_80106790(entry->marker);
                if (!actor->unk64_17) {
                    list[count++] = actor;
                }
            }
        }
    }
    list[count] = NULL;
    return list;
}
