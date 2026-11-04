// Door builder for the generic door: allocates and fills the per-actor door block for a motion
// kind (rotate, slide, fade) and snaps the door to its final pose if its flag is already set.
#include "common.h"
#include "memory.h"

typedef struct {
    u8 cutscene_id;
    u8 pad_1;
    u8 cutscene_active : 1;
    u8 pad_2 : 7;
    u8 pad_3[5];
} DoorMakeChannel1527;
typedef struct {
    s32 flags;
    s16 flag_id;
    u8 pad_6[2];
    u8 motion : 6;
    u8 pad_8 : 2;
    u8 pad_9;
    s16 move_time;
    s16 open_delay;
    s16 close_delay;
    s16 slide_closed[3];
    s16 slide_open[3];
    u8 pad_1C[4];
    DoorMakeChannel1527 channels[2];
} DoorMakeState1527;
extern void *func_80100074(Actor *, u32, u32);
extern void func_80103110(Actor *, s32);
extern f32 func_800136E4(f32);
extern void func_800EE940();
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF214(f32 *, f32, f32, f32);
extern s16 D_808009A0_chdoormake[][3];
extern s16 D_80800A0C_chdoormake[][5];
extern s16 D_80800AC0_chdoormake[][5];
typedef struct {
    u8 pad_0[0x1C];
    s16 unk_1C;
    s16 value;
    u8 pad_20;
    u8 type;
    u16 active : 1;
    u16 flag_id : 15;
} DoorMakeEventRecord;
typedef struct {
    u8 cutscene_id;
    u8 unk_1;
    u16 active : 1;
    u16 flag_id : 15;
    u8 pad_4[4];
} DoorEnt;
typedef struct {
    u8 pad_0[0x20];
    DoorEnt ents[1];
} DoorData;
extern DoorData *func_80100094(s32, s32);
typedef struct {
    s32 flags;
    s16 flag_id;
} DoorMakeFlags60;
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_80103EAC(Actor *);
int func_808008C4_chdoormake();

// Allocates the 0x48-byte door block and fills in the common fields.
s16 *func_80800000_chdoormake(actor, kind, flags, flag_id)
Actor *actor;
{
    DoorMakeState1527 *door;
    s32 i;

    door = func_80100074(actor, 0, 0x48);
    door->motion = kind;
    door->flags = flags;
    door->flag_id = flag_id;
    door->move_time = 0x200;
    door->open_delay = 0;
    door->close_delay = 0;
    for (i = 0; i != 2; i++) {
        door->channels[i].cutscene_active = 0;
        door->channels[i].cutscene_id = 0;
    }
    if (flags & 4)
        func_80103110(actor, 1);
    return (s16 *) door;
}

void func_808000B8_chdoormake(Actor *actor)
{
    s32 *door_flags;

    door_flags = func_80100094(actor, 0);
    if (actor->unk70_10 != 1) {
        if (actor->unk70_10 == 4) {
            if (*door_flags & 0x800)
                func_8010A624(actor);
            if (*door_flags & 0x2000)
                actor->unk64_16 = 0;
        }
    } else {
        if (*door_flags & 0x800)
            func_8010A63C(actor);
        if (*door_flags & 0x2000)
            actor->unk64_16 = 1;
    }
}

// Yaw-rotating door; angle is added to the current yaw to get the open yaw.
// Returns 2 if the door starts open, 1 otherwise.
s32 chdoormake_entrypoint_0(Actor *actor, f32 angle, s32 flags)
{
    s16 *door;

    door = func_80800000_chdoormake(actor, 1);
    door[8] = func_800136E4(actor->rotation[1] + angle);
    door[9] = actor->rotation[1];
    if (func_808008C4_chdoormake(actor) || actor->unk70_10 == 4) {
        if (flags & 1) {
            func_800FFAB0(actor);
            return 0;
        }
        actor->rotation[1] = door[8];
        func_80101FDC(actor, 4);
        func_808000B8_chdoormake(actor);
        return 2;
    }
    func_808000B8_chdoormake(actor);
    return 1;
}

// Pitch-rotating door; same as chdoormake_entrypoint_0 but on the pitch axis.
s32 chdoormake_entrypoint_1(Actor *actor, f32 angle, s32 flags)
{
    s16 *door;

    door = func_80800000_chdoormake(actor, 3);
    door[8] = func_800136E4(actor->rotation[0] + angle);
    door[9] = actor->rotation[0];
    if (func_808008C4_chdoormake(actor) || actor->unk70_10 == 4) {
        if (flags & 1) {
            func_800FFAB0(actor);
            return 0;
        }
        actor->rotation[0] = door[8];
        func_80101FDC(actor, 4);
        func_808000B8_chdoormake(actor);
        return 2;
    }
    func_808000B8_chdoormake(actor);
    return 1;
}

// Slide-and-roll door.
s32 chdoormake_entrypoint_2(Actor *actor, f32 unk_0, f32 unk_1, f32 unk_2, s32 flags,
                            s32 flag_id)
{
    s16 *door;
    f32 end_pos[3];
    f32 dist;

    door = func_80800000_chdoormake(actor, 4, flags, flag_id);
    func_800EE940(door + 8, actor->position);
    func_800EE7F8(end_pos, actor->position);
    func_800EF214(end_pos, unk_1, unk_0, unk_2);
    func_800EE940(door + 11, end_pos);
    dist = func_800EEAD4(actor->position, end_pos);
    door[14] = ((dist / (func_80103EAC(actor) * 6.2831855f)) * -360.0f) * 256.0f;
    if (func_808008C4_chdoormake(actor) || actor->unk70_10 == 4) {
        if (flags & 1) {
            func_800FFAB0(actor);
            return 0;
        }
        func_800EE7F8(actor->position, end_pos);
        actor->rotation[2] = door[14] * 0.00390625f;
        func_80101FDC(actor, 4);
        func_80103014(actor);
        func_808000B8_chdoormake(actor);
        return 2;
    }
    func_808000B8_chdoormake(actor);
    return 1;
}

// Slide door.
s32 chdoormake_entrypoint_3(Actor *actor, f32 unk_0, f32 unk_1, f32 unk_2, s32 flags,
                            s32 flag_id)
{
    s16 *door;
    f32 end_pos[3];

    door = func_80800000_chdoormake(actor, 2, flags, flag_id);
    func_800EE940(door + 8, actor->position);
    func_800EE7F8(end_pos, actor->position);
    func_800EF214(end_pos, unk_1, unk_0, unk_2);
    func_800EE940(door + 11, end_pos);
    if (func_808008C4_chdoormake(actor) || actor->unk70_10 == 4) {
        if (flags & 1) {
            func_800FFAB0(actor);
            return 0;
        }
        func_800EE7F8(actor->position, end_pos);
        func_80101FDC(actor, 4);
        func_80103014(actor);
        func_808000B8_chdoormake(actor);
        return 2;
    }
    func_808000B8_chdoormake(actor);
    return 1;
}

// Fade door.
s32 chdoormake_entrypoint_4(u8 *actor, s32 flags, s32 flag_id)
{
    func_80800000_chdoormake(actor, 5, flags, flag_id);
    if ((func_808008C4_chdoormake(actor) != 0) ||
        (((u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) == 4)) {
        if (flags & 1) {
            func_800FFAB0(actor);
            return 0;
        }
        _subaddiefade_entrypoint_1(actor, 0);
        func_80101FDC(actor, 4);
        func_808000B8_chdoormake(actor);
        return 2;
    }
    func_808000B8_chdoormake(actor);
    return 1;
}

// Sets the motion time in seconds (8.8 fixed point).
// Matching: the *& and the extra temporaries in entrypoints 5-7 are needed for the match.
void chdoormake_entrypoint_5(s32 actor, f32 seconds)
{
    void *door = func_80100094(actor, 0);
    int ticks;
    char *base;
    ticks = (s16) (256.0f * *&seconds);
    *(s16 *) ((base = (char *) door) + 0xA) = ticks;
}

// Sets the delay before opening in seconds (8.8 fixed point).
void chdoormake_entrypoint_6(Actor *actor, f32 seconds)
{
    void *door = func_80100094(actor, 0);
    int ticks;
    char *base;
    ticks = (s16) (256.0f * *&seconds);
    *(s16 *) ((base = (char *) door) + 12) = ticks;
}

// Sets the delay before closing in seconds (8.8 fixed point).
void chdoormake_entrypoint_7(s32 actor, f32 seconds)
{
    void *door = func_80100094(actor, 0);
    int ticks;
    char *base;
    ticks = (s16) (256.0f * *&seconds);
    *(s16 *) ((base = (char *) door) + 0xe) = ticks;
}

// Copies the sound records of the given preset into the door block.
void chdoormake_entrypoint_8(Actor *actor, s32 preset)
{
    u8 *door;

    door = func_80100094(actor, 0);
    rare_memcpy(door + 0x2E, D_808009A0_chdoormake[preset], 6);
    rare_memcpy(door + 0x34, D_80800A0C_chdoormake[preset], 10);
    rare_memcpy(door + 0x3E, D_80800AC0_chdoormake[preset], 10);
}

// Fills the camera/cutscene record at index.
void chdoormake_entrypoint_9(Actor *actor, s32 index, s32 type, s32 value)
{
    DoorMakeEventRecord *record;

    record = (DoorMakeEventRecord *) ((u8 *) func_80100094(actor, 0) + index * 8);
    record->type = (u16) type;
    record->value = value;
    record->active = 1;
    record->flag_id = 0;
}

void chdoormake_entrypoint_10(s32 actor, s32 index, s32 flag_id)
{
    func_80100094(actor, 0)->ents[index].flag_id = flag_id;
}

void chdoormake_entrypoint_11(s32 actor, s32 index, f32 seconds)
{
    u8 *door = func_80100094(actor, 0);
    *(s16 *) (door + index * 8 + 0x24) = 256.0f * seconds;
}

// True if the door's game flag is already set (flags bit 0x10 inverts the test;
// a set flag also needs global flag 0x9CC).
int func_808008C4_chdoormake(actor)
Actor *actor;
{
    DoorMakeFlags60 *door;

    door = func_80100094(actor, 0);
    if (door->flag_id == -1) {
        return 0;
    }
    if (door->flags & 0x10) {
        return func_800DA298(door->flag_id) == 0;
    }
    return func_800DA298(door->flag_id) != 0 && func_800DA298(0x9CC) != 0;
}

void chdoormake_entrypoint_12(actor, index, cutscene_id) s32 actor;
s32 index;
u16 cutscene_id;
{
    u8 *door = func_80100094(actor, 0);
    door[index * 8 + 0x20] = cutscene_id;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
s16 D_808009A0_chdoormake[18][3] = {
    0x0,    0x0,    0x0,    0x0,    0x0,    0x0,    0x4C0,  0x4650, 0x100,  0x507,  0x55F0,
    0x100,  0x528,  0x55F0, 0xC0,   0x4AD,  0x55F0, 0x100,  0x5B0,  0x55F0, 0x133,  0x4A9,
    0x55F0, 0x80,   0x5B9,  0x7D00, 0xCC,   0x638,  0x3A98, 0xE6,   0x4AD,  0x55F0, 0x100,
    0x0,    0x55F0, 0x0,    0x672,  0x55F0, 0xCC,   0x4AD,  0x55F0, 0x100,  0x695,  0x7D00,
    0x100,  0x695,  0x7D00, 0xCC,   0x5B9,  0x7D00, 0x100,  0x5B9,  0x7D00, 0x100};
s16 D_80800A0C_chdoormake[18][5] = {
    0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4AB, 0x55F0, 0xE6,  0x1, 0x1, 0x4C7, 0x4650, 0x100,
    0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4C7, 0x4650, 0x100, 0x0, 0x0, 0x0,   0x0,    0x0,
    0x1, 0x1, 0x4C7, 0x4650, 0x100, 0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x0, 0x0,   0x0,    0x0,
    0x1, 0x0, 0x52B, 0x55F0, 0x100, 0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4AF, 0x55F0, 0xB3,
    0x0, 0x0, 0x0,   0x0,    0x0,   0x0, 0x0, 0x0,   0x0,    0x0,   0x0, 0x0, 0x0,   0x0,    0x0,
    0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4C7, 0x55F0, 0x100, 0x1, 0x1, 0x4C7, 0x55F0, 0x100};
s16 D_80800AC0_chdoormake[19][5] = {
    0x0, 0x0, 0x0,   0x0,    0x0,   0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4C7, 0x55F0, 0x100,
    0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4C7, 0x55F0, 0x100, 0x0, 0x0, 0x0,   0x0,    0x0,
    0x0, 0x0, 0x0,   0x0,    0x0,   0x0, 0x1, 0x4CC, 0x4650, 0xCC,  0x0, 0x1, 0x4C7, 0x55F0, 0xCC,
    0x0, 0x0, 0x0,   0x0,    0x0,   0x1, 0x1, 0x4C7, 0x55F0, 0x100, 0x0, 0x0, 0x0,   0x0,    0x0,
    0x1, 0x1, 0x4C7, 0x55F0, 0x100, 0x1, 0x1, 0x4CC, 0x4650, 0xCC,  0x1, 0x1, 0x696, 0x7D00, 0x100,
    0x1, 0x1, 0x4CC, 0x7D00, 0xCC,  0x1, 0x1, 0x4C7, 0x55F0, 0x100, 0x0, 0x0, 0x0,   0x0,    0x0,
    0x0, 0x0, 0x0,   0x0,    0x0};
