#include "common.h"

extern u8 D_8012AB71[];
typedef struct { u8 pad_0[0x1C]; u8 local_0[0xC]; f32 local_1; s16 local_2; u8 pad_2E[2]; } Struct800CB3FC;
typedef struct { u8 pad0; u8 unk1; s16 unk2; void *unk4; u8 pad8[0x28]; } E_CB4D0;
extern s16 D_8012AB72[];
extern u8 D_8012AB70[];
extern u8 D_8012AB78[];
typedef struct { u8 pad0[0x1C]; u8 unk1C[0xC]; f32 unk28; s16 unk2C; u8 pad2E[2]; } E_CB6B4;
typedef struct { u8 pad0[8]; f32 unk8[3]; f32 unk14; s16 unk18; s16 unk1A; u8 pad1C[0x14]; } E_CB764;
extern void func_800EE7F8(f32 *, f32 *);
typedef s32 (*Fn800CB7C4)(s32, s32, s32);
typedef struct { Fn800CB7C4 *(*fn)(); s32 pad[11]; } S8012AB74;
extern S8012AB74 D_8012AB74[];
extern void func_800FC63C(s32, s32);
volatile char func_800CB698();

s32 func_800CB3E0(s32 param_0) {
    return D_8012AB71[param_0 * 48];
}

f32 func_800CB3FC(volatile s32 param_0, u32 param_1, s32 *param_2)
{
  Struct800CB3FC *local_0;
  ;
  func_800EE7F8(param_1, (local_0 = &((Struct800CB3FC *) D_8012AB70)[param_0])->local_0);
  *param_2 = local_0->local_2;
  return local_0->local_1;
}

f32 func_800CB45C(s32 param_0, u32 param_1, f32 *param_2, f32 *param_3)
{
    func_800EE7F8(param_1, (s16*)((s32)((int *) D_8012AB70) + param_0 * 48 + 8));
    *(s32 *)param_2 = *(s16 *)((s32)((int *) D_8012AB70) + param_0 * 48 + 0x18);
    *(s32 *)param_3 = *(s16 *)((s32)((int *) D_8012AB70) + param_0 * 48 + 0x1A);
    return *(f32 *)((s32)((int *) D_8012AB70) + param_0 * 48 + 0x14);
}

s32 func_800CB4D0(s32 param_0, void *param_1, s32 param_2) {
    s32 rv = 1;
    if (((E_CB4D0 *) D_8012AB70)[param_0].unk1 != 0) {
        rv = 0;
        goto end;
    }
    ((E_CB4D0 *) D_8012AB70)[param_0].unk1 = 1;
    ((E_CB4D0 *) D_8012AB70)[param_0].unk4 = param_1;
    ((E_CB4D0 *) D_8012AB70)[param_0].unk2 = param_2;
    return rv;
end:
    return rv;
}

s32 func_800CB518(s32 param_0)
{
  return *(s16 *)((char *)D_8012AB72 + param_0 * 48);
}

void func_800CB534(s32 param_0, s32 param_1, s32 param_2)
{
  u8 *local_1;
  ;
  local_1 = (s8 *) (*((u8 *(**)()) (((s8 *) ((param_0 * 0x30) + ((u8 *) (((s32 *) D_8012AB70))))) + 4)))();
  (*((s32 (**)(s32, s32, s32, s16)) (local_1 + 4)))(param_0, param_1, param_2, *((s16 *) (((s8 *) ((param_0 * 0x30) + ((u8 *) (((s32 *) D_8012AB70))))) + 0x1A)));
  local_1 = (param_0 * 0x30) + ((u8 *) (((s32 *) D_8012AB70)));
}

int func_800CB598(s32 param_0, s32 param_1, s32 param_2)
{
  func_800CB698(param_0, 4);
  func_800CB534(param_0, param_1, param_2);
}

int func_800CB5D4(s32 param_0, s32 param_1, s32 param_2)
{
  func_800CB698(param_0, 3);
  func_800CB534(param_0, param_1, param_2);
}

void func_800CB610(void) {
}

void func_800CB618()
{
  u8 *s0;
  u8 *s2;
  s32 i;
 do { s2 = &D_8012AB78; s0 = &D_8012AB70; i = 0; do { s0[0] = i; s0[1] = 0; *((s32 *) (&s0[4])) = 0; *((f32 *) (&s0[0x14])) = 0.0f; func_800EFD24(s2); i++; s0 += 0x30; s2 += 0x30; } while (i != 0x10); } while (0);
}

volatile char func_800CB698(param_0, param_1) s32 param_0; int param_1;
{
    D_8012AB71[param_0 * 0x30] = param_1;
}

void func_800CB6B4(s32 param_0, s32 param_1, f32 param_2, s32 param_3) {
    func_800EE7F8(((E_CB6B4 *) D_8012AB70)[param_0].unk1C, param_1);
    ((E_CB6B4 *) D_8012AB70)[param_0].unk28 = param_2;
    ((E_CB6B4 *) D_8012AB70)[param_0].unk2C = param_3;
}

void func_800CB70C(s32 param_0)
{
  func_800EE7F8((&D_8012AB70[param_0 * 48]) + 0x1C, (&D_8012AB70[param_0 * 48]) + 8);
  *((f32 *) ((&D_8012AB70[param_0 * 48]) + 0x28)) = *((f32 *) ((&D_8012AB70[param_0 * 48]) + 0x14));
  *((s16 *) ((&D_8012AB70[param_0 * 48]) + 0x2C)) = *((s16 *) ((&D_8012AB70[param_0 * 48]) + 0x18));
  *((s16 *) ((&D_8012AB70[param_0 * 48]) + 0x2E)) = *((s16 *) ((&D_8012AB70[param_0 * 48]) + 0x1A));
}

void func_800CB764(s32 param_0, f32 *param_1, f32 param_2, s32 param_3, s32 param_4) {
    func_800EE7F8(((E_CB764 *) D_8012AB70)[param_0].unk8, param_1);
    ((E_CB764 *) D_8012AB70)[param_0].unk14 = param_2;
    ((E_CB764 *) D_8012AB70)[param_0].unk18 = param_3;
    ((E_CB764 *) D_8012AB70)[param_0].unk1A = param_4;
}

s32 func_800CB7C4(s32 param_0, s32 param_1, s32 param_2)
{
    s32 ret = (*D_8012AB74[param_0].fn())(param_0, param_1, param_2);
    if (ret == 2) {
        func_800FC63C(0xE, 0x7FFF);
    }
    return ret;
}
