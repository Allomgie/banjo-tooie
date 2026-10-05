#include "common.h"

extern u8 D_80127115;
extern u8 D_80127114;
extern s32 defrag(s32);

extern s32 D_80127110;

void func_800A5BE0()
{
    _chbaddieDll_entrypoint_0(&D_80127110);
}

void func_800A5C04()
{
  D_80127110 = heap_alloc(0x2C0);
}

int func_800A5C28()
{
  _gccollectDll_entrypoint_4();
  _chbaddieDll_entrypoint_1(((int *) &D_80127110));
  _subaddietaxi_entrypoint_4();
  _cosectionstor_entrypoint_4(func_800EA05C());
  func_80108C14();
  func_800FFB74();
  if (!func_8001E204())
  {
    func_800BDCDC();
  }
}

int func_800A5C94()
{
  if (((char) (*((s8 *) &D_80127115))) != 0)
  {
    func_801002C0();
  }
  return;
}

int func_800A5CC4()
{
  _subaddietaxi_entrypoint_3();
  _chbaddieDll_entrypoint_2(&D_80127110);
}

int func_800A5CF0(int param_0)
{
  D_80127115 = param_0;
}

void func_800A5CFC()
{
    func_800FF62C();
}

int func_800A5D1C()
{
  if (D_80127114 != 0)
  {
    func_8010D1E8();
    _chbaddieDll_entrypoint_3(((int *) &D_80127110));
  }
  func_800FFB74();
}

int func_800A5D60()
{
    return (int)&D_80127110;
}

int func_800A5D6C()
{
  if (D_80127110 != 0)
  {
    D_80127110 = defrag(D_80127110);
  }
}
