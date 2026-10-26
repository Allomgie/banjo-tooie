#include "common.h"

extern int D_808004E0_chdinocoaster;
extern void _sucoaster_entrypoint_0();
extern void func_80102FDC(u8 *, f32);
extern u8 D_80800528_chdinocoaster[];
extern f32 func_8010CD28(Actor *);
extern void func_80102BF8(Actor *, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern f32 func_800F1FF0(f32, f32, f32, f32, f32);
extern s32 func_800F20BC(f32, f32, f32);
extern s32 func_80101E14(Actor *, f32);
extern u8 D_80800468_chdinocoaster[];
extern u8 D_80800544_chdinocoaster[];
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern s32 func_800F1B78(f32 *, f32 *, f32, f32);
extern f32 func_800F1F38(f32, f32, f32);
void func_808002CC_chdinocoaster();

int chdinocoaster_entrypoint_0()
{
    return (int)&D_808004E0_chdinocoaster;
}

void func_8080000C_chdinocoaster(u8 *param_0) {
    _sucoaster_entrypoint_0(param_0, 0);
    func_80102FDC(param_0, *(f32 *)(param_0 + 0x38) * 1.25f);
    *(f32 *)(param_0 + 0x50) = 0.0f;
    *(f32 *)(param_0 + 0x28) = 0.0f;
}

void func_80800064_chdinocoaster(Actor *param_0)
{
    f32 local_0;

    switch (param_0->unk70_10) {
        case 19:
            param_0->unk54 = func_8010CD28(param_0);
            func_80102BF8(param_0, 0.1f, 1.5f, 400.0f);
            _sucoaster_entrypoint_22(param_0);
            break;
        case 20:
            local_0 = func_800D8FF8();
            param_0->rotation[1] = func_800F1FF0(param_0->rotation[1], *(f32 *)&param_0->actorData[5], 0.12f, local_0 * 8.0f, local_0 * 200.0f);
            if (func_800F20BC(param_0->rotation[1], *(f32 *)&param_0->actorData[5], 4.0f)) _sucoaster_entrypoint_10(param_0, 3);
            _sucoaster_entrypoint_22(param_0);
            break;
        case 9:
            if (func_80101E14(param_0, 0.4f)) *(f32 *)&param_0->actorData[3] = 800.0f;
            _sucoaster_entrypoint_2(param_0);
            break;
        default:
            if (!_subaddiedialog_entrypoint_7(param_0, param_0->position, D_80800528_chdinocoaster)) _sucoaster_entrypoint_2(param_0);
            else {
                *(f32 *)&param_0->actorData[5] = param_0->rotation[1];
                func_8010A570(param_0);
            }
            break;
    }
    func_808002CC_chdinocoaster(param_0);
}

s32 func_808001C8_chdinocoaster(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
        case 0x2E:
            func_80101FDC(param_0, 0x14);
            func_8010A590(param_0);
            if (*(s16 *)&param_2 == 0x17B8) {
                func_8009032C(0x20);
            }
            break;
        case 0x38:
            func_80101074(D_80800468_chdinocoaster);
            return 10;
        case 0x52:
            func_800EFA4C(local_0, 0.0f, func_8010CD28(param_0), 0.0f);
            _gcdialogcamera_entrypoint_3(D_80800544_chdinocoaster, param_0->scale);
            _gcdialogcamera_entrypoint_5(local_0);
            break;
        case 0x95:
            param_0->unk64_20 = 0;
        default:
            return _sucoaster_entrypoint_21(param_0, param_1, param_2);
    }
    return 1;
}

void func_808002CC_chdinocoaster(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2;

    func_801051C8(param_0, local_1);
    if (func_800F1B78(local_0, local_1, param_0->rotation[1], 1.0f)) {
        param_0->unk50 = local_0[0];
        *(f32 *)((u8 *)param_0 + 0x28) = local_0[2];
    } else {
        param_0->unk50 = 0.0f;
        *(f32 *)((u8 *)param_0 + 0x28) = 0.0f;
    }
    if (!param_0->unk64_20) {
        param_0->unk64_20 = 1;
        param_0->rotation[0] = param_0->unk50;
        param_0->rotation[2] = *(f32 *)((u8 *)param_0 + 0x28);
    } else {
        local_2 = func_800D8FF8();
        param_0->rotation[0] = func_800F1F38(param_0->rotation[0], param_0->unk50, local_2 * 30.0f);
        param_0->rotation[2] = func_800F1F38(param_0->rotation[2], *(f32 *)((u8 *)param_0 + 0x28), local_2 * 30.0f);
    }
}
