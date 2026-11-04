#include "common.h"
extern void func_800EF1B8(f32 *, f32, f32);

extern int D_808013F0_chstonepillar[];
extern int D_80801438_chstonepillar[];
extern void *func_80100094(Actor *, u32);
typedef union {
    s32 value;
    Actor *other;
} StonePillarMessage1410;
extern u8 func_801015D0[];
extern f32 func_80103EF4(Actor *);
extern Actor *_subaddiefind_entrypoint_2(s32, s32 *);
extern Actor *_subaddiefind_entrypoint_3(s32, s32 *);
extern u8 D_80801480_chstonepillar[];
typedef struct {
    u8 pad_0[0x2C];
    s16 index;
    u8 pad_1;
    u8 bounced;
} StonePillarState;
extern void func_800BBCB8(f32 *, f32 *, f32, s32, s32);
extern s32 D_80801498_chstonepillar[];
extern f32 D_808014B8_chstonepillar[];
extern f32 func_800136E4(f32);
typedef struct {
    u8 pad_0[0x2C];
    s16 index;
} PillarActivation;
extern void func_800CE8D8(s32, f32, s32);
extern s32 func_800DA564(s32, s32);
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
typedef struct {
    u8 pad[0x5F];
    u8 f5F;
    u8 pad60[0x12];
    u16 f72 : 6;
    u16 rest : 10;
} PillarS;
extern u8 D_808014F0_chstonepillar[];
extern void _subaddieaudioloop_entrypoint_4(PillarS *, s32, s32, void *);
typedef struct {
    u8 pad[0xC];
    f32 position[3];
    u8 pad_18[0x18];
    f32 yaw;
    f32 speed;
    f32 height;
} StonePillarMotion;
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern u8 D_8080148C_chstonepillar[];
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_80018820(s32, f32, f32);
int func_808005B4_chstonepillar();
void func_808006AC_chstonepillar();
void func_80800704_chstonepillar();
// Links this pillar to the one with the next index.
void func_808007C8_chstonepillar();
void func_80800ADC_chstonepillar();
// Sparkle burst at the carried item.
s32 func_80800B58_chstonepillar();
void func_80800BDC_chstonepillar();
void func_80800C10_chstonepillar();
// Sets the yaw from the pillar index (72 degrees per step).
void func_80800C44_chstonepillar();
void func_80800CC8_chstonepillar();
int func_80800DA4_chstonepillar();
// True when this is the pillar due next and its completion flag is not set yet.
int func_80800DD8_chstonepillar();
void func_80800E30_chstonepillar();
void func_80800EE0_chstonepillar();
void func_80800FE0_chstonepillar();
int func_808010CC_chstonepillar();
int func_8080112C_chstonepillar();
s32 func_80801174_chstonepillar();
s32 func_80801238_chstonepillar();
void func_80801374_chstonepillar();
s32 func_80800474_chstonepillar();
// Bounces the carried item along the pillars with sparkles.
s32 func_80800870_chstonepillar();
// Switches state, starts the shake and rumbles.
void func_808011CC_chstonepillar(Actor *actor, s32 new_state, f32 shake, f32 rumble);

int chstonepillar_entrypoint_0()
{
    return (int) &D_808013F0_chstonepillar;
}

int chstonepillar_entrypoint_1()
{
    return (int) &D_80801438_chstonepillar;
}

// Main update of the pillar actor.
void func_80800018_chstonepillar(Actor *actor)
{
    u8 *state;
    s32 prev_anim;
    s32 cam_id;

    state = func_80100094(actor, 0);
    prev_anim = actor->unk70_10;
    func_80800FE0_chstonepillar(actor);
    if (*(s16 *) (state + 0x2C) == 4 || func_800D0B68(8, 1)) {
        if (_glcutDll_entrypoint_19(0xB) && prev_anim == 3) {
            func_80800ADC_chstonepillar(actor, 0);
        }
    } else if (func_800DA298(0x9D7) || func_8080112C_chstonepillar(actor)) {
        func_80801374_chstonepillar(actor, 2);
        switch (actor->unk70_10) {
            case 1:
                if (func_800DA298(0x9D7) && *(s16 *) (state + 0x2C) == 0) {
                    func_80801174_chstonepillar(actor);
                    func_80800B58_chstonepillar(actor);
                    *(f32 *) (state + 0x24) = 0.5f;
                    func_800DA524(0x9D7);
                    if (!func_800DA298(0x9D9)) {
                        cam_id = 0x810;
                        if (_glcutDll_entrypoint_19(0xB)) {
                            cam_id = 0x910;
                        }
                        _capod_entrypoint_13(actor->unk0, 0, 0xC, cam_id);
                        func_800DA544(0x9D9);
                    }
                } else if (func_80800474_chstonepillar(actor)) {
                    func_808011CC_chstonepillar(actor, 2, 1.0f, 1.0f);
                }
                break;
            case 2:
                if (!func_80801238_chstonepillar(actor)) {
                    func_80101FDC(actor, 3);
                }
                break;
            case 3:
                if (!func_80800870_chstonepillar(actor)) {
                    func_80800ADC_chstonepillar(actor, 1);
                }
        }
    }
}

void func_808001FC_chstonepillar(s32 actor)
{
    _subaddiefade_entrypoint_14();
    func_80800EE0_chstonepillar(actor);
}

void func_80800224_chstonepillar(u8 *actor)
{
    u8 *state;

    state = func_80100094(actor, 0);
    func_80800FE0_chstonepillar(actor);
    func_80801374_chstonepillar(actor, 2);
    if ((((u32) *(u16 *) ((s8 *) actor + 0x72) >> 0xA) == 2) &&
        (func_80800C10_chstonepillar(actor + 4), (func_80801238_chstonepillar(actor) == 0)) &&
        (func_80101FDC(actor, 1), (func_800D0B68(8, 1) == 0))) {
        if ((func_800DA298(0x9D8) == 0) && (*(s16 *) ((s8 *) state + 0x2C) == 0)) {
            func_800DA544(0x9D8);
        }
        if (func_800DA298(0x9D8) != 0) {
            if ((func_8080112C_chstonepillar(actor) != 0) &&
                (*(s16 *) ((s8 *) state + 0x2C) != 4)) {
                func_80800E30_chstonepillar(actor);
            }
        } else {
            func_80800DA4_chstonepillar(actor);
        }
    }
}

s32 func_8080031C_chstonepillar(Actor *actor, s32 msg, s32 msg_data)
{
    u8 *state;

    switch (msg) {
        case 0x95:
            state = func_80100094(actor, 0);
            func_80800704_chstonepillar(actor);
            if (_glcutDll_entrypoint_19(11) && !*(s16 *) (state + 0x2C)) {
                func_808006AC_chstonepillar(actor);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800390_chstonepillar(Actor *actor, s32 msg, StonePillarMessage1410 msg_data)
{
    switch (msg) {
        case 0x3F:
            func_80800CC8_chstonepillar(actor, msg_data.value);
            break;
        case 0x95:
            func_80800C44_chstonepillar(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003F4_chstonepillar(actor, unk_1) s32 actor;
u8 unk_1;
{
    s32 i;
    s32 next;
    i = 0;
    do {
        // Matching: `^ 0` and the chained assignment are needed for the match.
        next = (i = i + 1) ^ 0;
        func_800DF744(next, 0);
        i = next;
    } while (next != 5);
    func_800DF744(*(u8 *) ((char *) func_80100094(actor, 0) + 0x2E) + 1, 1);
    func_80101808(actor, &func_801015D0);
}

s32 func_80800474_chstonepillar(actor)
Actor *actor;
{
    StonePillarMotion *motion;
    f32 dist;

    motion = func_80100094(actor, 0);
    if (!func_8080112C_chstonepillar(actor) || !func_800DA298(0x9D5)) {
        return 0;
    }
    dist = func_800EFB8C(actor->position, motion->position);
    motion->yaw = func_80102D78(actor, motion->position);
    motion->speed = (0.3f * dist) / 0.5f;
    motion->height = 822.00006f;
    return 1;
}

// Sinks the pillar by 200 units per step of its index.
int func_80800520_chstonepillar(Actor *actor)
{
    Actor *state;
    s32 index;
    func_80800EE0_chstonepillar();
    state = func_80100094(actor, 0);
    index = func_808005B4_chstonepillar(actor, *(s32 *) ((char *) state + 0x28), state) | 0;
    // Matching: empty block steers IDO's register allocation.
    if ((actor && actor) && actor) {
    }
    index = *(s32 *) ((char *) state + 0x28) + 1;
    func_808005B4_chstonepillar(actor, index, (u8 *) state + 0xC);
    *(f32 *) ((char *) actor + 0x8) -= *(s32 *) ((char *) state + 0x28) * 200.0f;
    *(f32 *) ((char *) actor + 0x1C) = *(f32 *) ((char *) actor + 0x8);
}

int func_808005B4_chstonepillar(actor, index, out_pos)
Actor *actor;
s32 index;
f32 *out_pos;
{
    Actor *pillar;
    u8 *pillar_state;
    s32 count;
    f32 base_y;

    base_y = func_80103EF4(actor);
    for (pillar = _subaddiefind_entrypoint_2(0x12E, &count); pillar != NULL;
         pillar = _subaddiefind_entrypoint_3(0x12E, &count)) {
        pillar_state = func_80100094(pillar, 0);
        if (index == *(s16 *) (pillar_state + 0x2C)) {
            func_800EE7F8(out_pos, (f32 *) (pillar_state + 0x18));
            out_pos[1] += base_y - index * 200.0f;
            return;
        }
    }
    pillar_state = func_80100094(actor, 0);
    func_800EE7F8(out_pos, (f32 *) (pillar_state + 0x18));
    out_pos[1] += base_y - index * 200.0f;
}

void func_808006AC_chstonepillar(actor) s32 *actor;
{
    long target;
    u16 *entry_u16;
    u8 *entry;
    short cam_param;
    if (func_800DA298(0x9D5) != 0) {
        entry = &D_80801480_chstonepillar[func_800DA564(0x9CD, 3) * 2];
        target = *actor;
        entry_u16 = (u16 *) entry;
        cam_param = *entry_u16;
        _capod_entrypoint_13(target, 0, cam_param, 0x810);
    }
}

void func_80800704_chstonepillar(actor) Actor *actor;
{
    StonePillarState *state;
    f32 pos[3];

    state = func_80100094(actor, 0);
    state->bounced = 0;
    func_808007C8_chstonepillar(actor);
    func_80101FDC(actor, 1);
    if (func_800D0B68(8, 1)) {
        state->index = -1;
    } else if (!state->index) {
        func_808005B4_chstonepillar(actor, func_800DA564(0x9CD, 3), pos);
        func_800D1254(8, 1, pos);
        if (func_800DA298(0x9D7)) {
            func_80801174_chstonepillar(actor);
            func_800DA544(0x9D7);
        }
    }
}

void func_808007C8_chstonepillar(actor) Actor *actor;
{
    StonePillarState *state;
    StonePillarState *other_state;
    Actor *other;
    s32 count;

    state = func_80100094(actor, 0);
    other = _subaddiefind_entrypoint_2(actor->unk6C_9, &count);
    while (other) {
        if (other != actor) {
            other_state = func_80100094(other, 0);
            if (state->index + 1 == other_state->index) {
                func_800EE7F8((f32 *) ((u8 *) state + 0xC), other_state);
            }
        }
        other = _subaddiefind_entrypoint_3(actor->unk6C_9, &count);
    }
}

s32 func_80800870_chstonepillar(actor)
Actor *actor;
{
    f32 prev_vy;
    f32 dt;
    f32 item_pos[3];
    u8 *state;
    dt = func_800D8FF8();
    state = func_80100094(actor, 0);
    func_800D1218(8, 1, item_pos);
    _fxsparkle_entrypoint_1(item_pos, 0x12);
    if (!state[0x2F]) {
        if (item_pos[1] < *(f32 *) (state + 0x10)) {
            item_pos[1] = *(f32 *) (state + 0x10);
            *(f32 *) (state + 0x38) *= -0.54f;
            *(f32 *) (state + 0x34) *= 0.08f;
            func_800D1254(8, 1, item_pos);
            state[0x2F] = 1;
            func_8010D930(3, 0, item_pos, D_8080148C_chstonepillar);
            return 1;
        }
        prev_vy = *(f32 *) (state + 0x38);
        *(f32 *) (state + 0x38) -= 1200.0f * dt;
        item_pos[1] += *(f32 *) (state + 0x38) * dt;
        if (prev_vy >= 0.0f && *(f32 *) (state + 0x38) < 0.0f) {
            *(f32 *) (state + 0x30) = func_800F1DF4(item_pos, (f32 *) (state + 0xC));
        }
        func_800EF1B8(item_pos, *(f32 *) (state + 0x30), *(f32 *) (state + 0x34) * dt);
    } else {
        *(f32 *) (state + 0x38) -= 1200.0f * dt;
        item_pos[1] += *(f32 *) (state + 0x38) * dt;
        func_800EF1B8(item_pos, *(f32 *) (state + 0x30), *(f32 *) (state + 0x34) * dt);
        if (*(f32 *) (state + 0x38) < 0.0f && item_pos[1] < *(f32 *) (state + 0x10)) {
            item_pos[1] = *(f32 *) (state + 0x10);
            *(f32 *) (state + 0x38) *= -0.6f;
            func_8010D930(3, 0, item_pos, D_8080148C_chstonepillar);
            if (*(f32 *) (state + 0x38) < 2.0f * (1200.0f * dt)) {
                func_800D1254(8, 1, item_pos);
                return 0;
            }
        }
    }
    func_800D1254(8, 1, item_pos);
    return 1;
}

void func_80800ADC_chstonepillar(actor, advance) s32 actor;
s32 advance;
{
    u8 *state;

    state = func_80100094(actor, 0);
    func_800DA524(0x9D5);

if (advance != 0) {
    func_800DA7A8(0x9CD, *(s16 *) ((s8 *) state + 0x2C) + 1, 3);
}

func_80101FDC(actor, 1);

if (_glcutDll_entrypoint_19(0xB) != 0) {
    _glcutDll_entrypoint_17();
}

}

s32 func_80800B58_chstonepillar(actor)
Actor *actor;
{
    f32 pos[3];
    void *state;

    state = func_80100094(actor, 0);
    func_800D1218(8, 1, pos);
    func_800BBCB8(pos, pos, 1.0f, 0xE, _fxgenlist_entrypoint_0());
    pos[1] += 40.0f;
    func_80800BDC_chstonepillar(pos);
    func_800D1254(8, 1, state);
    return 0;
}

void func_80800BDC_chstonepillar(pos) s32 pos;
{
    func_800BBCB8(pos, 0, 1.0f, 1, &D_80801498_chstonepillar);
}

void func_80800C10_chstonepillar(pos) s32 pos;
{
    func_800BBCB8(pos, pos, 1.0f, 3, &D_808014B8_chstonepillar);
}

void func_80800C44_chstonepillar(actor) Actor *actor;
{
    u8 *state;

    state = func_80100094(actor, 0);
    actor->rotation[1] = func_800136E4((3 - *(s16 *) (state + 0x2C)) * 72.0f);

if (func_800D0B68(8, 1)) {
    *(s16 *) (state + 0x2C) = -1;
}

func_800EE7F8(actor->position, actor->actorData);
}

void func_80800CC8_chstonepillar(actor, unk_1) Actor *actor;
s32 unk_1;
{
    PillarActivation *state;
    state = func_80100094(actor, 0);

if (actor->unk70_10 != 2) {
    if (!state->index && !func_800DA298(0x9D6) && !func_800D0B68(8, 1)) {
        func_800CE8D8(0, 45.0f, 45);
        func_800CE88C(0, 1);
        func_800DA544(0x9D6);
    }
    if (func_80800DD8_chstonepillar(actor))
        func_800F7F98(func_800F54E4(), 1);
    func_800C3F48(0x7FF57C16);
    func_808011CC_chstonepillar(actor, 2, 1.0f, 1.0f);
}

}

int func_80800DA4_chstonepillar(actor)
s32 actor;
{
    if (!func_800DA298(0x9D8)) {
        func_800DA544(0x9D8);
    }

}

int func_80800DD8_chstonepillar(actor)
s32 actor;
{
    u8 *state = func_80100094(actor, 0);
    return func_800DA564(0x9CD, 3) == *(s16 *) (state + 0x2C) &&
           func_800DA298(*(s16 *) (state + 0x2C) + 0x65C) == 0;
}

void func_80800E30_chstonepillar(actor) s32 actor;
{
    u8 *state;

    state = func_80100094(actor, 0);

if (func_80800DD8_chstonepillar(actor) == 0) {
    func_800DA524(0x9D5);
    func_800DA7A8(0x9CD, *(s16 *) ((char *) state + 0x2C) + 1, 3);
    return;
}

func_800F7F98(func_800F54E4(), 0);

if (func_800F6CC8(func_800F54E4()) == 0) {
    func_800DA544(0x9D5);
    func_800DA544(*(s16 *) ((char *) state + 0x2C) + 0x65C);
    _glcutDll_entrypoint_6(0xB9, 0xB);
}

}

void func_80800EE0_chstonepillar(actor) Actor *actor;
{
    u8 *state;

    state = func_80100094(actor, 0);
    *(s16 *) (state + 0x2C) = (s32) actor->rotation[1] - 1;
    *(f32 *) (state + 0x24) = 0.0f;
    state[0x2F] = 0;
    *(s32 *) (state + 0x28) = *(s16 *) (state + 0x2C);
    state[0x2E] = (s32) actor->rotation[1] - 1;

if ((*(u32 *) ((u8 *) actor->unk0 + 0x24) >> 22) == 0x19F) {
    actor->rotation[1] = func_800136E4(actor->rotation[1] - *(s16 *) (state + 0x2C) * 18.0f);
} else {

actor->rotation[1] = 0.0f;
}
func_800EE7F8((f32 *) actor->actorData, actor->position);
func_800EE7F8((f32 *) (state + 0x18), actor->position);
if (func_800D0B68(8, 1)) {
    *(s16 *) (state + 0x2C) = -1;

}
}

void func_80800FE0_chstonepillar(actor) u8 **actor;
{
    if ((func_800DA298(0x9D6) != 0) && (func_800DA298(0x9D7) == 0) &&
        (func_8080112C_chstonepillar(actor) != 0) &&
        ((func_800CEAD0(0) != 0) || (func_800D0B68(8, 1) != 0))) {
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }

func_800DA544(0x9D7);

if (func_800DA298(0x9D9) != 0) {
    func_80801174_chstonepillar(actor);
    if (((u32) *(u32 *) ((s8 *) *actor + 0x24) >> 0x16) != 0x19F) {
        func_800DA524(0x9D7);
    }
}

if (func_800D0B68(8, 1) == 0) {
    func_808010CC_chstonepillar(actor);
    func_800FC660(0x17);
}

}
}

int func_808010CC_chstonepillar(actor)
Actor *actor;
{
    if (!func_800DA298(0x9D9)) {
        if (func_800EA05C() != 0xB9) {
            if (func_800F6CC8(func_800F54E4()) == 0) {
                _glcutDll_entrypoint_6(0xB9, 0xB);
            }
        }

}
}

int func_8080112C_chstonepillar(actor)
s32 actor;
{
    Actor *state;
    state = func_80100094(actor, 0);
    if (func_800DA564(0x9CD, 3) == (*(s16 *) ((char *) (state) + 0x2C))) {
        return 1;
    }
    return 0;
}

s32 func_80801174_chstonepillar(actor)
s32 actor;
{
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA524(0x9D6);
    func_800DA524(0x9D5);
    func_80101FDC(actor, 1);
}

void func_808011CC_chstonepillar(Actor *actor, s32 new_state, f32 shake, f32 rumble)
{
    if (new_state != actor->unk70_10) {
        func_80101FDC(actor, new_state);
        *(f32 *) ((u8 *) func_80100094(actor, 0) + 0x24) = shake;
        actor->unk58 = 0.3f;
        func_80018820(0, 3.0f, rumble);
    }
}

s32 func_80801238_chstonepillar(actor)
Actor *actor;
{
    f32 shake_pos[3];
    u8 *state;

    state = func_80100094(actor, 0);
    if (func_800D9078(&actor->unk58) && actor->unk0->unk24 >> 22 != 0x19F &&
        !func_800D0B68(8, 1) && *(s16 *) (state + 0x2C) != 4 &&
        func_8080112C_chstonepillar(actor)) {
        func_800FC660(0xE);
    }
    if (*(f32 *) (state + 0x24) > 0.0f) {
        *(f32 *) (state + 0x24) -= func_800D8FF8();
        func_800EE7F8(shake_pos, actor->actorData);
        shake_pos[0] += func_800DC178(-7.5f, 7.5f);
        shake_pos[2] += func_800DC178(-7.5f, 7.5f);
        func_800EE7F8(actor->position, shake_pos);
        return 1;
    }
    func_800EE7F8(actor->position, actor->actorData);
    return 0;
}

void func_80801374_chstonepillar(actor, anim_state) PillarS *actor;
s32 anim_state;
{
    s32 match = anim_state == actor->f72;
    if (match || (!match && actor->f5F)) {
        _subaddieaudioloop_entrypoint_4(actor, 0, match, &D_808014F0_chstonepillar);
    }
}

extern void func_80105834();
extern void func_80107C2C();
extern void func_80101870();
extern void func_80108ED0();
// TU-NOTE: the .data tables below were moved into C. They hold pointers to functions of this file,
// and IDO's assembler schedules some functions differently unless the tables are in the same unit.
int D_808013F0_chstonepillar[18] = {0x19F012E,
                                    0x6490001,
                                    0x0,
                                    (u32) func_80800018_chstonepillar,
                                    (u32) func_80105834,
                                    (u32) func_808003F4_chstonepillar,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0xC02,
                                    0x0,
                                    0x0,
                                    0x3C0000,
                                    (u32) func_80800520_chstonepillar,
                                    (u32) func_80107C2C,
                                    -0x7FFFDFFE,
                                    (u32) func_8080031C_chstonepillar,
                                    0x0};
int D_80801438_chstonepillar[18] = {0x1A0012F,
                                    0x64A0001,
                                    0x0,
                                    (u32) func_80800224_chstonepillar,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0xC00,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x3C0000,
                                    (u32) func_808001FC_chstonepillar,
                                    (u32) func_80107C2C,
                                    -0x7FF7E000,
                                    (u32) func_80800390_chstonepillar,
                                    0x0};
u8 D_80801480_chstonepillar[12] = {0x0, 0x4, 0x0, 0x6, 0x0, 0x8, 0x0, 0xA, 0x0, 0x0, 0x0, 0x0};
u8 D_8080148C_chstonepillar[12] = {0x0, 0x13, 0x3, 0xE9, 0x0, 0x16, 0x46, 0x50, 0x0, 0x2, 0x0, 0x0};
s32 D_80801498_chstonepillar[8] = {0x1D09C9,  0x150026, 0xCC0018, 0x0,
                                   0xE000E00, 0x230100, 0x2B0100, 0x1000000};
f32 D_808014B8_chstonepillar[14] = {2.66674e-39f,   3.214511e-39f, 2.978337e-39f,  2.5769847e+10f,
                                    3.490035e-39f,  2.204052e-39f, 5.022e-42f,     1.5777299e-30f,
                                    6.979677e-39f,  1.010443e-39f, 1.8367099e-38f, 6.3e-44f,
                                    1.6071562e-38f, 0.0f};
u8 D_808014F0_chstonepillar[16] = {0x0, 0x13, 0x4, 0xA9, 0x0, 0x16, 0x7D, 0x0,
                                   0x0, 0x14, 0x0, 0x0,  0x0, 0x0,  0x0,  0x0};
