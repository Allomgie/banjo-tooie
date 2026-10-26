#include "common.h"

extern int D_808001C0_chcaveofhorrorsdoors;
extern void func_800EF1B8(f32 *, f32, f32);
extern s32 D_80800208_chcaveofhorrorsdoors;
extern s32 func_80101080();
extern s32 func_80106790(s32);
extern void _chexploder_entrypoint_12(s32, s32);
extern void func_800C4AF0();
extern void func_800DA544(s32);
extern void func_800FFAB0();
typedef struct { u8 pad[0x76]; u16 f76:9; u16 pad76:7; } DoorState;
void func_80800144_chcaveofhorrorsdoors();
s32 func_808001A4_chcaveofhorrorsdoors();

int *chcaveofhorrorsdoors_entrypoint_0()
{
    return &D_808001C0_chcaveofhorrorsdoors;
}

int func_8080000C_chcaveofhorrorsdoors(s32 param_0)
{
  s32 local_0;
  unsigned int new_var2;
  int new_var;
  local_0 = func_808001A4_chcaveofhorrorsdoors(param_0);
  ;
  new_var2 = local_0 | local_0;
  if (func_800DA298(new_var = new_var2))
  {
    func_800FFAB0(param_0);
  }
  else
  {
    func_80109EEC(param_0, 0x40);
    _subaddiefade_entrypoint_14(param_0);
    func_8010A63C(param_0);
  }
}

s32 func_8080006C_chcaveofhorrorsdoors(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 local_0[3];

    switch (param_1) {
        case 0x40:
            func_800EE7F8(local_0, param_0->position);
            local_0[1] += 150.0f;
            func_800EF1B8(local_0, param_0->rotation[1], -80.0f);
            _chexploder_entrypoint_3(param_0, local_0, 7);
            if ((s32)param_0->unk74_7 < 0x34) func_800F8300(func_800F54E4(), 2, param_0->position);
            break;
        case 0x90:
            func_80800144_chcaveofhorrorsdoors(param_0);
            break;
        default: return 0;
    }
    return 1;
}

void func_80800144_chcaveofhorrorsdoors(param_0) u8 *param_0; {
    _chexploder_entrypoint_12(func_80106790(func_80101080(param_0)), 0x3C);
    func_800C4AF0(param_0 + 4, &D_80800208_chcaveofhorrorsdoors);
    func_800DA544(func_808001A4_chcaveofhorrorsdoors(param_0));
    func_800FFAB0(param_0);
}

s32 func_808001A4_chcaveofhorrorsdoors(param_0) DoorState *param_0; {
    return param_0->f76 + 0x65;
}
