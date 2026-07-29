#include "common.h"

extern s32 D_80046A88;
extern s32 osTvType;
extern s32 osViClock;
typedef struct Struct_69A40_s { struct Struct_69A40_s *unk0; struct Struct_69A40_s *unk4; u8 pad8[8]; void *unk10; } Struct_69A40;
typedef struct Obj_s { u8 *unk0; u32 pad4; u16 unk8; u16 padA; struct Obj_s *unkC; } Obj;
typedef struct { u8 *unk0[2]; Obj *unk8[3]; void *unk14; } Struct_459E0;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 *(*unk10)(s32 **); void *unk14; s32 unk18; u8 unk1C; u8 pad1D[3]; void *unk20; } Struct_6A1A8;
extern OSMesg D_800694A0[];
extern OSMesgQueue D_80045BF0;
extern OSMesg D_80045C08[];
extern OSMesgQueue D_80045BB8;
extern OSMesg D_80045BD0[];
extern u8 D_8006A1D2;
extern Struct_6A1A8 D_8006A1A8;
extern u8 D_8006A158[];
extern Struct_69A40 D_80069A40[90];
extern u8 D_8006A1D8[2][0x4E20];
extern s16 D_80073E18[3][0x730];
extern Struct_459E0 D_800459E0;
extern u8 D_800459F8[];
extern u8 D_80045BA8[];
extern u8 D_80046A78[];
extern u8 D_8003CA44[];
extern void func_80020D80(void *param_0, Struct_6A1A8 *param_1);
extern void func_80020E40( Struct_69A40 *param_0, Struct_69A40 *param_1 );
extern void *func_80020EE4( s32 param_0, s32 param_1, void *param_2, s32 param_3, s32 param_4 );
extern void func_8001DCB0( void *param_0, void *param_1, s32 param_2, void *param_3, void *param_4, void *param_5, s32 param_6 );
extern u8 *D_8003CC5C;
extern s32 D_8003CC60;
typedef struct { void *unk0; s16 unk4; } AiBuf;
extern u32 D_8006A150;
extern s32 D_80076938;
extern u32 osVirtualToPhysical();
extern s32 osAiSetNextBuffer(void *, u32);
extern u32 osAiGetLength(void);
extern s32 func_80021574(u32, s32 *, u32, s32);
extern void func_8001A148();
extern s32 D_8003CC64;
typedef struct Struct80012BB4Node { struct Struct80012BB4Node *local_0; struct Struct80012BB4Node *local_4; u32 local_8; u32 local_C; u8 *local_10; } Struct80012BB4Node;
typedef struct { u32 local_0; Struct80012BB4Node *local_4; Struct80012BB4Node *local_8; } Struct80012BB4Manager;
typedef struct { u32 pad0[6]; } Struct80012BB4Mesg;
extern u32 D_8006A148;
extern u32 D_8006A14C;
extern Struct80012BB4Mesg D_80069580[];
extern s32 D_80069A30;
extern s32 D_80069488;
extern s32 D_8003CA40;
extern int D_80069568;
extern u16 D_8006A1CC;
extern u16 D_8006A1CE;
extern OSMesgQueue D_8007695C;
extern u32 D_8003CC70;
extern void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *mesgs, s32 count);
extern void osCreatePiManager(OSPri pri, OSMesgQueue *mq, OSMesg *mesgs, s32 count);
extern OSMesg D_80076958;
extern OSMesgQueue D_800769B8;
extern OSMesgQueue D_80076978;
extern u32 *D_800769CC[];
extern u32 *D_800769D0[];
extern OSPiHandle *D_80076940;
extern void osInvalDCache();
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
void func_8001268C();
void func_800128C0();
s32 func_800129FC(u8 *param_0, AiBuf *param_1);
void func_80012B74();
s32 *func_80012D4C(s32 **param_0);
void func_80012D84();
s32 func_80012EA0();
void func_80012F0C();
void func_80012F34();

void func_800125B0(void)
{
  s32 *local_0;
  bzero(&D_80046A88, 0x22A00);
 local_0 = &D_80046A88; *((s32 **) (((s8 *) (((s32 *) D_80046A78))) + 4)) = (*((s32 **) (((s8 *) (((s32 *) D_80046A78))) + 0)) = local_0);
  *((s32 *) (((s8 *) (((s32 *) D_80046A78))) + 8)) = 0x22A00;
  *((s32 **) (((s8 *) (((s32 *) D_80046A78))) + 4)) = (*((s32 **) (((s8 *) (((s32 *) D_80046A78))) + 0)) = local_0);
  *((s32 *) ((0, ((s8 *) (((s32 *) D_80046A78))) + 0xC))) = 0;
  switch (osTvType)
  {
    case 0:

    case 1:
      osViClock = 0x02E6D354;
      break;

    case 2:
      osViClock = 0x02E6025C;
      break;

  }

  func_8001268C();
  func_800DC380();
  func_80016C00();
  func_80012F0C(4);
  func_80012F34(0, 4);
  func_80012F34(1, 4);
  func_80012EA0();
}

void func_8001268C(void)
{
    s32 local_0;

    osCreateMesgQueue(((OSMesgQueue *) &D_80069488), D_800694A0, 0x32);
    osCreateMesgQueue(&D_80045BF0, D_80045C08, 8);
    osCreateMesgQueue(&D_80045BB8, D_80045BD0, 8);

    D_8006A1D2 = 0;
    D_8006A1A8.unk0 = 0x18;
    D_8006A1A8.unk4 = 0x18;
    D_8006A1A8.unk8 = 0x80;
    D_8006A1A8.unkC = 1;
    D_8006A1A8.unk10 = func_80012D4C;
    D_8006A1A8.unk1C = 6;
    D_8006A1A8.unk20 = D_8003CA44;
    D_8006A1A8.unk14 = D_80046A78;
    D_8006A1A8.unk18 = osAiSetFrequency(0x5622);
    func_80020D80(D_8006A158, &D_8006A1A8);

    D_80069A40[0].unk4 = NULL;
    D_80069A40[0].unk0 = NULL;
    for (local_0 = 0; local_0 < 89; local_0++) {
        func_80020E40(&D_80069A40[local_0 + 1], &D_80069A40[local_0]);
        D_80069A40[local_0].unk10 = func_80020EE4(
            0, 0, D_8006A1A8.unk14, 1, 0x200
        );
    }
    D_80069A40[local_0].unk10 =
        func_80020EE4(0, 0, D_8006A1A8.unk14, 1, 0x200);

    for (local_0 = 0; local_0 < 2; local_0++) {
        D_800459E0.unk0[local_0] = D_8006A1D8[local_0];
    }

    for (local_0 = 0; local_0 < 3; local_0++) {
        D_800459E0.unk8[local_0] =
            func_80020EE4(0, 0, D_8006A1A8.unk14, 1, 0x10);
        D_800459E0.unk8[local_0]->unk8 = 0;
        D_800459E0.unk8[local_0]->unkC = D_800459E0.unk8[local_0];
        D_800459E0.unk8[local_0]->unk0 = D_80073E18[local_0];
    }

    func_8001DCB0(
        D_800459F8,
        D_80045BA8,
        4,
        func_800128C0,
        NULL,
        D_80046A78,
        0x32
    );
}

// audio_thread_entry
void func_800128C0(param_0) s32 param_0; {
    s32 var_s0;

    var_s0 = 1;
loop_1:
    osRecvMesg(((s32 *) &D_80045BB8), NULL, 1);
    if (func_800129FC((*(s32 *)((s8 *)((((s32 *) &D_800459E0) + (((s32) ((s32) D_8006A148) % 3)))) + (8))), D_8003CC60) != 0) {
        if (var_s0 == 0) {
            osRecvMesg(((s32 *) &D_80045BF0), &D_8003CC5C, 1);
            func_80012B74((*(s32 *)((s8 *)(D_8003CC5C) + (4))));
            D_8003CC60 = (*(s32 *)((s8 *)(D_8003CC5C) + (4)));
        } else {
            var_s0 -= 1;
        }
    }
    func_800E96B0(1);
    goto loop_1;
}

s32 func_800129FC(u8 *param_0, AiBuf *param_1)
{
    u32 phys;
    s32 local_0;
    s32 sp2C;
    s32 len;
    s32 ret = ret * 0;

    phys = osVirtualToPhysical(*((void **) param_0));
    func_80012D84();
    len = osAiGetLength() >> 2;
    if (param_1 != 0) {
        ret = osAiSetNextBuffer(param_1->unk0, param_1->unk4 << 2);
    }
    if (ret == -1) {
        return 0;
    }
    if ((len < 0x5C) && ((local_0 = D_80076938) == 0)) {
        *((s16 *) (param_0 + 4)) = 0x398;
        local_0 = 2 + local_0 * 0;
        (((s32 *) &D_80076940))[-2] = local_0;
    } else {
        local_0 = D_80076938;
        if ((len >= 0x115) && (local_0 == 0)) {
            *((s16 *) (param_0 + 4)) = 0x228;
            local_0 = 2 + local_0 * 0;
            (((s32 *) &D_80076940))[-2] = local_0;
        } else {
            *((s16 *) (param_0 + 4)) = 0x2E0;
            if (local_0 != 0) {
                local_0--;
                (((s32 *) &D_80076940))[-2] = local_0;
            }
        }
    }
    ret = func_80021574(((u32 *) &D_800459E0)[D_8006A150], &sp2C, phys,
                        *((s16 *) (param_0 + 4)));
    if (sp2C == 0) {
        return 0;
    }
    func_8001A148(((u32 *) &D_800459E0)[D_8006A150], ret, ((u32 *) &D_80045BF0), param_0 + 8);
    D_8006A150 ^= 1;
    return 1;
}

void func_80012B74(param_0) s32 param_0;
{
  int new_var;
  new_var = 0;
  if (((osAiGetLength() >> 2) == 0) && (D_8003CC64 == new_var))
  {
    D_8003CC64 = new_var;
  }
}
extern u32 osAiGetLength(void);

void *func_80012BB4(u32 param_0, u32 param_1, s32 param_2)
{
  u8 *local_0;
  u32 local_1;
  u32 local_2;
  Struct80012BB4Node *local_3;
  u32 local_6;
  Struct80012BB4Node *local_4;
  local_4 = 0;
  local_6 = (u32) (*((Struct80012BB4Manager *) &D_80069A30)).local_4;
  local_3 = (Struct80012BB4Node *) local_6;
  while (local_3 != 0)
  {
    local_1 = local_3->local_8 + 0x200;
    if (param_0 < local_3->local_8)
    {
      break;
    }
    {
    }
    if (!(((s32) local_1) < ((s32) (param_0 + param_1))))
    {
      local_3->local_C = D_8006A148;
      return osVirtualToPhysical(
          (void *) ((((u32) local_3->local_10) + param_0)
                    - local_3->local_8));
    }
    local_4 = local_3;
    local_3 = local_3->local_0;
  }

  local_3 = (*((Struct80012BB4Manager *) &D_80069A30)).local_8;
  if (local_3 == 0)
  {
    return osVirtualToPhysical((Struct80012BB4Node *) local_6);
  }
  (*((Struct80012BB4Manager *) &D_80069A30)).local_8 = local_3->local_0;
  func_80020E74(local_3);
  if (local_4 != 0)
  {
    func_80020E40(local_3, local_4);
  }
  else
  {
    local_6 = (u32) (*((Struct80012BB4Manager *) &D_80069A30)).local_4;
    if (local_6 != 0)
    {
      (*((Struct80012BB4Manager *) &D_80069A30)).local_4 = local_3;
      local_3->local_0 = (Struct80012BB4Node *) local_6;
      local_3->local_4 = 0;
      ((Struct80012BB4Node *) local_6)->local_4 = local_3;
    }
    else
    {
      (*((Struct80012BB4Manager *) &D_80069A30)).local_4 = local_3;
      local_3->local_0 = 0;
      local_3->local_4 = 0;
    }
  }
  local_6 = param_0 & 1;
  param_0 = param_0 - local_6;
  local_3->local_8 = param_0;
  local_3->local_C = D_8006A148;
  local_0 = local_3->local_10;
  osPiStartDma(&D_80069580[D_8006A14C++], 1, 0, param_0, local_0, 0x200, ((u32 *) &D_80069488));
  return (void *) (((u32) osVirtualToPhysical(local_0)) + local_6);
}
typedef struct ListNode {
    struct ListNode *next; // 0x0
    struct ListNode *prev; // 0x4
    u32 address;           // 0x8
    u32 unkC;              // 0xC
    u8 *buffer;            // 0x10
} ListNode;

typedef struct {
    u32 unk0;              // 0x0
    ListNode *list_head;   // 0x4
    ListNode *free_list;   // 0x8
} ListManager;

typedef struct {
    u32 pad[6];

} DmaMesg;

extern u32 D_8006A148;
extern u32 D_8006A14C;

s32 *func_80012D4C(s32 **param_0) {
    if ((*(u8 *)((s8 *)(&D_80069A30) + (0))) == 0) {
        (*(s32 *)((s8 *)(&D_80069A30) + (4))) = 0;
        (*(s32 **)((s8 *)(&D_80069A30) + (8))) = ((s32 *) D_80069A40);
        (*(u8 *)((s8 *)(&D_80069A30) + (0))) = 1U;
    }
    *param_0 = &D_80069A30;
    return &func_80012BB4;
}

void func_80012D84(void) {
    u32 local_1;
    s32 local_0;
    u8 *local_2;
    u8 *local_3;

    local_0 = 0;
    local_1 = 0;
    if (D_8006A14C != 0) {
        do {
            osRecvMesg(&D_80069488, &local_0, 0);
            local_1 += 1;
        } while (local_1 < (u32) D_8006A14C);
    }
    local_3 = (*(u8 **)((s8 *)(&D_80069A30) + (4)));
    if (local_3 != NULL) {
        do {
            local_2 = (*(u8 **)((s8 *)(local_3) + (0)));
            if ((u32) ((*(s32 *)((s8 *)(local_3) + (0xC))) + 1) < (u32) D_8006A148) {
                if (local_3 == (*(u8 **)((s8 *)(&D_80069A30) + (4)))) {
                    (*(u8 **)((s8 *)(&D_80069A30) + (4))) =
                        (*(u8 **)((s8 *)(local_3) + (0)));
                }
                func_80020E74(local_3);
                if ((*(u8 **)((s8 *)(&D_80069A30) + (8))) != NULL) {
                    func_80020E40(local_3, (*(u8 **)((s8 *)(&D_80069A30) + (8))));
                } else {
                    (*(u8 **)((s8 *)(&D_80069A30) + (8))) = local_3;
                    (*(u8 **)((s8 *)(local_3) + (0))) = NULL;
                    (*(s32 *)((s8 *)(local_3) + (4))) = 0;
                }
            }
            local_3 = local_2;
        } while (local_2 != NULL);
    }
    D_8006A14C = 0;
    D_8006A148 += 1;
}

s32 func_80012EA0(void){
    if(D_8003CA40 == 0){
        D_8003CA40 = 1;
        osStartThread(((s32 *) D_800459F8));
    }
}

int func_80012EDC()
{
  return (int)((int *) D_80046A78);
}

s32 func_80012EE8(void){
    s32 addr = (s32)&D_80069488;
    return addr;
}

int func_80012EF4()
{
    return &D_80069568;
}

int func_80012F00()
{
    return (int)((int *) &D_80045BB8);
}

void func_80012F0C(param_0) int param_0;
{
  D_8006A1CC = param_0;
  func_80021A00(param_0 & 0xFF);
}

void func_80012F34(param_0, param_1) s32 param_0; long param_1;
{
  u16 *local_0 = (u16 *) (&D_8006A1CE);
  if (!param_1)
  {
  }
  local_0[param_0 ^ 0] = param_1;
  func_80021AD0();
}

int *func_80012F60()
{
    return ((int *) &D_8007695C);
}

int func_80012F6C()
{
  return (int)((int *) &D_80076940);
}

void rom_dma_read(void *vaddr, s32 devaddr, s32 size)
{
  s32 block_cnt;
  s32 block_remainder;
  int i;
  osWritebackDCache(vaddr, size);
 block_cnt = size / 0x20000; block_cnt++; block_cnt--; block_remainder = size % 0x20000; for (i = 0; i < block_cnt; i++) { ((s32) D_8003CC70)++; osPiStartDma(((OSIoMesg *) &D_80076940), 0, 0, devaddr, vaddr, 0x20000, &D_8007695C); osRecvMesg(&D_8007695C, 0, 1); devaddr += 0x20000; vaddr = ((u32 *) vaddr) + 0x8000;
    ((s32) D_8003CC70)--;
  }

  ((s32) D_8003CC70)++;
  osPiStartDma(((OSIoMesg *) &D_80076940), 0, 0, devaddr, vaddr, block_remainder, &D_8007695C);
  osRecvMesg(&D_8007695C, 0, 1);
  ((s32) D_8003CC70)--;
  osInvalDCache(vaddr, size);
}

void func_8001311C(s32 param_0, s32 param_1)
{
    osWritebackDCache(param_0, 0x1800);
    D_8003CC70 += 1;
    osPiStartDma(((OSPiHandle *) &D_80076940), 0, 0, param_1, param_0, 0x1800, &D_8007695C);
    osRecvMesg(&D_8007695C, 0, 1);
    D_8003CC70 -= 1;
    osInvalDCache(param_0, 0x1800);
}

void func_800131C0()
{
  osCreateMesgQueue(&D_8007695C, &D_80076958, 1);
  osCreateMesgQueue(&D_800769B8, &D_80076978, 16);
  osCreatePiManager(0x96, &D_800769B8, &D_80076978, 16);
}

void func_80013224(s32 param_0, u32 *param_1, u32 *param_2)
{
    s32 local_0;

    D_8003CC70++;
    D_800769CC[D_8003CC70] = param_1;
    D_800769D0[D_8003CC70] = param_2;
    osWritebackDCache(param_1, param_2);
    osPiStartDma(&D_80076940, 0, 0, param_0, param_1, param_2, ((u32 *) &D_8007695C));
}

void func_800132BC()
{
  osRecvMesg(&D_8007695C, 0, 1);
  osInvalDCache(((u8 * *) D_800769CC)[D_8003CC70], ((u8 * *) D_800769D0)[D_8003CC70]);
  D_8003CC70--;
}

#pragma weak func_80013224_unproto = func_80013224
extern void func_80013224_unproto();

void func_80013324()
{
    func_80013224_unproto();
    func_800132BC();
}

void func_8001334C(void)
{
    while (((int) D_8003CC70) > 0)
    {
        func_800132BC();
    }
    return;
}
