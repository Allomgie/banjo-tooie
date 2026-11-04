#include "common.h"

#define AF(p, i) (*(f32 *) &(p)->actorData[i])
extern int D_80800B1C_chbadbeehive[];
extern void *func_80100094(Actor *, u32);
extern void func_800EE7F8(f32 *, f32 *);
extern u8 D_80800AEC_chbadbeehive[];
extern u8 D_80800B64_chbadbeehive[];
extern u8 D_80800B74_chbadbeehive[];
extern s32 func_80101E14(Actor *, f32);
extern f32 func_80101F24(Actor *);
extern void func_800C31DC(s32, f32);
extern void func_800C3584(s32, f32, f32);
extern s32 D_80800ABC_chbadbeehive[];
extern s32 D_80800AFC_chbadbeehive[];
extern s32 D_80800B0C_chbadbeehive[];
extern s32 D_80800BE4_chbadbeehive[];
extern Actor *func_80106790();
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void _chexploder_entrypoint_15(Actor *, s32, f32);
extern u8 D_8012762C;
typedef struct {
    u8 pad_0[0x72];
    u16 state : 6;
    u16 rest : 10;
} BHState;
typedef struct {
    u8 pad_0[0x64];
    u32 a : 2;
    u32 b : 1;
    u32 c : 29;
} BHBits;
typedef struct {
    s32 a;
    s32 b;
    s32 c;
} BH12;
typedef struct {
    u8 pad_0[0x78];
    u32 a : 29;
    u32 f : 1;
    u32 b : 2;
} BH78;
extern u8 D_80800B90_chbadbeehive[];
extern u8 D_80800BD8_chbadbeehive[];
extern f32 func_800F3780(f32, u8 *, s32);
extern f32 func_80102D78(Actor *, u32 *);
extern f32 func_800D8FF8(void);
extern f32 func_800F15F8(f32, f32, f32);
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern void func_801026CC(Actor *, BH12, f32);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern void func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, u8 *, f32, f32, f32, s32);
extern void _subaddierouteDll_entrypoint_5(Actor *, u8 *, f32, f32, f32, f32);
extern s32 func_800DC298(f32);
extern s32 func_800EFFB4();
extern void func_8010D254(u32 *);
extern u8 func_800D9078(f32 *);
extern void func_8010C908(Actor *, f32 *);
void func_808008F8_chbadbeehive();

int chbadbeehive_entrypoint_0()
{
    return (int) &D_80800B1C_chbadbeehive;
}

// Walking speed for the current level (D_8012762C).
f32 func_8080000C_chbadbeehive(void)
{
    switch (D_8012762C) {
        case 19:
            return 420.0f;
        case 16:
            return 440.0f;
        case 15:
            return 460.0f;
        case 18:
            return 480.0f;
        case 20:
            return 500.0f;
        case 21:
            return 550.0f;
        case 22:
            return 600.0f;
        case 23:
            return 650.0f;
        case 24:
            return 700.0f;
        case 25:
            return 630.0f;
        case 26:
            return 700.0f;
        default:
            return 0.0f;
    }
}

// Init: sets up the route and the per-level speed.
void func_808000EC_chbadbeehive(Actor *actor)
{
    f32 *route;

    route = func_80100094(actor, 0);
    _subaddierouteDll_entrypoint_3(actor, route, actor->position);
    *(f32 *) &actor->actorData[3] = 0.0f;
    *(f32 *) &actor->actorData[5] = 0.0f;
    func_800EE7F8(route + 4, actor->position);
    *(f32 *) &actor->actorData[6] = func_8080000C_chbadbeehive();
}

// Buzz loop (sfx 0x447), kept in step with the animation.
void func_80800158_chbadbeehive(Actor *actor)
{
    s32 restart_buzz = 0;

    switch (func_801022E4(actor)) {
        case 0x1C7:
            if (func_80101E14(actor, 0.48f) || func_80101E14(actor, 0.98f)) {
                _subaddieaudioquick_entrypoint_2(actor, actor->position,
                                                 D_80800AEC_chbadbeehive);
            }
            if (func_80101E4C(actor, D_80800B74_chbadbeehive))
                restart_buzz = 1;
            break;
        case 0x54:
            if (func_80101E4C(actor, D_80800B64_chbadbeehive))
                restart_buzz = 1;
    }
    if (restart_buzz) {
        func_800C3CE8(actor->unk5F);
        func_800C301C(actor->unk5F, 0x447);
        func_800C3058(actor->unk5F, 0x2EE0);
        func_800C31DC(actor->unk5F, func_80101F24(actor) + 0.5f);
        func_800C35E8(actor->unk5F, actor->position);
        func_800C3584(actor->unk5F, 300.0f, 1500.0f);
        func_800C330C(actor->unk5F, 3);
        func_800C3BDC(actor->unk5F);
    }
}

// Update: state machine for standing still and wandering along routes.
void func_80800298_chbadbeehive(Actor *actor)
{
    u8 *route;
    f32 anim_speed;
    f32 stick;

    route = func_80100094(actor, 0);
    anim_speed = func_800F3780(func_80101F24(actor), D_80800B90_chbadbeehive, 9);
    if (((BH78 *) actor)->f) {
        return;
    }
    func_800D9078(&actor->unk58);
    switch (((BHState *) actor)->state) {
        case 1:
            if (((BHBits *) actor)->b) {
                if (0.1f < _subaddiejoy_entrypoint_9(actor, 0, 0)) {
                    func_808008F8_chbadbeehive(actor, 2);
                }
            } else if (func_80800990_chbadbeehive(actor)) {
                func_808008F8_chbadbeehive(actor, 2);
            }
            break;
        case 2:
            func_801026CC(actor, *(BH12 *) D_80800BD8_chbadbeehive, AF(actor, 3));
            func_8010D254(actor->actorData);
            if (((BHBits *) actor)->b) {
                stick = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
                AF(actor, 3) = AF(actor, 5);
                func_80102BF8(actor, 0.2f, 8.0f, 500.0f);
                func_8010C3A8(actor, 0x205015, stick * anim_speed);
                if (_subaddiejoy_entrypoint_9(actor, 0, 0) == 0.0f) {
                    func_808008F8_chbadbeehive(actor, 1);
                }
            } else {
                if (_subaddierouteDll_entrypoint_4(actor)) {
                    actor->unk54 = func_80102D78(actor, actor->actorData);
                    _subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1],
                                                   actor->unk54, 200.0f, 0x5800);
                    *(s32 *) (route + 0xC) = *(u16 *) (route + 6);
                }
                _subaddierouteDll_entrypoint_5(actor, route, *(f32 *) (route + 0xC), 0.15f,
                                               8.0f, 200.0f);
                AF(actor, 3) =
                    func_800F15F8(AF(actor, 3), AF(actor, 5), func_800D8FF8() * 400.0f);
                func_8010C3A8(actor, 0x305115, anim_speed);
                if (_subaddierouteDll_entrypoint_4(actor) && func_800DC298(0.2f) &&
                    (!func_8010C9B0(actor->position, 1000) || !func_8010C500(actor))) {
                    func_808008F8_chbadbeehive(actor, 3);
                }
            }
            break;
        case 3:
            func_801026CC(actor, *(BH12 *) D_80800BD8_chbadbeehive, AF(actor, 3));
            if (func_80800990_chbadbeehive(actor)) {
                func_808008F8_chbadbeehive(actor, 2);
            }
            if (_subaddierouteDll_entrypoint_4(actor)) {
                actor->unk54 = func_80102D78(actor, actor->actorData);
                _subaddierouteDll_entrypoint_7(actor, route, actor->rotation[1],
                                               actor->unk54, 200.0f, 0x5800);
                *(s32 *) (route + 0xC) = *(u16 *) (route + 6);
            }
            _subaddierouteDll_entrypoint_5(actor, route, *(f32 *) (route + 0xC), 0.15f, 8.0f,
                                           200.0f);
            AF(actor, 3) =
                func_800F15F8(AF(actor, 3), AF(actor, 5), func_800D8FF8() * 400.0f);
            func_8010C3A8(actor, 0x305115, anim_speed);
            if (_subaddierouteDll_entrypoint_4(actor) && func_800DC298(0.2f) &&
                func_800EFFB4(actor->position, 0x42C80000, route + 0x10)) {
                func_808008F8_chbadbeehive(actor, 1);
            }
            break;
    }
    if (((BHState *) actor)->state < 4) {
        func_8010C908(actor, actor->position);
    }
    func_80800158_chbadbeehive(actor);
}

s32 func_8080070C_chbadbeehive(Actor *actor, s32 msg, Actor **attacker)
{
    f32 drop_pos[3];
    Actor *unk_0;

    switch (msg) {
        case 0x95:
            actor->unk5F = func_800C2E04();
            _subaddierouteDll_entrypoint_1(actor);
            break;
        case 0x40: // egg hit
            func_800EE88C(drop_pos, (*attacker)->position);
            drop_pos[1] = actor->position[1];
            _chexploder_entrypoint_3(actor, drop_pos, 0x20);
            break;
        case 0x90: // explosion: burst into particles, drop honeycomb
            unk_0 = func_80106790(func_80101080());
            _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800AFC_chbadbeehive);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, &D_80800B0C_chbadbeehive);
            func_800BBCB8(actor->position, NULL, actor->scale, 1, &D_80800BE4_chbadbeehive);
            if (!func_80107070(actor, 3))
                func_800FFAB0(actor);
            _chexploder_entrypoint_15(unk_0, 2, 1.0f);
            _chexploder_entrypoint_9(unk_0, 3, 2);
            break;
        case 1:
            func_808008F8_chbadbeehive(actor, 2);
            break;
        case 2:
            if (!_subaddieDll_entrypoint_3(actor)) {
                if (!func_80107070(actor, 1))
                    _subaddiefade_entrypoint_3(actor);
            } else {
                func_808008F8_chbadbeehive(actor, 3);
            }
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, 2);
            break;
        case 0x38:
            func_80101074(&D_80800ABC_chbadbeehive);
            return 4;
        default:
            return 0;
    }
    return 1;
}

void func_808008F0_chbadbeehive(s32 arg0)
{
}

// Switches to a new state.
// Matching: K&R-style definition and same-type casts, needed for the match.
void func_808008F8_chbadbeehive(actor, new_state) u8 *actor;
s32 new_state;
{
    s32 route;

    route = func_80100094(actor, 0);
    func_80102424(actor, new_state);

switch (new_state) {
    case 2:
        *(f32 *) ((s8 *) actor + 0x2C) = (f32) *(f32 *) ((s8 *) actor + 0x30);
        return;
    case 3:
        func_800EE7F8(actor + 0x18, route + 0x10);
        *(f32 *) ((s8 *) actor + 0x2C) = (f32) (*(f32 *) ((s8 *) actor + 0x2C) * 0.5f);

    case 1:
        return;
}

}

int func_80800990_chbadbeehive(f32 actor[3])
{
    if (actor[0x16] > 0.0f) {
        return 0;
    }

if (_subaddierouteDll_entrypoint_4(actor) && func_8010C9B0(&actor[1], 1000) != 0 &&
    _suchase_entrypoint_1(actor) != 0 && func_8010C500(actor) != 0) {
    return 1;
}

return 0;
}

// TU-NOTE: the overlay .data is defined in C here; its tables point to functions of this file.
extern void func_80105834();
extern void func_801018A4();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800A70_chbadbeehive[5] = {0x10000, 0x40000, 0x40000, 0x50000, 0x60000};
u32 D_80800A84_chbadbeehive[14] = {0x0,       0x0,        0x3F266666, 0x540001,   0x3FC00000,
                                   0x1C70401, 0x3FC00000, 0x1C70001,  0x3FC00000, 0x1C70000,
                                   0x0,       0x0,        0x3F266666, 0x540001};
s32 D_80800ABC_chbadbeehive[12] = {0x3,  0x40400000, 0x2A0000, 0x2A, 0x40333333, 0x2B0000,
                                   0x2B, 0x40266666, 0x2C0000, 0x2C, 0x4019999A, 0x2D0000};
u8 D_80800AEC_chbadbeehive[16] = {0x0, 0x13, 0x4, 0x4,  0x0,  0xD,  0x0, 0xF3,
                                  0x1, 0xC,  0x0, 0x16, 0x6D, 0x60, 0x0, 0x0};
s32 D_80800AFC_chbadbeehive[4] = {0x13040B, 0xA0100, 0x166D60, 0x0};
s32 D_80800B0C_chbadbeehive[4] = {0x130407, 0xA0100, 0x166D60, 0x0};
int D_80800B1C_chbadbeehive[18] = {0x22F019A,
                                   0x6150001,
                                   (u32) &D_80800A84_chbadbeehive,
                                   (u32) func_80800298_chbadbeehive,
                                   (u32) func_80105834,
                                   (u32) func_801018A4,
                                   0x7D00000,
                                   0x40000000,
                                   0x0,
                                   0x2048329,
                                   (u32) func_808008F0_chbadbeehive,
                                   (u32) func_80108ED0,
                                   0x1C0000,
                                   (u32) func_808000EC_chbadbeehive,
                                   (u32) func_80107C2C,
                                   -0x7FCDAFE3,
                                   (u32) func_8080070C_chbadbeehive,
                                   (u32) &D_80800A70_chbadbeehive};
u8 D_80800B64_chbadbeehive[16] = {0x3E, 0xE6, 0x66, 0x66, 0x3F, 0xC,  0xCC, 0xCD,
                                  0x3F, 0x19, 0x99, 0x9A, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800B74_chbadbeehive[28] = {0x3E, 0xE6, 0x66, 0x66, 0x3F, 0xC,  0xCC, 0xCD, 0x3F, 0x19,
                                  0x99, 0x9A, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x73, 0x33, 0x33,
                                  0x0,  0x0,  0x0,  0x0,  0xBF, 0x80, 0x0,  0x0};
u8 D_80800B90_chbadbeehive[72] = {
    0x0,  0x0,  0x0,  0x0,  0x3E, 0x99, 0x99, 0x9A, 0x3D, 0x4C, 0xCC, 0xCD, 0x3F, 0x19, 0x99,
    0x9A, 0x3E, 0x80, 0x0,  0x0,  0x3F, 0x99, 0x99, 0x9A, 0x3E, 0xCC, 0xCC, 0xCD, 0x3F, 0x19,
    0x99, 0x9A, 0x3E, 0xF5, 0xC2, 0x8F, 0x3E, 0x99, 0x99, 0x9A, 0x3F, 0x5,  0x1E, 0xB8, 0x3F,
    0x19, 0x99, 0x9A, 0x3F, 0x40, 0x0,  0x0,  0x3F, 0x99, 0x99, 0x9A, 0x3F, 0x73, 0x33, 0x33,
    0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x80, 0x0,  0x0,  0x3E, 0x99, 0x99, 0x9A};
u8 D_80800BD8_chbadbeehive[12] = {0x40, 0x6,  0x66, 0x66, 0xBB, 0x83,
                                  0x12, 0x6F, 0x3E, 0xCC, 0xCC, 0xCD};
s32 D_80800BE4_chbadbeehive[19] = {
    0x1D09C9, 0x160238,  0x150013,  0x660020,  -0x5050588, 0x1E000A, 0x14002C, 0x14, 0x0, 0x320000,
    0x2B0133, 0x1660022, 0x2000280, 0x4000480, 0x180000,   0x80,     0x800000, 0x0,  0x0};
