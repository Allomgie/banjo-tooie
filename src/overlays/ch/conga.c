#include "ch/conga.h"

extern int D_808006A0_chconga[];
typedef union {
    s32 word;
    s16 half[2];
} CongaEvent;
extern s32 D_808006E8_chconga[];
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void func_80105A9C(Actor *, f32);
extern s16 D_808006FE_chconga;
extern s16 D_808006FC_chconga;
extern u8 D_808006F8_chconga[];
extern s32 D_80800714_chconga[];
extern s32 D_80800724_chconga[];
extern void _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
void func_80800374_chconga();
int func_80800478_chconga();
int func_808004BC_chconga();

int *chconga_entrypoint_0()
{
    return &D_808006A0_chconga;
}

void func_8080000C_chconga(Actor *actor)
{
    s32 retry_flag;
    s32 unk_0;
    s32 unk_1;

    retry_flag = func_800DA298(0x17F);
    unk_0 = func_800F64A4(func_800F54E4(), 1);
    unk_1 = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(actor, 5);
        goto block_10;
    }
    if (func_800DA298(0x9C) != 0) {
        func_800FFAB0(actor);
        return;
    }
    if ((unk_1 != 0) && (retry_flag == 0)) {
        func_80102424(actor, 4);
        func_80105A9C(actor, 4e+02f);
        goto block_10;
    }
    if ((retry_flag != 0) && (unk_0 != 0)) {
        func_800FFAB0(actor);
        return;
    }
block_10:
    _subaddieitem_entrypoint_0(func_80100094(actor, 0), 0x4E2, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(actor, 0), 4);
}

void func_80800538_chconga();

void func_80800118_chconga(Actor *actor)
{
    f32 item_pos[3];

    _suexpression_entrypoint_10(func_80100094(actor, 1), actor->unk0, 0);
    switch (actor->unk70_10) {
        case 1:
            func_800D1824(0x4D);
            func_80800538_chconga(actor);
            func_80800618_chconga(actor);
            break;
        case 2:
            func_800D1824(0x4D);
            func_80800618_chconga(actor);
            break;
        case 3:
            func_800D1824(0x4D);
            func_80103DFC(actor, item_pos);
            if (_subaddieitem_entrypoint_3(actor, item_pos, func_80100094(actor, 0))) {
                func_800DA544(0x4A);
                func_80102424(actor, 2);
                _subaddiedialog_entrypoint_11(actor->unk0, *(s32 *) ((u8 *) actor + 0x28), 0xE,
                                              actor->position, 0x52);
                if (func_800C6E38(0x1B) && func_800C6E38(0x2D))
                    func_80101180(0x46E, 7, 0);
            }
            break;
        case 4:
            func_80105854(actor);
            break;
        case 5:
            func_80800618_chconga(actor);
            break;
    }
    _sudeflect_entrypoint_0(actor->position, 150.0f, 175.0f, 0xA);
}

void func_80800280_chconga(Actor *actor)
{
    _suexpression_entrypoint_8(actor, 1);
}

s32 func_808002A0_chconga(Actor *actor, s32 msg, CongaEvent arg)
{
    switch (msg) {
        case 0x2E:
            func_80800374_chconga(actor, arg.half[0], arg.half[1]);
            break;
        case 0x30:
            return func_80800478_chconga(actor, arg.half[0], arg.half[1]);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808006E8_chconga, actor->scale);
            break;
        case 0x95:
            _suexpression_entrypoint_7(actor, 1, 0x52);
            _suexpression_entrypoint_12(func_80100094(actor, 1), 45.0f, 15.0f);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800374_chconga(actor, dialog_id, param_2) Actor *actor;
s32 dialog_id;
s32 param_2;
{
    switch (dialog_id) {
        case 0x10B1:
            actor->actorData[4] = func_808004BC_chconga(actor, 0x10F2);
            _subaddieitem_entrypoint_2(func_80100094(actor, 0));
            func_80102424(actor, 3);
            break;
        case 0x10B3:
            actor->actorData[4] = func_808004BC_chconga(actor, 0x10F3);
            _subaddieitem_entrypoint_2(func_80100094(actor, 0));
            func_80102424(actor, 3);
            break;
        case 0x10F2:
        case 0x10F3:
        case 0x1101:
            func_80102424(actor, 4);
            func_80105A9C(actor, 400.0f);
            func_80101180(0x13C, 10, 0);
            break;
        default:
            func_80102424(actor, 1);
    }
}

int func_80800478_chconga(param_0, dialog_id, param_2)
s32 param_0;
s32 dialog_id;
s32 param_2;
{
    s32 result;

    if (dialog_id == 0x10B0 || dialog_id == 0x10B1) {
        return func_800D1A04(0x4D);
    }
    result = 0;
    return result;
}

// Picks a dialog from the Airborne Egg Aiming and Grenade Eggs abilities.
int func_808004BC_chconga(param_0, default_dialog)
s32 param_0;
s32 default_dialog;
{
    int dialog_id;

    if (func_800C6E38(0x1B) && func_800C6E38(0x2D)) {
        dialog_id = default_dialog;
    } else if (func_800C6E38(0x1B)) {
        dialog_id = 0x1112;
    } else if (func_800C6E38(0x2D)) {
        dialog_id = 0x10FF;
    } else {
        dialog_id = 0x1113;
    }
    return dialog_id;
}

void func_80800538_chconga(Actor *actor)
{
    if (func_800DA298(0x4A) && func_800F64A4(func_800F54E4(), 1)) {
        D_808006FE_chconga = func_808004BC_chconga(actor, 0x1101);
    } else {
        if (func_800D1A04(0x4D) >= 4)
            D_808006FC_chconga = 0x10B1;
        else
            D_808006FC_chconga = 0x10B0;
        if (func_800D1A04(0x4D) >= 4)
            D_808006FE_chconga = 0x10B3;
        else
            D_808006FE_chconga = 0x10B2;
    }
    if (_subaddiedialog_entrypoint_7(actor, actor->position, D_808006F8_chconga) == 0x1101)
        func_80101180(0x46E, 7, 0);
}

int func_80800618_chconga(s32 actor)
{
    s32 pos;
    pos = actor + 4;
    _subaddieaudioquick_entrypoint_4(actor, pos, &D_80800714_chconga, &D_80800724_chconga);
}

extern void func_80101870();
extern void func_80107C2C();
u32 D_80800670_chconga[12] = {0x0,        0x0,      0x40D66666, 0xFE0000,  0x40D66666, 0xFE0000,
                              0x40D66666, 0xFE0000, 0x3F4CCCCD, 0x3ED0000, 0x40D66666, 0xFE0000};
int D_808006A0_chconga[18] = {0x1B50333,
                              0x6930001,
                              (u32) &D_80800670_chconga,
                              (u32) func_80800118_chconga,
                              (u32) func_80800118_chconga,
                              (u32) func_80101870,
                              0x0,
                              0x40400000,
                              0x0,
                              0x40120,
                              (u32) func_80800280_chconga,
                              0x0,
                              0x140000,
                              (u32) func_8080000C_chconga,
                              (u32) func_80107C2C,
                              -0x7FFFFBEE,
                              (u32) func_808002A0_chconga,
                              0x0};
s32 D_808006E8_chconga[4] = {0x43AB8000, 0x43AB8000, 0x43AB8000, 0x432B8000};
u8 D_808006F8_chconga[4] = {0x0, 0xA1, 0x1, 0x90};
s16 D_808006FC_chconga = 0x0;
static u32 D_808006FC_chconga_rest[5] = {0x1, 0x120E0000, 0x520000, 0xC063C, 0x2000000};
s32 D_80800714_chconga[4] = {0x130417, 0xD0166, 0x1800016, 0x2EE00000};
s32 D_80800724_chconga[7] = {0x3ED70A3D, 0x3EF5C28F, 0x3F0A3D71, 0x3F2E147B,
                             0x3F400000, 0x3F4F5C29, -0x40800000};
