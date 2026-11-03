#include "common.h"

extern u32 D_80800E40_suegg[];
typedef struct EggSpriteClock {
    f32 speed;
    f32 time;
    s32 frame_count;
} EggSpriteClock;
typedef struct EggSpriteFlags {
    u8 pad_0[0xA];
    u8 frame : 5;
    u8 pad_1 : 3;
} EggSpriteFlags;
extern void *func_80100094(Actor *, u32);
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 10;
    u32 unk_39_20 : 1;
    u32 pad_2 : 21;
    void *light;
} EggLightState;
extern void *_chlightfader_entrypoint_1(void *, f32, s32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 8;
    u32 hit : 1;
    u32 unk_39_40 : 1;
    u32 pad_2 : 22;
} CodexEggFlags;
extern u8 D_80800E54_suegg[];
extern void _fxegg_entrypoint_0(s32, f32 *, f32);
typedef struct {
    u8 pad[0x2A];
    u8 pad2A : 5;
    u8 flag : 1;
    u8 rest : 2;
} EggSub;
extern f32 func_800EEB40(f32 *, f32 *);
extern int func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern void func_800CB840();
extern void func_800F7BC8();
extern Actor *func_80106790();
extern Unk80132ED0 *func_800CD820(Unk80132ED0 *, f32 *, f32 *, f32);
typedef struct {
    u8 pad_0[0x38];
    u32 pad_1 : 8;
    u32 hit : 1;
    u32 pad_2 : 23;
} EggHitFlags1081;
typedef struct {
    u8 pad_0[0x30];
    f32 timer;
    u8 pad_1[6];
    s16 owner;
} EggTimeState;
extern void *func_800A940C(s32);
extern f32 func_800C5190(void *);
typedef struct {
    u8 pad_0[0x14];
    u8 homing[0x1C];
    f32 timer;
    u8 pad_1[4];
    u8 mode;
} EggHomingState;
extern void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
typedef struct {
    u8 pad_0[0x38];
    u16 pad_1 : 8;
    u16 hit : 1;
    u16 unk_39_40 : 1;
    u16 unk_39_20 : 1;
    u16 pad_2 : 5;
} EggEventFlags;
typedef struct {
    u8 pad_0[0x3C];
    void *light;
    f32 last_pos[3];
} EggSoundPosition61;
extern int func_800E3E8C(f32 *, f32);
extern s32 D_80800E64_suegg[];
extern void func_8010D254(f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
s32 suegg_entrypoint_18();
void suegg_entrypoint_22();
s32 func_80800DC0_suegg();

void *suegg_entrypoint_0()
{
    return &D_80800E40_suegg;
}

// Init the sprite animation clock.
void func_8080000C_suegg(s32 *actor)
{
    u8 *state;
    u8 *data;

    data = func_80100094(actor, 0);
    // Matching: extra copy of the pointer is needed for the match.
    state = data;
    *(f32 *) ((s8 *) data + 4) = 0.0f;
    *(s32 *) ((s8 *) state + 8) = func_800AF5A0(func_800EC3E8(*actor));
    *(f32 *) ((s8 *) state + 0) = 1.0f;
}

// Advance the sprite animation and set the current frame.
void func_80800064_suegg(Actor *actor)
{
    EggSpriteClock *anim;
    f32 step;

    anim = func_80100094(actor, 0);
    step = func_800D8FF8() * anim->speed;
    step += anim->time;
    anim->time = func_800F13C4(step, (f32) anim->frame_count);
    ((EggSpriteFlags *) actor->unk0->unk0)->frame = (s32) anim->time % anim->frame_count;
}

void suegg_entrypoint_1(s32 actor, f32 speed)
{
    *(f32 *) func_80100094(actor, 0) = speed;
}

void suegg_entrypoint_15();

void suegg_entrypoint_2(Actor *actor)
{
    EggLightState *state;
    state = func_80100094(actor, 0);
    if (state->light) {
        if (state->unk_39_20) {
            func_800C8B84(state->light);
        } else {
            func_800C8CB8(state->light, actor->position);
            state->light = _chlightfader_entrypoint_1(state->light, 1.0f, 2);
        }
        state->light = NULL;
    }
    suegg_entrypoint_15((s32) actor);
}

void suegg_entrypoint_4();

void suegg_entrypoint_3(s32 actor)
{
    suegg_entrypoint_4(actor, 1);
}

// Despawn, optionally with the egg-type explosion effect.
void suegg_entrypoint_4(Actor *actor, s32 explode)
{
    CodexEggFlags *state;

    state = func_80100094(actor, 0);
    if (!actor->unk64_17) {
        if (!state->unk_39_40) {
            state->hit = 0;
            func_8010D930(0, *(u32 *) ((u8 *) actor + 0x70) & 1, actor->position,
                          D_80800E54_suegg);
            if (explode) {
                _fxegg_entrypoint_0(_gcegg_entrypoint_1(actor->unk6C_9), actor->position,
                                    actor->scale);
            }
        }
        func_800FFAB0(actor);
    }
}

void suegg_entrypoint_5(Actor *actor)
{
    if (!func_80800DC0_suegg(actor, *(s16 *) ((u8 *) func_80100094(actor, 0) + 0x3A))) {
        (*(EggSub **) actor)->flag = 1;
    }
}

s16 suegg_entrypoint_6(u8 *hitbox, s32 out_delta, s32 *out_type)
{
    s32 actor_addr;
    u8 *state;
    s32 actor;

    actor = func_80106790();
    // Matching: extra copy of the actor pointer is needed for the match.
    actor_addr = actor;
    state = func_80100094(actor, 0);
    func_800EFB24(out_delta, actor_addr + 4, actor_addr + 0x18);
    *out_type = _gcegg_entrypoint_0((u32) *(u32 *) ((s8 *) hitbox + 0x24) >> 0x16);
    return *(s16 *) ((s8 *) state + 0x3A);
}

s16 suegg_entrypoint_7(void)
{
    return *(s16 *) ((s8 *) func_80100094(func_80106790(), 0) + 0x3A);
}

// Returns the index of the closest player the egg's path hits, or -1.
s32 func_80800390_suegg(Actor *actor)
{
    u8 *state;
    f32 dist;
    f32 best_dist;
    s32 firstp;
    f32 delta[3];
    f32 pos[3];
    f32 hit_point[3];
    f32 unk_5[2];
    s32 i;
    f32 player_pos[3];
    f32 radius;
    f32 height;
    s32 result;

    state = func_80100094(actor, 0);
    result = -1;
    if (func_800EA068(0x4000)) {
        suegg_entrypoint_18(actor, delta);
        func_800EE7F8(pos, actor->position);
        best_dist = 0.0f;
        firstp = func_800EA068(8);
        for (i = 0; i < func_800F5898(); i++) {
            if (func_800F6438(i) && i != *(s16 *) (state + 0x3A)) {
                func_800F5A00(i, player_pos);
                dist = func_800EEB40(player_pos, delta);
                if (result < 0 || dist < best_dist) {
                    if (firstp) {
                        actor = func_800F53D0(i);
                        _bsfirstp_entrypoint_7(actor, &radius, &height);
                    } else {
                        func_800F551C(i, &radius, unk_5, &height);
                    }
                    if (func_800F0734(delta, pos, player_pos, radius, height, hit_point,
                                      hit_point)) {
                        result = i;
                        best_dist = dist;
                    }
                }
            }
        }
    }
    return result;
}

void suegg_entrypoint_8(s32 actor)
{
    suegg_entrypoint_9(actor, 1);
}

// Hit detection against props and players.
int suegg_entrypoint_9(Actor *actor, s32 param_1)
{
    u8 *state;
    Unk80132ED0 *prop_hit;
    Unk80132ED0 *hitbox;
    f32 delta[3];
    s32 player;
    Actor *prop;
    f32 prop_dist;
    f32 player_pos[3];

    state = func_80100094(actor, 0);
    hitbox = actor->unk0;
    player = func_80800390_suegg(actor);
    func_800CB840(3, actor);
    *(s16 *) ((u8 *) hitbox + 0x20) = 0;
    suegg_entrypoint_18(actor, delta);
    func_8010A590(actor);
    prop_hit = func_800CD820(hitbox, delta, actor->position, 38.0f);
    // Whichever of prop and player is closer wins.
    if (prop_hit && player >= 0) {
        prop = func_80106790(prop_hit);
        prop_dist = func_800EEB40(delta, prop->position);
        func_800F5A00(player, player_pos);
        if (func_800EEB40(delta, player_pos) < prop_dist)
            prop_hit = NULL;
        else
            player = -1;
    }
    if (prop_hit) {
        if (param_1)
            _glhittableDll_entrypoint_1(hitbox, prop_hit);
        else
            ((EggHitFlags1081 *) state)->hit = 1;
    }
    if (player >= 0) {
        func_800F7BC8(player, 0x47, hitbox);
        ((EggHitFlags1081 *) state)->hit = 1;
    }
    func_800CB870();
    func_8010A570(actor);
    return ((EggHitFlags1081 *) state)->hit;
}

int suegg_entrypoint_10(s32 hitbox, s32 param_1, s32 other)
{
    s32 *other_ref;
    other_ref = &other;
    if (_glhittableDll_entrypoint_6(*other_ref | 0) && _glhittableDll_entrypoint_9(other)) {
        Actor *state = func_80106790(hitbox);
        state = func_80100094(state, 0);
        // Matching: the empty triple test and the pointer alias are needed for the match.
        if ((!other && !other) && !other) {
        }
        *(u8 *) ((char *) state + 0x39) |= 0x80;
    }
}

// Spawn an egg; the HOMING cheat (flag 0xA31 clear) sets up homing.
u8 *suegg_entrypoint_11(s32 param_0, s32 param_1, s32 owner)
{
    u8 *actor;
    u8 *state;
    u8 *homing;

    actor = func_80108474(param_0, param_1, 0);
    state = func_80100094(actor, 0);
    // Matching: the two empty if (1) blocks are needed for the match.
    if (1) {
    }
    if (1) {
    }
    func_8080000C_suegg(actor);
    *(s16 *) (state + 0x3A) = owner;
    *(s32 *) (state + 0x34) = 0;
    state[0x38] = 1;
    *(f32 *) (state + 0x28) = 0.0f;
    *(f32 *) (state + 0x30) = 0.0f;
    if (func_800D3E40(0xC) && !func_800DA298(0xA31)) {
        homing = state + 0x14;
        _sumissilehome_entrypoint_0(actor, homing);
        _sumissilehome_entrypoint_3(actor, homing, *(s16 *) (state + 0x3A));
        _sumissilehome_entrypoint_1(actor, homing, -1);
        _sumissilehome_entrypoint_2(actor, homing, 0x45BB8000);
        state[0x38] = 2;
    }
    _sueggmove_entrypoint_4(actor);
    func_8010A570(actor);
    if (func_800F693C(owner)) {
        actor[0x75] &= ~0x10;
    } else if (func_800F690C(owner)) {
        actor[0x75] &= ~0x10;
    }
    return actor;
}

int suegg_entrypoint_12(Actor *actor)
{
    u8 *state;
    f32 center[3];
    f32 delta[3];

    state = func_80100094(actor, 0);
    if (func_800D3948()) {
        return 0;
    }
    if (*(f32 *) (state + 0x30) < 0.6f) {
        return 0;
    }
    func_8010D254(center);
    func_800EFB24(delta, center, actor->position);
    return center[1] < actor->position[1] && actor->position[1] < center[1] + 100.0f &&
           delta[0] * delta[0] + delta[2] * delta[2] < 4900.0f;
}

int suegg_entrypoint_13(Actor *actor)
{
    f32 *state;
    state = func_80100094(actor, 0);
    return state[12] > 2.8f && (_sueggmove_entrypoint_3(actor) || state[12] > 3.5f);
}

int suegg_entrypoint_14(Actor *actor)
{
    EggTimeState *state;
    f32 limit;
    state = func_80100094(actor, 0);
    limit = func_800C5190(func_800A940C(state->owner));
    if (limit > 2.0f)
        limit = 2.0f;
    return state->timer > limit + limit || !func_800DA298(0x662);
}

void suegg_entrypoint_15(s32 arg0)
{
}

// Per-frame update: homing, movement, sprite animation, light.
void suegg_entrypoint_16(Actor *actor)
{
    EggHomingState *state;
    state = func_80100094(actor, 0);
    if (state->mode != 1) {
        if (state->mode == 2) {
            state->mode = 3;
            _sumissilehome_entrypoint_5(actor, state->homing, 4500.0f, 1400.0f);
        }
        _sumissilehome_entrypoint_6(actor, state->homing);
    }
    _sueggmove_entrypoint_9(actor);
    func_80800064_suegg(actor);
    suegg_entrypoint_22(actor);
    state->timer += func_800D8FF8();
}

// Message handler.
s32 suegg_entrypoint_17(Actor *actor, s32 msg, s32 player)
{
    EggEventFlags *state;

    state = func_80100094(actor, 0);
    switch (msg) {
        case 5: // deflect
            state->hit = 1;
            func_8010A570(actor);
            return 1;
        case 0x2C: // destroy
            state->unk_39_40 = 1;
            func_8010A570(actor);
            func_800FFAB0(actor);
            return 1;
        case 0x92:
            state->unk_39_20 = 1;
            break;
        case 0x98:
            state->unk_39_40 = 1;
            break;
        case 0x9F:
            func_80800DC0_suegg(actor, player);
            return 1;
        default:
            return 0;
    }
    return 1;
}

s32 suegg_entrypoint_18(actor, out)
s32 actor;
s32 out;
{
    func_800EFB24(out, actor + 4, actor + 0x18);
}

// Matching: the unused copy of the output pointer and the base copy are needed for the match.
s32 suegg_entrypoint_19(s32 actor, s32 out)
{
    u32 unused = out;
    u32 base = actor;
    func_800EE7F8(out, base + 0x18);
}

// Matching: the unused copy of the output pointer and the base copy are needed for the match.
s32 suegg_entrypoint_20(s32 actor, s32 out)
{
    s32 unused = out;
    s32 base = actor;
    func_800EE7F8(out, base + 0x28);
}

// Create the attached point light.
void suegg_entrypoint_21(s32 actor, s32 param_1)
{
    s32 *state;
    s32 pos_copy;
    s32 pos;
    s32 light;

    state = func_80100094(actor, 0);

if (func_800BF8E4() > 0) {
    light = func_800C8A98();
    *(s32 *) ((char *) state + 0x3C) = light;
    pos = actor + 4;
    // Matching: extra copy of the position pointer is needed for the match.
    pos_copy = pos;
    func_800C8CB8(light, pos);
    func_800C8E84(*(s32 *) ((char *) state + 0x3C), param_1);
    func_800C8E54(*(s32 *) ((char *) state + 0x3C), 0x42A00000, 0x43E10000);
    func_800EE7F8((s32 *) ((char *) state + 0x40), pos_copy);
}

}

void suegg_entrypoint_22(actor) Actor *actor;
{
    EggSoundPosition61 *state;

    state = func_80100094(actor, 0);

if (state->light != NULL) {
    if (func_800E3E8C(actor->position, 450.0f) || func_800E3E8C(state->last_pos, 450.0f)) {
        func_800C8CB8(state->light, actor->position);
        func_800EE7F8(state->last_pos, actor->position);
    }
}

}

void suegg_entrypoint_23(s32 actor)
{
    func_8010D930(8, 0, actor + 4, &D_80800E64_suegg);
}

s32 func_80800DC0_suegg(actor, player)
Actor *actor;
s32 player;
{
    u8 *state;

if ((func_800D3948() == 0) && (func_800F6CC8(player) != (0 * 0))) {
    state = func_80100094(actor, 0);
    *(u8 *) ((char *) state + 0x39) = (u8) ((*(u8 *) ((char *) state + 0x39) & 0xFF) | 0x40);
    suegg_entrypoint_3(actor);
    return 1;
}

return 0;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file, and IDO
// schedules some of them differently unless the tables are in the same unit. Values are from the ROM.
extern void _suegg_entrypoint_10();
u32 D_80800E40_suegg[5] = {0x0, 0x0, 0x0, (u32) _suegg_entrypoint_10, 0x0};
u8 D_80800E54_suegg[16] = {0x0, 0x13, 0x4, 0x7,  0x0,  0xD,  0x1, 0x99,
                           0x1, 0xB3, 0x0, 0x16, 0x32, 0xC8, 0x0, 0x0};
s32 D_80800E64_suegg[7] = {0x130418, 0xD00F3, 0x10C0016, 0x2EE00000, 0x0, 0x0, 0x0};
