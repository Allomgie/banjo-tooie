#include "common.h"

extern int D_80800B88_chcablespark[];
extern f32 func_800DC178(f32, f32);
typedef union {
    s32 word;
    f32 value;
} CableEvent30;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_801015D0(void *);
extern s32 func_800DE448(f32 *, f32 *, f32, s32, void *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern f32 func_800136E4(f32);
extern void func_800E3980(f32 *);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern s32 func_800BEF00(void *, void *, void *, s32);
extern void func_800EE7F8(void *, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_80103014(void *);
extern s32 func_800F54E4(void);
extern f32 func_800F57F0(s32, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
typedef struct {
    f32 local_0;
    f32 local_1;
} CableSparkRange26;
extern CableSparkRange26 D_80800BDC_chcablespark;
extern u32 D_80800B70_chcablespark[3];
typedef struct {
    u8 local_0[0x64];
    u32 local_1 : 2;
    u32 local_2 : 1;
    u32 local_3 : 29;
} CableFlags49;
extern u8 D_80800BD0_chcablespark[];
extern int func_800DC298(f32);
extern void func_8010D254(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
void func_80800590_chcablespark();
int func_80800828_chcablespark();
void func_808008BC_chcablespark();
void func_80800A48_chcablespark();
s32 func_808007B8_chcablespark();

int chcablespark_entrypoint_0()
{
    return (int) D_80800B88_chcablespark;
}

s32 func_80800970_chcablespark();

void func_80800668_chcablespark();

void func_8080000C_chcablespark(Actor *actor)
{
    s32 timer_done;
    s32 out_of_range;
    s32 shocked;
    actor->unk64_24 = 0;
    if (func_80800828_chcablespark()) {
        actor->unk64_24 = 1;
        _subaddieaudioloop_entrypoint_4(actor, actor->position, actor->unk70_10 == 3,
                                        D_80800BD0_chcablespark);
        timer_done = func_800D90A4(&actor->unk58);
        switch (actor->unk70_10) {
            case 1:
                if (((CableFlags49 *) actor)->local_2) {
                    if (timer_done && _subaddiejoy_entrypoint_6(actor, 1) == 1) {
                        func_80101FDC(actor, 2);
                        actor->unk58 = 0.25f;
                    }
                } else if (timer_done && !func_808007B8_chcablespark(actor)) {
                    func_80101FDC(actor, 3);
                    actor->unk58 = func_800DC178(0.8f, 1.2f);
                    func_80800668_chcablespark(actor);
                    func_800C8FE0(actor->actorData[6], 1);
                }
                break;
            case 2:
                if (timer_done) {
                    func_80101FDC(actor, 3);
                    actor->unk58 = 1.0f;
                    func_80800668_chcablespark(actor);
                    func_800C8FE0(actor->actorData[6], 1);
                }
                break;
            case 3:
                if (((CableFlags49 *) actor)->local_2)
                    out_of_range = 0;
                else
                    out_of_range = func_808007B8_chcablespark(actor);
                shocked = func_80800970_chcablespark(actor);
                func_800C8E84(actor->actorData[6],
                              ((u32(*)[3]) D_80800B70_chcablespark)[func_800DC298(0.35f)]);
                if (timer_done || out_of_range || shocked) {
                    func_80101FDC(actor, 1);
                    if (((CableFlags49 *) actor)->local_2)
                        actor->unk58 = func_800DC178(1.2f, 1.4f);
                    else
                        actor->unk58 = 2.0f;
                    func_800C8FE0(actor->actorData[6], 0);
                }
        }
    }
}

void func_8080024C_chcablespark(Actor *actor)
{
    *(u8 *) actor->actorData = 0;
    actor->unk58 = func_800DC178(0.0f, 2.0f);
    if (actor->unk74_7 == 0x35 && func_80800828_chcablespark(actor)) {
        _subaddieDll_entrypoint_4(actor, 1);
    }
    func_808008BC_chcablespark(actor);
}

void func_808002BC_chcablespark(u8 *actor)
{
    // Matching: the redundant mask chain is needed for the match.
    int mask;
    int probe_id;
    mask = 0xFFFFFFFF;
    if (actor[24] != 0) {
        probe_id = (((actor[24] & mask) & mask) & mask) & 0xFFFFFFFF;
        func_800E87E0(((((probe_id & mask) & 0xFF) & 0xFF) & 0xFF) & 0xFF);
    }
}

s32 func_808002E8_chcablespark(Actor *actor, s32 msg, CableEvent30 event)
{
    f32 offset[3];
    f32 inv_scale;
    switch (msg) {
        case 0xA:
            actor->unk64_24 = func_80800828_chcablespark(actor);
            if (actor->unk74_7 == 0x35) {
                actor->unk64_24 = 0;
                if (func_80800828_chcablespark(actor))
                    _subaddieDll_entrypoint_4(actor, 1);
            }
            break;
        case 0x95:
            func_80800A48_chcablespark(actor);
            break;
        case 0x97:
            inv_scale = 1.0f / actor->scale;
            func_800EEB9C(offset, actor->rotation[1], 150.0f * inv_scale);
            offset[1] += 175.0f * inv_scale;
            func_80101010(offset);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080040C_chcablespark(Actor *actor, s32 unk_1)
{
    f32 aim_rot[3];
    actor->unk64_20 = (s32) actor->unk64_20 ^ 1;
    func_800DF830(1);
    func_800DF744(4, func_80800828_chcablespark(actor) ? 1 : 2);
    func_800DE448(actor->position, actor->rotation, actor->scale, 0,
                  (void *) func_800D674C(0x6BC));
    actor->unk7C_12 = func_800DF350();
    if (actor->unk70_10 == 3) {
        func_80800590_chcablespark(actor, aim_rot);
        func_800DF744(1, func_800DC128(0, 4));
        func_800DF47C(func_801015D0, actor);
        func_800DE448(actor->position, aim_rot, actor->scale, 0,
                      (void *) func_8010347C(actor->unk0));
        if (func_800E88E4(((u8 *) actor)[0x18]) == 1 && actor->unk64_20 && actor->unk7C_12) {
            func_800E3A58(aim_rot);
            func_800DF830(0);
            func_800DE448(actor->position, aim_rot, actor->scale, 0,
                          (void *) func_800D674C(0x6BB));
        }
    }
}

// Computes the rotation that aims the spark.
void func_80800590_chcablespark(actor, out_rot) Actor *actor;
f32 *out_rot;
{
    f32 unk_0[3];
    f32 unk_1[3];
    f32 unk_2[3];
    f32 unk_3[3];
    f32 yaw;

    yaw = 0.0f;
    func_800E3980(unk_0);
    func_800EFB24(unk_1, actor->position, unk_0);
    func_800EEC30(unk_2, ((f32 *) actor->actorData)[5], ((f32 *) actor->actorData)[4],
                  100.0f);
    if (actor->position[1] < unk_0[1])
        func_800EE97C(unk_3, unk_2, unk_1);
    else
        func_800EE97C(unk_3, unk_1, unk_2);
    func_800F1884(unk_3, &yaw);
    out_rot[0] = ((f32 *) actor->actorData)[5];
    out_rot[1] = ((f32 *) actor->actorData)[4];
    out_rot[2] = func_800136E4(yaw - 90.0f);
}

void func_80800668_chcablespark(Actor *actor)
{
    f32 unk_0[3];
    f32 unk_1[2];
    f32 unk_2;
    f32 unk_3;

    func_800E3980(unk_0);
    func_800F18FC((*(Actor **) &actor)->position, unk_0, unk_1);
    unk_1[1] = func_800F1DCC((*(Actor **) &actor)->rotation[1], unk_1[1]);
    unk_1[0] = -unk_1[0];
    unk_3 = (mlAbsF(unk_1[1]) > 45.0f) ? 0.0f : ((unk_1[1] > 0.0f) ? 15.0f : -15.0f);
    unk_2 = (mlAbsF(unk_1[0]) > 45.0f) ? 0 : ((unk_1[0] < 0.0f) ? 15.0f : -15.0f);
    *(f32 *) &*(Actor **) &actor->actorData[4] =
        func_800136E4((*(Actor **) &actor)->rotation[1] + unk_3);
    *(f32 *) &*(Actor **) &actor->actorData[5] = func_800136E4(unk_2);
}

// Returns 1 when the player is more than 1000 units away.
s32 func_808007B8_chcablespark(actor)
Actor *actor;
{
    f32 player_pos[3];
    if (actor->unk74_7 == 0x35)
        return 0;
    func_8010D254(player_pos);
    return func_800EEB40(actor->position, player_pos) > 1000000.0f;
}

// Returns 1 when the spark zone is powered.
int func_80800828_chcablespark(actor)
Actor *actor;
{
    s32 zone;
    zone = (u32) *(u16 *) ((char *) actor + 0x76) >> 7;
    zone -= 0x32;
    switch (zone) {
        case 1:
            if (!func_800DA298(0xEB)) {
                return 0;
            }
            break;
        case 2:
            if (!func_800DA298(0xEC)) {
                return 0;
            }
            break;
        case 3:
            if (!func_800DA298(0x18C)) {
                return 0;
            }
    }
    return 1;
}

// Snaps the spark onto the surface found by the probe ray.
void func_808008BC_chcablespark(actor) u8 *actor;
{
    f32 ray_start[3];
    f32 ray_end[3];
    f32 hit_pos[3];

    func_800EE7F8(ray_start, actor + 4);
    func_800EF1B8(ray_start, *(f32 *) (actor + 0x48), 100.0f);
    func_800EE7F8(ray_end, actor + 4);
    func_800EF1B8(ray_end, *(f32 *) (actor + 0x48), -50.0f);

if (func_800BEF00(ray_start, ray_end, hit_pos, *(s32 *) (actor + 0x14)) != 0) {
    func_800EE7F8(actor + 4, ray_end);
    func_800EF1B8(actor + 4, *(f32 *) (actor + 0x48), *(f32 *) (actor + 0x38) * 5.0f);
    func_80103014(actor);
}

}

// Shocks the player on contact; returns 1 when hit.
s32 func_80800970_chcablespark(Actor *actor)
{
    f32 spark_pos[3];
    f32 radius;
    f32 player_pos[3];
    f32 player_radius;
    s32 player;

    player = func_800F54E4();
    if (!func_800F6478(player))
        return 0;
    player_radius = func_800F57F0(player, player_pos);
    func_800EE7F8(spark_pos, actor->position);
    func_800EF1B8(spark_pos, actor->rotation[1], actor->scale * 40.0f);
    radius = actor->scale * 50.0f;

if (func_800F0008(spark_pos, radius, player_pos, player_radius) && func_800F7B9C(player, 0x51) == 2) {
    _chelectricfence_entrypoint_1(actor, player_pos);
    return 1;
}

return 0;
}

void func_80800A48_chcablespark(actor) Actor *actor;
{
    CableSparkRange26 range = D_80800BDC_chcablespark;

    range.local_0 *= actor->scale;
    range.local_1 *= actor->scale;
    actor->actorData[6] = func_800C8A98();
    func_800C8E84(actor->actorData[6], D_80800B70_chcablespark);
    func_800C8CB8(actor->actorData[6], actor->position);
    func_800C8F64(actor->actorData[6], 11);
    func_800C8D4C(actor->actorData[6], &range.local_0);
    func_800C8FE0(actor->actorData[6], actor->unk70_10 == 3);
    *(u8 *) &actor->actorData[0] = func_800E8714(1);
    func_800E8830(*(u8 *) &actor->actorData[0], actor->position);
    actor->unk64_24 = func_80800828_chcablespark(actor);

if (actor->unk74_7 == 0x35) {
    actor->unk64_24 = 0;
}

}

extern void func_80105834();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
u32 D_80800B70_chcablespark[3] = {0xC0, 0xC0, 0xFF};
static u32 D_80800B70_chcablespark_rest[3] = {0x80, 0x80, 0xA0};
int D_80800B88_chcablespark[18] = {0x2A4033D,
                                   0x6B90001,
                                   0x0,
                                   (u32) func_8080000C_chcablespark,
                                   (u32) func_80105834,
                                   (u32) func_8080040C_chcablespark,
                                   0x7080000,
                                   0x0,
                                   0x0,
                                   0x0,
                                   (u32) func_808002BC_chcablespark,
                                   0x0,
                                   0x0,
                                   (u32) func_8080024C_chcablespark,
                                   (u32) func_80107C2C,
                                   (u32) ((u8 *) boot_thread_stack + 0x1F23),
                                   (u32) func_808002E8_chcablespark,
                                   0x0};
u8 D_80800BD0_chcablespark[12] = {0x0, 0x13, 0x5, 0xC, 0x0, 0xD, 0x1, 0xC, 0x1, 0x19, 0x0, 0x0};
CableSparkRange26 D_80800BDC_chcablespark = {2.5e+02f, 4e+02f};
