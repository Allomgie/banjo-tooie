// Proximity egg (mine): lands, arms, waits for a player or actor to come near (with rumble), then
// explodes; messages can detonate or remove it.
#include "common.h"

extern int D_80800CE0_cheggproximity[];
extern Actor *_suegg_entrypoint_11(s32, void *, s32);
extern f32 func_80013B7C(f32, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _suegg_entrypoint_1(Actor *, f32);
// Proximity egg (mine): lands, arms, explodes when a player comes near.
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 8;
    u32 triggered : 1;
    u32 pad_2 : 23;
} EggProximityState;
typedef struct {
    u8 pad_0[0xA4];
    s32 flag;
} EggProximityExplosion;
extern void *func_80100094(Actor *, s32);
typedef struct {
    u8 unused[0x78];
    u16 unused_mode : 14;
    u16 mode : 2;
} ProximityRenderMode;
extern u8 func_800D9078();
typedef struct {
    u8 pad_0[0x40];
    s32 state[8];
    s32 prev_state[8];
    f32 rumble_timer[8];
    u8 pad_1[4];
    s32 flag;
} EggPlayerTimers1559;
extern int func_800F5898(void);
extern void *func_800F53D0(s32);
extern void _bamotor_entrypoint_0(void *, f32, f32);
typedef struct {
    u8 pad[0x40];
    s32 states[24];
    s32 player;
    s32 pad_A4;
    s32 dialog;
} ProximityEggState;
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _fxegg_entrypoint_5(f32 *, f32 *, f32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 8;
    u32 triggered : 1;
    u32 unk_39_40 : 1;
    u32 pad_2 : 22;
} ProximityFlags1834;
extern void _cheggproximity_entrypoint_2(void);
extern void _suegg_entrypoint_23();
extern void func_80101FDC();
extern s32 D_80800D28_cheggproximity[];
typedef struct {
    u8 pad_0[0x40];
    s32 state[8];
    s32 prev_state[8];
    u8 pad_1[0x28];
    s32 dialog;
} ProximityEggPayload921;
extern s32 func_800F6438(s32);
extern s32 func_800F6CC8(s32);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
typedef struct {
    f32 dy[8];
    f32 dist[8];
    s32 state[8];
    s32 prev[8];
    u8 pad80[0x20];
    s32 best;
    s32 flag;
} EggProx;
typedef struct {
    u8 pad[0x3A];
    s16 owner;
} EggProxLocal;
void func_80800AFC_cheggproximity();
s32 func_80800BF4_cheggproximity();
int func_8080048C_cheggproximity();
void func_80800718_cheggproximity();
void func_80800874_cheggproximity();

int *cheggproximity_entrypoint_0()
{
    return &D_80800CE0_cheggproximity;
}

Actor *cheggproximity_entrypoint_1(s32 param_0, void *param_1, f32 *velocity, s32 param_3)
{
    Actor *egg;
    _sueggmove_entrypoint_10(param_0, param_1);
    egg = _suegg_entrypoint_11(0x160, param_1, param_3);
    egg->scale = 0.25f;
    egg->rotation[1] = func_80013B7C(velocity[0], velocity[2]);
    _sueggmove_entrypoint_5(egg, 0);
    _sueggmove_entrypoint_6(egg, 0.0f, -22000.0f);
    _sueggmove_entrypoint_7(egg, velocity);
    _suegg_entrypoint_1(egg, 30.0f);
    return egg;
}

// Message handler: 0x4F removes, 0x40 explodes, 0x45/0x78 set the flag.
s32 func_808000A8_cheggproximity(Actor *actor, s32 msg, s32 param_2)
{
    EggProximityState *base;
    base = func_80100094(actor, 0);
    switch (msg) {
        case 0x4F:
            func_800FFAB0(actor);
            return 1;
        case 0x45:
        case 0x78:
            ((EggProximityExplosion *) func_80100094(actor, 1))->flag = 1;
            break;
        case 0x40:
            func_80800718_cheggproximity(actor, 6);
            base->triggered = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

// Draw; uses render mode 1 while the alpha is not 0xFF.
void func_80800164_cheggproximity(Actor *actor)
{
    u32 saved_mode = ((ProximityRenderMode *) actor)->mode;

    if (*(u8 *) ((u8 *) actor + 0x9B) != 0xFF) {
        ((ProximityRenderMode *) actor)->mode = 1;
    }
    _subaddiedraw25d_entrypoint_1(actor);
    ((ProximityRenderMode *) actor)->mode = saved_mode;
}

// Emits egg particles on a countdown timer.
void func_808001CC_cheggproximity(actor) Actor *actor;
{
    u8 *base;
    f32 interval;
    f32 pos[3];
    f32 unk_0[3];

    base = func_80100094(actor, 0);
    *(f32 *) (base + 0x28) -= func_800D8FF8();
    interval = func_800F10B4(*(f32 *) (base + 0x30), 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(actor, unk_0);
    while (0.0f >= *(f32 *) (base + 0x28)) {
        *(f32 *) (base + 0x28) += interval;
        func_800EE7F8(pos, actor->position);
        _fxegg_entrypoint_5(actor->position, unk_0, actor->scale);
    }
}

// Deferred explosion: spawns the blast through cheggsplode.
void cheggproximity_entrypoint_2(u8 *param_0)
{
    s32 egg_ref;
    s32 egg;
    s32 owner;

    egg = func_80106790();
    egg_ref = egg;
    owner = (s32) *(s16 *) ((s8 *) func_80100094(egg, 0) + 0x3A);
    _cheggsplode_entrypoint_1(&egg_ref, owner,
                              _gcegg_entrypoint_0((u32) *(u32 *) ((s8 *) param_0 + 0x24) >> 0x16));
    _suegg_entrypoint_4(egg_ref, 0);
}

void func_808006A4_cheggproximity();

void func_80800650_cheggproximity();

void func_808005EC_cheggproximity();

void func_80800588_cheggproximity();

void func_80800510_cheggproximity();

// Update: dispatches on the current state (unk70_10).
void func_80800330_cheggproximity(Actor *actor)
{
    u8 *base = func_80100094(actor, 0);
    u8 *prox;

    switch (actor->unk70_10) {
        case 1:
            if (!_suegg_entrypoint_8(actor))
                func_8080048C_cheggproximity(actor, base);
            break;
        case 2:
            if (!_suegg_entrypoint_8(actor))
                func_80800510_cheggproximity(actor, base);
            break;
        case 3:
            func_80800588_cheggproximity(actor, (Actor *) base);
            break;
        case 4:
            func_808005EC_cheggproximity(actor, (Actor *) base);
            break;
        case 5:
            func_80800650_cheggproximity(actor, base);
            break;
        case 6:
            func_808006A4_cheggproximity(actor, base);
            break;
    }
    if (((ProximityFlags1834 *) base)->triggered && !((ProximityFlags1834 *) base)->unk_39_40) {
        prox = func_80100094(actor, 1);
        if (*(s32 *) (prox + 0xA8))
            func_80101180(0x2C4, 0x74, actor->unk0);
        if (actor->unk70_10 == 6)
            _chbaddiesetup_entrypoint_1(_cheggproximity_entrypoint_2, actor->unk0);
        else
            func_800FFAB0(actor);
    }
}

int func_8080048C_cheggproximity(actor, base)
s32 actor;
f32 base[3];
{
    if (func_800EEEA8(actor + 0x28) != 0) {
        func_80800718_cheggproximity(actor, 3);
        return;
    }
    func_808001CC_cheggproximity(actor);
    _suegg_entrypoint_16(actor);
    if (base[12] > 0.19999695f) {
        func_80800718_cheggproximity(actor, 2);
    }
}

void func_80800510_cheggproximity(f32 actor[3], u8 *base)
{
    int is_null;
    if (func_800EEEA8((void *) ((char *) actor + 0x28)) != 0) {
        func_80800718_cheggproximity(actor, 3);
        return;
    }
    func_808001CC_cheggproximity(actor);
    // Matching: temp and empty if block are needed for the match.
    is_null = !actor;
    _suegg_entrypoint_16(actor);
    if ((is_null && !actor) && !actor) {
    }
    if (_suegg_entrypoint_14(actor) != 0) {
        base[0x39] |= 0x80 & 0xFFFF;
    }
}

void func_80800588_cheggproximity(Actor *actor, Actor *base)
{
    if (*(s32 *) ((u8 *) func_80100094(actor, 1) + 0xA4) == 0) {
        func_80800874_cheggproximity(actor);
        if (!func_80800BF4_cheggproximity(actor) &&
            func_800D9078((f32 *) ((u8 *) base + 0x30))) {
            func_80800718_cheggproximity(actor, 4);
        }
    }
}

void func_808005EC_cheggproximity(Actor *actor, Actor *base)
{
    if (*(s32 *) ((u8 *) func_80100094(actor, 1) + 0xA4) == 0) {
        func_80800874_cheggproximity(actor);
        if (!func_80800BF4_cheggproximity(actor) &&
            func_800D9078((f32 *) ((u8 *) base + 0x30))) {
            func_80800718_cheggproximity(actor, 5);
        }
    }
}

// Fades the actor out (alpha -8 per frame), then enters state 6.
void func_80800650_cheggproximity(actor, param_1) void *actor;
u8 param_1;
{
    // Matching: the temporaries are needed for the match.
    void *actor_alias;
    char *bytes;
    actor_alias = actor;
    func_80800874_cheggproximity();
    func_80800AFC_cheggproximity(actor_alias);
    bytes = (char *) actor;
    if ((s32) *(u8 *) (bytes + 0x9B) < 0x79) {
        func_80800718_cheggproximity(actor_alias, 6);
        return;
    }
    *(u8 *) ((char *) actor_alias + 0x9B) = (u8) (*(u8 *) (bytes + 0x9B) - 8);
}

void func_808006A4_cheggproximity(Actor *actor, EggProximityState *base)
{
    u8 *prox;
    s32 player;

    prox = func_80100094(actor, 1);
    player = *(s32 *) (prox + 0xA0);
    func_80800874_cheggproximity(actor);
    func_80800AFC_cheggproximity(actor);
    if (((s32 *) (prox + 0x40))[player] == 1) {
        base->triggered = 1;
    }
}

// Enters a new state and runs its setup.
void func_80800718_cheggproximity(actor, new_state) Actor *actor;
s32 new_state;
{
    u8 *base = func_80100094(actor, 0);
    ProximityEggPayload921 *prox = func_80100094(actor, 1);
    s32 i;

    func_80101FDC(actor, new_state);
    switch (new_state) {
        case 1:
            prox->dialog = 0;
            break;
        case 2:
            _sueggmove_entrypoint_6(actor, -3000.0f, -22000.0f);
            break;
        case 3:
            func_8010A590(actor);
            prox->dialog = 1;
            _suegg_entrypoint_23(actor);
            *(f32 *) (base + 0x30) = 1.0f;
            func_80101180(0x2C4, 0x73, actor->unk0);
            break;
        case 4:
            *(f32 *) (base + 0x30) = 3.5f;
            break;
        case 5:
            for (i = 0; i < 8; i++) {
                prox->prev_state[i] = -1;
                prox->state[i] = -1;
            }
            func_8010D930(4, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                          &D_80800D28_cheggproximity);
        case 6:
            break;
    }
}

// Updates each player's proximity zone (-1 out of range, 0..2 by distance) and picks the closest.
void func_80800874_cheggproximity(actor) Actor *actor;
{
    EggProxLocal *base;
    EggProx *prox;
    s32 best;
    s32 i;
    s32 state;
    f32 player_pos[3];
    f32 dist;
    f32 dy;

    base = func_80100094(actor, 0);
    prox = func_80100094(actor, 1);
    best = -1;
    for (i = 0; i < func_800F5898(); i++) {
        state = -1;
        if ((actor->unk70_10 != 3 || i != base->owner) && prox->flag == 0) {
            if (func_800F6438(i) && !func_800F6CC8(i)) {
                func_800F5A00(i, player_pos);
                dist = func_800EFC7C(player_pos, actor->position);
                dy = player_pos[1] - actor->position[1];
                prox->dist[i] = dist;
                prox->dy[i] = dy;
                if (!(160000.0f < dist)) {
                    if (90000.0f < dist) {
                        state = 0;
                    } else {
                        state = (3600.0f < dist) ? 1 : 2;
                    }
                }
                switch (state) {
                    case 2:
                        if (-dy < 175.0f && dy < 100.0f) {
                            break;
                        }
                        state = 1;
                    case 1:
                        if (-dy < 300.0f && dy < 300.0f) {
                            break;
                        }
                        state = 0;
                    case 0:
                        if (-dy < 400.0f && dy < 400.0f) {
                            break;
                        }
                        state = -1;
                }
                if (state != -1) {
                    if (best < 0) {
                        best = i;
                    } else if (prox->dist[i] < prox->dist[best]) {
                        best = i;
                    }
                }
            }
            prox->prev[i] = prox->state[i];
            prox->state[i] = state;
        }
    }
    prox->best = best;
}

// Rumbles in-range players, on entry and then periodically.
void func_80800AFC_cheggproximity(actor) Actor *actor;
{
    EggPlayerTimers1559 *prox;
    s32 i;

    prox = func_80100094(actor, 1);
    if (prox->flag == 0) {
        for (i = 0; i < func_800F5898(); i++) {
            if (prox->state[i] != -1) {
                if (prox->prev_state[i] == -1) {
                    prox->rumble_timer[i] = 1.0f;
                    _bamotor_entrypoint_0(func_800F53D0(i), 1.0f, 0.25f);
                } else if (func_800D9078(&prox->rumble_timer[i])) {
                    prox->rumble_timer[i] = 1.0f;
                    _bamotor_entrypoint_0(func_800F53D0(i), 1.0f, 0.25f);
                }
            }
        }
    }
}

s32 func_80800BF4_cheggproximity(actor)
Actor *actor;
{
    ProximityEggState *prox;
    s32 player;

    prox = func_80100094(actor, 1);
    player = prox->player;
    if (player >= 0 && prox->states[player] == 2) {
        if (((ProximityEggState *) func_80100094(actor, 1))->dialog) {
            func_80101180(0x2C4, 0x74, actor->unk0, player);
        }
        func_800F7664(player, 0x45, 1);
        _sueggmisc_entrypoint_2(actor->position, 6);
        func_800FFAB0(actor);
        return 1;
    }
    return 0;
}

// TU-NOTE: the overlay .data (formerly asm/data/overlays/ch/egg/proximity.data.s) is defined here in
// C; IDO schedules some functions differently unless the tables are in the same unit. Values are
// from the ROM. Externs adjusted: D_80800CE0_cheggproximity -> int[], D_80800D28_cheggproximity -> s32[].
extern void func_80105834();
extern void _suegg_entrypoint_2();
extern void func_80108ED0();
extern void _suegg_entrypoint_5();
extern void func_80107C2C();
int D_80800CE0_cheggproximity[18] = {0x16D0160,
                                     0x9C50001,
                                     0x0,
                                     (u32) func_80800330_cheggproximity,
                                     (u32) func_80105834,
                                     (u32) func_80800164_cheggproximity,
                                     0x0,
                                     0x3F800000,
                                     0x0,
                                     0x4,
                                     (u32) _suegg_entrypoint_2,
                                     (u32) func_80108ED0,
                                     0x4C00AC,
                                     (u32) _suegg_entrypoint_5,
                                     (u32) func_80107C2C,
                                     -0x7FFFFFF0,
                                     (u32) func_808000A8_cheggproximity,
                                     0x0};
s32 D_80800D28_cheggproximity[6] = {0x13065E, 0x1636B0, 0x1012C, 0x7D00000, 0x0, 0x0};
