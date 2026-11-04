#include "common.h"

// TU-NOTE: the overlay .data (tables below) is defined in this file because IDO's assembler
// schedules some functions differently unless the tables are in the same unit. Values come
// from the ROM.

extern void *D_808002CC_chfloorbubbles;
extern void *func_80100094(Actor *, s32);
extern f32 func_800DC0C0(void);
extern s32 func_800DC128(s32, s32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern u8 D_80800270_chfloorbubbles[];
typedef struct {
    f32 x;
    f32 yz[2];
} FloorBubblePoint;
extern f32 func_800DC178(f32, f32);
extern void func_800EEB9C(void *, f32, f32);
extern void _subaddie3d_entrypoint_0(void *, f32, f32, void *);
extern void _subaddie3d_entrypoint_1(void *, f32, f32, void *);

// Per frame: 10% chance to release a bubble burst at the current floor point.
void func_80800000_chfloorbubbles(Actor *actor)
{
    f32(*points)[3];
    s32 variant;
    s32 emitter;

    points = func_80100094(actor, 0);
    if (func_800DC0C0() < 0.1f) {
        variant = func_800DC128(0, 5);
        emitter = func_800B53A4(variant);
        func_800BABB8(emitter, points[actor->unk6C_0], NULL, 1.0f, D_80800270_chfloorbubbles);
        func_800BA568(emitter, (s16) ((f32 *) actor->actorData)[1]);
        func_800BA22C(emitter, variant);
        if (func_800DC0C0() < 0.75f) {
            actor->unk6C_0 = func_800DC128(0, 10);
        }
    }
}

// Picks ten random floor points within the radius given by the actor parameter.
void func_8080010C_chfloorbubbles(Actor *actor)
{
    FloorBubblePoint *points;
    s32 i;
    f32 angle;

    points = func_80100094(actor, 0);
    for (i = 0; i < 10; i++) {
        angle = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(&points[i], angle,
                      func_800DC178(0.0f, (f32) (s32) (actor->unk74_7 * 10)));
        func_800EF04C(&points[i], actor->position);
        _subaddie3d_entrypoint_0(&points[i], 100.0f, -100.0f, points[i].yz);
    }
    _subaddie3d_entrypoint_1(actor->position, 500.0f, 0.0f, (u8 *) actor + 0x1C);
}

// Empty stub.
void func_80800244_chfloorbubbles(s32 arg0)
{
}

int chfloorbubbles_entrypoint_0()
{
    return &D_808002CC_chfloorbubbles;
}

extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800270_chfloorbubbles[92] = {
    0x0,  0x1D, 0x9,  0xD9, 0x0, 0x16, 0x10, 0x4,  0x0, 0x2C, 0x0, 0x0,  0x0,  0x32, 0x0,  0x0,
    0x0,  0x0,  0x0,  0x46, 0x0, 0x0,  0x0,  0x1B, 0x0, 0x96, 0x0, 0xC8, 0x0,  0x7,  0x0,  0x1,
    0x0,  0x15, 0x0,  0x0,  0x0, 0xCC, 0x0,  0x2B, 0x1, 0x80, 0x2, 0x80, 0x0,  0xA,  0xFF, 0xF4,
    0xFF, 0x9C, 0xFF, 0xF4, 0x0, 0xC,  0x0,  0x0,  0x0, 0xC,  0x0, 0x20, 0xFF, 0xFF, 0xFE, 0xFF,
    0x0,  0x22, 0x0,  0x1E, 0x0, 0x26, 0x0,  0x14, 0x0, 0x19, 0x0, 0x2F, 0x0,  0x40, 0x0,  0x40,
    0x0,  0x0,  0x0,  0x0,  0x0, 0x19, 0x0,  0x0,  0x0, 0x33, 0x0, 0x0};
// TU-NOTE: one table at 0x808002CC: first word here, remaining words in the static array below.
void *D_808002CC_chfloorbubbles = (void *) 0x020F02AF;
static u32 D_808002CC_chfloorbubbles_rest[20] = {0x6740001,
                                                 0x0,
                                                 (u32) func_80800000_chfloorbubbles,
                                                 (u32) func_80105834,
                                                 (u32) func_8010A730,
                                                 0x9C40000,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 (u32) func_80800244_chfloorbubbles,
                                                 0x0,
                                                 0x780000,
                                                 (u32) func_8080010C_chfloorbubbles,
                                                 (u32) func_80107C2C,
                                                 0x80000602,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0,
                                                 0x0};
