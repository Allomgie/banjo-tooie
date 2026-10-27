#include "common.h"

#define CAMERA_TRANSITION_VIEW_1202
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800F7B9C(s32, s32);
extern s32 func_80110840(void);
typedef struct { f32 local_0[3]; f32 local_1[3]; f32 local_2[3]; f32 local_3[3]; f32 local_4[3]; f32 local_5[3]; f32 local_6; } CameraTransitionData1202;
typedef struct { CameraTransitionData1202 *local_0; } CameraTransition1202;
extern void func_801163A0(void *, f32);
extern f32 func_800F130C(f32, f32, f32, f32, f32);
extern f32 func_800F1DCC(f32, f32);
extern f32 func_800136E4(f32);
typedef struct { f32 position[3]; f32 rotation[3]; f32 target_position[3]; f32 target_rotation[3]; u8 pad_0[0x20]; u8 smooth; } BaCameraTransform;
extern void func_80111410(void *, f32 *, f32 *, f32);
typedef struct { f32 local_0[6][3]; u8 pad_0[4]; s32 local_1; u8 local_2; u8 local_3; } FirstPersonCameraData;
typedef struct { FirstPersonCameraData *local_0; } FirstPersonCamera;
extern void func_80111590(void *, f32, f32, f32, f32);
extern void func_80110728();
extern void func_801107F0();
extern void func_80110818();
extern void func_800EE7F8();
typedef struct { u8 unused[0x24]; f32 angles[3]; } BaCameraOrientation;
void ncba1p_entrypoint_3();
void ncba1p_entrypoint_5();
void *D_exp_ncba1p_entrypoint_5[] = { (void *)ncba1p_entrypoint_5 };

s32 ncba1p_entrypoint_0() 
{
    return 0x54;
}

int func_80800008_ncba1p(void *param_0, f32 *param_1, f32 *param_2)
{
    return func_800EEAD4(param_1, param_2) < 40.0f;
}

void func_8080004C_ncba1p(u8 **param_0, s32 param_1)
{
  s32 temp_a0;
  u8 *ptr;
  temp_a0 = func_80110840();
  ;
  if ((*param_0)[0x51] == 0)
  {
    func_800F7B9C(temp_a0, param_1);
    ptr = *param_0;
    temp_a0 = 1;
    (*param_0)[0x51] = temp_a0;
  }
}

void func_808000A0_ncba1p(CameraTransition1202 *param_0, f32 *param_1, f32 *param_2)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;

    func_800D9078(&param_0->local_0->local_6);
    local_2 = param_0->local_0->local_6 * 1;
    func_801163A0(param_0, local_2);
    for (local_0 = 0; local_0 < 3; local_0++) {
        param_0->local_0->local_0[local_0] = func_800F130C(param_0->local_0->local_6,
            1, 0, param_0->local_0->local_4[local_0],
            param_0->local_0->local_2[local_0]);
        local_1 = func_800F130C(param_0->local_0->local_6, 0.5f, 0.0f, 0.0f,
                func_800F1DCC(param_0->local_0->local_3[local_0],
                    param_0->local_0->local_5[local_0]));
        local_1 += param_0->local_0->local_5[local_0];
        param_0->local_0->local_1[local_0] = func_800136E4(local_1);
    }
    if (0 == param_0->local_0->local_6) ncba1p_entrypoint_5(param_0, 2);
    if (func_80800008_ncba1p(param_0, param_0->local_0->local_0,
            param_0->local_0->local_2)) func_8080004C_ncba1p(param_0, 0x62);
    func_800EE7F8(param_1, param_0->local_0->local_0);
    func_800EE7F8(param_2, param_0->local_0->local_1);
}

void func_80800230_ncba1p(CameraTransition1202 *param_0, f32 *param_1, f32 *param_2)
{
    s32 local_0;
    f32 local_1;
    f32 local_2;

    func_800D9078(&param_0->local_0->local_6);
    local_2 = 1 - param_0->local_0->local_6 * 1;
    func_801163A0(param_0, local_2);
    for (local_0 = 0; local_0 < 3; local_0++) {
        param_0->local_0->local_0[local_0] = func_800F130C(param_0->local_0->local_6,
            1, 0.0f, param_0->local_0->local_2[local_0], param_1[local_0]);
        local_1 = func_800F130C(param_0->local_0->local_6, 1, 0.5f, 0.0f,
                func_800F1DCC(param_2[local_0], param_0->local_0->local_3[local_0]));
        local_1 += param_0->local_0->local_3[local_0];
        param_0->local_0->local_1[local_0] = func_800136E4(local_1);
    }
    if (0.0f == param_0->local_0->local_6) ncba1p_entrypoint_5(param_0, 4);
    if (!func_80800008_ncba1p(param_0, param_0->local_0->local_2,
            param_0->local_0->local_0)) func_8080004C_ncba1p(param_0, 0x63);
    func_800EE7F8(param_1, param_0->local_0->local_0);
    func_800EE7F8(param_2, param_0->local_0->local_1);
}

void func_808003DC_ncba1p(BaCameraTransform **param_0, f32 *param_1, f32 *param_2)
{

    func_801163A0(param_0, 0.0f);
    func_800EE7F8((*param_0)->position, (*param_0)->target_position);
    if ((*param_0)->smooth) {
        func_80111410(param_0, (*param_0)->target_rotation, (*param_0)->rotation, 120.0f);
    } else {
        func_800EE7F8((*param_0)->rotation, (*param_0)->target_rotation);
    }
    func_800EE7F8(param_1, (*param_0)->position);
    func_800EE7F8(param_2, (*param_0)->rotation);
}

void ncba1p_entrypoint_1(FirstPersonCamera *param_0)
{
    if (!_plcamera_entrypoint_1(func_80110840())) {
        func_800EFD24(param_0->local_0->local_0[0]);
        func_800EFD24(param_0->local_0->local_0[1]);
        func_800EFD24(param_0->local_0->local_0[2]);
        func_800EFD24(param_0->local_0->local_0[3]);
        func_800EFD24(param_0->local_0->local_0[4]);
        func_800EFD24(param_0->local_0->local_0[5]);
        param_0->local_0->local_1 = 0;
        param_0->local_0->local_2 = 1;
        param_0->local_0->local_3 = 0;
        func_80111590(param_0, 10.0f, 20.0f, 120.0f, 300.0f);
    }
}

void ncba1p_entrypoint_2(s32 *param_0)
{
  f32 sp24[3];
  f32 sp18[3];

  ((s32 *) param_0[0])[0x13] = 2;
  ((u8 *) param_0[0])[0x50] = 0;
  ncba1p_entrypoint_3(param_0, sp24, sp18);
}

void ncba1p_entrypoint_3(param_0, param_1, param_2) u8 **param_0; s32 param_1; s32 param_2;
{
    s32 local_0;

    local_0 = *(s32 *)(*param_0 + 0x4C);
    if (local_0 != 4 && local_0 != 0) {
        func_8011607C(param_0, 0);
        local_0 = *(s32 *)(*param_0 + 0x4C);
    }
    switch (local_0) {
    case 1: func_808000A0_ncba1p(param_0, param_1, param_2); break;
    case 2: func_808003DC_ncba1p(param_0, param_1, param_2); break;
    case 3: func_80800230_ncba1p(param_0, param_1, param_2); break;
    case 4: break;
    }
}

void ncba1p_entrypoint_4(void *arg, s32 v)
{
    ((s8 *)(*(void **)((char *)arg + 0x0)))[80] = v;
}

void ncba1p_entrypoint_5(param_0, param_1) u8 **param_0; s32 param_1;
{
    u8 *local_2;

    switch (*(s32 *)(*param_0 + 0x4C)) {
    case 1:
        if (param_1 == 1) break;
        func_8080004C_ncba1p(param_0, 0x62);
        break;
    case 3:
        if (param_1 == 3) break;
        func_8080004C_ncba1p(param_0, 0x63);
        break;
    }
    switch (param_1) {
    case 1:
        func_80110728(param_0, 1);
        local_2 = *param_0;
        if (*(u32 *)(local_2 + 0x4C) == 3) {
            func_800EE7F8(*param_0 + 0x30, *param_0);
            func_800EE7F8(*param_0 + 0x3C, *param_0 + 0xC);
        } else {
            func_801107F0(param_0, *param_0);
            func_80110818(param_0, *param_0 + 0xC);
            func_801107F0(param_0, *param_0 + 0x30);
            func_80110818(param_0, *param_0 + 0x3C);
        }
        *(f32 *)(*param_0 + 0x48) = 1.0f;
        (*param_0)[0x51] = 0;
        break;

    case 3:
        *(f32 *)(*param_0 + 0x48) = 1.0f;
        (*param_0)[0x51] = 0;
        break;

    case 4:
        func_801163A0(param_0, 1.0f);
        func_80110728(param_0, 0);
        break;
    

    case 2:
        break;
    }
    *(s32 *)(*param_0 + 0x4C) = param_1;
}

void ncba1p_entrypoint_6(Actor *param_0)
{
  s32 *new_var;
  s32 *new_var2;
  new_var2 = (s32 *) ((new_var = (char *) param_0) + 0);
  new_var = new_var2;
  func_800EE7F8((*new_var) + 24);
}

void ncba1p_entrypoint_7(BaCameraOrientation **param_0, f32 *param_1)
{
    (*param_0)->angles[0] = func_800136E4(param_1[0]);
    (*param_0)->angles[1] = func_800136E4(param_1[1]);
    (*param_0)->angles[2] = func_800136E4(param_1[2]);
}

void ncba1p_entrypoint_8(s32 *param_0, s32 param_1) {
    func_800EE7F8(param_1, *(s32 *)(param_0 + 0) + 0x24);
}

f32 ncba1p_entrypoint_9(u8 **param_0) {
    return (*(f32 *)((s8 *)(*param_0) + (0x10)));
}

s32 ncba1p_entrypoint_10(u8 **param_0) {
    return (*(s32 *)((s8 *)(*param_0) + (0x4C)));
}

f32 ncba1p_entrypoint_11(u8 **param_0) {
    return *(f32 *)((char *)*param_0 + 0x48);
}

int ncba1p_entrypoint_12(s32 param_0, f32 param_1)
{
  int new_var;
  *((f32 *) ((*((u8 **) param_0)) + (new_var = 0x48))) = param_1;
  new_var = 0x50;
}

int ncba1p_entrypoint_13(s32 param_0[3], s32 param_1, s32 param_2)
{
  func_800EE7F8(param_1 | 0, param_0[0]);
  func_800EE7F8(param_2, param_0[0] + 0xC);
}
