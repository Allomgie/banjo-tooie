#include "common.h"

extern int D_808000B0_chlavafall;
typedef struct { u8 pad_0[0x1A]; u16 local_0 : 11; u16 pad_1 : 5; u8 pad_2[8]; u32 local_1 : 10; u32 pad_3 : 22; } LavaFallPlayer59;

int chlavafall_entrypoint_0()
{
    return (int)&D_808000B0_chlavafall;
}

int func_8080000C_chlavafall(volatile u8 *param_0)
{
  long long new_var;
  int new_var2;
  volatile u8 *new_var3;
  new_var = 0x3D;
  new_var2 = 0x80;
  new_var3 = param_0;
  *((u8 *) (((s8 *) param_0) + 122)) = ((*((u8 *) (((s8 *) new_var3) + 122))) & 0xFF3F) | 0x80;
}

s32 func_80800020_chlavafall(Actor *param_0, s32 param_1, LavaFallPlayer59 *param_2)
{
    LavaFallPlayer59 *local_0;

    switch (param_1) {
    case 0x3E:
        local_0 = *(LavaFallPlayer59 **)&param_2;
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
