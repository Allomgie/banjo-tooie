// Stop 'n' Swop eggs (pink, blue, yellow): sparkling, collectible egg actors that set their flags
// and give an inventory item; the yellow egg also has a hatch sequence.
#include "ch/secreteggs.h"

typedef struct unkEggData {
    u16 unk_0;
    u16 unk_2;
    u16 unk_4;
    u16 unk_6;
} unkEggData;

extern unkEggData D_80800494_chsecreteggs[0x3];
extern s32 D_808004A8_chsecreteggs;
extern f32 D_808004EC_chsecreteggs[5];
extern f32 D_80800500_chsecreteggs[3];
extern u32 D_8080050C_chsecreteggs[];

// Spawn the sparkle effect; the sprite depends on the egg kind (0x974-0x976).
void func_80800000_chsecreteggs(Actor *actor)
{
    s32 sparkle;

    sparkle = func_800B53A4(0x14);
    func_800BABB8(sparkle, actor->position, actor->position, 1.0f, &D_808004A8_chsecreteggs);
    switch (actor->unk0->unk14) {
        case 0x974:
            func_800BA3FC(sparkle, 0x9DF);
            break;
        case 0x975:
            func_800BA3FC(sparkle, 0x9E0);
            break;
        case 0x976:
            func_800BA3FC(sparkle, 0x9E2);
    }
    func_800BA22C(sparkle, 0x14);
}

void func_808000C0_chsecreteggs(Actor *actor)
{
    if (actor->unk7A_5) {
        if (func_800DA298(FLAG_3E7_SNS_EGG_HATCHED_YELLOW) != 0) {
            func_800FFA88(actor->unk0);
            return;
        }
        func_8010A570(actor);
    }
}

// Per-state update: state 1 plays sounds near the player, state 2 is the hatch sequence.
void func_80800118_chsecreteggs(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1: {
            f32 times_a[5] = D_808004EC_chsecreteggs;
            f32 times_b[3] = D_80800500_chsecreteggs;
            if (func_80101E4C(actor, times_a) != 0) {
                func_800C4140(0xF2EFA53F, actor->position, 0x04B000FA);
            } else if (func_80101E4C(actor, times_b) != 0) {
                func_800C4140(0xBFCFA53D, actor->position, 0x04B000FA);
            }
            if (actor->unk7A_5) {
                s32 player = _plsu_entrypoint_3(actor->unk0);
                if (player != -1) {
                    func_800F7BC8(player, 0x53, actor->unk0);
                }
            }
        }
            return;
        case 2:
            if (func_80101E14(actor, 0.32f) != 0) {
                func_800C4140(0x7FFF4561, actor->position, 0x04B000FA);
            }
            if (func_80101E14(actor, 0.4f) != 0) {
                func_80800000_chsecreteggs(actor);
                if (actor->unk7A_5) {
                    func_800F7700(func_800F54E4(), 9, actor->position);
                }
            } else if (func_80101DDC(actor) != 0) {
                if (actor->unk7A_5 && (func_800DA298(FLAG_3E7_SNS_EGG_HATCHED_YELLOW) == 0)) {
                    func_800DA544(FLAG_3E7_SNS_EGG_HATCHED_YELLOW);

                    func_80101180(0x514, 0x18, actor->unk7A_5 ? 1 : 0);
                }
                _subaddiefade_entrypoint_3(actor);
            }
    }
}

// Message handler; 0x3E = collected: sets the acquired flag, shows dialog, adds item 0x52.
s32 func_80800328_chsecreteggs(Actor *actor, s32 msg, s32 arg2)
{
    s32 dialog_id;

    switch (msg) {
        case 0x18:
            if (actor->unk70_10 != 2) {
                func_80102424(actor, 2);
            }
            return 1;
        case 0x1F:
            func_801015D0(actor);
            switch (D_80800494_chsecreteggs[actor->unk70_10].unk_0) {
                case 0x1D4:
                    func_800DF744(1, 1);
                    break;
                case 0x1D5:
                    func_800DF744(1, 2);
            }
            return 1;
        case 0x3E:
            dialog_id = 0;
            if (actor->unk0->unk14 != 0x974) {
                if (actor->unk0->unk14 == 0x975) {
                    func_800DA544(FLAG_3E3_SNS_EGG_ACQUIRED_BLUE);
                    dialog_id = 0x1551;
                }
            } else {
                func_800DA544(FLAG_3E5_SNS_EGG_ACQUIRED_PINK);
                dialog_id = 0x1552;
            }
            if (dialog_id != 0) {
                _subaddiedialog_entrypoint_11(actor->unk0, dialog_id, 4, actor->position, 0x6F);
            }
            func_800D1844(0x52);
            func_80800000_chsecreteggs(actor);
            func_800FC660(0xE);
            func_800FFA88(actor->unk0);
            return 1;
        default:
            return 0;
    }
}

u32 *chsecreteggs_entrypoint_0(void)
{
    return &D_8080050C_chsecreteggs;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_80800490_chsecreteggs[1] = {0x0};
unkEggData D_80800494_chsecreteggs[3] = {0x0,    0x0, 0x40B0, 0x0,  0x1D4, 0x9,
                                         0x3FC0, 0x0, 0x1D5,  0x4A, 0x1B,  0xFCE0};
static u32 D_80800494_chsecreteggs_rest[16] = {
    0xFDA8002D, 0x1C2028A, 0xD003C,  0x161002,  0x270000, 0x12C0000, 0x2580022, 0x4C004C,
    0xB3,       0x15000C,  0xD9002B, 0x4000500, 0x400B3,  0x70004,   0x31FF6A,  0xFF6A0000};
f32 D_808004EC_chsecreteggs[5] = {0.0f, 0.08f, 0.38f, 0.45f, -1.0f};
f32 D_80800500_chsecreteggs[3] = {0.78f, 0.84f, -1.0f};
u32 D_8080050C_chsecreteggs[21] = {0x1580517,
                                   0x9760001,
                                   (u32) &D_80800490_chsecreteggs,
                                   (u32) func_80800118_chsecreteggs,
                                   (u32) func_80105834,
                                   (u32) func_801018A4,
                                   0x7D00000,
                                   0x3F800000,
                                   0x0,
                                   0x808,
                                   0x0,
                                   (u32) func_80108ED0,
                                   0x0,
                                   (u32) func_808000C0_chsecreteggs,
                                   (u32) func_80107C2C,
                                   0x80000402,
                                   (u32) func_80800328_chsecreteggs,
                                   0x0,
                                   0x0,
                                   0x0,
                                   0x0};
