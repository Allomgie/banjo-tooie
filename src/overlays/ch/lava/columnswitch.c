#include "ch/lavacolumnswitch.h"

extern int D_80800080_chlavacolumnswitch[];

// On message 7 (pressed) plays the columns cutscene.
s32 func_80800000_chlavacolumnswitch(void *this, s32 message)
{
    if (message == 7) {
        _glcutDll_entrypoint_6(0x127, 0x4e);
        return 1 ^ 0;
    }
    return _chswitch_entrypoint_10(this, message);
}

void func_8080003C_chlavacolumnswitch(s32 actor)
{
    _chswitch_entrypoint_7(actor, FLAG_390_UNK);
    _chswitch_entrypoint_9(actor);
}

int chlavacolumnswitch_entrypoint_0()
{
    return &D_80800080_chlavacolumnswitch;
}

extern u8 D_8011A270[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800080_chlavacolumnswitch[20] = {0x343027E,
                                         0x8D60001,
                                         (u32) &D_8011A270,
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
                                         (u32) func_8080003C_chlavacolumnswitch,
                                         (u32) func_80107C2C,
                                         -0x7FF7D3FE,
                                         (u32) func_80800000_chlavacolumnswitch,
                                         0x0,
                                         0x0,
                                         0x0};
