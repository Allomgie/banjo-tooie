#include <ultra64.h>
#include "gfx.h"
#include "core2/1E99980.h"

#define SCREEN_WIDTH 304
#define SCREEN_HEIGHT 224
extern void _gcdialogexec_entrypoint_7();
extern void _gczoombox_entrypoint_2(s32 param_0, s32 param_1);
extern s32 D_80128A18;
extern u8 D_801288B8[];
extern void *D_801289DC;
extern void _gcdialogexec_entrypoint_10(void *arg);
extern void _gczoombox_entrypoint_4(void *arg);
typedef struct { u8 pad0[0x120]; void *box[2]; s16 x[2]; u8 pad12C[0x30]; u32 unused:18; u32 busy:1; u32 opening:1; u32 unused2:12; u8 pad160[6]; s8 step; } LocalDialog;
extern s8 D_8011A7C0[];
extern void _gczoombox_entrypoint_38(void *, s32);
typedef struct { u32 f0 : 18; u32 fX : 1; u32 f2 : 13; } G_C0438;
extern G_C0438 D_80128A0C;
extern u8 D_80128A11;
extern s32 func_800A819C(void);
extern void _gcdialogexec_entrypoint_1();
extern u8 D_80128A30[192];
extern s32 _gcdialogexec_entrypoint_0(u32 *, u32, u32, f32 *, Unk80132ED0 *, s32, s32, s32, s32);
extern s16 D_80128A12;
extern s32 _gcdialogexec_entrypoint_6(void *arg, s32 param_1);
typedef struct { u8 pad_0[0x15E]; u8 local_0 : 2; u8 local_1 : 1; u8 local_2 : 1; u8 local_3 : 4; u8 pad_15F[7]; s8 local_4; } Struct800C06C4;
extern u32 func_800C7150();
extern u32 defrag();
extern s32 D_80128AF0;
extern s32 D_8011A7D0;
extern u8 D_8012762C;
extern void *func_80014F00(void);
extern int D_80128B00;
s32 func_800C0638();
int func_800C0F8C();
void func_800C0FD8();
int func_800C1044();

/* Objekt, kein Zeiger: das Ziel materialisiert ueberall %hi/%lo der
   Adresse. Als Array meinen alle Zugriffsformen dieser TU dasselbe. */
extern u8 D_801288B0[];
void func_800C0658();
extern s32 D_80128AF4;

s32 func_800C0090(s32 param_0, s32 param_1) {
    s32 ret;
    if (param_1 == -1) {
        ret = 0;
    } else {
        ret = (param_1 == ((u32)*(u16 *)(param_0 + 0x12) >> 1));
    }
    return ret;
}

void func_800C00BC()
{
    _gcdialogDll_entrypoint_0(&D_801288B0);
}

void func_800C00E0(void)
{
  if (func_800C0638())
  {
    func_800FECB8(0);
  }
  func_800C0658();
  _gcdialogexec_entrypoint_7(((s32 *) D_801288B0));
  *(u8 *)((u8 *)((s32 *) D_801288B0) + 0x15C) = 0;
  *(u8 *)((u8 *)((s32 *) D_801288B0) + 0x180) = 0;
}

void func_800C0130(s32 param_0)
{
  s32 *s0;
  s32 *s1;
  s32 *s2;
 s0 = ((s32 *) D_801288B0); s1 = ((s32 *) D_801288B8);
  s2 = (s32 *) param_0;
  do
  {
    if (s0[0x48] != 0)
    {
      _gczoombox_entrypoint_2(s0[0x48], (s32) s2);
    }
    s0++;
  }
  while (s0 != s1);
  if (((s32) D_801289DC) != 0)
  {
    _gczoombox_entrypoint_2(((s32) D_801289DC), (s32) s2);
  }
}

int func_800C01A8(param_0, param_1) s16 param_0; s32 param_1;
{
  _gcdialogcamera_entrypoint_10(((s32 *) D_801288B0), param_0, param_1 | 0);
}

int func_800C01D8(s32 param_0, s32 param_1) { return _gcdialogexec_entrypoint_5(((s32 *) D_801288B0), param_0, param_1); }

int func_800C0208()
{
  s32 field_168 = ((s32 *)&D_801288B0)[0x168 / 4];

  if (field_168 == 0) {
    return 0;
  }

  if (func_800C0090(field_168, ((s32 *)&D_801288B0)[0x16C / 4]) != 0) {
    return D_80128A18;
  }

  return 0;
}

s16 func_800C0258(void)
{
  u32 base = (u32) D_801288B0;
  u32 var1 = (*((u16 *) (base + 0x15E))) & 0xFFFF;
  u32 offset = (var1 >> 15) << 1;
  return (s16) ((*((s16 *) ((base + 0x118) + offset))) + 0xC);
}

void func_800C0284()
{
  u8 *s0;
  u8 *s1;
  if ((*((u8 *) &D_80128A0C)) != 0)
  {
    _gcdialogexec_entrypoint_10(&D_801288B0);
  }
  for (s0 = D_801288B0, s1 = D_801288B8; ; )
  {
    void *val = *(void **)(s0 + 0x120);
    if (val != 0)
    {
      _gczoombox_entrypoint_4(val);
    }
    s0 += 4;
    if (s0 != s1)
    {
      continue;
    }
    break;
  }

  if (D_801289DC != 0)
  {
    _gczoombox_entrypoint_4((void *)D_801289DC);
  }
}

void func_800C0308(void)
{
    s32 local_0;
    if ((*((LocalDialog *) D_801288B0)).opening) {
        (*((LocalDialog *) D_801288B0)).step++;
        local_0 = D_8011A7C0[(*((LocalDialog *) D_801288B0)).step];
        if ((*((LocalDialog *) D_801288B0)).box[0]) {
            (*((LocalDialog *) D_801288B0)).x[0] -= local_0;
            _gczoombox_entrypoint_38((*((LocalDialog *) D_801288B0)).box[0], (*((LocalDialog *) D_801288B0)).x[0]);
        }
        if ((*((LocalDialog *) D_801288B0)).box[1]) {
            (*((LocalDialog *) D_801288B0)).x[1] += local_0;
            _gczoombox_entrypoint_38((*((LocalDialog *) D_801288B0)).box[1], (*((LocalDialog *) D_801288B0)).x[1]);
        }
        if ((*((LocalDialog *) D_801288B0)).step == 12) (*((LocalDialog *) D_801288B0)).busy = 0;
    } else {
        (*((LocalDialog *) D_801288B0)).step--;
        local_0 = D_8011A7C0[(*((LocalDialog *) D_801288B0)).step];
        if ((*((LocalDialog *) D_801288B0)).box[0]) {
            (*((LocalDialog *) D_801288B0)).x[0] += local_0;
            _gczoombox_entrypoint_38((*((LocalDialog *) D_801288B0)).box[0], (*((LocalDialog *) D_801288B0)).x[0]);
        }
        if ((*((LocalDialog *) D_801288B0)).box[1]) {
            (*((LocalDialog *) D_801288B0)).x[1] -= local_0;
            _gczoombox_entrypoint_38((*((LocalDialog *) D_801288B0)).box[1], (*((LocalDialog *) D_801288B0)).x[1]);
        }
        if ((*((LocalDialog *) D_801288B0)).step == 0) (*((LocalDialog *) D_801288B0)).busy = 0;
    }
}

void func_800C0438(void) {
    if (D_80128A0C.fX) { func_800C0308(); }
    if (func_800A819C() != 0) {
        if (!D_80128A0C.fX) {
            if ((func_800C0638() == 0) && ((s32)((u32)D_80128A11 >> 4) > 0)) {
                _gcdialogexec_entrypoint_1(D_801288B0);
            } else {
                func_800C0284();
            }
        }
    }
}

s32 func_800C04C8(s32 param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4)
{
  s32 local_0;

  if (*(u8 *)((int *) D_80128A30) != 0)
  {
    local_0 = _gcdialogexec_entrypoint_3(((int *) D_801288B0), param_0, param_1, param_2, param_3, param_4);
  }
  else
  {
    local_0 = 0;
  }
  return local_0;
}

u32 func_800C0534(u32 param_0, u32 param_1, f32 *param_2, Unk80132ED0 *param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7)
{
  u32 *local_0;
  s32 local_1;
  short local_2;
  local_2 = param_7;
  if (D_80128A30[0 & 0xFF] != 0)
  {
    local_0 = ((u32 *) D_801288B0);
    local_1 = _gcdialogexec_entrypoint_0(local_0, param_0, param_1, param_2, param_3, param_4, param_5, param_6, local_2);
  }
  else
  {
    local_1 = 0;
  }
  return local_1;
}

s32 func_800C05B8(s16 param_0, s32 param_1, f32 *param_2, Unk80132ED0 *param_3, s32 param_4, s32 param_5, s32 param_6)
{
    s32 local_1;
    if ((*((u8 *) D_80128A30)) != 0) {
        local_1 = _gcdialogexec_entrypoint_0(((u32 *) D_801288B0), *(s32 *)((u8 *)&param_0 - 2), param_1, param_2, param_3, param_4, param_5, 0, *(s16 *)((u8 *)&param_6 + 2));
    } else {
        local_1 = 0;
    }
    return local_1;
}

s32 func_800C0638()
{
  return D_80128A12 != ((unsigned long) ((float) (-0x7FFF)));
}

s32 func_800C064C()
{
  return D_80128A12;
}

void func_800C0658()
{
    _gcdialogexec_entrypoint_2(&D_801288B0);
}

s32 func_800C067C(s32 param_0)
{
    s32 local_0;
    s32 local_1;

    local_1 = func_800C064C();
    if (local_1 != param_0) {
        return 0;
    }
    _gcdialogexec_entrypoint_6((void *)((void * *) D_801288B0), 6);
    local_0 = 1;
    return local_0;
}

void func_800C06C4(void)
{
    if (func_800C0638() != 0) {
        (*((Struct800C06C4 *) D_801288B0)).local_1 = 1;
        (*((Struct800C06C4 *) D_801288B0)).local_2 = 0;
        (*((Struct800C06C4 *) D_801288B0)).local_4++;
    }
}

void func_800C0710(void)
{
  if (func_800C0638())
  {
    (*((Struct800C06C4 *) D_801288B0)).local_1 = 1;
    (*((Struct800C06C4 *) D_801288B0)).local_2 = 1;
    (*((Struct800C06C4 *) D_801288B0)).local_4--;
  }
}

void func_800C075C(void) {
    s32 local_0;
    for (local_0 = 0; local_0 < 2; local_0++) {
        if (((u32 *) D_801288B0)[0x48 + local_0]) ((u32 *) D_801288B0)[0x48 + local_0] = func_800C7150(((u32 *) D_801288B0)[0x48 + local_0]);
        if (((u32 *) D_801288B0)[0x4B]) ((u32 *) D_801288B0)[0x4B] = func_800C7150(((u32 *) D_801288B0)[0x4B]);
        if (((u32 *) D_801288B0)[0x41 + local_0]) ((u32 *) D_801288B0)[0x41 + local_0] = defrag(((u32 *) D_801288B0)[0x41 + local_0]);
    }
}

int func_800C07F4()
{
  return ((u32)(*((int *) &D_80128A0C)) << 21) >> 31;
}

void func_800C0808()
{
    _gcdialogexec_entrypoint_8(&D_801288B0);
}

void func_800C082C(unsigned int param_0)
{
  int new_var;
  D_801288B0[0x15E] = (D_801288B0[0x15E] & 0xFFF7) | ((new_var = (param_0 & 0xFFFFu) * 8) & 8);
}

void func_800C0850()
{
  ((unsigned char *) D_801288B0)[0x11C] &= ~0xC0;
  ((unsigned char *) D_801288B0)[0x11D] &= ~0xC0;
  _gcdialogexec_entrypoint_6(((unsigned char *) D_801288B0), 6);
}

int func_800C0890(s32 param_0, s32 param_1)
{
  _gcdialogexec_entrypoint_9(((s32 *) D_801288B0), param_0 | 0, param_1 | 0);
}

int func_800C08C0()
{
  if (D_80128AF0 != 0)
  {
    D_80128AF0 = defrag(D_80128AF0);
  }
}

void func_800C08F8()
{
  D_80128AF0 = _gcnewpause_entrypoint_0(D_80128AF4);
}

void func_800C0920()
{
  _gcnewpause_entrypoint_1(D_80128AF0);
  D_80128AF0 = 0;
}

s32 func_800C0948()
{
  s32 local_0;
  if (D_80128AF0 != 0) {
    local_0 = _gcnewpause_entrypoint_2(D_80128AF0);
    local_0 |= 0;
  } else {
    local_0 = 0;
  }
  return local_0;
}

void func_800C0984(s32 param_0) {
    if (func_800A8184() != 4) {
        if (D_8011A7D0 == 0) {
            func_800C1044(param_0);
        }
        D_8011A7D0 = 1;
        return;
    }
    if (func_800A8178() == 0) {
        if (D_8011A7D0 != 0) {
            func_800D58CC();
            func_800C0F8C(param_0);
            D_8011A7D0 = 0;
        } else {
            func_800C0FD8(param_0);
        }
        if (D_80128AF0 != 0) {
            _gcnewpause_entrypoint_3(param_0, D_80128AF0);
        }
    }
}

void func_800C0A2C(void) {
}

s32 func_800C0A34(void)
{
  s32 local_4;
  s32 local_2;
  s32 Struct800C06C4;
  s32 local_6;
  local_4 = D_8012762C != 0 && func_800C95D4() != 0 && !func_800C9510() && !func_800C0638();
  if (func_800D3948() == 0)
  {
    local_2 = func_800F54E4();
    Struct800C06C4 = func_800F6438(local_2) != 0 && !func_800DB9B0();
    local_4 &= Struct800C06C4;
    if (((local_4) && (func_800F6774(local_2) != 0)) && (func_80015FA0(0) == 1))
    {
      D_80128AF4 = 0;
      return 1;
    }
    goto block_21;
  }
  if (local_4 != 0)
  {
    s32 local_0;
    s32 local_3;
    local_0 = _gcstatusDll_entrypoint_11();
    local_6 = func_800DA298(0x6B6) != 0 && !func_800DA298(0x6E3);
    local_3 = 0;
    if (local_0 > 0)
    {
      loop_15:
      if ((func_80015FA0(local_3) == 1) && ((local_6 != 0) || ((func_800F6438(local_3) != 0) && (func_800F6774(local_3) != 0))))
      {
        D_80128AF4 = local_3;
        return 1;
      }

      local_3 += 1;
      if (local_3 == local_0)
      {
        goto block_21;
      }
      goto loop_15;
    }
    goto block_21;
  }
  block_21:
  return 0;
}

s32 func_800C0BB4()
{
    return D_80128AF4;
}

// Probably a file split here based on bk decomp and bss (D_80128AF4)

extern Gfx D_8011A7E0[];
extern Gfx D_8011A840[];

#define ROUND_UP_DIVIDE(x, y) (((x) + (y) - 1) / (y))

#if 0
// Scratch: https://decomp.me/scratch/iFD8T
// Much higher percent scratch with expanded macros: https://decomp.me/scratch/cyGKA

// copy_framebuffer
void func_800C0BC0(Gfx** gfx, void* destination, void* source) {
    s32 row;
    s32 col;
    Gfx* cur_gfx = *gfx;
    
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A7E0));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(destination));
    
    for (row = 0; row < ROUND_UP_DIVIDE(SCREEN_HEIGHT, 32); row++) {
        for (col = 0; col < ROUND_UP_DIVIDE(SCREEN_WIDTH, 32); col++) {
            gDPLoadTextureTile(cur_gfx++, osVirtualToPhysical(source), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                (col * 32), (row * 32), ((col + 1) * 32 - 1), ((row + 1) * 32 - 1), 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(cur_gfx++,
                (col * 32) * 4, (row * 32) * 4,
                ((col + 1) * 32) * 4, ((row + 1) * 32) * 4,
                0,
                (col * 32) << 5, (row * 32) << 5,
                1 << 10, 1 << 10);
        }
    }
    
    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A840));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(func_80014F00()));
    
    *gfx = cur_gfx;
}
#else
void func_800C0BC0(Gfx **gfx, void *destination, void *source) {
    s32 row;
    s32 col;
    Gfx *cur_gfx = *gfx;

    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A7E0));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(destination));

    for (row = 0; row < SCREEN_HEIGHT / 32 + 1; row++) {
        for (col = 0; col < SCREEN_WIDTH / 32 + 1; col++) {
            gDPLoadTextureTile(
                cur_gfx++, osVirtualToPhysical(source), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, SCREEN_HEIGHT,
                (col * 32), (row * 32), ((col + 1) * 32 - 1), ((row + 1) * 32 - 1), 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            gSPScisTextureRectangle(
                cur_gfx++,
                (col * 32) * 4, (row * 32) * 4,
                ((col + 1) * 32) * 4, ((row + 1) * 32) * 4,
                0,
                (col * 32) << 5, (row * 32) << 5,
                1 << 10, 1 << 10);
        }
    }

    gSPDisplayList(cur_gfx++, OS_K0_TO_PHYSICAL(D_8011A840));
    gDPSetColorImage(cur_gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_PHYSICAL_TO_K0(func_80014F00()));

    *gfx = cur_gfx;
}
#endif

int func_800C0F8C(param_0) s32 param_0;
{
  int new_var;
  s32 local_0;
  new_var = 0;
  func_800EA34C(new_var);
  D_80128B00 = 2;
  local_0 = func_8001A0A8();
  func_800C0BC0(param_0, local_0, (void *) ((s32) func_80014F00() | 0));
}

void func_800C0FD8(param_0) s32 param_0;
{
  int pad;
  s32 new_var;
  ;
  if (!((s32) D_80128B00))
  {
    func_800D6E54(2);
    func_800FFD10(2);
  }
  else
  {
    ((s32) D_80128B00)--;
  }
  new_var = func_80014F00();
  func_800C0BC0(param_0, new_var, func_8001A0A8());
}

int func_800C1044(param_0) s32 param_0;
{
  func_800EA34C(1);
}
