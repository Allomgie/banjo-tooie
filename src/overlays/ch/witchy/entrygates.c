// The two Witchyworld entrance gates on Isle o' Hags (left/right by variant 0x33). They open when
// the world is unlocked (flag 0x394) with creak sounds, and start open unless the cutscene runs.
#include "ch/witchyentrygates.h"

extern void func_80103140();
extern s32 _chdoor_entrypoint_1(Actor *, s32, s32);

extern u32 D_808001F0_chwitchyentrygates[];

// TU-NOTE: .data is defined in this C file; IDO schedules the functions differently otherwise.

// Init: gate opens when the world is unlocked; swings +75 deg for variant 0x33, -75 deg otherwise.
void func_80800000_chwitchyentrygates(Actor *actor)
{
    f32 swing_angle;
    s32 flag;
    if (_sujiggy_entrypoint_20(2U) != 0) {
        func_800DA544(FLAG_394_PROGRESS_OPENED_WORLD_WW);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7CU) == 0)) {
        flag = -1;
        func_80101FDC(actor, 4);
    } else {
        flag = 0x394;
    }
    if (actor->unk74_7 == 0x33) {
        swing_angle = 75.0f;
    } else {
        swing_angle = -75.0f;
    }
    _chdoormake_entrypoint_0(actor, swing_angle, 0, flag);
    _chdoormake_entrypoint_5(actor, 0.0f);
}

// Update: creak sounds while opening, then generic door update.
void func_808000B8_chwitchyentrygates(Actor *actor)
{
    u16 unk_0;
    Actor *door = actor;

    unk_0 = *(u16 *) ((u8 *) door + 0x72);
    if (((unk_0 & 0xFFFFu) >> 10) == 3) {
        if (!door->unk64_20) {
            func_800C3F48(0x66509D6D);
            door->unk64_20 = 1;
            *(f32 *) ((u8 *) door + 0x34) = 1.5f;
        } else if (func_800D90A4((u8 *) door + 0x34) != 0) {
            func_800C3F48(0x66509CA1);
            *(f32 *) ((u8 *) door + 0x34) = 1.0f;
        }
    }
    _chdoor_entrypoint_0(actor);
}

s32 func_80800168_chwitchyentrygates(Actor *actor, s32 msg, s32 arg)
{
    s32 sound_id;

    if (msg == 0x95) {
        sound_id = actor->unk74_7 == 0x33 ? 0x96C : 0x96D;
        func_80103140(actor, (u16) sound_id, *(u16 *) ((u8 *) actor->unk0 + 0x16));
    }
    return _chdoor_entrypoint_1(actor, msg, arg);
}

void *chwitchyentrygates_entrypoint_0(void)
{
    return &D_808001F0_chwitchyentrygates;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u32 D_808001F0_chwitchyentrygates[20] = {0xAC0489,
                                         0x96C0001,
                                         0x0,
                                         (u32) func_808000B8_chwitchyentrygates,
                                         (u32) func_80105834,
                                         (u32) func_80101870,
                                         0x0,
                                         0x0,
                                         0x0,
                                         0x20C00,
                                         0x0,
                                         0x0,
                                         0x0,
                                         (u32) func_80800000_chwitchyentrygates,
                                         (u32) func_80107C2C,
                                         0x80082402,
                                         (u32) func_80800168_chwitchyentrygates,
                                         0x0,
                                         0x0,
                                         0x0};
