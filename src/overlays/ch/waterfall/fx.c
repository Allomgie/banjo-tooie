#include "common.h"

extern void *D_80800410_chwaterfallfx;
extern u8 D_80800458_chwaterfallfx[];
extern void func_800EF334(f32 *, f32);
extern void func_800F22B4(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern u8 D_80800478_chwaterfallfx[];
extern f32 func_800D8FF8(void);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800DC178(f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
void func_808001F8_chwaterfallfx();

int chwaterfallfx_entrypoint_0()
{
    return &D_80800410_chwaterfallfx;
}

// Init: builds the line segment (actorData[0..7]) along the yaw and derives the spawn rate.
void func_8080000C_chwaterfallfx(Actor *actor)
{
    f32 unk_0[2];
    f32 unk_1[2];
    f32 dir[3];
    f32 length;

    func_800F22B4(unk_0, actor->rotation[1]);
    func_800F23AC(unk_1, unk_0);
    func_800EE8E8(dir, unk_1);
    func_800EF334(dir, (f32) actor->unk74_7);
    func_800EE780((u8 *) actor + 0x28, actor->position, dir);
    func_800EFB24(actor->actorData, actor->position, dir);
    length = func_800EEAD4((f32 *) ((u8 *) actor + 0x28), (f32 *) actor->actorData);
    *(f32 *) ((u8 *) actor + 0x34) = 0.6f * length;
    *(s32 *) ((u8 *) actor + 0x54) = 0;
    actor->unk64_20 = *(u32 *) ((u8 *) actor + 0x70) & 1;
    ((u8 *) actor)[0x73] &= ~1;
    *(s32 *) ((u8 *) actor + 0x24) = (s32) (length / 25.0f + 8.0f);
    actor->unk58 = 0.0f;
    actor->unk50 = *(s32 *) ((u8 *) actor + 0x24) * 1.5f;
}

void func_80800148_chwaterfallfx(Actor *actor)
{
    _subaddieaudioloop_entrypoint_5(actor, (u8 *) actor + 4, 1, 0xC80,
                                    &D_80800458_chwaterfallfx);
    if (actor->unk5F != 0) {
        if (!actor->unk64_19) {
            func_800C3058(actor->unk5F, 0x2AF8);
            actor->unk64_19 = 1;
        }
    } else {
        actor->unk64_19 = 0;
    }
    if (!actor->unk64_20) {
        func_808001F8_chwaterfallfx(actor);
    }
}

s32 func_808001E4_chwaterfallfx(s32 arg0, s32 arg1, s32 arg2)
{
    return 0;
}

// Spawns falling-water particles along the segment while the camera is near and the actor is visible.
void func_808001F8_chwaterfallfx(actor) Actor *actor;
{
    f32 cam_pos[3];
    s32 i;
    s32 count;
    s32 emitter;
    f32 velocity[3];
    f32 spawn_pos[3];

    func_800E3980(cam_pos);
    if (func_800EEB40(actor->position, cam_pos) < 25000000.0f &&
        func_800E3E8C(actor->position, actor->actorData[7])) {
        emitter = func_800B5BE4(0x23);
        count = 0;
        actor->unk58 += actor->unk50 * func_800D8FF8();
        while (actor->unk58 >= 1.0f) {
            count++;
            actor->unk58 -= 1.0f;
        }
        for (i = 0; i < count; i++) {
            func_800EFE50(spawn_pos, (f32 *) &actor->actorData[4], (f32 *) actor->actorData,
                          func_800DC178(0.0f, 1.0f));
            func_800EE7F8(velocity, spawn_pos);
            func_800EF1B8(velocity, actor->rotation[1], -100.0f);
            velocity[1] += 100.0f;
            func_800BABB8(emitter, spawn_pos, velocity, actor->scale * 1.15f,
                          D_80800478_chwaterfallfx);
            (*(s32 *) &actor->unk54)++;
            if (*(s32 *) &actor->unk54 >= (s32) actor->actorData[3]) {
                *(s32 *) &actor->unk54 = 0;
            }
        }
    }
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions
// of this file; IDO's assembler schedules some of these functions differently unless the tables
// are defined in the same unit. Values are taken from the ROM.
extern void func_80102EC0();
extern void func_8010A730();
extern void func_80107C2C();
void *D_80800410_chwaterfallfx = (void *) 0x015801BB;
static u32 D_80800410_chwaterfallfx_rest[17] = {0x1,
                                                0x0,
                                                (u32) func_80800148_chwaterfallfx,
                                                (u32) func_80102EC0,
                                                (u32) func_8010A730,
                                                0x17700000,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                0x0,
                                                (u32) func_8080000C_chwaterfallfx,
                                                (u32) func_80107C2C,
                                                0x80000602,
                                                (u32) func_808001E4_chwaterfallfx,
                                                0x0};
u8 D_80800458_chwaterfallfx[32] = {0x0,  0x13, 0x3, 0xEC, 0x0,  0x1,  0x1, 0x90, 0xC,  0x80, 0x0,
                                   0x1A, 0x1,  0x0, 0x0,  0x80, 0x0,  0xE, 0x0,  0xC0, 0x0,  0xD9,
                                   0x0,  0x26, 0x0, 0x16, 0x2A, 0xF8, 0x0, 0x0,  0x0,  0x0};
u8 D_80800478_chwaterfallfx[72] = {
    0x0,  0x1D, 0x9,  0xDD, 0x0,  0x1B, 0x1,  0xC2, 0x2,  0x26, 0x0,  0x2D, 0x0,  0xC8, 0x0,
    0xFA, 0x0,  0xE,  0x0,  0xF,  0x0,  0x14, 0x0,  0x16, 0x6,  0x0,  0x0,  0x32, 0x0,  0x0,
    0x0,  0x33, 0x0,  0x2,  0x0,  0x27, 0xFF, 0x9C, 0xFF, 0x9C, 0x0,  0x64, 0x0,  0x64, 0x0,
    0x22, 0x0,  0x91, 0x0,  0xAB, 0x0,  0xF8, 0x1,  0xF,  0x0,  0x15, 0x0,  0xC,  0x0,  0xA6,
    0x0,  0x2B, 0x0,  0x99, 0x0,  0xB3, 0x80, 0x2,  0x1,  0x1A, 0x0,  0x0};
