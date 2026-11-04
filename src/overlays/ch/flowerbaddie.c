// Probably a generic flower enemy: hides, pops up near the player, follows along its route,
// sinks back when they escape, and bursts into model parts on death.
#include "common.h"

extern int D_80800C14_chflowerbaddie[];
extern u8 D_80800CC0_chflowerbaddie[];
extern u8 D_80800BCC_chflowerbaddie[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _chexploder_entrypoint_6(s32, f32, f32);
extern void _chexploder_entrypoint_7(s32, f32, f32);
extern void _chexploder_entrypoint_8(s32, f32, f32);
typedef struct {
    u32 pad_0 : 29;
    u32 disabled : 1;
    u32 pad_1 : 2;
} Broad51FlowerFlags;
typedef struct {
    Actor **actors;
} FlowerArg;
extern u8 D_80800CCC_chflowerbaddie[];
extern u8 D_80800D18_chflowerbaddie[];
extern u8 D_80800CF0_chflowerbaddie[];
extern u8 D_80800D04_chflowerbaddie[];
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
typedef struct {
    u8 pad_0[0x64];
    u32 pad_64_30 : 2;
    u32 joy_control : 1;
    u32 pad_64_0 : 29;
} PlantActorFlags;
extern s32 _subaddierouteDll_entrypoint_4(Actor *);
extern s32 func_8010C9FC(void *, s32, s32, s32);
extern s32 func_8010C668(Actor *, void *, f32, f32);
extern void *_suchase_entrypoint_0(void);
extern s32 func_801072A8(Actor *);
extern u8 D_80800D28_chflowerbaddie[];
extern f32 func_800D8FF8(void);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102B2C(Actor *, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
extern u8 D_80800C80_chflowerbaddie[];
extern u8 D_80800C5C_chflowerbaddie[];
extern u8 D_80800C68_chflowerbaddie[];
extern u8 D_80800C94_chflowerbaddie[];
extern u8 D_80800CA8_chflowerbaddie[];
extern void *func_80100094(Actor *, u32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 disabled : 1;
    u32 pad_2 : 2;
} FlowerDisabled241;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 joy_control : 1;
    u32 pad_2 : 29;
} FlowerJoy241;
void func_808006A0_chflowerbaddie();

int chflowerbaddie_entrypoint_0(void)
{
    return (int) &D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(u8 *actor)
{
    _subaddierouteDll_entrypoint_3(actor, func_80100094(actor, 0), actor + 4);
    *(f32 *) ((s8 *) actor + 0x24) = 600.0f;
    *(u8 *) ((s8 *) actor + 0x65) = (u8) (*(u8 *) ((s8 *) actor + 0x65) & 0xFFEF);
}

s32 func_808009F0_chflowerbaddie(Actor *actor, u8 *route, f32 speed);

s32 func_808007F0_chflowerbaddie();

// Update: waits hidden, rises when the player is near, chases along the route, sinks back.
void func_8080005C_chflowerbaddie(Actor *actor)
{
    u8 *route;
    s32 next_state;

    route = func_80100094(actor, 0);
    if (!((FlowerDisabled241 *) actor)->disabled) {
        func_8010D254((f32 *) actor->actorData);
        func_800D9078(&actor->unk58);
        switch (actor->unk70_10) {
            case 1:
                if (func_808007F0_chflowerbaddie(actor)) {
                    func_80102424(actor, 2);
                }
                break;
            case 2:
                if (func_80101F24(actor) > 0.1f) {
                    actor->unk64_20 = 1;
                } else {
                    actor->unk64_20 = 0;
                }
                func_80800980_chflowerbaddie(actor, D_80800C80_chflowerbaddie);
                _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80800C5C_chflowerbaddie, 0.15f);
                if (func_80101F24(actor) > 0.5f) {
                    if (!func_808009F0_chflowerbaddie(
                            actor, route,
                            func_800F3780(func_80101F24(actor), D_80800C68_chflowerbaddie, 3))) {
                        return;
                    }
                } else {
                    if (((FlowerJoy241 *) actor)->joy_control) {
                        _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
                    } else {
                        actor->unk54 = func_80102D78(actor, (f32 *) actor->actorData);
                    }
                    func_80102B2C(actor, func_800D8FF8() * 120.0f);
                }
                if (func_80101DDC(actor)) {
                    func_80102424(actor, 3);
                }
                break;
            case 3:
                func_80800980_chflowerbaddie(actor, D_80800C94_chflowerbaddie);
                if (!(actor->unk58 > 0.0f)) {
                    func_808009F0_chflowerbaddie(
                        actor, route,
                        func_800F3780(func_80101F24(actor), D_80800CA8_chflowerbaddie, 3));
                }
                break;
            case 4:
                _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                 D_80800C5C_chflowerbaddie, 0.08f);
                if (func_80101F24(actor) > 0.7f) {
                    actor->unk64_20 = 0;
                } else {
                    actor->unk64_20 = 1;
                }
                if (func_80101DDC(actor)) {
                    func_80102424(actor, 1);
                }
                break;
            case 5:
                if (func_80101DDC(actor)) {
                    if (!func_808007F0_chflowerbaddie(actor)) {
                        next_state = actor->unk64_20 ? 4 : 1;
                        func_80102424(actor, next_state);
                    } else {
                        next_state = actor->unk64_20 ? 3 : 2;
                        func_80102424(actor, next_state);
                    }
                }
        }
    }
}

// Message handler; 0x90 breaks the flower into model parts.
s32 func_80800380_chflowerbaddie(Actor *actor, s32 msg, FlowerArg msg_data)
{
    s16 *unk_0;
    s16 bone_ids[18];
    s32 exploder;
    s32 i;
    f32 offset[3];
    switch (msg) {
        case 0x3E:
            actor->unk58 = 1.0f;
            break;
        case 0x3F:
            if (actor->unk70_10 != 5 &&
                !((Broad51FlowerFlags *) ((u8 *) actor + 0x78))->disabled) {
                _subaddieaudioloop_entrypoint_2(actor);
                func_80102424(actor, 5);
                actor->unk58 = 1.0f;
            }
            break;
        case 0x40:
            _chexploder_entrypoint_4(actor, msg_data.actors[0]->position, 4);
            _subaddieaudioloop_entrypoint_2(actor);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800CC0_chflowerbaddie);
            break;
        case 0x90:
            exploder = func_80106790(func_80101080());
            // Matching: "^ 0" and the empty block below are needed for the match.
            for (i = 0x44; (i ^ 0) < 0x53; i++) {
                bone_ids[i - 0x44] = i;
                if (msg_data.actors) {
                }
            }
            bone_ids[i++ - 0x44] = 0x5B;
            bone_ids[i++ - 0x44] = 0x5C;
            bone_ids[i - 0x44] = -1;
            _chexploder_entrypoint_9(exploder, 2, 0);
            _chexploder_entrypoint_9(exploder, 3, 0);
            _chexploder_entrypoint_9(exploder, 4, 1);
            _chexploder_entrypoint_9(exploder, 5, 2);
            _chexploder_entrypoint_9(exploder, 6, 1);
            _chexploder_entrypoint_10(exploder, bone_ids);
            _chexploder_entrypoint_6(exploder, 600.0f, 800.0f);
            _chexploder_entrypoint_7(exploder, -800.0f, -600.0f);
            _chexploder_entrypoint_8(exploder, 80.0f, 160.0f);
            func_808006A0_chflowerbaddie(actor);
            if (!func_80107070(actor, 3)) {
                func_800FFAB0(actor);
            }
            break;
        case 0x95:
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0x38:
            func_80101074(D_80800BCC_chflowerbaddie);
            return 6;
        case 0x97:
            func_800EFA4C(offset, 0.0f, 300.0f, 0.0f);
            func_80101010(offset);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(actor)) {
                func_80107070(actor, 1);
                actor->unk64_20 = 0;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800610_chflowerbaddie(Actor *actor, s32 param_1)
{
    func_800DF744(3, actor->unk64_20 ? 1 : 0);
    func_800DF744(4, actor->unk64_20 ? 2 : 1);
    func_800DF744(5, 1);
    func_800DF744(6, 0);
    func_80101870(actor, param_1);
}

void func_808006A0_chflowerbaddie(actor) Actor *actor;
{
    f32 pos[3];
    s32 emitter;
    func_80103DFC(actor, pos);
    emitter = func_800B53A4(1);
    func_800BABB8(emitter, pos, pos, actor->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, pos, pos, actor->scale, D_80800D18_chflowerbaddie);
    func_800BA22C(emitter, 1);
    emitter = func_800B53A4(2);
    func_800BABB8(emitter, pos, pos, actor->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, pos, pos, actor->scale, D_80800CF0_chflowerbaddie);
    func_800BA22C(emitter, 2);
    emitter = func_800B53A4(4);
    func_800BABB8(emitter, pos, pos, actor->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, pos, pos, actor->scale, D_80800D04_chflowerbaddie);
    func_800BA22C(emitter, 4);
    actor->unk64_20 = 0;
}

// Returns 1 when the flower should rise: player in range and this actor is the chase target.
s32 func_808007F0_chflowerbaddie(Actor *actor)
{
    if (actor->unk58 > 0.0f) {
        return 0;
    }
    if (((PlantActorFlags *) actor)->joy_control) {
        return 1;
    }
    if (func_801072A8(actor)) {
        return 0;
    }
    if (!_subaddierouteDll_entrypoint_4(actor)) {
        return 0;
    }
    if (!func_8010C9FC(actor->position, 1000, 500, -50)) {
        return 0;
    }
    if (!func_8010C668(actor, actor->position, 1000.0f, -200.0f)) {
        return 0;
    }
    return _suchase_entrypoint_0() == actor->unk0;
}

// Returns 1 when the flower should sink back (player out of range or not the chase target).
s32 func_808008D4_chflowerbaddie(Actor *actor)
{
    if (((PlantActorFlags *) actor)->joy_control) {
        return 0;
    }
    if (!_subaddierouteDll_entrypoint_4(actor)) {
        return 0;
    }
    if (!func_8010C9FC(actor->position, 1000, 500, -50)) {
        return 1;
    }
    if (!func_8010C668(actor, actor->position, 1000.0f, -200.0f)) {
        return 1;
    }
    return _suchase_entrypoint_0() != actor->unk0;
}

int func_80800980_chflowerbaddie(Actor *actor)
{
    if (func_80101E4C(actor)) {
        if (actor->unk5F == 0) {
            actor->unk5F = _subaddieaudioquick_entrypoint_1(actor, &actor->position);
            func_800C4350(actor->unk5F, &actor->position, &D_80800D28_chflowerbaddie);
        }
        func_800C3BDC(actor->unk5F);
    }
}

// Moves along the route, or by stick input when controlled. Returns 0 once the flower sinks.
s32 func_808009F0_chflowerbaddie(Actor *actor, u8 *route, f32 speed)
{
    f32 dt = func_800D8FF8();
    f32 stick;

    if ((*(u32 *) ((u8 *) actor + 0x64) << 2) >> 31) {
        stick = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
        func_80102B2C(actor, dt * 120.0f);
        func_8010C3A8(actor, 0x205025, stick * speed);
    } else {
        if (_subaddierouteDll_entrypoint_4(actor)) {
            actor->unk54 = func_80102D78(actor, (f32 *) actor->actorData);
            _subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1], actor->unk54,
                                           350.0f, 0x5000);
            *(s32 *) (route + 12) = *(u16 *) (route + 6);
        }
        func_80102B2C(actor, dt * 120.0f);
        func_8010C3A8(actor, 0x5325, speed);
    }
    if (func_808008D4_chflowerbaddie(actor)) {
        _subaddieaudioloop_entrypoint_2(actor);
        func_80102424(actor, 4);
        return 0;
    }
    return 1;
}

// TU-NOTE: the overlay .data is defined here in C (values from the ROM). Its tables point to
// functions of this file, and IDO's assembler schedules some of them differently otherwise.
// Externs are declared to match the object: D_80800C14_chflowerbaddie is int[],
// D_80800D28_chflowerbaddie is u8[].
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800B70_chflowerbaddie[18] = {0x0,        0x0,        0x3FF33333, 0x39D0001,  0x3FF33333,
                                     0x39E0002,  0x3F547AE1, 0x39F0301,  0x3F400000, 0x3A00002,
                                     0x3F75C28F, 0x3A10002,  0x3FF33333, 0x39D0001,  0x0,
                                     0x0,        0x3FF33333, 0x39D0001};
u32 D_80800BB8_chflowerbaddie[5] = {0x10000, 0x60000, 0x60000, 0x70000, 0x80000};
u8 D_80800BCC_chflowerbaddie[72] = {
    0x0,  0x0,  0x0,  0x12, 0x3F, 0xC0, 0x0,  0x0,  0x0,  0xFD, 0x0,  0x0,  0x0,  0x0,  0x0,
    0x1,  0x3F, 0xB3, 0x33, 0x33, 0x2,  0x3,  0x0,  0x0,  0x0,  0x0,  0x0,  0x45, 0x3F, 0xE6,
    0x66, 0x66, 0x0,  0x46, 0x0,  0x0,  0x0,  0x0,  0x0,  0x51, 0x3F, 0xE6, 0x66, 0x66, 0x0,
    0x52, 0x0,  0x0,  0x0,  0x0,  0x0,  0x4D, 0x3F, 0xE6, 0x66, 0x66, 0x0,  0x4E, 0x0,  0x0,
    0x0,  0x0,  0x0,  0x49, 0x3F, 0xE6, 0x66, 0x66, 0x0,  0x4A, 0x0,  0x0};
int D_80800C14_chflowerbaddie[18] = {0x1A9046B,
                                     0x8950001,
                                     (u32) &D_80800B70_chflowerbaddie,
                                     (u32) func_8080005C_chflowerbaddie,
                                     (u32) func_80105834,
                                     (u32) func_80800610_chflowerbaddie,
                                     0x7D00000,
                                     0x3F19999A,
                                     0x0,
                                     0x3050221,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x100000,
                                     (u32) func_8080000C_chflowerbaddie,
                                     (u32) func_80107C2C,
                                     -0x7FDDABE3,
                                     (u32) func_80800380_chflowerbaddie,
                                     (u32) &D_80800BB8_chflowerbaddie};
u8 D_80800C5C_chflowerbaddie[12] = {0x0, 0x13, 0x4, 0xD5, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80800C68_chflowerbaddie[24] = {0x3F, 0x0,  0x0, 0x0, 0x3F, 0x80, 0x0,  0x0,
                                    0x3F, 0x40, 0x0, 0x0, 0x3E, 0x4C, 0xCC, 0xCD,
                                    0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0,  0x0};
u8 D_80800C80_chflowerbaddie[20] = {0x3F, 0xF,  0x5C, 0x29, 0x3F, 0x2E, 0x14, 0x7B, 0x3F, 0x4A,
                                    0x3D, 0x71, 0x3F, 0x63, 0xD7, 0xA,  0xBF, 0x80, 0x0,  0x0};
u8 D_80800C94_chflowerbaddie[20] = {0x0, 0x0, 0x0,  0x0,  0x3E, 0x80, 0x0,  0x0,  0x3F, 0x0,
                                    0x0, 0x0, 0x3F, 0x40, 0x0,  0x0,  0xBF, 0x80, 0x0,  0x0};
u8 D_80800CA8_chflowerbaddie[24] = {0x0,  0x0,  0x0, 0x0, 0x3F, 0x80, 0x0,  0x0,
                                    0x3F, 0x0,  0x0, 0x0, 0x3E, 0x4C, 0xCC, 0xCD,
                                    0x3F, 0x80, 0x0, 0x0, 0x3F, 0x80, 0x0,  0x0};
u8 D_80800CC0_chflowerbaddie[12] = {0x0, 0x13, 0x4, 0x84, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80800CCC_chflowerbaddie[36] = {0x0,  0x1D, 0x9,  0xDD, 0x0,  0x22, 0x1,  0x80, 0x2,
                                    0x0,  0x2,  0x0,  0x2,  0x80, 0x0,  0x15, 0x0,  0x0,
                                    0x0,  0x99, 0x0,  0x19, 0x0,  0x0,  0x0,  0x7,  0x0,
                                    0x2D, 0x0,  0x32, 0x0,  0x64, 0x0,  0x0,  0x0,  0x0};
u8 D_80800CF0_chflowerbaddie[20] = {0x0, 0x2B, 0x1, 0x66, 0x1,  0x99, 0x0,  0xE,  0x0, 0x1E,
                                    0x0, 0x3C, 0x0, 0x20, 0xFF, 0x80, 0xFF, 0xBE, 0x0, 0x0};
u8 D_80800D04_chflowerbaddie[20] = {0x0, 0x2B, 0x1, 0x99, 0x1,  0xCC, 0x0,  0xE,  0x0, 0x3C,
                                    0x0, 0x64, 0x0, 0x20, 0x80, 0xC0, 0xFF, 0xBE, 0x0, 0x0};
u8 D_80800D18_chflowerbaddie[16] = {0x0,  0x2B, 0x1,  0x33, 0x1, 0x66, 0x0, 0x20,
                                    0xFF, 0xFF, 0x40, 0xE0, 0x0, 0x0,  0x0, 0x0};
u8 D_80800D28_chflowerbaddie[24] = {0x3, 0x6,  0x0, 0x13, 0x3, 0xFF, 0x0,  0xD,
                                    0x1, 0x26, 0x1, 0x40, 0x0, 0x16, 0x3A, 0x98,
                                    0x0, 0x3,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0};
