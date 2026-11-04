// Most likely a floor smoke/steam emitter: emits rising smoke and sometimes a hiss at a random
// on-screen point of its zone; interval and variant depend on the map.
#include "common.h"

// TU-NOTE: the overlay .data (tables below) is defined in this file because IDO's assembler
// schedules some functions differently unless the tables are in the same unit. Values come
// from the ROM. D_808002D0_chhotfloorsmoke is declared int[] to match the object.

extern int D_808002D0_chhotfloorsmoke[];
extern s32 func_800D9078(f32 *);
extern f32 func_800DC178(f32, f32);
extern u8 D_80800388_chhotfloorsmoke[];
extern u8 D_80800318_chhotfloorsmoke[];
extern u8 D_80800350_chhotfloorsmoke[];
extern s32 func_800E3E8C(s32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
void func_808000FC_chhotfloorsmoke();
void func_808001E8_chhotfloorsmoke();

int chhotfloorsmoke_entrypoint_0()
{
    return (int) &D_808002D0_chhotfloorsmoke;
}

// Picks the variant from the current map: 0xD1 = boiler, 0x12B = Chilli Billi arena.
void func_8080000C_chhotfloorsmoke(Actor *actor)
{
    s32 map_id;
    *(u8 *) ((s8 *) actor + 0x65) = (u8) ((*(u8 *) ((s8 *) actor + 0x65) & 0xFFu) | 0x10);
    map_id = func_800EA05C();
    if (map_id != 0xD1) {
        if (map_id != 0x12B) {
            *(u16 *) ((s8 *) actor + 0x6E) = (u16) (*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00);
            return;
        }
        *(u8 *) ((s8 *) actor + 0x65) = (u8) (*(u8 *) ((s8 *) actor + 0x65) & 0xFFEF);
        *(u16 *) ((s8 *) actor + 0x6E) = (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 2);
        return;
    }
    *(u16 *) ((s8 *) actor + 0x6E) = (u16) ((*(u16 *) ((s8 *) actor + 0x6E) & 0xFE00) | 1);
}

void func_80800090_chhotfloorsmoke(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            func_808000FC_chhotfloorsmoke(actor);
            break;
        case 2:
            if (func_800D9078(&actor->unk58)) {
                func_80101FDC(actor, 1);
            }
    }
}

// Chooses the next emit interval and a random zone point, then emits there.
void func_808000FC_chhotfloorsmoke(actor) Actor *actor;
{
    f32 interval;
    f32 zone_pos[3];

    switch (*(u32 *) ((u8 *) actor + 0x6C) & 0x1FF) {
        case 1:
            // Boiler variant only runs after flag 0x66F.
            if (!func_800DA298(0x66F)) {
                return;
            }
            interval = func_800DC178(1.0f, 1.5f);
            break;
        case 2:
            interval = func_800DC178(1.0f, 1.5f);
            break;
        default:
            interval = func_800DC178(2.0f, 3.0f);
    }
    func_800CD08C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1, zone_pos);
    zone_pos[1] = actor->position[1];
    func_808001E8_chhotfloorsmoke(actor, (s32) zone_pos);
    func_80101FDC(actor, 2);
    actor->unk58 = interval;
}

void func_808001E8_chhotfloorsmoke(actor, pos) Actor *actor;
s32 pos;
{
    f32 low_pos[3];
    f32 high_pos[3];

    // Only emit smoke when the point is on screen.
    if (func_800E3E8C(pos, 500.0f)) {
        func_800EE7F8(low_pos, pos);
        low_pos[1] -= 400.0f;
        func_800EE7F8(high_pos, pos);
        high_pos[1] -= 20.0f;
        func_800BABB8(0, high_pos, low_pos, 1.0f,
                      actor->unk6C_0 == 2 ? D_80800350_chhotfloorsmoke
                                          : D_80800318_chhotfloorsmoke);
    }
    if (actor->unk64_20 && !func_800DA298(0x66F)) {
        _subaddieaudioquick_entrypoint_2(actor, pos, D_80800388_chhotfloorsmoke);
    }
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
int D_808002D0_chhotfloorsmoke[18] = {0x1B30326,
                                      0x1,
                                      0x0,
                                      (u32) func_80800090_chhotfloorsmoke,
                                      (u32) func_80105834,
                                      (u32) func_8010A730,
                                      0x7D00000,
                                      0x0,
                                      0x0,
                                      0x1,
                                      0x0,
                                      0x0,
                                      0x0,
                                      (u32) func_8080000C_chhotfloorsmoke,
                                      (u32) func_80107C2C,
                                      -0x7FFFF9FE,
                                      0x0,
                                      0x0};
u8 D_80800318_chhotfloorsmoke[56] = {
    0xC, 0x10, 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2D, 0x3,  0xE8, 0x4, 0xB0, 0x0, 0xB,
    0x0, 0x0,  0x0, 0x14, 0x0, 0x0,  0x0, 0x0,  0x60, 0x2,  0x0, 0x22, 0x0, 0x99,
    0x1, 0x0,  0x3, 0x0,  0x3, 0x80, 0x0, 0x15, 0x0,  0x0,  0x0, 0x99, 0x0, 0x2A,
    0x0, 0x0,  0x0, 0xA,  0x1, 0x0,  0x1, 0x80, 0x0,  0xF,  0x0, 0x0,  0x0, 0x0};
u8 D_80800350_chhotfloorsmoke[56] = {
    0x4, 0x10, 0x0, 0x1D, 0x9, 0xDD, 0x0, 0x2D, 0x0,  0x64, 0x0, 0xC8, 0x0, 0xB,
    0x0, 0x0,  0x0, 0x14, 0x0, 0x0,  0x0, 0x0,  0x80, 0x2,  0x0, 0x22, 0x0, 0x99,
    0x1, 0x0,  0x3, 0x0,  0x3, 0x80, 0x0, 0x15, 0x0,  0x0,  0x0, 0x99, 0x0, 0x2A,
    0x0, 0x0,  0x0, 0xA,  0x1, 0x0,  0x1, 0x80, 0x0,  0xF,  0x0, 0x0,  0x0, 0x0};
u8 D_80800388_chhotfloorsmoke[40] = {0x0, 0x13, 0x4, 0xDC, 0x0, 0xD,  0x1, 0x0,  0x1, 0x4C,
                                     0x0, 0x15, 0x0, 0x0,  0x0, 0x80, 0x0, 0x66, 0x0, 0x1,
                                     0x1, 0xF4, 0x9, 0xC4, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0,
                                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0,  0x0, 0x0};
