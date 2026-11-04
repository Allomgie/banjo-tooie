#include "ch/ghostdoor.h"

extern int D_80800220_chghostdoor[];
extern int D_80800268_chghostdoor[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);
extern void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);

int *chghostdoor_entrypoint_0()
{
    return &D_80800220_chghostdoor;
}

int chghostdoor_entrypoint_1()
{
    return (int) &D_80800268_chghostdoor;
}

// Witchyworld station door: two leaves, opens when flag 0x96 is set.
void func_80800018_chghostdoor(Actor *actor)
{
    f32 yaw;
    s32 mirrored;
    yaw = actor->rotation[1];
    mirrored = 0;
    if (((u32) *(u16 *) ((u8 *) actor + 0x76) >> 7) == 50) {
        mirrored = 1;
        yaw += 180.0f;
    }
    func_800EFD24(actor->position);
    func_80103014(actor);
    if (_chdoormake_entrypoint_3(actor, yaw, 0.0f, 650.0f, 0x20, 0x96)) {
        _chdoormake_entrypoint_5(actor, 3.5f);
        _chdoormake_entrypoint_6(actor, 2.0f);
        if (mirrored)
            _chdoormake_entrypoint_8(actor, 15);
    }
    if (func_800DA298(0x96))
        func_800FFAB0(actor);
}

s32 func_808000F4_chghostdoor(Actor *actor, s32 msg, s32 payload)
{
    s32 model_id;
    switch (msg) {
        case 0x95:
            model_id = actor->unk74_7 == 0x32 ? 0x782 : 0x783;
            func_80103140(actor, model_id, *(u16 *) ((u8 *) actor->unk0 + 0x16));
            break;
        case 0x9D:
            func_800FFAB0(actor);
            return 1;
    }
    return _chdoor_entrypoint_1(actor, msg, payload);
}

// Switch that sets FLAG_096_STATION_UNLOCKED_WW.
void func_80800190_chghostdoor(s32 actor)
{
    _chswitch_entrypoint_7(actor, FLAG_096_STATION_UNLOCKED_WW);
    _chswitch_entrypoint_9(actor);
}

// Switch pressed: camera shot and tells the door (actor 0x344).
s32 func_808001BC_chghostdoor(Actor *actor, s32 msg, s32 payload)
{
    switch (msg) {
        case 7:
            _capod_entrypoint_13(actor->unk0, NULL, 5, 0x10);
            func_80101180(0x344, 7, 0);
            break;
        default:
            return _chswitch_entrypoint_10(actor, msg, payload);
    }
    return 1;
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern u8 D_8011A248[];
extern void _chswitch_entrypoint_6();
int D_80800220_chghostdoor[18] = {0xAC0344,
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
                                  (u32) func_80800018_chghostdoor,
                                  (u32) func_80107C2C,
                                  -0x7FF7D3FE,
                                  (u32) func_808000F4_chghostdoor,
                                  0x0};
int D_80800268_chghostdoor[18] = {0x3430348,
                                  0x86D0001,
                                  (u32) &D_8011A248,
                                  (u32) _chswitch_entrypoint_6,
                                  (u32) func_80105834,
                                  (u32) func_80101870,
                                  0x0,
                                  0x0,
                                  0x0,
                                  0x4000080C,
                                  0x0,
                                  0x0,
                                  0x0,
                                  (u32) func_80800190_chghostdoor,
                                  (u32) func_80107C2C,
                                  -0x7FF7D3EE,
                                  (u32) func_808001BC_chghostdoor,
                                  0x0};
