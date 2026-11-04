// Probably a Hailfire Peaks falling-lava hazard: on touch (message 0x3E) it sends the player
// lava-damage interrupt 4 unless invulnerable.
#include "common.h"

extern int D_808000B0_chlavafall[];

typedef struct {
    u8 pad_0[0x1A];
    u16 unk_1A : 11;
    u16 pad_1 : 5;
    u8 pad_2[8];
    u32 unk_24 : 10;
    u32 pad_3 : 22;
} LavaFallPlayer59;

int chlavafall_entrypoint_0()
{
    return (int) &D_808000B0_chlavafall;
}

// Sets a draw/flag bit.
int func_8080000C_chlavafall(volatile u8 *actor)
{
    volatile u8 *actor_alias;
    actor_alias = actor;
    *(u8 *) ((s8 *) actor + 122) = (*(u8 *) ((s8 *) actor_alias + 122) & 0xFF3F) | 0x80;
}

// Handles message 0x3E: lava damage to a vulnerable player.
s32 func_80800020_chlavafall(Actor *actor, s32 message, LavaFallPlayer59 *data)
{
    LavaFallPlayer59 *msg;

    switch (message) {
        case 0x3E:
            msg = *(LavaFallPlayer59 **) &data;
            if (!msg->unk_24) {
                if (!func_800F6AA4(msg->unk_1A)) {
                    func_800F79DC(msg->unk_1A, 4, actor->unk0);
                }
            }
            break;
        default:
            return 0;
    }
    return 1;
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000B0_chlavafall[20] = {0x3090502,
                                 0x9460001,
                                 0x0,
                                 (u32) func_80102EC0,
                                 (u32) func_80102EC0,
                                 (u32) func_80101870,
                                 0x1B58,
                                 0x0,
                                 0x0,
                                 0x21400,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 (u32) func_8080000C_chlavafall,
                                 (u32) func_80107C2C,
                                 -0x7FFFF400,
                                 (u32) func_80800020_chlavafall,
                                 0x0,
                                 0x0,
                                 0x0};
