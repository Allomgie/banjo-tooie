#include "common.h"

typedef struct {
    s16 unk0;
    u8 pad2[0xC];
} NestRecord_80800000_chnests;
extern void func_800FFAB0(Actor *);
extern s32 _subaddiesect_entrypoint_1(Actor *);
extern void _subaddiesect_entrypoint_2(Actor *, s32, s32);
typedef struct {
    u8 pad[8];
    s16 f8;
    u8 padA[4];
} NestEnt;
extern void _sudialog_entrypoint_0(s32, s32);
typedef struct {
    s16 unk0;
    s16 pad2;
    s16 sparkle;
    s16 sound;
    u16 pad8;
    u8 reward;
    u8 amount;
    u16 padC;
} NestRecord_80800144_chnests;
extern s16 D_808011DC_chnests[][2];
extern f32 func_800DC178(f32, f32);
extern void _subaddiefade_entrypoint_2();
extern void _subaddieDll_entrypoint_4(void *param_0, int param_1);
extern void func_80101FDC(void *param_0, void *param_1);
extern void func_80103110(void *param_0, int param_1);
extern void func_8010A590(void *param_0);
typedef struct {
    u8 pad[0x72];
    u16 f72 : 6;
    u16 rest : 10;
} NestState;
extern s32 func_800D9078();
typedef struct {
    u8 pad0[0x1A];
    u16 unk1A_5 : 11;
    u16 pad1A_0 : 5;
} NestMsg;
extern s32 func_800F4B4C(s32);
extern void func_800F7C0C(s32, s32, s32);
extern void func_80109EEC(Actor *, s32);
extern void func_8010DC50(s32);
extern void func_8010DCB4(s32);
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 4;
    u32 local_0 : 1;
    u32 pad_2 : 27;
} NestFlags1367;
extern f32 func_800D8FF8(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
typedef struct {
    u8 unk0;
    u8 pad1[0xD];
} NestEventRecord;
extern NestEventRecord D_80801124_chnests[];
extern void func_800DF3E0(void);
extern void func_800DF744(s32, s32);
extern void func_801018A4(Actor *, s32);
typedef struct {
    s16 id;
    s16 flag;
    u8 pad4[0xA];
} NestEntry;
extern s32 func_800C6E38(s32);
typedef struct {
    s16 unk0;
    u8 pad2[0xC];
} NestRecord_80800BA0_chnests;
typedef struct {
    u8 pad0[0x24];
    u16 unk24_6 : 10;
    u16 pad24_0 : 6;
} NestMarkerView;
typedef struct {
    NestMarkerView *unk0;
    u8 pad4[0x18];
    s32 unk1C;
} NestActorView;
typedef struct {
    u8 unused[0x24];
    u16 index : 10;
    u16 flags : 6;
} NestMarkerIndex;
extern int D_808011E8_chnests[];
extern int D_80801230_chnests[];
extern void *D_80801278_chnests;
extern s32 D_808012C0_chnests[];
extern int D_80801308_chnests[];
extern int D_80801350_chnests[];
extern int D_80801398_chnests[];
extern s32 D_808013E0_chnests[];
extern int D_80801428_chnests[];
extern int D_80801470_chnests[];
extern int D_808014B8_chnests[];
extern int D_80801500_chnests[];
extern int D_80801548_chnests[];
typedef struct {
    s16 unk0;
    u8 pad2[0xC];
} NestRecord_chnests_entrypoint_13;
extern NestRecord_chnests_entrypoint_13 D_80801118_chnests[];
extern u8 D_8012762C;
extern s32 func_800DC298(f32);
void func_808002E0_chnests();
int func_80800670_chnests();
s32 func_80800898_chnests(Actor *param_0, s32 param_1, f32 param_2);
s32 func_8080093C_chnests();
void func_80800B80_chnests();
int func_80801014_chnests();
int func_808010A0_chnests();

// Looks up the nest type of the actor's marker in the nest table and sets up the actor.
void func_80800000_chnests(actor) Actor *actor;
{
    NestRecord_80800000_chnests *record;
    s32 index;
    u32 marker_id;
    s32 count;

    count = 14;
    record = (NestRecord_80800000_chnests *) D_80801118_chnests;
    index = 0;
    marker_id = actor->unk0->unk24 >> 22;
    do {
        if (marker_id == record->unk0) {
            break;
        }
        index++;
        record++;
    } while (index < count);
    if (index == 14) {
        func_800FFAB0(actor);
        return;
    }
    *(s32 *) ((u8 *) actor + 0x1C) = index;
    *(s32 *) ((u8 *) actor + 0x24) = _subaddiesect_entrypoint_1(actor);
    if (*(s32 *) ((u8 *) actor + 0x24) != -1) {
        _subaddiesect_entrypoint_2(actor, *(s32 *) ((u8 *) actor + 0x24), 0);
    }
}

void func_80800098_chnests(s32 actor)
{
    func_80800000_chnests();
    if ((func_800D3948() == 0) && (func_800F7150(func_800F54E4()) != 0)) {
        func_808002E0_chnests(actor);
    }
}

void func_808000E8_chnests(u8 *actor)
{
    NestEnt *entry = &((NestEnt *) D_80801118_chnests)[*(s32 *) (actor + 0x1C)];
    if (entry->f8 != 0 && func_800DA298(entry->f8) == 0) {
        _sudialog_entrypoint_0(entry->f8, 0);
    }
}

// Plays the nest's sparkle and sound and gives the reward to the player.
void func_80800144_chnests(actor, msg) Actor *actor;
Unk80132ED0 *msg;
{
    NestRecord_80800144_chnests *record;
    record = &((NestRecord_80800144_chnests *) D_80801118_chnests)[actor->actorData[1]];
    if (record->sparkle)
        _fxsparkle_entrypoint_1(actor->position, record->sparkle);
    if (record->sound)
        func_800FC660(record->sound);
    if (record->reward && (_gleeprom_entrypoint_0() >> 24) == 16) {
        func_800F7664((u32) *(u16 *) ((u8 *) msg + 0x1A) >> 5, record->reward,
                      record->amount);
    }
}

void func_808001F0_chnests(actor) Actor *actor;
{
    Unk80132ED0 *marker;
    s32 variant;

    marker = actor->unk0;
    variant = actor->unk74_7 - 0x32;
    func_80800144_chnests(actor);
    func_808000E8_chnests(actor);
    switch (variant) {
        case 1:
        case 2:
        case 3:
            actor->unk58 = func_800DC178(D_808011DC_chnests[variant - 1][0],
                                           D_808011DC_chnests[variant - 1][1]);
            actor->unk64_16 = 0;
            func_8010A570(actor);
            func_80103110(actor, 1);
            _subaddieDll_entrypoint_4(actor, 1);
            *(s32 *) ((u8 *) actor + 0x18) = actor->unk70_10;
            func_80101FDC(actor, 4);
            func_80800B80_chnests(actor);
            break;
        default:
            func_800FFA88(marker);
    }
}

void func_808002E0_chnests(actor) u8 *actor;
{
    actor[0x65] &= 0xFFFE;
    func_8010A570();
    *(u32 *) (actor + 0x18) = (u32) *(u16 *) (actor + 0x72) >> 0xA;
    func_80101FDC(actor, 4);
}

void func_80800324_chnests(actor) s32 actor;
{
    func_80800144_chnests();
    func_808002E0_chnests(actor);
}
void func_8080034C_chnests(void *actor)
{
    _subaddiefade_entrypoint_2();
    func_80103110(actor, 0);
    _subaddieDll_entrypoint_4(actor, 0);
    func_8010A590(actor);
    ((u8 *) actor)[0x65] = (((u8 *) actor)[0x65] & 0xFF) | 1;
    func_80101FDC(actor, *((s32 *) (((char *) actor) + 0x18)));

}

void func_808003AC_chnests(NestState *actor)
{
    if (actor->f72 == 4 && func_800D9078((u8 *) actor + 0x58, actor) != 0) {
        func_8080034C_chnests(actor);
    }

}

void func_808009D4_chnests();

// Message handler of all nest actors.
s32 func_808003F4_chnests(Actor *actor, s32 msg_id, s32 msg_arg)
{
    NestMsg *toucher;

switch (msg_id) {
    case 0x3E:
        toucher = *(NestMsg **) &msg_arg;
        if (!func_800F4B4C(toucher->unk1A_5)) {
            return 0;
        }
        switch (actor->unk0->unk24 >> 22) {
            case 0x1D9:
            case 0x1DA:
                func_80800670_chnests(actor, toucher);
                return 1;
            case 0x1D4:
                func_800F7C0C(toucher->unk1A_5, 0x5F, actor->actorData[12]);
                if (actor->unk74_7 == 0x32) {
                    func_808001F0_chnests(actor, toucher);
                    return 1;
                }
                func_80800324_chnests(actor, toucher);
                return 1;
            default:
                func_808001F0_chnests(actor, toucher);
                return 1;
        }
    case 0x1F:
        if (func_80801014_chnests(actor)) {
            func_8080093C_chnests(actor, msg_arg);
            return 1;
        }
        if (func_808010A0_chnests(actor)) {
            func_808009D4_chnests(actor, msg_arg);
        }
        break;
    case 0x95:
        if (actor->unk6C_9 != 0x1E9 && actor->unk6C_9 != 0x4A6) {
            func_80103110(actor, 0);
        }
        func_80109EEC(actor, 0x44);
        return 1;
    case 0x29:
        if (func_80801014_chnests(actor)) {
            func_8010DC50(0);
            return 1;
        }
        if (func_808010A0_chnests(actor)) {
            func_8010DC50(1);
        }
        break;
    case 0x2A:
        if (func_80801014_chnests(actor)) {
            func_8010DCB4(0);
            return 1;
        }
        if (func_808010A0_chnests(actor)) {
            func_8010DCB4(1);
        }
        break;
    case 0x76:
        func_8080034C_chnests(actor);
        func_80101FDC(actor, 1);
        return 1;
    default:
        return 0;
}

return 1;
}

int func_80800670_chnests(actor)
Actor *actor;
{
    func_80800144_chnests();
    func_808000E8_chnests(actor);

if ((_gleeprom_entrypoint_0() >> 0x18) == 0x10) {
    func_800D0BD4(*(u8 **) ((char *) actor + 0x20), 6);
}

func_800FFAB0(actor);
}

// Registry nest (category 6): picks its type from the actor marker and randomizes the spin.
void func_808006C4_chnests(Actor *actor)
{
    s32 nest_index;
    f32 spin_sign;

    nest_index = (s32) actor->unk74_7 - 50;

if (nest_index <= 0 || nest_index >= 18) {
    func_800FFAB0(actor);
    return;
}

actor->actorData[2] = func_800D13E8(6, D_8012762C) + actor->unk74_7 - 50;

if (func_800D0B68(actor->actorData[2], 6)) {
    func_800FFAB0(actor);
    return;
}

func_80800000_chnests(actor);
*(f32 *) &actor->actorData[4] = actor->rotation[1];
spin_sign = func_800DC298(0.5f) ? -1.0f : 1.0f;
*(f32 *) &actor->actorData[5] = func_800DC178(540.0f, 630.0f) * spin_sign;
actor->rotation[1] = func_800DC178(0.0f, 360.0f);

}

void func_808007C8_chnests(Actor *actor)
{
    if (actor->unk70_10 == 2 && ((NestFlags1367 *) actor)->local_0) {
        actor->rotation[1] += *(f32 *) ((u8 *) actor + 0x2C) * func_800D8FF8();
        func_80103110(actor, 0);
    }

}

void func_8080082C_chnests(Actor *actor, s32 *gfx)
{
    if (func_80800898_chnests(actor, gfx, *(f32 *) &actor->actorData[4])) {
        func_80101870(actor, gfx);
        if (actor->unk7C_12 && (actor->unk70_10 == 2)) {
            func_80103110(actor, 1);
        }
    }

}

s32 func_80800898_chnests(Actor *actor, s32 gfx, f32 rot_y)
{
    f32 rotation[3];
    s32 model;
    model = func_800D674C(0x85C);
    func_80101970(actor);
    func_80106A98(actor, model);
    func_800DF830(1);
    func_800DF410(_subaddiefade_entrypoint_0(actor));
    func_800EFA4C(rotation, 0.0f, rot_y, 0.0f);
    return (s32) func_800DE448(actor->position, rotation, actor->scale,
                               (f32 *) func_801018D8(actor), model);
}

s32 func_8080093C_chnests(actor, gfx)
s32 actor;
s32 gfx;
{
    // Matching: `| 0` is needed for the match.
    func_8010DD20(actor, 0, gfx | 0);

}

void func_80800960_chnests(s32 actor)
{
}
void func_80800968_chnests(Actor *actor, s32 gfx)
{
    if (func_80800898_chnests(actor, gfx, actor->rotation[1])) {
        func_800DF3E0();
        func_800DF744(D_80801124_chnests[actor->actorData[1]].unk0, 1);
        func_801018A4(actor, gfx);
    }

}

void func_808009D4_chnests(s32 actor, s32 gfx)
{
    func_8010DD20(actor, 0x1, gfx);

}

void func_808009F8_chnests(s32 actor)
{
}
void func_80800A00_chnests(Actor *actor, s32 gfx)
{
    if (func_80800898_chnests(actor, gfx, actor->rotation[1])) {
        func_800DF3E0();
        func_800DF744(D_80801124_chnests[actor->actorData[1]].unk0, 1);
        func_801018A4(actor, gfx);
    }

}

void func_80800A6C_chnests(s32 actor)
{
}
// Returns the next nest type after `index` whose ability requirement the player meets.
s32 func_80800A74_chnests(s32 index)
{
    s16 start_id;

    start_id = ((NestEntry *) D_80801118_chnests)[index].id;
    index++;

while (start_id != ((NestEntry *) D_80801118_chnests)[index].id) {
    if (((NestEntry *) D_80801118_chnests)[index].id == -1 && index > 0 &&
        ((NestEntry *) D_80801118_chnests)[index - 1].id != -1) {
        do {
            index--;
        } while (index > 0 && ((NestEntry *) D_80801118_chnests)[index - 1].id != -1);
    }
    if (((NestEntry *) D_80801118_chnests)[index].flag == 0 ||
        func_800C6E38(((NestEntry *) D_80801118_chnests)[index].flag) != 0) {
        break;
    }
    index++;
}

return index;
}

// Restarts the type-change timer.
void func_80800B4C_chnests(u8 *actor)
{
    *(f32 *) (actor + 0x58) = func_800DC178(*(f32 *) (actor + 0x28), *(f32 *) (actor + 0x2C));
    *(s32 *) (actor + 0x30) = 0;
}

void func_80800B80_chnests(actor) void *actor;
{
    char *state_ptr;
    char *actor_bytes;
    int flag_bit;
    unsigned short shift;
    flag_bit = (((*((s32 *) (((char *) actor) + 0x64))) << 2) << 9) < 0;
    shift = 9;
    actor_bytes = (char *) actor;

// Matching: the extra temporaries and `* 0` are needed for the match.
if (((*(s32 *) ((char *) actor + 0x64) << 2) << shift) < (flag_bit * 0)) {
    state_ptr = actor_bytes + 0x30;
    *(s32 *) state_ptr = 2;
}

}

// Switches the actor to nest type `index`.
void func_80800BA0_chnests(NestActorView *actor, s32 index)
{
    NestMarkerView *marker;

    marker = actor->unk0;
    actor->unk1C = index;
    marker->unk24_6 = ((NestRecord_80800BA0_chnests *) D_80801118_chnests)[index].unk0;
}

void func_80800BD8_chnests(Actor *actor, s32 marker_id, f32 spin_a, f32 spin_b)
{
    ((NestMarkerIndex *) actor->unk0)->index = marker_id;
    func_80800000_chnests(actor);
    actor->unk64_20 = 1;
    *(f32 *) &actor->actorData[4] = spin_a;
    *(f32 *) &actor->actorData[5] = spin_b;
    func_80800B4C_chnests(actor);

}

// Cycling nest: after a timer, fades over to the next type the player has learned.
void func_80800C3C_chnests(Actor *actor)
{
    switch (actor->actorData[6]) {
        case 0:
            if (!(*(u16 *) ((u8 *) actor + 0x78) & 3) &&
                func_800D9078((f32 *) ((u8 *) actor + 0x58))) {
                actor->unk6C_0 = func_80800A74_chnests(actor->actorData[1]);
                if (actor->unk6C_0 == actor->actorData[1]) {
                    func_80800B4C_chnests(actor);
                    return;
                }
                actor->unk58 = 0.25f;
                actor->actorData[6] = 1;
            }
            break;
        case 1:
            if (func_800D9078((f32 *) ((u8 *) actor + 0x58))) {
                func_80800BA0_chnests(actor, actor->unk6C_0);
                func_80800B4C_chnests(actor);
                func_8010A828(actor, 1);
            }
            break;
        case 2:
            if (func_800D9078((f32 *) ((u8 *) actor + 0x58))) {
                _subaddiefade_entrypoint_2(actor);
                func_8010A590(actor);
                _subaddieDll_entrypoint_4(actor, 0);
                actor->unk64_16 = 1;
                func_80101FDC(actor, actor->actorData[0]);
                func_80800B4C_chnests(actor);
            }
            break;
    }

}

void func_80800D8C_chnests(Actor *actor, s32 gfx)
{
    s32 alpha;

if (func_80800898_chnests(actor, gfx, actor->rotation[1])) {
    func_800DF3E0();
    func_800DF744(D_80801124_chnests[actor->actorData[1]].unk0, 1);
    if (actor->actorData[6] == 1) {
        alpha = *(f32 *) ((u8 *) actor + 0x58) / 0.25f * 255.0f;
        ((u8 *) actor)[0x7A] = (((u8 *) actor)[0x7A] & ~0xC0) | 0x80;
        _subaddiefade_entrypoint_1(actor, alpha);
        func_801018A4(actor, gfx);
        func_800DF3E0();
        func_800DF744(D_80801124_chnests[actor->unk6C_0].unk0, 1);
        ((u8 *) actor)[0x7A] = (((u8 *) actor)[0x7A] & ~0xC0) | 0x40;
        _subaddiefade_entrypoint_1(actor, 255 - alpha);
        func_801018A4(actor, gfx);
        ((u8 *) actor)[0x7A] = (((u8 *) actor)[0x7A] & ~0xC0) | 0x40;
        _subaddiefade_entrypoint_1(actor, 255);
    } else
        func_801018A4(actor, gfx);
}

}

void func_80800ED8_chnests(s32 actor)
{
    func_80800BD8_chnests(actor, 0x1CE, 1.0f, 1.0f);
}

void func_80800F08_chnests(s32 actor)
{
    func_80800BD8_chnests(actor, 0x1d5, 1.0f, 1.0f);
}

int chnests_entrypoint_0()
{
    return &D_808011E8_chnests;
}

int chnests_entrypoint_1()
{
    return &D_80801230_chnests;
}

int chnests_entrypoint_2(void)
{
    return (int) &D_80801278_chnests;
}

int chnests_entrypoint_3()
{
    return D_808012C0_chnests;
}

int chnests_entrypoint_4()
{
    return (int) &D_80801308_chnests;
}

int chnests_entrypoint_5()
{
    return (int) &D_80801350_chnests;
}

int *chnests_entrypoint_6()
{
    return &D_80801398_chnests;
}

int chnests_entrypoint_7()
{
    return D_808013E0_chnests;
}

void *chnests_entrypoint_8()
{
    return &D_80801428_chnests;
}

int *chnests_entrypoint_9()
{
    return &D_80801470_chnests;
}

int chnests_entrypoint_10()
{
    return (int) &D_808014B8_chnests;
}

int *chnests_entrypoint_11()
{
    return &D_80801500_chnests;
}

int chnests_entrypoint_12()
{
    return (int) &D_80801548_chnests;
}

// Returns the collectible registry category of the nest type with this marker id.
u8 chnests_entrypoint_13(s32 marker_id)
{
    s32 count;
    s32 i;
    NestRecord_chnests_entrypoint_13 *record;

    count = 14;
    for (i = 0, record = D_80801118_chnests; i < count; i++, record++) {

if (record->unk0 == marker_id) {
    return record->pad2[9];
}

}
return 0;
}

int func_80801014_chnests(actor)
Actor *actor;
{
    return actor->unk6C_9 == 0x1C8 || actor->unk6C_9 == 0x1C9 || actor->unk6C_9 == 0x1CA ||
           actor->unk6C_9 == 0x1CB || actor->unk6C_9 == 0x1CC || actor->unk6C_9 == 0x1CD ||
           actor->unk6C_9 == 0x2B8 || actor->unk6C_9 == 0x1E9;
}

int func_808010A0_chnests(actor)
Actor *actor;
{
    u32 marker_id;
    marker_id = (*(u32 *) ((char *) (actor) + 0x6C)) << 11;
    marker_id = marker_id >> 20;
    return marker_id == 0x1CE || marker_id == 0x1CF || marker_id == 0x4A6;
}

// TU-NOTE: the overlay's .data is defined here in C. The tables point to functions of this
// file, and IDO's assembler schedules some of them differently unless they share the unit.
// D_80801124_chnests is a linker alias for D_80801118_chnests + 0xC. The nest table
// D_80801118_chnests has 14 entries of 0xE bytes.
extern void func_80102EC0();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808010F0_chnests[10] = {0x0,       0x0,        0x40000000, 0x1140401, 0x3F1C28F6,
                              0x1CB0D01, 0x3F800000, 0x1CC0C01,  0x0,       0x0};
NestRecord_chnests_entrypoint_13 D_80801118_chnests[14] = {
    0x1CE, 0x0,   0x31,  0x0,   0x3,   0x0,  0x4,  0x0,   0x2B,  0x40, 0x14,  0x2,   0x0,   0x1CF,
    0x0,   0x2C,  0x0,   0x4,   0x0,   0x6A, 0x0,  0x0,   0x41,  0xA,  0x1,   0x0,   0x1D1, 0x0,
    0x2D,  0x0,   0xC,   0x0,   0x6C,  0x0,  0x0,  0x43,  0xA,   0x5,  0x0,   0x1D0, 0x0,   0x2F,
    0x0,   0x3,   0x0,   0x6B,  0x0,   0x0,  0x42, 0xA,   0x3,   0x0,  0x1D2, 0x0,   0x2E,  0x0,
    0x4,   0x0,   0x69,  0x0,   0x0,   0x44, 0x1,  0x7,   0x0,   -0x1, 0x0,   0x0,   0x0,   0x0,
    0x0,   0x0,   0x0,   0x0,   0x0,   0x0,  0x0,  0x0,   0x1D5, 0x0,  0x0,   0x0,   0x4,   0x0,
    0x3,   0x0,   0x2C,  0x46,  0x14,  0x2,  0x0,  0x1D6, 0x0,   0x0,  0x0,   0x5,   0x0,   0x6,
    0x0,   0x2D,  0x47,  0x2,   0x1,   0x0,  -0x1, 0x0,   0x0,   0x0,  0x0,   0x0,   0x0,   0x0,
    0x0,   0x0,   0x0,   0x0,   0x0,   -0x2, 0x0,  0x0,   0x0,   0x0,  0x0,   0x0,   0x0,   0x0,
    0x0,   0x0,   0x0,   0x0,   0x1D4, 0x0,  0x0,  0x0,   0x5,   0x0,  0x4,   0x0,   0x0,   0x0,
    0x0,   0x4,   0x0,   0x1D3, 0x0,   0x0,  0x0,  0x3,   0x0,   0x78, 0x0,   0x0,   0x45,  0x5,
    0x8,   0x0,   0x1D9, 0x0,   0x0,   0x0,  0x5,  0x0,   0x1,   0x0,  0x29,  0x0,   0x5,   0x0,
    0x0,   0x1DA, 0x0,   0x0,   0x0,   0x5,  0x0,  0x14,  0x0,   0x2E, 0x0,   0x14,  0x0,   0x0};
s16 D_808011DC_chnests[3][2] = {0xA, 0xF, 0x14, 0x1E, 0x2D, 0x3C};
int D_808011E8_chnests[18] = {0x1CE01C8,
                              0x6EA0001,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800968_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800960_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801230_chnests[18] = {0x1CF01C9,
                              0x6EA0001,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800968_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800960_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
void *D_80801278_chnests = (void *) 0x01D001CA;
static u32 D_80801278_chnests_rest[17] = {0x6EA0001,
                                          0x0,
                                          (u32) func_808003AC_chnests,
                                          (u32) func_80102EC0,
                                          (u32) func_80800968_chnests,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x40000080,
                                          (u32) func_80800960_chnests,
                                          (u32) func_80108ED0,
                                          0x0,
                                          (u32) func_80800000_chnests,
                                          (u32) func_80107C2C,
                                          0x84003010,
                                          (u32) func_808003F4_chnests,
                                          0x0};
s32 D_808012C0_chnests[18] = {0x1D101CB,
                              0x6EA0001,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800968_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800960_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801308_chnests[18] = {0x1D201CC,
                              0x6EA0001,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800968_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800960_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801350_chnests[18] = {0x1D401CD,
                              0x6EA0001,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800968_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800960_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800098_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801398_chnests[18] = {0x1D302B8,
                              0x6EA0001,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800968_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800960_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
s32 D_808013E0_chnests[18] = {0x1D501CE,
                              0x6EF0003,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800A00_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_808009F8_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCFF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801428_chnests[18] = {0x1D601CF,
                              0x6EF0003,
                              0x0,
                              (u32) func_808003AC_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800A00_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000000,
                              (u32) func_808009F8_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800000_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCBF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801470_chnests[18] = {0x1D901D7,
                              0x6EC0002,
                              0x0,
                              (u32) func_808007C8_chnests,
                              (u32) func_80102EC0,
                              (u32) func_8080082C_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000000,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_808006C4_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCBB0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_808014B8_chnests[18] = {0x1DA01D8,
                              0x6ED0002,
                              0x0,
                              (u32) func_808007C8_chnests,
                              (u32) func_80102EC0,
                              (u32) func_8080082C_chnests,
                              0x0,
                              0x0,
                              0x0,
                              0x40000000,
                              0x0,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_808006C4_chnests,
                              (u32) func_80107C2C,
                              -0x7BFFCBB0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801500_chnests[18] = {0x1C501E9,
                              0x6EA0001,
                              0x0,
                              (u32) func_80800C3C_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800D8C_chnests,
                              0x1F40000,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800A6C_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800ED8_chnests,
                              (u32) func_80107C2C,
                              -0x7FFF8FF0,
                              (u32) func_808003F4_chnests,
                              0x0};
int D_80801548_chnests[18] = {0x1C604A6,
                              0x6EF0003,
                              0x0,
                              (u32) func_80800C3C_chnests,
                              (u32) func_80102EC0,
                              (u32) func_80800D8C_chnests,
                              0x1F40000,
                              0x0,
                              0x0,
                              0x40000080,
                              (u32) func_80800A6C_chnests,
                              (u32) func_80108ED0,
                              0x0,
                              (u32) func_80800F08_chnests,
                              (u32) func_80107C2C,
                              -0x7FFF8FF0,
                              (u32) func_808003F4_chnests,
                              0x0};
