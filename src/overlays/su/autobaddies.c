#include "common.h"

extern u8 _chjiggygamenew_entrypoint_1[];
extern void _chbaddiesetup_entrypoint_4(void *, int, int, int, int);
extern void _suautobaddies_entrypoint_2(void);
extern void func_800C9DAC(f32, void (*)(void));
extern int _chlensflare_entrypoint_0(void);
extern void *_chbaddiesetup_entrypoint_8;
extern int func_800D395C(void);
extern int func_800DB9B0(void);
extern int _gcfrontend_entrypoint_3(int);
extern int func_800D035C(int);
int func_80800104_suautobaddies();
void func_80800194_suautobaddies();
s32 func_80800258_suautobaddies();
void func_80800298_suautobaddies();
void func_8080036C_suautobaddies();
void func_808003DC_suautobaddies();
int suautobaddies_entrypoint_3();

int suautobaddies_entrypoint_0()
{
  func_80800104_suautobaddies();
  func_80800194_suautobaddies();
  func_80800258_suautobaddies();
  func_80800298_suautobaddies();
  func_8080036C_suautobaddies();
  func_808003DC_suautobaddies();
  suautobaddies_entrypoint_3();
  if (_gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(func_800EA05C()), 0x2000) != 0)
  {
    _chbaddiesetup_entrypoint_4(((u8 *) &_chbaddiesetup_entrypoint_8), 0x374, 0, 0, 0);
  }
  if (func_800A9CD0() == 1)
  {
    _chbaddiesetup_entrypoint_0(&_chjiggygamenew_entrypoint_1);
  }
}

int suautobaddies_entrypoint_1()
{
  s32 local_0[2];
  s32 local_3;
  s32 local_6;

  local_3 = _glcutDll_entrypoint_18();
  for (local_6 = func_801067C4(local_0); local_6 != 0; local_6 = func_8010682C(local_0)) {
      func_8010108C(local_6, 0x49, local_3);
  }
}

int func_80800104_suautobaddies()
{
  if (!_glcutDll_entrypoint_1())
  {
    if (!func_800DA298(0x647))
    {
      if (!func_800A9C98())
      {
        if (!_gcintrotext_entrypoint_1())
        {
          if (!_glcutDll_entrypoint_19(0x6F))
          {
            if (!_glcutDll_entrypoint_20())
            {
              if (!_gclevel_entrypoint_4(0x40))
              {
                _chintrotext_entrypoint_2(0);
              }
            }
          }
        }
      }
    }
  }
}

void func_80800194_suautobaddies(void) {
    s32 sp24;

    sp24 = func_800EA05C();
    if ((func_800DB9B0() == 0) && (_glcutDll_entrypoint_1() == 0) && (func_800DA298(0x647) == 0) && (func_800A9C98() == 0) && (_gcsectionDll_entrypoint_4(sp24) != 0xD)) {
        if ((func_800D3934() != 0) || (sp24 == 0xAF)) {
            func_800DA544(0x6A7);
            _chbaddiesetup_entrypoint_4(((s32 *) &_chbaddiesetup_entrypoint_8), 0x153, 0, 0, 0);
            return;
        }
        func_800DA524(0x6A7);
    }
}

s32 func_80800258_suautobaddies(void) {
    if (func_800DA298(0x6B6) && func_800DB9B0()) {
        _suquiz_entrypoint_27();
    }
}

void func_80800298_suautobaddies(void) {
    f32 sp1C[3];
    s32 temp_v0;

    if (func_800DA298(0x650) != 0) {
        temp_v0 = func_800EA05C();
        if ((temp_v0 != 0x19C) && (temp_v0 != 0x19D)) {
            func_800EFD24(sp1C);
            func_80108474(0x174, sp1C, 0);
        }
    }
}

void suautobaddies_entrypoint_2(void)
{
    if (func_800D1A04(0x4B)) {
        func_800D1864(0x4B, 0, 1);
        if (func_800D1A04(0x4C)) func_800C9DAC(1.5f, _suautobaddies_entrypoint_2);
    } else {
        if (func_800D1A04(0x4C)) func_800D1864(0x4C, 0, 1);
    }
}

void func_8080036C_suautobaddies(void)
{
    s32 local_0;
    local_0 = func_800EA05C();
    if (!func_800DB9B0() &&
        (local_0 == 0x154 || local_0 == 0xCA || func_800DA298(0x6E7))) {
        func_800DA524(0x6E7);
        func_800C9DAC(1.5f, _suautobaddies_entrypoint_2);
    }
}

void func_808003DC_suautobaddies()
{
  if (_chlensflare_entrypoint_0())
  {
    _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_8, 0x3FE, 0, 0, 0);
  }
}

int suautobaddies_entrypoint_3()
{
  if (!func_800D395C())
  {
    if (!func_800DB9B0() && !_gcfrontend_entrypoint_3(0x85) && func_800D035C(1) == 0x5A)
    {
      _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_8, 0x524, 0, 0, 0);
    }
  }
}
