#include "common.h"

extern s32 D_80041840;
extern s32 D_8007E950;
extern void func_8001D96C();
extern void func_8001E2A0();
extern void func_8001D37C();
extern int D_80041868;
extern s32 D_8004187C;
extern u8 D_800418A8[44];
extern s32 D_800418D4;
extern s32 D_800418EC;
extern s32 D_800418FC;
extern void func_8001D3D8();
extern int D_8007E948;
extern void func_8001E380();
extern void osSetThreadPri(OSThread *, OSPri);
extern void _gzpublic_entrypoint_0(void *);
extern s32 D_8007E958;
extern s32 D_8007E94C;
typedef struct { s32 unk0; OSThread *unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14[10]; } Struct_E948;
extern u8 D_80041180[];
extern s32 D_8011A3F0;
extern OSThread D_8007E788;
extern u8 D_8007E938[];
extern OSThread *__osFaultedThread;
extern OSThread *__osRunningThread;
extern OSThread *func_8001DDA4(s32);
extern OSThread *func_80012598(void);
extern s32 D_8007E95C[];
extern s16 D_8007DB80;

/* Vorwaertsdeklarationen der Funktionen dieser TU. */
void func_8001E7B4();

void func_8001E2A0()
{
    func_8001DA60(func_80014F00());
}

void func_8001E2C8(void){
    func_8001D96C();
    func_8001D37C(&D_80041840, D_8007E950);
    func_8001E2A0();
}

void func_8001E304()
{
    func_8001D96C();
    func_8001D37C(&D_80041868);
    func_8001D9CC(0, 0xa);
    _gzreg_entrypoint_1();
    func_8001E2A0();
}

s32 func_8001E34C(void){
    func_8001D96C();
    func_8001D37C(&D_8004187C);
    func_8001E2A0();
}

void func_8001E380()
{
    func_8001E2A0();
}

void func_8001E3A0()
{
  s32 ret;
  ret = func_8001211C();
  func_8001D37C(&D_800418A8, ret, ((s32) D_8007E948));
  func_8001E2A0();
}

s32 func_8001E3E0(void){
    func_8001D37C(&D_800418D4, func_8001211C());
    func_8001E2A0();
}

s32 func_8001E418(void){
    func_8001D96C();
    func_8001D37C(&D_800418EC);
    func_8001E2A0();
}

s32 func_8001E44C(void){
    func_8001D96C();
    func_8001D3D8(0x11, 0x18, &D_800418FC, D_8007E950);
    func_8001E2A0();
}

int func_8001E490()
{
  osDestroyThread(0);
}

void func_8001E4B0()
{
  switch (D_8007E948)
  {
    case 0 :
      func_8001E2C8();
      break;

    case 1 :
      func_8001E304();
      break;

    case 2 :
      func_8001E34C();
      break;

    case 3 :
      func_8001E380();
      break;

    case 4 :
      func_8001E418();
      break;

    case 5 :
      func_8001E3E0();
      break;

    case 6 :
      func_8001E44C();
      break;

    case 7 :
      func_8001E490();
      break;

    default:
      func_8001E3A0();
      break;
  }
}

void func_8001E578(s32 param_0) {
    func_8001E7B4(1);
    osSetThreadPri(func_8001DDA4(D_8007E958), 0);
    osSetThreadPri(func_8001DDA4(7), 0x5B);
    func_8001E4B0();
    _gzpublic_entrypoint_0(D_8007E94C);
}

void func_8001E5DC(s32 param_0)
{
    s32 i;
    OSThread *t;
    s32 id;

    if (D_8011A3F0 != 0) {
        func_8001559C(0);
        (*((Struct_E948 *) &D_8007E948)).unk10 = osGetThreadId(NULL);
        for (i = 0; i != 10; i++) {
            t = func_8001DDA4(i);
            if (t != NULL) {
                (*((Struct_E948 *) &D_8007E948)).unk14[i] = osGetThreadPri(t);
            } else {
                (*((Struct_E948 *) &D_8007E948)).unk14[i] = 0;
            }
        }
        for (i = 0; i != 10; i++) {
            if (i != (*((Struct_E948 *) &D_8007E948)).unk10) {
                t = func_8001DDA4(i);
                if (t != NULL) {
                    osSetThreadPri(t, D_80041180[i]);
                }
            }
        }
        osSetThreadPri(NULL, 0xA);
        switch (param_0) {
        default:
            (*((Struct_E948 *) &D_8007E948)).unk4 = __osRunningThread;
            break;
        case 1:
            (*((Struct_E948 *) &D_8007E948)).unk4 = func_8001DDA4(6);
            break;
        case 2:
            (*((Struct_E948 *) &D_8007E948)).unk4 = func_80012598();
            break;
        case 0:
            (*((Struct_E948 *) &D_8007E948)).unk4 = __osFaultedThread;
            break;
        case 7:
            (*((Struct_E948 *) &D_8007E948)).unk4 = __osFaultedThread;
            break;
        }
        id = osGetThreadId((*((Struct_E948 *) &D_8007E948)).unk4);
        (*((Struct_E948 *) &D_8007E948)).unk8 = id;
        (*((Struct_E948 *) &D_8007E948)).unkC = (*((Struct_E948 *) &D_8007E948)).unk14[(*((Struct_E948 *) &D_8007E948)).unk8];
        (*((Struct_E948 *) &D_8007E948)).unk0 = param_0;
        func_8001DCB0(&D_8007E788, D_8007E938, 9, func_8001E578, NULL, (OSThread *) (D_8007E938 - 0x1B0), 0x5A);
        osStartThread(&D_8007E788);
    }
}

int func_8001E7A0(s32 param_0)
{
  return D_8007E95C[param_0];
}

void func_8001E7B4(param_0) s32 param_0; {
    D_8007DB80 = param_0;
}

int func_8001E7C0()
{
  return D_8007DB80;
}

int func_8001E7CC()
{
  return D_8007E948;
}
