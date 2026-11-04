#include "common.h"

extern s32 _plsu_entrypoint_3(void *);
extern s32 func_800D90A4(f32 *);
extern void func_800C3F48(s32);
extern int D_808000A0_chjellycastle[];

// Plays a squelch sound when the player lands on the castle (0.5 s cooldown).
void func_80800000_chjellycastle(Actor *actor)
{
    s32 unk_0;

    unk_0 = _plsu_entrypoint_3(actor->unk0);
    if (!unk_0 && func_800D90A4(&actor->unk58) && !actor->unk64_20) {
        func_800C3F48(0x599C5699);
        actor->unk58 = 0.5f;
    }
    actor->unk64_20 = !unk_0;
}

int chjellycastle_entrypoint_0()
{
    return (int) &D_808000A0_chjellycastle;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
int D_808000A0_chjellycastle[20] = {0x158050C,
                                    0x92D0001,
                                    0x0,
                                    (u32) func_80800000_chjellycastle,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x7D00000,
                                    0x0,
                                    0x0,
                                    0x21C08,
                                    0x0,
                                    (u32) func_80108ED0,
                                    0x0,
                                    0x0,
                                    (u32) func_80107C2C,
                                    -0x7FFFDBFE,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0};
