#include "common.h"

typedef struct { s16 local_0; s16 local_1; s32 local_2; s32 local_3; s32 local_4; f32 local_5; f32 local_6; } FlashCycleState;
extern f32 func_800DC264(f32, f32);
extern f32 func_800D8FF8(void);
extern s32 func_800F1574(f32 *, f32);
extern void _idflasha_entrypoint_0(void);
void func_80800038_idflasha();

void idflasha_entrypoint_0(s32 param_0, u32 param_1, u8 *param_2, s32 param_3, s16 *param_4)
{
    u32 local_0;
    s32 local_1;

    local_1 = *param_4;
    local_0 = param_1 + param_3 * 0x10;
    while (param_1 < local_0) {
        param_1 += 0x10;
        param_2 += 0x10;
        param_2[-1] = local_1;
    }
}

void func_80800038_idflasha(param_0, param_1) FlashCycleState *param_0; s32 param_1;
{
    f32 local_0;

    if (param_1 == 1) {
        param_0->local_0 = 0;
        param_0->local_1 = func_800DC214(200, 255);
        param_0->local_2++;
        local_0 = func_800DC264(0.08f, 0.12f);
        param_0->local_5 = local_0;
        param_0->local_6 = local_0;
    }
    if (param_1 == 0) {
        param_0->local_0 = 0;
        if (param_0->local_2 > 0 && param_0->local_2 < param_0->local_3) {
            param_0->local_5 = func_800DC264(0.1f, 0.2f);
        } else {
            param_0->local_2 = 0;
            param_0->local_3 = func_800DC214(1, 4);
            param_0->local_5 = func_800DC264(4.0f, 6.0f);
        }
    }
    param_0->local_4 = param_1;
}

s32 idflasha_entrypoint_1(s16 *param_0){
    s16 out;
    out = *param_0;
    return out;
}

void idflasha_entrypoint_2(s32 arg0) 
{
}
void idflasha_entrypoint_3(void *param_0, s32 param_1, s32 param_2, s32 param_3)
{
  int new_var;
  void *new_var2;
  *(u16 *)((char *)(param_0) + 0x0) = 0;

 goto dummy_label_240018;
  ((s32 *) param_0)[0] = 0;
  dummy_label_240018:
  ;

  ((s32 *) param_0)[1] = 0;
  new_var = 2;
  ((s32 *) param_0)[new_var] = new_var;
  ((s32 *) param_0)[3] = 0;
  new_var2 = param_0;
  func_80800038_idflasha(new_var2, 0);
}

void idflasha_entrypoint_4(u8 *param_0, s32 param_1, s32 param_2)
{
    f32 local_0;

    f32 local_2;

    local_0 = func_800D8FF8();
    if (*(s32 *)(param_0 + 0xC) == 0 && func_800F1574((f32 *)(param_0 + 0x10), local_0)) {
        func_80800038_idflasha(param_0, 1);
    }
    if (*(s32 *)(param_0 + 0xC) == 1) {
        if ((*(f32 *)(param_0 + 0x10)) <= 0.04f) {
            *(s16 *)param_0 = (s32)((f32)*(s16 *)(param_0 + 2) * ((*(f32 *)(param_0 + 0x10)) / 0.04f));
        } else {
            local_2 = *(f32 *)(param_0 + 0x14);
            if ((*(f32 *)(param_0 + 0x10)) < local_2 - 0.04f) {
                *(s16 *)param_0 = *(s16 *)(param_0 + 2);
            } else {
                *(s16 *)param_0 = (s32)((f32)*(s16 *)(param_0 + 2) * ((local_2 - (*(f32 *)(param_0 + 0x10))) / 0.04f));
            }
        }
        if (func_800F1574((f32 *)(param_0 + 0x10), local_0)) {
            func_80800038_idflasha(param_0, 0);
        }
    }
    _glid_entrypoint_0(param_1, param_2, _idflasha_entrypoint_0, param_0);
}
