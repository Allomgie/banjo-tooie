// Probably the destructible grill in the Witchyworld castle pump room: when hit it is blown back,
// and when destroyed it plays a sound and sets flag 0x162.

#include "common.h"

extern int D_808000E0_chpumproomgrill[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern u8 D_80800128_chpumproomgrill[];
extern void _subaddieaudioquick_entrypoint_2();
extern void func_800DA544(s32);
void func_808000AC_chpumproomgrill();

void *chpumproomgrill_entrypoint_0()
{
    return (void *) &D_808000E0_chpumproomgrill;
}

void func_8080000C_chpumproomgrill(s32 unk_0)
{
}

// Message 0x40: blown back by the exploder; 0x90: destroyed.
s32 func_80800014_chpumproomgrill(Actor *actor, s32 msg, s32 data)
{
    f32 pos[3];
    switch (msg) {
        case 0x40:
            func_800EE7F8(pos, actor->position);
            func_800EF1B8(pos, actor->rotation[1], -400.0f);
            _chexploder_entrypoint_3(actor, pos, 0xF);
            break;
        case 0x90:
            func_808000AC_chpumproomgrill(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808000AC_chpumproomgrill(actor) u8 *actor;
{
    // Destroyed: play sound, set flag 0x162.
    _subaddieaudioquick_entrypoint_2(actor, actor + 4, D_80800128_chpumproomgrill);
    func_800DA544(0x162);
}

extern void func_80102EC0();
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
extern void _bsbtrot_entrypoint_10();
int D_808000E0_chpumproomgrill[18] = {0x19B034A,
                                      0x8810001,
                                      0x0,
                                      (u32) func_80102EC0,
                                      (u32) func_80105834,
                                      (u32) func_80101870,
                                      0x0,
                                      0x0,
                                      0x1620000,
                                      0x40020C00,
                                      0x0,
                                      (u32) func_80108ED0,
                                      0x0,
                                      (u32) func_8080000C_chpumproomgrill,
                                      (u32) func_80107C2C,
                                      (u32) _bsbtrot_entrypoint_10,
                                      (u32) func_80800014_chpumproomgrill,
                                      0x0};
u8 D_80800128_chpumproomgrill[24] = {0x0, 0x13, 0x4, 0xA0, 0x0, 0xA, 0x0, 0xE6,
                                     0x0, 0x18, 0x0, 0x0,  0x0, 0x0, 0x0, 0x0,
                                     0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
