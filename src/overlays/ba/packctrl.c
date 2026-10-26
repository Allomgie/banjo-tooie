#include "common.h"
#include "playerstate.h"

extern void func_8009EA58(s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800984F0(PlayerState *, f32 *);
typedef struct { f32 local_0; f32 local_1; f32 local_2; f32 local_3; f32 local_4[3]; u8 local_5; } PackState48;
extern void func_80098494(void *, f32, f32, f32, f32);
extern void func_800984CC(void *, f32 *);
void func_80800008_bapackctrl();
int bapackctrl_entrypoint_5();

s32 bapackctrl_entrypoint_0() 
{
    return 0x20;
}

int bapackctrl_entrypoint_1();

void func_80800008_bapackctrl(param_0) PlayerState *param_0;
{
    f32 local_0[3];
    if (bapackctrl_entrypoint_1(param_0)) {
        func_800EFA4C(local_0, 1.7f, 1.7f, 2.6f);
    } else {
        func_800EFA4C(local_0, 1.0f, 1.0f, 1.0f);
    }
    func_800984F0(param_0, local_0);
}

int bapackctrl_entrypoint_1(s32 param_0)
{
  s32 new_var4;
  s32 *new_var3;
  s32 new_var2;
  s32 *new_var;
  new_var3 = (0, new_var = &param_0);
 new_var4 = *new_var3; dummy_label_706621: ;
  func_8009EA58(new_var2 = new_var4);
}

void bapackctrl_entrypoint_2(s32 arg0)
{
    bapackctrl_entrypoint_5(arg0,0);
}

void bapackctrl_entrypoint_3(u8 *param_0) {
    f32 local_0;
    u8 *local_1;

    local_1 = (*(u8 **)((s8 *)(param_0) + (0xD8)));
    local_0 = (*(f32 *)((s8 *)(local_1) + (0xC)));
    (*(f32 *)((s8 *)(local_1) + (8))) = local_0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xD8)))) + (4))) = local_0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xD8)))) + (0))) = local_0;
    func_800EFD24((*(u8 **)((s8 *)(param_0) + (0xD8))) + 0x10);
    func_80800008_bapackctrl(param_0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(param_0) + (0xD8)))) + (0x1C))) = 0;
    bapackctrl_entrypoint_5(param_0, 1);
}

int bapackctrl_entrypoint_4(s32 param_0, s32 param_1)
{
  func_8009EADC(param_1 | 0);
  func_80800008_bapackctrl(param_0);
}

int bapackctrl_entrypoint_5(param_0, param_1) u8 *param_0; u32 param_1;
{
    f32 local_0;

    (*(PackState48 **)(param_0 + 0xD8))->local_5 = param_1;
    switch (param_1) {
    case 0:
        func_80098480(param_0, 0, 0);
        break;
    case 1:
        func_80098480(param_0, 0, 0);
        break;
    case 2:
        func_80098480(param_0, 1, 0);
        (*(PackState48 **)(param_0 + 0xD8))->local_0 = 80.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_1 = 13.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_2 = 50.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_3 = 40.0f;
        break;
    case 3:
        func_80098480(param_0, 1, 1);
        (*(PackState48 **)(param_0 + 0xD8))->local_0 = 80.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_1 = 13.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_2 = 50.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_3 = 40.0f;
        func_800EFA4C((*(PackState48 **)(param_0 + 0xD8))->local_4, 0.0f, -0.2f, -0.4f);
        break;
    case 4:
        func_80098480(param_0, 1, 1);
        (*(PackState48 **)(param_0 + 0xD8))->local_0 = 50.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_1 = 13.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_2 = 50.0f;
        (*(PackState48 **)(param_0 + 0xD8))->local_3 = 40.0f;
        func_800EFA4C((*(PackState48 **)(param_0 + 0xD8))->local_4, 0.0f, -0.2f, -0.4f);
        break;
    case 5:
        func_80098480(param_0, 1, 1);
        (*(PackState48 **)(param_0 + 0xD8))->local_3 = 0.0f;
        local_0 = (*(PackState48 **)(param_0 + 0xD8))->local_3;
        (*(PackState48 **)(param_0 + 0xD8))->local_2 = local_0;
        (*(PackState48 **)(param_0 + 0xD8))->local_1 = local_0;
        (*(PackState48 **)(param_0 + 0xD8))->local_0 = local_0;
        func_800EFD24((*(PackState48 **)(param_0 + 0xD8))->local_4);
        break;
    }
    func_80098494(param_0,
        (*(PackState48 **)(param_0 + 0xD8))->local_0,
        (*(PackState48 **)(param_0 + 0xD8))->local_1,
        (*(PackState48 **)(param_0 + 0xD8))->local_2,
        (*(PackState48 **)(param_0 + 0xD8))->local_3);
    func_800984CC(param_0, (*(PackState48 **)(param_0 + 0xD8))->local_4);
}
