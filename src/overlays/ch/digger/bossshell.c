#include "common.h"

extern void *D_80800560_chdiggerbossshell;
extern void *D_808005A8_chdiggerbossshell;
typedef union {
    s32 word;
    void *pointer;
} DiggerBossShellEventPayload;
extern int D_808005F0_chdiggerbossshell[];
extern u32 D_80800600_chdiggerbossshell[];
extern s32 func_800D9078(f32 *);
extern s32 D_8080060C_chdiggerbossshell[];
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_80102D78(Actor *, f32 *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void _fxegg_entrypoint_5(f32 *, f32 *, f32);
extern void func_800EF174(f32 *, f32 *, f32);
extern void func_800F1A88(f32 *, f32 *);
extern f32 func_8010CD28(void);
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800136E4(f32);
void func_808001EC_chdiggerbossshell();
int func_808002CC_chdiggerbossshell();
void func_80800504_chdiggerbossshell();
Actor *func_80800330_chdiggerbossshell();

void *chdiggerbossshell_entrypoint_0(void)
{
    return &D_80800560_chdiggerbossshell;
}

int chdiggerbossshell_entrypoint_1()
{
    return (int) &D_808005A8_chdiggerbossshell;
}

// Init: computes the launch velocity for a ballistic arc to the target at 45 degrees pitch.
void func_80800018_chdiggerbossshell(Actor *actor)
{
    f32 dist;
    f32 height;
    f32 speed;
    f32 speed_sq;
    s32 pad0;

    dist = func_800EFB8C(actor->position, (f32 *) actor->actorData);
    height = actor->position[1] - ((f32 *) actor->actorData)[1];
    actor->rotation[0] = 45.0f;
    actor->rotation[1] = func_80102D78(actor, (f32 *) actor->actorData);
    speed_sq = (dist * dist * 9800.0f) / (dist + height);
    speed = sqrtf(speed_sq);
    func_800EEC30((f32 *) &actor->actorData[4], actor->rotation[0], actor->rotation[1],
                  speed);
}

// Flight: egg trail, gravity; explodes when it reaches the target height.
void func_808000B4_chdiggerbossshell(Actor *actor)
{
    f32 dt;

    if (actor->unk70_10 == 1) {
        dt = func_800D8FF8();
        _fxegg_entrypoint_5(actor->position, (f32 *) &actor->actorData[4], 1.0f);
        func_800EF174(actor->position, (f32 *) &actor->actorData[4], func_800D8FF8());
        if (actor->position[1] < ((f32 *) actor->actorData)[1]) {
            actor->position[1] = ((f32 *) actor->actorData)[1];
            func_808001EC_chdiggerbossshell(actor);
        }
        ((f32 *) actor->actorData)[5] += -9800.0f * dt;
        func_800F1A88((f32 *) &actor->actorData[4], actor->rotation);
        actor->rotation[0] += 90.0f;
    }
}

s32 func_80800188_chdiggerbossshell(Actor *actor, s32 msg,
                                    DiggerBossShellEventPayload data)
{
    switch (msg) {
        case 0x40:
            func_808001EC_chdiggerbossshell(actor);
            break;
        case 0x3D:
            func_800FFAB0(func_80800330_chdiggerbossshell(actor));
            break;
        default:
            return 0;
    }
    return 1;
}

// Landing explosion: particles, sound, camera shake, rumble, light flash.
void func_808001EC_chdiggerbossshell(actor) s32 actor;
{
    f32 pos[3];
    func_800EE7F8(pos, actor + 4);
    pos[1] += 50.0f;
    func_800BBCB8(pos, 0, 0x3FB33333, 1, _fxgenlist_entrypoint_2());
    _subaddieaudioquick_entrypoint_2(actor, pos, &D_808005F0_chdiggerbossshell);
    func_800E1610(0, 0x41A00000, 0x3F666666, actor + 4);
    func_80018820(0, 0x40000000, 0x3E800000);
    pos[1] += 50.0f;
    func_808002CC_chdiggerbossshell(pos);
    func_8010A570(actor);
    func_80101FDC(actor, 2);
    func_80108B04(actor, 0);
}

int func_808002CC_chdiggerbossshell(pos)
s32 pos;
{
    s32 light;
    light = func_800C8A98();
    func_800C8CB8(light | 0, pos);
    func_800C8E84(light, &D_80800600_chdiggerbossshell);
    func_800C8E54(light, 0x44160000, 0x447A0000);
    _chlightfader_entrypoint_1(light, 0x3FB33333, 5);
}

// Splits the shell into 4 bomblets (actor 0x4F4).
Actor *func_80800330_chdiggerbossshell(actor)
Actor *actor;
{
    f32 yaw;
    s32 i;
    Actor *bomblet;
    f32 pos[3];
    yaw = func_8010CD28() + actor->unk54;
    func_800EE7F8(pos, actor->position);
    if (pos[1] < 7500.0f)
        pos[1] = 7500.0f;
    pos[1] += 60.0f;
    for (i = 0; i < 4; i++) {
        bomblet = func_80108528(0x4F4, pos, (s32) yaw, &actor);
        func_80102FDC(bomblet, actor->scale);
        func_80103140(bomblet, (u16) (i + 0x905), 0);
        *(f32 *) ((u8 *) bomblet + 0x24) = *(f32 *) ((u8 *) actor + 0x24);
        yaw = func_800136E4(yaw + 90.0f);
    }
    return actor;
}

void func_8080044C_chdiggerbossshell(void *actor)
{
    ((struct Actor *) actor)->unk58 = 1.75;
}

// Bomblet: explodes on contact or hit, fades out after 1.75 s.
void func_8080045C_chdiggerbossshell(Actor *actor)
{
    if (actor->unk70_10 == 1) {
        if (func_8010B990(actor, 0x400005) & 0x20) {
            func_80800504_chdiggerbossshell(actor);
        }
        if (func_800D9078(&actor->unk58)) {
            _subaddiefade_entrypoint_3(actor);
        }
    }
}

s32 func_808004C8_chdiggerbossshell(s32 actor, s32 msg, s32 data)
{
    if (msg == 0x40) {
        func_80800504_chdiggerbossshell(actor);
    } else {
        return 0;
    }
    return 1;
}

void func_80800504_chdiggerbossshell(actor) s32 actor;
{
    s32 pos;

    pos = actor + 4;
    func_800BBCB8(pos, pos, 0x3F800000, 3, &D_8080060C_chdiggerbossshell);
    func_8010A570(actor);
    func_800FFAB0(actor);
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
void *D_80800560_chdiggerbossshell = (void *) 0x01BD04F3;
static u32 D_80800560_chdiggerbossshell_rest[17] = {0x9040001,
                                                    0x0,
                                                    (u32) func_808000B4_chdiggerbossshell,
                                                    (u32) func_80102EC0,
                                                    (u32) func_80101870,
                                                    0x0,
                                                    0x41000000,
                                                    0x0,
                                                    0x4,
                                                    0x0,
                                                    (u32) func_80108ED0,
                                                    0x0,
                                                    (u32) func_80800018_chdiggerbossshell,
                                                    (u32) func_80107C2C,
                                                    0x80800000,
                                                    (u32) func_80800188_chdiggerbossshell,
                                                    0x0};
void *D_808005A8_chdiggerbossshell = (void *) 0x02AC04F4;
static u32 D_808005A8_chdiggerbossshell_rest[17] = {0xFFFF0001,
                                                    0x0,
                                                    (u32) func_8080045C_chdiggerbossshell,
                                                    (u32) func_80102EC0,
                                                    (u32) func_80101870,
                                                    0x0,
                                                    0x40400000,
                                                    0x0,
                                                    0x4,
                                                    0x0,
                                                    (u32) func_80108ED0,
                                                    0x0,
                                                    (u32) func_8080044C_chdiggerbossshell,
                                                    (u32) func_80107C2C,
                                                    0x0,
                                                    (u32) func_808004C8_chdiggerbossshell,
                                                    0x0};
int D_808005F0_chdiggerbossshell[4] = {0x130413, 0xD00F3, 0x10C0018, 0x0};
u32 D_80800600_chdiggerbossshell[3] = {0xFF, 0xC0, 0x60};
s32 D_8080060C_chdiggerbossshell[13] = {0x160004, 0x1D09C9, 0x20DCDC, -0x235FFFDE, 0x330066,
                                        0x9900CC, 0x2B004C, 0x800015, 0x190099,    0x2D003C,
                                        0x50000E, 0xF0014,  0x0};
