// Feather-use effect: when the player spends a red or gold feather, spawns a small falling,
// fading feather with sparkles beside the player (not in multiplayer).
#include "common.h"

extern f32 func_800DC0C0(void);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BABA0(s32, f32);
extern s32 D_80800340_chusefeather[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void *_chusefeather_entrypoint_0;
extern void _chbaddiesetup_entrypoint_2(void *, s32, s32);
extern s32 func_800D3948(void);
extern int D_80800364_chusefeather[];
extern s32 D_808003AC_chusefeather[];
extern f32 func_800F5F24(s32);
extern Actor *func_80108474(u32, f32 *, s32);
extern void func_80102FDC(Actor *, f32);

// Per-frame update of the feather actor: fall, emit sparkles, fade out and despawn.
void func_80800000_chusefeather(Actor *actor)
{
    s32 i;
    s32 emitter;
    f32 spark_pos[3];
    s32 alpha;

    func_800EF1B8(actor->position, actor->rotation[1], ((f32 *) actor->actorData)[3]);
    if (((f32 *) actor->actorData)[1] > -100.0f)
        ((f32 *) actor->actorData)[1] -= 3.5f;
    if (actor->position[1] > -16000.0f)
        actor->position[1] += ((f32 *) actor->actorData)[1];
    if (actor->unk58 > 0.5f) {
        for (i = 0; i < 3; i++) {
            spark_pos[i] = actor->position[i] + func_800DC0C0() * 2.0f * 25.0f -
                           (i == 1 ? 0 : 25);
        }
        emitter = func_800BABB8(0, spark_pos, NULL, 1.0f, D_80800340_chusefeather);
        func_800BA3FC(emitter, actor->unk6C_9 == 0x26A ? 0x9E4 : 0x9E2);
        func_800BA75C(emitter, spark_pos);
        func_800BABA0(emitter, 0.25f);
    }
    actor->unk58 -= func_800D8FF8();
    if (actor->unk58 < 0)
        func_800FFAB0(actor);
    else {
        alpha = func_800F10B4(actor->unk58, 0.0f, 0.3f, 0.0f, 255.0f);
        _subaddiefade_entrypoint_1(actor, alpha);
        if (alpha == 0)
            func_800FFAB0(actor);
    }
}

// Spawns a feather actor (actor_id) beside the player.
void chusefeather_entrypoint_0(s32 player, s32 actor_id)
{
    Actor *actor;
    f32 pos[3];
    s32 side_offset;
    f32 yaw;

    func_800F5A00(player, pos);
    yaw = func_800F5F24(player);
    side_offset = func_800DC0C0() > 0.5f ? 30 : -30;
    actor = func_80108474(actor_id, pos, (s32) ((f32) side_offset + yaw));
    func_80102FDC(actor, 0.45f);
    *(f32 *) &actor->actorData[3] = 22.0f;
    *(f32 *) &actor->actorData[1] = 48.0f;
    actor->unk58 = 1.2f;
}

// kind 0 = red feather (0x26A), otherwise gold (0x26B); not spawned in multiplayer.
void chusefeather_entrypoint_1(s32 player, s32 kind)
{
    s32 actor_id;

    if (func_800D3948() == 0) {
        if (kind == 0) {
            actor_id = 0x26A;
        } else {
            actor_id = 0x26B;
        }
        _chbaddiesetup_entrypoint_2(&_chusefeather_entrypoint_0, player, actor_id);
    }
}

int *chusefeather_entrypoint_2()
{
    return &D_80800364_chusefeather;
}

int chusefeather_entrypoint_3()
{
    return D_808003AC_chusefeather;
}

// TU-NOTE: the overlay .data is defined here in C; values are taken from the ROM.
extern void func_80105834();
extern void _subaddiedraw25d_entrypoint_2();
extern void func_80107C2C();
s32 D_80800340_chusefeather[9] = {0x1100022, 0x3D0033, 0x20002,  0x2A0000, 0x40,
                                  0x400015,  0x4C,     0x161000, 0x0};
int D_80800364_chusefeather[18] = {0x158026A,
                                   0x9BE0001,
                                   0x0,
                                   (u32) func_80800000_chusefeather,
                                   (u32) func_80105834,
                                   (u32) _subaddiedraw25d_entrypoint_2,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x4,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0};
s32 D_808003AC_chusefeather[21] = {0x158026B,
                                   0x9BF0001,
                                   0x0,
                                   (u32) func_80800000_chusefeather,
                                   (u32) func_80105834,
                                   (u32) _subaddiedraw25d_entrypoint_2,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x4,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_80107C2C,
                                   -0x7FFFFFFE,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0};
