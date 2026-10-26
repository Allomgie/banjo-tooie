#include "common.h"

typedef struct { s32 local_0[8]; s16 local_1[8]; u8 pad_0[8]; s32 local_2; u8 pad_1[4]; } CameraDatabase;
extern void *heap_alloc(s32);
extern OSIoMesg D_80800630_cadbmgrDll;
extern void _cadbfunc_entrypoint_7(f32, f32);
extern void _cadbfunc_entrypoint_9(f32, f32);
extern void _cadbfunc_entrypoint_11(f32);
extern void _cadbfunc_entrypoint_13(f32);
extern void _cadbfunc_entrypoint_15(f32);
extern void _cadbfunc_entrypoint_19(f32);
extern void _cadbfunc_entrypoint_21(f32);
extern void _cadbfunc_entrypoint_33(f32);
extern s32 func_800A57EC(s32);
typedef struct CameraDbManager { s32 local_0[8]; s16 local_1[8]; s32 local_2; s32 local_3; } CameraDbManager;
extern void func_8001B754();
extern s32 func_8001B798();
extern void *rare_memcpy(void *dest, const void *src, u32 n);
s32 func_808003D8_cadbmgrDll();
s32 func_808004C4_cadbmgrDll();
int func_80800528_cadbmgrDll();
void func_808005AC_cadbmgrDll();

void cadbmgrDll_entrypoint_0(CameraDatabase **param_0, s32 param_1)
{
    s32 local_0;

    *param_0 = heap_alloc(param_1 * 2 + 0x40);
    for (local_0 = 1; local_0 <= 8; local_0++) {
        (*param_0)->local_1[local_0 - 1] = 0;
        (*param_0)->local_0[local_0 - 1] = 0;
    }
    (*param_0)->local_2 = param_1;
    func_800A56A4();
}

int cadbmgrDll_entrypoint_1(void *param_0)
{
  void **local_0;
  local_0 = param_0;
  func_800A56A4();
  heap_free(*local_0);
  *local_0 = 0;
}

void func_808000F4_cadbmgrDll(s32 param_0)
{
    Vec3f local_0 = *((Vec3f *)&D_80800630_cadbmgrDll);
    s32 local_1;

    local_1 = func_800A5854(param_0);
    func_800A5800(param_0);
    if (local_1 == 1 || local_1 == 2 || local_1 == 3 || local_1 == 5) {
        func_800E3980(local_0.f);
        _cadbfunc_entrypoint_1(local_0.f);
        func_800E3A58(local_0.f);
        _cadbfunc_entrypoint_3(local_0.f);
    } else {
        _cadbfunc_entrypoint_1(local_0.f);
        _cadbfunc_entrypoint_3(local_0.f);
    }
    _cadbfunc_entrypoint_5(local_0.f);
    _cadbfunc_entrypoint_7(1.75f, 3.75f);
    _cadbfunc_entrypoint_9(2.75f, 12.0f);
    _cadbfunc_entrypoint_11(150.0f);
    _cadbfunc_entrypoint_13(40.0f);
    _cadbfunc_entrypoint_15(1.0f);
    _cadbfunc_entrypoint_17(-1);
    _cadbfunc_entrypoint_19(1000.0f);
    _cadbfunc_entrypoint_21(1000.0f);
    _cadbfunc_entrypoint_25(0);
    _cadbfunc_entrypoint_27(0);
    _cadbfunc_entrypoint_23(0);
    _cadbfunc_entrypoint_31(0);
    _cadbfunc_entrypoint_33(0.0f);
    _cadbfunc_entrypoint_35(0);
    switch (local_1) {
    case 4:
        _cadbfunc_entrypoint_27(0);
        _cadbfunc_entrypoint_23(10);
        break;
    case 1:
        _cadbfunc_entrypoint_28(2, 1);
        break;
    case 7:
        _cadbfunc_entrypoint_25(1);
        break;
    }
}

int cadbmgrDll_entrypoint_2(s32 *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;

    if (((u8 *)param_0)[0x3C + param_2 * 2]) return 0;
    local_0 = func_808004C4_cadbmgrDll(param_0, param_1, param_2);
    for (local_1 = 0; local_1 < param_0[14]; local_1++) {
        if (((u8 *)param_0)[0x3C + local_1 * 2] == param_1 &&
            ((u8 *)param_0)[0x3D + local_1 * 2] >= local_0) {
            ((u8 *)param_0)[0x3D + local_1 * 2]++;
        }
    }
    ((u8 *)param_0)[0x3C + param_2 * 2] = param_1;
    ((u8 *)param_0)[0x3D + param_2 * 2] = local_0;
    func_808003D8_cadbmgrDll(param_0, param_1, param_0[param_1 - 1] + 1);
    if (param_0[param_1 - 1] - 1 > local_0) func_80800528_cadbmgrDll(param_0, param_1, local_0);
    func_808000F4_cadbmgrDll(param_2);
    return 1;
}

s32 func_808003D8_cadbmgrDll(param_0, param_1, param_2) CameraDbManager *param_0; s32 param_1; s32 param_2;
{

    if (param_2 != 0) {
        if (param_0->local_0[param_1 - 1] != 0) {
            func_8001B710(param_0->local_1[param_1 - 1], func_800A57EC(param_1) * param_2);
        } else {
            param_0->local_1[param_1 - 1] = func_8001B668(0, func_800A57EC(param_1));
        }
    } else {
        if (param_0->local_0[param_1 - 1] != 0) {
            func_8001B754(param_0->local_1[param_1 - 1]);
            param_0->local_1[param_1 - 1] = 0;
        }
    }
    param_0->local_0[param_1 - 1] = param_2;
    param_0->local_2 = -1;
    param_0->local_3 = 0;
    return 1;
}

s32 func_808004C4_cadbmgrDll(param_0, param_1, param_2) s32 *param_0; s32 param_1; u32 param_2; {
    s32 local_0;
    s32 local_1;
    u8 local_2;
    u8 *local_3;

    local_0 = param_0[14] - 1;
    local_1 = param_0[param_1 - 1];
    if (local_0 >= 0) {
        local_3 = (u8 *)param_0 + (local_0 * 2);
        do {
            if ((param_1 == *(u8 *)((char *)local_3 + 0x3C)) && ((s32)(param_2) < local_0)) {
                local_2 = *(u8 *)((char *)local_3 + 0x3D);
                if (local_1 >= (s32) local_2) {
                    local_1 = (s32) local_2;
                }
            }
            local_0 -= 1;
            local_3 -= 2;
        } while (local_0 >= 0);
    }
    return local_1;
}

int func_80800528_cadbmgrDll(param_0, param_1, param_2) s32 param_0[4]; s32 param_1; s32 param_2;
{
  s32 new_var2;
  unsigned long long new_var;
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  s32 local_4;
  new_var = 1;
  local_0 = new_var;
  local_0 = (*((s32 *) (((s8 *) (&param_0[param_1])) + (local_2 = -4)))) - local_0;
  if (param_2 < local_0)
  {
    do
    {
      local_1 = local_0 - new_var;
      new_var2 = (0, param_1);
      func_808005AC_cadbmgrDll(param_0, new_var2, local_1, local_0);
      local_0 = local_1;
    }
    while (param_2 < local_0);
  }
}

void func_808005AC_cadbmgrDll(param_0, param_1, param_2, param_3) s32 param_0; s32 param_1; s32 param_2; s32 param_3;
{
  s32 sp1C;
  int temp_v0;
  sp1C = func_800A57EC(param_1);
  temp_v0 = func_8001B798(*((s16 *) (((s8 *) (param_0 + ((param_1 * 2) & 0xFFFFFFFFu))) + 0x1E)));
  rare_memcpy(temp_v0 + (param_3 * sp1C), temp_v0 + (param_2 * sp1C), sp1C);
}
