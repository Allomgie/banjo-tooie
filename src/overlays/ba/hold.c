#include "ba/hold.h"
#include "playerstate.h"

extern void func_8009ADF0(void *, s32, s32);
typedef struct { u8 pad[4]; f32 f4; f32 f8; f32 fC; u8 pad10[0x38]; f32 f48; u8 pad4C[0x19]; u8 flag:1; u8 rest:7; } HoldS;
extern HoldS *func_80106790(s32);
typedef struct { f32 local_0; f32 local_1; void *local_2; } HoldData;
extern void func_8008FF40(f32 *);
extern void func_80092D44(PlayerState *, f32 *);
extern f32 func_800136E4(f32);
void bahold_entrypoint_7(Actor *param_0, f32 param_1, f32 param_2);

s32 bahold_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_bahold(param_0, param_1) u8 *param_0; s32 param_1;
{
    *(s32 *)(*(u8 **)(param_0 + 0x9C) + 8) = param_1;
    func_8009ADF0(param_0, 0xE, param_1 != 0 ? 1 : 0);
}

void bahold_entrypoint_1(u8 *param_0) {
    func_80800008_bahold(param_0, 0);
    (*(u8 **)(param_0 + 0x9C))[0xC] = 0;
    bahold_entrypoint_7(param_0, 0.0f, 0.0f);
}

void bahold_entrypoint_2(s32 arg0) 
{
}
void func_80800088_bahold(s32 param_0, f32 *param_1, f32 *param_2) {
    HoldS *local_0 = func_80106790(param_0);
    if (local_0->flag) {
        local_0->f4 = param_1[0];
        local_0->f8 = param_1[1];
        local_0->fC = param_1[2];
        local_0->f48 = param_2[1];
    }
}

void func_808000E0_bahold(param_0) PlayerState *param_0;
{
    f32 local_1[3];
    f32 local_0[3];
    func_8008FF40(local_0);
    func_80092D44(param_0, local_1);
    local_0[1] = func_800136E4(local_0[1] + ((HoldData *)param_0->unk9C)->local_1);
    local_1[1] += ((HoldData *)param_0->unk9C)->local_0;
    func_80800088_bahold(((HoldData *)param_0->unk9C)->local_2, local_1, local_0);
}

void bahold_entrypoint_3(void *param_0)
{
  int new_var;
  void *temp_v0;
  ;
  if ((*((s32 *) (((char *) (*((void **) (((char *) param_0) + 0x9C)))) + 8))) != 0)
  {
    ;
    if ((*((u8 *) (((char *) (*((void **) (((char *) param_0) + 0x9C)))) + 0xC))) == 0)
    {
      func_80800008_bahold(param_0, 0);
      return;
    }
    func_808000E0_bahold();
    *((u8 *) (((char *) (*((void **) (((char *) param_0) + 0x9C)))) + 0xC)) = 0;
  }
}

void bahold_entrypoint_4(s32 arg0)
{
    func_80800008_bahold(arg0,0);
}

Unk80132ED0 * bahold_entrypoint_5(PlayerState * param_0) {
    return *(s32 *)(*(s32 *)((char *)(param_0) + 0x9C) + 0x8);
}

void bahold_entrypoint_6(u8 *param_0) {
    func_80800008_bahold();
    func_808000E0_bahold(param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0x9C)))) + (0xC))) = 1;
}

void bahold_entrypoint_7(Actor *param_0, f32 param_1, f32 param_2) {
    *(f32 *)((u8 *)*(void **)((u8 *)param_0 + 0x9C) + 0) = param_1;
    *(f32 *)((u8 *)*(void **)((u8 *)param_0 + 0x9C) + 4) = param_2;
}
