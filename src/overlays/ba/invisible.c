// Probably the player invisibility effect: two fade channels with fade in/out states, alpha
// that rises with movement, a timer and on/off sounds; plus a sort of players by distance.
#include "common.h"
#include "playerstate.h"
#include "yaw.h"

typedef struct {
    u8 pad0[0x30];
} InvisiblePart;
typedef struct {
    u8 pad0[0x1C];
    InvisiblePart unk1C[2];
} InvisibleState;
typedef struct {
    u8 pad0[0xA8];
    InvisibleState *unkA8;
} InvisiblePlayerView;

void bainvisible_entrypoint_1(void *player, f32 max_speed, f32 max_turn_rate);

extern void bastatetimer_clear(InvisiblePlayerView *, s32);
extern void bastatetimer_set(InvisiblePlayerView *, s32, f32);
extern f32 func_800D8FF8(void);
extern void func_8009BC08(PlayerState *, f32 *);
extern f32 func_800EFC7C(f32 *, f32 *);
extern void func_8009DBF0(PlayerState *, s32, f32);
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_80013728(f32);
extern f32 mlAbsF(f32);
extern f32 func_800F214C(f32, f32);
void func_808001BC_bainvisible();

// Sets a part's state: 0 visible, 1 fading in, 2 start delay, 3 invisible, 4 forced alpha.
void func_80800000_bainvisible(player, part, new_state) PlayerState *player;
u8 *part;
s32 new_state;
{
    u8 *main_part;
    u8 *second_part;
    part[0] = new_state;
    second_part = *(u8 **) ((u8 *) player + 0xA8) + 0x4C;
    main_part = *(u8 **) ((u8 *) player + 0xA8) + 0x1C;
    switch (new_state) {
        case 0:
            if (!main_part[0] && !second_part[0])
                func_8009ADF0(player, 0xC, 0);
            break;
        case 2:
            if (!func_8009AD78(player, 0xC)) {
                func_8009ADF0(player, 0xC, 1);
                bainvisible_entrypoint_1(player, 750.0f, 135.0f);
                func_8009BC08(player, *(f32 **) ((u8 *) player + 0xA8));
                *(f32 *) (*(u8 **) ((u8 *) player + 0xA8) + 0xC) = yaw_get(player);
                second_part[0x1C] = 0;
                *(f32 *) (second_part + 0xC) = 1.0f;
                *(f32 *) (second_part + 4) = 0.67f;
                main_part[0x1C] = 0;
                *(f32 *) (main_part + 0xC) = 1.0f;
                *(f32 *) (main_part + 4) = 0.67f;
                *(f32 *) (*(u8 **) ((u8 *) player + 0xA8) + 0x10) = 0.0f;
                func_808001BC_bainvisible(player);
            }
            break;
        case 3:
            if (part == main_part)
                func_8009DBF0(player, 0x65E, 1.0f);
            break;
        case 4:
            if (!func_8009AD78(player, 0xC)) {
                func_8009ADF0(player, 0xC, 1);
                *(f32 *) (second_part + 0xC) = 1.0f;
                *(f32 *) (main_part + 0xC) = 1.0f;
            }
            *(f32 *) (part + 0x24) = *(f32 *) (part + 0xC);
            *(f32 *) (part + 0x28) = 0.0f;
            break;
        case 1:
            part[0x1C] = 0;
            *(f32 *) (part + 8) = 1.0f;
    }
}

// While invisible, raises the target alpha with movement speed and turn rate.
void func_808001BC_bainvisible(player) u8 *player;
{
    u8 *part;
    f32 speed_frac;
    f32 turn_frac;
    f32 inv_dt;
    f32 pos[3];
    f32 yaw;
    f32 activity;
    f32 max_turn_rate;
    s32 offset;
    u8 *part_iter;

    part = *(u8 **) (player + 0xA8) + 0x1C;
    inv_dt = 1.0f / func_800D8FF8();
    func_8009BC08(player, &pos);
    speed_frac = func_800EFB8C(&pos, *(f32 **) (player + 0xA8)) * inv_dt;
    func_800EE7F8(*(f32 **) (player + 0xA8), &pos);
    turn_frac = *(f32 *) (*(u8 **) (player + 0xA8) + 0x14);
    if (turn_frac < speed_frac) {
        speed_frac = 1.0f;
    } else {
        speed_frac /= turn_frac;
    }
    yaw = yaw_get(player);
    turn_frac = mlAbsF(func_80013728(yaw - *(f32 *) (*(u8 **) (player + 0xA8) + 0xC)));
    *(f32 *) (*(u8 **) (player + 0xA8) + 0xC) = yaw;
    activity = turn_frac * inv_dt;
    max_turn_rate = *(f32 *) (*(u8 **) (player + 0xA8) + 0x18);
    turn_frac = max_turn_rate < activity ? 1.0f : activity / max_turn_rate;
    *(f32 *) (*(u8 **) (player + 0xA8) + 0x10) = turn_frac < speed_frac ? speed_frac : turn_frac;
    activity = turn_frac < speed_frac ? speed_frac : turn_frac;
    if (part[0] == 3) {
        *(f32 *) (part + 8) = 0.255f * activity + 0.07499999553f;
    }
    if (part[0x30] == 3) {
        *(f32 *) (part + 0x38) = 0.1999999881f * activity + 0.3999999762f;
    }
    part_iter = part;
    offset = 0;
    do {
        if (part_iter[0x1C]) {
            if (*(f32 *) (part_iter + 8) < *(f32 *) (part_iter + 0x10)) {
                *(f32 *) (part_iter + 8) = *(f32 *) (part_iter + 0x10);
            }
            if (*(f32 *) (part_iter + 0x14) < *(f32 *) (part_iter + 8)) {
                *(f32 *) (part_iter + 8) = *(f32 *) (part_iter + 0x14);
            }
        }
        offset += 0x30;
        part_iter += 0x30;
    } while (offset != 0x60);
    // Matching: empty block needed for the match.
    if (part) {
    }
}

// Eases the alpha toward its target; true once close enough.
s32 func_808003AC_bainvisible(part)
f32 *part;
{
    f32 diff;

    diff = part[2] - part[3];
    part[3] += diff * 0.25f;
    return func_800F214C(diff, 0.01f) == 0.0f;
}

// State size.
s32 bainvisible_entrypoint_0()
{
    return 0x7C;
}

// Sets the speed and turn rate at which the alpha is fully raised.
void bainvisible_entrypoint_1(void *player, f32 max_speed, f32 max_turn_rate)
{
    *(f32 *) ((u8 *) *(void **) ((u8 *) player + 0xA8) + 0x14) = max_speed;
    *(f32 *) ((u8 *) *(void **) ((u8 *) player + 0xA8) + 0x18) = max_turn_rate;
}

// Current alpha of a part.
f32 bainvisible_entrypoint_2(u8 *player, s32 part_index)
{
    return *(f32 *) ((s8 *) (*(s32 *) ((s8 *) player + 0xA8) + (part_index * 0x30)) + 0x28);
}

// Fades both parts in and clears the timer.
void bainvisible_entrypoint_3(InvisiblePlayerView *player)
{
    InvisiblePart *part;

    part = &player->unkA8->unk1C[0];
    func_80800000_bainvisible(player, part, 1);
    func_80800000_bainvisible(player, ++part, 1);
    bastatetimer_clear(player, 9);
}

// Makes both parts visible and clears the timer.
void bainvisible_entrypoint_4(InvisiblePlayerView *player)
{
    InvisiblePart *part;

    part = &player->unkA8->unk1C[0];
    func_80800000_bainvisible(player, part, 0);
    func_80800000_bainvisible(player, ++part, 0);
    bastatetimer_clear(player, 9);
}

// Turns both parts invisible and starts the timer.
void bainvisible_entrypoint_5(InvisiblePlayerView *player, f32 duration)
{
    InvisiblePart *part;

    part = &player->unkA8->unk1C[0];
    func_80800000_bainvisible(player, part, 2);
    func_80800000_bainvisible(player, ++part, 2);
    bastatetimer_set(player, 9, duration);
}

// Per-frame update of both parts.
void bainvisible_entrypoint_6(void *player)
{
    s32 offset;
    u8 *part;
    f32 progress;

    if (*(*(u8 **) ((u8 *) player + 0xA8) + 0x1C) == 3) {
        func_808001BC_bainvisible();
    }
    for (offset = 0; offset != 0x60; offset += 0x30) {
        part = *(u8 **) ((u8 *) player + 0xA8) + offset + 0x1C;
        switch (*part) {
            case 2:
                *(f32 *) (part + 4) -= func_800D8FF8();
                if (*(f32 *) (part + 4) < 0.0f) {
                    func_80800000_bainvisible(player, part, 3);
                }
                break;
            case 3:
                func_808003AC_bainvisible(part);
                if (bastatetimer_isDone(player, 9)) {
                    func_80800000_bainvisible(player, part, 1);
                    func_8009DBF0(player, 0x65D, 1.0f);
                }
                if (part[0x1C]) {
                    *(f32 *) (part + 0x18) -= func_800D8FF8();
                    if (*(f32 *) (part + 0x18) <= 0.0f) {
                        part[0x1C] = 0;
                    }
                }
                break;
            case 4:
                *(f32 *) (part + 0x28) += func_800D8FF8();
                progress = *(f32 *) (part + 0x28) < *(f32 *) (part + 0x2C)
                              ? *(f32 *) (part + 0x28) / *(f32 *) (part + 0x2C)
                              : 1.0f;
                *(f32 *) (part + 0xC) =
                    (*(f32 *) (part + 0x20) - *(f32 *) (part + 0x24)) * progress +
                    *(f32 *) (part + 0x24);
                break;
            case 1:
                if (func_808003AC_bainvisible(part)) {
                    func_80800000_bainvisible(player, part, 0);
                }
        }
    }
}

// Sets the alpha limits of the selected parts, with an optional duration.
void bainvisible_entrypoint_7(u8 *player, s32 part_mask, f32 min_alpha, f32 max_alpha, f32 duration)
{
    int limit_active;
    u8 *state;
    if (duration != 0.0f) {
        limit_active = 1;
    } else {
        limit_active = 0;
    }
    if (part_mask & 1) {
        state = *(u8 **) (player + 0xA8);
        state[0x38] = limit_active;
        *(f32 *) (state + 0x34) = duration;
        *(f32 *) (state + 0x2C) = min_alpha;
        state += 0x1C;
        *(f32 *) (state + 0x14) = max_alpha;
    }
    if (part_mask & 2) {
        state = *(u8 **) (player + 0xA8);
        state[0x68] = limit_active;
        *(f32 *) (state + 0x64) = duration;
        *(f32 *) (state + 0x5C) = min_alpha;
        state += 0x4C;
        *(f32 *) (state + 0x14) = max_alpha;
    }
}

// Forces a part to an alpha over a duration.
int func_808007CC_bainvisible(f32 player[3], f32 part[3], f32 alpha, f32 duration)
{
    func_80800000_bainvisible(player, part, 4);
    part[8] = alpha;
    part[11] = duration;
}

int bainvisible_entrypoint_8(Actor *player, s32 part_mask, f32 alpha, f32 duration)
{
    if (part_mask & 1) {
        func_808007CC_bainvisible(player, *(s32 *) ((char *) player + 0xA8) + 0x1C, alpha,
                                  duration);
    }
    if (part_mask & 2) {
        func_808007CC_bainvisible(player, *(s32 *) ((char *) player + 0xA8) + 0x4C, alpha,
                                  duration);
    }
}

// Sorts the players by distance to a point, farthest first.
void bainvisible_entrypoint_9(PlayerState **players, s32 count, f32 *point)
{
    f32 pos[3];
    f32 dist[8];
    f32 d;
    PlayerState *current;
    s32 i;
    s32 j;
    for (i = 0; i < count; i++) {
        func_8009BC08(players[i], pos);
        d = func_800EFC7C(pos, point);
        current = players[i];
        for (j = i; j > 0 && dist[j - 1] < d; j--) {
            players[j] = players[j - 1];
            dist[j] = dist[j - 1];
        }
        players[j] = current;
        dist[j] = d;
    }
}
