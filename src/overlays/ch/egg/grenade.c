// Grenade egg projectile: leaves an aimed trail and, on impact, is replaced by an egg explosion
// through a deferred spawn.
#include "common.h"

typedef struct {
    u8 pad_0[0x30];
    f32 unk_30;
    u8 pad_34[5];
    u8 done : 1;
    u8 unk_39 : 1;
    u8 pad_39 : 6;
} EggUpdateLocal;
extern void _chegggrenade_entrypoint_0(void);
extern void *func_80100094(Actor *, u32);
extern s32 func_800EEEA8(void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 _suegg_entrypoint_8(Actor *);
extern void _suegg_entrypoint_16(Actor *);
extern s32 _suegg_entrypoint_14(Actor *);
extern s32 _sueggmove_entrypoint_3(Actor *);
extern void _suegg_entrypoint_23(Actor *);
extern s32 _suegg_entrypoint_13(Actor *);
extern s32 _suegg_entrypoint_12(Actor *);
extern void _sueggmisc_entrypoint_1(Actor *);
extern void *D_80800450_chegggrenade;
extern Actor *_suegg_entrypoint_11(s32, s32, s32);
extern void _suegg_entrypoint_1(Actor *, f32);
extern void _sueggmove_entrypoint_5(Actor *, s32);
extern void _sueggmove_entrypoint_6(Actor *, f32, f32);
extern void _sueggmove_entrypoint_7(Actor *, s32);
extern void _sueggmove_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_5(f32 *, f32 *, f32);

// Spawns the aimed trail effect while the trail timer runs out.
void func_80800000_chegggrenade(actor) Actor *actor;
{
    u8 *data;
    f32 interval;
    f32 pos[3];
    f32 dir[3];

    data = func_80100094(actor, 0);
    *(f32 *) (data + 0x28) -= func_800D8FF8();
    interval = func_800F10B4(*(f32 *) (data + 0x30), 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(actor, dir);
    while (0.0f >= *(f32 *) (data + 0x28)) {
        *(f32 *) (data + 0x28) += interval;
        func_800EE7F8(pos, actor->position);
        _fxegg_entrypoint_5(actor->position, dir, actor->scale);
    }
}

// Deferred spawn: replaces the grenade egg with an egg explosion.
void chegggrenade_entrypoint_0(Actor *unk_0)
{
    s32 actor;
    s32 current;
    s32 player;

    current = func_80106790();
    actor = current;
    player = *(s16 *) ((char *) func_80100094(current, 0) + 0x3A);
    _cheggsplode_entrypoint_1(&actor, player,
                              _gcegg_entrypoint_0(*(u32 *) ((char *) unk_0 + 0x24) >> 0x16));
    _suegg_entrypoint_4(actor, 0);
}

int func_80800164_chegggrenade(Actor *actor)
{
    EggUpdateLocal *state;

    // Matching: needed for the match.
    if (1) {
    }
    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            if (!_suegg_entrypoint_8(actor)) {
                if (func_800EEEA8(&actor->actorData[4])) {
                    state->done = 1;
                } else {
                    func_80800000_chegggrenade(actor);
                    _suegg_entrypoint_16(actor);
                    if (_suegg_entrypoint_14(actor)) {
                        state->done = 1;
                    }
                }
            }
            break;
        case 2:
            if (!_suegg_entrypoint_8(actor)) {
                actor->scale = func_800F10B4(state->unk_30, 0.0f, 0.134f, 0.1f, 0.25f);
                if (_sueggmove_entrypoint_3(actor)) {
                    _suegg_entrypoint_23(actor);
                }
                if (_suegg_entrypoint_13(actor)) {
                    state->done = 1;
                } else if (_suegg_entrypoint_12(actor)) {
                    _sueggmisc_entrypoint_1(actor);
                } else {
                    func_80800000_chegggrenade(actor);
                    _suegg_entrypoint_16(actor);
                }
            }
            break;
    }
    if (state->done && !state->unk_39) {
        _chbaddiesetup_entrypoint_1(_chegggrenade_entrypoint_0, actor->unk0);
    }
}

int chegggrenade_entrypoint_1()
{
    return &D_80800450_chegggrenade;
}

u8 *chegggrenade_entrypoint_2(Actor *unk_0, s32 pos, f32 velocity[3], s32 player)
{
    Actor *egg;

    _sueggmove_entrypoint_10(unk_0);
    egg = _suegg_entrypoint_11(0x15d, pos, player);
    *(f32 *) ((char *) egg + 0x38) = 0.134f;
    _suegg_entrypoint_1(egg, 3e+01f);
    _sueggmove_entrypoint_5(egg, 1);
    _sueggmove_entrypoint_6(egg, -2.2e+03f, -22000.0f);
    _sueggmove_entrypoint_7(egg, velocity);
    *(u8 *) ((char *) egg + 0x72) = (*(u8 *) ((char *) egg + 0x72) & 0xFF03) | 8;
    return egg;
}

Actor *chegggrenade_entrypoint_3(s32 unk_0, s32 pos, s32 velocity, s32 player)
{
    Actor *egg;

    _sueggmove_entrypoint_10(unk_0, pos);
    egg = _suegg_entrypoint_11(0x15D, pos, player);
    egg->scale = 0.25f;
    _sueggmove_entrypoint_5(egg, 0);
    _sueggmove_entrypoint_6(egg, 0.0f, -100000.0f);
    _suegg_entrypoint_1(egg, 30.0f);
    _sueggmove_entrypoint_7(egg, velocity);
    egg->unk70_10 = 1;
    return egg;
}

// TU-NOTE: this overlay's .data is defined here in C. Its tables point at functions of this
// file, and IDO's assembler schedules some of them differently otherwise. Values are from the ROM.
extern void func_80105834();
extern void _subaddiedraw25d_entrypoint_2();
extern void _suegg_entrypoint_2();
extern void _suegg_entrypoint_0();
extern void _suegg_entrypoint_5();
extern void func_80107C2C();
extern void _suegg_entrypoint_17();
void *D_80800450_chegggrenade = (void *) 0x026F015D;
static u32 D_80800450_chegggrenade_rest[19] = {0x9C20001,
                                               0x0,
                                               (u32) func_80800164_chegggrenade,
                                               (u32) func_80105834,
                                               (u32) _subaddiedraw25d_entrypoint_2,
                                               0x0,
                                               0x3F800000,
                                               0x0,
                                               0x4,
                                               (u32) _suegg_entrypoint_2,
                                               (u32) _suegg_entrypoint_0,
                                               0x4C0000,
                                               (u32) _suegg_entrypoint_5,
                                               (u32) func_80107C2C,
                                               0x88000000,
                                               (u32) _suegg_entrypoint_17,
                                               0x0,
                                               0x0,
                                               0x0};
