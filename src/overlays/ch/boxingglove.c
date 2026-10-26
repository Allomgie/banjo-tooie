#include "common.h"

extern int D_80800708_chboxingglove;
extern void *D_80800750_chboxingglove;
extern void *_subaddiefind_entrypoint_2(int, s32 *);
extern u8 D_80800798_chboxingglove[];
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern Actor *func_80106790(Unk80132ED0 *);
extern f32 func_800DC178(f32, f32);
extern void func_8010D09C(void *, f32 *, f32);
extern u8 D_808007A0_chboxingglove[];
typedef struct { f32 local_0[3]; f32 local_1; } BoxingSphere1559;
extern void *func_80100094(Actor *, u32);
extern int func_800F0064(f32 *, f32, f32 *);
extern void func_800EE7F8(f32 *, f32 *);
extern int func_800BEF00(f32 *, f32 *, f32 *, u32);
typedef struct { f32 position[3]; f32 radius; } BoxingTarget;
void func_808002E0_chboxingglove();
int func_808004F8_chboxingglove();
int func_80800544_chboxingglove();
void func_80800630_chboxingglove();

int chboxingglove_entrypoint_0(void)
{
    return (int)&D_80800708_chboxingglove;
}

int chboxingglove_entrypoint_1()
{
  return &D_80800750_chboxingglove;
}

void func_80800018_chboxingglove(Actor *param_0)
{
    f32 local_0[3];

    switch (param_0->unk70_10) {
    case 1:
        if (!func_808004F8_chboxingglove(param_0)) {
            if ((func_8008FF18() || !func_8010D248()) && param_0->unk64_20) return;
            if (func_800D90A4(&param_0->unk58)) {
                func_8010D254(local_0);
                if (local_0[1] < *(f32 *)((u8 *)param_0 + 0x28) + 500.0f
                    || !param_0->unk64_20) {
                    func_808002E0_chboxingglove(param_0, 2);
                }
            }
        }
        break;
    case 2:
        if (func_800D90A4(&param_0->unk58)) func_808002E0_chboxingglove(param_0, 3);
        break;
    case 3:
        if (func_80101DDC(param_0)) func_808002E0_chboxingglove(param_0, 4);
        break;
    case 4:
        if (func_800D90A4(&param_0->unk58)) func_808002E0_chboxingglove(param_0, 1);
        break;
    }
}

void func_80800168_chboxingglove(void *param_0)
{
    void *local_1;
    s32 local_0;
    *(f32 *)((u8 *)param_0 + 88) = 1.0f;
    *(f32 *)((u8 *)param_0 + 0x28) = *(f32 *)((u8 *)param_0 + 0x8);
    *((u8 *)param_0 + 101) &= ~1;
    local_1 = _subaddiefind_entrypoint_2(0x36E, &local_0);
    *(u32 *)((u8 *)param_0 + 0x3C) = *(u32 *)((u8 *)local_1 + 0);
    *(u32 *)((u8 *)local_1 + 60) = *(u32 *)((u8 *)param_0 + 0);
    func_80800630_chboxingglove(param_0);
}

void func_808001CC_chboxingglove(Actor *param_0)
{
    s32 local_0;

    local_0 = 0;
    switch (param_0->unk70_10) {
    case 2:
        func_800D90A4(&param_0->unk58);
        param_0->position[1] = ((f32 *)param_0->actorData)[4] - func_800F10B4(param_0->unk58, 0.0f, 1.5f, 0.0f, 70.0f);
        local_0 = 1;
        break;
    case 4:
        func_800D90A4(&param_0->unk58);
        param_0->position[1] = ((f32 *)param_0->actorData)[4] - func_800F10B4(param_0->unk58, 0.0f, 1.5f, 70.0f, 0.0f);
        local_0 = 1;
        break;
    }
    if (local_0 || (!local_0 && ((u8 *)param_0)[0x5F])) {
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, local_0, D_80800798_chboxingglove);
    }
}

int func_808002AC_chboxingglove(f32 param_0[3])
{
  f32 local_0;
  int new_var3;
  int new_var;
  u8 *local_1;
  f32 new_var2;
  f32 new_var4;
  new_var4 = param_0[2];
  new_var3 = 101;
  local_1 = &(*((u8 *) (((char *) param_0) + new_var3)));
  local_0 = new_var4 - 70.0f;
  new_var2 = new_var4;
  param_0[2] = local_0;
  new_var = ~1;
  *local_1 &= new_var;
  param_0[10] = new_var4;
  param_0[22] = 1.0f;
}

void func_808002E0_chboxingglove(param_0, param_1) Actor *param_0; s32 param_1;
{
    Actor *local_3;
    f32 local_0[3];
    f32 local_1[3];

    local_3 = func_80106790(param_0->unk3C);
    switch (param_1) {
    case 1:
        param_0->unk58 = func_800DC178(2.0f, 3.0f);
        func_80102424(param_0, 1);
        func_80101FDC(local_3, param_1);
        local_3->unk64_16 = 0;
        return;
    case 2:
        if (param_0->unk64_20) {
            func_8010D09C(func_800F54E4(), local_0, 1.5f);
            if (!func_80800544_chboxingglove(param_0, local_0)) {
                func_8010D254(local_0);
                if (!func_80800544_chboxingglove(param_0, local_0)) {
                    return;
                }
            }
            param_0->position[0] = local_3->position[0] = local_0[0];
            param_0->position[2] = local_3->position[2] = local_0[2];
        } else {
            param_0->unk64_20 = 1;
        }
        param_0->unk58 = 1.5f;
        local_3->unk58 = 1.5f;
        func_80102424(param_0, param_1);
        func_80101FDC(local_3, param_1);
        local_3->unk64_16 = 1;
        return;
    case 3:
        _subaddieaudioquick_entrypoint_2(param_0, param_0->position, D_808007A0_chboxingglove);
        func_80102424(param_0, param_1);
        func_80101FDC(local_3, param_1);
        func_8010A590(param_0);
        param_0->unk64_16 = 1;
        func_8010D254(local_1);
        func_800F1E6C(local_1, param_0->position, &param_0->rotation[1]);
        return;
    case 4:
        local_3->unk58 = param_0->unk58 = 1.5f;
        func_80102424(param_0, param_1);
        func_80101FDC(local_3, param_1);
        func_8010A570(param_0);
        param_0->unk64_16 = 0;
        func_808004F8_chboxingglove(param_0);
        break;
    }
}

int func_808004F8_chboxingglove(param_0) Actor *param_0;
{
  s32 local_0;
  if (func_800DA298(0))
  {
    func_800FFAB0(param_0);
    func_800FFA88(param_0->unk3C);
    return 1;
  }
  local_0 = 0;
  return local_0;
}

int func_80800544_chboxingglove(param_0, param_1) Actor *param_0; f32 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    s32 local_3;
    BoxingSphere1559 *local_4;
    f32 *local_5;
    f32 *local_6;
    f32 *local_7;
    void *local_8;

    local_8 = func_80100094(param_0, 0);
    local_3 = 0;
    local_4 = local_8;
    for (; local_3 != 64; local_3 += 16, local_4++) {
        if (func_800F0064(param_1, local_4->local_1, local_4->local_0)) return 0;
    }
    local_5 = local_0;
    func_800EE7F8(local_5, param_1);
    local_6 = local_1;
    func_800EE7F8(local_6, param_1);
    local_5[1] = ((f32 *)param_0->actorData)[4] + 200.0f;
    local_6[1] = ((f32 *)param_0->actorData)[4] - 50.0f;
    local_7 = local_2;
    return func_800BEF00(local_5, local_6, local_7, param_0->unk14) ? 1 : 0;
}

void func_80800630_chboxingglove(param_0) Actor *param_0;
{
    Actor *local_0[4];
    s32 local_2;
    s32 local_3;
    BoxingTarget *local_1;
    local_1 = func_80100094(param_0, 0);
    local_2 = _subaddiefind_entrypoint_4(0x34D, local_0, 4);
    for (local_3 = 0; local_3 < local_2; local_3++) {
        func_800EE7F8(local_1[local_3].position, local_0[local_3]->position);
        local_1[local_3].radius = local_0[local_3]->scale * 150.0f;
    }
}
