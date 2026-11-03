#include "common.h"

extern u8 D_80800250_chdinoroargrill[];
extern int D_80800258_chdinoroargrill[];
extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);

void func_80800000_chdinoroargrill(u8 *param_0)
{
    *(f32 *)((char *)param_0 + 0x28) = 0.0f;
    func_8010A800(param_0, 0);
}

void func_80800028_chdinoroargrill(Actor *param_0)
{
    if (!D_80800250_chdinoroargrill[(s32)*(f32 *)&param_0->actorData[4]]) {
        if (!func_80102F44(param_0)) {
            func_80101FDC(param_0, 3);
            param_0->unk58 = 1.9f;
            _capod_entrypoint_13(param_0->unk0, param_0->unk0, 0x4C, 0x810);
            if (_chdoormake_entrypoint_3(param_0, 0.0f, 90.0f, param_0->scale * 170.0f, 0, -1)) {
                _chdoormake_entrypoint_8(param_0, 14);
            }
        }
        _chdoor_entrypoint_0(param_0);
    } else if (func_8010C710(param_0) >= 0xC5C11) {
        *(f32 *)&param_0->actorData[4] = 0.0f;
    }
}

s32 func_80800124_chdinoroargrill(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0xB:
            if (param_2 == 0x4C) {
                func_800DA544(0xA22);
                func_800FFAB0(param_0);
            }
            return 3;
        case 0x1D:
        case 0x1E:
            if (D_80800250_chdinoroargrill[(s32)*(f32 *)&param_0->actorData[4]]) {
                if (param_1 == D_80800250_chdinoroargrill[(s32)*(f32 *)&param_0->actorData[4]]) {
                    *(f32 *)&param_0->actorData[4] += 1.0f;
                    if (!D_80800250_chdinoroargrill[(s32)*(f32 *)&param_0->actorData[4]]) {
                        func_800FC63C(0x10, -1);
                        return 1;
                    }
                } else {
                    *(f32 *)&param_0->actorData[4] = 0.0f;
                }
            }
            return 1;
        case 0x95:
            param_0->unk79_2 = 0;
            return 1;
    }
    return 0;
}

int *chdinoroargrill_entrypoint_0()
{
    return &D_80800258_chdinoroargrill;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/dino/roargrill.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800258_chdinoroargrill -> int[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
u8 D_80800250_chdinoroargrill[8] = { 0x1D, 0x1D, 0x1E, 0x1D, 0x1E, 0x1E, 0x0, 0x0 };
int D_80800258_chdinoroargrill[18] = { 0xAC04A2, 0x7C40001, 0x0, (u32)func_80800028_chdinoroargrill, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0xA220000, 0x40000800, 0x0, 0x0, 0x0, (u32)func_80800000_chdinoroargrill, (u32)func_80107C2C, -0x7FFFDBEE, (u32)func_80800124_chdinoroargrill, 0x0 };
