#include "common.h"

extern int D_80800330_chcheatopage[];
extern f32 func_800D8FF8(void);
typedef union {
    s32 word;
    void *ptr;
} CheatoEvent;
extern u8 D_80800378_chcheatopage[];
void func_80800194_chcheatopage();
s32 func_808002F0_chcheatopage();

int chcheatopage_entrypoint_0()
{
    return (int) &D_80800330_chcheatopage;
}

void func_8080000C_chcheatopage(Actor *actor)
{
    func_80103110(actor, 0);
    func_8010A5B0(actor, !func_800DA298(0x666));
    if (actor->unk64_20) {
        func_800FC660(0x77);
        actor->unk64_20 = 0;
    }
}

void func_80800070_chcheatopage(Actor *actor)
{
    // 1: spin, 2: fly to player then delete
    switch (actor->unk70_10) {
        case 1:
            actor->rotation[1] += 186.0f * func_800D8FF8();
            func_80103110(actor, 0);
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_800F82D4(func_800F54E4(), 0);
                func_800FFAB0(actor);
                _glcutDll_entrypoint_6(0xAD, 1);
            }
    }
}

s32 func_80800124_chcheatopage(Actor *actor, s32 msg, CheatoEvent data)
{
    switch (msg) {
        case 0x3E:
            func_80800194_chcheatopage(actor, data.word);
            return 1;
        case 0x13:
            *(s32 *) &actor->unk50 = data.word;
            break;
        case 0x14:
            actor->unk64_20 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800194_chcheatopage(actor, info) Actor *actor;
s32 info;
{
    if (func_8010A6B0(actor, (u32) *(u16 *) (info + 0x1A) >> 5)) {
        // collect: sparkle, add Cheato page (item 0x4A), mark registry entry
        _fxsparkle_entrypoint_1(actor->position, 0x14);
        func_800D1844(0x4A);
        func_800D0BD4(*(s32 *) &actor->unk50, 4);
        func_800FC660(0x72);
        // 5th page counted: first-pages dialog
        if (func_800D035C(4) == 5) {
            _subaddiedialog_entrypoint_11(actor->unk0, 0x114A, 4, 0, 0);
        }
        // first-time tutorial: fly to the player in a short cutscene
        if (!func_808002F0_chcheatopage(actor) && !func_800DA9E4(0x67, 1)) {
            func_800F82D4(func_800F54E4(), 2);
            func_8010A570(actor);
            func_80101FDC(actor, 2);
            actor->unk58 = 0.75f;
            func_80103110(actor, 1);
            actor->unk64_16 = 0;
            *((u8 *) actor + 0x75) &= ~0x10;
        } else {
            func_800FFAB0(actor);
        }
    }
}

int func_808002A0_chcheatopage(Actor *actor)
{
    func_80101870();
    if (actor->unk7C_12 && (((u32) *(u16 *) ((u8 *) actor + 0x72) >> 10) == 1)) {
        func_80103110(actor, 1);
    }
}

s32 func_808002F0_chcheatopage(obj)
u8 *obj;
{
    s32 i;

    for (i = 0; i < 1; i++) {

if (D_80800378_chcheatopage[i] == *(s32 *) (obj + 0x50)) {
    return 1;
}

}
return 0;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
int D_80800330_chcheatopage[18] = {0x1870136,
                                   0x7F30001,
                                   0x0,
                                   (u32) func_80800070_chcheatopage,
                                   (u32) func_80105834,
                                   (u32) func_808002A0_chcheatopage,
                                   0x0,
                                   0x3F4CCCCD,
                                   0x0,
                                   0x40000004,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_8080000C_chcheatopage,
                                   (u32) func_80107C2C,
                                   -0x7BEFDFF0,
                                   (u32) func_80800124_chcheatopage,
                                   0x0};
u8 D_80800378_chcheatopage[8] = {0x18, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
