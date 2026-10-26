#include "common.h"

extern void *D_808004F4_chattract;
extern u8 D_8080046A_chattract[];
extern u8 D_8080046C_chattract[];
extern u8 D_80800470_chattract[];
extern f32 func_800D8FF8(void);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_801015D0(void);
extern void func_800DF944(void *, f32 *, f32, f32, s32, s32, s32);
typedef struct { u16 local_0; u8 local_1; u8 pad_0; f32 local_2; f32 pad_1; f32 local_3; s16 local_4; s16 local_5; f32 local_6; u8 local_7; u8 pad_2[3]; } AttractEntry26;
typedef struct { u8 pad_0[0x7A]; u8 local_0:2; u8 pad_1:6; } AttractFlags26;
extern AttractEntry26 D_80800468_chattract[];
extern void _subaddiefade_entrypoint_2(Actor *);
extern void _chattract_entrypoint_2(void);
extern void _chbaddiesetup_entrypoint_1(void *, s32);
typedef struct { u8 unused[0x12]; u16 type : 15; u16 enabled : 1; } AttractMarkerType;
extern f32 B_80800540_chattract[];
extern Actor *func_80108454(s32, f32 *, s32);

void *chattract_entrypoint_0()
{
  return &D_808004F4_chattract;
}

void func_8080000C_chattract(s32 arg0) 
{
}
void func_80800014_chattract(Actor *param_0)
{
    u8 *local_0;

    if (param_0->unk54 != 0.0f) {
        param_0->rotation[1] += param_0->unk54 * func_800D8FF8();
    }
    if (param_0->unk79_4) {
        if ((*(u16 *)((u8 *)param_0 + 0x78) & 3) == 0 && func_800D9078(&param_0->unk58)) {
            if (D_8080046A_chattract[param_0->unk74_7 * 28]) {
                _subaddiefade_entrypoint_2(param_0);
            } else {
                _subaddiefade_entrypoint_1(param_0, 255);
            }
            param_0->unk58 = *(f32 *)(D_8080046C_chattract + param_0->unk74_7 * 28);
            param_0->unk79_4 = 0;
            func_80102424(param_0, param_0->unk70_10);
        }
    } else {
        if ((*(u16 *)((u8 *)param_0 + 0x78) & 3) == 0 && func_800D9078(&param_0->unk58)) {
            local_0 = ((u8 *) D_80800468_chattract) + param_0->unk74_7 * 28;
            if (*(f32 *)(local_0 + 8) != 0.0f) {
                if (local_0[3]) {
                    _subaddiefade_entrypoint_5(param_0);
                } else {
                    _subaddiefade_entrypoint_1(param_0, 0);
                }
                param_0->unk58 = *(f32 *)(D_80800470_chattract + param_0->unk74_7 * 28);
                param_0->unk79_4 = 1;
            } else if (local_0[3]) {
                _subaddiefade_entrypoint_3(param_0);
            } else {
                func_800FFAB0(param_0);
            }
        }
    }
}

void func_80800204_chattract(Actor *param_0, void *param_1)
{
    f32 local_0[3];
    if (param_0->rotation[1] != 0) {
        func_800EFA4C(local_0, 0.0f, param_0->rotation[1], 0.0f);
        func_800DF4CC(local_0);
    }
    func_800DF410(param_0->alpha);
    func_800DF47C(func_801015D0, param_0);
    func_800DF944(param_1, param_0->position, 0.0f, param_0->scale, 0, 1, func_8010347C(param_0->unk0));
}

s32 func_808002AC_chattract(Actor *param_0, s32 param_1, s32 param_2)
{
    AttractEntry26 *local_0;

    if (param_1 == 0x95) {
        local_0 = &D_80800468_chattract[param_0->unk74_7];
        func_80103140(param_0, local_0->local_0, 0);
        func_80102424(param_0, param_0->unk74_7);
        param_0->unk58 = local_0->local_2;
        param_0->scale = local_0->local_3;
        ((AttractFlags26 *)param_0)->local_0 = local_0->local_7;
        if (local_0->local_1) {
            _subaddiefade_entrypoint_2(param_0);
        }
        param_0->position[0] = local_0->local_4;
        param_0->position[1] = local_0->local_5;
        param_0->unk54 = local_0->local_6;
        param_0->unk79_4 = 0;
        return 1;
    }
    return 0;
}

void chattract_entrypoint_1(s32 param_0) {
    _chbaddiesetup_entrypoint_1(_chattract_entrypoint_2, param_0);
}

void chattract_entrypoint_2(s32 param_0)
{
    Actor *local_0;

    local_0 = func_80108454(0x4B5, B_80800540_chattract, 0);
    if (local_0 != NULL) {
        local_0->unk74_7 = param_0 + 1;
        ((AttractMarkerType *)local_0->unk0)->type = 1;
        func_800EC828();
    }
}
