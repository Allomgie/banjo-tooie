// Climb trigger at the foot of a pole, ladder or rope: finds the nearest top marker, picks a
// climb style, and starts the player's climb when they stand inside its radius.
#include "common.h"

extern f32 func_800EFB8C(f32 *, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
typedef struct {
    s32 style;
    f32 scale;
} ClimbBaseScalePreset;
extern ClimbBaseScalePreset D_808003B0_chclimbbase[];
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F7F50(s32, f32 *, f32 *, f32, s32, s32);
extern void func_800F7F00(s32, f32 *, f32 *, f32, s32, s32, f32);
extern void *D_808003D0_chclimbbase;
extern void *D_80800418_chclimbbase;

// Finds the nearest top marker (0x1FA/0x1FB) and writes its position to top_pos.
s32 func_80800000_chclimbbase(Actor *actor, f32 *top_pos)
{
    f32 pos_a[3];
    f32 pos_b[3];
    f32 dist_a;
    s32 found_b;
    s32 found_a;
    f32 *pos;
    f32 dist_b;

    pos = actor->position;
    found_a = _gccubesearch_entrypoint_13(pos_a, 0x1FA, pos);
    found_b = _gccubesearch_entrypoint_13(pos_b, 0x1FB, pos);
    if (!found_a && !found_b) {
        return 0;
    }
    if (found_a && found_b) {
        dist_a = func_800EFB8C(pos, pos_a);
        dist_b = func_800EFB8C(pos, pos_b);
        if (dist_b < dist_a) {
            found_a = 0;
        }
    }
    if (found_a) {
        func_800EE7F8(top_pos, pos_a);
        actor->unk6C_0 = 1;
    } else {
        func_800EE7F8(top_pos, pos_b);
        actor->unk6C_0 = 2;
    }
    return 1;
}

// Climb style: 2 if the level ability bit 0x80 is set, else 1.
s32 func_808000FC_chclimbbase(void)
{
    if (_gclevel_entrypoint_4(0x80)) {
        return 2;
    }
    return 1;
}

// Setup: pick the climb style from the actor scale
void func_80800128_chclimbbase(Actor *actor)
{
    ClimbBaseScalePreset *preset;

    func_80800000_chclimbbase(actor, actor->actorData);
    preset = D_808003B0_chclimbbase;
    if (actor->scale == 1.0f) {
        actor->actorData[3] = func_808000FC_chclimbbase();
    } else {
        while (preset->style != 4 && preset->scale != actor->scale)
            preset++;
        actor->actorData[3] = preset->style;
    }
    *(s16 *) ((u8 *) actor + 0x7C) =
        (s32) func_800EEAD4(actor->position, (f32 *) actor->actorData) + 500;
}

// Update: start the climb when the player is inside the radius below the top
void func_80800200_chclimbbase(Actor *actor)
{
    f32 delta[3];
    f32 radius;
    f32 player_pos[3];
    radius = (s32) actor->unk74_7 + 25;
    func_8010D254(player_pos);
    func_800EFB24(delta, actor->position, player_pos);
    if (delta[0] * delta[0] + delta[2] * delta[2] < radius * radius &&
        actor->position[1] < player_pos[1] && player_pos[1] <= ((f32 *) actor->actorData)[1]) {
        switch (actor->unk6C_9) {
            case 0x1F9:
                func_800F7F50(func_800F54E4(), actor->position, (f32 *) actor->actorData,
                              (f32) actor->unk74_7, actor->unk6C_0, actor->actorData[3]);
                break;
            case 0x16E:
                func_800F7F00(func_800F54E4(), actor->position, (f32 *) actor->actorData,
                              (f32) actor->unk74_7, actor->unk6C_0, actor->actorData[3],
                              actor->rotation[1]);
        }
    }
}

int chclimbbase_entrypoint_0()
{
    return &D_808003D0_chclimbbase;
}

int chclimbbase_entrypoint_1()
{
    return &D_80800418_chclimbbase;
}

// TU-NOTE: the data tables below are defined in this file because they point to its
// functions; IDO schedules those differently otherwise. Values are from the ROM.
// D_808003B4_chclimbbase = D_808003B0_chclimbbase + 0x4 (linker symbol).
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
ClimbBaseScalePreset D_808003B0_chclimbbase[4] = {0x1, 1.01f, 0x2, 1.02f, 0x3, 1.03f, 0x4, 0.0f};
void *D_808003D0_chclimbbase = (void *) 0x003501F9;
static u32 D_808003D0_chclimbbase_rest[17] = {0x1,
                                              0x0,
                                              (u32) func_80800200_chclimbbase,
                                              (u32) func_80105834,
                                              (u32) func_8010A730,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              (u32) func_80800128_chclimbbase,
                                              (u32) func_80107C2C,
                                              0x80002602,
                                              0x0,
                                              0x0};
void *D_80800418_chclimbbase = (void *) 0x0035016E;
static u32 D_80800418_chclimbbase_rest[17] = {0x1,
                                              0x0,
                                              (u32) func_80800200_chclimbbase,
                                              (u32) func_80105834,
                                              (u32) func_8010A730,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0,
                                              (u32) func_80800128_chclimbbase,
                                              (u32) func_80107C2C,
                                              0x80002602,
                                              0x0,
                                              0x0};
