#include "common.h"

extern int D_80800408_chdiggerground;
extern void *func_80100094(Actor *, u32);
typedef struct { u8 pad[0x64]; u32 pad64:11; u32 flag:1; u32 r64:20; u8 pad68[4]; u32 f6C:11; u32 r6C:21; } DigS;
extern void func_80101FDC(DigS *, s32);
extern void func_8010A3E8(DigS *, f32);
extern void func_80101870(Actor *, s32);
extern void _sucoaster_entrypoint_20(Actor *, s32);
extern s32 D_80800450_chdiggerground[];
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_800EF04C(f32 *, f32 *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
extern s32 func_800DC298(f32);
extern s32 func_800D9058(f32);
void func_80800214_chdiggerground();
void func_808000C4_chdiggerground();

int chdiggerground_entrypoint_0()
{
  return (int)&D_80800408_chdiggerground;
}

void func_8080000C_chdiggerground(Actor *param_0)
{
    if (param_0->unk64_20) {
        if (func_80100094(param_0, 0) == NULL) {
            func_808000C4_chdiggerground(param_0);
            func_8010108C(param_0, 0x95, 0);
        }
        _sucoaster_entrypoint_2(param_0);
    }
}

void func_80800070_chdiggerground(DigS *param_0) {
    if (param_0->f6C != 0) {
        func_80101FDC(param_0, 1);
        func_808000C4_chdiggerground(param_0);
        param_0->flag = 1;
    }
    func_8010A3E8(param_0, 0.75f);
}

void func_808000C4_chdiggerground(param_0) Actor *param_0;
{
    _subaddieDll_entrypoint_1(param_0);
    if (_sucoaster_entrypoint_0(param_0, 0)) {
        _sucoaster_entrypoint_10(param_0, func_800DC298(0.65f) ? 3 : 2);
        if (param_0->pad6C_21 == 0) param_0->unk6C_0 = func_800D9058(1.5f);
        param_0->unk64_24 = 1;
        func_8010A590(param_0);
    }
}

int func_80800168_chdiggerground(s32 param_0, s32 param_1, s32 param_2)
{
  s32 local_0;
  if (!func_80100094(param_0, 0))
  {
    return 0;
  }
  else
  {
    if (param_1 == 0xB6)
    {
      func_80800214_chdiggerground(param_0);
    }
    _sucoaster_entrypoint_21(param_0, param_1, param_2);
  }
}

void func_808001C8_chdiggerground(Actor *param_0, s32 param_1) {
    if (func_80100094(param_0, 0) == NULL) {
        func_80101870(param_0, param_1);
    } else {
        _sucoaster_entrypoint_20(param_0, param_1);
    }
}

void func_80800214_chdiggerground(param_0) Actor *param_0;
{
    s32 local_3;
    Vec3f local_0;
    Vec3f local_1;
    Vec3f local_2;
    s32 local_4;
    func_800EE7F8(local_1.f, param_0->position);
    func_800EF1B8(local_1.f, param_0->rotation[1], param_0->scale * 80.0f);
    func_800EE7F8(local_2.f, local_1.f);
    local_2.f[1] -= 10.0f;
    local_3 = func_800B53A4(8);
    for (local_4 = 0; local_4 != 8; local_4++) {
        func_800EEB9C(local_0.f, local_4 * 45.0f, 20.0f);
        func_800EF04C(local_0.f, local_1.f);
        func_800BABB8(local_3, local_0.f, local_2.f, 1.0f, D_80800450_chdiggerground);
    }
}
