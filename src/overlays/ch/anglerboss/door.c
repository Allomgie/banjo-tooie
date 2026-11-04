#include "common.h"

extern int D_80800110_changlerbossdoor[];
extern void func_800F1A88();
extern void func_80101FDC();
typedef struct AnglerDoorFlags {
    u8 pad_0 : 7;
    u8 local_0 : 1;
} AnglerDoorFlags;
extern void func_80102FDC(Actor *, f32);
extern void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);

int *changlerbossdoor_entrypoint_0()
{
    return &D_80800110_changlerbossdoor;
}

void func_8080000C_changlerbossdoor(Actor *actor)
{
    f32 door_pos[3];
    f32 offset[3];
    s32 is_open;

    is_open = func_800DA298(0x1AF) != 0;
    if (!is_open) {
        is_open = _glcutDll_entrypoint_20() != 0;
    }

    // Open at once when retrying the boss (flag 0x1AF) or during a cutscene.
    if (is_open) {
        func_80101FDC(actor, 1);
    }
    func_80102FDC(actor, actor->scale * 1.75f);
    ((AnglerDoorFlags *) ((u8 *) actor + 0x73))->local_0 = 1;
    func_800EF6A8(offset, actor->rotation, 0.0f, 500.0f, 0.0f);
    func_800F1A88(offset, door_pos);
    if (_chdoormake_entrypoint_3(actor, door_pos[1], door_pos[0], 500.0f, 0x802, -1)) {
        _chdoormake_entrypoint_5(actor, 3.0f);
        _chdoormake_entrypoint_6(actor, 0.8f);
        _chdoormake_entrypoint_8(actor, 5);
    }
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
// TU-NOTE: .data of this overlay is defined here in C.
int D_80800110_changlerbossdoor[20] = {0xAC046C,
                                       0x9440004,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x3770000,
                                       0x410,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080000C_changlerbossdoor,
                                       (u32) func_80107C2C,
                                       -0x7FF7D3FE,
                                       (u32) _chdoor_entrypoint_1,
                                       0x0,
                                       0x0,
                                       0x0};
