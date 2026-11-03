#include "common.h"

extern void *func_80100094(Actor *, u32);
extern void *func_80104130(void);
extern void func_800DBEFC(void *, s32, f32 *);
extern void func_8008FB10(s32, f32, f32, f32);
typedef struct { u8 pad[0x7C]; u32 pad7C:19; u32 flag:1; u32 rest:12; } TorchState;
extern u8 D_80800230_chstatictorch[];
extern void _subaddieaudioloop_entrypoint_4();
extern int D_80800248_chstatictorch[];
extern void _suflamefx_entrypoint_7(void *, f32 *, f32, f32, f32, s32, f32);
void func_80800140_chstatictorch();

void func_80800000_chstatictorch(Actor *param_0, s32 param_1)
{
    func_80101870(param_0);
    if (param_0->unk7C_12) {
        func_800DBEFC(func_80104130(), 5, (f32 *)param_0->actorData);
        ((f32 *)param_0->actorData)[1] += 10.0f;
        if (func_80100094(param_0, 1)) _suflamefx_entrypoint_3(func_80100094(param_0, 1), param_1);
    }
}

s32 func_80800090_chstatictorch(s32 param_0){
    func_8008FB10(param_0 + 4, 40.0f, 0.0f, 1.0f);
    _suflamefx_entrypoint_2(func_80100094(param_0, 1), param_0 + 0x18);
    func_80800140_chstatictorch(param_0);
}

void func_808000E4_chstatictorch(s32 arg0) 
{
}
void func_808000EC_chstatictorch(Actor *param_0)
{
    if (func_80100094(param_0, 1)) {
        _suflamefx_entrypoint_1(param_0, 1);
    }
    if (param_0->unk5F != 0) {
        func_800C2FDC(param_0->unk5F);
        param_0->unk5F = 0;
    }
}

void func_80800140_chstatictorch(param_0) TorchState *param_0; {
    _subaddieaudioloop_entrypoint_4(param_0, param_0->flag ? (u8 *)param_0 + 0x18 : (u8 *)param_0 + 4, 1, D_80800230_chstatictorch);
}

int func_80800180_chstatictorch(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
    case 0x95:
        _suflamefx_entrypoint_0(param_0, 1, 15, 0x9EB);
        _suflamefx_entrypoint_7(func_80100094(param_0, 1), param_0->position, 0.4f, 0.5f, 11.0f, 3, 0.95f);
        break;
    default:
        return 0;
    }
    return 1;
}

int *chstatictorch_entrypoint_0()
{
    return &D_80800248_chstatictorch;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/statictor.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800248_chstatictorch -> int[] */
extern void func_80105834();
extern void func_80107C2C();
u8 D_80800230_chstatictorch[24] = { 0x0, 0x13, 0x4, 0x83, 0x0, 0x16, 0x27, 0x10, 0x0, 0xE, 0x1, 0x33, 0x1, 0x70, 0x1, 0x80, 0x0, 0x1, 0x1, 0xF4, 0x5, 0xDC, 0x0, 0x0 };
int D_80800248_chstatictorch[18] = { 0x20E02AE, 0x6740001, 0x0, (u32)func_80800090_chstatictorch, (u32)func_80105834, (u32)func_80800000_chstatictorch, 0x0, 0x0, 0x0, 0x23, (u32)func_808000EC_chstatictorch, 0x0, 0x0, (u32)func_808000E4_chstatictorch, (u32)func_80107C2C, 0x0, (u32)func_80800180_chstatictorch, 0x0 };
