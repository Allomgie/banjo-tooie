#include "common.h"

extern int D_80800540_chbilldrillboulder;
extern void *D_80800588_chbilldrillboulder;
extern int D_808005D0_chbilldrillboulder;
typedef union { s32 local_0; void *local_1; } BilldrillBoulderEvent;
extern u8 _chbaddiesetup_entrypoint_9[];
extern u8 D_80800684_chbilldrillboulder[];
extern u8 D_80800618_chbilldrillboulder[];
extern u8 D_808006F0_chbilldrillboulder[];
extern Actor *_subaddiefind_entrypoint_2(s32, s32);
extern f32 func_80103EF4(Actor *);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern void func_800EF1B8(f32 *, f32, f32);
extern void _chbaddiesetup_entrypoint_4(void *, s32, s32, s32, s32);
s32 func_808004D4_chbilldrillboulder();
void func_80800024_chbilldrillboulder();

int chbilldrillboulder_entrypoint_0()
{
    return (int)&D_80800540_chbilldrillboulder;
}

int chbilldrillboulder_entrypoint_1()
{
  return &D_80800588_chbilldrillboulder;
}

int chbilldrillboulder_entrypoint_2()
{
    return (int)&D_808005D0_chbilldrillboulder;
}

void func_80800024_chbilldrillboulder(param_0) Actor *param_0;
{
    s32 local_0;
    f32 *local_4;
    u8 *local_5;
    f32 local_1[3];
    s32 local_2;
    f32 local_3[3];
    local_0 = func_808004D4_chbilldrillboulder((u8 *)param_0);
    local_2 = param_0->unk6C_9;
    local_4 = param_0->position;
    if (!(local_2 ^ 0x322)) local_5 = D_80800684_chbilldrillboulder;
    else local_5 = D_80800618_chbilldrillboulder;
    func_800BABB8(0, local_4, local_4, param_0->scale, local_5);
    _subaddieaudioquick_entrypoint_2(param_0, local_4, D_808006F0_chbilldrillboulder);
    if (local_0) {
        func_800DA544(local_0);
        if (local_0 == 0x514) {
            if (param_0->unk64_20) {
                func_800EE7F8(local_1, local_4);
                func_800EF1B8(local_1, param_0->rotation[1] - 70.0f, 450.0f);
                func_800F77E8(func_800F54E4(), local_1);
            }
            func_800F7F98(func_800F54E4(), 1);
            _capod_entrypoint_21(_subaddiefind_entrypoint_2(0x117, 0)->unk0, 0, 0x1D, 0);
            func_800DA544(0x5B);
        }
    }
    if (param_0->unk6C_9 == 0x3CF) {
        local_2 = -1;
        switch (param_0->unk74_7) {
        case 0x33: func_800D1000(param_0->unk6C_0, 4, local_4, 0, 0); break;
        case 0x34: local_2 = 2; break;
        case 0x35: local_2 = 0x15; break;
        case 0x36: local_2 = 0x16; break;
        case 0x37: local_2 = 0x17; break;
        case 0x38: func_800D1000(param_0->unk6C_0, 2, local_4, 0, 0); break;
        }
        if (local_2 != -1) {
            func_800EE7F8(local_3, local_4);
            local_3[1] += 0.5f * func_80103EF4(param_0);
            _chbaddiesetup_entrypoint_4(&_chbaddiesetup_entrypoint_9, local_2, ((s32 *)local_3)[0], ((s32 *)local_3)[1], ((s32 *)local_3)[2]);
        }
    }
}

int func_8080026C_chbilldrillboulder(Actor *param_0)
{
  u16 local_0;
  if ((((((((((((*((u16 *) (((char *) param_0) + 0x72))) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) & 0xFFFFFFFFu) >> (10 & 0xFFFFFFFFFFFFFFFFu)) == 2)
  {
    if (_subaddieDll_entrypoint_6(param_0, 0xB))
    {
      func_8010A570(param_0);
      _chexploder_entrypoint_3(param_0, (Actor *) (((char *) param_0) + 4), 2);
    }
 do { } while (0);
  }
}

void func_808002C4_chbilldrillboulder(Actor *param_0)
{
  s32 local_0;
  s32 local_1;

  local_0 = func_808004D4_chbilldrillboulder();
  if ((local_0 != 0) && (func_800DA298(local_0) != 0)) {
    func_800FFAB0(param_0);
    return;
  }
  if (param_0->unk6C_9 == 0x3CF) {
    local_1 = param_0->unk74_7 - 0x32;
    switch (local_1) {
      case 1:
        param_0->unk6C_0 = _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x201, param_0));
        if (func_800D0A9C(param_0->unk6C_0, 4) != 0) {
          func_800FFAB0(param_0);
          return;
        }
        break;
      case 6:
        param_0->unk6C_0 = _gspropctrl_entrypoint_12(_gccubesearch_entrypoint_0(0x1F7, param_0));
        if (func_800D0A9C(param_0->unk6C_0, 2) != 0) {
          func_800FFAB0(param_0);
        }
        break;
    }
  }
}

s32 func_808003F0_chbilldrillboulder(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;

    switch (param_1) {
        case 0x3F:
            local_0 = *(s32 *)&param_2;
            if (param_0->unk70_10 != 2) {
                if (_subaddieDll_entrypoint_5(param_0, local_0)) {
                param_0->unk64_20 = 1;
                func_80103110(param_0, 1);
                func_80101FDC(param_0, 2);
                }
            }
            break;
        case 0x40:
            func_8010A570(param_0);
            _chexploder_entrypoint_3(param_0, param_0->position, 2);
            break;
        case 0x90:
            func_80800024_chbilldrillboulder(param_0);
            func_800FFAB0(param_0);
            break;
        default:
            return 0;
    }
    return 1;
}

s32 func_808004D4_chbilldrillboulder(param_0) u8 *param_0; {
    s32 local_0;

    if (((u32) ((*(s32 *)((s8 *)(param_0) + (0x6C))) << 0xB) >> 0x14) == 0x3CF) {
        return 0;
    }
    local_0 = ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) - 0x33;
    if ((local_0 < 0) || (local_0 >= 0x1E)) {
        return 0;
    }
    return local_0 + 0x514;
}
