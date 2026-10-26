#include "common.h"

extern int D_80800D5C_chboilerid;
typedef struct { s16 values[15]; } BoilerSettings29;
extern BoilerSettings29 D_80800D00_chboilerid[];
extern void *func_80100094(Actor *, u32);
extern void _mlwave_entrypoint_0(void *, f32, f32);
extern s32 D_80800DA4_chboilerid;
extern s32 D_80800DB0_chboilerid;
extern s32 D_80800DE8_chboilerid;
extern void _chboilerid_entrypoint_1(void);
extern void _chboilerid_entrypoint_2(void);
extern void _chboilerid_entrypoint_3(void);
extern void _chboilerid_entrypoint_4(void);
extern f32 func_800D8FF8(void);
extern s32 func_800D9078();
extern void func_800BBCB8(f32 *, s32, f32, s32, void *);
extern Actor *func_80106790(Unk80132ED0 *);
typedef struct { u8 pad_0[0x20]; f32 local_0; f32 local_1; u8 pad_1[0x32]; s16 local_2; } BoilerMotion1312;
extern f32 func_800EEF94(f32 *);
extern f32 func_800136D0(f32);
extern f32 func_800138BC(f32);
typedef struct { u8 pad_0[0x3C]; u8 local_0[0x20]; s16 local_1; } BoilerWave1472;
extern f32 _mlwave_entrypoint_4(void *, f32, f32, f32);
extern void _mlwave_entrypoint_3(void *, f32, f32);
extern u8 unk5C[];
extern u8 D_80800DFC_chboilerid[];
extern void func_800F3320(u32 *, void *, void *, f32);
extern void func_800F2FD0(void *, u32 *, f32);
void func_80800418_chboilerid();
s32 func_80800440_chboilerid();
s32 func_80800468_chboilerid();
int func_8080079C_chboilerid();
void func_8080084C_chboilerid();
void func_80800918_chboilerid();
void chboilerid_entrypoint_5();
s32 func_80800C48_chboilerid();
int func_80800CB0_chboilerid();
int func_80800700_chboilerid();

int chboilerid_entrypoint_0()
{
    return &D_80800D5C_chboilerid;
}

void func_8080000C_chboilerid(Actor *param_0)
{
    u8 *local_0;
    s32 local_1;
    local_0 = func_80100094(param_0, 0);
    *(s16 *)(local_0 + 0x5E) = func_800EA05C();
    _subaddielink_entrypoint_0(local_0 + 0x60);
    func_80800C48_chboilerid(param_0);
    *(f32 *)(local_0 + 0x1C) = 0.0f;
    local_1 = func_80800CB0_chboilerid(local_0);
    _mlwave_entrypoint_0(local_0, 500.0f, D_80800D00_chboilerid[local_1].values[0]);
    _mlwave_entrypoint_0(local_0 + 0x3C, 200.0f, D_80800D00_chboilerid[local_1].values[4]);
    _mlwave_entrypoint_0(local_0 + 0x20, 300.0f, D_80800D00_chboilerid[local_1].values[8]);
    *(s16 *)(local_0 + 0x58) = D_80800D00_chboilerid[local_1].values[13];
    *(s16 *)(local_0 + 0x5A) = D_80800D00_chboilerid[local_1].values[12];
    *(s16 *)(local_0 + 0x5C) = D_80800D00_chboilerid[local_1].values[14];
    func_800DA524(0x66F);
}

void func_80800998_chboilerid();

void func_80800128_chboilerid(Actor *param_0)
{
    f32 local_0[3];
    u8 *local_1;
    f32 local_2;
    s32 local_4;
    s32 local_3;
    local_1 = func_80100094(param_0, 0);
    local_2 = func_800D8FF8();
    func_8010D254(local_0);
    local_4 = param_0->unk70_10 != 1;
    if (local_4 || (!local_4 && param_0->unk5F)) {
        _subaddieaudioloop_entrypoint_4(param_0, 0, local_4, &D_80800DA4_chboilerid);
    }
    switch (param_0->unk70_10) {
    case 2:
        *(f32 *)(local_1 + 0x1C) += local_2;
        if (*(f32 *)(local_1 + 0x1C) >= 1.5f) {
            *(f32 *)(local_1 + 0x1C) = 1.5f;
            func_80101FDC(param_0, 3);
        }
        break;
    case 3:
        local_3 = func_800F54E4();
        if (func_800D9078(&param_0->unk58)) {
            chboilerid_entrypoint_5(param_0);
        }
        if (func_800F6C5C(local_3) && func_800F6478(local_3) &&
            func_800F64A4(local_3, 0x601) && (func_800F55FC(local_3) & 0x08000000) &&
            func_800F7B9C(local_3, 0x51) == 2) {
            func_800BBCB8(local_0, 0, 1.0f, 1, &D_80800DB0_chboilerid);
            func_800C4AF0(local_0, &D_80800DE8_chboilerid);
        }
        break;
    case 4:
        if (func_800D9078((f32 *)(local_1 + 0x1C))) {
            *(f32 *)(local_1 + 0x1C) = 0.0f;
            func_80101FDC(param_0, 1);
            func_800DA3B8(0x66F, 0);
            func_800CF494();
        }
        break;
    }
    func_80800418_chboilerid(param_0);
    func_80800440_chboilerid(param_0);
    func_80800468_chboilerid(param_0);
    func_80800998_chboilerid((s32)param_0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3C, _chboilerid_entrypoint_1, param_0->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3D, _chboilerid_entrypoint_2, param_0->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3E, _chboilerid_entrypoint_3, param_0->unk0);
    _glid_entrypoint_0(func_800BEA88(0), 0x3F, _chboilerid_entrypoint_4, param_0->unk0);
}

int func_808003AC_chboilerid(s32 param_0, s32 param_1, s32 param_2)
{
  if (param_1 == 0x95)
  {
    _subaddielink_entrypoint_3((s32)func_80100094(param_0, 0) + 0x60);
    return 1;
  }
  return 0;
}

s32 func_808003EC_chboilerid(s32 param_0){
    func_800DA524(0x66F);
    func_800CF494();
}

void func_80800418_chboilerid(param_0) s32 param_0; {
    _mlwave_entrypoint_1(func_80100094(param_0, 0));
}

s32 func_80800440_chboilerid(param_0) s32 param_0;{
    _mlwave_entrypoint_1((s32)func_80100094(param_0, 0) + 0x20);
}

s32 func_80800468_chboilerid(param_0) s32 param_0;
{
  _mlwave_entrypoint_1((s32)func_80100094(param_0, 0) + 0x3C);
}

void chboilerid_entrypoint_1(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    void *local_0;
    Vtx *local_1;

    local_0 = func_80100094(func_80106790(param_4), 0);
    for (local_1 = param_2 + param_3; param_2 < local_1; param_2++, param_1++) {
        func_80800700_chboilerid(param_1, param_2, local_0);
    }
}

void chboilerid_entrypoint_2(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    void *local_0;
    Vtx *local_1;
    local_0 = func_80100094(func_80106790(param_4), 0);
    local_1 = param_2 + param_3;
    for (; param_2 < local_1; param_2++, param_1++) {
        func_80800700_chboilerid(param_1, param_2, local_0);
        func_8080079C_chboilerid(param_1, param_2, local_0);
    }
}

void chboilerid_entrypoint_3(s32 param_0, Vtx *param_1, Vtx *param_2, s32 param_3, Unk80132ED0 *param_4)
{
    void *local_0;
    Vtx *local_1;

    local_0 = func_80100094(func_80106790(param_4), 0);
    for (local_1 = param_2 + param_3; param_2 < local_1; param_2++, param_1++) {
        func_8080079C_chboilerid(param_1, param_2, local_0);
    }
}

void chboilerid_entrypoint_4(s32 param_0, Vtx *param_1, Vtx *param_2,
    s32 param_3, Unk80132ED0 *param_4)
{
    void *local_0;
    Vtx *local_1;

    local_0 = func_80100094(func_80106790(param_4), 0);
    local_1 = param_3 + param_2;
    for (; param_2 < local_1; param_2++, param_1++) {
        func_80800700_chboilerid(param_1, param_2, local_0);
        func_8080079C_chboilerid(param_1, param_2, local_0);
        func_80800918_chboilerid(param_1, param_2, local_0);
    }
}

int func_80800700_chboilerid(param_0, param_1, param_2) Prop *param_0; Prop *param_1; u8 *param_2;
{
    f32 local_0[3];
    u32 local_1;
    f32 local_2;

    func_800EE88C(local_0, param_0);
    local_2 = _mlwave_entrypoint_4(param_2, func_800EEF94(local_0), 0.6f, 1.0f);
    func_800F3320(&local_1, (u8 *)param_0 + 0xC, D_80800DFC_chboilerid,
        *(f32 *)(param_2 + 0x1C) * 0.6666667f);
    func_800F2FD0((u8 *)param_1 + 0xC, &local_1, local_2);
}

int func_8080079C_chboilerid(param_0, param_1, param_2) u8 *param_0; u8 *param_1; u8 *param_2;
{
    f32 local_0[2];

    func_8080084C_chboilerid(param_2, param_0, local_0);
    *(s16 *)(param_1 + 8) = (s16)(s32)((f32)*(s16 *)(param_0 + 8) + (f32)*(s16 *)(param_2 + 0x58) * local_0[0]);
    *(s16 *)(param_1 + 0xA) = (s16)(s32)((f32)*(s16 *)(param_0 + 0xA) + (f32)*(s16 *)(param_2 + 0x58) * local_0[1]);
}

void func_8080084C_chboilerid(param_0, param_1, param_2) BoilerMotion1312 *param_0; s16 *param_1; f32 *param_2;
{
    f32 local_1;
    f32 local_2;
    f32 local_0[3];
    f32 local_3;

    func_800EE88C(local_0, param_1);
    local_1 = func_800EEF94(local_0);
    local_2 = func_800138BC(func_800136D0(param_0->local_1 * (local_1 - param_0->local_0)))
              * param_0->local_2 * param_0->local_1;
    if (local_1 != 0.0f) {
        local_3 = local_2 / local_1;
        param_2[0] = local_0[0] * local_3;
        param_2[1] = local_0[2] * local_3;
    } else {
        param_2[0] = local_0[0] * local_2;
        param_2[1] = local_0[2] * local_2;
    }
}

void func_80800918_chboilerid(param_0, param_1, param_2) Vtx *param_0; Vtx *param_1; BoilerWave1472 *param_2;
{
    f32 local_0[3];
    f32 local_1;
    f32 local_2;
    s32 local_3;

    func_800EE88C(local_0, param_0->v.ob);
    local_1 = func_800EEF94(local_0);
    local_2 = _mlwave_entrypoint_4(param_2->local_0, local_1, 0.0f, param_2->local_1);
    param_1->v.ob[1] = param_0->v.ob[1] + (s16)(s32)local_2;
}

void func_80800998_chboilerid(s32 arg0) 
{
}
void chboilerid_entrypoint_5(param_0) Actor *param_0;
{
    u8 *local_2;
    s32 local_0;

    local_2 = func_80100094(param_0, 0);
    if (param_0->unk70_10 != 1 && param_0->unk70_10 != 4) {
        local_0 = func_80800CB0_chboilerid(local_2);
        _mlwave_entrypoint_3(local_2, D_80800D00_chboilerid[local_0].values[0], D_80800D00_chboilerid[local_0].values[1]);
        _mlwave_entrypoint_3(local_2 + 0x3C, D_80800D00_chboilerid[local_0].values[4], D_80800D00_chboilerid[local_0].values[5]);
        _mlwave_entrypoint_3(local_2 + 0x20, D_80800D00_chboilerid[local_0].values[8], D_80800D00_chboilerid[local_0].values[9]);
        *(s16 *)(local_2 + 0x58) = D_80800D00_chboilerid[local_0].values[13];
        *(s16 *)(local_2 + 0x5A) = D_80800D00_chboilerid[local_0].values[12];
        *(s16 *)(local_2 + 0x5C) = D_80800D00_chboilerid[local_0].values[14];
        func_80101FDC(param_0, 4);
    }
}

void chboilerid_entrypoint_6(Actor *param_0, f32 param_1)
{
    u8 *local_2 = func_80100094(param_0, 0);
    s32 local_0;

    param_0->unk58 = param_1;
    if (param_0->unk70_10 != 3 && param_0->unk70_10 != 2) {
        local_0 = func_80800CB0_chboilerid(local_2);
        _mlwave_entrypoint_3(local_2, (f32)D_80800D00_chboilerid[local_0].values[2], (f32)D_80800D00_chboilerid[local_0].values[3]);
        _mlwave_entrypoint_3(local_2 + 0x3C, (f32)D_80800D00_chboilerid[local_0].values[6], (f32)D_80800D00_chboilerid[local_0].values[7]);
        _mlwave_entrypoint_3(local_2 + 0x20, (f32)D_80800D00_chboilerid[local_0].values[10], (f32)D_80800D00_chboilerid[local_0].values[11]);
        *(s16 *)(local_2 + 0x58) = D_80800D00_chboilerid[local_0].values[13];
        *(s16 *)(local_2 + 0x5A) = D_80800D00_chboilerid[local_0].values[12];
        *(s16 *)(local_2 + 0x5C) = D_80800D00_chboilerid[local_0].values[14];
        func_80101FDC(param_0, 2);
        func_800DA3B8(0x66F, 1);
        func_800CF2D4(3);
    }
}

s32 func_80800C48_chboilerid(param_0) s32 param_0; {
    s32 local_0;
    Actor *local_1;

    local_0 = func_80100094(param_0, 0);
    local_1 = _subaddiefind_entrypoint_0(param_0 + 4, 0x118, -1, 0);
    if (local_1 != NULL) {
        _subaddielink_entrypoint_1(local_0 + 0x60, local_1->unk0);
        return 1;
    }
    _subaddielink_entrypoint_0(local_0 + 0x60);
    return 0;
}

int func_80800CB0_chboilerid(param_0) Actor *param_0;
{
  short new_var;
  new_var = *((s32 *) (((char *) param_0) + 0x5C));
  switch (new_var)
  {
    case 0xD1:
      return 0;

    case 0xE7:
      return 1;

    default:
      return 2;

  }

}
