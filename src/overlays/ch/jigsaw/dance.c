#include "common.h"

extern int D_80800488_chjigsawdance[];
extern f32 func_80101F24(void);
extern f32 func_80090010(void);
extern void *func_8008FD20(void);
extern void *func_80104248(Actor *);
extern f32 anctrl_getAnimTimer(void *);
extern void anctrl_setStart(void *, f32);
extern void anctrl_setDuration(void *, f32);

// Init: claims a collectible light slot for the jiggy.
void func_80800000_chjigsawdance(Actor *actor)
{
    if (func_800CFA70((s32) actor->unk50, 1) != -1) {
        actor->unk6C_0 = func_800C8A98();
        func_800CF9E4((s32) actor->unk50, 1, actor->unk6C_0);
        func_800C8CB8(actor->unk6C_0, (u8 *) actor + 4);
        return;
    }
    actor->unk6C_0 = 0;
}

// Frees the light slot.
int func_808000AC_chjigsawdance(Actor *actor)
{
    Actor *owner;
    s32 masked;
    s32 word;
    char *base;
    s32 slot16;
    s32 slot;
    // Matching: the temporary chain and the missing return are needed for the match.
    word = *(s32 *) ((base = (char *) actor) + 0x6C);
    masked = word & 0x1FF;
    slot16 = (unsigned short) masked;
    slot = slot16;
    if (slot != 0) {
        func_800C8B84(slot);
        owner = actor;
        *(u16 *) ((char *) owner + 0x6E) &= 0xFE00;
    }
}

// Per frame: keeps the light at the player's hand bone (7) and copies the player's yaw, animation index and timer.
void func_808000F0_chjigsawdance(Actor *actor)
{
    void *player_anim;
    void *jiggy_anim;
    f32 hand_pos[3];

    if (actor->unk6C_0) {
        if (func_80101F24() > 0.85f) {
            func_800C8B84(actor->unk6C_0);
            actor->unk6C_0 = 0;
        } else {
            func_8008FE94(7, hand_pos);
            func_800C8CB8(actor->unk6C_0, hand_pos);
        }
    }
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            func_8010D254(actor->position);
            actor->rotation[1] = func_80090010();
            player_anim = func_8008FD20();
            jiggy_anim = func_80104248(actor);
            anctrl_setSmoothTransition(jiggy_anim, 0);
            anctrl_setIndex(jiggy_anim, anctrl_getIndex(player_anim));
            anctrl_setStart(jiggy_anim, anctrl_getAnimTimer(player_anim));
            anctrl_setDuration(jiggy_anim, 1000.0f);
            anctrl_start(jiggy_anim);
            break;
        case 3:
            player_anim = func_8008FD20();
            jiggy_anim = func_80104248(actor);
            anctrl_setSmoothTransition(jiggy_anim, 0);
            anctrl_setStart(jiggy_anim, anctrl_getAnimTimer(player_anim));
            anctrl_setDuration(jiggy_anim, 1000.0f);
            anctrl_start(jiggy_anim);
            break;
        case 4:
            func_8010D254(actor->position);
            actor->rotation[1] = func_80090010();
            player_anim = func_8008FD20();
            jiggy_anim = func_80104248(actor);
            anctrl_setSmoothTransition(jiggy_anim, 0);
            anctrl_setStart(jiggy_anim, anctrl_getAnimTimer(player_anim));
            anctrl_setDuration(jiggy_anim, 1000.0f);
            anctrl_start(jiggy_anim);
    }
}

s32 chjigsawdance_entrypoint_0(Actor *actor, s32 jiggy_index)
{
    actor->unk50 = jiggy_index;
}

// Command from bs/jig.c (1..5); 5 removes the actor.
void chjigsawdance_entrypoint_1(Actor *actor, s32 cmd)
{
    void *anim;

    switch (cmd) {
        case 3:
            if (actor->unk70_10 == 1) {
                func_80101FDC(actor, 2);
                anctrl_setPlaybackType(func_80104248(actor), 1);
            }
            break;
        case 2:
            func_80101FDC(actor, 3);
            break;
        case 1:
            func_80101FDC(actor, 4);
            break;
        case 4:
            func_8010D254(actor->position);
            actor->rotation[1] = func_80090010();
            anim = func_80104248(actor);
            anctrl_setSmoothTransition(anim, 0);
            anctrl_setStart(anim, anctrl_getAnimTimer(func_8008FD20()));
            anctrl_setDuration(anim, 1000.0f);
            anctrl_start(anim);
            break;
        case 5:
            if (actor->unk6C_0) {
                func_800C8B84((s32) actor->unk6C_0);
                actor->unk6C_0 = 0;
            }
            func_800FFA88(actor->unk0);
    }
}

int *chjigsawdance_entrypoint_2()
{
    return &D_80800488_chjigsawdance;
}

// TU-NOTE: the .data of this overlay is defined here in C; its tables point to functions of this file,
// and IDO schedules some of them differently unless they are in the same unit. Values come from the ROM.
// The extern of D_80800488 is retyped to int[].
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800460_chjigsawdance[10] = {0x0,      0x0,        0x40000000, 0x0,        0x3FC00000,
                                    0x760000, 0x3FC00000, 0x760000,   0x40A00000, 0x300000};
int D_80800488_chjigsawdance[18] = {0x68022C,
                                    0x60F0001,
                                    (u32) &D_80800460_chjigsawdance,
                                    (u32) func_808000F0_chjigsawdance,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x4,
                                    (u32) func_808000AC_chjigsawdance,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chjigsawdance,
                                    (u32) func_80107C2C,
                                    -0x7FFFFFFE,
                                    0x0,
                                    0x0};
