#include "common.h"

extern __OSBlockInfo B_80800290_fxdialog;
extern f32 B_808002A0_fxdialog;
extern void func_800E2554(f32, f32);
extern void func_800E257C(s32);
extern f32 B_808002A4_fxdialog;
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void *func_800DF944(u32, f32 *, f32, f32, f32 *, s32, s32);

void fxdialog_entrypoint_0(void)
{
  *((s32 *) (((s8 *) (((s32 *) &B_80800290_fxdialog))) + 0xC)) = 0;
  *((s32 *) (((s8 *) (((s32 *) &B_80800290_fxdialog))) + 8)) = 0;
  *((f32 *) (((s8 *) (((s32 *) &B_80800290_fxdialog))) + 0x10)) = 1.0f;
  *((f32 *) (((s8 *) (((s32 *) &B_80800290_fxdialog))) + 4)) = 0.0f;
  *((f32 *) (((s8 *) (((s32 *) &B_80800290_fxdialog))) + 0)) = (f32) (*((f32 *) (((s8 *) (((s32 *) &B_80800290_fxdialog))) + 4)));
}

void fxdialog_entrypoint_1(s32 param_0, s32 param_1)
{
  char *new_var;
  new_var = (char *) (&B_80800290_fxdialog);
  *((f32 *) (((char *) (&B_80800290_fxdialog)) + 0x4)) = (f32) param_1;
  *((s32 *) (((char *) (&B_80800290_fxdialog)) + 0x8)) = param_0 << 2;
  *((s32 *) (((char *) (&B_80800290_fxdialog)) + 0xC)) = param_1 << 2;
  *((f32 *) (new_var + 0x0)) = (f32) param_0;
  *((f32 *) (((char *) (&B_80800290_fxdialog)) + 0x4)) = (f32) param_1;
}

fxdialog_entrypoint_2(f32 param_0)
{
    if (param_0 > 0.0f)
    {
        *(f32*)((char*)((u8 *) &B_80800290_fxdialog) + 0x10) = param_0;
        *(f32*)((char*)((u8 *) &B_80800290_fxdialog) + 0x14) = 1.0f / param_0;
    }
}

void fxdialog_entrypoint_3(u32 param_0, f32 param_1, s32 param_2, s32 param_3)
{
    f32 local_0[2];
    f32 local_1[3];
    s32 local_2;

    local_2 = func_801040D0(param_0);
    local_0[1] = -24.0f;
    local_0[0] = 0.0f;
    func_800EFA4C(local_1, param_1 * 0.041666667f * B_808002A4_fxdialog - 2.0f, 0.0f, 0.0f);
    func_800DFFA0(local_2, 0x2A, local_1);
    func_800DF41C(local_2);
    func_800DF410(param_3);
    func_800DF944(param_0, (f32 *)((s32 *) &B_80800290_fxdialog), param_2 * 90.0f, ((f32 *)((s32 *) &B_80800290_fxdialog))[4], local_0, 0, func_800D674C(0x9F1));
}

void fxdialog_entrypoint_4(s32 param_0, s32 param_1, s32 param_2, f32 param_3, f32 param_4, s32 param_5, s32 param_6)
{
    s32 local_0[2];
    f32 local_1;
    f32 local_2;

    local_1 = param_6 ? -B_808002A0_fxdialog : B_808002A0_fxdialog;
    local_2 = B_808002A0_fxdialog;
    func_800E2554(local_1, local_2);
    func_800E257C(param_5);
    local_0[0] = ((s32 *) &B_80800290_fxdialog)[2] + param_3 * 4.0f * local_1;
    local_0[1] = ((s32 *) &B_80800290_fxdialog)[3] + param_4 * 4.0f * local_2;
    func_800E30E0(param_0, func_800D674C(param_1), param_2, local_0);
}
