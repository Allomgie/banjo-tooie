#include "common.h"

extern f32 func_800DC178(f32, f32);
extern s32 D_80800300_sufreezy;
extern void func_8010A570(s32);
extern s32 _sueggmisc_entrypoint_0(s32);
extern void func_8010114C(s32, s32, s32);
extern u8 D_80800328_sufreezy[];
extern u8 D_80800314_sufreezy[];
extern Actor *func_80106790();
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_801094E0(f32 *, f32);
extern void _subaddieaudioquick_entrypoint_2();

void sufreezy_entrypoint_0(param_0) u8 *param_0; {
    *(f32 *)(param_0 + 0x58) = func_800DC178(6.0f, 10.0f);
}

void sufreezy_entrypoint_1()
{
    sufreezy_entrypoint_0();
}

void sufreezy_entrypoint_2(s32 param_0) {
    u8 *local_0;

    local_0 = _subaddielink_entrypoint_4(func_80100094(param_0, 1));
    func_8010A570(param_0);
    if (local_0 != NULL) {
        (*(u8 *)((s8 *)(local_0) + (0x7B))) = (u8) ((*(u8 *)((s8 *)(local_0) + (0x7B))) & 0xFFFB);
        func_80102190(local_0, 0);
        func_8010A590(local_0);
        func_8010108C(local_0, 4, 0);
    }
    _subaddielink_entrypoint_0(func_80100094(param_0, 1));
}

void sufreezy_entrypoint_3(s32 param_0) {
    _subaddieaudioquick_entrypoint_2(param_0, 0, &D_80800300_sufreezy);
}

void sufreezy_entrypoint_4(Unk80132ED0 *param_0, s32 param_1)
{
    Actor *local_0;

    local_0 = func_80106790(param_0);
    func_800BBCB8(local_0->position, local_0->position, local_0->scale, param_1, D_80800328_sufreezy);
    _subaddieaudioquick_entrypoint_2(local_0, NULL, D_80800314_sufreezy);
    func_801094E0(local_0->position, local_0->scale * 1.4f);
}

void sufreezy_entrypoint_5(s32 param_0, s32 param_1) {
    func_8010A570(func_80106790(param_0));
    if (_sueggmisc_entrypoint_0(param_1) != 0) {
        func_8010114C(param_1, 5, 0);
    }
}

void sufreezy_entrypoint_6(s32 param_0, s32 param_1) {
    u8 *local_0 = func_80106790(param_0);
    *(f32 *)(local_0 + 0x58) = func_800DC178(6.0f, 10.0f);
}

int sufreezy_entrypoint_7(s32 param_0, s32 param_1)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  u8 *local_3;
  local_0 = func_80106790();
  local_1 = func_80100094(local_0, 1);
  local_3 = _subaddielink_entrypoint_4(local_1);
  func_8010A570(local_0);
  func_8010A590(local_3);
  func_80102190(local_3, 0);
  local_3[0x7B] = local_3[0x7B] & 0xFFFB;
  func_8010108C(local_3, 4, 0);
  local_2 = _glhittableDll_entrypoint_4(param_0, *(s32 *)local_3);
  if (_glhittableDll_entrypoint_2(local_2) != 0)
  {
    func_800EB2DC(*(s32 *)local_3, param_0, local_2);
  }
  else
  {
    func_800EB210(*(s32 *)local_3, param_0, 2);
  }
  _subaddielink_entrypoint_0(func_80100094(local_0, 1));
}
