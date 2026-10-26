#include "common.h"

extern void *func_800F5EF8();
extern void *func_80110014(void *);
extern void _ncbadeflect_entrypoint_0(void *, s32, s32, s32, f32, f32);
extern void _ncbadeflect_entrypoint_1(s32, s32, s32, s32, f32);
extern void func_801110EC(s32, s32, s32);
extern f32 func_800EEAA4(f32 *, f32 *);
extern void func_80110848(void *, s32, s32);
extern u8 D_80800510_plcamera[];
extern void *_gccubesearch_entrypoint_6(void *, f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
s32 func_80800300_plcamera();

void plcamera_entrypoint_0(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F5EF8();
    sp1C = temp_v0;
    func_801108A0(func_80110014(temp_v0));
    func_8010FD88(sp1C);
}

int plcamera_entrypoint_1(s32 param_0)
{
  s32 local_0;
  s32 local_1;
  local_0 = func_800F53E4();
  if (local_0 == 0)
  {
    return 0;
  }
  local_1 = local_0;
  if ((func_800A3404(local_1) != 0) && (func_800F693C(param_0) != 0) && (func_800EA068(8) != 0))
  {
    _bsfirstp_entrypoint_2(local_1);
    return 1;
  }
  if (func_800A3404(local_1) != 0)
  {
    return 1;
  }
  return 0;
}

int plcamera_entrypoint_2(s32 param_0, s32 param_1)
{
  int var;
  var = func_800F5EF8(param_0);
  var = func_80110014(var);
  func_801106A8(var, param_1);
}

int plcamera_entrypoint_3(s32 param_0, s32 param_1)
{
  int var;
  var = func_800F5EF8(param_0);
  var = func_80110014(var);
  func_80110720(var, param_1);
}

int plcamera_entrypoint_4(s32 param_0, s32 param_1)
{
  u32 local_0;
  local_0 = func_800F5EF8(param_0);
  func_80110770(func_80110014(local_0), param_1);
}

int plcamera_entrypoint_5(s32 param_0, s32 param_1)
{
  s32 local_0;
  local_0 = func_800F5EF8(param_0);
  func_80110790(func_80110014(local_0), param_1);
}

void plcamera_entrypoint_6(void *param_0, s32 param_1, s32 param_2, s32 param_3, f32 param_4)
{
    void *local_0;

    local_0 = func_800F5EF8(param_0);
    if (local_0 != NULL) {
        local_0 = func_80110014(local_0);
        if (local_0 != NULL) {
            _ncbadeflect_entrypoint_0(local_0, param_1, param_2, param_3, param_4, 1000.0f);
        }
    }
}

void plcamera_entrypoint_7(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    s32 local_0 = func_800F5EF8(param_0);
    if (local_0 != 0) {
        local_0 = func_80110014(local_0);
        if (local_0 != 0) {
            _ncbadeflect_entrypoint_1(local_0, param_1, param_2, param_3, 1000.0f);
        }
    }
}

void plcamera_entrypoint_8(void) {
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F5EF8();
    sp1C = temp_v0;
    func_80110928(func_80110014(temp_v0));
    func_8010FD88(sp1C);
}

void plcamera_entrypoint_9(s32 param_0, s32 param_1, s32 param_2) {
    func_801110EC(func_80110014(func_800F5EF8(param_0)), param_1, param_2);
}

int plcamera_entrypoint_10()
{
    func_801106A0((s32)func_80110014(func_800F5EF8()) | 0);
}

s32 func_80800300_plcamera(param_0, param_1) f32 *param_0; f32 *param_1;
{
    void *local_0;
    local_0 = _gccubesearch_entrypoint_6(D_80800510_plcamera, param_0);
    if (local_0 == NULL) return 0;
    _gspropctrl_entrypoint_11(local_0, param_1);
    return func_800EEB40(param_0, param_1) < 4000000.0f;
}

void plcamera_entrypoint_11(s32 param_0, f32 *param_1)
{
    s32 local_0;
    s32 local_1;
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6;
    f32 local_7[3];

    local_0 = (s32)func_800F5EF8((void *)param_0);
    local_1 = func_80110014(local_0);
    func_800F5A00(param_0, local_3);
    func_801107F0(local_1, local_2);
    func_800EFB24(local_4, local_2, local_3);
    func_800EFB24(local_5, param_1, local_3);
    local_6 = func_800EEAA4(local_4, local_5);
    func_80110720(local_1, 0);
    if (local_6 > 0.0f && func_80800300_plcamera(local_3, local_2)) {
        func_800A516C(local_7, param_1, local_2);
        local_7[0] += 10.0f;
        func_8010FE14(local_0, local_2, local_7);
    }
}

int plcamera_entrypoint_12(s32 param_0, s32 param_1, s32 param_2)
{
  func_8010FDA8((s32)func_800F5EF8(param_0) | 0, param_1, param_2);
}

s32 plcamera_entrypoint_13(s32 param_0, s32 param_1) {
    s32 local_0;

    local_0 = func_800F5EF8(param_0);
    func_8010FDEC(local_0, param_1);
}

void plcamera_entrypoint_14(void *param_0, s32 param_1, s32 param_2)
{
    func_80110848(func_80110014(func_800F5EF8(param_0)), param_1, param_2);
}
