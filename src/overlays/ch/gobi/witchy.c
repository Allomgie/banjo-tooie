// Gobi in Witchyworld: once freed he talks to the player (dialog 0x107B), then walks off
// along a path and triggers the cutscene to Hailfire Peaks. Before that he only idles.
#include "common.h"

extern int D_80800410_chgobiwitchy[];
extern u8 D_80800458_chgobiwitchy[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void *_suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _suexpression_entrypoint_14(void *, f32, f32);
extern void *func_80100094(Actor *, u32);
extern void _capod_entrypoint_22(void);
extern u8 D_80800468_chgobiwitchy[];
extern u8 D_808003C0_chgobiwitchy[];
extern s32 func_8008FB10(f32 *, f32, f32, f32);
extern void _chbadshad_entrypoint_2(Actor *, s32, f32, s32);
extern void _chgobicommon_entrypoint_0(Actor *);
void func_8080024C_chgobiwitchy();

int chgobiwitchy_entrypoint_0()
{
    return (int) &D_80800410_chgobiwitchy;
}

void func_808002DC_chgobiwitchy();

// Per-frame update; unk70_10 is the state.
void func_8080000C_chgobiwitchy(Actor *actor)
{
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(actor), actor->unk0, 0);
    _chgobicommon_entrypoint_0(actor);
    func_8008FB10(actor->position, 240.0f, 0.0f, 150.0f);
    switch (actor->unk70_10) {
        case 1:
            func_808002DC_chgobiwitchy(actor);
            break;
        case 4:
            func_80105834(actor);
            if (func_80105A5C(actor)) {
                func_800FFAB0(actor);
                _capod_entrypoint_14();
                if (_gclevel_entrypoint_3(0x17)) { // cutscene to Hailfire Peaks lava side
                    _glcutDll_entrypoint_6(0x127, 0x47);
                }
            }
        case 2:
            break;
    }
    _chbadshad_entrypoint_2(actor, 1, actor->scale * 2.4f, 0);
}

s32 func_80800104_chgobiwitchy(Actor *actor, s32 event, s32 payload)
{
    void *expression;

    switch (event) {
        case 0x2E:
            func_8080024C_chgobiwitchy(actor, ((s16 *) &payload)[0], ((s16 *) &payload)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800458_chgobiwitchy, actor->scale);
            break;
        case 0x95:
            expression = _suexpression_entrypoint_7(actor, 1, 0x38);
            _suexpression_entrypoint_12(expression, 40.0f, 60.0f);
            _suexpression_entrypoint_14(expression, 1.0f, 1.0f);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808001C8_chgobiwitchy(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

void func_808001E8_chgobiwitchy(u8 *actor)
{
    if (func_800DA298(0x97) != 0) {
        func_800FFAB0(actor);
        return;
    }
    func_80105A9C(actor, 0x43FA0000);
    func_80102FDC(actor, 0x3E800000);
    *(u8 *) ((s8 *) actor + 0x95) = (u8) ((*(u8 *) ((s8 *) actor + 0x95) & 0xFFFFu) | 1);
}

void func_8080024C_chgobiwitchy(actor, dialog_id, unk_2) Actor *actor;
s32 dialog_id;
s32 unk_2;
{
    _capod_entrypoint_22();
    if (dialog_id == 0x107B) {
        _suexpression_entrypoint_12(func_80100094(actor, 1), 0.0f, 0.0f);
        func_80101FDC(actor, 4);
        _capod_entrypoint_13(actor->unk0, 0, 1, 0x2031);
    } else
        func_80101FDC(actor, 1);
}

// Idle dialog until Gobi is freed, then starts the 0x107B dialog.
void func_808002DC_chgobiwitchy(Actor *actor)
{
    s32 started;

    started = 0;
    if (func_800DA298(0x97)) {
        if (!func_800DB9B0()) {
            func_800F82D4(func_800F54E4(), 0);
            func_800DA524(0x87);
            _subaddiedialog_entrypoint_11(actor->unk0, 0x107B, 0xE, 0, 0x38);
            func_80101FDC(actor, 3);
            started = 1;
        }
    } else {
        started = _subaddiedialog_entrypoint_8(actor, actor->position, D_80800468_chgobiwitchy,
                                               D_808003C0_chgobiwitchy, 5);
    }
    if (started) {
        _capod_entrypoint_21(actor->unk0, 0, 0xA, 0);
    }
}

// TU-NOTE: the overlay .data tables are defined in this file; their function pointers need them in the same unit for IDO to schedule the code as in the original. Values are from the ROM.
extern void func_80102EC0();
extern void func_80101870();
extern void func_80107C2C();
u8 D_808003C0_chgobiwitchy[40] = {0x0,  0x0,  0x0,  0x1,  0x10, 0x79, 0x1,  0x0, 0x0,  0x0,
                                  0x6,  0x1,  0x10, 0x7A, 0x2,  0x0,  0x0,  0x0, 0x2,  0x0,
                                  0x11, 0x16, 0x1,  0x0,  0x0,  0x0,  0x4,  0x0, 0x11, 0x17,
                                  0x1,  0x0,  0xFF, 0xFE, 0xDF, 0xFF, 0x12, 0xB, 0x3,  0x0};
u32 D_808003E8_chgobiwitchy[10] = {0x0,       0x0,        0x413CCCCD, 0x2210000,  0x413CCCCD,
                                   0x2210000, 0x40900000, 0x2220000,  0x3F07AE14, 0x2230000};
int D_80800410_chgobiwitchy[18] = {0x1880137,
                                   0x7880001,
                                   (u32) &D_808003E8_chgobiwitchy,
                                   (u32) func_80102EC0,
                                   (u32) func_8080000C_chgobiwitchy,
                                   (u32) func_80101870,
                                   0x0,
                                   0x4119999A,
                                   0x0,
                                   0x40040128,
                                   (u32) func_808001C8_chgobiwitchy,
                                   0x0,
                                   0x0,
                                   (u32) func_808001E8_chgobiwitchy,
                                   (u32) func_80107C2C,
                                   -0x7FFFFBEE,
                                   (u32) func_80800104_chgobiwitchy,
                                   0x0};
u8 D_80800458_chgobiwitchy[16] = {0x43, 0x16, 0x0, 0x0, 0x43, 0xFA, 0x0, 0x0,
                                  0x43, 0x8C, 0x0, 0x0, 0x42, 0xF0, 0x0, 0x0};
u8 D_80800468_chgobiwitchy[24] = {0x0, 0x87, 0x0, 0x0, 0x2, 0x58, 0x0, 0x38, 0x0, 0x0, 0x0, 0xE,
                                  0x0, 0x0,  0x2, 0x0, 0x0, 0x0,  0x0, 0x0,  0x0, 0x0, 0x0, 0x0};
