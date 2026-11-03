#include "common.h"

extern int D_808001F8_chfireimp[];
extern void func_8010A3E8(void *param_0, float param_1);
extern void *_sucoasterfly_entrypoint_1(void *param_0, int param_1);
extern void *_sucoasterfly_entrypoint_5(void *param_0);
extern f32 func_800DC178(f32, f32);
extern s32 func_800EFFB4(f32 *, f32, f32 *);
extern s16 D_80800240_chfireimp[];

int chfireimp_entrypoint_0()
{
    return (int)&D_808001F8_chfireimp;
}

void func_8080000C_chfireimp(Actor *param_0)
{
    void *local_0;
    local_0 = _sucoasterfly_entrypoint_1(param_0, 4);
    if (local_0 != 0)
    {
        local_0 = _sucoasterfly_entrypoint_5(param_0);
        *(float *)local_0 = 3.4f;
    }
    func_8010A3E8(param_0, 0.65f);
}

void func_8080005C_chfireimp(Actor *param_0)
{
    f32 *local_0;
    s32 local_1;
    f32 local_2[3];

    local_0 = _sucoasterfly_entrypoint_5(param_0);
    local_1 = 1;
    _sucoasterfly_entrypoint_3(param_0);
    switch (param_0->unk70_10) {
        case 10: case 11: case 12: case 13: case 14: case 15: case 16:
            local_1 = 0;
            break;
    }
    if (local_1 && func_800D90A4(local_0)) {
        func_8010D640(local_2);
        if (func_800EFFB4(param_0->position, 1800.0f, local_2)) {
            *local_0 = func_800DC178(2.4f, 3.4f);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800240_chfireimp);
        }
    }
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/fire/imp.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_808001F8_chfireimp -> int[] */
extern void func_80105834();
extern void _sucoasterfly_entrypoint_6();
extern void _sucoasterfly_entrypoint_2();
extern void _sucoasterfly_entrypoint_0();
extern void func_80107C2C();
extern void _sucoasterfly_entrypoint_4();
u32 D_80800170_chfireimp[34] = { 0x0, 0x0, 0x40000000, 0x15A0001, 0x40800000, 0x1890001, 0x40800000, 0x1890001, 0x40800000, 0x1890001, 0x0, 0x0, 0x40C00000, 0x1000001, 0x40C00000, 0x1000001, 0x40000000, 0x15A0001, 0x40000000, 0x15A0001, 0x3F000000, 0x1650002, 0x3E4CCCCD, 0x3CD0001, 0x40000000, 0xF70002, 0x40000000, 0xF70084, 0x0, 0x0, 0x40800000, 0x1890001, 0x40800000, 0x1890001 };
int D_808001F8_chfireimp[18] = { 0x2AD0462, 0x6B80001, (u32)&D_80800170_chfireimp, (u32)func_8080005C_chfireimp, (u32)func_80105834, (u32)_sucoasterfly_entrypoint_6, 0x9C40000, 0x3F800000, 0x0, 0x3271329, (u32)_sucoasterfly_entrypoint_2, (u32)_sucoasterfly_entrypoint_0, 0x0, (u32)func_8080000C_chfireimp, (u32)func_80107C2C, -0x7FCDBFA3, (u32)_sucoasterfly_entrypoint_4, -0x7FEDBA9C };
s16 D_80800240_chfireimp[16] = { 0x13, 0x63C, 0xD, 0xF3, 0x10C, 0x1, 0x190, 0x708, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
