#include "common.h"

typedef struct { u8 id; u8 pad[15]; } ReactEnt;
extern ReactEnt D_808000B0_bareact[];

s32 bareact_entrypoint_0() 
{
    return 0x4;
}

void bareact_entrypoint_1(u8 *param_0, s32 param_1) {
    s32 i;
    for (i = 0; D_808000B0_bareact[i].id != 0; i++) {
        if (param_1 == D_808000B0_bareact[i].id) {
            **(ReactEnt ***)(param_0 + 0xEC) = &D_808000B0_bareact[i];
            return;
        }
    }
}

u8 bareact_entrypoint_2(u8 *param_0) {
    return (*(u8 *)((s8 *)(*(*(u8 ***)((s8 *)(param_0) + (0xEC)))) + (1)));
}

f32 bareact_entrypoint_3(Actor *param_0)
{
  return ((f32 *)(*(s32 *)(*(s32 **)((char *)param_0 + 0xEC))))[1];
}

f32 bareact_entrypoint_4(u8 *param_0) {
    return (*(f32 *)((s8 *)(*(*(u8 ***)((s8 *)(param_0) + (0xEC)))) + (0xC)));
}

f32 bareact_entrypoint_5(u8 *param_0) {
    return (*(f32 *)((s8 *)(*(*(u8 ***)((s8 *)(param_0) + (0xEC)))) + (8)));
}
