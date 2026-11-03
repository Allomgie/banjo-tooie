#include "common.h"

#define ACTOR_CALLBACK_DATA_DEFINED
extern int D_80800380_chbigterrysbits[];
extern int D_808003C8_chbigterrysbits[];
extern int D_80800410_chbigterrysbits[];
extern void func_80101FDC(Actor *, s32);
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
typedef union { s32 word; void *pointer; } ActorCallbackData;
extern s32 _subaddieDll_entrypoint_5(Actor *, void *);
extern void func_80103110(Actor *, s32);
extern void _chexploder_entrypoint_3(void *param_0, f32 *local_0, int param_2);
extern void _subaddieaudioquick_entrypoint_2(void *param_0, void *param_1, void *param_2);
extern void func_800DA544(int param_0);
extern void func_800EE7F8(f32 *param_0, void *param_1);
extern u8 D_80800458_chbigterrysbits[];
void func_8080022C_chbigterrysbits();

int chbigterrysbits_entrypoint_0()
{
    return (int)&D_80800380_chbigterrysbits;
}

int chbigterrysbits_entrypoint_1()
{
    return (int)&D_808003C8_chbigterrysbits;
}

int chbigterrysbits_entrypoint_2()
{
    return (int)&D_80800410_chbigterrysbits;
}

void func_80800024_chbigterrysbits(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800D395C();
    local_1 = func_800DA298(0x172);
    if (func_800F64A4(func_800F54E4(), 0x1000) || _glcutDll_entrypoint_20()) {
        func_80101FDC(param_0, 1);
    }
    param_0->rotation[0] = -50.0f;
    func_8010A800(param_0, 0);
    if (_chdoormake_entrypoint_3(param_0, 0.0f, param_0->rotation[0] + 90.0f, -400.0f, 0x802, -1)) {
        _chdoormake_entrypoint_5(param_0, 3.0f);
        _chdoormake_entrypoint_6(param_0, 0.8f);
        _chdoormake_entrypoint_8(param_0, 0xE);
    }
    if (!_glcutDll_entrypoint_20() && local_0 && !local_1) {
        func_8010108C(param_0, 8, 0);
    }
}

s32 func_80800130_chbigterrysbits(Actor *this){
    if(_glcutDll_entrypoint_20())
        func_800FFAB0(this);
}

void func_80800160_chbigterrysbits(void *param_0)
{
  if ((2 == (((*((u16 *) (((u8 *) param_0) + 0x72))) & 0xFFFFFFFFu) >> 10)) && _subaddieDll_entrypoint_6(param_0, 11))
  {
    func_8080022C_chbigterrysbits(param_0);
  }
 do { } while (0);
}

s32 func_808001A8_chbigterrysbits(Actor *param_0, s32 param_1, ActorCallbackData param_2)
{
    switch (param_1) {
        case 0x3F:
            if (_subaddieDll_entrypoint_5(param_0, param_2.pointer)) {
                func_80103110(param_0, 1);
                func_80101FDC(param_0, 2);
                return 1;
            }
            break;
        case 0x40:
            func_8080022C_chbigterrysbits(param_0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_8080022C_chbigterrysbits(param_0) Actor *param_0;
{
  f32 local_0[3];
  func_800EE7F8(local_0, (u8 *)param_0 + 4);
  local_0[1] -= 80.0f;
  _chexploder_entrypoint_3(param_0, local_0, 0xc);
  _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, (void *)&D_80800458_chbigterrysbits);
  func_800DA544(0x173);
}

void func_8080029C_chbigterrysbits(Actor *param_0)
{
    s32 local_0;
    s32 local_1;

    local_0 = func_800DA298(0xE5);
    local_1 = func_800D395C();
    if (_glcutDll_entrypoint_20()) {
        func_800FFAB0(param_0);
    } else {
        if (local_0 && !local_1) func_80101FDC(param_0, 4);
        param_0->rotation[0] = -90.0f;
        func_8010A800(param_0, 0);
        if (_chdoormake_entrypoint_3(param_0, param_0->rotation[1],
                param_0->rotation[0] + 90.0f, -400.0f, 3, -1)) {
            _chdoormake_entrypoint_5(param_0, 3.0f);
            _chdoormake_entrypoint_6(param_0, 0.8f);
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/bigterrysbits.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800380_chbigterrysbits -> int[], D_808003C8_chbigterrysbits -> int[], D_80800410_chbigterrysbits -> int[] */
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
extern void _chdoor_entrypoint_1();
extern void func_80108ED0();
int D_80800380_chbigterrysbits[18] = { 0xAC0461, 0x7C40004, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x752F, 0x0, 0x0, 0x400, 0x0, 0x0, 0x0, (u32)func_80800024_chbigterrysbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)_chdoor_entrypoint_1, 0x0 };
int D_808003C8_chbigterrysbits[18] = { 0x2FF0365, 0x7530001, 0x0, (u32)func_80800160_chbigterrysbits, (u32)func_80105834, (u32)func_80101870, 0x752F, 0x0, 0x1730000, 0xC00, 0x0, (u32)func_80108ED0, 0x0, (u32)func_80800130_chbigterrysbits, (u32)func_80107C2C, -0x7FFFD400, (u32)func_808001A8_chbigterrysbits, 0x0 };
int D_80800410_chbigterrysbits[18] = { 0xAC0469, 0x7C40001, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x752F, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_8080029C_chbigterrysbits, (u32)func_80107C2C, -0x7FFFD3FE, (u32)_chdoor_entrypoint_1, 0x0 };
u8 D_80800458_chbigterrysbits[24] = { 0x0, 0x13, 0x4, 0xF4, 0x0, 0xA, 0x0, 0xCC, 0x0, 0x16, 0x6D, 0x60, 0x0, 0x1, 0x4, 0xE2, 0x1F, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
