// Sliding door of TDL's Chuffy train station: opens when flag 0x164 is set, with a camera shot
// and cutscene 0x3C; the variant with marker 50 is mirrored and has extra sounds.
#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void func_80103140(Actor *, u16, u16);
extern int D_808001D0_chdinotraindoor[];

// TDL train station door; opens with flag 0x164 and cutscene 0x3C. Marker 50 is mirrored.
void func_80800000_chdinotraindoor(Actor *actor)
{
    f32 yaw = actor->rotation[1];
    if (actor->unk74_7 == 50)
        yaw += 180.0f;
    func_800EFD24(actor->position);
    func_80103014(actor);
    if (_chdoormake_entrypoint_3(actor, yaw, 0.0f, actor->scale * 600.0f, 0x20, 0x164)) {
        _chdoormake_entrypoint_5(actor, 3.5f);
        _chdoormake_entrypoint_6(actor, 4.0f);
        _chdoormake_entrypoint_12(actor, 0, 0x3C);
        if (actor->unk74_7 == 50) {
            _chdoormake_entrypoint_8(actor, 5);
            _chdoormake_entrypoint_9(actor, 0, 10, 0x910);
        }
    }
    if (func_800DA298(0x164) && !_glcutDll_entrypoint_19(0x3C))
        func_800FFAB0(actor);
}

s32 func_80800120_chdinotraindoor(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0x95:
            func_80103140(actor, actor->unk74_7 == 0x32 ? 0x949 : 0x94A, 0);
            break;
        case 0x9D:
            func_800FFAB0(actor);
    }
    return _chdoor_entrypoint_1(actor, msg, arg);
}

int *chdinotraindoor_entrypoint_0()
{
    return &D_808001D0_chdinotraindoor;
}

// TU-NOTE: the overlay .data is defined here in C (from the ROM); its tables point to functions of
// this file, and IDO's assembler schedules them differently otherwise. D_808001D0_chdinotraindoor is int[].
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_808001D0_chdinotraindoor[20] = {0xAC049B,
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
                                      (u32) func_80800000_chdinotraindoor,
                                      (u32) func_80107C2C,
                                      -0x7FF7D3FE,
                                      (u32) func_80800120_chdinotraindoor,
                                      0x0,
                                      0x0,
                                      0x0};
