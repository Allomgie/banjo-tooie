#include "common.h"
void func_800B38C8();

extern void *heap_alloc(u32);
struct Actor_800B3310 { u8 pad_0[0xC]; s32 unkC; void *unk10; void *unk14; };
typedef struct { u8 pad_0[0x18]; f32 field_18; } LocalEntry;
typedef struct { u8 pad_0[0x10]; LocalEntry *field_10, *field_14; LocalEntry field_18[1]; } LocalBuffer;
typedef struct { f32 local_0[3]; s32 local_1[3]; f32 local_2; } LightB3494;
typedef struct { u8 pad[0x10]; LightB3494 *local_0; s32 pad1; LightB3494 local_1[1]; } CollectionB3494;
extern void *func_800C8760(s32, s32);
extern void *func_800C878C(void *, s32, s32);
extern void func_800C8800(void *, f32 *);
extern void func_800C8898(void *, f32 *);
extern void func_800C8900(void *, s32 *);
extern void func_800EFB24(f32 *, f32 *, f32 *);
extern void func_800EE830();
extern f32 func_800EEF94(f32 *);
typedef struct {u8 local_0[0x1C];} local_entry;
typedef struct {u8 local_0[0x10]; local_entry *local_1; local_entry *local_2; local_entry local_3[1];} local_type;
extern void *defrag(void *);
int func_800B3784();

struct Actor_800B3310 *func_800B3310(s32 param_0)
{
    struct Actor_800B3310 *local_0;

    local_0 = heap_alloc(param_0 * 0x1C + 0x18);
    func_800B38C8(local_0);
    local_0->unk10 = (void *)((u8 *)local_0 + 0x18);
    local_0->unk14 = (void *)((u8 *)local_0->unk10 + param_0 * 0x1C);
    local_0->unkC = param_0;
    return local_0;
}

void func_800B3370(void* arg0) 
{
    heap_free(arg0);
}
LocalEntry *func_800B3390(LocalBuffer *param_0, f32 param_1)
{
    LocalEntry *local_0;
    s32 *local_2;
    s32 *local_3;
    s32 local_4;
    local_0 = (LocalEntry *)((u8 *)param_0 + 0x18);
    for (; local_0 < param_0->field_10; local_0++) {
        if (param_1 < local_0->field_18) break;
    }
    if (local_0 == param_0->field_10) {
        if (param_0->field_10 < param_0->field_14) {
            param_0->field_10 = param_0->field_10 + 1;
            return local_0;
        }
        return 0;
    }
    if (param_0->field_10 == param_0->field_14) param_0->field_10--;
    local_2 = (s32 *)(param_0->field_10 + 1);
    local_4 = (param_0->field_10 - local_0) * sizeof(LocalEntry);
    local_2--;
    local_3 = (s32 *)param_0->field_10 - 1;
    while (local_4 > 0) {
        *local_2-- = *local_3--;
        local_4 -= 4;
    }
    param_0->field_10++;
    return local_0;
}

void func_800B3494(CollectionB3494 *param_0, f32 *param_1, f32 param_2) {
    f32 local_5, local_6;
    void *local_7;
    LightB3494 *local_8;
    f32 local_1[3];
    f32 local_2[3];
    f32 local_3[3];
    s32 local_4[3];
    s32 local_9;
    param_0->local_0 = param_0->local_1;
    for (local_7 = func_800C8760(0, 1); local_7; local_7 = func_800C878C(local_7, 0, 1)) {
        func_800C8800(local_7, local_2);
        func_800C8898(local_7, local_3);
        func_800EFB24(local_1, local_2, param_1);
        local_5 = func_800EEF94(local_1);
        if (local_5 >= local_3[1] + param_2) continue;
        local_8 = func_800B3390(param_0, local_5);
        if (!local_8) continue;
        local_8->local_2 = local_5;
        local_6 = 1.0f / local_5;
        for (local_9 = 0; local_9 < 3; local_9++) {
            local_8->local_0[local_9] = local_1[local_9] * local_6;
        }
        local_5 -= param_2;
        func_800C8900(local_7, local_4);
        if (local_5 <= local_3[0]) {
            func_800EE830(local_8->local_1, local_4);
        } else {
            local_6 = 1.0f - (local_5 - local_3[0]) * local_3[2];
            for (local_9 = 0; local_9 < 3; local_9++) local_8->local_1[local_9] = local_4[local_9] * local_6;
        }
    }
    func_800B3784(param_0);
}

int func_800B36C0(s32 *param_0, s32 param_1, s32 *param_2, f32 param_3)
{
  s32 local_0 = param_0[4];
  if ((u32)local_0 < (u32)param_0[5])
  {
    func_800EE7F8((void *)local_0, param_1);
    func_800EE830((void *)((u32)param_0[4] + 0xC), param_2);
    *((f32 *)((u32)param_0[4] + 0x18)) = param_3;
    param_0[4] += 0x1C;
    return 1;
  }
  return 0;
}

int func_800B3748(s32 param_0)
{
  f32 local_1[3];
  f32 local_0[3];
  func_800C8960(local_0, local_1);
  func_800B36C0(param_0, local_1, local_0, 5e+02f);
}

int func_800B3784(param_0) s32 * param_0;
{
  return (param_0[4] - (s32)param_0 - 0x18) / 0x1C;
}

int func_800B37A4(s32 param_0[5], s32 *param_1, s32 *param_2)
{
  int new_var;
  new_var = 0;
  new_var = 0xFFFFFFFF ^ new_var;
  param_1[0] = (s32*)((s8*)param_0 + 0x18);
  param_2[0] = *(s32*)((s8*)param_0 + 0x10);
  param_0 += 0;
}

int func_800B37B8(s32 param_0, s32 param_1)
{
  func_800EE830(param_1 | 0, param_0 | 0);
}

void func_800B37E4(u8 *param_0, u8 *param_1)
{
  u8 *local_3;
  *((u32 *) (param_0 + 0x10)) = (u32) (param_0 + 0x18);
  local_3 = param_1 + 0x18;
  if (((u32) local_3) < (*((u32 *) (param_1 + 0x10))))
  {
    if ((*((u32 *) (param_0 + 0x10))) < (*((u32 *) (param_0 + 0x14))))
    {
      do
      {
        aligned4_memcpy(*((u32 *) (param_0 + 0x10)), (u32) local_3, 0x1C);
        local_3 += 0x1C;
        *((u32 *) (param_0 + 0x10)) += 0x1C;
      }
      while ((((u32) local_3) < (*((u32 *) (param_1 + 0x10)))) && ((*((u32 *) (param_0 + 0x10))) < (*((u32 *) (param_0 + 0x14)))));
    }
  }
  func_800EE830(param_0, param_1);
}

int func_800B388C(s32 *param_0, s32 param_1) {
    param_0[5] = (s32)((u8 *)param_0 + (param_1 * 7) * 4) + 0x18;
}

void func_800B38A8()
{
    func_800EE830();
}

void func_800B38C8()
{
    func_800C87B8();
}

local_type *func_800B38E8(local_type *param_0) {
    s32 local_0;
    s32 local_1;
    local_type *local_2;
    local_0 = param_0->local_1 - param_0->local_3;
    local_1 = param_0->local_2 - param_0->local_3;
    local_2 = defrag(param_0);
    if (local_2 != param_0) {
        param_0 = local_2;
        param_0->local_1 = local_0 + param_0->local_3;
        param_0->local_2 = local_1 + param_0->local_3;
    }
    return param_0;
}
