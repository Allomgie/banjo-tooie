#include "ch/minelightswitch.h"

extern s32 _chswitch_entrypoint_10(Actor *, s32, s32);
extern void *D_808000C0_chminelightswitch;

// Plays cutscene 0x15 on switch press/release; the first time also sets FLAG2_673.
s32 func_80800000_chminelightswitch(Actor *actor, s32 msg, s32 data)
{
    switch (msg) {
        case 7:
            if (!func_800DA298(0x673))
                _glcutDll_entrypoint_6(0xCF, 0x15);
            break;
        case 8:
            if (!func_800DA298(0x673)) {
                func_800DA544(0x673);
                _glcutDll_entrypoint_6(0xCF, 0x15);
            }
            break;
        default:
            return _chswitch_entrypoint_10(actor, msg, data);
    }
    return 1;
}

void func_80800094_chminelightswitch(s32 arg0)
{
    _chswitch_entrypoint_7(arg0, FLAG3_9E0_UNK);
}

int chminelightswitch_entrypoint_0()
{
    return &D_808000C0_chminelightswitch;
}

extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
void *D_808000C0_chminelightswitch = (void *) 0x02C70302;
static u32 D_808000C0_chminelightswitch_rest[19] = {0x6A70001,
                                                    (u32) &D_8011A248,
                                                    (u32) _chswitch_entrypoint_6,
                                                    (u32) func_80105834,
                                                    (u32) func_80101870,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    0x808,
                                                    0x0,
                                                    0x0,
                                                    0x0,
                                                    (u32) func_80800094_chminelightswitch,
                                                    (u32) func_80107C2C,
                                                    0x80002C02,
                                                    (u32) func_80800000_chminelightswitch,
                                                    0x0,
                                                    0x0,
                                                    0x0};
