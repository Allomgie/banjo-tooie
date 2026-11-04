// Most likely an icy gust zone: near the player it emits gust particles with a looping sound and
// pushes the player away, less for heavy forms. Gone once Jinjo #33 is collected.
#include "common.h"

extern int D_80800300_chicywind[];
extern s32 D_80800348_chicywind[];
extern s32 D_80800358_chicywind[];
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern f32 func_800F1DF4(f32 *, f32 *);
extern void func_800EEB9C(f32 *, f32, f32);
void func_808001AC_chicywind();

int chicywind_entrypoint_0()
{
    return (int) &D_80800300_chicywind;
}

// Despawns once Jinjo #33 is collected.
s32 func_8080000C_chicywind(Actor *this)
{
    if (func_800D0B68(0x21, 0) != 0) {
        func_800FFAB0(this);
    }
}

// Emits gust particles with a looping sound while the player is near.
void func_80800044_chicywind(Actor *actor)
{
    s32 is_gusting;
    f32 gust_end[3];

    is_gusting = actor->unk70_10 == 2;
    if (is_gusting || (!is_gusting && *((u8 *) actor + 0x5F))) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, is_gusting, &D_80800348_chicywind);
    }
    if (func_800D0B68(0x21, 0)) {
        func_800FFAB0(actor);
        return;
    }
    switch (actor->unk70_10) {
        case 1:
            if (func_8010C9B0(actor->position, 1000)) {
                func_80101FDC(actor, 2);
                actor->unk58 = func_800DC178(0.15f, 0.2f);
            }
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_800EE7F8(gust_end, actor->position);
                func_800EF1B8(gust_end, *(f32 *) ((u8 *) actor + 0x48), -200.0f);
                func_800BBCB8(actor->position, gust_end, 1.0f, 1, &D_80800358_chicywind);
                actor->unk58 = func_800DC178(0.15f, 0.2f);
            }
            func_808001AC_chicywind(actor);
            if (!func_8010C9B0(actor->position, 1800))
                func_80101FDC(actor, 1);
    }
}

// Pushes the player away; weaker for heavy forms and with distance.
void func_808001AC_chicywind(actor) Actor *actor;
{
    f32 push[3];
    f32 player_pos[3];
    f32 distance;
    f32 strength;
    f32 resistance;
    s32 player;

    player = func_800F54E4();
    switch (func_800F5410(player)) {
        default:
            resistance = 0.85f;
            break;
        case 11:
        case 17:
            resistance = 0.65f;
            break;
        case 2:
            resistance =
                func_800F10B4(func_800F5578(player), 1.0f, func_800F55A4(player), 0.6f, 1.0f);
    }
    func_800F5A00(player, player_pos);
    distance = func_800EEAD4(player_pos, actor->position);
    strength = func_800F10B4(distance, 1000.0f, 1800.0f, 1200.0f, 300.0f) * (1.0f / resistance);
    func_800EEB9C(push, func_800F1DF4(actor->position, player_pos), strength);
    func_800F48BC(player, push);
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_80800300_chicywind[18] = {0x33E03AF,
                                0x1,
                                0x0,
                                (u32) func_80800044_chicywind,
                                (u32) func_80105834,
                                (u32) func_8010A730,
                                0x7D00000,
                                0x0,
                                0x0,
                                0x4,
                                0x0,
                                0x0,
                                0x0,
                                (u32) func_8080000C_chicywind,
                                (u32) func_80107C2C,
                                -0x7FFFF9FE,
                                0x0,
                                0x0};
s32 D_80800348_chicywind[4] = {0x1304A3, 0xE0166, 0x1CC0033, 0x180000};
s32 D_80800358_chicywind[14] = {0x1D09DD,  0x2D0640,  0x708000E, 0xF0014,  0x220133,
                                0x1660400, 0x5000015, 0x99,      0x2B0100, 0x1800027,
                                -0xC700C8, 0xC800C8,  0x320000,  0x0};
