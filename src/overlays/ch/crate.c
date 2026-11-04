// Breakable crate whose placement parameter selects the content: a flag, a pickup actor from a
// table, or a collectible. Breaking explodes it into splinters; three ActorInfo variants.
#include "common.h"

extern int D_80800458_chcrate[];
extern int D_808004A0_chcrate[];
extern f32 func_800EC708(void *);
extern u8 D_808004F8_chcrate[];
extern void _chcrate_entrypoint_3();
extern u8 D_80800508_chcrate[];
extern u8 D_808004E8_chcrate[];
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_12(Actor *, s32);
extern void func_800BBCB8(f32 *, void *, f32, s32, void *);
extern void func_801096C8(Actor *, s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern void _chbaddiesetup_entrypoint_5(void (*)(), s32, s32, s32, s32, s32);
extern void func_800DA544(s32);
extern void func_800FFAB0(Actor *);
extern void func_80101FDC(Actor *, s32);
extern void func_80103110(Actor *, s32);
extern void func_8010A570(Actor *);
extern void func_8010A624(Actor *);
extern s16 D_8080053C_chcrate[];
extern Actor *func_80108474(s32, f32 *, s32);
typedef struct {
    u8 pad_0[0x70];
    u32 pad_1 : 14;
    u32 unk_70 : 1;
    u32 pad_2 : 17;
} CrateSpawnFlags;
void func_80800104_chcrate();
s32 func_80800380_chcrate();

int chcrate_entrypoint_0()
{
    extern int D_80800410_chcrate[];
    return (int) &D_80800410_chcrate;
}

int chcrate_entrypoint_1()
{
    return (int) &D_80800458_chcrate;
}

int *chcrate_entrypoint_2()
{
    return &D_808004A0_chcrate;
}

// Setup: remove the crate if its 'opened' flag is already set
int func_80800024_chcrate(s32 actor)
{
    // Matching: named temporary for the flag.
    s32 flag;
    flag = func_80800380_chcrate();
    if ((flag != 0) && (func_800DA298(flag) != 0)) {
        func_800FFAB0(actor);
    }
}

// Message handler
s32 func_80800064_chcrate(Actor *actor, s32 msg, void *value)
{
    void *unk_0;
    switch (msg) {
        case 0x40:
            unk_0 = *(void **) &value;
            func_800EC398(unk_0, (f32 *) actor->actorData);
            ((f32 *) actor->actorData)[1] += func_800EC708(unk_0);
            _chexploder_entrypoint_4(actor, (u8 *) *(void **) unk_0 + 4, 4);
            break;
        case 0x90:
            func_80800104_chcrate(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

// Break the crate: explosion, splinters, sounds, spawn its content, then despawn or reset
void func_80800104_chcrate(actor) Actor *actor;
{
    Actor *unk_0;
    s32 flag;
    // Matching: one-element arrays, needed for the match.
    s32 spawn_x[1];
    s32 spawn_y[1];
    s32 spawn_z[1];
    s32 spawn_yaw[1];
    s32 spawn_kind[1];

    unk_0 = func_80106790(func_80101080());
    flag = func_80800380_chcrate(actor);
    _chexploder_entrypoint_12(unk_0, 0x32);
    func_800BBCB8(actor->position, actor->actorData, actor->scale, 0xA, D_80800508_chcrate);
    func_801096C8(actor, 0);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808004E8_chcrate);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_808004F8_chcrate);
    if ((s32) actor->unk74_7 >= 0x33) {
        spawn_x[0] = actor->position[0];
        spawn_y[0] = actor->position[1];
        spawn_z[0] = actor->position[2];
        spawn_yaw[0] = actor->rotation[1];
        spawn_kind[0] = actor->unk74_7;
        _chbaddiesetup_entrypoint_5(_chcrate_entrypoint_3, spawn_x[0], spawn_y[0], spawn_z[0],
                                    spawn_yaw[0], spawn_kind[0]);
    } else if (flag) {
        func_800DA544(flag);
    }
    if (flag) {
        func_800FFAB0(actor);
        return;
    }
    func_80101FDC(actor, 2);
    func_80103110(actor, 0);
    func_8010A570(actor);
    func_8010A624(actor);
    actor->unk64_16 = 0;
}

s16 func_808003AC_chcrate();

// Deferred spawn of the crate content (pickup actor or collectible) by placement parameter
void chcrate_entrypoint_3(s32 x, s32 y, s32 z, s32 yaw, s32 kind)
{
    f32 pos[3];
    Actor *spawned;

    spawned = NULL;
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;
    switch (kind) {
        case 0x33:
        case 0x34:
        case 0x35:
        case 0x36:
        case 0x37:
        case 0x38:
        case 0x3A:
        case 0x3B:
            spawned = func_80108474(func_808003AC_chcrate(kind), pos, yaw);
            spawned->unk74_7 = 0x32;
            break;
        case 0x39:
            if (!func_800D0B68(6, 2)) {
                func_800D1000(6, 2, pos, 3, 0);
            }
    }
    if (spawned != NULL) {
        ((CrateSpawnFlags *) spawned)->unk_70 = 1;
    }
}

// 'Crate opened' flag: 0xA40 + 0x31 - placement parameter; 0 if parameter >= 0x32
s32 func_80800380_chcrate(actor)
u16 *actor;
{
    u32 placement_param;
    int flag_offset;
    placement_param = (u32) (u16) actor[0x3B] >> 7;
    if ((s32) placement_param < 0x32) {
        return (flag_offset = 0x31 - ((u32) (u16) actor[0x3B] >> 7)) + 0xA40;
    }
    return 0;
}

// Pickup actor type from the table
s16 func_808003AC_chcrate(s32 kind)
{
    s32 slot = kind - 0x32;
    if (slot > 0) {
        return D_8080053C_chcrate[slot];
    }
    return 0;
}

// TU-NOTE: the data tables below are defined in this file because they point to its
// functions; IDO schedules those differently otherwise. Values are from the ROM.
extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_10();
int D_80800410_chcrate[18] = {0x2A01F0,
                              0x6A20001,
                              0x0,
                              (u32) func_80102EC0,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x0,
                              0x0,
                              0x0,
                              0x40000810,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800024_chcrate,
                              (u32) func_80107C2C,
                              (u32) _bsbtrot_entrypoint_10,
                              (u32) func_80800064_chcrate,
                              0x0};
int D_80800458_chcrate[18] = {0x33F03BC,
                              0x6FE0001,
                              0x0,
                              (u32) func_80102EC0,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x0,
                              0x0,
                              0x0,
                              0x40000810,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800024_chcrate,
                              (u32) func_80107C2C,
                              (u32) _bsbtrot_entrypoint_10,
                              (u32) func_80800064_chcrate,
                              0x0};
int D_808004A0_chcrate[18] = {0x2A03C2,
                              0x7000001,
                              0x0,
                              (u32) func_80102EC0,
                              (u32) func_80105834,
                              (u32) func_80101870,
                              0x0,
                              0x0,
                              0x0,
                              0x40000810,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800024_chcrate,
                              (u32) func_80107C2C,
                              (u32) _bsbtrot_entrypoint_10,
                              (u32) func_80800064_chcrate,
                              0x0};
u8 D_808004E8_chcrate[16] = {0x0, 0x13, 0x4, 0x7,  0x0, 0x16, 0x7D, 0x0,
                             0x0, 0xD,  0x0, 0xC0, 0x0, 0xD9, 0x0,  0x0};
u8 D_808004F8_chcrate[16] = {0x0, 0x13, 0x4, 0xB,  0x0, 0x16, 0x6D, 0x60,
                             0x0, 0xD,  0x0, 0xD9, 0x0, 0xF3, 0x0,  0x0};
u8 D_80800508_chcrate[52] = {0x0,  0x1D, 0x6,  0xA3, 0x0,  0x14, 0x0,  0x6,  0x0,  0x0,  0x0,
                             0x2D, 0x1,  0xC2, 0x2,  0x26, 0x0,  0x1B, 0xFD, 0xA8, 0xFE, 0x70,
                             0x0,  0x22, 0x0,  0x80, 0x0,  0x99, 0x0,  0x4C, 0x0,  0x66, 0x0,
                             0x1E, 0x0,  0x14, 0x0,  0x14, 0x0,  0x1F, 0x80, 0x80, 0x80, 0x0,
                             0x0,  0xD,  0x0,  0x64, 0x0,  0x0,  0x0,  0x0};
s16 D_8080053C_chcrate[10] = {0x0, 0x21A, 0x22E, 0x3DB, 0x16A, 0x210, 0x211, 0x0, 0x4A6, 0x1E9};
