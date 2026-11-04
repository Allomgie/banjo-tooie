#include "common.h"

extern Vec3f D_80801200_sukickball;
extern s32 func_801039E4(Actor *);
extern void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
extern Vec3f D_8080120C_sukickball;
extern void func_801015D0(void);
extern void func_800DF47C(void (*)(void), Actor *);
extern f32 func_800138D0(f32);
extern void *func_80100094(Actor *, u32);
extern s32 D_80801218_sukickball[];
extern void *func_80104248(Actor *);
extern void anctrl_setIndex(void *, s32);
extern void anctrl_start(void *);
extern void func_80101CDC(Actor *, f32);
extern int func_80101E14(Actor *, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern int func_800DC298(f32);
typedef struct {
    f32 sound_timer[2];
    u8 pad_8[0x18];
    s32 scores[4];
    u8 pad_30[9];
    u8 arena;
} Broad51KickballData;
extern f32 func_80102D78(Actor *, void *);
extern s32 func_80102CF4(Actor *, f32);
extern void func_80102B2C(Actor *, f32);
extern f32 D_80801234_sukickball[];
typedef struct {
    u8 pad_0[0x20];
    s32 scores[4];
    u8 unk_30[8];
    u8 unk_38;
} KickballScores;
extern f32 func_800DC178(f32, f32);
extern s32 func_800BF340(f32 *, f32 *, f32 *, u32, f32);
extern s32 func_800EFA98(f32 *, f32 *, f32);
typedef struct {
    f32 value[3];
} KickBallVector;
extern u8 D_80801228_sukickball[];
extern s32 func_800F0064(f32 *, f32, f32 *);
extern void func_800EF368(f32 *, f32);
float sukickball_entrypoint_15();

void func_80800000_sukickball(Actor *actor, void *unused, f32 *position, f32 scale)
{
    Vec3f rotation = D_80801200_sukickball;
    func_800DF830(3);
    func_800DE448(position, rotation.f, scale, NULL, func_801039E4(actor));
}

void sukickball_entrypoint_0(Actor *actor, void *unk_1)
{
    u8 *data;
    Vec3f rotation;
    s32 blend;
    f32 spawn_pos[3];

    data = func_80100094(actor, 0);
    // Matching: empty loop is needed for the match.
    do {
    } while (0);
    rotation = D_8080120C_sukickball;
    rotation.f[0] = actor->rotation[0];
    rotation.f[1] = 0.0f;
    rotation.f[2] = actor->rotation[2];
    func_800DF47C(func_801015D0, actor);
    blend = (s32) (func_800138D0(*(f32 *) (data + 0x14)) * (u32) *((u8 *) actor + 0x9B));
    if (blend < 0) {
        blend = -blend;
    }
    if (blend >= 97) {
        func_800DF744(3, 1);
        func_800DF410(blend);
        func_800DE448(actor->position, rotation.f, actor->scale, NULL,
                      func_8010347C(actor->unk0));
        if (func_800DF350()) {
            func_800DBEFC(func_80104130(), 4, data + 8);
        }
    }
    if (blend < 160) {
        func_800DF744(3, 2);
        func_800DF410(*((u8 *) actor + 0x9B) - blend);
        func_800DE448(actor->position, rotation.f, actor->scale, NULL,
                      func_8010347C(actor->unk0));
        if (func_800DF350()) {
            func_800DBEFC(func_80104130(), 5, data + 8);
        }
    }
    if (func_800DF350()) {
        spawn_pos[0] = actor->position[0];
        spawn_pos[1] = actor->position[1] - 30.0f;
        spawn_pos[2] = actor->position[2];
        func_80800000_sukickball((Actor *) actor->unk3C, unk_1, spawn_pos, 0.4f);
    }
}

void sukickball_entrypoint_1(Actor *actor, void *unk_1)
{
    func_800DF744(1, D_80801218_sukickball[actor->unk6C_0]);
    func_80101870(actor, unk_1);
    if (actor->unk7C_12) {
        func_80800000_sukickball((Actor *) actor->unk3C, unk_1, actor->position, 0.5f);
    }
}

void sukickball_entrypoint_2(Actor *actor, f32 unk_1, f32 unk_2)
{
    f32 *data;

    data = func_80100094(actor, 0);
    if (*(f32 *) &actor->actorData[3] > 0.5f) {
        if (func_801022E4(actor) == 0x63) {
            anctrl_setIndex(func_80104248(actor), 0x1D7);
            anctrl_start(func_80104248(actor));
        }
        func_80101CDC(actor,
                      func_800F10B4(*(f32 *) &actor->actorData[3], unk_1, unk_2, 1.0f, 0.5f));
    } else if (func_801022E4(actor) != 0x63) {
        anctrl_setIndex(func_80104248(actor), 0x63);
        func_80101CDC(actor, 8.0f);
        anctrl_start(func_80104248(actor));
    }
    if (data[1] <= 0.0f && (func_80101E14(actor, 0.5f) || func_80101E14(actor, 0.0f))) {
        func_800C4140(0xE627D4AE, actor->position, 0x3E800640);
        data[1] = 1.0f;
    }
}

// Returns the arena id for the current map.
s32 sukickball_entrypoint_3(void)
{
    switch (func_800EA05C()) {
        case 0xC6:
        case 0x12E:
            return 0;
        case 0xC8:
        case 0x12F:
            return 1;
        case 0xC9:
        case 0x130:
            return 2;
        case 0x17F:
        case 0x180:
            return 4;
        case 0xBB:
            return 3;
    }
    return 0;
}

// Sets the goal-line coordinate and clamps the other axis; random if out of range.
void sukickball_entrypoint_4(s32 goal, f32 *pos)
{
    pos[1] = 0.0f;
    switch (goal) {
        case 0:
            pos[0] = 846.0f;
            if (pos[2] < -108.0f || pos[2] > 108.0f)
                pos[2] = func_800DC178(-108.0f, 108.0f);
            break;
        case 2:
            if (pos[0] < -108.0f || pos[0] > 108.0f)
                pos[0] = func_800DC178(-108.0f, 108.0f);
            pos[2] = 846.0f;
            break;
        case 1:
            pos[0] = -846.0f;
            if (pos[2] < -108.0f || pos[2] > 108.0f)
                pos[2] = func_800DC178(-108.0f, 108.0f);
            break;
        case 3:
            if (pos[0] < -108.0f || pos[0] > 108.0f)
                pos[0] = func_800DC178(-108.0f, 108.0f);
            pos[2] = -846.0f;
    }
}

// Clamps the ball to the arena walls and bounces it off obstacles; returns 1 if moved.
s32 sukickball_entrypoint_5(Actor *actor, f32 *prev_pos)
{
    f32 hit[3];
    f32 delta[3];
    f32 pos[3];
    s32 clamped = 0;
    f32 unused;
    f32 push[3];

    func_800EFB24(delta, actor->position, prev_pos);
    func_800EE7F8(pos, actor->position);
    if (func_800BF340(prev_pos, pos, hit, 0x20020, 30.0f)) {
        func_800EFDE8(push, delta, hit);
        push[1] = 0.0f;
        func_800EFA98(push, push, 5.0f);
        func_800EE780(actor->position, pos, push);
        func_800EE7F8(prev_pos, actor->position);
        return 1;
    }
    if (actor->position[2] > 690.0f) {
        if (actor->position[0] > -159.0f && actor->position[0] < 159.0f) {
            if (actor->position[2] > 822.0f) {
                clamped = 1;
                actor->position[2] = 816.0f;
            }
        } else {
            actor->position[2] = 690.0f;
            clamped = 1;
        }
    }
    if (actor->position[2] < -696.0f) {
        if (actor->position[0] > -159.0f && actor->position[0] < 159.0f) {
            if (actor->position[2] < -822.0f) {
                clamped = 1;
                actor->position[2] = -816.0f;
            }
        } else {
            clamped = 1;
            actor->position[2] = -690.0f;
        }
    }
    if (actor->position[0] < -696.0f) {
        if (actor->position[2] < 159.0f && actor->position[2] > -159.0f) {
            if (actor->position[0] < -822.0f) {
                clamped = 1;
                actor->position[0] = -816.0f;
            }
        } else {
            clamped = 1;
            actor->position[0] = -690.0f;
        }
    }
    if (actor->position[0] > 696.0f) {
        if (actor->position[2] > -159.0f && actor->position[2] < 159.0f) {
            if (actor->position[0] > 822.0f) {
                clamped = 1;
                actor->position[0] = 816.0f;
            }
        } else {
            actor->position[0] = 690.0f;
            clamped = 1;
        }
    }
    if (clamped) {
        func_800EE7F8(actor->position, prev_pos);
    }
    return clamped;
}

s32 sukickball_entrypoint_6(s32 actor, s32 slot)
{
    return *(u8 *) (((s32) func_80100094(actor, 0) + slot) + 0xA) == 2;
}

s32 sukickball_entrypoint_7(s32 actor, s32 slot)
{
    return *(u8 *) ((s8 *) ((s32) func_80100094(actor, 0) + slot) + 0xA) == 1;
}

int sukickball_entrypoint_8(s32 actor, s32 slot)
{
    s32 value;
    s32 entry;
    s32 *data = func_80100094(actor, 0);
    data++;
    value = (entry = data[slot + 3]);
    return entry;
}

// Applies a score event to a team and plays the goal sound.
void sukickball_entrypoint_9(Actor *actor, s32 team, s32 event)
{
    Broad51KickballData *data;
    s32 goal_sound;
    data = func_80100094(actor, 0);
    goal_sound = 0;
    if (4 == (s32) actor->unk70_10) {
        switch (event) {
            case 1:
                data->scores[team] += 2;
                if ((!team && data->arena != 4) ||
                    (data->arena == 4 && func_800DC298(0.5f))) {
                    goal_sound = 2;
                } else {
                    goal_sound = 1;
                }
                break;
            case 5:
                data->scores[team] += 4;
                if ((!team && data->arena != 4) ||
                    (data->arena == 4 && func_800DC298(0.5f))) {
                    goal_sound = 2;
                } else {
                    goal_sound = 1;
                }
                break;
            case 2:
                data->scores[team]--;
                if (data->scores[team] < 0) {
                    data->scores[team] = 0;
                }
                if ((!team && data->arena != 4) ||
                    (data->arena == 4 && func_800DC298(0.5f))) {
                    goal_sound = 1;
                } else {
                    goal_sound = 2;
                }
                break;
            case 4:
                data->scores[team] -= 2;
                if (data->scores[team] < 0) {
                    data->scores[team] = 0;
                }
                if ((!team && data->arena != 4) ||
                    (data->arena == 4 && func_800DC298(0.5f))) {
                    goal_sound = 1;
                } else {
                    goal_sound = 2;
                }
        }
        switch (goal_sound) {
            case 1:
                if (data->sound_timer[0] <= 0.0f) {
                    func_800C4140(0x7FFF453A, actor->position, 0x3E800640);
                    data->sound_timer[0] = 1.0f;
                }
                break;
            case 2:
                if (data->sound_timer[1] <= 0.0f) {
                    func_800C4140(0x7FFF453B, actor->position, 0x3E800640);
                    data->sound_timer[1] = 1.0f;
                }
        }
    }
}

void sukickball_entrypoint_10(s32 actor, s32 slot, s32 value)
{
    s32 data;
    data = func_80100094(actor, 0);
    *(s8 *) ((s8 *) (data + slot) + 0x34) = (s8) value;
}

void sukickball_entrypoint_11(s32 actor, s32 slot)
{
    *(s8 *) ((s8 *) ((s32) func_80100094(actor, 0) + slot) + 0x34) = 0;
}

int sukickball_entrypoint_12(s32 actor, s32 slot)
{
    u8 *entry;
    entry = (s32) func_80100094(actor, 0) + slot;
    return entry[0x34];
}

// Pushes two overlapping balls apart; returns 1 if they overlapped.
int sukickball_entrypoint_13(f32 *ball_a, f32 *ball_b, f32 radius)
{
    KickBallVector diff;
    f32 saved_a[3];
    f32 saved_b[3];
    f32 b_y;
    f32 a_y;
    if (func_800F0064(ball_a, radius, ball_b)) {
        diff = *(KickBallVector *) D_80801228_sukickball;
        b_y = ball_b[1];
        a_y = ball_a[1];
        func_800EE7F8(saved_a, ball_a);
        func_800EE7F8(saved_b, ball_b);
        if (ball_b[0] == ball_a[0] && ball_b[2] == ball_a[2]) {
            ball_b[0] += func_800DC178(-5.0f, 5.0f);
            ball_b[2] += func_800DC178(-5.0f, 5.0f);
        }
        diff.value[0] = ball_a[0] - ball_b[0];
        diff.value[1] = ball_a[1] - ball_b[1];
        diff.value[2] = ball_a[2] - ball_b[2];
        func_800EF368(diff.value, radius * 1.1f);
        func_800EFB24(ball_b, saved_a, diff.value);
        func_800EE780(ball_a, saved_b, diff.value);
        ball_b[1] = b_y;
        ball_a[1] = a_y;
        return 1;
    }
    return 0;
}

void sukickball_entrypoint_14(Actor *actor)
{
    actor->unk54 = func_80102D78(actor, actor->actorData);
    if (actor->unk70_10 == 3) {
        actor->unk54 = sukickball_entrypoint_15(actor->unk6C_0);
    }
    if (!func_80102CF4(actor, 8.0f)) {
        func_80102B2C(actor, 8.0f);
    }
}

float sukickball_entrypoint_15(slot)
s32 slot;
{
    return D_80801234_sukickball[slot];
}

// Writes the player start position for a goal.
void sukickball_entrypoint_16(s32 goal, u8 *pos)
{
    switch (goal) {
        case 0:
            *(f32 *) ((s8 *) pos + 4) = 0.0f;
            *(f32 *) ((s8 *) pos + 8) = 0.0f;
            *(f32 *) ((s8 *) pos + 0) = 720.0f;
            return;
        case 2:
            *(f32 *) ((s8 *) pos + 0) = 0.0f;
            *(f32 *) ((s8 *) pos + 4) = 0.0f;
            *(f32 *) ((s8 *) pos + 8) = 720.0f;
            return;
        case 1:
            *(f32 *) ((s8 *) pos + 4) = 0.0f;
            *(f32 *) ((s8 *) pos + 8) = 0.0f;
            *(f32 *) ((s8 *) pos + 0) = -720.0f;
            return;
        case 3:
            *(f32 *) ((s8 *) pos + 0) = 0.0f;
            *(f32 *) ((s8 *) pos + 4) = 0.0f;
            *(f32 *) ((s8 *) pos + 8) = -720.0f;
    }
}

// Places the players at their goals.
s32 sukickball_entrypoint_17(s32 actor)
{
    s32 i;
    s32 unused;
    f32 pos[3];
    s32 *data;
    data = func_80100094(actor, 0);
    if ((u8) *(u8 *) ((char *) data + 0x39) != 3) {
        for (i = 0; i < 4; i++) {
            if (sukickball_entrypoint_6(actor, i)) {
                sukickball_entrypoint_16(i, &pos);
                func_800F8294(i, &pos);
            }
        }
    }
}

// Sets up the HUD score items.
void sukickball_entrypoint_18(Actor *actor)
{
    u8 *data;
    data = func_80100094(actor, 0);
    switch (data[0x39]) {
        case 0:
        case 1:
        case 2:
            func_800D2748(0xC3, 0x2D);
            break;
        case 4:
            func_800D2748(0xC3, 0x1F);
    }
    func_800D2748(0xC4, 0x20);
    func_800D2748(0xC5, 0x21);
    func_800D2748(0xC6, 0x22);
}

// Updates the HUD score items.
void sukickball_entrypoint_19(Actor *actor, s32 unk_1, s32 count)
{
    KickballScores *data;
    s32 i;
    s32 item_id;

    data = func_80100094(actor, 0);
    i = 0;
    if (count > 0) {
        do {
            item_id = i + 0xC3;
            if (data->unk_38 == 0) {
                func_800D2770(item_id, 0);
            } else {
                func_800D24E8(item_id, data->scores[i], 0);
            }
            if (unk_1 && data->unk_30[i])
                func_800D28A0(item_id);
            i++;
        } while (i != count);
    }
    data->unk_38 = 1;
}

// TU-NOTE: the .data of this overlay is defined here in C; values are taken from the ROM.
Vec3f D_80801200_sukickball = {0.0f, 0.0f, 0.0f};
Vec3f D_8080120C_sukickball = {0.0f, 0.0f, 0.0f};
s32 D_80801218_sukickball[4] = {0x4, 0x2, 0x1, 0x3};
u8 D_80801228_sukickball[12] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
f32 D_80801234_sukickball[7] = {2.7e+02f, 9e+01f, 1.8e+02f, 0.0f, 0.0f, 0.0f, 0.0f};
