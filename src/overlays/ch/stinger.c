#include "common.h"

extern s32 D_808007D0_chstinger[];
extern s32 D_808007FC_chstinger[];
extern s32 D_80800844_chstinger[];
extern f32 func_800DC178(f32, f32);
extern void func_800EFA98(f32 *, f32 *, f32);
extern void func_800EE780(f32 *, f32 *, f32 *);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern void func_800CB840();
extern void func_80101FDC();
typedef struct {
    u8 pad_0[0x28];
    u8 skip_update;
} StingerLife;  // skip_update: set on entering state 2, skips one missile update
extern void func_80109BEC(f32 *, f32, s32, s32, s32, Unk80132ED0 *);
extern void func_800F1A88(int, f32 *);
extern void func_800F5A00(s32, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern int D_80800870_chstinger[];
extern void _sumissilehome_entrypoint_6();
extern void func_800FFAB0();
extern void func_80103014();
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern s32 func_800CD820(Unk80132ED0 *, f32 *, f32 *, f32);

// Impact effect: sparkle burst plus two particle emitters.
void func_80800000_chstinger(Actor *actor)
{
    s32 emitter;
    f32 dir[3];
    f32 pos[3];

    if (actor->unk7C_12) {
        emitter = func_800B5BE4(0x1B);
        emitter = func_800BABB8(emitter, actor->position, actor->position, 1.0f,
                                &D_808007D0_chstinger);
        func_800EFA98(dir, (f32 *) ((u8 *) actor + 0x28), func_800DC178(-200.0f, -400.0f));
        func_800BA930(emitter, (s16) dir[0], (s16) dir[1], (s16) dir[2],
                      (s16) dir[0], (s16) dir[1], (s16) dir[2]);
        func_800BA22C(emitter, 3);
        func_800EFA98(dir, (f32 *) ((u8 *) actor + 0x28), -25.0f);
        func_800EE780(pos, actor->position, dir);
        func_800BBCB8(pos, 0, 1.0f, 1, &D_80800844_chstinger);
        func_800EF04C(pos, dir);
        emitter = func_800B5BE4(8);
        func_800BABB8(emitter, pos, NULL, 1.0f, &D_808007FC_chstinger);
    }
}

// State change: 2 = flying, 3 = impact (effect, then removed).
void func_8080015C_chstinger(Actor *actor, s32 new_state)
{
    StingerLife *life;
    s32 state;
    life = func_80100094(actor, 0);
    if (new_state != actor->unk70_10) {
        func_80101FDC(actor, new_state);
        state = actor->unk70_10;
        switch (state) {
            case 2:
                life->skip_update = 1;
                break;
            case 3:
                func_800CB840(4, actor);
                func_80109BEC(actor->position, 120.0f, 2, 0, 0, actor->unk0);
                func_800CB870();
                func_80800000_chstinger(actor);
        }
    }
}

// Orients the stinger along its flight direction.
void func_80800218_chstinger(s32 actor)
{
    f32 angles[2];
    func_800F1A88(actor + 0x28, angles);
    *(f32 *) (actor + 0x44) = -angles[0];
    *(f32 *) (actor + 0x48) = angles[1];
}

void func_8080025C_chstinger(s32 actor)
{
}

// Finds the nearest other player inside the cone in front of the stinger.
// Returns the player index or -1; out_dir gets the direction to them.
s32 func_80800264_chstinger(Actor *actor, f32 *out_dir)
{
    f32 best_dist;
    f32 dist;
    s32 i;
    s32 best_player;
    f32 dir[3];
    u8 *life;
    f32 *origin;
    s32 owner;
    s32 hit;
    f32 player_pos[3];
    life = func_80100094(actor, 0);
    best_dist = 0.0f;
    origin = (f32 *) (life + 0x18);
    best_player = -1;
    owner = *(s8 *) life;
    for (i = 0; i < func_800F5898(); i++) {
        if (func_800F6438(i) && i != owner) {
            func_800F5A00(i, player_pos);
            dist = func_800EEB40(player_pos, origin);
            if (best_player < 0 || dist < best_dist) {
                hit = func_800F0734(origin, actor->position, player_pos, 55.0f, 120.0f, dir,
                                        dir);
                if (hit) {
                    best_player = i;
                    best_dist = dist;
                    func_800EE7F8(out_dir, dir);
                }
            }
        }
    }
    return best_player;
}

// Multiplayer hit check: damages the targeted player.
s32 func_808003B0_chstinger(s32 actor)
{
    f32 dir[3];
    s32 target;
    s32 found;
    if (func_800EA068(0x4000) != 0) {
        found = func_80800264_chstinger(actor, dir);
        target = found;
        if (found >= 0) {
            func_800F7A7C(target, *(s8 *) ((char *) func_80100094(actor, 0) + 0x0), 1, 3,
                          dir);
            return 1;
        }
    }
    return 0;
}

void func_80800420_chstinger(Actor *actor)
{
    f32 age;
    f32 dt;
    s32 hit_level;
    s32 move_result;
    s32 hit_player;
    u8 *life;

    life = func_80100094(actor, 0);
    age = *(f32 *) (life + 0x14);
    dt = func_800D8FF8();
    switch (actor->unk70_10) {
        case 2:
            if (life[0x28]) {
                life[0x28] = 0;
                move_result = 0;
            } else {
                _sumissilehome_entrypoint_6(actor, life);
                move_result = func_8010B990(actor, 0x100004);
            }
            if (move_result == 0x20)
                func_8010AA78(actor->position);
            func_80800218_chstinger(actor);
            actor->rotation[2] = func_800136E4(actor->rotation[2] + dt * 1200.0f);
            func_80103014(actor);
            func_8010A590(actor);
            func_800CB840(4, actor);
            hit_level =
                func_800CD820(actor->unk0, (f32 *) (life + 0x18), actor->position, 80.0f);
            func_800CB870();
            func_8010A570(actor);
            // Matching: redundant comparison needed for the match.
            if (move_result == 0x20 || (hit_level != 0) != 0 || *(f32 *) (life + 0x24) > 5000.0f) {
                func_8080015C_chstinger(actor, 3);
            }
            hit_player = func_808003B0_chstinger(actor);
            if (hit_player)
                func_8080015C_chstinger(actor, 3);
            break;
        case 3:
            func_800FFAB0(actor);
    }
    *(f32 *) (life + 0x14) = age + dt;
    *(f32 *) (life + 0x24) += func_800EEAD4(actor->position, (f32 *) (life + 0x18));
    func_800EE7F8((f32 *) (life + 0x18), actor->position);
}

s32 chstinger_entrypoint_0(s32 spawn_pos, s32 origin, s32 direction, s32 unk_3, s32 unk_4)
{
    u8 *actor;
    f32 offset[3];
    f32 hit_pos[3];
    u8 *life;
    f32 push[3];

    func_800EFA98(offset, direction, 3e+01f);
    func_800EF04C(spawn_pos, offset);
    if (func_800C6A7C(origin, spawn_pos, hit_pos, 0x20020) != 0) {
        func_800EFB24(push, origin, spawn_pos);
        func_800EF368(push, 0x3F800000);
        func_800EF04C(spawn_pos, push);
    }
    actor = func_80108474(0x16F, spawn_pos, 0);
    life = func_80100094(actor, 0);
    *(f32 *) ((s8 *) actor + 0x34) = 0.0f;
    func_800EE7F8(actor + 0x28, direction);
    func_80800218_chstinger(actor);
    *(f32 *) ((s8 *) life + 0x24) = 0.0f;
    func_800EE7F8(life + 0x18, spawn_pos);
    *(f32 *) ((s8 *) life + 0x14) = 0.0f;
    func_8010A570(actor);
    _sumissilehome_entrypoint_0(actor, life);
    _sumissilehome_entrypoint_3(actor, life, unk_4);
    if (func_800EA068(0x20) != 0) {
        _sumissilehome_entrypoint_4(actor, life, 1);
    } else {
        _sumissilehome_entrypoint_1(actor, life, -1);
    }
    _sumissilehome_entrypoint_5(actor, life, 0x458CA000, 0x44960000);
    func_8080015C_chstinger(actor, 2);
    return *(s32 *) ((s8 *) actor + 0);
}

s32 func_80800774_chstinger(Actor *this, s32 msg, s32 unk_2)
{
    Actor *target;
    if (msg == 0x95) {
        // Matching: extra temporary needed for the match.
        target = this;
        func_80109EEC(target, 16);
    } else {
        return 0;
    }
    return 1;
}

int chstinger_entrypoint_1()
{
    return (int) &D_80800870_chstinger;
}

// TU-NOTE: the data tables below are defined in this file so IDO schedules the functions they point to correctly.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_808007D0_chstinger[11] = {0x1D09E4, 0x22004C, 0x4C0005, 0x50027,  0x0,       0x3200320,
                                0x2B004C, 0x4C000E, 0xF0028,  0x1BFCE0, -0x3200000};
s32 D_808007FC_chstinger[18] = {0x1D09DC, 0x2CFFD8,   0x32FFD8, 0x280064,  0x280015, 0x140066,
                                0x20F0F0, -0xFAFFFDE, 0x800099, 0x14C0199, 0x161000, 0x180000,
                                0x30000,  0x2B,       0xE60100, 0x210000,  0x0,      0x11A0000};
s32 D_80800844_chstinger[11] = {0x1D09E4, 0x150019,  0x4C0016,  0x10000022, 0xCC00CC, 0x70007,
                                0x270000, 0x3200000, 0x320002B, 0x260026,   0x0};
int D_80800870_chstinger[20] = {0x27F016F,
                                0x8370001,
                                0x0,
                                (u32) func_80800420_chstinger,
                                (u32) func_80105834,
                                (u32) func_80101870,
                                0x0,
                                0x0,
                                0x0,
                                0x4,
                                (u32) func_8080025C_chstinger,
                                (u32) func_80108ED0,
                                0x2C0000,
                                0x0,
                                (u32) func_80107C2C,
                                -0x7FFFE000,
                                (u32) func_80800774_chstinger,
                                0x0,
                                0x0,
                                0x0};
