#include "common.h"

extern int D_808000B0_chlavafall[];

typedef struct {
    u8 pad_0[0x1A];
    u16 local_0 : 11;
    u16 pad_1 : 5;
    u8 pad_2[8];
    u32 local_1 : 10;
    u32 pad_3 : 22;
} LavaFallPlayer59;

int chlavafall_entrypoint_0()
{
    return (int) &D_808000B0_chlavafall;
}

int func_8080000C_chlavafall(volatile u8 *param_0)
{
    volatile u8 *new_var3;
    new_var3 = param_0;
    *(u8 *) ((s8 *) param_0 + 122) = (*(u8 *) ((s8 *) new_var3 + 122) & 0xFF3F) | 0x80;
}

s32 func_80800020_chlavafall(Actor *param_0, s32 param_1, LavaFallPlayer59 *param_2)
{
    LavaFallPlayer59 *local_0;

    switch (param_1) {
        case 0x3E:
            local_0 = *(LavaFallPlayer59 **) &param_2;
            if (!local_0->local_1) {
                if (!func_800F6AA4(local_0->local_0)) {
                    func_800F79DC(local_0->local_0, 4, param_0->unk0);
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
