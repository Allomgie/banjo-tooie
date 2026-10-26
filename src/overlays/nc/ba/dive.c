#include "nc/ba/dive.h"

extern void func_800EF410(int param_0);
extern f32 func_800EEF94(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800D8FF8(void);
extern void func_800EFA20(f32 *, f32 *, f32);

s32 ncbadive_entrypoint_0() 
{
    return 0x10;
}

void ncbadive_entrypoint_1(u8 *param_0) {
    func_800EFD24(*(u8 **)(param_0 + 0x18));
    *(f32 *)((u8 *)(*(u8 **)(param_0 + 0x18)) + 0xC) = 0.0f;
    func_801120CC(param_0, 0x45834000, 0x46034000, 0xC6034000);
}

void ncbadive_entrypoint_2(int param_0)
{
  int new_var;
  new_var = new_var & 0xFF;
  func_801120CC(param_0, 0x44FA0000, 0x457A0000, 0xC57A0000);
}

void func_80800080_ncbadive(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void ncbadive_entrypoint_3(u8 *param_0)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4[3];
    f32 local_5[3];
    f32 local_6;
    f32 local_7;

    func_801107F0(param_0, local_4);
    func_80800080_ncbadive(param_0, local_0);
    func_800EFB24(local_2, local_4, local_0);
    local_6 = func_800EEF94(local_2);
    local_7 = func_800F10B4(*(f32 *)(*(u8 **)(param_0 + 0x18) + 0xC), 0.2f, 0.5f, local_6, 300.0f);
    *(f32 *)(*(u8 **)(param_0 + 0x18) + 0xC) += func_800D8FF8();
    func_800EFA20(local_3, *(f32 **)(param_0 + 0x18), local_7);
    func_800EFB24(local_1, local_0, local_3);
    if (func_80111FD4(param_0, local_1)) {
        func_8011309C(param_0, 0);
    }
    func_80800080_ncbadive(param_0, local_0);
    func_80110A68(param_0, local_5, local_0);
    func_80110790(param_0, local_5);
}

void ncbadive_entrypoint_4(int param_0)
{
    func_800EF410(*(int *)(param_0 + 0x18));
}
