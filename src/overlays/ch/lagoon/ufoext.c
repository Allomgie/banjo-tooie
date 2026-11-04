// Probably the outside of the Jolly Roger's Lagoon UFO: once the inside is repaired and the player
// stands in its trigger in first person, a camera sequence plays and the UFO leaves the lagoon.
#include "common.h"

extern void func_8010D5DC(void);
extern void func_800F4AC0(s32, f32 *, f32);
extern int D_80800558_chlagoonufoext[];
extern u8 D_80800500_chlagoonufoext[];
extern u8 D_80800510_chlagoonufoext[];
extern u8 D_80800524_chlagoonufoext[];
extern u8 D_808005A0_chlagoonufoext[];
extern void func_800DF428(f32);
extern void func_801015D0(Actor *, void *);
void func_808002A4_chlagoonufoext();

// Actor message handler.
int func_80800000_chlagoonufoext(Actor *actor, s32 msg, s32 arg)
{
    s32 handle;

    switch (msg) {
        case 0xB:
            if (arg == 0x32) {
                func_800DA544(0xB6);
                _susubgame_entrypoint_4(actor, func_80100094(actor, 0));
                if (_gclevel_entrypoint_3(0x17))
                    _glcutDll_entrypoint_6(0x128, 0x4A);
                return 4;
            }
            return 3;
        case 0x32:
            func_808002A4_chlagoonufoext(actor);
            return 1;
        case 0x95:
            if (func_800DA298(0x9F0) && func_80090178(1) && func_800EA090() == 9) {
                handle = func_800F54E4();
                func_800F608C(handle, 1);
                func_800F497C(handle);
                func_800F49D4(handle, func_8010D5DC, actor->unk0);
                func_800F4AC0(handle, (f32 *) ((u8 *) actor + 0x28), 300.0f);
                _susubgame_entrypoint_6(actor, func_80100094(actor, 0), 0x42, 0x60, 0);
                func_80102424(actor, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800168_chlagoonufoext(u8 *actor)
{
    actor[0x34] = _subaddieaudioloop_entrypoint_3(actor[0x34]);
    if (_susubgame_entrypoint_2(actor, func_80100094(actor, 0)) != 0) {
        _susubgame_entrypoint_4(actor, func_80100094(actor, 0));
    }
}

int chlagoonufoext_entrypoint_0()
{
    return (int) &D_80800558_chlagoonufoext;
}

void func_808001D8_chlagoonufoext(u8 *actor)
{
    s8 _sfpad[16];
    u8 *new_var;
    s32 marker;
    s32 sound;

    *(s32 *) (actor + 0x24) = func_800CBDD4(actor + 4, 0x64, 6);
    if (func_800DA298(0xB6) != 0) {
        sound = *(s32 *) (actor + 0x24);
        if (sound != -1) {
            func_800CBB80(sound, 0);
        }
        func_800FFAB0(actor);
    } else {
        ((Actor *) actor)->unk6C_0 = _subaddiesect_entrypoint_1(actor);
    }
    if (_subaddiemarker_entrypoint_0(actor, 0x1C0, &marker, 1) != 0) {
        func_800EE7F8(actor + 0x28, &marker);
    }
    _susubgame_entrypoint_0(actor, func_80100094(actor, 0), 0);
}

void func_808002A4_chlagoonufoext(actor) s32 *actor;
{
    func_80101FDC(actor, 3);
    func_80101D4C(actor);
    func_800D1000(0x28, 1, 0, 3, 0);
    _susubgame_entrypoint_6(actor, func_80100094(actor, 0), 0x32, 0x30, 0);
    _subaddiedialog_entrypoint_11(*actor, 0x1047, 0x40, actor + 1, 0);
}

void func_8080032C_chlagoonufoext(u8 *actor)
{
    s32 active;

switch ((u32) *(u16 *) (actor + 0x72) >> 0xA) {
    case 1:
        if (_subaddiesect_entrypoint_0(actor, *(s32 *) (actor + 0x6C) & 0x1FF, 4) == 0) {
        }
        return;
    case 3:
        active = 0;
        if (func_80101E14(actor, 0x3EFAE148) != 0) {
            actor[0x73] &= 0xFFFE;
        }
        if (func_80102320(actor, 0x3F07AE14, 0x3F333333) != 0) {
            active = 1;
        } else {
            _subaddieaudioloop_entrypoint_4(actor, actor + 0x18, 1, D_80800510_chlagoonufoext);
        }
        actor[0x34] = _subaddieaudioloop_entrypoint_7(actor[0x34], actor + 0x18, active,
                                                        D_80800500_chlagoonufoext,
                                                        *(s32 *) (actor + 0x70) & 1);
        _subaddieaudioquick_entrypoint_4(actor, actor + 0x18, D_80800524_chlagoonufoext,
                                         D_808005A0_chlagoonufoext);
        if (func_800DA298(0xB6) != 0) {
            if (*(s32 *) (actor + 0x24) != -1) {
                func_800CBB80(*(s32 *) (actor + 0x24), 0);
            }
            func_800FFAB0(actor);
        }
}

}

void func_8080047C_chlagoonufoext(Actor *actor, void *param_1)
{
    if (actor->unk70_10 != 3) {
        func_800DF428(9000.0f);
    } else {

func_800DF440(0);
}
func_80101808(actor, func_801015D0);
_subaddieskeleton_entrypoint_3(actor->unk0, 4, actor->actorData);
}

// TU-NOTE: .data of this overlay is defined here in C (values from the ROM). Its tables hold
// pointers to functions of this file; IDO schedules some of these functions differently unless
// the tables are in the same unit. D_80800558_chlagoonufoext is declared int[] to match the object.
extern void func_80102EC0();
extern void func_80107C2C();
u8 D_80800500_chlagoonufoext[16] = {0x0, 0x13, 0x5,  0xF0, 0x0,  0x16, 0x46, 0x50,
                                    0x0, 0x1,  0x27, 0x10, 0x3A, 0x98, 0x0,  0x0};
u8 D_80800510_chlagoonufoext[20] = {0x0, 0x13, 0x4, 0xDF, 0x0,  0x16, 0x2E, 0xE0, 0x0, 0x1B,
                                    0x1, 0x2,  0x0, 0x1,  0x27, 0x10, 0x3A, 0x98, 0x0, 0x0};
u8 D_80800524_chlagoonufoext[20] = {0x0,  0x13, 0x4, 0xB5, 0x0,  0xA,  0x0,  0xD9, 0x0, 0x16,
                                    0x61, 0xA8, 0x0, 0x1,  0x27, 0x10, 0x3A, 0x98, 0x0, 0x0};
u32 D_80800538_chlagoonufoext[8] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41F00000, 0x1CD0000};
int D_80800558_chlagoonufoext[18] = {0x15801C2,
                                     0x6FC0001,
                                     (u32) &D_80800538_chlagoonufoext,
                                     (u32) func_8080032C_chlagoonufoext,
                                     (u32) func_80102EC0,
                                     (u32) func_8080047C_chlagoonufoext,
                                     0x0,
                                     0x0,
                                     0x0,
                                     0x1406,
                                     (u32) func_80800168_chlagoonufoext,
                                     0x0,
                                     0x180000,
                                     (u32) func_808001D8_chlagoonufoext,
                                     (u32) func_80107C2C,
                                     -0x7FFFFBFE,
                                     (u32) func_80800000_chlagoonufoext,
                                     0x0};
u8 D_808005A0_chlagoonufoext[32] = {
    0x3F, 0x7,  0xAE, 0x14, 0x3F, 0x33, 0x33, 0x33, 0x3F, 0x47, 0xAE, 0x14, 0x3F, 0x5E, 0xB8, 0x52,
    0xBF, 0x80, 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0};
