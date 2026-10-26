#include "common.h"

extern void func_800C31DC(u8, f32);
extern void func_800C2FDC(u8);
extern f32 func_800EEB40(f32 *, f32 *);
extern s32 func_800C4350(u8, f32 *, s16 *);
extern s16 D_808003C0_subaddieaudioloop[];
extern void _subaddieaudioquick_entrypoint_0(u8, s32);
extern void func_800C3BDC(u8);
extern s16 D_808003CC_subaddieaudioloop[];
extern s32 func_800D9154(f32 *, f32);
u8 subaddieaudioloop_entrypoint_3();
u8 subaddieaudioloop_entrypoint_7();

void subaddieaudioloop_entrypoint_0(u8 *param_0, f32 param_1) {
    u8 local_0 = param_0[0x5F];
    if (local_0 != 0) {
        func_800C31DC(local_0, param_1);
    }
}

void subaddieaudioloop_entrypoint_1(Actor *this)
{
  unsigned int new_var;
  u8 local_0;
  local_0 = this->unk5F;
 goto dummy_label_322467; dummy_label_322467: ;
  new_var = this->unk5F;
  if (local_0 != (new_var * 0))
  {
    func_800C3058(local_0 & 0xFF);
  }
}

s32 subaddieaudioloop_entrypoint_2(Actor *this){
    u8 local_0 = subaddieaudioloop_entrypoint_3(this->unk5F);
    this->unk5F = local_0;
}

u8 subaddieaudioloop_entrypoint_3(param_0) u8 param_0; {
    if (param_0) {
        func_800C2FDC(param_0);
        param_0 = 0;
    }
    return param_0;
}

int subaddieaudioloop_entrypoint_4(Actor *param_0, f32 *param_1, u32 param_2, u32 *param_3)
{
    param_0->unk5F = subaddieaudioloop_entrypoint_7(param_0->unk5F, param_1, param_2, param_3,
        *(u32 *)((u8 *)param_0 + 0x70) & 1);
    return param_0->unk5F != 0;
}

void subaddieaudioloop_entrypoint_5(Actor *param_0, f32 *param_1, u32 param_2, s32 param_3, u32 *param_4)
{
    f32 local_0[3];

    if (param_2 != 0) {
        func_8010D640(local_0);
        if (param_3 == -1) param_3 = 3000;
        if (param_3 * param_3 < func_800EEB40(local_0, param_1)) param_2 = 0;
    }
    subaddieaudioloop_entrypoint_4(param_0, param_1, param_2, param_4);
}

u8 subaddieaudioloop_entrypoint_6(u8 param_0, f32 *param_1, u32 param_2, s32 param_3, u32 *param_4, s32 param_5)
{
    f32 local_0[3];
    if (param_2) {
        func_8010D640(local_0);
        if (param_3 == -1) param_3 = 3000;
        if (func_800EEB40(local_0, param_1) > param_3 * param_3) param_2 = 0;
    }
    return subaddieaudioloop_entrypoint_7(param_0, param_1, param_2, param_4, param_5);
}

u8 subaddieaudioloop_entrypoint_7(param_0, param_1, param_2, param_3, param_4) u8 param_0; f32 *param_1; u32 param_2; u32 *param_3; s32 param_4;
{
    if (param_2) {
        if (!param_0) {
            param_0 = func_800C4350(param_0, param_1, D_808003C0_subaddieaudioloop);
            func_800C4350(param_0, param_1, (s16 *)param_3);
        }
        if (param_0) {
            _subaddieaudioquick_entrypoint_0(param_0, param_4);
            func_800C4350(param_0, param_1, NULL);
            func_800C3BDC(param_0);
        }
    } else if (param_0) {
        func_800C2FDC(param_0);
        param_0 = 0;
    }
    return param_0;
}

f32 subaddieaudioloop_entrypoint_8(Actor *param_0, s32 param_1, s32 param_2, f32 param_3)
{
    if (param_2) {
        if (!param_0->unk5F) {
            param_0->unk5F = func_800C4350(0, param_0->position, D_808003CC_subaddieaudioloop);
            param_3 = 0.7f;
        } else if (func_800D9154(&param_3, 0.7f)) {
            if (param_0->unk5F) func_800C3BDC(param_0->unk5F);
        }
    } else if (param_0->unk5F) {
        func_800C2FDC(param_0->unk5F);
        param_0->unk5F = 0;
    }
    return param_3;
}
