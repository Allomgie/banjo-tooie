#include "common.h"

extern int D_80800500_chdiggergroundgen[];
extern void *func_80100094(Actor *, u32);
typedef union {
    s32 local_0;
    void *local_1;
} DiggerGeneratorEvent;
extern f32 func_8010CD28(Actor *);
extern f32 func_800DC0C0(void);
extern f32 func_800F2094(f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern u8 D_80800548_chdiggergroundgen[];
extern u8 D_80800554_chdiggergroundgen[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8001395C(f32);
extern void func_800EFE50(f32 *, f32 *, void *, f32);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern void func_800B4470(f32 *, s32, void *, s32, f32, f32, s32, s32, s32);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
void func_80800118_chdiggergroundgen();
void func_808002C4_chdiggergroundgen();
int func_8080035C_chdiggergroundgen();

int *chdiggergroundgen_entrypoint_0()
{
    return &D_80800500_chdiggergroundgen;
}

int func_8080000C_chdiggergroundgen(s32 actor)
{
    s32 link = func_80100094(actor, 0);
    _subaddielink_entrypoint_0(link);
}

void func_80800034_chdiggergroundgen(Actor *actor)
{
    void *link;
    link = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            if (!_subaddielink_entrypoint_4(link)) {
                func_80800118_chdiggergroundgen(actor);
            }
            break;
        case 2:
            func_8080035C_chdiggergroundgen(actor);
    }
}

s32 func_808000AC_chdiggergroundgen(Actor *actor, s32 msg, DiggerGeneratorEvent data)
{
    switch (msg) {
        case 0x3D:
            func_808002C4_chdiggergroundgen(actor);
            break;
        case 0x95:
            _subaddielink_entrypoint_3(func_80100094(actor, 0));
            break;
        default:
            return 0;
    }
    return 1;
}

// Picks a landing point 300-500 units away, at least 30 degrees off the player direction, and queues the spawn.
void func_80800118_chdiggergroundgen(actor) Actor *actor;
{
    f32 target[3];
    f32 player_yaw;
    f32 ray_start[3];
    f32 ray_end[3];
    f32 ray_hit[3];
    f32 angle;
    f32 dist;
    u8 *link;
    link = func_80100094(actor, 0);
    player_yaw = func_8010CD28(actor);
    for (;;) {
        angle = func_800DC0C0() * 360.0f;
        if (func_800F2094(angle, player_yaw) < 30.0f)
            continue;
        dist = func_800DC178(300.0f, 500.0f);
        func_800EE7F8(target, actor->position);
        func_800EF1B8(target, angle, dist);
        if (func_800CC338(target, (*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, 0) != -1)
            break;
    }
    func_800EE7F8(ray_start, target);
    func_800EE7F8(ray_end, target);
    ray_start[1] += 200.0f;
    ray_end[1] -= 200.0f;
    func_800BEF00(ray_start, ray_end, ray_hit, actor->unk14);
    target[1] = ray_end[1];
    func_800EE7F8(link + 8, target);
    func_80108B04(actor, 0);
    func_80101FDC(actor, 2);
    actor->unk58 = 0.85f;
}

// Spawns the minion (actor 0x131) at a random scale and links it.
void func_808002C4_chdiggergroundgen(actor) Actor *actor;
{
    u8 *link;
    Actor *minion;
    link = func_80100094(actor, 0);
    minion = func_801084B0(0x131, &actor);
    func_80102FDC(minion, func_800DC178(0.8f, 1.2f));
    minion->rotation[1] = func_800F1DF4(actor->position, (f32 *) (link + 8));
    _subaddielink_entrypoint_1(link, minion->unk0);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800548_chdiggergroundgen);
}

// Throws the minion in an arc to the landing point; on landing emits dust and a sound and releases it.
int func_8080035C_chdiggergroundgen(actor)
Actor *actor;
{
    u8 *link;
    Actor *minion;
    s32 landed;
    f32 t;
    f32 *minion_pos;
    link = func_80100094(actor, 0);
    minion = (Actor *) _subaddielink_entrypoint_4(link);
    landed = func_800D9078((u8 *) actor + 0x58);
    t = func_800F10B4(*(f32 *) ((u8 *) actor + 0x58), 0.0f, 0.85f, 1.0f, 0.0f);
    minion_pos = minion->position;
    func_800EFE50(minion_pos, actor->position, link + 8, t);
    minion->position[1] += func_8001395C(t * 3.141592741f) * 250.0f;
    func_8008FB10(minion_pos, 90.0f, actor->position[1] - minion->position[1],
                  minion->scale * 100.0f);
    if (landed) {
        func_800B4470(minion_pos, 0, D_80800554_chdiggergroundgen, 1, 0.8f, 0.0f, 100, 150, 0);
        func_800C4104(0x419, 1.0f, 28000, minion_pos, 1250.0f, 2500.0f);
        minion->unk64_20 = 1;
        func_80101FDC(actor, 1);
    }
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_80800500_chdiggergroundgen[18] = {0x1A30132,
                                        0x1,
                                        0x0,
                                        (u32) func_80800034_chdiggergroundgen,
                                        (u32) func_80105834,
                                        (u32) func_8010A730,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x1,
                                        0x0,
                                        0x0,
                                        0x140000,
                                        (u32) func_8080000C_chdiggergroundgen,
                                        (u32) func_80107C2C,
                                        -0x7FFFFFFE,
                                        (u32) func_808000AC_chdiggergroundgen,
                                        0x0};
u8 D_80800548_chdiggergroundgen[12] = {0x0, 0x13, 0x4, 0xBE, 0x0, 0xD,
                                       0x0, 0xF3, 0x1, 0xC,  0x0, 0x0};
u8 D_80800554_chdiggergroundgen[12] = {0x6E, 0x64, 0x50, 0xE0, 0x0, 0x0,
                                       0x0,  0x0,  0x0,  0x0,  0x0, 0x0};
