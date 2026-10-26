#include "common.h"

extern void *D_808003A0_chiciclebits;
typedef struct { s16 local_0[3]; u16 local_1; u16 pad_0; } IciclePlacement;
extern IciclePlacement D_808003E8_chiciclebits[];
extern void func_800EE88C();
extern void func_800EF334(f32 *, f32);
extern u8 D_808003EE_chiciclebits[];
extern s32 D_80800430_chiciclebits;
extern s32 D_80800468_chiciclebits;
extern s32 D_808004A8_chiciclebits;
extern f32 func_800D8FF8(void);
extern void func_800BBCB8(f32 *, f32 *, f32, s32, void *);
extern void func_80018820(s32, f32, f32);
extern u16 D_808003F0_chiciclebits[][5];
extern u8 D_808004B8_chiciclebits[];
extern u8 D_808004C8_chiciclebits[];

int chiciclebits_entrypoint_0()
{
  return (int)&D_808003A0_chiciclebits;
}

void func_8080000C_chiciclebits(Actor *param_0)
{
    s32 local_0;

    local_0 = param_0->unk74_7 - 0x32;
    func_800EE88C(param_0->position, (&D_808003E8_chiciclebits[local_0])->local_0);
    func_800EF334(param_0->position, 100.0f);
    param_0->actorData[4] = local_0;
    *(f32 *)&param_0->actorData[5] = param_0->position[1];
    *(f32 *)&param_0->actorData[7] = 600.0f;
    param_0->position[1] += 2500.0f;
    if (func_800DA298((&D_808003E8_chiciclebits[local_0])->local_1)) {
        param_0->position[1] = *(f32 *)&param_0->actorData[5];
        func_8010A570(param_0);
        func_80101FDC(param_0, 4);
    }
}

void func_808000D0_chiciclebits(Actor *param_0)
{
    f32 local_0;

    switch (param_0->unk70_10) {
    case 1: break;
    case 2:
        _subaddieDll_entrypoint_7(param_0, 8);
        if (func_800D9078(&param_0->unk58)) {
            func_800BBCB8(param_0->position, param_0->position, 1.0f, 6, &D_80800430_chiciclebits);
            func_800BBCB8(param_0->position, param_0->position, 1.0f, 8, &D_80800468_chiciclebits);
            func_80101FDC(param_0, 3);
        }
        break;
    case 3:
        local_0 = func_800D8FF8();
        param_0->position[1] -= *(f32 *)((u8 *)param_0 + 0x34) * local_0;
        *(f32 *)((u8 *)param_0 + 0x34) += 2500.0f * local_0;
        if (param_0->position[1] < *(f32 *)((u8 *)param_0 + 0x2C)) {
            param_0->position[1] = *(f32 *)((u8 *)param_0 + 0x2C);
            *(f32 *)((u8 *)param_0 + 0x34) = 600.0f;
            _subaddieaudioquick_entrypoint_2(param_0, param_0->position, &D_808004A8_chiciclebits);
            func_80101FDC(param_0, 4);
            func_80103110(param_0, 0);
            func_800DA544(*(u16 *)(D_808003EE_chiciclebits + *(s32 *)((u8 *)param_0 + 0x28) * 10));
            func_80018820(0, 5.0f, 0.4f);
        }
        break;
    }
}

s32 func_80800240_chiciclebits(Actor *param_0, s32 param_1, s32 param_2)
{
    s32 local_0;
    switch (param_1) {
    case 0x40:
        local_0 = !func_80101180(0x41C, 0x43, 0);
        _subaddieaudioquick_entrypoint_2(param_0, NULL, D_808004B8_chiciclebits);
        _subaddieaudioquick_entrypoint_2(param_0, NULL, D_808004C8_chiciclebits);
        func_8010A570(param_0);
        func_80101FDC(param_0, 2);
        func_80103110(param_0, 1);
        func_80018820(0, 3.0f, 0.5f);
        *(f32 *)((u8 *)param_0 + 0x58) = 1.4f;
        if (local_0) _capod_entrypoint_13(param_0->unk0, 0, 0, 0x11);
        break;
    case 0x43:
        if (param_0->unk70_10 == 1) return 0;
        break;
    case 0x95:
        func_80103140(param_0, D_808003F0_chiciclebits[*(s32 *)((u8 *)param_0 + 0x28)][0],
            *(u16 *)((u8 *)param_0->unk0 + 0x16));
        break;
    default:
        return 0;
    }
    return 1;
}
