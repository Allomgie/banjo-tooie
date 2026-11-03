#include "common.h"

extern s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
extern void _chdoormake_entrypoint_6(Actor *, f32);
extern void _chdoormake_entrypoint_5(Actor *, f32);
typedef union { s32 word; void *pointer; } HagsTrainDoorEvent;
extern int D_80800150_chhagstraindoor[];

void func_80800000_chhagstraindoor(Actor *param_0)
{
    f32 local_0;

    local_0 = 0.0f;
    func_800EFD24(param_0->position);
    func_80103014(param_0);
    if (param_0->unk74_7 == 0x32) local_0 = 180.0f;
    if (_chdoormake_entrypoint_3(param_0, local_0, 0.0f, 600.0f, 0x21, 0x403)) {
        _chdoormake_entrypoint_6(param_0, 4.4f);
        _chdoormake_entrypoint_5(param_0, 3.0f);
        if (param_0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(param_0, 13);
            _chdoormake_entrypoint_9(param_0, 0, 1, 0x10);
        }
    }
}

s32 func_808000D4_chhagstraindoor(Actor *param_0, s32 param_1, HagsTrainDoorEvent param_2)
{
    if (param_1 == 0x95) {
        func_80103140(param_0, (u16)(param_0->unk74_7 == 0x32 ? 0x94F : 0x950), 0);
    }
    return _chdoor_entrypoint_1(param_0, param_1, param_2.word);
}

int chhagstraindoor_entrypoint_0()
{
    return (int)&D_80800150_chhagstraindoor;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/hagstraindoor.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800150_chhagstraindoor -> int[] */
extern void _chdoor_entrypoint_0();
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
int D_80800150_chhagstraindoor[20] = { 0x371038C, -0xFFFF, 0x0, (u32)_chdoor_entrypoint_0, (u32)func_80105834, (u32)func_80101870, 0x0, 0x0, 0x0, 0xC00, 0x0, 0x0, 0x0, (u32)func_80800000_chhagstraindoor, (u32)func_80107C2C, -0x7FFFD3FE, (u32)func_808000D4_chhagstraindoor, 0x0, 0x0, 0x0 };
