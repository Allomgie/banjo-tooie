#include "common.h"

extern u8 D_8012C800[];
extern void func_80020790(s16, u16, u8, f32, u8, s32, s32);

void func_800DC380(void) {
    *(u32*)((char*)&D_8012C800 + 0x0) = 0x32;
    *(u32*)((char*)&D_8012C800 + 0x4) = 0x100;
    *(u16*)((char*)&D_8012C800 + 0x10) = 0x40;
    *(u32*)((char*)&D_8012C800 + 0x8) = 0x18;
    *(u32*)((char*)&D_8012C800 + 0xC) = func_80012EDC(&D_8012C800);
    func_8001EB10(&D_8012C800);
}

void func_800DC3D4(s32 param_0, f32 param_1, u16 param_2, u8 param_3, u8 param_4, s32 param_5) {
    func_80020790(param_0 + 1, param_2, param_3, param_1, param_4, 0, param_5);
}

int func_800DC42C(s32 param_0, s32 volatile param_1)
{
  func_80020C08(param_0, 0x10, param_1);
}

int func_800DC454(param_0, param_1) s32 param_0; u16 param_1;
{
  if (param_1 >= 0x8000)
  {
    param_1 = 0x7FFF;
  }
  func_80020C08(param_0, 8, param_1);
}

void func_800DC48C(s32 arg0,s32 arg1)
{
    func_80020C08(arg0,0x100,arg1);
}

void func_800DC4B0(s32 arg0,s32 arg1)
{
    func_80020C08(arg0,0x4,arg1);
}

int func_800DC4D4(s32 param_0)
{
  if (param_0 != 0 && func_80020760(param_0))
  {
    func_80020A60(param_0);
  }
}

void func_800DC508()
{
    func_80020760();
}

int func_800DC528()
{
  func_800E9054(0);
}

int func_800DC548()
{
    s32 *local_0;
    local_0 = (s32 *)func_800E9320();
    if (local_0[1] == -1)
    {
        return 1;
    }
    return 0;
}
