#include "common.h"

extern int D_808002D0_chhotfloorsmoke;
extern s32 func_800D9078(f32 *);
extern f32 func_800DC178(f32, f32);
extern u8 D_80800388_chhotfloorsmoke[];
extern u8 D_80800318_chhotfloorsmoke[];
extern u8 D_80800350_chhotfloorsmoke[];
extern s32 func_800E3E8C(s32, f32);
extern void func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
void func_808000FC_chhotfloorsmoke();
void func_808001E8_chhotfloorsmoke();

int chhotfloorsmoke_entrypoint_0()
{
  return (int)&D_808002D0_chhotfloorsmoke;
}

void func_8080000C_chhotfloorsmoke(Actor *param_0)
{
  s32 temp_v0;
  *((u8 *) (((s8 *) param_0) + 0x65)) = (u8) (((*((u8 *) (((s8 *) param_0) + 0x65))) & 0xFFu) | 0x10);
  temp_v0 = func_800EA05C();
  if (temp_v0 != 0xD1)
  {
    if (temp_v0 != 0x12B)
    {
      *((u16 *) (((s8 *) param_0) + 0x6E)) = (u16) ((*((u16 *) (((s8 *) param_0) + 0x6E))) & 0xFE00);
      return;
    }
    *((u8 *) (((s8 *) param_0) + 0x65)) = (u8) ((*((u8 *) (((s8 *) param_0) + 0x65))) & 0xFFEF);
    *((u16 *) (((s8 *) param_0) + 0x6E)) = (u16) (((*((u16 *) (((s8 *) param_0) + 0x6E))) & 0xFE00) | 2);
    return;
  }
  *((u16 *) (((s8 *) param_0) + 0x6E)) = (u16) (((*((u16 *) (((s8 *) param_0) + 0x6E))) & 0xFE00) | 1);
}

void func_80800090_chhotfloorsmoke(Actor *param_0)
{
    switch (param_0->unk70_10) {
    case 1:
        func_808000FC_chhotfloorsmoke(param_0);
        break;
    case 2:
        if (func_800D9078(&param_0->unk58)) {
            func_80101FDC(param_0, 1);
        }
        break;
    }
}

void func_808000FC_chhotfloorsmoke(param_0) Actor *param_0;
{
    f32 local_1;
    f32 local_0[3];

    switch (*(u32 *)((u8 *)param_0 + 0x6C) & 0x1FF) {
    case 1:
        if (!func_800DA298(0x66F)) {
            return;
        }
        local_1 = func_800DC178(1.0f, 1.5f);
        break;
    case 2:
        local_1 = func_800DC178(1.0f, 1.5f);
        break;
    default:
        local_1 = func_800DC178(2.0f, 3.0f);
        break;
    }
    func_800CD08C((*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, local_0);
    local_0[1] = param_0->position[1];
    func_808001E8_chhotfloorsmoke(param_0, (s32)local_0);
    func_80101FDC(param_0, 2);
    param_0->unk58 = local_1;
}

void func_808001E8_chhotfloorsmoke(param_0, param_1) Actor *param_0; s32 param_1;
{
    f32 local_0[3];
    f32 local_1[3];

    if (func_800E3E8C(param_1, 500.0f)) {
        func_800EE7F8(local_0, param_1);
        local_0[1] -= 400.0f;
        func_800EE7F8(local_1, param_1);
        local_1[1] -= 20.0f;
        func_800BABB8(0, local_1, local_0, 1.0f, param_0->unk6C_0 == 2 ? D_80800350_chhotfloorsmoke : D_80800318_chhotfloorsmoke);
    }
    if (param_0->unk64_20 && !func_800DA298(0x66F)) {
        _subaddieaudioquick_entrypoint_2(param_0, param_1, D_80800388_chhotfloorsmoke);
    }
}
