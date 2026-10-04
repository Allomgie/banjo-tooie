#include "common.h"

extern u8 D_8012762C;
extern s8 D_8012B3F1;
typedef struct { s8 unk0; s8 unk1; u8 unk2; u8 unk3; u8 pad4[2]; s16 unk6; s8 unk8; u8 unk9; u8 unkA; u8 unkB; } S8012B3F0;
typedef struct { u8 unk0; s8 unk1; u8 unk2; u8 unk3; u8 pad4[2]; s16 unk6; u8 unk8; u8 unk9; u8 unkA; u8 unkB; } G_D389C;
extern void _glsavegame_entrypoint_7();
extern s16 func_8001B668(s32, s32);
extern s32 func_8001B798();
extern void _glgamedata_entrypoint_1(s32);
extern u8 D_8012B3F2;
extern s16 D_8012B3FC;
extern int func_800B2DC0(int a0, int a1);
extern u8 D_8012B3F3;
extern s32 func_800DA544;
extern void func_800C70B0(void);
extern void func_800D1864();
extern void func_800DC324();
typedef void (*func_ptr_t)();
extern u8 D_8012B3F4;
extern u8 D_8012B3F5;
extern u8 D_8012B3F0;
int func_800D3A14();
int func_800D3B6C();
void func_800D3C70();
int func_800D3CF8();
int func_800D3D10();

int func_800D3770(void) {
    s32 local_1=D_8012762C;
    s32 local_0 = local_1 >= 0xF && local_1 < 0x1C;
    if (local_1 == 0x11) local_0 = 0;
    return D_8012B3F1 + 1 != 0 && local_0;
}

void func_800D37C0(s32 param_0)
{
  ((u8 *) &D_8012B3F0)[0] = param_0;
  ((u8 *) &D_8012B3F0)[1] = param_0;
}

int func_800D37D4()
{
  ((s8 *) &D_8012B3F0)[1] = -1;
  ((s8 *) &D_8012B3F0)[0] = ((s8 *) &D_8012B3F0)[1];
}

s8 func_800D37F0()
{
  return D_8012B3F1;
}

void func_800D37FC(void)
{
  if ((*((S8012B3F0 *) &D_8012B3F0)).unk9 == 3)
  {
    _glgamedata_entrypoint_2(func_8001B798((*((S8012B3F0 *) &D_8012B3F0)).unk6));
    func_8001B754((*((S8012B3F0 *) &D_8012B3F0)).unk6);
    (*((S8012B3F0 *) &D_8012B3F0)).unk1 = (*((S8012B3F0 *) &D_8012B3F0)).unk8;
    (*((S8012B3F0 *) &D_8012B3F0)).unk3 = (*((S8012B3F0 *) &D_8012B3F0)).unkB;
    (*((S8012B3F0 *) &D_8012B3F0)).unk2 = (*((S8012B3F0 *) &D_8012B3F0)).unkA;
    (*((S8012B3F0 *) &D_8012B3F0)).unk9 = 0;
    (*((S8012B3F0 *) &D_8012B3F0)).unk8 = -1;
    (*((S8012B3F0 *) &D_8012B3F0)).unk6 = 0;
  }
  if ((*((S8012B3F0 *) &D_8012B3F0)).unk0 != -1)
  {
    _glsavegame_entrypoint_8((*((S8012B3F0 *) &D_8012B3F0)).unk0);
    (*((S8012B3F0 *) &D_8012B3F0)).unk0 = -1;
  }
  func_800D3C70();
}

void func_800D389C(void) {
    if (func_800D3770() != 0) { _glsavegame_entrypoint_7((*((G_D389C *) &D_8012B3F0)).unk1); }
    if ((*((G_D389C *) &D_8012B3F0)).unk9 == 1) {
        (*((G_D389C *) &D_8012B3F0)).unk6 = func_8001B668(0, 0x1C0);
        _glgamedata_entrypoint_1(func_8001B798((*((G_D389C *) &D_8012B3F0)).unk6));
        (*((G_D389C *) &D_8012B3F0)).unk8 = (*((G_D389C *) &D_8012B3F0)).unk1;
        (*((G_D389C *) &D_8012B3F0)).unkB = (*((G_D389C *) &D_8012B3F0)).unk3;
        (*((G_D389C *) &D_8012B3F0)).unkA = (*((G_D389C *) &D_8012B3F0)).unk2;
        (*((G_D389C *) &D_8012B3F0)).unk1 = -1;
        (*((G_D389C *) &D_8012B3F0)).unk9 = 2;
    }
}

int func_800D3934()
{
  u8 *local_0 = &D_8012B3F2;
  return *local_0 == 1;
}

int func_800D3948()
{
  u8 *local_0 = &D_8012B3F2;
  return *local_0 == 3;
}

int func_800D395C()
{
  u8 *local_0 = &D_8012B3F2;
  return *local_0 == 2;
}

int func_800D3970()
{
  func_800D37D4();
  func_800D3A14(1);
  func_800D3CF8(0 | 0);
  func_800D3D10(1);
}

void func_800D39A8()
{
  D_8012B3FC = func_800B2DC0(0x14, 1);
}

int func_800D39D0(int param_0)
{
  int new_var;
  new_var = param_0;
  D_8012B3F2 = new_var;
}

s32 func_800D39DC(s32 param_0) {
    void *local_0;
    if (param_0 >= 0) {
        local_0 = param_0;
        func_800D3B6C(1, &func_800D39D0, local_0, 0, 0);
    }
}

int func_800D3A14(param_0) int param_0;
{
  int new_var;
  new_var = param_0;
  D_8012B3F3 = new_var;
}

void func_800D3A20(s32 param_0)
{
  int new_var2;
  int new_var;
  new_var = 1000;
  new_var = 1 * 0;
  new_var2 = new_var;
  func_800D3B6C(1, &func_800DA544, param_0, new_var2, new_var);
}

void func_800D3A54(s32 param_0, s32 param_1)
{
    func_800D3B6C(2, &func_800C70B0, param_0, param_1, (s32 *)0);
}

int func_800D3A88()
{
  extern void func_800C7010();
  func_800D3B6C(0, func_800C7010, 0, 0, 0);
}

void func_800D3ABC(s32 param_0, void *param_1)
{
    func_800D3B6C(3, &func_800D1864, param_0, param_1, 0);
}

int func_800D3AF0(s32 param_0)
{
  func_800D3B6C(3, &func_800D1864, param_0, 1000, 0);
}

s32 func_800D3B24(void){
    u32 local_0 = osGetCount();
    func_800D3B6C(1, &func_800DC324, local_0, 0, 0);
}

u8 func_800D3B60()
{
  return D_8012B3F3;
}

int func_800D3B6C(param_0, param_1, param_2, param_3, param_4) s32 param_0; s32 param_1; s32 param_2; s32 param_3; s32 param_4;
{
  Actor *local_0 = func_800B2A58(D_8012B3FC);
  *(u8 *)((char *)local_0 + 0x0) = param_0;
  *(s32 *)((char *)local_0 + 0x4) = param_1;
  *(s32 *)((char *)local_0 + 0x8) = param_2;
  *(s32 *)((char *)local_0 + 0xC) = param_3;
  *(s32 *)((char *)local_0 + 0x10) = param_4;
}

void func_800D3BC8(u8 *param_0)
{
  switch (param_0[0])
  {
    case 0 :
      ((func_ptr_t)((u32 *)param_0)[1])();
      break;

    case 1 :
      ((func_ptr_t)((u32 *)param_0)[1])((u32)((u32 *)param_0)[2]);
      break;

    case 2 :
      ((func_ptr_t)((u32 *)param_0)[1])((u32)((u32 *)param_0)[2], (u32)((u32 *)param_0)[3]);
      break;

    case 3 :
      ((func_ptr_t)((u32 *)param_0)[1])((u32)((u32 *)param_0)[2], (u32)((u32 *)param_0)[3], (u32)((u32 *)param_0)[4]);
      break;
  }
}

void func_800D3C70(void) {
    s32 local_0;
    u32 local_1;
    u32 local_2;

    if (D_8012B3FC != 0) {
        local_0 = func_800B2890(D_8012B3FC);
        local_2 = vector_begin(local_0);
        local_1 = vector_end(local_0);
        if (local_2 < local_1) {
            do {
                func_800D3BC8(local_2);
                local_2 += 0x14;
            } while (local_2 < local_1);
        }
        func_800B2D48(D_8012B3FC);
        D_8012B3FC = 0;
    }
}

int func_800D3CF8(param_0) unsigned long param_0;
{
  D_8012B3F4 = param_0;
 dummy_label_890567: ;
}

s32 func_800D3D04(void)
{
  return (*((u8 *) &D_8012B3F4));
}

int func_800D3D10(param_0) long param_0;
{
  unsigned long long new_var;
  new_var = param_0;
  D_8012B3F5 = new_var;
}

u8 func_800D3D1C()
{
  return D_8012B3F5;
}

s32 func_800D3D28()
{
  u8 *p = (u8 *) (&D_8012B3F0);
  if (p[9] != 0)
  {
    return 0;
  }
  ((u8 *) (&D_8012B3F0))[9] = 1;
  return 1;
}

s32 func_800D3D58(void) {
    switch ((*(u8 *)((s8 *)(&D_8012B3F0) + 9))) {
    case 1:
        (*(u8 *)((s8 *)(&D_8012B3F0) + 9)) = 0U;
        return 1;
    case 2:
        (*(u8 *)((s8 *)(&D_8012B3F0) + 9)) = 3U;
        return 1;
    default:
        return 0;
    }
}

int func_800D3DA4()
{
  func_800F54F0();
}
