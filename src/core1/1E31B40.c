#include "common.h"

struct OSPiInfo { u32 field0; u32 field4; };
extern u8 *D_8007BCC0;
extern u16 *D_8007BCC4;
extern OSMesgQueue D_8007BEE0;
extern s16 D_8007BED8;
extern void func_80013D10(void *);
extern OSMesg D_8007BEF8;
extern void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count);
extern s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flags);
extern void func_80014C40(void);
extern void *D_8007BCD4;
extern void *D_8007BCDC;
extern void *D_8007BCE4;
extern void heap_free();
extern s32 D_8007BCD0;
extern s32 D_8007BCD8;
extern s32 D_8007BCE0;
extern s16 D_8007BEDA;
typedef struct { s32 local_0[6]; } Struct8001A440;
extern Struct8001A440 D_8007BCF8[];
extern void *D_8007BCE8;
extern void *D_8007BCF0;
extern void *D_8007BCEC;
extern void *D_8007BCF4;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
void func_8001A63C();

void func_8001A010(void) {
}

s32 func_8001A018(s32 param_0)
{
  s32 local_0;
  local_0 = (s32)(D_8007BCC0 = heap_alloc(param_0 + 0x40));
  while (local_0 % 0x40)
  {
    local_0 += 2;
  }

  return local_0;
}

void func_8001A080()
{
  D_8007BCC4 = func_8001A018(0x21D80);
}

s32 func_8001A0A8()
{
    return (s32)D_8007BCC4;
}

int func_8001A0B4()
{
  return 0x21D80;
}

u16 func_8001A0C0(s32 param_0, s32 param_1) {
    s32 local_0;
    s32 local_1;

    local_0 = param_1 * 19;
    local_1 = local_0 << 5;
    return *(u16 *)((u8 *)D_8007BCC4 + local_1 + (param_0 << 1));
}

void func_8001A0F0()
{
  OSMesgQueue *local_0 = &D_8007BEE0;
  osRecvMesg(local_0, 0, 1);
}

void func_8001A11C()
{
  osSendMesg(((void * *) &D_8007BEE0), 0, OS_MESG_BLOCK);
}

void func_8001A148(s32 param_0, s32 param_1, s32 param_2, s32 param_3) {
    u8 *temp_a0;
    s16 *local_0;

    func_8001A0F0();
    local_0 = &D_8007BED8;
    temp_a0 = ((u8 *) D_8007BCF8) + *local_0 * 0x18;
    *local_0 = (s16)((s32)(*local_0 + 1) % 20);
    func_8001A11C(temp_a0);
    *(s32 *)(temp_a0 + 0) = 0;
    *(s32 *)(temp_a0 + 8) = param_0;
    *(s32 *)(temp_a0 + 12) = param_1;
    *(s32 *)(temp_a0 + 16) = param_2;
    *(s32 *)(temp_a0 + 20) = param_3;
    func_80013D10(temp_a0);
}

void func_8001A1E0(s32 param_0, s32 param_1, s32 param_2)
{
    u32 *temp_a0;

    func_8001A0F0();
    temp_a0 = (u32 *)((char *)((u32 *) D_8007BCF8) + D_8007BED8 * 24);
    D_8007BED8 = (s16)((D_8007BED8 + 1) % 20);
    func_8001A11C(temp_a0);
    temp_a0[0] = 1;
    temp_a0[1] = param_2;
    temp_a0[2] = param_0;
    temp_a0[3] = param_1;
    func_80013D10(temp_a0);
}

void func_8001A270(s32 param_0, s32 param_1)
{
    func_8001A1E0(param_0, param_1, 0x40000000);
}

void func_8001A290()
{
    func_80015190();
}

void func_8001A2B0()
{
    func_80013D10(0x3);
}

void func_8001A2D0()
{
  D_8007BED8 = 0;
  osCreateMesgQueue(&D_8007BEE0, &D_8007BEF8, 1);
  osSendMesg(&D_8007BEE0, 0, OS_MESG_BLOCK);
  func_80014C40();
}

void func_8001A324()
{
  if (((void *) D_8007BCD0) != 0)
  {
    heap_free(((void *) D_8007BCD0));
    heap_free(D_8007BCD4);
    heap_free(((void *) D_8007BCD8));
    heap_free(D_8007BCDC);
    heap_free(((void *) D_8007BCE0));
    heap_free(D_8007BCE4);
    D_8007BCD0 = 0;
  }
  func_8001A63C();
}

int func_8001A3A0()
{
  if (!D_8007BCD0)
  {
    D_8007BCD0 = heap_alloc(30400);
    D_8007BCD4 = heap_alloc(30400);
    D_8007BCD8 = heap_alloc(0x12C00);
    D_8007BCDC = heap_alloc(0x12C00);
    D_8007BCE0 = heap_alloc(6880);
    D_8007BCE4 = heap_alloc(6880);
    func_8001A570();
  }
  D_8007BEDA = 0;
  func_800A9800();
}

void func_8001A440(s32 param_0) {
    Struct8001A440 *local_0;

    func_8001A0F0();
    func_80015430(param_0);
    local_0 = &D_8007BCF8[D_8007BED8];
    D_8007BED8 = (D_8007BED8 + 1) % 20;
    func_8001A11C(local_0);
    local_0->local_0[0] = 7;
    func_80013D10(local_0);
}

void func_8001A4B8(u8 *param_0) {
    D_8007BEDA = 1 - D_8007BEDA;
    if (D_8007BCE8 != 0) {
        (*(s32 *)((s8 *)(param_0) + (0))) = (s32) (*(s32*)((u8*)&D_8007BCE8 + (D_8007BEDA * 4)));
    } else {
        (*(s32 *)((s8 *)(param_0) + (0))) = (s32) (*(s32*)((u8*)&D_8007BCD0 + (D_8007BEDA * 4)));
    }
    if (D_8007BCF0 != 0) {
        (*(s32 *)((s8 *)(param_0) + (4))) = (s32) (*(s32*)((u8*)&D_8007BCF0 + (D_8007BEDA * 4)));
    } else {
        (*(s32 *)((s8 *)(param_0) + (4))) = (s32) (*(s32*)((u8*)&D_8007BCD8 + (D_8007BEDA * 4)));
    }
    (*(s32 *)((s8 *)(param_0) + (8))) = (s32) (*(s32*)((u8*)&D_8007BCE0 + (D_8007BEDA * 4)));
}

int func_8001A570(void) {
}

void func_8001A578(s32 param_0)
{
    u32 local_0;
    s32 local_1;
    s32 local_2;
    s32 local_3;
    s32 local_4;
    s32 local_5;

    if (func_800D3948() != 0) {
        local_4 = 0x1388;
        if (param_0 != 0) {
            local_4 = param_0 * 0xE00;
            local_5 = param_0 * 0x1DB;
        } else {
            local_5 = 0;
        }
        local_3 = local_4 * 8;
        if (local_4 != 0) {
            local_0 = (u32)heap_alloc(local_3);
            local_1 = heap_alloc(local_3);
            (*((struct OSPiInfo *) &D_8007BCE8)).field0 = local_0;
            (*((struct OSPiInfo *) &D_8007BCE8)).field4 = local_1;
        }
        local_3 = local_5 << 6;
        if (local_5 != 0) {
            local_2 = heap_alloc(local_3);
            (*((struct OSPiInfo *) &D_8007BCF0)).field4 = (u32)heap_alloc(local_3);
            if (local_3 && local_3) {
            }
            *(s32 *)((char *)((struct OSPiInfo *) &D_8007BCF0) + 0) = local_2;
        }
    }
}

void func_8001A63C()
{
  void *local_1;
  void *local_0;
  local_1 = D_8007BCE8;
  local_0 = D_8007BCF0;
  if (local_1 != 0)
  {
    heap_free(local_1);
    heap_free(D_8007BCEC);
    D_8007BCE8 = 0;
  }
  if (local_0 != 0)
  {
    heap_free(D_8007BCF0);
    heap_free(D_8007BCF4);
    D_8007BCF0 = 0;
  }
}
