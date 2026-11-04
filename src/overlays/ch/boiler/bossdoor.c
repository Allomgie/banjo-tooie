// Probably the door to Old King Coal's arena: a doormake door that opens when the boss
// retry flag is set or in a cutscene, and otherwise messages itself to open.
#include "common.h"

extern int D_808000F0_chboilerbossdoor[];
extern void func_80102FDC(Actor *, f32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);

int chboilerbossdoor_entrypoint_0()
{
    return (int) &D_808000F0_chboilerbossdoor;
}

// Old King Coal's arena door: opens on boss retry (flag 0x179) or in a cutscene, else waits for message 8.
void func_8080000C_chboilerbossdoor(Actor *actor)
{
    s32 unk_0;
    s32 should_open;

    should_open = func_800DA298(0x179) != 0;
    if (!should_open)
        should_open = _glcutDll_entrypoint_20() != 0;
    if (should_open)
        func_80101FDC(actor, 1);
    func_80102FDC(actor, actor->scale * 1.1f);
    unk_0 = _chdoormake_entrypoint_3(actor, 0.0f, 90.0f, 400.0f, 0x802, -1);
    if (unk_0) {
        _chdoormake_entrypoint_5(actor, 4.0f);
        _chdoormake_entrypoint_8(actor, 12);
    }
    if (!should_open)
        func_8010108C(actor, 8, 0);
}

extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_808000F0_chboilerbossdoor[20] = {0xAC046D,
                                       0x77B0004,
                                       0x0,
                                       (u32) _chdoor_entrypoint_0,
                                       (u32) func_80105834,
                                       (u32) func_80101870,
                                       0x0,
                                       0x0,
                                       0x860000,
                                       0x400,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080000C_chboilerbossdoor,
                                       (u32) func_80107C2C,
                                       -0x7FF7D3FE,
                                       (u32) _chdoor_entrypoint_1,
                                       0x0,
                                       0x0,
                                       0x0};
