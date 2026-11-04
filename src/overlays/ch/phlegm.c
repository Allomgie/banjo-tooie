// Probably Terry's phlegm attack: a controller warns the player, then drops a phlegm ball
// (actor 0x398) every 3-4 s. It splats into goo and spawns a blob (0x399) that chases the player.
#include "common.h"

extern int D_80800B58_chphlegm[];
extern int D_80800BA0_chphlegm[];
extern s32 func_800DC298(f32);
typedef struct {
    u8 pad0[0x24];
    u32 unk24_22 : 10;
    u32 unk24_0 : 22;
} PhlegmData;
typedef struct {
    u8 pad0[0x64];
    u32 unk64_21 : 11;
    u32 unk64_20 : 1;
    u32 unk64_0 : 20;
} PhlegmBits;
extern s32 func_801084B0(s32, Actor **);
extern void func_8010A570(Actor *);
extern void func_800FFAB0(Actor *);
extern void func_80103140(Actor *, u16, s32);
typedef struct {
    u8 local_0[0x64];
    u32 local_1 : 1;
    u32 local_2 : 1;
    u32 local_3 : 1;
    u32 local_4 : 29;
} PhlegmFlags49;
extern f32 D_80800C30_chphlegm[];
extern f32 _subaddiejoy_entrypoint_9(Actor *, f32 *, s32);
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, f32 *, s32);
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
typedef union {
    s32 word;
    Actor **actors;
} PhlegmEvent30;
extern u8 D_80800C50_chphlegm[];
extern void _chbaddiesetup_entrypoint_10();
extern void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
extern Actor *func_80106790();
extern void _subaddiefade_entrypoint_3();
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800B53A4(s32);
extern s32 D_80800C5C_chphlegm[];
extern u8 D_80800C88_chphlegm[];
extern u8 D_80800C98_chphlegm[];
extern void func_8010D254();
extern f32 func_800DC178(f32, f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
typedef union {
    s32 local_0;
    void *local_1;
} PhlegmEvent9DC;
extern f32 func_800136E4(f32);
extern f32 func_800EEF94(f32 *);
extern u8 D_80800CD8_chphlegm[];
extern u8 D_80800CC4_chphlegm[];
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern void func_800EF368(f32 *, f32);
void func_80800748_chphlegm(Actor *actor, f32 y_offset, s32 particle_id);
void func_80800A58_chphlegm();

// Phlegm ball and goo blob (max 4 active, burst when hit), with shared splat/trail particles.
int chphlegm_entrypoint_0()
{
    return (int) &D_80800B58_chphlegm;
}

int chphlegm_entrypoint_1()
{
    return (int) &D_80800BA0_chphlegm;
}

// Spitter controller: warning dialogs, 3-4 s spit timer, spawns a ball aimed at the player.
void *chphlegm_entrypoint_2(void)
{
    extern void *D_80800BE8_chphlegm;
    return &D_80800BE8_chphlegm;
}

void func_80800024_chphlegm(Actor *actor)
{
    if (func_800DC298(0.5f))
        actor->unk50 = 600.0f;
    else
        actor->unk50 = -600.0f;
    if (func_800DC298(0.5f))
        actor->unk54 = 50.0f;
    else
        actor->unk54 = -50.0f;
    if (actor->unk64_20)
        func_8010A570(actor);
}

void func_808000C4_chphlegm(Actor *actor)
{
    s32 hit_flags;
    f32 frame_time;
    s32 particle_id;
    switch (actor->unk70_10) {
        case 1:
            hit_flags = func_8010B990(actor, 0x404007);
            frame_time = func_800D8FF8();
            particle_id = actor->unk64_20 ? 0x95C : 0x95D;
            func_808007EC_chphlegm(actor, particle_id);
            actor->rotation[0] = func_800136E4(actor->rotation[0] + frame_time * actor->unk50);
            actor->rotation[1] = func_800136E4(actor->rotation[1] + frame_time * actor->unk54);
            if (hit_flags & 0x28) {
                func_80800748_chphlegm(actor, -20.0f, particle_id);
                func_8010A570(actor);
                func_80101FDC(actor, 2);
                _subaddiefade_entrypoint_3(actor);
                if (actor->unk64_20) {
                    func_80108B04(actor, 0);
                }
            }
            if (!actor->unk64_19 &&
                (actor->position[1] < -2000.0f || func_800EEF94(actor->position) > 20000.0f)) {
                func_800FFAB0(actor);
            }
            break;
        case 2:
            actor->position[1] -= (actor->scale * func_800D8FF8()) * 25.0f;
    }
}

s32 func_8080026C_chphlegm(Actor *actor, s32 msg, s32 msg_data)
{
    s32 pad;
    PhlegmData *hit_info;

    switch (msg) {
        case 0x3D:
            func_80102FDC(func_801084B0(0x399, &actor), *(f32 *) ((u8 *) actor + 0x38));
            return 1;
        case 0x40:
            hit_info = *(PhlegmData **) &msg_data;
            func_8010A570(actor);
            func_80800748_chphlegm(actor, 0.0f, 0x95D);
            if (hit_info->unk24_22 != 0) {
                func_800FFAB0(actor);
            }
            break;
        case 0x95:
            func_80103140(actor, (PhlegmBits *) actor->unk64_20 ? 0x6DC : 0x876, 0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_80800354_chphlegm(u8 *actor)
{
    *(f32 *) (actor + 0x48) = *(f32 *) (actor + 0x54) = func_8010CD28(actor);
    *(f32 *) (actor + 0x24) = *(f32 *) (actor + 0x38) * 150.0f;
    *(f32 *) (actor + 0x58) = func_800DC178(0.8f, 1.0f);
}

void func_808003B4_chphlegm(Actor *actor)
{
    f32 probe_pos[3];
    f32 target_pos[3];
    f32 unk_0[3];
    f32 distance;
    Actor *blobs[10];
    s32 i;
    s32 blob_count;
    s32 active_count;
    f32 speed_scale;
    switch (actor->unk70_10) {
        case 1:
            if (func_80101DDC(actor)) {
                func_8010A590(actor);
                func_80102424(actor, 2);
            }
            break;
        case 2:
            if (func_8010D248()) {
                if (((PhlegmFlags49 *) actor)->local_3)
                    speed_scale = _subaddiejoy_entrypoint_9(actor, &actor->unk54, 3);
                else {
                    speed_scale = 1.0f;
                    actor->unk54 = func_8010CD28(actor);
                }
                func_80102BF8(actor, 0.15f, 120.0f, 360.0f);
                if (func_800DA298(0) && func_800D90A4(&actor->unk58)) {
                    blob_count = _subaddiefind_entrypoint_4(0x399, blobs, 10);
                    active_count = blob_count;
                    for (i = 0; i < blob_count; i++) {
                        if (!((PhlegmFlags49 *) blobs[i])->local_2)
                            active_count--;
                    }
                    if (!((PhlegmFlags49 *) actor)->local_3 && active_count >= 4 &&
                        !_suchase_entrypoint_1(actor))
                        return;
                    distance = (func_800D8FF8() * (*(f32 *) &actor->actorData[3] * speed_scale)) *
                              func_800F3780(func_80101F24(actor), D_80800C30_chphlegm, 4);
                    func_800EE7F8(target_pos, actor->position);
                    func_800EF1B8(target_pos, actor->rotation[1], distance);
                    target_pos[1] -= 80.0f;
                    func_800EE7F8(probe_pos, target_pos);
                    probe_pos[1] = actor->position[1] + 100.0f;
                    if (func_800C6A7C(probe_pos, target_pos, unk_0, actor->unk14))
                        func_800EE7F8(actor->position, target_pos);
                }
            }
    }
}

s32 func_808005E4_chphlegm(Actor *actor, s32 msg, PhlegmEvent30 msg_data)
{
    f32 drop_pos[3];
    Actor *fx_actor;
    switch (msg) {
        case 0x40:
            if (_subaddiefind_entrypoint_9(actor->unk6C_9) == 1) {
                func_80103DFC(actor, drop_pos);
                _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, ((s32 *) drop_pos)[0],
                                            ((s32 *) drop_pos)[1], ((s32 *) drop_pos)[2],
                                            *(s32 *) &actor->rotation[1]);
            }
            func_80800748_chphlegm(actor, -10.0f, 0x95C);
            _chexploder_entrypoint_4(actor, (*msg_data.actors)->position, 0x1C);
            break;
        case 0x90:
            fx_actor = func_80106790(func_80101080());
            _chexploder_entrypoint_9(fx_actor, 3, 0);
            _chexploder_entrypoint_9(fx_actor, 4, 1);
            _chexploder_entrypoint_10(fx_actor, D_80800C50_chphlegm);
            _subaddiefade_entrypoint_3(fx_actor);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_80800704_chphlegm(s32 arg0, s32 arg1)
{
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

void func_80800748_chphlegm(Actor *actor, f32 y_offset, s32 particle_id)
{
    f32 end_pos[3];
    s32 emitter;
    func_800EE7F8(end_pos, actor->position);
    end_pos[1] += actor->scale * y_offset;
    emitter = func_800B53A4(10);
    func_800BA3FC(emitter, particle_id);
    func_800BABB8(emitter, actor->position, end_pos, actor->scale, D_80800C5C_chphlegm);
    _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800C88_chphlegm);
}

int func_808007EC_chphlegm(Actor *actor, s32 particle_id)
{
    s32 *emitter;
    emitter = func_800B53A4(2);
    func_800BA3FC(emitter, particle_id);
    // Matching: empty loop needed for the match.
    do {
    } while (0);
    func_800BABB8(emitter, (char *) actor + 4, 0, *(f32 *) ((char *) actor + 0x38),
                  D_80800C98_chphlegm);
}

void func_80800848_chphlegm(s32 arg0)
{
}

void func_80800850_chphlegm(Actor *actor)
{
    s32 player_state;
    func_8010D254(actor->actorData);
    switch ((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) {
        case 1:
            if (!func_800C954C()) {
                func_80101FDC(actor, 2);
            }
            return;
        case 2:
            player_state = func_800F55FC(func_800F54E4());
            if (!func_800DA298(0x1A6) &&
                func_800EFFB4(actor->position, 1000.0f, (f32 *) actor->actorData)) {
                func_800DA544(0x1A6);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1800, 4, 0, 0x57);
            }
            if ((s32) ((u32) player_state << 4) < 0 && func_80090150()) {
                if (!func_800DA298(0x170)) {
                    func_800DA544(0x170);
                    _subaddiedialog_entrypoint_11(actor->unk0, 0x17FF, 4, 0, 0x57);
                    func_80101FDC(actor, 4);
                    return;
                }
                func_80108B04(actor, 0);
                func_80101FDC(actor, 3);
                actor->unk58 = func_800DC178(3.0f, 4.0f);
            }
            break;
        case 3:
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 2);
            }
    }
}

s32 func_808009DC_chphlegm(Actor *actor, s32 msg, PhlegmEvent9DC msg_data)
{
    switch (msg) {
        case 0x3D:
            func_80800A58_chphlegm(actor);
            break;
        case 0x2E:
            func_80101FDC(actor, 2);
            break;
        case 0x95:
            func_80101FDC(actor, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

// Drops a phlegm ball (0x398) from above the player.
void func_80800A58_chphlegm(actor) Actor *actor;
{
    f32 spawn_pos[3];
    f32 target_pos[3];
    f32 player_pos[3];
    Actor *ball;

    _subaddieaudioquick_entrypoint_2(actor, D_80800CD8_chphlegm, D_80800CC4_chphlegm);
    func_8008FE68(player_pos);
    func_800EE7F8(target_pos, player_pos);
    func_800EE7F8(spawn_pos, player_pos);
    spawn_pos[1] += 2500.0f;
    ball = func_80108528(0x398, spawn_pos, 0, &actor);
    func_80102FDC(ball, func_800DC178(3.0f, 4.0f));
    func_800EFB24((f32 *) &ball->actorData[4], target_pos, spawn_pos);
    func_800EF368((f32 *) &ball->actorData[4], 3500.0f);
    ball->unk64_19 = 1;
}

extern void func_80105834();
extern int func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_8010A730();
u32 D_80800B40_chphlegm[6] = {0x0, 0x0, 0x3F5EB852, 0x1BC0002, 0x3F0CCCCD, 0x1BD0001};
int D_80800B58_chphlegm[18] = {0x2FB0398,
                               -0xFFFF,
                               0x0,
                               (u32) func_808000C4_chphlegm,
                               (u32) func_80105834,
                               (u32) func_80101870,
                               0x752F,
                               0x3F4CCCCD,
                               0x0,
                               0x140404,
                               0x0,
                               (u32) func_80108ED0,
                               0x0,
                               (u32) func_80800024_chphlegm,
                               (u32) func_80107C2C,
                               -0x7FC00000,
                               (u32) func_8080026C_chphlegm,
                               0x0};
int D_80800BA0_chphlegm[18] = {0x2FC0399,
                               0x6DD0001,
                               (u32) &D_80800B40_chphlegm,
                               (u32) func_808003B4_chphlegm,
                               (u32) func_80105834,
                               (u32) func_80800704_chphlegm,
                               0x0,
                               0x3F4CCCCD,
                               0x0,
                               0x3140524,
                               0x0,
                               (u32) func_80108ED0,
                               0x0,
                               (u32) func_80800354_chphlegm,
                               (u32) func_80107C2C,
                               -0x7FDFFFF1,
                               (u32) func_808005E4_chphlegm,
                               0x0};
void *D_80800BE8_chphlegm = (void *) 0x030A03A0;
static u32 D_80800BE8_chphlegm_rest[17] = {0x1,
                                           0x0,
                                           (u32) func_80800850_chphlegm,
                                           (u32) func_80105834,
                                           (u32) func_8010A730,
                                           0x0,
                                           0x0,
                                           0xE50000,
                                           0x0,
                                           0x0,
                                           0x0,
                                           0x0,
                                           (u32) func_80800848_chphlegm,
                                           (u32) func_80107C2C,
                                           0x80000602,
                                           (u32) func_808009DC_chphlegm,
                                           0x0};
f32 D_80800C30_chphlegm[8] = {0.0f, 0.75f, 0.3f, 0.5f, 0.8f, 1.0f, 1.0f, 0.75f};
u8 D_80800C50_chphlegm[12] = {0x0, 0x44, 0x0, 0x45, 0x0, 0x46, 0x0, 0x47, 0x0, 0x48, 0xFF, 0xFF};
s32 D_80800C5C_chphlegm[11] = {0x140016,  0x17820022, 0x190033, 0xC0019,  0x2B0099, 0xCC002D,
                               0x2580320, 0x70000,    0xE000A,  0x140A1A, 0x0};
u8 D_80800C88_chphlegm[16] = {0x0, 0x13, 0x4, 0x1F, 0x0, 0x2, 0x0, 0xD,
                              0x0, 0xF3, 0x1, 0xC,  0x0, 0x0, 0x0, 0x0};
u8 D_80800C98_chphlegm[44] = {0x0,  0x16, 0x12, 0x0,  0x0,  0x22, 0x0,  0x19, 0x0,  0x33, 0x0,
                              0xC,  0x0,  0x19, 0x0,  0x2B, 0x0,  0x4C, 0x0,  0x66, 0x0,  0x15,
                              0x0,  0x19, 0x0,  0x99, 0x0,  0xE,  0x0,  0xA,  0x0,  0x1E, 0x0,
                              0x1B, 0xFE, 0x70, 0xFE, 0xD4, 0x2,  0x1A, 0x0,  0x0,  0x0,  0x0};
u8 D_80800CC4_chphlegm[20] = {0x0, 0x13, 0x5, 0x38, 0x0, 0x2, 0x0, 0x16, 0x75, 0x30,
                              0x0, 0xD,  0x0, 0xF3, 0x1, 0xC, 0x0, 0x0,  0x0,  0x0};
u8 D_80800CD8_chphlegm[24] = {0x0, 0x0, 0x0, 0x0, 0x45, 0xFA, 0x0, 0x0, 0xC4, 0xBB, 0x80, 0x0,
                              0x0, 0x0, 0x0, 0x0, 0x0,  0x0,  0x0, 0x0, 0x0,  0x0,  0x0,  0x0};
