#include "common.h"

extern int D_80800280_chicestationbits[];
extern int D_808002C8_chicestationbits[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);

int *chicestationbits_entrypoint_0()
{
    return &D_80800280_chicestationbits;
}

void *chicestationbits_entrypoint_1()
{
    return &D_808002C8_chicestationbits;
}

// Station unlock switch (flag 0x1CF).
s32 func_80800018_chicestationbits(void *actor)
{
    _chswitch_entrypoint_7(actor, 0x1CF);
    _chswitch_entrypoint_9(actor);
    _chswitch_entrypoint_8(actor, 2);
}

// Switch message handler: message 7 starts the unlock cutscene.
s32 func_80800050_chicestationbits(Actor *actor, s32 msg, s32 msg_data)
{
    switch (msg) {
        case 7:
            _glcutDll_entrypoint_6(0x12A, 0x48);
            break;
        case 0x91:
            if (!func_800F6B94(func_800F54E4())) {
                return 0;
            }
        default:
            return _chswitch_entrypoint_10(actor, msg, msg_data);
    }
    return 1;
}

// Station door; opens once flag 0x1CF is set.
void func_808000D4_chicestationbits(Actor *actor)
{
    f32 yaw;

    yaw = actor->rotation[1];
    if (actor->unk74_7 == 0x32) {
        yaw += 180.0f;
    }
    func_800EFD24(actor->position);
    func_80103014(actor);
    if (_chdoormake_entrypoint_3(actor, yaw, 0.0f, 600.0f, 0x20, 0x1CF)) {
        _chdoormake_entrypoint_5(actor, 3.5f);
        _chdoormake_entrypoint_6(actor, 0.5f);
        _chdoormake_entrypoint_12(actor, 0, 0x48);
        if (actor->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(actor, 9);
            _chdoormake_entrypoint_9(actor, 0, 0, 0x900);
        }
    }
    if (func_800DA298(0x1CF) && !_glcutDll_entrypoint_19(0x48)) {
        func_800FFAB0(actor);
    }
}

// Door message handler: sets the door model per variant.
s32 func_808001E0_chicestationbits(Actor *actor, s32 msg, s32 msg_data)
{
    s32 model_id;
    switch (msg) {
        case 0x95:
            model_id = actor->unk74_7 == 0x32 ? 0x872 : 0x873;
            func_80103140(actor, model_id, actor->unk0->unk16);
            break;
        case 0x9D:
            func_800FFAB0(actor);
    }
    return _chdoor_entrypoint_1(actor, msg, msg_data);
}

extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_0();
int D_80800280_chicestationbits[18] = {0x343041A,
                                       0x86D0001,
                                       (u32) &D_8011A248,
                                       (u32) _chswitch_entrypoint_6,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x80C,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_80800018_chicestationbits,
                                       (u32) func_80107C2C,
                                       -0x7FFFD3FE,
                                       (u32) func_80800050_chicestationbits,
                                       0x0};
int D_808002C8_chicestationbits[18] = {0xAC041B,
                                       -0xFFFF,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0xC00,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_808000D4_chicestationbits,
                                       (u32) func_80107C2C,
                                       -0x7FFFD3FE,
                                       (u32) func_808001E0_chicestationbits,
                                       0x0};
