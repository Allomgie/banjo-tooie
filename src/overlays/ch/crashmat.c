// Probably a crash mat: plays a sound once when the main player steps onto it (0.5 s cooldown).
#include "common.h"

extern s32 _plsu_entrypoint_3(void *);
extern s32 func_800D90A4(f32 *);
extern void func_800C3F48(s32);
extern int D_808000A0_chcrashmat[];

// Plays a sound when the main player steps on the mat; 0.5 s cooldown
void func_80800000_chcrashmat(Actor *actor)
{
    s32 standing_player;

    standing_player = _plsu_entrypoint_3(actor->unk0);
    if (!standing_player && func_800D90A4(&actor->unk58) && !actor->unk64_20) {
        func_800C3F48(0x599C5699);
        actor->unk58 = 0.5f;
    }
    actor->unk64_20 = !standing_player;
}

int chcrashmat_entrypoint_0()
{
    return (int) &D_808000A0_chcrashmat;
}

// TU-NOTE: the data table below is defined in this file because it points to its
// functions; IDO schedules those differently otherwise. Values are from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000A0_chcrashmat[20] = {0x158050B,
                                 0x92B0001,
                                 0x0,
                                 (u32) func_80800000_chcrashmat,
                                 (u32) func_80105834,
                                 (u32) func_80101870,
                                 0x3E80000,
                                 0x0,
                                 0x0,
                                 0x21C08,
                                 0x0,
                                 (u32) func_80108ED0,
                                 0x0,
                                 0x0,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBFE,
                                 0x0,
                                 0x0,
                                 0x0,
                                 0x0};
