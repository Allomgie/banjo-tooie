#include "common.h"

extern u32 D_80800290_chrainripples[];
extern void func_800EE7F8(f32 *, f32 *);
extern s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, void *);
extern s32 D_808002D8_chrainripples[];
extern f32 func_800D8FF8(void);
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
f32 func_808001FC_chrainripples();

char *chrainripples_entrypoint_0()
{
    return &D_80800290_chrainripples;
}

// Stores the ray-cast height plus 4 in the actor data.
void func_8080000C_chrainripples(u8 *actor)
{
    *(f32 *) (actor + 0x2C) = func_808001FC_chrainripples(actor) + 4.0f;
}

// While it rains, spawns ripples at the placed points, cycling through the point list.
void func_80800040_chrainripples(Actor *actor)
{
    s32 weather;
    s32 count;
    s32 point_count;
    s32 emitter;
    s32 i;
    u8 *point;
    f32 pos[3];
    f32 tmp;
    weather = func_800B7C98();
    if (weather && _fxrain_entrypoint_3(weather)) {
        tmp = func_800D8FF8();
        count = (s32) ((f32) actor->unk74_7 * tmp);
        point_count = func_800CC5F4((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1);
        emitter = 0;
        if (count)
            emitter = func_800B5BE4(3);
        for (i = 0; i < count; i++) {
            point = (u8 *) func_800CC63C((*(u32 *) ((u8 *) actor + 0x70) >> 25) - 1,
                                         actor->actorData[4]);
            func_800EE7F8(pos, point);
            tmp = func_800DC178(0.0f, 359.0f);
            func_800EF1B8(pos, tmp, func_800DC178(0.0f, *(s16 *) (point + 0xC)));
            pos[1] = ((f32 *) actor->actorData)[5];
            func_800BABB8(emitter, pos, 0, 1.0f, &D_808002D8_chrainripples);
            actor->actorData[4]++;
            if ((s32) actor->actorData[4] >= point_count)
                actor->actorData[4] = 0;
        }
    }
}

// Ray cast from 100 above to 100 below the actor; falls back to the actor's height.
f32 func_808001FC_chrainripples(actor)
Actor *actor;
{
    f32 start[3];
    f32 end[3];
    f32 hit[3];
    func_800EE7F8(start, actor->position);
    func_800EE7F8(end, actor->position);
    start[1] += 100.0f;
    end[1] -= 100.0f;
    if (func_800BEF00(start, end, hit, 0x1F00)) {
        return end[1];
    }
    return actor->position[1];
}

// TU-NOTE: .data of this overlay is defined here in C; its tables point to functions of this file.
// IDO's assembler schedules some of them differently otherwise. Values are taken from the ROM.
// D_80800290_chrainripples is declared as u32[] and D_808002D8_chrainripples as s32[] to match the object.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800290_chrainripples[18] = {0xA503DF,
                                    0x1,
                                    0x0,
                                    (u32) func_80800040_chrainripples,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x13880000,
                                    0x0,
                                    0x0,
                                    0x1,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chrainripples,
                                    (u32) func_80107C2C,
                                    0x80000602,
                                    0x0,
                                    0x0};
s32 D_808002D8_chrainripples[10] = {0x1D09DB, 0x161201, 0x2B00CC,  0x1000015, 0x80,
                                    0x220019, 0x190099, 0x100001F, -0x200,    0x11A0000};
