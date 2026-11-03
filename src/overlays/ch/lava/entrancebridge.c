#include "common.h"

extern int D_80800230_chlavaentrancebridge[];
extern s32 D_80800220_chlavaentrancebridge[];
extern s32 D_80800228_chlavaentrancebridge[];
extern f32 func_800D8FF8(void);
extern void func_800EDCEC(s32, f32);
extern void func_800E15CC(s32, f32, f32);
extern void func_80018820(s32, f32, f32);

void func_80800000_chlavaentrancebridge(void *param_0) {
    *(float *)((char *)param_0 + 0x58) = -2750.0f;
}

s32 func_80800010_chlavaentrancebridge(Actor *param_0, s32 param_1, s32 param_2)
{
    switch (param_1) {
        case 0x95:
            if (func_800DA298(0x391)) func_80101FDC(param_0, 4);
            break;
        case 0x60:
            func_80101FDC(param_0, 2);
            break;
        default: return 0;
    }
    return 1;
}

void func_8080008C_chlavaentrancebridge(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    f32 local_2;

    local_0 = _idworld_entrypoint_3(0x190);
    local_1 = _idworld_entrypoint_3(0x191);
    local_2 = -2750.0f;
    switch (param_0->unk70_10) {
    case 2:
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_80800220_chlavaentrancebridge);
        *(f32 *)((u8 *)param_0 + 0x58) += 450.0f * func_800D8FF8();
        if (*(f32 *)((u8 *)param_0 + 0x58) >= 0.0f) {
            *(f32 *)((u8 *)param_0 + 0x58) = 0.0f;
            func_80101FDC(param_0, 4);
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_80800228_chlavaentrancebridge);
            func_800E15CC(0, 20.0f, 0.85f);
            func_80018820(0, 1.0f, 0.4f);
        }
        local_2 = *(f32 *)((u8 *)param_0 + 0x58);
        break;
    case 4: local_2 = 0.0f; break;
    }
    if (local_0) func_800EDCEC(local_0, local_2);
    if (local_1) func_800EDCEC(local_1, local_2 >= -1350.0f ? local_2 : -1350.0f);
}

int *chlavaentrancebridge_entrypoint_0()
{
    return &D_80800230_chlavaentrancebridge;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/lava/entrancebridge.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800220_chlavaentrancebridge -> s32[], D_80800228_chlavaentrancebridge -> s32[], D_80800230_chlavaentrancebridge -> int[] */
extern void func_80105834();
extern void func_8010A730();
extern void func_80107C2C();
s32 D_80800220_chlavaentrancebridge[2] = { 0x1304AD, 0x20000 };
s32 D_80800228_chlavaentrancebridge[2] = { 0x1304CC, 0x20000 };
int D_80800230_chlavaentrancebridge[20] = { 0x158038E, 0x1, 0x0, (u32)func_8080008C_chlavaentrancebridge, (u32)func_80105834, (u32)func_8010A730, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, (u32)func_80800000_chlavaentrancebridge, (u32)func_80107C2C, -0x7FFFDBFE, (u32)func_80800010_chlavaentrancebridge, 0x0, 0x0, 0x0 };
