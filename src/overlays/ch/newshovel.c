#include "common.h"

extern int D_80800FB4_chnewshovel[];
extern u8 D_80801024_chnewshovel[];
extern u8 D_80801018_chnewshovel[];
extern u8 D_80801008_chnewshovel[];
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 disabled : 1;
    u32 pad_2 : 29;
} ShovelFlags;
typedef struct {
    u8 pad_0[0x64];
    u32 pad_1 : 2;
    u32 joy_controlled : 1;
    u32 pad_2 : 29;
} ShovelActorFlags;
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern s32 func_8010C3A8(Actor *, s32, f32);
extern void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
typedef struct {
    u8 pad_0[0x64];
    u32 : 2;
    u32 joy_controlled : 1;
    u32 : 29;
} ShovelFlags1274;
typedef struct {
    u8 pad_0[0x10];
    s16 unk_10;
} ShovelState1274;
extern void *func_80100094(Actor *, u32);
extern s32 D_80801064_chnewshovel[];
extern void func_800C4B7C(s32);
extern void _subaddieaudioquick_entrypoint_2();
extern s32 func_800DC298(f32);
extern u8 D_80801074_chnewshovel[];
extern void *func_800B53A4(s32);
extern void *func_800BABB8(void *, f32 *, f32 *, f32, void *);
extern u32 D_808010B0_chnewshovel[];
typedef struct {
    u8 pad_0[0x78];
    u32 pad_1 : 29;
    u32 unk_78 : 1;
    u32 pad_2 : 2;
} Mass64NewShovelFlags;
extern u8 D_80800FFC_chnewshovel[];
extern void _suexpression_entrypoint_14(void *, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, void *, s32);
extern u8 D_80801034_chnewshovel[];
extern u8 D_8080104C_chnewshovel[];
extern f32 func_800EEB40(f32 *, f32 *);
void func_80800CC4_chnewshovel();
void func_80800D18_chnewshovel();
int func_808006B0_chnewshovel();
s32 func_808007F8_chnewshovel();
s32 func_80800930_chnewshovel();
s32 func_80800B5C_chnewshovel();
s32 func_80800C58_chnewshovel();
extern void func_801018A4(), func_80102EC0(), func_80107C2C(), func_80108ED0(),
    func_8080004C_chnewshovel(), func_80800310_chnewshovel();

int chnewshovel_entrypoint_0()
{
    return (int) &D_80800FB4_chnewshovel;
}

s32 func_8080000C_chnewshovel(actor)
s32 actor;
{
    s32 state = func_80100094(actor, 0);
    _subaddierouteDll_entrypoint_3(actor, state, actor + 4);
    func_808007F8_chnewshovel(actor, 0);
}

s32 func_80800BC0_chnewshovel();

s32 func_80800610_chnewshovel();

void func_80800570_chnewshovel();

// Main AI. State 6 hops back to the home point.
void func_8080004C_chnewshovel(actor) Actor *actor;
{
    s32 move_flags;
    u8 *state;

    state = func_80100094(actor, 0);

if (!((Mass64NewShovelFlags *) actor)->unk_78) {
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), actor->unk0, 0);
    move_flags = func_80800930_chnewshovel(actor);
    func_80800570_chnewshovel(actor);
    switch (actor->unk70_10) {
        case 1:
            if (func_80800610_chnewshovel(actor)) {
                func_808006B0_chnewshovel(actor, 2);
            }
            break;
        case 2:
            if (func_80101DDC(actor)) {
                func_808006B0_chnewshovel(actor, func_80800610_chnewshovel(actor) ? 3 : 1);
            }
            break;
        case 3:
            func_80800BC0_chnewshovel(actor);
            if (func_80800610_chnewshovel(actor)) {
                func_800F5A00(func_8010D290(0x10000), (f32 *) actor->actorData);
                if (*(s16 *) (state + 0xC) == 2) {
                    func_808006B0_chnewshovel(actor, func_80800C58_chnewshovel(actor) ? 4 : 3);
                }
            } else if (*(s16 *) (state + 0xC) == 2) {
                func_808006B0_chnewshovel(actor, 6);
            }
            break;
        case 4:
            if (func_80800610_chnewshovel(actor)) {
                func_800F5A00(func_8010D290(0x10000), (f32 *) actor->actorData);
            }
            if (move_flags & 8) {
                ((f32 *) actor->actorData)[3] = 0.0f;
            }
            if (*(s16 *) (state + 0xC) == 2) {
                func_808006B0_chnewshovel(actor, 5);
            }
            break;
        case 5:
            if (func_80101DDC(actor)) {
                func_808006B0_chnewshovel(actor,
                                          func_80800610_chnewshovel(actor)
                                              ? 3
                                              : (func_80800B5C_chnewshovel(actor) ? 1 : 6));
            }
            break;
        case 6:
            if (func_80800610_chnewshovel(actor)) {
                if (*(s16 *) (state + 0xC) == 2) {
                    func_808006B0_chnewshovel(actor, 3);
                }
            } else {
                if (func_80800B5C_chnewshovel(actor)) {
                    ((f32 *) actor->actorData)[3] *= 0.9f;
                }
                if (*(s16 *) (state + 0xC) == 2) {
                    func_808006B0_chnewshovel(actor, func_80800B5C_chnewshovel(actor) ? 1 : 6);
                }
            }
    }
}

}

void func_80800310_chnewshovel(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}
int func_80800330_chnewshovel(Actor *actor, s32 msg, s32 *msg_data)
{
    void *expression;
    s32 *unk_0;
    s32 pad[2];
    f32 unk_1;
    f32 unk_2;

switch (msg) {
    case 0x1F:
        func_801015D0(actor);
        func_800DF744(3, 1);
        break;
    case 0x95:
        expression = _suexpression_entrypoint_7(actor, 1, 0x5A);
        _suexpression_entrypoint_12(expression, 0x428C0000, 0x41200000);
        _suexpression_entrypoint_14(expression, 1.0f, 1.0f);
        _subaddierouteDll_entrypoint_1(actor);
        break;
    case 0x40:
        unk_0 = *(s32 **) &msg_data;
        _chskeletonexplode_entrypoint_8(actor, *unk_0 + 4);
        func_8010A570(actor);
        _subaddieaudioquick_entrypoint_2(actor, (u8 *) actor + 4, D_80800FFC_chnewshovel);
        _subaddiejoy_entrypoint_10(actor, 0x3F800000, 0x3E800000);
        ((u8 *) actor)[0x64] &= ~1;
        break;
    case 0xF:
        _chskeletonexplode_entrypoint_3(func_80106790(func_80101080()), 3, 2);
        if (!func_80107070(actor, 3)) {
            func_800FFAB0(actor);
        }
        break;
    case 0x8F:
        if (*(s32 **) &msg_data == 0) {
            func_808006B0_chnewshovel(actor, 1);
        }
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(actor)) {
            if (!func_80107070(actor, 1)) {
                _subaddiefade_entrypoint_3(actor);
            }
        } else {
            func_808006B0_chnewshovel(actor, 6);
        }
        break;
    case 0x38:
        return func_80800DC8_chnewshovel(actor);
    case 0x94:
        actor = _suexpression_entrypoint_20(actor);
        if (actor == 0) {
            return 0;
        }
        func_800EFD24(&unk_2);
        _suexpression_entrypoint_13(actor, &unk_1, &unk_2);
        func_80101010(&unk_2);
        break;
    default:
        return 0;
    case 1:
        break;
}

return 1;
}

void func_80800570_chnewshovel(Actor *actor)
{
    s32 anim_id;

    anim_id = func_801022E4();

if (anim_id != 0x1BA) {
    if (anim_id == 0x1BB) {
        _subaddieaudioquick_entrypoint_4(actor, (u8 *) actor + 4, &D_80801008_chnewshovel,
                                         &D_80801018_chnewshovel);
        if (func_80101E14(actor, 0x3F333333) != 0) {
            func_80800CC4_chnewshovel(actor);
            func_80800D18_chnewshovel(actor);
        }
    }
}

else
{
    _subaddieaudioquick_entrypoint_3(actor, (u8 *) actor + 4, &D_80801024_chnewshovel,
                                     0x3ECCCCCD);
}
}

// Chase test: true when the player can be chased.
s32 func_80800610_chnewshovel(Actor *actor)
{
    s32 player;
    if (((ShovelFlags *) actor)->disabled)
        return 1;
    player = func_8010D290(0x10000);
    if (player == -1)
        return 0;
    if (!func_800F6478(player))
        return 0;
    if (!func_8010C550(actor, player))
        return 0;
    if (!_suchase_entrypoint_1(actor))
        return 0;
    return 1;
}

int func_808006B0_chnewshovel(actor, state)
Actor *actor;
s32 state;
{
    *(s16 *) ((u8 *) func_80100094(actor, 0) + 0x10) = 0;

switch (state) {
    case 1:
        func_80102424(actor, state);
        func_808007F8_chnewshovel(actor, 0);
        break;
    case 2:
        func_80102424(actor, state);
        break;
    case 3:
        func_80102424(actor, state);
        func_808007F8_chnewshovel(actor, 1);
        break;
    case 4:
        func_800F5A00(func_8010D290(0x10000), (u8 *) actor + 0x18);
        func_80102424(actor, state);
        func_808007F8_chnewshovel(actor, 3);
        break;
    case 5:
        func_80102424(actor, state);
        func_808007F8_chnewshovel(actor, 0);
        break;
    case 6:
        func_80107B70(actor, (u8 *) actor + 0x18);
        func_80102424(actor, state);
        func_808007F8_chnewshovel(actor, 1);
        break;
    default:
        func_80102424(actor, state);
}

return 1;
}

// Sets the hop phase: 1/3 launch a low/high hop, 2 landing (dust and thud), 0 stand still.
s32 func_808007F8_chnewshovel(actor, phase)
Actor *actor;
s32 phase;
{
    u8 *state;
    f32 speed;

    state = func_80100094(actor, 0);

switch (phase) {
    case 0:
        speed = 0;
        *(f32 *) ((u8 *) actor + 0x24) = speed;
        *(f32 *) ((u8 *) actor + 0x2C) = speed;
        break;
    case 1:
        speed = actor->scale * 450.0f;
        func_800EFA4C((f32 *) ((u8 *) actor + 0x28), 0.0f, speed, 0.0f);
        *(f32 *) ((u8 *) actor + 0x34) = (-speed - speed) / 0.6f;
        break;
    case 2:
        func_80800D18_chnewshovel(actor);
        func_80800CC4_chnewshovel(actor);
        speed = 0;
        *(f32 *) ((u8 *) actor + 0x24) = speed;
        *(f32 *) ((u8 *) actor + 0x2C) = speed;
        break;
    case 3:
        speed = actor->scale * 550.0f;
        func_800EFA4C((f32 *) ((u8 *) actor + 0x28), 0.0f, speed, 0.0f);
        *(f32 *) ((u8 *) actor + 0x34) = (-speed - speed) / 0.765f;
}

*(u16 *) (state + 0xC) = phase;
return 1;
}

s32 func_80800A50_chnewshovel();

s32 func_80800930_chnewshovel(actor)
Actor *actor;
{
    u8 *state;
    s32 move_flags;
    state = func_80100094(actor, 0);
    move_flags = 0;

switch (*(s16 *) (state + 0xC)) {
    case 0:
    case 2:
        break;
    case 1:
        *(f32 *) ((u8 *) actor + 0x24) =
            func_800F3780(func_80101F24(actor), D_80801034_chnewshovel, 3) * 550.0f;
        move_flags = func_80800A50_chnewshovel(actor);
        if (func_80101DDC(actor) && (move_flags & 8))
            func_808007F8_chnewshovel(actor, 2);
        break;
    case 3:
        *(f32 *) ((u8 *) actor + 0x24) =
            func_800F3780(func_80101F24(actor), D_8080104C_chnewshovel, 3) * 600.0f;
        move_flags = func_80800A50_chnewshovel(actor);
        if (func_80101DDC(actor) && (move_flags & 8))
            func_808007F8_chnewshovel(actor, 2);
}

return move_flags;
}

s32 func_80800A50_chnewshovel(Actor *actor)
{
    s32 move_flags;
    void *state;
    f32 speed;
    state = (void *) func_80100094(actor, 0);

if (((ShovelActorFlags *) actor)->joy_controlled) {
    speed = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
    func_80102BF8(actor, 0.12f, 5.0f, 180.0f);
    move_flags = func_8010C3A8(actor, 0x200025, speed);
    move_flags |= func_8010B990(actor, 0x4004);
} else {

actor->unk54 = func_80102D78(actor, (f32 *) actor->actorData);
_subaddierouteDll_entrypoint_7(actor, state, actor->rotation[1], actor->unk54, 200.0f,
                               0x5000);
func_80102BF8(actor, 0.12f, 5.0f, 180.0f);
move_flags = func_8010B990(actor, 0x325);
move_flags |= func_8010B990(actor, 0x4004);
}
return move_flags;
}

// True when the actor is close to its home point.
s32 func_80800B5C_chnewshovel(actor)
Actor *actor;
{
    f32 home[3];

    if (func_80107B70(actor, home)) {
        return func_800EEB40(actor->position, home) < 10000.0f;
    }
    return 0;
}

s32 func_80800BC0_chnewshovel(Actor *actor)
{
    ShovelState1274 *state;

    state = func_80100094(actor, 0);
    if (!((ShovelFlags1274 *) actor)->joy_controlled)
        return 0;
    if (_subaddiejoy_entrypoint_6(actor, 0) == 1 || _subaddiejoy_entrypoint_6(actor, 1) == 1 ||
        _subaddiejoy_entrypoint_7(actor, 0) == 1)
        state->unk_10 = 1;
    return state->unk_10;
}

s32 func_80800C58_chnewshovel(actor)
Actor *actor;
{
    f32 *target = (f32 *) actor->actorData;
    if (((ShovelActorFlags *) actor)->joy_controlled) {
        return func_80800BC0_chnewshovel(actor);
    } else {
        if (func_800EEB40(actor->position, target) > 40000.0f)
            return 0;
        return 1;
    }
}

// Landing thud.
void func_80800CC4_chnewshovel(actor) u8 *actor;
{
    func_800C4B7C(func_800DC298(0.5f) ? 0x517 : 0x518);
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, &D_80801064_chnewshovel);
}

// Landing dust burst.
void func_80800D18_chnewshovel(actor) Actor *actor;
{
    f32 pos[3];
    u8 color[4];
    void *emitter;

    if (actor->unk7C_12) {
        func_800F2EA0(color, &actor->pad98, actor);
        color[3] = 0xFF;
        func_800EE7F8(pos, actor->position);
        pos[1] -= 20.0f;
        emitter = func_800B53A4(3);
        func_800BABB8(emitter, actor->position, pos, 0.8f, D_80801074_chnewshovel);
        func_800BAB60(emitter, color);
        func_800BA22C(emitter, 3);
    }
}

int func_80800DC8_chnewshovel(s32 actor)
{
    func_80101074(&D_808010B0_chnewshovel);
    return 2;
}

// TU-NOTE: the overlay's .data is defined in C here, values taken from the ROM. The tables point to
// functions of this file, and IDO's assembler schedules some of them differently unless the tables
// are in the same unit. D_80800FB4_chnewshovel is declared as int[], D_80801064_chnewshovel as s32[],
// D_808010B0_chnewshovel as u32[] to match the object.
u8 D_80800F50_chnewshovel[80] = {
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x3F, 0x70, 0xA3, 0xD7, 0x1, 0xB8, 0x0, 0x44,
    0x3F, 0x70, 0xA3, 0xD7, 0x1, 0xB8, 0x0, 0x42, 0x3F, 0x19, 0x99, 0x9A, 0x1, 0xB9, 0x0, 0x42,
    0x3F, 0x66, 0x66, 0x66, 0x1, 0xBA, 0x0, 0x2,  0x40, 0x40, 0x0,  0x0,  0x1, 0xBB, 0x0, 0x2,
    0x3F, 0x19, 0x99, 0x9A, 0x1, 0xB9, 0x0, 0x42, 0x3F, 0x70, 0xA3, 0xD7, 0x1, 0xB8, 0x0, 0x44,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x0,  0x0, 0x0,  0x3F, 0x70, 0xA3, 0xD7, 0x1, 0xB8, 0x0, 0x44};
u8 D_80800FA0_chnewshovel[20] = {0x0, 0x1, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0, 0x7,
                                 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x9, 0x0, 0x0};
int D_80800FB4_chnewshovel[18] = {0xA011A,
                                  0x66F0001,
                                  (u32) &D_80800F50_chnewshovel,
                                  (u32) func_8080004C_chnewshovel,
                                  (u32) func_80102EC0,
                                  (u32) func_801018A4,
                                  0x7D00000,
                                  0x3F19999A,
                                  0x0,
                                  0x43050321,
                                  (u32) func_80800310_chnewshovel,
                                  (u32) func_80108ED0,
                                  0x140000,
                                  (u32) func_8080000C_chnewshovel,
                                  (u32) func_80107C2C,
                                  -0x7FDFEBE3,
                                  (u32) func_80800330_chnewshovel,
                                  (u32) &D_80800FA0_chnewshovel};
u8 D_80800FFC_chnewshovel[12] = {0x0, 0x13, 0x4, 0x7, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0};
u8 D_80801008_chnewshovel[16] = {0x0, 0x13, 0x4, 0x1D, 0x0,  0xD,  0x1, 0x4C,
                                 0x1, 0x66, 0x0, 0x16, 0x3A, 0x98, 0x0, 0x0};
u8 D_80801018_chnewshovel[12] = {0x3E, 0x19, 0x99, 0x9A, 0x3E, 0xCC,
                                 0xCC, 0xCD, 0xBF, 0x80, 0x0,  0x0};
u8 D_80801024_chnewshovel[16] = {0x0, 0x13, 0x3, 0xFF, 0x0,  0xD,  0x0, 0xB3,
                                 0x0, 0xCC, 0x0, 0x16, 0x3E, 0x80, 0x0, 0x0};
u8 D_80801034_chnewshovel[24] = {0x0,  0x0,  0x0, 0x0, 0x3E, 0x19, 0x99, 0x9A,
                                 0x3F, 0x0,  0x0, 0x0, 0x3F, 0x80, 0x0,  0x0,
                                 0x3F, 0x80, 0x0, 0x0, 0x3E, 0x19, 0x99, 0x9A};
u8 D_8080104C_chnewshovel[24] = {0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0,  0x0,  0x3F, 0x0, 0x0, 0x0,
                                 0x3F, 0x80, 0x0, 0x0, 0x3F, 0x59, 0x99, 0x9A, 0x0,  0x0, 0x0, 0x0};
s32 D_80801064_chnewshovel[4] = {0x21000D, 0xF3010C, 0x164650, 0x0};
u8 D_80801074_chnewshovel[60] = {
    0x0,  0x1D, 0x6,  0xA4, 0x0,  0x16, 0x10, 0x0, 0x0,  0x1B, 0xFD, 0xA8, 0xFD, 0xA8, 0x0,
    0x27, 0xFD, 0xA8, 0xFD, 0xA8, 0x2,  0x58, 0x2, 0x58, 0x0,  0x2D, 0x0,  0x96, 0x0,  0xC8,
    0x0,  0x22, 0x0,  0xC,  0x0,  0x19, 0x0,  0x0, 0x0,  0x0,  0x0,  0x2B, 0x0,  0x99, 0x0,
    0xCC, 0x0,  0x15, 0x0,  0x0,  0x0,  0xB3, 0x0, 0xE,  0x0,  0xA,  0x0,  0xF,  0x0,  0x0};
u32 D_808010B0_chnewshovel[8] = {0x3, 0x3F800000, 0x10000, 0x6B, 0x3FB33333, 0x2120000, 0x0, 0x0};
