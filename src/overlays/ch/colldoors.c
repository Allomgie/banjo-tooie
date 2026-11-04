#include "common.h"

extern s32 D_80800270_chcolldoors[];
extern f32 func_800D8FF8(void);
extern void *D_80800280_chcolldoors;

// Variant 0x33/0x34/0x35 watches flags 0x577/0x368/0x369; starts open if already set.
void func_80800000_chcolldoors(Actor *actor)
{
    s32 flag_set;

    switch (actor->unk74_7) {
        case 0x33:
            flag_set = func_800DA298(0x577);
            break;
        case 0x34:
            flag_set = func_800DA298(0x368);
            break;
        case 0x35:
            flag_set = func_800DA298(0x369);
    }
    if (flag_set) {
        actor->unk70_10 = 3;
        actor->position[1] += 250.0f;
    }
}

// Waits 1.5 s after the flag is set, unlocks the frontend entry, then slides up 250 units.
void func_808000B8_chcolldoors(Actor *actor)
{
    s32 flag_set;

    switch (actor->unk70_10) {
        case 1:
            flag_set = 0;
            switch (actor->unk74_7) {
                case 0x33:
                    flag_set = func_800DA298(0x577);
                    actor->unk58 = 1.5f;
                    _gcfrontend_entrypoint_9(0x6E);
                    break;
                case 0x34:
                    flag_set = func_800DA298(0x368);
                    actor->unk58 = 1.5f;
                    _gcfrontend_entrypoint_9(0x6F);
                    break;
                case 0x35:
                    flag_set = func_800DA298(0x369);
                    actor->unk58 = 1.5f;
                    _gcfrontend_entrypoint_9(0x70);
            }
            if (flag_set) {
                actor->unk70_10 = 2;
                *(f32 *) &actor->actorData[1] = actor->position[1] + 250.0f;
            }
            break;
        case 2:
            if (actor->unk58 <= 0.0f) {
                _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                                &D_80800270_chcolldoors);
                if (actor->position[1] < *(f32 *) &actor->actorData[1]) {
                    actor->position[1] += 150.0f * func_800D8FF8();
                } else {
                    actor->unk70_10 = 3;
                }
            } else {
                actor->unk58 -= func_800D8FF8();
            }
    }
}

int chcolldoors_entrypoint_0()
{
    return &D_80800280_chcolldoors;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800270_chcolldoors[4] = {0x1304AD, 0x1661A8, 0x100FA, 0xA8C0000};
void *D_80800280_chcolldoors = (void *) 0x00AC01A4;
static u32 D_80800280_chcolldoors_rest[19] = {0x95A0001,
                                              0x0,
                                              (u32) func_808000B8_chcolldoors,
                                              (u32) func_80105834,
                                              (u32) func_80101870,
                                              0x13880000,
                                              0x0,
                                              0x0,
                                              0x80C04,
                                              0x0,
                                              0x0,
                                              0x0,
                                              (u32) func_80800000_chcolldoors,
                                              (u32) func_80107C2C,
                                              0x80080002,
                                              0x0,
                                              0x0,
                                              0x0,
                                              0x0};
