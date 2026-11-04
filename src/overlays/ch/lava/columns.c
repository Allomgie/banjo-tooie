#include "common.h"

extern u8 D_80800250_chlavacolumns[];
extern u8 D_80800258_chlavacolumns[];
extern f32 func_800D8FF8(void);
extern int D_80800260_chlavacolumns[];
s32 func_80800200_chlavacolumns(s32 param_0, f32 param_1);
extern void func_800EDCB8(s32, f32);

void func_80800000_chlavacolumns(u8 *actor)
{
    func_80800200_chlavacolumns(actor, -400.0f);
    func_800EFD24(actor + 4);
    *(f32 *) (actor + 8) = -400.0f;
    func_80103014(actor);
}

s32 func_80800044_chlavacolumns(Actor *actor, s32 message, s32 data)
{
    if (message == 0x95) {
        if (_glcutDll_entrypoint_19(0x4E)) {
            actor->unk64_16 = 1;
            actor->position[1] = -400.0f;
            func_80103110(actor, 1);
            func_80102FE8(actor, 0);
            _subaddieDll_entrypoint_0(actor);
            func_80101FDC(actor, 2);
            func_80800200_chlavacolumns(actor, -400.0f);
            _capod_entrypoint_13(actor->unk0, 0, 0x1A, 0x910);
        } else if (func_800DA298(0x390)) {
            actor->position[1] = 0.0f;
            func_80101FDC(actor, 3);
            func_80800200_chlavacolumns(actor, 0.0f);
        } else {
            actor->position[1] = -400.0f;
            func_80800200_chlavacolumns(actor, -400.0f);
        }
        func_80103014(actor);
        return 1;
    }
    return 0;
}

// Per-frame: during the cutscene the column rises to y = 0.
void func_8080014C_chlavacolumns(Actor *actor)
{
    if (actor->unk70_10 == 2) {
        _subaddieaudioloop_entrypoint_4(actor, actor->position, 1, D_80800250_chlavacolumns);
        actor->position[1] += 100.0f * func_800D8FF8();
        if (actor->position[1] > 0.0f) {
            actor->position[1] = 0.0f;
            func_80101FDC(actor, 3);
            _subaddieaudioquick_entrypoint_2(actor, actor->position, D_80800258_chlavacolumns);
            func_80103110(actor, 0);
        }
    }
}

s32 func_80800200_chlavacolumns(s32 actor, f32 offset_y)
{
    s32 mesh;

    mesh = _idworld_entrypoint_3(0x190);
    if (mesh) {
        func_800EDCB8(mesh, offset_y);
        return 1;
    }
    return 0;
}

int chlavacolumns_entrypoint_0(void)
{
    return (int) &D_80800260_chlavacolumns;
}

extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_80800250_chlavacolumns[8] = {0x0, 0x13, 0x4, 0xAD, 0x0, 0x2, 0x0, 0x0};
u8 D_80800258_chlavacolumns[8] = {0x0, 0x13, 0x4, 0xC7, 0x0, 0x2, 0x0, 0x0};
int D_80800260_chlavacolumns[20] = {0x158027F,
                                    0x95F0001,
                                    0x0,
                                    (u32) func_8080014C_chlavacolumns,
                                    (u32) func_80105834,
                                    (u32) func_80101870,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    0x0,
                                    (u32) func_80800000_chlavacolumns,
                                    (u32) func_80107C2C,
                                    -0x7FFFD1FE,
                                    (u32) func_80800044_chlavacolumns,
                                    0x0,
                                    0x0,
                                    0x0};
