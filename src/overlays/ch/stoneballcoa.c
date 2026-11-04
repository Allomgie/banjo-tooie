// Most likely the Mayan Kickball coach: faces the player and, if the player is a Stony, talks about
// the next round (chosen by the won-round flags); otherwise warns to transform first.
#include "common.h"

extern u8 D_808003B8_chstoneballcoach[];
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern f32 func_8010CD28(void);
extern int func_80102CF4(void *arg0, float arg1);
extern void func_80102B2C(void *arg0, float arg1);
extern u8 D_808003C8_chstoneballcoach[];
extern f32 func_800DC0C0(void);
extern void func_80101EE4(s32, f32);
extern int D_808003D4_chstoneballcoach[];

s32 func_80800000_chstoneballcoach(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808003B8_chstoneballcoach, param_0->scale);
            break;
        case 0x2E:
            param_0->unk70_10 = 1;
            break;
        case 0x1F:
            func_801015D0(param_0);
            func_800DF744(3, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800090_chstoneballcoach(u8 *param_0, s32 param_1, s32 param_2)
{
    u8 *new_var3;
    char new_var;
    s8 *new_var2;
    new_var3 = &*(u8 *) ((s8 *) param_0 + 0x72);
    new_var = 0x34;
    if (param_1 != 0) {
        func_800C05B8(param_1, param_2, param_0 + 4, *(s32 *) ((s8 *) param_0 + 0), 0, 0, new_var);
        new_var2 = (s8 *) param_0;
        *(u8 *) (new_var2 + 0x72) = (u8) ((*new_var3 & 0xFF03) | 8);
        *(u8 *) ((s8 *) param_0 + 0x74) = (u8) ((*(u8 *) ((s8 *) param_0 + 0x74) & 0xFFFFu) | 0x40);
    }
}

void func_80800100_chstoneballcoach(u8 *param_0)
{
    *(f32 *) ((u8 *) param_0 + 0x54) = func_8010CD28();
    if (func_80102CF4(param_0, 1.0f) == 0) {
        func_80102B2C(param_0, 1.0f);
    }
}

void func_80800140_chstoneballcoach(Actor *actor)
{
    s32 dialog_id;
    s32 dialog_flags;

    if (func_80090128()) {
        func_8010C820(actor, 0x8C, 30);
        func_80800100_chstoneballcoach(actor);
    }
    if (actor->unk70_10 == 1) {
        if (func_80090178(0x80)) {
            if (func_8010CAC0(D_808003C8_chstoneballcoach, 150)) {
                if (!func_800DA9E4(0x428, 1)) {
                    func_80800090_chstoneballcoach(actor, 0xF23, 6);
                }
            } else if (func_8010CAC0(actor->position, 200) && func_8008FA60(0x80, 0)) {
                dialog_flags = 6;
                dialog_id = 0;
                if (!func_800DA9E4(actor->unk74_7 + 0x3F3, 1)) {
                    if (func_800DA298(0x5F)) {
                        dialog_id = actor->unk74_7 + 0xEF8;
                    } else if (func_800DA298(0x5E)) {
                        dialog_id = actor->unk74_7 + 0xEF5;
                    } else {
                        dialog_id = actor->unk74_7 + 0xEF2;
                    }
                    dialog_flags = 0xE;
                } else if (func_80090080() && func_80016B30(0, 1)) {
                    if (func_800DA298(0x5F)) {
                        dialog_id = actor->unk74_7 + 0xF18;
                    } else if (func_800DA298(0x5E)) {
                        dialog_id = actor->unk74_7 + 0xF15;
                    } else {
                        dialog_id = actor->unk74_7 + 0xF12;
                    }
                    dialog_flags = 0xE;
                }
                func_80800090_chstoneballcoach(actor, dialog_id, dialog_flags);
            }
        } else if (_subaddiedialog_entrypoint_6(actor->position, (s32) actor->rotation[1], 150,
                                                70, 6)) {
            func_80800090_chstoneballcoach(actor, actor->unk74_7 + 0xF21, 0xE);
        }
    }
}

void func_8080035C_chstoneballcoach(s32 param_0)
{
    func_80101EE4(param_0, func_800DC0C0());
}

int *chstoneballcoach_entrypoint_0()
{
    return &D_808003D4_chstoneballcoach;
}
// TU-NOTE: the .data of this overlay is defined in C. Its tables hold pointers to functions of
// this file; IDO's assembler schedules some of them differently unless they share the unit.

extern void func_80105834();
extern void func_801018A4();
extern void func_80107C2C();
u32 D_808003A0_chstoneballcoach[6] = {0x0, 0x0, 0x40800000, 0x7B0000, 0x40800000, 0x7B0000};
u8 D_808003B8_chstoneballcoach[16] = {0x43, 0x20, 0x0, 0x0, 0x42, 0xC8, 0x0, 0x0,
                                      0x42, 0xC8, 0x0, 0x0, 0x42, 0x20, 0x0, 0x0};
u8 D_808003C8_chstoneballcoach[12] = {0xC4, 0x96, 0x0,  0x0,  0xC3, 0xAF,
                                      0x0,  0x0,  0xC3, 0xAF, 0x0,  0x0};
int D_808003D4_chstoneballcoach[19] = {0x2570173,
                                       0x6760001,
                                       (u32) &D_808003A0_chstoneballcoach,
                                       (u32) func_80800140_chstoneballcoach,
                                       (u32) func_80105834,
                                       (u32) func_801018A4,
                                       0x0,
                                       0x0,
                                       0x0,
                                       0x80004,
                                       0x0,
                                       0x0,
                                       0x0,
                                       (u32) func_8080035C_chstoneballcoach,
                                       (u32) func_80107C2C,
                                       -0x7FFFFFFE,
                                       (u32) func_80800000_chstoneballcoach,
                                       0x0,
                                       0x0};
