#include "common.h"

typedef struct {
    u8 pad_0[8];
    f32 pos_y;
    u8 pad_C[0x64];
    unsigned zone : 7;
    unsigned unk_70_7 : 15;
    unsigned section : 6;
    unsigned unk_70_28 : 4;
} local_type;
extern f32 D_80136F54;
extern s32 func_800CC338();
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_800F4EC8(s32, f32 *, f32, f32, f32);
extern s32 func_800F54E4();
extern s32 func_800F8B88(void);
extern s32 _plsu_entrypoint_1(s32);
typedef struct {
    u8 pad_0[0x38];
    f32 scale;
    u8 pad_3C[0x26];
    u16 radius;
    u8 pad_64[0x24];
    s16 unk_88;
    s16 unk_8A;
} S_10C878;
extern f32 func_80103F38(void *, f32 *);
extern f32 func_8010A40C();
extern void func_8008FB58(f32 *, f32, f32);
extern s32 func_800F00A4(f32 *, f32, f32, f32, f32 *);
typedef struct {
    f32 pos[3];
    s16 active;
    s16 ok;
} Bounds_80136F50;
extern Bounds_80136F50 D_80136F50;
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s32 func_800F0064(f32 *, f32, f32 *);
extern s32 D_80136F68[];
extern s32 func_800F5898(void);
extern s32 func_800F6438(s32);
extern s32 D_80136F8C;
extern f32 func_80013728(f32);
extern f32 mlAbsF(f32);
extern void func_80102844(s32, f32, s32, void *);
f32 func_80102D78(Actor *param_0, f32 *param_1);
extern s32 func_800F57C0(s32 param_0);
extern f32 func_800F5794(s32, f32 *, s32);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
extern f32 func_800D8FF8(void);
extern void func_800EF334(s32, f32);
void func_800F5A2C(s32 a, s32 b, s32 *c);
void func_800EF3DC(s32 *a, s32 *b);
void func_800EE780(s32 a, s32 *b, s32 *c);
void func_800EF04C(s32 a, s32 *b);
extern s16 D_80136F5C;
extern s16 D_80136F5E;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800F5A00(s32, f32 *);
extern s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern f32 func_800F0C68(f32 *, f32 *, f32, f32);
extern void func_800F5BF0(s32, f32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern f32 func_800EEFD4(f32 *);
extern s32 func_800F0BD0(f32 *, f32 *, f32, f32);
extern s32 func_800F682C(s32 param_0);
extern s32 func_80109EE0(s32 param_0, s32 param_1);
extern void func_800F4F34(s32 param_0, s32 param_1, f32 param_2, f32 param_3);
void func_8010CE28();
int func_8010D600();
void func_8010D6E0(s32 param_0, s32 param_1, f32 param_2, f32 param_3);

extern s32 D_80136F60;
extern s32 D_80136F64;

// Cached player vs the actor's zone/section.
s32 func_8010C500(u8 *actor)
{
    u32 bits;
    u32 zone;
    u32 section;

    bits = *(u32 *) ((s8 *) actor + 0x70);
    zone = bits >> 25;
    if (zone == 0) {
        return 1;
    }
    section = ((bits << 22) >> 26) - 1;
    return (func_800CC338(D_80136F50.pos, zone - 1, section) + 1) != 0;
}

// Same as func_8010C500, for the player in slot `player`.
int func_8010C550(void *actor, void *player)
{
    f32 pos[3];
    u32 bits;
    if (!(((u32 *) actor)[0x70 / 4] >> 25)) {
        return 1;
    }
    func_800F5A00(player, &pos);
    bits = ((u32 *) actor)[0x70 / 4];
    return (func_800CC338(&pos, (bits >> 0x19) - 1, ((bits << 0x16) >> 0x1A) - 1,
                          actor) +
            1) != 0;
}

// Cached player within +-range of the actor's height and in its zone/section.
int func_8010C5C0(local_type *actor, f32 range)
{
    if (actor->zone == 0)
        return 1;
    return D_80136F54 < actor->pos_y + range && actor->pos_y - range < D_80136F54 &&
           func_800CC338(D_80136F50.pos, actor->zone - 1, actor->section - 1) != -1;
}

int func_8010C668(local_type *actor, f32 *pos, f32 top_offset, f32 bottom_offset)
{
    if (actor->zone == 0)
        return 1;
    return D_80136F50.pos[1] < pos[1] + top_offset && pos[1] + bottom_offset < D_80136F50.pos[1] &&
           func_800CC338(D_80136F50.pos, actor->zone - 1, actor->section - 1) != -1;
}

s32 func_8010C710(actor)
f32 *actor;
{
    f32 diff[3];
    func_800EFB24(diff, actor + 1, D_80136F50.pos);
    return (s32) func_800EEAA4(diff, diff);
}

int func_8010C754()
{
    f32 dist_sq;
    dist_sq = func_8010C710();
    return sqrtf(dist_sq);
}

// Pushes the players out of a collision cylinder at pos.
void func_8010C788(f32 *pos, f32 unk_0, f32 unk_1, f32 radius)
{
    s32 player;
    s32 unk_2;
    player = func_800F54E4();
    radius -= 30.0f;

if (func_800F8B88() == 3) {
    unk_2 = _plsu_entrypoint_1(0xA);
    if (unk_2 >= 0) {
        func_800F4EC8(unk_2, pos, unk_0, unk_1, radius);
    }
}

func_800F4EC8(player, pos, unk_0, unk_1, radius);
}

void func_8010C820(u8 *actor, s32 unk_0, s32 radius)
{
    func_8010C788((f32 *) (actor + 4), unk_0, 0.0f, radius + 0x1e);
}

void func_8010C878(S_10C878 *actor, void *pos, f32 size_scale)
{
    f32 unk_0 = actor->unk_8A * actor->scale;
    f32 unk_1 = actor->unk_88 * actor->scale;
    f32 radius = actor->scale * (f32) (u32) actor->radius * size_scale;

if (actor->radius != 0) {
    func_8010C788(pos, unk_0, unk_1, radius);
}

}

void func_8010C908(s32 actor, s32 pos)
{
    func_8010C878(actor, pos, func_8010A40C());
}

void func_8010C93C(s32 actor, s32 pos, f32 size_scale)
{
    func_8010C878(actor, pos, size_scale);
}

void func_8010C964(void *actor)
{
    // Matching: the extra array element is needed for the match.
    f32 pos[4];
    f32 radius;
    radius = func_80103F38(actor, &pos[1]);
    func_8008FB58(&pos[1], 0.0f, func_8010A40C(actor) * radius);

}

// Matching: the last call has no return statement; needed for the match.
s32 func_8010C9B0(s32 center, s32 radius)
{
    if (D_80136F50.ok == 0) {
        return 0;
    }

func_800EFFB4(center, (f32) radius, D_80136F50.pos);

}

s32 func_8010C9FC(void *center, s32 unk_0, s32 unk_1, s32 unk_2)
{
    if (D_80136F50.ok == 0) {
        return 0;
    }

return func_800F00A4(center, (f32) unk_0, (f32) unk_1, (f32) unk_2, D_80136F50.pos);

}

// Matching: the last call has no return statement; needed for the match.
s32 func_8010CA74(s32 center, s32 unk_0)
{
    if (D_80136F50.ok == 0) {
        return 0;
    }

func_800F0064(center, (f32) unk_0, D_80136F50.pos);

}

s32 func_8010CAC0(f32 *center, u32 radius)
{
    if (D_80136F50.active == 0) {
        return 0;
    }

return func_800EFFB4(center, (f32) (s32) radius, D_80136F50.pos);

}

s32 func_8010CB0C(f32 center[3], u32 unk_0, u32 unk_1, u32 unk_2)
{
    if (D_80136F50.active == 0) {
        return 0;
    }

return func_800F00A4(center, (f32) (s32) unk_0, (f32) (s32) unk_1, (f32) (s32) unk_2,
                     D_80136F50.pos);

}

s32 func_8010CB84(f32 *center, u32 unk_0)
{
    if (D_80136F50.active == 0) {
        return 0;
    }

return func_800F0064(center, (f32) (s32) unk_0, D_80136F50.pos);
}

// Writes the center of the player's body (position + 60 up) and returns its radius.
f32 func_8010CBD0(s32 player, u8 *pos)
{
    func_800F5A00(player, pos);
    *(f32 *) ((char *) pos + 4) = *(f32 *) ((char *) pos + 4) + 60.0f;
    return 90.0f;
}

// Collects the players within radius of center into D_80136F68 (count at [8], iterator at [9]).
// Returns the count.
s32 func_8010CC10(s32 center, f32 radius)
{
    s32 i;
    f32 player_radius;
    f32 player_pos[3];

    D_80136F68[8] = 0;
    D_80136F68[9] = 0;
    for (i = 0; i < func_800F5898(); i++) {

if (func_800F6438(i)) {
    player_radius = func_8010CBD0(i, player_pos);
    if (func_800EFFB4(center, radius + player_radius, player_pos)) {
        D_80136F68[D_80136F68[8]] = i;
        D_80136F68[8]++;
    }
}

}
return D_80136F68[8];
}

// Resets the iterator over the players found by func_8010CC10.
int func_8010CCE0()
{
    D_80136F8C = 0;
}

// Next player found by func_8010CC10, or -1 when done.
int func_8010CCEC()
{
    int player;
    if (((int *) D_80136F68)[9] >= ((int *) D_80136F68)[8]) {
        return -1;

}
player = ((int *) D_80136F68)[((int *) D_80136F68)[9]];
(int *) D_80136F68[9]++;
return player;
}

void func_8010CD28(s32 actor)
{
    func_800F1DF4(actor + 4, D_80136F50.pos);
}

int func_8010CD50(s32 actor, s32 player)
{
    f32 pos[3];
    func_800F5A00(player | 0, pos);
    func_800F1DF4(actor + 4, pos);
}

int func_8010CD88(u8 *actor, f32 tolerance_0, f32 tolerance_1)
{
    f32 angle[2];
    func_8010CE28(actor, angle);
    angle[0] = mlAbsF(func_80013728(*(f32 *) (actor + 0x44) - angle[0]));
    angle[1] = mlAbsF(func_80013728(*(f32 *) (actor + 0x48) - angle[1]));
    return angle[1] < tolerance_1 && angle[0] < tolerance_0;
}

void func_8010CE28(actor, angle) s32 actor;
f32 *angle;
{
    func_800F18FC(actor + 4, D_80136F50.pos, angle);
    *angle = 360.0f - *angle;
}

void func_8010CE70(s32 actor, s32 unk_0, s32 unk_1)
{
    func_80102844(actor, (f32) unk_0, unk_1, &D_80136F50);
}

s32 func_8010CEAC(Actor *actor)
{
    f32 player_pos[3];

    func_8010D600(player_pos);
    *(f32 *) ((char *) actor + 0x54) = func_80102D78(actor, player_pos);
    return func_80102BF8(actor, 0x3DCCCCCD, 0x40800000, 0x43340000);
}

s32 func_8010CEF8(s32 actor, s32 radius)
{
    s32 player;
    f32 unk_0;
    f32 point;
    s32 count;
    s32 i;
    s32 unk_1;

    unk_1 = actor + 4;
    player = func_800F54E4();
    count = func_800F57C0(player);
    i = 0;
    if (count > 0) {
    loop_2:
        if (func_800F0008(actor + 4, (f32) radius, &point,
                          func_800F5794(player, &point, i)) != 0) {
            return 1;
        }

i += 1;

if (i < count) {
    goto loop_2;
}

}
return 0;
}

s32 func_8010CFBC(s32 pos, s32 y_offset, s32 radius)
{
    s32 count;
    s32 player;
    f32 point[3];
    s32 i;
    f32 center[3];

    player = func_800F54E4();
    count = func_800F57C0(player);
    func_800EE7F8(center, pos);
    i = 0;
    center[1] += (f32) y_offset;
    if (count > 0) {
        do {
            if (func_800F0008(center, (f32) radius, point,
                              func_800F5794(player, point, i)) != 0) {
                return 1;
            }
            i++;
        } while (i != count);

}
return 0;
}

// Predicts where the player in slot `player` will be after `seconds`, written to out.
void func_8010D09C(s32 player, s32 out, f32 seconds)
{
    s32 prev_pos[3];
    s32 pos[3];
    s8 _sfpad[8];
    s32 velocity;
    f32 inv_dt;
    inv_dt = 1.0f / func_800D8FF8();
    func_800F5A00(player, &pos);
    func_800F5A2C(player, 8, &prev_pos);
    func_800EFB24(&velocity, &pos, &prev_pos);
    func_800EF334(&velocity, seconds * inv_dt);
    func_800EE780(out, &pos, &velocity);
}

void func_8010D12C(s32 player, s32 out, f32 seconds, s32 unk_0)
{
    s32 prev_pos[3];
    s32 pos[3];
    s32 velocity[3];
    s32 unk_1[3];
    f32 inv_dt;

    inv_dt = 1.0f / func_800D8FF8();
    func_800F5A00(player, &pos[0]);
    func_800F5A2C(player, 8, &prev_pos[0]);
    func_800F5A2C(player, unk_0, &unk_1);
    func_800EF3DC(&unk_1, &pos[0]);
    func_800EFB24(&velocity[0], &pos[0], &prev_pos[0]);
    func_800EF334(&velocity[0], seconds * inv_dt);
    func_800EE780(out, &pos[0], &velocity[0]);
    func_800EF04C(out, &unk_1);
}

// Caches the main player's state for this frame.
int func_8010D1E8()
{
    func_8008FE68(D_80136F50.pos);
    D_80136F5C = func_80090128();
    D_80136F5E = func_80090150();
    D_80136F60 = func_8008FD48();
    D_80136F64 = func_8008FF6C();
}

int func_8010D23C()
{
    return D_80136F5C;
}

int func_8010D248()
{
    return D_80136F5E;
}

// Copies the cached player position to dest.
void func_8010D254(s32 dest)
{
    func_800EE7F8(dest, D_80136F50.pos);
}

s32 func_8010D278()
{
    return D_80136F60;
}

s32 func_8010D284()
{
    return D_80136F64;
}

s32 func_8010D290(s32 unk_0)
{
    s32 i;
    s32 main_player;
    main_player = func_800F54E4(unk_0);
    if (main_player == (-1)) {
        return -1;

}
if (func_800F6438(main_player)) {
    // Matching: needed for the match.
    if (1) {
        if (func_800F64A4(main_player, unk_0) == 0) {
            return main_player;
        }
    }

}
for (i = 0; i < 8; i++) {
    if (i != main_player) {
        if (func_800F6438(i)) {
            if (func_800F64A4(i, unk_0) == 0) {
                return i;
            }
        }
    }

}

return -1;
}

// Index of the player hit by the segment (skipping one player), or -1.
s32 func_8010D350(f32 *seg_start, f32 *seg_end, f32 unk_0, s32 skip_player)
{
    f32 pos[3];
    f32 start[3];
    f32 end[3];
    f32 hit[3];
    f32 unk_1;
    f32 unk_2;
    f32 unk_3;
    s32 i;
    func_800EE7F8(start, seg_start);
    func_800EE7F8(end, seg_end);
    unk_1 = 120.0f;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6438(i) && i != skip_player) {
            unk_2 = unk_0 * 2;
            unk_3 = 55.0f + unk_0;
            func_800F5A00(i, pos);
            pos[1] -= unk_0;
            unk_1 += unk_2;
            if (func_800F0734(start, end, pos, unk_3, unk_1, hit, hit))
                return i;
        }

}
return -1;
}

// Nearest player in the cone from origin, or -1.
s32 func_8010D490(f32 *origin, f32 *dir, f32 unk_0, f32 unk_1, s32 skip_player)
{
    s32 best;
    f32 unk_2;
    f32 pos[3];
    f32 to_player[3];
    f32 dist;
    f32 best_dist;
    s32 i;
    f32 dir_copy[3];
    func_800EE7F8(dir_copy, dir);
    // Matching: dead reassignment needed for the match.
    dir = &dist;
    unk_2 = func_800F0C68(origin, dir_copy, unk_0, unk_1);
    best = -1;
    best_dist = 1e+08f;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6438(i) && i != skip_player) {
            func_800F5BF0(i, pos);
            func_800EFB24(to_player, pos, origin);
            dist = func_800EEFD4(to_player);
            if (dist < best_dist && func_800F0BD0(to_player, dir_copy, unk_0, unk_2)) {
                best = i;
                best_dist = dist;
            }
        }

}
if (best == -1)
    return -1;
return best;
}

void func_8010D5DC(s32 arg0, s32 arg1)
{
    func_8010114C(arg0, 0x32, arg1);
}

int func_8010D600(dest)
s32 dest;
{
    // Matching: the empty if with the repeated test is needed for the match.
    if ((dest && dest) && dest) {
    }
    if (func_8010D23C(dest)) {
        func_8008FE68(dest);
    } else {
        func_800E3980();
    }
}

int func_8010D640(s32 dest)
{
    if ((func_8010D23C() != 0) && (func_800DB9B0() == 0)) {
        func_8008FE68(dest);
        return;

}
func_800E3980(dest);
}

// Pushes the players out of the actor's collision cylinder.
void func_8010D690(void *actor)
{
    // Matching: the extra array element is needed for the match.
    f32 pos[4];
    f32 radius;
    radius = func_80103F38(actor, &pos[1]);
    func_8010D6E0(actor, &pos[1], 0.0f, func_8010A40C(actor) * radius);
}

void func_8010D6E0(s32 actor, s32 pos, f32 unk_0, f32 radius)
{
    s32 i;
    for (i = 0; i < 8; i++) {
        if (func_800F6438(i) != 0) {
            if (func_800F682C(i) != 0) {
                if (func_80109EE0(actor, 1) == 0) {
                    continue;
                }
            }
            func_800F4F34(i, pos, unk_0, radius);
        }

}
}
