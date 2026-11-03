#include "common.h"

extern s32 D_80800270_chcolldoors[];
extern f32 func_800D8FF8(void);
extern void *D_80800280_chcolldoors;

void func_80800000_chcolldoors(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk74_7) {
    case 0x33:
        local_0 = func_800DA298(0x577);
        break;
    case 0x34:
        local_0 = func_800DA298(0x368);
        break;
    case 0x35:
        local_0 = func_800DA298(0x369);
        break;
    }
    if (local_0) {
        param_0->unk70_10 = 3;
        param_0->position[1] += 250.0f;
    }
}

void func_808000B8_chcolldoors(Actor *param_0)
{
    s32 local_0;

    switch (param_0->unk70_10) {
    case 1:
        local_0 = 0;
        switch (param_0->unk74_7) {
        case 0x33:
            local_0 = func_800DA298(0x577);
            param_0->unk58 = 1.5f;
            _gcfrontend_entrypoint_9(0x6E);
            break;
        case 0x34:
            local_0 = func_800DA298(0x368);
            param_0->unk58 = 1.5f;
            _gcfrontend_entrypoint_9(0x6F);
            break;
        case 0x35:
            local_0 = func_800DA298(0x369);
            param_0->unk58 = 1.5f;
            _gcfrontend_entrypoint_9(0x70);
            break;
        }
        if (local_0) {
            param_0->unk70_10 = 2;
            *(f32 *)&param_0->actorData[1] = param_0->position[1] + 250.0f;
        }
        break;
    case 2:
        if (param_0->unk58 <= 0.0f) {
            _subaddieaudioloop_entrypoint_4(param_0, param_0->position, 1, &D_80800270_chcolldoors);
            if (param_0->position[1] < *(f32 *)&param_0->actorData[1]) {
                param_0->position[1] += 150.0f * func_800D8FF8();
            } else {
                param_0->unk70_10 = 3;
            }
        } else {
            param_0->unk58 -= func_800D8FF8();
        }
        break;
    }
}

int chcolldoors_entrypoint_0()
{
  return &D_80800280_chcolldoors;
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/colldoors.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * extern declarations adjusted to the object (same addresses): D_80800270_chcolldoors -> s32[] */
extern void func_80105834();
extern void func_80101870();
extern void func_80107C2C();
s32 D_80800270_chcolldoors[4] = { 0x1304AD, 0x1661A8, 0x100FA, 0xA8C0000 };
void *D_80800280_chcolldoors = (void *)0x00AC01A4;
static u32 D_80800280_chcolldoors_rest[19] = { 0x95A0001, 0x0, (u32)func_808000B8_chcolldoors, (u32)func_80105834, (u32)func_80101870, 0x13880000, 0x0, 0x0, 0x80C04, 0x0, 0x0, 0x0, (u32)func_80800000_chcolldoors, (u32)func_80107C2C, 0x80080002, 0x0, 0x0, 0x0, 0x0 };
