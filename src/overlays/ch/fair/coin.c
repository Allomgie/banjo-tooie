#include "common.h"

extern s32 D_80800150_chfaircoin;
extern int D_8080015C_chfaircoin;
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8001395C(f32);
extern void func_800EFE50(f32 *, f32 *, f32 *, f32);

void func_80800000_chfaircoin(Actor *param_0)
{
    f32 local_0;

    func_800D9078((f32 *)&param_0->actorData[3]);
    local_0 = func_800F10B4(*(f32 *)&param_0->actorData[3], param_0->unk58, 0.0f, 0.0f, 1.0f);
    func_800EFE50(param_0->position, (f32 *)&param_0->actorData[4], (f32 *)&param_0->actorData[0], local_0);
    param_0->position[1] += func_8001395C(local_0 * 3.1415927f) * 200.0f;
    if (*(f32 *)&param_0->actorData[3] == 0.0f) {
        func_800FFAB0(param_0);
        func_800FC660(0xE);
    }
}

u8 *chfaircoin_entrypoint_0(s32 param_0, s32 param_1, f32 param_2) {
    u8 *local_0;

    local_0 = func_80108474(0x166, param_0, 0);
    func_800EE7F8(local_0 + 0x18, param_1);
    func_800EE7F8(local_0 + 0x28, param_0);
    (*(f32 *)((s8 *)(local_0) + (0x24))) = param_2;
    (*(f32 *)((s8 *)(local_0) + (0x58))) = param_2;
    func_800C4AF0(0, &D_80800150_chfaircoin);
    return local_0;
}

int chfaircoin_entrypoint_1()
{
    return (int)&D_8080015C_chfaircoin;
}
