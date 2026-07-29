#include "threads.h"
#include "types.h"
#include "core1/1E2D890.h"

extern u32 D_8007DB54;
typedef struct { s32 local_0[14]; } Struct80015E80;
extern Struct80015E80 D_800799E0[];
extern s32 D_800799C0[256][2];
extern long long D_80079A14[];
extern u8 D_80079D69;
extern u8 D_80079B93;
extern s32 D_80079AF4;
extern s32 D_80079AC0[13];
typedef struct { s32 local_0[2]; f32 local_1[2]; } Struct80016068;
extern Struct80016068 D_80079AF8[];
typedef struct { u16 button; s8 stick_x; s8 stick_y; u8 errnum; } ContPad1608C;
typedef struct { u16 cur; u16 prev; u16 pressed; u16 released; f32 joy[2]; } PadState1608C;
extern ContPad1608C D_80079B40[4];
extern ContPad1608C D_80079B58;
extern OSThread D_80079BA8;
extern u8 D_80079D6C[4];
extern s32 func_800A9CAC(void);
extern s32 _glrecord_entrypoint_0(ContPad1608C *, s32 *);
extern void func_800D8FA0(s32);
extern void func_800A9CDC(void);
extern void func_800DC0C0(void);
extern f32 func_80013B70(f32 param_0, f32 param_1, f32 param_2);
extern s32 D_800799F8[][14];
extern s32 D_80079A04[][14];
extern u32 D_80079AFC[];

// .data
extern s32 D_8003F5F0;

// .bss

// si_mesg
extern OSMesg D_80079B38;
// joy_mesg
extern OSMesg D_80079B3C;
// controllers
// another contpad?
// si_mesg_queue
extern OSMesgQueue D_80079B60;
// joy_mesg_queue
extern OSMesgQueue D_80079B78;
// controller_statuses
extern OSContStatus D_80079B90[4];
extern volatile s32 D_80079BA0;
extern OSThread D_80079BA8;

// This should be much larger than 0x10 bytes. Maybe they had a second struct for threads that don't use
// SR_FR, since those will never save or load the odd float register values on context switch.
extern __OSThreadOddFpStorage D_80079D58;

// bitpattern
extern u8 D_80079D68;
extern u8 D_80079D6C[];
// joy_thread_stack
extern u64 D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)];

extern OSMesgQueue D_80079F70;
extern OSMesg D_80079F88[6];

void func_800165F0(void);
void func_80016934(s32 arg0);
void func_80016A48(void);
void func_80016864(void);
void func_800169B4(void);
void func_80016A04(void);

f32 func_80015D60(s32 arg0, s32 arg1, s32 arg2) {
    f32 scale;
    u32 sp0;

    sp0 = 0xE955CCDD - D_8007DB54;
    scale = *(f32 *)&sp0;
    if (arg0 > 0) {
        arg0 = (arg2 < arg0) ? arg2 : (arg0 < arg1) ? arg1 : arg0;
        arg0 = ((arg0 - arg1) * 0x50) / (arg2 - arg1);
    } else if (arg0 < 0) {
        arg0 = (arg0 < -arg2) ? -arg2 : (-arg1 < arg0) ? -arg1 : arg0;
        arg0 = ((arg0 + arg1) * 0x50) / (arg2 - arg1);
    }
    return scale *= arg0;
}

void func_80015E80(s32 param_0, s32 *param_1)
{
    Struct80015E80 *local_0;

    local_0 = &D_800799E0[param_0];
    param_1[0] = local_0->local_0[0];
    param_1[1] = local_0->local_0[1];
    param_1[2] = local_0->local_0[2];
    param_1[3] = local_0->local_0[3];
    param_1[4] = local_0->local_0[4];
    param_1[5] = local_0->local_0[5];
}

int func_80015ECC(s32 param_0, s32 *param_1)
{
  s32 local_1;
  local_1 = param_0;
  param_1[0] = D_80079AC0[0];
  param_1[1] = D_80079AC0[1];
  param_1[2] = D_80079AC0[2];
  param_1[3] = D_80079AC0[3];
  param_1[4] = D_80079AC0[4];
  param_1[5] = D_80079AC0[5];
}

s32 func_80015F0C(s32 param_0, s32 param_1)
{
  s32 *new_var = D_800799C0[param_0];
  return new_var[param_1];
}

void func_80015F28(s32 param_0, s32 *param_1)
{
    Struct80015E80 *local_0;

    local_0 = &D_800799E0[param_0];
    param_1[0] = local_0->local_0[6];
    param_1[1] = local_0->local_0[7];
    param_1[2] = local_0->local_0[8];
}

void func_80015F5C(s32 param_0, s32 *param_1)
{
  param_1[0] = ((s32 *) D_80079AC0)[6];
  param_1[1] = ((s32 *) D_80079AC0)[7];
  param_1[2] = ((s32 *) D_80079AC0)[8];
}

s32 func_80015F84(s32 param_0)
{
  int new_var2;
  long long *new_var4;
  long long *new_var3;
  int new_var;
  new_var2 = (((param_0 * 7) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var = (((new_var2 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var3 = &D_80079A14[((new_var & ((0xFFFFFFFFFFFFFFFFu & 0xFFFFFFFFFFFFFFFF) ^ (0xFFFFFFFFFFFFFFFFu * 0))) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu];
  return *(s32*)(new_var4 = (new_var3 = &(*new_var3)));
}

s32 func_80015FA0(s32 param_0) {
    s32 local_0;

    if ((D_80079D69 == 0) || (D_80079B93 != 0)) {
        return 0;
    }
    if (param_0 != 0) {
        local_0 = ((s32 (*)[14]) D_80079A14)[param_0][0];
    } else {
        local_0 = D_80079AF4;
    }
    return local_0;
}

void func_80015FFC(s32 param_0, s32 *param_1)
{
    s32 *local_0;
    local_0 = (s32*)((s8*)((s32 *) D_800799E0) + (param_0 * 0x38));
    param_1[0] = *(s32*)((s8*)local_0 + 0x24);
    param_1[1] = *(s32*)((s8*)local_0 + 0x28);
    param_1[2] = *(s32*)((s8*)local_0 + 0x2C);
    param_1[3] = *(s32*)((s8*)local_0 + 0x30);
}

void func_80016038(s32 param_0[4], s32 *param_1)
{
  param_1[0] = D_80079AC0[0x24 / 4];
  param_1[1] = D_80079AC0[0x28 / 4];
  param_1[2] = D_80079AC0[0x2c / 4];
  param_1[3] = D_80079AC0[0x30 / 4];
}

void func_80016068(s32 param_0, f32 *param_1) {
    param_1[0] = D_80079AF8[param_0].local_1[0];
    param_1[1] = D_80079AF8[param_0].local_1[1];
}

void func_8001608C(void)
{

  s32 j;
  register s32 i;
  s32 sp54;
  s32 sp50;
  sp54 = osGetThreadPri(&D_80079BA8);

  osSetThreadPri(&D_80079BA8, 0);

    
  D_80079B58.stick_x = D_80079B40[0].stick_x;

    
  D_80079B58.stick_y = D_80079B40[0].stick_y;

    
  D_80079B58.button = D_80079B40[0].button;

    
  if (func_800A9CAC())
  {
    if (_glrecord_entrypoint_0(D_80079B40, &sp50) == 0)
    {
      func_800A9CDC();
    }
    else
    {
      func_800D8FA0(sp50);
    }
  }
  func_800DC0C0();
  for (i = 0; 3 >= i; ++i)
  {
    D_80079D6C[i] = (D_80079B40[i].errnum & 8) ? (0) : (1);

    if ((D_80079B40[i].button & 0x20) && (D_80079B40[i].button & 0x10))
    {
      ((s32 (*)[2]) D_800799C0)[i][0] = (D_80079B40[i].button & 0x4000) ? (((s32 (*)[2]) D_800799C0)[i][0] + 1) : (0);
    }
    else
    {
      for (j = 0; 2 > j; ++j)
      {
        ((s32 (*)[2]) D_800799C0)[i][j] = 0;
      }

    }
    ((s32 (*)[14]) D_800799E0)[i][0] = (D_80079B40[i].button & 0x8000) ? (((s32 (*)[14]) D_800799E0)[i][0] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][1] = (D_80079B40[i].button & (0x4000 ^ 0)) ? (((s32 (*)[14]) D_800799E0)[i][1] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][2] = (D_80079B40[i].button & 0x2) ? (((s32 (*)[14]) D_800799E0)[i][2] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][3] = (D_80079B40[i].button & 0x4) ? (((s32 (*)[14]) D_800799E0)[i][3] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][4] = (D_80079B40[i].button & 0x8) ? (((s32 (*)[14]) D_800799E0)[i][4] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][5] = (D_80079B40[i].button & 0x1) ? (((s32 (*)[14]) D_800799E0)[i][5] + 1) : (0);

    ((s32 (*)[14]) D_800799E0)[i][6] = (D_80079B40[i].button & 0x2000) ? (((s32 (*)[14]) D_800799E0)[i][6] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][7] = (D_80079B40[i].button & 0x20) ? (((s32 (*)[14]) D_800799E0)[i][7] + 1) : (0);

    ((s32 (*)[14]) D_800799E0)[i][8] = (D_80079B40[i].button & 0x10) ? (((s32 (*)[14]) D_800799E0)[i][8] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][9] = (D_80079B40[i].button & 0x800) ? (((s32 (*)[14]) D_800799E0)[i][9] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][10] = (D_80079B40[i].button & 0x400) ? (((s32 (*)[14]) D_800799E0)[i][10] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][11] = (D_80079B40[i].button & 0x200) ? (((s32 (*)[14]) D_800799E0)[i][11] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][12] = (D_80079B40[i].button & 0x100) ? (((s32 (*)[14]) D_800799E0)[i][12] + 1) : (0);
    ((s32 (*)[14]) D_800799E0)[i][13] = (D_80079B40[i].button & 0x1000) ? (((s32 (*)[14]) D_800799E0)[i][13] + 1) : (0);
    if (i == 0)
    {
      s32 local_pad;
      local_pad = D_80079B58.button;

      ((s32 *) D_80079AC0)[0] = (local_pad & 0x8000) ? (((s32 *) D_80079AC0)[0] + 1) : (0);
      ((s32 *) D_80079AC0)[1] = (local_pad & 0x4000) ? (((s32 *) D_80079AC0)[1] + 1) : (0);
      ((s32 *) D_80079AC0)[2] = (local_pad & 0x2) ? (((s32 *) D_80079AC0)[2] + 1) : (0);
      ((s32 *) D_80079AC0)[3] = (local_pad & 0x4) ? (((s32 *) D_80079AC0)[3] + 1) : (0);
      ((s32 *) D_80079AC0)[4] = (local_pad & 0x8) ? (((s32 *) D_80079AC0)[4] + 1) : (0);
      ((s32 *) D_80079AC0)[5] = (local_pad & 0x1) ? ((((s32 *) D_80079AC0)[5] ^ 0) + 1) : (0);
      ((s32 *) D_80079AC0)[6] = (local_pad & 0x2000) ? (((s32 *) D_80079AC0)[((6 & 0xFFu) & 0xFFu) & 0xFFu] + 1) : (0);
      ((s32 *) D_80079AC0)[7] = (local_pad & 0x20) ? (((s32 *) D_80079AC0)[7] + 1) : (0);
      ((s32 *) D_80079AC0)[8] = (local_pad & 0x10) ? (((s32 *) D_80079AC0)[8] + 1) : (0);
      ((s32 *) D_80079AC0)[9] = (local_pad & 0x800) ? (((s32 *) D_80079AC0)[9] + 1) : (0);
      ((s32 *) D_80079AC0)[10] = (local_pad & 0x400) ? (((s32 *) D_80079AC0)[10] + 1) : (0);
      ((s32 *) D_80079AC0)[11] = (local_pad & 0x200) ? (((s32 *) D_80079AC0)[11] + 1) : (0);
      ((s32 *) D_80079AC0)[12] = (local_pad & 0x100) ? (((s32 *) D_80079AC0)[12] + 1) : (0);
      ((s32 *) D_80079AC0)[13] = (local_pad & 0x1000) ? (((s32 *) D_80079AC0)[13] + 1) : (0);
      if ((local_pad & 0x20) && (local_pad & 0x10))
      {
        ((s32 (*)[2]) D_800799C0)[i][1] = (local_pad & 0x4000) ? (((s32 (*)[2]) D_800799C0)[i][1] + 1) : (0);
      }
    }
    ((PadState1608C *) D_80079AF8)[i].prev = ((PadState1608C *) D_80079AF8)[i].cur;
    ((PadState1608C *) D_80079AF8)[i].cur = D_80079B40[i].button;
    ((PadState1608C *) D_80079AF8)[i].pressed = (u16)(((PadState1608C *) D_80079AF8)[i].cur & ~((PadState1608C *) D_80079AF8)[i].prev);
    ((PadState1608C *) D_80079AF8)[i].released = ((PadState1608C *) D_80079AF8)[i].prev & ~((PadState1608C *) D_80079AF8)[i].cur;
    ((PadState1608C *) D_80079AF8)[i].joy[0] = func_80015D60(D_80079B40[i].stick_x, 7, 0x3B);
    ((PadState1608C *) D_80079AF8)[i].joy[1] = func_80015D60(D_80079B40[i].stick_y, 7, 0x3D);
  }

  D_80079D69 = 1;
  osSetThreadPri(&D_80079BA8, sp54);
}

void func_800165F0(void) {
    func_80016934(0);
    if (D_80079B90[0].errno == 0) {
        osContGetReadData(D_80079B40);
    }
}

void func_8001662C(void) {
    while (TRUE) {
        osRecvMesg(&D_80079B60, NULL, OS_MESG_BLOCK);
        if (D_80079BA0 == 1) {
            func_800165F0();
        }
        else {
            osSendMesg(&D_80079B78, NULL, OS_MESG_NOBLOCK);
        }
    }
}

// joy_thread_entry
void func_800166DC(UNUSED void* arg0) {
    s32 eeprom_type = osEepromProbe(&D_80079B60);
    func_80016864();
    func_80014DC4();
    if (eeprom_type < EEPROM_TYPE_16K) {
        D_80079B90[0].errno = 8;
    }
    func_8001662C();
}

// joy_init
void func_80016734(void) {
    osCreateMesgQueue(&D_80079B60, &D_80079B38, 1);
    osCreateMesgQueue(&D_80079B78, &D_80079B3C, 1);
    func_8001DCB0(&D_80079BA8, &D_80079D58, THREAD_ID_JOY, func_800166DC, NULL, &D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)], JOY_THREAD_PRI);
    osSetEventMesg(OS_EVENT_SI, &D_80079B60, &D_80079B38);
    osContInit(&D_80079B60, &D_80079D68, D_80079B90);
    osStartThread(&D_80079BA8);
}

u8 func_800167F4(void) {
    return D_80079B90[0].errno;
}

u8 func_80016800(s32 arg0) {
    return D_80079D6C[arg0];
}

void func_80016810(void) {
    if (MQ_GET_COUNT(&D_80079F70) == 1) {
        func_80016934(1);
        osStopThread(&D_80079BA8);
        osContStartReadData(&D_80079B60);
        osStartThread(&D_80079BA8);
    }
}

void func_80016864(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        ((u16 *)&D_80079AF8[i])[0] = 0;
        ((u16 *)&D_80079AF8[i])[1] = 0;
        ((u16 *)&D_80079AF8[i])[2] = 0;
        ((u16 *)&D_80079AF8[i])[3] = 0;
        D_80079AF8[i].local_1[0] = 0.0f;
        D_80079AF8[i].local_1[1] = 0.0f;
        
        for (j = 0; j < (s32)ARRLEN(D_800799C0[i]); j++) {
            D_800799C0[i][j] = 0;
        }
        
        for (j = 0; j < ARRLEN(D_800799E0[i].local_0); j++) {
            D_800799E0[i].local_0[j] = 0;
        }
    }
}

void func_8001690C(s32 arg0, s32 arg1) {
    D_800799E0[arg0].local_0[6] = arg1;
}

OSMesgQueue* func_80016928(void) {
    return &D_80079B78;
}

void func_80016934(s32 arg0) {
    s32 temp_a0;

    if (arg0 == 0) {
        func_80016A48();
    } else {
        func_80016A04();
    }
    temp_a0 = __osDisableInt();
    if (arg0 != 0 || MQ_GET_COUNT(&D_80079F70) == 1) {
        D_80079BA0 = arg0;
    }
    __osRestoreInt(temp_a0);
}

OSContPad* func_800169A8(void) {
    return &D_80079B58;
}

void func_800169B4(void) {
    D_8003F5F0 = 1;
    osCreateMesgQueue(&D_80079F70, D_80079F88, ARRLEN(D_80079F88));
    osSendMesg(&D_80079F70, NULL, OS_MESG_NOBLOCK);
}

void func_80016A04(void) {
    if (D_8003F5F0 == 0) {
        func_800169B4();
    }
    osRecvMesg(&D_80079F70, NULL, OS_MESG_BLOCK);
}

void func_80016A48() {
    osSendMesg(&D_80079F70, NULL, OS_MESG_NOBLOCK);
}

s32 func_80016A74(s32 param_0, f32 *param_1)
{
    f32 local_0[2];
    f32 local_2;
    f32 local_1;

    local_1 = -1.0f;
    func_80016068(param_0, local_0);
    local_2 = sqrtf((local_0[0] * local_0[0]) +
        (local_0[1] * local_0[1]));
    if (local_2 != 0.0f) {
        local_1 = func_80013B70(local_0[1], local_0[0], local_2);
    }
    if (param_1 != NULL) {
        if (local_2 > 1.0f) {
            *param_1 = 1.0f;
        } else {
            *param_1 = local_2;
        }
    }
    return (s32)local_1;
}

s32 func_80016B30(s32 param_0, s32 param_1) {
    return ((s32 (*)[14]) D_800799E0)[param_0][param_1];
}

s32 func_80016B54(s32 param_0, s32 param_1)
{
    return D_800799F8[param_0][param_1];
}

s32 func_80016B78(s32 param_0, s32 param_1)
{
    return D_80079A04[param_0][param_1];
}

u32 func_80016B9C(param_0, param_1) s32 param_0; u16 param_1;
{
  int new_var3;
  s32 *new_var4;
  s32 new_var;
  int new_var2;
  new_var = param_0;
  new_var = new_var * 4;
  new_var4 = &new_var;
  new_var3 = ((*((u16 *) (&((u32 *) D_80079AF8)[*new_var4]))) & param_1) & 0xFFFFFFFFFFFFFFFFu;
  return new_var2 = new_var3;
}

unsigned int func_80016BBC(param_0, param_1) s32 param_0; u16 param_1;
{
  int new_var3;
  s32 *new_var4;
  int new_var5;
  s32 new_var;
  int new_var2;
  new_var = param_0;
  new_var = new_var * 4;
  new_var4 = &new_var;
  new_var5 = ((*((u16 *) (&D_80079AFC[*new_var4]))) & param_1) & 0xFFFFFFFFFFFFFFFFu;
  new_var3 = new_var5;
  return new_var2 = new_var3;
}

int func_80016BDC(int param_0)
{
  osContSetCh(param_0);
}
