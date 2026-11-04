#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
typedef union {
    s32 word;
    void *pointer;
} HagsTrainDoorEvent;
extern int D_80800150_chhagstraindoor[];

// Isle o' Hags station door: two leaves, opens on FLAG_403_STATION_UNLOCKED_IoH.
void func_80800000_chhagstraindoor(Actor *actor)
{
    f32 yaw;

    yaw = 0.0f;
    func_800EFD24(actor->position);
    func_80103014(actor);
    if (actor->unk74_7 == 0x32)
        yaw = 180.0f;
    if (_chdoormake_entrypoint_3(actor, yaw, 0.0f, 600.0f, 0x21, 0x403)) {
        _chdoormake_entrypoint_6(actor, 4.4f);
        _chdoormake_entrypoint_5(actor, 3.0f);
        if (actor->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(actor, 13);
            _chdoormake_entrypoint_9(actor, 0, 1, 0x10);
        }
    }
}

s32 func_808000D4_chhagstraindoor(Actor *actor, s32 msg, HagsTrainDoorEvent payload)
{
    if (msg == 0x95) {
        func_80103140(actor, (u16) (actor->unk74_7 == 0x32 ? 0x94F : 0x950), 0);
    }
    return _chdoor_entrypoint_1(actor, msg, payload.word);
}

int chhagstraindoor_entrypoint_0()
{
    return (int) &D_80800150_chhagstraindoor;
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800150_chhagstraindoor[20] = {0x371038C,
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
                                      (u32) func_80800000_chhagstraindoor,
                                      (u32) func_80107C2C,
                                      -0x7FFFD3FE,
                                      (u32) func_808000D4_chhagstraindoor,
                                      0x0,
                                      0x0,
                                      0x0};
