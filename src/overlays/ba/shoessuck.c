#include "common.h"
#include "playerstate.h"

extern void func_800EFA4C(f32 *, f32, f32, f32);

extern void func_8009BF5C(s32, f32);
extern void baroll_setIdeal(s32, f32);
extern f32 D_80800740_bashoessuck[];
extern f32 D_80800800_bashoessuck[];
extern void func_8009C128();
extern s32 func_800C6A7C(f32 *, f32 *, f32 *, s32);
extern void func_800EE7F8(void *, f32 *);
extern f32 yaw_get(PlayerState *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern void _bamovespline_entrypoint_9(PlayerState *, f32);
extern f32 func_800EEFD4(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
extern f32 func_800EFB8C(f32 *, f32 *);
extern f32 func_800C82CC(void *, f32 *);
extern void *func_800D7520(void *);
extern void *_gccubesearch_entrypoint_5(void *, f32 *);
extern void *_glsplinefind_entrypoint_3(f32 *);
extern void func_800C7A68(void *, f32, f32 *);
extern s32 func_800F1E6C(f32 *, f32 *, f32 *);

s32 bashoessuck_entrypoint_0(void *param_0, void *param_1)
{
    s32 pad1; /* unused, but it carries the stack frame (without it the frame is wrong); original variable unknown */
    f32 local_A[3];
    f32 local_B[3];
    f32 local_C[3];
    f32 local_D[3];
    s32 j;
    s32 i;

    func_8009C128(param_0, local_A);
    for (j = 0; j < 8; j++) {
        for (i = 0; i < 3; i++) {
            local_B[i] = local_A[i] + D_80800740_bashoessuck[j * 6 + i];
        }
        for (i = 0; i < 3; i++) {
            local_C[i] = local_A[i] + D_80800740_bashoessuck[j * 6 + i + 3];
        }
        if (func_800C6A7C(local_B, local_C, local_D, 0x20020) != 0) {
            if (local_D[1] < 0.8f) {
                func_800EE7F8(param_1, local_D);
                return 1;
            }
        }
    }
    func_800EFA4C(param_1, 0.0f, 1.0f, 0.0f);
    return 0;
}

s32 bashoessuck_entrypoint_1(s32 param_0, s32 param_1){
    s32 out;
    func_8009C128(param_0);
    out = _gccubesearch_entrypoint_1(0x16D, param_1);
    if(out){
        _gspropctrl_entrypoint_11(out, param_1);
    }
}

void bashoessuck_entrypoint_2(s32 param_0) {
    func_800932CC(param_0, 0);
    func_8009BF5C(param_0, 0);
    baroll_setIdeal(param_0, 0);
    func_800961AC(param_0, 1);
}

void bashoessuck_entrypoint_3(s32 arg0)
{
    func_800961AC(arg0,0xA);
}

void bashoessuck_entrypoint_4(s32 param_0)
{
  extern f32 func_8009BB18(s32);
  extern f32 func_800EEAA4(f32 *, f32 *);
  extern f32 func_800F1C98(f32 *, f32 *);
  extern f32 func_80013AAC(f32);
  extern void func_800EFA20(f32 *, f32 *, f32);
  extern void func_800EFA4C(f32 *, f32, f32, f32);
  extern void func_800EF934(f32 *, f32 *, f32);
  extern void _bashoes_entrypoint_10(s32, f32);
  extern void func_800932BC(s32, f32);
  extern void func_8009BF5C(s32, f32);
  extern void yaw_setIdeal(s32, f32);
  extern void baroll_setIdeal(s32, f32);
  f32 local_0;
  f32 *new_var2;
  f32 local_1;
  f32 *new_var;
  f32 local_2;
  f32 local_3[3];
  f32 local_4[3];
  f32 local_5[3];
  f32 local_6[3];
  f32 local_7[3];
  f32 local_8[3];
  f32 local_9[3];
  f32 local_10[3];
  s32 local_11;
  f32 local_12[3];
  local_11 = func_80092BC4();
  func_800932CC(param_0, 0);
  if (!_bamovespline_entrypoint_4(param_0))
  {
    func_800EFA4C(local_12, 0.0f, func_8009BB18(param_0), 0.0f);
    yaw_setIdeal(param_0, local_12[1]);
    return;
  }
  _bamovespline_entrypoint_0(param_0, local_5);
  if (bashoessuck_entrypoint_0(param_0, local_9))
  {
    func_800932CC(param_0, 1);
 dummy_label_104098: ;
    _bashoes_entrypoint_10(param_0, 1.0f);
    new_var2 = local_3;
    func_800EFA20(local_6, local_9, func_800EEAA4(local_5, local_9));
    func_800EFB24(local_7, local_5, local_6);
    func_800EFA4C(local_8, 0.0f, 1.0f, 0.0f);
    new_var = &local_2;
    if (local_9[1] > 0.99f)
    {
      local_2 = 0.0f;
      local_1 = 0.0f;
      local_0 = 0.0f;
    }
    else
    {
      func_800EFA4C(local_10, local_9[0], 0.0f, local_9[2]);
      func_800F1EA4(local_10, new_var);
      local_1 = func_80013AAC(func_800F1C98(local_8, local_9));
      func_800EE97C(local_3, local_8, local_10);
      local_0 = (func_80013AAC(func_800F1C98(local_7, new_var2)) - 90.0f) + 180.0f;
      if (local_7[1] < 0.0f)
      {
        local_0 = 180.0f - local_0;
      }
      func_800EF934(local_4, local_7, -local_2);
      if (local_4[0] < 0.0f)
      {
        local_0 = 360.0f - local_0;
      }
    }
    if (local_11 && (func_8009BB18(param_0) > 180.0f))
    {
      local_0 += 180.0f;
    }
    func_800932BC(param_0, local_2);
    func_8009BF5C(param_0, local_1);
    yaw_setIdeal(param_0, local_0);
    baroll_setIdeal(param_0, 0.0f);
    if (!local_11)
    {
      yaw_applyIdeal(param_0);
    }
  }
}

s32 bashoessuck_entrypoint_5(PlayerState *param_0, f32 *param_1)
{
    f32 local_2c;
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6[3];
    f32 local_7[3];
    void *local_8;
    f32 local_2b;
    u8 *local_10;
    void *local_9;

    if (_bashoes_entrypoint_9()) return 0;
    func_8009BB24(param_0, local_4);
    local_4[1] = 0.0f;
    if (func_800EEFD4(local_4) < 1.0f) return 0;
    local_2 = yaw_get(param_0);
    local_10 = _gccubesearch_entrypoint_5(((void * *) D_80800800_bashoessuck), param_1);
    if (!local_10) return 0;
    _gspropctrl_entrypoint_11(local_10, local_7);
    local_9 = _glsplinefind_entrypoint_3(local_7);
    func_800C7A68(func_800D7520(local_9), 1.0f, param_1);
    local_10 = _gccubesearch_entrypoint_5(((void * *) D_80800800_bashoessuck), param_1);
    if (!local_10) return 0;
    switch (*(u16 *)(local_10 + 8)) {
    case 0x16B: _bashoes_entrypoint_11(param_0, 1); break;
    case 0x16C: _bashoes_entrypoint_11(param_0, 2); break;
    }
    func_8009C128(param_0, local_5);
    local_8 = func_800D7520(local_9);
    local_1 = func_800C82CC(local_8, local_5);
    func_800C7A68(local_8, local_1, local_6);
    if (func_800EEB40(local_5, local_6) < 1764.0f) {
        baphysics_set_type(param_0, 0x12);
        _bamovespline_entrypoint_7(param_0, local_9);
        _bamovespline_entrypoint_9(param_0, local_1);
        return 1;
    }
    func_800F1E6C(local_5, local_7, &local_3);
    if (mlAbsF(func_800F1DCC(local_3, local_2)) > 45.0f) return 0;
    local_0 = local_5[1] - local_7[1];
    if (mlAbsF(local_0) > 20.0f) return 0;
    if (func_800EFB8C(local_5, local_7) < local_0) return 0;
    baphysics_set_type(param_0, 0x12);
    _bamovespline_entrypoint_7(param_0, local_9);
    _bamovespline_entrypoint_8(param_0);
    return 1;
}
