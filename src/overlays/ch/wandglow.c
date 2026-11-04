// Glow actor at the tip of Mumbo's wand: follows a player bone, pulses while the spell charges,
// and fades out when told to stop.
#include "common.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern void func_800F5A2C(Unk80132ED0 *, s32, f32 *);
extern s32 func_800D9078();
extern Actor *func_80108474(s32, f32 *, s32);
extern s32 D_80800410_chwandglow[];

typedef struct WandGlowStateBits {
    u8 state : 6;
    u8 pad_0 : 2;
} WandGlowStateBits;

// Draws the glow at the wand tip (player bone 6).
void func_80800000_chwandglow(Actor *actor, s32 param_1)
{
    f32 player_pos[3];
    f32 rotation[3];
    f32 tip_pos[3];

    func_800F5A00(actor->unk6C_0, player_pos);
    func_800F5A2C((Unk80132ED0 *) actor->unk6C_0, 6, tip_pos);
    if (!func_800EECE0(player_pos, tip_pos)) {
        func_800EE7F8(actor->position, tip_pos);
    }
    func_800EFA4C(rotation, 0.0f, 0.0f, 0.0f);
    func_800DF410((s32) func_800F10B4(*(f32 *) ((u8 *) actor + 0x2C), 0.0f, 1.0f, 0.0f, 255.0f));
    func_800DF830(2);
    func_800DE448(actor->position, rotation, actor->scale, 0, func_801039E4(actor->unk0));
}

// Calls the callback stored in the actor data.
void func_808000E8_chwandglow(s32 *actor)
{
    s32 (*callback)(s32, s32, s32 *);
    s32 handle;
    s32 (*callback_copy)(s32, s32, s32 *);
    s32 unk_0;
    handle = *actor;
    unk_0 = *(actor + 0x1B);
    callback = *(s32(**)(s32, s32, s32 *))(actor + 0xC);
    unk_0 &= 0x1FF;
    callback_copy = *(s32(**)(s32, s32, s32 *))(actor + 0xC);
    callback(handle, unk_0, actor);
}

// Switches to a new state and sets its start values.
void func_8080011C_chwandglow(actor, state_id) Actor *actor;
s32 state_id;
{
    switch (state_id) {
        case 2:
            ((f32 *) actor->actorData)[4] = 0.4f;
            ((f32 *) actor->actorData)[5] = 0.0f;
            break;
        case 3:
            ((f32 *) actor->actorData)[5] = 1.0f;
            actor->scale = 1.0f;
            break;
        case 4:
            actor->scale = 1.0f;
            ((f32 *) actor->actorData)[4] =
                func_800F10B4(((f32 *) actor->actorData)[5], 0.0f, 1.0f, 0.0f, 0.3f);
            if (((f32 *) actor->actorData)[4] == 0.0f)
                ((f32 *) actor->actorData)[4] += 0.01f;
            break;
        case 5:
            ((f32 *) actor->actorData)[5] = 0.0f;
    }
    ((WandGlowStateBits *) ((u8 *) actor + 0x72))->state = state_id;
}

// Per-frame update: 2 ramp, 3 pulse scale, 4 fade out, 5 delete.
void func_80800218_chwandglow(Actor *actor)
{
    switch (actor->unk70_10) {
        case 2:
            *(f32 *) ((u8 *) actor + 0x2C) =
                func_800F10B4(*(f32 *) ((u8 *) actor + 0x28), 0.0f, 0.4f, 1, 0.0f);
            if (func_800D9078((f32 *) ((u8 *) actor + 0x28)))
                func_8080011C_chwandglow(actor, 3);
            break;
        case 3:
            if (actor->scale == 1.0f)
                actor->scale = 0.75f;
            else
                actor->scale = 1.0f;
            break;
        case 4:
            *(f32 *) ((u8 *) actor + 0x2C) =
                func_800F10B4(*(f32 *) ((u8 *) actor + 0x28), 0.0f, 0.3f, 0.0f, 1);
            if (func_800D9078((f32 *) ((u8 *) actor + 0x28)))
                func_8080011C_chwandglow(actor, 5);
            break;
        case 5:
            func_800FFA88(actor->unk0);
    }
}

// Spawns the glow actor at player bone 6.
Unk80132ED0 *chwandglow_entrypoint_0(Unk80132ED0 *player, void *callback)
{
    Actor *glow;
    f32 pos[3];
    func_800F5A2C(player, 6, pos);
    glow = func_80108474(0x164, pos, 0);
    glow->unk6C_0 = (u32) player;
    glow->actorData[6] = (u32) callback;
    func_8080011C_chwandglow(glow, 2);
    return glow->unk0;
}

// Deletes the glow actor.
void chwandglow_entrypoint_1()
{
    func_800FFA88();
}

// Starts the fade-out.
s32 chwandglow_entrypoint_2(void)
{
    func_8080011C_chwandglow(func_80106790(), 4);
}

int chwandglow_entrypoint_3()
{
    return (int) D_80800410_chwandglow;
}

// TU-NOTE: the overlay .data is defined here in C; its tables point to functions of this file,
// and IDO's assembler schedules some of them differently unless they share the unit.
extern void func_80105834();
extern void func_80107C2C();
s32 D_80800410_chwandglow[20] = {0x2760164,
                                 0x6B60001,
                                 0x0,
                                 (u32) func_80800218_chwandglow,
                                 (u32) func_80105834,
                                 (u32) func_80800000_chwandglow,
                                 0x7D00000,
                                 0x0,
                                 0x0,
                                 0x20004,
                                 (u32) func_808000E8_chwandglow,
                                 0x0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFFFFE,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0};
