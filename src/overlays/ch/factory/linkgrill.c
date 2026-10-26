#include "ch/factory/linkgrill.h"

extern u8 D_80800244_chfactorylinkgrill[];
extern u8 D_80800200_chfactorylinkgrill[];
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern int D_80800250_chfactorylinkgrill;
extern int D_80800298_chfactorylinkgrill;
extern int D_808002E0_chfactorylinkgrill;

void func_80800000_chfactorylinkgrill(Actor *param_0)
{
    param_0->unk79_4 = _gccubesearch_entrypoint_10(1000, param_0->pad6C_21);
    if (func_800DA298(param_0->unk79_4 + 0x1C0)) {
        func_800FFAB0(param_0);
    }
}

s32 func_8080006C_chfactorylinkgrill(Actor *param_0, s32 param_1, s32 param_2)
{
    f32 *local_0;
    switch (param_1) {
        case 0x40:
            func_800DA544(param_0->unk79_4 + 0x1C0);
            local_0 = param_0->position;
            _chskeletonexplode_entrypoint_7(param_0, local_0);
            _subaddieaudioquick_entrypoint_2(param_0, local_0, D_80800244_chfactorylinkgrill);
            func_800BBCB8(local_0, local_0, 1.0f, 5, D_80800200_chfactorylinkgrill);
            return 1;
        case 0xF:
            func_800FFAB0(param_0);
            return 1;
    }
    return 0;
}

int chfactorylinkgrill_entrypoint_0()
{
  return &D_80800250_chfactorylinkgrill;
}

void func_80800124_chfactorylinkgrill(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D9_UNK);
    _chswitch_entrypoint_9(arg0);
}

int func_80800150_chfactorylinkgrill(Actor *param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 7)
  {
    func_80101180(0x3FA, 7, 0);
  }
  _chswitch_entrypoint_10(param_0, param_1, param_2);
}

int chfactorylinkgrill_entrypoint_1()
{
  return &D_80800298_chfactorylinkgrill;
}

s32 func_808001B0_chfactorylinkgrill(Actor *this) {
    _chdoormake_entrypoint_0(this, 0xC2B40000, 0, 0x1D9);
    _chdoormake_entrypoint_5(this, 0x3FC00000);
    _chdoormake_entrypoint_8(this, 2);
}

int *chfactorylinkgrill_entrypoint_2()
{
    return &D_808002E0_chfactorylinkgrill;
}
