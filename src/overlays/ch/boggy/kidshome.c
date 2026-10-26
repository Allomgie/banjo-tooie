#include "common.h"

extern int D_80800468_chboggykidshome;
extern int D_808004B0_chboggykidshome;
extern int D_808004F8_chboggykidshome;
typedef union { s32 word; void *pointer; } BoggyHomeMessage29;
typedef struct { u8 pad_0[0x6C]; u32 pad_1 : 11; u32 actor : 12; u32 pad_2 : 9; } BoggyHomeKind29;
extern u8 D_80800540_chboggykidshome[];
extern u8 D_80800550_chboggykidshome[];
extern u8 D_80800560_chboggykidshome[];
extern void *_suexpression_entrypoint_7(Actor *, s32, s32);
extern void _suexpression_entrypoint_12(void *, f32, f32);
extern void _gcdialogcamera_entrypoint_3(void *, f32);
extern u8 D_80800570_chboggykidshome[];
extern u8 D_808003C0_chboggykidshome[];
extern u8 D_80800580_chboggykidshome[];
extern u8 D_808003E8_chboggykidshome[];
extern u8 D_80800590_chboggykidshome[];
extern u8 D_80800408_chboggykidshome[];
extern s32 func_801022E4(Actor *);
extern s32 func_80101E14(Actor *, f32);
extern s32 func_80101E4C(Actor *, f32 *);
extern s32 func_800DC128(s32, s32);
extern void func_800C4B7C(s32);
extern void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
extern s16 D_808005A0_chboggykidshome[];
extern f32 D_808005AC_chboggykidshome[];
extern u8 D_808005BC_chboggykidshome[];
extern u8 D_808005CC_chboggykidshome[];
extern u8 D_808005E8_chboggykidshome[];
void func_80800214_chboggykidshome();
int func_808002C0_chboggykidshome();
void func_80800300_chboggykidshome();

int chboggykidshome_entrypoint_0()
{
  return &D_80800468_chboggykidshome;
}

int chboggykidshome_entrypoint_1()
{
    return (int)&D_808004B0_chboggykidshome;
}

int chboggykidshome_entrypoint_2()
{
    return (int)&D_808004F8_chboggykidshome;
}

int func_80800024_chboggykidshome(s32 param_0)
{
  if (!func_800DA298(0x1CD) && !_glcutDll_entrypoint_20() && !func_800FFAB0(param_0))
  {}

}

void func_80800068_chboggykidshome(Actor *param_0)
{
  s8 *new_var;
  new_var = ((s8 *) param_0) + 0x72;
  if (((((u16) (*((u16 *) new_var))) & 0xFFFFFFFF) >> 0xA) == 1)
  {
    func_80800214_chboggykidshome();
  }
  _sudeflect_entrypoint_0(((u8 *) param_0) + 4, 0x42C80000, 0x42480000, 0xA);
  _suexpression_entrypoint_10(_suexpression_entrypoint_20(param_0), *((s32 *) (((s8 *) param_0) + 0)), 0);
  func_80800300_chboggykidshome(param_0);
}

void func_808000DC_chboggykidshome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808000FC_chboggykidshome(Actor *param_0, s32 param_1, BoggyHomeMessage29 param_2)
{
    void *local_0;
    switch (param_1) {
    case 0x2E:
        func_80102424(param_0, 1);
        break;
    case 0x95:
        local_0 = _suexpression_entrypoint_7(param_0, 1, (s16)func_808002C0_chboggykidshome(param_0));
        _suexpression_entrypoint_12(local_0, 60.0f, 20.0f);
        _suexpression_entrypoint_17(local_0, 1000);
        break;
    case 0x52:
        switch (((BoggyHomeKind29 *)param_0)->actor) {
        case 0x41D:
            _gcdialogcamera_entrypoint_3(D_80800540_chboggykidshome, param_0->scale);
            break;
        case 0x3E4:
            _gcdialogcamera_entrypoint_3(D_80800550_chboggykidshome, param_0->scale);
            break;
        case 0x34E:
            _gcdialogcamera_entrypoint_3(D_80800560_chboggykidshome, param_0->scale);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800214_chboggykidshome(param_0) Actor *param_0;
{
    switch (param_0->unk6C_9) {
        case 0x41D:
            _subaddiedialog_entrypoint_8(param_0, param_0->position,
                D_80800570_chboggykidshome, D_808003C0_chboggykidshome, 5);
            break;
        case 0x3E4:
            _subaddiedialog_entrypoint_8(param_0, param_0->position,
                D_80800580_chboggykidshome, D_808003E8_chboggykidshome, 4);
            break;
        case 0x34E:
            _subaddiedialog_entrypoint_8(param_0, param_0->position,
                D_80800590_chboggykidshome, D_80800408_chboggykidshome, 3);
            break;
    }
}

int func_808002C0_chboggykidshome(param_0) s32 *param_0;
{
    s32 var = param_0[0x1B];
    var = (((u32)var) << 11) >> 20;
    if (var == 0x41D) {
        return 0x3B;
    }
    if (var == 0x3E4) {
        return 0x3C;
    }
    return 0x3D;
}

void func_80800300_chboggykidshome(param_0) Actor *param_0;
{
    if (func_801022E4(param_0) == 0x246) {
        if (func_80101E14(param_0, 0.0f)) {
            func_800C4B7C(D_808005A0_chboggykidshome[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808005BC_chboggykidshome);
        }
        if (func_80101E14(param_0, 0.5f)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808005CC_chboggykidshome);
        }
        if (func_80101E4C(param_0, D_808005AC_chboggykidshome)) {
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808005E8_chboggykidshome);
        }
    }
}
