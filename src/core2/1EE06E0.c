// Actor respawn system: a freelist of home-position records and a per-frame state machine
// (fade out, countdown, wait for players to leave, restore home pose, particle burst, fade in).
#include "common.h"

extern s32 D_80136F00;
extern u8 D_801244F0[];
typedef struct {
    u8 pad_0[0x94];
    u16 unk_94_0 : 2;
    u16 record_index : 10; // index into the respawn freelist, 0 = none
    u16 local_2 : 4;
} local_2;
typedef struct {
    u8 pad_0[0x5C];
    u8 unk_5C[3];
    u8 local_2[5];
    u32 unk_64_0 : 1;
    u32 unk_64_1 : 1;
    u32 unk_64_2 : 5;
    u32 unk_64_7 : 1;
    u32 unk_64_8 : 7;
    u32 unk_64_15 : 1;
    u32 unk_64_16 : 16;
    u32 unk_68;
    u32 unk_6C;
    u32 unk_70_0 : 15;
    u32 unk_70_15 : 1;
    u32 unk_70_16 : 16;
    u32 unk_74_0 : 7;
    u32 unk_74_7 : 1;
    u32 unk_74_8 : 3;
    u32 unk_74_11 : 1;
    u32 unk_74_12 : 20;
    u32 unk_78_0 : 14;
    u32 unk_78_14 : 2;
    u32 unk_78_16 : 16;
    u32 unk_7C_0 : 19;
    u32 unk_7C_19 : 1;
    u32 unk_7C_20 : 12;
} local_type_80107448;
extern void func_8010A570(local_type_80107448 *);
extern void func_8010A624(local_type_80107448 *);
extern void func_80104580(local_type_80107448 *);
typedef struct {
    u8 pad_0[0xC];
    u32 kind : 12, variant : 12, pad_18 : 8;
    s16 pad_10, rotation;
} LocalProp;
typedef struct {
    u8 pad_0[4];
    f32 position[3];
    u8 pad_10[0x38];
    f32 rotation;
    u8 pad_4C[0x24];
    u32 kind : 7, pad_77 : 9, pad_80 : 6, variant : 6, pad_90 : 4;
} LocalActor_8010754C;
extern void func_800EE88C(f32 *, void *);
extern void func_80103014(LocalActor_8010754C *);
typedef struct {
    u8 pad0[4];
    f32 position[3];
    u32 pad10, flags;
    u8 pad18[0x4C];
    u32 flag0 : 1, flag1 : 1, unused0 : 13, flag2 : 1, unused1 : 16;
    u8 pad68[8];
    u32 unused2 : 15, flag3 : 1, unused3 : 16;
    u32 unused4 : 11, flag4 : 1, unused5 : 20;
} LocalActor_801075E4;
typedef struct {
    u8 pad0[0x1C];
    f32 value;
} LocalDesc;
typedef struct {
    f32 value;
    u8 pad4[0x10];
    s16 value14;
} LocalState;
extern LocalDesc *func_80100368();
extern s32 func_80102FA0(LocalDesc *, u32);
extern f32 D_801244FC[];
typedef struct {
    u32 unk_0_0 : 7;
    u32 unk_0_7 : 1;
    u32 local_2 : 24;
} local_type_80107784;
extern s32 _subaddiefade_entrypoint_0(s32);
extern s32 func_800D90A4();
extern s32 func_80102F74(s32, s32);
extern void func_8010A590(s32);
extern void func_8010A63C(s32);
extern s32 _subaddievolume_entrypoint_0(void *, f32 (*)[3], s32, s32, s32 *);
extern s32 func_800B5BE4(s32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800EF368(f32 *, f32);
extern void func_800EF334(f32 *, f32);
extern u8 D_80124508[];
extern u8 D_80124538[];
extern u8 D_8012762C;
extern f32 D_80136F10;
extern f32 _gspropmarker_entrypoint_3(s32);
int func_80107070();
s32 func_80107320();
int func_801073AC();
s32 func_801073F8();
void func_80107448();
void func_8010754C();
void func_801075E4();
int func_80107750();
s32 func_80107784();
s32 func_80107858();
int func_801078AC();
s32 func_801078DC();
float func_80107A80();

void func_80106DF0()
{
    D_80136F00 = freelist_new(0x18, 0xC);
}

int func_80106E18()
{
    if (D_80136F00 != 0) {
        freelist_free(D_80136F00);
        D_80136F00 = 0;
    }
}

void func_80106E50()
{
    if (D_80136F00 != 0) {
        D_80136F00 = freelist_defrag(D_80136F00);
    }
}

// Creates the respawn record for an actor whose ActorInfo has a respawn table.
int func_80106E88(Actor *actor)
{
    s32 result = 0;
    void *info;
    // Matching: empty block, needed for the match.
    if (0) {
    }
    info = func_80100368();
    if ((*(s32 *) ((char *) info + 0x44) != 0) &&
        (((u32) *(s32 *) ((char *) actor + 0x6C) >> 21) != 0)) {
        result |= func_80107320(actor);
    }
    return result;
}

// Releases the actor's respawn record.
void func_80106EE0(u8 *actor)
{
    register u32 bits;
    register u32 shifted;
    u8 *field_ptr;
    register u32 slot;
    int field_bits;
    u8 *field_ptr2;
    bits = *(u32 *) (actor + 0x94);
    shifted = bits << 2;
    bits = shifted >> 0x16;
    slot = bits;
    if (slot != 0) {
        // Matching: comma expression and copies are needed for the match.
        field_ptr = (0, actor + 0x94);
        // Matching: `^ 0` is needed for the match.
        freelist_erase((u8 *) D_80136F00, slot ^ 0, actor);
        field_ptr2 = field_ptr;
        field_bits = *(u16 *) field_ptr2 & 0xFFFF;
        *(u16 *) (actor + 0x94) = field_bits & 0xC00F;
    }
}

// Returns the actor's respawn record, or 0 if it has none.
s32 func_80106F30(actor)
u8 *actor;
{
    u32 slot;
    s32 *word_ptr;
    char *actor_bytes;
    word_ptr = (s32 *) ((actor_bytes = (char *) actor) + 0x94);
    slot = *word_ptr;
    slot = (slot * 4) >> 22;
    if (slot == 0) {
        return 0;
    }
    // Matching: `^ 0` is needed for the match.
    return freelist_at((int) D_80136F00, slot ^ 0);
}

// Per-frame respawn state machine.
void func_80106F70(s32 actor)
{
    s32 record;
    s32 pos[3];
    record = func_80106F30(actor);
    switch (*(s16 *) ((u8 *) record + 10)) {
        case 1:
            if (func_80107858(actor, record) == 0)
                return;
            func_80107070(actor, 4);
            return;
        case 2:
            if (_subaddiefade_entrypoint_0(actor) != 0)
                return;
            func_80107070(actor, 3);
            return;
        case 3:
            if (func_801078AC(actor, record) == 0)
                return;
            func_800EE88C(&pos, record + 4);
            // Wait while a player is within 200 units of the home position.
            if (func_8010CAC0(&pos, 0xc8) != 0)
                return;
            func_80107070(actor, 4);
            return;
        case 4:
            if (func_80107784(actor, record) == 0)
                return;
            func_80107070(actor, 0);
    }
}

// Switches the actor to a new respawn state.
int func_80107070(actor, state)
s32 actor;
unsigned int state;
{
    u8 *record = func_80106F30(actor);
    if (!record) {
        return 0;
    }
    if (*(s16 *) (record + 0xA) == state) {
        return 1;
    }
    switch (state) {
        case 0:
            func_80103110(actor, 1);
            break;
        case 1:
            _subaddieaudioquick_entrypoint_2(actor, actor + 4, D_801244F0);
            if (!func_801073F8(actor, 1, 1)) {
                func_80103110(actor, 0);
            }
            func_80107750(actor, record);
            break;
        case 2:
            if (!func_801073F8(actor, 2, 1)) {
                func_80103110(actor, 0);
            }
            func_80107750(actor, record);
            break;
        case 3:
            if (!func_801073F8(actor, 3, 1)) {
                func_80103110(actor, 0);
            }
            func_80107448(actor, record);
            break;
        case 4:
            if (!func_801073F8(actor, 4, 1)) {
                func_80103110(actor, 0);
            }
            func_8010754C(actor, record);
            func_801075E4(actor, record);
    }
    func_801073AC(actor, state);
    *(s16 *) (record + 0xA) = state;
    return 1;
}

// Stores the actor's home position, kind/variant and yaw in its record.
void func_80107200(u8 *actor)
{
    u8 *record;
    u32 word;
    s16 *yaw_ptr;
    long offset;
    record = func_80106F30();
    if (record != 0) {
        yaw_ptr = (s16 *) ((s8 *) record + 0x12);
        func_800EE940(record + 4, actor + 4, actor);
        // Matching: empty block, needed for the match.
        if (1) {
        }
        offset = 0x70;
        word = *(u32 *) ((s8 *) record + 0xC);
        *(u32 *) ((s8 *) record + 0xC) =
            (u32) (((u32) ((((u32) (*(u32 *) ((s8 *) actor + offset) << 0x16) >> 0x1A) ^
                            (word >> 8))
                           << 0x14) >>
                    0xC) ^
                   word);
        *(u16 *) ((s8 *) record + 0xC) =
            (s16) ((*(u16 *) ((s8 *) record + 0xC) & 0xF) |
                   ((((u32) *(u32 *) ((s8 *) actor + offset) >> 0x19) * 0x10) & 0xFFFF));
        *yaw_ptr = (s16) (s32) *(f32 *) ((s8 *) actor + 0x48);
        *(s16 *) ((s8 *) record + 0xA) = 0;
        // Matching: `offset * 0` is needed for the match.
        *(f32 *) ((s8 *) record + (offset * 0)) = 0.0f;
    }
}

// Returns whether the actor's respawn state is nonzero.
int func_801072A8()
{
    s32 *record = func_80106F30();
    if (record == 0) {
        return 0;
    }
    return ((s16 *) record)[5] != 0;
}

// Returns whether the actor's respawn state is 4 (respawning).
s32 func_801072E4(void)
{
    u8 *record = func_80106F30();
    if (record == NULL) {
        return 0;
    }
    return *(s16 *) ((u8 *) record + 0xA) == 4;
}

// Allocates and fills a respawn record, links it to the actor.
s32 func_80107320(actor)
local_2 *actor;
{
    s32 slot = 0;
    s32 record;
    record = freelist_next((int *) &D_80136F00, &slot);
    bzero(record, 0x18);
    actor->record_index = slot;
    func_80107200(actor);
    return record;
}

s32 func_80107388()
{
    return *(s32 *) ((s8 *) func_80100368() + 0x44);
}

// Plays the animation of the given state and sends event 0x8F.
int func_801073AC(actor, state)
s32 actor;
s32 state;
{
    s16 *entry;
    entry = func_80107388(actor) + (state << 2);
    func_80102424(actor, *entry);
    func_8010108C(actor, 0x8F, state);
}

// Tests flags of the respawn table entry for a state.
s32 func_801073F8(actor, state, mask)
s32 actor;
s32 state;
u32 mask;
{
    s16 *table = func_80107388(actor);
    return (*(s16 *) ((u8 *) table + state * 4 + 2) & mask) ? 1 : 0;
}

void func_80107448(actor, record) local_type_80107448 *actor;
f32 *record;
{
    s32 i;

if (!func_801073F8(actor, 3, 4)) {
    actor->unk_74_11 = 0;
    actor->unk_64_15 = actor->unk_74_11;
    actor->unk_7C_19 = 0;
}

actor->unk_74_7 = 0;
actor->unk_64_7 = 0;
actor->unk_78_14 = 0;
actor->unk_64_0 = 0;
actor->unk_64_1 = 0;
actor->unk_70_15 = 0;
func_8010A570(actor);
func_8010A624(actor);
func_80104580(actor);
func_8010754C(actor, record);
i = 0;
do {
    ++i;
    actor->unk_5C[i - 1] = 99;
} while (i != 3);
// Starts the countdown.
*record = func_80107A80();
}

// Restores the home transform from the record.
void func_8010754C(actor, record) LocalActor_8010754C *actor;
LocalProp *record;
{
    func_800EE88C(actor->position, (u8 *) record + 4);
    actor->variant = record->variant;
    actor->kind = record->kind;
    actor->rotation = record->rotation;
    func_80103014(actor);
}

void func_801075E4(actor, record) LocalActor_801075E4 *actor;
LocalState *record;
{
    LocalDesc *info = func_80100368(actor);
    func_8010754C(actor, record);

if (!func_801073F8(actor, 3, 4)) {
    _subaddiefade_entrypoint_2(actor);
    actor->flag2 = 1;
    if (info->value != 0.0f)
        actor->flag4 = 1;
    else
        actor->flag4 = 0;
    record->value = 0;
} else
    record->value = 1.8f;

actor->flag0 = func_80102FA0(info, 0x80000004);
actor->flag1 = func_80102FA0(info, 0x80000008);
actor->flags |= 0x80000;
actor->flag3 = func_80102FA0(info, 0x80001000);
record->value14 = 0;

if (!func_801073F8(actor, 4, 2)) {
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_801244FC);
}

}

int func_80107750(actor, record)
s32 actor;
s32 record;
{
    _subaddiefade_entrypoint_5(actor);
    func_8010A570(actor);
    func_8010A624(actor);

}

s32 func_80107784(actor, record)
u8 *actor;
u8 *record;
{
    if (func_801073F8(actor, *(s16 *) ((u8 *) record + 0xA), 2) == 0) {
        func_801078DC(actor, record + 0x14);
    }

if ((_subaddiefade_entrypoint_0(actor) == 0xFF) && (func_800D90A4(record) != 0)) {
    ((local_type_80107784 *) (actor + 0x64))->unk_0_7 = func_80102F74(actor, 0x80000001);
    if (func_80102F74(actor, 0x80000002) == 0) {
        func_8010A590(actor);
    }
    if (func_80102F74(actor, 0x800) != 0) {
        func_8010A63C(actor);
    }
    return 1;
}

return 0;

}

s32 func_80107858(actor, record)
s32 actor;
s32 *record;
{
    if (!func_801073F8(actor, (s32) ((s16 *) record)[5], 2)) {
        func_801078DC(actor, &record[5]);
    }

if (_subaddiefade_entrypoint_0(actor) == 0) {
    return 1;
}

return 0;

}

int func_801078AC(actor, record)
s32 actor;
s32 record;
{
    // Matching: `| 0` is needed for the match.
    if (func_800D90A4(record | 0)) {
        return 1;
    }

return 0;
}

// Emits a particle burst over the actor's volume points.
s32 func_801078DC(actor, cursor) void *actor;
s16 *cursor;
{
    f32 points[20][3];
    f32 center[3];
    s32 local_2;
    s32 i;
    s32 emitter;
    s32 cursor_val;
    f32 offset[3];
    f32 target[3];
    cursor_val = *cursor;
    local_2 = _subaddievolume_entrypoint_0(actor, points, 3, 20, &cursor_val);
    *cursor = cursor_val;

if (local_2 > 0) {
    func_80103F38(actor, center);
    emitter = func_800B5BE4(0x11);
    func_800BABB8(emitter, 0, 0, 1.0f, D_80124508);
}

for (i = 0; i < local_2; i++) {
    func_800EFB24(offset, points[i], center);
    func_800EF368(offset, 40.0f);
    func_800EF04C(points[i], offset);
    func_800EFB24(offset, center, points[i]);
    func_800EF334(offset, -1.0f);
    func_800EE780(target, points[i], offset);
    func_800BABB8(emitter, points[i], target, 1.0f, D_80124538);
}
return local_2 >= 0;
}

// Returns the respawn countdown length for the current level.
float func_80107A80(void)
{
    switch (D_8012762C - 0xF) {
        case 4:
            return 40.0f;
        case 1:
            return 30.0f;
        case 0:
            return 28.0f;
        case 3:
            return 26.0f;
        case 5:
            return 24.0f;
        case 6:
            return 22.0f;
        case 7:
            return 20.0f;
        case 8:
            return 18.0f;
        case 9:
            return 16.5f;
        case 10:
            return 14.0f;
        case 11:
            return 30.0f;
        default:
            return 30.0f;
    }
}

// Copies the stored home position into out_pos; returns 0 if there is no record.
int func_80107B70(s32 actor, s32 out_pos)
{
    s32 record;
    s32 record_copy;
    record = func_80106F30(actor);
    if (record == 0) {
        return 0;
    }
    {
        // Matching: `| 0` is needed for the match.
        record_copy = record | 0;
        func_800EE88C(out_pos, record_copy + 4);
        return 1;
    }
}

// Reads the per-map respawn multiplier from prop 0x4F0.
void func_80107BB0(void)
{
    s32 val_3;
    int unk_0;
    s32 val_2;
    s32 prop_value;
    s32 val_1;
    s32 val_0;
    if (_gccubesearch_entrypoint_9(0x4F0, &prop_value, 4) > 0) {
        // Matching: chain of copies is needed for the match.
        val_0 = (unk_0, prop_value);
        val_2 = (val_1 = val_0);
        val_3 = val_2;
        D_80136F10 = _gspropmarker_entrypoint_3(val_3);
    } else {
        D_80136F10 = 1.0;
    }
}

float func_80107C00()
{
    return D_80136F10;
}

// TU-NOTE: the .data of this file is defined here in C; values are taken from the ROM.
u8 D_801244F0[12] = {0x0, 0x13, 0x4, 0xEE, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
f32 D_801244FC[3] = {1.746641e-39f, 1.194202e-39f, 2.571394e-38f};
u8 D_80124508[48] = {0x0, 0x1D, 0x9, 0xEA, 0x0, 0x15, 0x0, 0x0,  0x0,  0x66, 0x0, 0x22,
                     0x0, 0x19, 0x0, 0x1E, 0x0, 0x40, 0x0, 0x4C, 0x0,  0x27, 0x0, 0x0,
                     0x1, 0x90, 0x0, 0x0,  0x1, 0xB8, 0x0, 0x16, 0x30, 0x0,  0x0, 0x2B,
                     0x0, 0x40, 0x0, 0x59, 0x0, 0x30, 0x0, 0xE6, 0x0,  0x0,  0x0, 0x0};
u8 D_80124538[72] = {0x0, 0x2D, 0x1, 0x2C, 0x1, 0x90, 0x1, 0x1A, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x2, 0x0, 0x1, 0x0, 0xE,
                     0x0, 0x1,  0x0, 0xD,  0x0, 0x1,  0x0, 0x10, 0x0, 0x1, 0x0, 0xE, 0x0, 0x1, 0x0,
                     0x1, 0x0,  0x1, 0x0,  0xF, 0x0,  0x1, 0x0,  0xD, 0x0, 0x1, 0x0, 0xE, 0x0, 0x1,
                     0x0, 0xF,  0x0, 0x1,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
