#include "common.h"

extern int D_80800298_chfactorygoblin;
extern u8 D_808002E0_chfactorygoblin[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, void *);
void func_8080007C_chfactorygoblin();

int chfactorygoblin_entrypoint_0()
{
    return (int)&D_80800298_chfactorygoblin;
}

int func_8080000C_chfactorygoblin(s32 param_0)
{
  _sucoaster_entrypoint_0(param_0, 0);
  func_8010A3E8(param_0, 0x3F400000);
}

s32 func_8080003C_chfactorygoblin(s32 param_0, s32 param_1, s32 param_2){
    if(param_1 == 0xB6){
        func_8080007C_chfactorygoblin(param_0, param_1, param_2);
    }
    _sucoaster_entrypoint_21(param_0, param_1, param_2);
}

void func_8080007C_chfactorygoblin(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    s32 local_4;
    s32 local_5;
    local_4 = func_800DC128(6, 8);
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], param_0->scale * 200.0f);
    func_800EE7F8(local_1, local_0);
    local_1[1] -= 5.0f;
    local_3 = func_800B53A4(local_4);
    for (local_5 = 0; local_5 < local_4; local_5++) {
        func_800EEB9C(local_2, local_5 * (360.0f / local_4), 20.0f);
        func_800EF04C(local_2, local_0);
        func_800BABB8(local_3, local_2, local_1, param_0->scale * 0.5f, &D_808002E0_chfactorygoblin);
    }
}
