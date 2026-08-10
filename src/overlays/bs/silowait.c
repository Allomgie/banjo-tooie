#include "common.h"

extern s32 D_80800140_bssilowait[];

/* Auf Dateiebene, weil der erste Aufruf weiter unten sonst eine implizite
   int-Deklaration erzeugt, die der blockgueltigen widerspricht. */
extern void func_80092880(Actor *a0, s32 a1);

int func_80800000_bssilowait(Actor *param_0)
{
  func_80092880(param_0, 1);
  func_80091E6C(param_0);
  baphysics_reset_gravity(param_0);
  baphysics_reset_terminal_velocity(param_0);
}

int func_8080003C_bssilowait(Actor *param_0)
{
  extern void baanim_playForDuration_loop(Actor *a0, s32 a1, f32 a2);
  extern void baphysics_set_target_horizontal_velocity(Actor *a0, f32 a1);
  extern void baphysics_set_gravity(Actor *a0, f32 a1);
  extern void func_8009FFD8(Actor *a0, s32 a1, s32 a2, s32 a3, s32 a4);
  extern void baphysics_set_terminal_velocity(Actor *a0, f32 a1);
  extern void func_8009BA9C(Actor *a0, s32 a1);
  extern void func_80091E48(Actor *a0, s32 a1);
  extern void func_80092880(Actor *a0, s32 a1);

  baanim_playForDuration_loop(param_0, 0x6f, 5.5f);
  func_8009FFD8(param_0, 1, 1, 3, 6);
  baphysics_set_target_horizontal_velocity(param_0, 0.0f);
  func_8009BA9C(param_0, 0);
  baphysics_set_gravity(param_0, 0);
  baphysics_set_terminal_velocity(param_0, 0);
  func_80091E48(param_0, 0x33);
  func_80092880(param_0, 0);
}

s32 func_808000D0_bssilowait(s32 param_0){
    if(func_8009E6EC() == 0x90){
        bs_setState(param_0, 1);
        func_8009E830(param_0, 2);
    }
    else{
        func_80099AA8(param_0);
    }
}

void func_80800120_bssilowait(s32 arg0) 
{
}
int bssilowait_entrypoint_0(s32 param_0)
{
  return D_80800140_bssilowait[param_0];
}
