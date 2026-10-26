#include "common.h"

extern int D_80800B88_chcablespark;
extern f32 func_800DC178(f32, f32);
typedef union { s32 word; f32 value; } CableEvent30;
extern void func_800EEB9C(f32 *, f32, f32);
extern void func_801015D0(void *);
extern s32 func_800DE448(f32 *, f32 *, f32, s32, void *);
extern void func_800EEC30(f32 *, f32, f32, f32);
extern f32 func_800136E4(f32);
extern void func_800E3980(f32 *);
extern void func_800F18FC(f32 *, f32 *, f32 *);
extern f32 func_800F1DCC(f32, f32);
extern f32 mlAbsF(f32);
extern s32 func_800BEF00(void *, void *, void *, s32);
extern void func_800EE7F8(void *, s32);
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_80103014(void *);
extern s32 func_800F54E4(void);
extern f32 func_800F57F0(s32, f32 *);
extern s32 func_800F0008(f32 *, f32, f32 *, f32);
typedef struct { f32 local_0; f32 local_1; } CableSparkRange26;
extern CableSparkRange26 D_80800BDC_chcablespark;
extern u32 D_80800B70_chcablespark[3];
typedef struct { u8 local_0[0x64]; u32 local_1:2; u32 local_2:1; u32 local_3:29; } CableFlags49;
extern u8 D_80800BD0_chcablespark[];
extern int func_800DC298(f32);
extern void func_8010D254(f32 *);
extern f32 func_800EEB40(f32 *, f32 *);
void func_80800590_chcablespark();
int func_80800828_chcablespark();
void func_808008BC_chcablespark();
void func_80800A48_chcablespark();
s32 func_808007B8_chcablespark();

int chcablespark_entrypoint_0()
{
  return (int)&D_80800B88_chcablespark;
}

s32 func_80800970_chcablespark();

void func_80800668_chcablespark();

void func_8080000C_chcablespark(Actor *param_0)
{
    s32 local_0;
    s32 local_1;
    s32 local_2;
    param_0->unk64_24 = 0;
    if (func_80800828_chcablespark()) {
        param_0->unk64_24 = 1;
        _subaddieaudioloop_entrypoint_4(param_0, param_0->position, param_0->unk70_10 == 3, D_80800BD0_chcablespark);
        local_0 = func_800D90A4(&param_0->unk58);
        switch (param_0->unk70_10) {
        case 1:
            if (((CableFlags49 *)param_0)->local_2) {
                if (local_0 && _subaddiejoy_entrypoint_6(param_0, 1) == 1) {
                    func_80101FDC(param_0, 2);
                    param_0->unk58 = 0.25f;
                }
            } else if (local_0 && !func_808007B8_chcablespark(param_0)) {
                func_80101FDC(param_0, 3);
                param_0->unk58 = func_800DC178(0.8f, 1.2f);
                func_80800668_chcablespark(param_0);
                func_800C8FE0(param_0->actorData[6], 1);
            }
            break;
        case 2:
            if (local_0) {
                func_80101FDC(param_0, 3);
                param_0->unk58 = 1.0f;
                func_80800668_chcablespark(param_0);
                func_800C8FE0(param_0->actorData[6], 1);
            }
            break;
        case 3:
            if (((CableFlags49 *)param_0)->local_2) local_1 = 0;
            else local_1 = func_808007B8_chcablespark(param_0);
            local_2 = func_80800970_chcablespark(param_0);
            func_800C8E84(param_0->actorData[6], ((u32 (*)[3])D_80800B70_chcablespark)[func_800DC298(0.35f)]);
            if (local_0 || local_1 || local_2) {
                func_80101FDC(param_0, 1);
                if (((CableFlags49 *)param_0)->local_2) param_0->unk58 = func_800DC178(1.2f, 1.4f);
                else param_0->unk58 = 2.0f;
                func_800C8FE0(param_0->actorData[6], 0);
            }
            break;
        }
    }
}

void func_8080024C_chcablespark(Actor *param_0)
{
    *(u8 *)param_0->actorData = 0;
    param_0->unk58 = func_800DC178(0.0f, 2.0f);
    if (param_0->unk74_7 == 0x35 && func_80800828_chcablespark(param_0)) {
        _subaddieDll_entrypoint_4(param_0, 1);
    }
    func_808008BC_chcablespark(param_0);
}

void func_808002BC_chcablespark(u8 *arg0) {
  int new_var2;
  int new_var;
  new_var2 = 0xFFFFFFFF;
  if (arg0[24] != 0)
  {
    new_var = (((arg0[24] & new_var2) & new_var2) & new_var2) & 0xFFFFFFFF;
    func_800E87E0(((((new_var & new_var2) & 0xFF) & 0xFF) & 0xFF) & 0xFF);
  }
}

s32 func_808002E8_chcablespark(Actor *param_0, s32 param_1, CableEvent30 param_2)
{
    f32 local_0[3];
    f32 local_1;
    switch (param_1) {
    case 0xA:
        param_0->unk64_24 = func_80800828_chcablespark(param_0);
        if (param_0->unk74_7 == 0x35) {
            param_0->unk64_24 = 0;
            if (func_80800828_chcablespark(param_0)) _subaddieDll_entrypoint_4(param_0, 1);
        }
        break;
    case 0x95:
        func_80800A48_chcablespark(param_0);
        break;
    case 0x97:
        local_1 = 1.0f / param_0->scale;
        func_800EEB9C(local_0, param_0->rotation[1], 150.0f * local_1);
        local_0[1] += 175.0f * local_1;
        func_80101010(local_0);
        break;
    default: return 0;
    }
    return 1;
}

void func_8080040C_chcablespark(Actor *param_0, s32 param_1)
{
    f32 local_0[3];
    param_0->unk64_20 = (s32)param_0->unk64_20 ^ 1;
    func_800DF830(1);
    func_800DF744(4, func_80800828_chcablespark(param_0) ? 1 : 2);
    func_800DE448(param_0->position, param_0->rotation, param_0->scale, 0, (void *)func_800D674C(0x6BC));
    param_0->unk7C_12 = func_800DF350();
    if (param_0->unk70_10 == 3) {
        func_80800590_chcablespark(param_0, local_0);
        func_800DF744(1, func_800DC128(0, 4));
        func_800DF47C(func_801015D0, param_0);
        func_800DE448(param_0->position, local_0, param_0->scale, 0, (void *)func_8010347C(param_0->unk0));
        if (func_800E88E4(((u8 *)param_0)[0x18]) == 1
            && param_0->unk64_20 && param_0->unk7C_12) {
            func_800E3A58(local_0);
            func_800DF830(0);
            func_800DE448(param_0->position, local_0, param_0->scale, 0, (void *)func_800D674C(0x6BB));
        }
    }
}

void func_80800590_chcablespark(param_0, param_1) Actor *param_0; f32 *param_1;
{
    f32 local_0[3];
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    f32 local_4;

    local_4 = 0.0f;
    func_800E3980(local_0);
    func_800EFB24(local_1, param_0->position, local_0);
    func_800EEC30(local_2, ((f32 *)param_0->actorData)[5], ((f32 *)param_0->actorData)[4], 100.0f);
    if (param_0->position[1] < local_0[1]) func_800EE97C(local_3, local_2, local_1);
    else func_800EE97C(local_3, local_1, local_2);
    func_800F1884(local_3, &local_4);
    param_1[0] = ((f32 *)param_0->actorData)[5];
    param_1[1] = ((f32 *)param_0->actorData)[4];
    param_1[2] = func_800136E4(local_4 - 90.0f);
}

void func_80800668_chcablespark(Actor *param_0)
{
    f32 local_0[3];
    f32 local_1[2];
    f32 local_2;
    f32 local_3;

    func_800E3980(local_0);
    func_800F18FC((*(Actor **)&param_0)->position, local_0, local_1);
    local_1[1] = func_800F1DCC((*(Actor **)&param_0)->rotation[1], local_1[1]);
    local_1[0] = -local_1[0];
    local_3 = (mlAbsF(local_1[1]) > 45.0f) ? 0.0f : ((local_1[1] > 0.0f) ? 15.0f : -15.0f);
    local_2 = (mlAbsF(local_1[0]) > 45.0f) ? 0 : ((local_1[0] < 0.0f) ? 15.0f : -15.0f);
    *(f32 *)&(*(Actor **)&param_0)->actorData[4] = func_800136E4((*(Actor **)&param_0)->rotation[1] + local_3);
    *(f32 *)&(*(Actor **)&param_0)->actorData[5] = func_800136E4(local_2);
}

s32 func_808007B8_chcablespark(param_0) Actor *param_0;
{
    f32 local_0[3];
    if (param_0->unk74_7 == 0x35) return 0;
    func_8010D254(local_0);
    return func_800EEB40(param_0->position, local_0) > 1000000.0f;
}

int func_80800828_chcablespark(param_0) Actor *param_0;
{
    s32 local_0;
    local_0 = (u32)(*(u16 *)((char *)(param_0) + 0x76)) >> 7;
    local_0 -= 0x32;
    switch (local_0)
    {
        case 1:
            if (!func_800DA298(0xEB))
            {
                return 0;
            }
            break;
        case 2:
            if (!func_800DA298(0xEC))
            {
                return 0;
            }
            break;
        case 3:
            if (!func_800DA298(0x18C))
            {
                return 0;
            }
            break;
    }
    return 1;
}

void func_808008BC_chcablespark(param_0) u8 *param_0; {
    f32 var_3C[3];
    f32 var_30[3];
    f32 var_24[3];

    func_800EE7F8(var_3C, param_0 + 4);
    func_800EF1B8(var_3C, *(f32 *)(param_0 + 0x48), 100.0f);
    func_800EE7F8(var_30, param_0 + 4);
    func_800EF1B8(var_30, *(f32 *)(param_0 + 0x48), -50.0f);
    if (func_800BEF00(var_3C, var_30, var_24, *(s32 *)(param_0 + 0x14)) != 0) {
        func_800EE7F8(param_0 + 4, var_30);
        func_800EF1B8(param_0 + 4, *(f32 *)(param_0 + 0x48), *(f32 *)(param_0 + 0x38) * 5.0f);
        func_80103014(param_0);
    }
}

s32 func_80800970_chcablespark(Actor *param_0)
{
    f32 local_0[3];
    f32 local_4;
    f32 local_1[3];
    f32 local_2;
    s32 local_3;

    local_3 = func_800F54E4();
    if (!func_800F6478(local_3)) return 0;
    local_2 = func_800F57F0(local_3, local_1);
    func_800EE7F8(local_0, param_0->position);
    func_800EF1B8(local_0, param_0->rotation[1], param_0->scale * 40.0f);
    local_4 = param_0->scale * 50.0f;
    if (func_800F0008(local_0, local_4, local_1, local_2) &&
        func_800F7B9C(local_3, 0x51) == 2) {
        _chelectricfence_entrypoint_1(param_0, local_1);
        return 1;
    }
    return 0;
}

void func_80800A48_chcablespark(param_0) Actor *param_0;
{
    CableSparkRange26 local_0 = D_80800BDC_chcablespark;

    local_0.local_0 *= param_0->scale;
    local_0.local_1 *= param_0->scale;
    param_0->actorData[6] = func_800C8A98();
    func_800C8E84(param_0->actorData[6], D_80800B70_chcablespark);
    func_800C8CB8(param_0->actorData[6], param_0->position);
    func_800C8F64(param_0->actorData[6], 11);
    func_800C8D4C(param_0->actorData[6], &local_0.local_0);
    func_800C8FE0(param_0->actorData[6], param_0->unk70_10 == 3);
    *(u8 *)&param_0->actorData[0] = func_800E8714(1);
    func_800E8830(*(u8 *)&param_0->actorData[0], param_0->position);
    param_0->unk64_24 = func_80800828_chcablespark(param_0);
    if (param_0->unk74_7 == 0x35) {
        param_0->unk64_24 = 0;
    }
}
