// Most likely the lost baby dinosaur of Terrydactyland, met in Witchyworld and riding in Chuffy's
// wagon. It talks (dialogs 0x107D-0x1080) and, once the train is parked, triggers the cutscenes
// that take it home.
#include "common.h"

extern int D_80800770_chbabydino[];
typedef union {
    s32 word;
    s16 halves[2];
} PairEventPayload;
extern void *_suexpression_entrypoint_20(Actor *);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _capod_entrypoint_22(void);
extern s32 D_80800700_chbabydino[];
extern s32 D_808007D4_chbabydino[];
extern s32 D_808007B8_chbabydino[];
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
void func_808003BC_chbabydino();
int func_808005F0_chbabydino();

int chbabydino_entrypoint_0()
{
    return &D_80800770_chbabydino;
}

void func_8080000C_chbabydino(u8 *actor)
{
    s32 map_id;
    map_id = func_800EA05C();
    if (func_80105494(actor) != 0) {
        func_80105A9C(actor, 0x43FA0000);
    }
    switch (map_id) {
        case 0xEA: // Witchyworld Cave of Horrors
            if (func_800DA298(0x98) != 0) {
                *(u8 *) ((s8 *) actor + 0x65) =
                    (u8) ((*(u8 *) ((s8 *) actor + 0x65) & 0xFFFF) | 0x10);
            }
            if ((func_800DA298(0x8A) != 0) || (func_800DA298(0x588) != 0)) {
                func_800FFAB0(actor);
                return;
            }
            func_80102424(actor, 2);
            return;

        case 0xEC: // Witchyworld train station
            if (_glcutDll_entrypoint_19(0x1F) == 0) {
                func_800FFAB0(actor);
            }
            return;

        case 0x121: // Inside Chuffy's wagon
            if (func_800DA298(0x588) != 0) {
                func_80102424(actor, 5);
                return;
            }
            func_800FFAB0(actor);
    }
}

void func_80800448_chbabydino();

// Per-frame update; unk70_10 is the state.
void func_8080011C_chbabydino(Actor *actor)
{
    _sudeflect_entrypoint_0(actor->position, actor->scale * 100.0f, actor->scale * 150.0f,
                            0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), actor->unk0, 0);
    switch (actor->unk70_10) {
        case 1:
            break;
        case 2:
            func_80800448_chbabydino(actor);
            break;
        case 3:
            if (!func_808005A0_chbabydino(actor, 1)) {
                _capod_entrypoint_14();
                if (_glcutDll_entrypoint_19(0x1F))
                    _glcutDll_entrypoint_24(0xEC, -1, 0x1F);
                else
                    _glcutDll_entrypoint_6(0xEC, 0x1F);
            }
            break;
        case 4:
            if (!func_808005A0_chbabydino(actor, 0)) {
                func_800DA544(0x588);
                func_80102424(actor, 5);
                func_800FFAB0(actor);
                _glcutDll_entrypoint_15(1);
                _glcutDll_entrypoint_17();
                _capod_entrypoint_14();
            }
            break;
        case 5:
            _subaddiedialog_entrypoint_7(actor, actor->position, &D_808007B8_chbabydino);
            break;
    }
    _chdinofamilyfx_entrypoint_0(actor);
}

void func_8080028C_chbabydino(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

// Event handler; event 0xB8 picks the dialog.
s32 func_808002AC_chbabydino(Actor *actor, s32 event, PairEventPayload payload)
{
    void *expression;
    s32 sub_event;
    switch (event) {
        case 0x2E:
            func_808003BC_chbabydino(actor, payload.halves[0], payload.halves[1]);
            break;
        case 0x49:
            return func_808005F0_chbabydino(actor, payload.word);
        case 0x95:
            _suexpression_entrypoint_7(actor, 1, 0x39);
            expression = _suexpression_entrypoint_20(actor);
            _suexpression_entrypoint_12(expression, 50.0f, 20.0f);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        case 0x1F:
            func_801015D0(actor);
            func_800DF744(3, 1);
            break;
        case 0xB8:
            sub_event = payload.word & 0xFFFF;
            switch (sub_event) {
                case 1:
                    return func_800DA298(0x98) ? 0x107F : 0x107D;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808003BC_chbabydino(actor, dialog_id, unk_2) Actor *actor;
s32 dialog_id;
s32 unk_2;
{
    if (actor->unk64_19) {
        _capod_entrypoint_22();
        actor->unk64_19 = 0;
    }
    if (dialog_id != 0x107E && dialog_id != 0x1080) {
        func_80102424(actor, func_800DA298(0x588) ? 5 : 2);
    }
}

void func_80800448_chbabydino(Actor *actor)
{
    s32 started = 0;

    if (func_800DA298(0x98) && !actor->unk64_20) {
        if (!func_800DB9B0()) {
            func_800DA544(0x89);
            actor->unk64_20 = 1;
            func_800F82D4(func_800F54E4(), 0);
            if (func_800DA298(0x4EE)) {
                func_80102424(actor, 3);
                _subaddieDll_entrypoint_4(actor, 1);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x107E, 12, 0, 0x39);
                _capod_entrypoint_13(actor->unk0, 0, 3, 0x31);
            } else {
                _subaddiedialog_entrypoint_11(actor->unk0, 0x107F, 14, 0, 0x39);
                func_80102424(actor, 1);
                started = 1;
            }
        }
    } else {
        started = _subaddiedialog_entrypoint_8(actor, actor->position, &D_808007D4_chbabydino,
                                               &D_80800700_chbabydino, 5);
    }
    if (started) {
        _capod_entrypoint_21(actor->unk0, 0, 11, 0);
        actor->unk64_19 = 1;
    }
}

int func_808005A0_chbabydino(s32 actor, s32 unk_1)
{
    func_80105834(actor);
    if (func_80105A5C(actor) != 0) {
        if (unk_1 != 0) {
            func_800FFAB0(actor);
        }
        return 0;
    }
    return 1;
}

int func_808005F0_chbabydino(actor, unk_1)
Actor *actor;
s32 unk_1;
{
    switch (func_800EA05C()) {
        case 0xEA:
            if (_glcutDll_entrypoint_19(0x1F)) {
                func_80102424(actor, 3);
                _subaddieDll_entrypoint_4(actor, 1);
                _subaddiedialog_entrypoint_11(actor->unk0, 0x1080, 0xC, 0, 0x39);
                _capod_entrypoint_13(actor->unk0, 0, 3, 0x2821);
                return 1;
            }

            break;

        case 0xEC:
            if (_glcutDll_entrypoint_19(0x1F)) {
                func_80102424(actor, 4);
                _subaddieDll_entrypoint_4(actor, 1);
                _capod_entrypoint_13(actor->unk0, 0, 7, 0x2821);
                return 1;
            }
    }

    return 0;
}

// TU-NOTE: the overlay .data tables are defined in this file; their function pointers need them in the same unit for IDO to schedule the code as in the original. Values are from the ROM.
extern void func_801018A4();
extern void func_80107C2C();
s32 D_80800700_chbabydino[10] = {0x1,        0x107C0100, 0x601,      -0xFE00,  0x200,
                                 0x11140100, 0x400,      0x11150100, -0x12001, 0x120B0300};
u32 D_80800728_chbabydino[18] = {0x0,        0x0,        0x40D00000, 0x14D0000,  0x40D00000,
                                 0x14D0000,  0x3EE66666, 0x14C0000,  0x3EE66666, 0x14C0000,
                                 0x40D00000, 0x14D0000,  0x3EE66666, 0x14C0000,  0x3EE66666,
                                 0x14C0000,  0x40D00000, 0x14D0000};
int D_80800770_chbabydino[18] = {0x1890138,
                                 0x6CC0001,
                                 (u32) &D_80800728_chbabydino,
                                 (u32) func_8080011C_chbabydino,
                                 (u32) func_8080011C_chbabydino,
                                 (u32) func_801018A4,
                                 0x0,
                                 0x40200000,
                                 0x0,
                                 0x40040120,
                                 (u32) func_8080028C_chbabydino,
                                 0x0,
                                 0x0,
                                 (u32) func_8080000C_chbabydino,
                                 (u32) func_80107C2C,
                                 -0x7FFFFBAE,
                                 (u32) func_808002AC_chbabydino,
                                 0x0};
s32 D_808007B8_chbabydino[7] = {0x2BC, 0x1081, 0x601, 0x120B0000, 0x390000, 0xC0000, 0x1000000};
s32 D_808007D4_chbabydino[7] = {0x890000, 0x2BC0039, 0xC, 0x100, 0x0, 0x0, 0x0};
