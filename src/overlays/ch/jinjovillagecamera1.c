#include "common.h"

extern u8 D_80800470_chjinjovillagecamera1[];
extern u8 D_8080047C_chjinjovillagecamera1[];
extern u8 D_80800488_chjinjovillagecamera1[];
extern int D_80800494_chjinjovillagecamera1[];

void func_80800000_chjinjovillagecamera1(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1)
    {
    case 0x1522:
        _glcutDll_entrypoint_17();
        return;
    case 0x1523:
    case 0x1524:
    case 0x1565:
        func_80101FDC(param_0, 2);
        param_0->unk58 = 1.5f;
        return;
    }
}

int func_80800078_chjinjovillagecamera1(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_5;
    s32 local_4;
    s32 local_3;
    switch (param_1) {
    case 0xB:
        local_0 = func_800DA564(0x6D0, 4);
        if (func_800EA05C() == 0x142) {
            local_1 = _chjinjo_entrypoint_3(local_0);
            _glcutDll_entrypoint_24(local_1, _glcutDll_entrypoint_9(), 0x84);
            return 3;
        }
        if (param_2 == D_8080047C_chjinjovillagecamera1[local_0]) func_800DA544(0x39E);
        return 3;
    case 0x49:
        local_2 = func_800DA564(0x6D0, 4);
        if (!_glcutDll_entrypoint_19(0x84)) return 0;
        if (func_800EA05C() == 0x142) _capod_entrypoint_13(param_0->unk0, 0, D_80800470_chjinjovillagecamera1[local_2], 0x810);
        else {
            _capod_entrypoint_13(param_0->unk0, 0, D_8080047C_chjinjovillagecamera1[local_2], 0x2830);
            if (!func_800DA9E4(0x43C, 1)) {
                local_3 = func_800D1338(local_2);
                local_5 = func_800D129C(local_2);
                if (local_5 == local_3) {
                    func_800DA544(0x43D);
                    _subaddiedialog_entrypoint_11(param_0->unk0, 0x1524, 4, 0, _chjinjo_entrypoint_0(local_2));
                } else _subaddiedialog_entrypoint_11(param_0->unk0, 0x1522, 4, 0, _chjinjo_entrypoint_0(local_2));
            } else if (!func_800DA9E4(0x43D, 1)) {
                local_4 = local_2 == 0 ? 0x1565 : 0x1523;
                _subaddiedialog_entrypoint_11(param_0->unk0, local_4, 4, 0, _chjinjo_entrypoint_0(local_2));
            }
        }
        break;
    case 0x2E:
        func_80800000_chjinjovillagecamera1(param_0, ((s16 *)&param_2)[0], ((s16 *)&param_2)[1]);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_808002BC_chjinjovillagecamera1(param_0) s32 param_0;
{
  s32 local_0;
  local_0 = _chjinjo_entrypoint_2(-1);
  if (local_0 != -1)
  {
    func_800BF744(9, 0);
    func_800BF744(D_80800488_chjinjovillagecamera1[local_0], 1);
  }
}

int func_80800310_chjinjovillagecamera1()
{
    s32 local_1;
    s32 local_2;
    s32 local_0;
    s32 new_var;

    func_808002BC_chjinjovillagecamera1();
    if (func_800EA05C() != 0x142) {
        local_1 = _chjinjo_entrypoint_2(-1);
        local_2 = func_800D1338(local_1);
        local_0 = func_800D129C(local_1);
        new_var = local_2 == local_0;
        if (_glcutDll_entrypoint_19(0x84) != 0) {
            if ((new_var == 0) || (local_0 == 1)) {
                func_80101180(0x48F, 0x7E, 0);
            }
        } else if (new_var != 0) {
            func_800FDC28(0x12);
        }
    }
}

void func_808003C0_chjinjovillagecamera1(u8 *param_0)
{
  u32 temp_t6;
  temp_t6 = (u16) (*((u16 *) (((s8 *) param_0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  switch (temp_t6)
  {
    case 2:
      if (func_800D9078(param_0 + 0x58) != 0)
    {
      _chjinjo_entrypoint_1(_chjinjo_entrypoint_2(-1), 0);
      func_80101FDC(param_0, 3);
      *((f32 *) (((s8 *) param_0) + 0x58)) = 2.5f;
      return;
    }
      return;

    case 3:
      if (func_800D9078(param_0 + 0x58) != 0)
    {
      _glcutDll_entrypoint_17();
    }
      break;

  }

}

int chjinjovillagecamera1_entrypoint_0()
{
    return (int)&D_80800494_chjinjovillagecamera1;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/jinjovillagecamera1.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800494_chjinjovillagecamera1 -> int[] */
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
u8 D_80800470_chjinjovillagecamera1[12] = { 0x10, 0x18, 0x0, 0x16, 0xD, 0x6, 0x3, 0xA, 0x13, 0x0, 0x0, 0x0 };
u8 D_8080047C_chjinjovillagecamera1[12] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
u8 D_80800488_chjinjovillagecamera1[12] = { 0x4, 0x5, 0x1, 0x9, 0x6, 0x8, 0x3, 0x7, 0x2, 0x0, 0x0, 0x0 };
int D_80800494_chjinjovillagecamera1[19] = { 0x158048E, 0x1, 0x0, (u32)func_808003C0_chjinjovillagecamera1, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x80404, 0x0, 0x0, 0x0, (u32)func_80800310_chjinjovillagecamera1, (u32)func_80107C2C, -0x7FFFDFFE, (u32)func_80800078_chjinjovillagecamera1, 0x0, 0x0 };
