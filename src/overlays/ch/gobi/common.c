#include "common.h"

extern u8 D_8080021C_chgobicommon[];
extern u8 D_80800244_chgobicommon[];
extern u8 D_8080022C_chgobicommon[];
extern u8 D_80800254_chgobicommon[];
extern u8 D_80800238_chgobicommon[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern int D_80800264_chgobicommon[];
extern int D_80800270_chgobicommon[];
extern int D_80800200_chgobicommon[];
extern int D_80800210_chgobicommon[];
void func_80800070_chgobicommon();
void func_808000EC_chgobicommon();
void func_808001AC_chgobicommon();

s32 chgobicommon_entrypoint_0(s32 param_0){
    switch(func_801022E4(param_0)){
        case 0x221:
            func_80800070_chgobicommon(param_0);
            break;
        case 0x222:
            func_808000EC_chgobicommon(param_0);
            break;
        case 0x223:
            func_808001AC_chgobicommon(param_0);
            break;
        default:
            break;
    }
}

void func_80800070_chgobicommon(param_0) Actor *param_0;
{
    _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_8080021C_chgobicommon, D_80800244_chgobicommon);
    _subaddieaudioquick_entrypoint_4(param_0, param_0->position, D_8080022C_chgobicommon, D_80800254_chgobicommon);
    if (!func_800C0638()) _subaddieaudioquick_entrypoint_3(param_0, param_0->position, D_80800238_chgobicommon, 0.03f);
}

void func_808000EC_chgobicommon(param_0) s32 param_0;
{
  s32 s1 = param_0;
  unsigned int new_var;
  int s0;
 if (1) { } if (1) { } if (1) { }
  if (!func_800C0638())
  {
    new_var = 4;
    _subaddieaudioquick_entrypoint_4(s1, s1 + new_var, &D_80800264_chgobicommon, &D_80800270_chgobicommon);
  }
  s0 = s1 + 4;
  new_var = s1;
  _subaddieaudioquick_entrypoint_3(new_var, s0, &D_80800200_chgobicommon, 0.26f);
  _subaddieaudioquick_entrypoint_3(new_var, s0, &D_80800210_chgobicommon, 0.41f);
  _subaddieaudioquick_entrypoint_3(new_var, s0, &D_80800200_chgobicommon, 0.55f);
  _subaddieaudioquick_entrypoint_3(new_var, s0, &D_80800200_chgobicommon, 0.62f);
}

void func_808001AC_chgobicommon(param_0) u8 *param_0; {
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, ((s32 *) &D_80800200_chgobicommon), 0.65f);
    _subaddieaudioquick_entrypoint_3(param_0, param_0 + 4, ((s32 *) &D_80800210_chgobicommon), 0.0f);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/gobi/common.data.s) is defined here in C.
 * Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800200_chgobicommon -> int[], D_80800210_chgobicommon -> int[], D_80800264_chgobicommon -> int[], D_80800270_chgobicommon -> int[] */
int D_80800200_chgobicommon[4] = { 0x130402, 0x1636B0, 0xA00E6, 0x0 };
int D_80800210_chgobicommon[3] = { 0x130402, 0x1636B0, 0x0 };
u8 D_8080021C_chgobicommon[16] = { 0x0, 0x13, 0x4, 0x9C, 0x0, 0x16, 0x36, 0xB0, 0x0, 0xD, 0x0, 0xD9, 0x0, 0xF3, 0x0, 0x0 };
u8 D_8080022C_chgobicommon[12] = { 0x0, 0x13, 0x5, 0xBB, 0x0, 0xD, 0x0, 0xF3, 0x1, 0xC, 0x0, 0x0 };
u8 D_80800238_chgobicommon[12] = { 0x0, 0x13, 0x4, 0xCA, 0x0, 0xD, 0x1, 0x26, 0x1, 0x40, 0x0, 0x0 };
u8 D_80800244_chgobicommon[16] = { 0x3E, 0xDC, 0x28, 0xF6, 0x3E, 0xF5, 0xC2, 0x8F, 0x3F, 0xF, 0x5C, 0x29, 0xBF, 0x80, 0x0, 0x0 };
u8 D_80800254_chgobicommon[16] = { 0x3F, 0x26, 0x66, 0x66, 0x3F, 0x46, 0x66, 0x66, 0x3F, 0x66, 0x66, 0x66, 0xBF, 0x80, 0x0, 0x0 };
int D_80800264_chgobicommon[3] = { 0x1304CA, 0xD0126, 0x1400000 };
int D_80800270_chgobicommon[4] = { 0x3E2E147B, 0x3EA3D70A, 0x3EF5C28F, -0x40800000 };
