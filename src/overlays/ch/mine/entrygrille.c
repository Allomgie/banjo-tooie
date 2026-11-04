#include "ch/mineentrygrill.h"

extern s32 D_80800140_chmineentrygrille[];
extern u32 D_80800180_chmineentrygrille[];
extern u32 D_80800194_chmineentrygrille[];

// TU-NOTE: .data is defined in this C file; IDO schedules the functions differently otherwise.

// Message handler: 7 and 0x90 make the grille explode.
s32 func_80800000_chmineentrygrille(Actor *actor, s32 msg, u32 unk_2)
{
    Actor *exploder;

    switch (msg) {
        case 0x7:
            _chexploder_entrypoint_3(actor, actor->position, 8);
            func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
            return 1;
        case 0x90:
            exploder = func_80106790(func_80101080());
            _chexploder_entrypoint_13(exploder, 6);
            _chexploder_entrypoint_15(exploder, 2, 1.0f);

            func_800BABB8(0, actor->position, actor->position, actor->scale,
                          D_80800140_chmineentrygrille);
            func_800C4AF0(actor->position, &D_80800180_chmineentrygrille);
            return 1;
        default:
            return 0;
    }
}

// Init: removes the grille once the world is open.
void func_808000C4_chmineentrygrille(s32 actor)
{
    if (_sujiggy_entrypoint_20(1) != 0) {
        func_800DA544(FLAG_393_PROGRESS_OPENED_WORLD_GGM);
        func_800FFAB0(actor);
        return;
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7B) == 0)) {
        func_800FFAB0(actor);
    }
}

void *chmineentrygrille_entrypoint_0(void)
{
    return &D_80800194_chmineentrygrille;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800140_chmineentrygrille[16] = {
    0x610001D, 0x9DD002B, 0x2000300, 0x220180,   0x2000480, 0x6000015, 0x26,     0x190000,
    0x7002D,   0x320064,  0x20DEA7,  0x71C0000A, -0x63FFE7, -0x63FF9C, 0x4B0064, 0x61A0000};
u32 D_80800180_chmineentrygrille[5] = {0x130413, 0xA00E6, 0x166D60, 0x11964, 0x19640000};
u32 D_80800194_chmineentrygrille[19] = {0xAC0393,
                                        0x9690001,
                                        0x0,
                                        0x0,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x3930000,
                                        0x20C00,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_808000C4_chmineentrygrille,
                                        (u32) func_80107C2C,
                                        0x80002802,
                                        (u32) func_80800000_chmineentrygrille,
                                        0x0,
                                        0x0};
