// Probably two per-actor components: a spline path follower and model vertex-group ("glid")
// effects that are created per vertex-group id and applied to the actor's vertex buffers.
#include "common.h"
#include <vector.h>

// Path follower: records of a 0x48-byte freelist, indexed by actor+0x7C (low 12 bits).
extern s32 D_80136EC0;
typedef struct {
    u8 pad[0x7c];
    u32 unused : 20, index : 12;
} LocalActor_80105494;
typedef struct {
    u32 pad0 : 21;
    s32 path_id : 10;
    u32 pad1 : 1;
    u8 pad2[8];
    f32 t, prev_t, speed;
    u8 unk_18 : 1;
    u8 unk_18_1 : 1;
    u8 pad3 : 6;
    u8 pad4[14];
    u8 pad5 : 2;
    u8 delete_at_end : 1;
    u8 pad6 : 5;
    u8 unk_28 : 3;
    u8 pad7 : 5;
} Motion105;
extern s32 func_800D7DE8();
extern void *func_800D7520(s32);
extern void func_800C810C(void *, f32, f32 *, f32 *);
typedef struct {
    u8 pad[0x7C];
    u32 pad0 : 20;
    u32 index : 12;
} Actor105;
extern Motion105 *freelist_next(void *, s32 *);
extern s32 func_800E6A00(void);
extern void rare_memset(void *, s32, s32);
extern void freelist_erase(void *param_0, s32 param_1);
typedef struct {
    u8 pad_0[0x7C];
    u32 unused : 20;
    u32 index : 12;
} Struct80105634;
typedef struct {
    s32 pad0 : 21;
    s32 path_id : 10;
    s32 pad1 : 1;
    u8 pad4[8];
    f32 t;
    f32 prev_t;
} S_1056EC;
extern void func_800D86F0(s32, f32, void *);
typedef struct {
    s32 pad0 : 21;
    s32 path_id : 10;
    u32 unk_3 : 1;
    u8 pad4[8];
    f32 t;
    f32 prev_t;
    f32 speed;
    u8 pad18[0x10];
    u32 unk_28 : 3;
    u32 pad28 : 29;
} local_type;
typedef struct {
    u8 pad[0x74];
    u32 unused0 : 27;
    u32 has_path : 1;
    u32 unused1 : 4;
} local_actor;
extern void func_800D8648(s32, f32 *);
typedef struct {
    u8 pad0[0x27];
    u8 pad1 : 2;
    u8 delete_at_end : 1;
    u8 pad2 : 5;
} S_105BE0;
extern s32 D_80136ED0;
extern void *freelist_at(void *, s32);
extern void _glidmake_entrypoint_4(int a);
typedef struct {
    u8 pad[0x14];
    u16 id;
} LocalMarker;
typedef struct {
    LocalMarker *marker;
    u8 pad4[0x6C];
    u32 unused0 : 7, has_secondary : 1, unused1 : 20, reset : 1, unused2 : 3;
    u32 unused3 : 9, blocked : 1, unused4 : 22;
    u8 pad78[4];
    u32 unused5 : 19, update : 1, unused6 : 12;
} LocalActor_801061D8;
typedef struct {
    void *handle;
    Vector *entries;
} LocalState;
// Effect entry (0xA8 bytes) of the vertex-group effects.
typedef struct {
    s32 key;
    s16 type, id;
    u8 data[0xA0];
} LocalEntry;
// One row of the effect callback table D_80124440.
typedef struct {
    void *init;
    void (*update)(void *, s32, s16);
    void *unk_8[2];
} LocalCallbacks;
extern LocalCallbacks D_80124440[];
extern Vector *D_80136ED4;
extern void *func_80103AA0(LocalMarker *);
extern void *func_80103CDC(LocalActor_801061D8 *, void *);
extern void *func_80103D00(LocalActor_801061D8 *, void *);
extern void func_8010381C(LocalActor_801061D8 *);
extern void _glid_entrypoint_5(void *, void *);
extern void _glid_entrypoint_6(void *, void *);
int func_80105A5C();
void func_801060E4();
void *func_80106320();
int func_801063C0();
void func_801063EC();
extern s32 D_80136ED8;

// Per-actor spline path-follow component.
int func_80105410()
{
    D_80136EC0 = freelist_new(0x48, 8);
}

s32 func_80105438(void)
{
    freelist_free(D_80136EC0);
}

int func_8010545C()
{
    if (D_80136EC0 != 0) {
        D_80136EC0 = freelist_defrag(D_80136EC0);
    }
}

// Returns the actor's path record, or NULL.
void *func_80105494(actor)
LocalActor_80105494 *actor;
{
    if (actor->index == 0)
        return 0;
    return freelist_at(((void *) D_80136EC0), actor->index);
}

// Advances the actor along its path; deletes it at the end if requested.
s32 func_801054D4(actor)
s32 actor;
{
    typedef struct {
        u32 pad_0[9];
        u32 pad_24_6 : 26;
        u32 delete_at_end : 1;
    } Struct801054D4;
    u8 *rec;
    s32 result;
    rec = func_80105494();
    result = func_800D8588(actor, func_800D7DE8(actor), 0x19, 0x19);

if (((u32) *(u32 *) ((s8 *) rec + 0x18) >> 0x1F) != 0) {
    func_8010B990(actor, 0x6000);
}

if ((((Struct801054D4 *) rec)->delete_at_end != 0) && (func_80105A5C(actor) != 0)) {
    func_800FFAB0(actor);
}

return result;
}

Motion105 *func_8010556C(Actor105 *actor)
{
    s32 index = 0;
    Motion105 *rec;
    rec = freelist_next(((u8 *) &D_80136EC0), &index);
    actor->index = index;
    rare_memset(rec, 0, 0x48);
    rec->path_id = -1;
    rec->unk_28 = 7;
    rec->unk_18 = 0;
    rec->speed = 100.0f;
    rec->unk_18_1 = func_800E6A00();
    rec->delete_at_end = 0;
    return rec;
}

void func_80105634(void *actor)
{
    u32 index;
    index = ((Struct80105634 *) actor)->index;

if (index != 0) {
    freelist_erase((void *) D_80136EC0, index & 0xFFFFFFFFu);
    // Matching: the assignment inside the address is needed for the match.
    *(u16 *) ((u8 *) actor + (index = 0x7E)) &= 0xF000;
    *((u8 *) actor + 0x77) &= ~0x10;
}

}

// Returns 1 if the actor has a valid path; otherwise optionally deletes the actor and returns 0.
s32 func_8010568C(s32 actor, s32 delete_actor)
{
    s32 *rec;

    rec = func_80105494();

if ((rec == NULL) || (((s32) (*rec << 0x15) >> 0x16) == -1)) {
    if (delete_actor != 0) {
        func_800FFAB0(actor);
    }
    return 0;
}

return 1;
}

void func_801056EC(void *actor, f32 t)
{
    S_1056EC *rec = func_80105494();
    rec->prev_t = rec->t;
    rec->t = t;
    func_800D86F0(rec->path_id, t, (u8 *) actor + 4);
}

// Moves the actor to t on its path and sets yaw/pitch from the tangent.
void func_8010573C(u8 *actor, f32 t)
{
    f32 unk_0[3];
    f32 angles[3];
    Motion105 *rec;
    s32 flags;
    rec = func_80105494(actor);
    flags = func_800D7DE8(actor);
    rec->prev_t = rec->t;
    rec->t = t;
    func_800D86F0(rec->path_id, t, (f32 *) (actor + 4));
    func_800C810C(func_800D7520(rec->path_id), rec->t, unk_0, angles);

if (flags & 0x100) {
    if (angles[1] >= 180.0f)
        *(f32 *) (actor + 0x54) = angles[1] - 180.0f;
    else
        *(f32 *) (actor + 0x54) = angles[1] + 180.0f;
}

if (flags & 0x200)
    *(f32 *) (actor + 0x50) = 360.0f - angles[0];
*(f32 *) (actor + 0x48) = *(f32 *) (actor + 0x54);
*(f32 *) (actor + 0x44) = *(f32 *) (actor + 0x50);
}

void func_80105834()
{
    func_801054D4();
}

int func_80105854(s32 actor)
{
    func_801054D4(actor);

if (func_80105A5C(actor)) {
    func_800FFAB0(actor);
}

}

void func_8010588C(u8 **actor)
{
    // Matching: the pointer copies and the byte offset held in a local are needed for the match.
    int offset;
    u8 **actor_copy;
    u8 ***actor_addr;
    u8 **actor_alias;
    func_8010A570();
    actor_addr = &actor;
    offset = 0x2A;
    actor_copy = *actor_addr;
    actor_alias = actor_copy;
    actor[0][offset] |= 4;
    func_801054D4(actor_alias);
}

// Starts the actor on path path_id (-1 keeps the current one) with the given speed.
void func_801058C4(Actor *actor, s32 path_id, f32 speed, s32 param_3)
{
    local_type *rec;
    rec = func_80105494(actor);
    if (!rec)
        rec = func_8010556C(actor);
    if (path_id != -1)
        rec->path_id = path_id;
    if (param_3)
        func_800D8648(rec->path_id, (f32 *) ((u8 *) actor + 4));
    rec->t = 0.0f;
    rec->prev_t = 0.0f;
    rec->speed = speed;
    ((local_actor *) actor)->has_path = 1;
    rec->unk_3 = 1;
    rec->unk_28 = 0;
}

// Returns whether t lies in the window [prev t, current t), wrapping around.
s32 func_80105998(f32 *actor, f32 t)
{
    f32 *rec = func_80105494(actor);
    f32 cur_t = *((f32 *) (((char *) rec) + 0xC));
    f32 prev_t = *((f32 *) (((char *) rec) + 0x10));
    s32 result = 0;

if (prev_t == cur_t) {
    return 0;
}

if (prev_t < cur_t) {
    result = (prev_t <= t) && (t < cur_t);
}

else
{
    result = ((prev_t <= t) || (t < cur_t)) & 0xFFFFFFFFu;
}
return result;
}

// Returns whether the actor is at the end of its path (t == 1.0).
int func_80105A5C(actor)
int actor;
{
    f32 *rec = func_80105494(actor);
    return rec[3] == 1.0f;
}

void func_80105A9C(s32 actor, f32 speed)
{
    Actor *rec = func_80105494(actor);
    *(f32 *) ((char *) rec + 0x14) = speed;
}

float func_80105AC4(void)
{
    return *(float *) ((char *) func_80105494() + 0x14);
}

f32 func_80105AE8(void)
{
    return *(f32 *) ((char *) func_80105494() + 0xC);
}

// Returns the yaw of the path tangent at the current t.
f32 func_80105B0C(u8 *actor, f32 *unused)
{
    f32 unk_0[3];
    f32 angles[3];
    Motion105 *rec;
    s32 flags;
    rec = func_80105494(actor);
    flags = func_800D7DE8(actor);
    func_800C810C(func_800D7520(rec->path_id), rec->t, unk_0, angles);

if (flags & 0x100) {
    return angles[1] >= 180.0f ? angles[1] - 180.0f : angles[1] + 180.0f;
}

return angles[1];
}

void func_80105BAC(void)
{
    u8 *rec;
    rec = func_80105494();

if (rec != 0) {
    rec[0x18] = (rec[0x18] & 0xFFFF) | 0x80;
}

}

void func_80105BE0(void *actor, s32 delete_at_end)
{
    S_105BE0 *rec = func_80105494(actor);

if (rec != 0) {
    rec->delete_at_end = delete_at_end;
}

}

// Per-actor model vertex-group (glid) effect instances with a type callback table.
void func_80105C20()
{
    D_80136ED0 = freelist_new(8, 0);
}

s32 func_80105C48(void)
{
    s32 i;
    s32 max = freelist_capacity(D_80136ED0);
    for (i = 1; i < max; i++) {

if (freelist_is_element_alive(D_80136ED0, i)) {
    func_801060E4((s16) i);
}

}
freelist_free(D_80136ED0);
D_80136ED0 = 0;
}

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    void (*defrag_cb)(s32);
} Entry_80124440;

// Global defrag pass over all vertex-group effects.
void func_80105CD0(void)
{
    void (*defrag_fn)(s32);
    int i;
    s32 capacity;
    s32 entries;
    u32 end;
    u32 begin;
    u32 entry;
    u8 *state;
    if (D_80136ED0 != 0) {
        capacity = freelist_capacity(D_80136ED0);
        i = 1;

if (capacity >= 2) {
    do {
        if (freelist_is_element_alive(D_80136ED0, i) != 0) {
            state = freelist_at(D_80136ED0, i);
            func_801063EC((short) i, defrag(*(void **) ((char *) state + 0)));
            entries = vector_defrag(*(void **) ((char *) state + 4));
            *(void **) ((char *) state + 4) = entries;
            end = vector_end(entries);
            begin = vector_begin(*(void **) ((char *) state + 4));
            entry = begin;
            if (begin < end) {
                do {
                    defrag_fn = ((Entry_80124440 *) D_80124440)[*(s16 *) ((char *) entry + 4)].defrag_cb;
                    if (defrag_fn != 0) {
                        defrag_fn(entry + 8);
                    }
                    entry += 0xA8;
                } while (entry < end);
            }
        }
        i += 1;
    } while (i < capacity);
}

D_80136ED0 = freelist_defrag(D_80136ED0);
*(&D_80136ED0 + 1) = 0;
}
}

// Creates the vertex-group effects of the actor's model: one entry per id, type chosen by id range.
void func_80105DFC(u8 *actor)
{
    s16 *list;
    s16 *cursor;
    s16 id;
    s32 slot;
    s32 i;
    u8 *state;

    slot = 0;
    if ((*(s16 *) ((s8 *) (actor) + (0x90))) == 0) {
        state = freelist_next(&D_80136ED0, &slot);
        (*(s16 *) ((s8 *) (actor) + (0x90))) = (s16) slot;
        (*(s32 *) ((s8 *) (state) + (0))) = _glidmake_entrypoint_5(
            (*(u16 *) ((s8 *) ((*(u8 **) ((s8 *) (actor) + (0)))) + (0x14))), 0);

if (*(s32 *) ((s8 *) state + 0) == 0) {
    freelist_erase(D_80136ED0, slot);
    *(s16 *) ((s8 *) actor + 0x90) = 0;
    return;
}

(*(s32 *) ((s8 *) (state) + (4))) = vector_new(0xA8, 0);
list = _glidmake_entrypoint_1((*(s32 *) ((s8 *) (state) + (0))));
cursor = list + 1;
i = 0;

if (*list > 0) {
    do {
        id = *(s16 *) ((s8 *) cursor + 0);
        if ((id >= 0x65) && (id < 0xC8)) {
            func_80106320(actor, id, 1, id - 0x64, 0);
        } else if ((id >= 0xC8) && (id < 0x12C)) {
            func_80106320(actor, id, 0, id - 0xC8, 0);
        } else if ((id >= 0x12C) && (id < 0x190)) {
            func_80106320(actor, id, 3, id - 0x12C, 0);
        } else if ((id >= 0x190) && (id < 0x1F4)) {
            func_80106320(actor, id, 2, id - 0x190, 0);
        } else if ((id >= 0x1F4) && (id < 0x258)) {
            func_80106320(actor, id, 4, id - 0x1F4, 0);
        } else if ((id >= 0x258) && (id < 0x2BC)) {
            func_80106320(actor, id, 2, id - 0x258, 0);
        } else if ((id >= 0x2BC) && (id < 0x320)) {
            func_80106320(actor, id, 5, id - 0x2BC, 0);
        } else if ((id >= 0x320) && (id < 0x384)) {
            func_80106320(actor, id, 6, id - 0x320, 0);
        } else if ((id >= 0x384) && (id < 0x3E8)) {
            func_80106320(actor, id, 7, id - 0x384, 0);
        } else if ((id >= 0x4B0) && (id < 0x6A4)) {
            func_80106320(actor, id, 8, id - 0x4B0, 0);
        } else if ((id >= 0x6A4) && (id < 0x708)) {
            func_80106320(actor, id, 0xA, id - 0x6A4, 0);
        } else if ((id >= 0x76C) && (id < 0x7D0)) {
            func_80106320(actor, id, 9, id - 0x76C, 0);
        }
        i += 1;
        // Matching: the comma expression in the advance is needed for the match.
        cursor = &cursor[*(s16 *) ((s8 *) cursor + 2)] + (0, 2);
    } while (i < *list);
}

}
}

// Frees the effects record with the given freelist index.
void func_801060E4(index) s16 index;
{
    s32 *handle_ptr;
    s32 *state;

    state = freelist_at((void *) D_80136ED0, index);
    handle_ptr = state;
    vector_free(*(s32 *) ((s8 *) state + 4));
    _glidmake_entrypoint_4(*handle_ptr);
    freelist_erase((void *) D_80136ED0, index);
}

void func_80106138(u8 *actor)
{
    u32 end;
    u32 begin;
    u32 entry;
    int type_offset;
    u8 *state;
    state = func_801063C0();
    end = vector_end(*(s32 *) ((s8 *) state + 4));
    begin = vector_begin(*(s32 *) ((s8 *) state + 4));
    entry = begin;
    if (begin < end) {
        do {
            type_offset = *(s16 *) ((s8 *) entry + 4) * 4;
            (*(s32(**)(s32))((s8 *) ((s32 *) D_80124440 + type_offset) + 8))(entry + 8);
            entry += 0xA8;
        }

while (entry < end)
    ;
}
func_801060E4(*((s16 *) (((s8 *) actor) + 0x90)));
*((s16 *) (((s8 *) actor) + 0x90)) = 0;
}

// Per-frame: applies the effects to the actor's vertex buffers and runs their update callbacks.
void func_801061D8(LocalActor_801061D8 *actor)
{
    LocalState *state;
    void *model;
    LocalEntry *entry;
    LocalEntry *end;
    state = func_801063C0(actor);
    model = func_80103AA0(actor->marker);
    if (model) {
        func_800D62E4(actor->marker->id);
        _glid_entrypoint_5(state->handle, func_80103CDC(actor, model));
        if (actor->has_secondary)
            _glid_entrypoint_6(state->handle, func_80103D00(actor, model));

if (actor->update && !actor->blocked) {
    end = vector_end(state->entries);
    D_80136ED4 = state->entries;
    for (entry = vector_begin(state->entries); entry < end; entry++) {
        D_80124440[entry->type].update(entry->data, entry->key, entry->id);
    }
}

}
else if (actor->reset) func_8010381C(actor);
}

s32 func_80106314()
{
    return D_80136ED8;
}

// Appends an effect entry of the given type for an actor and calls the type's init callback.
void *func_80106320(actor, id, type, range_index)
s32 *actor;
s32 id;
s32 type;
s32 range_index;
{
    s32 *state;
    void *entry;

    state = func_801063C0();
    entry = vector_push_back((char *) state + 4);
    *(s16 *) ((char *) entry + 4) = (s16) type;
    *(s32 *) ((char *) entry + 0) = (s32) *state;
    *(s16 *) ((char *) entry + 6) = (s16) id;
    D_80136ED8 = *actor;
    (*(void (**)(s32, s32, s32, s16, s32))((char *) ((s32 *) D_80124440) +
                                           *(s16 *) ((char *) entry + 4) * 16))(
        (s32) ((char *) entry + 8), range_index, *(volatile s32 *) ((char *) entry + 0),
        *(s16 *) ((char *) entry + 6), 4);
    return entry;
}

// Returns the effects record of the actor (freelist index at actor+0x90).
int func_801063C0(actor) void *actor;
{
    freelist_at(((void *) D_80136ED0), *(s16 *) ((u8 *) actor + 0x90));
}

typedef struct {
    s32 handle;
    Vector *vec;
} Entry_801063EC;

// Sets the model handle of a record and of all its entries.
void func_801063EC(index, handle) s16 index;
s32 handle;
{
    Entry_801063EC *e;
    s32 *p;
    s32 *end;

    e = freelist_at(D_80136ED0, index);
    if (handle != e->handle) {
        end = vector_end(e->vec);
        for (p = vector_begin(e->vec); p < end; p = (s32 *) ((u8 *) p + 0xA8)) {
            *p = handle;
        }
        e->handle = handle;
    }
}

int func_8010647C(s32 actor)
{
    s16 index;
    index = *(s16 *) ((char *) actor + 0x90);
    func_801063EC(index);
}

// Returns the data of the type-2 entry with the given id, or NULL.
u8 *func_8010649C(s32 actor, s32 id)
{
    s32 wanted_id = id;
    u32 end;
    u8 *state_copy;
    u32 begin;
    u32 entry;
    u8 *state;

    state = func_801063C0(actor);
    state_copy = state;
    end = vector_end((*(s32 *) ((s8 *) (state) + (4))));
    begin = vector_begin((*(s32 *) ((s8 *) (state_copy) + (4))));
    entry = begin;
    if (begin < end) {
    loop_2:
        if (((*(s16 *) ((s8 *) (entry) + (4))) == 2) &&
            (wanted_id == (*(s16 *) ((s8 *) (entry) + (6))))) {
            return entry + 8;
        }
        entry += 0xA8;
        if (entry >= end) {
            goto block_6;

}
goto loop_2;
}
block_6 : return NULL;
}

// Returns the data of the type-7 entry with the given id in the current entry list, or NULL.
s32 func_80106520(s32 id)
{
    s32 begin;
    s32 end;
    s32 *entry;
    end = vector_end((s32 *) (u8 *) D_80136ED4);
    begin = vector_begin((s32 *) (u8 *) D_80136ED4);
    if ((u32) begin < (u32) end) {
        entry = (s32 *) begin;
        while (1) {
            if (*(s16 *) ((char *) entry + 4) == 7 &&
                *(s16 *) ((char *) entry + 6) == id) {
                return (s32) ((char *) entry + 8);
            }

entry = (s32 *) ((char *) entry + 0xA8);

if ((u32) entry >= (u32) end) {
    break;
}

}
}
return 0;
}

s32 func_801065A4(s32 actor)
{
    ;
    if ((*((s16 *) (actor + 0x90))) != 0) {
        s32 *state;
        state = func_801063C0(actor);
        return *state;
    }
    return 0;
}

// TU-NOTE: the .data of this file is defined here in C, values taken from the ROM. The table
// holds pointers to functions of this file; IDO's assembler schedules some of these functions
// differently unless the tables are defined in the same unit.
extern void _idlight_entrypoint_2();
extern void _idlight_entrypoint_3();
extern void _idlight_entrypoint_1();
extern void _idscroll_entrypoint_2();
extern void _idscroll_entrypoint_3();
extern void _idscroll_entrypoint_1();
extern void func_800EDB20();
extern void func_800EE108();
extern void func_800EDAF4();
extern void _idwater_entrypoint_3();
extern void _idwater_entrypoint_4();
extern void _idwater_entrypoint_2();
extern void _idglow_entrypoint_2();
extern void _idglow_entrypoint_3();
extern void _idglow_entrypoint_1();
extern void _idwave_entrypoint_2();
extern void _idwave_entrypoint_3();
extern void _idwave_entrypoint_1();
extern void _idglowa_entrypoint_3();
extern void _idglowa_entrypoint_4();
extern void _idglowa_entrypoint_2();
extern void _idflasha_entrypoint_3();
extern void _idflasha_entrypoint_4();
extern void _idflasha_entrypoint_2();
extern void _idwibble_entrypoint_2();
extern void _idwibble_entrypoint_3();
extern void _idwibble_entrypoint_1();
extern void _idflame_entrypoint_3();
extern void _idflame_entrypoint_4();
extern void _idflame_entrypoint_2();
extern void _idbounce_entrypoint_4();
extern void _idbounce_entrypoint_5();
extern void _idbounce_entrypoint_3();
extern void func_800EE55C();
LocalCallbacks D_80124440[11] = {(void *) _idlight_entrypoint_2,  (void *) _idlight_entrypoint_3,
                                 (void *) _idlight_entrypoint_1,  0,
                                 (void *) _idscroll_entrypoint_2, (void *) _idscroll_entrypoint_3,
                                 (void *) _idscroll_entrypoint_1, 0,
                                 (void *) func_800EDB20,          (void *) func_800EE108,
                                 (void *) func_800EDAF4,          0,
                                 (void *) _idwater_entrypoint_3,  (void *) _idwater_entrypoint_4,
                                 (void *) _idwater_entrypoint_2,  0,
                                 (void *) _idglow_entrypoint_2,   (void *) _idglow_entrypoint_3,
                                 (void *) _idglow_entrypoint_1,   0,
                                 (void *) _idwave_entrypoint_2,   (void *) _idwave_entrypoint_3,
                                 (void *) _idwave_entrypoint_1,   0,
                                 (void *) _idglowa_entrypoint_3,  (void *) _idglowa_entrypoint_4,
                                 (void *) _idglowa_entrypoint_2,  0,
                                 (void *) _idflasha_entrypoint_3, (void *) _idflasha_entrypoint_4,
                                 (void *) _idflasha_entrypoint_2, 0,
                                 (void *) _idwibble_entrypoint_2, (void *) _idwibble_entrypoint_3,
                                 (void *) _idwibble_entrypoint_1, 0,
                                 (void *) _idflame_entrypoint_3,  (void *) _idflame_entrypoint_4,
                                 (void *) _idflame_entrypoint_2,  0,
                                 (void *) _idbounce_entrypoint_4, (void *) _idbounce_entrypoint_5,
                                 (void *) _idbounce_entrypoint_3, (void *) func_800EE55C};
