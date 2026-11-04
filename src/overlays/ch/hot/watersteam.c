// Probably a steam vent over the Hailfire Peaks hot water: when visible it periodically emits
// steam at a random point of its zone. One variant vanishes once the water is cooled.
#include "common.h"

extern int D_80800240_chhotwatersteam[];
extern int D_80800288_chhotwatersteam[];
typedef struct {
    u8 pad_0[0x76];
    u16 subtype : 9;
    u16 pad_76 : 7;
} SteamState;
extern s32 func_800DA298(s32);
int func_808001E8_chhotwatersteam();
void func_808000D8_chhotwatersteam();

int chhotwatersteam_entrypoint_0()
{
    return (int) &D_80800240_chhotwatersteam;
}

// Despawns the vent when its visibility check fails.
void func_8080000C_chhotwatersteam(ALLink *actor)
{
    if (!(0, func_808001E8_chhotwatersteam(actor))) {
        func_800FFA88(actor->next);
    }
}

void func_8080003C_chhotwatersteam(Actor *actor)
{
    u32 state;
    u16 *flags_ptr;
    u16 flags_copy;
    flags_ptr = &*(u16 *) ((u8 *) actor + 0x72);
    if (func_808001E8_chhotwatersteam() == 0) {
        func_800FFA88(*(s32 *) actor);
        return;
    }
    flags_copy = (state = *flags_ptr);
    state = state >> 0xA;
    switch (state) {
        case 1:
            func_808000D8_chhotwatersteam(actor);
            return;

        case 2:
            if (func_800D9078((u8 *) actor + 0x58) != 0) {
                func_80101FDC(actor, 1);
            }
    }
}

s32 func_808000C4_chhotwatersteam(s32 arg0, s32 arg1, s32 arg2)
{
    return 0;
}

s32 func_8080014C_chhotwatersteam();

// Picks a random zone point at the actor height and tries to emit steam.
void func_808000D8_chhotwatersteam(actor) Actor *actor;
{
    extern f32 func_800DC178(f32, f32);
    f32 point[3];

    func_800CD08C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, point);
    point[1] = actor->position[1];
    if (func_8080014C_chhotwatersteam(actor, point)) {
        func_80101FDC(actor, 2);
        actor->unk58 = func_800DC178(0.3f, 0.4f);
    }
}

// Emits a steam burst at pos when on screen; returns 1 if emitted.
s32 func_8080014C_chhotwatersteam(s32 actor, s32 pos)
{
    f32 steam_end[3];
    f32 steam_start[3];

    if (func_800E3E8C(pos, 0x43FA0000) != 0) {
        func_800EE7F8(steam_end, pos);
        steam_end[1] -= 400.0f;
        func_800EE7F8(steam_start, pos);
        steam_start[1] -= 20.0f;
        func_800BBCB8(steam_start, steam_end, 0x3F800000, 1, &D_80800288_chhotwatersteam);
        return 1;
    }
    return 0;
}

// Variant 0x33 vanishes once the water is cooled (flag 0x31B).
int func_808001E8_chhotwatersteam(actor)
SteamState *actor;
{

if (actor->subtype == 0x33) {
    return !func_800DA298(0x31B);
}

return 1;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_80800240_chhotwatersteam[18] = {0x158046F,
                                      0x1,
                                      0x0,
                                      (u32) func_8080003C_chhotwatersteam,
                                      (u32) func_80105834,
                                      (u32) func_8010A730,
                                      0x9C40000,
                                      0x0,
                                      0x0,
                                      0x5,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_8080000C_chhotwatersteam,
                                      (u32) func_80107C2C,
                                      -0x7FFFF9FE,
                                      (u32) func_808000C4_chhotwatersteam,
                                      0x0};
int D_80800288_chhotwatersteam[14] = {0x1D09DD,   0x161200, 0x2D0014,  0x28001B, 0xFA015E,
                                      0x60020022, 0x990100, 0x3000380, 0x150000, 0x99002B,
                                      0x1000180,  0x0,      0x0,       0x0};
