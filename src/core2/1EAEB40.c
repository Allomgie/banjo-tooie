#include "common.h"

extern s8 D_8012B431;
extern unsigned char D_8012B430;
extern s16 D_8012B432;
extern void (*D_8011B680[])(s32, s32);
extern void (*D_8011B7C0[])(s32, s32);

void func_800D52B0(void);

void func_800D5250()
{
    func_800D52B0();
}

int func_800D5270()
{
  D_8012B431 = 0;
}

void func_800D527C(s32 param_0)
{
  int new_var;
  short new_var2;
  new_var2 = 0xFFFFu;
  ((s8 *) &D_8012B430)[0] = (param_0 & new_var2) + 1;
  new_var = param_0;
  new_var = 2;
  new_var = new_var + new_var;
  new_var = 1;
  new_var2 = new_var;
  ((s8 *) &D_8012B430)[new_var] = new_var2;
}

u8 func_800D5298()
{
  return D_8012B431;
}

s32 func_800D52A4(void)
{
  return (*((u8 *) &D_8012B430));
}

void func_800D52B0(void)
{
    *(unsigned char *)((char *)&D_8012B430 + 1) = 0;
    *(short *)((char *)&D_8012B430 + 2) = -1;
    *(unsigned char *)((char *)&D_8012B430 + 0) = 0;
}

int func_800D52CC(volatile int param_0)
{
  s16 local_0;
  func_800D52B0();
  D_8012B432 = param_0 & 0xFFFFFFFFu;
}

s32 func_800D52F4()
{
  return D_8012B432;
}

void func_800D5300(s32 arg0, s32 arg1) {
}
void func_800D530C(s32 arg0, s32 arg1) {
}
void func_800D5318(s32 param_0, s32 param_1)
{
    s32 local_0;
    switch (_gspropctrl_entrypoint_2(param_0))
    {
    case 3:
        local_0 = func_8001211C();
        if ((_gspropctrl_entrypoint_3(param_0) + 1) != local_0)
        {
            D_8011B680[_gspropctrl_entrypoint_4(param_0)](param_0, param_1);
        }
        _gspropctrl_entrypoint_5(param_0, local_0);
        return;
    case 5:
        _gcsectionskip_entrypoint_1(param_0, *(u16 *)(param_0 + 8) + 0xA0, *(s32 *)(param_0 + 12) & 0x7FFFFF, *(u8 *)(param_0 + 11), param_1);
        return;
    case 4:
        D_8011B7C0[_gspropctrl_entrypoint_4(param_0)](param_0, param_1);
        return;
    }
}

func_800D5424(s32 param_0) {
    s32 local_0;
    local_0 = param_0 - 0x16;
    return local_0;
}

func_800D542C(param_0){
    return param_0 + 0x9A;
}
