#include "ch/lagoonentrygate.h"

extern s32 _chdoormake_entrypoint_0(Actor *, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern int D_80800150_chlagoonentrygate[];

// TU-NOTE: .data is defined in this C file; IDO schedules the functions differently otherwise.

// Init: opens the gate once the world is unlocked (or via cheat).
void func_80800000_chlagoonentrygate(Actor *actor)
{
    s32 flag;
    if (_sujiggy_entrypoint_20(3))
        func_800DA544(0x395);
    if (func_800D3E40(0xB) && !_glcutDll_entrypoint_19(0x7D)) {
        flag = -1;
        func_80101FDC(actor, 4);
    } else
        flag = 0x395;
    _chdoormake_entrypoint_0(actor, -150.0f, 0, flag);
    _chdoormake_entrypoint_5(actor, 0.0f);
}

// Update: gate sounds while opening, then generic door update.
void func_8080008C_chlagoonentrygate(Actor *actor)
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

int chlagoonentrygate_entrypoint_0()
{
    return &D_80800150_chlagoonentrygate;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
int D_80800150_chlagoonentrygate[20] = {0xAC0392,
                                        0x96E0001,
                                        0x0,
                                        (u32) func_8080008C_chlagoonentrygate,
                                        (u32) func_80105834,
                                        (u32) func_80101870,
                                        0x0,
                                        0x0,
                                        0x0,
                                        0xC00,
                                        0x0,
                                        0x0,
                                        0x0,
                                        (u32) func_80800000_chlagoonentrygate,
                                        (u32) func_80107C2C,
                                        -0x7FFFDBFE,
                                        (u32) _chdoor_entrypoint_1,
                                        0x0,
                                        0x0,
                                        0x0};
