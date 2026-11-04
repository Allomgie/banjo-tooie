// Most likely one of 20 breakable jade statues: it spins, bursts into sparkles when hit and
// updates the HUD counter; a second actor shows the counter and despawns when all are broken.
#include "common.h"

extern void *D_80800310_chjadestatue;
extern void func_80102FDC(Actor *, f32);
extern f32 func_800D8FF8(void);
typedef union {
    s32 value;
    void *ptr;
} JadeStatueEvent;
extern void *D_80800358_chjadestatue;
void func_808001C0_chjadestatue();

int chjadestatue_entrypoint_0()
{
    return &D_80800310_chjadestatue;
}

void func_8080000C_chjadestatue(Actor *actor)
{
    s32 collected;
    s32 broken_count;
    func_80102FDC(actor, 0.75f);
    collected = func_800D0B68(actor->unk74_7 - 0x32, 5);
    broken_count = func_800D035C(5);
    if (collected || broken_count >= 20)
        func_800FFA88(actor->unk0);
    actor->unk64_20 = 0;
    func_8010A5B0(actor, !func_800DA298(0x680));
}

void func_80800098_chjadestatue(Actor *actor)
{
    actor->rotation[1] -= func_800D8FF8() * 120.0f;
    func_80103110(actor, 0);
    if (actor->unk64_20) {
        func_808001C0_chjadestatue(actor);
        func_800FFA88(actor->unk0);
    }
}

void func_80800104_chjadestatue(Actor *actor)
{
    func_80101870();
    if (actor->unk7C_12) {
        func_80103110(actor, 1);
    }
}

s32 func_80800140_chjadestatue(Actor *actor, s32 msg, JadeStatueEvent arg)
{
    switch (msg) {
        case 0x95:
            func_80109EEC(actor, 0x44);
            break;
        case 0x3E:
            actor->unk64_20 = 1;
            _subaddieDll_entrypoint_4(actor, 1);
            break;
        case 0x2C:
            func_800FFAB0(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808001C0_chjadestatue(actor) u8 *actor;
{
    s32 broken_count;
    _fxsparkle_entrypoint_1(actor + 4, 0xC);
    // Matching: do/while (0) wrapper needed for the match.
    do {
        func_800D0BD4(((u32) (u16) *(u16 *) ((s8 *) actor + 0x76) >> 7) - 0x32, 5);
        broken_count = func_800D035C(5);
        func_800D24E8(0xEE, broken_count, 0);
        func_800FC63C(0xE, 0x3E80);
    } while (0);
    switch (broken_count) {
        case 10:
            func_80101180(0x2B4, 7, 0);
            return;

        case 20:
            func_80101180(0x2B4, 7, 1);
    }
}

int func_8080026C_chjadestatue(s32 actor)
{
    if (func_800D035C(5) >= 0x14) {
        func_800FFAB0(actor);
    }
}

s32 func_808002A4_chjadestatue(Actor *this)
{
    s32 count = func_800D035C(5);
    func_800D24E8(0xEE, count, 0);
    if (count >= 0x14) {
        func_80101180(0x2B3, 0x2C, 0);
        func_800FFAB0(this);
    }
}

int chjadestatue_entrypoint_1()
{
    return &D_80800358_chjadestatue;
}

// TU-NOTE: the .data tables below are defined in this file; they point to functions here,
// and IDO schedules some of these functions differently otherwise. Values are from the ROM.
extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
extern int func_80101870();
void *D_80800310_chjadestatue = (void *) 0x015802B3;
static u32 D_80800310_chjadestatue_rest[17] = {0x9130001,
                                               0x0,
                                               (u32) func_80800098_chjadestatue,
                                               (u32) func_80105834,
                                               (u32) func_80800104_chjadestatue,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x40000000,
                                               0x0,
                                               (u32) func_80108ED0,
                                               0x0,
                                               (u32) func_8080000C_chjadestatue,
                                               (u32) func_80107C2C,
                                               0x80002410,
                                               (u32) func_80800140_chjadestatue,
                                               0x0};
void *D_80800358_chjadestatue = (void *) 0x0158053C;
static u32 D_80800358_chjadestatue_rest[17] = {0x1,
                                               0x0,
                                               (u32) func_808002A4_chjadestatue,
                                               (u32) func_80105834,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_8080026C_chjadestatue,
                                               (u32) func_80107C2C,
                                               0x80000602,
                                               0x0,
                                               0x0};
