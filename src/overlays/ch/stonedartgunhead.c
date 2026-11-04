// Probably a stone dart-gun head trap: a rotating head that aims at the player and fires stone
// darts (actor 0x123). An egg hit (message 0x40) crumbles it.
#include "common.h"

#define SDF(p) (((SDFlag *) (p)->unk0)->f)
#define AF(p, i) (*(f32 *) &(p)->actorData[i])
#define BITS29(p) (((SDBits *) (p))->b)
typedef struct {
    u8 pad_0[0x2A];
    u8 pad_1 : 2;
    u8 local_0 : 1;
    u8 pad_2 : 5;
} DartMarkerFlags1482;
extern f32 func_800EFB8C(f32 *, f32 *);
extern void _gccubesearch_entrypoint_13(f32 *, s32, f32 *);
extern s32 _gccubesearch_entrypoint_1(s32, f32 *);
extern s32 _gspropctrl_entrypoint_12(s32);
extern s32 _gspropctrl_entrypoint_13(s32);
extern Actor *func_801084B0(s32, Actor **);
extern f32 func_800F1828(f32 *, f32 *);
extern f32 func_80013728(f32);
extern u8 D_80800E78_chstonedartgunhead[];
typedef struct {
    u8 pad_0[0x18];
    u32 pad_1 : 11;
    u32 local_0 : 4;
    u32 pad_2 : 17;
} StoneDartMarker;
typedef union {
    s32 local_0;
    s16 local_1[2];
} StoneDartEvent;
typedef struct {
    u8 pad_0[0x28];
    u32 pad_1 : 18;
    u32 local_0 : 1;
    u32 pad_2 : 13;
} DartMarkerFlags;
extern void *D_80800F10_chstonedartgunhead;
extern void func_800EE7F8(int, int);
typedef union {
    s32 word;
    Unk80132ED0 *marker;
} DartgunEventPayload;
extern int D_80800FB0_chstonedartgunhead[];
extern f32 func_800136E4(f32);
extern void func_80101EE4(Actor *, f32);
extern s32 func_800E3AA4(f32);
typedef struct {
    u8 pad_0[0x72];
    u16 st : 6;
    u16 rest : 10;
} SDState;
extern u8 D_80800E80_chstonedartgunhead[];
extern u8 D_80800E8C_chstonedartgunhead[];
extern u8 D_80800E9C_chstonedartgunhead[];
extern u8 D_80800EAC_chstonedartgunhead[];
extern f32 func_800D8FF8(void);
extern void func_8010C820(Actor *, s32, s32);
extern void func_80108B04(Actor *, s32);
extern int func_800D9078(f32 *);
extern f32 func_8010CD28(Actor *);
extern f32 func_800F11E4(f32, f32, f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern s32 func_8010CB0C(f32 *, s32, s32, s32);
extern void func_80016068(u32, f32 *);
extern void func_80102B2C(Actor *, f32);
extern s32 func_80102CF4(Actor *, f32);
extern void _subaddieaudioquick_entrypoint_3();
extern void _subaddieaudioloop_entrypoint_4();
extern void _subaddieaudioloop_entrypoint_0(Actor *, s32);
typedef struct {
    u8 pad_0[0x2A];
    u8 a : 2;
    u8 f : 1;
    u8 b : 5;
} SDFlag;
typedef struct {
    u8 pad_0[0x64];
    u32 a : 2;
    u32 b : 1;
    u32 c : 2;
    u32 rest : 27;
} SDBits;
extern int D_80800EBC_chstonedartgunhead[];
extern int D_80800EE0_chstonedartgunhead[];
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
extern void func_800EF214(f32 *, f32, f32, f32);
extern f32 func_800EEB40(f32 *, f32 *);
extern u8 D_80800F58_chstonedartgunhead[];
extern u8 D_80800FA0_chstonedartgunhead[];
extern void func_80105834(), func_80107C2C(), func_80108ED0(), func_80800000_chstonedartgunhead(),
    func_80800B6C_chstonedartgunhead();

// Turret head: base lookup, rotation, state changes, firing, destruction and draw.
void func_80800000_chstonedartgunhead(actor) Actor *actor;
{
    s32 base;
    f32 base_pos[3];

    _gccubesearch_entrypoint_13(base_pos, 0x122, actor->position);
    ((f32 *) actor->actorData)[0] = func_800EFB8C(actor->position, base_pos);
    base = _gccubesearch_entrypoint_1(0x122, base_pos);
    ((f32 *) actor->actorData)[1] = _gspropctrl_entrypoint_12(base) + 1.0f;
    ((f32 *) actor->actorData)[4] = _gspropctrl_entrypoint_13(base);
    actor->unk64_24 = 1;
    ((DartMarkerFlags1482 *) actor->unk0)->local_0 = 1;
}

// Spawns a dart aimed at the player, pitch clamped to +-10.
void func_808000A8_chstonedartgunhead(Actor *actor)
{
    f32 player_pos[3];
    Actor *dart;

    dart = func_801084B0(0x123, &actor);
    dart->rotation[1] = actor->rotation[1];
    ((f32 *) dart->actorData)[3] = ((f32 *) actor->actorData)[4] * 0.125f * 30.0f;
    dart->position[1] += 104.0f * actor->scale;
    func_8010D254(player_pos);
    player_pos[1] += 60.0f;
    dart->rotation[0] = func_80013728(func_800F1828(dart->position, player_pos));
    if (dart->rotation[0] > 10.0f) {
        dart->rotation[0] = 10.0f;
    } else if (dart->rotation[0] < -10.0f) {
        dart->rotation[0] = -10.0f;
    }
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800E78_chstonedartgunhead);
}

void func_808001B4_chstonedartgunhead(Actor *actor)
{
    s32 prev_yaw;
    prev_yaw = actor->rotation[1];
    actor->rotation[1] = func_800136E4(
        actor->rotation[1] + *(f32 *) &actor->actorData[5] * *(f32 *) &actor->actorData[6]);
    if (prev_yaw != (s32) actor->rotation[1]) {
        *(f32 *) &actor->actorData[7] = 0.2f;
    }
}

void func_80800224_chstonedartgunhead(actor, state) Actor *actor;
s32 state;
{
    if (actor->unk70_10 == 8)
        _subaddieDll_entrypoint_4(actor, 0);
    func_80102424(actor, state);
    switch (actor->unk70_10) {
        case 4:
            actor->unk58 = 0.75f;
            break;
        case 5:
            func_80101EE4(actor, 0.856f);
            break;
        case 3:
            func_80101EE4(actor, 0.856f);
            break;
        case 6:
            if ((f32) func_800E3AA4(actor->rotation[1]) < 180.0f) {
                *(f32 *) ((u8 *) actor + 0x2C) = -1.0f;
            } else {
                *(f32 *) ((u8 *) actor + 0x2C) = 1.0f;
            }
            *(f32 *) ((u8 *) actor + 0x30) = 20.0f;
            actor->unk58 = 1.1599884033203125f;
            _subaddieDll_entrypoint_4(actor, 1);
            break;
        case 8:
            actor->unk58 = 20.0f;
            break;
    }
}

void func_80800364_chstonedartgunhead(Actor *actor)
{
    s32 prev_yaw;
    f32 unk_0[2];
    f32 unk_1[2];
    s32 prev_yaw_joy;
    f32 audio_pitch;

    func_8010C820(actor, 0x154, 0x64);
    SDF(actor) = 1;
    switch (((SDState *) actor)->st) {
        case 1:
            if (func_8010CB0C(actor->position, (s32) AF(actor, 0), 0x190, -0x190)) {
                func_80800224_chstonedartgunhead(actor, 2);
            }
            break;
        case 2:
            if (func_80101E14(actor, 0.856f)) {
                func_80800224_chstonedartgunhead(actor, 3);
            }
            break;
        case 3:
            if (!func_8010CB0C(actor->position, (s32) AF(actor, 0), 0x190, -0x190)) {
                func_80800224_chstonedartgunhead(actor, 5);
                break;
            }
            prev_yaw = (s32) actor->rotation[1];
            if (BITS29(actor)) {
                func_80016068(((SDBits *) actor)->c, unk_0);
                actor->unk54 = actor->rotation[1] + (unk_0[0] * 4.0f);
            } else {
                actor->unk54 = func_8010CD28(actor);
            }
            func_80102B2C(actor, 4.0f);
            if (prev_yaw != (s32) actor->rotation[1]) {
                AF(actor, 7) = 0.2f;
            }
            if (BITS29(actor)) {
                if (_subaddiejoy_entrypoint_6(actor, 1)) {
                    if (actor->unk58 <= 0.0f) {
                        func_80800224_chstonedartgunhead(actor, 4);
                    }
                }
            } else if (actor->unk58 <= 0.0f) {
                if (func_80102CF4(actor, 15.0f)) {
                    if (func_8010D248()) {
                        AF(actor, 2) += 1.0f;
                        if (AF(actor, 1) <= AF(actor, 2)) {
                            AF(actor, 2) = 0.0f;
                            func_80800224_chstonedartgunhead(actor, 4);
                        }
                    }
                }
            }
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_80800E80_chstonedartgunhead, 0x3EE66666);
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_80800E8C_chstonedartgunhead, 0x3F333333);
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_80800E9C_chstonedartgunhead, 0x3F7D2F1B);
            if (BITS29(actor)) {
                prev_yaw_joy = (s32) actor->rotation[1];
                if (0.2f <= func_80101F24(actor) && actor->unk58 <= 0.f &&
                    _subaddiejoy_entrypoint_6(actor, 1)) {
                    func_80800224_chstonedartgunhead(actor, 4);
                }
                func_80016068(((SDBits *) actor)->c, unk_1);
                actor->unk54 = actor->rotation[1] + (unk_1[0] * 4.0f);
                func_80102B2C(actor, 4.0f);
                if (prev_yaw_joy != (s32) actor->rotation[1]) {
                    AF(actor, 7) = 0.2f;
                }
            }
            if (func_80101E14(actor, 0.999f)) {
                func_80800224_chstonedartgunhead(actor, 3);
            } else if (func_80101E14(actor, 0.052f)) {
                func_80108B04(actor, 0);
            }
            break;
        case 5:
            if (func_80101E14(actor, 0.999f)) {
                func_80800224_chstonedartgunhead(actor, 1);
            }
            break;
        case 6:
            SDF(actor) = 0;
            func_808001B4_chstonedartgunhead(actor);
            AF(actor, 6) += 7.444444656f;
            if (87.0f < AF(actor, 6)) {
                AF(actor, 6) = 87.0f;
                func_80800224_chstonedartgunhead(actor, 7);
            }
            break;
        case 7:
            SDF(actor) = 0;
            func_808001B4_chstonedartgunhead(actor);
            if (actor->unk58 <= 0) {
                AF(actor, 6) -= 1.74000001f;
                if (AF(actor, 6) < 0) {
                    func_80800224_chstonedartgunhead(actor, 8);
                }
            }
            break;
        case 8:
            SDF(actor) = 0;
            if (actor->unk58 <= 0.0f) {
                func_80800224_chstonedartgunhead(actor, 1);
            }
    }
    if (0.0f < AF(actor, 7)) {
        audio_pitch = func_800F11E4(AF(actor, 6), 0.0f, 87.0f, 0.7f, 1.0f);
        _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                        D_80800EAC_chstonedartgunhead);
        _subaddieaudioloop_entrypoint_0(actor, *(s32 *) &audio_pitch);
        AF(actor, 7) -= func_800D8FF8();
    }
    func_800D9078(&actor->unk58);
}

// Crumble particles in four layers, rumble sound, despawn.
void func_80800908_chstonedartgunhead(actor, param_1) Actor *actor;
s32 param_1;
{
    f32 pos[3];
    f32 unk_0[3];
    f32 scale;
    s32 i;
    s32 particle;
    scale = actor->scale;
    func_800EC398(param_1, unk_0);
    func_800EE7F8(pos, actor->position);
    pos[1] += 70.0f * scale;
    for (i = 0; i != 4; i++) {
        particle = func_800BABB8(0, pos, unk_0, scale, &D_80800EBC_chstonedartgunhead);
        func_800BA4D0(particle, (s16) (actor->position[1] - 5.0f));
        func_800BA22C(particle, 8);
        func_800BBCB8(pos, unk_0, scale, 1, &D_80800EE0_chstonedartgunhead);
        pos[1] += 115.0f;
        scale -= 0.19f;
    }
    func_800C4104(0x413, 0.7f, 0x7D00, actor->position, 1250.0f, 2500.0f);
    func_800FFAB0(actor);
}

s32 func_80800AA4_chstonedartgunhead(Actor *actor, s32 message_id, StoneDartEvent param_2)
{
    s32 state;

    switch (message_id) {
        case 0x3D:
            func_808000A8_chstonedartgunhead(actor);
            break;
        case 0x3F:
            state = actor->unk70_10;
            if (state < 6 || state >= 10) {
                if (((StoneDartMarker *) actor->unk0)->local_0 == 1 && state != 6 &&
                    state != 7) {
                    func_80800224_chstonedartgunhead(actor, 6);
                }
            }
            break;
        case 0x40:
            func_80800908_chstonedartgunhead(actor, param_2.local_0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800B6C_chstonedartgunhead(actor, param_1) Actor *actor;
void *param_1;
{
    func_800DF744(2, 1);
    func_800DF744(3, 0);
    func_800DF744(4, ((DartMarkerFlags *) actor->unk0)->local_0 ? 1 : 2);
    func_80101870(actor, param_1);
}

int chstonedartgunhead_entrypoint_0()
{
    return &D_80800F10_chstonedartgunhead;
}

// Dart projectile: straight flight, timeout, collision and burst.
void func_80800BE8_chstonedartgunhead(struct Actor *actor)
{
    int dst;
    dst = (int) actor + 0x18;
    func_800EE7F8(dst, (int) actor + 4);
    actor->unk58 = 4.0f;
}

void func_80800C28_chstonedartgunhead(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            func_800EF214(actor->position, actor->rotation[0], actor->rotation[1],
                          *(f32 *) ((u8 *) actor + 0x24) * func_800D8FF8());
            if (func_800EEB40((f32 *) actor->actorData, actor->position) > 22500.0f) {
                func_80101FDC(actor, 10);
            }
            break;
        case 10:
            if (func_800D9078(&actor->unk58) || func_8010B990(actor, 0x100006)) {
                func_80102424(actor, 9);
            }
            break;
        case 9:
            func_800BBCB8(actor->position, 0, actor->scale, 2, D_80800F58_chstonedartgunhead);
            _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                             D_80800FA0_chstonedartgunhead);
            func_800FFAB0(actor);
    }
}

s32 func_80800D50_chstonedartgunhead(Actor *actor, s32 message_id, DartgunEventPayload payload)
{
    switch (message_id) {
        case 0x40:
            if ((payload.marker->unk24 >> 22) == 0) {
                func_80102424(actor, 9);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

int *chstonedartgunhead_entrypoint_1()
{
    return &D_80800FB0_chstonedartgunhead;
}

extern int func_80101870();
u8 D_80800E20_chstonedartgunhead[88] = {
    0x0,  0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x1, 0xA2, 0x0,
    0x84, 0x40, 0x40, 0x0,  0x0,  0x1, 0xA2, 0x0,  0x92, 0x0,  0x0,  0x0,  0x0, 0x1,  0xA2,
    0x0,  0xC,  0x3F, 0x80, 0x0,  0x0, 0x1,  0xA1, 0x0,  0x42, 0x40, 0x40, 0x0, 0x0,  0x1,
    0xA2, 0x0,  0x2,  0x0,  0x0,  0x0, 0x0,  0x1,  0xA2, 0x0,  0x2,  0x0,  0x0, 0x0,  0x0,
    0x1,  0xA2, 0x0,  0x2,  0x0,  0x0, 0x0,  0x0,  0x1,  0xA2, 0x0,  0x2,  0x0, 0x0,  0x0,
    0x0,  0x1,  0xA2, 0x0,  0x4A, 0x0, 0x0,  0x0,  0x0,  0x1,  0xA2, 0x0,  0x4};
u8 D_80800E78_chstonedartgunhead[8] = {0x0, 0x13, 0x4, 0xAC, 0x0, 0x0, 0x0, 0x0};
u8 D_80800E80_chstonedartgunhead[12] = {0x0, 0x13, 0x4, 0xBA, 0x0, 0xD,
                                        0x0, 0xB3, 0x0, 0xB4, 0x0, 0x0};
u8 D_80800E8C_chstonedartgunhead[16] = {0x0, 0x13, 0x4, 0xBA, 0x0, 0x16, 0x4E, 0x20,
                                        0x0, 0xD,  0x0, 0x99, 0x0, 0x9A, 0x0,  0x0};
u8 D_80800E9C_chstonedartgunhead[16] = {0x0, 0x13, 0x4, 0xBA, 0x0, 0x16, 0x3A, 0x98,
                                        0x0, 0xD,  0x0, 0x80, 0x0, 0x81, 0x0,  0x0};
u8 D_80800EAC_chstonedartgunhead[16] = {0x0, 0x13, 0x4, 0xAD, 0x0, 0x16, 0x61, 0xA8,
                                        0x0, 0x1,  0x0, 0xFA, 0xA, 0x8C, 0x0,  0x0};
int D_80800EBC_chstonedartgunhead[9] = {0x810001D, 0x6680014, 0x2D0320, 0x3E8001B, -0x3E70320,
                                        0x2200B3,  0xCC00B3,  0xB3000C, 0x640000};
int D_80800EE0_chstonedartgunhead[12] = {0x1D09DD,  0x2B0600,  0x8000022,   0x3000300,
                                         0x6800800, 0x150000,  0x260019,    0x7,
                                         0x2D015E,  0x1C20020, -0x55555501, 0x0};
void *D_80800F10_chstonedartgunhead = (void *) 0x015B0113;
static u32 D_80800F10_chstonedartgunhead_rest[17] = {0x6630001,
                                                     (u32) &D_80800E20_chstonedartgunhead,
                                                     (u32) func_80800364_chstonedartgunhead,
                                                     (u32) func_80105834,
                                                     (u32) func_80800B6C_chstonedartgunhead,
                                                     0x9C40000,
                                                     0x0,
                                                     0x0,
                                                     0x400008A2,
                                                     0x0,
                                                     (u32) func_80108ED0,
                                                     0x0,
                                                     (u32) func_80800000_chstonedartgunhead,
                                                     (u32) func_80107C2C,
                                                     0x80002011,
                                                     (u32) func_80800AA4_chstonedartgunhead,
                                                     0x0};
u8 D_80800F58_chstonedartgunhead[72] = {
    0x0,  0x16, 0x0,  0x4,  0x0,  0x1D, 0x9,  0xC9, 0x0,  0x20, 0xDC, 0xDC, 0xDC, 0xA0, 0x0,
    0x22, 0x0,  0x33, 0x0,  0x66, 0x0,  0x99, 0x0,  0xCC, 0x0,  0x2B, 0x0,  0x4C, 0x0,  0x80,
    0x0,  0x15, 0x0,  0x19, 0x0,  0x4C, 0x0,  0x2C, 0xFF, 0xCE, 0x0,  0x3C, 0xFF, 0xCE, 0x0,
    0x32, 0x0,  0x64, 0x0,  0x32, 0x0,  0xA,  0xFF, 0xF6, 0x0,  0x0,  0xFF, 0xF6, 0x0,  0xA,
    0x0,  0x0,  0x0,  0xA,  0x0,  0x1B, 0xFF, 0xEC, 0x0,  0x1E, 0x0,  0x0};
u8 D_80800FA0_chstonedartgunhead[16] = {0x0, 0x13, 0x4, 0x7,  0x0, 0x16, 0x32, 0xC8,
                                        0x0, 0xD,  0x1, 0xB3, 0x1, 0xCC, 0x0,  0x0};
int D_80800FB0_chstonedartgunhead[20] = {0x1610123,
                                         0x6640001,
                                         0x0,
                                         (u32) func_80800C28_chstonedartgunhead,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x0,
                                         (u32) func_80800BE8_chstonedartgunhead,
                                         (u32) func_80107C2C,
                                         -0x7FC00000,
                                         (u32) func_80800D50_chstonedartgunhead,
                                         0x0,
                                         0x0,
                                         0x0};
