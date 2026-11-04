#include "common.h"

extern int D_80800130_chklungoleave[];
extern s32 D_80800178_chklungoleave[];

int chklungoleave_entrypoint_0()
{
    return (int) &D_80800130_chklungoleave;
}

int func_8080000C_chklungoleave(s32 actor)
{
    // Walking speed 300.0f.
    func_80105A9C(actor, 0x43960000);
    func_80105BAC(actor);
}

void func_808000F0_chklungoleave();

void func_80800038_chklungoleave(s32 actor)
{
    func_80105834();
    func_808000F0_chklungoleave(actor);
}

s32 func_80800060_chklungoleave(Actor *actor, s32 msg, s32 unused)
{
    switch (msg) {
        case 0x95:
            // Cutscene 0x5B: Klungo speaks, camera pod follows. Otherwise delete the actor.
            if (_glcutDll_entrypoint_19(0x5B)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x162E, 0x44, actor->position, 0xAB);
                _capod_entrypoint_13(actor->unk0, 0, 6, 0x2911);
                break;
            }
            func_800FFAB0(actor);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808000F0_chklungoleave(s32 actor)
{
    func_80105230(actor, &D_80800178_chklungoleave);
}

extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
u32 D_80800120_chklungoleave[4] = {0x0, 0x0, 0x3F333333, 0x2640001};
int D_80800130_chklungoleave[18] = {0x1580323,
                                    0x90D0001,
                                    (u32) &D_80800120_chklungoleave,
                                    (u32) func_80102EC0,
                                    (u32) func_80800038_chklungoleave,
                                    (u32) func_80101870,
                                    0x0,
                                    0x40000000,
                                    0x0,
                                    0x40100,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_8080000C_chklungoleave,
                                    (u32) func_80107C2C,
                                    -0x7FFFFBFE,
                                    (u32) func_80800060_chklungoleave,
                                    0x0};
s32 D_80800178_chklungoleave[6] = {0x0, 0x3F000000, -0x40800000, 0x0, 0x0, 0x0};
