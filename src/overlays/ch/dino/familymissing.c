// The missing Styracosaurus kid: appears at the Terrydactyland train station, walks home through
// the family cave, then stays as a talking family member.
#include "common.h"

extern s32 D_808006AC_chdinofamilymissing[];
extern f32 func_80101F24(Actor *);
extern f32 func_800F3780(f32, s32 *, s32);
extern void func_80105A9C(Actor *, f32);
extern u8 D_80800664_chdinofamilymissing[];
extern u8 D_808006CC_chdinofamilymissing[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern int D_808006DC_chdinofamilymissing[];
extern u8 D_808006A0_chdinofamilymissing[];
extern f32 func_80103EF4(Actor *);
extern f32 func_80103EAC(Actor *);
extern void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern s32 func_80105998(Actor *, f32);

// Init: picks the initial state from the current map and cutscene/flag progress.
int func_80800000_chdinofamilymissing(s32 actor)
{
    switch (func_800EA05C()) {
        case 0x114:
            if (!_glcutDll_entrypoint_19(0x35)) {
                func_800FFAB0(actor);
            }
            return;

        case 0x118:
            if (_glcutDll_entrypoint_20() != 0) {
                if (func_80105494(actor) != 0) {
                    func_800FFAB0(actor);
                    return;
                }
                func_80102424(actor, 7);
                return;
            }
            if ((_glcutDll_entrypoint_19(0x35) == 0) || (func_80105494(actor) == 0)) {
                if ((func_800DA298(0x8A) != 0) && (func_80105494(actor) == 0)) {
                    func_80102424(actor, 5);
                    return;
                }
                func_800FFAB0(actor);
            }
            break;

        default:
            func_800FFAB0(actor);
    }
}

void func_80800418_chdinofamilymissing();

void func_80800104_chdinofamilymissing(Actor *actor)
{
    _sudeflect_entrypoint_1(actor->position, func_80103EF4(actor), 0.0f, func_80103EAC(actor),
                            10);
    switch (actor->unk70_10) {
        case 1: // walking home (dialog 0x17CD)
            func_80800418_chdinofamilymissing(actor);
            func_80105834(actor);
            if (func_80105998(actor, 0.15f)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17CD, 0xF, actor->position, 0x39);
            }
            if (func_80105A5C(actor)) {
                _glcutDll_entrypoint_24(0x118, -1, 0x35);
                func_800FFAB0(actor);
            }
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_808006A0_chdinofamilymissing, 0.47f);
            break;
        case 2:
            if (func_80105A5C(actor)) {
                func_800DA524(0x588);
                func_80102424(actor, 3);
                *((u8 *) actor + 0x77) &= ~0xF;
            } else {
                func_80800418_chdinofamilymissing(actor);
                func_80105834(actor);
            }
            _subaddieaudioquick_entrypoint_3(actor, actor->position,
                                             D_808006A0_chdinofamilymissing, 0.47f);
            break;
        case 3: // arrived: set flag 0x8A
            if (func_80105A5C(actor)) {
                func_800DA544(0x8A);
                func_80101180(0x290, 0x33, 2);
                func_80102424(actor, 4);
            }
        case 4:
            break;
        case 5: // talking family member (dialog 0x17CE)
            _sudeflect_entrypoint_1(actor->position, actor->scale * 235.0f, 0.0f,
                                    actor->scale * 179.0f, 30);
            if (_subaddiedialog_entrypoint_4(actor->position, 600, 0)) {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x17CE, 0xF, actor->position, 0x39);
            }
    }
    _chdinofamilyfx_entrypoint_0(actor);
}

int func_80800324_chdinofamilymissing(s32 actor, s32 msg_arg)
{
    int dialog_id; // Matching: extra temporary for the constant 0x2831.
    switch (func_800EA05C(actor)) {
        case 0x114:
            dialog_id = 0x2831;
            if (_glcutDll_entrypoint_19(0x35) != 0) {
                func_80102424(actor, 1);
                _capod_entrypoint_13(*(s32 *) ((char *) actor + 0x0), 0, 5, dialog_id);
                return 1;
            }
            break;

        case 0x118:
            if ((_glcutDll_entrypoint_19(0x35) != 0) && (func_80105494(actor) != 0)) {
                func_80102424(actor, 2);
                _capod_entrypoint_13(*(s32 *) ((char *) actor + 0x0), 0, 0xC, 0x2831);
                return 1;
            }
            if ((_glcutDll_entrypoint_19(0x38) != 0) && (func_80105494(actor) != 0)) {
                func_800FFAB0(actor);
                return 1;
            }
    }

    return 0;
}

// Walk speed from the anim curve; 0.75x in state 1.
void func_80800418_chdinofamilymissing(Actor *actor)
{
    f32 curve;

    curve = func_800F3780(func_80101F24(actor), D_808006AC_chdinofamilymissing, 4);
    func_80105A9C(actor, (actor->unk70_10 == 1 ? 0.75f : 1.0f) * (curve * 1200.0f));
}

int func_808004A4_chdinofamilymissing(Actor *actor, s32 msg, s32 msg_arg)
{
    switch (msg) {
        case 0x49:
            return func_80800324_chdinofamilymissing(actor, msg_arg);
        case 0x1F:
            func_801015D0(actor);
            if (*(u16 *) (D_80800664_chdinofamilymissing + actor->unk70_10 * 8) == 0x14D) {
                func_800DF744(3, 1);
                return 1;
            }
            func_800DF744(1, 0);
            func_800DF744(2, 1);
            func_800DF744(3, 2);
            return 1;
        case 0x52:
            _gcdialogcamera_entrypoint_4(actor->position);
            _gcdialogcamera_entrypoint_3(D_808006CC_chdinofamilymissing, actor->scale);
            return 3;
        case 0xB:
            if (msg_arg == 12 && _glcutDll_entrypoint_19(0x35)) {
                if (func_800DA298(0x189) && func_800DA298(0x15E)) {
                    _glcutDll_entrypoint_24(0x114, -1, 0x38);
                    return 3;
                }
                if (!func_800DA298(0x15E) || func_800DA298(0x189) || !func_800DA298(0x15F))
                    _glcutDll_entrypoint_17();
            }
            return 3;
        default:
            return 0;
    }
}

int chdinofamilymissing_entrypoint_0()
{
    return (int) D_808006DC_chdinofamilymissing;
}

extern void func_801018A4();
extern void func_80107C2C();
extern u8 boot_thread_stack[];
u32 D_80800660_chdinofamilymissing[1] = {0x0};
u8 D_80800664_chdinofamilymissing[60] = {
    0x0,  0x0,  0x0,  0x0,  0x3F, 0x0,  0x0,  0x0,  0x1,  0x4C, 0x0,  0x1,  0x3E, 0xB3, 0x33,
    0x33, 0x1,  0x4C, 0x0,  0x1,  0x40, 0xC,  0xCC, 0xCD, 0x3,  0xF8, 0x0,  0x1,  0x40, 0xC,
    0xCC, 0xCD, 0x3,  0xF8, 0x0,  0x1,  0x40, 0xC,  0xCC, 0xCD, 0x3,  0xF8, 0x0,  0x1,  0x40,
    0xC,  0xCC, 0xCD, 0x3,  0xF8, 0x0,  0x1,  0x40, 0xC,  0xCC, 0xCD, 0x3,  0xF8, 0x0,  0x1};
u8 D_808006A0_chdinofamilymissing[12] = {0x0, 0x13, 0x4, 0x4C, 0x0, 0xA,
                                         0x0, 0xB3, 0x0, 0x0,  0x0, 0x0};
s32 D_808006AC_chdinofamilymissing[8] = {0x0,        0x3F800000, 0x3E800000, 0x3F400000,
                                         0x3F000000, 0x3F800000, 0x3F400000, 0x3F400000};
u8 D_808006CC_chdinofamilymissing[16] = {0x43, 0x48, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0,
                                         0x43, 0x48, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0};
int D_808006DC_chdinofamilymissing[21] = {0x12B0293,
                                          0x6CC0001,
                                          (u32) &D_80800660_chdinofamilymissing,
                                          (u32) func_80800104_chdinofamilymissing,
                                          (u32) func_80800104_chdinofamilymissing,
                                          (u32) func_801018A4,
                                          0x13880000,
                                          0x40000000,
                                          0x0,
                                          0x840100,
                                          0x0,
                                          0x0,
                                          0x0,
                                          (u32) func_80800000_chdinofamilymissing,
                                          (u32) func_80107C2C,
                                          (u32) ((u8 *) boot_thread_stack + 0xF26),
                                          (u32) func_808004A4_chdinofamilymissing,
                                          0x0,
                                          0x0,
                                          0x0,
                                          0x0};
