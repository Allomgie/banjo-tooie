#include "common.h"

extern int D_80800804_chlagoonbits;
extern int D_8080084C_chlagoonbits;
extern s32 D_808008DC_chlagoonbits[];
extern int D_80800924_chlagoonbits;
extern int D_8080096C_chlagoonbits;
typedef struct { u8 pad[0x6C]; u32 pad6C:11; u32 f:12; u32 rest:9; } LagoonS;
extern s32 func_800DA298();
extern void func_800FFAB0();
extern u8 D_808007D0_chlagoonbits[];
extern u8 D_808009B4_chlagoonbits[];
extern s32 D_808009CC_chlagoonbits;
extern u8 D_808009FC_chlagoonbits[];
extern u8 D_808009E4_chlagoonbits[];
extern u8 D_80800A64_chlagoonbits[];
extern s32 D_80800A30_chlagoonbits[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
extern u8 D_80800A7C_chlagoonbits[];
extern u8 D_80800A88_chlagoonbits[];
typedef union LagoonMessage1601 { s32 local_0; s16 local_1[2]; f32 local_2; } LagoonMessage1601;
extern Unk80132ED0 *func_80101080(void);
extern Actor *func_80106790(Unk80132ED0 *);
extern void _chexploder_entrypoint_6(Actor *, f32, f32);
extern void _chexploder_entrypoint_7(Actor *, f32, f32);
void func_80800730_chlagoonbits();
void func_8080023C_chlagoonbits();

int *chlagoonbits_entrypoint_0()
{
    return &D_80800804_chlagoonbits;
}

int chlagoonbits_entrypoint_1()
{
    return (int)&D_8080084C_chlagoonbits;
}

int chlagoonbits_entrypoint_2(void)
{
    extern void *D_80800894_chlagoonbits;
    return (int)&D_80800894_chlagoonbits;
}

int chlagoonbits_entrypoint_3()
{
  return D_808008DC_chlagoonbits;
}

int chlagoonbits_entrypoint_4()
{
    return (int)&D_80800924_chlagoonbits;
}

int chlagoonbits_entrypoint_5()
{
  return (int)&D_8080096C_chlagoonbits;
}

void func_80800048_chlagoonbits(s32 arg0) 
{
}
void func_80800050_chlagoonbits(LagoonS *param_0) {
    if (func_800DA298(param_0->f == 0x368 ? 0xCB : 0xCC)) {
        func_800FFAB0(param_0);
    }
}

void func_808000A4_chlagoonbits(s32 arg0) 
{
}
void func_808000AC_chlagoonbits(Actor *param_0) {
    *(s32 **)((char *)param_0 + 0x28) = _subaddiesect_entrypoint_1();
    if (func_800DA298(0xCF) != 0) {
        func_80108B04(param_0, 0);
        func_80101FDC(param_0, 3);
        *(u8 *)((char *)param_0 + 0x65) = *(u8 *)((char *)param_0 + 0x65) & 0xFFFE;
    }
}

void func_80800108_chlagoonbits(u8 *param_0) {
    s32 local_0;
    s32 local_2;

    (*(s32 *)((s8 *)(param_0) + (0x28))) = _subaddiesect_entrypoint_1();
    func_80102FDC(param_0, 0x3F19999A);
    if (func_800DA9E4(0xD0, 1) == 0) {
        func_800DA7A8(0xD1, func_800DC128(0, 4), 2);
    }
    local_0 = func_800DA564(0xD1, 2);
    local_2 = ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) - 0x32;
    if ((func_800DA298(0x45, local_2) != 0) || (local_0 != local_2)) {
        if ((local_0 == local_2) && (func_800D0B68(0x14, 0) == 0)) {
            func_800D1000(0x14, 0, param_0 + 4, 3, 0);
        }
        func_800FFAB0(param_0);
        return;
    }
    _subaddiesect_entrypoint_2(param_0, (*(s32 *)((s8 *)(param_0) + (0x28))), 1);
}

int func_808001F4_chlagoonbits(s32 param_0)
{
  if ((2 == (((*((u16 *) (((u8 *) param_0) + 0x72))) & 0xFFFFFFFFu) >> 10)) && _subaddieDll_entrypoint_6(param_0, 11))
  {
    func_8080023C_chlagoonbits(param_0);
  }
 do { } while (0);
}

void func_80800548_chlagoonbits();

void func_808004B0_chlagoonbits();

void func_80800360_chlagoonbits();

void func_808002CC_chlagoonbits();

void func_8080023C_chlagoonbits(param_0) u8 *param_0;
{
  u32 temp_t8;
  temp_t8 = (((u32) ((*((s32 *) (((s8 *) param_0) + 0x6C))) << 0xB)) >> 0x14) & 0xFFFFFFFFFFFFFFFF;
  switch (temp_t8)
  {
    case 0x366:
      func_808002CC_chlagoonbits();
      return;

    case 0x367:
      ;
      ;
      ;

    case 0x368:
      func_80800360_chlagoonbits();
      return;

    case 0x369:
      func_8080041C_chlagoonbits();
      return;

    case 0x36C:
      func_808004B0_chlagoonbits();
      return;

    case 0x36D:
      func_80800548_chlagoonbits();

    default:
      return;

  }

}

void func_808002CC_chlagoonbits(param_0) Actor *param_0; {
    f32 local_0[3];
    func_800EE7F8(local_0, (s32 *)((char *)param_0 + 0x4));
    func_800EF1B8(local_0, *(s32 **)((char *)param_0 + 0x48), 0xC2C80000);
    _chexploder_entrypoint_3(param_0, local_0, 0xE);
    func_800BBCB8((s32 *)((char *)param_0 + 0x4), local_0, 0.8f, 5, &D_808007D0_chlagoonbits);
    _subaddieaudioquick_entrypoint_2(param_0, (s32 *)((char *)param_0 + 0x4), &D_808009B4_chlagoonbits);
    func_800DA544(0xCE);
}

void func_80800360_chlagoonbits(param_0) u8 *param_0; {
    s32 local_0;
    f32 local_1[3];

    if (((u32) ((*(s32 *)((s8 *)(param_0) + (0x6C))) << 0xB) >> 0x14) == 0x368) {
        local_0 = 0xCB;
    } else {
        local_0 = 0xCC;
    }
    func_800EE7F8(local_1, param_0 + 4);
    func_800EF1B8(local_1, (*(s32 *)((s8 *)(param_0) + (0x48))), 0xC2C80000);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_808009CC_chlagoonbits);
    func_800BBCB8(param_0 + 4, local_1, 0.8f, 5, ((s32 *) D_808007D0_chlagoonbits));
    _chexploder_entrypoint_3(param_0, local_1, 0xE);
    func_800DA544(local_0);
}

int func_8080041C_chlagoonbits(param_0) Actor *param_0;
{
  f32 local_0[3];
  func_800EE7F8(local_0, (u8 *)param_0 + 4);
  local_0[1] -= 100.0f;
  _subaddieaudioquick_entrypoint_2(param_0, (u8 *)param_0 + 4, D_808009E4_chlagoonbits);
  func_800BBCB8((u8 *)param_0 + 4, local_0, 0.8f, 5, D_808009FC_chlagoonbits);
  _chexploder_entrypoint_3(param_0, local_0, 0xe);
  func_800DA544(0xcd);
}

void func_808004B0_chlagoonbits(param_0) Actor *param_0;
{
    f32 *local_0;
    local_0 = param_0->position;
    _chexploder_entrypoint_3(param_0, local_0, 7);
    _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800A64_chlagoonbits);
    func_800BBCB8(local_0, local_0, 2.0f, 6, D_80800A30_chlagoonbits);
    func_80108B04(param_0, 0);
    func_80101FDC(param_0, 3);
    param_0->unk64_16 = 0;
    func_800DA544(0xCF);
}

void func_80800548_chlagoonbits(param_0) Actor *param_0;
{
    f32 *local_0 = param_0->position;
    func_800D1000(20, 0, local_0, 1, 0);
    _chexploder_entrypoint_3(param_0, local_0, 7);
    func_800BBCB8(local_0, local_0, 0.8f, 5, D_808007D0_chlagoonbits);
    func_800DA544(0x45);
    func_800FFAB0(param_0);
}

void func_808005D0_chlagoonbits(u16 *actor, s32 param_1) {
    if (((u32)((u16)actor[57]) >> 10) == 3) {
        func_800FFAB0();
    }
    if (param_1 == 0) {
        func_80102FDC(func_80108474(0x156, &D_80800A88_chlagoonbits, 0), 0x3F666666);
        func_80102FDC(func_80108474(0x157, &D_80800A7C_chlagoonbits, 0), 0x3F666666);
    }
}

s32 func_80800658_chlagoonbits(Actor *param_0, s32 param_1, LagoonMessage1601 param_2)
{
    Actor *local_0;

    switch (param_1) {
    case 0x40:
        func_80800730_chlagoonbits(param_0, param_2.local_0);
        break;
    case 0x3D:
        func_808005D0_chlagoonbits(param_0, param_2.local_0);
        break;
    case 0x90:
        local_0 = func_80106790(func_80101080());
        switch (param_2.local_0) {
        case 0x761:
            _chexploder_entrypoint_6(local_0, 500.0f, 600.0f);
            _chexploder_entrypoint_7(local_0, -500.0f, -400.0f);
            break;
        case 0x786:
            _chexploder_entrypoint_12(local_0, 50);
            break;
        }
        break;
    default:
        return 0;
    }
    if (param_2.local_0) {}
    return 1;
}

void func_80800730_chlagoonbits(param_0) u8 *param_0;
{
  s32 val = *((s32 *) (((char *) param_0) + 0x6C));
  if ((((u32) ((val << 7) << 4)) >> 0x14) == 0x369)
  {
    if (_subaddieDll_entrypoint_5() != 0)
    {
      func_80103110(param_0, 1);
      func_80101FDC(param_0, 2);
      return;
    }
    func_8080023C_chlagoonbits(param_0);
    return;
  }
  func_8080023C_chlagoonbits(param_0);
}
