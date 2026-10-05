#include "common.h"
#include "core2/1EBB4F0.h"

#define E1DF4_COMMAND(a,b) { Gfx *local_1 = local_0++; local_1->words.w0 = (a); local_1->words.w1 = (b); }
extern s16 D_8012D48C;
extern f32 func_800E3928(s32, s32);
extern f32 func_800E42C0(void);
extern void func_800EE7F8(s32, s32);
typedef struct { s32 pad; s32 local_0[3], local_1[3]; s16 local_2; u8 local_3, local_4, local_5; } RenderE1DF4;
extern Gfx D_801231B0[];
typedef struct { s16 local_0, local_1; u8 pad[40]; f32 local_2, local_3; } StateE204C;
typedef struct { s16 pad[2]; s16 local_0, local_1; } SizeE204C;
typedef struct { Gfx *local_0; Mtx *local_1; } DrawE;
extern f32 D_8012D4A8[4][4];
extern void func_800F26B0(f32 [4][4], f32, f32, f32);
typedef struct { s16 local_0, local_1, local_2, local_3; } FrameE;
typedef struct { s16 local_0, local_1; s32 local_2[3], local_3[3]; s16 local_4; u8 local_5, local_6, local_7, local_8, local_9, local_10; s32 local_11; f32 local_12, local_13, local_14, local_15; f32 local_16[4][4]; s32 local_17, local_18; void *local_19; ImageStruct *local_20; } StateE;

extern void *func_800AF5D8(void *);
extern void *func_800AF5E4(void *);
extern Gfx *func_800AF5F0(void *);
extern FrameE *func_800AF5FC(void *, s32);
typedef struct { s16 local_0, local_1; s32 local_2[3]; s32 local_3_0, local_3_1, local_3_2; s16 local_4; u8 local_5, local_6, local_7, local_8, local_9, local_10; s32 local_11; f32 local_12, local_13, local_14, local_15; u8 local_16[64]; s32 local_17, local_18; } local_type;
extern u8 D_8012D490;
extern s32 D_8012D474;
extern s32 D_8012D494;
extern float D_8012D4A4;
extern u8 D_8012D48F;
extern u8 D_8012D492;
extern u8 D_8012D493;
extern u8 D_8012D491;
extern s32 D_8012D480;
extern float D_8012D498;
extern u8 D_8012D48E;
extern s32 D_8012D4F0;
extern void *func_800E401C(void);
extern void mlMtxSet(void *);
extern void mlMtxRotRoll(f32);
extern void func_800191F8(f32, f32, f32);
extern void mlMtxRotatePYR(f32, f32, f32);
extern void mlMtxScale_xyz(f32, f32, f32);
extern void mlMtxApply(Mtx *);
extern void func_80019CD4(void);
extern f32 func_800A8AF0(s32 param_0);
extern s32 func_800A89F8(void);
typedef struct { s32 local_0, local_1, local_2; } LocalPosition;
typedef struct { s32 pad; s16 local_0, local_1, local_2, local_3; } ImageE2E48;
typedef struct { s16 local_0, local_1; u8 pad[0x24]; f32 local_4, pad2C; f32 local_2, local_3; } StateE2E48;
extern void func_800E42F0(DrawE *, s32);
extern void func_800EFA4C(f32 *, f32, f32, f32);
extern void func_800E4640(DrawE *);
extern int D_8012D4F4;
typedef struct { s16 local_0, local_1; s32 pad; } FrameE32CC;
typedef struct { s16 local_0, local_1; u8 pad[0xC]; s32 local_2[3]; s16 local_3; u8 pad1[0xA]; f32 local_4, local_5, local_6; u8 pad2[0x50]; ImageE2E48 *local_7; } StateE32CC;
typedef union {
    StateE StateE;
    RenderE1DF4 RenderE1DF4;
    StateE204C StateE204C;
    local_type local_type;
    StateE2E48 StateE2E48;
    StateE32CC StateE32CC;
} Union_D_8012D470;
extern Union_D_8012D470 D_8012D470;
void func_800E23A4();
int func_800E24F8();

s32 func_800E1C00(u8 *param_0, s32 param_1, f32 param_2, f32 param_3, s32 param_4)
{
  f32 local_0;
  s8 _sfpad[8];
  f32 local_1;
  f32 local_2;
  f32 local_3;
  f32 local_4;
  local_1 = ((f32) (*((s32 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x24)))) * func_800E42C0();
  local_0 = func_800E3928(param_1, param_4);
  func_800EE7F8(param_4, param_1);
  if ((local_0 < 0.0f) || (local_1 < local_0))
  {
    return 0;
  }
  if (((*((u8 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x21))) == 0) && ((*((s32 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x24))) == 0x4E20))
  {
    local_4 = ((f32) (*((s16 *) (((s8 *) param_0) + 4)))) * param_2;
    local_3 = ((f32) (*((s16 *) (((s8 *) param_0) + 6)))) * param_3;
    if (local_4 < local_3)
    {
      local_4 = local_3;
    }
    if (((local_1 * 0.15f) < local_0) && ((local_4 / local_0) < 0.1f))
    {
      return 0;
    }
    goto block_10;
  }
  block_10:
  if (((*((s32 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x80))) == 0) && ((*((s32 (**)(s32)) (((s8 *) (((s32 *) &D_8012D470))) + 0x78))) != 0))
  {
    (*((s32 (**)(s32)) (((s8 *) (((s32 *) &D_8012D470))) + 0x78)))(*((s32 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x7C)));
  }

  if ((*((u8 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x22))) != 0)
  {
    local_2 = local_1 - 500.0f;
    if (local_2 < local_0)
    {
      D_8012D48C = (s16) (((s32) ((*((s16 *) (((s8 *) (((s32 *) &D_8012D470))) + 0x1C))) * ((s32) ((1.0f - ((local_0 - local_2) / 500.0f)) * 256.0f)))) / 256);
    }
  }
  return 1;
}

void func_800E1DF4(param_0, param_1) Gfx ** param_0; s32 param_1; {
    Gfx *local_0 = *param_0;
    E1DF4_COMMAND(0xDE000000, (u32)((u8 *)D_801231B0 - 0x80000000));
    if (!D_8012D470.RenderE1DF4.local_4) { E1DF4_COMMAND(0xE3001801, 0xC0); }
    E1DF4_COMMAND(0xFA000000, ((D_8012D470.RenderE1DF4.local_1[0] & 0xFF) << 24) | ((D_8012D470.RenderE1DF4.local_1[1] & 0xFF) << 16) | ((D_8012D470.RenderE1DF4.local_1[2] & 0xFF) << 8) | (D_8012D470.RenderE1DF4.local_2 & 0xFF));
    E1DF4_COMMAND(0xFB000000, ((D_8012D470.RenderE1DF4.local_0[0] & 0xFF) << 24) | ((D_8012D470.RenderE1DF4.local_0[1] & 0xFF) << 16) | ((D_8012D470.RenderE1DF4.local_0[2] & 0xFF) << 8) | 0xFF);
    if (D_8012D470.RenderE1DF4.local_3 > 0 &&D_8012D470.RenderE1DF4.local_3 < 5) {
        E1DF4_COMMAND(0xD9FFFFFF, 1);
        switch (D_8012D470.RenderE1DF4.local_3) {
        case 1: E1DF4_COMMAND(0xE200001C, 0x504A50); break;
        case 2: E1DF4_COMMAND(0xE200001C, 0x504250); break;
        case 3: E1DF4_COMMAND(0xE200001C, 0x504A70);
            D_8012D470.RenderE1DF4.local_5 = 0x80; break;
        case 4: E1DF4_COMMAND(0xE200001C, 0x504B70); break;
        }
    } else if (D_8012D470.RenderE1DF4.local_3 == 5) {
        E1DF4_COMMAND(0xE200001C, 0x504340);
    } else {
        E1DF4_COMMAND(0xE200001C, 0x504240);
    }
    if (D_8012D470.RenderE1DF4.local_5) {
        E1DF4_COMMAND(0xE2001E01, 1);
        E1DF4_COMMAND(0xF9000000, D_8012D470.RenderE1DF4.local_5 & 0xFF);
    }
    *param_0 = local_0;
}

void func_800E204C(DrawE *param_0, SizeE204C *param_1) {
    if ((param_1->local_0 != D_8012D470.StateE204C.local_0 &&D_8012D470.StateE204C.local_0) ||
        (param_1->local_1 != D_8012D470.StateE204C.local_1 &&D_8012D470.StateE204C.local_1) ||
        (f32)D_8012D470.StateE204C.local_2 != 1.0f || (f32)D_8012D470.StateE204C.local_3 != 1.0f) {
    func_800F26B0(D_8012D4A8, (f32)D_8012D470.StateE204C.local_2 * D_8012D470.StateE204C.local_0 / param_1->local_0,
        (f32)D_8012D470.StateE204C.local_3 * D_8012D470.StateE204C.local_1 / param_1->local_1, 1.0f);
    guMtxF2L(D_8012D4A8, param_0->local_1);
    { Gfx *local_0 = param_0->local_0++;
      local_0->words.w0 = 0xDA380000;
      local_0->words.w1 = (u32)param_0->local_1;
    }
    param_0->local_1++;
    }
}

void func_800E2180(DrawE *param_0, void *param_1, s32 param_2)
{
    FrameE *local_0;
    Gfx *local_1;
    gDma1p(param_0->local_0++, 0xDB, osVirtualToPhysical(func_800AF5D8(param_1)), 8, 6);
    gDma1p(param_0->local_0++, 0xDB, osVirtualToPhysical(func_800AF5E4(param_1)), 4, 6);
    local_0 = func_800AF5FC(param_1, param_2);
    local_1 = func_800AF5F0(param_1);
    local_1 += local_0->local_2;
    gDma1p(param_0->local_0++, 0xDE, osVirtualToPhysical(local_1), 0, 0);
}

void func_800E2260(DrawE *param_0, FrameE *param_1)
{
    if ((param_1->local_2 != D_8012D470.StateE.local_0 && D_8012D470.StateE.local_0) ||
        (param_1->local_3 != D_8012D470.StateE.local_1 && D_8012D470.StateE.local_1) ||
        D_8012D470.StateE.local_13 != 1.0f || D_8012D470.StateE.local_14 != 1.0f) {
        gDma2p(param_0->local_0++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    }
}

void func_800E22F0(param_0, param_1) u8 **param_0; u8 param_1;
{
    u8 *local_0;
    u8 *local_1;
    u8 *local_2;

    if ((((u8 *) &D_8012D470)[0x1f] == 0) || (((u8 *) &D_8012D470)[0x20] != 0)) {
        local_0 = *param_0;
        *param_0 = local_0 + 8;
        *(s32 *)(local_0 + 4) = 0;
        *(s32 *)local_0 = 0xE7000000;
        if (((u8 *) &D_8012D470)[0x1f] == 0) {
            local_1 = *param_0;
            *param_0 = local_1 + 8;
            *(s32 *)(local_1 + 4) = 0;
            *(s32 *)local_1 = 0xE3001801;
        }
        if (((u8 *) &D_8012D470)[0x20] != 0) {
            local_2 = *param_0;
            *param_0 = local_2 + 8;
            *(s32 *)(local_2 + 4) = 0;
            *(s32 *)local_2 = 0xE2001E01;
        }
    }
    func_800E8078(param_0, ((u8 *) &D_8012D470));
    func_800E23A4();
}

void func_800E23A4(void) {
    D_8012D470.local_type.local_0 = D_8012D470.local_type.local_1 = 0;
    D_8012D470.local_type.local_2[2] = 0;
    D_8012D470.local_type.local_2[1] = 0;
    D_8012D470.local_type.local_2[0] = 0;
    D_8012D470.local_type.local_5 = D_8012D470.local_type.local_8 = D_8012D470.local_type.local_7 = D_8012D470.local_type.local_9 = D_8012D470.local_type.local_10 = 0;
    D_8012D470.local_type.local_4 = D_8012D470.local_type.local_6 = 255;
    D_8012D470.local_type.local_3_2 = D_8012D470.local_type.local_4;
    D_8012D470.local_type.local_3_1 = D_8012D470.local_type.local_4;
    D_8012D470.local_type.local_3_0 = D_8012D470.local_type.local_4;
    D_8012D470.local_type.local_17 = D_8012D470.local_type.local_18 = 0;
    D_8012D470.local_type.local_11 = 20000;
    D_8012D470.local_type.local_12 = 0.0f;
    D_8012D470.local_type.local_13 = D_8012D470.local_type.local_14 = 1.0f;
    D_8012D470.local_type.local_15 = -10.0f;
}

int func_800E2434(unsigned int param_0)
{
  D_8012D490 = param_0;
}

int func_800E2440(s32 param_0, s32 param_1, s32 param_2)
{
  func_800F31DC(&D_8012D474, param_0 | 0, param_1, param_2 | 0);
}

void func_800E2478(s32 param_0) {
    func_800E24F8(param_0, param_0, param_0);
}

int func_800E249C(s32 param_0)
{
  D_8012D494 = param_0;
}

void func_800E24A8(f32 param_0)
{
  D_8012D4A4 = param_0;
}

int func_800E24B4(unsigned int param_0)
{
  D_8012D48F = param_0 ^ 0;
}

int func_800E24C0(unsigned long param_0)
{
  D_8012D492 = param_0 ^ 0;
}

int func_800E24CC(unsigned int param_0)
{
  D_8012D493 = param_0;
}

int func_800E24D8(unsigned int param_0)
{
  unsigned int new_var;
  new_var = param_0;
  D_8012D491 = new_var;
}

void func_800E24E4(s32 param_0, s32 param_1)
{
  *(s32*)((char*)((s32 *) &D_8012D470) + 0x78) = param_0;
  *(s32*)((char*)((s32 *) &D_8012D470) + 0x7c) = param_1;
}

int func_800E24F8(param_0, param_1, param_2) s32 param_0; s32 param_1; s32 param_2;
{
  func_800F31DC(&D_8012D480, param_0 | 0, param_1, param_2 | 0);
}

void func_800E2530(f32 param_0)
{
  D_8012D498 = param_0;
}

int func_800E253C(f32 param_0)
{
  int new_var;
  ((f32 *) &D_8012D470)[12] = param_0;
  new_var++;
  new_var = 12;
  new_var--;
  ((f32 *) &D_8012D470)[new_var] = ((f32 *) &D_8012D470)[12];
}

void func_800E2554(f32 param_0, f32 param_1)
{
  *(f32*)((s8*)((f32 *) &D_8012D470) + 44) = param_0;
  *(f32*)((s8*)((f32 *) &D_8012D470) + 48) = param_1;
}

void func_800E2568(s32 param_0, s32 param_1)
{
  *(s16*)((char*)((s16 *) &D_8012D470) + 0x0) = (s16)param_0;
  *(s16*)((char*)((s16 *) &D_8012D470) + 0x2) = (s16)param_1;
}

long func_800E257C(int param_0)
{
  D_8012D48C = param_0;
}

void func_800E2588(u32 param_0)
{
  D_8012D48E = param_0;
}

void func_800E2594(u32 param_0, ImageStruct *param_1)
{
    func_800E1DF4((DrawE *)param_0, param_1);
    gDma1p(((DrawE *)param_0)->local_0++, 0xDB, osVirtualToPhysical(func_800AF5D8(param_1)), 8, 6);
    gDma1p(((DrawE *)param_0)->local_0++, 0xDB, osVirtualToPhysical(func_800AF5E4(param_1)), 4, 6);
    D_8012D4F0 = param_1;
}

void func_800E2630(DrawE *param_0, s32 param_1, s32 param_2)
{
    FrameE *local_0;
    Gfx *local_1;
    if (param_2 != D_8012D470.StateE.local_4) {
        D_8012D470.StateE.local_4 = param_2;
        gDPSetPrimColor(param_0->local_0++, 0, 0, D_8012D470.StateE.local_3[0], D_8012D470.StateE.local_3[1], D_8012D470.StateE.local_3[2], D_8012D470.StateE.local_4);
    }
    func_800E204C(param_0, D_8012D470.StateE.local_19);
    local_0 = func_800AF5FC(D_8012D470.StateE.local_19, param_1);
    local_1 = func_800AF5F0(D_8012D470.StateE.local_19);
    local_1 += local_0->local_2;
    gDma1p(param_0->local_0++, 0xDE, osVirtualToPhysical(local_1), 0, 0);
    func_800E2260(param_0, D_8012D470.StateE.local_19);
}

s32 func_800E2720(DrawE *param_0, s32 param_1, s32 param_2, f32 *param_3, f32 *param_4, s32 param_5) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    Gfx *local_4;
    if (param_4) {
        local_0 = param_4[0];
        local_1 = param_4[1];
        local_2 = param_4[2];
    } else {
        local_0 = local_1 = local_2 = 1.0f;
    }
    if (!func_800E1C00(D_8012D4F0, param_3, local_0, local_1, local_3)) return 0;
    mlMtxSet(func_800E401C());
    if (((f32) D_8012D498) != 0.0f) mlMtxRotRoll(((f32) D_8012D498));
    func_800191F8(local_3[0], local_3[1], local_3[2]);
    if (param_4 || param_2) mlMtxScale_xyz(param_2 ? -local_0 : local_0, local_1, local_2);
    mlMtxApply(param_0->local_1);
    gDma2p(param_0->local_0++, 0xDA, param_0->local_1, sizeof(Mtx), 2, 0);
    param_0->local_1++;
    func_800E2630(param_0, param_1, param_5);
    gDma2p(param_0->local_0++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    return 1;
}

s32 func_800E28A4(DrawE *param_0, s32 param_1, s32 param_2, f32 *param_3, f32 *param_4, f32 *param_5, s32 param_6) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    Gfx *local_4;
    if (param_5) {
        local_0 = param_5[0];
        local_1 = param_5[1];
        local_2 = param_5[2];
    } else {
        local_0 = local_1 = local_2 = 1.0f;
    }
    if (!func_800E1C00(D_8012D4F0, param_3, local_0, local_1, local_3)) return 0;
    func_80019CD4();
    func_800191F8(local_3[0], local_3[1], local_3[2]);
    if (param_4) mlMtxRotatePYR(param_4[0], param_4[1], param_4[2]);
    if (param_5 || param_2) mlMtxScale_xyz(param_2 ? -local_0 : local_0, local_1, local_2);
    mlMtxApply(param_0->local_1);
    gDma2p(param_0->local_0++, 0xDA, param_0->local_1, sizeof(Mtx), 2, 0);
    param_0->local_1++;
    func_800E2630(param_0, param_1, param_6);
    gDma2p(param_0->local_0++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    return 1;
}

void func_800E2A14(s32 param_0)
{
  func_800E22F0(param_0, ((int) D_8012D4F0));
  D_8012D4F0 = 0;
}

void func_800E2A3C(s32 param_0, s32 param_1, s32 param_2) {
  func_800E1DF4(param_0, param_1);
  func_800E204C(param_0, param_1);
  func_800E2180(param_0, param_1, param_2);
  func_800E2260(param_0, param_1);
  func_800E22F0(param_0, param_1);
}

void func_800E2AA4(DrawE *param_0, s32 param_1, s32 param_2, s32 param_3, f32 *param_4, f32 *param_5) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    Gfx *local_4;
    if (param_5) {
        local_0 = param_5[0];
        local_1 = param_5[1];
        local_2 = param_5[2];
    } else {
        local_0 = local_1 = local_2 = 1.0f;
    }
    if (!func_800E1C00(param_1, param_4, local_0, local_1, local_3)) {
        func_800E23A4();
        return;
    }
    func_800E1DF4(param_0, param_1);
    mlMtxSet(func_800E401C());
    if (((f32) D_8012D498) != 0.0f) mlMtxRotRoll(((f32) D_8012D498));
    func_800191F8(local_3[0], local_3[1], local_3[2]);
    if (param_5 || param_3) mlMtxScale_xyz(param_3 ? -local_0 : local_0, local_1, local_2);
    mlMtxApply(param_0->local_1);
    gDma2p(param_0->local_0++, 0xDA, param_0->local_1, sizeof(Mtx), 2, 0);
    param_0->local_1++;
    func_800E204C(param_0, param_1);
    func_800E2180(param_0, param_1, param_2);
    func_800E2260(param_0, param_1);
    gDma2p(param_0->local_0++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    func_800E22F0(param_0, param_1);
}

void func_800E2C54(DrawE *param_0, s32 param_1, s32 param_2, s32 param_3, f32 *param_4, f32 *param_5, f32 *param_6) {
    f32 local_0;
    f32 local_1;
    f32 local_2;
    f32 local_3[3];
    Gfx *local_4;
    if (param_6) {
        local_0 = param_6[0];
        local_1 = param_6[1];
        local_2 = param_6[2];
    } else {
        local_0 = local_1 = local_2 = 1.0f;
    }
    if (!func_800E1C00(param_1, param_4, local_0, local_1, local_3)) {
        func_800E23A4();
        return;
    }
    func_800E1DF4(param_0, param_1);
    func_80019CD4();
    func_800191F8(local_3[0], local_3[1], local_3[2]);
    if (param_5) mlMtxRotatePYR(param_5[0], param_5[1], param_5[2]);
    if (param_6 || param_3) mlMtxScale_xyz(param_3 ? -local_0 : local_0, local_1, local_2);
    mlMtxApply(param_0->local_1);
    gDma2p(param_0->local_0++, 0xDA, param_0->local_1, sizeof(Mtx), 2, 0);
    param_0->local_1++;
    func_800E204C(param_0, param_1);
    func_800E2180(param_0, param_1, param_2);
    func_800E2260(param_0, param_1);
    gDma2p(param_0->local_0++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);
    func_800E22F0(param_0, param_1);
}

f32 func_800E2DF0(void)
{
  f32 local_1;
  local_1 = *((f32 *) (&((u8 *) &D_8012D470)[0x2C]));
  if (((u8 *) &D_8012D470)[0x23] != 0)
  {
    if (1)
    {
      local_1 *= 1.3333334f / func_800A8AF0(func_800A89F8());
    }
  }
  return local_1;
}

void func_800E2E48(DrawE *param_0, ImageE2E48 *param_1, s32 param_2, LocalPosition *param_3) {
    f32 local_0[3];
    f32 local_1, local_2;
    s32 local_3, local_4;
    f32 local_5;
    func_800E42F0(param_0, 0);
    func_800E1DF4(param_0, param_1);
    local_3 = D_8012D470.StateE2E48.local_0 ? D_8012D470.StateE2E48.local_0 : param_1->local_2 * 4;
    local_4 = D_8012D470.StateE2E48.local_1 ? D_8012D470.StateE2E48.local_1 : param_1->local_3 * 4;
    local_5 = func_800E2DF0();
    local_1 = (f32)local_5 * local_3 / param_1->local_2;
    local_2 = (f32)D_8012D470.StateE2E48.local_2 * local_4 / param_1->local_3;
    func_800EFA4C(local_0, param_3->local_0 - 0x260, 0x1C8 - param_3->local_1, D_8012D470.StateE2E48.local_3);
    func_80019CD4();
    func_800191F8(local_0[0], local_0[1], local_0[2]);
    if (D_8012D470.StateE2E48.local_4 != 0.0f) mlMtxRotRoll(D_8012D470.StateE2E48.local_4);
    if (local_3 != param_1->local_0 || local_4 != param_1->local_1 || local_5 != 1.0f || D_8012D470.StateE2E48.local_2 != 1.0f) {
        mlMtxScale_xyz((f32)local_1 * param_1->local_2 / param_1->local_0, (f32)local_2 * param_1->local_3 / param_1->local_1, 1.0f);
    }
    mlMtxApply(param_0->local_1);
    { Gfx *local_6 = param_0->local_0++; local_6->words.w0 = 0xDA380002; local_6->words.w1 = (u32)param_0->local_1; }
    param_0->local_1++;
    func_800E2180(param_0, param_1, param_2);
    { Gfx *local_7 = param_0->local_0++; local_7->words.w0 = 0xD8380002; local_7->words.w1 = 0x40; }
    func_800E22F0(param_0, param_1);
    func_800E4640(param_0);
}

void func_800E30E0(s32 param_0, void *param_1, s32 param_2, void *param_3)
{
    s32 local_0[3];
    FrameE *local_1;
    f32 local_2;
    s32 local_3, local_4;
    local_1 = func_800AF5FC(param_1, param_2);
    if (!local_1->local_0 && !local_1->local_1) {
        local_2 = func_800E2DF0();
        local_3 = D_8012D470.StateE.local_0 ? D_8012D470.StateE.local_0 : ((ImageStruct *)param_1)->unk8 * 4;
        local_4 = D_8012D470.StateE.local_1 ? D_8012D470.StateE.local_1 : ((ImageStruct *)param_1)->unkA * 4;
        local_0[0] = ((s32 *)param_3)[0] - local_2 * local_3 / 2;
        local_0[1] = ((s32 *)param_3)[1] - D_8012D470.StateE.local_14 * local_4 / 2;
    } else {
        local_0[0] = ((s32 *)param_3)[0];
        local_0[1] = ((s32 *)param_3)[1];
    }
    func_800E2E48(param_0, param_1, param_2, local_0);
}

void func_800E3220(s32 **param_0, s32 param_1)
{
  s32 *local_0;
  s32 *local_1;
  s32 *local_2;
  s32 *local_3;
  func_800E1DF4();
  local_0 = *param_0;
  *param_0 = (*param_0) + 2;
  *local_0 = 0xDB060008;
  local_2 = local_0;
  *((s32 **) (4 + ((u8 *) local_2))) = osVirtualToPhysical(func_800AF5D8(param_1));
  local_1 = *param_0;
  *param_0 = (*param_0) + 2;
  *local_1 = 0xDB060004;
  local_3 = local_1;
  *((s32 **) (((u8 *) local_3) + 4)) = osVirtualToPhysical(func_800AF5E4(param_1));
  D_8012D4F4 = param_1;
  func_800E42F0(param_0, 0);
}

void func_800E32CC(DrawE *param_0, s32 param_1, LocalPosition *param_2, s32 param_3) {
    FrameE32CC *local_0;
    f32 local_1[3];
    f32 local_2, local_3;
    s32 local_4, local_5;
    Gfx *local_6;
    local_0 = func_800AF5FC(D_8012D470.StateE32CC.local_7, param_1);
    if (param_3 != D_8012D470.StateE32CC.local_3) {
        D_8012D470.StateE32CC.local_3 = param_3;
        gDPSetPrimColor(param_0->local_0++, 0, 0, D_8012D470.StateE32CC.local_2[0], D_8012D470.StateE32CC.local_2[1], D_8012D470.StateE32CC.local_2[2], D_8012D470.StateE32CC.local_3);
    }
    local_4 = D_8012D470.StateE32CC.local_0 ? D_8012D470.StateE32CC.local_0 : D_8012D470.StateE32CC.local_7->local_2 * 4;
    local_5 = D_8012D470.StateE32CC.local_1 ? D_8012D470.StateE32CC.local_1 : D_8012D470.StateE32CC.local_7->local_3 * 4;
    local_2 = (f32)D_8012D470.StateE32CC.local_5 * local_4 / D_8012D470.StateE32CC.local_7->local_2;
    local_3 = (f32)D_8012D470.StateE32CC.local_6 * local_5 / D_8012D470.StateE32CC.local_7->local_3;
    func_800EFA4C(local_1, local_0->local_0 * local_2 + (param_2->local_0 - 0x260), (0x1C8 - param_2->local_1) - local_0->local_1 * local_3, -10.0f);
    func_80019CD4();
    func_800191F8(local_1[0], local_1[1], local_1[2]);
    if (D_8012D470.StateE32CC.local_4 != 0.0f) mlMtxRotRoll(D_8012D470.StateE32CC.local_4);
    if (local_4 != D_8012D470.StateE32CC.local_7->local_0 || local_5 != D_8012D470.StateE32CC.local_7->local_1 || (f32)D_8012D470.StateE32CC.local_5 != 1.0f || (f32)D_8012D470.StateE32CC.local_6 != 1.0f) {
        mlMtxScale_xyz((f32)local_2 * D_8012D470.StateE32CC.local_7->local_2 / D_8012D470.StateE32CC.local_7->local_0, (f32)local_3 * D_8012D470.StateE32CC.local_7->local_3 / D_8012D470.StateE32CC.local_7->local_1, 1.0f);
    }
    mlMtxApply(param_0->local_1);
    gDma2p(param_0->local_0++, 0xDA, param_0->local_1, sizeof(Mtx), 2, 0);
    param_0->local_1++;
    local_6 = func_800AF5F0(D_8012D470.StateE32CC.local_7);
    local_6 += *(s16 *)((u8 *)local_0 + 4);
    gDma1p(param_0->local_0++, 0xDE, osVirtualToPhysical(local_6), 0, 0);
    gDma2p(param_0->local_0++, 0xD8, sizeof(Mtx), sizeof(Mtx), 2, 0);

}

void func_800E35E0(void *param_0, s32 param_1, s32 *param_2, s32 param_3)
{
    s32 local_1;
    s32 local_0[3];
    s32 local_2;
    local_1 = D_8012D470.StateE.local_0 ? D_8012D470.StateE.local_0 : D_8012D470.StateE.local_20->unk8 * 4;
    local_2 = D_8012D470.StateE.local_1 ? D_8012D470.StateE.local_1 : D_8012D470.StateE.local_20->unkA * 4;
    local_0[0] = param_2[0] - local_1 / 2;
    local_0[1] = param_2[1] - local_2 / 2;
    func_800E32CC(param_0, param_1, local_0, param_3);
}

s32 func_800E368C(s32 param_0){
    func_800E22F0(param_0, ((s32) D_8012D4F4));
    D_8012D4F4 = 0;
    func_800E4640(param_0);
}
