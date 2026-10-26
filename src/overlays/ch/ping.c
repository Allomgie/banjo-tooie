#include "common.h"

extern void *D_80800410_chping;
extern void *func_80100094(Actor *, s32);
extern s32 func_801039E4(void *);
extern void func_800E3A58(f32 *);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern f32 func_800F0F9C(f32, f32);
extern f32 func_80013970(f32);
extern void func_800DF410(s32);
extern void func_800DF830(s32);
extern void func_800DE448(f32 *, f32 *, f32, s32, s32);
extern f32 func_800D8FF8(void);
extern void func_800C4B90(s32, f32, f32);
extern void func_80109CC4(f32 *, f32, void *);

void func_80800000_chping(Actor *this, s32 arg1)
{
    f32 *data;
    s32 sp;
    s32 i;
    f32 t;
    f32 pos[3];
    f32 a;
    f32 b;

    data = func_80100094(this, 0);
    sp = func_801039E4(*(void **)this);
    func_800E3A58(pos);
    for (i = 0; i < 3; i++) {
        t = data[1];
        t -= i * 0.4f;
        if (t < 0.0f) continue;
        if (3.0f < t) continue;
        a = func_800F10B4(t, 0.0f, 3.0f, 0.5f, 30.0f);
        b = func_800F10B4(data[1], 0.0f, 3.0f, 40.0f, 0.0f);
        t = func_80013970(func_800F0F9C(data[1], 0.5) * 360.0f);
        func_800DF410(10.0f + b + b * t);
        func_800DF830(2);
        func_800DE448(this->position, pos, a, 0, sp);
    }
}

void func_808001B8_chping(Actor *param_0)
{
    f32 local_1;
    f32 local_2;
    f32 local_3;
    f32 local_4;
    f32 local_6;
    f32 local_5;
    f32 local_0[3];
    s32 local_8;
    u8 *local_7;

    local_7 = func_80100094(param_0, 0);
    local_8 = *(s32 *)local_7;
    func_800F5A00(local_8, local_0);
    local_0[1] += 60.0f;
    func_800EE7F8(param_0->position, local_0);
    local_5 = *(f32 *)(local_7 + 4);
    local_1 = func_800F0F9C(local_5, 0.5f);
    local_2 = func_80013970(local_1 * 360.0f);
    local_3 = func_80013970(local_1 * 360.0f + 180.0f);
    local_4 = func_800F10B4(local_5, 0.0f, 3.0f, 3.0f, 0.01f);
    func_800C4B90(func_800A940C(local_8), local_2 * local_4, local_3 * local_4);
    if (local_5 < 3.0f) {
        local_6 = func_800F10B4(local_5, 0.0f, 3.0f, 14.0f, 840.0f);
        func_8010A590(param_0);
        func_800CB840(5, param_0);
        func_80109CC4(param_0->position, local_6, param_0->unk0);
        func_800CB870();
        func_8010A570(param_0);
    }
    *(f32 *)(local_7 + 4) += func_800D8FF8();
    if (*(f32 *)(local_7 + 4) > 4.2f) func_800FFA88(param_0->unk0);
}

int chping_entrypoint_0(s32 param_0)
{
    s32 *local_0;
    s32 local_1[3];
    s32 *local_2;
    u8 *local_3;

    func_800F5A00(param_0, &local_1);
    local_2 = func_80108474(0x169, &local_1, 0);
    local_0 = local_2;
    local_3 = func_80100094(local_2, 0);
    *(f32 *)((char *)local_3 + 4) = 0.0f;
    *(s32 *)((char *)local_3 + 0) = param_0;
    func_8010A570(local_0);
    return *local_0;
}

int chping_entrypoint_1()
{
  return (int)&D_80800410_chping;
}
