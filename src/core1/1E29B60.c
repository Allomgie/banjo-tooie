#include "core1/1E29B60.h"

extern char core1_BSS_START;
extern char core1_BSS_END;
extern void bzero(void *, int);
extern void osWritebackDCacheAll(void);
extern void osInitialize(void);
extern void func_80013620(void);
extern s32 D_80043380;
extern s32 D_800459CC;
extern void func_8001207C();
extern void func_8001A2B0();
extern void func_800A7B24();
extern void func_800155BC();
extern void func_800A7BB8();
extern s32 D_800459C8;
extern s32 D_8007E994;
extern u8 core2_DATA_START[];
s32 D_800459D0;
s32 D_800459D4;
u64 D_800459D8;
extern u8 core2_RODATA_END[];
extern f32 D_800416A0;
extern s32 D_80043384;
extern f32 func_800D9004(void);
extern u8 D_80045938[];
extern u8 D_80045788[];

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
int func_80012520();
void func_8001253C();

void func_80012030(s32 param_0)
{
    bzero(&core1_BSS_START, &core1_BSS_END - &core1_BSS_START);
    osWritebackDCacheAll();
    osInitialize();
    func_80013620();
}

void func_8001207C(void) 
{
    func_800D5E74();
}

void func_8001209C(s32 param_0)
{
  s32 new_var;
  new_var = (new_var = param_0);
  func_8001A2B0();
  func_800155BC();
  if (D_80043380 == 1)
  {
    if (!new_var)
    {
    }
    func_800A7B24();
  }
  func_8001207C();
  D_80043380 = new_var;
  if (new_var == 1)
  {
    func_800A7BB8(D_800459CC);
  }
}

s32 func_8001210C(s32 param_0)
{
  return D_800459C8 & param_0;
}

s32 func_8001211C(void) 
{
    return D_800459C8;
}

void func_80012128(void) {
    D_800459C8 = 0;
}

int func_80012134()
{
  s32 local_0;
  local_0 = _cosection_entrypoint_1();
  func_8001253C(local_0 | 0);
  func_80012520(1);
}

s32 func_80012164()
{
  s32 local_0;
  local_0 = _cosection_entrypoint_0();
  func_8001253C(local_0 | 0);
  func_80012520(1);
}

s32 func_80012194(void)
{
    return D_8007E994 - (s32)core2_VRAM_END;
}

s32 func_800121AC()
{
  return core2_VRAM_END - (s32)&func_80012030 + 0xFFF21DD0;
}

void func_800121D0(void)
{
  s32 local_0;
  s32 v1;
  local_0 = func_80012194();
  if (1)
  {
    v1 = func_8001E830() + local_0;
    while (v1 & 0xF)
    {
      v1--;
    }

  }
  return;
}

// Needs migration
#if 0

#else
void func_80012214(void)
{
  D_800459D0 = osGetMemSize();
  func_8001DDF0();
  init_crc_check();
  func_80014FE8();
  func_8001E7E8();
  func_8001C1C0();
  func_80019EC0(0, core2_VRAM, core2_VRAM_END, core2_ROM_START, core2_ROM_END, core2_TEXT_START, core2_TEXT_END, core2_DATA_START, core2_RODATA_END, core2_BSS_START, core2_BSS_END);
  heap_setup(1);
  func_80014E6C();
  D_80043388.unk400 = 0x01020304;
  D_80043388.unk404 = 0x05060708;
  D_800459D8 = 0x0102030405060708ULL;
  func_801168F0();
  func_800815CC();
  func_8001A080();
  func_8001A2D0();
  func_800121D0();
  func_80016734();
  func_800184E8();
  func_800125B0();
  func_8001A3A0();
  func_800D66AC();
  func_800D5D70();
  func_800E692C();
  _gcstatusDll_entrypoint_0();
  func_800C929C();
  D_80043380 = 0;
  D_800459C8 = 0;
  func_800A5BE0();
  func_800D740C();
  func_8001253C(_cosection_entrypoint_1());
  func_8001209C(1);
}
#endif

s32 func_800123B0()
{
    return D_800459D0;
}

s32 func_800123BC(void)
{
  if (func_800A7D84())
  {
    func_800A7840(0);
  }
  func_800A5D1C();
}

void func_800123F4(void) {
    func_8001207C();
    if ((D_80043380 != 1) || (func_800A8184() != 4)) {
        D_800459C8 += 1;
    }
    if (func_80012530() == 1) {
        func_800A7D30();
    }
    func_8001608C();
    func_80018444();
    if (D_80043380 == 1) {
        func_800123BC();
    }
    func_8008160C(1);
    func_8001E010();
    if (func_800D9004() <= D_800416A0) {
        do_crc_check();
    }
    if (D_80043384 != 0) {
        func_8001209C(D_80043384 - 1);
        D_80043384 = 0;
    }
}

void func_800124EC(s32 param_0)
{
  func_80012214();

  while (1) {
    func_800123F4();
  }
}

int func_80012520(param_0) s32 param_0;
{
  D_80043384 = param_0 + 1;
}

int func_80012530()
{
    return D_80043380;
}

void func_8001253C(param_0) s32 param_0;
{
    D_800459CC = param_0;
}

void func_80012548()
{
    func_8001DD28(&D_80045788, &D_80045938, 6, &func_800124EC, 0, (u8 *)D_80045938 - 0x1B0, 0x14);
}

int *func_80012598()
{
    return ((int *) D_80045788);
}
