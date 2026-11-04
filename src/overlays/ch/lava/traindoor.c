// Door of the Hailfire Peaks fire-side train station: bound to FLAG_1D0_STATION_UNLOCKED_HFPL
// and opened during cutscene 0x4D; variant 0x32 is slower and has its own camera pod.
#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

// HFP fire-side train station door; opens with flag 0x1D0 and cutscene 0x4D. Marker 0x32 is slower.
void func_80800000_chlavatraindoor(Actor *actor)
{
    f32 speed;

    if (_chdoormake_entrypoint_3(actor, 0.0f, 90.0f, actor->scale * 1007.5f, 0x20, 0x1D0)) {
        _chdoormake_entrypoint_12(actor, 0, 0x4D);
        _chdoormake_entrypoint_8(actor, 5);
        if (actor->unk74_7 == 0x32)
            speed = 0.8f;
        else
            speed = 3.5f;
        _chdoormake_entrypoint_6(actor, speed);
        if (actor->unk74_7 == 0x32)
            _chdoormake_entrypoint_9(actor, 0, 8, 0x910);
    }
}

int chlavatraindoor_entrypoint_0()
{
    extern int D_808000F0_chlavatraindoor[];
    return &D_808000F0_chlavatraindoor;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise. D_808000F0_chlavatraindoor is int[].
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_808000F0_chlavatraindoor[20] = {0xAC0281,
                                      0x8F60001,
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
                                      (u32) func_80800000_chlavatraindoor,
                                      (u32) func_80107C2C,
                                      -0x7FF7DBEE,
                                      (u32) _chdoor_entrypoint_1,
                                      0x0,
                                      0x0,
                                      0x0};
