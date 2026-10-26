#include "common.h"

extern int D_80800220_chtnthut;
extern void func_800EE7F8(f32 *, f32 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 D_808002D8_chtnthut;
extern s32 D_80800268_chtnthut;
extern void _chexploder_entrypoint_10();
extern f32 func_800D8FF8(void);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
void func_80800170_chtnthut();

int *chtnthut_entrypoint_0()
{
    return &D_80800220_chtnthut;
}

void func_8080000C_chtnthut(s32 arg0) 
{
}
void func_80800014_chtnthut(Actor *param_0)
{
    if (param_0->unk70_10 == 2) {
        param_0->unk58 += func_800D8FF8();
        if (param_0->unk58 > 0.5f) {
            func_800C4104(0x43F, 0.9f, 0x6D60, param_0->position, 1250.0f, 2500.0f);
            func_800FFAB0(param_0);
        }
    }
}

s32 func_808000B0_chtnthut(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];
    switch (param_1) {
    case 5:
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, param_0->rotation[1], -100.0f);
        local_0[1] += 75.0f;
        _chexploder_entrypoint_3(param_0, local_0, 0);
        break;
    case 0x90:
        func_80800170_chtnthut(param_0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(param_0, 0x84);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800170_chtnthut(param_0) Actor *param_0;
{
  s32 local_0;
  local_0 = func_80106790(func_80101080());
  _chexploder_entrypoint_12(local_0, 0x3C);
  _chexploder_entrypoint_13(local_0, 4);
  _chexploder_entrypoint_10(local_0, &D_808002D8_chtnthut);
  func_800BABB8(0, (u8 *)param_0 + 4, local_0 + 0x18, *((s32 **)((u8 *)param_0 + 0x38)), &D_80800268_chtnthut);
  func_80101FDC(param_0, 2);
  func_80103110(param_0, 1);
  func_800DA544(0x84);
}
