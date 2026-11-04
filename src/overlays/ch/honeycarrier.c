// Empty Honeycomb collectible: a spinning pickup with twinkles. On touch it marks itself collected,
// plays the jingle, starts the first-time tutorial, adds the item and sparkles. May carry a light.
#include "ch/honeycarrier.h"

extern u32 D_808003E0_chhoneycarrier[3];
extern f32 D_808003EC_chhoneycarrier[2];
extern u32 D_808003F4_chhoneycarrier[];

void func_80800000_chhoneycarrier(Actor *actor, unkStructHoneyCarrier *info)
{
    if ((func_800F4B4C((u32) info->unk1A >> 5) != 0) &&
        (func_800DA298(FLAG2_663_EMPTY_HONEYCOMB_COLLISION) == 0)) {
        if (actor->unk6C_0 != 0) {
            func_800C8B84(actor->unk6C_0);
        }
        // mark collected in registry (category 2)
        func_800D0BD4(actor->unk50, 2);
        func_800FC63C(9, 0x6D60);
        func_800C9E20(2.0f, &_sudialog_entrypoint_0, FLAG_032_FTT_ITEM_EMPTY_HONEYCOMB, 0);
        // add empty honeycomb to inventory
        func_800D1844(0x49);
        _fxsparkle_entrypoint_1(actor->position, 0);
        func_800FFA88(actor->unk0);
    }
}

s32 func_808000C4_chhoneycarrier(Actor *actor, s32 msg, s32 data)
{
    f32 light_pos[3];
    switch (msg) {
        case 0x3E:
            func_80800000_chhoneycarrier(actor, (unkStructHoneyCarrier *) data);
            break;
        case 0x12:
            actor->unk64_19 = data;
            break;
        case 0x13:
            actor->unk50 = (f32) data;
            break;
        case 0x55: // attach light
            actor->unk6C_0 = func_800C8A98();
            func_800C8CB8(actor->unk6C_0, actor->position);
            func_800C8D4C(actor->unk6C_0, D_808003EC_chhoneycarrier);
            func_800C8E84(actor->unk6C_0, D_808003E0_chhoneycarrier);
            func_800EE7F8(light_pos, actor->position);
            light_pos[1] += 150.0f;
            func_800C8CB8(actor->unk6C_0, light_pos);
            break;
        default:
            return 0;
    }
    if (data) {
    }
    return 1;
}

void func_80800210_chhoneycarrier(Actor *actor)
{
    // random spin direction
    if (func_800DC298(0.5f) != 0) {
        actor->unk58 = 200.0f;
        return;
    }
    actor->unk58 = -200.0f;
}

void func_80800260_chhoneycarrier(Actor *actor)
{
    s32 i = 0;
    f32 pos[3];

    // spin about Y
    actor->rotation[1] += func_800D8FF8() * actor->unk58;
    actor->rotation[1] = func_800136E4(actor->rotation[1]);
    if (actor->unk7C_12) {
        i = 0;
        do {
            // up to 4 chances per frame for a twinkle
            if (func_800DC298(0.03f) != 0) {
                func_80103DFC(actor, pos);
                func_800EF214(pos, func_800DC178(0.0f, 360.0f), func_800DC178(0.0f, 360.0f),
                              60.0f);
                _fxtwinkle_entrypoint_0(pos);
            }
            i += 1;
        } while (i != 4);
    }
    func_80103110(actor, 0U);
}

void func_80800380_chhoneycarrier(Actor *actor, void *info)
{
    func_80101870(actor, info);
    if (actor->unk7C_12) {
        func_80103110(actor, 1);
    }
}

u32 *chhoneycarrier_entrypoint_0(void)
{
    return &D_808003F4_chhoneycarrier;
}

extern void func_80105834();
extern void func_80108ED0();
extern void func_80107C2C();
u32 D_808003E0_chhoneycarrier[3] = {0xFF, 0xFF, 0xC0};
f32 D_808003EC_chhoneycarrier[2] = {2.5e+02f, 3.5e+02f};
u32 D_808003F4_chhoneycarrier[19] = {0x530220,
                                     0x6120001,
                                     0x0,
                                     (u32) func_80800260_chhoneycarrier,
                                     (u32) func_80105834,
                                     (u32) func_80800380_chhoneycarrier,
                                     0x0,
                                     0x3F4CCCCD,
                                     0x0,
                                     0x4,
                                     0x0,
                                     (u32) func_80108ED0,
                                     0x0,
                                     (u32) func_80800210_chhoneycarrier,
                                     (u32) func_80107C2C,
                                     0x88003000,
                                     (u32) func_808000C4_chhoneycarrier,
                                     0x0,
                                     0x0};
