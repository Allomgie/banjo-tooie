#include "ch/conga.h"

extern int D_808006A0_chconga;
typedef union { s32 local_0; s16 local_1[2]; } CongaEvent;
extern s32 D_808006E8_chconga[];
extern void *func_80100094(Actor *, u32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern void func_80105A9C(Actor *, f32);
extern s16 D_808006FE_chconga;
extern s16 D_808006FC_chconga;
extern u8 D_808006F8_chconga[];
extern s32 D_80800714_chconga;
extern s32 D_80800724_chconga;
extern void _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
void func_80800374_chconga();
int func_80800478_chconga();
int func_808004BC_chconga();

int *chconga_entrypoint_0()
{
    return &D_808006A0_chconga;
}

void func_8080000C_chconga(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;

    local_0 = func_800DA298(0x17F);
    local_1 = func_800F64A4(func_800F54E4(), 1);
    local_2 = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(param_0, 5);
        goto block_10;
    }
    if (func_800DA298(0x9C) != 0) {
        func_800FFAB0(param_0);
        return;
    }
    if ((local_2 != 0) && (local_0 == 0)) {
        func_80102424(param_0, 4);
        func_80105A9C(param_0, 4e+02f);
        goto block_10;
    }
    if ((local_0 != 0) && (local_1 != 0)) {
        func_800FFAB0(param_0);
        return;
    }
block_10:
    _subaddieitem_entrypoint_0(func_80100094(param_0, 0), 0x4E2, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(param_0, 0), 4);
}

void func_80800538_chconga();

void func_80800118_chconga(Actor *param_0)
{
    f32 local_0[3];

    _suexpression_entrypoint_10(func_80100094(param_0, 1), param_0->unk0, 0);
    switch (param_0->unk70_10) {
    case 1:
        func_800D1824(0x4D);
        func_80800538_chconga(param_0);
        func_80800618_chconga(param_0);
        break;
    case 2:
        func_800D1824(0x4D);
        func_80800618_chconga(param_0);
        break;
    case 3:
        func_800D1824(0x4D);
        func_80103DFC(param_0, local_0);
        if (_subaddieitem_entrypoint_3(param_0, local_0, func_80100094(param_0, 0))) {
            func_800DA544(0x4A);
            func_80102424(param_0, 2);
            _subaddiedialog_entrypoint_11(param_0->unk0, *(s32 *)((u8 *)param_0 + 0x28),
                0xE, param_0->position, 0x52);
            if (func_800C6E38(0x1B) && func_800C6E38(0x2D)) func_80101180(0x46E, 7, 0);
        }
        break;
    case 4: func_80105854(param_0); break;
    case 5: func_80800618_chconga(param_0); break;
    }
    _sudeflect_entrypoint_0(param_0->position, 150.0f, 175.0f, 0xA);
}

void func_80800280_chconga(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808002A0_chconga(Actor *param_0, s32 param_1, CongaEvent param_2)
{
    switch (param_1) {
        case 0x2E:
            func_80800374_chconga(param_0, param_2.local_1[0], param_2.local_1[1]);
            break;
        case 0x30:
            return func_80800478_chconga(param_0, param_2.local_1[0], param_2.local_1[1]);
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_808006E8_chconga, param_0->scale);
            break;
        case 0x95:
            _suexpression_entrypoint_7(param_0, 1, 0x52);
            _suexpression_entrypoint_12(func_80100094(param_0, 1), 45.0f, 15.0f);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800374_chconga(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    switch (param_1) {
        case 0x10B1:
            param_0->actorData[4] = func_808004BC_chconga(param_0, 0x10F2);
            _subaddieitem_entrypoint_2(func_80100094(param_0, 0));
            func_80102424(param_0, 3);
            break;
        case 0x10B3:
            param_0->actorData[4] = func_808004BC_chconga(param_0, 0x10F3);
            _subaddieitem_entrypoint_2(func_80100094(param_0, 0));
            func_80102424(param_0, 3);
            break;
        case 0x10F2:
        case 0x10F3:
        case 0x1101:
            func_80102424(param_0, 4);
            func_80105A9C(param_0, 400.0f);
            func_80101180(0x13C, 10, 0);
            break;
        default:
            func_80102424(param_0, 1);
            break;
    }
}

int func_80800478_chconga(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
    s32 local_0;

    if (param_1 == 0x10B0 || param_1 == 0x10B1) {
        return func_800D1A04(0x4D);
    }
    local_0 = 0;
    return local_0;
}

int func_808004BC_chconga(param_0, param_1) s32 param_0; s32 param_1;
{
    int local_0;

    if (func_800C6E38(0x1B) && func_800C6E38(0x2D)) {
        local_0 = param_1;
    } else if (func_800C6E38(0x1B)) {
        local_0 = 0x1112;
    } else if (func_800C6E38(0x2D)) {
        local_0 = 0x10FF;
    } else {
        local_0 = 0x1113;
    }
    return local_0;
}

void func_80800538_chconga(Actor *param_0)
{
    if (func_800DA298(0x4A) && func_800F64A4(func_800F54E4(), 1)) {
        D_808006FE_chconga = func_808004BC_chconga(param_0, 0x1101);
    } else {
        if (func_800D1A04(0x4D) >= 4) D_808006FC_chconga = 0x10B1;
        else D_808006FC_chconga = 0x10B0;
        if (func_800D1A04(0x4D) >= 4) D_808006FE_chconga = 0x10B3;
        else D_808006FE_chconga = 0x10B2;
    }
    if (_subaddiedialog_entrypoint_7(param_0, param_0->position, D_808006F8_chconga) == 0x1101) func_80101180(0x46E, 7, 0);
}

int func_80800618_chconga(s32 param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  _subaddieaudioquick_entrypoint_4(param_0, local_0, &D_80800714_chconga, &D_80800724_chconga);
}
