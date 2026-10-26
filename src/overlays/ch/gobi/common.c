#include "common.h"

extern u8 D_8080021C_chgobicommon[];
extern u8 D_80800244_chgobicommon[];
extern u8 D_8080022C_chgobicommon[];
extern u8 D_80800254_chgobicommon[];
extern u8 D_80800238_chgobicommon[];
extern void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
extern int D_80800264_chgobicommon;
extern int D_80800270_chgobicommon;
extern int D_80800200_chgobicommon;
extern int D_80800210_chgobicommon;
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
