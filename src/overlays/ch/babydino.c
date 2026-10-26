#include "common.h"

#define CODEX_PAIR_EVENT_PAYLOAD
extern int D_80800770_chbabydino;
typedef union { s32 word; s16 halves[2]; } PairEventPayload;
extern void *_suexpression_entrypoint_20(Actor *);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _capod_entrypoint_22(void);
extern s32 D_80800700_chbabydino;
extern s32 D_808007D4_chbabydino;
extern s32 D_808007B8_chbabydino;
extern void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
void func_808003BC_chbabydino();
int func_808005F0_chbabydino();

int chbabydino_entrypoint_0()
{
  return &D_80800770_chbabydino;
}

void func_8080000C_chbabydino(u8 *param_0)
{
  s32 local_0;
  local_0 = func_800EA05C();
  if (func_80105494(param_0) != 0)
  {
    func_80105A9C(param_0, 0x43FA0000);
  }
  switch (local_0)
  {
    case 0xEA:
      if (func_800DA298(0x98) != 0)
    {
      *((u8 *) (((s8 *) param_0) + 0x65)) = (u8) (((*((u8 *) (((s8 *) param_0) + 0x65))) & 0xFFFF) | 0x10);
    }
      if ((func_800DA298(0x8A) != 0) || (func_800DA298(0x588) != 0))
    {
      func_800FFAB0(param_0);
      return;
    }
      func_80102424(param_0, 2);
      return;

    case 0xEC:
      if (_glcutDll_entrypoint_19(0x1F) == 0)
    {
      func_800FFAB0(param_0);
      return;
    }
      return;

    case 0x121:
      if (func_800DA298(0x588) != 0)
    {
      func_80102424(param_0, 5);
      return;
    }
      func_800FFAB0(param_0);
      break;

  }

}

void func_80800448_chbabydino();

void func_8080011C_chbabydino(Actor *param_0)
{
    _sudeflect_entrypoint_0(param_0->position, param_0->scale * 100.0f, param_0->scale * 150.0f, 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), param_0->unk0, 0);
    switch (param_0->unk70_10) {
    case 1: break;
    case 2: func_80800448_chbabydino(param_0); break;
    case 3:
        if (!func_808005A0_chbabydino(param_0, 1)) {
            _capod_entrypoint_14();
            if (_glcutDll_entrypoint_19(0x1F)) _glcutDll_entrypoint_24(0xEC, -1, 0x1F);
            else _glcutDll_entrypoint_6(0xEC, 0x1F);
        }
        break;
    case 4:
        if (!func_808005A0_chbabydino(param_0, 0)) {
            func_800DA544(0x588);
            func_80102424(param_0, 5);
            func_800FFAB0(param_0);
            _glcutDll_entrypoint_15(1);
            _glcutDll_entrypoint_17();
            _capod_entrypoint_14();
        }
        break;
    case 5: _subaddiedialog_entrypoint_7(param_0, param_0->position, &D_808007B8_chbabydino); break;
    }
    _chdinofamilyfx_entrypoint_0(param_0);
}

void func_8080028C_chbabydino(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808002AC_chbabydino(Actor *param_0, s32 param_1, PairEventPayload param_2)
{
    void *local_0;
    s32 local_1;
    switch (param_1) {
    case 0x2E:
        func_808003BC_chbabydino(param_0, param_2.halves[0], param_2.halves[1]);
        break;
    case 0x49:
        return func_808005F0_chbabydino(param_0, param_2.word);
    case 0x95:
        _suexpression_entrypoint_7(param_0, 1, 0x39);
        local_0 = _suexpression_entrypoint_20(param_0);
        _suexpression_entrypoint_12(local_0, 50.0f, 20.0f);
        _suexpression_entrypoint_17(local_0, 1000);
        break;
    case 0x1F:
        func_801015D0(param_0);
        func_800DF744(3, 1);
        break;
    case 0xB8:
        local_1 = param_2.word & 0xFFFF;
        switch (local_1) {
        case 1:
            return func_800DA298(0x98) ? 0x107F : 0x107D;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808003BC_chbabydino(param_0, param_1, param_2) Actor *param_0; s32 param_1; s32 param_2;
{
    if (param_0->unk64_19) {
        _capod_entrypoint_22();
        param_0->unk64_19 = 0;
    }
    if (param_1 != 0x107E && param_1 != 0x1080) {
        func_80102424(param_0, func_800DA298(0x588) ? 5 : 2);
    }
}

void func_80800448_chbabydino(Actor *param_0)
{
    s32 local_0 = 0;

    if (func_800DA298(0x98) && !param_0->unk64_20) {
        if (!func_800DB9B0()) {
            func_800DA544(0x89);
            param_0->unk64_20 = 1;
            func_800F82D4(func_800F54E4(), 0);
            if (func_800DA298(0x4EE)) {
                func_80102424(param_0, 3);
                _subaddieDll_entrypoint_4(param_0, 1);
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x107E, 12, 0, 0x39);
                _capod_entrypoint_13(param_0->unk0, 0, 3, 0x31);
            } else {
                _subaddiedialog_entrypoint_11(param_0->unk0, 0x107F, 14, 0, 0x39);
                func_80102424(param_0, 1);
                local_0 = 1;
            }
        }
    } else {
        local_0 = _subaddiedialog_entrypoint_8(param_0, param_0->position, &D_808007D4_chbabydino, &D_80800700_chbabydino, 5);
    }
    if (local_0) {
        _capod_entrypoint_21(param_0->unk0, 0, 11, 0);
        param_0->unk64_19 = 1;
    }
}

int func_808005A0_chbabydino(s32 param_0, s32 param_1)
{
  func_80105834(param_0);
  if (func_80105A5C(param_0) != 0) {
    if (param_1 != 0) {
      func_800FFAB0(param_0);
    }
    return 0;
  }
  return 1;
}

int func_808005F0_chbabydino(param_0, param_1) Actor *param_0; s32 param_1;
{
  switch (func_800EA05C())
  {
    case 0xEA :
      if (_glcutDll_entrypoint_19(0x1F))
    {
      func_80102424(param_0, 3);
      _subaddieDll_entrypoint_4(param_0, 1);
      _subaddiedialog_entrypoint_11(param_0->unk0, 0x1080, 0xC, 0, 0x39);
      _capod_entrypoint_13(param_0->unk0, 0, 3, 0x2821);
      return 1;
    }

      break;

    case 0xEC :
      if (_glcutDll_entrypoint_19(0x1F))
    {
      func_80102424(param_0, 4);
      _subaddieDll_entrypoint_4(param_0, 1);
      _capod_entrypoint_13(param_0->unk0, 0, 7, 0x2821);
      return 1;
    }

  }

  return 0;
}
