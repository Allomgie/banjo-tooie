#include "common.h"

extern int D_80800708_chboxingglove[];
extern void *D_80800750_chboxingglove;
extern void *_subaddiefind_entrypoint_2(int, s32 *);
extern u8 D_80800798_chboxingglove[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800DC178(f32, f32);
extern void func_8010D09C(void *, f32 *, f32);
extern u8 D_808007A0_chboxingglove[];
typedef struct {
    f32 center[3];
    f32 radius;
} BoxingSphere1559;
extern void *func_80100094(Actor *, u32);
extern int func_800F0064(f32 *, f32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern int func_800BEF00(f32 *, f32 *, f32 *, u32);
typedef struct {
    f32 position[3];
    f32 radius;
} BoxingTarget;
// State change: picks a spot near the player and syncs the partner actor.
void func_808002E0_chboxingglove();
int func_808004F8_chboxingglove();
int func_80800544_chboxingglove();
// Records position and radius of nearby 0x34D actors to avoid.
void func_80800630_chboxingglove();

int chboxingglove_entrypoint_0(void)
{
    return (int) &D_80800708_chboxingglove;
}

int chboxingglove_entrypoint_1()
{
    return &D_80800750_chboxingglove;
}

void func_80800018_chboxingglove(Actor *glove)
{
    f32 player_pos[3];

    switch (glove->unk70_10) {
        case 1:
            if (!func_808004F8_chboxingglove(glove)) {
                if ((func_8008FF18() || !func_8010D248()) && glove->unk64_20)
                    return;
                if (func_800D90A4(&glove->unk58)) {
                    func_8010D254(player_pos);
                    if (player_pos[1] < *(f32 *) ((u8 *) glove + 0x28) + 500.0f ||
                        !glove->unk64_20) {
                        func_808002E0_chboxingglove(glove, 2);
                    }
                }
            }
            break;
        case 2:
            if (func_800D90A4(&glove->unk58))
                func_808002E0_chboxingglove(glove, 3);
            break;
        case 3:
            if (func_80101DDC(glove))
                func_808002E0_chboxingglove(glove, 4);
            break;
        case 4:
            if (func_800D90A4(&glove->unk58))
                func_808002E0_chboxingglove(glove, 1);
    }
}

void func_80800168_chboxingglove(void *glove)
{
    void *partner;
    s32 count;
    *(f32 *) ((u8 *) glove + 88) = 1.0f;
    *(f32 *) ((u8 *) glove + 0x28) = *(f32 *) ((u8 *) glove + 0x8);
    *((u8 *) glove + 101) &= ~1;
    partner = _subaddiefind_entrypoint_2(0x36E, &count);
    *(u32 *) ((u8 *) glove + 0x3C) = *(u32 *) ((u8 *) partner + 0);
    *(u32 *) ((u8 *) partner + 60) = *(u32 *) ((u8 *) glove + 0);
    func_80800630_chboxingglove(glove);
}

void func_808001CC_chboxingglove(Actor *actor)
{
    s32 moving;

    moving = 0;
    switch (actor->unk70_10) {
        case 2:
            func_800D90A4(&actor->unk58);
            actor->position[1] = ((f32 *) actor->actorData)[4] -
                                   func_800F10B4(actor->unk58, 0.0f, 1.5f, 0.0f, 70.0f);
            moving = 1;
            break;
        case 4:
            func_800D90A4(&actor->unk58);
            actor->position[1] = ((f32 *) actor->actorData)[4] -
                                   func_800F10B4(actor->unk58, 0.0f, 1.5f, 70.0f, 0.0f);
            moving = 1;
    }
    if (moving || (!moving && ((u8 *) actor)[0x5F])) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, moving,
                                        D_80800798_chboxingglove);
    }
}

int func_808002AC_chboxingglove(f32 actor[3])
{
    f32 new_y;
    int flags_offset;
    int mask;
    u8 *flags;
    f32 old_y;
    old_y = actor[2];
    flags_offset = 101;
    flags = &*(u8 *) ((char *) actor + flags_offset);
    new_y = old_y - 70.0f;
    actor[2] = new_y;
    mask = ~1;
    *flags &= mask;
    actor[10] = old_y;
    actor[22] = 1.0f;
}

// State change: picks a spot near the player and syncs the partner actor.
void func_808002E0_chboxingglove(glove, state) Actor *glove;
s32 state;
{
    Actor *partner;
    f32 target_pos[3];
    f32 player_pos[3];

    partner = func_80106790(glove->unk3C);
    switch (state) {
        case 1:
            glove->unk58 = func_800DC178(2.0f, 3.0f);
            func_80102424(glove, 1);
            func_80101FDC(partner, state);
            partner->unk64_16 = 0;
            return;
        case 2:
            if (glove->unk64_20) {
                func_8010D09C(func_800F54E4(), target_pos, 1.5f);
                if (!func_80800544_chboxingglove(glove, target_pos)) {
                    func_8010D254(target_pos);
                    if (!func_80800544_chboxingglove(glove, target_pos)) {
                        return;
                    }
                }
                glove->position[0] = partner->position[0] = target_pos[0];
                glove->position[2] = partner->position[2] = target_pos[2];
            } else {
                glove->unk64_20 = 1;
            }
            glove->unk58 = 1.5f;
            partner->unk58 = 1.5f;
            func_80102424(glove, state);
            func_80101FDC(partner, state);
            partner->unk64_16 = 1;
            return;
        case 3:
            _subaddieaudioquick_entrypoint_2(glove, glove->position, D_808007A0_chboxingglove);
            func_80102424(glove, state);
            func_80101FDC(partner, state);
            func_8010A590(glove);
            glove->unk64_16 = 1;
            func_8010D254(player_pos);
            func_800F1E6C(player_pos, glove->position, &glove->rotation[1]);
            return;
        case 4:
            partner->unk58 = glove->unk58 = 1.5f;
            func_80102424(glove, state);
            func_80101FDC(partner, state);
            func_8010A570(glove);
            glove->unk64_16 = 0;
            func_808004F8_chboxingglove(glove);
    }
}

int func_808004F8_chboxingglove(glove)
Actor *glove;
{
    s32 despawn;
    if (func_800DA298(0)) {
        func_800FFAB0(glove);
        func_800FFA88(glove->unk3C);
        return 1;
    }
    despawn = 0;
    return despawn;
}

int func_80800544_chboxingglove(glove, pos)
Actor *glove;
f32 *pos;
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 hit_pos[3];
    s32 offset;
    BoxingSphere1559 *sphere;
    f32 *start_ptr;
    f32 *end_ptr;
    f32 *hit_ptr;
    void *spheres;

    spheres = func_80100094(glove, 0);
    offset = 0;
    sphere = spheres;
    for (; offset != 64; offset += 16, sphere++) {
        if (func_800F0064(pos, sphere->radius, sphere->center))
            return 0;
    }
    start_ptr = ray_start;
    func_800EE7F8(start_ptr, pos);
    end_ptr = ray_end;
    func_800EE7F8(end_ptr, pos);
    start_ptr[1] = ((f32 *) glove->actorData)[4] + 200.0f;
    end_ptr[1] = ((f32 *) glove->actorData)[4] - 50.0f;
    hit_ptr = hit_pos;
    return func_800BEF00(start_ptr, end_ptr, hit_ptr, glove->unk14) ? 1 : 0;
}

// Records position and radius of nearby 0x34D actors to avoid.
void func_80800630_chboxingglove(glove) Actor *glove;
{
    Actor *nearby[4];
    s32 count;
    s32 i;
    BoxingTarget *targets;
    targets = func_80100094(glove, 0);
    count = _subaddiefind_entrypoint_4(0x34D, nearby, 4);
    for (i = 0; i < count; i++) {
        func_800EE7F8(targets[i].position, nearby[i]->position);
        targets[i].radius = nearby[i]->scale * 150.0f;
    }
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_808006E0_chboxingglove[10] = {0x0,       0x0,        0x3FC00000, 0x20B0044,  0x3FC00000,
                                    0x20B0044, 0x3FC00000, 0x20B0002,  0x3FC00000, 0x20B0044};
int D_80800708_chboxingglove[18] = {0x1B4013E,
                                    0x7760001,
                                    (u32) &D_808006E0_chboxingglove,
                                    (u32) func_80800018_chboxingglove,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x3010024,
                                    0x0,
                                    0x0,
                                    0x400000,
                                    (u32) func_80800168_chboxingglove,
                                    (u32) func_80107C2C,
                                    -0x7FFFFFFE,
                                    0x0,
                                    0x0};
void *D_80800750_chboxingglove = (void *) 0x01AD036E;
static u32 D_80800750_chboxingglove_rest[17] = {0x6290001,
                                                0x0,
                                                (u32) func_808001CC_chboxingglove,
                                                (u32) func_80105834,
                                                (u32) func_80101870,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x804,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) func_808002AC_chboxingglove,
                                                (u32) func_80107C2C,
                                                0x80000002,
                                                0x0,
                                                0x0};
u8 D_80800798_chboxingglove[8] = {0x0, 0x13, 0x4, 0xD2, 0x0, 0x0, 0x0, 0x0};
u8 D_808007A0_chboxingglove[16] = {0x0, 0x13, 0x5, 0x8, 0x0, 0x18, 0x0, 0x0,
                                   0x0, 0x0,  0x0, 0x0, 0x0, 0x0,  0x0, 0x0};
