#include "common.h"

extern int D_80800500_chdiggergroundgen;
extern void *func_80100094(Actor *, u32);
typedef union { s32 local_0; void *local_1; } DiggerGeneratorEvent;
extern f32 func_8010CD28(Actor *);
extern f32 func_800DC0C0(void);
extern f32 func_800F2094(f32, f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EF1B8(f32 *, f32, f32);
extern Actor *func_801084B0(s32, Actor **);
extern void func_80102FDC(Actor *, f32);
extern f32 func_800F1DF4(f32 *, f32 *);
extern u8 D_80800548_chdiggergroundgen[];
extern u8 D_80800554_chdiggergroundgen[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_8001395C(f32);
extern void func_800EFE50(f32 *, f32 *, void *, f32);
extern void func_8008FB10(f32 *, f32, f32, f32);
extern void func_800B4470(f32 *, s32, void *, s32, f32, f32, s32, s32, s32);
extern void func_800C4104(s32, f32, s32, f32 *, f32, f32);
void func_80800118_chdiggergroundgen();
void func_808002C4_chdiggergroundgen();
int func_8080035C_chdiggergroundgen();

int *chdiggergroundgen_entrypoint_0()
{
    return &D_80800500_chdiggergroundgen;
}

int func_8080000C_chdiggergroundgen(s32 param_0)
{
  s32 local_0 = func_80100094(param_0, 0);
  _subaddielink_entrypoint_0(local_0);
}

void func_80800034_chdiggergroundgen(Actor *param_0)
{
    void *local_0;
    local_0 = func_80100094(param_0, 0);
    switch (param_0->unk70_10) {
    case 1:
        if (!_subaddielink_entrypoint_4(local_0)) {
            func_80800118_chdiggergroundgen(param_0);
        }
        break;
    case 2:
        func_8080035C_chdiggergroundgen(param_0);
        break;
    }
}

s32 func_808000AC_chdiggergroundgen(Actor *param_0, s32 param_1, DiggerGeneratorEvent param_2)
{
    switch (param_1) {
    case 0x3D:
        func_808002C4_chdiggergroundgen(param_0);
        break;
    case 0x95:
        _subaddielink_entrypoint_3(func_80100094(param_0, 0));
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800118_chdiggergroundgen(param_0) Actor *param_0;
{
    f32 local_0[3];
    f32 local_5;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_6;
    f32 local_7;
    u8 *local_4;
    local_4 = func_80100094(param_0, 0);
    local_5 = func_8010CD28(param_0);
    for (;;) {
        local_6 = func_800DC0C0() * 360.0f;
        if (func_800F2094(local_6, local_5) < 30.0f) continue;
        local_7 = func_800DC178(300.0f, 500.0f);
        func_800EE7F8(local_0, param_0->position);
        func_800EF1B8(local_0, local_6, local_7);
        if (func_800CC338(local_0, (*(u32 *)((u8 *)param_0 + 0x70) >> 25) - 1, 0) != -1) break;
    }
    func_800EE7F8(local_1, local_0);
    func_800EE7F8(local_2, local_0);
    local_1[1] += 200.0f;
    local_2[1] -= 200.0f;
    func_800BEF00(local_1, local_2, local_3, param_0->unk14);
    local_0[1] = local_2[1];
    func_800EE7F8(local_4 + 8, local_0);
    func_80108B04(param_0, 0);
    func_80101FDC(param_0, 2);
    param_0->unk58 = 0.85f;
}

void func_808002C4_chdiggergroundgen(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;
    local_0 = func_80100094(param_0, 0);
    local_1 = func_801084B0(0x131, &param_0);
    func_80102FDC(local_1, func_800DC178(0.8f, 1.2f));
    local_1->rotation[1] = func_800F1DF4(param_0->position, (f32 *)(local_0 + 8));
    _subaddielink_entrypoint_1(local_0, local_1->unk0);
    _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_80800548_chdiggergroundgen);
}

int func_8080035C_chdiggergroundgen(param_0) Actor *param_0;
{
    u8 *local_0;
    Actor *local_1;
    s32 local_2;
    f32 local_3;
    f32 *local_4;
    local_0 = func_80100094(param_0, 0);
    local_1 = (Actor *)_subaddielink_entrypoint_4(local_0);
    local_2 = func_800D9078((u8 *)param_0 + 0x58);
    local_3 = func_800F10B4(*(f32 *)((u8 *)param_0 + 0x58), 0.0f, 0.85f, 1.0f, 0.0f);
    local_4 = local_1->position;
    func_800EFE50(local_4, param_0->position, local_0 + 8, local_3);
    local_1->position[1] += func_8001395C(local_3 * 3.141592741f) * 250.0f;
    func_8008FB10(local_4, 90.0f, param_0->position[1] - local_1->position[1], local_1->scale * 100.0f);
    if (local_2) {
        func_800B4470(local_4, 0, D_80800554_chdiggergroundgen, 1, 0.8f, 0.0f, 100, 150, 0);
        func_800C4104(0x419, 1.0f, 28000, local_4, 1250.0f, 2500.0f);
        local_1->unk64_20 = 1;
        func_80101FDC(param_0, 1);
    }
}
