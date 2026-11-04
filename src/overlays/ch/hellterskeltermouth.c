#include "common.h"

extern int D_80800330_chhellterskeltermouth[];
extern s32 D_80800384_chhellterskeltermouth[];
extern void _subaddieaudioloop_entrypoint_4();
extern u8 D_80800378_chhellterskeltermouth[];
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);

int chhellterskeltermouth_entrypoint_0()
{
    return (int) &D_80800330_chhellterskeltermouth;
}

void func_808002E4_chhellterskeltermouth();

// Opens and closes the mouth in a loop: states 2/4 lerp the position, 3/5 wait.
void func_8080000C_chhellterskeltermouth(Actor *actor)
{
    s32 open_done;
    f32 t;
    s32 close_done;
    f32 *pos;
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            open_done = func_800D9078(&actor->unk58);
            pos = actor->position;
            t = func_800F12D4(actor->unk58, 0.0f, 2.5f, 1.0f, 0.0f);
            func_800EFE50(pos, (f32 *) actor->actorData + 4, (f32 *) actor->actorData,
                          t);
            if (open_done) {
                actor->unk58 = 0.7f;
                func_80101FDC(actor, 3);
                _subaddieaudioquick_entrypoint_2(actor, pos,
                                                 D_80800378_chhellterskeltermouth);
            }
            func_808002E4_chhellterskeltermouth(actor);
            break;
        case 3:
            if (func_800D9078(&actor->unk58)) {
                actor->unk58 = 2.5f;
                func_80101FDC(actor, 4);
            }
            break;
        case 4:
            close_done = func_800D9078(&actor->unk58);
            pos = actor->position;
            t = func_800F12D4(actor->unk58, 0.0f, 2.5f, 0.0f, 1.0f);
            func_800EFE50(pos, (f32 *) actor->actorData + 4, (f32 *) actor->actorData,
                          t);
            if (close_done) {
                actor->unk58 = 0.7f;
                func_80101FDC(actor, 5);
                _subaddieaudioquick_entrypoint_2(actor, pos,
                                                 D_80800378_chhellterskeltermouth);
            }
            func_808002E4_chhellterskeltermouth(actor);
            break;
        case 5:
            if (func_800D9078(&actor->unk58)) {
                actor->unk58 = 2.5f;
                func_80101FDC(actor, 2);
            }
    }
}

// Stays open for good if flag 0xA4 is set.
void func_808001BC_chhellterskeltermouth(u8 *actor)
{
    func_800EE7F8(actor + 0x18, actor + 4);
    func_800EE7F8(actor + 0x28, actor + 4);
    *(f32 *) ((char *) actor + 0x2C) = *(f32 *) ((char *) actor + 0x2C) - 350.0f;
    if (func_800DA298(0xA4) != 0) {
        func_8010A590(actor);
        func_80102FE8(actor, 0);
        func_80101FDC(actor, 4);
        *(f32 *) ((char *) actor + 0x58) = 2.5f;
        return;
    }
    func_80103110(actor, 0);
}

int func_80800258_chhellterskeltermouth(Actor *actor, s32 msg, s32 arg)
{
    switch (msg) {
        case 0xA:
            _capod_entrypoint_13(actor->unk0, 0, 0x1A, 0x2010);
            func_8010A590(actor);
            func_80103110(actor, 1);
            func_80102FE8(actor, 0);
            func_80101FDC(actor, 4);
            actor->unk58 = 2.5f;
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002E4_chhellterskeltermouth(u8 *actor)
{
    _subaddieaudioloop_entrypoint_4(actor, actor + 4, 1, &D_80800384_chhellterskeltermouth);
}

// TU-NOTE: the .data of this overlay is defined here in C. Its tables hold pointers to
// functions of this file; IDO assembler schedules some of them differently unless the
// tables are in the same unit. Values are taken from the ROM.
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800330_chhellterskeltermouth[18] = {0x1AA0340,
                                            0x77E0001,
                                            0x0,
                                            (u32) func_8080000C_chhellterskeltermouth,
                                            (u32) func_80105834,
                                            (u32) func_80101870,
                                            0xDAC0000,
                                            0x0,
                                            0x0,
                                            0xC00,
                                            0x0,
                                            0x0,
                                            0x0,
                                            (u32) func_808001BC_chhellterskeltermouth,
                                            (u32) func_80107C2C,
                                            -0x7FFFDBFE,
                                            (u32) func_80800258_chhellterskeltermouth,
                                            0x0};
u8 D_80800378_chhellterskeltermouth[12] = {0x0, 0x13, 0x4, 0xCC, 0x0, 0xD,
                                           0x0, 0xA6, 0x0, 0xC0, 0x0, 0x0};
s32 D_80800384_chhellterskeltermouth[7] = {0x1304AD, 0x105DC,    0xBB8000E, 0x94009E,
                                           0x190016, 0x6D600000, 0x0};
