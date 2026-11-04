#include "common.h"

extern void *D_80800410_chbottlesparty;
extern int D_80800458_chbottlesparty[];
extern u8 D_808004A0_chbottlesparty[];
extern u8 D_808004B0_chbottlesparty[];
extern s32 D_808004CC_chbottlesparty[][3];
extern s32 D_808004FC_chbottlesparty[];
extern s32 D_80800508_chbottlesparty[];
extern f32 func_800F0F9C(f32, f32);
extern f32 func_800F3780(f32, s32 *, s32);
extern int func_800F3214(s32 *, s32 *, s32 *, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
extern void func_800C8E54(s32, f32, f32);
int func_80800138_chbottlesparty();
void func_80800170_chbottlesparty();

int chbottlesparty_entrypoint_0()
{
    return &D_80800410_chbottlesparty;
}

int chbottlesparty_entrypoint_1()
{
    return &D_80800458_chbottlesparty;
}

s32 func_80800018_chbottlesparty(s32 actor)
{
    if (func_800DA298(0x3B) == 0) {
        func_800FFAB0(actor);
    } else {
        func_8010A800(actor, 0);
    }
}

void func_8080022C_chbottlesparty();

void func_8080005C_chbottlesparty(u8 *actor)
{
    func_8080022C_chbottlesparty();
    if (((u32) (u16) *(u16 *) ((char *) actor + 0x72) >> 0xA) == 1) {
        func_80800170_chbottlesparty(actor);
    }
}

s32 func_8080009C_chbottlesparty(Actor *actor, s32 msg, s32 param_2)
{
    switch (msg) {
        case 0x2E:
            *(f32 *) &actor->actorData[4] = 6.0f;
            func_80101FDC(actor, 1);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808004A0_chbottlesparty, *(s32 *) &actor->scale);
            break;
        case 0x95:
            func_80800138_chbottlesparty(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

// Message 0x95 (init): only for guests with world index 0x32 (unk74_7).
int func_80800138_chbottlesparty(actor)
Actor *actor;
{
    if (((u32) *(u16 *) ((char *) actor + 0x76) >> 7) == 0x32) {
        func_80103140(actor, 0x653, 0);
    }
}

// Guest dialog: before the quiz (FLAG2_67C unset) starts the idle dialog; afterwards triggers 0x154F when the player is near.
void func_80800170_chbottlesparty(actor) Actor *actor;
{
    if (!func_800DA298(0x43)) {
        if (!func_800DA298(0x67C))
            _subaddiedialog_entrypoint_7(actor, actor->position, D_808004B0_chbottlesparty);
        else if (func_800F64A4(func_800F54E4(), 0x601) && func_8010CAC0(actor->position, 500) &&
                 func_800D90A4((f32 *) &actor->actorData[4])) {
            _subaddiedialog_entrypoint_11(actor->unk0, 0x154F, 4, 0, 15);
            func_80101FDC(actor, 2);
        }
    }
}

void func_8080022C_chbottlesparty(s32 arg0)
{
}

// Despawns unless the Tower of Tragedy is finished and Hag 1 is alive; otherwise creates the point light.
void func_80800234_chbottlesparty(Actor *actor)
{
    if (!func_800DA298(0x3B) || func_800DA298(0x43)) {
        func_800FFAB0(actor);
    } else {
        *(f32 *) &actor->actorData[5] = func_800DC178(0.4f, 0.6f);
        actor->unk58 = func_800DC178(0.0f, *(f32 *) &actor->actorData[5]);
        actor->unk6C_0 = actor->unk74_7 - 0x32;
        if (actor->unk6C_0 >= 5) {
            actor->unk6C_0 = 0;
        }
        actor->actorData[4] = func_800C8A98();
        func_800C8E54(actor->actorData[4], actor->scale * 300.0f, actor->scale * 600.0f);
        func_800C8CB8(actor->actorData[4], actor->position);
    }
}

// Cycles the light colour through the palette indexed by the actor param.
void func_80800330_chbottlesparty(Actor *actor)
{
    s32 color[3];
    Vec3f light_pos;
    s32 pad0;
    f32 blend;
    if (actor->actorData[4] != 0) {
        blend = func_800F3780(func_800F0F9C(actor->unk58, *(f32 *) &actor->actorData[5]),
                                D_80800508_chbottlesparty, 3);
        func_80103DFC(actor, light_pos.f);
        func_800F3214(color, D_808004FC_chbottlesparty,
                      D_808004CC_chbottlesparty[actor->unk6C_0], blend);
        func_800C8E84(actor->actorData[4], color);
        actor->unk58 += func_800D8FF8();
    }
}

s32 func_808003E4_chbottlesparty(s32 actor, s32 msg, s32 param_2)
{
    return 0;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_80800410_chbottlesparty = (void *) 0x00AC04F8;
static u32 D_80800410_chbottlesparty_rest[17] = {0x7810001,
                                                 0x0,
                                                 (u32) func_8080005C_chbottlesparty,
                                                 (u32) func_80105834,
                                                 (u32) func_80101870,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x804,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_80800018_chbottlesparty,
                                                 (u32) func_80107C2C,
                                                 0x80082402,
                                                 (u32) func_8080009C_chbottlesparty,
                                                 0x0};
int D_80800458_chbottlesparty[18] = {0x15804F9,
                                     0x1,
                                     0x0,
                                     (u32) func_80800330_chbottlesparty,
                                     (u32) func_80105834,
                                     (u32) func_80101870,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x4,
                                     0x0,
                                     0x0,
                                     0x0,
                                     (u32) func_80800234_chbottlesparty,
                                     (u32) func_80107C2C,
                                     -0x7FFFDBFE,
                                     (u32) func_808003E4_chbottlesparty,
                                     0x0};
u8 D_808004A0_chbottlesparty[16] = {0x43, 0x85, 0x80, 0x0, 0x43, 0x85, 0x80, 0x0,
                                    0x43, 0x85, 0x80, 0x0, 0x43, 0x5,  0x80, 0x0};
u8 D_808004B0_chbottlesparty[28] = {0x6, 0x7C, 0x1, 0xF4, 0x15, 0x4E, 0x0, 0x0, 0x0, 0x0,
                                    0x6, 0x1,  0x0, 0x0,  0x0,  0x0,  0x0, 0xF, 0x0, 0x0,
                                    0x0, 0xC,  0x0, 0x0,  0x2,  0x0,  0x0, 0x0};
s32 D_808004CC_chbottlesparty[4][3] = {0xFF, 0x0, 0x0,  0x0,  0xFF, 0x0,
                                       0x0,  0x0, 0xFF, 0xFF, 0xFF, 0x0};
s32 D_808004FC_chbottlesparty[3] = {0x20, 0x20, 0x20};
s32 D_80800508_chbottlesparty[6] = {0x0, 0x0, 0x3F000000, 0x3F800000, 0x3F800000, 0x0};
