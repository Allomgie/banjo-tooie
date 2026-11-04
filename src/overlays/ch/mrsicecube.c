#include "common.h"

extern int D_8080099C_chmrsicecube[];
extern int D_808009E4_chmrsicecube[];
extern s32 D_808008F0_chmrsicecube[];
extern s32 D_80800A2C_chmrsicecube[];
typedef union {
    s32 word;
    s16 half;
    s16 halves[2];
} MrsIceCubeMessage36;
extern f32 func_80103FB8(Actor *);
extern s32 func_800E3E8C(f32 *, f32);
extern void *func_80100094(Actor *, s32);
extern Actor *_subaddielink_entrypoint_4(void *);
extern void func_8010A764(Actor *, f32 *);
extern void func_800DF744(s32, s32);
extern void func_80101870(Actor *, f32 *);
extern s32 _subaddiefind_entrypoint_0();
extern void func_800EE7F8(s32, s32);
extern s32 D_80800A3C_chmrsicecube;
extern s32 D_80800A44_chmrsicecube[];
extern int _subaddiedialog_entrypoint_8();
extern u16 D_80800912_chmrsicecube[];
extern s32 D_80800A54_chmrsicecube[];
typedef struct {
    u8 pad_0[0x74];
    u32 : 11;
    u32 unk_74_a : 1;
    u32 : 20;
} MrsIceCubeFlags36;
extern s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
extern void func_801094E0(f32 *, f32);
extern u8 D_80800A74_chmrsicecube[];
extern u8 D_80800A64_chmrsicecube[];
extern int D_80800AB8_chmrsicecube[];
typedef struct {
    u8 pad_0[0x74];
    u32 pad_1 : 11;
    u32 unk_74_a : 1;
    u32 pad_2 : 14;
    u32 unk_74_b : 1;
    u32 pad_3 : 5;
} IceCubeFlags31;
extern s32 D_80800910_chmrsicecube[];
extern f32 func_800EEB40(f32 *, f32 *);
void func_808006C4_chmrsicecube();
void func_80800818_chmrsicecube();
Unk80132ED0 *func_80800508_chmrsicecube();

int chmrsicecube_entrypoint_0()
{
    return (int) &D_8080099C_chmrsicecube;
}

int chmrsicecube_entrypoint_1()
{
    return (int) &D_808009E4_chmrsicecube;
}

void func_80800018_chmrsicecube(u8 *actor)
{
    s32 link_data;
    s32 variant;
    link_data = func_80100094(actor, 0);
    func_8010A800(actor, 0);
    _subaddielink_entrypoint_0(link_data);
    // Matching: empty block is needed for the match.
    if (0 && 0) {
    }
    variant = ((u32) *(u16 *) ((char *) actor + 0x76) >> 7) - 0x32;
    *(s32 *) ((char *) actor + 0x28) = variant;
    if (variant == 0) {
        func_8010A5B0(actor, func_800DA298(0x1C5));
        if (_glcutDll_entrypoint_20() != 0) {
            func_80102424(actor, 7);
            return;
        }
        if (func_800DA298(0x378) != 0) {
            func_800FFAB0(actor);
        }
    }
}

void func_80800634_chmrsicecube();

void func_808000BC_chmrsicecube(Actor *actor)
{
    void *link_data;
    Actor *trapped;
    s32 follow;
    f32 attach_pos[3];
    f32 bone_pos[3];
    link_data = func_80100094(actor, 0);
    follow = 0;
    switch (actor->unk70_10) {
        case 2:
            func_80800634_chmrsicecube(actor);
            break;
        case 3:
            actor->unk64_19 = 1;
            func_80800898_chmrsicecube(actor);
            follow = 1;
            if (func_80101DDC(actor)) {
                func_80102424(actor, 4);
            }
            break;
        case 5:
            follow = 1;
            if (func_80101DDC(actor)) {
                actor->unk64_19 = 0;
                func_80102424(actor, 2);
            }
            break;
        case 6:
            if (_subaddieDll_entrypoint_6(actor, 0xA)) {
                func_808006C4_chmrsicecube(actor);
            }
            break;
        case 7:
            func_80800898_chmrsicecube(actor);
            follow = 1;
            actor->unk64_19 = 1;
            if (func_80101DDC(actor)) {
                func_80102424(actor, 8);
            }
    }
    trapped = (Actor *) _subaddielink_entrypoint_4(link_data);
    if (trapped) {
        func_8080066C_chmrsicecube(actor, attach_pos);
        func_800EE7F8(trapped->position, attach_pos);
        if (follow && _subaddieskeleton_entrypoint_0(actor, 3, bone_pos)) {
            trapped->position[1] += bone_pos[1] - actor->position[1];
        }
    }
}

s32 func_80800260_chmrsicecube(Actor *actor, s32 msg, MrsIceCubeMessage36 data)
{
    s32 found;
    s32 link_data;
    s16 dialog_id;

    switch (msg) {
        case 0x2E:
            dialog_id = data.halves[0];
            if (_subaddiedialog_entrypoint_9(actor, dialog_id, &D_808008F0_chmrsicecube, 4) == 1)
                func_8010A590(actor);
            func_80102424(actor, 5);
            break;
        case 0x40:
            if (_subaddieDll_entrypoint_5(actor, data.word)) {
                func_80103110(actor, 1);
                _subaddieDll_entrypoint_4(actor, 1);
                func_80102424(actor, 6);
            } else {
                func_808006C4_chmrsicecube(actor);
            }
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(&D_80800A2C_chmrsicecube, *(s32 *) &actor->scale);
            break;
        case 0x95:
            link_data = func_80100094(actor, 0);
            found = func_80800508_chmrsicecube(actor);
            if (found)
                _subaddielink_entrypoint_1(link_data, found);
            else if (actor->actorData[4] || !_glcutDll_entrypoint_20())
                func_800FFAB0(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003BC_chmrsicecube(Actor *actor, f32 *pos)
{
    Actor *trapped;

    if (func_800E3E8C(actor->position, func_80103FB8(actor))) {
        trapped = _subaddielink_entrypoint_4(func_80100094(actor, 0));
        if (trapped != NULL) {
            func_8010A764(trapped, pos);
        }
        func_800DF744(3, actor->unk64_19);
        func_80101870(actor, pos);
    }
}

s32 func_8080043C_chmrsicecube(u8 *actor, s32 kind, s32 out_pos)
{
    s32 found = _subaddiefind_entrypoint_0(actor + 4, kind, -1, 0);
    if (found) {
        func_800EE7F8(out_pos, found + 4);
    }
    return found;
}

s32 func_8080048C_chmrsicecube(s32 actor, s32 kind, s32 out_pos)
{
    s32 search;
    s32 found;

    D_80800A3C_chmrsicecube = kind;
    search = _gccubesearch_entrypoint_6(&D_80800A3C_chmrsicecube, actor + 4);
    if (search == 0) {
        return 0;
    }
    found =
        _subaddiefind_entrypoint_12((u32) *(s32 *) ((char *) search + 0x10) >> 0x15, search);
    if (found != 0) {
        func_800EE88C(out_pos, search);
    }
    return found;
}

// Finds the actor to encase (by kind or cube search) and links it to the cube.
Unk80132ED0 *func_80800508_chmrsicecube(actor)
Actor *actor;
{
    s32 variant;
    Actor *target;
    f32 target_pos[3];
    u8 *link_data;

    variant = actor->actorData[4];
    link_data = func_80100094(actor, 0);
    if (*(u16 *) ((u8 *) &D_80800910_chmrsicecube + variant * 4) == 0x1F4) {
        target = func_8080043C_chmrsicecube(
            actor, *(u16 *) ((u8 *) &D_80800910_chmrsicecube + variant * 4), target_pos);
    } else {
        target = (Actor *) func_8080048C_chmrsicecube(
            (s32) actor, *(u16 *) ((u8 *) &D_80800910_chmrsicecube + variant * 4), (s32) target_pos);
    }
    if (target && func_800EEB40(target_pos, actor->position) < 40000.0f) {
        *(u32 *) (link_data + 8) = ((IceCubeFlags31 *) target)->unk_74_a;
        func_8010A570(target);
        func_8010A624(target);
        func_80102190(target, 1);
        func_80103110(target, 0);
        target->unk64_24 = 0;
        target->unk64_16 = 0;
        ((IceCubeFlags31 *) target)->unk_74_a = 0;
        func_8080066C_chmrsicecube((f32 *) actor, target->position);
        if (((IceCubeFlags31 *) target)->unk_74_b) {
            func_80103014(target);
        }
        return target->unk0;
    }
    return 0;
}

void func_80800634_chmrsicecube(s32 actor)
{
    s32 unk_0;
    unk_0 = 4;
    _subaddiedialog_entrypoint_8(actor, actor + 4, &D_80800A44_chmrsicecube,
                                 &D_808008F0_chmrsicecube, unk_0);
}

int func_8080066C_chmrsicecube(f32 cube[3], f32 out_pos[3])
{
    func_800EE7F8(out_pos, &cube[1]);
    out_pos[1] += cube[14] * 100.0f;
}

// Releases the trapped actor; variant 0 (Mildred) sets flag 0x378.
void func_808006C4_chmrsicecube(actor) Actor *actor;
{
    u8 *link_data = (u8 *) func_80100094(actor, 0);
    Actor *trapped = (Actor *) _subaddielink_entrypoint_4(link_data);
    s32 variant = actor->actorData[4];

    if (variant == 0) {
        _subaddiedialog_entrypoint_11(actor->unk0, 0x12D3, 0x44, 0, 0xA7);
        _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800A54_chmrsicecube);
        func_800DA544(0x378);
    }
    if (trapped != NULL) {
        _subaddielink_entrypoint_0(link_data);
        func_8010A590(trapped);
        func_8010A654(trapped, func_80102F74(trapped, 0x800));
        func_80102190(trapped, 0);
        func_80103110(trapped, func_80102F74(trapped, 0x80000800) == 0);
        trapped->unk64_24 = func_80102F74(trapped, 0x80000001);
        trapped->unk64_16 = 1;
        ((MrsIceCubeFlags36 *) trapped)->unk_74_a = *(u32 *) (link_data + 8);
        _chbounce_entrypoint_5(
            *(u16 *) ((u8 *) D_80800912_chmrsicecube + actor->actorData[4] * 4), trapped);
    }
    func_80800818_chmrsicecube(actor);
    func_800FFAB0(actor);
}

// Shatter effect: particles and sound.
void func_80800818_chmrsicecube(actor) Actor *actor;
{
    f32 center[3];
    func_8080066C_chmrsicecube(actor, center);
    func_800BBCB8(center, actor->position, actor->scale, 0xC, (s32 *) D_80800A74_chmrsicecube);
    _subaddieaudioquick_entrypoint_2(actor, center, D_80800A64_chmrsicecube);
    func_801094E0(center, actor->scale * 3.0f);
}

int func_80800898_chmrsicecube(s32 actor)
{
    s32 pos;
    pos = actor + 4;
    _subaddieaudioquick_entrypoint_3(actor, pos, &D_80800AB8_chmrsicecube, 0x3DCCCCCD);
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_808008F0_chmrsicecube[8] = {0x401, 0x126C0100, 0x601,    0x126D0200,
                                  0x200, 0x12D80100, -0x12001, 0x120B0300};
s32 D_80800910_chmrsicecube[17] = {0x1F4001E, 0x2290003, 0x136001E, 0x4A60006, 0x1C90015, 0x1CA0016,
                                   0x1CB0016, 0x1CC0017, 0x1CE0016, 0x1CF0016, 0x1D7001E, 0x2110006,
                                   0x19C0000, 0x1D8001E, 0x1E90006, 0x2100001, 0x2B00001};
u32 D_80800954_chmrsicecube[18] = {0x0,        0x0,        0x3FA66666, 0x4A80044,  0x3FA66666,
                                   0x4A80044,  0x3FA66666, 0x4A80002,  0x3FA66666, 0x4A90001,
                                   0x3FA66666, 0x4A80092,  0x3FA66666, 0x4A80044,  0x3FA66666,
                                   0x4A80002,  0x3FA66666, 0x4A90001};
int D_8080099C_chmrsicecube[18] = {0xA703E1,
                                   0x9160002,
                                   (u32) &D_80800954_chmrsicecube,
                                   (u32) func_808000BC_chmrsicecube,
                                   (u32) func_80105834,
                                   (u32) func_808003BC_chmrsicecube,
                                   0x3E80000,
                                   0x0,
                                   0x0,
                                   0x920,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0xC0000,
                                   (u32) func_80800018_chmrsicecube,
                                   (u32) func_80107C2C,
                                   -0x7F7F9BFE,
                                   (u32) func_80800260_chmrsicecube,
                                   0x0};
int D_808009E4_chmrsicecube[18] = {0xA803E2,
                                   0x7AC0001,
                                   0x0,
                                   (u32) func_808000BC_chmrsicecube,
                                   (u32) func_80105834,
                                   (u32) func_808003BC_chmrsicecube,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x880,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0xC0000,
                                   (u32) func_80800018_chmrsicecube,
                                   (u32) func_80107C2C,
                                   -0x7F7FD800,
                                   (u32) func_80800260_chmrsicecube,
                                   0x0};
s32 D_80800A2C_chmrsicecube[4] = {0x43F00000, 0x43960000, 0x438E0000, 0x42F00000};
s32 D_80800A3C_chmrsicecube = -0x1;
static u32 D_80800A3C_chmrsicecube_rest[1] = {0xFFFFFFFF};
s32 D_80800A44_chmrsicecube[4] = {0x1C50000, 0x25800A7, 0xC, 0x300};
s32 D_80800A54_chmrsicecube[4] = {0x130498, 0x18000A, 0x1A60020, 0x0};
u8 D_80800A64_chmrsicecube[16] = {0x0, 0x13, 0x4, 0x8D, 0x0, 0x18, 0x0, 0xD,
                                  0x1, 0x33, 0x1, 0x4C, 0x0, 0x0,  0x0, 0x0};
u8 D_80800A74_chmrsicecube[68] = {
    0x0, 0x1D, 0x7, 0x5E, 0x0,  0x16, 0x15, 0x86, 0x0, 0x2B, 0x2, 0x80, 0x3, 0x0,
    0x0, 0x27, 0x0, 0xC8, 0x0,  0xC8, 0x1,  0x90, 0x1, 0x90, 0x0, 0x2D, 0x1, 0xF4,
    0x2, 0x58, 0x0, 0x1B, 0xFC, 0x18, 0xFC, 0xE0, 0x0, 0x22, 0x2, 0x80, 0x4, 0x0,
    0x1, 0x0,  0x1, 0x80, 0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0, 0xE,  0x0, 0x50,
    0x0, 0x78, 0x0, 0x7,  0x0,  0x2,  0x0,  0x4,  0x0, 0x66, 0x0, 0x0};
int D_80800AB8_chmrsicecube[6] = {0x13047F, 0xD00F3, 0x10C0000, 0x0, 0x0, 0x0};
