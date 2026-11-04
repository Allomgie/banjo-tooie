#include "ch/cauldronenergybars.h"

#define CAULDRONENERGYBARS_DATA(arg0) ((CauldronEnergyBarsData *) (arg0->actorData))

extern s32 D_808002C0_chcauldronenergybars[];
extern s32 D_808002D4_chcauldronenergybars[];

// Removes the barrier once its world is open (Jiggywiggy challenge or open-worlds cheat).
// Actor param 0x32 selects Cauldron Keep, otherwise the Hag 1 battle.
void func_80800000_chcauldronenergybars(Actor *actor)
{
    s32 flag;
    s32 cheat_id;
    u8 challenge;

    if (actor->unk74_7 == 0x32) {
        challenge = 8;
        flag = FLAG_39A_PROGRESS_OPENED_WORLD_CK;
        cheat_id = 0x82;
    } else {
        challenge = 9;
        flag = FLAG_39B_PROGRESS_OPENED_WORLD_HAG_1_BATTLE;
        cheat_id = 0x83;
    }
    if (_sujiggy_entrypoint_20(challenge) != 0) {
        func_800DA544(flag);
    }
    if (func_800DA298(flag) != 0) {
        func_800FFAB0(actor);
        return;
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(cheat_id) == 0)) {
        func_800FFAB0(actor);
    }
}

// Case 1: idle, shock timer. Case 2: fade out with an audio pitch sweep.
void func_808000B8_chcauldronenergybars(Actor *actor)
{
    switch (actor->unk70_10) {
        case 1:
            if (func_800D9078(&CAULDRONENERGYBARS_DATA(actor)->unk10) != 0) {
                func_8010A590(actor);
            }
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            &D_808002C0_chcauldronenergybars);
            return;
        case 2:
            if (func_800D90A4(&actor->unk58) != 0) {
                func_800FFAB0(actor);
            }
            _subaddieaudioloop_entrypoint_4(actor, actor->position, 1,
                                            &D_808002C0_chcauldronenergybars);
            _subaddieaudioloop_entrypoint_0(
                actor,
                func_800F10B4(actor->unk58, CAULDRONENERGYBARS_DATA(actor)->unk1C, 0.0f, 1.4f, 0.7f));
            actor->alpha = (u8) (s32) func_800F10B4(
                actor->unk58, CAULDRONENERGYBARS_DATA(actor)->unk1C, 0.0f, 255.0f, 0.0f);
    }
}

// Message 7: world opened, start fade. Message 0x3F: shock the player.
s32 func_808001C4_chcauldronenergybars(Actor *actor, s32 msg, s32 data)
{
    union {
        f32 f;
    } fade;
    f32 shock_pos[3];
    s32 raw[1];

    switch (msg) {
        case 0x7:
            fade.f = data;
            CAULDRONENERGYBARS_DATA(actor)->unk1C = fade.f;
            actor->unk58 = fade.f;
            func_80101FDC(actor, 2);
            _subaddieDll_entrypoint_4(actor, 1);
            func_8010A570(actor);
            func_800DA544((actor->unk74_7 == 0x32) ? 0x39A : 0x39B);
            return 1;

        case 0x3F:
            raw[0] = *(s32 *) &data;
            func_800EC75C(raw[0], shock_pos);
            _chelectricfence_entrypoint_1(actor, shock_pos);
            CAULDRONENERGYBARS_DATA(actor)->unk10 = 0.2f;
            func_8010A570(actor);
            return 1;
    }

    return 0;
}

s32 *chcauldronenergybars_entrypoint_0(void)
{
    return &D_808002D4_chcauldronenergybars;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80108ED0();
extern void func_80107C2C();
s32 D_808002C0_chcauldronenergybars[5] = {0x1305B7, 0x100C8, 0x7D0000A, 0x1660016, 0x7D000000};
s32 D_808002D4_chcauldronenergybars[19] = {0x331048D,
                                           0x9780001,
                                           0x0,
                                           (u32) func_808000B8_chcauldronenergybars,
                                           (u32) func_80105834,
                                           (u32) func_80101870,
                                           0x7D00000,
                                           0x0,
                                           0x0,
                                           0xC00,
                                           0x0,
                                           (u32) func_80108ED0,
                                           0x0,
                                           (u32) func_80800000_chcauldronenergybars,
                                           (u32) func_80107C2C,
                                           -0x7FFFDC00,
                                           (u32) func_808001C4_chcauldronenergybars,
                                           0x0,
                                           0x0};
