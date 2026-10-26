#include "common.h"

typedef union OverworldMoleEvent { s32 local_0; s16 local_1[2]; } OverworldMoleEvent;
extern s32 D_808001E0_chmole_overworld[];
extern u8 D_80800190_chmole_overworld[];
extern void _sumole_entrypoint_4(s32, void *);
extern int D_808001F0_chmole_overworld;

s32 func_80800000_chmole_overworld(Actor *param_0, s32 param_1, OverworldMoleEvent param_2)
{
    switch (param_1) {
        case 0x2F:
            if (param_2.local_1[1] == 3) {
                func_800D175C(D_808001E0_chmole_overworld[(s32)param_0->unk54], func_800D1A6C(D_808001E0_chmole_overworld[(s32)param_0->unk54]) - func_800D1A04(D_808001E0_chmole_overworld[(s32)param_0->unk54]));
                break;
            }
            return _sumole_entrypoint_3(param_0, param_1, param_2.local_0, D_80800190_chmole_overworld);
        default:
            return _sumole_entrypoint_3(param_0, param_1, param_2.local_0, D_80800190_chmole_overworld);
    }
    return 1;
}

void func_808000F4_chmole_overworld(Actor* arg0) 
{
    _sumole_entrypoint_0(arg0, 0);
    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->unk54 = arg0->unk74_7;
}
void func_80800160_chmole_overworld(s32 param_0) {
    _sumole_entrypoint_4(param_0, ((s32 *) D_80800190_chmole_overworld));
}

int chmole_overworld_entrypoint_0()
{
    return (int)&D_808001F0_chmole_overworld;
}
