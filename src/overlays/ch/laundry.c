#include "common.h"

extern int D_80800400_chlaundry;
extern f32 func_800C5190(s32);
extern s32 func_800A940C(s32);
extern u8 D_80800488_chlaundry[];
extern void *func_80100094(Actor *, u32);
extern f32 func_800D8FF8(void);
extern f32 func_800F13C4(f32, f32);
extern s32 func_800BABB8(s32, f32 *, f32 *, f32, u8 *);
extern int func_800CD820(void *, f32 *, f32 *, f32);
typedef struct { u8 pad[0xA]; u8 f : 5; u8 r : 3; } LaundryBits;
typedef struct { u8 local_0; u8 local_1; u8 pad_0[2]; f32 local_2; } LaundryData;
extern u32 D_8080048C_chlaundry;
extern Actor *func_80108454(s32, f32 *, s32);
extern void func_800FAB50(void *, f32 *, f32 *, s32, f32);
extern u8 D_80800448_chlaundry[];
int func_808003A0_chlaundry(s32 volatile param_0);

int chlaundry_entrypoint_0()
{
  return (int)&D_80800400_chlaundry;
}

f32 func_8080000C_chlaundry(Actor *param_0) {
    f32 local_0 = func_800C5190(func_800A940C(*(u8 *)func_80100094(param_0, 0)));
    if (local_0 > 2.0f) {
        local_0 = 2.0f;
    }
    return local_0;
}

void func_80800058_chlaundry(Actor *param_0, f32 param_1)
{
    f32 local_1;
    u32 local_3;
    int local_2;
    s32 local_4;
    u8 *local_0;
    local_0 = func_80100094(param_0, 0);
    if (*(f32 *)(local_0 + 4) < 2.5f) func_800BABB8(func_800B5BE4(0x19), param_0->position, 0, 1.0f, D_80800488_chlaundry);
    local_1 = *(f32 *)(local_0 + 0x18) + func_800D8FF8() * 24.0f;
    local_2 = func_800EC3E8(param_0->unk0);
    local_1 = func_800F13C4(local_1, (f32)func_800AF5A0(local_2));
    *(f32 *)(local_0 + 0x18) = local_1;
    ((LaundryBits *)param_0->unk0->unk0)->f = (s32)local_1;
    *(s16 *)&param_0->unk0->unk20 = 0;
    func_8010A590(param_0);
    local_3 = func_800CD820(param_0->unk0, ((f32 *)(local_0 + 0xC)), (param_0->position), 40.0f);
    local_2 = local_3 != 0;
    if (local_3) _glhittableDll_entrypoint_1(param_0->unk0, local_3);
    func_8010A570(param_0);
    func_800EE7F8(((f32 *)(local_0 + 0xC)), (param_0->position));
    local_4 = func_8010B990(param_0, 0x100004);
    if (local_4 == 0x20) func_8010AA78((param_0->position));
    if (local_2 || local_4 == 0x20 || func_8080000C_chlaundry(param_0) * 4.0f < *(f32 *)(local_0 + 4)) local_0[1] = 1;
}

void func_80800218_chlaundry(Actor *param_0)
{
    f32 local_1;
    f32 local_2;
    LaundryData *local_0;
    local_0 = func_80100094(param_0, 0);
    local_1 = local_0->local_2;
    local_2 = func_800D8FF8();
    func_80800058_chlaundry(param_0, local_2);
    local_0->local_2 = local_1 + local_2;
    if (local_0->local_1) {
        func_808003A0_chlaundry(param_0);
        func_800FFAB0(param_0);
    }
}

s32 func_80800288_chlaundry(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
Actor *chlaundry_entrypoint_1(void *param_0, f32 *param_1, f32 *param_2, s32 param_3)
{
    Actor *local_3;
    f32 local_0[3];
    f32 local_1[3];
    u8 *local_2;

    func_800FAB50(param_0, param_1, local_0, 0x24200A1, 15.0f);
    func_800EE904(local_1, param_1);
    local_3 = func_80108454(0x162, local_1, 0);
    local_2 = func_80100094(local_3, 0);
    func_800EE7F8((f32 *)(local_2 + 0xC), local_3->position);
    local_2[0] = param_3;
    local_2[1] = 0;
    *(f32 *)(local_2 + 4) = 0.0f;
    local_3->scale = 0.5f;
    *(f32 *)&local_3->actorData[7] = -800.0f;
    *(f32 *)(local_2 + 8) = -22000.0f;
    func_800EE7F8((f32 *)&local_3->actorData[4], param_2);
    *(f32 *)(local_2 + 0x18) = 0.0f;
    func_800BABB8(func_800B5BE4(0x19), local_3->position, NULL, 1.0f, D_80800448_chlaundry);
    return local_3;
}

int func_808003A0_chlaundry(s32 volatile param_0)
{
  s32 local_0;
  local_0 = param_0 + 4;
  func_8010D930(0, -1, local_0, &D_8080048C_chlaundry);
  _fxsparkle_entrypoint_1(local_0, 0xD);
}
