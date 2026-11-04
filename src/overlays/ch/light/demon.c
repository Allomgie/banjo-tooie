// Possibly small light-carrying actors: one follows a spline path at speed 650 and moves a point
// light with it; another checks a player state bit and then sends the player interrupt 3.
#include "common.h"

extern void *D_80800140_chlightdemon;
typedef union {
    s32 value;
    void *ptr;
} LightDemonEvent;
extern u8 D_80800194_chlightdemon[];
extern u8 D_80800188_chlightdemon[];
extern void func_800C8D4C(s32, void *);
extern void func_800C8CB8();
extern void func_800C8E84(s32, void *);
extern void *D_8080019C_chlightdemon;

int chlightdemon_entrypoint_0()
{
    return &D_80800140_chlightdemon;
}

// Follows the path, then moves the point light to the actor.
void func_8080000C_chlightdemon(u8 *actor)
{
    func_80105834();
    func_800C8CB8(*(s32 *) ((s8 *) actor + 0x28), actor + 4, actor);
}

// Path speed is 650.0f.
void func_8080003C_chlightdemon(s32 actor)
{
    func_80105A9C(actor, 0x44228000);
}

// Message 0x95 creates the point light.
s32 func_80800060_chlightdemon(Actor *actor, s32 msg, LightDemonEvent event)
{
    if (msg == 0x95) {
        actor->actorData[4] = func_800C8A98();
        func_800C8D4C(actor->actorData[4], D_80800194_chlightdemon);
        func_800C8CB8(actor->actorData[4], actor->position);
        func_800C8E84(actor->actorData[4], D_80800188_chlightdemon);
        return 1;
    }
    return 0;
}

// Sends player interrupt 3 when a player state bit is set.
int func_808000D8_chlightdemon(s32 actor)
{
    s32 player;
    s32 state;
    player = func_800F54E4();
    state = func_800F581C(player);
    if ((state << 4) < 0) {
        func_800F796C(player, 3);
    }
}

int chlightdemon_entrypoint_1()
{
    return &D_8080019C_chlightdemon;
}

// TU-NOTE: the overlay's .data is defined here in C; its tables point to functions of this
// file, and IDO's assembler schedules them differently otherwise. Values taken from the ROM.
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
extern void func_8010A730();
u32 D_80800130_chlightdemon[4] = {0x0, 0x0, 0x3F19999A, 0x1130000};
void *D_80800140_chlightdemon = (void *) 0x019E012D;
static u32 D_80800140_chlightdemon_rest[17] = {0x6BE0001,
                                               (u32) &D_80800130_chlightdemon,
                                               (u32) func_80102EC0,
                                               (u32) func_8080000C_chlightdemon,
                                               (u32) func_80101870,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x21500,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_8080003C_chlightdemon,
                                               (u32) func_80107C2C,
                                               0x80000402,
                                               (u32) func_80800060_chlightdemon,
                                               0x0};
u8 D_80800188_chlightdemon[12] = {0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0xFF, 0x0, 0x0, 0x0, 0x40};
u8 D_80800194_chlightdemon[8] = {0x43, 0xFA, 0x0, 0x0, 0x44, 0xDA, 0xC0, 0x0};
void *D_8080019C_chlightdemon = (void *) 0x015801E0;
static u32 D_8080019C_chlightdemon_rest[20] = {0x1,
                                               0x0,
                                               (u32) func_808000D8_chlightdemon,
                                               (u32) func_80102EC0,
                                               (u32) func_8010A730,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               (u32) func_80107C2C,
                                               0x80002602,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0,
                                               0x0};
