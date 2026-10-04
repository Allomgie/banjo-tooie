#include "core2/1E831D0.h"

extern s8 D_80127763;
extern void func_8001608C(void);
extern void func_800D3D28(void);
extern void _glrecord_entrypoint_3();
typedef struct { u8 field_0; u8 field_1; u8 _pad0[2]; u8 field_2; u8 _pad1[1]; s16 field_3; s16 field_4; } Struct_80127760;
extern void func_800A9B84(void);
extern s32 func_800EA05C();
extern s32 func_800EA090(void);
extern unsigned char D_80127760;
extern u8 D_8011A470[];
extern u8 D_8011A478[];
extern u8 D_8011A47C[];
extern void func_800D39A8(void);
extern void func_800D39DC();
extern void func_800D3A88(void);
extern void func_800D3AF0();
extern void func_800D3A20();
void func_800A9D08();

void func_800A98E0()
{
  switch (((u8 *) &D_80127760)[0])
  {
    case 1:
      break;

    case 2:
      _gsattract_entrypoint_3();
      break;
  }
  D_80127763 = 1;
}

void func_800A9924(param_0, param_1) s16 param_0; u8 param_1; {
  ((u8 *) &D_80127760)[0] = ((u8 *) &D_80127760)[1];
  ((u8 *) &D_80127760)[1] = 0;
  func_800D3D28();
  if ((((u8 *) &D_80127760)[0] == 1) || (((u8 *) &D_80127760)[0] == 2)) {
    _glrecord_entrypoint_3(*(s16 *)&((u8 *) &D_80127760)[6], *(s16 *)&((u8 *) &D_80127760)[8]);
  }
  func_800A9D08();
  func_8001608C();
}

void func_800A9998(void) {
    switch (((u8 *) &D_80127760)[0]) {
        case 1:
            func_800E80A0();
            break;
        case 2:
            _gsattract_entrypoint_0();
    }
    if (((u8 *) &D_80127760)[4] != 0) {
        ((u8 *) &D_80127760)[4] = 0;
    }
    func_800A1618(1);
}

void func_800A9A14()
{
  int new_var;
  func_8001211C();
  new_var = 2;
  _gcgoto_entrypoint_14(1);
  if ((((u8 *) &D_80127760)[2] != 0) && (((u8 *) &D_80127760)[3] == 0))
  {
    func_800A98E0();
  }
  switch (((u8 *) &D_80127760)[0])
  {
    case 1:
      func_800E8144();
      break;

    case 2:
      _gsattract_entrypoint_1();
      break;

  }

}

int func_800A9AA4()
{
  switch ((*((u8 *) &D_80127760)))
  {
    case 1:
      func_800E817C();
      break;

    case 2:
 if (1) { }
      _gsattract_entrypoint_2();
      break;

    return 0;
  }

}

void func_800A9AF8(void)
{
  switch (*((u8 *) (((s8 *) (((u8 *) &D_80127760))) + 0)))
  {
    case 2:
      break;

    case 1:
      func_800E8104();
      break;

  }

  if ((*((u8 *) (((s8 *) (((u8 *) &D_80127760))) + 4))) == 0)
  {
    func_800D3D58();
 do { *((u8 *) (((s8 *) (((u8 *) &D_80127760))) + 0)) = 0; } while (0);
    _glrecord_entrypoint_4();
  }
  *((s8 *) (((s8 *) (((u8 *) &D_80127760))) + 3)) = 0;
  *((s8 *) (((s8 *) (((u8 *) &D_80127760))) + 2)) = 0;
  func_800A1618(0);
}

void func_800A9B84(void) {
}

void func_800A9B8C(s32 param_0, s32 param_1)
{
  *(s16*)((char*)((s16 *) &D_80127760) + 0xa) = (s16)param_0;
  *(s16*)((char*)((s16 *) &D_80127760) + 0xc) = (s16)param_1;
}

void func_800A9BA0(s32 param_0, s32 param_1, s32 param_2)
{
    (*((Struct_80127760 *) &D_80127760)).field_1 = param_0;
    if ((*((Struct_80127760 *) &D_80127760)).field_0 != 0) {
        (*((Struct_80127760 *) &D_80127760)).field_2 = 1;
    }
    (*((Struct_80127760 *) &D_80127760)).field_3 = param_1;
    (*((Struct_80127760 *) &D_80127760)).field_4 = param_2;
    func_800A79D4(param_1, param_2);
    func_800A7A90(1);
    func_800A7B18(3);
}

void func_800A9BFC(s32 param_0, s32 param_1, s32 param_2)
{
  volatile s32 local_1;
  s32 local_0;
  func_800A9B84();
  local_0 = func_800EA05C();
  func_800A9B8C(local_0, func_800EA090());
  func_800A9BA0(param_0, param_1, param_2);
}

void func_800A9C50()
{
  if (func_800A8264() == 0)
  {
    if (!((u16 *) &D_80127760))
    {
    }
    func_800A79D4(*(s16*)((s8*)&((u16 *) &D_80127760)[0] + 0xA), *(s16*)((s8*)&((u16 *) &D_80127760)[0] + 0xC));
    func_800A7A90(1);
    func_800A7B18(1);
  }
}

s32 func_800A9C98()
{
  return (s32)(*((u8 *) &D_80127760)) != 0;
}

int func_800A9CAC(void) {
  return (*((u8 *) &D_80127760)) ? 1 : 0;
}

unsigned char func_800A9CD0(void) {
    return D_80127760;
}

int func_800A9CDC()
{
  if (!((u8*)((s32 *) &D_80127760))[2])
  {
    ((u8*)((s32 *) &D_80127760))[2] = 1;
  }
}

void func_800A9D00(void) {
}

void func_800A9D08(void)
{
    u8 *s0;
    u8 *s1;
    func_800D39A8();
    func_800D39DC(0);
    func_800D3A88();
    s0 = D_8011A470;
    s1 = 0;
    do {
        func_800D3AF0(*s0);
        s0++;
        s1++;
    } while ((u32)s1 < 7);
    s0 = D_8011A478, s1 = D_8011A47C;
    do {
        func_800D3A20(*(s16 *)s0);
        s0 += 2;
    } while (s0 != s1);
}
