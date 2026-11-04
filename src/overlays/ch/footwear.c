#include "common.h"

typedef struct {
    u8 pad0[0x79];
    u8 unk79_4 : 4;
    u8 unk79_0 : 4;
} FootActor;
typedef struct {
    u8 pad0[0x1A];
    u16 unk1A_5 : 11;
    u16 unk1A_0 : 5;
    u8 pad1C[0x24 - 0x1C];
    u32 unk24_22 : 10;
    u32 unk24_0 : 22;
} FootData;
extern s32 func_800DA298(s32);
extern s16 D_808006E6_chfootwear[][5];
extern s16 D_808006E0_chfootwear[][5];
extern s16 D_808006E2_chfootwear[][5];
extern s16 D_808006E8_chfootwear[][5];
extern s32 func_800F7C0C(s32, s32, f32);
extern void *D_80800788_chfootwear;
extern int D_808007D0_chfootwear[];
extern int D_80800818_chfootwear[];
extern s32 D_80800860_chfootwear[];
extern int D_808008A8_chfootwear[];
extern s16 D_808006E4_chfootwear[][5];
extern u8 D_80800754_chfootwear[];
extern u8 D_80800768_chfootwear[];
extern u8 D_80800774_chfootwear[];
extern f32 func_800D8FF8(void);
extern f32 func_800136E4(f32);
extern int func_800EFCD8(f32 *, f32, f32);
extern f32 func_80102D78(Actor *, f32 *);
extern int func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800F549C(s32, s32);
extern int _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
void func_80800424_chfootwear();

// Init: pick the shoe kind (0..4) from the actor id.
void func_80800000_chfootwear(Actor *actor)
{
    u32 actor_id;
    actor_id = (u32) (*(s32 *) ((char *) actor + 0x6C) << 0xB) >> 0x14;
    switch (actor_id) {
        case 0x21A:
            *(s32 *) ((char *) actor + 0x2C) = 0;
            break;

        case 0x22E:
            *(s32 *) ((char *) actor + 0x2C) = 1;
            break;

        case 0x3DB:
            *(s32 *) ((char *) actor + 0x2C) = 2;
            break;

        case 0x16A:

            *(s32 *) ((char *) actor + 0x2C) = 3;
            break;

        case 0x471:
            *(s32 *) ((char *) actor + 0x2C) = 4;
    }

    func_800EE7F8((f32 *) ((char *) actor + 0x18), (f32 *) ((char *) actor + 4), actor);
    *(f32 *) ((char *) actor + 0x50) = *(f32 *) ((char *) actor + 0x48);
    *(f32 *) ((char *) actor + 0x34) = 0.0f;
    func_80800424_chfootwear(actor, 1);
}

int func_80800644_chfootwear();

// Per-frame update: hover/spin, fade by player proximity, respawn timing.
void func_808000B8_chfootwear(Actor *actor)
{
    f32 dir[3];
    f32 target[3];

    switch (((s32 *) actor->actorData)[6]) {
        case 1:
            switch (((u32 *) actor->actorData)[5]) {
                case 0:
                case 4:
                    _subaddieaudioquick_entrypoint_4(actor, actor->position,
                                                     D_80800754_chfootwear, D_80800768_chfootwear);
                    func_800EFCD8(dir, ((f32 *) actor->actorData)[7], 40.0f);
                    dir[1] = 0.0f;
                    func_800EE780(actor->position, (f32 *) actor->actorData, dir);
                    ((f32 *) actor->actorData)[7] += 70.0f * func_800D8FF8();
                    actor->rotation[1] = func_800136E4(((f32 *) actor->actorData)[7] + 90.0f);
                    break;
                case 1:
                    _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                                     D_80800774_chfootwear, 0.25f);
                    break;
                case 2:
                case 3:
                    if (func_8010D23C()) {
                        func_8010D254(target);
                    } else {
                        func_800E3980(target);
                    }
                    func_8010D600(target);
                    actor->unk54 = func_80102D78(actor, target);
                    func_80102BF8(actor, 0.1f, 3.0f, 120.0f);
            }
            if (func_80800644_chfootwear(actor, func_800F54E4()) || _glcutDll_entrypoint_20()) {
                ((s32 *) actor->actorData)[4] = 255;
            } else {
                ((s32 *) actor->actorData)[4] = 120;
            }
            if ((s32) *(u8 *) ((u8 *) actor + 0x9B) < ((s32 *) actor->actorData)[4] - 5) {
                *(u8 *) ((u8 *) actor + 0x9B) = *(u8 *) ((u8 *) actor + 0x9B) + 5;
            } else if (((s32 *) actor->actorData)[4] + 5 <
                       (s32) *(u8 *) ((u8 *) actor + 0x9B)) {
                *(u8 *) ((u8 *) actor + 0x9B) = *(u8 *) ((u8 *) actor + 0x9B) - 5;
            } else {
                *(u8 *) ((u8 *) actor + 0x9B) = ((s32 *) actor->actorData)[4];
            }
            break;
        case 2:
            if (func_800D90A4(&((f32 *) actor->actorData)[3])) {
                func_80800424_chfootwear(
                    actor, D_808006E4_chfootwear[((u32 *) actor->actorData)[5]][0] ? 3 : 4);
            }
            break;
        case 3:
            if (func_800F549C(actor->unk79_4,
                              D_808006E4_chfootwear[((u32 *) actor->actorData)[5]][0]) == 0.0f) {
                func_80800424_chfootwear(actor, 4);
            }
            break;
        case 4:
            if (func_800D90A4(&((f32 *) actor->actorData)[3])) {
                func_80800424_chfootwear(actor, 1);
            }
    }
}

int func_80800664_chfootwear();

s32 func_80800364_chfootwear(FootActor *actor, s32 msg_id, FootData *msg)
{
    FootData *msg_copy;

    if (msg_id == 0x3E) {
        // Matching: copy through the parameter's address needed for the match.
        msg_copy = *(FootData **) &msg;
        if (msg_copy->unk24_22 == 0) {
            if (func_800DA298(0x64F)) {
                if (func_80800664_chfootwear(actor, msg_copy->unk1A_5)) {
                    actor->unk79_4 = msg_copy->unk1A_5;
                    func_80800424_chfootwear(actor, 2);
                    return 1;
                }
            }
        }
        return 0;
    }
    return 0;
}

// State change: 1 hidden, 2 picked up (sparkle), 3 worn, 4 respawn.
void func_80800424_chfootwear(actor, state) Actor *actor;
s32 state;
{
    switch (state) {
        case 1:
            _subaddieDll_entrypoint_4(actor, 0);
            actor->unk64_16 = 1;
            func_8010A590(actor);
            break;
        case 2:
            func_8010A570(actor);
            _fxsparkle_entrypoint_1(actor->position,
                                    D_808006E6_chfootwear[*(s32 *) ((u8 *) actor + 0x2C)][0]);
            _subaddieDll_entrypoint_4(actor, 1);
            actor->unk64_16 = 0;
            *(f32 *) ((u8 *) actor + 0x24) = 1.0f;
        case 3:
            break;
        case 4:
            *(u8 *) ((u8 *) actor + 0x9B) = 0;
            *(f32 *) ((u8 *) actor + 0x24) = 1.0f;
    }
    *(s32 *) ((u8 *) actor + 0x30) = state;
}

// Checks whether the player can take the shoes; with commit also hands them over.
s32 func_8080050C_chfootwear(Actor *actor, s32 player, s32 commit)
{
    if (!actor->unk64_16) {
        return 0;
    }
    if (func_800F6D24(player)) {
        return 0;
    }
    if (!func_800F65D0(player)) {
        return 0;
    }
    if (!func_800C6E38(D_808006E0_chfootwear[*(s32 *) ((u8 *) actor + 0x2C)][0])) {
        if (commit && D_808006E8_chfootwear[*(s32 *) ((u8 *) actor + 0x2C)][0]) {
            _sudialog_entrypoint_0(D_808006E8_chfootwear[*(s32 *) ((u8 *) actor + 0x2C)][0], 0xE);
        }
        return 0;
    }
    if (!func_800F64A4(player, 0x501)) {
        return 0;
    }
    if (commit &&
        func_800F7C0C(player, D_808006E2_chfootwear[*(s32 *) ((u8 *) actor + 0x2C)][0],
                      actor->unk50) != 2) {
        return 0;
    }
    return 1;
}

int func_80800644_chfootwear(s32 actor, s32 player)
{
    func_8080050C_chfootwear(actor, player, 0);
}

int func_80800664_chfootwear(s32 actor, s32 player)
{
    func_8080050C_chfootwear(actor, player, 0x1);
}

int chfootwear_entrypoint_0()
{
    return &D_80800788_chfootwear;
}

int chfootwear_entrypoint_1()
{
    return (int) &D_808007D0_chfootwear;
}

void *chfootwear_entrypoint_2()
{
    return &D_80800818_chfootwear;
}

int chfootwear_entrypoint_3()
{
    return D_80800860_chfootwear;
}

int chfootwear_entrypoint_4()
{
    return (int) &D_808008A8_chfootwear;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void func_80104410();
s16 D_808006E0_chfootwear[5][5] = {0x11, 0x1A, 0x3,  0xD,  0x0, 0xE,  0x1B, 0x2,  0x10,
                                   0x0,  0x26, 0x2B, 0x3,  0xE, 0x4E, 0x25, 0x29, 0x3,
                                   0xF,  0x4F, 0x11, 0x1A, 0x0, 0xD,  0x0};
u32 D_80800714_chfootwear[4] = {0x0, 0x0, 0x3FC00000, 0xD60000};
u32 D_80800724_chfootwear[4] = {0x0, 0x0, 0x3F333333, 0x670000};
u32 D_80800734_chfootwear[4] = {0x0, 0x0, 0x3F4CCCCD, 0x2140000};
u32 D_80800744_chfootwear[4] = {0x0, 0x0, 0x3FE66666, 0x2990000};
u8 D_80800754_chfootwear[20] = {0x0,  0x13, 0x4, 0x4, 0x0, 0xA,  0x1, 0x99, 0x0, 0x16,
                                0x1B, 0x58, 0x0, 0x1, 0x2, 0x58, 0x5, 0xDC, 0x0, 0x0};
u8 D_80800768_chfootwear[12] = {0x3E, 0xC2, 0x8F, 0x5C, 0x3F, 0x61,
                                0x47, 0xAE, 0xBF, 0x80, 0x0,  0x0};
u8 D_80800774_chfootwear[20] = {0x0,  0x13, 0x3, 0xF0, 0x0, 0xA,  0x1, 0x66, 0x0, 0x16,
                                0x59, 0xD8, 0x0, 0x1,  0x2, 0x58, 0x5, 0xDC, 0x0, 0x0};
void *D_80800788_chfootwear = (void *) 0x0158021A;
static u32 D_80800788_chfootwear_rest[17] = {0x6170001,
                                             (u32) &D_80800714_chfootwear,
                                             (u32) func_808000B8_chfootwear,
                                             (u32) func_80105834,
                                             (u32) func_80101870,
                                             0x1F40000,
                                             0x0,
                                             0x0,
                                             0x40000000,
                                             0x0,
                                             (u32) func_80108ED0,
                                             0x0,
                                             (u32) func_80800000_chfootwear,
                                             (u32) func_80107C2C,
                                             (u32) func_80104410,
                                             (u32) func_80800364_chfootwear,
                                             0x0};
int D_808007D0_chfootwear[18] = {0x158022E,
                                 0x6160001,
                                 (u32) &D_80800724_chfootwear,
                                 (u32) func_808000B8_chfootwear,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x1F40000,
                                 0x0,
                                 0x0,
                                 0x40000000,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chfootwear,
                                 (u32) func_80107C2C,
                                 -0x7FEF9BF0,
                                 (u32) func_80800364_chfootwear,
                                 0x0};
int D_80800818_chfootwear[18] = {0x15803DB,
                                 0x7AA0001,
                                 (u32) &D_80800734_chfootwear,
                                 (u32) func_808000B8_chfootwear,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x1F40000,
                                 0x0,
                                 0x0,
                                 0x40000000,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chfootwear,
                                 (u32) func_80107C2C,
                                 -0x7FEF9BB0,
                                 (u32) func_80800364_chfootwear,
                                 0x0};
s32 D_80800860_chfootwear[18] = {0x158016A,
                                 0x8320001,
                                 (u32) &D_80800744_chfootwear,
                                 (u32) func_808000B8_chfootwear,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x1F40000,
                                 0x0,
                                 0x0,
                                 0x40000000,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chfootwear,
                                 (u32) func_80107C2C,
                                 -0x7FEF9BB0,
                                 (u32) func_80800364_chfootwear,
                                 0x0};
int D_808008A8_chfootwear[18] = {0x1580471,
                                 0x6170001,
                                 (u32) &D_80800714_chfootwear,
                                 (u32) func_808000B8_chfootwear,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x1F40000,
                                 0x0,
                                 0x0,
                                 0x40000000,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_80800000_chfootwear,
                                 (u32) func_80107C2C,
                                 (u32) func_80104410,
                                 (u32) func_80800364_chfootwear,
                                 0x0};
