#include "common.h"

extern int D_80800290_charea51gate;
extern void func_800EC398(void *, f32 *);
extern int D_808002D8_charea51gate;
typedef struct { u8 pad[0x7C]; u32 pad7C:19; u32 flag:1; u32 rest:12; } GateState;
extern void _chelectricfence_entrypoint_2();
extern int func_800DC298(f32);
void func_80800228_charea51gate();

int *charea51gate_entrypoint_0()
{
    return &D_80800290_charea51gate;
}

int func_8080000C_charea51gate(f32 param_0[3])
{
  f32 local_0[3];
  f32 *local_1;
 local_1 = &param_0[0]; func_80104004(param_0, &param_0[6], &param_0[10]); do { param_0[12] = param_0[8] + 40.0f; func_8010A800(local_1, 2); } while (0);
}

void func_80800054_charea51gate(GateState *param_0) {
    if (param_0->flag && func_800DC298(0.15f)) {
        _chelectricfence_entrypoint_2(param_0, (u8 *)param_0 + 0x18, (u8 *)param_0 + 0x28);
    }
}

s32 func_808000A0_charea51gate(Actor *param_0, s32 param_1, void *param_2)
{
    u8 *local_1;
    f32 local_0[3];
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    switch (param_1) {
    case 0x3E:
        local_2 = 1;
        local_1 = (*(void * *)&param_2);
        func_800EC398(local_1, local_0);
        if ((*(u32 *)(local_1 + 0x24) >> 22) == 0) {
            if (!func_800F64A4((u32)*(u16 *)(local_1 + 0x1A) >> 5, 0x8000))
                func_800F79DC((u32)*(u16 *)(local_1 + 0x1A) >> 5, 5, param_0->unk0, local_1);
            else local_2 = func_8001210C(3) == 0;
        }
        if (local_2) _chelectricfence_entrypoint_1(param_0, local_0);
        return 1;
    case 0x40: _chexploder_entrypoint_4(param_0, (u8 *)*(void **)(*(void * *)&param_2) + 4, 2); break;
    case 0x90: func_80800228_charea51gate(param_0); break;
    case 0x95:
        local_3 = func_800F6438(func_800F54E4()) != 0;
        if (local_3) local_3 = func_800F64A4(func_800F54E4(), 0x8000) == 0;
        if (local_3) func_80109EF4(param_0, 1);
        else func_80109F08(param_0, 1);
        break;
    default: return 0;
    }
    return 1;
}

void func_80800228_charea51gate(param_0) s32 param_0;
{
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    _subaddieaudioquick_entrypoint_2(param_0, param_0 + 4, &D_808002D8_charea51gate);
    func_800FFAB0(param_0);
    func_800DA544(0xA7);
}
