#include "ch/mole.h"

extern void *D_80800258_chmole_maya;

extern MoveData D_808001E0_chmole_maya[];
extern D_808000D0 D_80800210_chmole_maya;

void func_80800000_chmole_maya(Actor* a0, u32 a1, u32 a2)
{
	_sumole_entrypoint_3(a0, a1, a2, D_808001E0_chmole_maya);
}

void func_80800024_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_0(a0, 0);
	a0->unk74_7 = a0->unk74_7 - 0x32;
	a0->unk54 = a0->unk74_7;
}

void func_80800090_chmole_maya(Actor* a0)
{
	_sumole_entrypoint_4(a0, D_808001E0_chmole_maya);
}

void* chmole_maya_entrypoint_0()
{
	return &D_80800210_chmole_maya;
}

void func_808000C0_chmole_maya(u8 *param_0) {
    if ((func_8010C500(param_0) != 0) && (func_8008FA2C(-1, 0) != 0)) {
        (*(u8 *)((s8 *)(param_0) + (0x7E))) = (u8) ((*(u8 *)((s8 *)(param_0) + (0x7E))) & 0xFFBF);
        func_800DA544(0x506);
        _subaddiedialog_entrypoint_11((*(s32 *)((s8 *)(param_0) + (0))), 0xDBF, 0xC, param_0 + 4, 0x6F);
        _capod_entrypoint_13((*(s32 *)((s8 *)(param_0) + (0))), 0, 0xB, 0x20);
    }
}

void func_80800144_chmole_maya(s32 arg0) 
{
}
s32 func_8080014C_chmole_maya(s32 param_0) {
    if (func_800DA298(0x506)) {
        func_800FFAB0(param_0);
    }
}

int func_80800180_chmole_maya(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x2E)
  {
    _capod_entrypoint_14();
    func_800FFAB0(param_0);
    } else {
        return 0;
    }
    return 1;
}

int chmole_maya_entrypoint_1()
{
  return &D_80800258_chmole_maya;
}
