// Most likely the core in-game world driver: world draw pass, per-frame world update, map getters,
// gsworld DLL wrappers, carrying the player on moving actors, and per-cube prop collision queries.
#include "core2/1EC3810.h"

extern s16 D_80132DCC;
extern int D_80127EF4;
extern s32 D_80132DC4;
extern void _gcsectionDll_entrypoint_3();
extern s16 D_80132DC8;
extern s16 D_80132DCA;
extern s32 D_80127EF8;
extern s32 D_80127EF0;
extern u16 D_80132DCE;
extern int D_80132DD8[];
extern int D_80132E78[];
extern u8 D_80132DD0[];
extern void func_800EE7F8(s32 *, s32);
typedef struct {
    f32 position[3];
    void *marker;
    s32 argument;
} LocalDraw;
// TU-NOTE: D_80132DD0 is accessed as LocalState: hit callback and argument, then 8 carry
// slots of 0x14 bytes. D_80132DD8 is the slot array and D_80132E78 its end.
typedef struct {
    s32 callback, arg;
    LocalDraw entries[8];
} LocalState;
extern void *func_80103C94(Actor *);
extern void func_800F5A00(s32, f32 *);
extern void func_800D8B80(s32, s32, void *, void *, f32, s32, s32, void *, void *);
extern void func_800F8418(s32, f32 *);
extern s32 func_800D89C8(s16, s32, f32 *, f32 *, f32, f32 *, void *, f32 *, f32 *);
typedef struct MarkerEA MarkerEA;
typedef struct {
    s32 (*callback)(MarkerEA *, s32 *, s32 *, f32 *, s32);
} HandlerEA_800EA628;
// Prop list entry: either an actor marker or a static model prop.
typedef union {
    struct {
        MarkerEA *marker;
        s32 pad4;
        u32 pad8 : 27;
        u32 active : 1;
        u32 unk_8_3 : 1;
        u32 pad : 1;
        u32 unk_8_1 : 1;
        u32 is_actor : 1;
    } actor_view;
    struct {
        u16 pad;
        u8 rot[2];
        s16 pos[3];
        u8 scale;
        u8 padB;
    } prop_view;
} EntryEA;
typedef struct {
    u32 pad;
    f32 position[3];
    u8 pad10[0x28];
    f32 scale;
    u8 pad3C[8];
    f32 rotation[3];
    u8 pad50[0x14];
    u32 pad64 : 14;
    u32 unk_64 : 1;
    u32 pad64a : 17;
    u16 pad68;
    u16 radius;
    u8 pad6C[0x14];
    u16 unk_80;
} ActorEA_800EA628;
extern EntryEA *func_800E9E88(void *);
extern EntryEA *func_800E9EB4(void *);
extern s32 _gsproplookup_entrypoint_0(EntryEA *);
extern void *func_800BFC54(s32);
extern void *func_800B2720(void *);
extern void *func_800B2840(void *);
extern s32 func_800AD1AC(void *, void *, f32 *, f32 *, f32, f32 *, f32, f32 *, s32);
extern ActorEA_800EA628 *func_80106790();
extern void func_80103508(ActorEA_800EA628 *);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void *func_80103AA0(MarkerEA *);
extern void *func_80103CDC(ActorEA_800EA628 *, void *);
extern void func_800D62E4(u16);
extern void *func_800BFC34(s32);
extern void func_800BFC74(s32);
extern f32 func_800B2354(void *);
extern s32 func_800AAEF4(f32 *, f32, s32 *, s32 *);
extern s32 func_800AB868(void *, void *, f32 *, f32 *, f32, s32 *, s32 *, f32 *, s32);
extern s32 D_80132DD4;
extern void func_801039E4(MarkerEA *);
typedef struct {
    u8 pad[4];
    s32 (*callback)(MarkerEA *, f32 *, f32 *, f32, f32 *, s32, s32);
} HandlerEA_800EAA2C;
typedef struct {
    u32 pad;
    f32 position[3];
    u8 pad10[0x28];
    f32 scale;
    u8 pad3C[8];
    f32 rotation[3];
    u8 pad50[0x14];
    u32 pad64 : 14;
    u32 unk_64 : 1;
    u32 pad64a : 17;
    u16 pad68;
    u16 radius;
} ActorEA_800EAA2C;
extern s32 func_800AC848(void *, void *, f32 *, f32 *, f32, f32 *, f32 *, f32, f32 *, s32, s32);
extern s32 func_800CB854(s32);
typedef struct {
    u8 pad[8];
    s32 (*callback)(MarkerEA *, f32 *, f32, f32 *, s32);
} HandlerEA_800EADFC;
typedef struct {
    u32 pad;
    f32 position[3];
    u8 pad10[0x28];
    f32 scale;
    u8 pad3C[8];
    f32 rotation[3];
    u8 pad50[0x14];
    u32 pad64 : 14;
    u32 unk_64 : 1;
    u32 pad64a : 17;
    u16 pad68;
    u16 radius;
} ActorEA_800EADFC;
typedef struct {
    u8 pad0[0xC];
    void (*unkC)(void *, s32, s32);
} O_EB2DC;
typedef struct {
    u8 pad0[0x28];
    u32 f0 : 22;
    u32 flag : 1;
    u32 rest : 9;
} S_EB2DC;
extern O_EB2DC *func_800EC3C4(S_EB2DC *);
typedef struct {
    u8 pad0[0x38];
    f32 scale;
    u8 pad3C[0x2E];
    u16 radius;
} S_EB350;
extern void func_80103328();
s32 func_800EB350();

extern u16 D_80132DC2;
extern s32 D_80132DC0;

// Group: world draw pass ordering (projection, sky, cubes, actors, layers, fade).
// World draw pass: projection, environment, props, actors and layers, then fade.
int func_800E9F20(s32 param_0, s32 param_1)
{
    u32 gfx;
    gfx = func_800A7180();
    if (D_80132DCC == 0) {
        func_800E44FC(gfx);
        return;
    }
    func_800BE9B0();
    func_800BFD6C(gfx, param_0);
    func_800E44FC(gfx);
    func_800D2A44(gfx);
    func_800BC8F8(gfx);
    func_800BE9E4(gfx);
    func_800BD594(gfx);
    func_800EB51C(1, gfx);
    func_800EB51C(5, gfx);
    func_800F5008(gfx);
    func_800EB51C(0, gfx);
    func_800B525C(gfx);
    if (func_800BF3E4() != 0) {
        func_800BEA24(gfx);
    }
    func_800B7BB0();
    func_800F50D0(gfx);
    func_800EB51C(2, gfx);
    func_800B52EC(gfx);
    func_800BC948(gfx);
    func_800EB51C(6, gfx);
    if (D_80127EF4 != 0) {
        _sufade_entrypoint_1(gfx);
    }
    func_800A8EF0(gfx, param_0);
    func_800F51CC();
}

// Group: map id and section queries, gsworld DLL wrappers, per-frame update, update/draw flags.
// Get World Section
MapId func_800EA05C(void)
{
    return D_80132DC2;
}

s32 func_800EA068(s32 flag)
{
    // Matching: needed for the match.
    s32 flag_copy = flag;
    _gcsectionDll_entrypoint_3(D_80132DC4, flag_copy);
}

s32 func_800EA090()
{
    return D_80132DC8;
}

int func_800EA09C()
{
    return *(s16 *) &D_80132DC0;
}

void func_800EA0A8()
{
    _gsworldDll_entrypoint_1(&D_80132DC0);
}

void func_800EA0CC(s32 param_0, s32 param_1, s32 param_2)
{
    _cothemedll_entrypoint_0();
    func_800DBB5C();
    func_800BF8BC(param_0);
    func_800C0064(param_0);
    _gsworldDll_entrypoint_2((int *) &D_80132DC0, param_0, param_1, param_2);
}

void func_800EA124()
{
    _gsworldDll_entrypoint_4(&D_80132DC0);
}

int func_800EA148(s32 param_0)
{
    s32 arg;
    // Matching: the "| 0" is needed for the match.
    arg = param_0 | 0;
    _gsworldDll_entrypoint_3((s32 *) &D_80132DC0, arg);
}

// World tick: runs the per-frame update of all world subsystems.
s32 func_800EA170()
{
    func_800C718C();
    func_800D8744();
    func_800FA2C0();
    if (func_800A8184() != 4) {
        func_800B7E38();
    }
    if (D_80132DCA == 0) {
        return 1;
    }
    func_800FFBE4();
    func_800EE718();
    if (D_80127EF8 != 0) {
        _idworld_entrypoint_5();
    }
    func_800E97C0();
    func_8010D7EC();
    func_800EE748();
    func_800F84FC();
    func_800BF710();
    func_800B592C();
    func_8008B850();
    func_800E1804();
    func_800A8E9C();
    func_800CF264();
    func_800CE628();
    func_800D2574();
    if (func_800EA09C() == 2) {
        func_800A1450();
        func_800DAE9C();
    }
    func_800C57F0();
    if (D_80127EF0 != 0) {
        _sulights_entrypoint_9();
    }
    func_800BFCC4(1);
    func_8001B50C();
    func_800D6E54(1);
    func_800ABA9C();
    func_800BFF70();
    func_800B50F0();
    func_800DBC68();
    func_800E8A68();
    func_800D5270();
    func_800C0438();
    func_800FFD10(1);
    func_800C7494();
    func_80100534();
    func_80100C74();
    func_800FFBEC();
    func_800BF7E0();
    func_800C8A08();
    func_800D154C();
    return 1;
}

// Set update enable flag.
void func_800EA334(s32 enabled)
{
    D_80132DCA = (s16) enabled;
}

// Get update enable flag.
int func_800EA340()
{
    return D_80132DCA;
}

// Set draw enable flag.
void func_800EA34C(s32 enabled)
{
    D_80132DCC = (s16) enabled;
}

// Get draw enable flag.
int func_800EA358()
{
    return D_80132DCC;
}

u16 func_800EA364()
{
    return D_80132DCE;
}

void func_800EA3A0();

// Group: moving-platform carry; moves the player along with the actor it stands on.
void func_800EA370()
{
    func_800EA3A0();
}

void func_800EA390(void)
{
}

void func_800EA398(void)
{
}

// Matching: the line breaks in this function are needed for the match.
// Clears all carry slots.
void func_800EA3A0()
{
    int *marker_slot;
    int *pos;
    marker_slot = &((int *) D_80132DD0)[0];
    do { pos = &D_80132DD8[0]; marker_slot = &((int *) D_80132DD0)[0]; do { func_800EFD24(pos); pos += 5; marker_slot += 5; marker_slot[0] = 0; marker_slot[1] = 0; } while (pos != &D_80132E78[0]); } while (0);
}

// Store the carrying marker in a player's carry slot.
void func_800EA400(s32 slot, s32 marker, s32 pos, s32 argument)
{
    func_800EE7F8(((u8 *) &D_80132DD0 + (slot * 0x14)) + 8, pos);
    *(s32 *) (((u8 *) &D_80132DD0 + (slot * 0x14)) + 0x14) = marker;
    *(s32 *) (((u8 *) &D_80132DD0 + (slot * 0x14)) + 0x18) = argument;
}

// Record each carried player's transform relative to its carrying actor.
void func_800EA45C(void)
{
    LocalDraw *entry;
    f32 player_pos[3];
    s32 i;
    Actor *actor;
    for (i = 0; i < 8; i++) {
        if ((*(LocalState *) D_80132DD0).entries[i].marker) {
            entry = &(*(LocalState *) D_80132DD0).entries[i];
            actor = func_80106790((*(LocalState *) D_80132DD0).entries[i].marker);
            func_800F5A00(i, player_pos);
            func_800D8B80(*(s16 *) ((u8 *) actor + 0x80), i, actor->position,
                          actor->rotation, actor->scale, 0,
                          (*(LocalState *) D_80132DD0).entries[i].argument,
                          func_80103C94(actor), entry->position);
        }
    }
}

// Reapply the recorded transform and move each carried player with its actor.
void func_800EA51C(void)
{
    u8 *slot;
    f32 player_pos[3];
    s32 i;
    u8 *actor;

    slot = &D_80132DD0;
    i = 0;
    do {
        if (*(s32 *) ((u8 *) slot + 0x14) != 0) {
            actor = func_80106790(*(s32 *) ((u8 *) slot + 0x14));
            func_800F5A00(i, player_pos);
            if (func_800D89C8(*(s16 *) ((u8 *) actor + 0x80), i, actor + 4, actor + 0x44,
                              *(f32 *) ((u8 *) actor + 0x38), 0, func_80103C94(actor), player_pos,
                              player_pos) != 0) {
                player_pos[1] -= 10.0f;
                func_800F8418(i, player_pos);
            }
            *(s32 *) ((u8 *) slot + 0x14) = 0;
        }
        i += 1;
        slot += 0x14;
    } while (i != 8);
}

// Group: per-cube prop collision queries (segment, swept sphere, sphere) and the on-hit callback.
// Set the callback (and its argument) called on a marker hit.
void func_800EA600(s32 callback, s32 arg)
{
    *(s32 *) (s32 *) D_80132DD0 = callback;
    *(s32 *) ((char *) (s32 *) D_80132DD0 + 4) = arg;
}

// Clear the marker hit callback.
int func_800EA614()
{
    ((s32 *) D_80132DD0)[0] = 0;
    ((s32 *) D_80132DD0)[1] = 0;
}

struct MarkerEA {
    u8 pad[0xC];
    HandlerEA_800EA628 *(*get_handlers)(void);
    u32 pad10;
    u16 unk_14;
    u16 pad16;
    u16 flags;
};

// Segment collision against all props of a cube; returns the last nonzero hit.
s32 func_800EA628(void *cube, s32 *param_1, s32 *param_2, f32 *param_3, s32 param_4)
{
    s32 result = 0;
    s32 hit;
    EntryEA *entry;
    EntryEA *end;
    void *model;
    void *collision;
    ActorEA_800EA628 *actor;
    f32 pos[3];
    f32 rot[3];
    MarkerEA *marker;
    HandlerEA_800EA628 *handlers;
    f32 scale;
    s32 prop_id;
    s32 unk_0;
    void *player_index;
    s32 unk_1;
    entry = func_800E9E88(cube);
    end = func_800E9EB4(cube);
    for (; entry < end; entry++) {
        if (entry->actor_view.active) {
            // Static model prop
            if (!entry->actor_view.is_actor) {
                if (!entry->actor_view.unk_8_1)
                    continue;
                prop_id = _gsproplookup_entrypoint_0(entry);
                model = func_800BFC54(prop_id);
                if (!model) {
                    if (func_800CB854(0) != 1)
                        continue;
                    model = func_800BFC34(prop_id);
                    if (!model)
                        continue;
                }
                collision = func_800B2720(model);
                if (collision) {
                    entry->actor_view.unk_8_3 = 1;
                    pos[0] = entry->prop_view.pos[0];
                    pos[1] = entry->prop_view.pos[1];
                    pos[2] = entry->prop_view.pos[2];
                    rot[0] = 0.0f;
                    rot[1] = (u32) entry->prop_view.rot[0] * 2.0f;
                    rot[2] = (u32) entry->prop_view.rot[1] * 2.0f;
                    scale = (u32) entry->prop_view.scale * 0.01f;
                    if (func_800AAEF4(pos, func_800B2354(func_800B2840(model)) * scale,
                                      param_1, param_2)) {
                        hit = func_800AB868(collision, func_800B2840(model), pos, rot,
                                            scale, param_1, param_2, param_3, param_4);
                        if (hit)
                            result = hit;
                    }
                }
                if (model)
                    func_800BFC74(prop_id);
            } else {
                // Actor marker
                marker = entry->actor_view.marker;
                if (!entry->actor_view.unk_8_3)
                    continue;
                if (!(marker->flags & 1))
                    continue;
                if (marker->get_handlers && (handlers = marker->get_handlers())->callback) {
                    hit = handlers->callback(marker, param_1, param_2, param_3, param_4);
                    if (hit)
                        result = hit;
                } else {
                    actor = func_80106790(marker);
                    if (actor->unk_64)
                        continue;
                    if (func_800EB350(actor, param_1, param_2))
                        continue;
                    if (func_800CB854(0) == 1)
                        func_80103508(actor);
                    model = func_80103AA0(marker);
                    if (!model)
                        continue;
                    collision = func_800B2720(model);
                    if (collision) {
                        hit = func_800AB868(
                            collision, func_80103CDC(actor, model), actor->position,
                            actor->rotation, actor->scale, param_1, param_2, param_3, param_4);
                        if (hit && *(void **) D_80132DD0)
                            (*(void (**)(void *, s32)) D_80132DD0)(marker, D_80132DD4);
                        if (hit && func_800CB854(&player_index) == 1) {
                            func_801039E4(marker);
                            if (actor->unk_80)
                                func_800EA400(player_index, marker, param_2, hit);
                        }
                        if (hit)
                            result = hit;
                    }
                    if (model)
                        func_800D62E4(marker->unk_14);
                }
            }
        }
    }
    return result;
}

// Sphere-sweep collision against all props of a cube; returns the last nonzero hit.
s32 func_800EAA2C(void *cube, f32 *param_1, f32 *param_2, f32 radius, f32 *param_4, s32 param_5,
                  s32 param_6)
{
    s32 result = 0;
    s32 hit;
    EntryEA *entry;
    EntryEA *end;
    void *model;
    void *collision;
    ActorEA_800EAA2C *actor;
    f32 pos[3];
    f32 rot[3];
    MarkerEA *marker;
    HandlerEA_800EAA2C *handlers;
    s32 prop_id;
    s32 unk_0;
    entry = func_800E9E88(cube);
    end = func_800E9EB4(cube);
    for (; entry < end; entry++) {
        if (!entry->actor_view.active)
            continue;
        // Static model prop
        if (!entry->actor_view.is_actor) {
            if (entry->actor_view.unk_8_1) {
                prop_id = _gsproplookup_entrypoint_0(entry);
                model = func_800BFC54(prop_id);
                collision = func_800B2720(model);
                if (collision) {
                    pos[0] = entry->prop_view.pos[0];
                    pos[1] = entry->prop_view.pos[1];
                    pos[2] = entry->prop_view.pos[2];
                    rot[0] = 0.0f;
                    rot[1] = (u32) entry->prop_view.rot[0] * 2.0f;
                    rot[2] = (u32) entry->prop_view.rot[1] * 2.0f;
                    hit = func_800AC848(collision, func_800B2840(model), pos, rot,
                                        (u32) entry->prop_view.scale * 0.01f, param_1,
                                        param_2, radius, param_4, param_5, param_6);
                    if (hit && *(void **) D_80132DD0)
                        (*(void (**)(void *, s32)) D_80132DD0)(entry->actor_view.marker,
                                                               D_80132DD4);
                    if (hit)
                        result = hit;
                }
                if (model)
                    func_800BFC74(prop_id);
            }
        } else {
            // Actor marker
            marker = entry->actor_view.marker;
            if (!entry->actor_view.unk_8_3)
                continue;
            if (!(marker->flags & 1))
                continue;
            actor = func_80106790(marker);
            // Matching: the double negation is needed for the match.
            if (!!actor->unk_64)
                continue;
            if (marker->get_handlers && (handlers = marker->get_handlers())->callback) {
                hit = handlers->callback(marker, param_1, param_2, radius, param_4, param_5,
                                         param_6);
                if (hit)
                    result = hit;
            } else {
                func_80103328(actor);
                if ((u32) actor->radius * actor->scale <=
                    func_800EEAD4(param_2, actor->position) - radius)
                    continue;
                if (func_800CB854(0) == 1)
                    func_80103508(actor);
                model = func_80103AA0(marker);
                collision = func_800B2720(model);
                if (collision) {
                    hit = func_800AC848(collision, func_80103CDC(actor, model),
                                        actor->position, actor->rotation, actor->scale,
                                        param_1, param_2, radius, param_4, param_5, param_6);
                    if (hit)
                        result = hit;
                }
                if (model)
                    func_800D62E4(marker->unk_14);
            }
        }
    }
    return result;
}

// Sphere collision against all props of a cube; returns the last nonzero hit.
s32 func_800EADFC(void *cube, f32 *center, f32 radius, f32 *param_3, s32 param_4)
{
    s32 result = 0;
    s32 hit;
    EntryEA *entry;
    EntryEA *end;
    void *model;
    void *collision;
    ActorEA_800EADFC *actor;
    f32 pos[3];
    f32 rot[3];
    MarkerEA *marker;
    HandlerEA_800EADFC *handlers;
    s32 unk_0;
    s32 unk_1;
    entry = func_800E9E88(cube);
    end = func_800E9EB4(cube);
    for (; entry < end; entry++) {
        if (entry->actor_view.active) {
            // Static model prop
            if (!entry->actor_view.is_actor) {
                if (entry->actor_view.unk_8_1) {
                    model = func_800BFC54(_gsproplookup_entrypoint_0(entry));
                    collision = func_800B2720(model);
                    if (collision) {
                        pos[0] = entry->prop_view.pos[0];
                        pos[1] = entry->prop_view.pos[1];
                        pos[2] = entry->prop_view.pos[2];
                        rot[0] = 0.0f;
                        rot[1] = (u32) entry->prop_view.rot[0] * 2.0f;
                        rot[2] = (u32) entry->prop_view.rot[1] * 2.0f;
                        hit = func_800AD1AC(collision, func_800B2840(model), pos, rot,
                                            (u32) entry->prop_view.scale * 0.01f, center,
                                            radius, param_3, param_4);
                        if (hit)
                            result = hit;
                    }
                }
            } else {
                // Actor marker
                marker = entry->actor_view.marker;
                if (entry->actor_view.unk_8_3) {
                    if (marker->flags & 1) {
                        actor = func_80106790(marker);
                        if (!actor->unk_64) {
                            if (marker->get_handlers && (handlers = marker->get_handlers())->callback) {
                                hit =
                                    handlers->callback(marker, center, radius, param_3, param_4);
                                if (hit)
                                    result = hit;
                            } else {
                                func_80103328(actor);
                                if ((u32) actor->radius * actor->scale <=
                                    func_800EEAD4(center, actor->position) - radius)
                                    continue;
                                if (func_800CB854(0) == 1)
                                    func_80103508(actor);
                                model = func_80103AA0(marker);
                                collision = func_800B2720(model);
                                if (collision) {
                                    hit = func_800AD1AC(
                                        collision, func_80103CDC(actor, model), actor->position,
                                        actor->rotation, actor->scale, center, radius,
                                        param_3, param_4);
                                    if (hit)
                                        result = hit;
                                }
                                if (model)
                                    func_800D62E4(marker->unk_14);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

// Group: marker collision-callback eligibility check and dispatch.
// Whether a marker's collision callbacks may run.
s32 func_800EB15C(u8 *marker)
{
    if (*(s32 *) ((s8 *) marker + 0x18) & 1) {
        return 0;
    }
    if (((u32) *(u32 *) ((s8 *) marker + 0x24) >> 0x16) == 0) {
        return 1;
    }
    if ((func_800D3948() == 0) && (func_800F6774(func_800F54E4()) == 0)) {
        if (((u16) *(u16 *) ((s8 *) marker + 0x18) & 1) &&
            (func_80102F74(func_80106790(marker), 0x88000000) != 0)) {
            return 1;
        }
        return 0;
    }
    return 1;
}

// Dispatch marker collision callback 0, 1 or 2 if the marker is eligible.
void func_800EB210(s32 marker, s32 param_1, s32 callback_slot)
{
    u8 *callbacks;
    u8 *callbacks_alias;

    if (func_800EB15C(marker) != 0) {
        callbacks = func_800EC3C4(marker);
        // Matching: the extra copy is needed for the match.
        callbacks_alias = callbacks;
        switch (callback_slot) {
            case 0:
                if (*(s32 *) ((s8 *) callbacks + 0) != 0) {
                    (*(s32(**)(s32, s32))((s8 *) callbacks_alias + 0))(marker, param_1);
                }
                break;
            case 1:
                if (*(s32 *) ((s8 *) callbacks + 4) != 0) {
                    (*(s32(**)(s32, s32))((s8 *) callbacks_alias + 4))(marker, param_1);
                }
                break;
            case 2:
                if (*(s32 *) ((s8 *) callbacks + 8) != 0) {
                    (*(s32(**)(s32, s32))((s8 *) callbacks_alias + 8))(marker, param_1);
                }
        }
    }
}

void func_800EB2DC(S_EB2DC *marker, s32 param_1, s32 param_2)
{
    O_EB2DC *callbacks;
    if (func_800EB15C(marker) == 0) {
        return;
    }
    if (marker->flag == 0) {
        return;
    }
    callbacks = func_800EC3C4(marker);
    if (marker == 0) {
        return;
    }
    if (callbacks->unkC == 0) {
        return;
    }
    callbacks->unkC(marker, param_1, param_2);
}

// Nonzero when the actor's bounding sphere is not hit by the query.
s32 func_800EB350(actor, param_1, param_2)
S_EB350 *actor;
s32 param_1;
s32 param_2;
{
    func_80103328(actor, param_1, param_2);
    return func_800AAEF4((u8 *) actor + 4, (f32) (u32) actor->radius * actor->scale * 1.1f,
                         param_1, param_2) == 0;
}
