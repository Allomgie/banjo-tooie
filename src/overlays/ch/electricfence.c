#include "common.h"

extern int D_808004C0_chelectricfence;
extern void func_800BBCB8(s32, s32, float, s32, void *);
extern void _subaddieaudioquick_entrypoint_2(s32, s32, void *);
extern s32 func_800C8A98(void);
extern void func_800C8CB8(s32, s32);
extern void func_800C8E84(s32, void *);
extern void func_800C8E54(s32, s32, s32);
extern void _chlightfader_entrypoint_1(s32, s32, int);
extern void *D_80800558_chelectricfence;
extern void *D_8080051C_chelectricfence;
extern void *D_8080058C_chelectricfence;
extern void *D_80800598_chelectricfence;
extern u8 D_808005A4_chelectricfence[];
extern s32 func_800DC298(f32);
extern f32 func_800DC178(f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800EF934(f32 *, f32 *, f32);
extern void func_800EF368(f32 *, f32);
extern f32 func_800EEAD4(f32 *, f32 *);
extern void func_800BABB8(s32, void *, s32, f32, void *);
extern void func_800BA8F8(s32, f32, f32);
extern u8 D_80800508_chelectricfence[];
extern f32 func_800EC75C(void *, f32 *);

int *chelectricfence_entrypoint_0()
{
    return &D_808004C0_chelectricfence;
}

int func_8080000C_chelectricfence(s32 param_0)
{
  if (func_800EA05C() == 0x124) {
    func_8010A624(param_0);
    func_8010A570(param_0);
  }
  func_80104004(param_0, param_0 + 0x18, param_0 + 0x28);
}

void chelectricfence_entrypoint_2();

void func_80800060_chelectricfence(Actor *param_0)
{
    if (func_800D9078(&param_0->unk58)) func_8010A590(param_0);
    _subaddieaudioloop_entrypoint_5(param_0, param_0->position, param_0->unk70_10 == 1, -1, D_80800508_chelectricfence);
    if (param_0->unk70_10 == 1 && param_0->unk7C_12 && func_800DC298(0.2f)) {
        chelectricfence_entrypoint_2(param_0, (f32 *)&param_0->actorData[0], (f32 *)&param_0->actorData[4]);
    }
}

void chelectricfence_entrypoint_1();

s32 func_8080010C_chelectricfence(Actor *param_0, s32 param_1, u32 *param_2)
{
    f32 local_0[3];
    u32 *local_1;

    switch (param_1) {
        case 0x3F:
            local_1 = *(u32 **)&param_2;
            func_800EC75C(local_1, local_0);
            chelectricfence_entrypoint_1((s32)param_0, (s32)local_0);
            param_0->unk58 = 0.2f;
            func_8010A570(param_0);
            if (local_1[0x24 / 4] >> 22 == 0) {
            }
            break;
        case 0x95:
            func_8010A5B0(param_0, func_800F6438(func_800F54E4()) &&
                            !func_800F64A4(func_800F54E4(), 0x8000));
            break;
        default: return 0;
    }
    return 1;
}

void chelectricfence_entrypoint_1(s32 param_0, s32 param_1) {
    s32 sp2C;
    s32 temp_v0;

    func_800BBCB8(param_1, param_1, 1.0f, 3, &D_80800558_chelectricfence);
    func_800BBCB8(param_1, param_1, 1.0f, 12, &D_8080051C_chelectricfence);
    _subaddieaudioquick_entrypoint_2(param_0, param_1, &D_8080058C_chelectricfence);
    temp_v0 = func_800C8A98();
    sp2C = temp_v0;
    func_800C8CB8(temp_v0, param_1);
    func_800C8E84(sp2C, &D_80800598_chelectricfence);
    func_800C8E54(sp2C, 0x43960000, 0x44160000);
    _chlightfader_entrypoint_1(sp2C, 0x3F4CCCCD, 5);
}

void chelectricfence_entrypoint_2(Actor *param_0, f32 *param_1, f32 *param_2)
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3;
    s32 local_4;
    f32 local_5;

    local_3 = func_800DC298(0.5f) ? param_1[2] : param_2[2];
    func_800EFA4C(local_0, func_800DC178(param_1[0], param_2[0]), func_800DC178(param_1[1], param_2[1]), local_3);
    func_800EFA4C(local_1, func_800DC178(param_1[0], param_2[0]), func_800DC178(param_1[1], param_2[1]), local_3);
    func_800EF934(local_0, local_0, param_0->rotation[1]);
    func_800EF04C(local_0, param_0->position);
    func_800EF934(local_1, local_1, param_0->rotation[1]);
    func_800EF04C(local_1, param_0->position);
    func_800EFB24(local_2, local_1, local_0);
    func_800EF368(local_2, 400.0f);
    local_5 = func_800EEAD4(local_1, local_0) / 500.0f;
    local_4 = func_800B5BE4(0x12);
    func_800BABB8(local_4, local_0, 0, 1.8f, D_808005A4_chelectricfence);
    func_800BA930(local_4, (s16)local_2[0], (s16)local_2[1], (s16)local_2[2],
        (s16)local_2[0], (s16)local_2[1], (s16)local_2[2]);
    func_800BA8F8(local_4, local_5, local_5);
    func_800BA22C(local_4, 1);
}
