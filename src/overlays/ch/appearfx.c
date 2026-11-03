#include "common.h"

extern int D_80800990_chappearfx[];
typedef struct { s32 a; s32 b; } AfxPair;
extern AfxPair D_80800970_chappearfx[];
extern void func_800EF1B8(f32 *, f32, f32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E2530(f32);
typedef struct { s16 h0, h2, h4, h6, h8, hA; f32 fC; f32 f10; } AFXE_;
extern s32 _chappearfx_entrypoint_3;
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; s16 local_5; u8 local_6; u8 local_7; s16 local_8; s16 local_9; s16 local_10; u8 local_11[8]; } AppearFX49;
extern s32 D_80800974_chappearfx[][2];
extern u8 D_808009D8_chappearfx[];
extern Actor *func_80106790();
extern Actor *func_80108528(s32, f32 *, s32, Actor **);
extern void *func_80100074(Actor *, s32, s32);
extern f32 func_80103EAC(Actor *);
extern f32 func_800F0E00(f32, f32);
extern f32 func_800F13F0(f32, f32);
extern f32 func_800F10B4(f32, f32, f32, f32, f32);
extern void _subaddielink_entrypoint_0();
extern void rare_memcpy();
extern f32 func_800D8FF8(void);
extern void func_800EE7F8(f32 *, f32 *);
extern Actor *_subaddielink_entrypoint_4(void *);
typedef struct { s16 local_0[6]; f32 local_1, local_2; } AppearParticle;
extern f32 func_800DC178(f32, f32);
extern s32 func_800DC128(s32, s32);
extern int func_800DC298(f32);
void chappearfx_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, f32 param_3);
void func_80800014_chappearfx();
void func_80800554_chappearfx();
extern void func_80105834(), func_80107C2C(), func_8080000C_chappearfx(), func_80800014_chappearfx(), func_8080031C_chappearfx();

int *chappearfx_entrypoint_0()
{
    return &D_80800990_chappearfx;
}

void func_8080000C_chappearfx(s32 arg0) 
{
}
void func_80800014_chappearfx(param_0) Actor *param_0;
{
    s16 *local_0;
    AppearParticle *local_1;
    AppearParticle *local_2;
    s32 local_4;
    f32 local_3;
    s32 local_5;

    local_0 = func_80100094(param_0, 0);
    if (!func_8001210C(1)) {
        func_80800554_chappearfx(param_0);
    }
    switch ((s32)param_0->unk70_10) {
    case 1:
        ((u8 *)local_0)[0xD] = 1;
        func_800FCAE0(0x1C, -1, 0x1F4);
        if (func_800D9078(&param_0->unk58)) {
            func_80101FDC(param_0, 2);
            param_0->unk58 = 1.2f;
        }
        break;
    case 2:
        local_5 = func_800D9078(&param_0->unk58);
        ((u8 *)local_0)[0xC] = (u32)func_800F10B4(param_0->unk58, 0.0f, 1.2f, 16.0f, 255.0f);
        if (local_5) {
            ((u8 *)local_0)[0xD] = 0;
            func_800FCAE0(0x1C, 0, 0x1F4);
            func_800FCA90(0x1C);
            func_800FFAB0(param_0);
        } else {
            ((u8 *)local_0)[0xD] = 1;
            func_800FCAE0(0x1C, -1, 0x1F4);
        }
        break;
    }
    if ((((u16 *)local_0)[2] & 8) && _subaddielink_entrypoint_2((u8 *)local_0 + 0x14)) {
        func_800EE7F8(param_0->position,
            _subaddielink_entrypoint_4((u8 *)local_0 + 0x14)->position);
    }
    local_3 = func_800D8FF8();
    local_2 = (AppearParticle *)((u8 *)local_0 + 0x1C);
    local_1 = local_2;
    for (local_4 = 0; local_4 < local_0[0]; ) {
        local_1->local_0[4] += local_3 * local_1->local_0[1];
        local_1->local_0[3] += local_3 * local_1->local_0[0];
        local_1->local_1 += local_3 * local_1->local_0[5];
        if (local_1->local_0[4] >= local_0[4]) {
            local_0[0]--;
            if (local_0[0] > 0) {
                rare_memcpy(local_1, local_2 + local_0[0], sizeof(AppearParticle));
            }
            continue;
        }
        local_1++;
        local_4++;
    }
}

void func_8080031C_chappearfx(param_0) s32 param_0;
{
    u8 *v0;

    v0 = func_80100094(param_0, 0);
    if (v0[0xD] != 0) {
        v0[0xD] = 0;
        func_800FCAE0(0x1C, 0, 0x1F4);
        func_800FCA90(0x1C);
    }
}

int func_80800360_chappearfx(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  if (param_1 == 0x95)
  {
    _subaddielink_entrypoint_3(func_80100094(param_0, 0) + 0x14);
    return 1;
  }
  return 0;
}

void func_808003A0_chappearfx(Actor *param_0, void *param_1)
{
    u8 *local_0;
    u8 *local_1;
    s32 local_2;
    void *local_3;
    f32 local_5[3];
    f32 local_6[3];
    f32 local_4;
    local_0 = func_80100094(param_0, 0);
    local_1 = local_0 + 0x1C;
    param_0->unk7C_12 = 1;
    if (*(s16 *)local_0) {
        local_3 = func_800D674C(D_80800970_chappearfx[*(s16 *)(local_0 + 0xE)].a);
        func_800E2588((*(u16 *)(local_0 + 4) & 0x10) ? 0 : 1);
        func_800E2594(param_1, local_3);
        func_800E24D8(1);
        for (local_2 = 0; local_2 < *(s16 *)local_0; local_2++, local_1 += 0x14) {
            local_4 = param_0->scale * ((AFXE_ *)local_1)->f10;
            func_800EE7F8(local_5, param_0->position);
            func_800EF1B8(local_5, *(s16 *)(local_1 + 6), *(s16 *)(local_0 + 6));
            local_5[1] += *(s16 *)(local_1 + 8);
            func_800EFA4C(local_6, local_4, local_4, local_4);
            func_800E2530(*(f32 *)(local_1 + 0xC));
            func_800E2720(param_1, 0, *(s16 *)(local_1 + 4), local_5, local_6, local_0[0xC]);
        }
        func_800E2A14(param_1);
    }
}

void func_80800554_chappearfx(param_0) Actor *param_0;
{
    s16 *local_0;
    AppearParticle *local_1;
    f32 local_2;
    local_0 = func_80100094(param_0, 0);
    if (local_0[0] < local_0[1]) {
        local_1 = (AppearParticle *)local_0;
        local_1 += local_0[0];
        local_1 = (AppearParticle *)((u8 *)local_1 + 0x1C);
        local_1->local_0[3] = func_800DC178(0.0f, 359.0f);
        local_1->local_0[0] = func_800DC128(250, 350);
        local_2 = func_800F10B4(local_0[4] - local_0[5], 0.0f, 500.0f, 30.0f, 350.0f);
        local_1->local_0[1] = func_800DC178(0.8f, 1.2f) * local_2;
        local_1->local_0[4] = local_0[5];
        local_1->local_0[2] = func_800DC298(0.5f);
        local_1->local_2 = func_800DC178(0.8f, 1.4f);
        local_1->local_1 = func_800DC178(0.0f, 360.0f);
        local_1->local_0[5] = func_800DC128(-200, 200);
        local_0[0]++;
    }
}

void chappearfx_entrypoint_1(s32 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    _chbaddiesetup_entrypoint_4(&_chappearfx_entrypoint_3, *param_0, param_1, param_2, param_3);
}

void chappearfx_entrypoint_2(Actor **param_0, f32 *param_1, s32 param_2, s32 param_3)
{
    chappearfx_entrypoint_3(*param_0, param_1, param_2, *(f32 *)&param_3);
}

void chappearfx_entrypoint_3(s32 param_0, s32 param_1, s32 param_2, f32 param_3)
{
    Actor *local_0;
    Actor *local_1;
    s32 local_3;
    s32 local_4;
    s32 local_5;
    s32 local_6;
    f32 local_7;
    AppearFX49 *local_2;
    *(f32 *)&local_7 = *(f32 *)&param_3;
    local_0 = func_80106790(param_0);
    local_1 = func_80108528(0x3D9, local_0->position, 0, &local_0);

    local_3 = (func_80103EAC(local_0) + 20.0f) * local_7;
    local_4 = func_800F0E00(50.0f, *(s16 *)((u8 *)local_0 + 0x8A) * local_0->scale);
    local_5 = func_800F13F0(0.0f, *(s16 *)((u8 *)local_0 + 0x88) * local_0->scale);
    local_6 = func_800F10B4(local_4 - local_5, 0.0f, 500.0f, 15.0f, 40.0f);


    local_2 = func_80100074(local_1, 0, local_6 * 20 + 28);
    local_1->unk58 = 3.0f;
    local_2->local_1 = local_6;
    local_2->local_0 = 0;
    local_2->local_10 = local_3 + 400;
    local_2->local_3 = local_3;
    local_2->local_9 = local_3;
    local_2->local_4 = local_4;
    local_2->local_5 = local_5;
    local_2->local_6 = 255;
    local_2->local_2 = param_1;
    _subaddielink_entrypoint_0(local_2->local_11);
    local_2->local_8 = param_2;
    func_80102FDC(local_1, D_80800974_chappearfx[param_2][0]);

    if (param_1 & 2) _subaddieaudioquick_entrypoint_2(local_1, local_1->position, D_808009D8_chappearfx);
    if (param_1 & 4) func_800FC660(0x10);
    if (param_1 & 8) _subaddielink_entrypoint_1(local_2->local_11, local_0->unk0);
    if (param_1 & 0x20) _subaddiefade_entrypoint_2(local_0);
}

/* TU-NOTE: the .data of this overlay (formerly asm/data/overlays/ch/appearfx.data.s) is defined here in C.
 * Its tables hold pointers to functions of this file; IDO's assembler schedules some of these
 * functions differently unless the tables are defined in the same unit. Values are taken from the ROM.
 * Labels inside an object are linker symbols in undefined_syms.us.txt: D_80800974_chappearfx = D_80800970_chappearfx + 0x4
 * extern declarations adjusted to the object (same addresses): D_80800990_chappearfx -> int[] */
AfxPair D_80800970_chappearfx[4] = { 0x9E3, 0x3E99999A, 0x9E1, 0x3E99999A, 0x9E4, 0x3E99999A, 0x9E9, 0x3E99999A };
int D_80800990_chappearfx[18] = { 0xA003D9, -0xFFFF, 0x0, (u32)func_80800014_chappearfx, (u32)func_80105834, (u32)func_808003A0_chappearfx, 0x0, 0x0, 0x0, 0x20000, (u32)func_8080031C_chappearfx, 0x0, 0x0, (u32)func_8080000C_chappearfx, (u32)func_80107C2C, -0x7FFFFBFE, (u32)func_80800360_chappearfx, 0x0 };
u8 D_808009D8_chappearfx[24] = { 0x0, 0x13, 0x4, 0x80, 0x0, 0x18, 0x0, 0xD, 0x0, 0xE6, 0x1, 0x19, 0x0, 0x2, 0x0, 0x1B, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0 };
