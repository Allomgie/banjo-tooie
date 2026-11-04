#include "common.h"

extern void *D_80800438_chfactoryworkerwear;
extern f32 D_80800480_chfactoryworkerwear[];
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);
extern f32 func_800F1214(f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_80013970(f32);
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern u8 *func_80100094(s32, s32);
extern void func_80101038();
extern f32 func_80101068(void);
extern f32 func_800136E4(f32);

void *chfactoryworkerwear_entrypoint_0()
{
    return &D_80800438_chfactoryworkerwear;
}

void func_8080000C_chfactoryworkerwear(actor, mode) Actor *actor;
s32 mode;
{
    u8 *state;

    state = func_80100094(actor, 0);
    switch (mode) {
        case 2:
            *(f32 *) state = actor->scale;
            func_800EE7F8((f32 *) (state + 4), actor->position);
            func_8010A800(actor, 1);
            break;
        case 3:
            func_800EE7F8(actor->position, (f32 *) (state + 0x10));
            actor->rotation[1] = func_800136E4(actor->rotation[1] + 180.0f);
            actor->scale = 1.0f;
            break;
        case 4:
            actor->rotation[2] = 0.0f;
            actor->scale = 0.4f;
            func_801032B0(actor, 0x83C, actor->unk0->unk16);
    }
    func_80102424(actor, mode);
}

// Despawn handler: clears the stage byte.
void func_80800100_chfactoryworkerwear(s32 actor)
{
    *(u8 *) (func_80100094(actor, 0) + 0x24) = 0;
}

void func_80800124_chfactoryworkerwear(s32 arg0)
{
}

void func_8080012C_chfactoryworkerwear(Actor *actor)
{
    u8 *state;

    state = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            func_800EFE50(actor->position, (f32 *) (state + 4), (f32 *) (state + 0x10),
                          *(f32 *) (state + 0x1C));
            actor->scale = func_800F1214(*(f32 *) (state + 0x1C), *(f32 *) state, 0.4f);
            break;
        case 3:
            actor->rotation[2] += *(f32 *) (state + 0x20) * func_800D8FF8();
            break;
        case 4:
            func_800BBCB8(actor->position, 0, 1.0f, 5, D_80800480_chfactoryworkerwear);
            func_800EFE50(actor->position, (f32 *) (state + 4), (f32 *) (state + 0x10),
                          *(f32 *) (state + 0x1C));
            actor->position[1] += func_80013970(*(f32 *) (state + 0x1C) * 180.0f) * 30.0f;
            actor->scale = func_800F1214(*(f32 *) (state + 0x1C), *(f32 *) state, 0.4f);
    }
}

int func_80800260_chfactoryworkerwear(Actor *actor, s32 sub_cmd)
{
    Actor *state;
    state = func_80100094(actor, 0);
    *(u8 *) ((char *) state + 0x24) = sub_cmd;
    switch (sub_cmd) {
        case 1:
            func_8080000C_chfactoryworkerwear(actor, 2);
            return;
        case 2:
            func_8080000C_chfactoryworkerwear(actor, 3);
            return;
        case 3:
            func_8080000C_chfactoryworkerwear(actor, 4);
    }
}

void func_808002E4_chfactoryworkerwear(s32 actor)
{
    u8 *state = func_80100094(actor, 0);
    func_80101038(state + 0x10);
    *(f32 *) (state + 0x1C) = func_80101068();
}

void func_80800320_chfactoryworkerwear(s32 actor)
{
    u8 *state = func_80100094(actor, 0);
    *(f32 *) (state + 0x20) = func_80101068();
}

// Messages from the owning skivvy: 0x21 steers the clothing, 0x2C despawns it.
int func_80800350_chfactoryworkerwear(Actor *actor, s32 msg, s32 payload)
{
    switch (msg) {
        case 0x21:
            switch (((s16 *) &payload)[0]) {
                case 1:
                    func_80800260_chfactoryworkerwear(actor, ((s16 *) &payload)[1]);
                    break;
                case 2:
                    func_80800320_chfactoryworkerwear(actor);
                    break;
                case 3:
                    func_808002E4_chfactoryworkerwear(actor);
                    break;
            }
            break;
        case 0x2C:
            func_800FFA88(actor->unk0);
    }
    return 0;
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to functions
// of this file; IDO's assembler schedules some of these functions differently unless the tables
// are defined in the same unit. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800410_chfactoryworkerwear[10] = {0x0,       0x0,        0x3ECCCCCD, 0x35D0001,  0x3ECCCCCD,
                                          0x2A00001, 0x3F19999A, 0x2A10001,  0x3ECCCCCD, 0x2A00001};
void *D_80800438_chfactoryworkerwear = (void *) 0x027E0239;
static u32 D_80800438_chfactoryworkerwear_rest[17] = {0x83D0001,
                                                      (u32) &D_80800410_chfactoryworkerwear,
                                                      (u32) func_8080012C_chfactoryworkerwear,
                                                      (u32) func_80105834,
                                                      (u32) func_80101870,
                                                      0x0,
                                                      0x3F800000,
                                                      0x0,
                                                      0x40000120,
                                                      (u32) func_80800124_chfactoryworkerwear,
                                                      0x0,
                                                      0x280000,
                                                      (u32) func_80800100_chfactoryworkerwear,
                                                      (u32) func_80107C2C,
                                                      0x80002412,
                                                      (u32) func_80800350_chfactoryworkerwear,
                                                      0x0};
f32 D_80800480_chfactoryworkerwear[12] = {
    2.666786e-39f,  1.928617e-39f, 1.1754963e-38f, 4.591859e-39f, 3.581584e-39f, 1.8367099e-38f,
    2.2958924e-38f, 3.214291e-39f, 3.397927e-39f,  9.18415e-40f,  6.979604e-39f, 0.0f};
