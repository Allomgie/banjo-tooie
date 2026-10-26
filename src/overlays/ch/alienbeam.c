#include "common.h"

extern int D_808001A0_chalienbeam;
extern s32 func_800D9078(f32 *);
extern f32 func_800F12D4(f32, f32, f32, f32, f32);
extern void func_800EFE50(f32 *, void *, void *, f32);

int chalienbeam_entrypoint_0()
{
    return (int)&D_808001A0_chalienbeam;
}

void func_8080000C_chalienbeam(void *param_0)
{
    func_800EE7F8(((char *) param_0) + 0x18, ((char *) param_0) + 4, param_0);
    *(f32 *)((char *) param_0 + 0x8) = *(f32 *)((char *) param_0 + 0x8) + 600.0f;
    func_800EE7F8(((char *) param_0) + 0x28, ((char *) param_0) + 4, param_0);
    *(f32 *)((char *) param_0 + 0x58) = 3.0f;
    *(u8 *)((char *) param_0 + 0x7A) = (u8) ((*(u8 *)((char *) param_0 + 0x7A) & 0xFF3F) | 0x80);
    _subaddiefade_entrypoint_1(param_0, 0xC0);
}

void func_80800088_chalienbeam(Actor *param_0)
{
    s32 local_0;
    if (param_0->unk70_10 == 1) {
        local_0 = func_800D9078(&param_0->unk58);
        func_800EFE50(param_0->position, &param_0->actorData[4], param_0->actorData,
            func_800F12D4(param_0->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
        if (local_0) func_80102424(param_0, 2);
    }
}

int func_80800110_chalienbeam(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x4F)
  {
    _subaddiefade_entrypoint_3();
    func_80102424(param_0, 3);
    } else {
        return 0;
    }
    return 1;
}

void func_8080015C_chalienbeam(u8 *param_0, s32 param_1) {
    f32 local_0[3];

    func_800E3A58(local_0);
    *(f32 *)((char *)param_0 + 0x48) = local_0[1];
    func_80101870(param_0, param_1);
}
