#include "common.h"

extern f32 func_800DC0C0(void);
extern f32 func_800D8FF8(void);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern void func_800BABA0(s32, f32);
extern s32 D_80800340_chusefeather[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void *_chusefeather_entrypoint_0;
extern void _chbaddiesetup_entrypoint_2(void *, s32, s32);
extern s32 func_800D3948(void);
extern int D_80800364_chusefeather;
extern s32 D_808003AC_chusefeather[];
extern f32 func_800F5F24(s32);
extern Actor *func_80108474(u32, f32 *, s32);
extern void func_80102FDC(Actor *, f32);

void func_80800000_chusefeather(Actor *param_0)
{
    s32 local_2;
    s32 local_3;
    f32 local_0[3];
    s32 local_4;

    func_800EF1B8(param_0->position, param_0->rotation[1], ((f32 *)param_0->actorData)[3]);
    if (((f32 *)param_0->actorData)[1] > -100.0f) ((f32 *)param_0->actorData)[1] -= 3.5f;
    if (param_0->position[1] > -16000.0f) param_0->position[1] += ((f32 *)param_0->actorData)[1];
    if (param_0->unk58 > 0.5f) {
        for (local_2 = 0; local_2 < 3; local_2++) {
            local_0[local_2] = param_0->position[local_2] + func_800DC0C0() * 2.0f * 25.0f - (local_2 == 1 ? 0 : 25);
        }
        local_3 = func_800BABB8(0, local_0, NULL, 1.0f, D_80800340_chusefeather);
        func_800BA3FC(local_3, param_0->unk6C_9 == 0x26A ? 0x9E4 : 0x9E2);
        func_800BA75C(local_3, local_0);
        func_800BABA0(local_3, 0.25f);
    }
    param_0->unk58 -= func_800D8FF8();
    if (param_0->unk58 < 0) func_800FFAB0(param_0);
    else {
        local_4 = func_800F10B4(param_0->unk58, 0.0f, 0.3f, 0.0f, 255.0f);
        _subaddiefade_entrypoint_1(param_0, local_4);
        if (local_4 == 0) func_800FFAB0(param_0);
    }
}

void chusefeather_entrypoint_0(s32 param_0, s32 param_1)
{
    Actor *local_0;
    f32 local_1[3];
    s32 local_2;
    f32 local_3;

    func_800F5A00(param_0, local_1);
    local_3 = func_800F5F24(param_0);
    local_2 = func_800DC0C0() > 0.5f ? 30 : -30;
    local_0 = func_80108474(param_1, local_1, (s32)((f32)local_2 + local_3));
    func_80102FDC(local_0, 0.45f);
    *(f32 *)&local_0->actorData[3] = 22.0f;
    *(f32 *)&local_0->actorData[1] = 48.0f;
    local_0->unk58 = 1.2f;
}

void chusefeather_entrypoint_1(s32 param_0, s32 param_1)
{
  s32 local_0;

  if (func_800D3948() == 0) {
    if (param_1 == 0) {
      local_0 = 0x26A;
    } else {
      local_0 = 0x26B;
    }
    _chbaddiesetup_entrypoint_2(&_chusefeather_entrypoint_0, param_0, local_0);
  }
}

int *chusefeather_entrypoint_2()
{
    return &D_80800364_chusefeather;
}

int chusefeather_entrypoint_3()
{
  return D_808003AC_chusefeather;
}
