// Actor message dispatch: sends a message to one actor, all actors, by type id, by radius or to
// prop-attached actors near a point, plus small global mailbox registers for replies.
#include "core2/1EDA900.h"

extern s32 D_80135A70;
extern float D_80135A7C;
typedef struct {
    u8 pad_0[0x74];
    u32 pad_74_0 : 3;
    u32 msg_enabled : 1;
    u32 pad_74_4 : 28;
} Actor108C;
extern s32 *func_80081D34(s32 *);
extern s32 func_80081D80(s32 *);
extern s32 *func_80100368(Actor *);
extern s32 func_800819B4(s32 *, s32);
extern Actor *func_80106790(Unk80132ED0 *);
extern Actor *func_801067C4();
extern f32 func_800EEB40(f32 *, f32 *);
typedef struct {
    Unk80132ED0 *prop;
    s32 unk_4;
    u32 flags;
} Entry1013;
extern void **func_800BE3F8(void);
extern void *func_800BDC44(void);
extern s32 func_800BDC5C(void);
extern Entry1013 *func_800E9E88();
extern Unk80132ED0 *D_80135A80;

// Mailbox registers (vec3, float, pointer): message handlers use them to return
// data to the sender.
int func_80101010(s32 vec)
{
    s32 vec_copy;
    // Matching: the | 0 copy is needed for the match.
    vec_copy = vec | 0;
    func_800EE7F8(&D_80135A70, vec_copy);
}

void func_80101038(s32 vec)
{
    func_800EE7F8(vec, &D_80135A70);
}

void func_8010105C(f32 value)
{
    D_80135A7C = value;
}

float func_80101068()
{
    return D_80135A7C;
}

void func_80101074(s32 value)
{
    D_80135A80 = value;
}

Unk80132ED0 *func_80101080()
{
    return D_80135A80;
}

// Calls the actor type's message handler (ActorInfo+0x40) with (msg, arg).
// Returns -1 when the actor does not accept messages.
s32 func_8010108C(Actor *actor, s32 msg, s32 arg)
{
    s32 *info;
    s32 result;
    s32 unk_0;
    s32 *ovl;

    if (((Actor108C *) actor)->msg_enabled) {
        ovl = func_80081D34(*(s32 **) ((char *) actor + 0x10));
        if (ovl != 0) {
            unk_0 = func_80081D80(ovl);
        } else {
            unk_0 = 0;
        }
        info = func_80100368(actor);
        result =
            (*(s32(**)(Actor *, s32, s32))((char *) info + 0x40))(actor, msg, arg);
        if (ovl != 0 && unk_0 == 0 && result <= 0) {
            func_800819B4(*(s32 **) ((char *) actor + 0x10), result);
        }
        return result;
    }
    return -1;
}

s32 func_8010114C(s32 prop, s32 msg, s32 arg)
{
    return func_8010108C(func_80106790((Unk80132ED0 *) prop), msg, arg);
}

// Sends msg to all actors with the given type id; returns the first positive reply.
s32 func_80101180(s32 actor_id, s32 msg, s32 arg)
{
    Actor *actor;
    s32 iter;
    s32 result = 0;
    s32 reply;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        if (!actor->unk64_17 && ((*(u32 *) ((u8 *) actor + 0x6C) << 11) >> 20) == actor_id) {
            reply = func_8010108C(actor, msg, arg);
            if (reply > 0 && !result)
                result = reply;
        }
    }
    return result;
}

// Sends msg to all actors; returns the first positive reply.
s32 func_80101238(s32 msg, s32 arg)
{
    Actor *actor;
    s32 iter;
    s32 result = 0;
    s32 reply;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        if (!actor->unk64_17) {
            reply = func_8010108C(actor, msg, arg);
            if (reply > 0 && !result)
                result = reply;
        }
    }
    return result;
}

// Sends msg to all actors within radius of pos; returns the first positive reply.
s32 func_801012D0(f32 *pos, f32 radius, s32 msg, s32 arg)
{
    Actor *actor;
    s32 iter;
    s32 result = 0;
    s32 reply;
    radius *= radius;
    for (actor = func_801067C4(&iter); actor; actor = func_8010682C(&iter)) {
        if (!actor->unk64_17 && func_800EEB40(actor->position, pos) < radius) {
            reply = func_8010108C(actor, msg, arg);
            if (reply > 0 && !result)
                result = reply;
        }
    }
    return result;
}

// Sends msg to prop-attached actors in the cubes around pos.
s32 func_801013A8(f32 *pos, s32 msg, s32 arg)
{
    Entry1013 *entry;
    Entry1013 *entry_end;
    s32 result;
    s32 reply;
    void **cubes;
    void *cube;
    Actor *actor;
    f32 dist_sq;
    Entry1013 *cube_end;
    Unk80132ED0 *prop;
    cubes = func_800BE3F8();
    result = 0;
    for (; *cubes; cubes++) {
        entry = func_800E9E88(*cubes);
        entry_end = func_800E9EB4(*cubes);
        for (; entry < entry_end; entry++) {
            if ((entry->flags & 1) &&
                (prop = entry->prop, *(u16 *) ((u8 *) prop + 0x18) & 1)) {
                reply = func_8010114C((s32) prop, msg, arg);
                if (reply > 0 && !result)
                    result = reply;
            }
        }
    }
    cube = func_800BDC44();
    entry = func_800E9E88(cube);
    cube_end = func_800E9EB4(cube);
    for (; entry < cube_end; entry++) {
        if ((entry->flags & 1) &&
            (prop = entry->prop, *(u16 *) ((u8 *) prop + 0x18) & 1)) {
            actor = func_80106790(prop);
            dist_sq = func_800EEB40(actor->position, pos);
            if (dist_sq < (1.5f * func_800BDC5C()) * (func_800BDC5C() * 1.5f)) {
                func_8010108C(actor, msg, arg);
                if (reply > 0 && !result)
                    result = reply;
            }
        }
    }
    return result;
}
