#include "common.h"

typedef struct { s32 pad; s16 local_0[3]; } MarkerEB;
typedef struct { MarkerEB *local_0; s32 local_1; } EntryEB;
extern void *vector_new(s32, s32);
extern void *vector_push_back(void **);
extern EntryEB *vector_begin(void *);
extern EntryEB *vector_end(void *);
extern void _gspropprop_entrypoint_3(void *param_0, s32 param_1, void *param_2);
typedef struct { u8 pad[0x28]; u32 pad2:23; u32 local_0:8; u32 pad3:1; } ObjectEB5E0;
typedef struct { ObjectEB5E0 *local_0; s32 pad; u32 pad2:27; u32 local_1:1; u32 local_2:1; u32 pad3:1; u32 local_3:1; u32 local_4:1; } EntryEB5E0;
extern void func_800E3A30(f32 *);
extern void _gspropprop_entrypoint_2(EntryEB5E0 *);
typedef struct { void *w[7]; s16 unk1C; } G_EB70C;
G_EB70C D_80132E80;
extern void vector_free(void *vec);
extern void *D_80132E9C;
extern void vector_clear(void *vec);
extern s32 D_80132EC0;
typedef struct { s32 pad; s16 local_0[2]; union { struct { s16 local_0; u16 pad; } local_0; struct { u32 pad:30; u32 local_0:1; u32 local_1:1; } local_1; } local_1; } EntryEB8C0;
typedef struct { s16 local_0[3]; u8 pad[14]; } PropEB8C0;
typedef struct { s32 local_0[3]; s32 local_1, local_2; void *local_3, *local_4; s32 local_5; s32 (*local_6)(PropEB8C0 *, void *); void *local_7; } SearchEB8C0;
extern SearchEB8C0 D_80132EA0;
extern s32 func_800E9DCC(void *);
extern s32 func_800E9DC4(void *);
extern EntryEB8C0 *func_800E9E88(void *);
extern EntryEB8C0 *func_800E9EB4(void *);
extern PropEB8C0 *func_800E9D68(void *);
extern PropEB8C0 *func_800E9D90(void *);
extern s32 D_80123540;
extern s32 D_8013546C;
typedef struct { u8 pad0[0x12]; u16 unk12; u8 pad14[0x1C]; } Sub_EBB94;
typedef struct { Sub_EBB94 sub[4]; } E_EBB94;
typedef struct { E_EBB94 arr[50]; u8 flags[25]; } G_EBB94;
typedef struct MarkerEntry MarkerEntry;
typedef struct { MarkerEntry *field_0; u8 pad_4[0x18]; s16 field_1C; } MarkerRef;
extern MarkerEntry *func_800E99E0(void);
extern s32 func_800DC214(s32, s32, s32 *);
extern s32 func_800BD948(void *);
extern u8 D_80132ED0[];
extern u8 D_80135450;
extern u8 D_80123554[];
typedef struct { u8 pad_0[8]; void (*field_8)(void); u8 pad_C[6]; u16 field_12:15; u16 field_13:1; u8 pad_14[0x10]; u32 field_24:10; u32 pad_24:22; u32 pad_28:22; u32 field_2A:1; u32 pad_2B:9; u32 pad_2C; } MarkerCreate;
typedef struct { u8 pad_0[0x10]; u32 field_10; u8 pad_14[8]; s16 field_1C; u8 pad_1E[10]; u32 pad_28:21; u32 field_28:1; u32 pad_29:10; } MarkerMove;
extern s32 func_800BD97C(s32 *);
extern void func_800CDFD0(MarkerMove *);
typedef struct { u8 pad[0x24]; u32 pad1:16; u32 local_0:9; u32 pad2:7; u32 local_1:9; u32 local_2:9; u32 pad3:14; } MarkerEC124;
extern f32 func_800136E4(f32);
typedef struct { u8 pad0[0x14]; u16 unk14; u16 pad16; u16 unk18; } S_EC428;
typedef struct { u8 pad0[0x14]; u16 unk14; u8 pad16[0xA]; s16 unk20; } S_EC48C;
extern s32 func_800B0CFC(void *);
typedef struct { u8 pad[0x18]; u32 local_0:11; u32 pad_1:4; u32 local_1:1; u32 pad_2:16; } EntryEC5C0;
typedef struct { u8 pad0[8]; u32 f0 : 30; u32 bit : 1; u32 f2 : 1; } S_EC708;
int func_800EC7D4();
s32 func_800EC800();
s32 func_800EC854();

void func_800EB3D0(MarkerEB *param_0, s32 param_1, s16 *param_2) {
    s32 local_0, local_1, local_2;
    EntryEB *local_4, *local_6, *local_5;
    void *local_8;
    if (!D_80132E80.w[param_1]) D_80132E80.w[param_1] = vector_new(8, 5);
    vector_push_back(&D_80132E80.w[param_1]);
    local_0 = param_0->local_0[0] - param_2[0];
    local_1 = param_0->local_0[1] - param_2[1];
    local_2 = param_0->local_0[2] - param_2[2];
    local_0 = local_0 * local_0 + local_1 * local_1 + local_2 * local_2;
    local_8 = D_80132E80.w[param_1];
    local_6 = vector_begin(local_8);
    local_5 = vector_end(local_8) - 1;
    local_4 = local_5 - 1;
    while (local_4 >= local_6) {
        if (local_0 < local_4->local_1) break;
        local_4--;
    }
    local_4++;
    if (local_4 < local_5) aligned4_memmove(local_4 + 1, local_4, (local_5 - local_4) * sizeof(EntryEB));
    local_4->local_1 = local_0;
    local_4->local_0 = param_0;
}

void func_800EB51C(s32 param_0, s32 param_1)
{
  s8 _sfpad[8];
  void *sp2C;
  void *temp_s0;
  void *temp_v0;
  u8 *var_s0;
  void *temp_a2;
  temp_s0 = D_80132E80.w[param_0];
  if (temp_s0 != 0)
  {
    sp2C = vector_begin(temp_s0);
    temp_v0 = vector_end(temp_s0);
    if (temp_v0 != sp2C)
    {
      (*((s16 *) &D_80132E9C)) = (s16) param_0;
      var_s0 = (u8 *) sp2C;
      if (sp2C < temp_v0)
      {
        do
        {
          temp_a2 = *((void **) var_s0);
          if ((*((s32 *) (((u8 *) (*((void **) var_s0))) + 8))) & 1)
          {
            do
            {
              func_800EC7D4(*((s32 *) (*((void **) var_s0))), param_1 ^ 0, *((void **) var_s0));
            }
            while (0);
          }
          else
          {
            _gspropprop_entrypoint_3(temp_a2, param_1, *((void **) var_s0));
          }
          var_s0 += 8;
        }
        while (var_s0 < ((u8 *) temp_v0));
      }
    }
  }
}

void func_800EB5E0(s32 param_0, s32 param_1) {
    EntryEB5E0 *local_1;
    f32 local_0[3];
    EntryEB5E0 *local_2;
    ObjectEB5E0 *local_3;
    func_800E3A30(local_0);
    local_1 = func_800E9E88(param_0);
    local_2 = func_800E9EB4(param_0);
    for (; local_1 < local_2; local_1++) {
        if (local_1->local_1) {
            if (!local_1->local_3) _gspropprop_entrypoint_2(local_1);
            if (local_1->local_4) {
                local_3 = local_1->local_0;
                if (func_800EC800(local_3)) {
                    for (param_1 = 0; param_1 < 7; param_1++) {
                        if (local_3->local_0 & (1 << param_1)) func_800EB3D0(local_1, param_1, local_0);
                    }
                }
            } else func_800EB3D0(local_1, local_1->local_2 ? 1 : 0, local_0);
        }
    }
}

void func_800EB70C(void) {
    s32 i;
    D_80132E80.unk1C = -1;
    for (i = 0; i < 7; i++) {
        D_80132E80.w[i] = 0;
    }
}

void func_800EB750()
{
  void **local_0 = D_80132E80.w;
 local_0 = local_0; do { void *local_1; do { local_1 = *local_0; if (0 != local_1) { vector_free(local_1); *local_0 = 0; } local_0 += 1; } while (local_0 != (&D_80132E9C)); } while (0);
}

void func_800EB7A8(void)
{
  s32 *ptr;
  s32 local_0;
 ptr = ((s32 *) &D_80132E80); do {
    local_0 = *ptr;
    if (local_0 != 0)
    {
      *ptr = vector_defrag(local_0);
    }
    ptr += 1;
  }
  while (ptr != (((s32 *) &D_80132E9C)));
}

void func_800EB800()
{
  void **local_0 = D_80132E80.w;
 local_0 = local_0; do { void *local_1; do { local_1 = *local_0; if (0 != local_1) { vector_clear(local_1); } local_0 += 1; } while (local_0 != (&D_80132E9C)); } while (0);
}

int func_800EB854()
{
  return (*((s16 *) &D_80132E9C));
}

void func_800EB860(s32 param_0, s32 param_1)
{
  *(s32*)((char*)((s32 *) &D_80132EA0) + 0x20) = param_0;
  *(s32*)((char*)((s32 *) &D_80132EA0) + 0x24) = param_1;
}

void func_800EB874()
{
  D_80132EC0 = 0;
}

int func_800EB880(OSViCommonRegs *param_0, s32 param_1, u32 param_2)
{
  *(u32*)((char*)((u32 *) &D_80132EA0) + 0x0) = *(u32*)((char*)param_0 + 0x0);
  *(u32*)((char*)((u32 *) &D_80132EA0) + 4) = *(u32*)((char*)param_0 + 0x4);
  *(u32*)((char*)((u32 *) &D_80132EA0) + 8) = *(u32*)((char*)param_0 + 0x8);
  *(u32*)((char*)((u32 *) &D_80132EA0) + 0xC) = param_2 * param_2;
  *(u32*)((char*)((u32 *) &D_80132EA0) + 0x10) = param_1;
  *(u32*)((char*)((u32 *) &D_80132EA0) + 0x14) = 0;
  *(u32*)((char*)((u32 *) &D_80132EA0) + 0x18) = 0;
  *(u32*)((char*)((u32 *) &D_80132EA0) + 0x1C) = 0;
}

void func_800EB8C0(void *param_0) {
    EntryEB8C0 *local_0, *local_1;
    PropEB8C0 *local_2, *local_3;
    s32 local_4;
    if (func_800E9DCC(param_0) && (D_80132EA0.local_2 == 1 || D_80132EA0.local_2 == 2)) {
        local_0 = func_800E9E88(param_0);
        local_1 = func_800E9EB4(param_0);
        for (; local_0 < local_1; local_0++) {
            if (local_0->local_1.local_1.local_1) continue;
            local_4 = (local_0->local_0[0] - D_80132EA0.local_0[0]) * (local_0->local_0[0] - D_80132EA0.local_0[0]) +
                      (local_0->local_0[1] - D_80132EA0.local_0[1]) * (local_0->local_0[1] - D_80132EA0.local_0[1]) +
                      (local_0->local_1.local_0.local_0 - D_80132EA0.local_0[2]) * (local_0->local_1.local_0.local_0 - D_80132EA0.local_0[2]);
            if (local_4 < D_80132EA0.local_1 && (local_0->local_1.local_1.local_0 ? 2 : 1) == D_80132EA0.local_2) {
                D_80132EA0.local_1 = local_4;
                D_80132EA0.local_3 = param_0;
                D_80132EA0.local_4 = local_0;
                D_80132EA0.local_5 = D_80132EA0.local_2;
            }
        }
    }
    if (func_800E9DC4(param_0) && D_80132EA0.local_2 == 3) {
        local_2 = func_800E9D68(param_0);
        local_3 = func_800E9D90(param_0);
        for (; local_2 < local_3; local_2++) {
            if ((local_2->local_0[0] - D_80132EA0.local_0[0]) * (local_2->local_0[0] - D_80132EA0.local_0[0]) + (local_2->local_0[1] - D_80132EA0.local_0[1]) * (local_2->local_0[1] - D_80132EA0.local_0[1]) + (local_2->local_0[2] - D_80132EA0.local_0[2]) * (local_2->local_0[2] - D_80132EA0.local_0[2]) < D_80132EA0.local_1 && (!D_80132EA0.local_6 || D_80132EA0.local_6(local_2, D_80132EA0.local_7))) {
                D_80132EA0.local_1 = (local_2->local_0[0] - D_80132EA0.local_0[0]) * (local_2->local_0[0] - D_80132EA0.local_0[0]) + (local_2->local_0[1] - D_80132EA0.local_0[1]) * (local_2->local_0[1] - D_80132EA0.local_0[1]) + (local_2->local_0[2] - D_80132EA0.local_0[2]) * (local_2->local_0[2] - D_80132EA0.local_0[2]);
                D_80132EA0.local_3 = param_0;
                D_80132EA0.local_4 = local_2;
                D_80132EA0.local_5 = D_80132EA0.local_2;
            }
        }
    }
}

int func_800EBB30(s32 *param_0, s32 *param_1)
{
  *param_0 = ((s32 *) &D_80132EA0)[5];
  *param_1 = ((s32 *) &D_80132EA0)[6];
  return ((s32 *) &D_80132EA0)[7];
}

int func_800EBB50()
{
  return (int)&D_80123540;
}

void func_800EBB5C()
{
  D_8013546C = 0x6B7;
}

void func_800EBB6C(void) {
}

int func_800EBB74()
{
  return (((u8 *) D_80132ED0)) ? 1 : 0;
}

void func_800EBB94(void) {
    s32 i;
    s32 j;
    for (i = 0; i < 25; i++) {
        (*((G_EBB94 *) D_80132ED0)).flags[i] = 0;
    }
    for (i = 0; i < 50; i++) {
        for (j = 0; j < 4; j++) {
            (*((G_EBB94 *) D_80132ED0)).arr[i].sub[j].unk12 &= 1;
        }
    }
}

void func_800EBC04(void) {
}

struct MarkerEntry {
    MarkerRef *field_0;
    s16 field_4[3];
    u16 field_A:5;
    u16 field_A_room:5;
    u16 field_B5:1;
    u16 pad_B:3;
    u16 field_B1:1;
    u16 pad_B0:1;
};

void func_800EBC0C(void *param_0, s32 *param_1, MarkerRef *param_2, s32 param_3) {
    MarkerEntry *local_0;
    local_0 = func_800E99E0();
    local_0->field_4[0] = param_1[0];
    local_0->field_4[1] = param_1[1];
    local_0->field_4[2] = param_1[2];
    local_0->field_0 = param_2;
    local_0->field_B1 = param_3;
    local_0->field_A = 0;
    local_0->field_B5 = 0;
    local_0->field_A_room = func_800DC214(0, 0x20, param_1);
    param_2->field_0 = local_0;
    param_2->field_1C = func_800BD948(param_0);
}

void func_800EBCD0(s32 *param_0, s32 *param_1, u32 param_2, s32 param_3)
{
  u8 *local_1;
  s32 local_2;
  u16 local_0;

  local_1 = *param_0;
  local_0 = *(u16 *)((char *)local_1 + 0xA);
  func_800EBC0C(param_3, param_1, param_0, func_800E9AC0(param_2, local_1));
  *(u16 *)((char *)*param_0 + 0xA) = local_0;
}

void func_800EBD2C(s32 arg0, s32 arg1, s32 arg2) {
    func_800EBCD0(arg0, arg1, func_800BDB9C(*(s16 *)(arg0 + 0x1C)), func_800BDB9C(arg2));
}

u8 *func_800EBD78(void)
{
  s32 local_0;
  s32 local_1;
  s32 local_2;
  s32 local_3;
  s32 local_4;
  s32 local_5;
  u8 *local_6;
  local_4 = 0;
  if (D_80135450 == 0xFF)
  {
    loop_2:
    local_4 += 1;

    if (local_4 < 0x19)
    {
      if ((*((u8 *) ((D_80132ED0 + local_4) + 0x2580))) == 0xFF)
      {
        goto loop_2;
      }
    }
  }
  if (local_4 == 0x19)
  {
    return 0;
  }
  local_6 = D_80132ED0 + local_4;
  local_5 = *((u8 *) (local_6 + 0x2580));
  local_2 = 0x80;
  local_3 = 0;
  if (local_5 & 0x80)
  {
    do
    {
      local_0 = (local_2 = local_2 >> 1);
      local_1 = local_5 & local_0;
      local_3 += 1;
    }
    while (local_1 != 0);
  }
  *((u8 *) (local_6 + 0x2580)) = (u8) (local_5 | local_2);
  return (D_80132ED0 + (local_4 * 0x180)) + (local_3 * 0x30);
}

void func_800EBE24(u8 *param_0)
{
    s32 local_0;
    u8 *local_1;
    s32 local_2;

    local_0 = (s32)param_0 - (s32)&D_80132ED0;
    *(u16 *)((char *)param_0 + 0x12) = *(u16 *)((char *)param_0 + 0x12) & 1;
    local_2 = local_0 / 48;
    local_1 = (u8 *)&D_80132ED0 + (local_2 >> 3);
    local_1[0x2580] = local_1[0x2580] & ((u32 *)&D_80123554)[local_2 & 7];
}

int func_800EBE74(s32 param_0, s32 *param_1, s32 param_2)
{
  u32 local_0;
  if (param_1[4] & 1)
  {
    local_0 = func_800BDC44() | 0;
  }
  else
  {
    local_0 = func_800BDBC4(param_0) | 0;
  }
  func_800EBC0C(local_0, param_0, param_1, param_2);
}

MarkerCreate *func_800EBED4(s32 *param_0, s32 param_1, s32 param_2, s32 param_3) {
    MarkerCreate *local_0;
    local_0 = func_800EBD78();
    bzero(local_0, 0x30);
    local_0->field_12 = func_800EC854();
    local_0->field_24 = param_2;
    local_0->field_13 = param_3;
    local_0->field_8 = func_800EBB50;
    local_0->field_2A = 1;
    func_800EBE74(param_0, local_0, param_1);
    return local_0;
}

int func_800EBF8C(s32 param_0, s32 param_1, s32 param_2, s32 param_3)
{
  f32 local_0[3];
  func_800EE904(local_0, param_0 | 0);
  func_800EBED4(local_0, param_1, param_2, param_3);
}

s32 func_800EBFD4(s32 map, s32 exit, s32 direction){
    func_800EBF8C(map, exit, direction, 0);
}

void func_800EBFF4(u8 *param_0) {
    func_800E9AC0(func_800BDB9C((*(s16 *)((s8 *)(param_0) + (0x1C)))), (*(s32 *)((s8 *)(param_0) + (0))));
    func_800EBE24(param_0);
}

void func_800EC030(u8 **param_0, u8 *param_1) {
    (*(s16 *)((s8 *)(*param_0) + 4)) = (s16) (*(s32 *)((s8 *)(param_1) + 0));
    (*(s16 *)((s8 *)(*param_0) + 6)) = (s16) (*(s32 *)((s8 *)(param_1) + 4));
    (*(s16 *)((s8 *)(*param_0) + 8)) = (s16) (*(s32 *)((s8 *)(param_1) + 8));
}

void func_800EC058(s32 *param_0, MarkerMove *param_1) {
    s32 local_0;
    if (param_1->field_10 & 1) local_0 = -1;
    else local_0 = func_800BD97C(param_0);
    if (local_0 == param_1->field_1C) func_800EC030(param_1, param_0);
    else func_800EBD2C(param_1, param_0, local_0);
    if (param_1->field_28) func_800CDFD0(param_1);
}

int func_800EC0EC(s32 param_0, s32 param_1)
{
  f32 local_0[3];
  func_800EE904(local_0, param_0 | 0);
  func_800EC058(local_0, param_1);
}

void func_800EC124(void *param_0, MarkerEC124 *param_1, f32 *param_2) {
    param_1->local_0 = func_800136E4(param_2[0]);
    param_1->local_1 = func_800136E4(param_2[1]);
    param_1->local_2 = func_800136E4(param_2[2]);
    func_800EC0EC(param_0, param_1);
}

void func_800EC340(u16 *a0, s32 a1)
{
  short new_var;
  u16 temp = a0[13];
  new_var = temp;
  if (1)
  {
    temp = new_var;
    a0[13] = ((a1 << 3) << 2) | ((temp & 0x1F) & 0xFFFFFFFF);
 if (0) { }
  }
}

func_800EC358(s32 param_0, s32 param_1){
    s32 local_0;
    local_0 = param_1;
    ((s32*)param_0)[3] = local_0;
}

int func_800EC360(s32 param_0, unsigned long param_1)
{
  *((s16 *) (param_0 + 0x14)) = param_1;
  if (param_0)
  {
  }
}

int func_800EC368(s32 param_0, int param_1)
{
  s16 new_var;
  new_var = param_1;
  *((s16 *) (((char *) param_0) + 22)) = param_1;
}

void func_800EC370(u8 **param_0, u8 *param_1) {
    *(s16 *)(param_1 + 0) = *(s16 *)(*param_0 + 4);
    *(s16 *)(param_1 + 2) = *(s16 *)(*param_0 + 6);
    *(s16 *)(param_1 + 4) = *(s16 *)(*param_0 + 8);
}

void func_800EC398(s32 *param_0, s32 param_1) {
    func_800EE88C(param_1, *(s32 *)(param_0 + 0) + 0x4);
}

void func_800EC3C4(u8 *param_0) {
    (*(s32 (**)())((s8 *)(param_0) + (8)))();
}

int func_800EC3E8(Actor *param_0)
{
  u16 local_0;
  extern u16 D_801039A4_unk14_1;
  ;
  if (((*((u16 *) (((char *) param_0) + 0x14))) == 0) || ((*((u16 *) (((char *) param_0) + 0x14))) == 0xFFFF))
  {
    return 0;
  }
  else
  {
    return func_800D674C((*((u16 *) (((char *) param_0) + 0x14))) | 0);
  }
}

s32 func_800EC428(S_EC428 *param_0) {
    if ((param_0->unk18 & 1) != 0) {
        return func_801039E4(param_0);
    }
    if ((param_0->unk14 == 0) || (param_0->unk14 == 0xFFFF)) {
        return 0;
    }
    return func_800D674C(param_0->unk14);
}

f32 func_800EC48C(S_EC48C *param_0) {
    f32 r;
    if ((param_0->unk14 == 0) || (param_0->unk14 == 0xFFFF)) { return 0.0f; }
    r = (f32)func_800B0CFC(func_800EC3E8(param_0)) * 0.5f;
    param_0->unk20 = (s16)r;
    return r;
}

f32 func_800EC504(u8 *param_0) {
    f32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    if (*(u16 *)(param_0 + 0x14) == 0 || *(u16 *)(param_0 + 0x14) == 0xFFFF) {
        return 1.0f;
    }
    sp28 = func_800D73CC(*(u16 *)(param_0 + 0x14));
    sp2C = func_800D674C(*(u16 *)(param_0 + 0x14));
    if (sp2C == 0) {
        return 1.0f;
    }
    func_800D62E4(*(u16 *)(param_0 + 0x14), sp2C);
    func_800B237C(func_800B2840(sp2C), &sp30, &sp3C);
    func_800EE940(param_0 + 0x1E, &sp30);
    if (sp28 == 0) {
        func_800D6CEC(*(u16 *)(param_0 + 0x14));
    }
    return sp3C;
}

f32 func_800EC5C0(EntryEC5C0 **param_0, f32 (*param_1)(EntryEC5C0 *)) {
    EntryEC5C0 *local_0;
    f32 local_1;
    local_0 = *param_0;
    local_1 = local_0->local_0;
    if (local_1 == 0.0f) {
        local_1 = local_0->local_0 = param_1(local_0);
    }
    if (local_0->local_1) {
        local_1 *= ((f32 *)func_80106790((Unk80132ED0 *)local_0))[14];
    }
    return local_1;
}

f32 func_800EC708(S_EC708 **param_0) {
    S_EC708 *p = *param_0;
    if (p->bit) { return func_800EC5C0(p, func_800EC504); }
    else { return func_800EC5C0(p, func_800EC48C); }
}

f32 func_800EC75C(s32 param_0, s32 param_1)
{
  f32 local_1;
  f32 local_0[3];
  u8 *s0 = (u8 *)param_0;
  local_1 = func_800EC708(param_0);
  func_800EE88C(param_1, s0 + 0x1e);
  if (*(u16 *)(s0 + 0x18) & 1)
  {
    u8 *tmp = func_80106790(s0);
    func_800EF334(param_1, *(s32 *)(tmp + 0x38));
  }
  func_800EC398(s0, local_0);
  func_800EF04C(param_1, local_0);
  return local_1;
}

int func_800EC7D4(param_0, param_1) s32 param_0; s32 param_1;
{
  func_8010A79C(func_80106790(param_0) | 0, param_1);
}

s32 func_800EC800(param_0) u8 * param_0;
{
  s32 var_v0;
  var_v0 = ((*((u16 *) (((u8 *) param_0) + 0x18))) & 1) != 0;
  if (0 != var_v0)
  {
    return (*((u16 *) (((u8 *) param_0) + 0x14))) != 0;
    ;
  }
}

int func_800EC828()
{
  ((int *) D_80132ED0)[0x967]--;
  if (((int *) D_80132ED0)[0x967] < 0x6B7)
  {
    ((int *) D_80132ED0)[0x967] = 0x7FFF;
  }
}

s32 func_800EC854(void)
{
    s32 local_0;

    local_0 = *(s32 *)((s8 *)((s16 *) D_80132ED0) + 0x259c);
    if (++*(s32 *)((s8 *)((s16 *) D_80132ED0) + 0x259c) >= 0x8000) {
        *(s32 *)((s8 *)((s16 *) D_80132ED0) + 0x259c) = 0x6b7;
    }
    return local_0;
}
