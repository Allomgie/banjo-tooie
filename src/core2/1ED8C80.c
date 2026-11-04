// Actor manager core loop: init/free/defrag of the actor sub-pools, the per-frame actor update,
// deferred actor deletion and per-actor heap local data and overlay unloading.
#include "core2/1ED8C80.h"

extern s32 D_80135A50;
typedef struct {
    u8 pad_0[0x28];
    void (*unk_28)(void *);
} O_FF3EC;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64 : 5;
    u32 teardown_done : 1;
    u32 pad_65 : 26;
} S_FF3EC;
extern int D_80127194;
extern void func_800EBFF4(s32);
typedef struct {
    u8 pad_0[0x24];
    u32 pad_24 : 16, x : 9, pad_26 : 7;
    u32 y : 9, z : 9, pad_28 : 14;
} MarkerFF62C;
typedef struct ActorFF62C {
    MarkerFF62C *marker;
    u8 pad_4[0x40];
    f32 pos[3];
    u8 pad_50[0x14];
    u32 pad_64 : 14, deleted : 1, pad_65 : 17;
    u8 pad_68[0xC];
    u32 pad_74 : 4, unk_74_4 : 1, pad_75 : 21, unk_74_26 : 1, unk_74_27 : 1, pad_77 : 4;
    u32 pad_78 : 14, fade : 2, pad_7A : 12, bounce : 1, pad_7B : 3;
    u8 pad_7C[0x10];
    s16 anim, floor_tint, glid, pad_92;
    u32 pad_94 : 2, unk_94_2 : 10, pad_95 : 20;
} ActorFF62C;
typedef struct {
    u8 pad_0[0xC];
    void (*unk_C)(ActorFF62C *);
    void (*unk_10)(ActorFF62C *);
} DataFF62C;
extern s32 func_800BEC1C(void);
extern s32 func_800DB9B0(void);
extern void func_8010D1E8(void);
extern void func_8010DF3C(void);
extern void func_800E3980(f32 *);
extern void func_8010D254(f32 *);
extern ActorFF62C *func_801067C4(s32 *);
extern ActorFF62C *func_8010682C(s32 *);
extern void func_801061D8(ActorFF62C *);
extern void _subaddiefade_entrypoint_7(ActorFF62C *);
extern void func_80106F70(ActorFF62C *);
extern void func_80104780(ActorFF62C *);
extern void _chbounce_entrypoint_8(ActorFF62C *);
extern void func_80103014(ActorFF62C *);
extern void _subaddiezone_entrypoint_0(ActorFF62C *);
extern void func_80103040(ActorFF62C *);
extern void *func_80104248(ActorFF62C *);
extern void func_8008ADE4(void *);
extern f32 func_800136E4(f32);
typedef struct {
    u8 pad_0[0x40];
    Unk80132ED0 *link;
    u8 pad_44[0x20];
    u32 pad_64 : 14;
    u32 deleted : 1;
    u32 pad_65 : 17;
    u32 unk_68;
    u32 unk_6C_0 : 11;
    u32 actor_id : 12;
    u32 unk_6C_23 : 9;
    u32 unk_70;
    u32 unk_74_0 : 7;
    u32 unk_74_7 : 1;
    u32 pad_75 : 24;
    u32 pad_78 : 29;
    u32 unk_78_29 : 1;
    u32 pad_7B : 2;
} local_type_800FFAB0;
typedef struct {
    u8 pad0[0x70];
    u8 pad70 : 7;
    u8 unk70_0 : 1;
    u8 unk71_7 : 1;
    u8 pad71 : 7;
    u8 pad72[0xA];
    u32 pad7C_0 : 19;
    u32 unk7C_19 : 1;
    u32 pad7C_20 : 12;
} S800FFC90;
extern u8 D_80124390[];
extern void *D_80124394;
extern void *func_801068A8(void **);
extern void **func_80106920(void **);
extern int func_800DC060(int);
extern void func_80106630(void);
extern void func_801041C8(void);
extern void func_801043A0(void);
extern void func_8010545C(void);
extern void func_80105CD0(void);
extern void func_80106A60(void);
extern void func_80106E50(void);
extern void func_80107C10(void);
typedef struct {
    u8 pad_0[0x82];
    s16 data_handle[1];
} ActorFFECC;
extern s32 func_8001B7B8();
extern u32 *func_8001B710();
extern s16 func_8001B668(s32, s32);
extern void func_8001B754();
extern void *func_8001B798(s16);
// Bit views of the actor flag words used by func_80100120.
typedef struct {
    u32 pre : 10;
    u32 init_done : 1;
    u32 post : 21;
} local_flags_a;
typedef struct {
    u32 pre : 28;
    u32 unk_70_28 : 1;
    u32 post : 3;
} local_flags_b;
typedef struct {
    u32 pre : 14;
    u32 deleted : 1;
    u32 post : 17;
} local_flags_c;
typedef struct {
    u8 unk_7E_0 : 1;
    u8 unk_7E_1 : 1;
    u8 post : 6;
} local_flags_d;
typedef struct {
    u8 pre : 2;
    u8 init_done : 1;
    u8 post : 5;
} local_flags_e;
typedef struct {
    u8 pad_0[0x34];
    void (*init)(Actor *);
} local_type_80100120;
extern s32 func_80102F74(Actor *, u32);
extern void func_8010381C(Actor *);
typedef struct {
    u8 pad_0[0x7C];
    u32 radius : 16;
    u32 initialized : 1;
    u32 active : 1;
    u32 pad_7E : 14;
} S_100230;
extern f32 func_800EEB40(void *, void *);
extern void func_800819B4(s32 *);
extern s32 func_80081D34(s32 *);
extern void _suautobaddies_entrypoint_1(void);
extern s32 func_800F54E4(void);
extern void func_800F5A00(s32, s32 *);
typedef struct {
    u8 pad_0[0x10];
    void *marker;
    u8 pad_14[0x50];
    u32 pad_64 : 14;
    u32 deleted : 1;
    u32 pad_65 : 17;
    u8 pad_68[0x10];
    u32 pad_78 : 26;
    u32 release : 1;
    u32 pad_7B : 5;
    u32 radius : 16;
    u32 initialized : 1;
    u32 active : 1;
    u32 unk_7C_18 : 1;
    u32 unk_7C_19 : 1;
    u32 pad_7E : 12;
} LocalActor;
extern s32 func_800EFFB4(void *, f32, f32 *);
extern void func_8010108C();
DataFF62C *func_80100368();
s32 func_8010038C();

// Initialises all actor sub-pools.
int func_800FF390()
{
    D_80135A50 = 0;
    func_801065E0();
    func_80104170();
    func_80104350();
    func_80105410();
    func_80105C20();
    func_80106A20();
    func_80106DF0();
    func_80107BB0();
}

void func_800FF3EC(actor) S_FF3EC *actor;
{
    O_FF3EC *info;

if (actor->teardown_done) {
    return;
}

info = func_80100368(actor);

if (info->unk_28 != 0) {
    info->unk_28(actor);
}

actor->teardown_done = 1;
}

// Broadcasts message 0x93 (teardown) to all actors, then finalises each.
void func_800FF44C(void)
{
    s32 iter;
    s32 actor;

    func_80101238(0x93, 0);
    actor = func_801067C4(&iter);

while (actor != 0) {
    func_800FF3EC(actor);
    actor = func_8010682C(&iter);
}

}

int func_800FF4A4(Actor *actor)
{
    u32 *marker;

    marker = *(u32 **) ((u8 *) actor + 0x0);
    func_8010381C(actor);
    func_80103938(actor);

if (*(s32 *) ((u8 *) actor + 0x7C) & 0xFFF) {
    func_800D8808((*(u32 *) ((u8 *) func_80105494(actor) + 0x24) << 23) >> 29);
    func_80105634(actor);
}

*(u16 *) ((u8 *) marker + 0x24) &= 0x3F;
func_80104328(actor);
_subaddieaudioloop_entrypoint_2(actor);
func_80104504(actor);

func_80106EE0(actor);
// Free the three local-data blocks.
{
    s32 i;

    for (i = 0; i < 3; i++) {
        func_80100074(actor, i, 0);
    }
}

}

// Tears down and frees all actors, then resets every actor sub-pool.
void func_800FF564(void)
{
    s32 iter;
    s32 *actor;

    func_80101238(0x93, 0);
    for (actor = func_801067C4(&iter); actor != NULL; actor = func_8010682C(&iter)) {
        func_800FF3EC(actor);
        func_800FF4A4(actor);

if (*actor != 0) {
    func_800EBFF4(*actor);
}

*actor = 0;
}
D_80135A50 = 0;
D_80127194 = 0;
func_801041A0();
func_80104378();
func_80105438();
func_80105C48();
func_80106608();
func_80106A28();
func_80106E18();
func_8010DF98();
}

// Per-frame actor update: info callbacks, then the components of each actor.
void func_800FF62C(void)
{
    s32 unk_0, unk_1;
    s32 iter;
    f32 ref_pos[3];
    s32 unk_2;
    MarkerFF62C *marker;
    DataFF62C *info;
    ActorFF62C *actor;
    unk_2 = func_800BEC1C();
    if (unk_2)
        unk_0 = 1;
    else
        unk_0 = 0;
    func_8010D1E8();
    if (func_800DB9B0())
        func_800E3980(ref_pos);
    else
        func_8010D254(ref_pos);
    for (actor = func_801067C4(&iter); actor != 0; actor = func_8010682C(&iter)) {
        marker = actor->marker;

// Skip deleted actors.
if (actor->deleted)
    continue;
{
    if (actor->unk_74_27) {
        if (func_8010038C(actor, ref_pos))
            func_80100368(actor)->unk_10(actor);
    } else {
        func_80100120((Actor *) actor);
        if (func_8010038C(actor, ref_pos)) {
            info = func_80100368(actor);
            if (info->unk_C)
                info->unk_C(actor);
        }
    }
    if (actor->anim && actor->unk_74_4)
        func_8008ADE4(func_80104248(actor));
    if (actor->glid)
        func_801061D8(actor);
    if (actor->fade)
        _subaddiefade_entrypoint_7(actor);
    if (actor->unk_94_2)
        func_80106F70(actor);
    if (actor->floor_tint)
        func_80104780(actor);
    if (actor->bounce) {
        _chbounce_entrypoint_8(actor);
        func_80103014(actor);
        if (unk_0)
            _subaddiezone_entrypoint_0(actor);
    } else if (!actor->unk_74_26) {
        func_80103014(actor);
        if (unk_0)
            _subaddiezone_entrypoint_0(actor);
    } else {
        marker->y = func_800136E4(actor->pos[1]);
        marker->x = func_800136E4(actor->pos[0]);
        marker->z = func_800136E4(actor->pos[2]);
    }
    func_80103040(actor);
}

}
func_8010DF3C();
}

// Final removal of one deleted actor.
int func_800FFA3C(s32 actor[3])
{
    s32 marker;
    // Matching: the always-true if is needed for the match.
    if (1) {
        marker = actor[0];
    }
    func_800FF3EC();
    func_800FF4A4(actor);
    func_801066C0(((u32) (*((u16 *) (marker + 0x1A)))) >> 5);
    func_800EBFF4(marker);
}

void func_800FFA88(Unk80132ED0 *link)
{
    func_800FFAB0(func_80106790(link));
}

// Marks the actor and its linked actor as deleted; func_800FFB74 sweeps them.
void func_800FFAB0(Actor *actor)
{
    local_type_800FFAB0 *linked;
    ((local_type_800FFAB0 *) actor)->deleted = 1;
    D_80135A50++;
    if (((local_type_800FFAB0 *) actor)->link &&
        ((local_type_800FFAB0 *) actor)->actor_id != 0x243) {
        linked = (local_type_800FFAB0 *) func_80106790(((local_type_800FFAB0 *) actor)->link);
        linked->deleted = 1;
        ((local_type_800FFAB0 *) actor)->link = 0;
        linked->link = 0;
        D_80135A50++;
    }
    ((local_type_800FFAB0 *) actor)->unk_78_29 = 0;
    ((local_type_800FFAB0 *) actor)->unk_74_7 = ((local_type_800FFAB0 *) actor)->unk_78_29;
}

// Removes all actors marked as deleted.
void func_800FFB74()
{
    typedef struct {
        u32 pad_0[0x19];
        u32 pad_64_18 : 14;
        u32 deleted : 1;
    } Struct800FFB74;
    s32 iter;
    u8 *actor;
    if (D_80135A50 > 0) {
        // Matching: the iterator state is passed as &iter - 1.
        actor = func_801067C4((&iter) - 1);

if (actor != 0) {
    do {
        if (((Struct800FFB74 *) actor)->deleted != 0) {
            func_800FFA3C(actor);
        }
        actor = func_8010682C(&iter - 1);
    } while (actor != 0);
}

D_80135A50 = 0;
}
}

void func_800FFBE4(void)
{
}

void func_800FFC3C();

void func_800FFBEC()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC14()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC3C()
{
    void *actor;
    s32 iter;
    actor = func_801067C4(&iter);
    while (actor != 0) {
        ((u8 *) actor)[0x7E] &= 0xFFEF;
        actor = func_8010682C(&iter);

}
}

void func_800FFC90(void)
{
    S800FFC90 *actor;
    s32 iter;
    actor = func_801067C4(&iter);
    if (actor) {
        do {
            if (actor->unk7C_19 && actor->unk70_0) {
                actor->unk71_7 ^= 1;
            }
            actor = func_8010682C(&iter);
        }

while (actor != 0)
    ;
}
}

void func_800FFD10(s32 param_0)
{
    typedef struct {
        u32 pad_0[0x1C];
        u32 pad_70_4 : 28;
        u32 unk_70_28 : 1;
    } Struct800FFD10;
    s32 remaining;
    u8 *entry_copy;
    u8 *entry;
    if (param_0 == 1) {
        remaining = 0xA;
    } else {
        remaining = func_80106730();

}
entry = func_801068A8(&D_80124390);
// Matching: entry_copy duplicates entry, needed for the match.
entry_copy = entry;
if ((entry != 0) && (remaining > 0)) {
loop_5:
    if (((Struct800FFD10 *) entry)->unk_70_28 != 0) {
        if (func_80103AC0(entry_copy) == 0) {
            func_8010381C(entry_copy);
        }
    }

entry = func_80106920(&D_80124390);
entry_copy = entry;
remaining -= 1;

if ((entry != 0) && (remaining > 0)) {
    goto loop_5;
}
}

}

void func_800FFDBC()
{
    s32 actor;
    s32 iter;
    actor = func_801067C4(&iter);

while (actor != 0) {
    func_8010381C(actor);
    actor = func_8010682C(&iter);
}

}

// Defragments all actor sub-pools.
void func_800FFE08()
{
    void **entry;
    void *block;
    int data;
    int count;
    count = 0;
    entry = func_801068A8(&D_80124394);

if (entry != 0) {
    do {
        block = *entry;
        data = *(int *) ((char *) block + 4);
        if (data != 0) {
            *(int *) ((char *) block + 4) = func_800DC060(data);
        }
        // Matching: empty block needed for the match.
        if (0) {
        }
        entry = func_80106920(&D_80124394);
        count += 1;
    } while ((entry != 0) && (count != 8));
}

func_80106630();
func_801041C8();
func_801043A0();
func_8010545C();
func_80105CD0();
func_80106A60();
func_80106E50();
func_80107C10();
}

// Resizes local-data block `slot` of the actor to `size` bytes, allocating it if
// missing; size 0 frees it. New memory is zeroed. Returns the block or NULL.
u32 *func_800FFECC(ActorFFECC *actor, s32 slot, s32 size)
{
    u32 *data;
    s32 aligned_size;
    s32 i, j;
    s32 old_size;

if (size) {
    aligned_size = (size + 3) & 0x7FFFFFFC;
    if (actor->data_handle[slot]) {
        old_size = func_8001B7B8(actor->data_handle[slot]);
        data = func_8001B710(actor->data_handle[slot], aligned_size);
        if (old_size < aligned_size) {
            for (i = (aligned_size >> 2) - 1; i >= (old_size >> 2); i--) {
                data[i] = 0;
            }
        }
    } else {
        actor->data_handle[slot] = func_8001B668(4, aligned_size);
        data = func_8001B798(actor->data_handle[slot]);
        for (i = (aligned_size >> 2) - 1; i >= 0; i--) {
            data[i] = 0;
        }
    }
} else if (actor->data_handle[slot]) {

func_8001B754(actor->data_handle[slot]);
actor->data_handle[slot] = 0;
}
if (actor->data_handle[slot])
    return func_8001B798(actor->data_handle[slot]);
return 0;
}

u32 *func_80100074(Actor *actor, u32 slot, u32 size)
{
    return func_800FFECC(actor, slot, size);
}

// Returns local-data block `slot` of the actor, or NULL.
void *func_80100094(Actor *actor, u32 slot)
{
    void *rv = 0;
    s16 handle = *(s16 *) ((u8 *) actor + 0x82 + slot * 2);
    if (handle != 0) {
        return func_8001B798(handle);
    }
    return rv;

}

// Returns local-data block `slot`, allocating it with `size` bytes if missing.
s32 func_801000D8(Actor *actor, s32 slot, s32 size)
{
    if (!func_80100094(actor, slot)) {
        func_80100074(actor, slot, size);
    }

return func_80100094(actor, slot);
}

// Runs the actor type's init callback once.
void func_80100120(actor) Actor *actor;
{
    void (*init)(Actor *);

if (!((local_flags_a *) ((u8 *) actor + 0x74))->init_done) {
    init = ((local_type_80100120 *) func_80100368(actor))->init;
    if (init) {
        if (((local_flags_b *) ((u8 *) actor + 0x70))->unk_70_28 &&
            func_80102F74(actor, 0x80080000))
            func_8010381C(actor);
        init(actor);
        if (((local_flags_c *) ((u8 *) actor + 0x64))->deleted) {
            ((local_flags_d *) ((u8 *) actor + 0x7E))->unk_7E_0 = 1;
            ((local_flags_d *) ((u8 *) actor + 0x7E))->unk_7E_1 = 0;
        }
    }
    ((local_flags_e *) ((u8 *) actor + 0x75))->init_done = 1;
}

}

// Runs the one-time init of every actor, then sweeps deleted actors.
void func_801001D8()
{
    s32 iter;
    s32 actor;
    func_8010D1E8();
    actor = func_801067C4(&iter);

while (actor != 0) {
    func_80100120(actor);
    actor = func_8010682C(&iter);
}

func_800FFB74();

}

s32 func_80100230(S_100230 *actor, void *ref_pos)
{
    if (!actor->active) {
        return 0;
    }

if (actor->radius == 0) {
    return 1;
}

return (f32) (s32) (actor->radius * actor->radius) < func_800EEB40(ref_pos, (u8 *) actor + 4);
}

// Unloads the code overlays of out-of-range actors.
void func_801002C0()
{
    s32 actor;
    s32 iter;
    s32 ref_pos[3];
    func_801001D8();
    _suautobaddies_entrypoint_1();
    func_800FFB74();
    func_800F5A00(func_800F54E4(), ref_pos);
    // Matching: the iterator state is passed as &iter + 1.
    actor = func_801067C4(&iter + 1);

while (actor != 0) {
    if (func_80100230(actor, &ref_pos) && func_80081D34(*(s32 **) (actor + 0x10))) {
        func_800819B4(*(s32 **) (actor + 0x10));
    }
    actor = func_8010682C(&iter + 1);
}

}

// Matching: there is no return statement; the callee's v0 passes through.
DataFF62C *func_80100368(actor) void *actor;
{
    (*(s32(**)())((u8 *) actor + 0x10))();

}

// Sends message 0x95 on first activation. Returns whether the actor is active
// and within its radius of ref_pos.
s32 func_8010038C(actor, ref_pos)
LocalActor *actor;
f32 *ref_pos;
{
    if (!actor->initialized) {
        actor->initialized = 1;
        func_8010108C(actor, 0x95, 0);
        if (actor->deleted)
            return 0;
        if (actor->release)
            func_80081D34(actor->marker);
    }

if (!actor->active)
    return 0;
if (!actor->radius)
    return 1;
if (actor->unk_7C_18 && actor->unk_7C_19)
    return 1;
return func_800EFFB4((u8 *) actor + 4, (f32) (s32) actor->radius, ref_pos);
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
u8 D_80124390[4] = {0x0, 0x0, 0x0, 0x0};
void *D_80124394 = 0;
