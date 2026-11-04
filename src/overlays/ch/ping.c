// Sonar ping of the submarine in Jolly Roger's Lagoon: follows the sub for 4.2 s, draws expanding
// rings, pans the sound, and sends a growing hit sphere to nearby actors.
#include "common.h"

extern void *D_80800410_chping;
extern void *func_80100094(Actor *, s32);
extern s32 func_801039E4(void *);
extern void func_800E3A58(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F0F9C(f32, f32);
extern f32 func_80013970(f32);
extern void func_800DF410(s32);
extern void func_800DF830(s32);
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern f32 func_800D8FF8(void);
extern void func_800C4B90(s32, f32, f32);
extern void func_80109CC4(f32 *, f32, void *);

// Draw three staggered expanding rings.
void func_80800000_chping(Actor *this, s32 arg1)
{
    f32 *data;
    s32 sp;
    s32 i;
    f32 t;
    f32 pos[3];
    f32 a;
    f32 b;

    data = func_80100094(this, 0);
    sp = func_801039E4(*(void **) this);
    func_800E3A58(pos);
    for (i = 0; i < 3; i++) {
        t = data[1];
        t -= i * 0.4f;
        if (t < 0.0f)
            continue;
        if (3.0f < t)
            continue;
        a = func_800F10B4(t, 0.0f, 3.0f, 0.5f, 30.0f);
        b = func_800F10B4(data[1], 0.0f, 3.0f, 40.0f, 0.0f);
        t = func_80013970(func_800F0F9C(data[1], 0.5) * 360.0f);
        func_800DF410(10.0f + b + b * t);
        func_800DF830(2);
        func_800DE448(this->position, pos, a, 0, sp);
    }
}

// Per-frame update: follow the sub, pan the sound, send the growing hit sphere, despawn at 4.2 s.
void func_808001B8_chping(Actor *actor)
{
    f32 phase;
    f32 pan_left;
    f32 pan_right;
    f32 pan_scale;
    f32 radius;
    f32 age;
    f32 pos[3];
    s32 player;
    u8 *data;

    data = func_80100094(actor, 0);
    player = *(s32 *) data;
    func_800F5A00(player, pos);
    pos[1] += 60.0f;
    func_800EE7F8(actor->position, pos);
    age = *(f32 *) (data + 4);
    phase = func_800F0F9C(age, 0.5f);
    pan_left = func_80013970(phase * 360.0f);
    pan_right = func_80013970(phase * 360.0f + 180.0f);
    pan_scale = func_800F10B4(age, 0.0f, 3.0f, 3.0f, 0.01f);
    func_800C4B90(func_800A940C(player), pan_left * pan_scale, pan_right * pan_scale);
    if (age < 3.0f) {
        radius = func_800F10B4(age, 0.0f, 3.0f, 14.0f, 840.0f);
        func_8010A590(actor);
        func_800CB840(5, actor);
        func_80109CC4(actor->position, radius, actor->unk0);
        func_800CB870();
        func_8010A570(actor);
    }
    *(f32 *) (data + 4) += func_800D8FF8();
    if (*(f32 *) (data + 4) > 4.2f)
        func_800FFA88(actor->unk0);
}

// Spawn the ping actor (0x169) at the player.
int chping_entrypoint_0(s32 player)
{
    s32 *actor_out;
    s32 pos[3];
    s32 *actor;
    u8 *data;

    func_800F5A00(player, &pos);
    actor = func_80108474(0x169, &pos, 0);
    actor_out = actor;
    data = func_80100094(actor, 0);
    *(f32 *) ((char *) data + 4) = 0.0f;
    *(s32 *) ((char *) data + 0) = player;
    func_8010A570(actor_out);
    return *actor_out;
}

int chping_entrypoint_1()
{
    return (int) &D_80800410_chping;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions of this file; IDO schedules some of them differently unless the tables are in the same unit. Values are taken from the ROM.
void *D_80800410_chping = (void *) 0x027B0169;
static u32 D_80800410_chping_rest[19] = {0x6DF0001,
                                         0x0,
                                         (u32) func_808001B8_chping,
                                         (u32) func_80105834,
                                         (u32) func_80800000_chping,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x4,
                                         0x0,
                                         (u32) func_80108ED0,
                                         0x80000,
                                         0x0,
                                         (u32) func_80107C2C,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x0};
