#include "types.h"
#include "gfx.h"
#include "threads.h"
#include "common.h"

extern u32 *D_80078F70[];
extern void *heap_alloc_sided(s32, s32);
extern s32 D_80078F88;
extern s16 D_80078F62;
extern s16 D_80078F60;
typedef struct { OSMesgQueue *local_0; OSMesg local_1; } Struct80014FE8;
extern OSThread D_80079140;
extern OSMesgQueue D_80078FD0;
extern OSMesgQueue D_80079010;
extern OSMesgQueue D_80079030;
extern OSMesg D_80079048[];
extern s32 D_80079700;
extern u16 D_80078F64;
extern volatile s32 D_80079138;
extern void *D_80078F68;
extern void *D_8003F530;
extern void *D_8003F4E0;
extern OSMesg D_80078FE8[10];
extern OSMesg D_80079028[1];
extern __OSThreadOddFpStorage D_800792F0;
extern s32 osTvType;
extern s32 D_8007913C;
extern s32 D_80079704;
extern s32 func_80015184(void);
extern s32 func_80013474(void);
extern s32 func_80081D28(void);
extern void* D_80078F80[];
typedef struct { OSMesgQueue *queue; OSMesg msg; } Pair_F90;
extern s32 D_8003F5D0;
extern Pair_F90 D_80078F90[8];
extern void *D_80078F84;
extern void aligned8_memset(void *dst, int val, int len);
extern void osWritebackDCache(void *addr, s32 size);
extern s16 D_80079778[0x20];
extern s16 D_8003F5E0;
extern u8 D_80079710[8];
typedef struct { s32 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; } Struct8001592C_0;
typedef struct { s16 local_0; s16 local_1; s16 local_2; s16 local_3; s16 local_4; s16 local_5; s16 local_6; s16 local_7; } Struct8001592C_1;
extern Struct8001592C_0 D_80079718[];
extern Struct8001592C_1 D_800797B8[];
typedef struct { s16 f0, f2, f4, f6, f8, fA, fC, fE; } TileEntry;
extern void func_800CA510(s32, f32);
extern f32 D_80041710;
extern s16 widescreen_enabled;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
s32 func_80014F38();
s16 func_80014F58();
void func_80015178();
void func_8001546C();
f32 func_80015D14(OSLogItem *param_0);

extern s32 D_80078F88;
extern s32 D_8007913C;
extern OSMesgQueue D_80079010;

u32 *func_80014E10(s32 param_0, s32 param_1)
{
  u32 *local_0;
  char *local_4;
  local_0 = (u32 *)heap_alloc_sided(param_1 + 0x40, 1);
  D_80078F70[param_0] = local_0;
  local_4 = (char *)local_0;
  while ((u32)local_4 & 0x3F)
  {
    local_4++;
  }
  return (u32 *)local_4;
}

void func_80014E6C()
{
  (*((int *) D_80078F80)) = func_80014E10(0, 0x21D80);
  D_80078F84 = func_80014E10(1, 0x21D80);
  D_80078F88 = func_80014E10(2, 0x10EC0);
}

// get_framebuffer_size_bytes
u32 func_80014EC8() {
    return FRAMEBUFFER_SIZE_BYTES;
}

int func_80014ED4()
{
    int idx = func_80014F38();
    return ((int *) D_80078F80)[idx];
}

s32 func_80014F00()
{
  u16 local_0;
  ;
  return ((s32 *) D_80078F80)[D_80078F62 ^ func_80014F58()];
}

s32 func_80014F38(void)
{
  return D_80078F60 ^ 1;
}

int func_80014F4C(void)
{
    return (*((s16 *) &D_80078F64));
}

s16 func_80014F58()
{
  return D_80078F60;
}

// register_vi_handler
void func_80014F64(OSMesgQueue* queue, OSMesg mesg) {
    s32 i;
    for (i = 0; i < ARRLEN(D_80078F90); i++) {
        if (D_80078F90[i].queue == NULL) {
            D_80078F90[i].queue = queue;
            D_80078F90[i].msg = mesg;
            return;
        }
    }
}

void func_80014FE8(void)
{
    s32 local_0;

    osCreateViManager(0xFE);
    switch (osTvType) {
        case 0:
        case 1:
            D_80078F68 = &D_8003F4E0;
            break;
        case 2:
            D_80078F68 = &D_8003F530;
            break;
    }
    osViSetMode(D_80078F68);
    osViBlack(1);
    D_80079700 = 1;
    osViSetSpecialFeatures(0x40);
    osViSetSpecialFeatures(2);
    osViSetSpecialFeatures(0x20);
    osCreateMesgQueue(&D_80078FD0, D_80078FE8, 10);
    osCreateMesgQueue(&D_80079010, D_80079028, 1);
    osCreateMesgQueue(&D_80079030, D_80079048, 60);
    osViSetEvent(&D_80078FD0, NULL, 1);
    (*((u16 *) &D_80078F60)) = 0;
    D_80078F64 = 1;
    for (local_0 = 0; local_0 < 8; local_0++) {
        ((Struct80014FE8 *) D_80078F90)[local_0].local_0 = NULL;
    }
    D_80079138 = 0;
    func_80015178(2);
    func_8001DCB0(&D_80079140, &D_800792F0, 0, func_8001546C,
        NULL, &D_80079700, 0x50);
    osStartThread(&D_80079140);
}

void func_80015178(param_0) s32 param_0;
{
    D_8007913C = param_0;
    return;
}

s32 func_80015184()
{
    return D_8007913C;
}

void func_80015190(void) 
{
    osSendMesg(&D_80079010, NULL, 0);
}

void func_800151BC(s32 param_0)
{
  void *fb;
  s32 *new_var;
  osSetThreadPri(0, 0x7F);
  func_80013500(0x23);
  func_80013488();
  if (param_0 != 0)
  {
    osRecvMesg(&D_80079010, 0, 1);
  }
  while (D_80079138 < (func_80015184() - D_80079704))
  {
    osRecvMesg(&D_80079030, 0, 1);
  }

  while ((*((s32 *) (((u8 *) (&D_80079030)) + 8))) != 0)
  {
    osRecvMesg(&D_80079030, 0, 0);
  }

  if ((*((volatile s16 *) &D_80078F62)) == 0)
  {
    if (D_80079700 != 0)
    {
      D_80079700--;
      if (D_80079700 == 0)
      {
        osViBlack(0);
      }
    }
    D_80078F60 = func_80014F38();
    osViSwapBuffer((void *) ((u32 *) D_80078F80)[D_80078F60]);
    new_var = &D_80079704;
    D_80079704 = 0;
    if (!(osDpGetStatus() & 2))
    {
      fb = osViGetCurrentFramebuffer();
      if (osViGetNextFramebuffer() != fb)
      {
        if (!D_80079704)
        {
        }
        do
        {
          osRecvMesg(&D_80079030, 0, 1);
          D_80079704 = (*new_var) + 1;
          if (osDpGetStatus() & 2)
          {
            break;
          }
          fb = osViGetCurrentFramebuffer();
        }
        while (osViGetNextFramebuffer() != fb);
      }
    }
  }
  else
  {
    (*((volatile s16 *) &D_80078F62)) = 0;
  }
  D_80078F64 = D_80079138;
  D_80079138 = 0;
  func_800134C4();
  osSetThreadPri(0, 0x14);
  if ((func_80013474() == 0) && (func_80081D28() != 0))
  {
    do
    {
      osYieldThread();
    }
    while ((func_80013474() == 0) && (func_80081D28() != 0));
  }
  func_80013500(0xA);
}

void func_80015410()
{
    func_800151BC(0x1);
}

void func_80015430(unsigned int param_0)
{
  unsigned short var;
  void **new_var;
  void **new_var2;
  D_80078F60 = param_0;
  ;
  new_var2 = D_80078F80;
  new_var = new_var2;
  osViSwapBuffer(new_var[D_80078F60 ^ 0]);
}

void func_8001546C(param_0) s32 param_0; {
    s32 hit;
    OSMesg sp50;
    s32 rv;
    s32 rv2;
    s32 i;

    while (1) {
        osRecvMesg(&D_80078FD0, &sp50, 1);
        func_80014A54();
        if (1) {
            D_80079138++;
            hit = (D_80079138 == 0x258);
            rv = (func_8001E7C0() == 0);
        }
        rv2 = D_8003F5D0;
        if (((hit != 0) && (rv != 0)) && (rv2 != 0)) {
            func_8001E5DC(2);
            D_8003F5D0 = 0;
        }
        osSendMesg(&D_80079030, NULL, 0);
        for (i = 0; i < 8; i++) {
            if (D_80078F90[i].queue != NULL) {
                osSendMesg(D_80078F90[i].queue, D_80078F90[i].msg, 0);
            }
        }
    }
}

int func_8001559C(long param_0)
{
  osViBlack(param_0);
}

void func_800155BC()
{
    if ((*((void * *) D_80078F80)) != 0)
    {
        aligned8_memset((*((void * *) D_80078F80)), 0x10001, 0x21D80);
        osWritebackDCache((*((void * *) D_80078F80)), 0x21D80);
    }
    if (D_80078F84 != 0)
    {
        aligned8_memset(D_80078F84, 0x10001, 0x21D80);
        osWritebackDCache(D_80078F84, 0x21D80);
    }
    if ((*((void * *) &D_80078F88)) != 0)
    {
        aligned8_memset((*((void * *) &D_80078F88)), 0x10001, 0x10EC0);
        osWritebackDCache((*((void * *) &D_80078F88)), 0x10EC0);
    }
}

void func_80015670(s32 param_0, s32 param_1)
{
  u8 *local_2 = ((u8 *) D_80078F68) + 0x30;
  u8 *local_3 = ((u8 *) D_80078F68) + 0x44;
  u8 *local_1 = ((u8 *) D_80078F68) + 0x1C;
  s32 local_0;
  u8 *local_4 = ((u8 *) D_80078F68) + 0x30;
  u8 *local_5 = ((u8 *) D_80078F68) + 0x32;
  if (param_0 < (-0x20))
  {
    param_0 = -0x20;
  }
  else
    if (param_0 >= 0x21)
  {
    param_0 = 0x20;
  }
  if (param_1 < (-0x28))
  {
    param_1 = -0x28;
  }
  else
    if (param_1 >= 0x19)
  {
    param_1 = 0x18;
  }
  local_0 = osSetIntMask(0x80401);
  *((s16 *) (local_1 + 0)) = param_0 + 0x80;
  *((s16 *) (local_1 + 2)) = param_0 + 0x2E0;
  *((s16 *) (local_4 + 0)) = param_1 + 0x30;
  *((s16 *) (local_5 + 0)) = param_1 + 0x1F4;
  *((s32 *) (local_3 + 0)) = *((s32 *) (local_2 + 0));
  osSetIntMask(local_0);
}

s32 func_8001575C()
{
    return D_80078F88;
}

int func_80015768()
{
  D_80078F62 = 1;
}

void wait_one_frame(void) {
    while (osViGetCurrentLine() < 5) {
    }
    while (osViGetCurrentLine() > 5) { 
    }
}

void set_widescreen(s32 enabled) {
    widescreen_enabled = enabled;
}

void func_800157EC(s32 *param_0, u8 **param_1)
{
  u8 *new_var;
  u8 *temp_v1;
  new_var = (temp_v1 = ((u32 *) D_800797B8));
  temp_v1 = *param_1;
  if (1)
  {
    *param_1 += 8;
    *((s32 *) (((s8 *) temp_v1) + 0)) = 0xDC080008;
    *((u8 **) (((s8 *) temp_v1) + 4)) = (u8 *) (((((*param_0) * (4 ^ 0)) * 4) + 0x80000000) + new_var);
  }
}

s32 func_80015828(void)
{
  s32 i;
  s16 val;
  for (i = 0; i < 0x20; i++)
  {
    val = D_80079778[i];
    if (D_80079778[i] == 0)
    {
      break;
    }
  }

  D_80079778[i] = -1;
  return i;
}

void func_80015860(s32 param_0)
{
    ((u16 *) D_80079778)[param_0] = 1;
    return;
}

void func_80015878(void)
{
  s16 *local_0;
  s16 *local_1;
 do { local_0 = ((s16 *) D_80079778); local_1 = ((s16 *) D_800797B8); local_1 += 0; local_0 = ((s16 *) D_80079778); local_loop: { if (local_0[0] > 0) { local_0[0] = 0; } if (local_0[1] > 0) { local_0[1] = 0; } if (local_0[2] > 0) { local_0[2] = 0; } if (local_0[3] > 0) { local_0[3] = 0; } local_0 += 4; } } while (0);
  if (local_0 != local_1)
  {
    goto local_loop;
  }
  D_8003F5E0 = -1;
}

void func_800158E4(s32 *param_0)
{
    func_80015860(*param_0);
    *(u8 *)((char *)D_80079710 + ((s32)param_0 - (s32)((u8 *) D_80079718)) / 12) = 0;
}

Struct8001592C_0 *func_8001592C(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  s32 local_0;
  Struct8001592C_0 *local_1;
  Struct8001592C_1 *local_2;
 local_0 = 0; while (1) {
    if (D_80079710[local_0] != 0)
    {
      local_0++;
      if (local_0 == 8)
      {
        break;
      }
    }
    else
    {
      break;
    }
  }

  D_80079710[local_0] = 1;
  local_1 = &D_80079718[local_0];
  local_1->local_0 = func_80015828();
  local_1->local_1 = param_0;
  local_1->local_2 = param_1;
  local_1->local_3 = param_2;
  local_1->local_4 = param_3;
  local_2 = &D_800797B8[local_1->local_0];
  local_2->local_0 = param_2 * 2;
  local_2->local_1 = param_3 * 2;
  local_2->local_2 = 0x1FF;
  local_2->local_3 = 0;
  local_2->local_4 = (s32) ((param_0 + (param_2 * 0.5f)) * 4.0f);
  local_2->local_5 = (s32) ((param_1 + (param_3 * 0.5f)) * 4.0f);
  local_2->local_6 = 0x1FF;
  local_2->local_7 = 0;
  osWritebackDCache(local_2, 0x200);
  return local_1;
}

void func_80015A70(s32 *param_0, f32 param_1, f32 param_2, f32 param_3, f32 param_4) {
    s32 temp_v0;
    u8 *temp_a0;

    func_80015860(*param_0);
    temp_v0 = func_80015828();
    *param_0 = temp_v0;
    temp_a0 = (u8 *)((s32 *) D_800797B8) + (temp_v0 * 0x10);
    (*(s16 *)((s8 *)(temp_a0) + 4)) = 0x1FF;
    (*(s16 *)((s8 *)(temp_a0) + 6)) = 0;
    (*(s16 *)((s8 *)(temp_a0) + 0xC)) = 0x1FF;
    (*(s16 *)((s8 *)(temp_a0) + 0xE)) = 0;
    (*(s16 *)((s8 *)(temp_a0) + 0)) = (s16)(s32)(param_1 * 4.0f);
    (*(s16 *)((s8 *)(temp_a0) + 2)) = (s16)(s32)(param_2 * 4.0f);
    (*(s16 *)((s8 *)(temp_a0) + 8)) = (s16)(s32)(param_3 * 4.0f);
    (*(s16 *)((s8 *)(temp_a0) + 0xA)) = (s16)(s32)(param_4 * 4.0f);
    osWritebackDCache(temp_a0, 0x200);
}

void func_80015B34(void *param_0, s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
    s32 idx;
    s32 x1, y1;
    s32 w, h;
    f32 cx, cy;
    func_80015860(*(u32 *)param_0);
    idx = func_80015828();
    *(u32 *)param_0 = idx;

    x1 = param_1 + param_3;
    y1 = param_2 + param_4;
    if (param_1 < 0) param_1 = 0;
    else if (param_1 >= 0x131) param_1 = 0x130;
    if (param_2 < 0) param_2 = 0;
    else if (param_2 >= 0xE5) param_2 = 0xE4;
    if (x1 < 0) x1 = 0;
    else if (x1 >= 0x131) x1 = 0x130;
    if (y1 < 0) y1 = 0;
    else if (y1 >= 0xE5) y1 = 0xE4;

    w = x1 - param_1;
    h = y1 - param_2;
    cx = (f32)param_1 + (f32)w * 0.5f;
    cy = (f32)param_2 + (f32)h * 0.5f;

    ((s16 *)param_0)[4] = w;
    ((s16 *)param_0)[5] = h;
    ((s16 *)param_0)[2] = param_1;
    ((s16 *)param_0)[3] = param_2;

    ((TileEntry *) D_800797B8)[idx].f0 = w * 2;
    ((TileEntry *) D_800797B8)[idx].f2 = h * 2;
    ((TileEntry *) D_800797B8)[idx].f4 = 0x1FF;
    ((TileEntry *) D_800797B8)[idx].f6 = 0;
    ((TileEntry *) D_800797B8)[idx].fC = 0x1FF;
    ((TileEntry *) D_800797B8)[idx].fE = 0;
    ((TileEntry *) D_800797B8)[idx].f8 = cx * 4.0f;
    ((TileEntry *) D_800797B8)[idx].fA = cy * 4.0f;
    osWritebackDCache(&((TileEntry *) D_800797B8)[idx], 0x200);
}

int func_80015CC0(s16 param_0[5], s32 *param_1, s32 *param_2, s32 *param_3, s32 *param_4) {
    *param_1 = param_0[2];
    *param_2 = param_0[3];
    *param_3 = param_0[4];
    *param_4 = param_0[5];
}

void func_80015CE8(s32 param_0, s32 param_1)
{
  func_800CA510(param_1, func_80015D14(param_0));
}

f32 func_80015D14(OSLogItem *param_0)
{
    f32 var;
    var = (f32) (s16) param_0->argCount / (f32) (s16) param_0->eventID;
    if (widescreen_enabled)
    {
        var *= D_80041710;
    }
    return var;
}
