#include "common.h"

extern int D_808001B0_chtransparencypot[];
extern f32 func_800DC178(f32 param_0, f32 param_1);
typedef struct {
    u8 pad_0[0x72];
    u16 state : 6;
    u16 unk_72_6 : 10;
} PotState;
extern s32 func_800D9078();
typedef union {
    s32 value;
    Unk80132ED0 *msg;
} TransparencyPotEvent;
extern u8 D_808001F8_chtransparencypot[];
extern void func_800F7C0C(s32, s32, f32);
extern void _fxsparkle_entrypoint_1(f32 *, s32);
void func_80800148_chtransparencypot();

int chtransparencypot_entrypoint_0()
{
    return (int) D_808001B0_chtransparencypot;
}

void func_8080000C_chtransparencypot(void *actor)
{
    *(float *) ((char *) actor + 0x38) = 0.5f;
}

// mode 1: fade out; mode 2: start the respawn timer
void func_8080001C_chtransparencypot(Actor *actor, s32 mode)
{
    f32 respawn_delay;

    if (mode != 1) {
        if (mode == 2) {
            actor->unk64_16 = 0;
            func_8010A570();
            respawn_delay = *(f32 *) ((u8 *) actor + 0x48) * func_800DC178(0.5f, 1.0f);
            *(f32 *) ((u8 *) actor + 0x58) = respawn_delay;
        }
    } else {
        actor->unk64_16 = 1;
        func_8010A590(actor);
        _subaddiefade_entrypoint_2(actor);
    }
    func_80101FDC(actor, mode);
}

void func_808000B8_chtransparencypot(PotState *pot, s32 unk_1)
{
    if (pot->state == 2 && func_800D9078((u8 *) pot + 0x58, unk_1, pot) != 0) {
        func_8080001C_chtransparencypot(pot, 1);
    }
}

s32 func_80800104_chtransparencypot(Actor *actor, s32 msg_id, TransparencyPotEvent data)
{
    switch (msg_id) {
        case 0x3E:
            func_80800148_chtransparencypot(actor,
                                            (u32) *(u16 *) ((u8 *) data.msg + 0x1A) >> 5);
            break;
        default:
            return 0;
    }
    return 1;
}

// Makes the player invisible (duration from the pot's yaw), plays sparkle and sound, then hides the pot.
void func_80800148_chtransparencypot(actor, player_index) Actor *actor;
s32 player_index;
{
    f32 yaw;

    yaw = actor->rotation[1];
    func_800F7C0C(player_index, 0x67, yaw);
    _fxsparkle_entrypoint_1(actor->position, 2);
    func_800C4AF0(actor->position, D_808001F8_chtransparencypot);
    func_8080001C_chtransparencypot(actor, 2);
}

// TU-NOTE: this overlay's .data is defined here in C. Its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless they share the unit.
// D_808001B0_chtransparencypot is declared as int[] (uses written as NAME[0]).

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
int D_808001B0_chtransparencypot[18] = {0x15802BB,
                                        0x6A60001,
                                        0x0,
                                        (u32) func_808000B8_chtransparencypot,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0x100,
                                        0x0,
                                        (u32) func_80108ED0,
                                        0x0,
                                        (u32) func_8080000C_chtransparencypot,
                                        (u32) func_80107C2C,
                                        (u32) ((u8 *) boot_thread_stack + 0x1F20),
                                        (u32) func_80800104_chtransparencypot,
                                        0x0};
u8 D_808001F8_chtransparencypot[24] = {0x0, 0x13, 0x6, 0x5F, 0x0, 0x16, 0x6D, 0x60,
                                       0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0,
                                       0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0,  0x0};
