#include "common.h"

extern int D_80800354_chmermaidstatue;
extern void *D_8080039C_chmermaidstatue;
extern s16 D_80800330_chmermaidstatue[][6];
extern int _chdoormake_entrypoint_3(s32, f32, s32, s32, s32, s32);
int func_80800150_chmermaidstatue();
void func_808001B0_chmermaidstatue();

int chmermaidstatue_entrypoint_0()
{
  return (int)&D_80800354_chmermaidstatue;
}

int chmermaidstatue_entrypoint_1()
{
  return &D_8080039C_chmermaidstatue;
}

s32 func_80800018_chmermaidstatue(s32 param_0)
{
    s32 local_0;

    local_0 = _subaddiesect_entrypoint_1();
    *(s32 **)(param_0 + 0x30) = local_0;
    _subaddiesect_entrypoint_2(param_0, local_0, 0);
    func_800DA7A8(0x6B1, 0, 3);
    func_80109EEC(param_0, 0x40);
    if (func_800DA298(0x18D) != 0) {
        func_8010A570(param_0);
        func_80101FDC(param_0, 2);
    }
}

void func_80800094_chmermaidstatue(s32 arg0) 
{
}
void func_8080009C_chmermaidstatue(u8 *param_0, s32 param_1) {
    func_800DF744(3, ((u32)((u16) (*(u16 *)((s8 *)(param_0) + (0x76)))) >> 7) - 0x31);
    func_80101870(param_0, param_1);
}

s32 func_808000E0_chmermaidstatue(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x40:
        func_808001B0_chmermaidstatue(param_0);
        break;
    case 0x95:
        func_800BF744(1, func_80800150_chmermaidstatue() + 1);
        break;
    default:
        return 0;
    }
    return 1;
}

int func_80800150_chmermaidstatue()
{
  s32 local_0;
  if (!func_800DA298(0x6AE))
  {
    local_0 = func_800DC128(0, 3);
    func_800DA7A8(0x6AF, local_0, 2);
    func_800DA544(0x6AE);
    return local_0;
  }
  else
  {
    return func_800DA564(0x6AF, 2);
  }
}

void func_808001B0_chmermaidstatue(param_0) Actor *param_0;
{
    s32 local_0;
    s32 local_2;
    s32 local_1;
    local_0 = param_0->unk74_7 - 50;
    local_1 = func_800DA564(0x6B1, 3);
    if (local_1 != 6) {
        local_2 = func_80800150_chmermaidstatue();
        if (local_0 == D_80800330_chmermaidstatue[local_2][local_1]) {
            local_1++;
            func_800DA7A8(0x6B1, local_1, 3);
            if (local_1 == 6) {
                if (!func_800DA298(0x18D)) {
                    func_800FC660(0x10);
                    _capod_entrypoint_13(param_0->unk0, 0, 0x1E, 0x10);
                    func_80101180(0x3C1, 7, 0);
                    func_800DA544(0x18D);
                }
            } else {
                func_800FC660(0xE);
            }
        } else {
            func_800DA7A8(0x6B1, 0, 3);
            func_800FC660(0xF);
        }
    }
}

void func_808002C8_chmermaidstatue(s32 param_0)
{
    if (_chdoormake_entrypoint_3(param_0, 0, 0x42B40000, 0x43C80000, 1, 0x18D) != 0)
    {
        _chdoormake_entrypoint_8(param_0, 0xD);
        _chdoormake_entrypoint_5(param_0, 0x40000000);
        _chdoormake_entrypoint_6(param_0, 0x40400000);
    }
}
